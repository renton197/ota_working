/*******************************************************************************
*                                                                              *
*   Copyright (c) 2013-2014 Ambiq Micro                                        *
*                                                                              *
********************************************************************************
*                                                                              *
*   File:       ctimer.h                                                       *
*                                                                              *
*   Title:      Ambiq Micro MCU register definitions                           *
*                                                                              *
*   Abstract:   This module contains macros to facilitate access to the        *
*               Ambiq MCU register set.                                        *
*                                                                              *
*   Date:       03/27/2014 (date this file was auto-generated)                 *
*                                                                              *
*   Author:     Auto-generated                                                 *
*                                                                              *
*   Target:     Ambiq Micro MCU                                                *
*                                                                              *
********************************************************************************
*                                                                              *
*   The following naming conventions are followed for these macros:            *
*       XX_<devname>_<regname>_<bitfield>_<suffix>                             *
*                                                                              *
*   XX specifies the define or macro.                                          *
*       BFP defines a bitfield position (LSB).                                 *
*       BFM defines a bitfield mask.                                           *
*       BFN - BitField Number of bits (Width)                                  *
*       BFD - BitField Default value                                           *
*       BFV moves a given value to the correct position for the bitfield.      *
*       BFX extracts a bitfield from a given value and moves it to bit0.       *
*       BFC indicates a bitfield enumeration constant.                         *
*   Read or write directly to the register.                                    *
*       BFW - BitField Write                                                   *
*             Write a value to only a particular bitfield in the register      *
*             (all other bitfields retain their previous value).               *
*       BFR - BitField Read                                                    *
*             Reads a value from a bitfield in the actual register.            *
*       BFS - Bit field set (only if specified in the source file)             *
*             Write a bitfield with its mask value (all other bfs written w/0).*
*       REG read, write or define an entire register.                          *
*                                                                              *
*   The following conventions are used as the suffix of the REG_ macros:       *
*       ADDR   = The address of the register.                                  *
*       RD()   = Read the register.                                            *
*       WR(v)  = Write the entire register with the value given by v.          *
*       CLR(m) = Clear the register bits given by the mask, m.                 *
*       SET(m) = Set the register bits given by the mask, m.                   *
*       DEF    = The default value for the register.                           *
*                                                                              *
*   Notes:                                                                     *
*   - These macros are not atomic.                                             *
*   - For efficiency, BFW (BitField Write) commands in single-field registers  *
*     actually perform a simple write to the entire register with the reserved *
*     field, if any, set to zero.                                              *
*                                                                              *
*******************************************************************************/

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************


#ifndef _CTIMER_H
#define _CTIMER_H     1

#include "../am_mcu_apollo.h"



// *****************************************************************************
//                                                                             *
//  CTIMER_CTTMR0 - Counter/Timer Register                                     *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CTTMRB0                    : 16;
        unsigned CTTMRA0                    : 16;
    } B;
} reg_ctimer_cttmr0_t;

#define REG_CTIMER_CTTMR0_ADDR                  (REG_CTIMER_BASEADDR + 0x00000000UL)
#define REG_CTIMER_CTTMR0                       (*(volatile reg_ctimer_cttmr0_t *) REG_CTIMER_CTTMR0_ADDR)
#define REG_CTIMER_CTTMR0_RD()                  (REG_CTIMER_CTTMR0.U32)
#define REG_CTIMER_CTTMR0_WR(v)                 (REG_CTIMER_CTTMR0.U32 = (v))
#define REG_CTIMER_CTTMR0_CLR(m)                (REG_CTIMER_CTTMR0.U32 = ((REG_CTIMER_CTTMR0.U32) & ~(m)))
#define REG_CTIMER_CTTMR0_SET(m)                (REG_CTIMER_CTTMR0.U32 = ((REG_CTIMER_CTTMR0.U32) | (m)))
#define REG_CTIMER_CTTMR0_DEF                   0x00000000

#define BFP_CTIMER_CTTMR0_CTTMRB0               (16)                    /* bitfield lsb */
#define BFM_CTIMER_CTTMR0_CTTMRB0               ((uint32_t)0xffff0000)  /* bitfield mask */
#define BFN_CTIMER_CTTMR0_CTTMRB0               (16)                    /* bitfield width */
#define BFD_CTIMER_CTTMR0_CTTMRB0               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTTMR0_CTTMRB0(v)            ((((uint32_t) v) << (BFP_CTIMER_CTTMR0_CTTMRB0)) & (BFM_CTIMER_CTTMR0_CTTMRB0))
#define BFX_CTIMER_CTTMR0_CTTMRB0(v)            ((((uint32_t) v) & (BFM_CTIMER_CTTMR0_CTTMRB0)) >> (BFP_CTIMER_CTTMR0_CTTMRB0))
#define BFW_CTIMER_CTTMR0_CTTMRB0(v)            (REG_CTIMER_CTTMR0.U32 = ( (REG_CTIMER_CTTMR0.U32 & ~(BFM_CTIMER_CTTMR0_CTTMRB0)) | ((((uint32_t) v)<<(BFP_CTIMER_CTTMR0_CTTMRB0)) & (BFM_CTIMER_CTTMR0_CTTMRB0)) ))
#define BFR_CTIMER_CTTMR0_CTTMRB0()             ((REG_CTIMER_CTTMR0.U32 & (BFM_CTIMER_CTTMR0_CTTMRB0))>>(BFP_CTIMER_CTTMR0_CTTMRB0))

#define BFP_CTIMER_CTTMR0_CTTMRA0               (0)                     /* bitfield lsb */
#define BFM_CTIMER_CTTMR0_CTTMRA0               ((uint32_t)0x0000ffff)  /* bitfield mask */
#define BFN_CTIMER_CTTMR0_CTTMRA0               (16)                    /* bitfield width */
#define BFD_CTIMER_CTTMR0_CTTMRA0               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTTMR0_CTTMRA0(v)            ((((uint32_t) v) << (BFP_CTIMER_CTTMR0_CTTMRA0)) & (BFM_CTIMER_CTTMR0_CTTMRA0))
#define BFX_CTIMER_CTTMR0_CTTMRA0(v)            ((((uint32_t) v) & (BFM_CTIMER_CTTMR0_CTTMRA0)) >> (BFP_CTIMER_CTTMR0_CTTMRA0))
#define BFW_CTIMER_CTTMR0_CTTMRA0(v)            (REG_CTIMER_CTTMR0.U32 = ( (REG_CTIMER_CTTMR0.U32 & ~(BFM_CTIMER_CTTMR0_CTTMRA0)) | ((((uint32_t) v)<<(BFP_CTIMER_CTTMR0_CTTMRA0)) & (BFM_CTIMER_CTTMR0_CTTMRA0)) ))
#define BFR_CTIMER_CTTMR0_CTTMRA0()             ((REG_CTIMER_CTTMR0.U32 & (BFM_CTIMER_CTTMR0_CTTMRA0))>>(BFP_CTIMER_CTTMR0_CTTMRA0))


// *****************************************************************************
//                                                                             *
//  CTIMER_CMPRA0 - Counter/Timer A0 Compare Registers                         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CMPR1A0                    : 16;
        unsigned CMPR0A0                    : 16;
    } B;
} reg_ctimer_cmpra0_t;

#define REG_CTIMER_CMPRA0_ADDR                  (REG_CTIMER_BASEADDR + 0x00000004UL)
#define REG_CTIMER_CMPRA0                       (*(volatile reg_ctimer_cmpra0_t *) REG_CTIMER_CMPRA0_ADDR)
#define REG_CTIMER_CMPRA0_RD()                  (REG_CTIMER_CMPRA0.U32)
#define REG_CTIMER_CMPRA0_WR(v)                 (REG_CTIMER_CMPRA0.U32 = (v))
#define REG_CTIMER_CMPRA0_CLR(m)                (REG_CTIMER_CMPRA0.U32 = ((REG_CTIMER_CMPRA0.U32) & ~(m)))
#define REG_CTIMER_CMPRA0_SET(m)                (REG_CTIMER_CMPRA0.U32 = ((REG_CTIMER_CMPRA0.U32) | (m)))
#define REG_CTIMER_CMPRA0_DEF                   0x00000000

#define BFP_CTIMER_CMPRA0_CMPR1A0               (16)                    /* bitfield lsb */
#define BFM_CTIMER_CMPRA0_CMPR1A0               ((uint32_t)0xffff0000)  /* bitfield mask */
#define BFN_CTIMER_CMPRA0_CMPR1A0               (16)                    /* bitfield width */
#define BFD_CTIMER_CMPRA0_CMPR1A0               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CMPRA0_CMPR1A0(v)            ((((uint32_t) v) << (BFP_CTIMER_CMPRA0_CMPR1A0)) & (BFM_CTIMER_CMPRA0_CMPR1A0))
#define BFX_CTIMER_CMPRA0_CMPR1A0(v)            ((((uint32_t) v) & (BFM_CTIMER_CMPRA0_CMPR1A0)) >> (BFP_CTIMER_CMPRA0_CMPR1A0))
#define BFW_CTIMER_CMPRA0_CMPR1A0(v)            (REG_CTIMER_CMPRA0.U32 = ( (REG_CTIMER_CMPRA0.U32 & ~(BFM_CTIMER_CMPRA0_CMPR1A0)) | ((((uint32_t) v)<<(BFP_CTIMER_CMPRA0_CMPR1A0)) & (BFM_CTIMER_CMPRA0_CMPR1A0)) ))
#define BFR_CTIMER_CMPRA0_CMPR1A0()             ((REG_CTIMER_CMPRA0.U32 & (BFM_CTIMER_CMPRA0_CMPR1A0))>>(BFP_CTIMER_CMPRA0_CMPR1A0))

#define BFP_CTIMER_CMPRA0_CMPR0A0               (0)                     /* bitfield lsb */
#define BFM_CTIMER_CMPRA0_CMPR0A0               ((uint32_t)0x0000ffff)  /* bitfield mask */
#define BFN_CTIMER_CMPRA0_CMPR0A0               (16)                    /* bitfield width */
#define BFD_CTIMER_CMPRA0_CMPR0A0               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CMPRA0_CMPR0A0(v)            ((((uint32_t) v) << (BFP_CTIMER_CMPRA0_CMPR0A0)) & (BFM_CTIMER_CMPRA0_CMPR0A0))
#define BFX_CTIMER_CMPRA0_CMPR0A0(v)            ((((uint32_t) v) & (BFM_CTIMER_CMPRA0_CMPR0A0)) >> (BFP_CTIMER_CMPRA0_CMPR0A0))
#define BFW_CTIMER_CMPRA0_CMPR0A0(v)            (REG_CTIMER_CMPRA0.U32 = ( (REG_CTIMER_CMPRA0.U32 & ~(BFM_CTIMER_CMPRA0_CMPR0A0)) | ((((uint32_t) v)<<(BFP_CTIMER_CMPRA0_CMPR0A0)) & (BFM_CTIMER_CMPRA0_CMPR0A0)) ))
#define BFR_CTIMER_CMPRA0_CMPR0A0()             ((REG_CTIMER_CMPRA0.U32 & (BFM_CTIMER_CMPRA0_CMPR0A0))>>(BFP_CTIMER_CMPRA0_CMPR0A0))


// *****************************************************************************
//                                                                             *
//  CTIMER_CMPRB0 - Counter/Timer B0 Compare Registers                         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CMPR1B0                    : 16;
        unsigned CMPR0B0                    : 16;
    } B;
} reg_ctimer_cmprb0_t;

#define REG_CTIMER_CMPRB0_ADDR                  (REG_CTIMER_BASEADDR + 0x00000008UL)
#define REG_CTIMER_CMPRB0                       (*(volatile reg_ctimer_cmprb0_t *) REG_CTIMER_CMPRB0_ADDR)
#define REG_CTIMER_CMPRB0_RD()                  (REG_CTIMER_CMPRB0.U32)
#define REG_CTIMER_CMPRB0_WR(v)                 (REG_CTIMER_CMPRB0.U32 = (v))
#define REG_CTIMER_CMPRB0_CLR(m)                (REG_CTIMER_CMPRB0.U32 = ((REG_CTIMER_CMPRB0.U32) & ~(m)))
#define REG_CTIMER_CMPRB0_SET(m)                (REG_CTIMER_CMPRB0.U32 = ((REG_CTIMER_CMPRB0.U32) | (m)))
#define REG_CTIMER_CMPRB0_DEF                   0x00000000

#define BFP_CTIMER_CMPRB0_CMPR1B0               (16)                    /* bitfield lsb */
#define BFM_CTIMER_CMPRB0_CMPR1B0               ((uint32_t)0xffff0000)  /* bitfield mask */
#define BFN_CTIMER_CMPRB0_CMPR1B0               (16)                    /* bitfield width */
#define BFD_CTIMER_CMPRB0_CMPR1B0               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CMPRB0_CMPR1B0(v)            ((((uint32_t) v) << (BFP_CTIMER_CMPRB0_CMPR1B0)) & (BFM_CTIMER_CMPRB0_CMPR1B0))
#define BFX_CTIMER_CMPRB0_CMPR1B0(v)            ((((uint32_t) v) & (BFM_CTIMER_CMPRB0_CMPR1B0)) >> (BFP_CTIMER_CMPRB0_CMPR1B0))
#define BFW_CTIMER_CMPRB0_CMPR1B0(v)            (REG_CTIMER_CMPRB0.U32 = ( (REG_CTIMER_CMPRB0.U32 & ~(BFM_CTIMER_CMPRB0_CMPR1B0)) | ((((uint32_t) v)<<(BFP_CTIMER_CMPRB0_CMPR1B0)) & (BFM_CTIMER_CMPRB0_CMPR1B0)) ))
#define BFR_CTIMER_CMPRB0_CMPR1B0()             ((REG_CTIMER_CMPRB0.U32 & (BFM_CTIMER_CMPRB0_CMPR1B0))>>(BFP_CTIMER_CMPRB0_CMPR1B0))

#define BFP_CTIMER_CMPRB0_CMPR0B0               (0)                     /* bitfield lsb */
#define BFM_CTIMER_CMPRB0_CMPR0B0               ((uint32_t)0x0000ffff)  /* bitfield mask */
#define BFN_CTIMER_CMPRB0_CMPR0B0               (16)                    /* bitfield width */
#define BFD_CTIMER_CMPRB0_CMPR0B0               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CMPRB0_CMPR0B0(v)            ((((uint32_t) v) << (BFP_CTIMER_CMPRB0_CMPR0B0)) & (BFM_CTIMER_CMPRB0_CMPR0B0))
#define BFX_CTIMER_CMPRB0_CMPR0B0(v)            ((((uint32_t) v) & (BFM_CTIMER_CMPRB0_CMPR0B0)) >> (BFP_CTIMER_CMPRB0_CMPR0B0))
#define BFW_CTIMER_CMPRB0_CMPR0B0(v)            (REG_CTIMER_CMPRB0.U32 = ( (REG_CTIMER_CMPRB0.U32 & ~(BFM_CTIMER_CMPRB0_CMPR0B0)) | ((((uint32_t) v)<<(BFP_CTIMER_CMPRB0_CMPR0B0)) & (BFM_CTIMER_CMPRB0_CMPR0B0)) ))
#define BFR_CTIMER_CMPRB0_CMPR0B0()             ((REG_CTIMER_CMPRB0.U32 & (BFM_CTIMER_CMPRB0_CMPR0B0))>>(BFP_CTIMER_CMPRB0_CMPR0B0))


// *****************************************************************************
//                                                                             *
//  CTIMER_CTCTRL0 - Counter/Timer Control                                     *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CTLINK0                    :  1;
        unsigned RSVD_29                    :  2;
        unsigned TMRB0POL                   :  1;
        unsigned TMRB0CLR                   :  1;
        unsigned TMRB0PE                    :  1;
        unsigned TMRB0IE                    :  1;
        unsigned TMRB0FN                    :  3;
        unsigned TMRB0CLK                   :  5;
        unsigned TMRB0EN                    :  1;
        unsigned RSVD_13                    :  3;
        unsigned TMRA0POL                   :  1;
        unsigned TMRA0CLR                   :  1;
        unsigned TMRA0PE                    :  1;
        unsigned TMRA0IE                    :  1;
        unsigned TMRA0FN                    :  3;
        unsigned TMRA0CLK                   :  5;
        unsigned TMRA0EN                    :  1;
    } B;
} reg_ctimer_ctctrl0_t;

#define REG_CTIMER_CTCTRL0_ADDR                 (REG_CTIMER_BASEADDR + 0x0000000CUL)
#define REG_CTIMER_CTCTRL0                      (*(volatile reg_ctimer_ctctrl0_t *) REG_CTIMER_CTCTRL0_ADDR)
#define REG_CTIMER_CTCTRL0_RD()                 (REG_CTIMER_CTCTRL0.U32)
#define REG_CTIMER_CTCTRL0_WR(v)                (REG_CTIMER_CTCTRL0.U32 = (v))
#define REG_CTIMER_CTCTRL0_CLR(m)               (REG_CTIMER_CTCTRL0.U32 = ((REG_CTIMER_CTCTRL0.U32) & ~(m)))
#define REG_CTIMER_CTCTRL0_SET(m)               (REG_CTIMER_CTCTRL0.U32 = ((REG_CTIMER_CTCTRL0.U32) | (m)))
#define REG_CTIMER_CTCTRL0_DEF                  0x00020002

#define BFP_CTIMER_CTCTRL0_CTLINK0              (31)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL0_CTLINK0              ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL0_CTLINK0              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL0_CTLINK0              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL0_CTLINK0(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL0_CTLINK0)) & (BFM_CTIMER_CTCTRL0_CTLINK0))
#define BFX_CTIMER_CTCTRL0_CTLINK0(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL0_CTLINK0)) >> (BFP_CTIMER_CTCTRL0_CTLINK0))
#define BFW_CTIMER_CTCTRL0_CTLINK0(v)           (REG_CTIMER_CTCTRL0.U32 = ( (REG_CTIMER_CTCTRL0.U32 & ~(BFM_CTIMER_CTCTRL0_CTLINK0)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL0_CTLINK0)) & (BFM_CTIMER_CTCTRL0_CTLINK0)) ))
#define BFR_CTIMER_CTCTRL0_CTLINK0()            ((REG_CTIMER_CTCTRL0.U32 & (BFM_CTIMER_CTCTRL0_CTLINK0))>>(BFP_CTIMER_CTCTRL0_CTLINK0))

#define BFP_CTIMER_CTCTRL0_RSVD_29              (29)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL0_RSVD_29              ((uint32_t)0x60000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL0_RSVD_29              (2)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL0_RSVD_29              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL0_RSVD_29(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL0_RSVD_29)) & (BFM_CTIMER_CTCTRL0_RSVD_29))
#define BFX_CTIMER_CTCTRL0_RSVD_29(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL0_RSVD_29)) >> (BFP_CTIMER_CTCTRL0_RSVD_29))
#define BFW_CTIMER_CTCTRL0_RSVD_29(v)           (REG_CTIMER_CTCTRL0.U32 = ( (REG_CTIMER_CTCTRL0.U32 & ~(BFM_CTIMER_CTCTRL0_RSVD_29)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL0_RSVD_29)) & (BFM_CTIMER_CTCTRL0_RSVD_29)) ))
#define BFR_CTIMER_CTCTRL0_RSVD_29()            ((REG_CTIMER_CTCTRL0.U32 & (BFM_CTIMER_CTCTRL0_RSVD_29))>>(BFP_CTIMER_CTCTRL0_RSVD_29))

#define BFP_CTIMER_CTCTRL0_TMRB0POL             (28)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL0_TMRB0POL             ((uint32_t)0x10000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL0_TMRB0POL             (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL0_TMRB0POL             (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL0_TMRB0POL(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL0_TMRB0POL)) & (BFM_CTIMER_CTCTRL0_TMRB0POL))
#define BFX_CTIMER_CTCTRL0_TMRB0POL(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL0_TMRB0POL)) >> (BFP_CTIMER_CTCTRL0_TMRB0POL))
#define BFW_CTIMER_CTCTRL0_TMRB0POL(v)          (REG_CTIMER_CTCTRL0.U32 = ( (REG_CTIMER_CTCTRL0.U32 & ~(BFM_CTIMER_CTCTRL0_TMRB0POL)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL0_TMRB0POL)) & (BFM_CTIMER_CTCTRL0_TMRB0POL)) ))
#define BFR_CTIMER_CTCTRL0_TMRB0POL()           ((REG_CTIMER_CTCTRL0.U32 & (BFM_CTIMER_CTCTRL0_TMRB0POL))>>(BFP_CTIMER_CTCTRL0_TMRB0POL))

#define BFP_CTIMER_CTCTRL0_TMRB0CLR             (27)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL0_TMRB0CLR             ((uint32_t)0x08000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL0_TMRB0CLR             (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL0_TMRB0CLR             (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL0_TMRB0CLR(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL0_TMRB0CLR)) & (BFM_CTIMER_CTCTRL0_TMRB0CLR))
#define BFX_CTIMER_CTCTRL0_TMRB0CLR(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL0_TMRB0CLR)) >> (BFP_CTIMER_CTCTRL0_TMRB0CLR))
#define BFW_CTIMER_CTCTRL0_TMRB0CLR(v)          (REG_CTIMER_CTCTRL0.U32 = ( (REG_CTIMER_CTCTRL0.U32 & ~(BFM_CTIMER_CTCTRL0_TMRB0CLR)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL0_TMRB0CLR)) & (BFM_CTIMER_CTCTRL0_TMRB0CLR)) ))
#define BFR_CTIMER_CTCTRL0_TMRB0CLR()           ((REG_CTIMER_CTCTRL0.U32 & (BFM_CTIMER_CTCTRL0_TMRB0CLR))>>(BFP_CTIMER_CTCTRL0_TMRB0CLR))

#define BFP_CTIMER_CTCTRL0_TMRB0PE              (26)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL0_TMRB0PE              ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL0_TMRB0PE              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL0_TMRB0PE              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL0_TMRB0PE(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL0_TMRB0PE)) & (BFM_CTIMER_CTCTRL0_TMRB0PE))
#define BFX_CTIMER_CTCTRL0_TMRB0PE(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL0_TMRB0PE)) >> (BFP_CTIMER_CTCTRL0_TMRB0PE))
#define BFW_CTIMER_CTCTRL0_TMRB0PE(v)           (REG_CTIMER_CTCTRL0.U32 = ( (REG_CTIMER_CTCTRL0.U32 & ~(BFM_CTIMER_CTCTRL0_TMRB0PE)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL0_TMRB0PE)) & (BFM_CTIMER_CTCTRL0_TMRB0PE)) ))
#define BFR_CTIMER_CTCTRL0_TMRB0PE()            ((REG_CTIMER_CTCTRL0.U32 & (BFM_CTIMER_CTCTRL0_TMRB0PE))>>(BFP_CTIMER_CTCTRL0_TMRB0PE))

#define BFP_CTIMER_CTCTRL0_TMRB0IE              (25)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL0_TMRB0IE              ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL0_TMRB0IE              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL0_TMRB0IE              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL0_TMRB0IE(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL0_TMRB0IE)) & (BFM_CTIMER_CTCTRL0_TMRB0IE))
#define BFX_CTIMER_CTCTRL0_TMRB0IE(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL0_TMRB0IE)) >> (BFP_CTIMER_CTCTRL0_TMRB0IE))
#define BFW_CTIMER_CTCTRL0_TMRB0IE(v)           (REG_CTIMER_CTCTRL0.U32 = ( (REG_CTIMER_CTCTRL0.U32 & ~(BFM_CTIMER_CTCTRL0_TMRB0IE)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL0_TMRB0IE)) & (BFM_CTIMER_CTCTRL0_TMRB0IE)) ))
#define BFR_CTIMER_CTCTRL0_TMRB0IE()            ((REG_CTIMER_CTCTRL0.U32 & (BFM_CTIMER_CTCTRL0_TMRB0IE))>>(BFP_CTIMER_CTCTRL0_TMRB0IE))

