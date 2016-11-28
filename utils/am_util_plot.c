//*****************************************************************************
//
//! @file am_util_plot.c
//!
//! @brief A few useful plot functions to be used with AM Flash.
//!
//! Functions for providing AM Flash with the correct data enabling real-time
//! plotting.
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
#include <stdarg.h>
#include "hal/am_hal_itm.h"
#include "am_util_stdio.h"
#include "am_util_plot.h"

//*****************************************************************************
//
// Globals
//
//*****************************************************************************
// variable to keep track if we need to send a sync packet.
uint32_t g_ui32Sync = 0;

//*****************************************************************************
//
//! @brief Initializes the plot interface (ITM)
//!
//! This function initializes the ITM to allow for plotting.
//!
//! @returns None
//
//*****************************************************************************
void
am_util_plot_init(void)
{
    //
    // Enable the ITM.
    //
    am_hal_itm_enable();

    //
    // Initialize the printf interface for ITM/SWO output
    //
    am_util_stdio_printf_init((am_util_stdio_print_char_t) am_hal_itm_print);
}

//*****************************************************************************
//
//! @brief Plots an integer using AM Flash as the viewer.
//!
//! @param ui32Trace - trace number.
//! @param i32Value - value to plot.
//!
//! This function will plot a value to the desired trace. Valid values for
//! ui32Trace are:
//!
//! AM_UTIL_PLOT_0
//! AM_UTIL_PLOT_1
//! AM_UTIL_PLOT_2
//! AM_UTIL_PLOT_3
//!
//! @returns None
//
//*****************************************************************************
void
am_util_plot_int(uint32_t ui32Trace, int32_t i32Value)
{
    if (g_ui32Sync == 0)
    {
        //
        // Send Sync.
        //
        am_hal_itm_sync_send();

        //
        // Reset sync count.
        //
        g_ui32Sync = AM_UTIL_PLOT_SYNC_SEND;
    }
    else
    {
        g_ui32Sync--;
    }

    //
    // Write to the stimulus register.
    //
    am_hal_itm_stimulus_reg_word_write(ui32Trace, i32Value);
}

//*****************************************************************************
//
//! @brief Plots an byte using AM Flash as the veiwer.
//!
//! @param ui32Trace - trace number.
//! @param ui8Value - byte value to plot.
//!
//! This function will plot a byte value to the desired trace. If your plot
//! value fits into a byte, use this function as the ITM traffic can be reduced
//! by a factor of 4 over am_util_plot_int().  Valid values for ui32Trace
//! are:
//!
//! AM_UTIL_PLOT_0
//! AM_UTIL_PLOT_1
//! AM_UTIL_PLOT_2
//! AM_UTIL_PLOT_3
//!
//! @returns None
//
//*****************************************************************************
void
am_util_plot_byte(uint32_t ui32Trace, uint8_t ui8Value)
{
    if (g_ui32Sync == 0)
    {
        //
        // Send Sync.
        //
        am_hal_itm_sync_send();

        //
        // Reset sync count.
        //
        g_ui32Sync = AM_UTIL_PLOT_SYNC_SEND;
    }
    else
    {
        g_ui32Sync--;
    }

    //
    // Write to the stimulus register.
    //
    am_hal_itm_stimulus_reg_byte_write(ui32Trace, ui8Value);
}
