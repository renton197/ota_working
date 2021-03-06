//*****************************************************************************
//
//! @file exactle_fit.c
//!
//! @brief ExactLE Fit example.
//!
//! This example application implements the standard BLE HRP profile using the
//! ExactLE stack and the Dialog DA14581 BLE radio. This application is able to
//! communicate with standard heart-rate applications running on recent model
//! mobile devices.
//!
//! In this example implementation, the heart rate value is reported as a
//! constant "78", and the "kCals consumed" value is reported as a single
//! incrementing integer value. In a real application, these values could be
//! supplied by a heart-rate sensor and context-tracking software.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>

#include "wsf_types.h"
#include "wsf_trace.h"
#include "wsf_buf.h"

#include "hci_handler.h"
#include "dm_handler.h"
#include "l2c_handler.h"
#include "att_handler.h"
#include "smp_handler.h"
#include "l2c_api.h"
#include "att_api.h"
#include "smp_api.h"
#include "app_api.h"
#include "fit_api.h"
#include "hci_core.h"
#include "hci_drv.h"
#include "hci_drv_apollo.h"

#include "am_mcu_apollo.h"
#include "am_util.h"
#include "am_bsp.h"
#include "exactle_fit_amota_multi_boot_config.h"

#include "hci_apollo_config.h"

#include "fit_api.h"
#include "app_ui.h"

#include "binary_counter.h"

//*****************************************************************************
//
// Forward declarations.
//
//*****************************************************************************
void exactle_stack_init(void);
void scheduler_timer_init(void);
void update_scheduler_timers(void);
void set_next_wakeup(void);

//*****************************************************************************
//
// Flag page information.
//
//*****************************************************************************
am_bootloader_image_t *g_psBootImage = (am_bootloader_image_t *) FLAG_PAGE_LOCATION;

//*****************************************************************************
//
// Timer configuration macros.
//
//*****************************************************************************
#define MS_PER_TIMER_TICK           10  // Milliseconds per WSF tick
#define CLK_TICKS_PER_WSF_TICKS     5   // Number of CTIMER counts per WSF tick.

//*****************************************************************************
//
// WSF buffer pools.
//
//*****************************************************************************
#define WSF_BUF_POOLS               4

// Memory for the buffer pool
static uint32_t g_pui32BufMem[1024 / sizeof(uint32_t)];

// Default pool descriptor.
static wsfBufPoolDesc_t g_psPoolDescriptors[WSF_BUF_POOLS] =
{
    {  16,  8 },
    {  32,  4 },
    {  64,  6 },
    { 128,  2 }
};

//*****************************************************************************
//
// Tracking variable for the scheduler timer.
//
//*****************************************************************************
uint32_t g_ui32LastTime = 0;

//*****************************************************************************
//
// Interrupt flag for the stack timers.
//
//*****************************************************************************
bool g_bCounterTimerFlag = false;


//*****************************************************************************
//
// Initialization for the ExactLE stack.
//
//*****************************************************************************
void
exactle_stack_init(void)
{
    wsfHandlerId_t handlerId;

    //
    // Set up timers for the WSF scheduler.
    //
    scheduler_timer_init();
    WsfTimerInit();

    //
    // Initialize a buffer pool for WSF dynamic memory needs.
    //
    WsfBufInit(sizeof(g_pui32BufMem), (uint8_t*)g_pui32BufMem, WSF_BUF_POOLS, g_psPoolDescriptors);

    //
    // Initialize the WSF security service.
    //
    SecInit();
    SecAesInit();
    SecCmacInit();
    SecEccInit();

    //
    // Set up callback functions for the various layers of the ExactLE stack.
    //
    handlerId = WsfOsSetNextHandler(HciHandler);
    HciHandlerInit(handlerId);

    handlerId = WsfOsSetNextHandler(DmHandler);
    DmAdvInit();
    DmConnInit();
    DmConnSlaveInit();
    DmSecInit();
    DmSecLescInit();
    DmPrivInit();
    DmHandlerInit(handlerId);

    handlerId = WsfOsSetNextHandler(L2cSlaveHandler);
    L2cSlaveHandlerInit(handlerId);
    L2cInit();
    L2cSlaveInit();

    handlerId = WsfOsSetNextHandler(AttHandler);
    AttHandlerInit(handlerId);
    AttsInit();
    AttsIndInit();
    AttcInit();

    handlerId = WsfOsSetNextHandler(SmpHandler);
    SmpHandlerInit(handlerId);
    SmprInit();
    SmprScInit();
    HciSetMaxRxAclLen(100);

    handlerId = WsfOsSetNextHandler(AppHandler);
    AppHandlerInit(handlerId);

    handlerId = WsfOsSetNextHandler(FitHandler);
    FitHandlerInit(handlerId);
}

