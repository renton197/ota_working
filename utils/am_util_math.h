//*****************************************************************************
//
//! @file am_util_math.h
//!
//! @brief A few useful math functions
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_UTIL_MATH_H
#define AM_UTIL_MATH_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern uint8_t am_util_math_dec_to_bcd(uint8_t ui8DecimalByte);
extern uint8_t am_util_math_bcd_to_dec(uint8_t ui8BCDByte);

#ifdef __cplusplus
}
#endif

#endif // AM_UTIL_MATH_H