#define BFP_CTIMER_CTCTRL0_TMRB0FN              (22)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL0_TMRB0FN              ((uint32_t)0x01c00000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL0_TMRB0FN              (3)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL0_TMRB0FN              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL0_TMRB0FN(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL0_TMRB0FN)) & (BFM_CTIMER_CTCTRL0_TMRB0FN))
#define BFX_CTIMER_CTCTRL0_TMRB0FN(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL0_TMRB0FN)) >> (BFP_CTIMER_CTCTRL0_TMRB0FN))
#define BFW_CTIMER_CTCTRL0_TMRB0FN(v)           (REG_CTIMER_CTCTRL0.U32 = ( (REG_CTIMER_CTCTRL0.U32 & ~(BFM_CTIMER_CTCTRL0_TMRB0FN)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL0_TMRB0FN)) & (BFM_CTIMER_CTCTRL0_TMRB0FN)) ))
#define BFR_CTIMER_CTCTRL0_TMRB0FN()            ((REG_CTIMER_CTCTRL0.U32 & (BFM_CTIMER_CTCTRL0_TMRB0FN))>>(BFP_CTIMER_CTCTRL0_TMRB0FN))

#define BFP_CTIMER_CTCTRL0_TMRB0CLK             (17)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL0_TMRB0CLK             ((uint32_t)0x003e0000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL0_TMRB0CLK             (5)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL0_TMRB0CLK             (0x1)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL0_TMRB0CLK(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL0_TMRB0CLK)) & (BFM_CTIMER_CTCTRL0_TMRB0CLK))
#define BFX_CTIMER_CTCTRL0_TMRB0CLK(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL0_TMRB0CLK)) >> (BFP_CTIMER_CTCTRL0_TMRB0CLK))
#define BFW_CTIMER_CTCTRL0_TMRB0CLK(v)          (REG_CTIMER_CTCTRL0.U32 = ( (REG_CTIMER_CTCTRL0.U32 & ~(BFM_CTIMER_CTCTRL0_TMRB0CLK)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL0_TMRB0CLK)) & (BFM_CTIMER_CTCTRL0_TMRB0CLK)) ))
#define BFR_CTIMER_CTCTRL0_TMRB0CLK()           ((REG_CTIMER_CTCTRL0.U32 & (BFM_CTIMER_CTCTRL0_TMRB0CLK))>>(BFP_CTIMER_CTCTRL0_TMRB0CLK))

#define BFP_CTIMER_CTCTRL0_TMRB0EN              (16)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL0_TMRB0EN              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL0_TMRB0EN              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL0_TMRB0EN              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL0_TMRB0EN(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL0_TMRB0EN)) & (BFM_CTIMER_CTCTRL0_TMRB0EN))
#define BFX_CTIMER_CTCTRL0_TMRB0EN(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL0_TMRB0EN)) >> (BFP_CTIMER_CTCTRL0_TMRB0EN))
#define BFW_CTIMER_CTCTRL0_TMRB0EN(v)           (REG_CTIMER_CTCTRL0.U32 = ( (REG_CTIMER_CTCTRL0.U32 & ~(BFM_CTIMER_CTCTRL0_TMRB0EN)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL0_TMRB0EN)) & (BFM_CTIMER_CTCTRL0_TMRB0EN)) ))
#define BFR_CTIMER_CTCTRL0_TMRB0EN()            ((REG_CTIMER_CTCTRL0.U32 & (BFM_CTIMER_CTCTRL0_TMRB0EN))>>(BFP_CTIMER_CTCTRL0_TMRB0EN))

#define BFP_CTIMER_CTCTRL0_RSVD_13              (13)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL0_RSVD_13              ((uint32_t)0x0000e000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL0_RSVD_13              (3)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL0_RSVD_13              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL0_RSVD_13(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL0_RSVD_13)) & (BFM_CTIMER_CTCTRL0_RSVD_13))
#define BFX_CTIMER_CTCTRL0_RSVD_13(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL0_RSVD_13)) >> (BFP_CTIMER_CTCTRL0_RSVD_13))
#define BFW_CTIMER_CTCTRL0_RSVD_13(v)           (REG_CTIMER_CTCTRL0.U32 = ( (REG_CTIMER_CTCTRL0.U32 & ~(BFM_CTIMER_CTCTRL0_RSVD_13)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL0_RSVD_13)) & (BFM_CTIMER_CTCTRL0_RSVD_13)) ))
#define BFR_CTIMER_CTCTRL0_RSVD_13()            ((REG_CTIMER_CTCTRL0.U32 & (BFM_CTIMER_CTCTRL0_RSVD_13))>>(BFP_CTIMER_CTCTRL0_RSVD_13))

#define BFP_CTIMER_CTCTRL0_TMRA0POL             (12)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL0_TMRA0POL             ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL0_TMRA0POL             (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL0_TMRA0POL             (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL0_TMRA0POL(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL0_TMRA0POL)) & (BFM_CTIMER_CTCTRL0_TMRA0POL))
#define BFX_CTIMER_CTCTRL0_TMRA0POL(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL0_TMRA0POL)) >> (BFP_CTIMER_CTCTRL0_TMRA0POL))
#define BFW_CTIMER_CTCTRL0_TMRA0POL(v)          (REG_CTIMER_CTCTRL0.U32 = ( (REG_CTIMER_CTCTRL0.U32 & ~(BFM_CTIMER_CTCTRL0_TMRA0POL)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL0_TMRA0POL)) & (BFM_CTIMER_CTCTRL0_TMRA0POL)) ))
#define BFR_CTIMER_CTCTRL0_TMRA0POL()           ((REG_CTIMER_CTCTRL0.U32 & (BFM_CTIMER_CTCTRL0_TMRA0POL))>>(BFP_CTIMER_CTCTRL0_TMRA0POL))

#define BFP_CTIMER_CTCTRL0_TMRA0CLR             (11)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL0_TMRA0CLR             ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL0_TMRA0CLR             (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL0_TMRA0CLR             (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL0_TMRA0CLR(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL0_TMRA0CLR)) & (BFM_CTIMER_CTCTRL0_TMRA0CLR))
#define BFX_CTIMER_CTCTRL0_TMRA0CLR(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL0_TMRA0CLR)) >> (BFP_CTIMER_CTCTRL0_TMRA0CLR))
#define BFW_CTIMER_CTCTRL0_TMRA0CLR(v)          (REG_CTIMER_CTCTRL0.U32 = ( (REG_CTIMER_CTCTRL0.U32 & ~(BFM_CTIMER_CTCTRL0_TMRA0CLR)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL0_TMRA0CLR)) & (BFM_CTIMER_CTCTRL0_TMRA0CLR)) ))
#define BFR_CTIMER_CTCTRL0_TMRA0CLR()           ((REG_CTIMER_CTCTRL0.U32 & (BFM_CTIMER_CTCTRL0_TMRA0CLR))>>(BFP_CTIMER_CTCTRL0_TMRA0CLR))

#define BFP_CTIMER_CTCTRL0_TMRA0PE              (10)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL0_TMRA0PE              ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL0_TMRA0PE              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL0_TMRA0PE              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL0_TMRA0PE(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL0_TMRA0PE)) & (BFM_CTIMER_CTCTRL0_TMRA0PE))
#define BFX_CTIMER_CTCTRL0_TMRA0PE(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL0_TMRA0PE)) >> (BFP_CTIMER_CTCTRL0_TMRA0PE))
#define BFW_CTIMER_CTCTRL0_TMRA0PE(v)           (REG_CTIMER_CTCTRL0.U32 = ( (REG_CTIMER_CTCTRL0.U32 & ~(BFM_CTIMER_CTCTRL0_TMRA0PE)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL0_TMRA0PE)) & (BFM_CTIMER_CTCTRL0_TMRA0PE)) ))
#define BFR_CTIMER_CTCTRL0_TMRA0PE()            ((REG_CTIMER_CTCTRL0.U32 & (BFM_CTIMER_CTCTRL0_TMRA0PE))>>(BFP_CTIMER_CTCTRL0_TMRA0PE))

#define BFP_CTIMER_CTCTRL0_TMRA0IE              (9)                     /* bitfield lsb */
#define BFM_CTIMER_CTCTRL0_TMRA0IE              ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL0_TMRA0IE              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL0_TMRA0IE              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL0_TMRA0IE(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL0_TMRA0IE)) & (BFM_CTIMER_CTCTRL0_TMRA0IE))
#define BFX_CTIMER_CTCTRL0_TMRA0IE(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL0_TMRA0IE)) >> (BFP_CTIMER_CTCTRL0_TMRA0IE))
#define BFW_CTIMER_CTCTRL0_TMRA0IE(v)           (REG_CTIMER_CTCTRL0.U32 = ( (REG_CTIMER_CTCTRL0.U32 & ~(BFM_CTIMER_CTCTRL0_TMRA0IE)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL0_TMRA0IE)) & (BFM_CTIMER_CTCTRL0_TMRA0IE)) ))
#define BFR_CTIMER_CTCTRL0_TMRA0IE()            ((REG_CTIMER_CTCTRL0.U32 & (BFM_CTIMER_CTCTRL0_TMRA0IE))>>(BFP_CTIMER_CTCTRL0_TMRA0IE))

#define BFP_CTIMER_CTCTRL0_TMRA0FN              (6)                     /* bitfield lsb */
#define BFM_CTIMER_CTCTRL0_TMRA0FN              ((uint32_t)0x000001c0)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL0_TMRA0FN              (3)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL0_TMRA0FN              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL0_TMRA0FN(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL0_TMRA0FN)) & (BFM_CTIMER_CTCTRL0_TMRA0FN))
#define BFX_CTIMER_CTCTRL0_TMRA0FN(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL0_TMRA0FN)) >> (BFP_CTIMER_CTCTRL0_TMRA0FN))
#define BFW_CTIMER_CTCTRL0_TMRA0FN(v)           (REG_CTIMER_CTCTRL0.U32 = ( (REG_CTIMER_CTCTRL0.U32 & ~(BFM_CTIMER_CTCTRL0_TMRA0FN)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL0_TMRA0FN)) & (BFM_CTIMER_CTCTRL0_TMRA0FN)) ))
#define BFR_CTIMER_CTCTRL0_TMRA0FN()            ((REG_CTIMER_CTCTRL0.U32 & (BFM_CTIMER_CTCTRL0_TMRA0FN))>>(BFP_CTIMER_CTCTRL0_TMRA0FN))

#define BFP_CTIMER_CTCTRL0_TMRA0CLK             (1)                     /* bitfield lsb */
#define BFM_CTIMER_CTCTRL0_TMRA0CLK             ((uint32_t)0x0000003e)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL0_TMRA0CLK             (5)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL0_TMRA0CLK             (0x1)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL0_TMRA0CLK(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL0_TMRA0CLK)) & (BFM_CTIMER_CTCTRL0_TMRA0CLK))
#define BFX_CTIMER_CTCTRL0_TMRA0CLK(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL0_TMRA0CLK)) >> (BFP_CTIMER_CTCTRL0_TMRA0CLK))
#define BFW_CTIMER_CTCTRL0_TMRA0CLK(v)          (REG_CTIMER_CTCTRL0.U32 = ( (REG_CTIMER_CTCTRL0.U32 & ~(BFM_CTIMER_CTCTRL0_TMRA0CLK)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL0_TMRA0CLK)) & (BFM_CTIMER_CTCTRL0_TMRA0CLK)) ))
#define BFR_CTIMER_CTCTRL0_TMRA0CLK()           ((REG_CTIMER_CTCTRL0.U32 & (BFM_CTIMER_CTCTRL0_TMRA0CLK))>>(BFP_CTIMER_CTCTRL0_TMRA0CLK))

#define BFP_CTIMER_CTCTRL0_TMRA0EN              (0)                     /* bitfield lsb */
#define BFM_CTIMER_CTCTRL0_TMRA0EN              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL0_TMRA0EN              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL0_TMRA0EN              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL0_TMRA0EN(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL0_TMRA0EN)) & (BFM_CTIMER_CTCTRL0_TMRA0EN))
#define BFX_CTIMER_CTCTRL0_TMRA0EN(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL0_TMRA0EN)) >> (BFP_CTIMER_CTCTRL0_TMRA0EN))
#define BFW_CTIMER_CTCTRL0_TMRA0EN(v)           (REG_CTIMER_CTCTRL0.U32 = ( (REG_CTIMER_CTCTRL0.U32 & ~(BFM_CTIMER_CTCTRL0_TMRA0EN)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL0_TMRA0EN)) & (BFM_CTIMER_CTCTRL0_TMRA0EN)) ))
#define BFR_CTIMER_CTCTRL0_TMRA0EN()            ((REG_CTIMER_CTCTRL0.U32 & (BFM_CTIMER_CTCTRL0_TMRA0EN))>>(BFP_CTIMER_CTCTRL0_TMRA0EN))


// *****************************************************************************
//                                                                             *
//  CTIMER_CTTMR1 - Counter/Timer Register                                     *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CTTMRB1                    : 16;
        unsigned CTTMRA1                    : 16;
    } B;
} reg_ctimer_cttmr1_t;

#define REG_CTIMER_CTTMR1_ADDR                  (REG_CTIMER_BASEADDR + 0x00000010UL)
#define REG_CTIMER_CTTMR1                       (*(volatile reg_ctimer_cttmr1_t *) REG_CTIMER_CTTMR1_ADDR)
#define REG_CTIMER_CTTMR1_RD()                  (REG_CTIMER_CTTMR1.U32)
#define REG_CTIMER_CTTMR1_WR(v)                 (REG_CTIMER_CTTMR1.U32 = (v))
#define REG_CTIMER_CTTMR1_CLR(m)                (REG_CTIMER_CTTMR1.U32 = ((REG_CTIMER_CTTMR1.U32) & ~(m)))
#define REG_CTIMER_CTTMR1_SET(m)                (REG_CTIMER_CTTMR1.U32 = ((REG_CTIMER_CTTMR1.U32) | (m)))
#define REG_CTIMER_CTTMR1_DEF                   0x00000000

#define BFP_CTIMER_CTTMR1_CTTMRB1               (16)                    /* bitfield lsb */
#define BFM_CTIMER_CTTMR1_CTTMRB1               ((uint32_t)0xffff0000)  /* bitfield mask */
#define BFN_CTIMER_CTTMR1_CTTMRB1               (16)                    /* bitfield width */
#define BFD_CTIMER_CTTMR1_CTTMRB1               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTTMR1_CTTMRB1(v)            ((((uint32_t) v) << (BFP_CTIMER_CTTMR1_CTTMRB1)) & (BFM_CTIMER_CTTMR1_CTTMRB1))
#define BFX_CTIMER_CTTMR1_CTTMRB1(v)            ((((uint32_t) v) & (BFM_CTIMER_CTTMR1_CTTMRB1)) >> (BFP_CTIMER_CTTMR1_CTTMRB1))
#define BFW_CTIMER_CTTMR1_CTTMRB1(v)            (REG_CTIMER_CTTMR1.U32 = ( (REG_CTIMER_CTTMR1.U32 & ~(BFM_CTIMER_CTTMR1_CTTMRB1)) | ((((uint32_t) v)<<(BFP_CTIMER_CTTMR1_CTTMRB1)) & (BFM_CTIMER_CTTMR1_CTTMRB1)) ))
#define BFR_CTIMER_CTTMR1_CTTMRB1()             ((REG_CTIMER_CTTMR1.U32 & (BFM_CTIMER_CTTMR1_CTTMRB1))>>(BFP_CTIMER_CTTMR1_CTTMRB1))

#define BFP_CTIMER_CTTMR1_CTTMRA1               (0)                     /* bitfield lsb */
#define BFM_CTIMER_CTTMR1_CTTMRA1               ((uint32_t)0x0000ffff)  /* bitfield mask */
#define BFN_CTIMER_CTTMR1_CTTMRA1               (16)                    /* bitfield width */
#define BFD_CTIMER_CTTMR1_CTTMRA1               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTTMR1_CTTMRA1(v)            ((((uint32_t) v) << (BFP_CTIMER_CTTMR1_CTTMRA1)) & (BFM_CTIMER_CTTMR1_CTTMRA1))
#define BFX_CTIMER_CTTMR1_CTTMRA1(v)            ((((uint32_t) v) & (BFM_CTIMER_CTTMR1_CTTMRA1)) >> (BFP_CTIMER_CTTMR1_CTTMRA1))
#define BFW_CTIMER_CTTMR1_CTTMRA1(v)            (REG_CTIMER_CTTMR1.U32 = ( (REG_CTIMER_CTTMR1.U32 & ~(BFM_CTIMER_CTTMR1_CTTMRA1)) | ((((uint32_t) v)<<(BFP_CTIMER_CTTMR1_CTTMRA1)) & (BFM_CTIMER_CTTMR1_CTTMRA1)) ))
#define BFR_CTIMER_CTTMR1_CTTMRA1()             ((REG_CTIMER_CTTMR1.U32 & (BFM_CTIMER_CTTMR1_CTTMRA1))>>(BFP_CTIMER_CTTMR1_CTTMRA1))


// *****************************************************************************
//                                                                             *
//  CTIMER_CMPRA1 - Counter/Timer A1 Compare Registers                         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CMPR1A1                    : 16;
        unsigned CMPR0A1                    : 16;
    } B;
} reg_ctimer_cmpra1_t;

#define REG_CTIMER_CMPRA1_ADDR                  (REG_CTIMER_BASEADDR + 0x00000014UL)
#define REG_CTIMER_CMPRA1                       (*(volatile reg_ctimer_cmpra1_t *) REG_CTIMER_CMPRA1_ADDR)
#define REG_CTIMER_CMPRA1_RD()                  (REG_CTIMER_CMPRA1.U32)
#define REG_CTIMER_CMPRA1_WR(v)                 (REG_CTIMER_CMPRA1.U32 = (v))
#define REG_CTIMER_CMPRA1_CLR(m)                (REG_CTIMER_CMPRA1.U32 = ((REG_CTIMER_CMPRA1.U32) & ~(m)))
#define REG_CTIMER_CMPRA1_SET(m)                (REG_CTIMER_CMPRA1.U32 = ((REG_CTIMER_CMPRA1.U32) | (m)))
#define REG_CTIMER_CMPRA1_DEF                   0x00000000

#define BFP_CTIMER_CMPRA1_CMPR1A1               (16)                    /* bitfield lsb */
#define BFM_CTIMER_CMPRA1_CMPR1A1               ((uint32_t)0xffff0000)  /* bitfield mask */
#define BFN_CTIMER_CMPRA1_CMPR1A1               (16)                    /* bitfield width */
#define BFD_CTIMER_CMPRA1_CMPR1A1               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CMPRA1_CMPR1A1(v)            ((((uint32_t) v) << (BFP_CTIMER_CMPRA1_CMPR1A1)) & (BFM_CTIMER_CMPRA1_CMPR1A1))
#define BFX_CTIMER_CMPRA1_CMPR1A1(v)            ((((uint32_t) v) & (BFM_CTIMER_CMPRA1_CMPR1A1)) >> (BFP_CTIMER_CMPRA1_CMPR1A1))
#define BFW_CTIMER_CMPRA1_CMPR1A1(v)            (REG_CTIMER_CMPRA1.U32 = ( (REG_CTIMER_CMPRA1.U32 & ~(BFM_CTIMER_CMPRA1_CMPR1A1)) | ((((uint32_t) v)<<(BFP_CTIMER_CMPRA1_CMPR1A1)) & (BFM_CTIMER_CMPRA1_CMPR1A1)) ))
#define BFR_CTIMER_CMPRA1_CMPR1A1()             ((REG_CTIMER_CMPRA1.U32 & (BFM_CTIMER_CMPRA1_CMPR1A1))>>(BFP_CTIMER_CMPRA1_CMPR1A1))

#define BFP_CTIMER_CMPRA1_CMPR0A1               (0)                     /* bitfield lsb */
#define BFM_CTIMER_CMPRA1_CMPR0A1               ((uint32_t)0x0000ffff)  /* bitfield mask */
#define BFN_CTIMER_CMPRA1_CMPR0A1               (16)                    /* bitfield width */
#define BFD_CTIMER_CMPRA1_CMPR0A1               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CMPRA1_CMPR0A1(v)            ((((uint32_t) v) << (BFP_CTIMER_CMPRA1_CMPR0A1)) & (BFM_CTIMER_CMPRA1_CMPR0A1))
#define BFX_CTIMER_CMPRA1_CMPR0A1(v)            ((((uint32_t) v) & (BFM_CTIMER_CMPRA1_CMPR0A1)) >> (BFP_CTIMER_CMPRA1_CMPR0A1))
#define BFW_CTIMER_CMPRA1_CMPR0A1(v)            (REG_CTIMER_CMPRA1.U32 = ( (REG_CTIMER_CMPRA1.U32 & ~(BFM_CTIMER_CMPRA1_CMPR0A1)) | ((((uint32_t) v)<<(BFP_CTIMER_CMPRA1_CMPR0A1)) & (BFM_CTIMER_CMPRA1_CMPR0A1)) ))
#define BFR_CTIMER_CMPRA1_CMPR0A1()             ((REG_CTIMER_CMPRA1.U32 & (BFM_CTIMER_CMPRA1_CMPR0A1))>>(BFP_CTIMER_CMPRA1_CMPR0A1))


// *****************************************************************************
//                                                                             *
//  CTIMER_CMPRB1 - Counter/Timer B1 Compare Registers                         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CMPR1B1                    : 16;
        unsigned CMPR0B1                    : 16;
    } B;
} reg_ctimer_cmprb1_t;

#define REG_CTIMER_CMPRB1_ADDR                  (REG_CTIMER_BASEADDR + 0x00000018UL)
#define REG_CTIMER_CMPRB1                       (*(volatile reg_ctimer_cmprb1_t *) REG_CTIMER_CMPRB1_ADDR)
#define REG_CTIMER_CMPRB1_RD()                  (REG_CTIMER_CMPRB1.U32)
#define REG_CTIMER_CMPRB1_WR(v)                 (REG_CTIMER_CMPRB1.U32 = (v))
#define REG_CTIMER_CMPRB1_CLR(m)                (REG_CTIMER_CMPRB1.U32 = ((REG_CTIMER_CMPRB1.U32) & ~(m)))
#define REG_CTIMER_CMPRB1_SET(m)                (REG_CTIMER_CMPRB1.U32 = ((REG_CTIMER_CMPRB1.U32) | (m)))
#define REG_CTIMER_CMPRB1_DEF                   0x00000000

#define BFP_CTIMER_CMPRB1_CMPR1B1               (16)                    /* bitfield lsb */
#define BFM_CTIMER_CMPRB1_CMPR1B1               ((uint32_t)0xffff0000)  /* bitfield mask */
#define BFN_CTIMER_CMPRB1_CMPR1B1               (16)                    /* bitfield width */
#define BFD_CTIMER_CMPRB1_CMPR1B1               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CMPRB1_CMPR1B1(v)            ((((uint32_t) v) << (BFP_CTIMER_CMPRB1_CMPR1B1)) & (BFM_CTIMER_CMPRB1_CMPR1B1))
#define BFX_CTIMER_CMPRB1_CMPR1B1(v)            ((((uint32_t) v) & (BFM_CTIMER_CMPRB1_CMPR1B1)) >> (BFP_CTIMER_CMPRB1_CMPR1B1))
#define BFW_CTIMER_CMPRB1_CMPR1B1(v)            (REG_CTIMER_CMPRB1.U32 = ( (REG_CTIMER_CMPRB1.U32 & ~(BFM_CTIMER_CMPRB1_CMPR1B1)) | ((((uint32_t) v)<<(BFP_CTIMER_CMPRB1_CMPR1B1)) & (BFM_CTIMER_CMPRB1_CMPR1B1)) ))
#define BFR_CTIMER_CMPRB1_CMPR1B1()             ((REG_CTIMER_CMPRB1.U32 & (BFM_CTIMER_CMPRB1_CMPR1B1))>>(BFP_CTIMER_CMPRB1_CMPR1B1))

#define BFP_CTIMER_CMPRB1_CMPR0B1               (0)                     /* bitfield lsb */
#define BFM_CTIMER_CMPRB1_CMPR0B1               ((uint32_t)0x0000ffff)  /* bitfield mask */
#define BFN_CTIMER_CMPRB1_CMPR0B1               (16)                    /* bitfield width */
#define BFD_CTIMER_CMPRB1_CMPR0B1               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CMPRB1_CMPR0B1(v)            ((((uint32_t) v) << (BFP_CTIMER_CMPRB1_CMPR0B1)) & (BFM_CTIMER_CMPRB1_CMPR0B1))
#define BFX_CTIMER_CMPRB1_CMPR0B1(v)            ((((uint32_t) v) & (BFM_CTIMER_CMPRB1_CMPR0B1)) >> (BFP_CTIMER_CMPRB1_CMPR0B1))
#define BFW_CTIMER_CMPRB1_CMPR0B1(v)            (REG_CTIMER_CMPRB1.U32 = ( (REG_CTIMER_CMPRB1.U32 & ~(BFM_CTIMER_CMPRB1_CMPR0B1)) | ((((uint32_t) v)<<(BFP_CTIMER_CMPRB1_CMPR0B1)) & (BFM_CTIMER_CMPRB1_CMPR0B1)) ))
#define BFR_CTIMER_CMPRB1_CMPR0B1()             ((REG_CTIMER_CMPRB1.U32 & (BFM_CTIMER_CMPRB1_CMPR0B1))>>(BFP_CTIMER_CMPRB1_CMPR0B1))


