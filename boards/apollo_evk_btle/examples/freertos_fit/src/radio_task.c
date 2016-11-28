//*****************************************************************************
//
//! @file radio_task.c
//!
//! @brief Task to handle radio operation.
//!
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************

//*****************************************************************************
//
// Global includes for this project.
//
//*****************************************************************************
#include "freertos_fit.h"

//*****************************************************************************
//
// WSF standard includes.
//
//*****************************************************************************
#include "wsf_types.h"
#include "wsf_trace.h"
#include "wsf_buf.h"
#include "wsf_timer.h"

//*****************************************************************************
//
// Includes for operating the ExactLE stack.
//
//*****************************************************************************
#include "hci_handler.h"
#include "dm_handler.h"
#include "l2c_handler.h"
#include "att_handler.h"
#include "smp_handler.h"
#include "l2c_api.h"
#include "att_api.h"
#include "smp_api.h"
#include "app_api.h"
#include "hci_core.h"
#include "hci_drv.h"
#include "hci_drv_apollo.h"

#include "hci_apollo_config.h"

//*****************************************************************************
//
// Includes for the ExactLE "fit" profile.
//
//*****************************************************************************
#include "fit_api.h"
#include "app_ui.h"

//*****************************************************************************
//
// Radio task handle.
//
//*****************************************************************************
TaskHandle_t radio_task_handle;

//*****************************************************************************
//
// Handle for Radio-related events.
//
//*****************************************************************************
EventGroupHandle_t xRadioEventHandle;

//*****************************************************************************
//
// Function prototypes
//
//*****************************************************************************
void exactle_stack_init(void);
void scheduler_timer_init(void);
void update_scheduler_timers(void);
void set_next_wakeup(void);

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
    WsfBufInit(sizeof(g_pui32BufMem), (uint8_t *)g_pui32BufMem, WSF_BUF_POOLS,
               g_psPoolDescriptors);

    //
    // Initialize the WSF security service.
    //
    WsfSecInit();

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
    am_hal_ctimer_clear(1, AM_HAL_CTIMER_TIMERA);
    am_hal_ctimer_config_single(1, AM_HAL_CTIMER_TIMERA,
                                (AM_HAL_CTIMER_INT_ENABLE |
                                 AM_HAL_CTIMER_LFRC_512HZ |
                                 AM_HAL_CTIMER_FN_ONCE));

    //
    // The other timer will run continuously and provide a constant time-base.
    //
    am_hal_ctimer_clear(1, AM_HAL_CTIMER_TIMERB);
    am_hal_ctimer_config_single(1, AM_HAL_CTIMER_TIMERB,
                                (AM_HAL_CTIMER_LFRC_512HZ |
                                 AM_HAL_CTIMER_FN_CONTINUOUS));

    //
    // Start the continuous timer.
    //
    am_hal_ctimer_start(1, AM_HAL_CTIMER_TIMERB);

    //
    // Enable the timer interrupt.
    //
    am_hal_ctimer_int_enable(AM_HAL_CTIMER_INT_TIMERA1);
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
    ui32CurrentTime = am_hal_ctimer_read(1, AM_HAL_CTIMER_TIMERB);

    //
    // Figure out how long it has been since the last time we've read the
    // continuous timer. We should be reading often enough that we'll never
    // have more than one overflow.
    //
    ui32ElapsedTime = ui32CurrentTime - g_ui32LastTime;

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
    am_hal_ctimer_stop(1, AM_HAL_CTIMER_TIMERA);
    am_hal_ctimer_clear(1, AM_HAL_CTIMER_TIMERA);

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
        am_hal_ctimer_period_set(1, AM_HAL_CTIMER_TIMERA,
                                 xNextExpiration * CLK_TICKS_PER_WSF_TICKS, 0);
    }
    else
    {
        am_hal_ctimer_period_set(1, AM_HAL_CTIMER_TIMERA, 0x8000, 0);
    }

    //
    // Start the scheduling timer.
    //
    am_hal_ctimer_start(1, AM_HAL_CTIMER_TIMERA);
}

