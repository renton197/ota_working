//*****************************************************************************
//
//! @file multi_boot.c
//!
//! @brief Bootloader program accepting multiple host protocols.
//!
//! This is a bootloader program that supports flash programming over UART,
//! SPI, and I2C. The correct protocol is selected automatically at boot time.
//!
//! SWO is configured in 1M baud, 8-n-1 mode.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************

#include "am_mcu_apollo.h"
#include "am_bsp.h"
#include "am_util.h"
#include "am_bootloader.h"
#include "multi_boot.h"
#include "multi_boot_config.h"

//*****************************************************************************
//
// UART pin used for AutoBaud
//
//*****************************************************************************
#if defined (AM_PART_APOLLO)
#define UART_RX_PIN                     1
#elif defined (AM_PART_APOLLO2)
#define UART_RX_PIN                     2
#endif

//*****************************************************************************
//
// Message buffers.
//
// Note: The RX buffer needs to be 32-bit aligned to be compatible with the
// flash helper functions, but we also need an 8-bit pointer to it for copying
// data from the IOS interface, which is only 8 bits wide.
//
//*****************************************************************************
uint8_t g_pui8TxBuffer[8];
uint32_t g_pui32RxBuffer[AM_HAL_FLASH_PAGE_SIZE / 4];
uint8_t *g_pui8RxBuffer = (uint8_t *) g_pui32RxBuffer;
uint32_t g_ui32BytesInBuffer = 0;

uint8_t g_TestArray[32*4];

//*****************************************************************************
//
// Globals to keep track of the image write state.
//
//*****************************************************************************
uint32_t *g_pui32WriteAddress = 0;
uint32_t g_ui32BytesReceived = 0;

volatile bool g_bImageValid = false;

uint32_t g_ui32CRC = 0;

//*****************************************************************************
//
// Global variable to keep track of which interface we're using.
//
//*****************************************************************************
extern volatile bool g_bIOSActive;

//*****************************************************************************
//
// Image structure to hold data about the downloaded boot image.
//
//*****************************************************************************
am_bootloader_image_t g_sImage = {0, 0, 0, 0, 0, 0, 0, 0};  //RMA: added elements

//*****************************************************************************
//
// Flag page information.
//
//*****************************************************************************

void setup_ios_interface(void);
void setup_serial(int32_t i32Module, uint32_t ui32BaudRate);
void cleanup_ios_interface(void);

//*****************************************************************************
//
// Setting up a GPIO ISR for the UART autobaud feature.
//
//*****************************************************************************
void
am_gpio_isr(void)
{
    uint32_t ui32Start, ui32End, ui32Counts, ui32BaudRate;

    //
    // Check the time, and record this as the "start" time.
    //
    // We need to hit this register as early as possible, so we are skipping
    // all of the normal logic that checks to make sure we are responding to
    // the right GPIO. In the interest of time, we will just assume that this
    // interrupt is coming from the UART RX pin.
    //
    ui32Start = am_hal_systick_count();

    //
    // Wait for exactly 9 edges on the UART RX pin. This corresponds to the
    // number of edges in the byte 0x55 after the start bit. Using a simple
    // polling approach here gives us the best possible chance to catch every
    // single edge.
    //
    while(!am_hal_gpio_input_bit_read(UART_RX_PIN));
    while(am_hal_gpio_input_bit_read(UART_RX_PIN));
    while(!am_hal_gpio_input_bit_read(UART_RX_PIN));
    while(am_hal_gpio_input_bit_read(UART_RX_PIN));
    while(!am_hal_gpio_input_bit_read(UART_RX_PIN));
    while(am_hal_gpio_input_bit_read(UART_RX_PIN));
    while(!am_hal_gpio_input_bit_read(UART_RX_PIN));
    while(am_hal_gpio_input_bit_read(UART_RX_PIN));
    while(!am_hal_gpio_input_bit_read(UART_RX_PIN));

    //
    // Record the "end" time.
    //
    ui32End = am_hal_systick_count();

    //
    // At this point, the timing-critical portion of the interrupt handler is
    // complete, and we are free to clean up our interrupt status. We only
    // intend to perform the automatic baud-rate detection once, so we will go
    // ahead and disable the interrupt on the UART RX pin now.
    //
    am_hal_gpio_int_disable(AM_HAL_GPIO_BIT(UART_RX_PIN));
    am_hal_gpio_int_clear(AM_HAL_GPIO_BIT(UART_RX_PIN));

    //
    // Check to see how long those nine edges took to arrive. This should
    // correspond to exactly nine bit-times of UART traffic from the host. From
    // there, we can use the speed of the processor (which is known) to
    // calculate the host's baud rate.
    //
    ui32Counts = ui32Start - ui32End;
    ui32BaudRate = AM_HAL_CLKGEN_FREQ_MAX_HZ * 9 / ui32Counts;

    //
    // Now that we have a baud rate, we can configure our UART.
    //
    setup_serial(0, ui32BaudRate);

    //
    // Send a '0x55' to give the boot host some indication that we have the
    // correct baud rate and to let it know that our UART is ready for further
    // traffic.
    //
    am_hal_uart_char_transmit_polled(0, 0x55);
}