// *****************************************************************************
//                                                                             *
//  CTIMER_CTCTRL1 - Counter/Timer Control                                     *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CTLINK1                    :  1;
        unsigned RSVD_29                    :  2;
        unsigned TMRB1POL                   :  1;
        unsigned TMRB1CLR                   :  1;
        unsigned TMRB1PE                    :  1;
        unsigned TMRB1IE                    :  1;
        unsigned TMRB1FN                    :  3;
        unsigned TMRB1CLK                   :  5;
        unsigned TMRB1EN                    :  1;
        unsigned RSVD_13                    :  3;
        unsigned TMRA1POL                   :  1;
        unsigned TMRA1CLR                   :  1;
        unsigned TMRA1PE                    :  1;
        unsigned TMRA1IE                    :  1;
        unsigned TMRA1FN                    :  3;
        unsigned TMRA1CLK                   :  5;
        unsigned TMRA1EN                    :  1;
    } B;
} reg_ctimer_ctctrl1_t;

#define REG_CTIMER_CTCTRL1_ADDR                 (REG_CTIMER_BASEADDR + 0x0000001CUL)
#define REG_CTIMER_CTCTRL1                      (*(volatile reg_ctimer_ctctrl1_t *) REG_CTIMER_CTCTRL1_ADDR)
#define REG_CTIMER_CTCTRL1_RD()                 (REG_CTIMER_CTCTRL1.U32)
#define REG_CTIMER_CTCTRL1_WR(v)                (REG_CTIMER_CTCTRL1.U32 = (v))
#define REG_CTIMER_CTCTRL1_CLR(m)               (REG_CTIMER_CTCTRL1.U32 = ((REG_CTIMER_CTCTRL1.U32) & ~(m)))
#define REG_CTIMER_CTCTRL1_SET(m)               (REG_CTIMER_CTCTRL1.U32 = ((REG_CTIMER_CTCTRL1.U32) | (m)))
#define REG_CTIMER_CTCTRL1_DEF                  0x00020002

#define BFP_CTIMER_CTCTRL1_CTLINK1              (31)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL1_CTLINK1              ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL1_CTLINK1              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL1_CTLINK1              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL1_CTLINK1(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL1_CTLINK1)) & (BFM_CTIMER_CTCTRL1_CTLINK1))
#define BFX_CTIMER_CTCTRL1_CTLINK1(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL1_CTLINK1)) >> (BFP_CTIMER_CTCTRL1_CTLINK1))
#define BFW_CTIMER_CTCTRL1_CTLINK1(v)           (REG_CTIMER_CTCTRL1.U32 = ( (REG_CTIMER_CTCTRL1.U32 & ~(BFM_CTIMER_CTCTRL1_CTLINK1)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL1_CTLINK1)) & (BFM_CTIMER_CTCTRL1_CTLINK1)) ))
#define BFR_CTIMER_CTCTRL1_CTLINK1()            ((REG_CTIMER_CTCTRL1.U32 & (BFM_CTIMER_CTCTRL1_CTLINK1))>>(BFP_CTIMER_CTCTRL1_CTLINK1))

#define BFP_CTIMER_CTCTRL1_RSVD_29              (29)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL1_RSVD_29              ((uint32_t)0x60000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL1_RSVD_29              (2)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL1_RSVD_29              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL1_RSVD_29(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL1_RSVD_29)) & (BFM_CTIMER_CTCTRL1_RSVD_29))
#define BFX_CTIMER_CTCTRL1_RSVD_29(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL1_RSVD_29)) >> (BFP_CTIMER_CTCTRL1_RSVD_29))
#define BFW_CTIMER_CTCTRL1_RSVD_29(v)           (REG_CTIMER_CTCTRL1.U32 = ( (REG_CTIMER_CTCTRL1.U32 & ~(BFM_CTIMER_CTCTRL1_RSVD_29)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL1_RSVD_29)) & (BFM_CTIMER_CTCTRL1_RSVD_29)) ))
#define BFR_CTIMER_CTCTRL1_RSVD_29()            ((REG_CTIMER_CTCTRL1.U32 & (BFM_CTIMER_CTCTRL1_RSVD_29))>>(BFP_CTIMER_CTCTRL1_RSVD_29))

#define BFP_CTIMER_CTCTRL1_TMRB1POL             (28)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL1_TMRB1POL             ((uint32_t)0x10000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL1_TMRB1POL             (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL1_TMRB1POL             (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL1_TMRB1POL(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL1_TMRB1POL)) & (BFM_CTIMER_CTCTRL1_TMRB1POL))
#define BFX_CTIMER_CTCTRL1_TMRB1POL(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL1_TMRB1POL)) >> (BFP_CTIMER_CTCTRL1_TMRB1POL))
#define BFW_CTIMER_CTCTRL1_TMRB1POL(v)          (REG_CTIMER_CTCTRL1.U32 = ( (REG_CTIMER_CTCTRL1.U32 & ~(BFM_CTIMER_CTCTRL1_TMRB1POL)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL1_TMRB1POL)) & (BFM_CTIMER_CTCTRL1_TMRB1POL)) ))
#define BFR_CTIMER_CTCTRL1_TMRB1POL()           ((REG_CTIMER_CTCTRL1.U32 & (BFM_CTIMER_CTCTRL1_TMRB1POL))>>(BFP_CTIMER_CTCTRL1_TMRB1POL))

#define BFP_CTIMER_CTCTRL1_TMRB1CLR             (27)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL1_TMRB1CLR             ((uint32_t)0x08000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL1_TMRB1CLR             (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL1_TMRB1CLR             (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL1_TMRB1CLR(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL1_TMRB1CLR)) & (BFM_CTIMER_CTCTRL1_TMRB1CLR))
#define BFX_CTIMER_CTCTRL1_TMRB1CLR(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL1_TMRB1CLR)) >> (BFP_CTIMER_CTCTRL1_TMRB1CLR))
#define BFW_CTIMER_CTCTRL1_TMRB1CLR(v)          (REG_CTIMER_CTCTRL1.U32 = ( (REG_CTIMER_CTCTRL1.U32 & ~(BFM_CTIMER_CTCTRL1_TMRB1CLR)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL1_TMRB1CLR)) & (BFM_CTIMER_CTCTRL1_TMRB1CLR)) ))
#define BFR_CTIMER_CTCTRL1_TMRB1CLR()           ((REG_CTIMER_CTCTRL1.U32 & (BFM_CTIMER_CTCTRL1_TMRB1CLR))>>(BFP_CTIMER_CTCTRL1_TMRB1CLR))

#define BFP_CTIMER_CTCTRL1_TMRB1PE              (26)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL1_TMRB1PE              ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL1_TMRB1PE              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL1_TMRB1PE              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL1_TMRB1PE(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL1_TMRB1PE)) & (BFM_CTIMER_CTCTRL1_TMRB1PE))
#define BFX_CTIMER_CTCTRL1_TMRB1PE(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL1_TMRB1PE)) >> (BFP_CTIMER_CTCTRL1_TMRB1PE))
#define BFW_CTIMER_CTCTRL1_TMRB1PE(v)           (REG_CTIMER_CTCTRL1.U32 = ( (REG_CTIMER_CTCTRL1.U32 & ~(BFM_CTIMER_CTCTRL1_TMRB1PE)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL1_TMRB1PE)) & (BFM_CTIMER_CTCTRL1_TMRB1PE)) ))
#define BFR_CTIMER_CTCTRL1_TMRB1PE()            ((REG_CTIMER_CTCTRL1.U32 & (BFM_CTIMER_CTCTRL1_TMRB1PE))>>(BFP_CTIMER_CTCTRL1_TMRB1PE))

#define BFP_CTIMER_CTCTRL1_TMRB1IE              (25)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL1_TMRB1IE              ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL1_TMRB1IE              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL1_TMRB1IE              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL1_TMRB1IE(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL1_TMRB1IE)) & (BFM_CTIMER_CTCTRL1_TMRB1IE))
#define BFX_CTIMER_CTCTRL1_TMRB1IE(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL1_TMRB1IE)) >> (BFP_CTIMER_CTCTRL1_TMRB1IE))
#define BFW_CTIMER_CTCTRL1_TMRB1IE(v)           (REG_CTIMER_CTCTRL1.U32 = ( (REG_CTIMER_CTCTRL1.U32 & ~(BFM_CTIMER_CTCTRL1_TMRB1IE)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL1_TMRB1IE)) & (BFM_CTIMER_CTCTRL1_TMRB1IE)) ))
#define BFR_CTIMER_CTCTRL1_TMRB1IE()            ((REG_CTIMER_CTCTRL1.U32 & (BFM_CTIMER_CTCTRL1_TMRB1IE))>>(BFP_CTIMER_CTCTRL1_TMRB1IE))

#define BFP_CTIMER_CTCTRL1_TMRB1FN              (22)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL1_TMRB1FN              ((uint32_t)0x01c00000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL1_TMRB1FN              (3)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL1_TMRB1FN              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL1_TMRB1FN(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL1_TMRB1FN)) & (BFM_CTIMER_CTCTRL1_TMRB1FN))
#define BFX_CTIMER_CTCTRL1_TMRB1FN(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL1_TMRB1FN)) >> (BFP_CTIMER_CTCTRL1_TMRB1FN))
#define BFW_CTIMER_CTCTRL1_TMRB1FN(v)           (REG_CTIMER_CTCTRL1.U32 = ( (REG_CTIMER_CTCTRL1.U32 & ~(BFM_CTIMER_CTCTRL1_TMRB1FN)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL1_TMRB1FN)) & (BFM_CTIMER_CTCTRL1_TMRB1FN)) ))
#define BFR_CTIMER_CTCTRL1_TMRB1FN()            ((REG_CTIMER_CTCTRL1.U32 & (BFM_CTIMER_CTCTRL1_TMRB1FN))>>(BFP_CTIMER_CTCTRL1_TMRB1FN))

#define BFP_CTIMER_CTCTRL1_TMRB1CLK             (17)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL1_TMRB1CLK             ((uint32_t)0x003e0000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL1_TMRB1CLK             (5)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL1_TMRB1CLK             (0x1)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL1_TMRB1CLK(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL1_TMRB1CLK)) & (BFM_CTIMER_CTCTRL1_TMRB1CLK))
#define BFX_CTIMER_CTCTRL1_TMRB1CLK(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL1_TMRB1CLK)) >> (BFP_CTIMER_CTCTRL1_TMRB1CLK))
#define BFW_CTIMER_CTCTRL1_TMRB1CLK(v)          (REG_CTIMER_CTCTRL1.U32 = ( (REG_CTIMER_CTCTRL1.U32 & ~(BFM_CTIMER_CTCTRL1_TMRB1CLK)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL1_TMRB1CLK)) & (BFM_CTIMER_CTCTRL1_TMRB1CLK)) ))
#define BFR_CTIMER_CTCTRL1_TMRB1CLK()           ((REG_CTIMER_CTCTRL1.U32 & (BFM_CTIMER_CTCTRL1_TMRB1CLK))>>(BFP_CTIMER_CTCTRL1_TMRB1CLK))

#define BFP_CTIMER_CTCTRL1_TMRB1EN              (16)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL1_TMRB1EN              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL1_TMRB1EN              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL1_TMRB1EN              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL1_TMRB1EN(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL1_TMRB1EN)) & (BFM_CTIMER_CTCTRL1_TMRB1EN))
#define BFX_CTIMER_CTCTRL1_TMRB1EN(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL1_TMRB1EN)) >> (BFP_CTIMER_CTCTRL1_TMRB1EN))
#define BFW_CTIMER_CTCTRL1_TMRB1EN(v)           (REG_CTIMER_CTCTRL1.U32 = ( (REG_CTIMER_CTCTRL1.U32 & ~(BFM_CTIMER_CTCTRL1_TMRB1EN)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL1_TMRB1EN)) & (BFM_CTIMER_CTCTRL1_TMRB1EN)) ))
#define BFR_CTIMER_CTCTRL1_TMRB1EN()            ((REG_CTIMER_CTCTRL1.U32 & (BFM_CTIMER_CTCTRL1_TMRB1EN))>>(BFP_CTIMER_CTCTRL1_TMRB1EN))

#define BFP_CTIMER_CTCTRL1_RSVD_13              (13)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL1_RSVD_13              ((uint32_t)0x0000e000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL1_RSVD_13              (3)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL1_RSVD_13              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL1_RSVD_13(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL1_RSVD_13)) & (BFM_CTIMER_CTCTRL1_RSVD_13))
#define BFX_CTIMER_CTCTRL1_RSVD_13(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL1_RSVD_13)) >> (BFP_CTIMER_CTCTRL1_RSVD_13))
#define BFW_CTIMER_CTCTRL1_RSVD_13(v)           (REG_CTIMER_CTCTRL1.U32 = ( (REG_CTIMER_CTCTRL1.U32 & ~(BFM_CTIMER_CTCTRL1_RSVD_13)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL1_RSVD_13)) & (BFM_CTIMER_CTCTRL1_RSVD_13)) ))
#define BFR_CTIMER_CTCTRL1_RSVD_13()            ((REG_CTIMER_CTCTRL1.U32 & (BFM_CTIMER_CTCTRL1_RSVD_13))>>(BFP_CTIMER_CTCTRL1_RSVD_13))

#define BFP_CTIMER_CTCTRL1_TMRA1POL             (12)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL1_TMRA1POL             ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL1_TMRA1POL             (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL1_TMRA1POL             (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL1_TMRA1POL(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL1_TMRA1POL)) & (BFM_CTIMER_CTCTRL1_TMRA1POL))
#define BFX_CTIMER_CTCTRL1_TMRA1POL(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL1_TMRA1POL)) >> (BFP_CTIMER_CTCTRL1_TMRA1POL))
#define BFW_CTIMER_CTCTRL1_TMRA1POL(v)          (REG_CTIMER_CTCTRL1.U32 = ( (REG_CTIMER_CTCTRL1.U32 & ~(BFM_CTIMER_CTCTRL1_TMRA1POL)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL1_TMRA1POL)) & (BFM_CTIMER_CTCTRL1_TMRA1POL)) ))
#define BFR_CTIMER_CTCTRL1_TMRA1POL()           ((REG_CTIMER_CTCTRL1.U32 & (BFM_CTIMER_CTCTRL1_TMRA1POL))>>(BFP_CTIMER_CTCTRL1_TMRA1POL))

#define BFP_CTIMER_CTCTRL1_TMRA1CLR             (11)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL1_TMRA1CLR             ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL1_TMRA1CLR             (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL1_TMRA1CLR             (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL1_TMRA1CLR(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL1_TMRA1CLR)) & (BFM_CTIMER_CTCTRL1_TMRA1CLR))
#define BFX_CTIMER_CTCTRL1_TMRA1CLR(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL1_TMRA1CLR)) >> (BFP_CTIMER_CTCTRL1_TMRA1CLR))
#define BFW_CTIMER_CTCTRL1_TMRA1CLR(v)          (REG_CTIMER_CTCTRL1.U32 = ( (REG_CTIMER_CTCTRL1.U32 & ~(BFM_CTIMER_CTCTRL1_TMRA1CLR)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL1_TMRA1CLR)) & (BFM_CTIMER_CTCTRL1_TMRA1CLR)) ))
#define BFR_CTIMER_CTCTRL1_TMRA1CLR()           ((REG_CTIMER_CTCTRL1.U32 & (BFM_CTIMER_CTCTRL1_TMRA1CLR))>>(BFP_CTIMER_CTCTRL1_TMRA1CLR))

#define BFP_CTIMER_CTCTRL1_TMRA1PE              (10)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL1_TMRA1PE              ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL1_TMRA1PE              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL1_TMRA1PE              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL1_TMRA1PE(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL1_TMRA1PE)) & (BFM_CTIMER_CTCTRL1_TMRA1PE))
#define BFX_CTIMER_CTCTRL1_TMRA1PE(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL1_TMRA1PE)) >> (BFP_CTIMER_CTCTRL1_TMRA1PE))
#define BFW_CTIMER_CTCTRL1_TMRA1PE(v)           (REG_CTIMER_CTCTRL1.U32 = ( (REG_CTIMER_CTCTRL1.U32 & ~(BFM_CTIMER_CTCTRL1_TMRA1PE)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL1_TMRA1PE)) & (BFM_CTIMER_CTCTRL1_TMRA1PE)) ))
#define BFR_CTIMER_CTCTRL1_TMRA1PE()            ((REG_CTIMER_CTCTRL1.U32 & (BFM_CTIMER_CTCTRL1_TMRA1PE))>>(BFP_CTIMER_CTCTRL1_TMRA1PE))

#define BFP_CTIMER_CTCTRL1_TMRA1IE              (9)                     /* bitfield lsb */
#define BFM_CTIMER_CTCTRL1_TMRA1IE              ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL1_TMRA1IE              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL1_TMRA1IE              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL1_TMRA1IE(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL1_TMRA1IE)) & (BFM_CTIMER_CTCTRL1_TMRA1IE))
#define BFX_CTIMER_CTCTRL1_TMRA1IE(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL1_TMRA1IE)) >> (BFP_CTIMER_CTCTRL1_TMRA1IE))
#define BFW_CTIMER_CTCTRL1_TMRA1IE(v)           (REG_CTIMER_CTCTRL1.U32 = ( (REG_CTIMER_CTCTRL1.U32 & ~(BFM_CTIMER_CTCTRL1_TMRA1IE)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL1_TMRA1IE)) & (BFM_CTIMER_CTCTRL1_TMRA1IE)) ))
#define BFR_CTIMER_CTCTRL1_TMRA1IE()            ((REG_CTIMER_CTCTRL1.U32 & (BFM_CTIMER_CTCTRL1_TMRA1IE))>>(BFP_CTIMER_CTCTRL1_TMRA1IE))

#define BFP_CTIMER_CTCTRL1_TMRA1FN              (6)                     /* bitfield lsb */
#define BFM_CTIMER_CTCTRL1_TMRA1FN              ((uint32_t)0x000001c0)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL1_TMRA1FN              (3)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL1_TMRA1FN              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL1_TMRA1FN(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL1_TMRA1FN)) & (BFM_CTIMER_CTCTRL1_TMRA1FN))
#define BFX_CTIMER_CTCTRL1_TMRA1FN(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL1_TMRA1FN)) >> (BFP_CTIMER_CTCTRL1_TMRA1FN))
#define BFW_CTIMER_CTCTRL1_TMRA1FN(v)           (REG_CTIMER_CTCTRL1.U32 = ( (REG_CTIMER_CTCTRL1.U32 & ~(BFM_CTIMER_CTCTRL1_TMRA1FN)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL1_TMRA1FN)) & (BFM_CTIMER_CTCTRL1_TMRA1FN)) ))
#define BFR_CTIMER_CTCTRL1_TMRA1FN()            ((REG_CTIMER_CTCTRL1.U32 & (BFM_CTIMER_CTCTRL1_TMRA1FN))>>(BFP_CTIMER_CTCTRL1_TMRA1FN))

#define BFP_CTIMER_CTCTRL1_TMRA1CLK             (1)                     /* bitfield lsb */
#define BFM_CTIMER_CTCTRL1_TMRA1CLK             ((uint32_t)0x0000003e)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL1_TMRA1CLK             (5)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL1_TMRA1CLK             (0x1)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL1_TMRA1CLK(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL1_TMRA1CLK)) & (BFM_CTIMER_CTCTRL1_TMRA1CLK))
#define BFX_CTIMER_CTCTRL1_TMRA1CLK(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL1_TMRA1CLK)) >> (BFP_CTIMER_CTCTRL1_TMRA1CLK))
#define BFW_CTIMER_CTCTRL1_TMRA1CLK(v)          (REG_CTIMER_CTCTRL1.U32 = ( (REG_CTIMER_CTCTRL1.U32 & ~(BFM_CTIMER_CTCTRL1_TMRA1CLK)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL1_TMRA1CLK)) & (BFM_CTIMER_CTCTRL1_TMRA1CLK)) ))
#define BFR_CTIMER_CTCTRL1_TMRA1CLK()           ((REG_CTIMER_CTCTRL1.U32 & (BFM_CTIMER_CTCTRL1_TMRA1CLK))>>(BFP_CTIMER_CTCTRL1_TMRA1CLK))

#define BFP_CTIMER_CTCTRL1_TMRA1EN              (0)                     /* bitfield lsb */
#define BFM_CTIMER_CTCTRL1_TMRA1EN              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL1_TMRA1EN              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL1_TMRA1EN              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL1_TMRA1EN(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL1_TMRA1EN)) & (BFM_CTIMER_CTCTRL1_TMRA1EN))
#define BFX_CTIMER_CTCTRL1_TMRA1EN(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL1_TMRA1EN)) >> (BFP_CTIMER_CTCTRL1_TMRA1EN))
#define BFW_CTIMER_CTCTRL1_TMRA1EN(v)           (REG_CTIMER_CTCTRL1.U32 = ( (REG_CTIMER_CTCTRL1.U32 & ~(BFM_CTIMER_CTCTRL1_TMRA1EN)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL1_TMRA1EN)) & (BFM_CTIMER_CTCTRL1_TMRA1EN)) ))
#define BFR_CTIMER_CTCTRL1_TMRA1EN()            ((REG_CTIMER_CTCTRL1.U32 & (BFM_CTIMER_CTCTRL1_TMRA1EN))>>(BFP_CTIMER_CTCTRL1_TMRA1EN))


// *****************************************************************************
//                                                                             *
//  CTIMER_CTTMR2 - Counter/Timer Register                                     *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CTTMRB2                    : 16;
        unsigned CTTMRA2                    : 16;
    } B;
} reg_ctimer_cttmr2_t;

#define REG_CTIMER_CTTMR2_ADDR                  (REG_CTIMER_BASEADDR + 0x00000020UL)
#define REG_CTIMER_CTTMR2                       (*(volatile reg_ctimer_cttmr2_t *) REG_CTIMER_CTTMR2_ADDR)
#define REG_CTIMER_CTTMR2_RD()                  (REG_CTIMER_CTTMR2.U32)
#define REG_CTIMER_CTTMR2_WR(v)                 (REG_CTIMER_CTTMR2.U32 = (v))
#define REG_CTIMER_CTTMR2_CLR(m)                (REG_CTIMER_CTTMR2.U32 = ((REG_CTIMER_CTTMR2.U32) & ~(m)))
#define REG_CTIMER_CTTMR2_SET(m)                (REG_CTIMER_CTTMR2.U32 = ((REG_CTIMER_CTTMR2.U32) | (m)))
#define REG_CTIMER_CTTMR2_DEF                   0x00000000

#define BFP_CTIMER_CTTMR2_CTTMRB2               (16)                    /* bitfield lsb */
#define BFM_CTIMER_CTTMR2_CTTMRB2               ((uint32_t)0xffff0000)  /* bitfield mask */
#define BFN_CTIMER_CTTMR2_CTTMRB2               (16)                    /* bitfield width */
#define BFD_CTIMER_CTTMR2_CTTMRB2               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTTMR2_CTTMRB2(v)            ((((uint32_t) v) << (BFP_CTIMER_CTTMR2_CTTMRB2)) & (BFM_CTIMER_CTTMR2_CTTMRB2))
#define BFX_CTIMER_CTTMR2_CTTMRB2(v)            ((((uint32_t) v) & (BFM_CTIMER_CTTMR2_CTTMRB2)) >> (BFP_CTIMER_CTTMR2_CTTMRB2))
#define BFW_CTIMER_CTTMR2_CTTMRB2(v)            (REG_CTIMER_CTTMR2.U32 = ( (REG_CTIMER_CTTMR2.U32 & ~(BFM_CTIMER_CTTMR2_CTTMRB2)) | ((((uint32_t) v)<<(BFP_CTIMER_CTTMR2_CTTMRB2)) & (BFM_CTIMER_CTTMR2_CTTMRB2)) ))
#define BFR_CTIMER_CTTMR2_CTTMRB2()             ((REG_CTIMER_CTTMR2.U32 & (BFM_CTIMER_CTTMR2_CTTMRB2))>>(BFP_CTIMER_CTTMR2_CTTMRB2))