//*****************************************************************************
//
// Interrupt handler for the CTIMERs
//
//*****************************************************************************
void
radio_timer_handler(uint32_t ui32Status)
{
    BaseType_t xHigherPriorityTaskWoken, xResult;

    if (ui32Status & AM_HAL_CTIMER_INT_TIMERA1)
    {
        //
        // Set an event to wake up the radio task.
        //
        xHigherPriorityTaskWoken = pdFALSE;

        xResult = xEventGroupSetBitsFromISR(xRadioEventHandle, 1,
                                            &xHigherPriorityTaskWoken);

        //
        // If the radio task is higher-priority than the context we're currently
        // running from, we should yield now and run the radio task.
        //
        if (xResult != pdFAIL)
        {
            portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
        }
    }
}

//*****************************************************************************
//
// UART interrupt handler.
//
//*****************************************************************************
void
am_uart_isr(void)
{
    uint32_t ui32Status;
    BaseType_t xHigherPriorityTaskWoken, xResult;

    //
    // Read and save the interrupt status, but clear out the status register.
    //
    ui32Status = AM_REGn(UART, 0, MIS);
    AM_REGn(UART, 0, IEC) = ui32Status;

    //
    // Allow the HCI driver to respond to the interrupt.
    //
    HciDrvUartISR(ui32Status);

    //
    // Send an event to wake up the radio task.
    //
    xHigherPriorityTaskWoken = pdFALSE;

    xResult = xEventGroupSetBitsFromISR(xRadioEventHandle, 1,
                                        &xHigherPriorityTaskWoken);

    //
    // If the radio task is higher-priority than the context we're currently
    // running from, we should yield now and run the radio task.
    //
    if (xResult != pdFAIL)
    {
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

//*****************************************************************************
//
// Interrupt handler for the CTS pin
//
//*****************************************************************************
void
radio_cts_handler(void)
{
    BaseType_t xHigherPriorityTaskWoken, xResult;

    //
    // If the radio is trying to wake up our UART, we should turn it on.
    //
    HciDrvUartEnable();
    HciDrvUartFlowOn();

    //
    // Send an event to the main radio task
    //
    xHigherPriorityTaskWoken = pdFALSE;

    xResult = xEventGroupSetBitsFromISR(xRadioEventHandle, 1,
                                        &xHigherPriorityTaskWoken);

    //
    // If the radio task is higher-priority than the context we're currently
    // running from, we should yield now and run the radio task.
    //
    if (xResult != pdFAIL)
    {
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

//*****************************************************************************
//
// Perform initial setup for the radio task.
//
//*****************************************************************************
void
RadioTaskSetup(void)
{
    am_util_debug_printf("RadioTask: setup\r\n");

    //
    // Create an event handle for our wake-up events.
    //
    xRadioEventHandle = xEventGroupCreate();

    //
    // Make sure we actually allocated space for the events we need.
    //
    while (xRadioEventHandle == NULL);
    
    //
    // Boot the radio.
    //
    HciDrvRadioBoot(AM_BSP_UART_BTLE_INST);
}

//*****************************************************************************
//
// Short Description.
//
//*****************************************************************************
void
RadioTask(void *pvParameters)
{
    //
    // Register an interrupt handler to turn on the UART every time we get a
    // falling edge on CTS.
    //
    am_hal_gpio_int_register(AM_BSP_GPIO_UART_CTS, radio_cts_handler);

#if WSF_TRACE_ENABLED == TRUE
    //
    // Enable ITM
    //
    am_util_debug_printf("Starting wicentric trace:\n\n");
#endif

    //
    // Initialize the main ExactLE stack.
    //
    exactle_stack_init();

    //
    // Start the "Fit" profile.
    //
    FitStart();

    while (1)
    {
        //
        // Calculate the elapsed time from our free-running timer, and update
        // the software timers in the WSF scheduler.
        //
        update_scheduler_timers();
        wsfOsDispatcher();
        
        //
        // Enable an interrupt to wake us up next time we have a scheduled
        // event.
        //
        set_next_wakeup();
        
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
                // Wait for an event to be posted to the Radio Event Handle.
                //
                xEventGroupWaitBits(xRadioEventHandle, 1, pdTRUE,
                                    pdFALSE, portMAX_DELAY);
            }
        }
    }
}
