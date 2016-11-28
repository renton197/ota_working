//*****************************************************************************
//
//! @file ios_boot_handlers.c
//!
//! @brief Boot related functions for the IOS interface.
//!
//! This file contains the main state machine for handling boot commands via
//! the I2C interface.
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
// Global variable to let the main loop know whether the IOS interface has been
// used yet.
//
//*****************************************************************************
volatile bool g_bIOSActive = false;

//*****************************************************************************
//
//! @brief Read an image start packet from the IOS LRAM
//!
//! @param psImage is the image structure to read the packet into.
//!
//! This function reads the IOS LRAM as a "new image" packet, and uses that
//! packet to fill in a bootloader image structure. The caller is responsible
//! for verifying the packet type before calling this function.
//!
//! @return true if the image parameters are acceptable.
//
//*****************************************************************************
static bool
image_start_packet_read(am_bootloader_image_t *psImage)
{
    uint32_t *pui32Packet;

    pui32Packet = (uint32_t *) am_hal_ios_pui8LRAM;

    //
    // Set the image structure parameters based on the information in the
    // packet.
    //
    psImage->pui32LinkAddress = (uint32_t *)(pui32Packet[1]);
    psImage->ui32NumBytes = pui32Packet[2];
    psImage->ui32CRC = pui32Packet[3];
    psImage->ui32OverrideGPIO = DEFAULT_OVERRIDE_GPIO;
    psImage->ui32OverridePolarity = DEFAULT_OVERRIDE_POLARITY;
    psImage->bEncrypted = 0;

    //
    // We'll need to fill in the stack pointer and reset vector a little later
    // in the process.
    //
    psImage->pui32StackPointer = 0;
    psImage->pui32ResetVector = 0;

    //
    // Check to make sure we're not overwriting the bootloader.
    //
    if((uint32_t) psImage->pui32LinkAddress < 0x4000)
    {
        return false;
    }

    //
    // Otherwise, the image is presumed to be reasonable. Set our global
    // variables based on the new image structure.
    //
    g_pui32WriteAddress = psImage->pui32LinkAddress;
    g_ui32BytesReceived = 0;
    g_ui32BytesInBuffer = 0;
    return true;
}

//*****************************************************************************
//
//! @brief Read an image start packet from the IOS LRAM
//!
//! @param psImage is the image structure to read the packet into.
//!
//! This function reads the IOS LRAM as a "new image" packet, and uses that
//! packet to fill in a bootloader image structure. The caller is responsible
//! for verifying the packet type before calling this function.
//!
//! @return None.
//
//*****************************************************************************
static void
image_data_packet_read(void)
{
    uint32_t i;
    uint8_t *pui8Src;
    uint32_t ui32Size, ui32CurrentPage, ui32CurrentBlock;

    //
    // Get the size information from the packet header, and set the src pointer
    // to the beginning of the actual data.
    //
    ui32Size = *((uint32_t *) (am_hal_ios_pui8LRAM + 4));
    pui8Src = (uint8_t *)(am_hal_ios_pui8LRAM + 8);

    //
    // Loop through the data, copying it into the global buffer.
    //
    for(i = 0; i < ui32Size; i++)
    {
        g_pui8RxBuffer[g_ui32BytesInBuffer] = *pui8Src++;

        //
        // Keep track of how much data we've copied into the SRAM buffer.
        //
        g_ui32BytesInBuffer++;
        g_ui32BytesReceived++;

        //
        // Whenever we hit a page boundary or the end of the image, we should
        // write to flash.
        //
        if(g_ui32BytesInBuffer == AM_HAL_FLASH_PAGE_SIZE ||
           g_ui32BytesReceived == g_sImage.ui32NumBytes)
        {
            //
            // Run a quick CRC on the received bytes, holding on to the result in a
            // global variable, so we can pick up where we left off on the next pass.
            //
            am_bootloader_partial_crc32(g_pui8RxBuffer, g_ui32BytesInBuffer, &g_ui32CRC);

            //
            // If this is the first block of our new image, we need to record
            // the reset vector and stack pointer information for inclusion in
            // the flag page.
            //
            if(g_ui32BytesReceived <= AM_HAL_FLASH_PAGE_SIZE)
            {
                g_sImage.pui32StackPointer = (uint32_t *)(g_pui32RxBuffer[0]);
                g_sImage.pui32ResetVector = (uint32_t *)(g_pui32RxBuffer[1]);
            }

            //
            // Figure out what page and block we're working on.
            //
            ui32CurrentPage =  AM_HAL_FLASH_ADDR2PAGE((uint32_t)g_pui32WriteAddress);
            ui32CurrentBlock = AM_HAL_FLASH_ADDR2INST((uint32_t)g_pui32WriteAddress);

            am_hal_flash_page_erase(AM_HAL_FLASH_PROGRAM_KEY,
                                        ui32CurrentBlock, ui32CurrentPage);

            //
            // Program the flash page with the data we just received.
            //
            am_hal_flash_program_main(AM_HAL_FLASH_PROGRAM_KEY, g_pui32RxBuffer,
                                      g_pui32WriteAddress, g_ui32BytesInBuffer / 4);

            //
            // Adjust the global variables.
            //
            g_pui32WriteAddress += (g_ui32BytesInBuffer / 4);
            g_ui32BytesInBuffer = 0;
        }
    }
}

