//*****************************************************************************
//
//! @file am_util_delay.h
//!
//! @brief A few useful delay functions
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_UTIL_DELAY_H
#define AM_UTIL_DELAY_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern void am_util_delay_cycles(uint32_t ui32Iterations);
extern void am_util_delay_ms(uint32_t ui32MilliSeconds);
extern void am_util_delay_us(uint32_t ui32MicroSeconds);

#ifdef __cplusplus
}
#endif

#endif // AM_UTIL_DELAY_H

