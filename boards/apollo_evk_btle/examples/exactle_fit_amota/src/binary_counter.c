//*****************************************************************************
//
//! @file binary_counter.c
//!
//! @brief Example that displays the timer count on the LEDs.
//!
//! This example increments a variable on every timer interrupt. The global
//! variable is used to set the state of the LEDs. The example sleeps otherwise.
//!
//! SWO is configured in 1M baud, 8-n-1 mode.
//
//*****************************************************************************

//*****************************************************************************
//
// Copyright (c) 2016, Ambiq Micro
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived from this
// software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// This is part of revision v1.2.2-238-g68ec99b-stable of the AmbiqSuite Development Package.
//
//*****************************************************************************

#include "am_mcu_apollo.h"
#include "am_bsp.h"
#include "am_util.h"

volatile uint32_t g_ui32TimerCount = 0;

//*****************************************************************************
//
// Timer configuration.
//
//*****************************************************************************
static am_hal_ctimer_config_t g_sTimer1 =
{
    // Don't link timers.
    0,

    // Set up Timer1A.
    (AM_HAL_CTIMER_FN_REPEAT |
     AM_HAL_CTIMER_INT_ENABLE    |
     AM_HAL_CTIMER_LFRC_32HZ),  //AM_HAL_CTIMER_LFRC_512HZ),//

    // No configuration for Timer1B.
    0,
};

//*****************************************************************************
//
// Function to initialize Timer A0 to interrupt every 1/4 second.
//
//*****************************************************************************
void
timerA1_init(void)
{
    uint32_t ui32Period;

    //
    // Enable the LFRC.
    //
    am_hal_clkgen_osc_start(AM_HAL_CLKGEN_OSC_LFRC);

    //
    // Set up timer A1.
    //
    am_hal_ctimer_clear(1, AM_HAL_CTIMER_TIMERA);
    am_hal_ctimer_config(1, &g_sTimer1);

    //
    // Set up timerA1 to 32Hz from LFRC divided to 1 second period.
    //
    ui32Period = 8;
    am_hal_ctimer_period_set(1, AM_HAL_CTIMER_TIMERA, ui32Period,
                             (ui32Period >> 1));

    //
    // Clear the timer Interrupt
    //
    am_hal_ctimer_int_clear(AM_HAL_CTIMER_INT_TIMERA1);
}

void binary_counter_init(void)
{
    //
    // Initialize LEDs on board
    //
    am_devices_led_array_init(am_bsp_psLEDs, AM_BSP_NUM_LEDS);
    
    //
    // TimerA1 init.
    //
    timerA1_init();

    //
    // Enable the timer Interrupt.
    //
    am_hal_ctimer_int_enable(AM_HAL_CTIMER_INT_TIMERA1);

    //
    // Enable the timer interrupt in the NVIC.
    //
    am_hal_interrupt_enable(AM_HAL_INTERRUPT_CTIMER);

    //
    // Start timer A1
    //
    am_hal_ctimer_start(1, AM_HAL_CTIMER_TIMERA);
}