#define BFP_CTIMER_CTTMR2_CTTMRA2               (0)                     /* bitfield lsb */
#define BFM_CTIMER_CTTMR2_CTTMRA2               ((uint32_t)0x0000ffff)  /* bitfield mask */
#define BFN_CTIMER_CTTMR2_CTTMRA2               (16)                    /* bitfield width */
#define BFD_CTIMER_CTTMR2_CTTMRA2               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTTMR2_CTTMRA2(v)            ((((uint32_t) v) << (BFP_CTIMER_CTTMR2_CTTMRA2)) & (BFM_CTIMER_CTTMR2_CTTMRA2))
#define BFX_CTIMER_CTTMR2_CTTMRA2(v)            ((((uint32_t) v) & (BFM_CTIMER_CTTMR2_CTTMRA2)) >> (BFP_CTIMER_CTTMR2_CTTMRA2))
#define BFW_CTIMER_CTTMR2_CTTMRA2(v)            (REG_CTIMER_CTTMR2.U32 = ( (REG_CTIMER_CTTMR2.U32 & ~(BFM_CTIMER_CTTMR2_CTTMRA2)) | ((((uint32_t) v)<<(BFP_CTIMER_CTTMR2_CTTMRA2)) & (BFM_CTIMER_CTTMR2_CTTMRA2)) ))
#define BFR_CTIMER_CTTMR2_CTTMRA2()             ((REG_CTIMER_CTTMR2.U32 & (BFM_CTIMER_CTTMR2_CTTMRA2))>>(BFP_CTIMER_CTTMR2_CTTMRA2))


// *****************************************************************************
//                                                                             *
//  CTIMER_CMPRA2 - Counter/Timer A2 Compare Registers                         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CMPR1A2                    : 16;
        unsigned CMPR0A2                    : 16;
    } B;
} reg_ctimer_cmpra2_t;

#define REG_CTIMER_CMPRA2_ADDR                  (REG_CTIMER_BASEADDR + 0x00000024UL)
#define REG_CTIMER_CMPRA2                       (*(volatile reg_ctimer_cmpra2_t *) REG_CTIMER_CMPRA2_ADDR)
#define REG_CTIMER_CMPRA2_RD()                  (REG_CTIMER_CMPRA2.U32)
#define REG_CTIMER_CMPRA2_WR(v)                 (REG_CTIMER_CMPRA2.U32 = (v))
#define REG_CTIMER_CMPRA2_CLR(m)                (REG_CTIMER_CMPRA2.U32 = ((REG_CTIMER_CMPRA2.U32) & ~(m)))
#define REG_CTIMER_CMPRA2_SET(m)                (REG_CTIMER_CMPRA2.U32 = ((REG_CTIMER_CMPRA2.U32) | (m)))
#define REG_CTIMER_CMPRA2_DEF                   0x00000000

#define BFP_CTIMER_CMPRA2_CMPR1A2               (16)                    /* bitfield lsb */
#define BFM_CTIMER_CMPRA2_CMPR1A2               ((uint32_t)0xffff0000)  /* bitfield mask */
#define BFN_CTIMER_CMPRA2_CMPR1A2               (16)                    /* bitfield width */
#define BFD_CTIMER_CMPRA2_CMPR1A2               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CMPRA2_CMPR1A2(v)            ((((uint32_t) v) << (BFP_CTIMER_CMPRA2_CMPR1A2)) & (BFM_CTIMER_CMPRA2_CMPR1A2))
#define BFX_CTIMER_CMPRA2_CMPR1A2(v)            ((((uint32_t) v) & (BFM_CTIMER_CMPRA2_CMPR1A2)) >> (BFP_CTIMER_CMPRA2_CMPR1A2))
#define BFW_CTIMER_CMPRA2_CMPR1A2(v)            (REG_CTIMER_CMPRA2.U32 = ( (REG_CTIMER_CMPRA2.U32 & ~(BFM_CTIMER_CMPRA2_CMPR1A2)) | ((((uint32_t) v)<<(BFP_CTIMER_CMPRA2_CMPR1A2)) & (BFM_CTIMER_CMPRA2_CMPR1A2)) ))
#define BFR_CTIMER_CMPRA2_CMPR1A2()             ((REG_CTIMER_CMPRA2.U32 & (BFM_CTIMER_CMPRA2_CMPR1A2))>>(BFP_CTIMER_CMPRA2_CMPR1A2))

#define BFP_CTIMER_CMPRA2_CMPR0A2               (0)                     /* bitfield lsb */
#define BFM_CTIMER_CMPRA2_CMPR0A2               ((uint32_t)0x0000ffff)  /* bitfield mask */
#define BFN_CTIMER_CMPRA2_CMPR0A2               (16)                    /* bitfield width */
#define BFD_CTIMER_CMPRA2_CMPR0A2               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CMPRA2_CMPR0A2(v)            ((((uint32_t) v) << (BFP_CTIMER_CMPRA2_CMPR0A2)) & (BFM_CTIMER_CMPRA2_CMPR0A2))
#define BFX_CTIMER_CMPRA2_CMPR0A2(v)            ((((uint32_t) v) & (BFM_CTIMER_CMPRA2_CMPR0A2)) >> (BFP_CTIMER_CMPRA2_CMPR0A2))
#define BFW_CTIMER_CMPRA2_CMPR0A2(v)            (REG_CTIMER_CMPRA2.U32 = ( (REG_CTIMER_CMPRA2.U32 & ~(BFM_CTIMER_CMPRA2_CMPR0A2)) | ((((uint32_t) v)<<(BFP_CTIMER_CMPRA2_CMPR0A2)) & (BFM_CTIMER_CMPRA2_CMPR0A2)) ))
#define BFR_CTIMER_CMPRA2_CMPR0A2()             ((REG_CTIMER_CMPRA2.U32 & (BFM_CTIMER_CMPRA2_CMPR0A2))>>(BFP_CTIMER_CMPRA2_CMPR0A2))


// *****************************************************************************
//                                                                             *
//  CTIMER_CMPRB2 - Counter/Timer B2 Compare Registers                         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CMPR1B2                    : 16;
        unsigned CMPR0B2                    : 16;
    } B;
} reg_ctimer_cmprb2_t;

#define REG_CTIMER_CMPRB2_ADDR                  (REG_CTIMER_BASEADDR + 0x00000028UL)
#define REG_CTIMER_CMPRB2                       (*(volatile reg_ctimer_cmprb2_t *) REG_CTIMER_CMPRB2_ADDR)
#define REG_CTIMER_CMPRB2_RD()                  (REG_CTIMER_CMPRB2.U32)
#define REG_CTIMER_CMPRB2_WR(v)                 (REG_CTIMER_CMPRB2.U32 = (v))
#define REG_CTIMER_CMPRB2_CLR(m)                (REG_CTIMER_CMPRB2.U32 = ((REG_CTIMER_CMPRB2.U32) & ~(m)))
#define REG_CTIMER_CMPRB2_SET(m)                (REG_CTIMER_CMPRB2.U32 = ((REG_CTIMER_CMPRB2.U32) | (m)))
#define REG_CTIMER_CMPRB2_DEF                   0x00000000

#define BFP_CTIMER_CMPRB2_CMPR1B2               (16)                    /* bitfield lsb */
#define BFM_CTIMER_CMPRB2_CMPR1B2               ((uint32_t)0xffff0000)  /* bitfield mask */
#define BFN_CTIMER_CMPRB2_CMPR1B2               (16)                    /* bitfield width */
#define BFD_CTIMER_CMPRB2_CMPR1B2               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CMPRB2_CMPR1B2(v)            ((((uint32_t) v) << (BFP_CTIMER_CMPRB2_CMPR1B2)) & (BFM_CTIMER_CMPRB2_CMPR1B2))
#define BFX_CTIMER_CMPRB2_CMPR1B2(v)            ((((uint32_t) v) & (BFM_CTIMER_CMPRB2_CMPR1B2)) >> (BFP_CTIMER_CMPRB2_CMPR1B2))
#define BFW_CTIMER_CMPRB2_CMPR1B2(v)            (REG_CTIMER_CMPRB2.U32 = ( (REG_CTIMER_CMPRB2.U32 & ~(BFM_CTIMER_CMPRB2_CMPR1B2)) | ((((uint32_t) v)<<(BFP_CTIMER_CMPRB2_CMPR1B2)) & (BFM_CTIMER_CMPRB2_CMPR1B2)) ))
#define BFR_CTIMER_CMPRB2_CMPR1B2()             ((REG_CTIMER_CMPRB2.U32 & (BFM_CTIMER_CMPRB2_CMPR1B2))>>(BFP_CTIMER_CMPRB2_CMPR1B2))

#define BFP_CTIMER_CMPRB2_CMPR0B2               (0)                     /* bitfield lsb */
#define BFM_CTIMER_CMPRB2_CMPR0B2               ((uint32_t)0x0000ffff)  /* bitfield mask */
#define BFN_CTIMER_CMPRB2_CMPR0B2               (16)                    /* bitfield width */
#define BFD_CTIMER_CMPRB2_CMPR0B2               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CMPRB2_CMPR0B2(v)            ((((uint32_t) v) << (BFP_CTIMER_CMPRB2_CMPR0B2)) & (BFM_CTIMER_CMPRB2_CMPR0B2))
#define BFX_CTIMER_CMPRB2_CMPR0B2(v)            ((((uint32_t) v) & (BFM_CTIMER_CMPRB2_CMPR0B2)) >> (BFP_CTIMER_CMPRB2_CMPR0B2))
#define BFW_CTIMER_CMPRB2_CMPR0B2(v)            (REG_CTIMER_CMPRB2.U32 = ( (REG_CTIMER_CMPRB2.U32 & ~(BFM_CTIMER_CMPRB2_CMPR0B2)) | ((((uint32_t) v)<<(BFP_CTIMER_CMPRB2_CMPR0B2)) & (BFM_CTIMER_CMPRB2_CMPR0B2)) ))
#define BFR_CTIMER_CMPRB2_CMPR0B2()             ((REG_CTIMER_CMPRB2.U32 & (BFM_CTIMER_CMPRB2_CMPR0B2))>>(BFP_CTIMER_CMPRB2_CMPR0B2))


// *****************************************************************************
//                                                                             *
//  CTIMER_CTCTRL2 - Counter/Timer Control                                     *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CTLINK2                    :  1;
        unsigned RSVD_29                    :  2;
        unsigned TMRB2POL                   :  1;
        unsigned TMRB2CLR                   :  1;
        unsigned TMRB2PE                    :  1;
        unsigned TMRB2IE                    :  1;
        unsigned TMRB2FN                    :  3;
        unsigned TMRB2CLK                   :  5;
        unsigned TMRB2EN                    :  1;
        unsigned RSVD_13                    :  3;
        unsigned TMRA2POL                   :  1;
        unsigned TMRA2CLR                   :  1;
        unsigned TMRA2PE                    :  1;
        unsigned TMRA2IE                    :  1;
        unsigned TMRA2FN                    :  3;
        unsigned TMRA2CLK                   :  5;
        unsigned TMRA2EN                    :  1;
    } B;
} reg_ctimer_ctctrl2_t;

#define REG_CTIMER_CTCTRL2_ADDR                 (REG_CTIMER_BASEADDR + 0x0000002CUL)
#define REG_CTIMER_CTCTRL2                      (*(volatile reg_ctimer_ctctrl2_t *) REG_CTIMER_CTCTRL2_ADDR)
#define REG_CTIMER_CTCTRL2_RD()                 (REG_CTIMER_CTCTRL2.U32)
#define REG_CTIMER_CTCTRL2_WR(v)                (REG_CTIMER_CTCTRL2.U32 = (v))
#define REG_CTIMER_CTCTRL2_CLR(m)               (REG_CTIMER_CTCTRL2.U32 = ((REG_CTIMER_CTCTRL2.U32) & ~(m)))
#define REG_CTIMER_CTCTRL2_SET(m)               (REG_CTIMER_CTCTRL2.U32 = ((REG_CTIMER_CTCTRL2.U32) | (m)))
#define REG_CTIMER_CTCTRL2_DEF                  0x00020002

#define BFP_CTIMER_CTCTRL2_CTLINK2              (31)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL2_CTLINK2              ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL2_CTLINK2              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL2_CTLINK2              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL2_CTLINK2(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL2_CTLINK2)) & (BFM_CTIMER_CTCTRL2_CTLINK2))
#define BFX_CTIMER_CTCTRL2_CTLINK2(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL2_CTLINK2)) >> (BFP_CTIMER_CTCTRL2_CTLINK2))
#define BFW_CTIMER_CTCTRL2_CTLINK2(v)           (REG_CTIMER_CTCTRL2.U32 = ( (REG_CTIMER_CTCTRL2.U32 & ~(BFM_CTIMER_CTCTRL2_CTLINK2)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL2_CTLINK2)) & (BFM_CTIMER_CTCTRL2_CTLINK2)) ))
#define BFR_CTIMER_CTCTRL2_CTLINK2()            ((REG_CTIMER_CTCTRL2.U32 & (BFM_CTIMER_CTCTRL2_CTLINK2))>>(BFP_CTIMER_CTCTRL2_CTLINK2))

#define BFP_CTIMER_CTCTRL2_RSVD_29              (29)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL2_RSVD_29              ((uint32_t)0x60000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL2_RSVD_29              (2)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL2_RSVD_29              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL2_RSVD_29(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL2_RSVD_29)) & (BFM_CTIMER_CTCTRL2_RSVD_29))
#define BFX_CTIMER_CTCTRL2_RSVD_29(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL2_RSVD_29)) >> (BFP_CTIMER_CTCTRL2_RSVD_29))
#define BFW_CTIMER_CTCTRL2_RSVD_29(v)           (REG_CTIMER_CTCTRL2.U32 = ( (REG_CTIMER_CTCTRL2.U32 & ~(BFM_CTIMER_CTCTRL2_RSVD_29)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL2_RSVD_29)) & (BFM_CTIMER_CTCTRL2_RSVD_29)) ))
#define BFR_CTIMER_CTCTRL2_RSVD_29()            ((REG_CTIMER_CTCTRL2.U32 & (BFM_CTIMER_CTCTRL2_RSVD_29))>>(BFP_CTIMER_CTCTRL2_RSVD_29))

#define BFP_CTIMER_CTCTRL2_TMRB2POL             (28)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL2_TMRB2POL             ((uint32_t)0x10000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL2_TMRB2POL             (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL2_TMRB2POL             (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL2_TMRB2POL(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL2_TMRB2POL)) & (BFM_CTIMER_CTCTRL2_TMRB2POL))
#define BFX_CTIMER_CTCTRL2_TMRB2POL(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL2_TMRB2POL)) >> (BFP_CTIMER_CTCTRL2_TMRB2POL))
#define BFW_CTIMER_CTCTRL2_TMRB2POL(v)          (REG_CTIMER_CTCTRL2.U32 = ( (REG_CTIMER_CTCTRL2.U32 & ~(BFM_CTIMER_CTCTRL2_TMRB2POL)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL2_TMRB2POL)) & (BFM_CTIMER_CTCTRL2_TMRB2POL)) ))
#define BFR_CTIMER_CTCTRL2_TMRB2POL()           ((REG_CTIMER_CTCTRL2.U32 & (BFM_CTIMER_CTCTRL2_TMRB2POL))>>(BFP_CTIMER_CTCTRL2_TMRB2POL))

#define BFP_CTIMER_CTCTRL2_TMRB2CLR             (27)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL2_TMRB2CLR             ((uint32_t)0x08000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL2_TMRB2CLR             (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL2_TMRB2CLR             (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL2_TMRB2CLR(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL2_TMRB2CLR)) & (BFM_CTIMER_CTCTRL2_TMRB2CLR))
#define BFX_CTIMER_CTCTRL2_TMRB2CLR(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL2_TMRB2CLR)) >> (BFP_CTIMER_CTCTRL2_TMRB2CLR))
#define BFW_CTIMER_CTCTRL2_TMRB2CLR(v)          (REG_CTIMER_CTCTRL2.U32 = ( (REG_CTIMER_CTCTRL2.U32 & ~(BFM_CTIMER_CTCTRL2_TMRB2CLR)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL2_TMRB2CLR)) & (BFM_CTIMER_CTCTRL2_TMRB2CLR)) ))
#define BFR_CTIMER_CTCTRL2_TMRB2CLR()           ((REG_CTIMER_CTCTRL2.U32 & (BFM_CTIMER_CTCTRL2_TMRB2CLR))>>(BFP_CTIMER_CTCTRL2_TMRB2CLR))

#define BFP_CTIMER_CTCTRL2_TMRB2PE              (26)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL2_TMRB2PE              ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL2_TMRB2PE              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL2_TMRB2PE              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL2_TMRB2PE(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL2_TMRB2PE)) & (BFM_CTIMER_CTCTRL2_TMRB2PE))
#define BFX_CTIMER_CTCTRL2_TMRB2PE(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL2_TMRB2PE)) >> (BFP_CTIMER_CTCTRL2_TMRB2PE))
#define BFW_CTIMER_CTCTRL2_TMRB2PE(v)           (REG_CTIMER_CTCTRL2.U32 = ( (REG_CTIMER_CTCTRL2.U32 & ~(BFM_CTIMER_CTCTRL2_TMRB2PE)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL2_TMRB2PE)) & (BFM_CTIMER_CTCTRL2_TMRB2PE)) ))
#define BFR_CTIMER_CTCTRL2_TMRB2PE()            ((REG_CTIMER_CTCTRL2.U32 & (BFM_CTIMER_CTCTRL2_TMRB2PE))>>(BFP_CTIMER_CTCTRL2_TMRB2PE))

#define BFP_CTIMER_CTCTRL2_TMRB2IE              (25)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL2_TMRB2IE              ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL2_TMRB2IE              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL2_TMRB2IE              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL2_TMRB2IE(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL2_TMRB2IE)) & (BFM_CTIMER_CTCTRL2_TMRB2IE))
#define BFX_CTIMER_CTCTRL2_TMRB2IE(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL2_TMRB2IE)) >> (BFP_CTIMER_CTCTRL2_TMRB2IE))
#define BFW_CTIMER_CTCTRL2_TMRB2IE(v)           (REG_CTIMER_CTCTRL2.U32 = ( (REG_CTIMER_CTCTRL2.U32 & ~(BFM_CTIMER_CTCTRL2_TMRB2IE)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL2_TMRB2IE)) & (BFM_CTIMER_CTCTRL2_TMRB2IE)) ))
#define BFR_CTIMER_CTCTRL2_TMRB2IE()            ((REG_CTIMER_CTCTRL2.U32 & (BFM_CTIMER_CTCTRL2_TMRB2IE))>>(BFP_CTIMER_CTCTRL2_TMRB2IE))

#define BFP_CTIMER_CTCTRL2_TMRB2FN              (22)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL2_TMRB2FN              ((uint32_t)0x01c00000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL2_TMRB2FN              (3)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL2_TMRB2FN              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL2_TMRB2FN(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL2_TMRB2FN)) & (BFM_CTIMER_CTCTRL2_TMRB2FN))
#define BFX_CTIMER_CTCTRL2_TMRB2FN(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL2_TMRB2FN)) >> (BFP_CTIMER_CTCTRL2_TMRB2FN))
#define BFW_CTIMER_CTCTRL2_TMRB2FN(v)           (REG_CTIMER_CTCTRL2.U32 = ( (REG_CTIMER_CTCTRL2.U32 & ~(BFM_CTIMER_CTCTRL2_TMRB2FN)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL2_TMRB2FN)) & (BFM_CTIMER_CTCTRL2_TMRB2FN)) ))
#define BFR_CTIMER_CTCTRL2_TMRB2FN()            ((REG_CTIMER_CTCTRL2.U32 & (BFM_CTIMER_CTCTRL2_TMRB2FN))>>(BFP_CTIMER_CTCTRL2_TMRB2FN))

#define BFP_CTIMER_CTCTRL2_TMRB2CLK             (17)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL2_TMRB2CLK             ((uint32_t)0x003e0000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL2_TMRB2CLK             (5)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL2_TMRB2CLK             (0x1)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL2_TMRB2CLK(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL2_TMRB2CLK)) & (BFM_CTIMER_CTCTRL2_TMRB2CLK))
#define BFX_CTIMER_CTCTRL2_TMRB2CLK(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL2_TMRB2CLK)) >> (BFP_CTIMER_CTCTRL2_TMRB2CLK))
#define BFW_CTIMER_CTCTRL2_TMRB2CLK(v)          (REG_CTIMER_CTCTRL2.U32 = ( (REG_CTIMER_CTCTRL2.U32 & ~(BFM_CTIMER_CTCTRL2_TMRB2CLK)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL2_TMRB2CLK)) & (BFM_CTIMER_CTCTRL2_TMRB2CLK)) ))
#define BFR_CTIMER_CTCTRL2_TMRB2CLK()           ((REG_CTIMER_CTCTRL2.U32 & (BFM_CTIMER_CTCTRL2_TMRB2CLK))>>(BFP_CTIMER_CTCTRL2_TMRB2CLK))

#define BFP_CTIMER_CTCTRL2_TMRB2EN              (16)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL2_TMRB2EN              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL2_TMRB2EN              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL2_TMRB2EN              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL2_TMRB2EN(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL2_TMRB2EN)) & (BFM_CTIMER_CTCTRL2_TMRB2EN))
#define BFX_CTIMER_CTCTRL2_TMRB2EN(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL2_TMRB2EN)) >> (BFP_CTIMER_CTCTRL2_TMRB2EN))
#define BFW_CTIMER_CTCTRL2_TMRB2EN(v)           (REG_CTIMER_CTCTRL2.U32 = ( (REG_CTIMER_CTCTRL2.U32 & ~(BFM_CTIMER_CTCTRL2_TMRB2EN)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL2_TMRB2EN)) & (BFM_CTIMER_CTCTRL2_TMRB2EN)) ))
#define BFR_CTIMER_CTCTRL2_TMRB2EN()            ((REG_CTIMER_CTCTRL2.U32 & (BFM_CTIMER_CTCTRL2_TMRB2EN))>>(BFP_CTIMER_CTCTRL2_TMRB2EN))

#define BFP_CTIMER_CTCTRL2_RSVD_13              (13)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL2_RSVD_13              ((uint32_t)0x0000e000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL2_RSVD_13              (3)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL2_RSVD_13              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL2_RSVD_13(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL2_RSVD_13)) & (BFM_CTIMER_CTCTRL2_RSVD_13))
#define BFX_CTIMER_CTCTRL2_RSVD_13(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL2_RSVD_13)) >> (BFP_CTIMER_CTCTRL2_RSVD_13))
#define BFW_CTIMER_CTCTRL2_RSVD_13(v)           (REG_CTIMER_CTCTRL2.U32 = ( (REG_CTIMER_CTCTRL2.U32 & ~(BFM_CTIMER_CTCTRL2_RSVD_13)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL2_RSVD_13)) & (BFM_CTIMER_CTCTRL2_RSVD_13)) ))
#define BFR_CTIMER_CTCTRL2_RSVD_13()            ((REG_CTIMER_CTCTRL2.U32 & (BFM_CTIMER_CTCTRL2_RSVD_13))>>(BFP_CTIMER_CTCTRL2_RSVD_13))

#define BFP_CTIMER_CTCTRL2_TMRA2POL             (12)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL2_TMRA2POL             ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL2_TMRA2POL             (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL2_TMRA2POL             (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL2_TMRA2POL(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL2_TMRA2POL)) & (BFM_CTIMER_CTCTRL2_TMRA2POL))
#define BFX_CTIMER_CTCTRL2_TMRA2POL(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL2_TMRA2POL)) >> (BFP_CTIMER_CTCTRL2_TMRA2POL))
#define BFW_CTIMER_CTCTRL2_TMRA2POL(v)          (REG_CTIMER_CTCTRL2.U32 = ( (REG_CTIMER_CTCTRL2.U32 & ~(BFM_CTIMER_CTCTRL2_TMRA2POL)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL2_TMRA2POL)) & (BFM_CTIMER_CTCTRL2_TMRA2POL)) ))
#define BFR_CTIMER_CTCTRL2_TMRA2POL()           ((REG_CTIMER_CTCTRL2.U32 & (BFM_CTIMER_CTCTRL2_TMRA2POL))>>(BFP_CTIMER_CTCTRL2_TMRA2POL))

