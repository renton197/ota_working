//*****************************************************************************
//
//! @file am_util_delay.c
//!
//! @brief A few useful delay functions.
//!
//! Functions for fixed delays.
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
#include "hal/am_hal_clkgen.h"
#include "am_util_delay.h"

//*****************************************************************************
//
//! @brief Delays for a desired amount of cycles.
//!
//! @param ui32Cycles - Desired number of cycles to delay for.
//!
//! This function will delay for a number of cycles.
//!
//! @note - the number of cycles this function takes to execute is
//! approximately ~3. Therefore, ui32Cycles will be ~3x what is passed.
//!
//! For example, a ui32Cycles value of 100 will delay for 300 cycles.
//!
//! @returns None
//
//*****************************************************************************
#ifdef gcc
void __attribute__((naked))
am_util_delay_cycles(uint32_t ui32Cycles)
{
    __asm("    subs    r0, #1\n"
          "    bne     am_util_delay_cycles\n"
          "    bx      lr");
}
#endif
#ifdef keil
__asm void
am_util_delay_cycles(uint32_t ui32Cycles)
{
    SUBS    R0, #1
    BNE     am_util_delay_cycles
    BX      LR
}
#endif
#ifdef iar
void
am_util_delay_cycles(uint32_t ui32Cycles)
{
    asm("SUBS    R0, #1");
    asm("BNE.N     am_util_delay_cycles");
    asm("BX      LR");
}
#endif

//*****************************************************************************
//
//! @brief Delays for a desired amount of milliseconds.
//!
//! @param ui32MilliSeconds - number of milliseconds to delay for.
//!
//! This function will delay for a number of milliseconds.
//!
//! @returns None
//
//*****************************************************************************
void
am_util_delay_ms(uint32_t ui32MilliSeconds)
{
    uint32_t ui32Cycles = ui32MilliSeconds * (am_hal_clkgen_sysclk_get() / 3000);

    //
    // Call the cycle delay
    //
    am_util_delay_cycles(ui32Cycles);
}

//*****************************************************************************
//
//! @brief Delays for a desired amount of microseconds.
//!
//! @param ui32MicroSeconds - number of microseconds to delay for.
//!
//! This function will delay for a number of microseconds.
//!
//! @returns None
//
//*****************************************************************************
void
am_util_delay_us(uint32_t ui32MicroSeconds)
{
    uint32_t ui32Cycles = ui32MicroSeconds * (am_hal_clkgen_sysclk_get() / 3000000);

    //
    // Call the cycle delay
    //
    am_util_delay_cycles(ui32Cycles);
}
