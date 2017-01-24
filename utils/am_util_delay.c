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
#include "hal/am_hal_flash.h"
#include "am_util_delay.h"

//*****************************************************************************
//
//! @brief Delays for a desired amount of loops.
//!
//! @param ui32CycleLoops - Desired number of cycle loops to delay for.
//!
//! This function will delay for a number of cycle loops.
//!
//! @note - the number of cycles each loops takes to execute is approximately 3.
//! Therefore the actual number of cycles executed will be ~3x ui32CycleLoops.
//!
//! For example, a ui32CycleLoops value of 100 will delay for 300 cycles.
//!
//! @returns None
//
//*****************************************************************************
void
am_util_delay_cycles(uint32_t ui32Iterations)
{
    //
    // Call the BOOTROM cycle delay function
    //
    am_hal_flash_delay(ui32Iterations);
}

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
    uint32_t ui32Loops = ui32MilliSeconds *
                          (am_hal_clkgen_sysclk_get() / 3000);

    //
    // Call the BOOTROM cycle delay function
    //
    am_hal_flash_delay(ui32Loops);
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
    uint32_t ui32Loops = ui32MicroSeconds *
                          (am_hal_clkgen_sysclk_get() / 3000000);

    //
    // Call the BOOTROM cycle delay function
    //
    am_hal_flash_delay(ui32Loops);
}