#define BFP_CTIMER_CTCTRL2_TMRA2CLR             (11)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL2_TMRA2CLR             ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL2_TMRA2CLR             (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL2_TMRA2CLR             (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL2_TMRA2CLR(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL2_TMRA2CLR)) & (BFM_CTIMER_CTCTRL2_TMRA2CLR))
#define BFX_CTIMER_CTCTRL2_TMRA2CLR(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL2_TMRA2CLR)) >> (BFP_CTIMER_CTCTRL2_TMRA2CLR))
#define BFW_CTIMER_CTCTRL2_TMRA2CLR(v)          (REG_CTIMER_CTCTRL2.U32 = ( (REG_CTIMER_CTCTRL2.U32 & ~(BFM_CTIMER_CTCTRL2_TMRA2CLR)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL2_TMRA2CLR)) & (BFM_CTIMER_CTCTRL2_TMRA2CLR)) ))
#define BFR_CTIMER_CTCTRL2_TMRA2CLR()           ((REG_CTIMER_CTCTRL2.U32 & (BFM_CTIMER_CTCTRL2_TMRA2CLR))>>(BFP_CTIMER_CTCTRL2_TMRA2CLR))

#define BFP_CTIMER_CTCTRL2_TMRA2PE              (10)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL2_TMRA2PE              ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL2_TMRA2PE              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL2_TMRA2PE              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL2_TMRA2PE(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL2_TMRA2PE)) & (BFM_CTIMER_CTCTRL2_TMRA2PE))
#define BFX_CTIMER_CTCTRL2_TMRA2PE(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL2_TMRA2PE)) >> (BFP_CTIMER_CTCTRL2_TMRA2PE))
#define BFW_CTIMER_CTCTRL2_TMRA2PE(v)           (REG_CTIMER_CTCTRL2.U32 = ( (REG_CTIMER_CTCTRL2.U32 & ~(BFM_CTIMER_CTCTRL2_TMRA2PE)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL2_TMRA2PE)) & (BFM_CTIMER_CTCTRL2_TMRA2PE)) ))
#define BFR_CTIMER_CTCTRL2_TMRA2PE()            ((REG_CTIMER_CTCTRL2.U32 & (BFM_CTIMER_CTCTRL2_TMRA2PE))>>(BFP_CTIMER_CTCTRL2_TMRA2PE))

#define BFP_CTIMER_CTCTRL2_TMRA2IE              (9)                     /* bitfield lsb */
#define BFM_CTIMER_CTCTRL2_TMRA2IE              ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL2_TMRA2IE              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL2_TMRA2IE              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL2_TMRA2IE(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL2_TMRA2IE)) & (BFM_CTIMER_CTCTRL2_TMRA2IE))
#define BFX_CTIMER_CTCTRL2_TMRA2IE(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL2_TMRA2IE)) >> (BFP_CTIMER_CTCTRL2_TMRA2IE))
#define BFW_CTIMER_CTCTRL2_TMRA2IE(v)           (REG_CTIMER_CTCTRL2.U32 = ( (REG_CTIMER_CTCTRL2.U32 & ~(BFM_CTIMER_CTCTRL2_TMRA2IE)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL2_TMRA2IE)) & (BFM_CTIMER_CTCTRL2_TMRA2IE)) ))
#define BFR_CTIMER_CTCTRL2_TMRA2IE()            ((REG_CTIMER_CTCTRL2.U32 & (BFM_CTIMER_CTCTRL2_TMRA2IE))>>(BFP_CTIMER_CTCTRL2_TMRA2IE))

#define BFP_CTIMER_CTCTRL2_TMRA2FN              (6)                     /* bitfield lsb */
#define BFM_CTIMER_CTCTRL2_TMRA2FN              ((uint32_t)0x000001c0)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL2_TMRA2FN              (3)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL2_TMRA2FN              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL2_TMRA2FN(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL2_TMRA2FN)) & (BFM_CTIMER_CTCTRL2_TMRA2FN))
#define BFX_CTIMER_CTCTRL2_TMRA2FN(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL2_TMRA2FN)) >> (BFP_CTIMER_CTCTRL2_TMRA2FN))
#define BFW_CTIMER_CTCTRL2_TMRA2FN(v)           (REG_CTIMER_CTCTRL2.U32 = ( (REG_CTIMER_CTCTRL2.U32 & ~(BFM_CTIMER_CTCTRL2_TMRA2FN)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL2_TMRA2FN)) & (BFM_CTIMER_CTCTRL2_TMRA2FN)) ))
#define BFR_CTIMER_CTCTRL2_TMRA2FN()            ((REG_CTIMER_CTCTRL2.U32 & (BFM_CTIMER_CTCTRL2_TMRA2FN))>>(BFP_CTIMER_CTCTRL2_TMRA2FN))

#define BFP_CTIMER_CTCTRL2_TMRA2CLK             (1)                     /* bitfield lsb */
#define BFM_CTIMER_CTCTRL2_TMRA2CLK             ((uint32_t)0x0000003e)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL2_TMRA2CLK             (5)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL2_TMRA2CLK             (0x1)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL2_TMRA2CLK(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL2_TMRA2CLK)) & (BFM_CTIMER_CTCTRL2_TMRA2CLK))
#define BFX_CTIMER_CTCTRL2_TMRA2CLK(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL2_TMRA2CLK)) >> (BFP_CTIMER_CTCTRL2_TMRA2CLK))
#define BFW_CTIMER_CTCTRL2_TMRA2CLK(v)          (REG_CTIMER_CTCTRL2.U32 = ( (REG_CTIMER_CTCTRL2.U32 & ~(BFM_CTIMER_CTCTRL2_TMRA2CLK)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL2_TMRA2CLK)) & (BFM_CTIMER_CTCTRL2_TMRA2CLK)) ))
#define BFR_CTIMER_CTCTRL2_TMRA2CLK()           ((REG_CTIMER_CTCTRL2.U32 & (BFM_CTIMER_CTCTRL2_TMRA2CLK))>>(BFP_CTIMER_CTCTRL2_TMRA2CLK))

#define BFP_CTIMER_CTCTRL2_TMRA2EN              (0)                     /* bitfield lsb */
#define BFM_CTIMER_CTCTRL2_TMRA2EN              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL2_TMRA2EN              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL2_TMRA2EN              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL2_TMRA2EN(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL2_TMRA2EN)) & (BFM_CTIMER_CTCTRL2_TMRA2EN))
#define BFX_CTIMER_CTCTRL2_TMRA2EN(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL2_TMRA2EN)) >> (BFP_CTIMER_CTCTRL2_TMRA2EN))
#define BFW_CTIMER_CTCTRL2_TMRA2EN(v)           (REG_CTIMER_CTCTRL2.U32 = ( (REG_CTIMER_CTCTRL2.U32 & ~(BFM_CTIMER_CTCTRL2_TMRA2EN)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL2_TMRA2EN)) & (BFM_CTIMER_CTCTRL2_TMRA2EN)) ))
#define BFR_CTIMER_CTCTRL2_TMRA2EN()            ((REG_CTIMER_CTCTRL2.U32 & (BFM_CTIMER_CTCTRL2_TMRA2EN))>>(BFP_CTIMER_CTCTRL2_TMRA2EN))


// *****************************************************************************
//                                                                             *
//  CTIMER_CTTMR3 - Counter/Timer Register                                     *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CTTMRB3                    : 16;
        unsigned CTTMRA3                    : 16;
    } B;
} reg_ctimer_cttmr3_t;

#define REG_CTIMER_CTTMR3_ADDR                  (REG_CTIMER_BASEADDR + 0x00000030UL)
#define REG_CTIMER_CTTMR3                       (*(volatile reg_ctimer_cttmr3_t *) REG_CTIMER_CTTMR3_ADDR)
#define REG_CTIMER_CTTMR3_RD()                  (REG_CTIMER_CTTMR3.U32)
#define REG_CTIMER_CTTMR3_WR(v)                 (REG_CTIMER_CTTMR3.U32 = (v))
#define REG_CTIMER_CTTMR3_CLR(m)                (REG_CTIMER_CTTMR3.U32 = ((REG_CTIMER_CTTMR3.U32) & ~(m)))
#define REG_CTIMER_CTTMR3_SET(m)                (REG_CTIMER_CTTMR3.U32 = ((REG_CTIMER_CTTMR3.U32) | (m)))
#define REG_CTIMER_CTTMR3_DEF                   0x00000000

#define BFP_CTIMER_CTTMR3_CTTMRB3               (16)                    /* bitfield lsb */
#define BFM_CTIMER_CTTMR3_CTTMRB3               ((uint32_t)0xffff0000)  /* bitfield mask */
#define BFN_CTIMER_CTTMR3_CTTMRB3               (16)                    /* bitfield width */
#define BFD_CTIMER_CTTMR3_CTTMRB3               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTTMR3_CTTMRB3(v)            ((((uint32_t) v) << (BFP_CTIMER_CTTMR3_CTTMRB3)) & (BFM_CTIMER_CTTMR3_CTTMRB3))
#define BFX_CTIMER_CTTMR3_CTTMRB3(v)            ((((uint32_t) v) & (BFM_CTIMER_CTTMR3_CTTMRB3)) >> (BFP_CTIMER_CTTMR3_CTTMRB3))
#define BFW_CTIMER_CTTMR3_CTTMRB3(v)            (REG_CTIMER_CTTMR3.U32 = ( (REG_CTIMER_CTTMR3.U32 & ~(BFM_CTIMER_CTTMR3_CTTMRB3)) | ((((uint32_t) v)<<(BFP_CTIMER_CTTMR3_CTTMRB3)) & (BFM_CTIMER_CTTMR3_CTTMRB3)) ))
#define BFR_CTIMER_CTTMR3_CTTMRB3()             ((REG_CTIMER_CTTMR3.U32 & (BFM_CTIMER_CTTMR3_CTTMRB3))>>(BFP_CTIMER_CTTMR3_CTTMRB3))

#define BFP_CTIMER_CTTMR3_CTTMRA3               (0)                     /* bitfield lsb */
#define BFM_CTIMER_CTTMR3_CTTMRA3               ((uint32_t)0x0000ffff)  /* bitfield mask */
#define BFN_CTIMER_CTTMR3_CTTMRA3               (16)                    /* bitfield width */
#define BFD_CTIMER_CTTMR3_CTTMRA3               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTTMR3_CTTMRA3(v)            ((((uint32_t) v) << (BFP_CTIMER_CTTMR3_CTTMRA3)) & (BFM_CTIMER_CTTMR3_CTTMRA3))
#define BFX_CTIMER_CTTMR3_CTTMRA3(v)            ((((uint32_t) v) & (BFM_CTIMER_CTTMR3_CTTMRA3)) >> (BFP_CTIMER_CTTMR3_CTTMRA3))
#define BFW_CTIMER_CTTMR3_CTTMRA3(v)            (REG_CTIMER_CTTMR3.U32 = ( (REG_CTIMER_CTTMR3.U32 & ~(BFM_CTIMER_CTTMR3_CTTMRA3)) | ((((uint32_t) v)<<(BFP_CTIMER_CTTMR3_CTTMRA3)) & (BFM_CTIMER_CTTMR3_CTTMRA3)) ))
#define BFR_CTIMER_CTTMR3_CTTMRA3()             ((REG_CTIMER_CTTMR3.U32 & (BFM_CTIMER_CTTMR3_CTTMRA3))>>(BFP_CTIMER_CTTMR3_CTTMRA3))


// *****************************************************************************
//                                                                             *
//  CTIMER_CMPRA3 - Counter/Timer A3 Compare Registers                         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CMPR1A3                    : 16;
        unsigned CMPR0A3                    : 16;
    } B;
} reg_ctimer_cmpra3_t;

#define REG_CTIMER_CMPRA3_ADDR                  (REG_CTIMER_BASEADDR + 0x00000034UL)
#define REG_CTIMER_CMPRA3                       (*(volatile reg_ctimer_cmpra3_t *) REG_CTIMER_CMPRA3_ADDR)
#define REG_CTIMER_CMPRA3_RD()                  (REG_CTIMER_CMPRA3.U32)
#define REG_CTIMER_CMPRA3_WR(v)                 (REG_CTIMER_CMPRA3.U32 = (v))
#define REG_CTIMER_CMPRA3_CLR(m)                (REG_CTIMER_CMPRA3.U32 = ((REG_CTIMER_CMPRA3.U32) & ~(m)))
#define REG_CTIMER_CMPRA3_SET(m)                (REG_CTIMER_CMPRA3.U32 = ((REG_CTIMER_CMPRA3.U32) | (m)))
#define REG_CTIMER_CMPRA3_DEF                   0x00000000

#define BFP_CTIMER_CMPRA3_CMPR1A3               (16)                    /* bitfield lsb */
#define BFM_CTIMER_CMPRA3_CMPR1A3               ((uint32_t)0xffff0000)  /* bitfield mask */
#define BFN_CTIMER_CMPRA3_CMPR1A3               (16)                    /* bitfield width */
#define BFD_CTIMER_CMPRA3_CMPR1A3               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CMPRA3_CMPR1A3(v)            ((((uint32_t) v) << (BFP_CTIMER_CMPRA3_CMPR1A3)) & (BFM_CTIMER_CMPRA3_CMPR1A3))
#define BFX_CTIMER_CMPRA3_CMPR1A3(v)            ((((uint32_t) v) & (BFM_CTIMER_CMPRA3_CMPR1A3)) >> (BFP_CTIMER_CMPRA3_CMPR1A3))
#define BFW_CTIMER_CMPRA3_CMPR1A3(v)            (REG_CTIMER_CMPRA3.U32 = ( (REG_CTIMER_CMPRA3.U32 & ~(BFM_CTIMER_CMPRA3_CMPR1A3)) | ((((uint32_t) v)<<(BFP_CTIMER_CMPRA3_CMPR1A3)) & (BFM_CTIMER_CMPRA3_CMPR1A3)) ))
#define BFR_CTIMER_CMPRA3_CMPR1A3()             ((REG_CTIMER_CMPRA3.U32 & (BFM_CTIMER_CMPRA3_CMPR1A3))>>(BFP_CTIMER_CMPRA3_CMPR1A3))

#define BFP_CTIMER_CMPRA3_CMPR0A3               (0)                     /* bitfield lsb */
#define BFM_CTIMER_CMPRA3_CMPR0A3               ((uint32_t)0x0000ffff)  /* bitfield mask */
#define BFN_CTIMER_CMPRA3_CMPR0A3               (16)                    /* bitfield width */
#define BFD_CTIMER_CMPRA3_CMPR0A3               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CMPRA3_CMPR0A3(v)            ((((uint32_t) v) << (BFP_CTIMER_CMPRA3_CMPR0A3)) & (BFM_CTIMER_CMPRA3_CMPR0A3))
#define BFX_CTIMER_CMPRA3_CMPR0A3(v)            ((((uint32_t) v) & (BFM_CTIMER_CMPRA3_CMPR0A3)) >> (BFP_CTIMER_CMPRA3_CMPR0A3))
#define BFW_CTIMER_CMPRA3_CMPR0A3(v)            (REG_CTIMER_CMPRA3.U32 = ( (REG_CTIMER_CMPRA3.U32 & ~(BFM_CTIMER_CMPRA3_CMPR0A3)) | ((((uint32_t) v)<<(BFP_CTIMER_CMPRA3_CMPR0A3)) & (BFM_CTIMER_CMPRA3_CMPR0A3)) ))
#define BFR_CTIMER_CMPRA3_CMPR0A3()             ((REG_CTIMER_CMPRA3.U32 & (BFM_CTIMER_CMPRA3_CMPR0A3))>>(BFP_CTIMER_CMPRA3_CMPR0A3))


// *****************************************************************************
//                                                                             *
//  CTIMER_CMPRB3 - Counter/Timer B3 Compare Registers                         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CMPR1B3                    : 16;
        unsigned CMPR0B3                    : 16;
    } B;
} reg_ctimer_cmprb3_t;

#define REG_CTIMER_CMPRB3_ADDR                  (REG_CTIMER_BASEADDR + 0x00000038UL)
#define REG_CTIMER_CMPRB3                       (*(volatile reg_ctimer_cmprb3_t *) REG_CTIMER_CMPRB3_ADDR)
#define REG_CTIMER_CMPRB3_RD()                  (REG_CTIMER_CMPRB3.U32)
#define REG_CTIMER_CMPRB3_WR(v)                 (REG_CTIMER_CMPRB3.U32 = (v))
#define REG_CTIMER_CMPRB3_CLR(m)                (REG_CTIMER_CMPRB3.U32 = ((REG_CTIMER_CMPRB3.U32) & ~(m)))
#define REG_CTIMER_CMPRB3_SET(m)                (REG_CTIMER_CMPRB3.U32 = ((REG_CTIMER_CMPRB3.U32) | (m)))
#define REG_CTIMER_CMPRB3_DEF                   0x00000000

#define BFP_CTIMER_CMPRB3_CMPR1B3               (16)                    /* bitfield lsb */
#define BFM_CTIMER_CMPRB3_CMPR1B3               ((uint32_t)0xffff0000)  /* bitfield mask */
#define BFN_CTIMER_CMPRB3_CMPR1B3               (16)                    /* bitfield width */
#define BFD_CTIMER_CMPRB3_CMPR1B3               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CMPRB3_CMPR1B3(v)            ((((uint32_t) v) << (BFP_CTIMER_CMPRB3_CMPR1B3)) & (BFM_CTIMER_CMPRB3_CMPR1B3))
#define BFX_CTIMER_CMPRB3_CMPR1B3(v)            ((((uint32_t) v) & (BFM_CTIMER_CMPRB3_CMPR1B3)) >> (BFP_CTIMER_CMPRB3_CMPR1B3))
#define BFW_CTIMER_CMPRB3_CMPR1B3(v)            (REG_CTIMER_CMPRB3.U32 = ( (REG_CTIMER_CMPRB3.U32 & ~(BFM_CTIMER_CMPRB3_CMPR1B3)) | ((((uint32_t) v)<<(BFP_CTIMER_CMPRB3_CMPR1B3)) & (BFM_CTIMER_CMPRB3_CMPR1B3)) ))
#define BFR_CTIMER_CMPRB3_CMPR1B3()             ((REG_CTIMER_CMPRB3.U32 & (BFM_CTIMER_CMPRB3_CMPR1B3))>>(BFP_CTIMER_CMPRB3_CMPR1B3))

#define BFP_CTIMER_CMPRB3_CMPR0B3               (0)                     /* bitfield lsb */
#define BFM_CTIMER_CMPRB3_CMPR0B3               ((uint32_t)0x0000ffff)  /* bitfield mask */
#define BFN_CTIMER_CMPRB3_CMPR0B3               (16)                    /* bitfield width */
#define BFD_CTIMER_CMPRB3_CMPR0B3               (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CMPRB3_CMPR0B3(v)            ((((uint32_t) v) << (BFP_CTIMER_CMPRB3_CMPR0B3)) & (BFM_CTIMER_CMPRB3_CMPR0B3))
#define BFX_CTIMER_CMPRB3_CMPR0B3(v)            ((((uint32_t) v) & (BFM_CTIMER_CMPRB3_CMPR0B3)) >> (BFP_CTIMER_CMPRB3_CMPR0B3))
#define BFW_CTIMER_CMPRB3_CMPR0B3(v)            (REG_CTIMER_CMPRB3.U32 = ( (REG_CTIMER_CMPRB3.U32 & ~(BFM_CTIMER_CMPRB3_CMPR0B3)) | ((((uint32_t) v)<<(BFP_CTIMER_CMPRB3_CMPR0B3)) & (BFM_CTIMER_CMPRB3_CMPR0B3)) ))
#define BFR_CTIMER_CMPRB3_CMPR0B3()             ((REG_CTIMER_CMPRB3.U32 & (BFM_CTIMER_CMPRB3_CMPR0B3))>>(BFP_CTIMER_CMPRB3_CMPR0B3))


// *****************************************************************************
//                                                                             *
//  CTIMER_CTCTRL3 - Counter/Timer Control                                     *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CTLINK3                    :  1;
        unsigned RSVD_29                    :  2;
        unsigned TMRB3POL                   :  1;
        unsigned TMRB3CLR                   :  1;
        unsigned TMRB3PE                    :  1;
        unsigned TMRB3IE                    :  1;
        unsigned TMRB3FN                    :  3;
        unsigned TMRB3CLK                   :  5;
        unsigned TMRB3EN                    :  1;
        unsigned ADCEN                      :  1;
        unsigned RSVD_13                    :  2;
        unsigned TMRA3POL                   :  1;
        unsigned TMRA3CLR                   :  1;
        unsigned TMRA3PE                    :  1;
        unsigned TMRA3IE                    :  1;
        unsigned TMRA3FN                    :  3;
        unsigned TMRA3CLK                   :  5;
        unsigned TMRA3EN                    :  1;
    } B;
} reg_ctimer_ctctrl3_t;

#define REG_CTIMER_CTCTRL3_ADDR                 (REG_CTIMER_BASEADDR + 0x0000003CUL)
#define REG_CTIMER_CTCTRL3                      (*(volatile reg_ctimer_ctctrl3_t *) REG_CTIMER_CTCTRL3_ADDR)
#define REG_CTIMER_CTCTRL3_RD()                 (REG_CTIMER_CTCTRL3.U32)
#define REG_CTIMER_CTCTRL3_WR(v)                (REG_CTIMER_CTCTRL3.U32 = (v))
#define REG_CTIMER_CTCTRL3_CLR(m)               (REG_CTIMER_CTCTRL3.U32 = ((REG_CTIMER_CTCTRL3.U32) & ~(m)))
#define REG_CTIMER_CTCTRL3_SET(m)               (REG_CTIMER_CTCTRL3.U32 = ((REG_CTIMER_CTCTRL3.U32) | (m)))
#define REG_CTIMER_CTCTRL3_DEF                  0x00020002

#define BFP_CTIMER_CTCTRL3_CTLINK3              (31)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_CTLINK3              ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_CTLINK3              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_CTLINK3              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_CTLINK3(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_CTLINK3)) & (BFM_CTIMER_CTCTRL3_CTLINK3))
#define BFX_CTIMER_CTCTRL3_CTLINK3(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_CTLINK3)) >> (BFP_CTIMER_CTCTRL3_CTLINK3))
#define BFW_CTIMER_CTCTRL3_CTLINK3(v)           (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_CTLINK3)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_CTLINK3)) & (BFM_CTIMER_CTCTRL3_CTLINK3)) ))
#define BFR_CTIMER_CTCTRL3_CTLINK3()            ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_CTLINK3))>>(BFP_CTIMER_CTCTRL3_CTLINK3))

#define BFP_CTIMER_CTCTRL3_RSVD_29              (29)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_RSVD_29              ((uint32_t)0x60000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_RSVD_29              (2)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_RSVD_29              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_RSVD_29(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_RSVD_29)) & (BFM_CTIMER_CTCTRL3_RSVD_29))
#define BFX_CTIMER_CTCTRL3_RSVD_29(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_RSVD_29)) >> (BFP_CTIMER_CTCTRL3_RSVD_29))
#define BFW_CTIMER_CTCTRL3_RSVD_29(v)           (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_RSVD_29)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_RSVD_29)) & (BFM_CTIMER_CTCTRL3_RSVD_29)) ))
#define BFR_CTIMER_CTCTRL3_RSVD_29()            ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_RSVD_29))>>(BFP_CTIMER_CTCTRL3_RSVD_29))

#define BFP_CTIMER_CTCTRL3_TMRB3POL             (28)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_TMRB3POL             ((uint32_t)0x10000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_TMRB3POL             (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_TMRB3POL             (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_TMRB3POL(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_TMRB3POL)) & (BFM_CTIMER_CTCTRL3_TMRB3POL))
#define BFX_CTIMER_CTCTRL3_TMRB3POL(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_TMRB3POL)) >> (BFP_CTIMER_CTCTRL3_TMRB3POL))
#define BFW_CTIMER_CTCTRL3_TMRB3POL(v)          (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_TMRB3POL)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_TMRB3POL)) & (BFM_CTIMER_CTCTRL3_TMRB3POL)) ))
#define BFR_CTIMER_CTCTRL3_TMRB3POL()           ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_TMRB3POL))>>(BFP_CTIMER_CTCTRL3_TMRB3POL))

