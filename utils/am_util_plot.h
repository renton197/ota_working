//*****************************************************************************
//
//! @file am_util_plot.h
//!
//! @brief A few useful plot functions to be used with AM Flash.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_UTIL_PLOT_H
#define AM_UTIL_PLOT_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
//! @name Trace defines
//! @brief Trace defines for valid plot traces
//!
//! These macros should be used to specify which trace to update for plotting.
//! @{
//
//*****************************************************************************
#define AM_UTIL_PLOT_0              24
#define AM_UTIL_PLOT_1              25
#define AM_UTIL_PLOT_2              26
#define AM_UTIL_PLOT_3              27
//! @}

//
// Define for the frequency of sync packets.
//
#define AM_UTIL_PLOT_SYNC_SEND      64

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern void am_util_plot_init(void);
extern void am_util_plot_int(uint32_t ui32Trace, int32_t i32Value);
extern void am_util_plot_byte(uint32_t ui32Trace, uint8_t ui8Value);


#ifdef __cplusplus
}
#endif

#endif // AM_UTIL_PLOT_H