//*****************************************************************************
//
// IO Slave Register Access ISR.
//
//*****************************************************************************
void
am_ioslave_acc_isr(void)
{
    uint32_t ui32Status;
    uint32_t *pui32Packet;

    //
    // Make sure the main loop knows that the IOS is currently in use.
    //
    g_bIOSActive = true;

    //
    // Set up a pointer for writing 32-bit aligned packets through the IO slave
    // interface.
    //
    pui32Packet = (uint32_t *) am_hal_ios_pui8LRAM;

    //
    // Check to see what caused this interrupt, then clear the bit from the
    // interrupt register.
    //
    ui32Status = am_hal_ios_access_int_status_get(false);
    am_hal_ios_access_int_clear(ui32Status);

    if(ui32Status & AM_HAL_IOS_ACCESS_INT_03)
    {
        am_hal_gpio_out_bit_set(INTERRUPT_PIN);

        //
        // Figure out what to do next based on the packet header.
        //
        switch(pui32Packet[0])
        {
            case AM_BOOTLOADER_NEW_IMAGE:

                //
                // Parse the image packet, and store the result to the global
                // image structure.
                //
                g_bImageValid = image_start_packet_read(&g_sImage);

                //
                // Make sure the image packet had reasonable contents. If it
                // didn't, we need to let the host know.
                //
                if(g_bImageValid)
                {
                    //
                    // Good image; Send back a "READY" packet.
                    //
                    pui32Packet[0] = AM_BOOTLOADER_READY;
                    am_hal_gpio_out_bit_clear(INTERRUPT_PIN);
                }
                else
                {
                    //
                    // Bad image; Send back an error.
                    //
                    pui32Packet[0] = AM_BOOTLOADER_ERROR;
                    am_hal_gpio_out_bit_clear(INTERRUPT_PIN);
                }

                break;

            case AM_BOOTLOADER_SET_OVERRIDE_CMD:
                //
                // Set the override GPIO settings based on the packet
                // information.
                //
                g_sImage.ui32OverrideGPIO = pui32Packet[1];
                g_sImage.ui32OverridePolarity = pui32Packet[2];

                //
                // Send back a "READY" packet.
                //
                pui32Packet[0] = AM_BOOTLOADER_READY;
                am_hal_gpio_out_bit_clear(INTERRUPT_PIN);
                break;

            case AM_BOOTLOADER_NEW_PACKET:
                //
                // Only take new packets if our image structure is valid.
                //
                if(!g_bImageValid)
                {
                    pui32Packet[0] = AM_BOOTLOADER_ERROR;
                    am_hal_gpio_out_bit_clear(INTERRUPT_PIN);
                    break;
                }

                //
                // Parse the reset of the packet sitting in the IOS LRAM.
                //
                image_data_packet_read();

                //
                // If this packet completed the image...
                //
                if(g_ui32BytesReceived == g_sImage.ui32NumBytes)
                {
                    //
                    // Check this against the CRC we received from the host
                    // earlier. Report the status (either good or bad) back to
                    // the host.
                    //
                    pui32Packet[0] = ((g_ui32CRC == g_sImage.ui32CRC) ?
                                      AM_BOOTLOADER_IMAGE_COMPLETE :
                                      AM_BOOTLOADER_BAD_CRC);

                    //
                    // Assert the interrupt line so the host knows we have a
                    // message.
                    //
                    am_hal_gpio_out_bit_clear(INTERRUPT_PIN);
                }
                else
                {
                    //
                    // If this wasn't the end of the image, just send back a
                    // "READY" packet.
                    //
                    pui32Packet[0] = AM_BOOTLOADER_READY;
                    am_hal_gpio_out_bit_clear(INTERRUPT_PIN);
                }

                break;

            case AM_BOOTLOADER_RESET:
                //
                // Write the flag page.
                //
                am_bootloader_flag_page_update(&g_sImage, (uint32_t *)g_psBootImage);

            case AM_BOOTLOADER_RESTART:
                //
                // Perform a software reset.
                //
                am_hal_reset_poi();

                //
                // Wait for the reset to take effect.
                //
                while(1);

            case AM_BOOTLOADER_BL_VERSION_CMD:
                //
                // Respond with the version number.
                //
                pui32Packet[0] = AM_BOOTLOADER_BL_VERSION;
                pui32Packet[1] = AM_BOOTLOADER_VERSION_NUM;
                am_hal_gpio_out_bit_clear(INTERRUPT_PIN);
                break;

            case AM_BOOTLOADER_ACK_CMD:
            case AM_BOOTLOADER_NAK_CMD:
                break;

            default:
                break;
        }
    }
}