//*****************************************************************************
//
// Set up a pair of timers to handle the WSF scheduler.
//
//*****************************************************************************
void
scheduler_timer_init(void)
{
    //
    // One of the timers will run in one-shot mode and provide interrupts for
    // scheduled events.
    //
    am_hal_ctimer_clear(0, AM_HAL_CTIMER_TIMERA);
    am_hal_ctimer_config_single(0, AM_HAL_CTIMER_TIMERA,
                                (AM_HAL_CTIMER_INT_ENABLE |
                                 AM_HAL_CTIMER_LFRC_512HZ |
                                 AM_HAL_CTIMER_FN_ONCE));

    //
    // The other timer will run continuously and provide a constant time-base.
    //
    am_hal_ctimer_clear(0, AM_HAL_CTIMER_TIMERB);
    am_hal_ctimer_config_single(0, AM_HAL_CTIMER_TIMERB,
                                 (AM_HAL_CTIMER_LFRC_512HZ |
                                 AM_HAL_CTIMER_FN_CONTINUOUS));

    //
    // Start the continuous timer.
    //
    am_hal_ctimer_start(0, AM_HAL_CTIMER_TIMERB);

    //
    // Enable the timer interrupt.
    //
    am_hal_ctimer_int_enable(AM_HAL_CTIMER_INT_TIMERA0);
    am_hal_interrupt_enable(AM_HAL_INTERRUPT_CTIMER);
}

//*****************************************************************************
//
// Calculate the elapsed time, and update the WSF software timers.
//
//*****************************************************************************
void
update_scheduler_timers(void)
{
    uint32_t ui32CurrentTime, ui32ElapsedTime;

    //
    // Read the continuous timer.
    //
    ui32CurrentTime = am_hal_ctimer_read(0, AM_HAL_CTIMER_TIMERB);

    //
    // Figure out how long it has been since the last time we've read the
    // continuous timer. We should be reading often enough that we'll never
    // have more than one overflow.
    //
    ui32ElapsedTime = (ui32CurrentTime >= g_ui32LastTime ?
                       (ui32CurrentTime - g_ui32LastTime) :
                       (0x10000 + ui32CurrentTime - g_ui32LastTime));

    //
    // Check to see if any WSF ticks need to happen.
    //
    if ((ui32ElapsedTime / CLK_TICKS_PER_WSF_TICKS) > 0)
    {
        //
        // Update the WSF timers and save the current time as our "last
        // update".
        //
        WsfTimerUpdate(ui32ElapsedTime / CLK_TICKS_PER_WSF_TICKS);

        g_ui32LastTime = ui32CurrentTime;
    }
}

//*****************************************************************************
//
// Set a timer interrupt for the next upcoming scheduler event.
//
//*****************************************************************************
void
set_next_wakeup(void)
{
    bool_t bTimerRunning;
    wsfTimerTicks_t xNextExpiration;

    //
    // Stop and clear the scheduling timer.
    //
    am_hal_ctimer_stop(0, AM_HAL_CTIMER_TIMERA);
    am_hal_ctimer_clear(0, AM_HAL_CTIMER_TIMERA);

    //
    // Check to see when the next timer expiration should happen.
    //
    xNextExpiration = WsfTimerNextExpiration(&bTimerRunning);

    //
    // If there's a pending WSF timer event, set an interrupt to wake us up in
    // time to service it. Otherwise, set an interrupt to wake us up in time to
    // prevent a double-overflow of our continuous timer.
    //
    if (xNextExpiration)
    {
        am_hal_ctimer_period_set(0, AM_HAL_CTIMER_TIMERA,
                                 xNextExpiration * CLK_TICKS_PER_WSF_TICKS, 0);
    }
    else
    {
        am_hal_ctimer_period_set(0, AM_HAL_CTIMER_TIMERA, 0x8000, 0);
    }

    //
    // Start the scheduling timer.
    //
    am_hal_ctimer_start(0, AM_HAL_CTIMER_TIMERA);
}