#define BFP_CTIMER_CTCTRL3_TMRB3CLR             (27)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_TMRB3CLR             ((uint32_t)0x08000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_TMRB3CLR             (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_TMRB3CLR             (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_TMRB3CLR(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_TMRB3CLR)) & (BFM_CTIMER_CTCTRL3_TMRB3CLR))
#define BFX_CTIMER_CTCTRL3_TMRB3CLR(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_TMRB3CLR)) >> (BFP_CTIMER_CTCTRL3_TMRB3CLR))
#define BFW_CTIMER_CTCTRL3_TMRB3CLR(v)          (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_TMRB3CLR)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_TMRB3CLR)) & (BFM_CTIMER_CTCTRL3_TMRB3CLR)) ))
#define BFR_CTIMER_CTCTRL3_TMRB3CLR()           ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_TMRB3CLR))>>(BFP_CTIMER_CTCTRL3_TMRB3CLR))

#define BFP_CTIMER_CTCTRL3_TMRB3PE              (26)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_TMRB3PE              ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_TMRB3PE              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_TMRB3PE              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_TMRB3PE(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_TMRB3PE)) & (BFM_CTIMER_CTCTRL3_TMRB3PE))
#define BFX_CTIMER_CTCTRL3_TMRB3PE(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_TMRB3PE)) >> (BFP_CTIMER_CTCTRL3_TMRB3PE))
#define BFW_CTIMER_CTCTRL3_TMRB3PE(v)           (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_TMRB3PE)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_TMRB3PE)) & (BFM_CTIMER_CTCTRL3_TMRB3PE)) ))
#define BFR_CTIMER_CTCTRL3_TMRB3PE()            ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_TMRB3PE))>>(BFP_CTIMER_CTCTRL3_TMRB3PE))

#define BFP_CTIMER_CTCTRL3_TMRB3IE              (25)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_TMRB3IE              ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_TMRB3IE              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_TMRB3IE              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_TMRB3IE(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_TMRB3IE)) & (BFM_CTIMER_CTCTRL3_TMRB3IE))
#define BFX_CTIMER_CTCTRL3_TMRB3IE(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_TMRB3IE)) >> (BFP_CTIMER_CTCTRL3_TMRB3IE))
#define BFW_CTIMER_CTCTRL3_TMRB3IE(v)           (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_TMRB3IE)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_TMRB3IE)) & (BFM_CTIMER_CTCTRL3_TMRB3IE)) ))
#define BFR_CTIMER_CTCTRL3_TMRB3IE()            ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_TMRB3IE))>>(BFP_CTIMER_CTCTRL3_TMRB3IE))

#define BFP_CTIMER_CTCTRL3_TMRB3FN              (22)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_TMRB3FN              ((uint32_t)0x01c00000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_TMRB3FN              (3)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_TMRB3FN              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_TMRB3FN(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_TMRB3FN)) & (BFM_CTIMER_CTCTRL3_TMRB3FN))
#define BFX_CTIMER_CTCTRL3_TMRB3FN(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_TMRB3FN)) >> (BFP_CTIMER_CTCTRL3_TMRB3FN))
#define BFW_CTIMER_CTCTRL3_TMRB3FN(v)           (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_TMRB3FN)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_TMRB3FN)) & (BFM_CTIMER_CTCTRL3_TMRB3FN)) ))
#define BFR_CTIMER_CTCTRL3_TMRB3FN()            ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_TMRB3FN))>>(BFP_CTIMER_CTCTRL3_TMRB3FN))

#define BFP_CTIMER_CTCTRL3_TMRB3CLK             (17)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_TMRB3CLK             ((uint32_t)0x003e0000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_TMRB3CLK             (5)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_TMRB3CLK             (0x1)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_TMRB3CLK(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_TMRB3CLK)) & (BFM_CTIMER_CTCTRL3_TMRB3CLK))
#define BFX_CTIMER_CTCTRL3_TMRB3CLK(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_TMRB3CLK)) >> (BFP_CTIMER_CTCTRL3_TMRB3CLK))
#define BFW_CTIMER_CTCTRL3_TMRB3CLK(v)          (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_TMRB3CLK)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_TMRB3CLK)) & (BFM_CTIMER_CTCTRL3_TMRB3CLK)) ))
#define BFR_CTIMER_CTCTRL3_TMRB3CLK()           ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_TMRB3CLK))>>(BFP_CTIMER_CTCTRL3_TMRB3CLK))

#define BFP_CTIMER_CTCTRL3_TMRB3EN              (16)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_TMRB3EN              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_TMRB3EN              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_TMRB3EN              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_TMRB3EN(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_TMRB3EN)) & (BFM_CTIMER_CTCTRL3_TMRB3EN))
#define BFX_CTIMER_CTCTRL3_TMRB3EN(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_TMRB3EN)) >> (BFP_CTIMER_CTCTRL3_TMRB3EN))
#define BFW_CTIMER_CTCTRL3_TMRB3EN(v)           (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_TMRB3EN)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_TMRB3EN)) & (BFM_CTIMER_CTCTRL3_TMRB3EN)) ))
#define BFR_CTIMER_CTCTRL3_TMRB3EN()            ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_TMRB3EN))>>(BFP_CTIMER_CTCTRL3_TMRB3EN))

#define BFP_CTIMER_CTCTRL3_ADCEN                (15)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_ADCEN                ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_ADCEN                (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_ADCEN                (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_ADCEN(v)             ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_ADCEN)) & (BFM_CTIMER_CTCTRL3_ADCEN))
#define BFX_CTIMER_CTCTRL3_ADCEN(v)             ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_ADCEN)) >> (BFP_CTIMER_CTCTRL3_ADCEN))
#define BFW_CTIMER_CTCTRL3_ADCEN(v)             (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_ADCEN)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_ADCEN)) & (BFM_CTIMER_CTCTRL3_ADCEN)) ))
#define BFR_CTIMER_CTCTRL3_ADCEN()              ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_ADCEN))>>(BFP_CTIMER_CTCTRL3_ADCEN))

#define BFP_CTIMER_CTCTRL3_RSVD_13              (13)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_RSVD_13              ((uint32_t)0x00006000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_RSVD_13              (2)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_RSVD_13              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_RSVD_13(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_RSVD_13)) & (BFM_CTIMER_CTCTRL3_RSVD_13))
#define BFX_CTIMER_CTCTRL3_RSVD_13(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_RSVD_13)) >> (BFP_CTIMER_CTCTRL3_RSVD_13))
#define BFW_CTIMER_CTCTRL3_RSVD_13(v)           (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_RSVD_13)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_RSVD_13)) & (BFM_CTIMER_CTCTRL3_RSVD_13)) ))
#define BFR_CTIMER_CTCTRL3_RSVD_13()            ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_RSVD_13))>>(BFP_CTIMER_CTCTRL3_RSVD_13))

#define BFP_CTIMER_CTCTRL3_TMRA3POL             (12)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_TMRA3POL             ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_TMRA3POL             (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_TMRA3POL             (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_TMRA3POL(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_TMRA3POL)) & (BFM_CTIMER_CTCTRL3_TMRA3POL))
#define BFX_CTIMER_CTCTRL3_TMRA3POL(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_TMRA3POL)) >> (BFP_CTIMER_CTCTRL3_TMRA3POL))
#define BFW_CTIMER_CTCTRL3_TMRA3POL(v)          (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_TMRA3POL)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_TMRA3POL)) & (BFM_CTIMER_CTCTRL3_TMRA3POL)) ))
#define BFR_CTIMER_CTCTRL3_TMRA3POL()           ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_TMRA3POL))>>(BFP_CTIMER_CTCTRL3_TMRA3POL))

#define BFP_CTIMER_CTCTRL3_TMRA3CLR             (11)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_TMRA3CLR             ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_TMRA3CLR             (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_TMRA3CLR             (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_TMRA3CLR(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_TMRA3CLR)) & (BFM_CTIMER_CTCTRL3_TMRA3CLR))
#define BFX_CTIMER_CTCTRL3_TMRA3CLR(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_TMRA3CLR)) >> (BFP_CTIMER_CTCTRL3_TMRA3CLR))
#define BFW_CTIMER_CTCTRL3_TMRA3CLR(v)          (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_TMRA3CLR)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_TMRA3CLR)) & (BFM_CTIMER_CTCTRL3_TMRA3CLR)) ))
#define BFR_CTIMER_CTCTRL3_TMRA3CLR()           ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_TMRA3CLR))>>(BFP_CTIMER_CTCTRL3_TMRA3CLR))

#define BFP_CTIMER_CTCTRL3_TMRA3PE              (10)                    /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_TMRA3PE              ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_TMRA3PE              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_TMRA3PE              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_TMRA3PE(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_TMRA3PE)) & (BFM_CTIMER_CTCTRL3_TMRA3PE))
#define BFX_CTIMER_CTCTRL3_TMRA3PE(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_TMRA3PE)) >> (BFP_CTIMER_CTCTRL3_TMRA3PE))
#define BFW_CTIMER_CTCTRL3_TMRA3PE(v)           (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_TMRA3PE)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_TMRA3PE)) & (BFM_CTIMER_CTCTRL3_TMRA3PE)) ))
#define BFR_CTIMER_CTCTRL3_TMRA3PE()            ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_TMRA3PE))>>(BFP_CTIMER_CTCTRL3_TMRA3PE))

#define BFP_CTIMER_CTCTRL3_TMRA3IE              (9)                     /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_TMRA3IE              ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_TMRA3IE              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_TMRA3IE              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_TMRA3IE(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_TMRA3IE)) & (BFM_CTIMER_CTCTRL3_TMRA3IE))
#define BFX_CTIMER_CTCTRL3_TMRA3IE(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_TMRA3IE)) >> (BFP_CTIMER_CTCTRL3_TMRA3IE))
#define BFW_CTIMER_CTCTRL3_TMRA3IE(v)           (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_TMRA3IE)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_TMRA3IE)) & (BFM_CTIMER_CTCTRL3_TMRA3IE)) ))
#define BFR_CTIMER_CTCTRL3_TMRA3IE()            ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_TMRA3IE))>>(BFP_CTIMER_CTCTRL3_TMRA3IE))

#define BFP_CTIMER_CTCTRL3_TMRA3FN              (6)                     /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_TMRA3FN              ((uint32_t)0x000001c0)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_TMRA3FN              (3)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_TMRA3FN              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_TMRA3FN(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_TMRA3FN)) & (BFM_CTIMER_CTCTRL3_TMRA3FN))
#define BFX_CTIMER_CTCTRL3_TMRA3FN(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_TMRA3FN)) >> (BFP_CTIMER_CTCTRL3_TMRA3FN))
#define BFW_CTIMER_CTCTRL3_TMRA3FN(v)           (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_TMRA3FN)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_TMRA3FN)) & (BFM_CTIMER_CTCTRL3_TMRA3FN)) ))
#define BFR_CTIMER_CTCTRL3_TMRA3FN()            ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_TMRA3FN))>>(BFP_CTIMER_CTCTRL3_TMRA3FN))

#define BFP_CTIMER_CTCTRL3_TMRA3CLK             (1)                     /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_TMRA3CLK             ((uint32_t)0x0000003e)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_TMRA3CLK             (5)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_TMRA3CLK             (0x1)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_TMRA3CLK(v)          ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_TMRA3CLK)) & (BFM_CTIMER_CTCTRL3_TMRA3CLK))
#define BFX_CTIMER_CTCTRL3_TMRA3CLK(v)          ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_TMRA3CLK)) >> (BFP_CTIMER_CTCTRL3_TMRA3CLK))
#define BFW_CTIMER_CTCTRL3_TMRA3CLK(v)          (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_TMRA3CLK)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_TMRA3CLK)) & (BFM_CTIMER_CTCTRL3_TMRA3CLK)) ))
#define BFR_CTIMER_CTCTRL3_TMRA3CLK()           ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_TMRA3CLK))>>(BFP_CTIMER_CTCTRL3_TMRA3CLK))

#define BFP_CTIMER_CTCTRL3_TMRA3EN              (0)                     /* bitfield lsb */
#define BFM_CTIMER_CTCTRL3_TMRA3EN              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CTIMER_CTCTRL3_TMRA3EN              (1)                     /* bitfield width */
#define BFD_CTIMER_CTCTRL3_TMRA3EN              (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTCTRL3_TMRA3EN(v)           ((((uint32_t) v) << (BFP_CTIMER_CTCTRL3_TMRA3EN)) & (BFM_CTIMER_CTCTRL3_TMRA3EN))
#define BFX_CTIMER_CTCTRL3_TMRA3EN(v)           ((((uint32_t) v) & (BFM_CTIMER_CTCTRL3_TMRA3EN)) >> (BFP_CTIMER_CTCTRL3_TMRA3EN))
#define BFW_CTIMER_CTCTRL3_TMRA3EN(v)           (REG_CTIMER_CTCTRL3.U32 = ( (REG_CTIMER_CTCTRL3.U32 & ~(BFM_CTIMER_CTCTRL3_TMRA3EN)) | ((((uint32_t) v)<<(BFP_CTIMER_CTCTRL3_TMRA3EN)) & (BFM_CTIMER_CTCTRL3_TMRA3EN)) ))
#define BFR_CTIMER_CTCTRL3_TMRA3EN()            ((REG_CTIMER_CTCTRL3.U32 & (BFM_CTIMER_CTCTRL3_TMRA3EN))>>(BFP_CTIMER_CTCTRL3_TMRA3EN))


// *****************************************************************************
//                                                                             *
//  CTIMER_CTIMERINTEN - Counter/Timer Interrupts                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned CTMRB3INT                  :  1;
        unsigned CTMRA3INT                  :  1;
        unsigned CTMRB2INT                  :  1;
        unsigned CTMRA2INT                  :  1;
        unsigned CTMRB1INT                  :  1;
        unsigned CTMRA1INT                  :  1;
        unsigned CTMRB0INT                  :  1;
        unsigned CTMRA0INT                  :  1;
    } B;
} reg_ctimer_ctimerinten_t;

#define REG_CTIMER_CTIMERINTEN_ADDR             (REG_CTIMER_BASEADDR + 0x00000200UL)
#define REG_CTIMER_CTIMERINTEN                  (*(volatile reg_ctimer_ctimerinten_t *) REG_CTIMER_CTIMERINTEN_ADDR)
#define REG_CTIMER_CTIMERINTEN_RD()             (REG_CTIMER_CTIMERINTEN.U32)
#define REG_CTIMER_CTIMERINTEN_WR(v)            (REG_CTIMER_CTIMERINTEN.U32 = (v))
#define REG_CTIMER_CTIMERINTEN_CLR(m)           (REG_CTIMER_CTIMERINTEN.U32 = ((REG_CTIMER_CTIMERINTEN.U32) & ~(m)))
#define REG_CTIMER_CTIMERINTEN_SET(m)           (REG_CTIMER_CTIMERINTEN.U32 = ((REG_CTIMER_CTIMERINTEN.U32) | (m)))
#define REG_CTIMER_CTIMERINTEN_DEF              0x00000000

#define BFP_CTIMER_CTIMERINTEN_RSVD_8           (8)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTEN_RSVD_8           ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTEN_RSVD_8           (24)                    /* bitfield width */
#define BFD_CTIMER_CTIMERINTEN_RSVD_8           (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTEN_RSVD_8(v)        ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTEN_RSVD_8)) & (BFM_CTIMER_CTIMERINTEN_RSVD_8))
#define BFX_CTIMER_CTIMERINTEN_RSVD_8(v)        ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTEN_RSVD_8)) >> (BFP_CTIMER_CTIMERINTEN_RSVD_8))
#define BFW_CTIMER_CTIMERINTEN_RSVD_8(v)        (REG_CTIMER_CTIMERINTEN.U32 = ( (REG_CTIMER_CTIMERINTEN.U32 & ~(BFM_CTIMER_CTIMERINTEN_RSVD_8)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTEN_RSVD_8)) & (BFM_CTIMER_CTIMERINTEN_RSVD_8)) ))
#define BFR_CTIMER_CTIMERINTEN_RSVD_8()         ((REG_CTIMER_CTIMERINTEN.U32 & (BFM_CTIMER_CTIMERINTEN_RSVD_8))>>(BFP_CTIMER_CTIMERINTEN_RSVD_8))
#define BFS_CTIMER_CTIMERINTEN_RSVD_8()         (REG_CTIMER_CTIMERINTEN.U32 = (BFM_CTIMER_CTIMERINTEN_RSVD_8) )

#define BFP_CTIMER_CTIMERINTEN_CTMRB3INT        (7)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTEN_CTMRB3INT        ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTEN_CTMRB3INT        (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTEN_CTMRB3INT        (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTEN_CTMRB3INT(v)     ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTEN_CTMRB3INT)) & (BFM_CTIMER_CTIMERINTEN_CTMRB3INT))
#define BFX_CTIMER_CTIMERINTEN_CTMRB3INT(v)     ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTEN_CTMRB3INT)) >> (BFP_CTIMER_CTIMERINTEN_CTMRB3INT))
#define BFW_CTIMER_CTIMERINTEN_CTMRB3INT(v)     (REG_CTIMER_CTIMERINTEN.U32 = ( (REG_CTIMER_CTIMERINTEN.U32 & ~(BFM_CTIMER_CTIMERINTEN_CTMRB3INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTEN_CTMRB3INT)) & (BFM_CTIMER_CTIMERINTEN_CTMRB3INT)) ))
#define BFR_CTIMER_CTIMERINTEN_CTMRB3INT()      ((REG_CTIMER_CTIMERINTEN.U32 & (BFM_CTIMER_CTIMERINTEN_CTMRB3INT))>>(BFP_CTIMER_CTIMERINTEN_CTMRB3INT))
#define BFS_CTIMER_CTIMERINTEN_CTMRB3INT()      (REG_CTIMER_CTIMERINTEN.U32 = (BFM_CTIMER_CTIMERINTEN_CTMRB3INT) )

#define BFP_CTIMER_CTIMERINTEN_CTMRA3INT        (6)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTEN_CTMRA3INT        ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTEN_CTMRA3INT        (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTEN_CTMRA3INT        (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTEN_CTMRA3INT(v)     ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTEN_CTMRA3INT)) & (BFM_CTIMER_CTIMERINTEN_CTMRA3INT))
#define BFX_CTIMER_CTIMERINTEN_CTMRA3INT(v)     ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTEN_CTMRA3INT)) >> (BFP_CTIMER_CTIMERINTEN_CTMRA3INT))
#define BFW_CTIMER_CTIMERINTEN_CTMRA3INT(v)     (REG_CTIMER_CTIMERINTEN.U32 = ( (REG_CTIMER_CTIMERINTEN.U32 & ~(BFM_CTIMER_CTIMERINTEN_CTMRA3INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTEN_CTMRA3INT)) & (BFM_CTIMER_CTIMERINTEN_CTMRA3INT)) ))
#define BFR_CTIMER_CTIMERINTEN_CTMRA3INT()      ((REG_CTIMER_CTIMERINTEN.U32 & (BFM_CTIMER_CTIMERINTEN_CTMRA3INT))>>(BFP_CTIMER_CTIMERINTEN_CTMRA3INT))
#define BFS_CTIMER_CTIMERINTEN_CTMRA3INT()      (REG_CTIMER_CTIMERINTEN.U32 = (BFM_CTIMER_CTIMERINTEN_CTMRA3INT) )

#define BFP_CTIMER_CTIMERINTEN_CTMRB2INT        (5)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTEN_CTMRB2INT        ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTEN_CTMRB2INT        (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTEN_CTMRB2INT        (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTEN_CTMRB2INT(v)     ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTEN_CTMRB2INT)) & (BFM_CTIMER_CTIMERINTEN_CTMRB2INT))
#define BFX_CTIMER_CTIMERINTEN_CTMRB2INT(v)     ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTEN_CTMRB2INT)) >> (BFP_CTIMER_CTIMERINTEN_CTMRB2INT))
#define BFW_CTIMER_CTIMERINTEN_CTMRB2INT(v)     (REG_CTIMER_CTIMERINTEN.U32 = ( (REG_CTIMER_CTIMERINTEN.U32 & ~(BFM_CTIMER_CTIMERINTEN_CTMRB2INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTEN_CTMRB2INT)) & (BFM_CTIMER_CTIMERINTEN_CTMRB2INT)) ))
#define BFR_CTIMER_CTIMERINTEN_CTMRB2INT()      ((REG_CTIMER_CTIMERINTEN.U32 & (BFM_CTIMER_CTIMERINTEN_CTMRB2INT))>>(BFP_CTIMER_CTIMERINTEN_CTMRB2INT))
#define BFS_CTIMER_CTIMERINTEN_CTMRB2INT()      (REG_CTIMER_CTIMERINTEN.U32 = (BFM_CTIMER_CTIMERINTEN_CTMRB2INT) )

#define BFP_CTIMER_CTIMERINTEN_CTMRA2INT        (4)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTEN_CTMRA2INT        ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTEN_CTMRA2INT        (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTEN_CTMRA2INT        (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTEN_CTMRA2INT(v)     ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTEN_CTMRA2INT)) & (BFM_CTIMER_CTIMERINTEN_CTMRA2INT))
#define BFX_CTIMER_CTIMERINTEN_CTMRA2INT(v)     ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTEN_CTMRA2INT)) >> (BFP_CTIMER_CTIMERINTEN_CTMRA2INT))
#define BFW_CTIMER_CTIMERINTEN_CTMRA2INT(v)     (REG_CTIMER_CTIMERINTEN.U32 = ( (REG_CTIMER_CTIMERINTEN.U32 & ~(BFM_CTIMER_CTIMERINTEN_CTMRA2INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTEN_CTMRA2INT)) & (BFM_CTIMER_CTIMERINTEN_CTMRA2INT)) ))
#define BFR_CTIMER_CTIMERINTEN_CTMRA2INT()      ((REG_CTIMER_CTIMERINTEN.U32 & (BFM_CTIMER_CTIMERINTEN_CTMRA2INT))>>(BFP_CTIMER_CTIMERINTEN_CTMRA2INT))
#define BFS_CTIMER_CTIMERINTEN_CTMRA2INT()      (REG_CTIMER_CTIMERINTEN.U32 = (BFM_CTIMER_CTIMERINTEN_CTMRA2INT) )

#define BFP_CTIMER_CTIMERINTEN_CTMRB1INT        (3)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTEN_CTMRB1INT        ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTEN_CTMRB1INT        (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTEN_CTMRB1INT        (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTEN_CTMRB1INT(v)     ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTEN_CTMRB1INT)) & (BFM_CTIMER_CTIMERINTEN_CTMRB1INT))
#define BFX_CTIMER_CTIMERINTEN_CTMRB1INT(v)     ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTEN_CTMRB1INT)) >> (BFP_CTIMER_CTIMERINTEN_CTMRB1INT))
#define BFW_CTIMER_CTIMERINTEN_CTMRB1INT(v)     (REG_CTIMER_CTIMERINTEN.U32 = ( (REG_CTIMER_CTIMERINTEN.U32 & ~(BFM_CTIMER_CTIMERINTEN_CTMRB1INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTEN_CTMRB1INT)) & (BFM_CTIMER_CTIMERINTEN_CTMRB1INT)) ))
#define BFR_CTIMER_CTIMERINTEN_CTMRB1INT()      ((REG_CTIMER_CTIMERINTEN.U32 & (BFM_CTIMER_CTIMERINTEN_CTMRB1INT))>>(BFP_CTIMER_CTIMERINTEN_CTMRB1INT))
#define BFS_CTIMER_CTIMERINTEN_CTMRB1INT()      (REG_CTIMER_CTIMERINTEN.U32 = (BFM_CTIMER_CTIMERINTEN_CTMRB1INT) )

#define BFP_CTIMER_CTIMERINTEN_CTMRA1INT        (2)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTEN_CTMRA1INT        ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTEN_CTMRA1INT        (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTEN_CTMRA1INT        (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTEN_CTMRA1INT(v)     ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTEN_CTMRA1INT)) & (BFM_CTIMER_CTIMERINTEN_CTMRA1INT))
#define BFX_CTIMER_CTIMERINTEN_CTMRA1INT(v)     ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTEN_CTMRA1INT)) >> (BFP_CTIMER_CTIMERINTEN_CTMRA1INT))
#define BFW_CTIMER_CTIMERINTEN_CTMRA1INT(v)     (REG_CTIMER_CTIMERINTEN.U32 = ( (REG_CTIMER_CTIMERINTEN.U32 & ~(BFM_CTIMER_CTIMERINTEN_CTMRA1INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTEN_CTMRA1INT)) & (BFM_CTIMER_CTIMERINTEN_CTMRA1INT)) ))
#define BFR_CTIMER_CTIMERINTEN_CTMRA1INT()      ((REG_CTIMER_CTIMERINTEN.U32 & (BFM_CTIMER_CTIMERINTEN_CTMRA1INT))>>(BFP_CTIMER_CTIMERINTEN_CTMRA1INT))
#define BFS_CTIMER_CTIMERINTEN_CTMRA1INT()      (REG_CTIMER_CTIMERINTEN.U32 = (BFM_CTIMER_CTIMERINTEN_CTMRA1INT) )

