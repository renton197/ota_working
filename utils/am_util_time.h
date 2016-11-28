//*****************************************************************************
//
//! @file am_util_time.h
//!
//! @brief Functions useful for RTC, calendar, time, etc. computations.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_UTIL_TIME_H
#define AM_UTIL_TIME_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern int am_util_time_computeDayofWeek(int iYear, int iMonth, int iDay);

#ifdef __cplusplus
}
#endif

#endif // AM_UTIL_TIME_H

