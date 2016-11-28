//*****************************************************************************
//
//! @file am_util_math.c
//!
//! @brief A few useful math functions.
//!
//! Functions for performing some number manipulation.
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
#include "am_util_math.h"

//*****************************************************************************
//
//! @brief Converts a Binary Coded Decimal (BCD) byte to its Decimal form.
//!
//! @param ui8BCDByte is a BCD byte.
//!
//! This function is useful when working with RTC's as they tend to be in BCD 
//! format.
//!
//! @returns the BCD byte converted to Decimal
//
//*****************************************************************************
uint8_t
am_util_math_bcd_to_dec(uint8_t ui8BCDByte)
{
  return (((ui8BCDByte & 0xF0) >> 4) * 10) + (ui8BCDByte & 0x0F);
}

//*****************************************************************************
//
//! @brief Converts a Decimal byte to its Binary Coded Decimal (BCD) form.
//!
//! @param ui8DecimalByte is a Decimal byte.
//!
//! This function is useful when working with RTC's as they tend to be in BCD 
//! format.
//!
//! @returns the Decimal byte converted to BCD.
//
//*****************************************************************************
uint8_t
am_util_math_dec_to_bcd(uint8_t ui8DecimalByte)
{
  return (((ui8DecimalByte / 10) << 4) | (ui8DecimalByte % 10));
}