//*****************************************************************************
//
// SPI Slave Configuration
//
//*****************************************************************************
static am_hal_ios_config_t g_sIOSConfig =
{
    // Configure the IOS in SPI mode.
    .ui32InterfaceSelect = AM_HAL_IOS_USE_SPI,

    // Eliminate the "read-only" section, so an external host can use the
    // entire "direct write" section.
    .ui32ROBase = 0x78,

    // Set the FIFO base to the maximum value, making the "direct write"
    // section as big as possible.
    .ui32FIFOBase = 0x78,

    // We don't need any RAM space, so extend the FIFO all the way to the end
    // of the LRAM.
    .ui32RAMBase = 0x100,
};

//*****************************************************************************
//
// Configure the SPI slave.
//
//*****************************************************************************
void
setup_ios_interface(void)
{
    //
    // Check pin 0 to see if we should be using SPI or I2C
    //
    am_hal_gpio_pin_config(0, AM_HAL_GPIO_INPUT);
    if (am_hal_gpio_input_bit_read(0))
    {
        //
        // If the clock line is high, we'll assume I2C.
        //
        am_hal_gpio_pin_config(0, AM_HAL_PIN_0_SLSCL);
        am_hal_gpio_pin_config(1, AM_HAL_PIN_1_SLSDA);

        g_sIOSConfig.ui32InterfaceSelect = (AM_HAL_IOS_USE_I2C |
                                            AM_HAL_IOS_I2C_ADDRESS(0x20));
    }
    else
    {
        //
        // If the clock line is low, we'll assume SPI.
        //
        am_hal_gpio_pin_config(0, AM_HAL_PIN_0_SLSCK);
        am_hal_gpio_pin_config(1, AM_HAL_PIN_1_SLMISO);
        am_hal_gpio_pin_config(2, AM_HAL_PIN_2_SLMOSI);
        am_hal_gpio_pin_config(3, AM_HAL_PIN_3_SLnCE);

        g_sIOSConfig.ui32InterfaceSelect = AM_HAL_IOS_USE_SPI;
    }

    //
    // Make sure the interrupt pin is set up correctly
    //
    am_hal_gpio_out_bit_set(INTERRUPT_PIN);
    am_hal_gpio_pin_config(INTERRUPT_PIN, AM_HAL_PIN_OUTPUT);

    //
    // Configure the IOS interface and LRAM structure.
    //
    am_hal_ios_config(&g_sIOSConfig);

    //
    // Clear out any IOS register-access interrupts that may be active, and
    // enable interrupts for the registers we're interested in.
    //
    am_hal_ios_access_int_clear(AM_HAL_IOS_ACCESS_INT_ALL);
    am_hal_ios_access_int_enable(AM_HAL_IOS_ACCESS_INT_03);

    am_hal_ios_int_clear(AM_HAL_IOS_INT_ALL);
    am_hal_ios_int_enable(AM_HAL_IOS_INT_FSIZE);

    //
    // Set the bit in the NVIC to accept access interrupts from the IO Slave.
    //
    am_hal_interrupt_enable(AM_HAL_INTERRUPT_IOSACC);
    am_hal_interrupt_enable(AM_HAL_INTERRUPT_IOSLAVE);

    //
    // Notify the host that we're ready to receive data.
    //
    *((uint32_t *) am_hal_ios_pui8LRAM) = AM_BOOTLOADER_READY;
    am_hal_gpio_out_bit_clear(INTERRUPT_PIN);
}

