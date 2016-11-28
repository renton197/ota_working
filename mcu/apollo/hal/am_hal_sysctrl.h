//*****************************************************************************
//
//! @file am_hal_sysctrl.h
//!
//! @brief Functions for interfacing with the M4F system control registers
//!
//! @addtogroup hal Hardware Abstraction Layer (HAL)
//! @addtogroup sysctrl System Control (SYSCTRL)
//! @ingroup hal
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_HAL_SYSCTRL_H
#define AM_HAL_SYSCTRL_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Definitions for sleep mode parameter
//
//*****************************************************************************
#define AM_HAL_SYSCTRL_SLEEP_DEEP       true
#define AM_HAL_SYSCTRL_SLEEP_NORMAL     false

//*****************************************************************************
//
// Macros to make intrinsics a little easier.
//
//*****************************************************************************
#if defined(__ARMCC_VERSION)
#define am_wfi() __wfi();

#elif defined(__IAR_SYSTEMS_ICC__)
#define am_wfi() asm("    wfi")

#else
#define am_wfi() __asm("    wfi")

#endif

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern void am_hal_sysctrl_sleep(bool bSleepDeep);
extern void am_hal_sysctrl_sleep_auto(void);
extern void am_hal_sysctrl_fpu_enable(void);
extern void am_hal_sysctrl_fpu_disable(void);
extern void am_hal_sysctrl_fpu_stacking_enable(bool bLazy);
extern void am_hal_sysctrl_fpu_stacking_disable(void);
extern void am_hal_sysctrl_aircr_reset(void);
#ifdef __cplusplus
}
#endif

#endif // AM_HAL_SYSCTRL_H

//*****************************************************************************
//
// End Doxygen group.
//! @}
//
//*****************************************************************************

