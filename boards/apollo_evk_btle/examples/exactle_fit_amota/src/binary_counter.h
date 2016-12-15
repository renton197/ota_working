//*****************************************************************************
//
//! @file binary_counter.h
//!
//! @brief This file describes the external calls and variable definitions 
//!         of the binary counter for debug purpose/
//! --RMA
//
//*****************************************************************************

#include <stdint.h>
#include "am_bsp.h"

#ifndef BINARY_COUNTER_H
#define BINARY_COUNTER_H

//*****************************************************************************
//
// External function declaration
//
//*****************************************************************************
extern void binary_counter_init(void);
extern void timerA1_init(void);
//*****************************************************************************
//
// External variable declaration
//
//*****************************************************************************
extern volatile uint32_t g_ui32TimerCount;

#endif // BINARY_COUNTER_H