#define BFP_CTIMER_CTIMERINTEN_CTMRB0INT        (1)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTEN_CTMRB0INT        ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTEN_CTMRB0INT        (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTEN_CTMRB0INT        (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTEN_CTMRB0INT(v)     ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTEN_CTMRB0INT)) & (BFM_CTIMER_CTIMERINTEN_CTMRB0INT))
#define BFX_CTIMER_CTIMERINTEN_CTMRB0INT(v)     ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTEN_CTMRB0INT)) >> (BFP_CTIMER_CTIMERINTEN_CTMRB0INT))
#define BFW_CTIMER_CTIMERINTEN_CTMRB0INT(v)     (REG_CTIMER_CTIMERINTEN.U32 = ( (REG_CTIMER_CTIMERINTEN.U32 & ~(BFM_CTIMER_CTIMERINTEN_CTMRB0INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTEN_CTMRB0INT)) & (BFM_CTIMER_CTIMERINTEN_CTMRB0INT)) ))
#define BFR_CTIMER_CTIMERINTEN_CTMRB0INT()      ((REG_CTIMER_CTIMERINTEN.U32 & (BFM_CTIMER_CTIMERINTEN_CTMRB0INT))>>(BFP_CTIMER_CTIMERINTEN_CTMRB0INT))
#define BFS_CTIMER_CTIMERINTEN_CTMRB0INT()      (REG_CTIMER_CTIMERINTEN.U32 = (BFM_CTIMER_CTIMERINTEN_CTMRB0INT) )

#define BFP_CTIMER_CTIMERINTEN_CTMRA0INT        (0)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTEN_CTMRA0INT        ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTEN_CTMRA0INT        (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTEN_CTMRA0INT        (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTEN_CTMRA0INT(v)     ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTEN_CTMRA0INT)) & (BFM_CTIMER_CTIMERINTEN_CTMRA0INT))
#define BFX_CTIMER_CTIMERINTEN_CTMRA0INT(v)     ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTEN_CTMRA0INT)) >> (BFP_CTIMER_CTIMERINTEN_CTMRA0INT))
#define BFW_CTIMER_CTIMERINTEN_CTMRA0INT(v)     (REG_CTIMER_CTIMERINTEN.U32 = ( (REG_CTIMER_CTIMERINTEN.U32 & ~(BFM_CTIMER_CTIMERINTEN_CTMRA0INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTEN_CTMRA0INT)) & (BFM_CTIMER_CTIMERINTEN_CTMRA0INT)) ))
#define BFR_CTIMER_CTIMERINTEN_CTMRA0INT()      ((REG_CTIMER_CTIMERINTEN.U32 & (BFM_CTIMER_CTIMERINTEN_CTMRA0INT))>>(BFP_CTIMER_CTIMERINTEN_CTMRA0INT))
#define BFS_CTIMER_CTIMERINTEN_CTMRA0INT()      (REG_CTIMER_CTIMERINTEN.U32 = (BFM_CTIMER_CTIMERINTEN_CTMRA0INT) )


// *****************************************************************************
//                                                                             *
//  CTIMER_CTIMERINTSTAT - Counter/Timer Interrupts                            *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned CTMRB3INT                  :  1;
        unsigned CTMRA3INT                  :  1;
        unsigned CTMRB2INT                  :  1;
        unsigned CTMRA2INT                  :  1;
        unsigned CTMRB1INT                  :  1;
        unsigned CTMRA1INT                  :  1;
        unsigned CTMRB0INT                  :  1;
        unsigned CTMRA0INT                  :  1;
    } B;
} reg_ctimer_ctimerintstat_t;

#define REG_CTIMER_CTIMERINTSTAT_ADDR           (REG_CTIMER_BASEADDR + 0x00000204UL)
#define REG_CTIMER_CTIMERINTSTAT                (*(volatile reg_ctimer_ctimerintstat_t *) REG_CTIMER_CTIMERINTSTAT_ADDR)
#define REG_CTIMER_CTIMERINTSTAT_RD()           (REG_CTIMER_CTIMERINTSTAT.U32)
#define REG_CTIMER_CTIMERINTSTAT_WR(v)          (REG_CTIMER_CTIMERINTSTAT.U32 = (v))
#define REG_CTIMER_CTIMERINTSTAT_CLR(m)         (REG_CTIMER_CTIMERINTSTAT.U32 = ((REG_CTIMER_CTIMERINTSTAT.U32) & ~(m)))
#define REG_CTIMER_CTIMERINTSTAT_SET(m)         (REG_CTIMER_CTIMERINTSTAT.U32 = ((REG_CTIMER_CTIMERINTSTAT.U32) | (m)))
#define REG_CTIMER_CTIMERINTSTAT_DEF            0x00000000

#define BFP_CTIMER_CTIMERINTSTAT_RSVD_8         (8)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSTAT_RSVD_8         ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSTAT_RSVD_8         (24)                    /* bitfield width */
#define BFD_CTIMER_CTIMERINTSTAT_RSVD_8         (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSTAT_RSVD_8(v)      ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSTAT_RSVD_8)) & (BFM_CTIMER_CTIMERINTSTAT_RSVD_8))
#define BFX_CTIMER_CTIMERINTSTAT_RSVD_8(v)      ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSTAT_RSVD_8)) >> (BFP_CTIMER_CTIMERINTSTAT_RSVD_8))
#define BFW_CTIMER_CTIMERINTSTAT_RSVD_8(v)      (REG_CTIMER_CTIMERINTSTAT.U32 = ( (REG_CTIMER_CTIMERINTSTAT.U32 & ~(BFM_CTIMER_CTIMERINTSTAT_RSVD_8)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSTAT_RSVD_8)) & (BFM_CTIMER_CTIMERINTSTAT_RSVD_8)) ))
#define BFR_CTIMER_CTIMERINTSTAT_RSVD_8()       ((REG_CTIMER_CTIMERINTSTAT.U32 & (BFM_CTIMER_CTIMERINTSTAT_RSVD_8))>>(BFP_CTIMER_CTIMERINTSTAT_RSVD_8))
#define BFS_CTIMER_CTIMERINTSTAT_RSVD_8()       (REG_CTIMER_CTIMERINTSTAT.U32 = (BFM_CTIMER_CTIMERINTSTAT_RSVD_8) )

#define BFP_CTIMER_CTIMERINTSTAT_CTMRB3INT      (7)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSTAT_CTMRB3INT      ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSTAT_CTMRB3INT      (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTSTAT_CTMRB3INT      (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSTAT_CTMRB3INT(v)   ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSTAT_CTMRB3INT)) & (BFM_CTIMER_CTIMERINTSTAT_CTMRB3INT))
#define BFX_CTIMER_CTIMERINTSTAT_CTMRB3INT(v)   ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSTAT_CTMRB3INT)) >> (BFP_CTIMER_CTIMERINTSTAT_CTMRB3INT))
#define BFW_CTIMER_CTIMERINTSTAT_CTMRB3INT(v)   (REG_CTIMER_CTIMERINTSTAT.U32 = ( (REG_CTIMER_CTIMERINTSTAT.U32 & ~(BFM_CTIMER_CTIMERINTSTAT_CTMRB3INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSTAT_CTMRB3INT)) & (BFM_CTIMER_CTIMERINTSTAT_CTMRB3INT)) ))
#define BFR_CTIMER_CTIMERINTSTAT_CTMRB3INT()    ((REG_CTIMER_CTIMERINTSTAT.U32 & (BFM_CTIMER_CTIMERINTSTAT_CTMRB3INT))>>(BFP_CTIMER_CTIMERINTSTAT_CTMRB3INT))
#define BFS_CTIMER_CTIMERINTSTAT_CTMRB3INT()    (REG_CTIMER_CTIMERINTSTAT.U32 = (BFM_CTIMER_CTIMERINTSTAT_CTMRB3INT) )

#define BFP_CTIMER_CTIMERINTSTAT_CTMRA3INT      (6)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSTAT_CTMRA3INT      ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSTAT_CTMRA3INT      (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTSTAT_CTMRA3INT      (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSTAT_CTMRA3INT(v)   ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSTAT_CTMRA3INT)) & (BFM_CTIMER_CTIMERINTSTAT_CTMRA3INT))
#define BFX_CTIMER_CTIMERINTSTAT_CTMRA3INT(v)   ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSTAT_CTMRA3INT)) >> (BFP_CTIMER_CTIMERINTSTAT_CTMRA3INT))
#define BFW_CTIMER_CTIMERINTSTAT_CTMRA3INT(v)   (REG_CTIMER_CTIMERINTSTAT.U32 = ( (REG_CTIMER_CTIMERINTSTAT.U32 & ~(BFM_CTIMER_CTIMERINTSTAT_CTMRA3INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSTAT_CTMRA3INT)) & (BFM_CTIMER_CTIMERINTSTAT_CTMRA3INT)) ))
#define BFR_CTIMER_CTIMERINTSTAT_CTMRA3INT()    ((REG_CTIMER_CTIMERINTSTAT.U32 & (BFM_CTIMER_CTIMERINTSTAT_CTMRA3INT))>>(BFP_CTIMER_CTIMERINTSTAT_CTMRA3INT))
#define BFS_CTIMER_CTIMERINTSTAT_CTMRA3INT()    (REG_CTIMER_CTIMERINTSTAT.U32 = (BFM_CTIMER_CTIMERINTSTAT_CTMRA3INT) )

#define BFP_CTIMER_CTIMERINTSTAT_CTMRB2INT      (5)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSTAT_CTMRB2INT      ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSTAT_CTMRB2INT      (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTSTAT_CTMRB2INT      (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSTAT_CTMRB2INT(v)   ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSTAT_CTMRB2INT)) & (BFM_CTIMER_CTIMERINTSTAT_CTMRB2INT))
#define BFX_CTIMER_CTIMERINTSTAT_CTMRB2INT(v)   ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSTAT_CTMRB2INT)) >> (BFP_CTIMER_CTIMERINTSTAT_CTMRB2INT))
#define BFW_CTIMER_CTIMERINTSTAT_CTMRB2INT(v)   (REG_CTIMER_CTIMERINTSTAT.U32 = ( (REG_CTIMER_CTIMERINTSTAT.U32 & ~(BFM_CTIMER_CTIMERINTSTAT_CTMRB2INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSTAT_CTMRB2INT)) & (BFM_CTIMER_CTIMERINTSTAT_CTMRB2INT)) ))
#define BFR_CTIMER_CTIMERINTSTAT_CTMRB2INT()    ((REG_CTIMER_CTIMERINTSTAT.U32 & (BFM_CTIMER_CTIMERINTSTAT_CTMRB2INT))>>(BFP_CTIMER_CTIMERINTSTAT_CTMRB2INT))
#define BFS_CTIMER_CTIMERINTSTAT_CTMRB2INT()    (REG_CTIMER_CTIMERINTSTAT.U32 = (BFM_CTIMER_CTIMERINTSTAT_CTMRB2INT) )

#define BFP_CTIMER_CTIMERINTSTAT_CTMRA2INT      (4)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSTAT_CTMRA2INT      ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSTAT_CTMRA2INT      (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTSTAT_CTMRA2INT      (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSTAT_CTMRA2INT(v)   ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSTAT_CTMRA2INT)) & (BFM_CTIMER_CTIMERINTSTAT_CTMRA2INT))
#define BFX_CTIMER_CTIMERINTSTAT_CTMRA2INT(v)   ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSTAT_CTMRA2INT)) >> (BFP_CTIMER_CTIMERINTSTAT_CTMRA2INT))
#define BFW_CTIMER_CTIMERINTSTAT_CTMRA2INT(v)   (REG_CTIMER_CTIMERINTSTAT.U32 = ( (REG_CTIMER_CTIMERINTSTAT.U32 & ~(BFM_CTIMER_CTIMERINTSTAT_CTMRA2INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSTAT_CTMRA2INT)) & (BFM_CTIMER_CTIMERINTSTAT_CTMRA2INT)) ))
#define BFR_CTIMER_CTIMERINTSTAT_CTMRA2INT()    ((REG_CTIMER_CTIMERINTSTAT.U32 & (BFM_CTIMER_CTIMERINTSTAT_CTMRA2INT))>>(BFP_CTIMER_CTIMERINTSTAT_CTMRA2INT))
#define BFS_CTIMER_CTIMERINTSTAT_CTMRA2INT()    (REG_CTIMER_CTIMERINTSTAT.U32 = (BFM_CTIMER_CTIMERINTSTAT_CTMRA2INT) )

#define BFP_CTIMER_CTIMERINTSTAT_CTMRB1INT      (3)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSTAT_CTMRB1INT      ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSTAT_CTMRB1INT      (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTSTAT_CTMRB1INT      (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSTAT_CTMRB1INT(v)   ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSTAT_CTMRB1INT)) & (BFM_CTIMER_CTIMERINTSTAT_CTMRB1INT))
#define BFX_CTIMER_CTIMERINTSTAT_CTMRB1INT(v)   ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSTAT_CTMRB1INT)) >> (BFP_CTIMER_CTIMERINTSTAT_CTMRB1INT))
#define BFW_CTIMER_CTIMERINTSTAT_CTMRB1INT(v)   (REG_CTIMER_CTIMERINTSTAT.U32 = ( (REG_CTIMER_CTIMERINTSTAT.U32 & ~(BFM_CTIMER_CTIMERINTSTAT_CTMRB1INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSTAT_CTMRB1INT)) & (BFM_CTIMER_CTIMERINTSTAT_CTMRB1INT)) ))
#define BFR_CTIMER_CTIMERINTSTAT_CTMRB1INT()    ((REG_CTIMER_CTIMERINTSTAT.U32 & (BFM_CTIMER_CTIMERINTSTAT_CTMRB1INT))>>(BFP_CTIMER_CTIMERINTSTAT_CTMRB1INT))
#define BFS_CTIMER_CTIMERINTSTAT_CTMRB1INT()    (REG_CTIMER_CTIMERINTSTAT.U32 = (BFM_CTIMER_CTIMERINTSTAT_CTMRB1INT) )

#define BFP_CTIMER_CTIMERINTSTAT_CTMRA1INT      (2)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSTAT_CTMRA1INT      ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSTAT_CTMRA1INT      (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTSTAT_CTMRA1INT      (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSTAT_CTMRA1INT(v)   ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSTAT_CTMRA1INT)) & (BFM_CTIMER_CTIMERINTSTAT_CTMRA1INT))
#define BFX_CTIMER_CTIMERINTSTAT_CTMRA1INT(v)   ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSTAT_CTMRA1INT)) >> (BFP_CTIMER_CTIMERINTSTAT_CTMRA1INT))
#define BFW_CTIMER_CTIMERINTSTAT_CTMRA1INT(v)   (REG_CTIMER_CTIMERINTSTAT.U32 = ( (REG_CTIMER_CTIMERINTSTAT.U32 & ~(BFM_CTIMER_CTIMERINTSTAT_CTMRA1INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSTAT_CTMRA1INT)) & (BFM_CTIMER_CTIMERINTSTAT_CTMRA1INT)) ))
#define BFR_CTIMER_CTIMERINTSTAT_CTMRA1INT()    ((REG_CTIMER_CTIMERINTSTAT.U32 & (BFM_CTIMER_CTIMERINTSTAT_CTMRA1INT))>>(BFP_CTIMER_CTIMERINTSTAT_CTMRA1INT))
#define BFS_CTIMER_CTIMERINTSTAT_CTMRA1INT()    (REG_CTIMER_CTIMERINTSTAT.U32 = (BFM_CTIMER_CTIMERINTSTAT_CTMRA1INT) )

#define BFP_CTIMER_CTIMERINTSTAT_CTMRB0INT      (1)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSTAT_CTMRB0INT      ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSTAT_CTMRB0INT      (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTSTAT_CTMRB0INT      (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSTAT_CTMRB0INT(v)   ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSTAT_CTMRB0INT)) & (BFM_CTIMER_CTIMERINTSTAT_CTMRB0INT))
#define BFX_CTIMER_CTIMERINTSTAT_CTMRB0INT(v)   ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSTAT_CTMRB0INT)) >> (BFP_CTIMER_CTIMERINTSTAT_CTMRB0INT))
#define BFW_CTIMER_CTIMERINTSTAT_CTMRB0INT(v)   (REG_CTIMER_CTIMERINTSTAT.U32 = ( (REG_CTIMER_CTIMERINTSTAT.U32 & ~(BFM_CTIMER_CTIMERINTSTAT_CTMRB0INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSTAT_CTMRB0INT)) & (BFM_CTIMER_CTIMERINTSTAT_CTMRB0INT)) ))
#define BFR_CTIMER_CTIMERINTSTAT_CTMRB0INT()    ((REG_CTIMER_CTIMERINTSTAT.U32 & (BFM_CTIMER_CTIMERINTSTAT_CTMRB0INT))>>(BFP_CTIMER_CTIMERINTSTAT_CTMRB0INT))
#define BFS_CTIMER_CTIMERINTSTAT_CTMRB0INT()    (REG_CTIMER_CTIMERINTSTAT.U32 = (BFM_CTIMER_CTIMERINTSTAT_CTMRB0INT) )

#define BFP_CTIMER_CTIMERINTSTAT_CTMRA0INT      (0)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSTAT_CTMRA0INT      ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSTAT_CTMRA0INT      (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTSTAT_CTMRA0INT      (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSTAT_CTMRA0INT(v)   ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSTAT_CTMRA0INT)) & (BFM_CTIMER_CTIMERINTSTAT_CTMRA0INT))
#define BFX_CTIMER_CTIMERINTSTAT_CTMRA0INT(v)   ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSTAT_CTMRA0INT)) >> (BFP_CTIMER_CTIMERINTSTAT_CTMRA0INT))
#define BFW_CTIMER_CTIMERINTSTAT_CTMRA0INT(v)   (REG_CTIMER_CTIMERINTSTAT.U32 = ( (REG_CTIMER_CTIMERINTSTAT.U32 & ~(BFM_CTIMER_CTIMERINTSTAT_CTMRA0INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSTAT_CTMRA0INT)) & (BFM_CTIMER_CTIMERINTSTAT_CTMRA0INT)) ))
#define BFR_CTIMER_CTIMERINTSTAT_CTMRA0INT()    ((REG_CTIMER_CTIMERINTSTAT.U32 & (BFM_CTIMER_CTIMERINTSTAT_CTMRA0INT))>>(BFP_CTIMER_CTIMERINTSTAT_CTMRA0INT))
#define BFS_CTIMER_CTIMERINTSTAT_CTMRA0INT()    (REG_CTIMER_CTIMERINTSTAT.U32 = (BFM_CTIMER_CTIMERINTSTAT_CTMRA0INT) )


// *****************************************************************************
//                                                                             *
//  CTIMER_CTIMERINTCLR - Counter/Timer Interrupts                             *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned CTMRB3INT                  :  1;
        unsigned CTMRA3INT                  :  1;
        unsigned CTMRB2INT                  :  1;
        unsigned CTMRA2INT                  :  1;
        unsigned CTMRB1INT                  :  1;
        unsigned CTMRA1INT                  :  1;
        unsigned CTMRB0INT                  :  1;
        unsigned CTMRA0INT                  :  1;
    } B;
} reg_ctimer_ctimerintclr_t;

#define REG_CTIMER_CTIMERINTCLR_ADDR            (REG_CTIMER_BASEADDR + 0x00000208UL)
#define REG_CTIMER_CTIMERINTCLR                 (*(volatile reg_ctimer_ctimerintclr_t *) REG_CTIMER_CTIMERINTCLR_ADDR)
#define REG_CTIMER_CTIMERINTCLR_RD()            (REG_CTIMER_CTIMERINTCLR.U32)
#define REG_CTIMER_CTIMERINTCLR_WR(v)           (REG_CTIMER_CTIMERINTCLR.U32 = (v))
#define REG_CTIMER_CTIMERINTCLR_CLR(m)          (REG_CTIMER_CTIMERINTCLR.U32 = ((REG_CTIMER_CTIMERINTCLR.U32) & ~(m)))
#define REG_CTIMER_CTIMERINTCLR_SET(m)          (REG_CTIMER_CTIMERINTCLR.U32 = ((REG_CTIMER_CTIMERINTCLR.U32) | (m)))
#define REG_CTIMER_CTIMERINTCLR_DEF             0x00000000

#define BFP_CTIMER_CTIMERINTCLR_RSVD_8          (8)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTCLR_RSVD_8          ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTCLR_RSVD_8          (24)                    /* bitfield width */
#define BFD_CTIMER_CTIMERINTCLR_RSVD_8          (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTCLR_RSVD_8(v)       ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTCLR_RSVD_8)) & (BFM_CTIMER_CTIMERINTCLR_RSVD_8))
#define BFX_CTIMER_CTIMERINTCLR_RSVD_8(v)       ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTCLR_RSVD_8)) >> (BFP_CTIMER_CTIMERINTCLR_RSVD_8))
#define BFW_CTIMER_CTIMERINTCLR_RSVD_8(v)       (REG_CTIMER_CTIMERINTCLR.U32 = ( (REG_CTIMER_CTIMERINTCLR.U32 & ~(BFM_CTIMER_CTIMERINTCLR_RSVD_8)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTCLR_RSVD_8)) & (BFM_CTIMER_CTIMERINTCLR_RSVD_8)) ))
#define BFR_CTIMER_CTIMERINTCLR_RSVD_8()        ((REG_CTIMER_CTIMERINTCLR.U32 & (BFM_CTIMER_CTIMERINTCLR_RSVD_8))>>(BFP_CTIMER_CTIMERINTCLR_RSVD_8))
#define BFS_CTIMER_CTIMERINTCLR_RSVD_8()        (REG_CTIMER_CTIMERINTCLR.U32 = (BFM_CTIMER_CTIMERINTCLR_RSVD_8) )

#define BFP_CTIMER_CTIMERINTCLR_CTMRB3INT       (7)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTCLR_CTMRB3INT       ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTCLR_CTMRB3INT       (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTCLR_CTMRB3INT       (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTCLR_CTMRB3INT(v)    ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTCLR_CTMRB3INT)) & (BFM_CTIMER_CTIMERINTCLR_CTMRB3INT))
#define BFX_CTIMER_CTIMERINTCLR_CTMRB3INT(v)    ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTCLR_CTMRB3INT)) >> (BFP_CTIMER_CTIMERINTCLR_CTMRB3INT))
#define BFW_CTIMER_CTIMERINTCLR_CTMRB3INT(v)    (REG_CTIMER_CTIMERINTCLR.U32 = ( (REG_CTIMER_CTIMERINTCLR.U32 & ~(BFM_CTIMER_CTIMERINTCLR_CTMRB3INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTCLR_CTMRB3INT)) & (BFM_CTIMER_CTIMERINTCLR_CTMRB3INT)) ))
#define BFR_CTIMER_CTIMERINTCLR_CTMRB3INT()     ((REG_CTIMER_CTIMERINTCLR.U32 & (BFM_CTIMER_CTIMERINTCLR_CTMRB3INT))>>(BFP_CTIMER_CTIMERINTCLR_CTMRB3INT))
#define BFS_CTIMER_CTIMERINTCLR_CTMRB3INT()     (REG_CTIMER_CTIMERINTCLR.U32 = (BFM_CTIMER_CTIMERINTCLR_CTMRB3INT) )

#define BFP_CTIMER_CTIMERINTCLR_CTMRA3INT       (6)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTCLR_CTMRA3INT       ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTCLR_CTMRA3INT       (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTCLR_CTMRA3INT       (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTCLR_CTMRA3INT(v)    ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTCLR_CTMRA3INT)) & (BFM_CTIMER_CTIMERINTCLR_CTMRA3INT))
#define BFX_CTIMER_CTIMERINTCLR_CTMRA3INT(v)    ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTCLR_CTMRA3INT)) >> (BFP_CTIMER_CTIMERINTCLR_CTMRA3INT))
#define BFW_CTIMER_CTIMERINTCLR_CTMRA3INT(v)    (REG_CTIMER_CTIMERINTCLR.U32 = ( (REG_CTIMER_CTIMERINTCLR.U32 & ~(BFM_CTIMER_CTIMERINTCLR_CTMRA3INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTCLR_CTMRA3INT)) & (BFM_CTIMER_CTIMERINTCLR_CTMRA3INT)) ))
#define BFR_CTIMER_CTIMERINTCLR_CTMRA3INT()     ((REG_CTIMER_CTIMERINTCLR.U32 & (BFM_CTIMER_CTIMERINTCLR_CTMRA3INT))>>(BFP_CTIMER_CTIMERINTCLR_CTMRA3INT))
#define BFS_CTIMER_CTIMERINTCLR_CTMRA3INT()     (REG_CTIMER_CTIMERINTCLR.U32 = (BFM_CTIMER_CTIMERINTCLR_CTMRA3INT) )