//*****************************************************************************
//
// Interrupt handler for the CTIMERs
//
//*****************************************************************************
void
am_ctimer_isr(void)
{
    uint32_t ui32Status;

    //
    // Check and clear any active CTIMER interrupts.
    //
    ui32Status = am_hal_ctimer_int_status_get(true);

    //
    // Increment count and set limit based on the number of LEDs available.
    //
    if((ui32Status & AM_HAL_CTIMER_INT_TIMERA1) == AM_HAL_CTIMER_INT_TIMERA1)
    {
        am_hal_ctimer_int_clear(AM_HAL_CTIMER_INT_TIMERA1);
        if (++g_ui32TimerCount >= (1 << AM_BSP_NUM_LEDS))
        {
            //
            // Reset the global.
            //
            g_ui32TimerCount = 0;
        }

        //
        // counter timer interrupt occurred, set flag
        //
        g_bCounterTimerFlag = true;
    }
    else
    {
        am_hal_ctimer_int_clear(ui32Status);

    }
}

//*****************************************************************************
//
// Interrupt handler for the GPIO module
//
//*****************************************************************************
void
am_gpio_isr(void)
{
    uint64_t ui64Status;

    //
    // Check and clear the GPIO interrupt status
    //
    ui64Status = am_hal_gpio_int_status_get(true);
    am_hal_gpio_int_clear(ui64Status);

    //
    // Check to see if this was a UART wakeup event from the dialog radio.
    //
    if (ui64Status & AM_HAL_GPIO_BIT(AM_BSP_GPIO_UART_CTS))
    {
        //
        // If the radio is trying to wake up our UART, we should go ahead and
        // turn it on now.
        //
        HciDrvUartEnable();
        HciDrvUartFlowOn();
    }
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
    // Configure the system clock to run at 24 MHz
    //
    am_hal_clkgen_sysclk_select(AM_HAL_CLKGEN_SYSCLK_24MHZ);

    //
    // Configure the MCU for low power operation, but leave the LFRC on.
    //
    am_hal_mcuctrl_bucks_enable();
    am_hal_vcomp_disable();
    am_hal_mcuctrl_bandgap_disable();

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

    // init debug session
    am_util_stdio_printf_init((am_util_stdio_print_char_t) am_bsp_itm_string_print);
    am_bsp_pin_enable(ITM_SWO);
    am_hal_itm_enable();
    am_bsp_debug_printf_enable();
    am_util_stdio_terminal_clear();
    am_util_stdio_printf("Ambiq OTA Demo B\r\n");

    //
    // Boot the radio.
    //
    HciDrvRadioBoot(AM_BSP_UART_BTLE_INST);

    //
    // Initialize the main ExactLE stack.
    //
    exactle_stack_init();

    //
    // Start the "Fit" profile.
    //
    FitStart();

    // 
    // Adding initilization for binary_counter for debug purpose only
    //
    binary_counter_init();

    while (TRUE)
    {
        if(g_bCounterTimerFlag == true)
        {
            g_bCounterTimerFlag = false;
            
            //
            // Set the LEDs for binary counter.
            // use this for "add" version
            //
//            am_devices_led_array_out(am_bsp_psLEDs, AM_BSP_NUM_LEDS,
//                             g_ui32TimerCount);

            // use this for "sub" version
            am_devices_led_array_out(am_bsp_psLEDs, AM_BSP_NUM_LEDS,
                             (g_ui32TimerCount^0xffffffff));

            //
            // Go to deep sleep.
            //
            am_hal_sysctrl_sleep(AM_HAL_SYSCTRL_SLEEP_DEEP);

        }
        else
        {
            //
            // Calculate the elapsed time from our free-running timer, and update
            // the software timers in the WSF scheduler.
            //
            update_scheduler_timers();
            wsfOsDispatcher();

            //
            // Enable an interrupt to wake us up next time we have a scheduled event.
            //
            set_next_wakeup();


            am_hal_interrupt_master_disable();

            //
            // Check to see if the WSF routines are ready to go to sleep.
            //
            if (wsfOsReadyToSleep())
            {
                //
                // Attempt to shut down the UART. If we can shut it down
                // successfully, we can go to deep sleep. Otherwise, we'll need to
                // stay awake to finish processing the current packet.
                //
                if (HciDrvUartSafeShutdown())
                {
                    //
                    // Go to deep sleep.
                    //
                    am_hal_sysctrl_sleep(AM_HAL_SYSCTRL_SLEEP_DEEP);
                }
            }

            am_hal_interrupt_master_enable();

        }
    }
}
