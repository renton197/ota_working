//*****************************************************************************
//
//! @file am_hal_global.c
//!
//! @brief Locate global variables here.
//!
//! This module contains global variables that are used throughout the HAL.
//!
//! One use in particular is that it uses a global HAL flags variable that
//! contains flags used in various parts of the HAL.
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
#include "am_mcu_apollo.h"

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint32_t volatile g_ui32HALflags = 0x00000000;