//*****************************************************************************
//
// Main function.
//
//*****************************************************************************
int
main(void)
{
    //
    // Set the (active LOW) interrupt pin so the host knows we don't have a
    // message to send yet.
    //
    am_hal_gpio_out_bit_set(INTERRUPT_PIN);
    am_hal_gpio_pin_config(INTERRUPT_PIN, AM_HAL_PIN_OUTPUT);

    //
    // If the user selected to use the last page of flash as the flag page, we
    // need to configure for that now.
    //
#if USE_LAST_PAGE_FOR_FLAG
    am_hal_mcuctrl_device_t device;

    //
    // Read the MCU registers to find our flash size.
    //
    am_hal_mcuctrl_device_info_get(&device);

    //
    // Set the boot image location based on the flash size.
    //
    if(device.ui32FlashSize != 0)
    {
        g_psBootImage = (am_bootloader_image_t *)(device.ui32FlashSize - AM_HAL_FLASH_PAGE_SIZE);
    }
    else
    {
        g_psBootImage = (am_bootloader_image_t *)(AM_HAL_FLASH_TOTAL_SIZE - AM_HAL_FLASH_PAGE_SIZE);
    }
#endif

#ifdef MULTI_BOOT_OTA_DEBUG
    //
    // (Delete me!) -- RMA
    // Update the flash flag page for debug purpose only
    //
    am_bootloader_image_t FlagImage;
    FlagImage.pui32LinkAddress = (uint32_t*)0x00004000;
    FlagImage.ui32NumBytes = 0x00001430;
    FlagImage.ui32CRC = 0xb84e1fa0;
    FlagImage.ui32OverrideGPIO = 0xffffffff;
    FlagImage.ui32OverridePolarity = 0x00000000;
    FlagImage.pui32StackPointer = (uint32_t*)0x100003a0;
    FlagImage.pui32ResetVector = (uint32_t*)0x00004071;
    FlagImage.ui32Options = BOOT_NO_NEW_IMAGE;//BOOT_NEW_IMAGE_INTERNAL_FLASH;
    FlagImage.pui32StorageAddressNewImage = (uint32_t*)0x00008000;
    FlagImage.bEncrypted = false;
    
    am_bootloader_flag_page_update(&FlagImage, (uint32_t *)g_psBootImage);
#endif //MULTI_BOOT_OTA_DEBUG

#ifdef MULTI_BOOT_OTA_DEBUG
    //
    // (Delete me!) -- RMA
    // Interface test here
    // (available space: 499712 bytes, returns false for test length of 502768
    // and true for test length of 32768)
    //
    volatile uint32_t ui32TestStoreAddress = 0;
    volatile uint32_t ui32TestSpaceLeft = 0;
    volatile bool bResult;
    bResult = image_get_storage_information_internal(g_psBootImage, 
                                                        502768, //32768,
                                                        &ui32TestStoreAddress,
                                                        &ui32TestSpaceLeft);
#endif //MULTI_BOOT_OTA_DEBUG

#ifdef MULTI_BOOT_OTA_DEBUG
    //
    // (Delete me!) -- RMA
    // Interface test here
    // do not operation cross flash block (0/1), which flash write api does not support
    //
    for(uint16_t i = 0; i < 32*4; i++)
    {
        g_TestArray[i] = i+1;
    }
    bResult = image_flash_write_from_sram(0x40000, (uint32_t)g_TestArray, 32*4);

#endif //MULTI_BOOT_OTA_DEBUG

    //
    // Check the flag page to see if there's a valid image ready. We do this
    // before any system initialization so we can minimize the number of
    // configuration options we need to undo before calling the application.
    //
    // In this case, we only have the interrupt pin to un-configure before we
    // can safely run the main application.
    //
    if(am_bootloader_image_check(g_psBootImage))
    {
        am_hal_gpio_pin_config(INTERRUPT_PIN, AM_HAL_PIN_DISABLE);
        am_bootloader_image_run(g_psBootImage);
    }
    
    //
    // If we get here, we didn't have a valid image in the flag page, so we
    // need to go get one from a suitable boot host. Speed up the clocks and
    // start turning on peripherals.
    //
    am_hal_clkgen_sysclk_select(AM_HAL_CLKGEN_SYSCLK_MAX);

    //
    // Configure the board for low power.
    //
    am_bsp_low_power_init();

    //
    // Start systick to measure time for autobaud and for the IOS timeout.
    //
    am_hal_systick_load(0x00FFFFFF);
    am_hal_systick_start();

    //
    // Enable the IOS. Choose the correct protocol based on the state of pin 0.
    //
    setup_ios_interface();

    //
    // Enable interrupts so we can receive messages from the boot host.
    //
    am_hal_interrupt_master_enable();

    //
    // Wait for a few milliseconds to see if anyone will send us data.
    //
    while (g_bIOSActive || am_hal_systick_count() > 0x00B6C1FF)
    {
        //
        // Delay to avoid polling peripheral registers so frequently.
        //
        am_util_delay_ms(1);
    }

    //
    // Disable interrupts briefly to make sure the next few steps are
    // deterministically executed.
    //
    am_hal_interrupt_master_disable();

    //
    // If we didn't get any IOS packets, we'll move on to the UART option.
    //
    cleanup_ios_interface();

    //
    // Configure our RX pin as a GPIO input with a falling edge interrupt.
    //
    am_hal_gpio_pin_config(UART_RX_PIN, AM_HAL_GPIO_INPUT);
    am_hal_gpio_int_polarity_bit_set(UART_RX_PIN, AM_HAL_GPIO_FALLING);

    am_hal_gpio_int_clear(AM_HAL_GPIO_BIT(UART_RX_PIN));
    am_hal_gpio_int_enable(AM_HAL_GPIO_BIT(UART_RX_PIN));
    am_hal_interrupt_enable(AM_HAL_INTERRUPT_GPIO);

    //
    // Enable interrupts so we can receive messages from the boot host.
    //
    am_hal_interrupt_master_enable();

    //
    // Loop forever.
    //
    while(1)
    {
    }
}
