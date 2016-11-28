/*******************************************************************************
*                                                                              *
* Copyright (c) 2013 Ambiq Micro.                                              *
*                                                                              *
********************************************************************************
*                                                                              *
* File:     mcu_irq.c                                                          *
*                                                                              *
* Title:    Ambiq Micro MCU peripheral IRQ definitions.                        *
*                                                                              *
* Abstract: This module defines Ambiq Micro IRQs                               *
*           This module is expected to be included by mcu.h.                   *
*                                                                              *
* Date:     10/20/2013                                                         *
*                                                                              *
* Author:   Ron Hemphill                                                       *
*                                                                              *
* Target:   Ambiq MCU                                                          *
*                                                                              *
********************************************************************************
*                                                                              *
*******************************************************************************/

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************

#ifndef _MCU_IRQ_H_
#define _MCU_IRQ_H_

// *****************************************************************************
// Include files
// *****************************************************************************
#include "../am_mcu_apollo.h"


// *****************************************************************************
// Defines
// *****************************************************************************


// *************************************
// Peripheral IRQ definitions
// *************************************
#define AMBQ_IRQ_BOD                    (IRQ00_IRQn)    // Brownout detect
#define AMBQ_IRQ_WDT                    (IRQ01_IRQn)    // Watchdog Timer
#define AMBQ_IRQ_CLKCTRL                (IRQ02_IRQn)    // Clock Control
#define AMBQ_IRQ_VCOMP                  (IRQ03_IRQn)    // VComp
#define AMBQ_IRQ_IOSINT                 (IRQ04_IRQn)    // IO Slave Interrupt
#define AMBQ_IRQ_IOSREGACC              (IRQ05_IRQn)    // IO Slave Register Access
#define AMBQ_IRQ_IOM0                   (IRQ06_IRQn)    // IO Master 0
#define AMBQ_IRQ_IOM1                   (IRQ07_IRQn)    // IO Master 1
#define AMBQ_IRQ_ADC                    (IRQ08_IRQn)    // ADC
#define AMBQ_IRQ_GPIO                   (IRQ09_IRQn)    // GPIO
#define AMBQ_IRQ_CTIMER                 (IRQ10_IRQn)    // Counter/Timers
#define AMBQ_IRQ_UART                   (IRQ11_IRQn)    // UART
#define AMBQ_IRQ_RSVD12                 (IRQ12_IRQn)
#define AMBQ_IRQ_RSVD13                 (IRQ13_IRQn)
#define AMBQ_IRQ_RSVD14                 (IRQ14_IRQn)
#define AMBQ_IRQ_RSVD15                 (IRQ15_IRQn)

#define AMBQ_IRQ_BOD_MSK                (0x1 << AMBQ_IRQ_BOD)
#define AMBQ_IRQ_WDT_MSK                (0x1 << AMBQ_IRQ_WDT)
#define AMBQ_IRQ_CLKCTRL_MSK            (0x1 << AMBQ_IRQ_CLKCTRL)
#define AMBQ_IRQ_VCOMP_MSK              (0x1 << AMBQ_IRQ_VCOMP)
#define AMBQ_IRQ_IOSINT_MSK             (0x1 << AMBQ_IRQ_IOSINT)
#define AMBQ_IRQ_IOSREGACC_MSK          (0x1 << AMBQ_IRQ_IOSREGACC)
#define AMBQ_IRQ_IOM0_MSK               (0x1 << AMBQ_IRQ_IOM0)
#define AMBQ_IRQ_IOM1_MSK               (0x1 << AMBQ_IRQ_IOM1)
#define AMBQ_IRQ_ADC_MSK                (0x1 << AMBQ_IRQ_ADC)
#define AMBQ_IRQ_GPIO_MSK               (0x1 << AMBQ_IRQ_GPIO)
#define AMBQ_IRQ_CTIMER_MSK             (0x1 << AMBQ_IRQ_CTIMER)
#define AMBQ_IRQ_UART_MSK               (0x1 << AMBQ_IRQ_UART)



// *****************************************************************************
// Prototypes
// *****************************************************************************



// *****************************************************************************
// Globals
// *****************************************************************************


// *****************************************************************************
// Functions
// *****************************************************************************

#endif // _MCU_IRQ_H_
