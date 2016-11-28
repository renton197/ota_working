//*****************************************************************************
//
//! @file freertos_fit.c
//!
//! @brief Example of the exactle_fit app running under FreeRTOS.
//!
//! This example implements a BLE heart rate sensor within the FreeRTOS
//! framework. To save power, this application is compiled without print
//! statements by default. To enable them, add the following project-level
//! macro definitions.
//!
//! AM_DEBUG_PRINTF
//! WSF_TRACE_ENABLED=1
//!
//! If enabled, debug messages will be sent over ITM.
//
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
// This application has a large number of common include files. For
// convenience, we'll collect them all together in a single header and include
// that everywhere.
//
//*****************************************************************************
#include "freertos_fit.h"

//*****************************************************************************
//
// Task handle for the initial setup task.
//
//*****************************************************************************
TaskHandle_t xSetupTask;

//*****************************************************************************
//
// High priority task to run immediately after the scheduler starts.
//
// This task is used for any global initialization that must occur after the
// scheduler starts, but before any functional tasks are running. This can be
// useful for enabling events, semaphores, and other global, RTOS-specific
// features.
//
//*****************************************************************************
void
setup_task(void *pvParameters)
{
    //
    // Print a debug message.
    //
    am_util_debug_printf("Running setup tasks...\r\n");

    //
    // Run setup functions.
    //
    RadioTaskSetup();

    //
    // Run the functional tasks
    //
    xTaskCreate(RadioTask, "RadioTask", 512, 0, 3, &radio_task_handle);

    //
    // The setup operations are complete, so suspend the setup task now.
    //
    vTaskSuspend(NULL);

    while (1);
}

//*****************************************************************************
//
// Initializes all tasks
//
//*****************************************************************************
void
run_tasks(void)
{
    //
    // Set some interrupt priorities before we create tasks or start the scheduler.
    //
    // Note: Timer priority is handled by the FreeRTOS kernel, so we won't
    // touch it here.
    //
    am_hal_interrupt_priority_set(AM_HAL_INTERRUPT_UART, configMAX_SYSCALL_INTERRUPT_PRIORITY);
    am_hal_interrupt_priority_set(AM_HAL_INTERRUPT_GPIO, configMAX_SYSCALL_INTERRUPT_PRIORITY);

    //
    // Create essential tasks.
    //
    xTaskCreate(sleep_task, "Sleep", 64, 0, tskIDLE_PRIORITY, &xSleepTask);
    xTaskCreate(setup_task, "Setup", 128, 0, 3, &xSetupTask);

    //
    // Start the scheduler.
    //
    vTaskStartScheduler();
}

//*****************************************************************************
//
// Enable printing to the console.
//
//*****************************************************************************
void
enable_print_interface(void)
{
    //
    // Initialize a debug printing interface.
    //
    am_hal_itm_enable();
    am_bsp_debug_printf_enable();
    am_util_debug_printf_init(am_hal_itm_print);
    am_util_stdio_terminal_clear();
}

//*****************************************************************************
//
// Main Function
//
//*****************************************************************************
int
main(void)
{

    //
    // Set the clock frequency
    //
    am_hal_clkgen_sysclk_select(AM_HAL_CLKGEN_SYSCLK_MAX);

    //
    // Initialize the board.
    //
    am_hal_mcuctrl_bucks_enable();
    am_hal_vcomp_disable();
    am_hal_mcuctrl_bandgap_disable();

    //
    // Enable printing to the console.
    //
#ifdef AM_DEBUG_PRINTF
    enable_print_interface();
#endif

    //
    // Initialize plotting interface.
    //
    am_util_debug_printf("FreeRTOS Fit Example\n");

    //
    // Run the application.
    //
    run_tasks();

    //
    // We shouldn't ever get here.
    //
    while (1)
    {
    }

}