#define BFP_CTIMER_CTIMERINTCLR_CTMRB2INT       (5)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTCLR_CTMRB2INT       ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTCLR_CTMRB2INT       (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTCLR_CTMRB2INT       (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTCLR_CTMRB2INT(v)    ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTCLR_CTMRB2INT)) & (BFM_CTIMER_CTIMERINTCLR_CTMRB2INT))
#define BFX_CTIMER_CTIMERINTCLR_CTMRB2INT(v)    ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTCLR_CTMRB2INT)) >> (BFP_CTIMER_CTIMERINTCLR_CTMRB2INT))
#define BFW_CTIMER_CTIMERINTCLR_CTMRB2INT(v)    (REG_CTIMER_CTIMERINTCLR.U32 = ( (REG_CTIMER_CTIMERINTCLR.U32 & ~(BFM_CTIMER_CTIMERINTCLR_CTMRB2INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTCLR_CTMRB2INT)) & (BFM_CTIMER_CTIMERINTCLR_CTMRB2INT)) ))
#define BFR_CTIMER_CTIMERINTCLR_CTMRB2INT()     ((REG_CTIMER_CTIMERINTCLR.U32 & (BFM_CTIMER_CTIMERINTCLR_CTMRB2INT))>>(BFP_CTIMER_CTIMERINTCLR_CTMRB2INT))
#define BFS_CTIMER_CTIMERINTCLR_CTMRB2INT()     (REG_CTIMER_CTIMERINTCLR.U32 = (BFM_CTIMER_CTIMERINTCLR_CTMRB2INT) )

#define BFP_CTIMER_CTIMERINTCLR_CTMRA2INT       (4)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTCLR_CTMRA2INT       ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTCLR_CTMRA2INT       (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTCLR_CTMRA2INT       (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTCLR_CTMRA2INT(v)    ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTCLR_CTMRA2INT)) & (BFM_CTIMER_CTIMERINTCLR_CTMRA2INT))
#define BFX_CTIMER_CTIMERINTCLR_CTMRA2INT(v)    ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTCLR_CTMRA2INT)) >> (BFP_CTIMER_CTIMERINTCLR_CTMRA2INT))
#define BFW_CTIMER_CTIMERINTCLR_CTMRA2INT(v)    (REG_CTIMER_CTIMERINTCLR.U32 = ( (REG_CTIMER_CTIMERINTCLR.U32 & ~(BFM_CTIMER_CTIMERINTCLR_CTMRA2INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTCLR_CTMRA2INT)) & (BFM_CTIMER_CTIMERINTCLR_CTMRA2INT)) ))
#define BFR_CTIMER_CTIMERINTCLR_CTMRA2INT()     ((REG_CTIMER_CTIMERINTCLR.U32 & (BFM_CTIMER_CTIMERINTCLR_CTMRA2INT))>>(BFP_CTIMER_CTIMERINTCLR_CTMRA2INT))
#define BFS_CTIMER_CTIMERINTCLR_CTMRA2INT()     (REG_CTIMER_CTIMERINTCLR.U32 = (BFM_CTIMER_CTIMERINTCLR_CTMRA2INT) )

#define BFP_CTIMER_CTIMERINTCLR_CTMRB1INT       (3)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTCLR_CTMRB1INT       ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTCLR_CTMRB1INT       (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTCLR_CTMRB1INT       (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTCLR_CTMRB1INT(v)    ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTCLR_CTMRB1INT)) & (BFM_CTIMER_CTIMERINTCLR_CTMRB1INT))
#define BFX_CTIMER_CTIMERINTCLR_CTMRB1INT(v)    ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTCLR_CTMRB1INT)) >> (BFP_CTIMER_CTIMERINTCLR_CTMRB1INT))
#define BFW_CTIMER_CTIMERINTCLR_CTMRB1INT(v)    (REG_CTIMER_CTIMERINTCLR.U32 = ( (REG_CTIMER_CTIMERINTCLR.U32 & ~(BFM_CTIMER_CTIMERINTCLR_CTMRB1INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTCLR_CTMRB1INT)) & (BFM_CTIMER_CTIMERINTCLR_CTMRB1INT)) ))
#define BFR_CTIMER_CTIMERINTCLR_CTMRB1INT()     ((REG_CTIMER_CTIMERINTCLR.U32 & (BFM_CTIMER_CTIMERINTCLR_CTMRB1INT))>>(BFP_CTIMER_CTIMERINTCLR_CTMRB1INT))
#define BFS_CTIMER_CTIMERINTCLR_CTMRB1INT()     (REG_CTIMER_CTIMERINTCLR.U32 = (BFM_CTIMER_CTIMERINTCLR_CTMRB1INT) )

#define BFP_CTIMER_CTIMERINTCLR_CTMRA1INT       (2)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTCLR_CTMRA1INT       ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTCLR_CTMRA1INT       (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTCLR_CTMRA1INT       (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTCLR_CTMRA1INT(v)    ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTCLR_CTMRA1INT)) & (BFM_CTIMER_CTIMERINTCLR_CTMRA1INT))
#define BFX_CTIMER_CTIMERINTCLR_CTMRA1INT(v)    ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTCLR_CTMRA1INT)) >> (BFP_CTIMER_CTIMERINTCLR_CTMRA1INT))
#define BFW_CTIMER_CTIMERINTCLR_CTMRA1INT(v)    (REG_CTIMER_CTIMERINTCLR.U32 = ( (REG_CTIMER_CTIMERINTCLR.U32 & ~(BFM_CTIMER_CTIMERINTCLR_CTMRA1INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTCLR_CTMRA1INT)) & (BFM_CTIMER_CTIMERINTCLR_CTMRA1INT)) ))
#define BFR_CTIMER_CTIMERINTCLR_CTMRA1INT()     ((REG_CTIMER_CTIMERINTCLR.U32 & (BFM_CTIMER_CTIMERINTCLR_CTMRA1INT))>>(BFP_CTIMER_CTIMERINTCLR_CTMRA1INT))
#define BFS_CTIMER_CTIMERINTCLR_CTMRA1INT()     (REG_CTIMER_CTIMERINTCLR.U32 = (BFM_CTIMER_CTIMERINTCLR_CTMRA1INT) )

#define BFP_CTIMER_CTIMERINTCLR_CTMRB0INT       (1)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTCLR_CTMRB0INT       ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTCLR_CTMRB0INT       (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTCLR_CTMRB0INT       (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTCLR_CTMRB0INT(v)    ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTCLR_CTMRB0INT)) & (BFM_CTIMER_CTIMERINTCLR_CTMRB0INT))
#define BFX_CTIMER_CTIMERINTCLR_CTMRB0INT(v)    ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTCLR_CTMRB0INT)) >> (BFP_CTIMER_CTIMERINTCLR_CTMRB0INT))
#define BFW_CTIMER_CTIMERINTCLR_CTMRB0INT(v)    (REG_CTIMER_CTIMERINTCLR.U32 = ( (REG_CTIMER_CTIMERINTCLR.U32 & ~(BFM_CTIMER_CTIMERINTCLR_CTMRB0INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTCLR_CTMRB0INT)) & (BFM_CTIMER_CTIMERINTCLR_CTMRB0INT)) ))
#define BFR_CTIMER_CTIMERINTCLR_CTMRB0INT()     ((REG_CTIMER_CTIMERINTCLR.U32 & (BFM_CTIMER_CTIMERINTCLR_CTMRB0INT))>>(BFP_CTIMER_CTIMERINTCLR_CTMRB0INT))
#define BFS_CTIMER_CTIMERINTCLR_CTMRB0INT()     (REG_CTIMER_CTIMERINTCLR.U32 = (BFM_CTIMER_CTIMERINTCLR_CTMRB0INT) )

#define BFP_CTIMER_CTIMERINTCLR_CTMRA0INT       (0)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTCLR_CTMRA0INT       ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTCLR_CTMRA0INT       (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTCLR_CTMRA0INT       (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTCLR_CTMRA0INT(v)    ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTCLR_CTMRA0INT)) & (BFM_CTIMER_CTIMERINTCLR_CTMRA0INT))
#define BFX_CTIMER_CTIMERINTCLR_CTMRA0INT(v)    ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTCLR_CTMRA0INT)) >> (BFP_CTIMER_CTIMERINTCLR_CTMRA0INT))
#define BFW_CTIMER_CTIMERINTCLR_CTMRA0INT(v)    (REG_CTIMER_CTIMERINTCLR.U32 = ( (REG_CTIMER_CTIMERINTCLR.U32 & ~(BFM_CTIMER_CTIMERINTCLR_CTMRA0INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTCLR_CTMRA0INT)) & (BFM_CTIMER_CTIMERINTCLR_CTMRA0INT)) ))
#define BFR_CTIMER_CTIMERINTCLR_CTMRA0INT()     ((REG_CTIMER_CTIMERINTCLR.U32 & (BFM_CTIMER_CTIMERINTCLR_CTMRA0INT))>>(BFP_CTIMER_CTIMERINTCLR_CTMRA0INT))
#define BFS_CTIMER_CTIMERINTCLR_CTMRA0INT()     (REG_CTIMER_CTIMERINTCLR.U32 = (BFM_CTIMER_CTIMERINTCLR_CTMRA0INT) )


// *****************************************************************************
//                                                                             *
//  CTIMER_CTIMERINTSET - Counter/Timer Interrupts                             *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned CTMRB3INT                  :  1;
        unsigned CTMRA3INT                  :  1;
        unsigned CTMRB2INT                  :  1;
        unsigned CTMRA2INT                  :  1;
        unsigned CTMRB1INT                  :  1;
        unsigned CTMRA1INT                  :  1;
        unsigned CTMRB0INT                  :  1;
        unsigned CTMRA0INT                  :  1;
    } B;
} reg_ctimer_ctimerintset_t;

#define REG_CTIMER_CTIMERINTSET_ADDR            (REG_CTIMER_BASEADDR + 0x0000020CUL)
#define REG_CTIMER_CTIMERINTSET                 (*(volatile reg_ctimer_ctimerintset_t *) REG_CTIMER_CTIMERINTSET_ADDR)
#define REG_CTIMER_CTIMERINTSET_RD()            (REG_CTIMER_CTIMERINTSET.U32)
#define REG_CTIMER_CTIMERINTSET_WR(v)           (REG_CTIMER_CTIMERINTSET.U32 = (v))
#define REG_CTIMER_CTIMERINTSET_CLR(m)          (REG_CTIMER_CTIMERINTSET.U32 = ((REG_CTIMER_CTIMERINTSET.U32) & ~(m)))
#define REG_CTIMER_CTIMERINTSET_SET(m)          (REG_CTIMER_CTIMERINTSET.U32 = ((REG_CTIMER_CTIMERINTSET.U32) | (m)))
#define REG_CTIMER_CTIMERINTSET_DEF             0x00000000

#define BFP_CTIMER_CTIMERINTSET_RSVD_8          (8)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSET_RSVD_8          ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSET_RSVD_8          (24)                    /* bitfield width */
#define BFD_CTIMER_CTIMERINTSET_RSVD_8          (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSET_RSVD_8(v)       ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSET_RSVD_8)) & (BFM_CTIMER_CTIMERINTSET_RSVD_8))
#define BFX_CTIMER_CTIMERINTSET_RSVD_8(v)       ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSET_RSVD_8)) >> (BFP_CTIMER_CTIMERINTSET_RSVD_8))
#define BFW_CTIMER_CTIMERINTSET_RSVD_8(v)       (REG_CTIMER_CTIMERINTSET.U32 = ( (REG_CTIMER_CTIMERINTSET.U32 & ~(BFM_CTIMER_CTIMERINTSET_RSVD_8)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSET_RSVD_8)) & (BFM_CTIMER_CTIMERINTSET_RSVD_8)) ))
#define BFR_CTIMER_CTIMERINTSET_RSVD_8()        ((REG_CTIMER_CTIMERINTSET.U32 & (BFM_CTIMER_CTIMERINTSET_RSVD_8))>>(BFP_CTIMER_CTIMERINTSET_RSVD_8))
#define BFS_CTIMER_CTIMERINTSET_RSVD_8()        (REG_CTIMER_CTIMERINTSET.U32 = (BFM_CTIMER_CTIMERINTSET_RSVD_8) )

#define BFP_CTIMER_CTIMERINTSET_CTMRB3INT       (7)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSET_CTMRB3INT       ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSET_CTMRB3INT       (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTSET_CTMRB3INT       (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSET_CTMRB3INT(v)    ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSET_CTMRB3INT)) & (BFM_CTIMER_CTIMERINTSET_CTMRB3INT))
#define BFX_CTIMER_CTIMERINTSET_CTMRB3INT(v)    ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSET_CTMRB3INT)) >> (BFP_CTIMER_CTIMERINTSET_CTMRB3INT))
#define BFW_CTIMER_CTIMERINTSET_CTMRB3INT(v)    (REG_CTIMER_CTIMERINTSET.U32 = ( (REG_CTIMER_CTIMERINTSET.U32 & ~(BFM_CTIMER_CTIMERINTSET_CTMRB3INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSET_CTMRB3INT)) & (BFM_CTIMER_CTIMERINTSET_CTMRB3INT)) ))
#define BFR_CTIMER_CTIMERINTSET_CTMRB3INT()     ((REG_CTIMER_CTIMERINTSET.U32 & (BFM_CTIMER_CTIMERINTSET_CTMRB3INT))>>(BFP_CTIMER_CTIMERINTSET_CTMRB3INT))
#define BFS_CTIMER_CTIMERINTSET_CTMRB3INT()     (REG_CTIMER_CTIMERINTSET.U32 = (BFM_CTIMER_CTIMERINTSET_CTMRB3INT) )

#define BFP_CTIMER_CTIMERINTSET_CTMRA3INT       (6)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSET_CTMRA3INT       ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSET_CTMRA3INT       (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTSET_CTMRA3INT       (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSET_CTMRA3INT(v)    ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSET_CTMRA3INT)) & (BFM_CTIMER_CTIMERINTSET_CTMRA3INT))
#define BFX_CTIMER_CTIMERINTSET_CTMRA3INT(v)    ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSET_CTMRA3INT)) >> (BFP_CTIMER_CTIMERINTSET_CTMRA3INT))
#define BFW_CTIMER_CTIMERINTSET_CTMRA3INT(v)    (REG_CTIMER_CTIMERINTSET.U32 = ( (REG_CTIMER_CTIMERINTSET.U32 & ~(BFM_CTIMER_CTIMERINTSET_CTMRA3INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSET_CTMRA3INT)) & (BFM_CTIMER_CTIMERINTSET_CTMRA3INT)) ))
#define BFR_CTIMER_CTIMERINTSET_CTMRA3INT()     ((REG_CTIMER_CTIMERINTSET.U32 & (BFM_CTIMER_CTIMERINTSET_CTMRA3INT))>>(BFP_CTIMER_CTIMERINTSET_CTMRA3INT))
#define BFS_CTIMER_CTIMERINTSET_CTMRA3INT()     (REG_CTIMER_CTIMERINTSET.U32 = (BFM_CTIMER_CTIMERINTSET_CTMRA3INT) )

#define BFP_CTIMER_CTIMERINTSET_CTMRB2INT       (5)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSET_CTMRB2INT       ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSET_CTMRB2INT       (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTSET_CTMRB2INT       (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSET_CTMRB2INT(v)    ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSET_CTMRB2INT)) & (BFM_CTIMER_CTIMERINTSET_CTMRB2INT))
#define BFX_CTIMER_CTIMERINTSET_CTMRB2INT(v)    ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSET_CTMRB2INT)) >> (BFP_CTIMER_CTIMERINTSET_CTMRB2INT))
#define BFW_CTIMER_CTIMERINTSET_CTMRB2INT(v)    (REG_CTIMER_CTIMERINTSET.U32 = ( (REG_CTIMER_CTIMERINTSET.U32 & ~(BFM_CTIMER_CTIMERINTSET_CTMRB2INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSET_CTMRB2INT)) & (BFM_CTIMER_CTIMERINTSET_CTMRB2INT)) ))
#define BFR_CTIMER_CTIMERINTSET_CTMRB2INT()     ((REG_CTIMER_CTIMERINTSET.U32 & (BFM_CTIMER_CTIMERINTSET_CTMRB2INT))>>(BFP_CTIMER_CTIMERINTSET_CTMRB2INT))
#define BFS_CTIMER_CTIMERINTSET_CTMRB2INT()     (REG_CTIMER_CTIMERINTSET.U32 = (BFM_CTIMER_CTIMERINTSET_CTMRB2INT) )

#define BFP_CTIMER_CTIMERINTSET_CTMRA2INT       (4)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSET_CTMRA2INT       ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSET_CTMRA2INT       (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTSET_CTMRA2INT       (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSET_CTMRA2INT(v)    ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSET_CTMRA2INT)) & (BFM_CTIMER_CTIMERINTSET_CTMRA2INT))
#define BFX_CTIMER_CTIMERINTSET_CTMRA2INT(v)    ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSET_CTMRA2INT)) >> (BFP_CTIMER_CTIMERINTSET_CTMRA2INT))
#define BFW_CTIMER_CTIMERINTSET_CTMRA2INT(v)    (REG_CTIMER_CTIMERINTSET.U32 = ( (REG_CTIMER_CTIMERINTSET.U32 & ~(BFM_CTIMER_CTIMERINTSET_CTMRA2INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSET_CTMRA2INT)) & (BFM_CTIMER_CTIMERINTSET_CTMRA2INT)) ))
#define BFR_CTIMER_CTIMERINTSET_CTMRA2INT()     ((REG_CTIMER_CTIMERINTSET.U32 & (BFM_CTIMER_CTIMERINTSET_CTMRA2INT))>>(BFP_CTIMER_CTIMERINTSET_CTMRA2INT))
#define BFS_CTIMER_CTIMERINTSET_CTMRA2INT()     (REG_CTIMER_CTIMERINTSET.U32 = (BFM_CTIMER_CTIMERINTSET_CTMRA2INT) )

#define BFP_CTIMER_CTIMERINTSET_CTMRB1INT       (3)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSET_CTMRB1INT       ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSET_CTMRB1INT       (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTSET_CTMRB1INT       (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSET_CTMRB1INT(v)    ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSET_CTMRB1INT)) & (BFM_CTIMER_CTIMERINTSET_CTMRB1INT))
#define BFX_CTIMER_CTIMERINTSET_CTMRB1INT(v)    ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSET_CTMRB1INT)) >> (BFP_CTIMER_CTIMERINTSET_CTMRB1INT))
#define BFW_CTIMER_CTIMERINTSET_CTMRB1INT(v)    (REG_CTIMER_CTIMERINTSET.U32 = ( (REG_CTIMER_CTIMERINTSET.U32 & ~(BFM_CTIMER_CTIMERINTSET_CTMRB1INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSET_CTMRB1INT)) & (BFM_CTIMER_CTIMERINTSET_CTMRB1INT)) ))
#define BFR_CTIMER_CTIMERINTSET_CTMRB1INT()     ((REG_CTIMER_CTIMERINTSET.U32 & (BFM_CTIMER_CTIMERINTSET_CTMRB1INT))>>(BFP_CTIMER_CTIMERINTSET_CTMRB1INT))
#define BFS_CTIMER_CTIMERINTSET_CTMRB1INT()     (REG_CTIMER_CTIMERINTSET.U32 = (BFM_CTIMER_CTIMERINTSET_CTMRB1INT) )

#define BFP_CTIMER_CTIMERINTSET_CTMRA1INT       (2)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSET_CTMRA1INT       ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSET_CTMRA1INT       (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTSET_CTMRA1INT       (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSET_CTMRA1INT(v)    ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSET_CTMRA1INT)) & (BFM_CTIMER_CTIMERINTSET_CTMRA1INT))
#define BFX_CTIMER_CTIMERINTSET_CTMRA1INT(v)    ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSET_CTMRA1INT)) >> (BFP_CTIMER_CTIMERINTSET_CTMRA1INT))
#define BFW_CTIMER_CTIMERINTSET_CTMRA1INT(v)    (REG_CTIMER_CTIMERINTSET.U32 = ( (REG_CTIMER_CTIMERINTSET.U32 & ~(BFM_CTIMER_CTIMERINTSET_CTMRA1INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSET_CTMRA1INT)) & (BFM_CTIMER_CTIMERINTSET_CTMRA1INT)) ))
#define BFR_CTIMER_CTIMERINTSET_CTMRA1INT()     ((REG_CTIMER_CTIMERINTSET.U32 & (BFM_CTIMER_CTIMERINTSET_CTMRA1INT))>>(BFP_CTIMER_CTIMERINTSET_CTMRA1INT))
#define BFS_CTIMER_CTIMERINTSET_CTMRA1INT()     (REG_CTIMER_CTIMERINTSET.U32 = (BFM_CTIMER_CTIMERINTSET_CTMRA1INT) )

#define BFP_CTIMER_CTIMERINTSET_CTMRB0INT       (1)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSET_CTMRB0INT       ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSET_CTMRB0INT       (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTSET_CTMRB0INT       (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSET_CTMRB0INT(v)    ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSET_CTMRB0INT)) & (BFM_CTIMER_CTIMERINTSET_CTMRB0INT))
#define BFX_CTIMER_CTIMERINTSET_CTMRB0INT(v)    ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSET_CTMRB0INT)) >> (BFP_CTIMER_CTIMERINTSET_CTMRB0INT))
#define BFW_CTIMER_CTIMERINTSET_CTMRB0INT(v)    (REG_CTIMER_CTIMERINTSET.U32 = ( (REG_CTIMER_CTIMERINTSET.U32 & ~(BFM_CTIMER_CTIMERINTSET_CTMRB0INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSET_CTMRB0INT)) & (BFM_CTIMER_CTIMERINTSET_CTMRB0INT)) ))
#define BFR_CTIMER_CTIMERINTSET_CTMRB0INT()     ((REG_CTIMER_CTIMERINTSET.U32 & (BFM_CTIMER_CTIMERINTSET_CTMRB0INT))>>(BFP_CTIMER_CTIMERINTSET_CTMRB0INT))
#define BFS_CTIMER_CTIMERINTSET_CTMRB0INT()     (REG_CTIMER_CTIMERINTSET.U32 = (BFM_CTIMER_CTIMERINTSET_CTMRB0INT) )

#define BFP_CTIMER_CTIMERINTSET_CTMRA0INT       (0)                     /* bitfield lsb */
#define BFM_CTIMER_CTIMERINTSET_CTMRA0INT       ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CTIMER_CTIMERINTSET_CTMRA0INT       (1)                     /* bitfield width */
#define BFD_CTIMER_CTIMERINTSET_CTMRA0INT       (0x0)                   /* bitfield default value */
#define BFV_CTIMER_CTIMERINTSET_CTMRA0INT(v)    ((((uint32_t) v) << (BFP_CTIMER_CTIMERINTSET_CTMRA0INT)) & (BFM_CTIMER_CTIMERINTSET_CTMRA0INT))
#define BFX_CTIMER_CTIMERINTSET_CTMRA0INT(v)    ((((uint32_t) v) & (BFM_CTIMER_CTIMERINTSET_CTMRA0INT)) >> (BFP_CTIMER_CTIMERINTSET_CTMRA0INT))
#define BFW_CTIMER_CTIMERINTSET_CTMRA0INT(v)    (REG_CTIMER_CTIMERINTSET.U32 = ( (REG_CTIMER_CTIMERINTSET.U32 & ~(BFM_CTIMER_CTIMERINTSET_CTMRA0INT)) | ((((uint32_t) v)<<(BFP_CTIMER_CTIMERINTSET_CTMRA0INT)) & (BFM_CTIMER_CTIMERINTSET_CTMRA0INT)) ))
#define BFR_CTIMER_CTIMERINTSET_CTMRA0INT()     ((REG_CTIMER_CTIMERINTSET.U32 & (BFM_CTIMER_CTIMERINTSET_CTMRA0INT))>>(BFP_CTIMER_CTIMERINTSET_CTMRA0INT))
#define BFS_CTIMER_CTIMERINTSET_CTMRA0INT()     (REG_CTIMER_CTIMERINTSET.U32 = (BFM_CTIMER_CTIMERINTSET_CTMRA0INT) )

#define REG_CTIMER_LASTREG_ADDR                 (REG_CTIMER_CTIMERINTSET_ADDR)




#endif  // _CTIMER_H