//*****************************************************************************
//
// Clean the slave.
//
//*****************************************************************************
void
cleanup_ios_interface(void)
{
    am_hal_gpio_pin_config(0, AM_HAL_PIN_DISABLE);
    am_hal_gpio_pin_config(1, AM_HAL_PIN_DISABLE);
    am_hal_gpio_pin_config(2, AM_HAL_PIN_DISABLE);
    am_hal_gpio_pin_config(3, AM_HAL_PIN_DISABLE);
    am_hal_gpio_pin_config(INTERRUPT_PIN, AM_HAL_PIN_DISABLE);
}

//*****************************************************************************
//
// IO Slave Main ISR.
//
//*****************************************************************************
void
am_ioslave_ios_isr(void)
{
    uint32_t ui32Status;

    //
    // Check to see what caused this interrupt, then clear the bit from the
    // interrupt register.
    //
    ui32Status = am_hal_ios_int_status_get(false);
    am_hal_ios_int_clear(ui32Status);

    //
    // Service the I2C slave FIFO if necessary.
    //
    am_hal_ios_fifo_service(ui32Status);
}

//*****************************************************************************
//
// IO Slave handshake
//
//*****************************************************************************
bool
am_ioslave_handshake(uint32_t ui32Timeout)
{
    uint32_t i;
    uint32_t *pui32Packet;
    bool bReturnVal = false;

    //
    // Set up a pointer for writing 32-bit aligned packets through the IO slave
    // interface.
    //
    pui32Packet = (uint32_t *) am_hal_ios_pui8LRAM;
    am_hal_gpio_out_bit_set(INTERRUPT_PIN);

    for (i = 0; i < ui32Timeout; i++)
    {
        if (pui32Packet[0] == 0x5A)
        {
            bReturnVal = true;

            //
            // Notify the host that we're ready to receive data.
            //
            *((uint32_t *) am_hal_ios_pui8LRAM) = AM_BOOTLOADER_READY;
            am_hal_gpio_out_bit_clear(INTERRUPT_PIN);
            break;
        }
        am_util_delay_us(1);
    }
    return bReturnVal;
}
