//*****************************************************************************
//
//! @file am_hal_debug.h
//!
//! @brief Useful macros for debugging.
//!
//! These functions and macros were created to assist with debugging. They are
//! intended to be as unintrusive as possible and designed to be removed from
//! the compilation of a project when they are no longer needed.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_HAL_DEBUG_H
#define AM_HAL_DEBUG_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Debug assert macros.
//
//*****************************************************************************
#ifndef AM_HAL_DEBUG_NO_ASSERT

#define am_hal_debug_assert_msg(bCondition, pcMessage)                        \
    if ( !(bCondition))  am_hal_debug_error(__FILE__, __LINE__, pcMessage)

#define am_hal_debug_assert(bCondition)                                       \
    if ( !(bCondition))  am_hal_debug_error(__FILE__, __LINE__, 0)

#else

#define am_hal_debug_assert_msg(bCondition, pcMessage)
#define am_hal_debug_assert(bCondition)

#endif // AM_DEBUG_ASSERT

//*****************************************************************************
//
// External function prototypes.
//
//*****************************************************************************
extern void am_hal_debug_error(const char *pcFile, uint32_t ui32Line,
                               const char *pcMessage);

#ifdef __cplusplus
}
#endif

#endif // AM_HAL_DEBUG_H

