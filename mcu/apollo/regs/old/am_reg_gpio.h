/*******************************************************************************
*                                                                              *
*   Copyright (c) 2013-2014 Ambiq Micro                                        *
*                                                                              *
********************************************************************************
*                                                                              *
*   File:       gpio_regs.h                                                    *
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


#ifndef __GPIO_H
#define __GPIO_H

#include "../am_mcu_apollo.h"


// *****************************************************************************
//                                                                             *
//  GPIO_PADREGA - Pad Configuration Register A                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned PAD3PWRUP                  :  1;
        unsigned PAD3PWRDN                  :  1;
        unsigned PAD3FNCSEL                 :  3;
        unsigned PAD3STRNG                  :  1;
        unsigned PAD3INPEN                  :  1;
        unsigned PAD3PULL                   :  1;
        unsigned RSVD_22                    :  2;
        unsigned PAD2FNCSEL                 :  3;
        unsigned PAD2STRNG                  :  1;
        unsigned PAD2INPEN                  :  1;
        unsigned PAD2PULL                   :  1;
        unsigned RSVD_14                    :  2;
        unsigned PAD1FNCSEL                 :  3;
        unsigned PAD1STRNG                  :  1;
        unsigned PAD1INPEN                  :  1;
        unsigned PAD1PULL                   :  1;
        unsigned RSVD_6                     :  2;
        unsigned PAD0FNCSEL                 :  3;
        unsigned PAD0STRNG                  :  1;
        unsigned PAD0INPEN                  :  1;
        unsigned PAD0PULL                   :  1;
    } B;
} reg_gpio_padrega_t;

#define REG_GPIO_PADREGA_ADDR                   (REG_GPIO_BASEADDR + 0x00000000UL)
#define REG_GPIO_PADREGA                        (*(volatile reg_gpio_padrega_t *) REG_GPIO_PADREGA_ADDR)
#define REG_GPIO_PADREGA_RD()                   (REG_GPIO_PADREGA.U32)
#define REG_GPIO_PADREGA_WR(v)                  (REG_GPIO_PADREGA.U32 = (v))
#define REG_GPIO_PADREGA_CLR(m)                 (REG_GPIO_PADREGA.U32 = ((REG_GPIO_PADREGA.U32) & ~(m)))
#define REG_GPIO_PADREGA_SET(m)                 (REG_GPIO_PADREGA.U32 = ((REG_GPIO_PADREGA.U32) | (m)))
#define REG_GPIO_PADREGA_DEF                    0x18181818

#define BFP_GPIO_PADREGA_PAD3PWRUP              (31)                    /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD3PWRUP              ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD3PWRUP              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD3PWRUP              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD3PWRUP(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD3PWRUP)) & (BFM_GPIO_PADREGA_PAD3PWRUP))
#define BFX_GPIO_PADREGA_PAD3PWRUP(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD3PWRUP)) >> (BFP_GPIO_PADREGA_PAD3PWRUP))
#define BFW_GPIO_PADREGA_PAD3PWRUP(v)           (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD3PWRUP)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD3PWRUP)) & (BFM_GPIO_PADREGA_PAD3PWRUP)) ))
#define BFR_GPIO_PADREGA_PAD3PWRUP()            ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD3PWRUP))>>(BFP_GPIO_PADREGA_PAD3PWRUP))

#define BFP_GPIO_PADREGA_PAD3PWRDN              (30)                    /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD3PWRDN              ((uint32_t)0x40000000)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD3PWRDN              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD3PWRDN              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD3PWRDN(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD3PWRDN)) & (BFM_GPIO_PADREGA_PAD3PWRDN))
#define BFX_GPIO_PADREGA_PAD3PWRDN(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD3PWRDN)) >> (BFP_GPIO_PADREGA_PAD3PWRDN))
#define BFW_GPIO_PADREGA_PAD3PWRDN(v)           (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD3PWRDN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD3PWRDN)) & (BFM_GPIO_PADREGA_PAD3PWRDN)) ))
#define BFR_GPIO_PADREGA_PAD3PWRDN()            ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD3PWRDN))>>(BFP_GPIO_PADREGA_PAD3PWRDN))

#define BFP_GPIO_PADREGA_PAD3FNCSEL             (27)                    /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD3FNCSEL             ((uint32_t)0x38000000)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD3FNCSEL             (3)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD3FNCSEL             (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD3FNCSEL(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD3FNCSEL)) & (BFM_GPIO_PADREGA_PAD3FNCSEL))
#define BFX_GPIO_PADREGA_PAD3FNCSEL(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD3FNCSEL)) >> (BFP_GPIO_PADREGA_PAD3FNCSEL))
#define BFW_GPIO_PADREGA_PAD3FNCSEL(v)          (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD3FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD3FNCSEL)) & (BFM_GPIO_PADREGA_PAD3FNCSEL)) ))
#define BFR_GPIO_PADREGA_PAD3FNCSEL()           ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD3FNCSEL))>>(BFP_GPIO_PADREGA_PAD3FNCSEL))

#define BFP_GPIO_PADREGA_PAD3STRNG              (26)                    /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD3STRNG              ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD3STRNG              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD3STRNG              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD3STRNG(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD3STRNG)) & (BFM_GPIO_PADREGA_PAD3STRNG))
#define BFX_GPIO_PADREGA_PAD3STRNG(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD3STRNG)) >> (BFP_GPIO_PADREGA_PAD3STRNG))
#define BFW_GPIO_PADREGA_PAD3STRNG(v)           (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD3STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD3STRNG)) & (BFM_GPIO_PADREGA_PAD3STRNG)) ))
#define BFR_GPIO_PADREGA_PAD3STRNG()            ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD3STRNG))>>(BFP_GPIO_PADREGA_PAD3STRNG))

#define BFP_GPIO_PADREGA_PAD3INPEN              (25)                    /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD3INPEN              ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD3INPEN              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD3INPEN              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD3INPEN(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD3INPEN)) & (BFM_GPIO_PADREGA_PAD3INPEN))
#define BFX_GPIO_PADREGA_PAD3INPEN(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD3INPEN)) >> (BFP_GPIO_PADREGA_PAD3INPEN))
#define BFW_GPIO_PADREGA_PAD3INPEN(v)           (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD3INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD3INPEN)) & (BFM_GPIO_PADREGA_PAD3INPEN)) ))
#define BFR_GPIO_PADREGA_PAD3INPEN()            ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD3INPEN))>>(BFP_GPIO_PADREGA_PAD3INPEN))

#define BFP_GPIO_PADREGA_PAD3PULL               (24)                    /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD3PULL               ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD3PULL               (1)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD3PULL               (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD3PULL(v)            ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD3PULL)) & (BFM_GPIO_PADREGA_PAD3PULL))
#define BFX_GPIO_PADREGA_PAD3PULL(v)            ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD3PULL)) >> (BFP_GPIO_PADREGA_PAD3PULL))
#define BFW_GPIO_PADREGA_PAD3PULL(v)            (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD3PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD3PULL)) & (BFM_GPIO_PADREGA_PAD3PULL)) ))
#define BFR_GPIO_PADREGA_PAD3PULL()             ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD3PULL))>>(BFP_GPIO_PADREGA_PAD3PULL))

#define BFP_GPIO_PADREGA_RSVD_22                (22)                    /* bitfield lsb */
#define BFM_GPIO_PADREGA_RSVD_22                ((uint32_t)0x00c00000)  /* bitfield mask */
#define BFN_GPIO_PADREGA_RSVD_22                (2)                     /* bitfield width */
#define BFD_GPIO_PADREGA_RSVD_22                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_RSVD_22(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGA_RSVD_22)) & (BFM_GPIO_PADREGA_RSVD_22))
#define BFX_GPIO_PADREGA_RSVD_22(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGA_RSVD_22)) >> (BFP_GPIO_PADREGA_RSVD_22))
#define BFW_GPIO_PADREGA_RSVD_22(v)             (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_RSVD_22)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_RSVD_22)) & (BFM_GPIO_PADREGA_RSVD_22)) ))
#define BFR_GPIO_PADREGA_RSVD_22()              ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_RSVD_22))>>(BFP_GPIO_PADREGA_RSVD_22))

#define BFP_GPIO_PADREGA_PAD2FNCSEL             (19)                    /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD2FNCSEL             ((uint32_t)0x00380000)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD2FNCSEL             (3)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD2FNCSEL             (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD2FNCSEL(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD2FNCSEL)) & (BFM_GPIO_PADREGA_PAD2FNCSEL))
#define BFX_GPIO_PADREGA_PAD2FNCSEL(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD2FNCSEL)) >> (BFP_GPIO_PADREGA_PAD2FNCSEL))
#define BFW_GPIO_PADREGA_PAD2FNCSEL(v)          (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD2FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD2FNCSEL)) & (BFM_GPIO_PADREGA_PAD2FNCSEL)) ))
#define BFR_GPIO_PADREGA_PAD2FNCSEL()           ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD2FNCSEL))>>(BFP_GPIO_PADREGA_PAD2FNCSEL))

#define BFP_GPIO_PADREGA_PAD2STRNG              (18)                    /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD2STRNG              ((uint32_t)0x00040000)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD2STRNG              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD2STRNG              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD2STRNG(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD2STRNG)) & (BFM_GPIO_PADREGA_PAD2STRNG))
#define BFX_GPIO_PADREGA_PAD2STRNG(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD2STRNG)) >> (BFP_GPIO_PADREGA_PAD2STRNG))
#define BFW_GPIO_PADREGA_PAD2STRNG(v)           (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD2STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD2STRNG)) & (BFM_GPIO_PADREGA_PAD2STRNG)) ))
#define BFR_GPIO_PADREGA_PAD2STRNG()            ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD2STRNG))>>(BFP_GPIO_PADREGA_PAD2STRNG))

#define BFP_GPIO_PADREGA_PAD2INPEN              (17)                    /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD2INPEN              ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD2INPEN              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD2INPEN              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD2INPEN(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD2INPEN)) & (BFM_GPIO_PADREGA_PAD2INPEN))
#define BFX_GPIO_PADREGA_PAD2INPEN(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD2INPEN)) >> (BFP_GPIO_PADREGA_PAD2INPEN))
#define BFW_GPIO_PADREGA_PAD2INPEN(v)           (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD2INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD2INPEN)) & (BFM_GPIO_PADREGA_PAD2INPEN)) ))
#define BFR_GPIO_PADREGA_PAD2INPEN()            ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD2INPEN))>>(BFP_GPIO_PADREGA_PAD2INPEN))

#define BFP_GPIO_PADREGA_PAD2PULL               (16)                    /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD2PULL               ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD2PULL               (1)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD2PULL               (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD2PULL(v)            ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD2PULL)) & (BFM_GPIO_PADREGA_PAD2PULL))
#define BFX_GPIO_PADREGA_PAD2PULL(v)            ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD2PULL)) >> (BFP_GPIO_PADREGA_PAD2PULL))
#define BFW_GPIO_PADREGA_PAD2PULL(v)            (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD2PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD2PULL)) & (BFM_GPIO_PADREGA_PAD2PULL)) ))
#define BFR_GPIO_PADREGA_PAD2PULL()             ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD2PULL))>>(BFP_GPIO_PADREGA_PAD2PULL))

#define BFP_GPIO_PADREGA_RSVD_14                (14)                    /* bitfield lsb */
#define BFM_GPIO_PADREGA_RSVD_14                ((uint32_t)0x0000c000)  /* bitfield mask */
#define BFN_GPIO_PADREGA_RSVD_14                (2)                     /* bitfield width */
#define BFD_GPIO_PADREGA_RSVD_14                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_RSVD_14(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGA_RSVD_14)) & (BFM_GPIO_PADREGA_RSVD_14))
#define BFX_GPIO_PADREGA_RSVD_14(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGA_RSVD_14)) >> (BFP_GPIO_PADREGA_RSVD_14))
#define BFW_GPIO_PADREGA_RSVD_14(v)             (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_RSVD_14)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_RSVD_14)) & (BFM_GPIO_PADREGA_RSVD_14)) ))
#define BFR_GPIO_PADREGA_RSVD_14()              ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_RSVD_14))>>(BFP_GPIO_PADREGA_RSVD_14))

#define BFP_GPIO_PADREGA_PAD1FNCSEL             (11)                    /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD1FNCSEL             ((uint32_t)0x00003800)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD1FNCSEL             (3)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD1FNCSEL             (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD1FNCSEL(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD1FNCSEL)) & (BFM_GPIO_PADREGA_PAD1FNCSEL))
#define BFX_GPIO_PADREGA_PAD1FNCSEL(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD1FNCSEL)) >> (BFP_GPIO_PADREGA_PAD1FNCSEL))
#define BFW_GPIO_PADREGA_PAD1FNCSEL(v)          (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD1FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD1FNCSEL)) & (BFM_GPIO_PADREGA_PAD1FNCSEL)) ))
#define BFR_GPIO_PADREGA_PAD1FNCSEL()           ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD1FNCSEL))>>(BFP_GPIO_PADREGA_PAD1FNCSEL))

#define BFP_GPIO_PADREGA_PAD1STRNG              (10)                    /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD1STRNG              ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD1STRNG              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD1STRNG              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD1STRNG(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD1STRNG)) & (BFM_GPIO_PADREGA_PAD1STRNG))
#define BFX_GPIO_PADREGA_PAD1STRNG(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD1STRNG)) >> (BFP_GPIO_PADREGA_PAD1STRNG))
#define BFW_GPIO_PADREGA_PAD1STRNG(v)           (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD1STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD1STRNG)) & (BFM_GPIO_PADREGA_PAD1STRNG)) ))
#define BFR_GPIO_PADREGA_PAD1STRNG()            ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD1STRNG))>>(BFP_GPIO_PADREGA_PAD1STRNG))

#define BFP_GPIO_PADREGA_PAD1INPEN              (9)                     /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD1INPEN              ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD1INPEN              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD1INPEN              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD1INPEN(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD1INPEN)) & (BFM_GPIO_PADREGA_PAD1INPEN))
#define BFX_GPIO_PADREGA_PAD1INPEN(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD1INPEN)) >> (BFP_GPIO_PADREGA_PAD1INPEN))
#define BFW_GPIO_PADREGA_PAD1INPEN(v)           (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD1INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD1INPEN)) & (BFM_GPIO_PADREGA_PAD1INPEN)) ))
#define BFR_GPIO_PADREGA_PAD1INPEN()            ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD1INPEN))>>(BFP_GPIO_PADREGA_PAD1INPEN))

#define BFP_GPIO_PADREGA_PAD1PULL               (8)                     /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD1PULL               ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD1PULL               (1)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD1PULL               (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD1PULL(v)            ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD1PULL)) & (BFM_GPIO_PADREGA_PAD1PULL))
#define BFX_GPIO_PADREGA_PAD1PULL(v)            ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD1PULL)) >> (BFP_GPIO_PADREGA_PAD1PULL))
#define BFW_GPIO_PADREGA_PAD1PULL(v)            (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD1PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD1PULL)) & (BFM_GPIO_PADREGA_PAD1PULL)) ))
#define BFR_GPIO_PADREGA_PAD1PULL()             ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD1PULL))>>(BFP_GPIO_PADREGA_PAD1PULL))

#define BFP_GPIO_PADREGA_RSVD_6                 (6)                     /* bitfield lsb */
#define BFM_GPIO_PADREGA_RSVD_6                 ((uint32_t)0x000000c0)  /* bitfield mask */
#define BFN_GPIO_PADREGA_RSVD_6                 (2)                     /* bitfield width */
#define BFD_GPIO_PADREGA_RSVD_6                 (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_RSVD_6(v)              ((((uint32_t) v) << (BFP_GPIO_PADREGA_RSVD_6)) & (BFM_GPIO_PADREGA_RSVD_6))
#define BFX_GPIO_PADREGA_RSVD_6(v)              ((((uint32_t) v) & (BFM_GPIO_PADREGA_RSVD_6)) >> (BFP_GPIO_PADREGA_RSVD_6))
#define BFW_GPIO_PADREGA_RSVD_6(v)              (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_RSVD_6)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_RSVD_6)) & (BFM_GPIO_PADREGA_RSVD_6)) ))
#define BFR_GPIO_PADREGA_RSVD_6()               ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_RSVD_6))>>(BFP_GPIO_PADREGA_RSVD_6))

#define BFP_GPIO_PADREGA_PAD0FNCSEL             (3)                     /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD0FNCSEL             ((uint32_t)0x00000038)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD0FNCSEL             (3)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD0FNCSEL             (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD0FNCSEL(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD0FNCSEL)) & (BFM_GPIO_PADREGA_PAD0FNCSEL))
#define BFX_GPIO_PADREGA_PAD0FNCSEL(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD0FNCSEL)) >> (BFP_GPIO_PADREGA_PAD0FNCSEL))
#define BFW_GPIO_PADREGA_PAD0FNCSEL(v)          (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD0FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD0FNCSEL)) & (BFM_GPIO_PADREGA_PAD0FNCSEL)) ))
#define BFR_GPIO_PADREGA_PAD0FNCSEL()           ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD0FNCSEL))>>(BFP_GPIO_PADREGA_PAD0FNCSEL))

#define BFP_GPIO_PADREGA_PAD0STRNG              (2)                     /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD0STRNG              ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD0STRNG              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD0STRNG              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD0STRNG(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD0STRNG)) & (BFM_GPIO_PADREGA_PAD0STRNG))
#define BFX_GPIO_PADREGA_PAD0STRNG(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD0STRNG)) >> (BFP_GPIO_PADREGA_PAD0STRNG))
#define BFW_GPIO_PADREGA_PAD0STRNG(v)           (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD0STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD0STRNG)) & (BFM_GPIO_PADREGA_PAD0STRNG)) ))
#define BFR_GPIO_PADREGA_PAD0STRNG()            ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD0STRNG))>>(BFP_GPIO_PADREGA_PAD0STRNG))

#define BFP_GPIO_PADREGA_PAD0INPEN              (1)                     /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD0INPEN              ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD0INPEN              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD0INPEN              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD0INPEN(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD0INPEN)) & (BFM_GPIO_PADREGA_PAD0INPEN))
#define BFX_GPIO_PADREGA_PAD0INPEN(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD0INPEN)) >> (BFP_GPIO_PADREGA_PAD0INPEN))
#define BFW_GPIO_PADREGA_PAD0INPEN(v)           (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD0INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD0INPEN)) & (BFM_GPIO_PADREGA_PAD0INPEN)) ))
#define BFR_GPIO_PADREGA_PAD0INPEN()            ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD0INPEN))>>(BFP_GPIO_PADREGA_PAD0INPEN))

#define BFP_GPIO_PADREGA_PAD0PULL               (0)                     /* bitfield lsb */
#define BFM_GPIO_PADREGA_PAD0PULL               ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_PADREGA_PAD0PULL               (1)                     /* bitfield width */
#define BFD_GPIO_PADREGA_PAD0PULL               (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGA_PAD0PULL(v)            ((((uint32_t) v) << (BFP_GPIO_PADREGA_PAD0PULL)) & (BFM_GPIO_PADREGA_PAD0PULL))
#define BFX_GPIO_PADREGA_PAD0PULL(v)            ((((uint32_t) v) & (BFM_GPIO_PADREGA_PAD0PULL)) >> (BFP_GPIO_PADREGA_PAD0PULL))
#define BFW_GPIO_PADREGA_PAD0PULL(v)            (REG_GPIO_PADREGA.U32 = ( (REG_GPIO_PADREGA.U32 & ~(BFM_GPIO_PADREGA_PAD0PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGA_PAD0PULL)) & (BFM_GPIO_PADREGA_PAD0PULL)) ))
#define BFR_GPIO_PADREGA_PAD0PULL()             ((REG_GPIO_PADREGA.U32 & (BFM_GPIO_PADREGA_PAD0PULL))>>(BFP_GPIO_PADREGA_PAD0PULL))


// *****************************************************************************
//                                                                             *
//  GPIO_PADREGB - Pad Configuration Register B                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_30                    :  2;
        unsigned PAD7FNCSEL                 :  3;
        unsigned PAD7STRNG                  :  1;
        unsigned PAD7INPEN                  :  1;
        unsigned PAD7PULL                   :  1;
        unsigned PAD6RSEL                   :  2;
        unsigned PAD6FNCSEL                 :  3;
        unsigned PAD6STRNG                  :  1;
        unsigned PAD6INPEN                  :  1;
        unsigned PAD6PULL                   :  1;
        unsigned PAD5RSEL                   :  2;
        unsigned PAD5FNCSEL                 :  3;
        unsigned PAD5STRNG                  :  1;
        unsigned PAD5INPEN                  :  1;
        unsigned PAD5PULL                   :  1;
        unsigned PAD4PWRUP                  :  1;
        unsigned PAD4PWRDN                  :  1;
        unsigned PAD4FNCSEL                 :  3;
        unsigned PAD4STRNG                  :  1;
        unsigned PAD4INPEN                  :  1;
        unsigned PAD4PULL                   :  1;
    } B;
} reg_gpio_padregb_t;

#define REG_GPIO_PADREGB_ADDR                   (REG_GPIO_BASEADDR + 0x00000004UL)
#define REG_GPIO_PADREGB                        (*(volatile reg_gpio_padregb_t *) REG_GPIO_PADREGB_ADDR)
#define REG_GPIO_PADREGB_RD()                   (REG_GPIO_PADREGB.U32)
#define REG_GPIO_PADREGB_WR(v)                  (REG_GPIO_PADREGB.U32 = (v))
#define REG_GPIO_PADREGB_CLR(m)                 (REG_GPIO_PADREGB.U32 = ((REG_GPIO_PADREGB.U32) & ~(m)))
#define REG_GPIO_PADREGB_SET(m)                 (REG_GPIO_PADREGB.U32 = ((REG_GPIO_PADREGB.U32) | (m)))
#define REG_GPIO_PADREGB_DEF                    0x18181818

#define BFP_GPIO_PADREGB_RSVD_30                (30)                    /* bitfield lsb */
#define BFM_GPIO_PADREGB_RSVD_30                ((uint32_t)0xc0000000)  /* bitfield mask */
#define BFN_GPIO_PADREGB_RSVD_30                (2)                     /* bitfield width */
#define BFD_GPIO_PADREGB_RSVD_30                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_RSVD_30(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGB_RSVD_30)) & (BFM_GPIO_PADREGB_RSVD_30))
#define BFX_GPIO_PADREGB_RSVD_30(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGB_RSVD_30)) >> (BFP_GPIO_PADREGB_RSVD_30))
#define BFW_GPIO_PADREGB_RSVD_30(v)             (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_RSVD_30)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_RSVD_30)) & (BFM_GPIO_PADREGB_RSVD_30)) ))
#define BFR_GPIO_PADREGB_RSVD_30()              ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_RSVD_30))>>(BFP_GPIO_PADREGB_RSVD_30))

#define BFP_GPIO_PADREGB_PAD7FNCSEL             (27)                    /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD7FNCSEL             ((uint32_t)0x38000000)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD7FNCSEL             (3)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD7FNCSEL             (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD7FNCSEL(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD7FNCSEL)) & (BFM_GPIO_PADREGB_PAD7FNCSEL))
#define BFX_GPIO_PADREGB_PAD7FNCSEL(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD7FNCSEL)) >> (BFP_GPIO_PADREGB_PAD7FNCSEL))
#define BFW_GPIO_PADREGB_PAD7FNCSEL(v)          (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD7FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD7FNCSEL)) & (BFM_GPIO_PADREGB_PAD7FNCSEL)) ))
#define BFR_GPIO_PADREGB_PAD7FNCSEL()           ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD7FNCSEL))>>(BFP_GPIO_PADREGB_PAD7FNCSEL))

#define BFP_GPIO_PADREGB_PAD7STRNG              (26)                    /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD7STRNG              ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD7STRNG              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD7STRNG              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD7STRNG(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD7STRNG)) & (BFM_GPIO_PADREGB_PAD7STRNG))
#define BFX_GPIO_PADREGB_PAD7STRNG(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD7STRNG)) >> (BFP_GPIO_PADREGB_PAD7STRNG))
#define BFW_GPIO_PADREGB_PAD7STRNG(v)           (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD7STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD7STRNG)) & (BFM_GPIO_PADREGB_PAD7STRNG)) ))
#define BFR_GPIO_PADREGB_PAD7STRNG()            ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD7STRNG))>>(BFP_GPIO_PADREGB_PAD7STRNG))

#define BFP_GPIO_PADREGB_PAD7INPEN              (25)                    /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD7INPEN              ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD7INPEN              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD7INPEN              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD7INPEN(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD7INPEN)) & (BFM_GPIO_PADREGB_PAD7INPEN))
#define BFX_GPIO_PADREGB_PAD7INPEN(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD7INPEN)) >> (BFP_GPIO_PADREGB_PAD7INPEN))
#define BFW_GPIO_PADREGB_PAD7INPEN(v)           (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD7INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD7INPEN)) & (BFM_GPIO_PADREGB_PAD7INPEN)) ))
#define BFR_GPIO_PADREGB_PAD7INPEN()            ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD7INPEN))>>(BFP_GPIO_PADREGB_PAD7INPEN))

#define BFP_GPIO_PADREGB_PAD7PULL               (24)                    /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD7PULL               ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD7PULL               (1)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD7PULL               (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD7PULL(v)            ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD7PULL)) & (BFM_GPIO_PADREGB_PAD7PULL))
#define BFX_GPIO_PADREGB_PAD7PULL(v)            ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD7PULL)) >> (BFP_GPIO_PADREGB_PAD7PULL))
#define BFW_GPIO_PADREGB_PAD7PULL(v)            (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD7PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD7PULL)) & (BFM_GPIO_PADREGB_PAD7PULL)) ))
#define BFR_GPIO_PADREGB_PAD7PULL()             ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD7PULL))>>(BFP_GPIO_PADREGB_PAD7PULL))

#define BFP_GPIO_PADREGB_PAD6RSEL               (22)                    /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD6RSEL               ((uint32_t)0x00c00000)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD6RSEL               (2)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD6RSEL               (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD6RSEL(v)            ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD6RSEL)) & (BFM_GPIO_PADREGB_PAD6RSEL))
#define BFX_GPIO_PADREGB_PAD6RSEL(v)            ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD6RSEL)) >> (BFP_GPIO_PADREGB_PAD6RSEL))
#define BFW_GPIO_PADREGB_PAD6RSEL(v)            (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD6RSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD6RSEL)) & (BFM_GPIO_PADREGB_PAD6RSEL)) ))
#define BFR_GPIO_PADREGB_PAD6RSEL()             ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD6RSEL))>>(BFP_GPIO_PADREGB_PAD6RSEL))

#define BFP_GPIO_PADREGB_PAD6FNCSEL             (19)                    /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD6FNCSEL             ((uint32_t)0x00380000)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD6FNCSEL             (3)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD6FNCSEL             (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD6FNCSEL(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD6FNCSEL)) & (BFM_GPIO_PADREGB_PAD6FNCSEL))
#define BFX_GPIO_PADREGB_PAD6FNCSEL(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD6FNCSEL)) >> (BFP_GPIO_PADREGB_PAD6FNCSEL))
#define BFW_GPIO_PADREGB_PAD6FNCSEL(v)          (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD6FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD6FNCSEL)) & (BFM_GPIO_PADREGB_PAD6FNCSEL)) ))
#define BFR_GPIO_PADREGB_PAD6FNCSEL()           ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD6FNCSEL))>>(BFP_GPIO_PADREGB_PAD6FNCSEL))

#define BFP_GPIO_PADREGB_PAD6STRNG              (18)                    /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD6STRNG              ((uint32_t)0x00040000)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD6STRNG              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD6STRNG              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD6STRNG(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD6STRNG)) & (BFM_GPIO_PADREGB_PAD6STRNG))
#define BFX_GPIO_PADREGB_PAD6STRNG(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD6STRNG)) >> (BFP_GPIO_PADREGB_PAD6STRNG))
#define BFW_GPIO_PADREGB_PAD6STRNG(v)           (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD6STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD6STRNG)) & (BFM_GPIO_PADREGB_PAD6STRNG)) ))
#define BFR_GPIO_PADREGB_PAD6STRNG()            ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD6STRNG))>>(BFP_GPIO_PADREGB_PAD6STRNG))

#define BFP_GPIO_PADREGB_PAD6INPEN              (17)                    /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD6INPEN              ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD6INPEN              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD6INPEN              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD6INPEN(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD6INPEN)) & (BFM_GPIO_PADREGB_PAD6INPEN))
#define BFX_GPIO_PADREGB_PAD6INPEN(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD6INPEN)) >> (BFP_GPIO_PADREGB_PAD6INPEN))
#define BFW_GPIO_PADREGB_PAD6INPEN(v)           (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD6INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD6INPEN)) & (BFM_GPIO_PADREGB_PAD6INPEN)) ))
#define BFR_GPIO_PADREGB_PAD6INPEN()            ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD6INPEN))>>(BFP_GPIO_PADREGB_PAD6INPEN))

#define BFP_GPIO_PADREGB_PAD6PULL               (16)                    /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD6PULL               ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD6PULL               (1)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD6PULL               (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD6PULL(v)            ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD6PULL)) & (BFM_GPIO_PADREGB_PAD6PULL))
#define BFX_GPIO_PADREGB_PAD6PULL(v)            ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD6PULL)) >> (BFP_GPIO_PADREGB_PAD6PULL))
#define BFW_GPIO_PADREGB_PAD6PULL(v)            (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD6PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD6PULL)) & (BFM_GPIO_PADREGB_PAD6PULL)) ))
#define BFR_GPIO_PADREGB_PAD6PULL()             ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD6PULL))>>(BFP_GPIO_PADREGB_PAD6PULL))

#define BFP_GPIO_PADREGB_PAD5RSEL               (14)                    /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD5RSEL               ((uint32_t)0x0000c000)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD5RSEL               (2)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD5RSEL               (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD5RSEL(v)            ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD5RSEL)) & (BFM_GPIO_PADREGB_PAD5RSEL))
#define BFX_GPIO_PADREGB_PAD5RSEL(v)            ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD5RSEL)) >> (BFP_GPIO_PADREGB_PAD5RSEL))
#define BFW_GPIO_PADREGB_PAD5RSEL(v)            (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD5RSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD5RSEL)) & (BFM_GPIO_PADREGB_PAD5RSEL)) ))
#define BFR_GPIO_PADREGB_PAD5RSEL()             ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD5RSEL))>>(BFP_GPIO_PADREGB_PAD5RSEL))

#define BFP_GPIO_PADREGB_PAD5FNCSEL             (11)                    /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD5FNCSEL             ((uint32_t)0x00003800)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD5FNCSEL             (3)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD5FNCSEL             (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD5FNCSEL(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD5FNCSEL)) & (BFM_GPIO_PADREGB_PAD5FNCSEL))
#define BFX_GPIO_PADREGB_PAD5FNCSEL(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD5FNCSEL)) >> (BFP_GPIO_PADREGB_PAD5FNCSEL))
#define BFW_GPIO_PADREGB_PAD5FNCSEL(v)          (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD5FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD5FNCSEL)) & (BFM_GPIO_PADREGB_PAD5FNCSEL)) ))
#define BFR_GPIO_PADREGB_PAD5FNCSEL()           ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD5FNCSEL))>>(BFP_GPIO_PADREGB_PAD5FNCSEL))

#define BFP_GPIO_PADREGB_PAD5STRNG              (10)                    /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD5STRNG              ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD5STRNG              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD5STRNG              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD5STRNG(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD5STRNG)) & (BFM_GPIO_PADREGB_PAD5STRNG))
#define BFX_GPIO_PADREGB_PAD5STRNG(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD5STRNG)) >> (BFP_GPIO_PADREGB_PAD5STRNG))
#define BFW_GPIO_PADREGB_PAD5STRNG(v)           (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD5STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD5STRNG)) & (BFM_GPIO_PADREGB_PAD5STRNG)) ))
#define BFR_GPIO_PADREGB_PAD5STRNG()            ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD5STRNG))>>(BFP_GPIO_PADREGB_PAD5STRNG))

#define BFP_GPIO_PADREGB_PAD5INPEN              (9)                     /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD5INPEN              ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD5INPEN              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD5INPEN              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD5INPEN(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD5INPEN)) & (BFM_GPIO_PADREGB_PAD5INPEN))
#define BFX_GPIO_PADREGB_PAD5INPEN(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD5INPEN)) >> (BFP_GPIO_PADREGB_PAD5INPEN))
#define BFW_GPIO_PADREGB_PAD5INPEN(v)           (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD5INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD5INPEN)) & (BFM_GPIO_PADREGB_PAD5INPEN)) ))
#define BFR_GPIO_PADREGB_PAD5INPEN()            ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD5INPEN))>>(BFP_GPIO_PADREGB_PAD5INPEN))

#define BFP_GPIO_PADREGB_PAD5PULL               (8)                     /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD5PULL               ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD5PULL               (1)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD5PULL               (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD5PULL(v)            ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD5PULL)) & (BFM_GPIO_PADREGB_PAD5PULL))
#define BFX_GPIO_PADREGB_PAD5PULL(v)            ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD5PULL)) >> (BFP_GPIO_PADREGB_PAD5PULL))
#define BFW_GPIO_PADREGB_PAD5PULL(v)            (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD5PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD5PULL)) & (BFM_GPIO_PADREGB_PAD5PULL)) ))
#define BFR_GPIO_PADREGB_PAD5PULL()             ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD5PULL))>>(BFP_GPIO_PADREGB_PAD5PULL))

#define BFP_GPIO_PADREGB_PAD4PWRUP              (7)                     /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD4PWRUP              ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD4PWRUP              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD4PWRUP              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD4PWRUP(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD4PWRUP)) & (BFM_GPIO_PADREGB_PAD4PWRUP))
#define BFX_GPIO_PADREGB_PAD4PWRUP(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD4PWRUP)) >> (BFP_GPIO_PADREGB_PAD4PWRUP))
#define BFW_GPIO_PADREGB_PAD4PWRUP(v)           (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD4PWRUP)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD4PWRUP)) & (BFM_GPIO_PADREGB_PAD4PWRUP)) ))
#define BFR_GPIO_PADREGB_PAD4PWRUP()            ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD4PWRUP))>>(BFP_GPIO_PADREGB_PAD4PWRUP))

#define BFP_GPIO_PADREGB_PAD4PWRDN              (6)                     /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD4PWRDN              ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD4PWRDN              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD4PWRDN              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD4PWRDN(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD4PWRDN)) & (BFM_GPIO_PADREGB_PAD4PWRDN))
#define BFX_GPIO_PADREGB_PAD4PWRDN(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD4PWRDN)) >> (BFP_GPIO_PADREGB_PAD4PWRDN))
#define BFW_GPIO_PADREGB_PAD4PWRDN(v)           (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD4PWRDN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD4PWRDN)) & (BFM_GPIO_PADREGB_PAD4PWRDN)) ))
#define BFR_GPIO_PADREGB_PAD4PWRDN()            ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD4PWRDN))>>(BFP_GPIO_PADREGB_PAD4PWRDN))

#define BFP_GPIO_PADREGB_PAD4FNCSEL             (3)                     /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD4FNCSEL             ((uint32_t)0x00000038)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD4FNCSEL             (3)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD4FNCSEL             (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD4FNCSEL(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD4FNCSEL)) & (BFM_GPIO_PADREGB_PAD4FNCSEL))
#define BFX_GPIO_PADREGB_PAD4FNCSEL(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD4FNCSEL)) >> (BFP_GPIO_PADREGB_PAD4FNCSEL))
#define BFW_GPIO_PADREGB_PAD4FNCSEL(v)          (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD4FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD4FNCSEL)) & (BFM_GPIO_PADREGB_PAD4FNCSEL)) ))
#define BFR_GPIO_PADREGB_PAD4FNCSEL()           ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD4FNCSEL))>>(BFP_GPIO_PADREGB_PAD4FNCSEL))

#define BFP_GPIO_PADREGB_PAD4STRNG              (2)                     /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD4STRNG              ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD4STRNG              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD4STRNG              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD4STRNG(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD4STRNG)) & (BFM_GPIO_PADREGB_PAD4STRNG))
#define BFX_GPIO_PADREGB_PAD4STRNG(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD4STRNG)) >> (BFP_GPIO_PADREGB_PAD4STRNG))
#define BFW_GPIO_PADREGB_PAD4STRNG(v)           (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD4STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD4STRNG)) & (BFM_GPIO_PADREGB_PAD4STRNG)) ))
#define BFR_GPIO_PADREGB_PAD4STRNG()            ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD4STRNG))>>(BFP_GPIO_PADREGB_PAD4STRNG))

#define BFP_GPIO_PADREGB_PAD4INPEN              (1)                     /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD4INPEN              ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD4INPEN              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD4INPEN              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD4INPEN(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD4INPEN)) & (BFM_GPIO_PADREGB_PAD4INPEN))
#define BFX_GPIO_PADREGB_PAD4INPEN(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD4INPEN)) >> (BFP_GPIO_PADREGB_PAD4INPEN))
#define BFW_GPIO_PADREGB_PAD4INPEN(v)           (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD4INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD4INPEN)) & (BFM_GPIO_PADREGB_PAD4INPEN)) ))
#define BFR_GPIO_PADREGB_PAD4INPEN()            ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD4INPEN))>>(BFP_GPIO_PADREGB_PAD4INPEN))

#define BFP_GPIO_PADREGB_PAD4PULL               (0)                     /* bitfield lsb */
#define BFM_GPIO_PADREGB_PAD4PULL               ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_PADREGB_PAD4PULL               (1)                     /* bitfield width */
#define BFD_GPIO_PADREGB_PAD4PULL               (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGB_PAD4PULL(v)            ((((uint32_t) v) << (BFP_GPIO_PADREGB_PAD4PULL)) & (BFM_GPIO_PADREGB_PAD4PULL))
#define BFX_GPIO_PADREGB_PAD4PULL(v)            ((((uint32_t) v) & (BFM_GPIO_PADREGB_PAD4PULL)) >> (BFP_GPIO_PADREGB_PAD4PULL))
#define BFW_GPIO_PADREGB_PAD4PULL(v)            (REG_GPIO_PADREGB.U32 = ( (REG_GPIO_PADREGB.U32 & ~(BFM_GPIO_PADREGB_PAD4PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGB_PAD4PULL)) & (BFM_GPIO_PADREGB_PAD4PULL)) ))
#define BFR_GPIO_PADREGB_PAD4PULL()             ((REG_GPIO_PADREGB.U32 & (BFM_GPIO_PADREGB_PAD4PULL))>>(BFP_GPIO_PADREGB_PAD4PULL))


// *****************************************************************************
//                                                                             *
//  GPIO_PADREGC - Pad Configuration Register C                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned PAD11PWRUP                 :  1;
        unsigned PAD11PWRDN                 :  1;
        unsigned RSVD_29                    :  1;
        unsigned PAD11FNCSEL                :  2;
        unsigned PAD11STRNG                 :  1;
        unsigned PAD11INPEN                 :  1;
        unsigned PAD11PULL                  :  1;
        unsigned RSVD_22                    :  2;
        unsigned PAD10FNCSEL                :  3;
        unsigned PAD10STRNG                 :  1;
        unsigned PAD10INPEN                 :  1;
        unsigned PAD10PULL                  :  1;
        unsigned PAD9RSEL                   :  2;
        unsigned PAD9FNCSEL                 :  3;
        unsigned PAD9STRNG                  :  1;
        unsigned PAD9INPEN                  :  1;
        unsigned PAD9PULL                   :  1;
        unsigned PAD8RSEL                   :  2;
        unsigned PAD8FNCSEL                 :  3;
        unsigned PAD8STRNG                  :  1;
        unsigned PAD8INPEN                  :  1;
        unsigned PAD8PULL                   :  1;
    } B;
} reg_gpio_padregc_t;

#define REG_GPIO_PADREGC_ADDR                   (REG_GPIO_BASEADDR + 0x00000008UL)
#define REG_GPIO_PADREGC                        (*(volatile reg_gpio_padregc_t *) REG_GPIO_PADREGC_ADDR)
#define REG_GPIO_PADREGC_RD()                   (REG_GPIO_PADREGC.U32)
#define REG_GPIO_PADREGC_WR(v)                  (REG_GPIO_PADREGC.U32 = (v))
#define REG_GPIO_PADREGC_CLR(m)                 (REG_GPIO_PADREGC.U32 = ((REG_GPIO_PADREGC.U32) & ~(m)))
#define REG_GPIO_PADREGC_SET(m)                 (REG_GPIO_PADREGC.U32 = ((REG_GPIO_PADREGC.U32) | (m)))
#define REG_GPIO_PADREGC_DEF                    0x18181818

#define BFP_GPIO_PADREGC_PAD11PWRUP             (31)                    /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD11PWRUP             ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD11PWRUP             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD11PWRUP             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD11PWRUP(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD11PWRUP)) & (BFM_GPIO_PADREGC_PAD11PWRUP))
#define BFX_GPIO_PADREGC_PAD11PWRUP(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD11PWRUP)) >> (BFP_GPIO_PADREGC_PAD11PWRUP))
#define BFW_GPIO_PADREGC_PAD11PWRUP(v)          (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD11PWRUP)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD11PWRUP)) & (BFM_GPIO_PADREGC_PAD11PWRUP)) ))
#define BFR_GPIO_PADREGC_PAD11PWRUP()           ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD11PWRUP))>>(BFP_GPIO_PADREGC_PAD11PWRUP))

#define BFP_GPIO_PADREGC_PAD11PWRDN             (30)                    /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD11PWRDN             ((uint32_t)0x40000000)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD11PWRDN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD11PWRDN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD11PWRDN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD11PWRDN)) & (BFM_GPIO_PADREGC_PAD11PWRDN))
#define BFX_GPIO_PADREGC_PAD11PWRDN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD11PWRDN)) >> (BFP_GPIO_PADREGC_PAD11PWRDN))
#define BFW_GPIO_PADREGC_PAD11PWRDN(v)          (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD11PWRDN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD11PWRDN)) & (BFM_GPIO_PADREGC_PAD11PWRDN)) ))
#define BFR_GPIO_PADREGC_PAD11PWRDN()           ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD11PWRDN))>>(BFP_GPIO_PADREGC_PAD11PWRDN))

#define BFP_GPIO_PADREGC_RSVD_29                (29)                    /* bitfield lsb */
#define BFM_GPIO_PADREGC_RSVD_29                ((uint32_t)0x20000000)  /* bitfield mask */
#define BFN_GPIO_PADREGC_RSVD_29                (1)                     /* bitfield width */
#define BFD_GPIO_PADREGC_RSVD_29                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_RSVD_29(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGC_RSVD_29)) & (BFM_GPIO_PADREGC_RSVD_29))
#define BFX_GPIO_PADREGC_RSVD_29(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGC_RSVD_29)) >> (BFP_GPIO_PADREGC_RSVD_29))
#define BFW_GPIO_PADREGC_RSVD_29(v)             (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_RSVD_29)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_RSVD_29)) & (BFM_GPIO_PADREGC_RSVD_29)) ))
#define BFR_GPIO_PADREGC_RSVD_29()              ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_RSVD_29))>>(BFP_GPIO_PADREGC_RSVD_29))

#define BFP_GPIO_PADREGC_PAD11FNCSEL            (27)                    /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD11FNCSEL            ((uint32_t)0x18000000)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD11FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD11FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD11FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD11FNCSEL)) & (BFM_GPIO_PADREGC_PAD11FNCSEL))
#define BFX_GPIO_PADREGC_PAD11FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD11FNCSEL)) >> (BFP_GPIO_PADREGC_PAD11FNCSEL))
#define BFW_GPIO_PADREGC_PAD11FNCSEL(v)         (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD11FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD11FNCSEL)) & (BFM_GPIO_PADREGC_PAD11FNCSEL)) ))
#define BFR_GPIO_PADREGC_PAD11FNCSEL()          ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD11FNCSEL))>>(BFP_GPIO_PADREGC_PAD11FNCSEL))

#define BFP_GPIO_PADREGC_PAD11STRNG             (26)                    /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD11STRNG             ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD11STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD11STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD11STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD11STRNG)) & (BFM_GPIO_PADREGC_PAD11STRNG))
#define BFX_GPIO_PADREGC_PAD11STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD11STRNG)) >> (BFP_GPIO_PADREGC_PAD11STRNG))
#define BFW_GPIO_PADREGC_PAD11STRNG(v)          (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD11STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD11STRNG)) & (BFM_GPIO_PADREGC_PAD11STRNG)) ))
#define BFR_GPIO_PADREGC_PAD11STRNG()           ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD11STRNG))>>(BFP_GPIO_PADREGC_PAD11STRNG))

#define BFP_GPIO_PADREGC_PAD11INPEN             (25)                    /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD11INPEN             ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD11INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD11INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD11INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD11INPEN)) & (BFM_GPIO_PADREGC_PAD11INPEN))
#define BFX_GPIO_PADREGC_PAD11INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD11INPEN)) >> (BFP_GPIO_PADREGC_PAD11INPEN))
#define BFW_GPIO_PADREGC_PAD11INPEN(v)          (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD11INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD11INPEN)) & (BFM_GPIO_PADREGC_PAD11INPEN)) ))
#define BFR_GPIO_PADREGC_PAD11INPEN()           ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD11INPEN))>>(BFP_GPIO_PADREGC_PAD11INPEN))

#define BFP_GPIO_PADREGC_PAD11PULL              (24)                    /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD11PULL              ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD11PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD11PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD11PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD11PULL)) & (BFM_GPIO_PADREGC_PAD11PULL))
#define BFX_GPIO_PADREGC_PAD11PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD11PULL)) >> (BFP_GPIO_PADREGC_PAD11PULL))
#define BFW_GPIO_PADREGC_PAD11PULL(v)           (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD11PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD11PULL)) & (BFM_GPIO_PADREGC_PAD11PULL)) ))
#define BFR_GPIO_PADREGC_PAD11PULL()            ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD11PULL))>>(BFP_GPIO_PADREGC_PAD11PULL))

#define BFP_GPIO_PADREGC_RSVD_22                (22)                    /* bitfield lsb */
#define BFM_GPIO_PADREGC_RSVD_22                ((uint32_t)0x00c00000)  /* bitfield mask */
#define BFN_GPIO_PADREGC_RSVD_22                (2)                     /* bitfield width */
#define BFD_GPIO_PADREGC_RSVD_22                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_RSVD_22(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGC_RSVD_22)) & (BFM_GPIO_PADREGC_RSVD_22))
#define BFX_GPIO_PADREGC_RSVD_22(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGC_RSVD_22)) >> (BFP_GPIO_PADREGC_RSVD_22))
#define BFW_GPIO_PADREGC_RSVD_22(v)             (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_RSVD_22)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_RSVD_22)) & (BFM_GPIO_PADREGC_RSVD_22)) ))
#define BFR_GPIO_PADREGC_RSVD_22()              ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_RSVD_22))>>(BFP_GPIO_PADREGC_RSVD_22))

#define BFP_GPIO_PADREGC_PAD10FNCSEL            (19)                    /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD10FNCSEL            ((uint32_t)0x00380000)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD10FNCSEL            (3)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD10FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD10FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD10FNCSEL)) & (BFM_GPIO_PADREGC_PAD10FNCSEL))
#define BFX_GPIO_PADREGC_PAD10FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD10FNCSEL)) >> (BFP_GPIO_PADREGC_PAD10FNCSEL))
#define BFW_GPIO_PADREGC_PAD10FNCSEL(v)         (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD10FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD10FNCSEL)) & (BFM_GPIO_PADREGC_PAD10FNCSEL)) ))
#define BFR_GPIO_PADREGC_PAD10FNCSEL()          ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD10FNCSEL))>>(BFP_GPIO_PADREGC_PAD10FNCSEL))

#define BFP_GPIO_PADREGC_PAD10STRNG             (18)                    /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD10STRNG             ((uint32_t)0x00040000)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD10STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD10STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD10STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD10STRNG)) & (BFM_GPIO_PADREGC_PAD10STRNG))
#define BFX_GPIO_PADREGC_PAD10STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD10STRNG)) >> (BFP_GPIO_PADREGC_PAD10STRNG))
#define BFW_GPIO_PADREGC_PAD10STRNG(v)          (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD10STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD10STRNG)) & (BFM_GPIO_PADREGC_PAD10STRNG)) ))
#define BFR_GPIO_PADREGC_PAD10STRNG()           ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD10STRNG))>>(BFP_GPIO_PADREGC_PAD10STRNG))

#define BFP_GPIO_PADREGC_PAD10INPEN             (17)                    /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD10INPEN             ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD10INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD10INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD10INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD10INPEN)) & (BFM_GPIO_PADREGC_PAD10INPEN))
#define BFX_GPIO_PADREGC_PAD10INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD10INPEN)) >> (BFP_GPIO_PADREGC_PAD10INPEN))
#define BFW_GPIO_PADREGC_PAD10INPEN(v)          (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD10INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD10INPEN)) & (BFM_GPIO_PADREGC_PAD10INPEN)) ))
#define BFR_GPIO_PADREGC_PAD10INPEN()           ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD10INPEN))>>(BFP_GPIO_PADREGC_PAD10INPEN))

#define BFP_GPIO_PADREGC_PAD10PULL              (16)                    /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD10PULL              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD10PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD10PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD10PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD10PULL)) & (BFM_GPIO_PADREGC_PAD10PULL))
#define BFX_GPIO_PADREGC_PAD10PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD10PULL)) >> (BFP_GPIO_PADREGC_PAD10PULL))
#define BFW_GPIO_PADREGC_PAD10PULL(v)           (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD10PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD10PULL)) & (BFM_GPIO_PADREGC_PAD10PULL)) ))
#define BFR_GPIO_PADREGC_PAD10PULL()            ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD10PULL))>>(BFP_GPIO_PADREGC_PAD10PULL))

#define BFP_GPIO_PADREGC_PAD9RSEL               (14)                    /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD9RSEL               ((uint32_t)0x0000c000)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD9RSEL               (2)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD9RSEL               (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD9RSEL(v)            ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD9RSEL)) & (BFM_GPIO_PADREGC_PAD9RSEL))
#define BFX_GPIO_PADREGC_PAD9RSEL(v)            ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD9RSEL)) >> (BFP_GPIO_PADREGC_PAD9RSEL))
#define BFW_GPIO_PADREGC_PAD9RSEL(v)            (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD9RSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD9RSEL)) & (BFM_GPIO_PADREGC_PAD9RSEL)) ))
#define BFR_GPIO_PADREGC_PAD9RSEL()             ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD9RSEL))>>(BFP_GPIO_PADREGC_PAD9RSEL))

#define BFP_GPIO_PADREGC_PAD9FNCSEL             (11)                    /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD9FNCSEL             ((uint32_t)0x00003800)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD9FNCSEL             (3)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD9FNCSEL             (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD9FNCSEL(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD9FNCSEL)) & (BFM_GPIO_PADREGC_PAD9FNCSEL))
#define BFX_GPIO_PADREGC_PAD9FNCSEL(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD9FNCSEL)) >> (BFP_GPIO_PADREGC_PAD9FNCSEL))
#define BFW_GPIO_PADREGC_PAD9FNCSEL(v)          (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD9FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD9FNCSEL)) & (BFM_GPIO_PADREGC_PAD9FNCSEL)) ))
#define BFR_GPIO_PADREGC_PAD9FNCSEL()           ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD9FNCSEL))>>(BFP_GPIO_PADREGC_PAD9FNCSEL))

#define BFP_GPIO_PADREGC_PAD9STRNG              (10)                    /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD9STRNG              ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD9STRNG              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD9STRNG              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD9STRNG(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD9STRNG)) & (BFM_GPIO_PADREGC_PAD9STRNG))
#define BFX_GPIO_PADREGC_PAD9STRNG(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD9STRNG)) >> (BFP_GPIO_PADREGC_PAD9STRNG))
#define BFW_GPIO_PADREGC_PAD9STRNG(v)           (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD9STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD9STRNG)) & (BFM_GPIO_PADREGC_PAD9STRNG)) ))
#define BFR_GPIO_PADREGC_PAD9STRNG()            ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD9STRNG))>>(BFP_GPIO_PADREGC_PAD9STRNG))

#define BFP_GPIO_PADREGC_PAD9INPEN              (9)                     /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD9INPEN              ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD9INPEN              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD9INPEN              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD9INPEN(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD9INPEN)) & (BFM_GPIO_PADREGC_PAD9INPEN))
#define BFX_GPIO_PADREGC_PAD9INPEN(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD9INPEN)) >> (BFP_GPIO_PADREGC_PAD9INPEN))
#define BFW_GPIO_PADREGC_PAD9INPEN(v)           (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD9INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD9INPEN)) & (BFM_GPIO_PADREGC_PAD9INPEN)) ))
#define BFR_GPIO_PADREGC_PAD9INPEN()            ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD9INPEN))>>(BFP_GPIO_PADREGC_PAD9INPEN))

#define BFP_GPIO_PADREGC_PAD9PULL               (8)                     /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD9PULL               ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD9PULL               (1)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD9PULL               (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD9PULL(v)            ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD9PULL)) & (BFM_GPIO_PADREGC_PAD9PULL))
#define BFX_GPIO_PADREGC_PAD9PULL(v)            ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD9PULL)) >> (BFP_GPIO_PADREGC_PAD9PULL))
#define BFW_GPIO_PADREGC_PAD9PULL(v)            (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD9PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD9PULL)) & (BFM_GPIO_PADREGC_PAD9PULL)) ))
#define BFR_GPIO_PADREGC_PAD9PULL()             ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD9PULL))>>(BFP_GPIO_PADREGC_PAD9PULL))

#define BFP_GPIO_PADREGC_PAD8RSEL               (6)                     /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD8RSEL               ((uint32_t)0x000000c0)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD8RSEL               (2)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD8RSEL               (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD8RSEL(v)            ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD8RSEL)) & (BFM_GPIO_PADREGC_PAD8RSEL))
#define BFX_GPIO_PADREGC_PAD8RSEL(v)            ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD8RSEL)) >> (BFP_GPIO_PADREGC_PAD8RSEL))
#define BFW_GPIO_PADREGC_PAD8RSEL(v)            (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD8RSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD8RSEL)) & (BFM_GPIO_PADREGC_PAD8RSEL)) ))
#define BFR_GPIO_PADREGC_PAD8RSEL()             ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD8RSEL))>>(BFP_GPIO_PADREGC_PAD8RSEL))

#define BFP_GPIO_PADREGC_PAD8FNCSEL             (3)                     /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD8FNCSEL             ((uint32_t)0x00000038)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD8FNCSEL             (3)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD8FNCSEL             (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD8FNCSEL(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD8FNCSEL)) & (BFM_GPIO_PADREGC_PAD8FNCSEL))
#define BFX_GPIO_PADREGC_PAD8FNCSEL(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD8FNCSEL)) >> (BFP_GPIO_PADREGC_PAD8FNCSEL))
#define BFW_GPIO_PADREGC_PAD8FNCSEL(v)          (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD8FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD8FNCSEL)) & (BFM_GPIO_PADREGC_PAD8FNCSEL)) ))
#define BFR_GPIO_PADREGC_PAD8FNCSEL()           ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD8FNCSEL))>>(BFP_GPIO_PADREGC_PAD8FNCSEL))

#define BFP_GPIO_PADREGC_PAD8STRNG              (2)                     /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD8STRNG              ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD8STRNG              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD8STRNG              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD8STRNG(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD8STRNG)) & (BFM_GPIO_PADREGC_PAD8STRNG))
#define BFX_GPIO_PADREGC_PAD8STRNG(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD8STRNG)) >> (BFP_GPIO_PADREGC_PAD8STRNG))
#define BFW_GPIO_PADREGC_PAD8STRNG(v)           (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD8STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD8STRNG)) & (BFM_GPIO_PADREGC_PAD8STRNG)) ))
#define BFR_GPIO_PADREGC_PAD8STRNG()            ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD8STRNG))>>(BFP_GPIO_PADREGC_PAD8STRNG))

#define BFP_GPIO_PADREGC_PAD8INPEN              (1)                     /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD8INPEN              ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD8INPEN              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD8INPEN              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD8INPEN(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD8INPEN)) & (BFM_GPIO_PADREGC_PAD8INPEN))
#define BFX_GPIO_PADREGC_PAD8INPEN(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD8INPEN)) >> (BFP_GPIO_PADREGC_PAD8INPEN))
#define BFW_GPIO_PADREGC_PAD8INPEN(v)           (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD8INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD8INPEN)) & (BFM_GPIO_PADREGC_PAD8INPEN)) ))
#define BFR_GPIO_PADREGC_PAD8INPEN()            ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD8INPEN))>>(BFP_GPIO_PADREGC_PAD8INPEN))

#define BFP_GPIO_PADREGC_PAD8PULL               (0)                     /* bitfield lsb */
#define BFM_GPIO_PADREGC_PAD8PULL               ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_PADREGC_PAD8PULL               (1)                     /* bitfield width */
#define BFD_GPIO_PADREGC_PAD8PULL               (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGC_PAD8PULL(v)            ((((uint32_t) v) << (BFP_GPIO_PADREGC_PAD8PULL)) & (BFM_GPIO_PADREGC_PAD8PULL))
#define BFX_GPIO_PADREGC_PAD8PULL(v)            ((((uint32_t) v) & (BFM_GPIO_PADREGC_PAD8PULL)) >> (BFP_GPIO_PADREGC_PAD8PULL))
#define BFW_GPIO_PADREGC_PAD8PULL(v)            (REG_GPIO_PADREGC.U32 = ( (REG_GPIO_PADREGC.U32 & ~(BFM_GPIO_PADREGC_PAD8PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGC_PAD8PULL)) & (BFM_GPIO_PADREGC_PAD8PULL)) ))
#define BFR_GPIO_PADREGC_PAD8PULL()             ((REG_GPIO_PADREGC.U32 & (BFM_GPIO_PADREGC_PAD8PULL))>>(BFP_GPIO_PADREGC_PAD8PULL))


// *****************************************************************************
//                                                                             *
//  GPIO_PADREGD - Pad Configuration Register D                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_30                    :  2;
        unsigned PAD15FNCSEL                :  3;
        unsigned PAD15STRNG                 :  1;
        unsigned PAD15INPEN                 :  1;
        unsigned PAD15PULL                  :  1;
        unsigned RSVD_22                    :  2;
        unsigned PAD14FNCSEL                :  3;
        unsigned PAD14STRNG                 :  1;
        unsigned PAD14INPEN                 :  1;
        unsigned PAD14PULL                  :  1;
        unsigned RSVD_14                    :  2;
        unsigned PAD13FNCSEL                :  3;
        unsigned PAD13STRNG                 :  1;
        unsigned PAD13INPEN                 :  1;
        unsigned PAD13PULL                  :  1;
        unsigned RSVD_5                     :  3;
        unsigned PAD12FNCSEL                :  2;
        unsigned PAD12STRNG                 :  1;
        unsigned PAD12INPEN                 :  1;
        unsigned PAD12PULL                  :  1;
    } B;
} reg_gpio_padregd_t;

#define REG_GPIO_PADREGD_ADDR                   (REG_GPIO_BASEADDR + 0x0000000CUL)
#define REG_GPIO_PADREGD                        (*(volatile reg_gpio_padregd_t *) REG_GPIO_PADREGD_ADDR)
#define REG_GPIO_PADREGD_RD()                   (REG_GPIO_PADREGD.U32)
#define REG_GPIO_PADREGD_WR(v)                  (REG_GPIO_PADREGD.U32 = (v))
#define REG_GPIO_PADREGD_CLR(m)                 (REG_GPIO_PADREGD.U32 = ((REG_GPIO_PADREGD.U32) & ~(m)))
#define REG_GPIO_PADREGD_SET(m)                 (REG_GPIO_PADREGD.U32 = ((REG_GPIO_PADREGD.U32) | (m)))
#define REG_GPIO_PADREGD_DEF                    0x18181818

#define BFP_GPIO_PADREGD_RSVD_30                (30)                    /* bitfield lsb */
#define BFM_GPIO_PADREGD_RSVD_30                ((uint32_t)0xc0000000)  /* bitfield mask */
#define BFN_GPIO_PADREGD_RSVD_30                (2)                     /* bitfield width */
#define BFD_GPIO_PADREGD_RSVD_30                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_RSVD_30(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGD_RSVD_30)) & (BFM_GPIO_PADREGD_RSVD_30))
#define BFX_GPIO_PADREGD_RSVD_30(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGD_RSVD_30)) >> (BFP_GPIO_PADREGD_RSVD_30))
#define BFW_GPIO_PADREGD_RSVD_30(v)             (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_RSVD_30)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_RSVD_30)) & (BFM_GPIO_PADREGD_RSVD_30)) ))
#define BFR_GPIO_PADREGD_RSVD_30()              ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_RSVD_30))>>(BFP_GPIO_PADREGD_RSVD_30))

#define BFP_GPIO_PADREGD_PAD15FNCSEL            (27)                    /* bitfield lsb */
#define BFM_GPIO_PADREGD_PAD15FNCSEL            ((uint32_t)0x38000000)  /* bitfield mask */
#define BFN_GPIO_PADREGD_PAD15FNCSEL            (3)                     /* bitfield width */
#define BFD_GPIO_PADREGD_PAD15FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_PAD15FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGD_PAD15FNCSEL)) & (BFM_GPIO_PADREGD_PAD15FNCSEL))
#define BFX_GPIO_PADREGD_PAD15FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGD_PAD15FNCSEL)) >> (BFP_GPIO_PADREGD_PAD15FNCSEL))
#define BFW_GPIO_PADREGD_PAD15FNCSEL(v)         (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_PAD15FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_PAD15FNCSEL)) & (BFM_GPIO_PADREGD_PAD15FNCSEL)) ))
#define BFR_GPIO_PADREGD_PAD15FNCSEL()          ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_PAD15FNCSEL))>>(BFP_GPIO_PADREGD_PAD15FNCSEL))

#define BFP_GPIO_PADREGD_PAD15STRNG             (26)                    /* bitfield lsb */
#define BFM_GPIO_PADREGD_PAD15STRNG             ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_GPIO_PADREGD_PAD15STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGD_PAD15STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_PAD15STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGD_PAD15STRNG)) & (BFM_GPIO_PADREGD_PAD15STRNG))
#define BFX_GPIO_PADREGD_PAD15STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGD_PAD15STRNG)) >> (BFP_GPIO_PADREGD_PAD15STRNG))
#define BFW_GPIO_PADREGD_PAD15STRNG(v)          (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_PAD15STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_PAD15STRNG)) & (BFM_GPIO_PADREGD_PAD15STRNG)) ))
#define BFR_GPIO_PADREGD_PAD15STRNG()           ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_PAD15STRNG))>>(BFP_GPIO_PADREGD_PAD15STRNG))

#define BFP_GPIO_PADREGD_PAD15INPEN             (25)                    /* bitfield lsb */
#define BFM_GPIO_PADREGD_PAD15INPEN             ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_GPIO_PADREGD_PAD15INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGD_PAD15INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_PAD15INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGD_PAD15INPEN)) & (BFM_GPIO_PADREGD_PAD15INPEN))
#define BFX_GPIO_PADREGD_PAD15INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGD_PAD15INPEN)) >> (BFP_GPIO_PADREGD_PAD15INPEN))
#define BFW_GPIO_PADREGD_PAD15INPEN(v)          (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_PAD15INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_PAD15INPEN)) & (BFM_GPIO_PADREGD_PAD15INPEN)) ))
#define BFR_GPIO_PADREGD_PAD15INPEN()           ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_PAD15INPEN))>>(BFP_GPIO_PADREGD_PAD15INPEN))

#define BFP_GPIO_PADREGD_PAD15PULL              (24)                    /* bitfield lsb */
#define BFM_GPIO_PADREGD_PAD15PULL              ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_PADREGD_PAD15PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGD_PAD15PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_PAD15PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGD_PAD15PULL)) & (BFM_GPIO_PADREGD_PAD15PULL))
#define BFX_GPIO_PADREGD_PAD15PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGD_PAD15PULL)) >> (BFP_GPIO_PADREGD_PAD15PULL))
#define BFW_GPIO_PADREGD_PAD15PULL(v)           (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_PAD15PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_PAD15PULL)) & (BFM_GPIO_PADREGD_PAD15PULL)) ))
#define BFR_GPIO_PADREGD_PAD15PULL()            ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_PAD15PULL))>>(BFP_GPIO_PADREGD_PAD15PULL))

#define BFP_GPIO_PADREGD_RSVD_22                (22)                    /* bitfield lsb */
#define BFM_GPIO_PADREGD_RSVD_22                ((uint32_t)0x00c00000)  /* bitfield mask */
#define BFN_GPIO_PADREGD_RSVD_22                (2)                     /* bitfield width */
#define BFD_GPIO_PADREGD_RSVD_22                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_RSVD_22(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGD_RSVD_22)) & (BFM_GPIO_PADREGD_RSVD_22))
#define BFX_GPIO_PADREGD_RSVD_22(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGD_RSVD_22)) >> (BFP_GPIO_PADREGD_RSVD_22))
#define BFW_GPIO_PADREGD_RSVD_22(v)             (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_RSVD_22)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_RSVD_22)) & (BFM_GPIO_PADREGD_RSVD_22)) ))
#define BFR_GPIO_PADREGD_RSVD_22()              ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_RSVD_22))>>(BFP_GPIO_PADREGD_RSVD_22))

#define BFP_GPIO_PADREGD_PAD14FNCSEL            (19)                    /* bitfield lsb */
#define BFM_GPIO_PADREGD_PAD14FNCSEL            ((uint32_t)0x00380000)  /* bitfield mask */
#define BFN_GPIO_PADREGD_PAD14FNCSEL            (3)                     /* bitfield width */
#define BFD_GPIO_PADREGD_PAD14FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_PAD14FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGD_PAD14FNCSEL)) & (BFM_GPIO_PADREGD_PAD14FNCSEL))
#define BFX_GPIO_PADREGD_PAD14FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGD_PAD14FNCSEL)) >> (BFP_GPIO_PADREGD_PAD14FNCSEL))
#define BFW_GPIO_PADREGD_PAD14FNCSEL(v)         (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_PAD14FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_PAD14FNCSEL)) & (BFM_GPIO_PADREGD_PAD14FNCSEL)) ))
#define BFR_GPIO_PADREGD_PAD14FNCSEL()          ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_PAD14FNCSEL))>>(BFP_GPIO_PADREGD_PAD14FNCSEL))

#define BFP_GPIO_PADREGD_PAD14STRNG             (18)                    /* bitfield lsb */
#define BFM_GPIO_PADREGD_PAD14STRNG             ((uint32_t)0x00040000)  /* bitfield mask */
#define BFN_GPIO_PADREGD_PAD14STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGD_PAD14STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_PAD14STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGD_PAD14STRNG)) & (BFM_GPIO_PADREGD_PAD14STRNG))
#define BFX_GPIO_PADREGD_PAD14STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGD_PAD14STRNG)) >> (BFP_GPIO_PADREGD_PAD14STRNG))
#define BFW_GPIO_PADREGD_PAD14STRNG(v)          (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_PAD14STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_PAD14STRNG)) & (BFM_GPIO_PADREGD_PAD14STRNG)) ))
#define BFR_GPIO_PADREGD_PAD14STRNG()           ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_PAD14STRNG))>>(BFP_GPIO_PADREGD_PAD14STRNG))

#define BFP_GPIO_PADREGD_PAD14INPEN             (17)                    /* bitfield lsb */
#define BFM_GPIO_PADREGD_PAD14INPEN             ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_PADREGD_PAD14INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGD_PAD14INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_PAD14INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGD_PAD14INPEN)) & (BFM_GPIO_PADREGD_PAD14INPEN))
#define BFX_GPIO_PADREGD_PAD14INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGD_PAD14INPEN)) >> (BFP_GPIO_PADREGD_PAD14INPEN))
#define BFW_GPIO_PADREGD_PAD14INPEN(v)          (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_PAD14INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_PAD14INPEN)) & (BFM_GPIO_PADREGD_PAD14INPEN)) ))
#define BFR_GPIO_PADREGD_PAD14INPEN()           ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_PAD14INPEN))>>(BFP_GPIO_PADREGD_PAD14INPEN))

#define BFP_GPIO_PADREGD_PAD14PULL              (16)                    /* bitfield lsb */
#define BFM_GPIO_PADREGD_PAD14PULL              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_PADREGD_PAD14PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGD_PAD14PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_PAD14PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGD_PAD14PULL)) & (BFM_GPIO_PADREGD_PAD14PULL))
#define BFX_GPIO_PADREGD_PAD14PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGD_PAD14PULL)) >> (BFP_GPIO_PADREGD_PAD14PULL))
#define BFW_GPIO_PADREGD_PAD14PULL(v)           (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_PAD14PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_PAD14PULL)) & (BFM_GPIO_PADREGD_PAD14PULL)) ))
#define BFR_GPIO_PADREGD_PAD14PULL()            ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_PAD14PULL))>>(BFP_GPIO_PADREGD_PAD14PULL))

#define BFP_GPIO_PADREGD_RSVD_14                (14)                    /* bitfield lsb */
#define BFM_GPIO_PADREGD_RSVD_14                ((uint32_t)0x0000c000)  /* bitfield mask */
#define BFN_GPIO_PADREGD_RSVD_14                (2)                     /* bitfield width */
#define BFD_GPIO_PADREGD_RSVD_14                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_RSVD_14(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGD_RSVD_14)) & (BFM_GPIO_PADREGD_RSVD_14))
#define BFX_GPIO_PADREGD_RSVD_14(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGD_RSVD_14)) >> (BFP_GPIO_PADREGD_RSVD_14))
#define BFW_GPIO_PADREGD_RSVD_14(v)             (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_RSVD_14)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_RSVD_14)) & (BFM_GPIO_PADREGD_RSVD_14)) ))
#define BFR_GPIO_PADREGD_RSVD_14()              ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_RSVD_14))>>(BFP_GPIO_PADREGD_RSVD_14))

#define BFP_GPIO_PADREGD_PAD13FNCSEL            (11)                    /* bitfield lsb */
#define BFM_GPIO_PADREGD_PAD13FNCSEL            ((uint32_t)0x00003800)  /* bitfield mask */
#define BFN_GPIO_PADREGD_PAD13FNCSEL            (3)                     /* bitfield width */
#define BFD_GPIO_PADREGD_PAD13FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_PAD13FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGD_PAD13FNCSEL)) & (BFM_GPIO_PADREGD_PAD13FNCSEL))
#define BFX_GPIO_PADREGD_PAD13FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGD_PAD13FNCSEL)) >> (BFP_GPIO_PADREGD_PAD13FNCSEL))
#define BFW_GPIO_PADREGD_PAD13FNCSEL(v)         (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_PAD13FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_PAD13FNCSEL)) & (BFM_GPIO_PADREGD_PAD13FNCSEL)) ))
#define BFR_GPIO_PADREGD_PAD13FNCSEL()          ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_PAD13FNCSEL))>>(BFP_GPIO_PADREGD_PAD13FNCSEL))

#define BFP_GPIO_PADREGD_PAD13STRNG             (10)                    /* bitfield lsb */
#define BFM_GPIO_PADREGD_PAD13STRNG             ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_PADREGD_PAD13STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGD_PAD13STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_PAD13STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGD_PAD13STRNG)) & (BFM_GPIO_PADREGD_PAD13STRNG))
#define BFX_GPIO_PADREGD_PAD13STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGD_PAD13STRNG)) >> (BFP_GPIO_PADREGD_PAD13STRNG))
#define BFW_GPIO_PADREGD_PAD13STRNG(v)          (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_PAD13STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_PAD13STRNG)) & (BFM_GPIO_PADREGD_PAD13STRNG)) ))
#define BFR_GPIO_PADREGD_PAD13STRNG()           ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_PAD13STRNG))>>(BFP_GPIO_PADREGD_PAD13STRNG))

#define BFP_GPIO_PADREGD_PAD13INPEN             (9)                     /* bitfield lsb */
#define BFM_GPIO_PADREGD_PAD13INPEN             ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_PADREGD_PAD13INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGD_PAD13INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_PAD13INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGD_PAD13INPEN)) & (BFM_GPIO_PADREGD_PAD13INPEN))
#define BFX_GPIO_PADREGD_PAD13INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGD_PAD13INPEN)) >> (BFP_GPIO_PADREGD_PAD13INPEN))
#define BFW_GPIO_PADREGD_PAD13INPEN(v)          (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_PAD13INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_PAD13INPEN)) & (BFM_GPIO_PADREGD_PAD13INPEN)) ))
#define BFR_GPIO_PADREGD_PAD13INPEN()           ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_PAD13INPEN))>>(BFP_GPIO_PADREGD_PAD13INPEN))

#define BFP_GPIO_PADREGD_PAD13PULL              (8)                     /* bitfield lsb */
#define BFM_GPIO_PADREGD_PAD13PULL              ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_PADREGD_PAD13PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGD_PAD13PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_PAD13PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGD_PAD13PULL)) & (BFM_GPIO_PADREGD_PAD13PULL))
#define BFX_GPIO_PADREGD_PAD13PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGD_PAD13PULL)) >> (BFP_GPIO_PADREGD_PAD13PULL))
#define BFW_GPIO_PADREGD_PAD13PULL(v)           (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_PAD13PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_PAD13PULL)) & (BFM_GPIO_PADREGD_PAD13PULL)) ))
#define BFR_GPIO_PADREGD_PAD13PULL()            ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_PAD13PULL))>>(BFP_GPIO_PADREGD_PAD13PULL))

#define BFP_GPIO_PADREGD_RSVD_5                 (5)                     /* bitfield lsb */
#define BFM_GPIO_PADREGD_RSVD_5                 ((uint32_t)0x000000e0)  /* bitfield mask */
#define BFN_GPIO_PADREGD_RSVD_5                 (3)                     /* bitfield width */
#define BFD_GPIO_PADREGD_RSVD_5                 (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_RSVD_5(v)              ((((uint32_t) v) << (BFP_GPIO_PADREGD_RSVD_5)) & (BFM_GPIO_PADREGD_RSVD_5))
#define BFX_GPIO_PADREGD_RSVD_5(v)              ((((uint32_t) v) & (BFM_GPIO_PADREGD_RSVD_5)) >> (BFP_GPIO_PADREGD_RSVD_5))
#define BFW_GPIO_PADREGD_RSVD_5(v)              (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_RSVD_5)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_RSVD_5)) & (BFM_GPIO_PADREGD_RSVD_5)) ))
#define BFR_GPIO_PADREGD_RSVD_5()               ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_RSVD_5))>>(BFP_GPIO_PADREGD_RSVD_5))

#define BFP_GPIO_PADREGD_PAD12FNCSEL            (3)                     /* bitfield lsb */
#define BFM_GPIO_PADREGD_PAD12FNCSEL            ((uint32_t)0x00000018)  /* bitfield mask */
#define BFN_GPIO_PADREGD_PAD12FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGD_PAD12FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_PAD12FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGD_PAD12FNCSEL)) & (BFM_GPIO_PADREGD_PAD12FNCSEL))
#define BFX_GPIO_PADREGD_PAD12FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGD_PAD12FNCSEL)) >> (BFP_GPIO_PADREGD_PAD12FNCSEL))
#define BFW_GPIO_PADREGD_PAD12FNCSEL(v)         (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_PAD12FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_PAD12FNCSEL)) & (BFM_GPIO_PADREGD_PAD12FNCSEL)) ))
#define BFR_GPIO_PADREGD_PAD12FNCSEL()          ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_PAD12FNCSEL))>>(BFP_GPIO_PADREGD_PAD12FNCSEL))

#define BFP_GPIO_PADREGD_PAD12STRNG             (2)                     /* bitfield lsb */
#define BFM_GPIO_PADREGD_PAD12STRNG             ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_PADREGD_PAD12STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGD_PAD12STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_PAD12STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGD_PAD12STRNG)) & (BFM_GPIO_PADREGD_PAD12STRNG))
#define BFX_GPIO_PADREGD_PAD12STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGD_PAD12STRNG)) >> (BFP_GPIO_PADREGD_PAD12STRNG))
#define BFW_GPIO_PADREGD_PAD12STRNG(v)          (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_PAD12STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_PAD12STRNG)) & (BFM_GPIO_PADREGD_PAD12STRNG)) ))
#define BFR_GPIO_PADREGD_PAD12STRNG()           ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_PAD12STRNG))>>(BFP_GPIO_PADREGD_PAD12STRNG))

#define BFP_GPIO_PADREGD_PAD12INPEN             (1)                     /* bitfield lsb */
#define BFM_GPIO_PADREGD_PAD12INPEN             ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_PADREGD_PAD12INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGD_PAD12INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_PAD12INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGD_PAD12INPEN)) & (BFM_GPIO_PADREGD_PAD12INPEN))
#define BFX_GPIO_PADREGD_PAD12INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGD_PAD12INPEN)) >> (BFP_GPIO_PADREGD_PAD12INPEN))
#define BFW_GPIO_PADREGD_PAD12INPEN(v)          (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_PAD12INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_PAD12INPEN)) & (BFM_GPIO_PADREGD_PAD12INPEN)) ))
#define BFR_GPIO_PADREGD_PAD12INPEN()           ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_PAD12INPEN))>>(BFP_GPIO_PADREGD_PAD12INPEN))

#define BFP_GPIO_PADREGD_PAD12PULL              (0)                     /* bitfield lsb */
#define BFM_GPIO_PADREGD_PAD12PULL              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_PADREGD_PAD12PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGD_PAD12PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGD_PAD12PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGD_PAD12PULL)) & (BFM_GPIO_PADREGD_PAD12PULL))
#define BFX_GPIO_PADREGD_PAD12PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGD_PAD12PULL)) >> (BFP_GPIO_PADREGD_PAD12PULL))
#define BFW_GPIO_PADREGD_PAD12PULL(v)           (REG_GPIO_PADREGD.U32 = ( (REG_GPIO_PADREGD.U32 & ~(BFM_GPIO_PADREGD_PAD12PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGD_PAD12PULL)) & (BFM_GPIO_PADREGD_PAD12PULL)) ))
#define BFR_GPIO_PADREGD_PAD12PULL()            ((REG_GPIO_PADREGD.U32 & (BFM_GPIO_PADREGD_PAD12PULL))>>(BFP_GPIO_PADREGD_PAD12PULL))


// *****************************************************************************
//                                                                             *
//  GPIO_PADREGE - Pad Configuration Register E                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_29                    :  3;
        unsigned PAD19FNCSEL                :  2;
        unsigned PAD19STRNG                 :  1;
        unsigned PAD19INPEN                 :  1;
        unsigned PAD19PULL                  :  1;
        unsigned RSVD_21                    :  3;
        unsigned PAD18FNCSEL                :  2;
        unsigned PAD18STRNG                 :  1;
        unsigned PAD18INPEN                 :  1;
        unsigned PAD18PULL                  :  1;
        unsigned RSVD_14                    :  2;
        unsigned PAD17FNCSEL                :  3;
        unsigned PAD17STRNG                 :  1;
        unsigned PAD17INPEN                 :  1;
        unsigned PAD17PULL                  :  1;
        unsigned RSVD_5                     :  3;
        unsigned PAD16FNCSEL                :  2;
        unsigned PAD16STRNG                 :  1;
        unsigned PAD16INPEN                 :  1;
        unsigned PAD16PULL                  :  1;
    } B;
} reg_gpio_padrege_t;

#define REG_GPIO_PADREGE_ADDR                   (REG_GPIO_BASEADDR + 0x00000010UL)
#define REG_GPIO_PADREGE                        (*(volatile reg_gpio_padrege_t *) REG_GPIO_PADREGE_ADDR)
#define REG_GPIO_PADREGE_RD()                   (REG_GPIO_PADREGE.U32)
#define REG_GPIO_PADREGE_WR(v)                  (REG_GPIO_PADREGE.U32 = (v))
#define REG_GPIO_PADREGE_CLR(m)                 (REG_GPIO_PADREGE.U32 = ((REG_GPIO_PADREGE.U32) & ~(m)))
#define REG_GPIO_PADREGE_SET(m)                 (REG_GPIO_PADREGE.U32 = ((REG_GPIO_PADREGE.U32) | (m)))
#define REG_GPIO_PADREGE_DEF                    0x18181818

#define BFP_GPIO_PADREGE_RSVD_29                (29)                    /* bitfield lsb */
#define BFM_GPIO_PADREGE_RSVD_29                ((uint32_t)0xe0000000)  /* bitfield mask */
#define BFN_GPIO_PADREGE_RSVD_29                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGE_RSVD_29                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_RSVD_29(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGE_RSVD_29)) & (BFM_GPIO_PADREGE_RSVD_29))
#define BFX_GPIO_PADREGE_RSVD_29(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGE_RSVD_29)) >> (BFP_GPIO_PADREGE_RSVD_29))
#define BFW_GPIO_PADREGE_RSVD_29(v)             (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_RSVD_29)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_RSVD_29)) & (BFM_GPIO_PADREGE_RSVD_29)) ))
#define BFR_GPIO_PADREGE_RSVD_29()              ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_RSVD_29))>>(BFP_GPIO_PADREGE_RSVD_29))

#define BFP_GPIO_PADREGE_PAD19FNCSEL            (27)                    /* bitfield lsb */
#define BFM_GPIO_PADREGE_PAD19FNCSEL            ((uint32_t)0x18000000)  /* bitfield mask */
#define BFN_GPIO_PADREGE_PAD19FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGE_PAD19FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_PAD19FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGE_PAD19FNCSEL)) & (BFM_GPIO_PADREGE_PAD19FNCSEL))
#define BFX_GPIO_PADREGE_PAD19FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGE_PAD19FNCSEL)) >> (BFP_GPIO_PADREGE_PAD19FNCSEL))
#define BFW_GPIO_PADREGE_PAD19FNCSEL(v)         (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_PAD19FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_PAD19FNCSEL)) & (BFM_GPIO_PADREGE_PAD19FNCSEL)) ))
#define BFR_GPIO_PADREGE_PAD19FNCSEL()          ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_PAD19FNCSEL))>>(BFP_GPIO_PADREGE_PAD19FNCSEL))

#define BFP_GPIO_PADREGE_PAD19STRNG             (26)                    /* bitfield lsb */
#define BFM_GPIO_PADREGE_PAD19STRNG             ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_GPIO_PADREGE_PAD19STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGE_PAD19STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_PAD19STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGE_PAD19STRNG)) & (BFM_GPIO_PADREGE_PAD19STRNG))
#define BFX_GPIO_PADREGE_PAD19STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGE_PAD19STRNG)) >> (BFP_GPIO_PADREGE_PAD19STRNG))
#define BFW_GPIO_PADREGE_PAD19STRNG(v)          (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_PAD19STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_PAD19STRNG)) & (BFM_GPIO_PADREGE_PAD19STRNG)) ))
#define BFR_GPIO_PADREGE_PAD19STRNG()           ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_PAD19STRNG))>>(BFP_GPIO_PADREGE_PAD19STRNG))

#define BFP_GPIO_PADREGE_PAD19INPEN             (25)                    /* bitfield lsb */
#define BFM_GPIO_PADREGE_PAD19INPEN             ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_GPIO_PADREGE_PAD19INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGE_PAD19INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_PAD19INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGE_PAD19INPEN)) & (BFM_GPIO_PADREGE_PAD19INPEN))
#define BFX_GPIO_PADREGE_PAD19INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGE_PAD19INPEN)) >> (BFP_GPIO_PADREGE_PAD19INPEN))
#define BFW_GPIO_PADREGE_PAD19INPEN(v)          (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_PAD19INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_PAD19INPEN)) & (BFM_GPIO_PADREGE_PAD19INPEN)) ))
#define BFR_GPIO_PADREGE_PAD19INPEN()           ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_PAD19INPEN))>>(BFP_GPIO_PADREGE_PAD19INPEN))

#define BFP_GPIO_PADREGE_PAD19PULL              (24)                    /* bitfield lsb */
#define BFM_GPIO_PADREGE_PAD19PULL              ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_PADREGE_PAD19PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGE_PAD19PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_PAD19PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGE_PAD19PULL)) & (BFM_GPIO_PADREGE_PAD19PULL))
#define BFX_GPIO_PADREGE_PAD19PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGE_PAD19PULL)) >> (BFP_GPIO_PADREGE_PAD19PULL))
#define BFW_GPIO_PADREGE_PAD19PULL(v)           (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_PAD19PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_PAD19PULL)) & (BFM_GPIO_PADREGE_PAD19PULL)) ))
#define BFR_GPIO_PADREGE_PAD19PULL()            ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_PAD19PULL))>>(BFP_GPIO_PADREGE_PAD19PULL))

#define BFP_GPIO_PADREGE_RSVD_21                (21)                    /* bitfield lsb */
#define BFM_GPIO_PADREGE_RSVD_21                ((uint32_t)0x00e00000)  /* bitfield mask */
#define BFN_GPIO_PADREGE_RSVD_21                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGE_RSVD_21                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_RSVD_21(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGE_RSVD_21)) & (BFM_GPIO_PADREGE_RSVD_21))
#define BFX_GPIO_PADREGE_RSVD_21(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGE_RSVD_21)) >> (BFP_GPIO_PADREGE_RSVD_21))
#define BFW_GPIO_PADREGE_RSVD_21(v)             (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_RSVD_21)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_RSVD_21)) & (BFM_GPIO_PADREGE_RSVD_21)) ))
#define BFR_GPIO_PADREGE_RSVD_21()              ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_RSVD_21))>>(BFP_GPIO_PADREGE_RSVD_21))

#define BFP_GPIO_PADREGE_PAD18FNCSEL            (19)                    /* bitfield lsb */
#define BFM_GPIO_PADREGE_PAD18FNCSEL            ((uint32_t)0x00180000)  /* bitfield mask */
#define BFN_GPIO_PADREGE_PAD18FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGE_PAD18FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_PAD18FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGE_PAD18FNCSEL)) & (BFM_GPIO_PADREGE_PAD18FNCSEL))
#define BFX_GPIO_PADREGE_PAD18FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGE_PAD18FNCSEL)) >> (BFP_GPIO_PADREGE_PAD18FNCSEL))
#define BFW_GPIO_PADREGE_PAD18FNCSEL(v)         (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_PAD18FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_PAD18FNCSEL)) & (BFM_GPIO_PADREGE_PAD18FNCSEL)) ))
#define BFR_GPIO_PADREGE_PAD18FNCSEL()          ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_PAD18FNCSEL))>>(BFP_GPIO_PADREGE_PAD18FNCSEL))

#define BFP_GPIO_PADREGE_PAD18STRNG             (18)                    /* bitfield lsb */
#define BFM_GPIO_PADREGE_PAD18STRNG             ((uint32_t)0x00040000)  /* bitfield mask */
#define BFN_GPIO_PADREGE_PAD18STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGE_PAD18STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_PAD18STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGE_PAD18STRNG)) & (BFM_GPIO_PADREGE_PAD18STRNG))
#define BFX_GPIO_PADREGE_PAD18STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGE_PAD18STRNG)) >> (BFP_GPIO_PADREGE_PAD18STRNG))
#define BFW_GPIO_PADREGE_PAD18STRNG(v)          (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_PAD18STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_PAD18STRNG)) & (BFM_GPIO_PADREGE_PAD18STRNG)) ))
#define BFR_GPIO_PADREGE_PAD18STRNG()           ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_PAD18STRNG))>>(BFP_GPIO_PADREGE_PAD18STRNG))

#define BFP_GPIO_PADREGE_PAD18INPEN             (17)                    /* bitfield lsb */
#define BFM_GPIO_PADREGE_PAD18INPEN             ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_PADREGE_PAD18INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGE_PAD18INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_PAD18INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGE_PAD18INPEN)) & (BFM_GPIO_PADREGE_PAD18INPEN))
#define BFX_GPIO_PADREGE_PAD18INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGE_PAD18INPEN)) >> (BFP_GPIO_PADREGE_PAD18INPEN))
#define BFW_GPIO_PADREGE_PAD18INPEN(v)          (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_PAD18INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_PAD18INPEN)) & (BFM_GPIO_PADREGE_PAD18INPEN)) ))
#define BFR_GPIO_PADREGE_PAD18INPEN()           ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_PAD18INPEN))>>(BFP_GPIO_PADREGE_PAD18INPEN))

#define BFP_GPIO_PADREGE_PAD18PULL              (16)                    /* bitfield lsb */
#define BFM_GPIO_PADREGE_PAD18PULL              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_PADREGE_PAD18PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGE_PAD18PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_PAD18PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGE_PAD18PULL)) & (BFM_GPIO_PADREGE_PAD18PULL))
#define BFX_GPIO_PADREGE_PAD18PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGE_PAD18PULL)) >> (BFP_GPIO_PADREGE_PAD18PULL))
#define BFW_GPIO_PADREGE_PAD18PULL(v)           (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_PAD18PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_PAD18PULL)) & (BFM_GPIO_PADREGE_PAD18PULL)) ))
#define BFR_GPIO_PADREGE_PAD18PULL()            ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_PAD18PULL))>>(BFP_GPIO_PADREGE_PAD18PULL))

#define BFP_GPIO_PADREGE_RSVD_14                (14)                    /* bitfield lsb */
#define BFM_GPIO_PADREGE_RSVD_14                ((uint32_t)0x0000c000)  /* bitfield mask */
#define BFN_GPIO_PADREGE_RSVD_14                (2)                     /* bitfield width */
#define BFD_GPIO_PADREGE_RSVD_14                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_RSVD_14(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGE_RSVD_14)) & (BFM_GPIO_PADREGE_RSVD_14))
#define BFX_GPIO_PADREGE_RSVD_14(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGE_RSVD_14)) >> (BFP_GPIO_PADREGE_RSVD_14))
#define BFW_GPIO_PADREGE_RSVD_14(v)             (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_RSVD_14)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_RSVD_14)) & (BFM_GPIO_PADREGE_RSVD_14)) ))
#define BFR_GPIO_PADREGE_RSVD_14()              ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_RSVD_14))>>(BFP_GPIO_PADREGE_RSVD_14))

#define BFP_GPIO_PADREGE_PAD17FNCSEL            (11)                    /* bitfield lsb */
#define BFM_GPIO_PADREGE_PAD17FNCSEL            ((uint32_t)0x00003800)  /* bitfield mask */
#define BFN_GPIO_PADREGE_PAD17FNCSEL            (3)                     /* bitfield width */
#define BFD_GPIO_PADREGE_PAD17FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_PAD17FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGE_PAD17FNCSEL)) & (BFM_GPIO_PADREGE_PAD17FNCSEL))
#define BFX_GPIO_PADREGE_PAD17FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGE_PAD17FNCSEL)) >> (BFP_GPIO_PADREGE_PAD17FNCSEL))
#define BFW_GPIO_PADREGE_PAD17FNCSEL(v)         (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_PAD17FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_PAD17FNCSEL)) & (BFM_GPIO_PADREGE_PAD17FNCSEL)) ))
#define BFR_GPIO_PADREGE_PAD17FNCSEL()          ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_PAD17FNCSEL))>>(BFP_GPIO_PADREGE_PAD17FNCSEL))

#define BFP_GPIO_PADREGE_PAD17STRNG             (10)                    /* bitfield lsb */
#define BFM_GPIO_PADREGE_PAD17STRNG             ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_PADREGE_PAD17STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGE_PAD17STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_PAD17STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGE_PAD17STRNG)) & (BFM_GPIO_PADREGE_PAD17STRNG))
#define BFX_GPIO_PADREGE_PAD17STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGE_PAD17STRNG)) >> (BFP_GPIO_PADREGE_PAD17STRNG))
#define BFW_GPIO_PADREGE_PAD17STRNG(v)          (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_PAD17STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_PAD17STRNG)) & (BFM_GPIO_PADREGE_PAD17STRNG)) ))
#define BFR_GPIO_PADREGE_PAD17STRNG()           ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_PAD17STRNG))>>(BFP_GPIO_PADREGE_PAD17STRNG))

#define BFP_GPIO_PADREGE_PAD17INPEN             (9)                     /* bitfield lsb */
#define BFM_GPIO_PADREGE_PAD17INPEN             ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_PADREGE_PAD17INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGE_PAD17INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_PAD17INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGE_PAD17INPEN)) & (BFM_GPIO_PADREGE_PAD17INPEN))
#define BFX_GPIO_PADREGE_PAD17INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGE_PAD17INPEN)) >> (BFP_GPIO_PADREGE_PAD17INPEN))
#define BFW_GPIO_PADREGE_PAD17INPEN(v)          (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_PAD17INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_PAD17INPEN)) & (BFM_GPIO_PADREGE_PAD17INPEN)) ))
#define BFR_GPIO_PADREGE_PAD17INPEN()           ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_PAD17INPEN))>>(BFP_GPIO_PADREGE_PAD17INPEN))

#define BFP_GPIO_PADREGE_PAD17PULL              (8)                     /* bitfield lsb */
#define BFM_GPIO_PADREGE_PAD17PULL              ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_PADREGE_PAD17PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGE_PAD17PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_PAD17PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGE_PAD17PULL)) & (BFM_GPIO_PADREGE_PAD17PULL))
#define BFX_GPIO_PADREGE_PAD17PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGE_PAD17PULL)) >> (BFP_GPIO_PADREGE_PAD17PULL))
#define BFW_GPIO_PADREGE_PAD17PULL(v)           (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_PAD17PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_PAD17PULL)) & (BFM_GPIO_PADREGE_PAD17PULL)) ))
#define BFR_GPIO_PADREGE_PAD17PULL()            ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_PAD17PULL))>>(BFP_GPIO_PADREGE_PAD17PULL))

#define BFP_GPIO_PADREGE_RSVD_5                 (5)                     /* bitfield lsb */
#define BFM_GPIO_PADREGE_RSVD_5                 ((uint32_t)0x000000e0)  /* bitfield mask */
#define BFN_GPIO_PADREGE_RSVD_5                 (3)                     /* bitfield width */
#define BFD_GPIO_PADREGE_RSVD_5                 (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_RSVD_5(v)              ((((uint32_t) v) << (BFP_GPIO_PADREGE_RSVD_5)) & (BFM_GPIO_PADREGE_RSVD_5))
#define BFX_GPIO_PADREGE_RSVD_5(v)              ((((uint32_t) v) & (BFM_GPIO_PADREGE_RSVD_5)) >> (BFP_GPIO_PADREGE_RSVD_5))
#define BFW_GPIO_PADREGE_RSVD_5(v)              (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_RSVD_5)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_RSVD_5)) & (BFM_GPIO_PADREGE_RSVD_5)) ))
#define BFR_GPIO_PADREGE_RSVD_5()               ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_RSVD_5))>>(BFP_GPIO_PADREGE_RSVD_5))

#define BFP_GPIO_PADREGE_PAD16FNCSEL            (3)                     /* bitfield lsb */
#define BFM_GPIO_PADREGE_PAD16FNCSEL            ((uint32_t)0x00000018)  /* bitfield mask */
#define BFN_GPIO_PADREGE_PAD16FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGE_PAD16FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_PAD16FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGE_PAD16FNCSEL)) & (BFM_GPIO_PADREGE_PAD16FNCSEL))
#define BFX_GPIO_PADREGE_PAD16FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGE_PAD16FNCSEL)) >> (BFP_GPIO_PADREGE_PAD16FNCSEL))
#define BFW_GPIO_PADREGE_PAD16FNCSEL(v)         (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_PAD16FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_PAD16FNCSEL)) & (BFM_GPIO_PADREGE_PAD16FNCSEL)) ))
#define BFR_GPIO_PADREGE_PAD16FNCSEL()          ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_PAD16FNCSEL))>>(BFP_GPIO_PADREGE_PAD16FNCSEL))

#define BFP_GPIO_PADREGE_PAD16STRNG             (2)                     /* bitfield lsb */
#define BFM_GPIO_PADREGE_PAD16STRNG             ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_PADREGE_PAD16STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGE_PAD16STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_PAD16STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGE_PAD16STRNG)) & (BFM_GPIO_PADREGE_PAD16STRNG))
#define BFX_GPIO_PADREGE_PAD16STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGE_PAD16STRNG)) >> (BFP_GPIO_PADREGE_PAD16STRNG))
#define BFW_GPIO_PADREGE_PAD16STRNG(v)          (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_PAD16STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_PAD16STRNG)) & (BFM_GPIO_PADREGE_PAD16STRNG)) ))
#define BFR_GPIO_PADREGE_PAD16STRNG()           ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_PAD16STRNG))>>(BFP_GPIO_PADREGE_PAD16STRNG))

#define BFP_GPIO_PADREGE_PAD16INPEN             (1)                     /* bitfield lsb */
#define BFM_GPIO_PADREGE_PAD16INPEN             ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_PADREGE_PAD16INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGE_PAD16INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_PAD16INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGE_PAD16INPEN)) & (BFM_GPIO_PADREGE_PAD16INPEN))
#define BFX_GPIO_PADREGE_PAD16INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGE_PAD16INPEN)) >> (BFP_GPIO_PADREGE_PAD16INPEN))
#define BFW_GPIO_PADREGE_PAD16INPEN(v)          (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_PAD16INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_PAD16INPEN)) & (BFM_GPIO_PADREGE_PAD16INPEN)) ))
#define BFR_GPIO_PADREGE_PAD16INPEN()           ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_PAD16INPEN))>>(BFP_GPIO_PADREGE_PAD16INPEN))

#define BFP_GPIO_PADREGE_PAD16PULL              (0)                     /* bitfield lsb */
#define BFM_GPIO_PADREGE_PAD16PULL              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_PADREGE_PAD16PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGE_PAD16PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGE_PAD16PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGE_PAD16PULL)) & (BFM_GPIO_PADREGE_PAD16PULL))
#define BFX_GPIO_PADREGE_PAD16PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGE_PAD16PULL)) >> (BFP_GPIO_PADREGE_PAD16PULL))
#define BFW_GPIO_PADREGE_PAD16PULL(v)           (REG_GPIO_PADREGE.U32 = ( (REG_GPIO_PADREGE.U32 & ~(BFM_GPIO_PADREGE_PAD16PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGE_PAD16PULL)) & (BFM_GPIO_PADREGE_PAD16PULL)) ))
#define BFR_GPIO_PADREGE_PAD16PULL()            ((REG_GPIO_PADREGE.U32 & (BFM_GPIO_PADREGE_PAD16PULL))>>(BFP_GPIO_PADREGE_PAD16PULL))


// *****************************************************************************
//                                                                             *
//  GPIO_PADREGF - Pad Configuration Register F                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_29                    :  3;
        unsigned PAD23FNCSEL                :  2;
        unsigned PAD23STRNG                 :  1;
        unsigned PAD23INPEN                 :  1;
        unsigned PAD23PULL                  :  1;
        unsigned RSVD_21                    :  3;
        unsigned PAD22FNCSEL                :  2;
        unsigned PAD22STRNG                 :  1;
        unsigned PAD22INPEN                 :  1;
        unsigned PAD22PULL                  :  1;
        unsigned RSVD_13                    :  3;
        unsigned PAD21FNCSEL                :  2;
        unsigned PAD21STRNG                 :  1;
        unsigned PAD21INPEN                 :  1;
        unsigned PAD21PULL                  :  1;
        unsigned RSVD_5                     :  3;
        unsigned PAD20FNCSEL                :  2;
        unsigned PAD20STRNG                 :  1;
        unsigned PAD20INPEN                 :  1;
        unsigned PAD20PULL                  :  1;
    } B;
} reg_gpio_padregf_t;

#define REG_GPIO_PADREGF_ADDR                   (REG_GPIO_BASEADDR + 0x00000014UL)
#define REG_GPIO_PADREGF                        (*(volatile reg_gpio_padregf_t *) REG_GPIO_PADREGF_ADDR)
#define REG_GPIO_PADREGF_RD()                   (REG_GPIO_PADREGF.U32)
#define REG_GPIO_PADREGF_WR(v)                  (REG_GPIO_PADREGF.U32 = (v))
#define REG_GPIO_PADREGF_CLR(m)                 (REG_GPIO_PADREGF.U32 = ((REG_GPIO_PADREGF.U32) & ~(m)))
#define REG_GPIO_PADREGF_SET(m)                 (REG_GPIO_PADREGF.U32 = ((REG_GPIO_PADREGF.U32) | (m)))
#define REG_GPIO_PADREGF_DEF                    0x18180202

#define BFP_GPIO_PADREGF_RSVD_29                (29)                    /* bitfield lsb */
#define BFM_GPIO_PADREGF_RSVD_29                ((uint32_t)0xe0000000)  /* bitfield mask */
#define BFN_GPIO_PADREGF_RSVD_29                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGF_RSVD_29                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_RSVD_29(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGF_RSVD_29)) & (BFM_GPIO_PADREGF_RSVD_29))
#define BFX_GPIO_PADREGF_RSVD_29(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGF_RSVD_29)) >> (BFP_GPIO_PADREGF_RSVD_29))
#define BFW_GPIO_PADREGF_RSVD_29(v)             (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_RSVD_29)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_RSVD_29)) & (BFM_GPIO_PADREGF_RSVD_29)) ))
#define BFR_GPIO_PADREGF_RSVD_29()              ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_RSVD_29))>>(BFP_GPIO_PADREGF_RSVD_29))

#define BFP_GPIO_PADREGF_PAD23FNCSEL            (27)                    /* bitfield lsb */
#define BFM_GPIO_PADREGF_PAD23FNCSEL            ((uint32_t)0x18000000)  /* bitfield mask */
#define BFN_GPIO_PADREGF_PAD23FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGF_PAD23FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_PAD23FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGF_PAD23FNCSEL)) & (BFM_GPIO_PADREGF_PAD23FNCSEL))
#define BFX_GPIO_PADREGF_PAD23FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGF_PAD23FNCSEL)) >> (BFP_GPIO_PADREGF_PAD23FNCSEL))
#define BFW_GPIO_PADREGF_PAD23FNCSEL(v)         (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_PAD23FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_PAD23FNCSEL)) & (BFM_GPIO_PADREGF_PAD23FNCSEL)) ))
#define BFR_GPIO_PADREGF_PAD23FNCSEL()          ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_PAD23FNCSEL))>>(BFP_GPIO_PADREGF_PAD23FNCSEL))

#define BFP_GPIO_PADREGF_PAD23STRNG             (26)                    /* bitfield lsb */
#define BFM_GPIO_PADREGF_PAD23STRNG             ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_GPIO_PADREGF_PAD23STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGF_PAD23STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_PAD23STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGF_PAD23STRNG)) & (BFM_GPIO_PADREGF_PAD23STRNG))
#define BFX_GPIO_PADREGF_PAD23STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGF_PAD23STRNG)) >> (BFP_GPIO_PADREGF_PAD23STRNG))
#define BFW_GPIO_PADREGF_PAD23STRNG(v)          (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_PAD23STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_PAD23STRNG)) & (BFM_GPIO_PADREGF_PAD23STRNG)) ))
#define BFR_GPIO_PADREGF_PAD23STRNG()           ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_PAD23STRNG))>>(BFP_GPIO_PADREGF_PAD23STRNG))

#define BFP_GPIO_PADREGF_PAD23INPEN             (25)                    /* bitfield lsb */
#define BFM_GPIO_PADREGF_PAD23INPEN             ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_GPIO_PADREGF_PAD23INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGF_PAD23INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_PAD23INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGF_PAD23INPEN)) & (BFM_GPIO_PADREGF_PAD23INPEN))
#define BFX_GPIO_PADREGF_PAD23INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGF_PAD23INPEN)) >> (BFP_GPIO_PADREGF_PAD23INPEN))
#define BFW_GPIO_PADREGF_PAD23INPEN(v)          (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_PAD23INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_PAD23INPEN)) & (BFM_GPIO_PADREGF_PAD23INPEN)) ))
#define BFR_GPIO_PADREGF_PAD23INPEN()           ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_PAD23INPEN))>>(BFP_GPIO_PADREGF_PAD23INPEN))

#define BFP_GPIO_PADREGF_PAD23PULL              (24)                    /* bitfield lsb */
#define BFM_GPIO_PADREGF_PAD23PULL              ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_PADREGF_PAD23PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGF_PAD23PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_PAD23PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGF_PAD23PULL)) & (BFM_GPIO_PADREGF_PAD23PULL))
#define BFX_GPIO_PADREGF_PAD23PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGF_PAD23PULL)) >> (BFP_GPIO_PADREGF_PAD23PULL))
#define BFW_GPIO_PADREGF_PAD23PULL(v)           (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_PAD23PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_PAD23PULL)) & (BFM_GPIO_PADREGF_PAD23PULL)) ))
#define BFR_GPIO_PADREGF_PAD23PULL()            ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_PAD23PULL))>>(BFP_GPIO_PADREGF_PAD23PULL))

#define BFP_GPIO_PADREGF_RSVD_21                (21)                    /* bitfield lsb */
#define BFM_GPIO_PADREGF_RSVD_21                ((uint32_t)0x00e00000)  /* bitfield mask */
#define BFN_GPIO_PADREGF_RSVD_21                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGF_RSVD_21                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_RSVD_21(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGF_RSVD_21)) & (BFM_GPIO_PADREGF_RSVD_21))
#define BFX_GPIO_PADREGF_RSVD_21(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGF_RSVD_21)) >> (BFP_GPIO_PADREGF_RSVD_21))
#define BFW_GPIO_PADREGF_RSVD_21(v)             (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_RSVD_21)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_RSVD_21)) & (BFM_GPIO_PADREGF_RSVD_21)) ))
#define BFR_GPIO_PADREGF_RSVD_21()              ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_RSVD_21))>>(BFP_GPIO_PADREGF_RSVD_21))

#define BFP_GPIO_PADREGF_PAD22FNCSEL            (19)                    /* bitfield lsb */
#define BFM_GPIO_PADREGF_PAD22FNCSEL            ((uint32_t)0x00180000)  /* bitfield mask */
#define BFN_GPIO_PADREGF_PAD22FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGF_PAD22FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_PAD22FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGF_PAD22FNCSEL)) & (BFM_GPIO_PADREGF_PAD22FNCSEL))
#define BFX_GPIO_PADREGF_PAD22FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGF_PAD22FNCSEL)) >> (BFP_GPIO_PADREGF_PAD22FNCSEL))
#define BFW_GPIO_PADREGF_PAD22FNCSEL(v)         (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_PAD22FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_PAD22FNCSEL)) & (BFM_GPIO_PADREGF_PAD22FNCSEL)) ))
#define BFR_GPIO_PADREGF_PAD22FNCSEL()          ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_PAD22FNCSEL))>>(BFP_GPIO_PADREGF_PAD22FNCSEL))

#define BFP_GPIO_PADREGF_PAD22STRNG             (18)                    /* bitfield lsb */
#define BFM_GPIO_PADREGF_PAD22STRNG             ((uint32_t)0x00040000)  /* bitfield mask */
#define BFN_GPIO_PADREGF_PAD22STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGF_PAD22STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_PAD22STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGF_PAD22STRNG)) & (BFM_GPIO_PADREGF_PAD22STRNG))
#define BFX_GPIO_PADREGF_PAD22STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGF_PAD22STRNG)) >> (BFP_GPIO_PADREGF_PAD22STRNG))
#define BFW_GPIO_PADREGF_PAD22STRNG(v)          (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_PAD22STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_PAD22STRNG)) & (BFM_GPIO_PADREGF_PAD22STRNG)) ))
#define BFR_GPIO_PADREGF_PAD22STRNG()           ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_PAD22STRNG))>>(BFP_GPIO_PADREGF_PAD22STRNG))

#define BFP_GPIO_PADREGF_PAD22INPEN             (17)                    /* bitfield lsb */
#define BFM_GPIO_PADREGF_PAD22INPEN             ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_PADREGF_PAD22INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGF_PAD22INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_PAD22INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGF_PAD22INPEN)) & (BFM_GPIO_PADREGF_PAD22INPEN))
#define BFX_GPIO_PADREGF_PAD22INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGF_PAD22INPEN)) >> (BFP_GPIO_PADREGF_PAD22INPEN))
#define BFW_GPIO_PADREGF_PAD22INPEN(v)          (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_PAD22INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_PAD22INPEN)) & (BFM_GPIO_PADREGF_PAD22INPEN)) ))
#define BFR_GPIO_PADREGF_PAD22INPEN()           ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_PAD22INPEN))>>(BFP_GPIO_PADREGF_PAD22INPEN))

#define BFP_GPIO_PADREGF_PAD22PULL              (16)                    /* bitfield lsb */
#define BFM_GPIO_PADREGF_PAD22PULL              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_PADREGF_PAD22PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGF_PAD22PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_PAD22PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGF_PAD22PULL)) & (BFM_GPIO_PADREGF_PAD22PULL))
#define BFX_GPIO_PADREGF_PAD22PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGF_PAD22PULL)) >> (BFP_GPIO_PADREGF_PAD22PULL))
#define BFW_GPIO_PADREGF_PAD22PULL(v)           (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_PAD22PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_PAD22PULL)) & (BFM_GPIO_PADREGF_PAD22PULL)) ))
#define BFR_GPIO_PADREGF_PAD22PULL()            ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_PAD22PULL))>>(BFP_GPIO_PADREGF_PAD22PULL))

#define BFP_GPIO_PADREGF_RSVD_13                (13)                    /* bitfield lsb */
#define BFM_GPIO_PADREGF_RSVD_13                ((uint32_t)0x0000e000)  /* bitfield mask */
#define BFN_GPIO_PADREGF_RSVD_13                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGF_RSVD_13                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_RSVD_13(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGF_RSVD_13)) & (BFM_GPIO_PADREGF_RSVD_13))
#define BFX_GPIO_PADREGF_RSVD_13(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGF_RSVD_13)) >> (BFP_GPIO_PADREGF_RSVD_13))
#define BFW_GPIO_PADREGF_RSVD_13(v)             (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_RSVD_13)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_RSVD_13)) & (BFM_GPIO_PADREGF_RSVD_13)) ))
#define BFR_GPIO_PADREGF_RSVD_13()              ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_RSVD_13))>>(BFP_GPIO_PADREGF_RSVD_13))

#define BFP_GPIO_PADREGF_PAD21FNCSEL            (11)                    /* bitfield lsb */
#define BFM_GPIO_PADREGF_PAD21FNCSEL            ((uint32_t)0x00001800)  /* bitfield mask */
#define BFN_GPIO_PADREGF_PAD21FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGF_PAD21FNCSEL            (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_PAD21FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGF_PAD21FNCSEL)) & (BFM_GPIO_PADREGF_PAD21FNCSEL))
#define BFX_GPIO_PADREGF_PAD21FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGF_PAD21FNCSEL)) >> (BFP_GPIO_PADREGF_PAD21FNCSEL))
#define BFW_GPIO_PADREGF_PAD21FNCSEL(v)         (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_PAD21FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_PAD21FNCSEL)) & (BFM_GPIO_PADREGF_PAD21FNCSEL)) ))
#define BFR_GPIO_PADREGF_PAD21FNCSEL()          ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_PAD21FNCSEL))>>(BFP_GPIO_PADREGF_PAD21FNCSEL))

#define BFP_GPIO_PADREGF_PAD21STRNG             (10)                    /* bitfield lsb */
#define BFM_GPIO_PADREGF_PAD21STRNG             ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_PADREGF_PAD21STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGF_PAD21STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_PAD21STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGF_PAD21STRNG)) & (BFM_GPIO_PADREGF_PAD21STRNG))
#define BFX_GPIO_PADREGF_PAD21STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGF_PAD21STRNG)) >> (BFP_GPIO_PADREGF_PAD21STRNG))
#define BFW_GPIO_PADREGF_PAD21STRNG(v)          (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_PAD21STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_PAD21STRNG)) & (BFM_GPIO_PADREGF_PAD21STRNG)) ))
#define BFR_GPIO_PADREGF_PAD21STRNG()           ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_PAD21STRNG))>>(BFP_GPIO_PADREGF_PAD21STRNG))

#define BFP_GPIO_PADREGF_PAD21INPEN             (9)                     /* bitfield lsb */
#define BFM_GPIO_PADREGF_PAD21INPEN             ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_PADREGF_PAD21INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGF_PAD21INPEN             (0x1)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_PAD21INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGF_PAD21INPEN)) & (BFM_GPIO_PADREGF_PAD21INPEN))
#define BFX_GPIO_PADREGF_PAD21INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGF_PAD21INPEN)) >> (BFP_GPIO_PADREGF_PAD21INPEN))
#define BFW_GPIO_PADREGF_PAD21INPEN(v)          (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_PAD21INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_PAD21INPEN)) & (BFM_GPIO_PADREGF_PAD21INPEN)) ))
#define BFR_GPIO_PADREGF_PAD21INPEN()           ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_PAD21INPEN))>>(BFP_GPIO_PADREGF_PAD21INPEN))

#define BFP_GPIO_PADREGF_PAD21PULL              (8)                     /* bitfield lsb */
#define BFM_GPIO_PADREGF_PAD21PULL              ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_PADREGF_PAD21PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGF_PAD21PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_PAD21PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGF_PAD21PULL)) & (BFM_GPIO_PADREGF_PAD21PULL))
#define BFX_GPIO_PADREGF_PAD21PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGF_PAD21PULL)) >> (BFP_GPIO_PADREGF_PAD21PULL))
#define BFW_GPIO_PADREGF_PAD21PULL(v)           (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_PAD21PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_PAD21PULL)) & (BFM_GPIO_PADREGF_PAD21PULL)) ))
#define BFR_GPIO_PADREGF_PAD21PULL()            ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_PAD21PULL))>>(BFP_GPIO_PADREGF_PAD21PULL))

#define BFP_GPIO_PADREGF_RSVD_5                 (5)                     /* bitfield lsb */
#define BFM_GPIO_PADREGF_RSVD_5                 ((uint32_t)0x000000e0)  /* bitfield mask */
#define BFN_GPIO_PADREGF_RSVD_5                 (3)                     /* bitfield width */
#define BFD_GPIO_PADREGF_RSVD_5                 (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_RSVD_5(v)              ((((uint32_t) v) << (BFP_GPIO_PADREGF_RSVD_5)) & (BFM_GPIO_PADREGF_RSVD_5))
#define BFX_GPIO_PADREGF_RSVD_5(v)              ((((uint32_t) v) & (BFM_GPIO_PADREGF_RSVD_5)) >> (BFP_GPIO_PADREGF_RSVD_5))
#define BFW_GPIO_PADREGF_RSVD_5(v)              (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_RSVD_5)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_RSVD_5)) & (BFM_GPIO_PADREGF_RSVD_5)) ))
#define BFR_GPIO_PADREGF_RSVD_5()               ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_RSVD_5))>>(BFP_GPIO_PADREGF_RSVD_5))

#define BFP_GPIO_PADREGF_PAD20FNCSEL            (3)                     /* bitfield lsb */
#define BFM_GPIO_PADREGF_PAD20FNCSEL            ((uint32_t)0x00000018)  /* bitfield mask */
#define BFN_GPIO_PADREGF_PAD20FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGF_PAD20FNCSEL            (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_PAD20FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGF_PAD20FNCSEL)) & (BFM_GPIO_PADREGF_PAD20FNCSEL))
#define BFX_GPIO_PADREGF_PAD20FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGF_PAD20FNCSEL)) >> (BFP_GPIO_PADREGF_PAD20FNCSEL))
#define BFW_GPIO_PADREGF_PAD20FNCSEL(v)         (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_PAD20FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_PAD20FNCSEL)) & (BFM_GPIO_PADREGF_PAD20FNCSEL)) ))
#define BFR_GPIO_PADREGF_PAD20FNCSEL()          ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_PAD20FNCSEL))>>(BFP_GPIO_PADREGF_PAD20FNCSEL))

#define BFP_GPIO_PADREGF_PAD20STRNG             (2)                     /* bitfield lsb */
#define BFM_GPIO_PADREGF_PAD20STRNG             ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_PADREGF_PAD20STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGF_PAD20STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_PAD20STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGF_PAD20STRNG)) & (BFM_GPIO_PADREGF_PAD20STRNG))
#define BFX_GPIO_PADREGF_PAD20STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGF_PAD20STRNG)) >> (BFP_GPIO_PADREGF_PAD20STRNG))
#define BFW_GPIO_PADREGF_PAD20STRNG(v)          (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_PAD20STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_PAD20STRNG)) & (BFM_GPIO_PADREGF_PAD20STRNG)) ))
#define BFR_GPIO_PADREGF_PAD20STRNG()           ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_PAD20STRNG))>>(BFP_GPIO_PADREGF_PAD20STRNG))

#define BFP_GPIO_PADREGF_PAD20INPEN             (1)                     /* bitfield lsb */
#define BFM_GPIO_PADREGF_PAD20INPEN             ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_PADREGF_PAD20INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGF_PAD20INPEN             (0x1)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_PAD20INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGF_PAD20INPEN)) & (BFM_GPIO_PADREGF_PAD20INPEN))
#define BFX_GPIO_PADREGF_PAD20INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGF_PAD20INPEN)) >> (BFP_GPIO_PADREGF_PAD20INPEN))
#define BFW_GPIO_PADREGF_PAD20INPEN(v)          (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_PAD20INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_PAD20INPEN)) & (BFM_GPIO_PADREGF_PAD20INPEN)) ))
#define BFR_GPIO_PADREGF_PAD20INPEN()           ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_PAD20INPEN))>>(BFP_GPIO_PADREGF_PAD20INPEN))

#define BFP_GPIO_PADREGF_PAD20PULL              (0)                     /* bitfield lsb */
#define BFM_GPIO_PADREGF_PAD20PULL              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_PADREGF_PAD20PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGF_PAD20PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGF_PAD20PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGF_PAD20PULL)) & (BFM_GPIO_PADREGF_PAD20PULL))
#define BFX_GPIO_PADREGF_PAD20PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGF_PAD20PULL)) >> (BFP_GPIO_PADREGF_PAD20PULL))
#define BFW_GPIO_PADREGF_PAD20PULL(v)           (REG_GPIO_PADREGF.U32 = ( (REG_GPIO_PADREGF.U32 & ~(BFM_GPIO_PADREGF_PAD20PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGF_PAD20PULL)) & (BFM_GPIO_PADREGF_PAD20PULL)) ))
#define BFR_GPIO_PADREGF_PAD20PULL()            ((REG_GPIO_PADREGF.U32 & (BFM_GPIO_PADREGF_PAD20PULL))>>(BFP_GPIO_PADREGF_PAD20PULL))


// *****************************************************************************
//                                                                             *
//  GPIO_PADREGG - Pad Configuration Register G                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_29                    :  3;
        unsigned PAD27FNCSEL                :  2;
        unsigned PAD27STRNG                 :  1;
        unsigned PAD27INPEN                 :  1;
        unsigned PAD27PULL                  :  1;
        unsigned RSVD_21                    :  3;
        unsigned PAD26FNCSEL                :  2;
        unsigned PAD26STRNG                 :  1;
        unsigned PAD26INPEN                 :  1;
        unsigned PAD26PULL                  :  1;
        unsigned RSVD_13                    :  3;
        unsigned PAD25FNCSEL                :  2;
        unsigned PAD25STRNG                 :  1;
        unsigned PAD25INPEN                 :  1;
        unsigned PAD25PULL                  :  1;
        unsigned RSVD_5                     :  3;
        unsigned PAD24FNCSEL                :  2;
        unsigned PAD24STRNG                 :  1;
        unsigned PAD24INPEN                 :  1;
        unsigned PAD24PULL                  :  1;
    } B;
} reg_gpio_padregg_t;

#define REG_GPIO_PADREGG_ADDR                   (REG_GPIO_BASEADDR + 0x00000018UL)
#define REG_GPIO_PADREGG                        (*(volatile reg_gpio_padregg_t *) REG_GPIO_PADREGG_ADDR)
#define REG_GPIO_PADREGG_RD()                   (REG_GPIO_PADREGG.U32)
#define REG_GPIO_PADREGG_WR(v)                  (REG_GPIO_PADREGG.U32 = (v))
#define REG_GPIO_PADREGG_CLR(m)                 (REG_GPIO_PADREGG.U32 = ((REG_GPIO_PADREGG.U32) & ~(m)))
#define REG_GPIO_PADREGG_SET(m)                 (REG_GPIO_PADREGG.U32 = ((REG_GPIO_PADREGG.U32) | (m)))
#define REG_GPIO_PADREGG_DEF                    0x18181818

#define BFP_GPIO_PADREGG_RSVD_29                (29)                    /* bitfield lsb */
#define BFM_GPIO_PADREGG_RSVD_29                ((uint32_t)0xe0000000)  /* bitfield mask */
#define BFN_GPIO_PADREGG_RSVD_29                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGG_RSVD_29                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_RSVD_29(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGG_RSVD_29)) & (BFM_GPIO_PADREGG_RSVD_29))
#define BFX_GPIO_PADREGG_RSVD_29(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGG_RSVD_29)) >> (BFP_GPIO_PADREGG_RSVD_29))
#define BFW_GPIO_PADREGG_RSVD_29(v)             (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_RSVD_29)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_RSVD_29)) & (BFM_GPIO_PADREGG_RSVD_29)) ))
#define BFR_GPIO_PADREGG_RSVD_29()              ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_RSVD_29))>>(BFP_GPIO_PADREGG_RSVD_29))

#define BFP_GPIO_PADREGG_PAD27FNCSEL            (27)                    /* bitfield lsb */
#define BFM_GPIO_PADREGG_PAD27FNCSEL            ((uint32_t)0x18000000)  /* bitfield mask */
#define BFN_GPIO_PADREGG_PAD27FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGG_PAD27FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_PAD27FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGG_PAD27FNCSEL)) & (BFM_GPIO_PADREGG_PAD27FNCSEL))
#define BFX_GPIO_PADREGG_PAD27FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGG_PAD27FNCSEL)) >> (BFP_GPIO_PADREGG_PAD27FNCSEL))
#define BFW_GPIO_PADREGG_PAD27FNCSEL(v)         (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_PAD27FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_PAD27FNCSEL)) & (BFM_GPIO_PADREGG_PAD27FNCSEL)) ))
#define BFR_GPIO_PADREGG_PAD27FNCSEL()          ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_PAD27FNCSEL))>>(BFP_GPIO_PADREGG_PAD27FNCSEL))

#define BFP_GPIO_PADREGG_PAD27STRNG             (26)                    /* bitfield lsb */
#define BFM_GPIO_PADREGG_PAD27STRNG             ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_GPIO_PADREGG_PAD27STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGG_PAD27STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_PAD27STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGG_PAD27STRNG)) & (BFM_GPIO_PADREGG_PAD27STRNG))
#define BFX_GPIO_PADREGG_PAD27STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGG_PAD27STRNG)) >> (BFP_GPIO_PADREGG_PAD27STRNG))
#define BFW_GPIO_PADREGG_PAD27STRNG(v)          (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_PAD27STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_PAD27STRNG)) & (BFM_GPIO_PADREGG_PAD27STRNG)) ))
#define BFR_GPIO_PADREGG_PAD27STRNG()           ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_PAD27STRNG))>>(BFP_GPIO_PADREGG_PAD27STRNG))

#define BFP_GPIO_PADREGG_PAD27INPEN             (25)                    /* bitfield lsb */
#define BFM_GPIO_PADREGG_PAD27INPEN             ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_GPIO_PADREGG_PAD27INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGG_PAD27INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_PAD27INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGG_PAD27INPEN)) & (BFM_GPIO_PADREGG_PAD27INPEN))
#define BFX_GPIO_PADREGG_PAD27INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGG_PAD27INPEN)) >> (BFP_GPIO_PADREGG_PAD27INPEN))
#define BFW_GPIO_PADREGG_PAD27INPEN(v)          (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_PAD27INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_PAD27INPEN)) & (BFM_GPIO_PADREGG_PAD27INPEN)) ))
#define BFR_GPIO_PADREGG_PAD27INPEN()           ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_PAD27INPEN))>>(BFP_GPIO_PADREGG_PAD27INPEN))

#define BFP_GPIO_PADREGG_PAD27PULL              (24)                    /* bitfield lsb */
#define BFM_GPIO_PADREGG_PAD27PULL              ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_PADREGG_PAD27PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGG_PAD27PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_PAD27PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGG_PAD27PULL)) & (BFM_GPIO_PADREGG_PAD27PULL))
#define BFX_GPIO_PADREGG_PAD27PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGG_PAD27PULL)) >> (BFP_GPIO_PADREGG_PAD27PULL))
#define BFW_GPIO_PADREGG_PAD27PULL(v)           (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_PAD27PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_PAD27PULL)) & (BFM_GPIO_PADREGG_PAD27PULL)) ))
#define BFR_GPIO_PADREGG_PAD27PULL()            ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_PAD27PULL))>>(BFP_GPIO_PADREGG_PAD27PULL))

#define BFP_GPIO_PADREGG_RSVD_21                (21)                    /* bitfield lsb */
#define BFM_GPIO_PADREGG_RSVD_21                ((uint32_t)0x00e00000)  /* bitfield mask */
#define BFN_GPIO_PADREGG_RSVD_21                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGG_RSVD_21                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_RSVD_21(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGG_RSVD_21)) & (BFM_GPIO_PADREGG_RSVD_21))
#define BFX_GPIO_PADREGG_RSVD_21(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGG_RSVD_21)) >> (BFP_GPIO_PADREGG_RSVD_21))
#define BFW_GPIO_PADREGG_RSVD_21(v)             (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_RSVD_21)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_RSVD_21)) & (BFM_GPIO_PADREGG_RSVD_21)) ))
#define BFR_GPIO_PADREGG_RSVD_21()              ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_RSVD_21))>>(BFP_GPIO_PADREGG_RSVD_21))

#define BFP_GPIO_PADREGG_PAD26FNCSEL            (19)                    /* bitfield lsb */
#define BFM_GPIO_PADREGG_PAD26FNCSEL            ((uint32_t)0x00180000)  /* bitfield mask */
#define BFN_GPIO_PADREGG_PAD26FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGG_PAD26FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_PAD26FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGG_PAD26FNCSEL)) & (BFM_GPIO_PADREGG_PAD26FNCSEL))
#define BFX_GPIO_PADREGG_PAD26FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGG_PAD26FNCSEL)) >> (BFP_GPIO_PADREGG_PAD26FNCSEL))
#define BFW_GPIO_PADREGG_PAD26FNCSEL(v)         (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_PAD26FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_PAD26FNCSEL)) & (BFM_GPIO_PADREGG_PAD26FNCSEL)) ))
#define BFR_GPIO_PADREGG_PAD26FNCSEL()          ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_PAD26FNCSEL))>>(BFP_GPIO_PADREGG_PAD26FNCSEL))

#define BFP_GPIO_PADREGG_PAD26STRNG             (18)                    /* bitfield lsb */
#define BFM_GPIO_PADREGG_PAD26STRNG             ((uint32_t)0x00040000)  /* bitfield mask */
#define BFN_GPIO_PADREGG_PAD26STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGG_PAD26STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_PAD26STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGG_PAD26STRNG)) & (BFM_GPIO_PADREGG_PAD26STRNG))
#define BFX_GPIO_PADREGG_PAD26STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGG_PAD26STRNG)) >> (BFP_GPIO_PADREGG_PAD26STRNG))
#define BFW_GPIO_PADREGG_PAD26STRNG(v)          (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_PAD26STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_PAD26STRNG)) & (BFM_GPIO_PADREGG_PAD26STRNG)) ))
#define BFR_GPIO_PADREGG_PAD26STRNG()           ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_PAD26STRNG))>>(BFP_GPIO_PADREGG_PAD26STRNG))

#define BFP_GPIO_PADREGG_PAD26INPEN             (17)                    /* bitfield lsb */
#define BFM_GPIO_PADREGG_PAD26INPEN             ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_PADREGG_PAD26INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGG_PAD26INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_PAD26INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGG_PAD26INPEN)) & (BFM_GPIO_PADREGG_PAD26INPEN))
#define BFX_GPIO_PADREGG_PAD26INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGG_PAD26INPEN)) >> (BFP_GPIO_PADREGG_PAD26INPEN))
#define BFW_GPIO_PADREGG_PAD26INPEN(v)          (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_PAD26INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_PAD26INPEN)) & (BFM_GPIO_PADREGG_PAD26INPEN)) ))
#define BFR_GPIO_PADREGG_PAD26INPEN()           ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_PAD26INPEN))>>(BFP_GPIO_PADREGG_PAD26INPEN))

#define BFP_GPIO_PADREGG_PAD26PULL              (16)                    /* bitfield lsb */
#define BFM_GPIO_PADREGG_PAD26PULL              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_PADREGG_PAD26PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGG_PAD26PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_PAD26PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGG_PAD26PULL)) & (BFM_GPIO_PADREGG_PAD26PULL))
#define BFX_GPIO_PADREGG_PAD26PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGG_PAD26PULL)) >> (BFP_GPIO_PADREGG_PAD26PULL))
#define BFW_GPIO_PADREGG_PAD26PULL(v)           (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_PAD26PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_PAD26PULL)) & (BFM_GPIO_PADREGG_PAD26PULL)) ))
#define BFR_GPIO_PADREGG_PAD26PULL()            ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_PAD26PULL))>>(BFP_GPIO_PADREGG_PAD26PULL))

#define BFP_GPIO_PADREGG_RSVD_13                (13)                    /* bitfield lsb */
#define BFM_GPIO_PADREGG_RSVD_13                ((uint32_t)0x0000e000)  /* bitfield mask */
#define BFN_GPIO_PADREGG_RSVD_13                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGG_RSVD_13                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_RSVD_13(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGG_RSVD_13)) & (BFM_GPIO_PADREGG_RSVD_13))
#define BFX_GPIO_PADREGG_RSVD_13(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGG_RSVD_13)) >> (BFP_GPIO_PADREGG_RSVD_13))
#define BFW_GPIO_PADREGG_RSVD_13(v)             (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_RSVD_13)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_RSVD_13)) & (BFM_GPIO_PADREGG_RSVD_13)) ))
#define BFR_GPIO_PADREGG_RSVD_13()              ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_RSVD_13))>>(BFP_GPIO_PADREGG_RSVD_13))

#define BFP_GPIO_PADREGG_PAD25FNCSEL            (11)                    /* bitfield lsb */
#define BFM_GPIO_PADREGG_PAD25FNCSEL            ((uint32_t)0x00001800)  /* bitfield mask */
#define BFN_GPIO_PADREGG_PAD25FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGG_PAD25FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_PAD25FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGG_PAD25FNCSEL)) & (BFM_GPIO_PADREGG_PAD25FNCSEL))
#define BFX_GPIO_PADREGG_PAD25FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGG_PAD25FNCSEL)) >> (BFP_GPIO_PADREGG_PAD25FNCSEL))
#define BFW_GPIO_PADREGG_PAD25FNCSEL(v)         (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_PAD25FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_PAD25FNCSEL)) & (BFM_GPIO_PADREGG_PAD25FNCSEL)) ))
#define BFR_GPIO_PADREGG_PAD25FNCSEL()          ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_PAD25FNCSEL))>>(BFP_GPIO_PADREGG_PAD25FNCSEL))

#define BFP_GPIO_PADREGG_PAD25STRNG             (10)                    /* bitfield lsb */
#define BFM_GPIO_PADREGG_PAD25STRNG             ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_PADREGG_PAD25STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGG_PAD25STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_PAD25STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGG_PAD25STRNG)) & (BFM_GPIO_PADREGG_PAD25STRNG))
#define BFX_GPIO_PADREGG_PAD25STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGG_PAD25STRNG)) >> (BFP_GPIO_PADREGG_PAD25STRNG))
#define BFW_GPIO_PADREGG_PAD25STRNG(v)          (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_PAD25STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_PAD25STRNG)) & (BFM_GPIO_PADREGG_PAD25STRNG)) ))
#define BFR_GPIO_PADREGG_PAD25STRNG()           ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_PAD25STRNG))>>(BFP_GPIO_PADREGG_PAD25STRNG))

#define BFP_GPIO_PADREGG_PAD25INPEN             (9)                     /* bitfield lsb */
#define BFM_GPIO_PADREGG_PAD25INPEN             ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_PADREGG_PAD25INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGG_PAD25INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_PAD25INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGG_PAD25INPEN)) & (BFM_GPIO_PADREGG_PAD25INPEN))
#define BFX_GPIO_PADREGG_PAD25INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGG_PAD25INPEN)) >> (BFP_GPIO_PADREGG_PAD25INPEN))
#define BFW_GPIO_PADREGG_PAD25INPEN(v)          (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_PAD25INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_PAD25INPEN)) & (BFM_GPIO_PADREGG_PAD25INPEN)) ))
#define BFR_GPIO_PADREGG_PAD25INPEN()           ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_PAD25INPEN))>>(BFP_GPIO_PADREGG_PAD25INPEN))

#define BFP_GPIO_PADREGG_PAD25PULL              (8)                     /* bitfield lsb */
#define BFM_GPIO_PADREGG_PAD25PULL              ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_PADREGG_PAD25PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGG_PAD25PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_PAD25PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGG_PAD25PULL)) & (BFM_GPIO_PADREGG_PAD25PULL))
#define BFX_GPIO_PADREGG_PAD25PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGG_PAD25PULL)) >> (BFP_GPIO_PADREGG_PAD25PULL))
#define BFW_GPIO_PADREGG_PAD25PULL(v)           (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_PAD25PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_PAD25PULL)) & (BFM_GPIO_PADREGG_PAD25PULL)) ))
#define BFR_GPIO_PADREGG_PAD25PULL()            ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_PAD25PULL))>>(BFP_GPIO_PADREGG_PAD25PULL))

#define BFP_GPIO_PADREGG_RSVD_5                 (5)                     /* bitfield lsb */
#define BFM_GPIO_PADREGG_RSVD_5                 ((uint32_t)0x000000e0)  /* bitfield mask */
#define BFN_GPIO_PADREGG_RSVD_5                 (3)                     /* bitfield width */
#define BFD_GPIO_PADREGG_RSVD_5                 (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_RSVD_5(v)              ((((uint32_t) v) << (BFP_GPIO_PADREGG_RSVD_5)) & (BFM_GPIO_PADREGG_RSVD_5))
#define BFX_GPIO_PADREGG_RSVD_5(v)              ((((uint32_t) v) & (BFM_GPIO_PADREGG_RSVD_5)) >> (BFP_GPIO_PADREGG_RSVD_5))
#define BFW_GPIO_PADREGG_RSVD_5(v)              (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_RSVD_5)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_RSVD_5)) & (BFM_GPIO_PADREGG_RSVD_5)) ))
#define BFR_GPIO_PADREGG_RSVD_5()               ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_RSVD_5))>>(BFP_GPIO_PADREGG_RSVD_5))

#define BFP_GPIO_PADREGG_PAD24FNCSEL            (3)                     /* bitfield lsb */
#define BFM_GPIO_PADREGG_PAD24FNCSEL            ((uint32_t)0x00000018)  /* bitfield mask */
#define BFN_GPIO_PADREGG_PAD24FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGG_PAD24FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_PAD24FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGG_PAD24FNCSEL)) & (BFM_GPIO_PADREGG_PAD24FNCSEL))
#define BFX_GPIO_PADREGG_PAD24FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGG_PAD24FNCSEL)) >> (BFP_GPIO_PADREGG_PAD24FNCSEL))
#define BFW_GPIO_PADREGG_PAD24FNCSEL(v)         (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_PAD24FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_PAD24FNCSEL)) & (BFM_GPIO_PADREGG_PAD24FNCSEL)) ))
#define BFR_GPIO_PADREGG_PAD24FNCSEL()          ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_PAD24FNCSEL))>>(BFP_GPIO_PADREGG_PAD24FNCSEL))

#define BFP_GPIO_PADREGG_PAD24STRNG             (2)                     /* bitfield lsb */
#define BFM_GPIO_PADREGG_PAD24STRNG             ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_PADREGG_PAD24STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGG_PAD24STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_PAD24STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGG_PAD24STRNG)) & (BFM_GPIO_PADREGG_PAD24STRNG))
#define BFX_GPIO_PADREGG_PAD24STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGG_PAD24STRNG)) >> (BFP_GPIO_PADREGG_PAD24STRNG))
#define BFW_GPIO_PADREGG_PAD24STRNG(v)          (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_PAD24STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_PAD24STRNG)) & (BFM_GPIO_PADREGG_PAD24STRNG)) ))
#define BFR_GPIO_PADREGG_PAD24STRNG()           ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_PAD24STRNG))>>(BFP_GPIO_PADREGG_PAD24STRNG))

#define BFP_GPIO_PADREGG_PAD24INPEN             (1)                     /* bitfield lsb */
#define BFM_GPIO_PADREGG_PAD24INPEN             ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_PADREGG_PAD24INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGG_PAD24INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_PAD24INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGG_PAD24INPEN)) & (BFM_GPIO_PADREGG_PAD24INPEN))
#define BFX_GPIO_PADREGG_PAD24INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGG_PAD24INPEN)) >> (BFP_GPIO_PADREGG_PAD24INPEN))
#define BFW_GPIO_PADREGG_PAD24INPEN(v)          (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_PAD24INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_PAD24INPEN)) & (BFM_GPIO_PADREGG_PAD24INPEN)) ))
#define BFR_GPIO_PADREGG_PAD24INPEN()           ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_PAD24INPEN))>>(BFP_GPIO_PADREGG_PAD24INPEN))

#define BFP_GPIO_PADREGG_PAD24PULL              (0)                     /* bitfield lsb */
#define BFM_GPIO_PADREGG_PAD24PULL              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_PADREGG_PAD24PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGG_PAD24PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGG_PAD24PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGG_PAD24PULL)) & (BFM_GPIO_PADREGG_PAD24PULL))
#define BFX_GPIO_PADREGG_PAD24PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGG_PAD24PULL)) >> (BFP_GPIO_PADREGG_PAD24PULL))
#define BFW_GPIO_PADREGG_PAD24PULL(v)           (REG_GPIO_PADREGG.U32 = ( (REG_GPIO_PADREGG.U32 & ~(BFM_GPIO_PADREGG_PAD24PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGG_PAD24PULL)) & (BFM_GPIO_PADREGG_PAD24PULL)) ))
#define BFR_GPIO_PADREGG_PAD24PULL()            ((REG_GPIO_PADREGG.U32 & (BFM_GPIO_PADREGG_PAD24PULL))>>(BFP_GPIO_PADREGG_PAD24PULL))


// *****************************************************************************
//                                                                             *
//  GPIO_PADREGH - Pad Configuration Register H                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_29                    :  3;
        unsigned PAD31FNCSEL                :  2;
        unsigned PAD31STRNG                 :  1;
        unsigned PAD31INPEN                 :  1;
        unsigned PAD31PULL                  :  1;
        unsigned RSVD_21                    :  3;
        unsigned PAD30FNCSEL                :  2;
        unsigned PAD30STRNG                 :  1;
        unsigned PAD30INPEN                 :  1;
        unsigned PAD30PULL                  :  1;
        unsigned RSVD_13                    :  3;
        unsigned PAD29FNCSEL                :  2;
        unsigned PAD29STRNG                 :  1;
        unsigned PAD29INPEN                 :  1;
        unsigned PAD29PULL                  :  1;
        unsigned RSVD_5                     :  3;
        unsigned PAD28FNCSEL                :  2;
        unsigned PAD28STRNG                 :  1;
        unsigned PAD28INPEN                 :  1;
        unsigned PAD28PULL                  :  1;
    } B;
} reg_gpio_padregh_t;

#define REG_GPIO_PADREGH_ADDR                   (REG_GPIO_BASEADDR + 0x0000001CUL)
#define REG_GPIO_PADREGH                        (*(volatile reg_gpio_padregh_t *) REG_GPIO_PADREGH_ADDR)
#define REG_GPIO_PADREGH_RD()                   (REG_GPIO_PADREGH.U32)
#define REG_GPIO_PADREGH_WR(v)                  (REG_GPIO_PADREGH.U32 = (v))
#define REG_GPIO_PADREGH_CLR(m)                 (REG_GPIO_PADREGH.U32 = ((REG_GPIO_PADREGH.U32) & ~(m)))
#define REG_GPIO_PADREGH_SET(m)                 (REG_GPIO_PADREGH.U32 = ((REG_GPIO_PADREGH.U32) | (m)))
#define REG_GPIO_PADREGH_DEF                    0x18181818

#define BFP_GPIO_PADREGH_RSVD_29                (29)                    /* bitfield lsb */
#define BFM_GPIO_PADREGH_RSVD_29                ((uint32_t)0xe0000000)  /* bitfield mask */
#define BFN_GPIO_PADREGH_RSVD_29                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGH_RSVD_29                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_RSVD_29(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGH_RSVD_29)) & (BFM_GPIO_PADREGH_RSVD_29))
#define BFX_GPIO_PADREGH_RSVD_29(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGH_RSVD_29)) >> (BFP_GPIO_PADREGH_RSVD_29))
#define BFW_GPIO_PADREGH_RSVD_29(v)             (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_RSVD_29)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_RSVD_29)) & (BFM_GPIO_PADREGH_RSVD_29)) ))
#define BFR_GPIO_PADREGH_RSVD_29()              ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_RSVD_29))>>(BFP_GPIO_PADREGH_RSVD_29))

#define BFP_GPIO_PADREGH_PAD31FNCSEL            (27)                    /* bitfield lsb */
#define BFM_GPIO_PADREGH_PAD31FNCSEL            ((uint32_t)0x18000000)  /* bitfield mask */
#define BFN_GPIO_PADREGH_PAD31FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGH_PAD31FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_PAD31FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGH_PAD31FNCSEL)) & (BFM_GPIO_PADREGH_PAD31FNCSEL))
#define BFX_GPIO_PADREGH_PAD31FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGH_PAD31FNCSEL)) >> (BFP_GPIO_PADREGH_PAD31FNCSEL))
#define BFW_GPIO_PADREGH_PAD31FNCSEL(v)         (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_PAD31FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_PAD31FNCSEL)) & (BFM_GPIO_PADREGH_PAD31FNCSEL)) ))
#define BFR_GPIO_PADREGH_PAD31FNCSEL()          ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_PAD31FNCSEL))>>(BFP_GPIO_PADREGH_PAD31FNCSEL))

#define BFP_GPIO_PADREGH_PAD31STRNG             (26)                    /* bitfield lsb */
#define BFM_GPIO_PADREGH_PAD31STRNG             ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_GPIO_PADREGH_PAD31STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGH_PAD31STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_PAD31STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGH_PAD31STRNG)) & (BFM_GPIO_PADREGH_PAD31STRNG))
#define BFX_GPIO_PADREGH_PAD31STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGH_PAD31STRNG)) >> (BFP_GPIO_PADREGH_PAD31STRNG))
#define BFW_GPIO_PADREGH_PAD31STRNG(v)          (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_PAD31STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_PAD31STRNG)) & (BFM_GPIO_PADREGH_PAD31STRNG)) ))
#define BFR_GPIO_PADREGH_PAD31STRNG()           ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_PAD31STRNG))>>(BFP_GPIO_PADREGH_PAD31STRNG))

#define BFP_GPIO_PADREGH_PAD31INPEN             (25)                    /* bitfield lsb */
#define BFM_GPIO_PADREGH_PAD31INPEN             ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_GPIO_PADREGH_PAD31INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGH_PAD31INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_PAD31INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGH_PAD31INPEN)) & (BFM_GPIO_PADREGH_PAD31INPEN))
#define BFX_GPIO_PADREGH_PAD31INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGH_PAD31INPEN)) >> (BFP_GPIO_PADREGH_PAD31INPEN))
#define BFW_GPIO_PADREGH_PAD31INPEN(v)          (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_PAD31INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_PAD31INPEN)) & (BFM_GPIO_PADREGH_PAD31INPEN)) ))
#define BFR_GPIO_PADREGH_PAD31INPEN()           ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_PAD31INPEN))>>(BFP_GPIO_PADREGH_PAD31INPEN))

#define BFP_GPIO_PADREGH_PAD31PULL              (24)                    /* bitfield lsb */
#define BFM_GPIO_PADREGH_PAD31PULL              ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_PADREGH_PAD31PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGH_PAD31PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_PAD31PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGH_PAD31PULL)) & (BFM_GPIO_PADREGH_PAD31PULL))
#define BFX_GPIO_PADREGH_PAD31PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGH_PAD31PULL)) >> (BFP_GPIO_PADREGH_PAD31PULL))
#define BFW_GPIO_PADREGH_PAD31PULL(v)           (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_PAD31PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_PAD31PULL)) & (BFM_GPIO_PADREGH_PAD31PULL)) ))
#define BFR_GPIO_PADREGH_PAD31PULL()            ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_PAD31PULL))>>(BFP_GPIO_PADREGH_PAD31PULL))

#define BFP_GPIO_PADREGH_RSVD_21                (21)                    /* bitfield lsb */
#define BFM_GPIO_PADREGH_RSVD_21                ((uint32_t)0x00e00000)  /* bitfield mask */
#define BFN_GPIO_PADREGH_RSVD_21                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGH_RSVD_21                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_RSVD_21(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGH_RSVD_21)) & (BFM_GPIO_PADREGH_RSVD_21))
#define BFX_GPIO_PADREGH_RSVD_21(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGH_RSVD_21)) >> (BFP_GPIO_PADREGH_RSVD_21))
#define BFW_GPIO_PADREGH_RSVD_21(v)             (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_RSVD_21)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_RSVD_21)) & (BFM_GPIO_PADREGH_RSVD_21)) ))
#define BFR_GPIO_PADREGH_RSVD_21()              ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_RSVD_21))>>(BFP_GPIO_PADREGH_RSVD_21))

#define BFP_GPIO_PADREGH_PAD30FNCSEL            (19)                    /* bitfield lsb */
#define BFM_GPIO_PADREGH_PAD30FNCSEL            ((uint32_t)0x00180000)  /* bitfield mask */
#define BFN_GPIO_PADREGH_PAD30FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGH_PAD30FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_PAD30FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGH_PAD30FNCSEL)) & (BFM_GPIO_PADREGH_PAD30FNCSEL))
#define BFX_GPIO_PADREGH_PAD30FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGH_PAD30FNCSEL)) >> (BFP_GPIO_PADREGH_PAD30FNCSEL))
#define BFW_GPIO_PADREGH_PAD30FNCSEL(v)         (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_PAD30FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_PAD30FNCSEL)) & (BFM_GPIO_PADREGH_PAD30FNCSEL)) ))
#define BFR_GPIO_PADREGH_PAD30FNCSEL()          ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_PAD30FNCSEL))>>(BFP_GPIO_PADREGH_PAD30FNCSEL))

#define BFP_GPIO_PADREGH_PAD30STRNG             (18)                    /* bitfield lsb */
#define BFM_GPIO_PADREGH_PAD30STRNG             ((uint32_t)0x00040000)  /* bitfield mask */
#define BFN_GPIO_PADREGH_PAD30STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGH_PAD30STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_PAD30STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGH_PAD30STRNG)) & (BFM_GPIO_PADREGH_PAD30STRNG))
#define BFX_GPIO_PADREGH_PAD30STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGH_PAD30STRNG)) >> (BFP_GPIO_PADREGH_PAD30STRNG))
#define BFW_GPIO_PADREGH_PAD30STRNG(v)          (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_PAD30STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_PAD30STRNG)) & (BFM_GPIO_PADREGH_PAD30STRNG)) ))
#define BFR_GPIO_PADREGH_PAD30STRNG()           ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_PAD30STRNG))>>(BFP_GPIO_PADREGH_PAD30STRNG))

#define BFP_GPIO_PADREGH_PAD30INPEN             (17)                    /* bitfield lsb */
#define BFM_GPIO_PADREGH_PAD30INPEN             ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_PADREGH_PAD30INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGH_PAD30INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_PAD30INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGH_PAD30INPEN)) & (BFM_GPIO_PADREGH_PAD30INPEN))
#define BFX_GPIO_PADREGH_PAD30INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGH_PAD30INPEN)) >> (BFP_GPIO_PADREGH_PAD30INPEN))
#define BFW_GPIO_PADREGH_PAD30INPEN(v)          (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_PAD30INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_PAD30INPEN)) & (BFM_GPIO_PADREGH_PAD30INPEN)) ))
#define BFR_GPIO_PADREGH_PAD30INPEN()           ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_PAD30INPEN))>>(BFP_GPIO_PADREGH_PAD30INPEN))

#define BFP_GPIO_PADREGH_PAD30PULL              (16)                    /* bitfield lsb */
#define BFM_GPIO_PADREGH_PAD30PULL              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_PADREGH_PAD30PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGH_PAD30PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_PAD30PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGH_PAD30PULL)) & (BFM_GPIO_PADREGH_PAD30PULL))
#define BFX_GPIO_PADREGH_PAD30PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGH_PAD30PULL)) >> (BFP_GPIO_PADREGH_PAD30PULL))
#define BFW_GPIO_PADREGH_PAD30PULL(v)           (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_PAD30PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_PAD30PULL)) & (BFM_GPIO_PADREGH_PAD30PULL)) ))
#define BFR_GPIO_PADREGH_PAD30PULL()            ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_PAD30PULL))>>(BFP_GPIO_PADREGH_PAD30PULL))

#define BFP_GPIO_PADREGH_RSVD_13                (13)                    /* bitfield lsb */
#define BFM_GPIO_PADREGH_RSVD_13                ((uint32_t)0x0000e000)  /* bitfield mask */
#define BFN_GPIO_PADREGH_RSVD_13                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGH_RSVD_13                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_RSVD_13(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGH_RSVD_13)) & (BFM_GPIO_PADREGH_RSVD_13))
#define BFX_GPIO_PADREGH_RSVD_13(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGH_RSVD_13)) >> (BFP_GPIO_PADREGH_RSVD_13))
#define BFW_GPIO_PADREGH_RSVD_13(v)             (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_RSVD_13)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_RSVD_13)) & (BFM_GPIO_PADREGH_RSVD_13)) ))
#define BFR_GPIO_PADREGH_RSVD_13()              ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_RSVD_13))>>(BFP_GPIO_PADREGH_RSVD_13))

#define BFP_GPIO_PADREGH_PAD29FNCSEL            (11)                    /* bitfield lsb */
#define BFM_GPIO_PADREGH_PAD29FNCSEL            ((uint32_t)0x00001800)  /* bitfield mask */
#define BFN_GPIO_PADREGH_PAD29FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGH_PAD29FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_PAD29FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGH_PAD29FNCSEL)) & (BFM_GPIO_PADREGH_PAD29FNCSEL))
#define BFX_GPIO_PADREGH_PAD29FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGH_PAD29FNCSEL)) >> (BFP_GPIO_PADREGH_PAD29FNCSEL))
#define BFW_GPIO_PADREGH_PAD29FNCSEL(v)         (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_PAD29FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_PAD29FNCSEL)) & (BFM_GPIO_PADREGH_PAD29FNCSEL)) ))
#define BFR_GPIO_PADREGH_PAD29FNCSEL()          ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_PAD29FNCSEL))>>(BFP_GPIO_PADREGH_PAD29FNCSEL))

#define BFP_GPIO_PADREGH_PAD29STRNG             (10)                    /* bitfield lsb */
#define BFM_GPIO_PADREGH_PAD29STRNG             ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_PADREGH_PAD29STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGH_PAD29STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_PAD29STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGH_PAD29STRNG)) & (BFM_GPIO_PADREGH_PAD29STRNG))
#define BFX_GPIO_PADREGH_PAD29STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGH_PAD29STRNG)) >> (BFP_GPIO_PADREGH_PAD29STRNG))
#define BFW_GPIO_PADREGH_PAD29STRNG(v)          (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_PAD29STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_PAD29STRNG)) & (BFM_GPIO_PADREGH_PAD29STRNG)) ))
#define BFR_GPIO_PADREGH_PAD29STRNG()           ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_PAD29STRNG))>>(BFP_GPIO_PADREGH_PAD29STRNG))

#define BFP_GPIO_PADREGH_PAD29INPEN             (9)                     /* bitfield lsb */
#define BFM_GPIO_PADREGH_PAD29INPEN             ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_PADREGH_PAD29INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGH_PAD29INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_PAD29INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGH_PAD29INPEN)) & (BFM_GPIO_PADREGH_PAD29INPEN))
#define BFX_GPIO_PADREGH_PAD29INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGH_PAD29INPEN)) >> (BFP_GPIO_PADREGH_PAD29INPEN))
#define BFW_GPIO_PADREGH_PAD29INPEN(v)          (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_PAD29INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_PAD29INPEN)) & (BFM_GPIO_PADREGH_PAD29INPEN)) ))
#define BFR_GPIO_PADREGH_PAD29INPEN()           ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_PAD29INPEN))>>(BFP_GPIO_PADREGH_PAD29INPEN))

#define BFP_GPIO_PADREGH_PAD29PULL              (8)                     /* bitfield lsb */
#define BFM_GPIO_PADREGH_PAD29PULL              ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_PADREGH_PAD29PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGH_PAD29PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_PAD29PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGH_PAD29PULL)) & (BFM_GPIO_PADREGH_PAD29PULL))
#define BFX_GPIO_PADREGH_PAD29PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGH_PAD29PULL)) >> (BFP_GPIO_PADREGH_PAD29PULL))
#define BFW_GPIO_PADREGH_PAD29PULL(v)           (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_PAD29PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_PAD29PULL)) & (BFM_GPIO_PADREGH_PAD29PULL)) ))
#define BFR_GPIO_PADREGH_PAD29PULL()            ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_PAD29PULL))>>(BFP_GPIO_PADREGH_PAD29PULL))

#define BFP_GPIO_PADREGH_RSVD_5                 (5)                     /* bitfield lsb */
#define BFM_GPIO_PADREGH_RSVD_5                 ((uint32_t)0x000000e0)  /* bitfield mask */
#define BFN_GPIO_PADREGH_RSVD_5                 (3)                     /* bitfield width */
#define BFD_GPIO_PADREGH_RSVD_5                 (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_RSVD_5(v)              ((((uint32_t) v) << (BFP_GPIO_PADREGH_RSVD_5)) & (BFM_GPIO_PADREGH_RSVD_5))
#define BFX_GPIO_PADREGH_RSVD_5(v)              ((((uint32_t) v) & (BFM_GPIO_PADREGH_RSVD_5)) >> (BFP_GPIO_PADREGH_RSVD_5))
#define BFW_GPIO_PADREGH_RSVD_5(v)              (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_RSVD_5)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_RSVD_5)) & (BFM_GPIO_PADREGH_RSVD_5)) ))
#define BFR_GPIO_PADREGH_RSVD_5()               ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_RSVD_5))>>(BFP_GPIO_PADREGH_RSVD_5))

#define BFP_GPIO_PADREGH_PAD28FNCSEL            (3)                     /* bitfield lsb */
#define BFM_GPIO_PADREGH_PAD28FNCSEL            ((uint32_t)0x00000018)  /* bitfield mask */
#define BFN_GPIO_PADREGH_PAD28FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGH_PAD28FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_PAD28FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGH_PAD28FNCSEL)) & (BFM_GPIO_PADREGH_PAD28FNCSEL))
#define BFX_GPIO_PADREGH_PAD28FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGH_PAD28FNCSEL)) >> (BFP_GPIO_PADREGH_PAD28FNCSEL))
#define BFW_GPIO_PADREGH_PAD28FNCSEL(v)         (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_PAD28FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_PAD28FNCSEL)) & (BFM_GPIO_PADREGH_PAD28FNCSEL)) ))
#define BFR_GPIO_PADREGH_PAD28FNCSEL()          ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_PAD28FNCSEL))>>(BFP_GPIO_PADREGH_PAD28FNCSEL))

#define BFP_GPIO_PADREGH_PAD28STRNG             (2)                     /* bitfield lsb */
#define BFM_GPIO_PADREGH_PAD28STRNG             ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_PADREGH_PAD28STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGH_PAD28STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_PAD28STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGH_PAD28STRNG)) & (BFM_GPIO_PADREGH_PAD28STRNG))
#define BFX_GPIO_PADREGH_PAD28STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGH_PAD28STRNG)) >> (BFP_GPIO_PADREGH_PAD28STRNG))
#define BFW_GPIO_PADREGH_PAD28STRNG(v)          (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_PAD28STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_PAD28STRNG)) & (BFM_GPIO_PADREGH_PAD28STRNG)) ))
#define BFR_GPIO_PADREGH_PAD28STRNG()           ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_PAD28STRNG))>>(BFP_GPIO_PADREGH_PAD28STRNG))

#define BFP_GPIO_PADREGH_PAD28INPEN             (1)                     /* bitfield lsb */
#define BFM_GPIO_PADREGH_PAD28INPEN             ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_PADREGH_PAD28INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGH_PAD28INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_PAD28INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGH_PAD28INPEN)) & (BFM_GPIO_PADREGH_PAD28INPEN))
#define BFX_GPIO_PADREGH_PAD28INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGH_PAD28INPEN)) >> (BFP_GPIO_PADREGH_PAD28INPEN))
#define BFW_GPIO_PADREGH_PAD28INPEN(v)          (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_PAD28INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_PAD28INPEN)) & (BFM_GPIO_PADREGH_PAD28INPEN)) ))
#define BFR_GPIO_PADREGH_PAD28INPEN()           ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_PAD28INPEN))>>(BFP_GPIO_PADREGH_PAD28INPEN))

#define BFP_GPIO_PADREGH_PAD28PULL              (0)                     /* bitfield lsb */
#define BFM_GPIO_PADREGH_PAD28PULL              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_PADREGH_PAD28PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGH_PAD28PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGH_PAD28PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGH_PAD28PULL)) & (BFM_GPIO_PADREGH_PAD28PULL))
#define BFX_GPIO_PADREGH_PAD28PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGH_PAD28PULL)) >> (BFP_GPIO_PADREGH_PAD28PULL))
#define BFW_GPIO_PADREGH_PAD28PULL(v)           (REG_GPIO_PADREGH.U32 = ( (REG_GPIO_PADREGH.U32 & ~(BFM_GPIO_PADREGH_PAD28PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGH_PAD28PULL)) & (BFM_GPIO_PADREGH_PAD28PULL)) ))
#define BFR_GPIO_PADREGH_PAD28PULL()            ((REG_GPIO_PADREGH.U32 & (BFM_GPIO_PADREGH_PAD28PULL))>>(BFP_GPIO_PADREGH_PAD28PULL))


// *****************************************************************************
//                                                                             *
//  GPIO_PADREGI - Pad Configuration Register I                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_29                    :  3;
        unsigned PAD35FNCSEL                :  2;
        unsigned PAD35STRNG                 :  1;
        unsigned PAD35INPEN                 :  1;
        unsigned PAD35PULL                  :  1;
        unsigned RSVD_21                    :  3;
        unsigned PAD34FNCSEL                :  2;
        unsigned PAD34STRNG                 :  1;
        unsigned PAD34INPEN                 :  1;
        unsigned PAD34PULL                  :  1;
        unsigned RSVD_13                    :  3;
        unsigned PAD33FNCSEL                :  2;
        unsigned PAD33STRNG                 :  1;
        unsigned PAD33INPEN                 :  1;
        unsigned PAD33PULL                  :  1;
        unsigned RSVD_5                     :  3;
        unsigned PAD32FNCSEL                :  2;
        unsigned PAD32STRNG                 :  1;
        unsigned PAD32INPEN                 :  1;
        unsigned PAD32PULL                  :  1;
    } B;
} reg_gpio_padregi_t;

#define REG_GPIO_PADREGI_ADDR                   (REG_GPIO_BASEADDR + 0x00000020UL)
#define REG_GPIO_PADREGI                        (*(volatile reg_gpio_padregi_t *) REG_GPIO_PADREGI_ADDR)
#define REG_GPIO_PADREGI_RD()                   (REG_GPIO_PADREGI.U32)
#define REG_GPIO_PADREGI_WR(v)                  (REG_GPIO_PADREGI.U32 = (v))
#define REG_GPIO_PADREGI_CLR(m)                 (REG_GPIO_PADREGI.U32 = ((REG_GPIO_PADREGI.U32) & ~(m)))
#define REG_GPIO_PADREGI_SET(m)                 (REG_GPIO_PADREGI.U32 = ((REG_GPIO_PADREGI.U32) | (m)))
#define REG_GPIO_PADREGI_DEF                    0x18181818

#define BFP_GPIO_PADREGI_RSVD_29                (29)                    /* bitfield lsb */
#define BFM_GPIO_PADREGI_RSVD_29                ((uint32_t)0xe0000000)  /* bitfield mask */
#define BFN_GPIO_PADREGI_RSVD_29                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGI_RSVD_29                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_RSVD_29(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGI_RSVD_29)) & (BFM_GPIO_PADREGI_RSVD_29))
#define BFX_GPIO_PADREGI_RSVD_29(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGI_RSVD_29)) >> (BFP_GPIO_PADREGI_RSVD_29))
#define BFW_GPIO_PADREGI_RSVD_29(v)             (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_RSVD_29)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_RSVD_29)) & (BFM_GPIO_PADREGI_RSVD_29)) ))
#define BFR_GPIO_PADREGI_RSVD_29()              ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_RSVD_29))>>(BFP_GPIO_PADREGI_RSVD_29))

#define BFP_GPIO_PADREGI_PAD35FNCSEL            (27)                    /* bitfield lsb */
#define BFM_GPIO_PADREGI_PAD35FNCSEL            ((uint32_t)0x18000000)  /* bitfield mask */
#define BFN_GPIO_PADREGI_PAD35FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGI_PAD35FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_PAD35FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGI_PAD35FNCSEL)) & (BFM_GPIO_PADREGI_PAD35FNCSEL))
#define BFX_GPIO_PADREGI_PAD35FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGI_PAD35FNCSEL)) >> (BFP_GPIO_PADREGI_PAD35FNCSEL))
#define BFW_GPIO_PADREGI_PAD35FNCSEL(v)         (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_PAD35FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_PAD35FNCSEL)) & (BFM_GPIO_PADREGI_PAD35FNCSEL)) ))
#define BFR_GPIO_PADREGI_PAD35FNCSEL()          ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_PAD35FNCSEL))>>(BFP_GPIO_PADREGI_PAD35FNCSEL))

#define BFP_GPIO_PADREGI_PAD35STRNG             (26)                    /* bitfield lsb */
#define BFM_GPIO_PADREGI_PAD35STRNG             ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_GPIO_PADREGI_PAD35STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGI_PAD35STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_PAD35STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGI_PAD35STRNG)) & (BFM_GPIO_PADREGI_PAD35STRNG))
#define BFX_GPIO_PADREGI_PAD35STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGI_PAD35STRNG)) >> (BFP_GPIO_PADREGI_PAD35STRNG))
#define BFW_GPIO_PADREGI_PAD35STRNG(v)          (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_PAD35STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_PAD35STRNG)) & (BFM_GPIO_PADREGI_PAD35STRNG)) ))
#define BFR_GPIO_PADREGI_PAD35STRNG()           ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_PAD35STRNG))>>(BFP_GPIO_PADREGI_PAD35STRNG))

#define BFP_GPIO_PADREGI_PAD35INPEN             (25)                    /* bitfield lsb */
#define BFM_GPIO_PADREGI_PAD35INPEN             ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_GPIO_PADREGI_PAD35INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGI_PAD35INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_PAD35INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGI_PAD35INPEN)) & (BFM_GPIO_PADREGI_PAD35INPEN))
#define BFX_GPIO_PADREGI_PAD35INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGI_PAD35INPEN)) >> (BFP_GPIO_PADREGI_PAD35INPEN))
#define BFW_GPIO_PADREGI_PAD35INPEN(v)          (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_PAD35INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_PAD35INPEN)) & (BFM_GPIO_PADREGI_PAD35INPEN)) ))
#define BFR_GPIO_PADREGI_PAD35INPEN()           ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_PAD35INPEN))>>(BFP_GPIO_PADREGI_PAD35INPEN))

#define BFP_GPIO_PADREGI_PAD35PULL              (24)                    /* bitfield lsb */
#define BFM_GPIO_PADREGI_PAD35PULL              ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_PADREGI_PAD35PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGI_PAD35PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_PAD35PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGI_PAD35PULL)) & (BFM_GPIO_PADREGI_PAD35PULL))
#define BFX_GPIO_PADREGI_PAD35PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGI_PAD35PULL)) >> (BFP_GPIO_PADREGI_PAD35PULL))
#define BFW_GPIO_PADREGI_PAD35PULL(v)           (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_PAD35PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_PAD35PULL)) & (BFM_GPIO_PADREGI_PAD35PULL)) ))
#define BFR_GPIO_PADREGI_PAD35PULL()            ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_PAD35PULL))>>(BFP_GPIO_PADREGI_PAD35PULL))

#define BFP_GPIO_PADREGI_RSVD_21                (21)                    /* bitfield lsb */
#define BFM_GPIO_PADREGI_RSVD_21                ((uint32_t)0x00e00000)  /* bitfield mask */
#define BFN_GPIO_PADREGI_RSVD_21                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGI_RSVD_21                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_RSVD_21(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGI_RSVD_21)) & (BFM_GPIO_PADREGI_RSVD_21))
#define BFX_GPIO_PADREGI_RSVD_21(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGI_RSVD_21)) >> (BFP_GPIO_PADREGI_RSVD_21))
#define BFW_GPIO_PADREGI_RSVD_21(v)             (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_RSVD_21)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_RSVD_21)) & (BFM_GPIO_PADREGI_RSVD_21)) ))
#define BFR_GPIO_PADREGI_RSVD_21()              ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_RSVD_21))>>(BFP_GPIO_PADREGI_RSVD_21))

#define BFP_GPIO_PADREGI_PAD34FNCSEL            (19)                    /* bitfield lsb */
#define BFM_GPIO_PADREGI_PAD34FNCSEL            ((uint32_t)0x00180000)  /* bitfield mask */
#define BFN_GPIO_PADREGI_PAD34FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGI_PAD34FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_PAD34FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGI_PAD34FNCSEL)) & (BFM_GPIO_PADREGI_PAD34FNCSEL))
#define BFX_GPIO_PADREGI_PAD34FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGI_PAD34FNCSEL)) >> (BFP_GPIO_PADREGI_PAD34FNCSEL))
#define BFW_GPIO_PADREGI_PAD34FNCSEL(v)         (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_PAD34FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_PAD34FNCSEL)) & (BFM_GPIO_PADREGI_PAD34FNCSEL)) ))
#define BFR_GPIO_PADREGI_PAD34FNCSEL()          ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_PAD34FNCSEL))>>(BFP_GPIO_PADREGI_PAD34FNCSEL))

#define BFP_GPIO_PADREGI_PAD34STRNG             (18)                    /* bitfield lsb */
#define BFM_GPIO_PADREGI_PAD34STRNG             ((uint32_t)0x00040000)  /* bitfield mask */
#define BFN_GPIO_PADREGI_PAD34STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGI_PAD34STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_PAD34STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGI_PAD34STRNG)) & (BFM_GPIO_PADREGI_PAD34STRNG))
#define BFX_GPIO_PADREGI_PAD34STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGI_PAD34STRNG)) >> (BFP_GPIO_PADREGI_PAD34STRNG))
#define BFW_GPIO_PADREGI_PAD34STRNG(v)          (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_PAD34STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_PAD34STRNG)) & (BFM_GPIO_PADREGI_PAD34STRNG)) ))
#define BFR_GPIO_PADREGI_PAD34STRNG()           ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_PAD34STRNG))>>(BFP_GPIO_PADREGI_PAD34STRNG))

#define BFP_GPIO_PADREGI_PAD34INPEN             (17)                    /* bitfield lsb */
#define BFM_GPIO_PADREGI_PAD34INPEN             ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_PADREGI_PAD34INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGI_PAD34INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_PAD34INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGI_PAD34INPEN)) & (BFM_GPIO_PADREGI_PAD34INPEN))
#define BFX_GPIO_PADREGI_PAD34INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGI_PAD34INPEN)) >> (BFP_GPIO_PADREGI_PAD34INPEN))
#define BFW_GPIO_PADREGI_PAD34INPEN(v)          (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_PAD34INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_PAD34INPEN)) & (BFM_GPIO_PADREGI_PAD34INPEN)) ))
#define BFR_GPIO_PADREGI_PAD34INPEN()           ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_PAD34INPEN))>>(BFP_GPIO_PADREGI_PAD34INPEN))

#define BFP_GPIO_PADREGI_PAD34PULL              (16)                    /* bitfield lsb */
#define BFM_GPIO_PADREGI_PAD34PULL              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_PADREGI_PAD34PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGI_PAD34PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_PAD34PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGI_PAD34PULL)) & (BFM_GPIO_PADREGI_PAD34PULL))
#define BFX_GPIO_PADREGI_PAD34PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGI_PAD34PULL)) >> (BFP_GPIO_PADREGI_PAD34PULL))
#define BFW_GPIO_PADREGI_PAD34PULL(v)           (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_PAD34PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_PAD34PULL)) & (BFM_GPIO_PADREGI_PAD34PULL)) ))
#define BFR_GPIO_PADREGI_PAD34PULL()            ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_PAD34PULL))>>(BFP_GPIO_PADREGI_PAD34PULL))

#define BFP_GPIO_PADREGI_RSVD_13                (13)                    /* bitfield lsb */
#define BFM_GPIO_PADREGI_RSVD_13                ((uint32_t)0x0000e000)  /* bitfield mask */
#define BFN_GPIO_PADREGI_RSVD_13                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGI_RSVD_13                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_RSVD_13(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGI_RSVD_13)) & (BFM_GPIO_PADREGI_RSVD_13))
#define BFX_GPIO_PADREGI_RSVD_13(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGI_RSVD_13)) >> (BFP_GPIO_PADREGI_RSVD_13))
#define BFW_GPIO_PADREGI_RSVD_13(v)             (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_RSVD_13)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_RSVD_13)) & (BFM_GPIO_PADREGI_RSVD_13)) ))
#define BFR_GPIO_PADREGI_RSVD_13()              ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_RSVD_13))>>(BFP_GPIO_PADREGI_RSVD_13))

#define BFP_GPIO_PADREGI_PAD33FNCSEL            (11)                    /* bitfield lsb */
#define BFM_GPIO_PADREGI_PAD33FNCSEL            ((uint32_t)0x00001800)  /* bitfield mask */
#define BFN_GPIO_PADREGI_PAD33FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGI_PAD33FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_PAD33FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGI_PAD33FNCSEL)) & (BFM_GPIO_PADREGI_PAD33FNCSEL))
#define BFX_GPIO_PADREGI_PAD33FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGI_PAD33FNCSEL)) >> (BFP_GPIO_PADREGI_PAD33FNCSEL))
#define BFW_GPIO_PADREGI_PAD33FNCSEL(v)         (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_PAD33FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_PAD33FNCSEL)) & (BFM_GPIO_PADREGI_PAD33FNCSEL)) ))
#define BFR_GPIO_PADREGI_PAD33FNCSEL()          ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_PAD33FNCSEL))>>(BFP_GPIO_PADREGI_PAD33FNCSEL))

#define BFP_GPIO_PADREGI_PAD33STRNG             (10)                    /* bitfield lsb */
#define BFM_GPIO_PADREGI_PAD33STRNG             ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_PADREGI_PAD33STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGI_PAD33STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_PAD33STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGI_PAD33STRNG)) & (BFM_GPIO_PADREGI_PAD33STRNG))
#define BFX_GPIO_PADREGI_PAD33STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGI_PAD33STRNG)) >> (BFP_GPIO_PADREGI_PAD33STRNG))
#define BFW_GPIO_PADREGI_PAD33STRNG(v)          (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_PAD33STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_PAD33STRNG)) & (BFM_GPIO_PADREGI_PAD33STRNG)) ))
#define BFR_GPIO_PADREGI_PAD33STRNG()           ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_PAD33STRNG))>>(BFP_GPIO_PADREGI_PAD33STRNG))

#define BFP_GPIO_PADREGI_PAD33INPEN             (9)                     /* bitfield lsb */
#define BFM_GPIO_PADREGI_PAD33INPEN             ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_PADREGI_PAD33INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGI_PAD33INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_PAD33INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGI_PAD33INPEN)) & (BFM_GPIO_PADREGI_PAD33INPEN))
#define BFX_GPIO_PADREGI_PAD33INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGI_PAD33INPEN)) >> (BFP_GPIO_PADREGI_PAD33INPEN))
#define BFW_GPIO_PADREGI_PAD33INPEN(v)          (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_PAD33INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_PAD33INPEN)) & (BFM_GPIO_PADREGI_PAD33INPEN)) ))
#define BFR_GPIO_PADREGI_PAD33INPEN()           ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_PAD33INPEN))>>(BFP_GPIO_PADREGI_PAD33INPEN))

#define BFP_GPIO_PADREGI_PAD33PULL              (8)                     /* bitfield lsb */
#define BFM_GPIO_PADREGI_PAD33PULL              ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_PADREGI_PAD33PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGI_PAD33PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_PAD33PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGI_PAD33PULL)) & (BFM_GPIO_PADREGI_PAD33PULL))
#define BFX_GPIO_PADREGI_PAD33PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGI_PAD33PULL)) >> (BFP_GPIO_PADREGI_PAD33PULL))
#define BFW_GPIO_PADREGI_PAD33PULL(v)           (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_PAD33PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_PAD33PULL)) & (BFM_GPIO_PADREGI_PAD33PULL)) ))
#define BFR_GPIO_PADREGI_PAD33PULL()            ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_PAD33PULL))>>(BFP_GPIO_PADREGI_PAD33PULL))

#define BFP_GPIO_PADREGI_RSVD_5                 (5)                     /* bitfield lsb */
#define BFM_GPIO_PADREGI_RSVD_5                 ((uint32_t)0x000000e0)  /* bitfield mask */
#define BFN_GPIO_PADREGI_RSVD_5                 (3)                     /* bitfield width */
#define BFD_GPIO_PADREGI_RSVD_5                 (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_RSVD_5(v)              ((((uint32_t) v) << (BFP_GPIO_PADREGI_RSVD_5)) & (BFM_GPIO_PADREGI_RSVD_5))
#define BFX_GPIO_PADREGI_RSVD_5(v)              ((((uint32_t) v) & (BFM_GPIO_PADREGI_RSVD_5)) >> (BFP_GPIO_PADREGI_RSVD_5))
#define BFW_GPIO_PADREGI_RSVD_5(v)              (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_RSVD_5)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_RSVD_5)) & (BFM_GPIO_PADREGI_RSVD_5)) ))
#define BFR_GPIO_PADREGI_RSVD_5()               ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_RSVD_5))>>(BFP_GPIO_PADREGI_RSVD_5))

#define BFP_GPIO_PADREGI_PAD32FNCSEL            (3)                     /* bitfield lsb */
#define BFM_GPIO_PADREGI_PAD32FNCSEL            ((uint32_t)0x00000018)  /* bitfield mask */
#define BFN_GPIO_PADREGI_PAD32FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGI_PAD32FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_PAD32FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGI_PAD32FNCSEL)) & (BFM_GPIO_PADREGI_PAD32FNCSEL))
#define BFX_GPIO_PADREGI_PAD32FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGI_PAD32FNCSEL)) >> (BFP_GPIO_PADREGI_PAD32FNCSEL))
#define BFW_GPIO_PADREGI_PAD32FNCSEL(v)         (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_PAD32FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_PAD32FNCSEL)) & (BFM_GPIO_PADREGI_PAD32FNCSEL)) ))
#define BFR_GPIO_PADREGI_PAD32FNCSEL()          ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_PAD32FNCSEL))>>(BFP_GPIO_PADREGI_PAD32FNCSEL))

#define BFP_GPIO_PADREGI_PAD32STRNG             (2)                     /* bitfield lsb */
#define BFM_GPIO_PADREGI_PAD32STRNG             ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_PADREGI_PAD32STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGI_PAD32STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_PAD32STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGI_PAD32STRNG)) & (BFM_GPIO_PADREGI_PAD32STRNG))
#define BFX_GPIO_PADREGI_PAD32STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGI_PAD32STRNG)) >> (BFP_GPIO_PADREGI_PAD32STRNG))
#define BFW_GPIO_PADREGI_PAD32STRNG(v)          (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_PAD32STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_PAD32STRNG)) & (BFM_GPIO_PADREGI_PAD32STRNG)) ))
#define BFR_GPIO_PADREGI_PAD32STRNG()           ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_PAD32STRNG))>>(BFP_GPIO_PADREGI_PAD32STRNG))

#define BFP_GPIO_PADREGI_PAD32INPEN             (1)                     /* bitfield lsb */
#define BFM_GPIO_PADREGI_PAD32INPEN             ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_PADREGI_PAD32INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGI_PAD32INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_PAD32INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGI_PAD32INPEN)) & (BFM_GPIO_PADREGI_PAD32INPEN))
#define BFX_GPIO_PADREGI_PAD32INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGI_PAD32INPEN)) >> (BFP_GPIO_PADREGI_PAD32INPEN))
#define BFW_GPIO_PADREGI_PAD32INPEN(v)          (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_PAD32INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_PAD32INPEN)) & (BFM_GPIO_PADREGI_PAD32INPEN)) ))
#define BFR_GPIO_PADREGI_PAD32INPEN()           ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_PAD32INPEN))>>(BFP_GPIO_PADREGI_PAD32INPEN))

#define BFP_GPIO_PADREGI_PAD32PULL              (0)                     /* bitfield lsb */
#define BFM_GPIO_PADREGI_PAD32PULL              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_PADREGI_PAD32PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGI_PAD32PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGI_PAD32PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGI_PAD32PULL)) & (BFM_GPIO_PADREGI_PAD32PULL))
#define BFX_GPIO_PADREGI_PAD32PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGI_PAD32PULL)) >> (BFP_GPIO_PADREGI_PAD32PULL))
#define BFW_GPIO_PADREGI_PAD32PULL(v)           (REG_GPIO_PADREGI.U32 = ( (REG_GPIO_PADREGI.U32 & ~(BFM_GPIO_PADREGI_PAD32PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGI_PAD32PULL)) & (BFM_GPIO_PADREGI_PAD32PULL)) ))
#define BFR_GPIO_PADREGI_PAD32PULL()            ((REG_GPIO_PADREGI.U32 & (BFM_GPIO_PADREGI_PAD32PULL))>>(BFP_GPIO_PADREGI_PAD32PULL))


// *****************************************************************************
//                                                                             *
//  GPIO_PADREGJ - Pad Configuration Register J                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_29                    :  3;
        unsigned PAD39FNCSEL                :  2;
        unsigned PAD39STRNG                 :  1;
        unsigned PAD39INPEN                 :  1;
        unsigned PAD39PULL                  :  1;
        unsigned RSVD_21                    :  3;
        unsigned PAD38FNCSEL                :  2;
        unsigned PAD38STRNG                 :  1;
        unsigned PAD38INPEN                 :  1;
        unsigned PAD38PULL                  :  1;
        unsigned RSVD_13                    :  3;
        unsigned PAD37FNCSEL                :  2;
        unsigned PAD37STRNG                 :  1;
        unsigned PAD37INPEN                 :  1;
        unsigned PAD37PULL                  :  1;
        unsigned RSVD_5                     :  3;
        unsigned PAD36FNCSEL                :  2;
        unsigned PAD36STRNG                 :  1;
        unsigned PAD36INPEN                 :  1;
        unsigned PAD36PULL                  :  1;
    } B;
} reg_gpio_padregj_t;

#define REG_GPIO_PADREGJ_ADDR                   (REG_GPIO_BASEADDR + 0x00000024UL)
#define REG_GPIO_PADREGJ                        (*(volatile reg_gpio_padregj_t *) REG_GPIO_PADREGJ_ADDR)
#define REG_GPIO_PADREGJ_RD()                   (REG_GPIO_PADREGJ.U32)
#define REG_GPIO_PADREGJ_WR(v)                  (REG_GPIO_PADREGJ.U32 = (v))
#define REG_GPIO_PADREGJ_CLR(m)                 (REG_GPIO_PADREGJ.U32 = ((REG_GPIO_PADREGJ.U32) & ~(m)))
#define REG_GPIO_PADREGJ_SET(m)                 (REG_GPIO_PADREGJ.U32 = ((REG_GPIO_PADREGJ.U32) | (m)))
#define REG_GPIO_PADREGJ_DEF                    0x18181818

#define BFP_GPIO_PADREGJ_RSVD_29                (29)                    /* bitfield lsb */
#define BFM_GPIO_PADREGJ_RSVD_29                ((uint32_t)0xe0000000)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_RSVD_29                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_RSVD_29                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_RSVD_29(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGJ_RSVD_29)) & (BFM_GPIO_PADREGJ_RSVD_29))
#define BFX_GPIO_PADREGJ_RSVD_29(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGJ_RSVD_29)) >> (BFP_GPIO_PADREGJ_RSVD_29))
#define BFW_GPIO_PADREGJ_RSVD_29(v)             (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_RSVD_29)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_RSVD_29)) & (BFM_GPIO_PADREGJ_RSVD_29)) ))
#define BFR_GPIO_PADREGJ_RSVD_29()              ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_RSVD_29))>>(BFP_GPIO_PADREGJ_RSVD_29))

#define BFP_GPIO_PADREGJ_PAD39FNCSEL            (27)                    /* bitfield lsb */
#define BFM_GPIO_PADREGJ_PAD39FNCSEL            ((uint32_t)0x18000000)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_PAD39FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_PAD39FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_PAD39FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGJ_PAD39FNCSEL)) & (BFM_GPIO_PADREGJ_PAD39FNCSEL))
#define BFX_GPIO_PADREGJ_PAD39FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGJ_PAD39FNCSEL)) >> (BFP_GPIO_PADREGJ_PAD39FNCSEL))
#define BFW_GPIO_PADREGJ_PAD39FNCSEL(v)         (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_PAD39FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_PAD39FNCSEL)) & (BFM_GPIO_PADREGJ_PAD39FNCSEL)) ))
#define BFR_GPIO_PADREGJ_PAD39FNCSEL()          ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_PAD39FNCSEL))>>(BFP_GPIO_PADREGJ_PAD39FNCSEL))

#define BFP_GPIO_PADREGJ_PAD39STRNG             (26)                    /* bitfield lsb */
#define BFM_GPIO_PADREGJ_PAD39STRNG             ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_PAD39STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_PAD39STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_PAD39STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGJ_PAD39STRNG)) & (BFM_GPIO_PADREGJ_PAD39STRNG))
#define BFX_GPIO_PADREGJ_PAD39STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGJ_PAD39STRNG)) >> (BFP_GPIO_PADREGJ_PAD39STRNG))
#define BFW_GPIO_PADREGJ_PAD39STRNG(v)          (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_PAD39STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_PAD39STRNG)) & (BFM_GPIO_PADREGJ_PAD39STRNG)) ))
#define BFR_GPIO_PADREGJ_PAD39STRNG()           ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_PAD39STRNG))>>(BFP_GPIO_PADREGJ_PAD39STRNG))

#define BFP_GPIO_PADREGJ_PAD39INPEN             (25)                    /* bitfield lsb */
#define BFM_GPIO_PADREGJ_PAD39INPEN             ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_PAD39INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_PAD39INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_PAD39INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGJ_PAD39INPEN)) & (BFM_GPIO_PADREGJ_PAD39INPEN))
#define BFX_GPIO_PADREGJ_PAD39INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGJ_PAD39INPEN)) >> (BFP_GPIO_PADREGJ_PAD39INPEN))
#define BFW_GPIO_PADREGJ_PAD39INPEN(v)          (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_PAD39INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_PAD39INPEN)) & (BFM_GPIO_PADREGJ_PAD39INPEN)) ))
#define BFR_GPIO_PADREGJ_PAD39INPEN()           ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_PAD39INPEN))>>(BFP_GPIO_PADREGJ_PAD39INPEN))

#define BFP_GPIO_PADREGJ_PAD39PULL              (24)                    /* bitfield lsb */
#define BFM_GPIO_PADREGJ_PAD39PULL              ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_PAD39PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_PAD39PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_PAD39PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGJ_PAD39PULL)) & (BFM_GPIO_PADREGJ_PAD39PULL))
#define BFX_GPIO_PADREGJ_PAD39PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGJ_PAD39PULL)) >> (BFP_GPIO_PADREGJ_PAD39PULL))
#define BFW_GPIO_PADREGJ_PAD39PULL(v)           (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_PAD39PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_PAD39PULL)) & (BFM_GPIO_PADREGJ_PAD39PULL)) ))
#define BFR_GPIO_PADREGJ_PAD39PULL()            ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_PAD39PULL))>>(BFP_GPIO_PADREGJ_PAD39PULL))

#define BFP_GPIO_PADREGJ_RSVD_21                (21)                    /* bitfield lsb */
#define BFM_GPIO_PADREGJ_RSVD_21                ((uint32_t)0x00e00000)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_RSVD_21                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_RSVD_21                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_RSVD_21(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGJ_RSVD_21)) & (BFM_GPIO_PADREGJ_RSVD_21))
#define BFX_GPIO_PADREGJ_RSVD_21(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGJ_RSVD_21)) >> (BFP_GPIO_PADREGJ_RSVD_21))
#define BFW_GPIO_PADREGJ_RSVD_21(v)             (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_RSVD_21)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_RSVD_21)) & (BFM_GPIO_PADREGJ_RSVD_21)) ))
#define BFR_GPIO_PADREGJ_RSVD_21()              ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_RSVD_21))>>(BFP_GPIO_PADREGJ_RSVD_21))

#define BFP_GPIO_PADREGJ_PAD38FNCSEL            (19)                    /* bitfield lsb */
#define BFM_GPIO_PADREGJ_PAD38FNCSEL            ((uint32_t)0x00180000)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_PAD38FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_PAD38FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_PAD38FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGJ_PAD38FNCSEL)) & (BFM_GPIO_PADREGJ_PAD38FNCSEL))
#define BFX_GPIO_PADREGJ_PAD38FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGJ_PAD38FNCSEL)) >> (BFP_GPIO_PADREGJ_PAD38FNCSEL))
#define BFW_GPIO_PADREGJ_PAD38FNCSEL(v)         (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_PAD38FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_PAD38FNCSEL)) & (BFM_GPIO_PADREGJ_PAD38FNCSEL)) ))
#define BFR_GPIO_PADREGJ_PAD38FNCSEL()          ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_PAD38FNCSEL))>>(BFP_GPIO_PADREGJ_PAD38FNCSEL))

#define BFP_GPIO_PADREGJ_PAD38STRNG             (18)                    /* bitfield lsb */
#define BFM_GPIO_PADREGJ_PAD38STRNG             ((uint32_t)0x00040000)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_PAD38STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_PAD38STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_PAD38STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGJ_PAD38STRNG)) & (BFM_GPIO_PADREGJ_PAD38STRNG))
#define BFX_GPIO_PADREGJ_PAD38STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGJ_PAD38STRNG)) >> (BFP_GPIO_PADREGJ_PAD38STRNG))
#define BFW_GPIO_PADREGJ_PAD38STRNG(v)          (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_PAD38STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_PAD38STRNG)) & (BFM_GPIO_PADREGJ_PAD38STRNG)) ))
#define BFR_GPIO_PADREGJ_PAD38STRNG()           ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_PAD38STRNG))>>(BFP_GPIO_PADREGJ_PAD38STRNG))

#define BFP_GPIO_PADREGJ_PAD38INPEN             (17)                    /* bitfield lsb */
#define BFM_GPIO_PADREGJ_PAD38INPEN             ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_PAD38INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_PAD38INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_PAD38INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGJ_PAD38INPEN)) & (BFM_GPIO_PADREGJ_PAD38INPEN))
#define BFX_GPIO_PADREGJ_PAD38INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGJ_PAD38INPEN)) >> (BFP_GPIO_PADREGJ_PAD38INPEN))
#define BFW_GPIO_PADREGJ_PAD38INPEN(v)          (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_PAD38INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_PAD38INPEN)) & (BFM_GPIO_PADREGJ_PAD38INPEN)) ))
#define BFR_GPIO_PADREGJ_PAD38INPEN()           ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_PAD38INPEN))>>(BFP_GPIO_PADREGJ_PAD38INPEN))

#define BFP_GPIO_PADREGJ_PAD38PULL              (16)                    /* bitfield lsb */
#define BFM_GPIO_PADREGJ_PAD38PULL              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_PAD38PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_PAD38PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_PAD38PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGJ_PAD38PULL)) & (BFM_GPIO_PADREGJ_PAD38PULL))
#define BFX_GPIO_PADREGJ_PAD38PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGJ_PAD38PULL)) >> (BFP_GPIO_PADREGJ_PAD38PULL))
#define BFW_GPIO_PADREGJ_PAD38PULL(v)           (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_PAD38PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_PAD38PULL)) & (BFM_GPIO_PADREGJ_PAD38PULL)) ))
#define BFR_GPIO_PADREGJ_PAD38PULL()            ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_PAD38PULL))>>(BFP_GPIO_PADREGJ_PAD38PULL))

#define BFP_GPIO_PADREGJ_RSVD_13                (13)                    /* bitfield lsb */
#define BFM_GPIO_PADREGJ_RSVD_13                ((uint32_t)0x0000e000)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_RSVD_13                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_RSVD_13                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_RSVD_13(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGJ_RSVD_13)) & (BFM_GPIO_PADREGJ_RSVD_13))
#define BFX_GPIO_PADREGJ_RSVD_13(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGJ_RSVD_13)) >> (BFP_GPIO_PADREGJ_RSVD_13))
#define BFW_GPIO_PADREGJ_RSVD_13(v)             (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_RSVD_13)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_RSVD_13)) & (BFM_GPIO_PADREGJ_RSVD_13)) ))
#define BFR_GPIO_PADREGJ_RSVD_13()              ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_RSVD_13))>>(BFP_GPIO_PADREGJ_RSVD_13))

#define BFP_GPIO_PADREGJ_PAD37FNCSEL            (11)                    /* bitfield lsb */
#define BFM_GPIO_PADREGJ_PAD37FNCSEL            ((uint32_t)0x00001800)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_PAD37FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_PAD37FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_PAD37FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGJ_PAD37FNCSEL)) & (BFM_GPIO_PADREGJ_PAD37FNCSEL))
#define BFX_GPIO_PADREGJ_PAD37FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGJ_PAD37FNCSEL)) >> (BFP_GPIO_PADREGJ_PAD37FNCSEL))
#define BFW_GPIO_PADREGJ_PAD37FNCSEL(v)         (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_PAD37FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_PAD37FNCSEL)) & (BFM_GPIO_PADREGJ_PAD37FNCSEL)) ))
#define BFR_GPIO_PADREGJ_PAD37FNCSEL()          ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_PAD37FNCSEL))>>(BFP_GPIO_PADREGJ_PAD37FNCSEL))

#define BFP_GPIO_PADREGJ_PAD37STRNG             (10)                    /* bitfield lsb */
#define BFM_GPIO_PADREGJ_PAD37STRNG             ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_PAD37STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_PAD37STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_PAD37STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGJ_PAD37STRNG)) & (BFM_GPIO_PADREGJ_PAD37STRNG))
#define BFX_GPIO_PADREGJ_PAD37STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGJ_PAD37STRNG)) >> (BFP_GPIO_PADREGJ_PAD37STRNG))
#define BFW_GPIO_PADREGJ_PAD37STRNG(v)          (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_PAD37STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_PAD37STRNG)) & (BFM_GPIO_PADREGJ_PAD37STRNG)) ))
#define BFR_GPIO_PADREGJ_PAD37STRNG()           ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_PAD37STRNG))>>(BFP_GPIO_PADREGJ_PAD37STRNG))

#define BFP_GPIO_PADREGJ_PAD37INPEN             (9)                     /* bitfield lsb */
#define BFM_GPIO_PADREGJ_PAD37INPEN             ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_PAD37INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_PAD37INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_PAD37INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGJ_PAD37INPEN)) & (BFM_GPIO_PADREGJ_PAD37INPEN))
#define BFX_GPIO_PADREGJ_PAD37INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGJ_PAD37INPEN)) >> (BFP_GPIO_PADREGJ_PAD37INPEN))
#define BFW_GPIO_PADREGJ_PAD37INPEN(v)          (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_PAD37INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_PAD37INPEN)) & (BFM_GPIO_PADREGJ_PAD37INPEN)) ))
#define BFR_GPIO_PADREGJ_PAD37INPEN()           ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_PAD37INPEN))>>(BFP_GPIO_PADREGJ_PAD37INPEN))

#define BFP_GPIO_PADREGJ_PAD37PULL              (8)                     /* bitfield lsb */
#define BFM_GPIO_PADREGJ_PAD37PULL              ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_PAD37PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_PAD37PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_PAD37PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGJ_PAD37PULL)) & (BFM_GPIO_PADREGJ_PAD37PULL))
#define BFX_GPIO_PADREGJ_PAD37PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGJ_PAD37PULL)) >> (BFP_GPIO_PADREGJ_PAD37PULL))
#define BFW_GPIO_PADREGJ_PAD37PULL(v)           (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_PAD37PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_PAD37PULL)) & (BFM_GPIO_PADREGJ_PAD37PULL)) ))
#define BFR_GPIO_PADREGJ_PAD37PULL()            ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_PAD37PULL))>>(BFP_GPIO_PADREGJ_PAD37PULL))

#define BFP_GPIO_PADREGJ_RSVD_5                 (5)                     /* bitfield lsb */
#define BFM_GPIO_PADREGJ_RSVD_5                 ((uint32_t)0x000000e0)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_RSVD_5                 (3)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_RSVD_5                 (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_RSVD_5(v)              ((((uint32_t) v) << (BFP_GPIO_PADREGJ_RSVD_5)) & (BFM_GPIO_PADREGJ_RSVD_5))
#define BFX_GPIO_PADREGJ_RSVD_5(v)              ((((uint32_t) v) & (BFM_GPIO_PADREGJ_RSVD_5)) >> (BFP_GPIO_PADREGJ_RSVD_5))
#define BFW_GPIO_PADREGJ_RSVD_5(v)              (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_RSVD_5)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_RSVD_5)) & (BFM_GPIO_PADREGJ_RSVD_5)) ))
#define BFR_GPIO_PADREGJ_RSVD_5()               ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_RSVD_5))>>(BFP_GPIO_PADREGJ_RSVD_5))

#define BFP_GPIO_PADREGJ_PAD36FNCSEL            (3)                     /* bitfield lsb */
#define BFM_GPIO_PADREGJ_PAD36FNCSEL            ((uint32_t)0x00000018)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_PAD36FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_PAD36FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_PAD36FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGJ_PAD36FNCSEL)) & (BFM_GPIO_PADREGJ_PAD36FNCSEL))
#define BFX_GPIO_PADREGJ_PAD36FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGJ_PAD36FNCSEL)) >> (BFP_GPIO_PADREGJ_PAD36FNCSEL))
#define BFW_GPIO_PADREGJ_PAD36FNCSEL(v)         (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_PAD36FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_PAD36FNCSEL)) & (BFM_GPIO_PADREGJ_PAD36FNCSEL)) ))
#define BFR_GPIO_PADREGJ_PAD36FNCSEL()          ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_PAD36FNCSEL))>>(BFP_GPIO_PADREGJ_PAD36FNCSEL))

#define BFP_GPIO_PADREGJ_PAD36STRNG             (2)                     /* bitfield lsb */
#define BFM_GPIO_PADREGJ_PAD36STRNG             ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_PAD36STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_PAD36STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_PAD36STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGJ_PAD36STRNG)) & (BFM_GPIO_PADREGJ_PAD36STRNG))
#define BFX_GPIO_PADREGJ_PAD36STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGJ_PAD36STRNG)) >> (BFP_GPIO_PADREGJ_PAD36STRNG))
#define BFW_GPIO_PADREGJ_PAD36STRNG(v)          (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_PAD36STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_PAD36STRNG)) & (BFM_GPIO_PADREGJ_PAD36STRNG)) ))
#define BFR_GPIO_PADREGJ_PAD36STRNG()           ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_PAD36STRNG))>>(BFP_GPIO_PADREGJ_PAD36STRNG))

#define BFP_GPIO_PADREGJ_PAD36INPEN             (1)                     /* bitfield lsb */
#define BFM_GPIO_PADREGJ_PAD36INPEN             ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_PAD36INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_PAD36INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_PAD36INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGJ_PAD36INPEN)) & (BFM_GPIO_PADREGJ_PAD36INPEN))
#define BFX_GPIO_PADREGJ_PAD36INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGJ_PAD36INPEN)) >> (BFP_GPIO_PADREGJ_PAD36INPEN))
#define BFW_GPIO_PADREGJ_PAD36INPEN(v)          (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_PAD36INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_PAD36INPEN)) & (BFM_GPIO_PADREGJ_PAD36INPEN)) ))
#define BFR_GPIO_PADREGJ_PAD36INPEN()           ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_PAD36INPEN))>>(BFP_GPIO_PADREGJ_PAD36INPEN))

#define BFP_GPIO_PADREGJ_PAD36PULL              (0)                     /* bitfield lsb */
#define BFM_GPIO_PADREGJ_PAD36PULL              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_PADREGJ_PAD36PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGJ_PAD36PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGJ_PAD36PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGJ_PAD36PULL)) & (BFM_GPIO_PADREGJ_PAD36PULL))
#define BFX_GPIO_PADREGJ_PAD36PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGJ_PAD36PULL)) >> (BFP_GPIO_PADREGJ_PAD36PULL))
#define BFW_GPIO_PADREGJ_PAD36PULL(v)           (REG_GPIO_PADREGJ.U32 = ( (REG_GPIO_PADREGJ.U32 & ~(BFM_GPIO_PADREGJ_PAD36PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGJ_PAD36PULL)) & (BFM_GPIO_PADREGJ_PAD36PULL)) ))
#define BFR_GPIO_PADREGJ_PAD36PULL()            ((REG_GPIO_PADREGJ.U32 & (BFM_GPIO_PADREGJ_PAD36PULL))>>(BFP_GPIO_PADREGJ_PAD36PULL))


// *****************************************************************************
//                                                                             *
//  GPIO_PADREGK - Pad Configuration Register K                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_29                    :  3;
        unsigned PAD43FNCSEL                :  2;
        unsigned PAD43STRNG                 :  1;
        unsigned PAD43INPEN                 :  1;
        unsigned PAD43PULL                  :  1;
        unsigned RSVD_21                    :  3;
        unsigned PAD42FNCSEL                :  2;
        unsigned PAD42STRNG                 :  1;
        unsigned PAD42INPEN                 :  1;
        unsigned PAD42PULL                  :  1;
        unsigned RSVD_13                    :  3;
        unsigned PAD41FNCSEL                :  2;
        unsigned PAD41STRNG                 :  1;
        unsigned PAD41INPEN                 :  1;
        unsigned PAD41PULL                  :  1;
        unsigned RSVD_5                     :  3;
        unsigned PAD40FNCSEL                :  2;
        unsigned PAD40STRNG                 :  1;
        unsigned PAD40INPEN                 :  1;
        unsigned PAD40PULL                  :  1;
    } B;
} reg_gpio_padregk_t;

#define REG_GPIO_PADREGK_ADDR                   (REG_GPIO_BASEADDR + 0x00000028UL)
#define REG_GPIO_PADREGK                        (*(volatile reg_gpio_padregk_t *) REG_GPIO_PADREGK_ADDR)
#define REG_GPIO_PADREGK_RD()                   (REG_GPIO_PADREGK.U32)
#define REG_GPIO_PADREGK_WR(v)                  (REG_GPIO_PADREGK.U32 = (v))
#define REG_GPIO_PADREGK_CLR(m)                 (REG_GPIO_PADREGK.U32 = ((REG_GPIO_PADREGK.U32) & ~(m)))
#define REG_GPIO_PADREGK_SET(m)                 (REG_GPIO_PADREGK.U32 = ((REG_GPIO_PADREGK.U32) | (m)))
#define REG_GPIO_PADREGK_DEF                    0x18181818

#define BFP_GPIO_PADREGK_RSVD_29                (29)                    /* bitfield lsb */
#define BFM_GPIO_PADREGK_RSVD_29                ((uint32_t)0xe0000000)  /* bitfield mask */
#define BFN_GPIO_PADREGK_RSVD_29                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGK_RSVD_29                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_RSVD_29(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGK_RSVD_29)) & (BFM_GPIO_PADREGK_RSVD_29))
#define BFX_GPIO_PADREGK_RSVD_29(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGK_RSVD_29)) >> (BFP_GPIO_PADREGK_RSVD_29))
#define BFW_GPIO_PADREGK_RSVD_29(v)             (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_RSVD_29)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_RSVD_29)) & (BFM_GPIO_PADREGK_RSVD_29)) ))
#define BFR_GPIO_PADREGK_RSVD_29()              ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_RSVD_29))>>(BFP_GPIO_PADREGK_RSVD_29))

#define BFP_GPIO_PADREGK_PAD43FNCSEL            (27)                    /* bitfield lsb */
#define BFM_GPIO_PADREGK_PAD43FNCSEL            ((uint32_t)0x18000000)  /* bitfield mask */
#define BFN_GPIO_PADREGK_PAD43FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGK_PAD43FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_PAD43FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGK_PAD43FNCSEL)) & (BFM_GPIO_PADREGK_PAD43FNCSEL))
#define BFX_GPIO_PADREGK_PAD43FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGK_PAD43FNCSEL)) >> (BFP_GPIO_PADREGK_PAD43FNCSEL))
#define BFW_GPIO_PADREGK_PAD43FNCSEL(v)         (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_PAD43FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_PAD43FNCSEL)) & (BFM_GPIO_PADREGK_PAD43FNCSEL)) ))
#define BFR_GPIO_PADREGK_PAD43FNCSEL()          ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_PAD43FNCSEL))>>(BFP_GPIO_PADREGK_PAD43FNCSEL))

#define BFP_GPIO_PADREGK_PAD43STRNG             (26)                    /* bitfield lsb */
#define BFM_GPIO_PADREGK_PAD43STRNG             ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_GPIO_PADREGK_PAD43STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGK_PAD43STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_PAD43STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGK_PAD43STRNG)) & (BFM_GPIO_PADREGK_PAD43STRNG))
#define BFX_GPIO_PADREGK_PAD43STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGK_PAD43STRNG)) >> (BFP_GPIO_PADREGK_PAD43STRNG))
#define BFW_GPIO_PADREGK_PAD43STRNG(v)          (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_PAD43STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_PAD43STRNG)) & (BFM_GPIO_PADREGK_PAD43STRNG)) ))
#define BFR_GPIO_PADREGK_PAD43STRNG()           ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_PAD43STRNG))>>(BFP_GPIO_PADREGK_PAD43STRNG))

#define BFP_GPIO_PADREGK_PAD43INPEN             (25)                    /* bitfield lsb */
#define BFM_GPIO_PADREGK_PAD43INPEN             ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_GPIO_PADREGK_PAD43INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGK_PAD43INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_PAD43INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGK_PAD43INPEN)) & (BFM_GPIO_PADREGK_PAD43INPEN))
#define BFX_GPIO_PADREGK_PAD43INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGK_PAD43INPEN)) >> (BFP_GPIO_PADREGK_PAD43INPEN))
#define BFW_GPIO_PADREGK_PAD43INPEN(v)          (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_PAD43INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_PAD43INPEN)) & (BFM_GPIO_PADREGK_PAD43INPEN)) ))
#define BFR_GPIO_PADREGK_PAD43INPEN()           ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_PAD43INPEN))>>(BFP_GPIO_PADREGK_PAD43INPEN))

#define BFP_GPIO_PADREGK_PAD43PULL              (24)                    /* bitfield lsb */
#define BFM_GPIO_PADREGK_PAD43PULL              ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_PADREGK_PAD43PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGK_PAD43PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_PAD43PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGK_PAD43PULL)) & (BFM_GPIO_PADREGK_PAD43PULL))
#define BFX_GPIO_PADREGK_PAD43PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGK_PAD43PULL)) >> (BFP_GPIO_PADREGK_PAD43PULL))
#define BFW_GPIO_PADREGK_PAD43PULL(v)           (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_PAD43PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_PAD43PULL)) & (BFM_GPIO_PADREGK_PAD43PULL)) ))
#define BFR_GPIO_PADREGK_PAD43PULL()            ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_PAD43PULL))>>(BFP_GPIO_PADREGK_PAD43PULL))

#define BFP_GPIO_PADREGK_RSVD_21                (21)                    /* bitfield lsb */
#define BFM_GPIO_PADREGK_RSVD_21                ((uint32_t)0x00e00000)  /* bitfield mask */
#define BFN_GPIO_PADREGK_RSVD_21                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGK_RSVD_21                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_RSVD_21(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGK_RSVD_21)) & (BFM_GPIO_PADREGK_RSVD_21))
#define BFX_GPIO_PADREGK_RSVD_21(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGK_RSVD_21)) >> (BFP_GPIO_PADREGK_RSVD_21))
#define BFW_GPIO_PADREGK_RSVD_21(v)             (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_RSVD_21)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_RSVD_21)) & (BFM_GPIO_PADREGK_RSVD_21)) ))
#define BFR_GPIO_PADREGK_RSVD_21()              ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_RSVD_21))>>(BFP_GPIO_PADREGK_RSVD_21))

#define BFP_GPIO_PADREGK_PAD42FNCSEL            (19)                    /* bitfield lsb */
#define BFM_GPIO_PADREGK_PAD42FNCSEL            ((uint32_t)0x00180000)  /* bitfield mask */
#define BFN_GPIO_PADREGK_PAD42FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGK_PAD42FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_PAD42FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGK_PAD42FNCSEL)) & (BFM_GPIO_PADREGK_PAD42FNCSEL))
#define BFX_GPIO_PADREGK_PAD42FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGK_PAD42FNCSEL)) >> (BFP_GPIO_PADREGK_PAD42FNCSEL))
#define BFW_GPIO_PADREGK_PAD42FNCSEL(v)         (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_PAD42FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_PAD42FNCSEL)) & (BFM_GPIO_PADREGK_PAD42FNCSEL)) ))
#define BFR_GPIO_PADREGK_PAD42FNCSEL()          ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_PAD42FNCSEL))>>(BFP_GPIO_PADREGK_PAD42FNCSEL))

#define BFP_GPIO_PADREGK_PAD42STRNG             (18)                    /* bitfield lsb */
#define BFM_GPIO_PADREGK_PAD42STRNG             ((uint32_t)0x00040000)  /* bitfield mask */
#define BFN_GPIO_PADREGK_PAD42STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGK_PAD42STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_PAD42STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGK_PAD42STRNG)) & (BFM_GPIO_PADREGK_PAD42STRNG))
#define BFX_GPIO_PADREGK_PAD42STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGK_PAD42STRNG)) >> (BFP_GPIO_PADREGK_PAD42STRNG))
#define BFW_GPIO_PADREGK_PAD42STRNG(v)          (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_PAD42STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_PAD42STRNG)) & (BFM_GPIO_PADREGK_PAD42STRNG)) ))
#define BFR_GPIO_PADREGK_PAD42STRNG()           ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_PAD42STRNG))>>(BFP_GPIO_PADREGK_PAD42STRNG))

#define BFP_GPIO_PADREGK_PAD42INPEN             (17)                    /* bitfield lsb */
#define BFM_GPIO_PADREGK_PAD42INPEN             ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_PADREGK_PAD42INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGK_PAD42INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_PAD42INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGK_PAD42INPEN)) & (BFM_GPIO_PADREGK_PAD42INPEN))
#define BFX_GPIO_PADREGK_PAD42INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGK_PAD42INPEN)) >> (BFP_GPIO_PADREGK_PAD42INPEN))
#define BFW_GPIO_PADREGK_PAD42INPEN(v)          (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_PAD42INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_PAD42INPEN)) & (BFM_GPIO_PADREGK_PAD42INPEN)) ))
#define BFR_GPIO_PADREGK_PAD42INPEN()           ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_PAD42INPEN))>>(BFP_GPIO_PADREGK_PAD42INPEN))

#define BFP_GPIO_PADREGK_PAD42PULL              (16)                    /* bitfield lsb */
#define BFM_GPIO_PADREGK_PAD42PULL              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_PADREGK_PAD42PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGK_PAD42PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_PAD42PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGK_PAD42PULL)) & (BFM_GPIO_PADREGK_PAD42PULL))
#define BFX_GPIO_PADREGK_PAD42PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGK_PAD42PULL)) >> (BFP_GPIO_PADREGK_PAD42PULL))
#define BFW_GPIO_PADREGK_PAD42PULL(v)           (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_PAD42PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_PAD42PULL)) & (BFM_GPIO_PADREGK_PAD42PULL)) ))
#define BFR_GPIO_PADREGK_PAD42PULL()            ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_PAD42PULL))>>(BFP_GPIO_PADREGK_PAD42PULL))

#define BFP_GPIO_PADREGK_RSVD_13                (13)                    /* bitfield lsb */
#define BFM_GPIO_PADREGK_RSVD_13                ((uint32_t)0x0000e000)  /* bitfield mask */
#define BFN_GPIO_PADREGK_RSVD_13                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGK_RSVD_13                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_RSVD_13(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGK_RSVD_13)) & (BFM_GPIO_PADREGK_RSVD_13))
#define BFX_GPIO_PADREGK_RSVD_13(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGK_RSVD_13)) >> (BFP_GPIO_PADREGK_RSVD_13))
#define BFW_GPIO_PADREGK_RSVD_13(v)             (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_RSVD_13)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_RSVD_13)) & (BFM_GPIO_PADREGK_RSVD_13)) ))
#define BFR_GPIO_PADREGK_RSVD_13()              ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_RSVD_13))>>(BFP_GPIO_PADREGK_RSVD_13))

#define BFP_GPIO_PADREGK_PAD41FNCSEL            (11)                    /* bitfield lsb */
#define BFM_GPIO_PADREGK_PAD41FNCSEL            ((uint32_t)0x00001800)  /* bitfield mask */
#define BFN_GPIO_PADREGK_PAD41FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGK_PAD41FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_PAD41FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGK_PAD41FNCSEL)) & (BFM_GPIO_PADREGK_PAD41FNCSEL))
#define BFX_GPIO_PADREGK_PAD41FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGK_PAD41FNCSEL)) >> (BFP_GPIO_PADREGK_PAD41FNCSEL))
#define BFW_GPIO_PADREGK_PAD41FNCSEL(v)         (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_PAD41FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_PAD41FNCSEL)) & (BFM_GPIO_PADREGK_PAD41FNCSEL)) ))
#define BFR_GPIO_PADREGK_PAD41FNCSEL()          ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_PAD41FNCSEL))>>(BFP_GPIO_PADREGK_PAD41FNCSEL))

#define BFP_GPIO_PADREGK_PAD41STRNG             (10)                    /* bitfield lsb */
#define BFM_GPIO_PADREGK_PAD41STRNG             ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_PADREGK_PAD41STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGK_PAD41STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_PAD41STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGK_PAD41STRNG)) & (BFM_GPIO_PADREGK_PAD41STRNG))
#define BFX_GPIO_PADREGK_PAD41STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGK_PAD41STRNG)) >> (BFP_GPIO_PADREGK_PAD41STRNG))
#define BFW_GPIO_PADREGK_PAD41STRNG(v)          (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_PAD41STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_PAD41STRNG)) & (BFM_GPIO_PADREGK_PAD41STRNG)) ))
#define BFR_GPIO_PADREGK_PAD41STRNG()           ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_PAD41STRNG))>>(BFP_GPIO_PADREGK_PAD41STRNG))

#define BFP_GPIO_PADREGK_PAD41INPEN             (9)                     /* bitfield lsb */
#define BFM_GPIO_PADREGK_PAD41INPEN             ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_PADREGK_PAD41INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGK_PAD41INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_PAD41INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGK_PAD41INPEN)) & (BFM_GPIO_PADREGK_PAD41INPEN))
#define BFX_GPIO_PADREGK_PAD41INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGK_PAD41INPEN)) >> (BFP_GPIO_PADREGK_PAD41INPEN))
#define BFW_GPIO_PADREGK_PAD41INPEN(v)          (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_PAD41INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_PAD41INPEN)) & (BFM_GPIO_PADREGK_PAD41INPEN)) ))
#define BFR_GPIO_PADREGK_PAD41INPEN()           ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_PAD41INPEN))>>(BFP_GPIO_PADREGK_PAD41INPEN))

#define BFP_GPIO_PADREGK_PAD41PULL              (8)                     /* bitfield lsb */
#define BFM_GPIO_PADREGK_PAD41PULL              ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_PADREGK_PAD41PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGK_PAD41PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_PAD41PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGK_PAD41PULL)) & (BFM_GPIO_PADREGK_PAD41PULL))
#define BFX_GPIO_PADREGK_PAD41PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGK_PAD41PULL)) >> (BFP_GPIO_PADREGK_PAD41PULL))
#define BFW_GPIO_PADREGK_PAD41PULL(v)           (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_PAD41PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_PAD41PULL)) & (BFM_GPIO_PADREGK_PAD41PULL)) ))
#define BFR_GPIO_PADREGK_PAD41PULL()            ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_PAD41PULL))>>(BFP_GPIO_PADREGK_PAD41PULL))

#define BFP_GPIO_PADREGK_RSVD_5                 (5)                     /* bitfield lsb */
#define BFM_GPIO_PADREGK_RSVD_5                 ((uint32_t)0x000000e0)  /* bitfield mask */
#define BFN_GPIO_PADREGK_RSVD_5                 (3)                     /* bitfield width */
#define BFD_GPIO_PADREGK_RSVD_5                 (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_RSVD_5(v)              ((((uint32_t) v) << (BFP_GPIO_PADREGK_RSVD_5)) & (BFM_GPIO_PADREGK_RSVD_5))
#define BFX_GPIO_PADREGK_RSVD_5(v)              ((((uint32_t) v) & (BFM_GPIO_PADREGK_RSVD_5)) >> (BFP_GPIO_PADREGK_RSVD_5))
#define BFW_GPIO_PADREGK_RSVD_5(v)              (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_RSVD_5)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_RSVD_5)) & (BFM_GPIO_PADREGK_RSVD_5)) ))
#define BFR_GPIO_PADREGK_RSVD_5()               ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_RSVD_5))>>(BFP_GPIO_PADREGK_RSVD_5))

#define BFP_GPIO_PADREGK_PAD40FNCSEL            (3)                     /* bitfield lsb */
#define BFM_GPIO_PADREGK_PAD40FNCSEL            ((uint32_t)0x00000018)  /* bitfield mask */
#define BFN_GPIO_PADREGK_PAD40FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGK_PAD40FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_PAD40FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGK_PAD40FNCSEL)) & (BFM_GPIO_PADREGK_PAD40FNCSEL))
#define BFX_GPIO_PADREGK_PAD40FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGK_PAD40FNCSEL)) >> (BFP_GPIO_PADREGK_PAD40FNCSEL))
#define BFW_GPIO_PADREGK_PAD40FNCSEL(v)         (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_PAD40FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_PAD40FNCSEL)) & (BFM_GPIO_PADREGK_PAD40FNCSEL)) ))
#define BFR_GPIO_PADREGK_PAD40FNCSEL()          ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_PAD40FNCSEL))>>(BFP_GPIO_PADREGK_PAD40FNCSEL))

#define BFP_GPIO_PADREGK_PAD40STRNG             (2)                     /* bitfield lsb */
#define BFM_GPIO_PADREGK_PAD40STRNG             ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_PADREGK_PAD40STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGK_PAD40STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_PAD40STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGK_PAD40STRNG)) & (BFM_GPIO_PADREGK_PAD40STRNG))
#define BFX_GPIO_PADREGK_PAD40STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGK_PAD40STRNG)) >> (BFP_GPIO_PADREGK_PAD40STRNG))
#define BFW_GPIO_PADREGK_PAD40STRNG(v)          (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_PAD40STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_PAD40STRNG)) & (BFM_GPIO_PADREGK_PAD40STRNG)) ))
#define BFR_GPIO_PADREGK_PAD40STRNG()           ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_PAD40STRNG))>>(BFP_GPIO_PADREGK_PAD40STRNG))

#define BFP_GPIO_PADREGK_PAD40INPEN             (1)                     /* bitfield lsb */
#define BFM_GPIO_PADREGK_PAD40INPEN             ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_PADREGK_PAD40INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGK_PAD40INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_PAD40INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGK_PAD40INPEN)) & (BFM_GPIO_PADREGK_PAD40INPEN))
#define BFX_GPIO_PADREGK_PAD40INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGK_PAD40INPEN)) >> (BFP_GPIO_PADREGK_PAD40INPEN))
#define BFW_GPIO_PADREGK_PAD40INPEN(v)          (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_PAD40INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_PAD40INPEN)) & (BFM_GPIO_PADREGK_PAD40INPEN)) ))
#define BFR_GPIO_PADREGK_PAD40INPEN()           ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_PAD40INPEN))>>(BFP_GPIO_PADREGK_PAD40INPEN))

#define BFP_GPIO_PADREGK_PAD40PULL              (0)                     /* bitfield lsb */
#define BFM_GPIO_PADREGK_PAD40PULL              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_PADREGK_PAD40PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGK_PAD40PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGK_PAD40PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGK_PAD40PULL)) & (BFM_GPIO_PADREGK_PAD40PULL))
#define BFX_GPIO_PADREGK_PAD40PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGK_PAD40PULL)) >> (BFP_GPIO_PADREGK_PAD40PULL))
#define BFW_GPIO_PADREGK_PAD40PULL(v)           (REG_GPIO_PADREGK.U32 = ( (REG_GPIO_PADREGK.U32 & ~(BFM_GPIO_PADREGK_PAD40PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGK_PAD40PULL)) & (BFM_GPIO_PADREGK_PAD40PULL)) ))
#define BFR_GPIO_PADREGK_PAD40PULL()            ((REG_GPIO_PADREGK.U32 & (BFM_GPIO_PADREGK_PAD40PULL))>>(BFP_GPIO_PADREGK_PAD40PULL))


// *****************************************************************************
//                                                                             *
//  GPIO_PADREGL - Pad Configuration Register L                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_29                    :  3;
        unsigned PAD47FNCSEL                :  2;
        unsigned PAD47STRNG                 :  1;
        unsigned PAD47INPEN                 :  1;
        unsigned PAD47PULL                  :  1;
        unsigned RSVD_21                    :  3;
        unsigned PAD46FNCSEL                :  2;
        unsigned PAD46STRNG                 :  1;
        unsigned PAD46INPEN                 :  1;
        unsigned PAD46PULL                  :  1;
        unsigned RSVD_13                    :  3;
        unsigned PAD45FNCSEL                :  2;
        unsigned PAD45STRNG                 :  1;
        unsigned PAD45INPEN                 :  1;
        unsigned PAD45PULL                  :  1;
        unsigned RSVD_5                     :  3;
        unsigned PAD44FNCSEL                :  2;
        unsigned PAD44STRNG                 :  1;
        unsigned PAD44INPEN                 :  1;
        unsigned PAD44PULL                  :  1;
    } B;
} reg_gpio_padregl_t;

#define REG_GPIO_PADREGL_ADDR                   (REG_GPIO_BASEADDR + 0x0000002CUL)
#define REG_GPIO_PADREGL                        (*(volatile reg_gpio_padregl_t *) REG_GPIO_PADREGL_ADDR)
#define REG_GPIO_PADREGL_RD()                   (REG_GPIO_PADREGL.U32)
#define REG_GPIO_PADREGL_WR(v)                  (REG_GPIO_PADREGL.U32 = (v))
#define REG_GPIO_PADREGL_CLR(m)                 (REG_GPIO_PADREGL.U32 = ((REG_GPIO_PADREGL.U32) & ~(m)))
#define REG_GPIO_PADREGL_SET(m)                 (REG_GPIO_PADREGL.U32 = ((REG_GPIO_PADREGL.U32) | (m)))
#define REG_GPIO_PADREGL_DEF                    0x18181818

#define BFP_GPIO_PADREGL_RSVD_29                (29)                    /* bitfield lsb */
#define BFM_GPIO_PADREGL_RSVD_29                ((uint32_t)0xe0000000)  /* bitfield mask */
#define BFN_GPIO_PADREGL_RSVD_29                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGL_RSVD_29                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_RSVD_29(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGL_RSVD_29)) & (BFM_GPIO_PADREGL_RSVD_29))
#define BFX_GPIO_PADREGL_RSVD_29(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGL_RSVD_29)) >> (BFP_GPIO_PADREGL_RSVD_29))
#define BFW_GPIO_PADREGL_RSVD_29(v)             (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_RSVD_29)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_RSVD_29)) & (BFM_GPIO_PADREGL_RSVD_29)) ))
#define BFR_GPIO_PADREGL_RSVD_29()              ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_RSVD_29))>>(BFP_GPIO_PADREGL_RSVD_29))

#define BFP_GPIO_PADREGL_PAD47FNCSEL            (27)                    /* bitfield lsb */
#define BFM_GPIO_PADREGL_PAD47FNCSEL            ((uint32_t)0x18000000)  /* bitfield mask */
#define BFN_GPIO_PADREGL_PAD47FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGL_PAD47FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_PAD47FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGL_PAD47FNCSEL)) & (BFM_GPIO_PADREGL_PAD47FNCSEL))
#define BFX_GPIO_PADREGL_PAD47FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGL_PAD47FNCSEL)) >> (BFP_GPIO_PADREGL_PAD47FNCSEL))
#define BFW_GPIO_PADREGL_PAD47FNCSEL(v)         (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_PAD47FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_PAD47FNCSEL)) & (BFM_GPIO_PADREGL_PAD47FNCSEL)) ))
#define BFR_GPIO_PADREGL_PAD47FNCSEL()          ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_PAD47FNCSEL))>>(BFP_GPIO_PADREGL_PAD47FNCSEL))

#define BFP_GPIO_PADREGL_PAD47STRNG             (26)                    /* bitfield lsb */
#define BFM_GPIO_PADREGL_PAD47STRNG             ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_GPIO_PADREGL_PAD47STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGL_PAD47STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_PAD47STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGL_PAD47STRNG)) & (BFM_GPIO_PADREGL_PAD47STRNG))
#define BFX_GPIO_PADREGL_PAD47STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGL_PAD47STRNG)) >> (BFP_GPIO_PADREGL_PAD47STRNG))
#define BFW_GPIO_PADREGL_PAD47STRNG(v)          (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_PAD47STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_PAD47STRNG)) & (BFM_GPIO_PADREGL_PAD47STRNG)) ))
#define BFR_GPIO_PADREGL_PAD47STRNG()           ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_PAD47STRNG))>>(BFP_GPIO_PADREGL_PAD47STRNG))

#define BFP_GPIO_PADREGL_PAD47INPEN             (25)                    /* bitfield lsb */
#define BFM_GPIO_PADREGL_PAD47INPEN             ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_GPIO_PADREGL_PAD47INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGL_PAD47INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_PAD47INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGL_PAD47INPEN)) & (BFM_GPIO_PADREGL_PAD47INPEN))
#define BFX_GPIO_PADREGL_PAD47INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGL_PAD47INPEN)) >> (BFP_GPIO_PADREGL_PAD47INPEN))
#define BFW_GPIO_PADREGL_PAD47INPEN(v)          (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_PAD47INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_PAD47INPEN)) & (BFM_GPIO_PADREGL_PAD47INPEN)) ))
#define BFR_GPIO_PADREGL_PAD47INPEN()           ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_PAD47INPEN))>>(BFP_GPIO_PADREGL_PAD47INPEN))

#define BFP_GPIO_PADREGL_PAD47PULL              (24)                    /* bitfield lsb */
#define BFM_GPIO_PADREGL_PAD47PULL              ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_PADREGL_PAD47PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGL_PAD47PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_PAD47PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGL_PAD47PULL)) & (BFM_GPIO_PADREGL_PAD47PULL))
#define BFX_GPIO_PADREGL_PAD47PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGL_PAD47PULL)) >> (BFP_GPIO_PADREGL_PAD47PULL))
#define BFW_GPIO_PADREGL_PAD47PULL(v)           (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_PAD47PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_PAD47PULL)) & (BFM_GPIO_PADREGL_PAD47PULL)) ))
#define BFR_GPIO_PADREGL_PAD47PULL()            ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_PAD47PULL))>>(BFP_GPIO_PADREGL_PAD47PULL))

#define BFP_GPIO_PADREGL_RSVD_21                (21)                    /* bitfield lsb */
#define BFM_GPIO_PADREGL_RSVD_21                ((uint32_t)0x00e00000)  /* bitfield mask */
#define BFN_GPIO_PADREGL_RSVD_21                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGL_RSVD_21                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_RSVD_21(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGL_RSVD_21)) & (BFM_GPIO_PADREGL_RSVD_21))
#define BFX_GPIO_PADREGL_RSVD_21(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGL_RSVD_21)) >> (BFP_GPIO_PADREGL_RSVD_21))
#define BFW_GPIO_PADREGL_RSVD_21(v)             (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_RSVD_21)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_RSVD_21)) & (BFM_GPIO_PADREGL_RSVD_21)) ))
#define BFR_GPIO_PADREGL_RSVD_21()              ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_RSVD_21))>>(BFP_GPIO_PADREGL_RSVD_21))

#define BFP_GPIO_PADREGL_PAD46FNCSEL            (19)                    /* bitfield lsb */
#define BFM_GPIO_PADREGL_PAD46FNCSEL            ((uint32_t)0x00180000)  /* bitfield mask */
#define BFN_GPIO_PADREGL_PAD46FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGL_PAD46FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_PAD46FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGL_PAD46FNCSEL)) & (BFM_GPIO_PADREGL_PAD46FNCSEL))
#define BFX_GPIO_PADREGL_PAD46FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGL_PAD46FNCSEL)) >> (BFP_GPIO_PADREGL_PAD46FNCSEL))
#define BFW_GPIO_PADREGL_PAD46FNCSEL(v)         (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_PAD46FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_PAD46FNCSEL)) & (BFM_GPIO_PADREGL_PAD46FNCSEL)) ))
#define BFR_GPIO_PADREGL_PAD46FNCSEL()          ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_PAD46FNCSEL))>>(BFP_GPIO_PADREGL_PAD46FNCSEL))

#define BFP_GPIO_PADREGL_PAD46STRNG             (18)                    /* bitfield lsb */
#define BFM_GPIO_PADREGL_PAD46STRNG             ((uint32_t)0x00040000)  /* bitfield mask */
#define BFN_GPIO_PADREGL_PAD46STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGL_PAD46STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_PAD46STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGL_PAD46STRNG)) & (BFM_GPIO_PADREGL_PAD46STRNG))
#define BFX_GPIO_PADREGL_PAD46STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGL_PAD46STRNG)) >> (BFP_GPIO_PADREGL_PAD46STRNG))
#define BFW_GPIO_PADREGL_PAD46STRNG(v)          (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_PAD46STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_PAD46STRNG)) & (BFM_GPIO_PADREGL_PAD46STRNG)) ))
#define BFR_GPIO_PADREGL_PAD46STRNG()           ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_PAD46STRNG))>>(BFP_GPIO_PADREGL_PAD46STRNG))

#define BFP_GPIO_PADREGL_PAD46INPEN             (17)                    /* bitfield lsb */
#define BFM_GPIO_PADREGL_PAD46INPEN             ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_PADREGL_PAD46INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGL_PAD46INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_PAD46INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGL_PAD46INPEN)) & (BFM_GPIO_PADREGL_PAD46INPEN))
#define BFX_GPIO_PADREGL_PAD46INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGL_PAD46INPEN)) >> (BFP_GPIO_PADREGL_PAD46INPEN))
#define BFW_GPIO_PADREGL_PAD46INPEN(v)          (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_PAD46INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_PAD46INPEN)) & (BFM_GPIO_PADREGL_PAD46INPEN)) ))
#define BFR_GPIO_PADREGL_PAD46INPEN()           ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_PAD46INPEN))>>(BFP_GPIO_PADREGL_PAD46INPEN))

#define BFP_GPIO_PADREGL_PAD46PULL              (16)                    /* bitfield lsb */
#define BFM_GPIO_PADREGL_PAD46PULL              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_PADREGL_PAD46PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGL_PAD46PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_PAD46PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGL_PAD46PULL)) & (BFM_GPIO_PADREGL_PAD46PULL))
#define BFX_GPIO_PADREGL_PAD46PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGL_PAD46PULL)) >> (BFP_GPIO_PADREGL_PAD46PULL))
#define BFW_GPIO_PADREGL_PAD46PULL(v)           (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_PAD46PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_PAD46PULL)) & (BFM_GPIO_PADREGL_PAD46PULL)) ))
#define BFR_GPIO_PADREGL_PAD46PULL()            ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_PAD46PULL))>>(BFP_GPIO_PADREGL_PAD46PULL))

#define BFP_GPIO_PADREGL_RSVD_13                (13)                    /* bitfield lsb */
#define BFM_GPIO_PADREGL_RSVD_13                ((uint32_t)0x0000e000)  /* bitfield mask */
#define BFN_GPIO_PADREGL_RSVD_13                (3)                     /* bitfield width */
#define BFD_GPIO_PADREGL_RSVD_13                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_RSVD_13(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGL_RSVD_13)) & (BFM_GPIO_PADREGL_RSVD_13))
#define BFX_GPIO_PADREGL_RSVD_13(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGL_RSVD_13)) >> (BFP_GPIO_PADREGL_RSVD_13))
#define BFW_GPIO_PADREGL_RSVD_13(v)             (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_RSVD_13)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_RSVD_13)) & (BFM_GPIO_PADREGL_RSVD_13)) ))
#define BFR_GPIO_PADREGL_RSVD_13()              ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_RSVD_13))>>(BFP_GPIO_PADREGL_RSVD_13))

#define BFP_GPIO_PADREGL_PAD45FNCSEL            (11)                    /* bitfield lsb */
#define BFM_GPIO_PADREGL_PAD45FNCSEL            ((uint32_t)0x00001800)  /* bitfield mask */
#define BFN_GPIO_PADREGL_PAD45FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGL_PAD45FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_PAD45FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGL_PAD45FNCSEL)) & (BFM_GPIO_PADREGL_PAD45FNCSEL))
#define BFX_GPIO_PADREGL_PAD45FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGL_PAD45FNCSEL)) >> (BFP_GPIO_PADREGL_PAD45FNCSEL))
#define BFW_GPIO_PADREGL_PAD45FNCSEL(v)         (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_PAD45FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_PAD45FNCSEL)) & (BFM_GPIO_PADREGL_PAD45FNCSEL)) ))
#define BFR_GPIO_PADREGL_PAD45FNCSEL()          ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_PAD45FNCSEL))>>(BFP_GPIO_PADREGL_PAD45FNCSEL))

#define BFP_GPIO_PADREGL_PAD45STRNG             (10)                    /* bitfield lsb */
#define BFM_GPIO_PADREGL_PAD45STRNG             ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_PADREGL_PAD45STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGL_PAD45STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_PAD45STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGL_PAD45STRNG)) & (BFM_GPIO_PADREGL_PAD45STRNG))
#define BFX_GPIO_PADREGL_PAD45STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGL_PAD45STRNG)) >> (BFP_GPIO_PADREGL_PAD45STRNG))
#define BFW_GPIO_PADREGL_PAD45STRNG(v)          (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_PAD45STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_PAD45STRNG)) & (BFM_GPIO_PADREGL_PAD45STRNG)) ))
#define BFR_GPIO_PADREGL_PAD45STRNG()           ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_PAD45STRNG))>>(BFP_GPIO_PADREGL_PAD45STRNG))

#define BFP_GPIO_PADREGL_PAD45INPEN             (9)                     /* bitfield lsb */
#define BFM_GPIO_PADREGL_PAD45INPEN             ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_PADREGL_PAD45INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGL_PAD45INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_PAD45INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGL_PAD45INPEN)) & (BFM_GPIO_PADREGL_PAD45INPEN))
#define BFX_GPIO_PADREGL_PAD45INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGL_PAD45INPEN)) >> (BFP_GPIO_PADREGL_PAD45INPEN))
#define BFW_GPIO_PADREGL_PAD45INPEN(v)          (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_PAD45INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_PAD45INPEN)) & (BFM_GPIO_PADREGL_PAD45INPEN)) ))
#define BFR_GPIO_PADREGL_PAD45INPEN()           ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_PAD45INPEN))>>(BFP_GPIO_PADREGL_PAD45INPEN))

#define BFP_GPIO_PADREGL_PAD45PULL              (8)                     /* bitfield lsb */
#define BFM_GPIO_PADREGL_PAD45PULL              ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_PADREGL_PAD45PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGL_PAD45PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_PAD45PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGL_PAD45PULL)) & (BFM_GPIO_PADREGL_PAD45PULL))
#define BFX_GPIO_PADREGL_PAD45PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGL_PAD45PULL)) >> (BFP_GPIO_PADREGL_PAD45PULL))
#define BFW_GPIO_PADREGL_PAD45PULL(v)           (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_PAD45PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_PAD45PULL)) & (BFM_GPIO_PADREGL_PAD45PULL)) ))
#define BFR_GPIO_PADREGL_PAD45PULL()            ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_PAD45PULL))>>(BFP_GPIO_PADREGL_PAD45PULL))

#define BFP_GPIO_PADREGL_RSVD_5                 (5)                     /* bitfield lsb */
#define BFM_GPIO_PADREGL_RSVD_5                 ((uint32_t)0x000000e0)  /* bitfield mask */
#define BFN_GPIO_PADREGL_RSVD_5                 (3)                     /* bitfield width */
#define BFD_GPIO_PADREGL_RSVD_5                 (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_RSVD_5(v)              ((((uint32_t) v) << (BFP_GPIO_PADREGL_RSVD_5)) & (BFM_GPIO_PADREGL_RSVD_5))
#define BFX_GPIO_PADREGL_RSVD_5(v)              ((((uint32_t) v) & (BFM_GPIO_PADREGL_RSVD_5)) >> (BFP_GPIO_PADREGL_RSVD_5))
#define BFW_GPIO_PADREGL_RSVD_5(v)              (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_RSVD_5)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_RSVD_5)) & (BFM_GPIO_PADREGL_RSVD_5)) ))
#define BFR_GPIO_PADREGL_RSVD_5()               ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_RSVD_5))>>(BFP_GPIO_PADREGL_RSVD_5))

#define BFP_GPIO_PADREGL_PAD44FNCSEL            (3)                     /* bitfield lsb */
#define BFM_GPIO_PADREGL_PAD44FNCSEL            ((uint32_t)0x00000018)  /* bitfield mask */
#define BFN_GPIO_PADREGL_PAD44FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGL_PAD44FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_PAD44FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGL_PAD44FNCSEL)) & (BFM_GPIO_PADREGL_PAD44FNCSEL))
#define BFX_GPIO_PADREGL_PAD44FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGL_PAD44FNCSEL)) >> (BFP_GPIO_PADREGL_PAD44FNCSEL))
#define BFW_GPIO_PADREGL_PAD44FNCSEL(v)         (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_PAD44FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_PAD44FNCSEL)) & (BFM_GPIO_PADREGL_PAD44FNCSEL)) ))
#define BFR_GPIO_PADREGL_PAD44FNCSEL()          ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_PAD44FNCSEL))>>(BFP_GPIO_PADREGL_PAD44FNCSEL))

#define BFP_GPIO_PADREGL_PAD44STRNG             (2)                     /* bitfield lsb */
#define BFM_GPIO_PADREGL_PAD44STRNG             ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_PADREGL_PAD44STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGL_PAD44STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_PAD44STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGL_PAD44STRNG)) & (BFM_GPIO_PADREGL_PAD44STRNG))
#define BFX_GPIO_PADREGL_PAD44STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGL_PAD44STRNG)) >> (BFP_GPIO_PADREGL_PAD44STRNG))
#define BFW_GPIO_PADREGL_PAD44STRNG(v)          (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_PAD44STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_PAD44STRNG)) & (BFM_GPIO_PADREGL_PAD44STRNG)) ))
#define BFR_GPIO_PADREGL_PAD44STRNG()           ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_PAD44STRNG))>>(BFP_GPIO_PADREGL_PAD44STRNG))

#define BFP_GPIO_PADREGL_PAD44INPEN             (1)                     /* bitfield lsb */
#define BFM_GPIO_PADREGL_PAD44INPEN             ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_PADREGL_PAD44INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGL_PAD44INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_PAD44INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGL_PAD44INPEN)) & (BFM_GPIO_PADREGL_PAD44INPEN))
#define BFX_GPIO_PADREGL_PAD44INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGL_PAD44INPEN)) >> (BFP_GPIO_PADREGL_PAD44INPEN))
#define BFW_GPIO_PADREGL_PAD44INPEN(v)          (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_PAD44INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_PAD44INPEN)) & (BFM_GPIO_PADREGL_PAD44INPEN)) ))
#define BFR_GPIO_PADREGL_PAD44INPEN()           ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_PAD44INPEN))>>(BFP_GPIO_PADREGL_PAD44INPEN))

#define BFP_GPIO_PADREGL_PAD44PULL              (0)                     /* bitfield lsb */
#define BFM_GPIO_PADREGL_PAD44PULL              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_PADREGL_PAD44PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGL_PAD44PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGL_PAD44PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGL_PAD44PULL)) & (BFM_GPIO_PADREGL_PAD44PULL))
#define BFX_GPIO_PADREGL_PAD44PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGL_PAD44PULL)) >> (BFP_GPIO_PADREGL_PAD44PULL))
#define BFW_GPIO_PADREGL_PAD44PULL(v)           (REG_GPIO_PADREGL.U32 = ( (REG_GPIO_PADREGL.U32 & ~(BFM_GPIO_PADREGL_PAD44PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGL_PAD44PULL)) & (BFM_GPIO_PADREGL_PAD44PULL)) ))
#define BFR_GPIO_PADREGL_PAD44PULL()            ((REG_GPIO_PADREGL.U32 & (BFM_GPIO_PADREGL_PAD44PULL))>>(BFP_GPIO_PADREGL_PAD44PULL))


// *****************************************************************************
//                                                                             *
//  GPIO_PADREGM - Pad Configuration Register M                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_13                    : 19;
        unsigned PAD49FNCSEL                :  2;
        unsigned PAD49STRNG                 :  1;
        unsigned PAD49INPEN                 :  1;
        unsigned PAD49PULL                  :  1;
        unsigned RSVD_5                     :  3;
        unsigned PAD48FNCSEL                :  2;
        unsigned PAD48STRNG                 :  1;
        unsigned PAD48INPEN                 :  1;
        unsigned PAD48PULL                  :  1;
    } B;
} reg_gpio_padregm_t;

#define REG_GPIO_PADREGM_ADDR                   (REG_GPIO_BASEADDR + 0x00000030UL)
#define REG_GPIO_PADREGM                        (*(volatile reg_gpio_padregm_t *) REG_GPIO_PADREGM_ADDR)
#define REG_GPIO_PADREGM_RD()                   (REG_GPIO_PADREGM.U32)
#define REG_GPIO_PADREGM_WR(v)                  (REG_GPIO_PADREGM.U32 = (v))
#define REG_GPIO_PADREGM_CLR(m)                 (REG_GPIO_PADREGM.U32 = ((REG_GPIO_PADREGM.U32) & ~(m)))
#define REG_GPIO_PADREGM_SET(m)                 (REG_GPIO_PADREGM.U32 = ((REG_GPIO_PADREGM.U32) | (m)))
#define REG_GPIO_PADREGM_DEF                    0x00001818

#define BFP_GPIO_PADREGM_RSVD_13                (13)                    /* bitfield lsb */
#define BFM_GPIO_PADREGM_RSVD_13                ((uint32_t)0xffffe000)  /* bitfield mask */
#define BFN_GPIO_PADREGM_RSVD_13                (19)                    /* bitfield width */
#define BFD_GPIO_PADREGM_RSVD_13                (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGM_RSVD_13(v)             ((((uint32_t) v) << (BFP_GPIO_PADREGM_RSVD_13)) & (BFM_GPIO_PADREGM_RSVD_13))
#define BFX_GPIO_PADREGM_RSVD_13(v)             ((((uint32_t) v) & (BFM_GPIO_PADREGM_RSVD_13)) >> (BFP_GPIO_PADREGM_RSVD_13))
#define BFW_GPIO_PADREGM_RSVD_13(v)             (REG_GPIO_PADREGM.U32 = ( (REG_GPIO_PADREGM.U32 & ~(BFM_GPIO_PADREGM_RSVD_13)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGM_RSVD_13)) & (BFM_GPIO_PADREGM_RSVD_13)) ))
#define BFR_GPIO_PADREGM_RSVD_13()              ((REG_GPIO_PADREGM.U32 & (BFM_GPIO_PADREGM_RSVD_13))>>(BFP_GPIO_PADREGM_RSVD_13))

#define BFP_GPIO_PADREGM_PAD49FNCSEL            (11)                    /* bitfield lsb */
#define BFM_GPIO_PADREGM_PAD49FNCSEL            ((uint32_t)0x00001800)  /* bitfield mask */
#define BFN_GPIO_PADREGM_PAD49FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGM_PAD49FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGM_PAD49FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGM_PAD49FNCSEL)) & (BFM_GPIO_PADREGM_PAD49FNCSEL))
#define BFX_GPIO_PADREGM_PAD49FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGM_PAD49FNCSEL)) >> (BFP_GPIO_PADREGM_PAD49FNCSEL))
#define BFW_GPIO_PADREGM_PAD49FNCSEL(v)         (REG_GPIO_PADREGM.U32 = ( (REG_GPIO_PADREGM.U32 & ~(BFM_GPIO_PADREGM_PAD49FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGM_PAD49FNCSEL)) & (BFM_GPIO_PADREGM_PAD49FNCSEL)) ))
#define BFR_GPIO_PADREGM_PAD49FNCSEL()          ((REG_GPIO_PADREGM.U32 & (BFM_GPIO_PADREGM_PAD49FNCSEL))>>(BFP_GPIO_PADREGM_PAD49FNCSEL))

#define BFP_GPIO_PADREGM_PAD49STRNG             (10)                    /* bitfield lsb */
#define BFM_GPIO_PADREGM_PAD49STRNG             ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_PADREGM_PAD49STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGM_PAD49STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGM_PAD49STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGM_PAD49STRNG)) & (BFM_GPIO_PADREGM_PAD49STRNG))
#define BFX_GPIO_PADREGM_PAD49STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGM_PAD49STRNG)) >> (BFP_GPIO_PADREGM_PAD49STRNG))
#define BFW_GPIO_PADREGM_PAD49STRNG(v)          (REG_GPIO_PADREGM.U32 = ( (REG_GPIO_PADREGM.U32 & ~(BFM_GPIO_PADREGM_PAD49STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGM_PAD49STRNG)) & (BFM_GPIO_PADREGM_PAD49STRNG)) ))
#define BFR_GPIO_PADREGM_PAD49STRNG()           ((REG_GPIO_PADREGM.U32 & (BFM_GPIO_PADREGM_PAD49STRNG))>>(BFP_GPIO_PADREGM_PAD49STRNG))

#define BFP_GPIO_PADREGM_PAD49INPEN             (9)                     /* bitfield lsb */
#define BFM_GPIO_PADREGM_PAD49INPEN             ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_PADREGM_PAD49INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGM_PAD49INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGM_PAD49INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGM_PAD49INPEN)) & (BFM_GPIO_PADREGM_PAD49INPEN))
#define BFX_GPIO_PADREGM_PAD49INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGM_PAD49INPEN)) >> (BFP_GPIO_PADREGM_PAD49INPEN))
#define BFW_GPIO_PADREGM_PAD49INPEN(v)          (REG_GPIO_PADREGM.U32 = ( (REG_GPIO_PADREGM.U32 & ~(BFM_GPIO_PADREGM_PAD49INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGM_PAD49INPEN)) & (BFM_GPIO_PADREGM_PAD49INPEN)) ))
#define BFR_GPIO_PADREGM_PAD49INPEN()           ((REG_GPIO_PADREGM.U32 & (BFM_GPIO_PADREGM_PAD49INPEN))>>(BFP_GPIO_PADREGM_PAD49INPEN))

#define BFP_GPIO_PADREGM_PAD49PULL              (8)                     /* bitfield lsb */
#define BFM_GPIO_PADREGM_PAD49PULL              ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_PADREGM_PAD49PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGM_PAD49PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGM_PAD49PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGM_PAD49PULL)) & (BFM_GPIO_PADREGM_PAD49PULL))
#define BFX_GPIO_PADREGM_PAD49PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGM_PAD49PULL)) >> (BFP_GPIO_PADREGM_PAD49PULL))
#define BFW_GPIO_PADREGM_PAD49PULL(v)           (REG_GPIO_PADREGM.U32 = ( (REG_GPIO_PADREGM.U32 & ~(BFM_GPIO_PADREGM_PAD49PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGM_PAD49PULL)) & (BFM_GPIO_PADREGM_PAD49PULL)) ))
#define BFR_GPIO_PADREGM_PAD49PULL()            ((REG_GPIO_PADREGM.U32 & (BFM_GPIO_PADREGM_PAD49PULL))>>(BFP_GPIO_PADREGM_PAD49PULL))

#define BFP_GPIO_PADREGM_RSVD_5                 (5)                     /* bitfield lsb */
#define BFM_GPIO_PADREGM_RSVD_5                 ((uint32_t)0x000000e0)  /* bitfield mask */
#define BFN_GPIO_PADREGM_RSVD_5                 (3)                     /* bitfield width */
#define BFD_GPIO_PADREGM_RSVD_5                 (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGM_RSVD_5(v)              ((((uint32_t) v) << (BFP_GPIO_PADREGM_RSVD_5)) & (BFM_GPIO_PADREGM_RSVD_5))
#define BFX_GPIO_PADREGM_RSVD_5(v)              ((((uint32_t) v) & (BFM_GPIO_PADREGM_RSVD_5)) >> (BFP_GPIO_PADREGM_RSVD_5))
#define BFW_GPIO_PADREGM_RSVD_5(v)              (REG_GPIO_PADREGM.U32 = ( (REG_GPIO_PADREGM.U32 & ~(BFM_GPIO_PADREGM_RSVD_5)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGM_RSVD_5)) & (BFM_GPIO_PADREGM_RSVD_5)) ))
#define BFR_GPIO_PADREGM_RSVD_5()               ((REG_GPIO_PADREGM.U32 & (BFM_GPIO_PADREGM_RSVD_5))>>(BFP_GPIO_PADREGM_RSVD_5))

#define BFP_GPIO_PADREGM_PAD48FNCSEL            (3)                     /* bitfield lsb */
#define BFM_GPIO_PADREGM_PAD48FNCSEL            ((uint32_t)0x00000018)  /* bitfield mask */
#define BFN_GPIO_PADREGM_PAD48FNCSEL            (2)                     /* bitfield width */
#define BFD_GPIO_PADREGM_PAD48FNCSEL            (0x3)                   /* bitfield default value */
#define BFV_GPIO_PADREGM_PAD48FNCSEL(v)         ((((uint32_t) v) << (BFP_GPIO_PADREGM_PAD48FNCSEL)) & (BFM_GPIO_PADREGM_PAD48FNCSEL))
#define BFX_GPIO_PADREGM_PAD48FNCSEL(v)         ((((uint32_t) v) & (BFM_GPIO_PADREGM_PAD48FNCSEL)) >> (BFP_GPIO_PADREGM_PAD48FNCSEL))
#define BFW_GPIO_PADREGM_PAD48FNCSEL(v)         (REG_GPIO_PADREGM.U32 = ( (REG_GPIO_PADREGM.U32 & ~(BFM_GPIO_PADREGM_PAD48FNCSEL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGM_PAD48FNCSEL)) & (BFM_GPIO_PADREGM_PAD48FNCSEL)) ))
#define BFR_GPIO_PADREGM_PAD48FNCSEL()          ((REG_GPIO_PADREGM.U32 & (BFM_GPIO_PADREGM_PAD48FNCSEL))>>(BFP_GPIO_PADREGM_PAD48FNCSEL))

#define BFP_GPIO_PADREGM_PAD48STRNG             (2)                     /* bitfield lsb */
#define BFM_GPIO_PADREGM_PAD48STRNG             ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_PADREGM_PAD48STRNG             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGM_PAD48STRNG             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGM_PAD48STRNG(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGM_PAD48STRNG)) & (BFM_GPIO_PADREGM_PAD48STRNG))
#define BFX_GPIO_PADREGM_PAD48STRNG(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGM_PAD48STRNG)) >> (BFP_GPIO_PADREGM_PAD48STRNG))
#define BFW_GPIO_PADREGM_PAD48STRNG(v)          (REG_GPIO_PADREGM.U32 = ( (REG_GPIO_PADREGM.U32 & ~(BFM_GPIO_PADREGM_PAD48STRNG)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGM_PAD48STRNG)) & (BFM_GPIO_PADREGM_PAD48STRNG)) ))
#define BFR_GPIO_PADREGM_PAD48STRNG()           ((REG_GPIO_PADREGM.U32 & (BFM_GPIO_PADREGM_PAD48STRNG))>>(BFP_GPIO_PADREGM_PAD48STRNG))

#define BFP_GPIO_PADREGM_PAD48INPEN             (1)                     /* bitfield lsb */
#define BFM_GPIO_PADREGM_PAD48INPEN             ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_PADREGM_PAD48INPEN             (1)                     /* bitfield width */
#define BFD_GPIO_PADREGM_PAD48INPEN             (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGM_PAD48INPEN(v)          ((((uint32_t) v) << (BFP_GPIO_PADREGM_PAD48INPEN)) & (BFM_GPIO_PADREGM_PAD48INPEN))
#define BFX_GPIO_PADREGM_PAD48INPEN(v)          ((((uint32_t) v) & (BFM_GPIO_PADREGM_PAD48INPEN)) >> (BFP_GPIO_PADREGM_PAD48INPEN))
#define BFW_GPIO_PADREGM_PAD48INPEN(v)          (REG_GPIO_PADREGM.U32 = ( (REG_GPIO_PADREGM.U32 & ~(BFM_GPIO_PADREGM_PAD48INPEN)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGM_PAD48INPEN)) & (BFM_GPIO_PADREGM_PAD48INPEN)) ))
#define BFR_GPIO_PADREGM_PAD48INPEN()           ((REG_GPIO_PADREGM.U32 & (BFM_GPIO_PADREGM_PAD48INPEN))>>(BFP_GPIO_PADREGM_PAD48INPEN))

#define BFP_GPIO_PADREGM_PAD48PULL              (0)                     /* bitfield lsb */
#define BFM_GPIO_PADREGM_PAD48PULL              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_PADREGM_PAD48PULL              (1)                     /* bitfield width */
#define BFD_GPIO_PADREGM_PAD48PULL              (0x0)                   /* bitfield default value */
#define BFV_GPIO_PADREGM_PAD48PULL(v)           ((((uint32_t) v) << (BFP_GPIO_PADREGM_PAD48PULL)) & (BFM_GPIO_PADREGM_PAD48PULL))
#define BFX_GPIO_PADREGM_PAD48PULL(v)           ((((uint32_t) v) & (BFM_GPIO_PADREGM_PAD48PULL)) >> (BFP_GPIO_PADREGM_PAD48PULL))
#define BFW_GPIO_PADREGM_PAD48PULL(v)           (REG_GPIO_PADREGM.U32 = ( (REG_GPIO_PADREGM.U32 & ~(BFM_GPIO_PADREGM_PAD48PULL)) | ((((uint32_t) v)<<(BFP_GPIO_PADREGM_PAD48PULL)) & (BFM_GPIO_PADREGM_PAD48PULL)) ))
#define BFR_GPIO_PADREGM_PAD48PULL()            ((REG_GPIO_PADREGM.U32 & (BFM_GPIO_PADREGM_PAD48PULL))>>(BFP_GPIO_PADREGM_PAD48PULL))


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOCFGA - GPIO Configuration Register A                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned GPIO7INTD                  :  1;
        unsigned GPIO7OUTCFG                :  2;
        unsigned GPIO7INCFG                 :  1;
        unsigned GPIO6INTD                  :  1;
        unsigned GPIO6OUTCFG                :  2;
        unsigned GPIO6INCFG                 :  1;
        unsigned GPIO5INTD                  :  1;
        unsigned GPIO5OUTCFG                :  2;
        unsigned GPIO5INCFG                 :  1;
        unsigned GPIO4INTD                  :  1;
        unsigned GPIO4OUTCFG                :  2;
        unsigned GPIO4INCFG                 :  1;
        unsigned GPIO3INTD                  :  1;
        unsigned GPIO3OUTCFG                :  2;
        unsigned GPIO3INCFG                 :  1;
        unsigned GPIO2INTD                  :  1;
        unsigned GPIO2OUTCFG                :  2;
        unsigned GPIO2INCFG                 :  1;
        unsigned GPIO1INTD                  :  1;
        unsigned GPIO1OUTCFG                :  2;
        unsigned GPIO1INCFG                 :  1;
        unsigned GPIO0INTD                  :  1;
        unsigned GPIO0OUTCFG                :  2;
        unsigned GPIO0INCFG                 :  1;
    } B;
} reg_gpio_gpiocfga_t;

#define REG_GPIO_GPIOCFGA_ADDR                  (REG_GPIO_BASEADDR + 0x00000040UL)
#define REG_GPIO_GPIOCFGA                       (*(volatile reg_gpio_gpiocfga_t *) REG_GPIO_GPIOCFGA_ADDR)
#define REG_GPIO_GPIOCFGA_RD()                  (REG_GPIO_GPIOCFGA.U32)
#define REG_GPIO_GPIOCFGA_WR(v)                 (REG_GPIO_GPIOCFGA.U32 = (v))
#define REG_GPIO_GPIOCFGA_CLR(m)                (REG_GPIO_GPIOCFGA.U32 = ((REG_GPIO_GPIOCFGA.U32) & ~(m)))
#define REG_GPIO_GPIOCFGA_SET(m)                (REG_GPIO_GPIOCFGA.U32 = ((REG_GPIO_GPIOCFGA.U32) | (m)))
#define REG_GPIO_GPIOCFGA_DEF                   0x00000000

#define BFP_GPIO_GPIOCFGA_GPIO7INTD             (31)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO7INTD             ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO7INTD             (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO7INTD             (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO7INTD(v)          ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO7INTD)) & (BFM_GPIO_GPIOCFGA_GPIO7INTD))
#define BFX_GPIO_GPIOCFGA_GPIO7INTD(v)          ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO7INTD)) >> (BFP_GPIO_GPIOCFGA_GPIO7INTD))
#define BFW_GPIO_GPIOCFGA_GPIO7INTD(v)          (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO7INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO7INTD)) & (BFM_GPIO_GPIOCFGA_GPIO7INTD)) ))
#define BFR_GPIO_GPIOCFGA_GPIO7INTD()           ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO7INTD))>>(BFP_GPIO_GPIOCFGA_GPIO7INTD))

#define BFP_GPIO_GPIOCFGA_GPIO7OUTCFG           (29)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO7OUTCFG           ((uint32_t)0x60000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO7OUTCFG           (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO7OUTCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO7OUTCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO7OUTCFG)) & (BFM_GPIO_GPIOCFGA_GPIO7OUTCFG))
#define BFX_GPIO_GPIOCFGA_GPIO7OUTCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO7OUTCFG)) >> (BFP_GPIO_GPIOCFGA_GPIO7OUTCFG))
#define BFW_GPIO_GPIOCFGA_GPIO7OUTCFG(v)        (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO7OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO7OUTCFG)) & (BFM_GPIO_GPIOCFGA_GPIO7OUTCFG)) ))
#define BFR_GPIO_GPIOCFGA_GPIO7OUTCFG()         ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO7OUTCFG))>>(BFP_GPIO_GPIOCFGA_GPIO7OUTCFG))

#define BFP_GPIO_GPIOCFGA_GPIO7INCFG            (28)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO7INCFG            ((uint32_t)0x10000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO7INCFG            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO7INCFG            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO7INCFG(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO7INCFG)) & (BFM_GPIO_GPIOCFGA_GPIO7INCFG))
#define BFX_GPIO_GPIOCFGA_GPIO7INCFG(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO7INCFG)) >> (BFP_GPIO_GPIOCFGA_GPIO7INCFG))
#define BFW_GPIO_GPIOCFGA_GPIO7INCFG(v)         (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO7INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO7INCFG)) & (BFM_GPIO_GPIOCFGA_GPIO7INCFG)) ))
#define BFR_GPIO_GPIOCFGA_GPIO7INCFG()          ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO7INCFG))>>(BFP_GPIO_GPIOCFGA_GPIO7INCFG))

#define BFP_GPIO_GPIOCFGA_GPIO6INTD             (27)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO6INTD             ((uint32_t)0x08000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO6INTD             (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO6INTD             (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO6INTD(v)          ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO6INTD)) & (BFM_GPIO_GPIOCFGA_GPIO6INTD))
#define BFX_GPIO_GPIOCFGA_GPIO6INTD(v)          ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO6INTD)) >> (BFP_GPIO_GPIOCFGA_GPIO6INTD))
#define BFW_GPIO_GPIOCFGA_GPIO6INTD(v)          (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO6INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO6INTD)) & (BFM_GPIO_GPIOCFGA_GPIO6INTD)) ))
#define BFR_GPIO_GPIOCFGA_GPIO6INTD()           ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO6INTD))>>(BFP_GPIO_GPIOCFGA_GPIO6INTD))

#define BFP_GPIO_GPIOCFGA_GPIO6OUTCFG           (25)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO6OUTCFG           ((uint32_t)0x06000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO6OUTCFG           (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO6OUTCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO6OUTCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO6OUTCFG)) & (BFM_GPIO_GPIOCFGA_GPIO6OUTCFG))
#define BFX_GPIO_GPIOCFGA_GPIO6OUTCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO6OUTCFG)) >> (BFP_GPIO_GPIOCFGA_GPIO6OUTCFG))
#define BFW_GPIO_GPIOCFGA_GPIO6OUTCFG(v)        (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO6OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO6OUTCFG)) & (BFM_GPIO_GPIOCFGA_GPIO6OUTCFG)) ))
#define BFR_GPIO_GPIOCFGA_GPIO6OUTCFG()         ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO6OUTCFG))>>(BFP_GPIO_GPIOCFGA_GPIO6OUTCFG))

#define BFP_GPIO_GPIOCFGA_GPIO6INCFG            (24)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO6INCFG            ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO6INCFG            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO6INCFG            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO6INCFG(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO6INCFG)) & (BFM_GPIO_GPIOCFGA_GPIO6INCFG))
#define BFX_GPIO_GPIOCFGA_GPIO6INCFG(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO6INCFG)) >> (BFP_GPIO_GPIOCFGA_GPIO6INCFG))
#define BFW_GPIO_GPIOCFGA_GPIO6INCFG(v)         (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO6INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO6INCFG)) & (BFM_GPIO_GPIOCFGA_GPIO6INCFG)) ))
#define BFR_GPIO_GPIOCFGA_GPIO6INCFG()          ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO6INCFG))>>(BFP_GPIO_GPIOCFGA_GPIO6INCFG))

#define BFP_GPIO_GPIOCFGA_GPIO5INTD             (23)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO5INTD             ((uint32_t)0x00800000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO5INTD             (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO5INTD             (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO5INTD(v)          ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO5INTD)) & (BFM_GPIO_GPIOCFGA_GPIO5INTD))
#define BFX_GPIO_GPIOCFGA_GPIO5INTD(v)          ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO5INTD)) >> (BFP_GPIO_GPIOCFGA_GPIO5INTD))
#define BFW_GPIO_GPIOCFGA_GPIO5INTD(v)          (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO5INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO5INTD)) & (BFM_GPIO_GPIOCFGA_GPIO5INTD)) ))
#define BFR_GPIO_GPIOCFGA_GPIO5INTD()           ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO5INTD))>>(BFP_GPIO_GPIOCFGA_GPIO5INTD))

#define BFP_GPIO_GPIOCFGA_GPIO5OUTCFG           (21)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO5OUTCFG           ((uint32_t)0x00600000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO5OUTCFG           (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO5OUTCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO5OUTCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO5OUTCFG)) & (BFM_GPIO_GPIOCFGA_GPIO5OUTCFG))
#define BFX_GPIO_GPIOCFGA_GPIO5OUTCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO5OUTCFG)) >> (BFP_GPIO_GPIOCFGA_GPIO5OUTCFG))
#define BFW_GPIO_GPIOCFGA_GPIO5OUTCFG(v)        (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO5OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO5OUTCFG)) & (BFM_GPIO_GPIOCFGA_GPIO5OUTCFG)) ))
#define BFR_GPIO_GPIOCFGA_GPIO5OUTCFG()         ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO5OUTCFG))>>(BFP_GPIO_GPIOCFGA_GPIO5OUTCFG))

#define BFP_GPIO_GPIOCFGA_GPIO5INCFG            (20)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO5INCFG            ((uint32_t)0x00100000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO5INCFG            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO5INCFG            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO5INCFG(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO5INCFG)) & (BFM_GPIO_GPIOCFGA_GPIO5INCFG))
#define BFX_GPIO_GPIOCFGA_GPIO5INCFG(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO5INCFG)) >> (BFP_GPIO_GPIOCFGA_GPIO5INCFG))
#define BFW_GPIO_GPIOCFGA_GPIO5INCFG(v)         (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO5INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO5INCFG)) & (BFM_GPIO_GPIOCFGA_GPIO5INCFG)) ))
#define BFR_GPIO_GPIOCFGA_GPIO5INCFG()          ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO5INCFG))>>(BFP_GPIO_GPIOCFGA_GPIO5INCFG))

#define BFP_GPIO_GPIOCFGA_GPIO4INTD             (19)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO4INTD             ((uint32_t)0x00080000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO4INTD             (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO4INTD             (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO4INTD(v)          ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO4INTD)) & (BFM_GPIO_GPIOCFGA_GPIO4INTD))
#define BFX_GPIO_GPIOCFGA_GPIO4INTD(v)          ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO4INTD)) >> (BFP_GPIO_GPIOCFGA_GPIO4INTD))
#define BFW_GPIO_GPIOCFGA_GPIO4INTD(v)          (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO4INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO4INTD)) & (BFM_GPIO_GPIOCFGA_GPIO4INTD)) ))
#define BFR_GPIO_GPIOCFGA_GPIO4INTD()           ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO4INTD))>>(BFP_GPIO_GPIOCFGA_GPIO4INTD))

#define BFP_GPIO_GPIOCFGA_GPIO4OUTCFG           (17)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO4OUTCFG           ((uint32_t)0x00060000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO4OUTCFG           (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO4OUTCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO4OUTCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO4OUTCFG)) & (BFM_GPIO_GPIOCFGA_GPIO4OUTCFG))
#define BFX_GPIO_GPIOCFGA_GPIO4OUTCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO4OUTCFG)) >> (BFP_GPIO_GPIOCFGA_GPIO4OUTCFG))
#define BFW_GPIO_GPIOCFGA_GPIO4OUTCFG(v)        (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO4OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO4OUTCFG)) & (BFM_GPIO_GPIOCFGA_GPIO4OUTCFG)) ))
#define BFR_GPIO_GPIOCFGA_GPIO4OUTCFG()         ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO4OUTCFG))>>(BFP_GPIO_GPIOCFGA_GPIO4OUTCFG))

#define BFP_GPIO_GPIOCFGA_GPIO4INCFG            (16)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO4INCFG            ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO4INCFG            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO4INCFG            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO4INCFG(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO4INCFG)) & (BFM_GPIO_GPIOCFGA_GPIO4INCFG))
#define BFX_GPIO_GPIOCFGA_GPIO4INCFG(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO4INCFG)) >> (BFP_GPIO_GPIOCFGA_GPIO4INCFG))
#define BFW_GPIO_GPIOCFGA_GPIO4INCFG(v)         (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO4INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO4INCFG)) & (BFM_GPIO_GPIOCFGA_GPIO4INCFG)) ))
#define BFR_GPIO_GPIOCFGA_GPIO4INCFG()          ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO4INCFG))>>(BFP_GPIO_GPIOCFGA_GPIO4INCFG))

#define BFP_GPIO_GPIOCFGA_GPIO3INTD             (15)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO3INTD             ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO3INTD             (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO3INTD             (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO3INTD(v)          ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO3INTD)) & (BFM_GPIO_GPIOCFGA_GPIO3INTD))
#define BFX_GPIO_GPIOCFGA_GPIO3INTD(v)          ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO3INTD)) >> (BFP_GPIO_GPIOCFGA_GPIO3INTD))
#define BFW_GPIO_GPIOCFGA_GPIO3INTD(v)          (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO3INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO3INTD)) & (BFM_GPIO_GPIOCFGA_GPIO3INTD)) ))
#define BFR_GPIO_GPIOCFGA_GPIO3INTD()           ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO3INTD))>>(BFP_GPIO_GPIOCFGA_GPIO3INTD))

#define BFP_GPIO_GPIOCFGA_GPIO3OUTCFG           (13)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO3OUTCFG           ((uint32_t)0x00006000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO3OUTCFG           (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO3OUTCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO3OUTCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO3OUTCFG)) & (BFM_GPIO_GPIOCFGA_GPIO3OUTCFG))
#define BFX_GPIO_GPIOCFGA_GPIO3OUTCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO3OUTCFG)) >> (BFP_GPIO_GPIOCFGA_GPIO3OUTCFG))
#define BFW_GPIO_GPIOCFGA_GPIO3OUTCFG(v)        (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO3OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO3OUTCFG)) & (BFM_GPIO_GPIOCFGA_GPIO3OUTCFG)) ))
#define BFR_GPIO_GPIOCFGA_GPIO3OUTCFG()         ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO3OUTCFG))>>(BFP_GPIO_GPIOCFGA_GPIO3OUTCFG))

#define BFP_GPIO_GPIOCFGA_GPIO3INCFG            (12)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO3INCFG            ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO3INCFG            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO3INCFG            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO3INCFG(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO3INCFG)) & (BFM_GPIO_GPIOCFGA_GPIO3INCFG))
#define BFX_GPIO_GPIOCFGA_GPIO3INCFG(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO3INCFG)) >> (BFP_GPIO_GPIOCFGA_GPIO3INCFG))
#define BFW_GPIO_GPIOCFGA_GPIO3INCFG(v)         (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO3INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO3INCFG)) & (BFM_GPIO_GPIOCFGA_GPIO3INCFG)) ))
#define BFR_GPIO_GPIOCFGA_GPIO3INCFG()          ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO3INCFG))>>(BFP_GPIO_GPIOCFGA_GPIO3INCFG))

#define BFP_GPIO_GPIOCFGA_GPIO2INTD             (11)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO2INTD             ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO2INTD             (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO2INTD             (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO2INTD(v)          ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO2INTD)) & (BFM_GPIO_GPIOCFGA_GPIO2INTD))
#define BFX_GPIO_GPIOCFGA_GPIO2INTD(v)          ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO2INTD)) >> (BFP_GPIO_GPIOCFGA_GPIO2INTD))
#define BFW_GPIO_GPIOCFGA_GPIO2INTD(v)          (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO2INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO2INTD)) & (BFM_GPIO_GPIOCFGA_GPIO2INTD)) ))
#define BFR_GPIO_GPIOCFGA_GPIO2INTD()           ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO2INTD))>>(BFP_GPIO_GPIOCFGA_GPIO2INTD))

#define BFP_GPIO_GPIOCFGA_GPIO2OUTCFG           (9)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO2OUTCFG           ((uint32_t)0x00000600)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO2OUTCFG           (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO2OUTCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO2OUTCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO2OUTCFG)) & (BFM_GPIO_GPIOCFGA_GPIO2OUTCFG))
#define BFX_GPIO_GPIOCFGA_GPIO2OUTCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO2OUTCFG)) >> (BFP_GPIO_GPIOCFGA_GPIO2OUTCFG))
#define BFW_GPIO_GPIOCFGA_GPIO2OUTCFG(v)        (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO2OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO2OUTCFG)) & (BFM_GPIO_GPIOCFGA_GPIO2OUTCFG)) ))
#define BFR_GPIO_GPIOCFGA_GPIO2OUTCFG()         ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO2OUTCFG))>>(BFP_GPIO_GPIOCFGA_GPIO2OUTCFG))

#define BFP_GPIO_GPIOCFGA_GPIO2INCFG            (8)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO2INCFG            ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO2INCFG            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO2INCFG            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO2INCFG(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO2INCFG)) & (BFM_GPIO_GPIOCFGA_GPIO2INCFG))
#define BFX_GPIO_GPIOCFGA_GPIO2INCFG(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO2INCFG)) >> (BFP_GPIO_GPIOCFGA_GPIO2INCFG))
#define BFW_GPIO_GPIOCFGA_GPIO2INCFG(v)         (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO2INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO2INCFG)) & (BFM_GPIO_GPIOCFGA_GPIO2INCFG)) ))
#define BFR_GPIO_GPIOCFGA_GPIO2INCFG()          ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO2INCFG))>>(BFP_GPIO_GPIOCFGA_GPIO2INCFG))

#define BFP_GPIO_GPIOCFGA_GPIO1INTD             (7)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO1INTD             ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO1INTD             (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO1INTD             (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO1INTD(v)          ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO1INTD)) & (BFM_GPIO_GPIOCFGA_GPIO1INTD))
#define BFX_GPIO_GPIOCFGA_GPIO1INTD(v)          ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO1INTD)) >> (BFP_GPIO_GPIOCFGA_GPIO1INTD))
#define BFW_GPIO_GPIOCFGA_GPIO1INTD(v)          (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO1INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO1INTD)) & (BFM_GPIO_GPIOCFGA_GPIO1INTD)) ))
#define BFR_GPIO_GPIOCFGA_GPIO1INTD()           ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO1INTD))>>(BFP_GPIO_GPIOCFGA_GPIO1INTD))

#define BFP_GPIO_GPIOCFGA_GPIO1OUTCFG           (5)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO1OUTCFG           ((uint32_t)0x00000060)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO1OUTCFG           (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO1OUTCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO1OUTCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO1OUTCFG)) & (BFM_GPIO_GPIOCFGA_GPIO1OUTCFG))
#define BFX_GPIO_GPIOCFGA_GPIO1OUTCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO1OUTCFG)) >> (BFP_GPIO_GPIOCFGA_GPIO1OUTCFG))
#define BFW_GPIO_GPIOCFGA_GPIO1OUTCFG(v)        (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO1OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO1OUTCFG)) & (BFM_GPIO_GPIOCFGA_GPIO1OUTCFG)) ))
#define BFR_GPIO_GPIOCFGA_GPIO1OUTCFG()         ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO1OUTCFG))>>(BFP_GPIO_GPIOCFGA_GPIO1OUTCFG))

#define BFP_GPIO_GPIOCFGA_GPIO1INCFG            (4)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO1INCFG            ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO1INCFG            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO1INCFG            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO1INCFG(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO1INCFG)) & (BFM_GPIO_GPIOCFGA_GPIO1INCFG))
#define BFX_GPIO_GPIOCFGA_GPIO1INCFG(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO1INCFG)) >> (BFP_GPIO_GPIOCFGA_GPIO1INCFG))
#define BFW_GPIO_GPIOCFGA_GPIO1INCFG(v)         (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO1INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO1INCFG)) & (BFM_GPIO_GPIOCFGA_GPIO1INCFG)) ))
#define BFR_GPIO_GPIOCFGA_GPIO1INCFG()          ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO1INCFG))>>(BFP_GPIO_GPIOCFGA_GPIO1INCFG))

#define BFP_GPIO_GPIOCFGA_GPIO0INTD             (3)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO0INTD             ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO0INTD             (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO0INTD             (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO0INTD(v)          ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO0INTD)) & (BFM_GPIO_GPIOCFGA_GPIO0INTD))
#define BFX_GPIO_GPIOCFGA_GPIO0INTD(v)          ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO0INTD)) >> (BFP_GPIO_GPIOCFGA_GPIO0INTD))
#define BFW_GPIO_GPIOCFGA_GPIO0INTD(v)          (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO0INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO0INTD)) & (BFM_GPIO_GPIOCFGA_GPIO0INTD)) ))
#define BFR_GPIO_GPIOCFGA_GPIO0INTD()           ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO0INTD))>>(BFP_GPIO_GPIOCFGA_GPIO0INTD))

#define BFP_GPIO_GPIOCFGA_GPIO0OUTCFG           (1)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO0OUTCFG           ((uint32_t)0x00000006)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO0OUTCFG           (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO0OUTCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO0OUTCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO0OUTCFG)) & (BFM_GPIO_GPIOCFGA_GPIO0OUTCFG))
#define BFX_GPIO_GPIOCFGA_GPIO0OUTCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO0OUTCFG)) >> (BFP_GPIO_GPIOCFGA_GPIO0OUTCFG))
#define BFW_GPIO_GPIOCFGA_GPIO0OUTCFG(v)        (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO0OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO0OUTCFG)) & (BFM_GPIO_GPIOCFGA_GPIO0OUTCFG)) ))
#define BFR_GPIO_GPIOCFGA_GPIO0OUTCFG()         ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO0OUTCFG))>>(BFP_GPIO_GPIOCFGA_GPIO0OUTCFG))

#define BFP_GPIO_GPIOCFGA_GPIO0INCFG            (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGA_GPIO0INCFG            ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGA_GPIO0INCFG            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGA_GPIO0INCFG            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGA_GPIO0INCFG(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGA_GPIO0INCFG)) & (BFM_GPIO_GPIOCFGA_GPIO0INCFG))
#define BFX_GPIO_GPIOCFGA_GPIO0INCFG(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGA_GPIO0INCFG)) >> (BFP_GPIO_GPIOCFGA_GPIO0INCFG))
#define BFW_GPIO_GPIOCFGA_GPIO0INCFG(v)         (REG_GPIO_GPIOCFGA.U32 = ( (REG_GPIO_GPIOCFGA.U32 & ~(BFM_GPIO_GPIOCFGA_GPIO0INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGA_GPIO0INCFG)) & (BFM_GPIO_GPIOCFGA_GPIO0INCFG)) ))
#define BFR_GPIO_GPIOCFGA_GPIO0INCFG()          ((REG_GPIO_GPIOCFGA.U32 & (BFM_GPIO_GPIOCFGA_GPIO0INCFG))>>(BFP_GPIO_GPIOCFGA_GPIO0INCFG))


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOCFGB - GPIO Configuration Register B                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned GPIO15INTD                 :  1;
        unsigned GPIO15OUTCFG               :  2;
        unsigned GPIO15INCFG                :  1;
        unsigned GPIO14INTD                 :  1;
        unsigned GPIO14OUTCFG               :  2;
        unsigned GPIO14INCFG                :  1;
        unsigned GPIO13INTD                 :  1;
        unsigned GPIO13OUTCFG               :  2;
        unsigned GPIO13INCFG                :  1;
        unsigned GPIO12INTD                 :  1;
        unsigned GPIO12OUTCFG               :  2;
        unsigned GPIO12INCFG                :  1;
        unsigned GPIO11INTD                 :  1;
        unsigned GPIO11OUTCFG               :  2;
        unsigned GPIO11INCFG                :  1;
        unsigned GPIO10INTD                 :  1;
        unsigned GPIO10OUTCFG               :  2;
        unsigned GPIO10INCFG                :  1;
        unsigned GPIO9INTD                  :  1;
        unsigned GPIO9OUTCFG                :  2;
        unsigned GPIO9INCFG                 :  1;
        unsigned GPIO8INTD                  :  1;
        unsigned GPIO8OUTCFG                :  2;
        unsigned GPIO8INCFG                 :  1;
    } B;
} reg_gpio_gpiocfgb_t;

#define REG_GPIO_GPIOCFGB_ADDR                  (REG_GPIO_BASEADDR + 0x00000044UL)
#define REG_GPIO_GPIOCFGB                       (*(volatile reg_gpio_gpiocfgb_t *) REG_GPIO_GPIOCFGB_ADDR)
#define REG_GPIO_GPIOCFGB_RD()                  (REG_GPIO_GPIOCFGB.U32)
#define REG_GPIO_GPIOCFGB_WR(v)                 (REG_GPIO_GPIOCFGB.U32 = (v))
#define REG_GPIO_GPIOCFGB_CLR(m)                (REG_GPIO_GPIOCFGB.U32 = ((REG_GPIO_GPIOCFGB.U32) & ~(m)))
#define REG_GPIO_GPIOCFGB_SET(m)                (REG_GPIO_GPIOCFGB.U32 = ((REG_GPIO_GPIOCFGB.U32) | (m)))
#define REG_GPIO_GPIOCFGB_DEF                   0x00000000

#define BFP_GPIO_GPIOCFGB_GPIO15INTD            (31)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO15INTD            ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO15INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO15INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO15INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO15INTD)) & (BFM_GPIO_GPIOCFGB_GPIO15INTD))
#define BFX_GPIO_GPIOCFGB_GPIO15INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO15INTD)) >> (BFP_GPIO_GPIOCFGB_GPIO15INTD))
#define BFW_GPIO_GPIOCFGB_GPIO15INTD(v)         (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO15INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO15INTD)) & (BFM_GPIO_GPIOCFGB_GPIO15INTD)) ))
#define BFR_GPIO_GPIOCFGB_GPIO15INTD()          ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO15INTD))>>(BFP_GPIO_GPIOCFGB_GPIO15INTD))

#define BFP_GPIO_GPIOCFGB_GPIO15OUTCFG          (29)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO15OUTCFG          ((uint32_t)0x60000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO15OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO15OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO15OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO15OUTCFG)) & (BFM_GPIO_GPIOCFGB_GPIO15OUTCFG))
#define BFX_GPIO_GPIOCFGB_GPIO15OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO15OUTCFG)) >> (BFP_GPIO_GPIOCFGB_GPIO15OUTCFG))
#define BFW_GPIO_GPIOCFGB_GPIO15OUTCFG(v)       (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO15OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO15OUTCFG)) & (BFM_GPIO_GPIOCFGB_GPIO15OUTCFG)) ))
#define BFR_GPIO_GPIOCFGB_GPIO15OUTCFG()        ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO15OUTCFG))>>(BFP_GPIO_GPIOCFGB_GPIO15OUTCFG))

#define BFP_GPIO_GPIOCFGB_GPIO15INCFG           (28)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO15INCFG           ((uint32_t)0x10000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO15INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO15INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO15INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO15INCFG)) & (BFM_GPIO_GPIOCFGB_GPIO15INCFG))
#define BFX_GPIO_GPIOCFGB_GPIO15INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO15INCFG)) >> (BFP_GPIO_GPIOCFGB_GPIO15INCFG))
#define BFW_GPIO_GPIOCFGB_GPIO15INCFG(v)        (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO15INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO15INCFG)) & (BFM_GPIO_GPIOCFGB_GPIO15INCFG)) ))
#define BFR_GPIO_GPIOCFGB_GPIO15INCFG()         ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO15INCFG))>>(BFP_GPIO_GPIOCFGB_GPIO15INCFG))

#define BFP_GPIO_GPIOCFGB_GPIO14INTD            (27)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO14INTD            ((uint32_t)0x08000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO14INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO14INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO14INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO14INTD)) & (BFM_GPIO_GPIOCFGB_GPIO14INTD))
#define BFX_GPIO_GPIOCFGB_GPIO14INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO14INTD)) >> (BFP_GPIO_GPIOCFGB_GPIO14INTD))
#define BFW_GPIO_GPIOCFGB_GPIO14INTD(v)         (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO14INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO14INTD)) & (BFM_GPIO_GPIOCFGB_GPIO14INTD)) ))
#define BFR_GPIO_GPIOCFGB_GPIO14INTD()          ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO14INTD))>>(BFP_GPIO_GPIOCFGB_GPIO14INTD))

#define BFP_GPIO_GPIOCFGB_GPIO14OUTCFG          (25)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO14OUTCFG          ((uint32_t)0x06000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO14OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO14OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO14OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO14OUTCFG)) & (BFM_GPIO_GPIOCFGB_GPIO14OUTCFG))
#define BFX_GPIO_GPIOCFGB_GPIO14OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO14OUTCFG)) >> (BFP_GPIO_GPIOCFGB_GPIO14OUTCFG))
#define BFW_GPIO_GPIOCFGB_GPIO14OUTCFG(v)       (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO14OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO14OUTCFG)) & (BFM_GPIO_GPIOCFGB_GPIO14OUTCFG)) ))
#define BFR_GPIO_GPIOCFGB_GPIO14OUTCFG()        ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO14OUTCFG))>>(BFP_GPIO_GPIOCFGB_GPIO14OUTCFG))

#define BFP_GPIO_GPIOCFGB_GPIO14INCFG           (24)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO14INCFG           ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO14INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO14INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO14INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO14INCFG)) & (BFM_GPIO_GPIOCFGB_GPIO14INCFG))
#define BFX_GPIO_GPIOCFGB_GPIO14INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO14INCFG)) >> (BFP_GPIO_GPIOCFGB_GPIO14INCFG))
#define BFW_GPIO_GPIOCFGB_GPIO14INCFG(v)        (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO14INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO14INCFG)) & (BFM_GPIO_GPIOCFGB_GPIO14INCFG)) ))
#define BFR_GPIO_GPIOCFGB_GPIO14INCFG()         ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO14INCFG))>>(BFP_GPIO_GPIOCFGB_GPIO14INCFG))

#define BFP_GPIO_GPIOCFGB_GPIO13INTD            (23)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO13INTD            ((uint32_t)0x00800000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO13INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO13INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO13INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO13INTD)) & (BFM_GPIO_GPIOCFGB_GPIO13INTD))
#define BFX_GPIO_GPIOCFGB_GPIO13INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO13INTD)) >> (BFP_GPIO_GPIOCFGB_GPIO13INTD))
#define BFW_GPIO_GPIOCFGB_GPIO13INTD(v)         (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO13INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO13INTD)) & (BFM_GPIO_GPIOCFGB_GPIO13INTD)) ))
#define BFR_GPIO_GPIOCFGB_GPIO13INTD()          ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO13INTD))>>(BFP_GPIO_GPIOCFGB_GPIO13INTD))

#define BFP_GPIO_GPIOCFGB_GPIO13OUTCFG          (21)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO13OUTCFG          ((uint32_t)0x00600000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO13OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO13OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO13OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO13OUTCFG)) & (BFM_GPIO_GPIOCFGB_GPIO13OUTCFG))
#define BFX_GPIO_GPIOCFGB_GPIO13OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO13OUTCFG)) >> (BFP_GPIO_GPIOCFGB_GPIO13OUTCFG))
#define BFW_GPIO_GPIOCFGB_GPIO13OUTCFG(v)       (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO13OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO13OUTCFG)) & (BFM_GPIO_GPIOCFGB_GPIO13OUTCFG)) ))
#define BFR_GPIO_GPIOCFGB_GPIO13OUTCFG()        ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO13OUTCFG))>>(BFP_GPIO_GPIOCFGB_GPIO13OUTCFG))

#define BFP_GPIO_GPIOCFGB_GPIO13INCFG           (20)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO13INCFG           ((uint32_t)0x00100000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO13INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO13INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO13INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO13INCFG)) & (BFM_GPIO_GPIOCFGB_GPIO13INCFG))
#define BFX_GPIO_GPIOCFGB_GPIO13INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO13INCFG)) >> (BFP_GPIO_GPIOCFGB_GPIO13INCFG))
#define BFW_GPIO_GPIOCFGB_GPIO13INCFG(v)        (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO13INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO13INCFG)) & (BFM_GPIO_GPIOCFGB_GPIO13INCFG)) ))
#define BFR_GPIO_GPIOCFGB_GPIO13INCFG()         ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO13INCFG))>>(BFP_GPIO_GPIOCFGB_GPIO13INCFG))

#define BFP_GPIO_GPIOCFGB_GPIO12INTD            (19)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO12INTD            ((uint32_t)0x00080000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO12INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO12INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO12INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO12INTD)) & (BFM_GPIO_GPIOCFGB_GPIO12INTD))
#define BFX_GPIO_GPIOCFGB_GPIO12INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO12INTD)) >> (BFP_GPIO_GPIOCFGB_GPIO12INTD))
#define BFW_GPIO_GPIOCFGB_GPIO12INTD(v)         (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO12INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO12INTD)) & (BFM_GPIO_GPIOCFGB_GPIO12INTD)) ))
#define BFR_GPIO_GPIOCFGB_GPIO12INTD()          ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO12INTD))>>(BFP_GPIO_GPIOCFGB_GPIO12INTD))

#define BFP_GPIO_GPIOCFGB_GPIO12OUTCFG          (17)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO12OUTCFG          ((uint32_t)0x00060000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO12OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO12OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO12OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO12OUTCFG)) & (BFM_GPIO_GPIOCFGB_GPIO12OUTCFG))
#define BFX_GPIO_GPIOCFGB_GPIO12OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO12OUTCFG)) >> (BFP_GPIO_GPIOCFGB_GPIO12OUTCFG))
#define BFW_GPIO_GPIOCFGB_GPIO12OUTCFG(v)       (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO12OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO12OUTCFG)) & (BFM_GPIO_GPIOCFGB_GPIO12OUTCFG)) ))
#define BFR_GPIO_GPIOCFGB_GPIO12OUTCFG()        ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO12OUTCFG))>>(BFP_GPIO_GPIOCFGB_GPIO12OUTCFG))

#define BFP_GPIO_GPIOCFGB_GPIO12INCFG           (16)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO12INCFG           ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO12INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO12INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO12INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO12INCFG)) & (BFM_GPIO_GPIOCFGB_GPIO12INCFG))
#define BFX_GPIO_GPIOCFGB_GPIO12INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO12INCFG)) >> (BFP_GPIO_GPIOCFGB_GPIO12INCFG))
#define BFW_GPIO_GPIOCFGB_GPIO12INCFG(v)        (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO12INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO12INCFG)) & (BFM_GPIO_GPIOCFGB_GPIO12INCFG)) ))
#define BFR_GPIO_GPIOCFGB_GPIO12INCFG()         ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO12INCFG))>>(BFP_GPIO_GPIOCFGB_GPIO12INCFG))

#define BFP_GPIO_GPIOCFGB_GPIO11INTD            (15)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO11INTD            ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO11INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO11INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO11INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO11INTD)) & (BFM_GPIO_GPIOCFGB_GPIO11INTD))
#define BFX_GPIO_GPIOCFGB_GPIO11INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO11INTD)) >> (BFP_GPIO_GPIOCFGB_GPIO11INTD))
#define BFW_GPIO_GPIOCFGB_GPIO11INTD(v)         (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO11INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO11INTD)) & (BFM_GPIO_GPIOCFGB_GPIO11INTD)) ))
#define BFR_GPIO_GPIOCFGB_GPIO11INTD()          ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO11INTD))>>(BFP_GPIO_GPIOCFGB_GPIO11INTD))

#define BFP_GPIO_GPIOCFGB_GPIO11OUTCFG          (13)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO11OUTCFG          ((uint32_t)0x00006000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO11OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO11OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO11OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO11OUTCFG)) & (BFM_GPIO_GPIOCFGB_GPIO11OUTCFG))
#define BFX_GPIO_GPIOCFGB_GPIO11OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO11OUTCFG)) >> (BFP_GPIO_GPIOCFGB_GPIO11OUTCFG))
#define BFW_GPIO_GPIOCFGB_GPIO11OUTCFG(v)       (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO11OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO11OUTCFG)) & (BFM_GPIO_GPIOCFGB_GPIO11OUTCFG)) ))
#define BFR_GPIO_GPIOCFGB_GPIO11OUTCFG()        ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO11OUTCFG))>>(BFP_GPIO_GPIOCFGB_GPIO11OUTCFG))

#define BFP_GPIO_GPIOCFGB_GPIO11INCFG           (12)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO11INCFG           ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO11INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO11INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO11INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO11INCFG)) & (BFM_GPIO_GPIOCFGB_GPIO11INCFG))
#define BFX_GPIO_GPIOCFGB_GPIO11INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO11INCFG)) >> (BFP_GPIO_GPIOCFGB_GPIO11INCFG))
#define BFW_GPIO_GPIOCFGB_GPIO11INCFG(v)        (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO11INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO11INCFG)) & (BFM_GPIO_GPIOCFGB_GPIO11INCFG)) ))
#define BFR_GPIO_GPIOCFGB_GPIO11INCFG()         ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO11INCFG))>>(BFP_GPIO_GPIOCFGB_GPIO11INCFG))

#define BFP_GPIO_GPIOCFGB_GPIO10INTD            (11)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO10INTD            ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO10INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO10INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO10INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO10INTD)) & (BFM_GPIO_GPIOCFGB_GPIO10INTD))
#define BFX_GPIO_GPIOCFGB_GPIO10INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO10INTD)) >> (BFP_GPIO_GPIOCFGB_GPIO10INTD))
#define BFW_GPIO_GPIOCFGB_GPIO10INTD(v)         (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO10INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO10INTD)) & (BFM_GPIO_GPIOCFGB_GPIO10INTD)) ))
#define BFR_GPIO_GPIOCFGB_GPIO10INTD()          ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO10INTD))>>(BFP_GPIO_GPIOCFGB_GPIO10INTD))

#define BFP_GPIO_GPIOCFGB_GPIO10OUTCFG          (9)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO10OUTCFG          ((uint32_t)0x00000600)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO10OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO10OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO10OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO10OUTCFG)) & (BFM_GPIO_GPIOCFGB_GPIO10OUTCFG))
#define BFX_GPIO_GPIOCFGB_GPIO10OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO10OUTCFG)) >> (BFP_GPIO_GPIOCFGB_GPIO10OUTCFG))
#define BFW_GPIO_GPIOCFGB_GPIO10OUTCFG(v)       (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO10OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO10OUTCFG)) & (BFM_GPIO_GPIOCFGB_GPIO10OUTCFG)) ))
#define BFR_GPIO_GPIOCFGB_GPIO10OUTCFG()        ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO10OUTCFG))>>(BFP_GPIO_GPIOCFGB_GPIO10OUTCFG))

#define BFP_GPIO_GPIOCFGB_GPIO10INCFG           (8)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO10INCFG           ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO10INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO10INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO10INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO10INCFG)) & (BFM_GPIO_GPIOCFGB_GPIO10INCFG))
#define BFX_GPIO_GPIOCFGB_GPIO10INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO10INCFG)) >> (BFP_GPIO_GPIOCFGB_GPIO10INCFG))
#define BFW_GPIO_GPIOCFGB_GPIO10INCFG(v)        (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO10INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO10INCFG)) & (BFM_GPIO_GPIOCFGB_GPIO10INCFG)) ))
#define BFR_GPIO_GPIOCFGB_GPIO10INCFG()         ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO10INCFG))>>(BFP_GPIO_GPIOCFGB_GPIO10INCFG))

#define BFP_GPIO_GPIOCFGB_GPIO9INTD             (7)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO9INTD             ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO9INTD             (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO9INTD             (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO9INTD(v)          ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO9INTD)) & (BFM_GPIO_GPIOCFGB_GPIO9INTD))
#define BFX_GPIO_GPIOCFGB_GPIO9INTD(v)          ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO9INTD)) >> (BFP_GPIO_GPIOCFGB_GPIO9INTD))
#define BFW_GPIO_GPIOCFGB_GPIO9INTD(v)          (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO9INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO9INTD)) & (BFM_GPIO_GPIOCFGB_GPIO9INTD)) ))
#define BFR_GPIO_GPIOCFGB_GPIO9INTD()           ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO9INTD))>>(BFP_GPIO_GPIOCFGB_GPIO9INTD))

#define BFP_GPIO_GPIOCFGB_GPIO9OUTCFG           (5)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO9OUTCFG           ((uint32_t)0x00000060)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO9OUTCFG           (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO9OUTCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO9OUTCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO9OUTCFG)) & (BFM_GPIO_GPIOCFGB_GPIO9OUTCFG))
#define BFX_GPIO_GPIOCFGB_GPIO9OUTCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO9OUTCFG)) >> (BFP_GPIO_GPIOCFGB_GPIO9OUTCFG))
#define BFW_GPIO_GPIOCFGB_GPIO9OUTCFG(v)        (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO9OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO9OUTCFG)) & (BFM_GPIO_GPIOCFGB_GPIO9OUTCFG)) ))
#define BFR_GPIO_GPIOCFGB_GPIO9OUTCFG()         ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO9OUTCFG))>>(BFP_GPIO_GPIOCFGB_GPIO9OUTCFG))

#define BFP_GPIO_GPIOCFGB_GPIO9INCFG            (4)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO9INCFG            ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO9INCFG            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO9INCFG            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO9INCFG(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO9INCFG)) & (BFM_GPIO_GPIOCFGB_GPIO9INCFG))
#define BFX_GPIO_GPIOCFGB_GPIO9INCFG(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO9INCFG)) >> (BFP_GPIO_GPIOCFGB_GPIO9INCFG))
#define BFW_GPIO_GPIOCFGB_GPIO9INCFG(v)         (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO9INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO9INCFG)) & (BFM_GPIO_GPIOCFGB_GPIO9INCFG)) ))
#define BFR_GPIO_GPIOCFGB_GPIO9INCFG()          ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO9INCFG))>>(BFP_GPIO_GPIOCFGB_GPIO9INCFG))

#define BFP_GPIO_GPIOCFGB_GPIO8INTD             (3)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO8INTD             ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO8INTD             (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO8INTD             (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO8INTD(v)          ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO8INTD)) & (BFM_GPIO_GPIOCFGB_GPIO8INTD))
#define BFX_GPIO_GPIOCFGB_GPIO8INTD(v)          ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO8INTD)) >> (BFP_GPIO_GPIOCFGB_GPIO8INTD))
#define BFW_GPIO_GPIOCFGB_GPIO8INTD(v)          (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO8INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO8INTD)) & (BFM_GPIO_GPIOCFGB_GPIO8INTD)) ))
#define BFR_GPIO_GPIOCFGB_GPIO8INTD()           ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO8INTD))>>(BFP_GPIO_GPIOCFGB_GPIO8INTD))

#define BFP_GPIO_GPIOCFGB_GPIO8OUTCFG           (1)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO8OUTCFG           ((uint32_t)0x00000006)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO8OUTCFG           (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO8OUTCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO8OUTCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO8OUTCFG)) & (BFM_GPIO_GPIOCFGB_GPIO8OUTCFG))
#define BFX_GPIO_GPIOCFGB_GPIO8OUTCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO8OUTCFG)) >> (BFP_GPIO_GPIOCFGB_GPIO8OUTCFG))
#define BFW_GPIO_GPIOCFGB_GPIO8OUTCFG(v)        (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO8OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO8OUTCFG)) & (BFM_GPIO_GPIOCFGB_GPIO8OUTCFG)) ))
#define BFR_GPIO_GPIOCFGB_GPIO8OUTCFG()         ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO8OUTCFG))>>(BFP_GPIO_GPIOCFGB_GPIO8OUTCFG))

#define BFP_GPIO_GPIOCFGB_GPIO8INCFG            (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGB_GPIO8INCFG            ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGB_GPIO8INCFG            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGB_GPIO8INCFG            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGB_GPIO8INCFG(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGB_GPIO8INCFG)) & (BFM_GPIO_GPIOCFGB_GPIO8INCFG))
#define BFX_GPIO_GPIOCFGB_GPIO8INCFG(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGB_GPIO8INCFG)) >> (BFP_GPIO_GPIOCFGB_GPIO8INCFG))
#define BFW_GPIO_GPIOCFGB_GPIO8INCFG(v)         (REG_GPIO_GPIOCFGB.U32 = ( (REG_GPIO_GPIOCFGB.U32 & ~(BFM_GPIO_GPIOCFGB_GPIO8INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGB_GPIO8INCFG)) & (BFM_GPIO_GPIOCFGB_GPIO8INCFG)) ))
#define BFR_GPIO_GPIOCFGB_GPIO8INCFG()          ((REG_GPIO_GPIOCFGB.U32 & (BFM_GPIO_GPIOCFGB_GPIO8INCFG))>>(BFP_GPIO_GPIOCFGB_GPIO8INCFG))


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOCFGC - GPIO Configuration Register C                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned GPIO23INTD                 :  1;
        unsigned GPIO23OUTCFG               :  2;
        unsigned GPIO23INCFG                :  1;
        unsigned GPIO22INTD                 :  1;
        unsigned GPIO22OUTCFG               :  2;
        unsigned GPIO22INCFG                :  1;
        unsigned GPIO21INTD                 :  1;
        unsigned GPIO21OUTCFG               :  2;
        unsigned GPIO21INCFG                :  1;
        unsigned GPIO20INTD                 :  1;
        unsigned GPIO20OUTCFG               :  2;
        unsigned GPIO20INCFG                :  1;
        unsigned GPIO19INTD                 :  1;
        unsigned GPIO19OUTCFG               :  2;
        unsigned GPIO19INCFG                :  1;
        unsigned GPIO18INTD                 :  1;
        unsigned GPIO18OUTCFG               :  2;
        unsigned GPIO18INCFG                :  1;
        unsigned GPIO17INTD                 :  1;
        unsigned GPIO17OUTCFG               :  2;
        unsigned GPIO17INCFG                :  1;
        unsigned GPIO16INTD                 :  1;
        unsigned GPIO16OUTCFG               :  2;
        unsigned GPIO16INCFG                :  1;
    } B;
} reg_gpio_gpiocfgc_t;

#define REG_GPIO_GPIOCFGC_ADDR                  (REG_GPIO_BASEADDR + 0x00000048UL)
#define REG_GPIO_GPIOCFGC                       (*(volatile reg_gpio_gpiocfgc_t *) REG_GPIO_GPIOCFGC_ADDR)
#define REG_GPIO_GPIOCFGC_RD()                  (REG_GPIO_GPIOCFGC.U32)
#define REG_GPIO_GPIOCFGC_WR(v)                 (REG_GPIO_GPIOCFGC.U32 = (v))
#define REG_GPIO_GPIOCFGC_CLR(m)                (REG_GPIO_GPIOCFGC.U32 = ((REG_GPIO_GPIOCFGC.U32) & ~(m)))
#define REG_GPIO_GPIOCFGC_SET(m)                (REG_GPIO_GPIOCFGC.U32 = ((REG_GPIO_GPIOCFGC.U32) | (m)))
#define REG_GPIO_GPIOCFGC_DEF                   0x00000000

#define BFP_GPIO_GPIOCFGC_GPIO23INTD            (31)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO23INTD            ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO23INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO23INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO23INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO23INTD)) & (BFM_GPIO_GPIOCFGC_GPIO23INTD))
#define BFX_GPIO_GPIOCFGC_GPIO23INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO23INTD)) >> (BFP_GPIO_GPIOCFGC_GPIO23INTD))
#define BFW_GPIO_GPIOCFGC_GPIO23INTD(v)         (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO23INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO23INTD)) & (BFM_GPIO_GPIOCFGC_GPIO23INTD)) ))
#define BFR_GPIO_GPIOCFGC_GPIO23INTD()          ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO23INTD))>>(BFP_GPIO_GPIOCFGC_GPIO23INTD))

#define BFP_GPIO_GPIOCFGC_GPIO23OUTCFG          (29)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO23OUTCFG          ((uint32_t)0x60000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO23OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO23OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO23OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO23OUTCFG)) & (BFM_GPIO_GPIOCFGC_GPIO23OUTCFG))
#define BFX_GPIO_GPIOCFGC_GPIO23OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO23OUTCFG)) >> (BFP_GPIO_GPIOCFGC_GPIO23OUTCFG))
#define BFW_GPIO_GPIOCFGC_GPIO23OUTCFG(v)       (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO23OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO23OUTCFG)) & (BFM_GPIO_GPIOCFGC_GPIO23OUTCFG)) ))
#define BFR_GPIO_GPIOCFGC_GPIO23OUTCFG()        ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO23OUTCFG))>>(BFP_GPIO_GPIOCFGC_GPIO23OUTCFG))

#define BFP_GPIO_GPIOCFGC_GPIO23INCFG           (28)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO23INCFG           ((uint32_t)0x10000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO23INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO23INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO23INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO23INCFG)) & (BFM_GPIO_GPIOCFGC_GPIO23INCFG))
#define BFX_GPIO_GPIOCFGC_GPIO23INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO23INCFG)) >> (BFP_GPIO_GPIOCFGC_GPIO23INCFG))
#define BFW_GPIO_GPIOCFGC_GPIO23INCFG(v)        (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO23INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO23INCFG)) & (BFM_GPIO_GPIOCFGC_GPIO23INCFG)) ))
#define BFR_GPIO_GPIOCFGC_GPIO23INCFG()         ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO23INCFG))>>(BFP_GPIO_GPIOCFGC_GPIO23INCFG))

#define BFP_GPIO_GPIOCFGC_GPIO22INTD            (27)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO22INTD            ((uint32_t)0x08000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO22INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO22INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO22INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO22INTD)) & (BFM_GPIO_GPIOCFGC_GPIO22INTD))
#define BFX_GPIO_GPIOCFGC_GPIO22INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO22INTD)) >> (BFP_GPIO_GPIOCFGC_GPIO22INTD))
#define BFW_GPIO_GPIOCFGC_GPIO22INTD(v)         (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO22INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO22INTD)) & (BFM_GPIO_GPIOCFGC_GPIO22INTD)) ))
#define BFR_GPIO_GPIOCFGC_GPIO22INTD()          ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO22INTD))>>(BFP_GPIO_GPIOCFGC_GPIO22INTD))

#define BFP_GPIO_GPIOCFGC_GPIO22OUTCFG          (25)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO22OUTCFG          ((uint32_t)0x06000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO22OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO22OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO22OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO22OUTCFG)) & (BFM_GPIO_GPIOCFGC_GPIO22OUTCFG))
#define BFX_GPIO_GPIOCFGC_GPIO22OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO22OUTCFG)) >> (BFP_GPIO_GPIOCFGC_GPIO22OUTCFG))
#define BFW_GPIO_GPIOCFGC_GPIO22OUTCFG(v)       (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO22OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO22OUTCFG)) & (BFM_GPIO_GPIOCFGC_GPIO22OUTCFG)) ))
#define BFR_GPIO_GPIOCFGC_GPIO22OUTCFG()        ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO22OUTCFG))>>(BFP_GPIO_GPIOCFGC_GPIO22OUTCFG))

#define BFP_GPIO_GPIOCFGC_GPIO22INCFG           (24)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO22INCFG           ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO22INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO22INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO22INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO22INCFG)) & (BFM_GPIO_GPIOCFGC_GPIO22INCFG))
#define BFX_GPIO_GPIOCFGC_GPIO22INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO22INCFG)) >> (BFP_GPIO_GPIOCFGC_GPIO22INCFG))
#define BFW_GPIO_GPIOCFGC_GPIO22INCFG(v)        (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO22INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO22INCFG)) & (BFM_GPIO_GPIOCFGC_GPIO22INCFG)) ))
#define BFR_GPIO_GPIOCFGC_GPIO22INCFG()         ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO22INCFG))>>(BFP_GPIO_GPIOCFGC_GPIO22INCFG))

#define BFP_GPIO_GPIOCFGC_GPIO21INTD            (23)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO21INTD            ((uint32_t)0x00800000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO21INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO21INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO21INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO21INTD)) & (BFM_GPIO_GPIOCFGC_GPIO21INTD))
#define BFX_GPIO_GPIOCFGC_GPIO21INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO21INTD)) >> (BFP_GPIO_GPIOCFGC_GPIO21INTD))
#define BFW_GPIO_GPIOCFGC_GPIO21INTD(v)         (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO21INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO21INTD)) & (BFM_GPIO_GPIOCFGC_GPIO21INTD)) ))
#define BFR_GPIO_GPIOCFGC_GPIO21INTD()          ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO21INTD))>>(BFP_GPIO_GPIOCFGC_GPIO21INTD))

#define BFP_GPIO_GPIOCFGC_GPIO21OUTCFG          (21)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO21OUTCFG          ((uint32_t)0x00600000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO21OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO21OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO21OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO21OUTCFG)) & (BFM_GPIO_GPIOCFGC_GPIO21OUTCFG))
#define BFX_GPIO_GPIOCFGC_GPIO21OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO21OUTCFG)) >> (BFP_GPIO_GPIOCFGC_GPIO21OUTCFG))
#define BFW_GPIO_GPIOCFGC_GPIO21OUTCFG(v)       (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO21OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO21OUTCFG)) & (BFM_GPIO_GPIOCFGC_GPIO21OUTCFG)) ))
#define BFR_GPIO_GPIOCFGC_GPIO21OUTCFG()        ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO21OUTCFG))>>(BFP_GPIO_GPIOCFGC_GPIO21OUTCFG))

#define BFP_GPIO_GPIOCFGC_GPIO21INCFG           (20)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO21INCFG           ((uint32_t)0x00100000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO21INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO21INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO21INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO21INCFG)) & (BFM_GPIO_GPIOCFGC_GPIO21INCFG))
#define BFX_GPIO_GPIOCFGC_GPIO21INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO21INCFG)) >> (BFP_GPIO_GPIOCFGC_GPIO21INCFG))
#define BFW_GPIO_GPIOCFGC_GPIO21INCFG(v)        (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO21INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO21INCFG)) & (BFM_GPIO_GPIOCFGC_GPIO21INCFG)) ))
#define BFR_GPIO_GPIOCFGC_GPIO21INCFG()         ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO21INCFG))>>(BFP_GPIO_GPIOCFGC_GPIO21INCFG))

#define BFP_GPIO_GPIOCFGC_GPIO20INTD            (19)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO20INTD            ((uint32_t)0x00080000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO20INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO20INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO20INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO20INTD)) & (BFM_GPIO_GPIOCFGC_GPIO20INTD))
#define BFX_GPIO_GPIOCFGC_GPIO20INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO20INTD)) >> (BFP_GPIO_GPIOCFGC_GPIO20INTD))
#define BFW_GPIO_GPIOCFGC_GPIO20INTD(v)         (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO20INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO20INTD)) & (BFM_GPIO_GPIOCFGC_GPIO20INTD)) ))
#define BFR_GPIO_GPIOCFGC_GPIO20INTD()          ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO20INTD))>>(BFP_GPIO_GPIOCFGC_GPIO20INTD))

#define BFP_GPIO_GPIOCFGC_GPIO20OUTCFG          (17)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO20OUTCFG          ((uint32_t)0x00060000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO20OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO20OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO20OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO20OUTCFG)) & (BFM_GPIO_GPIOCFGC_GPIO20OUTCFG))
#define BFX_GPIO_GPIOCFGC_GPIO20OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO20OUTCFG)) >> (BFP_GPIO_GPIOCFGC_GPIO20OUTCFG))
#define BFW_GPIO_GPIOCFGC_GPIO20OUTCFG(v)       (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO20OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO20OUTCFG)) & (BFM_GPIO_GPIOCFGC_GPIO20OUTCFG)) ))
#define BFR_GPIO_GPIOCFGC_GPIO20OUTCFG()        ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO20OUTCFG))>>(BFP_GPIO_GPIOCFGC_GPIO20OUTCFG))

#define BFP_GPIO_GPIOCFGC_GPIO20INCFG           (16)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO20INCFG           ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO20INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO20INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO20INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO20INCFG)) & (BFM_GPIO_GPIOCFGC_GPIO20INCFG))
#define BFX_GPIO_GPIOCFGC_GPIO20INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO20INCFG)) >> (BFP_GPIO_GPIOCFGC_GPIO20INCFG))
#define BFW_GPIO_GPIOCFGC_GPIO20INCFG(v)        (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO20INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO20INCFG)) & (BFM_GPIO_GPIOCFGC_GPIO20INCFG)) ))
#define BFR_GPIO_GPIOCFGC_GPIO20INCFG()         ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO20INCFG))>>(BFP_GPIO_GPIOCFGC_GPIO20INCFG))

#define BFP_GPIO_GPIOCFGC_GPIO19INTD            (15)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO19INTD            ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO19INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO19INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO19INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO19INTD)) & (BFM_GPIO_GPIOCFGC_GPIO19INTD))
#define BFX_GPIO_GPIOCFGC_GPIO19INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO19INTD)) >> (BFP_GPIO_GPIOCFGC_GPIO19INTD))
#define BFW_GPIO_GPIOCFGC_GPIO19INTD(v)         (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO19INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO19INTD)) & (BFM_GPIO_GPIOCFGC_GPIO19INTD)) ))
#define BFR_GPIO_GPIOCFGC_GPIO19INTD()          ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO19INTD))>>(BFP_GPIO_GPIOCFGC_GPIO19INTD))

#define BFP_GPIO_GPIOCFGC_GPIO19OUTCFG          (13)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO19OUTCFG          ((uint32_t)0x00006000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO19OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO19OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO19OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO19OUTCFG)) & (BFM_GPIO_GPIOCFGC_GPIO19OUTCFG))
#define BFX_GPIO_GPIOCFGC_GPIO19OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO19OUTCFG)) >> (BFP_GPIO_GPIOCFGC_GPIO19OUTCFG))
#define BFW_GPIO_GPIOCFGC_GPIO19OUTCFG(v)       (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO19OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO19OUTCFG)) & (BFM_GPIO_GPIOCFGC_GPIO19OUTCFG)) ))
#define BFR_GPIO_GPIOCFGC_GPIO19OUTCFG()        ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO19OUTCFG))>>(BFP_GPIO_GPIOCFGC_GPIO19OUTCFG))

#define BFP_GPIO_GPIOCFGC_GPIO19INCFG           (12)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO19INCFG           ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO19INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO19INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO19INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO19INCFG)) & (BFM_GPIO_GPIOCFGC_GPIO19INCFG))
#define BFX_GPIO_GPIOCFGC_GPIO19INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO19INCFG)) >> (BFP_GPIO_GPIOCFGC_GPIO19INCFG))
#define BFW_GPIO_GPIOCFGC_GPIO19INCFG(v)        (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO19INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO19INCFG)) & (BFM_GPIO_GPIOCFGC_GPIO19INCFG)) ))
#define BFR_GPIO_GPIOCFGC_GPIO19INCFG()         ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO19INCFG))>>(BFP_GPIO_GPIOCFGC_GPIO19INCFG))

#define BFP_GPIO_GPIOCFGC_GPIO18INTD            (11)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO18INTD            ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO18INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO18INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO18INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO18INTD)) & (BFM_GPIO_GPIOCFGC_GPIO18INTD))
#define BFX_GPIO_GPIOCFGC_GPIO18INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO18INTD)) >> (BFP_GPIO_GPIOCFGC_GPIO18INTD))
#define BFW_GPIO_GPIOCFGC_GPIO18INTD(v)         (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO18INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO18INTD)) & (BFM_GPIO_GPIOCFGC_GPIO18INTD)) ))
#define BFR_GPIO_GPIOCFGC_GPIO18INTD()          ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO18INTD))>>(BFP_GPIO_GPIOCFGC_GPIO18INTD))

#define BFP_GPIO_GPIOCFGC_GPIO18OUTCFG          (9)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO18OUTCFG          ((uint32_t)0x00000600)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO18OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO18OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO18OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO18OUTCFG)) & (BFM_GPIO_GPIOCFGC_GPIO18OUTCFG))
#define BFX_GPIO_GPIOCFGC_GPIO18OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO18OUTCFG)) >> (BFP_GPIO_GPIOCFGC_GPIO18OUTCFG))
#define BFW_GPIO_GPIOCFGC_GPIO18OUTCFG(v)       (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO18OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO18OUTCFG)) & (BFM_GPIO_GPIOCFGC_GPIO18OUTCFG)) ))
#define BFR_GPIO_GPIOCFGC_GPIO18OUTCFG()        ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO18OUTCFG))>>(BFP_GPIO_GPIOCFGC_GPIO18OUTCFG))

#define BFP_GPIO_GPIOCFGC_GPIO18INCFG           (8)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO18INCFG           ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO18INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO18INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO18INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO18INCFG)) & (BFM_GPIO_GPIOCFGC_GPIO18INCFG))
#define BFX_GPIO_GPIOCFGC_GPIO18INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO18INCFG)) >> (BFP_GPIO_GPIOCFGC_GPIO18INCFG))
#define BFW_GPIO_GPIOCFGC_GPIO18INCFG(v)        (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO18INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO18INCFG)) & (BFM_GPIO_GPIOCFGC_GPIO18INCFG)) ))
#define BFR_GPIO_GPIOCFGC_GPIO18INCFG()         ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO18INCFG))>>(BFP_GPIO_GPIOCFGC_GPIO18INCFG))

#define BFP_GPIO_GPIOCFGC_GPIO17INTD            (7)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO17INTD            ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO17INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO17INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO17INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO17INTD)) & (BFM_GPIO_GPIOCFGC_GPIO17INTD))
#define BFX_GPIO_GPIOCFGC_GPIO17INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO17INTD)) >> (BFP_GPIO_GPIOCFGC_GPIO17INTD))
#define BFW_GPIO_GPIOCFGC_GPIO17INTD(v)         (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO17INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO17INTD)) & (BFM_GPIO_GPIOCFGC_GPIO17INTD)) ))
#define BFR_GPIO_GPIOCFGC_GPIO17INTD()          ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO17INTD))>>(BFP_GPIO_GPIOCFGC_GPIO17INTD))

#define BFP_GPIO_GPIOCFGC_GPIO17OUTCFG          (5)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO17OUTCFG          ((uint32_t)0x00000060)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO17OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO17OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO17OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO17OUTCFG)) & (BFM_GPIO_GPIOCFGC_GPIO17OUTCFG))
#define BFX_GPIO_GPIOCFGC_GPIO17OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO17OUTCFG)) >> (BFP_GPIO_GPIOCFGC_GPIO17OUTCFG))
#define BFW_GPIO_GPIOCFGC_GPIO17OUTCFG(v)       (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO17OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO17OUTCFG)) & (BFM_GPIO_GPIOCFGC_GPIO17OUTCFG)) ))
#define BFR_GPIO_GPIOCFGC_GPIO17OUTCFG()        ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO17OUTCFG))>>(BFP_GPIO_GPIOCFGC_GPIO17OUTCFG))

#define BFP_GPIO_GPIOCFGC_GPIO17INCFG           (4)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO17INCFG           ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO17INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO17INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO17INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO17INCFG)) & (BFM_GPIO_GPIOCFGC_GPIO17INCFG))
#define BFX_GPIO_GPIOCFGC_GPIO17INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO17INCFG)) >> (BFP_GPIO_GPIOCFGC_GPIO17INCFG))
#define BFW_GPIO_GPIOCFGC_GPIO17INCFG(v)        (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO17INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO17INCFG)) & (BFM_GPIO_GPIOCFGC_GPIO17INCFG)) ))
#define BFR_GPIO_GPIOCFGC_GPIO17INCFG()         ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO17INCFG))>>(BFP_GPIO_GPIOCFGC_GPIO17INCFG))

#define BFP_GPIO_GPIOCFGC_GPIO16INTD            (3)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO16INTD            ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO16INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO16INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO16INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO16INTD)) & (BFM_GPIO_GPIOCFGC_GPIO16INTD))
#define BFX_GPIO_GPIOCFGC_GPIO16INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO16INTD)) >> (BFP_GPIO_GPIOCFGC_GPIO16INTD))
#define BFW_GPIO_GPIOCFGC_GPIO16INTD(v)         (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO16INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO16INTD)) & (BFM_GPIO_GPIOCFGC_GPIO16INTD)) ))
#define BFR_GPIO_GPIOCFGC_GPIO16INTD()          ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO16INTD))>>(BFP_GPIO_GPIOCFGC_GPIO16INTD))

#define BFP_GPIO_GPIOCFGC_GPIO16OUTCFG          (1)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO16OUTCFG          ((uint32_t)0x00000006)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO16OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO16OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO16OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO16OUTCFG)) & (BFM_GPIO_GPIOCFGC_GPIO16OUTCFG))
#define BFX_GPIO_GPIOCFGC_GPIO16OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO16OUTCFG)) >> (BFP_GPIO_GPIOCFGC_GPIO16OUTCFG))
#define BFW_GPIO_GPIOCFGC_GPIO16OUTCFG(v)       (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO16OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO16OUTCFG)) & (BFM_GPIO_GPIOCFGC_GPIO16OUTCFG)) ))
#define BFR_GPIO_GPIOCFGC_GPIO16OUTCFG()        ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO16OUTCFG))>>(BFP_GPIO_GPIOCFGC_GPIO16OUTCFG))

#define BFP_GPIO_GPIOCFGC_GPIO16INCFG           (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGC_GPIO16INCFG           ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGC_GPIO16INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGC_GPIO16INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGC_GPIO16INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGC_GPIO16INCFG)) & (BFM_GPIO_GPIOCFGC_GPIO16INCFG))
#define BFX_GPIO_GPIOCFGC_GPIO16INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGC_GPIO16INCFG)) >> (BFP_GPIO_GPIOCFGC_GPIO16INCFG))
#define BFW_GPIO_GPIOCFGC_GPIO16INCFG(v)        (REG_GPIO_GPIOCFGC.U32 = ( (REG_GPIO_GPIOCFGC.U32 & ~(BFM_GPIO_GPIOCFGC_GPIO16INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGC_GPIO16INCFG)) & (BFM_GPIO_GPIOCFGC_GPIO16INCFG)) ))
#define BFR_GPIO_GPIOCFGC_GPIO16INCFG()         ((REG_GPIO_GPIOCFGC.U32 & (BFM_GPIO_GPIOCFGC_GPIO16INCFG))>>(BFP_GPIO_GPIOCFGC_GPIO16INCFG))


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOCFGD - GPIO Configuration Register D                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned GPIO31INTD                 :  1;
        unsigned GPIO31OUTCFG               :  2;
        unsigned GPIO31INCFG                :  1;
        unsigned GPIO30INTD                 :  1;
        unsigned GPIO30OUTCFG               :  2;
        unsigned GPIO30INCFG                :  1;
        unsigned GPIO29INTD                 :  1;
        unsigned GPIO29OUTCFG               :  2;
        unsigned GPIO29INCFG                :  1;
        unsigned GPIO28INTD                 :  1;
        unsigned GPIO28OUTCFG               :  2;
        unsigned GPIO28INCFG                :  1;
        unsigned GPIO27INTD                 :  1;
        unsigned GPIO27OUTCFG               :  2;
        unsigned GPIO27INCFG                :  1;
        unsigned GPIO26INTD                 :  1;
        unsigned GPIO26OUTCFG               :  2;
        unsigned GPIO26INCFG                :  1;
        unsigned GPIO25INTD                 :  1;
        unsigned GPIO25OUTCFG               :  2;
        unsigned GPIO25INCFG                :  1;
        unsigned GPIO24INTD                 :  1;
        unsigned GPIO24OUTCFG               :  2;
        unsigned GPIO24INCFG                :  1;
    } B;
} reg_gpio_gpiocfgd_t;

#define REG_GPIO_GPIOCFGD_ADDR                  (REG_GPIO_BASEADDR + 0x0000004CUL)
#define REG_GPIO_GPIOCFGD                       (*(volatile reg_gpio_gpiocfgd_t *) REG_GPIO_GPIOCFGD_ADDR)
#define REG_GPIO_GPIOCFGD_RD()                  (REG_GPIO_GPIOCFGD.U32)
#define REG_GPIO_GPIOCFGD_WR(v)                 (REG_GPIO_GPIOCFGD.U32 = (v))
#define REG_GPIO_GPIOCFGD_CLR(m)                (REG_GPIO_GPIOCFGD.U32 = ((REG_GPIO_GPIOCFGD.U32) & ~(m)))
#define REG_GPIO_GPIOCFGD_SET(m)                (REG_GPIO_GPIOCFGD.U32 = ((REG_GPIO_GPIOCFGD.U32) | (m)))
#define REG_GPIO_GPIOCFGD_DEF                   0x00000000

#define BFP_GPIO_GPIOCFGD_GPIO31INTD            (31)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO31INTD            ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO31INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO31INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO31INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO31INTD)) & (BFM_GPIO_GPIOCFGD_GPIO31INTD))
#define BFX_GPIO_GPIOCFGD_GPIO31INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO31INTD)) >> (BFP_GPIO_GPIOCFGD_GPIO31INTD))
#define BFW_GPIO_GPIOCFGD_GPIO31INTD(v)         (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO31INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO31INTD)) & (BFM_GPIO_GPIOCFGD_GPIO31INTD)) ))
#define BFR_GPIO_GPIOCFGD_GPIO31INTD()          ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO31INTD))>>(BFP_GPIO_GPIOCFGD_GPIO31INTD))

#define BFP_GPIO_GPIOCFGD_GPIO31OUTCFG          (29)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO31OUTCFG          ((uint32_t)0x60000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO31OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO31OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO31OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO31OUTCFG)) & (BFM_GPIO_GPIOCFGD_GPIO31OUTCFG))
#define BFX_GPIO_GPIOCFGD_GPIO31OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO31OUTCFG)) >> (BFP_GPIO_GPIOCFGD_GPIO31OUTCFG))
#define BFW_GPIO_GPIOCFGD_GPIO31OUTCFG(v)       (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO31OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO31OUTCFG)) & (BFM_GPIO_GPIOCFGD_GPIO31OUTCFG)) ))
#define BFR_GPIO_GPIOCFGD_GPIO31OUTCFG()        ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO31OUTCFG))>>(BFP_GPIO_GPIOCFGD_GPIO31OUTCFG))

#define BFP_GPIO_GPIOCFGD_GPIO31INCFG           (28)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO31INCFG           ((uint32_t)0x10000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO31INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO31INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO31INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO31INCFG)) & (BFM_GPIO_GPIOCFGD_GPIO31INCFG))
#define BFX_GPIO_GPIOCFGD_GPIO31INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO31INCFG)) >> (BFP_GPIO_GPIOCFGD_GPIO31INCFG))
#define BFW_GPIO_GPIOCFGD_GPIO31INCFG(v)        (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO31INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO31INCFG)) & (BFM_GPIO_GPIOCFGD_GPIO31INCFG)) ))
#define BFR_GPIO_GPIOCFGD_GPIO31INCFG()         ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO31INCFG))>>(BFP_GPIO_GPIOCFGD_GPIO31INCFG))

#define BFP_GPIO_GPIOCFGD_GPIO30INTD            (27)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO30INTD            ((uint32_t)0x08000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO30INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO30INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO30INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO30INTD)) & (BFM_GPIO_GPIOCFGD_GPIO30INTD))
#define BFX_GPIO_GPIOCFGD_GPIO30INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO30INTD)) >> (BFP_GPIO_GPIOCFGD_GPIO30INTD))
#define BFW_GPIO_GPIOCFGD_GPIO30INTD(v)         (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO30INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO30INTD)) & (BFM_GPIO_GPIOCFGD_GPIO30INTD)) ))
#define BFR_GPIO_GPIOCFGD_GPIO30INTD()          ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO30INTD))>>(BFP_GPIO_GPIOCFGD_GPIO30INTD))

#define BFP_GPIO_GPIOCFGD_GPIO30OUTCFG          (25)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO30OUTCFG          ((uint32_t)0x06000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO30OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO30OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO30OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO30OUTCFG)) & (BFM_GPIO_GPIOCFGD_GPIO30OUTCFG))
#define BFX_GPIO_GPIOCFGD_GPIO30OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO30OUTCFG)) >> (BFP_GPIO_GPIOCFGD_GPIO30OUTCFG))
#define BFW_GPIO_GPIOCFGD_GPIO30OUTCFG(v)       (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO30OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO30OUTCFG)) & (BFM_GPIO_GPIOCFGD_GPIO30OUTCFG)) ))
#define BFR_GPIO_GPIOCFGD_GPIO30OUTCFG()        ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO30OUTCFG))>>(BFP_GPIO_GPIOCFGD_GPIO30OUTCFG))

#define BFP_GPIO_GPIOCFGD_GPIO30INCFG           (24)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO30INCFG           ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO30INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO30INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO30INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO30INCFG)) & (BFM_GPIO_GPIOCFGD_GPIO30INCFG))
#define BFX_GPIO_GPIOCFGD_GPIO30INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO30INCFG)) >> (BFP_GPIO_GPIOCFGD_GPIO30INCFG))
#define BFW_GPIO_GPIOCFGD_GPIO30INCFG(v)        (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO30INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO30INCFG)) & (BFM_GPIO_GPIOCFGD_GPIO30INCFG)) ))
#define BFR_GPIO_GPIOCFGD_GPIO30INCFG()         ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO30INCFG))>>(BFP_GPIO_GPIOCFGD_GPIO30INCFG))

#define BFP_GPIO_GPIOCFGD_GPIO29INTD            (23)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO29INTD            ((uint32_t)0x00800000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO29INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO29INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO29INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO29INTD)) & (BFM_GPIO_GPIOCFGD_GPIO29INTD))
#define BFX_GPIO_GPIOCFGD_GPIO29INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO29INTD)) >> (BFP_GPIO_GPIOCFGD_GPIO29INTD))
#define BFW_GPIO_GPIOCFGD_GPIO29INTD(v)         (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO29INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO29INTD)) & (BFM_GPIO_GPIOCFGD_GPIO29INTD)) ))
#define BFR_GPIO_GPIOCFGD_GPIO29INTD()          ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO29INTD))>>(BFP_GPIO_GPIOCFGD_GPIO29INTD))

#define BFP_GPIO_GPIOCFGD_GPIO29OUTCFG          (21)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO29OUTCFG          ((uint32_t)0x00600000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO29OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO29OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO29OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO29OUTCFG)) & (BFM_GPIO_GPIOCFGD_GPIO29OUTCFG))
#define BFX_GPIO_GPIOCFGD_GPIO29OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO29OUTCFG)) >> (BFP_GPIO_GPIOCFGD_GPIO29OUTCFG))
#define BFW_GPIO_GPIOCFGD_GPIO29OUTCFG(v)       (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO29OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO29OUTCFG)) & (BFM_GPIO_GPIOCFGD_GPIO29OUTCFG)) ))
#define BFR_GPIO_GPIOCFGD_GPIO29OUTCFG()        ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO29OUTCFG))>>(BFP_GPIO_GPIOCFGD_GPIO29OUTCFG))

#define BFP_GPIO_GPIOCFGD_GPIO29INCFG           (20)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO29INCFG           ((uint32_t)0x00100000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO29INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO29INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO29INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO29INCFG)) & (BFM_GPIO_GPIOCFGD_GPIO29INCFG))
#define BFX_GPIO_GPIOCFGD_GPIO29INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO29INCFG)) >> (BFP_GPIO_GPIOCFGD_GPIO29INCFG))
#define BFW_GPIO_GPIOCFGD_GPIO29INCFG(v)        (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO29INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO29INCFG)) & (BFM_GPIO_GPIOCFGD_GPIO29INCFG)) ))
#define BFR_GPIO_GPIOCFGD_GPIO29INCFG()         ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO29INCFG))>>(BFP_GPIO_GPIOCFGD_GPIO29INCFG))

#define BFP_GPIO_GPIOCFGD_GPIO28INTD            (19)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO28INTD            ((uint32_t)0x00080000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO28INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO28INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO28INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO28INTD)) & (BFM_GPIO_GPIOCFGD_GPIO28INTD))
#define BFX_GPIO_GPIOCFGD_GPIO28INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO28INTD)) >> (BFP_GPIO_GPIOCFGD_GPIO28INTD))
#define BFW_GPIO_GPIOCFGD_GPIO28INTD(v)         (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO28INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO28INTD)) & (BFM_GPIO_GPIOCFGD_GPIO28INTD)) ))
#define BFR_GPIO_GPIOCFGD_GPIO28INTD()          ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO28INTD))>>(BFP_GPIO_GPIOCFGD_GPIO28INTD))

#define BFP_GPIO_GPIOCFGD_GPIO28OUTCFG          (17)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO28OUTCFG          ((uint32_t)0x00060000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO28OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO28OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO28OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO28OUTCFG)) & (BFM_GPIO_GPIOCFGD_GPIO28OUTCFG))
#define BFX_GPIO_GPIOCFGD_GPIO28OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO28OUTCFG)) >> (BFP_GPIO_GPIOCFGD_GPIO28OUTCFG))
#define BFW_GPIO_GPIOCFGD_GPIO28OUTCFG(v)       (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO28OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO28OUTCFG)) & (BFM_GPIO_GPIOCFGD_GPIO28OUTCFG)) ))
#define BFR_GPIO_GPIOCFGD_GPIO28OUTCFG()        ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO28OUTCFG))>>(BFP_GPIO_GPIOCFGD_GPIO28OUTCFG))

#define BFP_GPIO_GPIOCFGD_GPIO28INCFG           (16)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO28INCFG           ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO28INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO28INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO28INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO28INCFG)) & (BFM_GPIO_GPIOCFGD_GPIO28INCFG))
#define BFX_GPIO_GPIOCFGD_GPIO28INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO28INCFG)) >> (BFP_GPIO_GPIOCFGD_GPIO28INCFG))
#define BFW_GPIO_GPIOCFGD_GPIO28INCFG(v)        (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO28INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO28INCFG)) & (BFM_GPIO_GPIOCFGD_GPIO28INCFG)) ))
#define BFR_GPIO_GPIOCFGD_GPIO28INCFG()         ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO28INCFG))>>(BFP_GPIO_GPIOCFGD_GPIO28INCFG))

#define BFP_GPIO_GPIOCFGD_GPIO27INTD            (15)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO27INTD            ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO27INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO27INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO27INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO27INTD)) & (BFM_GPIO_GPIOCFGD_GPIO27INTD))
#define BFX_GPIO_GPIOCFGD_GPIO27INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO27INTD)) >> (BFP_GPIO_GPIOCFGD_GPIO27INTD))
#define BFW_GPIO_GPIOCFGD_GPIO27INTD(v)         (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO27INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO27INTD)) & (BFM_GPIO_GPIOCFGD_GPIO27INTD)) ))
#define BFR_GPIO_GPIOCFGD_GPIO27INTD()          ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO27INTD))>>(BFP_GPIO_GPIOCFGD_GPIO27INTD))

#define BFP_GPIO_GPIOCFGD_GPIO27OUTCFG          (13)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO27OUTCFG          ((uint32_t)0x00006000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO27OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO27OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO27OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO27OUTCFG)) & (BFM_GPIO_GPIOCFGD_GPIO27OUTCFG))
#define BFX_GPIO_GPIOCFGD_GPIO27OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO27OUTCFG)) >> (BFP_GPIO_GPIOCFGD_GPIO27OUTCFG))
#define BFW_GPIO_GPIOCFGD_GPIO27OUTCFG(v)       (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO27OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO27OUTCFG)) & (BFM_GPIO_GPIOCFGD_GPIO27OUTCFG)) ))
#define BFR_GPIO_GPIOCFGD_GPIO27OUTCFG()        ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO27OUTCFG))>>(BFP_GPIO_GPIOCFGD_GPIO27OUTCFG))

#define BFP_GPIO_GPIOCFGD_GPIO27INCFG           (12)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO27INCFG           ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO27INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO27INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO27INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO27INCFG)) & (BFM_GPIO_GPIOCFGD_GPIO27INCFG))
#define BFX_GPIO_GPIOCFGD_GPIO27INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO27INCFG)) >> (BFP_GPIO_GPIOCFGD_GPIO27INCFG))
#define BFW_GPIO_GPIOCFGD_GPIO27INCFG(v)        (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO27INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO27INCFG)) & (BFM_GPIO_GPIOCFGD_GPIO27INCFG)) ))
#define BFR_GPIO_GPIOCFGD_GPIO27INCFG()         ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO27INCFG))>>(BFP_GPIO_GPIOCFGD_GPIO27INCFG))

#define BFP_GPIO_GPIOCFGD_GPIO26INTD            (11)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO26INTD            ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO26INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO26INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO26INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO26INTD)) & (BFM_GPIO_GPIOCFGD_GPIO26INTD))
#define BFX_GPIO_GPIOCFGD_GPIO26INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO26INTD)) >> (BFP_GPIO_GPIOCFGD_GPIO26INTD))
#define BFW_GPIO_GPIOCFGD_GPIO26INTD(v)         (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO26INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO26INTD)) & (BFM_GPIO_GPIOCFGD_GPIO26INTD)) ))
#define BFR_GPIO_GPIOCFGD_GPIO26INTD()          ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO26INTD))>>(BFP_GPIO_GPIOCFGD_GPIO26INTD))

#define BFP_GPIO_GPIOCFGD_GPIO26OUTCFG          (9)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO26OUTCFG          ((uint32_t)0x00000600)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO26OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO26OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO26OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO26OUTCFG)) & (BFM_GPIO_GPIOCFGD_GPIO26OUTCFG))
#define BFX_GPIO_GPIOCFGD_GPIO26OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO26OUTCFG)) >> (BFP_GPIO_GPIOCFGD_GPIO26OUTCFG))
#define BFW_GPIO_GPIOCFGD_GPIO26OUTCFG(v)       (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO26OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO26OUTCFG)) & (BFM_GPIO_GPIOCFGD_GPIO26OUTCFG)) ))
#define BFR_GPIO_GPIOCFGD_GPIO26OUTCFG()        ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO26OUTCFG))>>(BFP_GPIO_GPIOCFGD_GPIO26OUTCFG))

#define BFP_GPIO_GPIOCFGD_GPIO26INCFG           (8)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO26INCFG           ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO26INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO26INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO26INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO26INCFG)) & (BFM_GPIO_GPIOCFGD_GPIO26INCFG))
#define BFX_GPIO_GPIOCFGD_GPIO26INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO26INCFG)) >> (BFP_GPIO_GPIOCFGD_GPIO26INCFG))
#define BFW_GPIO_GPIOCFGD_GPIO26INCFG(v)        (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO26INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO26INCFG)) & (BFM_GPIO_GPIOCFGD_GPIO26INCFG)) ))
#define BFR_GPIO_GPIOCFGD_GPIO26INCFG()         ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO26INCFG))>>(BFP_GPIO_GPIOCFGD_GPIO26INCFG))

#define BFP_GPIO_GPIOCFGD_GPIO25INTD            (7)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO25INTD            ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO25INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO25INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO25INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO25INTD)) & (BFM_GPIO_GPIOCFGD_GPIO25INTD))
#define BFX_GPIO_GPIOCFGD_GPIO25INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO25INTD)) >> (BFP_GPIO_GPIOCFGD_GPIO25INTD))
#define BFW_GPIO_GPIOCFGD_GPIO25INTD(v)         (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO25INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO25INTD)) & (BFM_GPIO_GPIOCFGD_GPIO25INTD)) ))
#define BFR_GPIO_GPIOCFGD_GPIO25INTD()          ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO25INTD))>>(BFP_GPIO_GPIOCFGD_GPIO25INTD))

#define BFP_GPIO_GPIOCFGD_GPIO25OUTCFG          (5)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO25OUTCFG          ((uint32_t)0x00000060)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO25OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO25OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO25OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO25OUTCFG)) & (BFM_GPIO_GPIOCFGD_GPIO25OUTCFG))
#define BFX_GPIO_GPIOCFGD_GPIO25OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO25OUTCFG)) >> (BFP_GPIO_GPIOCFGD_GPIO25OUTCFG))
#define BFW_GPIO_GPIOCFGD_GPIO25OUTCFG(v)       (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO25OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO25OUTCFG)) & (BFM_GPIO_GPIOCFGD_GPIO25OUTCFG)) ))
#define BFR_GPIO_GPIOCFGD_GPIO25OUTCFG()        ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO25OUTCFG))>>(BFP_GPIO_GPIOCFGD_GPIO25OUTCFG))

#define BFP_GPIO_GPIOCFGD_GPIO25INCFG           (4)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO25INCFG           ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO25INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO25INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO25INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO25INCFG)) & (BFM_GPIO_GPIOCFGD_GPIO25INCFG))
#define BFX_GPIO_GPIOCFGD_GPIO25INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO25INCFG)) >> (BFP_GPIO_GPIOCFGD_GPIO25INCFG))
#define BFW_GPIO_GPIOCFGD_GPIO25INCFG(v)        (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO25INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO25INCFG)) & (BFM_GPIO_GPIOCFGD_GPIO25INCFG)) ))
#define BFR_GPIO_GPIOCFGD_GPIO25INCFG()         ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO25INCFG))>>(BFP_GPIO_GPIOCFGD_GPIO25INCFG))

#define BFP_GPIO_GPIOCFGD_GPIO24INTD            (3)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO24INTD            ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO24INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO24INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO24INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO24INTD)) & (BFM_GPIO_GPIOCFGD_GPIO24INTD))
#define BFX_GPIO_GPIOCFGD_GPIO24INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO24INTD)) >> (BFP_GPIO_GPIOCFGD_GPIO24INTD))
#define BFW_GPIO_GPIOCFGD_GPIO24INTD(v)         (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO24INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO24INTD)) & (BFM_GPIO_GPIOCFGD_GPIO24INTD)) ))
#define BFR_GPIO_GPIOCFGD_GPIO24INTD()          ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO24INTD))>>(BFP_GPIO_GPIOCFGD_GPIO24INTD))

#define BFP_GPIO_GPIOCFGD_GPIO24OUTCFG          (1)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO24OUTCFG          ((uint32_t)0x00000006)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO24OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO24OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO24OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO24OUTCFG)) & (BFM_GPIO_GPIOCFGD_GPIO24OUTCFG))
#define BFX_GPIO_GPIOCFGD_GPIO24OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO24OUTCFG)) >> (BFP_GPIO_GPIOCFGD_GPIO24OUTCFG))
#define BFW_GPIO_GPIOCFGD_GPIO24OUTCFG(v)       (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO24OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO24OUTCFG)) & (BFM_GPIO_GPIOCFGD_GPIO24OUTCFG)) ))
#define BFR_GPIO_GPIOCFGD_GPIO24OUTCFG()        ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO24OUTCFG))>>(BFP_GPIO_GPIOCFGD_GPIO24OUTCFG))

#define BFP_GPIO_GPIOCFGD_GPIO24INCFG           (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGD_GPIO24INCFG           ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGD_GPIO24INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGD_GPIO24INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGD_GPIO24INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGD_GPIO24INCFG)) & (BFM_GPIO_GPIOCFGD_GPIO24INCFG))
#define BFX_GPIO_GPIOCFGD_GPIO24INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGD_GPIO24INCFG)) >> (BFP_GPIO_GPIOCFGD_GPIO24INCFG))
#define BFW_GPIO_GPIOCFGD_GPIO24INCFG(v)        (REG_GPIO_GPIOCFGD.U32 = ( (REG_GPIO_GPIOCFGD.U32 & ~(BFM_GPIO_GPIOCFGD_GPIO24INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGD_GPIO24INCFG)) & (BFM_GPIO_GPIOCFGD_GPIO24INCFG)) ))
#define BFR_GPIO_GPIOCFGD_GPIO24INCFG()         ((REG_GPIO_GPIOCFGD.U32 & (BFM_GPIO_GPIOCFGD_GPIO24INCFG))>>(BFP_GPIO_GPIOCFGD_GPIO24INCFG))


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOCFGE - GPIO Configuration Register E                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned GPIO39INTD                 :  1;
        unsigned GPIO39OUTCFG               :  2;
        unsigned GPIO39INCFG                :  1;
        unsigned GPIO38INTD                 :  1;
        unsigned GPIO38OUTCFG               :  2;
        unsigned GPIO38INCFG                :  1;
        unsigned GPIO37INTD                 :  1;
        unsigned GPIO37OUTCFG               :  2;
        unsigned GPIO37INCFG                :  1;
        unsigned GPIO36INTD                 :  1;
        unsigned GPIO36OUTCFG               :  2;
        unsigned GPIO36INCFG                :  1;
        unsigned GPIO35INTD                 :  1;
        unsigned GPIO35OUTCFG               :  2;
        unsigned GPIO35INCFG                :  1;
        unsigned GPIO34INTD                 :  1;
        unsigned GPIO34OUTCFG               :  2;
        unsigned GPIO34INCFG                :  1;
        unsigned GPIO33INTD                 :  1;
        unsigned GPIO33OUTCFG               :  2;
        unsigned GPIO33INCFG                :  1;
        unsigned GPIO32INTD                 :  1;
        unsigned GPIO32OUTCFG               :  2;
        unsigned GPIO32INCFG                :  1;
    } B;
} reg_gpio_gpiocfge_t;

#define REG_GPIO_GPIOCFGE_ADDR                  (REG_GPIO_BASEADDR + 0x00000050UL)
#define REG_GPIO_GPIOCFGE                       (*(volatile reg_gpio_gpiocfge_t *) REG_GPIO_GPIOCFGE_ADDR)
#define REG_GPIO_GPIOCFGE_RD()                  (REG_GPIO_GPIOCFGE.U32)
#define REG_GPIO_GPIOCFGE_WR(v)                 (REG_GPIO_GPIOCFGE.U32 = (v))
#define REG_GPIO_GPIOCFGE_CLR(m)                (REG_GPIO_GPIOCFGE.U32 = ((REG_GPIO_GPIOCFGE.U32) & ~(m)))
#define REG_GPIO_GPIOCFGE_SET(m)                (REG_GPIO_GPIOCFGE.U32 = ((REG_GPIO_GPIOCFGE.U32) | (m)))
#define REG_GPIO_GPIOCFGE_DEF                   0x00000000

#define BFP_GPIO_GPIOCFGE_GPIO39INTD            (31)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO39INTD            ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO39INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO39INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO39INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO39INTD)) & (BFM_GPIO_GPIOCFGE_GPIO39INTD))
#define BFX_GPIO_GPIOCFGE_GPIO39INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO39INTD)) >> (BFP_GPIO_GPIOCFGE_GPIO39INTD))
#define BFW_GPIO_GPIOCFGE_GPIO39INTD(v)         (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO39INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO39INTD)) & (BFM_GPIO_GPIOCFGE_GPIO39INTD)) ))
#define BFR_GPIO_GPIOCFGE_GPIO39INTD()          ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO39INTD))>>(BFP_GPIO_GPIOCFGE_GPIO39INTD))

#define BFP_GPIO_GPIOCFGE_GPIO39OUTCFG          (29)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO39OUTCFG          ((uint32_t)0x60000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO39OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO39OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO39OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO39OUTCFG)) & (BFM_GPIO_GPIOCFGE_GPIO39OUTCFG))
#define BFX_GPIO_GPIOCFGE_GPIO39OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO39OUTCFG)) >> (BFP_GPIO_GPIOCFGE_GPIO39OUTCFG))
#define BFW_GPIO_GPIOCFGE_GPIO39OUTCFG(v)       (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO39OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO39OUTCFG)) & (BFM_GPIO_GPIOCFGE_GPIO39OUTCFG)) ))
#define BFR_GPIO_GPIOCFGE_GPIO39OUTCFG()        ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO39OUTCFG))>>(BFP_GPIO_GPIOCFGE_GPIO39OUTCFG))

#define BFP_GPIO_GPIOCFGE_GPIO39INCFG           (28)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO39INCFG           ((uint32_t)0x10000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO39INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO39INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO39INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO39INCFG)) & (BFM_GPIO_GPIOCFGE_GPIO39INCFG))
#define BFX_GPIO_GPIOCFGE_GPIO39INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO39INCFG)) >> (BFP_GPIO_GPIOCFGE_GPIO39INCFG))
#define BFW_GPIO_GPIOCFGE_GPIO39INCFG(v)        (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO39INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO39INCFG)) & (BFM_GPIO_GPIOCFGE_GPIO39INCFG)) ))
#define BFR_GPIO_GPIOCFGE_GPIO39INCFG()         ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO39INCFG))>>(BFP_GPIO_GPIOCFGE_GPIO39INCFG))

#define BFP_GPIO_GPIOCFGE_GPIO38INTD            (27)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO38INTD            ((uint32_t)0x08000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO38INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO38INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO38INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO38INTD)) & (BFM_GPIO_GPIOCFGE_GPIO38INTD))
#define BFX_GPIO_GPIOCFGE_GPIO38INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO38INTD)) >> (BFP_GPIO_GPIOCFGE_GPIO38INTD))
#define BFW_GPIO_GPIOCFGE_GPIO38INTD(v)         (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO38INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO38INTD)) & (BFM_GPIO_GPIOCFGE_GPIO38INTD)) ))
#define BFR_GPIO_GPIOCFGE_GPIO38INTD()          ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO38INTD))>>(BFP_GPIO_GPIOCFGE_GPIO38INTD))

#define BFP_GPIO_GPIOCFGE_GPIO38OUTCFG          (25)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO38OUTCFG          ((uint32_t)0x06000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO38OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO38OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO38OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO38OUTCFG)) & (BFM_GPIO_GPIOCFGE_GPIO38OUTCFG))
#define BFX_GPIO_GPIOCFGE_GPIO38OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO38OUTCFG)) >> (BFP_GPIO_GPIOCFGE_GPIO38OUTCFG))
#define BFW_GPIO_GPIOCFGE_GPIO38OUTCFG(v)       (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO38OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO38OUTCFG)) & (BFM_GPIO_GPIOCFGE_GPIO38OUTCFG)) ))
#define BFR_GPIO_GPIOCFGE_GPIO38OUTCFG()        ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO38OUTCFG))>>(BFP_GPIO_GPIOCFGE_GPIO38OUTCFG))

#define BFP_GPIO_GPIOCFGE_GPIO38INCFG           (24)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO38INCFG           ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO38INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO38INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO38INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO38INCFG)) & (BFM_GPIO_GPIOCFGE_GPIO38INCFG))
#define BFX_GPIO_GPIOCFGE_GPIO38INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO38INCFG)) >> (BFP_GPIO_GPIOCFGE_GPIO38INCFG))
#define BFW_GPIO_GPIOCFGE_GPIO38INCFG(v)        (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO38INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO38INCFG)) & (BFM_GPIO_GPIOCFGE_GPIO38INCFG)) ))
#define BFR_GPIO_GPIOCFGE_GPIO38INCFG()         ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO38INCFG))>>(BFP_GPIO_GPIOCFGE_GPIO38INCFG))

#define BFP_GPIO_GPIOCFGE_GPIO37INTD            (23)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO37INTD            ((uint32_t)0x00800000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO37INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO37INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO37INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO37INTD)) & (BFM_GPIO_GPIOCFGE_GPIO37INTD))
#define BFX_GPIO_GPIOCFGE_GPIO37INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO37INTD)) >> (BFP_GPIO_GPIOCFGE_GPIO37INTD))
#define BFW_GPIO_GPIOCFGE_GPIO37INTD(v)         (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO37INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO37INTD)) & (BFM_GPIO_GPIOCFGE_GPIO37INTD)) ))
#define BFR_GPIO_GPIOCFGE_GPIO37INTD()          ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO37INTD))>>(BFP_GPIO_GPIOCFGE_GPIO37INTD))

#define BFP_GPIO_GPIOCFGE_GPIO37OUTCFG          (21)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO37OUTCFG          ((uint32_t)0x00600000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO37OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO37OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO37OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO37OUTCFG)) & (BFM_GPIO_GPIOCFGE_GPIO37OUTCFG))
#define BFX_GPIO_GPIOCFGE_GPIO37OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO37OUTCFG)) >> (BFP_GPIO_GPIOCFGE_GPIO37OUTCFG))
#define BFW_GPIO_GPIOCFGE_GPIO37OUTCFG(v)       (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO37OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO37OUTCFG)) & (BFM_GPIO_GPIOCFGE_GPIO37OUTCFG)) ))
#define BFR_GPIO_GPIOCFGE_GPIO37OUTCFG()        ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO37OUTCFG))>>(BFP_GPIO_GPIOCFGE_GPIO37OUTCFG))

#define BFP_GPIO_GPIOCFGE_GPIO37INCFG           (20)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO37INCFG           ((uint32_t)0x00100000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO37INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO37INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO37INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO37INCFG)) & (BFM_GPIO_GPIOCFGE_GPIO37INCFG))
#define BFX_GPIO_GPIOCFGE_GPIO37INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO37INCFG)) >> (BFP_GPIO_GPIOCFGE_GPIO37INCFG))
#define BFW_GPIO_GPIOCFGE_GPIO37INCFG(v)        (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO37INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO37INCFG)) & (BFM_GPIO_GPIOCFGE_GPIO37INCFG)) ))
#define BFR_GPIO_GPIOCFGE_GPIO37INCFG()         ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO37INCFG))>>(BFP_GPIO_GPIOCFGE_GPIO37INCFG))

#define BFP_GPIO_GPIOCFGE_GPIO36INTD            (19)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO36INTD            ((uint32_t)0x00080000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO36INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO36INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO36INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO36INTD)) & (BFM_GPIO_GPIOCFGE_GPIO36INTD))
#define BFX_GPIO_GPIOCFGE_GPIO36INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO36INTD)) >> (BFP_GPIO_GPIOCFGE_GPIO36INTD))
#define BFW_GPIO_GPIOCFGE_GPIO36INTD(v)         (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO36INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO36INTD)) & (BFM_GPIO_GPIOCFGE_GPIO36INTD)) ))
#define BFR_GPIO_GPIOCFGE_GPIO36INTD()          ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO36INTD))>>(BFP_GPIO_GPIOCFGE_GPIO36INTD))

#define BFP_GPIO_GPIOCFGE_GPIO36OUTCFG          (17)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO36OUTCFG          ((uint32_t)0x00060000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO36OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO36OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO36OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO36OUTCFG)) & (BFM_GPIO_GPIOCFGE_GPIO36OUTCFG))
#define BFX_GPIO_GPIOCFGE_GPIO36OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO36OUTCFG)) >> (BFP_GPIO_GPIOCFGE_GPIO36OUTCFG))
#define BFW_GPIO_GPIOCFGE_GPIO36OUTCFG(v)       (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO36OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO36OUTCFG)) & (BFM_GPIO_GPIOCFGE_GPIO36OUTCFG)) ))
#define BFR_GPIO_GPIOCFGE_GPIO36OUTCFG()        ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO36OUTCFG))>>(BFP_GPIO_GPIOCFGE_GPIO36OUTCFG))

#define BFP_GPIO_GPIOCFGE_GPIO36INCFG           (16)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO36INCFG           ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO36INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO36INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO36INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO36INCFG)) & (BFM_GPIO_GPIOCFGE_GPIO36INCFG))
#define BFX_GPIO_GPIOCFGE_GPIO36INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO36INCFG)) >> (BFP_GPIO_GPIOCFGE_GPIO36INCFG))
#define BFW_GPIO_GPIOCFGE_GPIO36INCFG(v)        (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO36INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO36INCFG)) & (BFM_GPIO_GPIOCFGE_GPIO36INCFG)) ))
#define BFR_GPIO_GPIOCFGE_GPIO36INCFG()         ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO36INCFG))>>(BFP_GPIO_GPIOCFGE_GPIO36INCFG))

#define BFP_GPIO_GPIOCFGE_GPIO35INTD            (15)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO35INTD            ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO35INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO35INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO35INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO35INTD)) & (BFM_GPIO_GPIOCFGE_GPIO35INTD))
#define BFX_GPIO_GPIOCFGE_GPIO35INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO35INTD)) >> (BFP_GPIO_GPIOCFGE_GPIO35INTD))
#define BFW_GPIO_GPIOCFGE_GPIO35INTD(v)         (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO35INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO35INTD)) & (BFM_GPIO_GPIOCFGE_GPIO35INTD)) ))
#define BFR_GPIO_GPIOCFGE_GPIO35INTD()          ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO35INTD))>>(BFP_GPIO_GPIOCFGE_GPIO35INTD))

#define BFP_GPIO_GPIOCFGE_GPIO35OUTCFG          (13)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO35OUTCFG          ((uint32_t)0x00006000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO35OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO35OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO35OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO35OUTCFG)) & (BFM_GPIO_GPIOCFGE_GPIO35OUTCFG))
#define BFX_GPIO_GPIOCFGE_GPIO35OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO35OUTCFG)) >> (BFP_GPIO_GPIOCFGE_GPIO35OUTCFG))
#define BFW_GPIO_GPIOCFGE_GPIO35OUTCFG(v)       (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO35OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO35OUTCFG)) & (BFM_GPIO_GPIOCFGE_GPIO35OUTCFG)) ))
#define BFR_GPIO_GPIOCFGE_GPIO35OUTCFG()        ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO35OUTCFG))>>(BFP_GPIO_GPIOCFGE_GPIO35OUTCFG))

#define BFP_GPIO_GPIOCFGE_GPIO35INCFG           (12)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO35INCFG           ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO35INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO35INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO35INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO35INCFG)) & (BFM_GPIO_GPIOCFGE_GPIO35INCFG))
#define BFX_GPIO_GPIOCFGE_GPIO35INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO35INCFG)) >> (BFP_GPIO_GPIOCFGE_GPIO35INCFG))
#define BFW_GPIO_GPIOCFGE_GPIO35INCFG(v)        (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO35INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO35INCFG)) & (BFM_GPIO_GPIOCFGE_GPIO35INCFG)) ))
#define BFR_GPIO_GPIOCFGE_GPIO35INCFG()         ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO35INCFG))>>(BFP_GPIO_GPIOCFGE_GPIO35INCFG))

#define BFP_GPIO_GPIOCFGE_GPIO34INTD            (11)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO34INTD            ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO34INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO34INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO34INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO34INTD)) & (BFM_GPIO_GPIOCFGE_GPIO34INTD))
#define BFX_GPIO_GPIOCFGE_GPIO34INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO34INTD)) >> (BFP_GPIO_GPIOCFGE_GPIO34INTD))
#define BFW_GPIO_GPIOCFGE_GPIO34INTD(v)         (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO34INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO34INTD)) & (BFM_GPIO_GPIOCFGE_GPIO34INTD)) ))
#define BFR_GPIO_GPIOCFGE_GPIO34INTD()          ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO34INTD))>>(BFP_GPIO_GPIOCFGE_GPIO34INTD))

#define BFP_GPIO_GPIOCFGE_GPIO34OUTCFG          (9)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO34OUTCFG          ((uint32_t)0x00000600)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO34OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO34OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO34OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO34OUTCFG)) & (BFM_GPIO_GPIOCFGE_GPIO34OUTCFG))
#define BFX_GPIO_GPIOCFGE_GPIO34OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO34OUTCFG)) >> (BFP_GPIO_GPIOCFGE_GPIO34OUTCFG))
#define BFW_GPIO_GPIOCFGE_GPIO34OUTCFG(v)       (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO34OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO34OUTCFG)) & (BFM_GPIO_GPIOCFGE_GPIO34OUTCFG)) ))
#define BFR_GPIO_GPIOCFGE_GPIO34OUTCFG()        ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO34OUTCFG))>>(BFP_GPIO_GPIOCFGE_GPIO34OUTCFG))

#define BFP_GPIO_GPIOCFGE_GPIO34INCFG           (8)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO34INCFG           ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO34INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO34INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO34INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO34INCFG)) & (BFM_GPIO_GPIOCFGE_GPIO34INCFG))
#define BFX_GPIO_GPIOCFGE_GPIO34INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO34INCFG)) >> (BFP_GPIO_GPIOCFGE_GPIO34INCFG))
#define BFW_GPIO_GPIOCFGE_GPIO34INCFG(v)        (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO34INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO34INCFG)) & (BFM_GPIO_GPIOCFGE_GPIO34INCFG)) ))
#define BFR_GPIO_GPIOCFGE_GPIO34INCFG()         ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO34INCFG))>>(BFP_GPIO_GPIOCFGE_GPIO34INCFG))

#define BFP_GPIO_GPIOCFGE_GPIO33INTD            (7)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO33INTD            ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO33INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO33INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO33INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO33INTD)) & (BFM_GPIO_GPIOCFGE_GPIO33INTD))
#define BFX_GPIO_GPIOCFGE_GPIO33INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO33INTD)) >> (BFP_GPIO_GPIOCFGE_GPIO33INTD))
#define BFW_GPIO_GPIOCFGE_GPIO33INTD(v)         (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO33INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO33INTD)) & (BFM_GPIO_GPIOCFGE_GPIO33INTD)) ))
#define BFR_GPIO_GPIOCFGE_GPIO33INTD()          ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO33INTD))>>(BFP_GPIO_GPIOCFGE_GPIO33INTD))

#define BFP_GPIO_GPIOCFGE_GPIO33OUTCFG          (5)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO33OUTCFG          ((uint32_t)0x00000060)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO33OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO33OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO33OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO33OUTCFG)) & (BFM_GPIO_GPIOCFGE_GPIO33OUTCFG))
#define BFX_GPIO_GPIOCFGE_GPIO33OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO33OUTCFG)) >> (BFP_GPIO_GPIOCFGE_GPIO33OUTCFG))
#define BFW_GPIO_GPIOCFGE_GPIO33OUTCFG(v)       (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO33OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO33OUTCFG)) & (BFM_GPIO_GPIOCFGE_GPIO33OUTCFG)) ))
#define BFR_GPIO_GPIOCFGE_GPIO33OUTCFG()        ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO33OUTCFG))>>(BFP_GPIO_GPIOCFGE_GPIO33OUTCFG))

#define BFP_GPIO_GPIOCFGE_GPIO33INCFG           (4)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO33INCFG           ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO33INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO33INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO33INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO33INCFG)) & (BFM_GPIO_GPIOCFGE_GPIO33INCFG))
#define BFX_GPIO_GPIOCFGE_GPIO33INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO33INCFG)) >> (BFP_GPIO_GPIOCFGE_GPIO33INCFG))
#define BFW_GPIO_GPIOCFGE_GPIO33INCFG(v)        (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO33INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO33INCFG)) & (BFM_GPIO_GPIOCFGE_GPIO33INCFG)) ))
#define BFR_GPIO_GPIOCFGE_GPIO33INCFG()         ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO33INCFG))>>(BFP_GPIO_GPIOCFGE_GPIO33INCFG))

#define BFP_GPIO_GPIOCFGE_GPIO32INTD            (3)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO32INTD            ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO32INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO32INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO32INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO32INTD)) & (BFM_GPIO_GPIOCFGE_GPIO32INTD))
#define BFX_GPIO_GPIOCFGE_GPIO32INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO32INTD)) >> (BFP_GPIO_GPIOCFGE_GPIO32INTD))
#define BFW_GPIO_GPIOCFGE_GPIO32INTD(v)         (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO32INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO32INTD)) & (BFM_GPIO_GPIOCFGE_GPIO32INTD)) ))
#define BFR_GPIO_GPIOCFGE_GPIO32INTD()          ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO32INTD))>>(BFP_GPIO_GPIOCFGE_GPIO32INTD))

#define BFP_GPIO_GPIOCFGE_GPIO32OUTCFG          (1)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO32OUTCFG          ((uint32_t)0x00000006)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO32OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO32OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO32OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO32OUTCFG)) & (BFM_GPIO_GPIOCFGE_GPIO32OUTCFG))
#define BFX_GPIO_GPIOCFGE_GPIO32OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO32OUTCFG)) >> (BFP_GPIO_GPIOCFGE_GPIO32OUTCFG))
#define BFW_GPIO_GPIOCFGE_GPIO32OUTCFG(v)       (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO32OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO32OUTCFG)) & (BFM_GPIO_GPIOCFGE_GPIO32OUTCFG)) ))
#define BFR_GPIO_GPIOCFGE_GPIO32OUTCFG()        ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO32OUTCFG))>>(BFP_GPIO_GPIOCFGE_GPIO32OUTCFG))

#define BFP_GPIO_GPIOCFGE_GPIO32INCFG           (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGE_GPIO32INCFG           ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGE_GPIO32INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGE_GPIO32INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGE_GPIO32INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGE_GPIO32INCFG)) & (BFM_GPIO_GPIOCFGE_GPIO32INCFG))
#define BFX_GPIO_GPIOCFGE_GPIO32INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGE_GPIO32INCFG)) >> (BFP_GPIO_GPIOCFGE_GPIO32INCFG))
#define BFW_GPIO_GPIOCFGE_GPIO32INCFG(v)        (REG_GPIO_GPIOCFGE.U32 = ( (REG_GPIO_GPIOCFGE.U32 & ~(BFM_GPIO_GPIOCFGE_GPIO32INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGE_GPIO32INCFG)) & (BFM_GPIO_GPIOCFGE_GPIO32INCFG)) ))
#define BFR_GPIO_GPIOCFGE_GPIO32INCFG()         ((REG_GPIO_GPIOCFGE.U32 & (BFM_GPIO_GPIOCFGE_GPIO32INCFG))>>(BFP_GPIO_GPIOCFGE_GPIO32INCFG))


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOCFGF - GPIO Configuration Register F                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned GPIO47INTD                 :  1;
        unsigned GPIO47OUTCFG               :  2;
        unsigned GPIO47INCFG                :  1;
        unsigned GPIO46INTD                 :  1;
        unsigned GPIO46OUTCFG               :  2;
        unsigned GPIO46INCFG                :  1;
        unsigned GPIO45INTD                 :  1;
        unsigned GPIO45OUTCFG               :  2;
        unsigned GPIO45INCFG                :  1;
        unsigned GPIO44INTD                 :  1;
        unsigned GPIO44OUTCFG               :  2;
        unsigned GPIO44INCFG                :  1;
        unsigned GPIO43INTD                 :  1;
        unsigned GPIO43OUTCFG               :  2;
        unsigned GPIO43INCFG                :  1;
        unsigned GPIO42INTD                 :  1;
        unsigned GPIO42OUTCFG               :  2;
        unsigned GPIO42INCFG                :  1;
        unsigned GPIO41INTD                 :  1;
        unsigned GPIO41OUTCFG               :  2;
        unsigned GPIO41INCFG                :  1;
        unsigned GPIO40INTD                 :  1;
        unsigned GPIO40OUTCFG               :  2;
        unsigned GPIO40INCFG                :  1;
    } B;
} reg_gpio_gpiocfgf_t;

#define REG_GPIO_GPIOCFGF_ADDR                  (REG_GPIO_BASEADDR + 0x00000054UL)
#define REG_GPIO_GPIOCFGF                       (*(volatile reg_gpio_gpiocfgf_t *) REG_GPIO_GPIOCFGF_ADDR)
#define REG_GPIO_GPIOCFGF_RD()                  (REG_GPIO_GPIOCFGF.U32)
#define REG_GPIO_GPIOCFGF_WR(v)                 (REG_GPIO_GPIOCFGF.U32 = (v))
#define REG_GPIO_GPIOCFGF_CLR(m)                (REG_GPIO_GPIOCFGF.U32 = ((REG_GPIO_GPIOCFGF.U32) & ~(m)))
#define REG_GPIO_GPIOCFGF_SET(m)                (REG_GPIO_GPIOCFGF.U32 = ((REG_GPIO_GPIOCFGF.U32) | (m)))
#define REG_GPIO_GPIOCFGF_DEF                   0x00000000

#define BFP_GPIO_GPIOCFGF_GPIO47INTD            (31)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO47INTD            ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO47INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO47INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO47INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO47INTD)) & (BFM_GPIO_GPIOCFGF_GPIO47INTD))
#define BFX_GPIO_GPIOCFGF_GPIO47INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO47INTD)) >> (BFP_GPIO_GPIOCFGF_GPIO47INTD))
#define BFW_GPIO_GPIOCFGF_GPIO47INTD(v)         (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO47INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO47INTD)) & (BFM_GPIO_GPIOCFGF_GPIO47INTD)) ))
#define BFR_GPIO_GPIOCFGF_GPIO47INTD()          ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO47INTD))>>(BFP_GPIO_GPIOCFGF_GPIO47INTD))

#define BFP_GPIO_GPIOCFGF_GPIO47OUTCFG          (29)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO47OUTCFG          ((uint32_t)0x60000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO47OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO47OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO47OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO47OUTCFG)) & (BFM_GPIO_GPIOCFGF_GPIO47OUTCFG))
#define BFX_GPIO_GPIOCFGF_GPIO47OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO47OUTCFG)) >> (BFP_GPIO_GPIOCFGF_GPIO47OUTCFG))
#define BFW_GPIO_GPIOCFGF_GPIO47OUTCFG(v)       (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO47OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO47OUTCFG)) & (BFM_GPIO_GPIOCFGF_GPIO47OUTCFG)) ))
#define BFR_GPIO_GPIOCFGF_GPIO47OUTCFG()        ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO47OUTCFG))>>(BFP_GPIO_GPIOCFGF_GPIO47OUTCFG))

#define BFP_GPIO_GPIOCFGF_GPIO47INCFG           (28)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO47INCFG           ((uint32_t)0x10000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO47INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO47INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO47INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO47INCFG)) & (BFM_GPIO_GPIOCFGF_GPIO47INCFG))
#define BFX_GPIO_GPIOCFGF_GPIO47INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO47INCFG)) >> (BFP_GPIO_GPIOCFGF_GPIO47INCFG))
#define BFW_GPIO_GPIOCFGF_GPIO47INCFG(v)        (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO47INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO47INCFG)) & (BFM_GPIO_GPIOCFGF_GPIO47INCFG)) ))
#define BFR_GPIO_GPIOCFGF_GPIO47INCFG()         ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO47INCFG))>>(BFP_GPIO_GPIOCFGF_GPIO47INCFG))

#define BFP_GPIO_GPIOCFGF_GPIO46INTD            (27)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO46INTD            ((uint32_t)0x08000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO46INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO46INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO46INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO46INTD)) & (BFM_GPIO_GPIOCFGF_GPIO46INTD))
#define BFX_GPIO_GPIOCFGF_GPIO46INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO46INTD)) >> (BFP_GPIO_GPIOCFGF_GPIO46INTD))
#define BFW_GPIO_GPIOCFGF_GPIO46INTD(v)         (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO46INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO46INTD)) & (BFM_GPIO_GPIOCFGF_GPIO46INTD)) ))
#define BFR_GPIO_GPIOCFGF_GPIO46INTD()          ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO46INTD))>>(BFP_GPIO_GPIOCFGF_GPIO46INTD))

#define BFP_GPIO_GPIOCFGF_GPIO46OUTCFG          (25)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO46OUTCFG          ((uint32_t)0x06000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO46OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO46OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO46OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO46OUTCFG)) & (BFM_GPIO_GPIOCFGF_GPIO46OUTCFG))
#define BFX_GPIO_GPIOCFGF_GPIO46OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO46OUTCFG)) >> (BFP_GPIO_GPIOCFGF_GPIO46OUTCFG))
#define BFW_GPIO_GPIOCFGF_GPIO46OUTCFG(v)       (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO46OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO46OUTCFG)) & (BFM_GPIO_GPIOCFGF_GPIO46OUTCFG)) ))
#define BFR_GPIO_GPIOCFGF_GPIO46OUTCFG()        ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO46OUTCFG))>>(BFP_GPIO_GPIOCFGF_GPIO46OUTCFG))

#define BFP_GPIO_GPIOCFGF_GPIO46INCFG           (24)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO46INCFG           ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO46INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO46INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO46INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO46INCFG)) & (BFM_GPIO_GPIOCFGF_GPIO46INCFG))
#define BFX_GPIO_GPIOCFGF_GPIO46INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO46INCFG)) >> (BFP_GPIO_GPIOCFGF_GPIO46INCFG))
#define BFW_GPIO_GPIOCFGF_GPIO46INCFG(v)        (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO46INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO46INCFG)) & (BFM_GPIO_GPIOCFGF_GPIO46INCFG)) ))
#define BFR_GPIO_GPIOCFGF_GPIO46INCFG()         ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO46INCFG))>>(BFP_GPIO_GPIOCFGF_GPIO46INCFG))

#define BFP_GPIO_GPIOCFGF_GPIO45INTD            (23)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO45INTD            ((uint32_t)0x00800000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO45INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO45INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO45INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO45INTD)) & (BFM_GPIO_GPIOCFGF_GPIO45INTD))
#define BFX_GPIO_GPIOCFGF_GPIO45INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO45INTD)) >> (BFP_GPIO_GPIOCFGF_GPIO45INTD))
#define BFW_GPIO_GPIOCFGF_GPIO45INTD(v)         (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO45INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO45INTD)) & (BFM_GPIO_GPIOCFGF_GPIO45INTD)) ))
#define BFR_GPIO_GPIOCFGF_GPIO45INTD()          ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO45INTD))>>(BFP_GPIO_GPIOCFGF_GPIO45INTD))

#define BFP_GPIO_GPIOCFGF_GPIO45OUTCFG          (21)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO45OUTCFG          ((uint32_t)0x00600000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO45OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO45OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO45OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO45OUTCFG)) & (BFM_GPIO_GPIOCFGF_GPIO45OUTCFG))
#define BFX_GPIO_GPIOCFGF_GPIO45OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO45OUTCFG)) >> (BFP_GPIO_GPIOCFGF_GPIO45OUTCFG))
#define BFW_GPIO_GPIOCFGF_GPIO45OUTCFG(v)       (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO45OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO45OUTCFG)) & (BFM_GPIO_GPIOCFGF_GPIO45OUTCFG)) ))
#define BFR_GPIO_GPIOCFGF_GPIO45OUTCFG()        ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO45OUTCFG))>>(BFP_GPIO_GPIOCFGF_GPIO45OUTCFG))

#define BFP_GPIO_GPIOCFGF_GPIO45INCFG           (20)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO45INCFG           ((uint32_t)0x00100000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO45INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO45INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO45INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO45INCFG)) & (BFM_GPIO_GPIOCFGF_GPIO45INCFG))
#define BFX_GPIO_GPIOCFGF_GPIO45INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO45INCFG)) >> (BFP_GPIO_GPIOCFGF_GPIO45INCFG))
#define BFW_GPIO_GPIOCFGF_GPIO45INCFG(v)        (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO45INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO45INCFG)) & (BFM_GPIO_GPIOCFGF_GPIO45INCFG)) ))
#define BFR_GPIO_GPIOCFGF_GPIO45INCFG()         ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO45INCFG))>>(BFP_GPIO_GPIOCFGF_GPIO45INCFG))

#define BFP_GPIO_GPIOCFGF_GPIO44INTD            (19)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO44INTD            ((uint32_t)0x00080000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO44INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO44INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO44INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO44INTD)) & (BFM_GPIO_GPIOCFGF_GPIO44INTD))
#define BFX_GPIO_GPIOCFGF_GPIO44INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO44INTD)) >> (BFP_GPIO_GPIOCFGF_GPIO44INTD))
#define BFW_GPIO_GPIOCFGF_GPIO44INTD(v)         (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO44INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO44INTD)) & (BFM_GPIO_GPIOCFGF_GPIO44INTD)) ))
#define BFR_GPIO_GPIOCFGF_GPIO44INTD()          ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO44INTD))>>(BFP_GPIO_GPIOCFGF_GPIO44INTD))

#define BFP_GPIO_GPIOCFGF_GPIO44OUTCFG          (17)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO44OUTCFG          ((uint32_t)0x00060000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO44OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO44OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO44OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO44OUTCFG)) & (BFM_GPIO_GPIOCFGF_GPIO44OUTCFG))
#define BFX_GPIO_GPIOCFGF_GPIO44OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO44OUTCFG)) >> (BFP_GPIO_GPIOCFGF_GPIO44OUTCFG))
#define BFW_GPIO_GPIOCFGF_GPIO44OUTCFG(v)       (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO44OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO44OUTCFG)) & (BFM_GPIO_GPIOCFGF_GPIO44OUTCFG)) ))
#define BFR_GPIO_GPIOCFGF_GPIO44OUTCFG()        ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO44OUTCFG))>>(BFP_GPIO_GPIOCFGF_GPIO44OUTCFG))

#define BFP_GPIO_GPIOCFGF_GPIO44INCFG           (16)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO44INCFG           ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO44INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO44INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO44INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO44INCFG)) & (BFM_GPIO_GPIOCFGF_GPIO44INCFG))
#define BFX_GPIO_GPIOCFGF_GPIO44INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO44INCFG)) >> (BFP_GPIO_GPIOCFGF_GPIO44INCFG))
#define BFW_GPIO_GPIOCFGF_GPIO44INCFG(v)        (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO44INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO44INCFG)) & (BFM_GPIO_GPIOCFGF_GPIO44INCFG)) ))
#define BFR_GPIO_GPIOCFGF_GPIO44INCFG()         ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO44INCFG))>>(BFP_GPIO_GPIOCFGF_GPIO44INCFG))

#define BFP_GPIO_GPIOCFGF_GPIO43INTD            (15)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO43INTD            ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO43INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO43INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO43INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO43INTD)) & (BFM_GPIO_GPIOCFGF_GPIO43INTD))
#define BFX_GPIO_GPIOCFGF_GPIO43INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO43INTD)) >> (BFP_GPIO_GPIOCFGF_GPIO43INTD))
#define BFW_GPIO_GPIOCFGF_GPIO43INTD(v)         (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO43INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO43INTD)) & (BFM_GPIO_GPIOCFGF_GPIO43INTD)) ))
#define BFR_GPIO_GPIOCFGF_GPIO43INTD()          ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO43INTD))>>(BFP_GPIO_GPIOCFGF_GPIO43INTD))

#define BFP_GPIO_GPIOCFGF_GPIO43OUTCFG          (13)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO43OUTCFG          ((uint32_t)0x00006000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO43OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO43OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO43OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO43OUTCFG)) & (BFM_GPIO_GPIOCFGF_GPIO43OUTCFG))
#define BFX_GPIO_GPIOCFGF_GPIO43OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO43OUTCFG)) >> (BFP_GPIO_GPIOCFGF_GPIO43OUTCFG))
#define BFW_GPIO_GPIOCFGF_GPIO43OUTCFG(v)       (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO43OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO43OUTCFG)) & (BFM_GPIO_GPIOCFGF_GPIO43OUTCFG)) ))
#define BFR_GPIO_GPIOCFGF_GPIO43OUTCFG()        ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO43OUTCFG))>>(BFP_GPIO_GPIOCFGF_GPIO43OUTCFG))

#define BFP_GPIO_GPIOCFGF_GPIO43INCFG           (12)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO43INCFG           ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO43INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO43INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO43INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO43INCFG)) & (BFM_GPIO_GPIOCFGF_GPIO43INCFG))
#define BFX_GPIO_GPIOCFGF_GPIO43INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO43INCFG)) >> (BFP_GPIO_GPIOCFGF_GPIO43INCFG))
#define BFW_GPIO_GPIOCFGF_GPIO43INCFG(v)        (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO43INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO43INCFG)) & (BFM_GPIO_GPIOCFGF_GPIO43INCFG)) ))
#define BFR_GPIO_GPIOCFGF_GPIO43INCFG()         ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO43INCFG))>>(BFP_GPIO_GPIOCFGF_GPIO43INCFG))

#define BFP_GPIO_GPIOCFGF_GPIO42INTD            (11)                    /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO42INTD            ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO42INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO42INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO42INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO42INTD)) & (BFM_GPIO_GPIOCFGF_GPIO42INTD))
#define BFX_GPIO_GPIOCFGF_GPIO42INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO42INTD)) >> (BFP_GPIO_GPIOCFGF_GPIO42INTD))
#define BFW_GPIO_GPIOCFGF_GPIO42INTD(v)         (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO42INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO42INTD)) & (BFM_GPIO_GPIOCFGF_GPIO42INTD)) ))
#define BFR_GPIO_GPIOCFGF_GPIO42INTD()          ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO42INTD))>>(BFP_GPIO_GPIOCFGF_GPIO42INTD))

#define BFP_GPIO_GPIOCFGF_GPIO42OUTCFG          (9)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO42OUTCFG          ((uint32_t)0x00000600)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO42OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO42OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO42OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO42OUTCFG)) & (BFM_GPIO_GPIOCFGF_GPIO42OUTCFG))
#define BFX_GPIO_GPIOCFGF_GPIO42OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO42OUTCFG)) >> (BFP_GPIO_GPIOCFGF_GPIO42OUTCFG))
#define BFW_GPIO_GPIOCFGF_GPIO42OUTCFG(v)       (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO42OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO42OUTCFG)) & (BFM_GPIO_GPIOCFGF_GPIO42OUTCFG)) ))
#define BFR_GPIO_GPIOCFGF_GPIO42OUTCFG()        ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO42OUTCFG))>>(BFP_GPIO_GPIOCFGF_GPIO42OUTCFG))

#define BFP_GPIO_GPIOCFGF_GPIO42INCFG           (8)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO42INCFG           ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO42INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO42INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO42INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO42INCFG)) & (BFM_GPIO_GPIOCFGF_GPIO42INCFG))
#define BFX_GPIO_GPIOCFGF_GPIO42INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO42INCFG)) >> (BFP_GPIO_GPIOCFGF_GPIO42INCFG))
#define BFW_GPIO_GPIOCFGF_GPIO42INCFG(v)        (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO42INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO42INCFG)) & (BFM_GPIO_GPIOCFGF_GPIO42INCFG)) ))
#define BFR_GPIO_GPIOCFGF_GPIO42INCFG()         ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO42INCFG))>>(BFP_GPIO_GPIOCFGF_GPIO42INCFG))

#define BFP_GPIO_GPIOCFGF_GPIO41INTD            (7)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO41INTD            ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO41INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO41INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO41INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO41INTD)) & (BFM_GPIO_GPIOCFGF_GPIO41INTD))
#define BFX_GPIO_GPIOCFGF_GPIO41INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO41INTD)) >> (BFP_GPIO_GPIOCFGF_GPIO41INTD))
#define BFW_GPIO_GPIOCFGF_GPIO41INTD(v)         (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO41INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO41INTD)) & (BFM_GPIO_GPIOCFGF_GPIO41INTD)) ))
#define BFR_GPIO_GPIOCFGF_GPIO41INTD()          ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO41INTD))>>(BFP_GPIO_GPIOCFGF_GPIO41INTD))

#define BFP_GPIO_GPIOCFGF_GPIO41OUTCFG          (5)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO41OUTCFG          ((uint32_t)0x00000060)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO41OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO41OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO41OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO41OUTCFG)) & (BFM_GPIO_GPIOCFGF_GPIO41OUTCFG))
#define BFX_GPIO_GPIOCFGF_GPIO41OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO41OUTCFG)) >> (BFP_GPIO_GPIOCFGF_GPIO41OUTCFG))
#define BFW_GPIO_GPIOCFGF_GPIO41OUTCFG(v)       (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO41OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO41OUTCFG)) & (BFM_GPIO_GPIOCFGF_GPIO41OUTCFG)) ))
#define BFR_GPIO_GPIOCFGF_GPIO41OUTCFG()        ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO41OUTCFG))>>(BFP_GPIO_GPIOCFGF_GPIO41OUTCFG))

#define BFP_GPIO_GPIOCFGF_GPIO41INCFG           (4)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO41INCFG           ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO41INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO41INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO41INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO41INCFG)) & (BFM_GPIO_GPIOCFGF_GPIO41INCFG))
#define BFX_GPIO_GPIOCFGF_GPIO41INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO41INCFG)) >> (BFP_GPIO_GPIOCFGF_GPIO41INCFG))
#define BFW_GPIO_GPIOCFGF_GPIO41INCFG(v)        (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO41INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO41INCFG)) & (BFM_GPIO_GPIOCFGF_GPIO41INCFG)) ))
#define BFR_GPIO_GPIOCFGF_GPIO41INCFG()         ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO41INCFG))>>(BFP_GPIO_GPIOCFGF_GPIO41INCFG))

#define BFP_GPIO_GPIOCFGF_GPIO40INTD            (3)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO40INTD            ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO40INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO40INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO40INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO40INTD)) & (BFM_GPIO_GPIOCFGF_GPIO40INTD))
#define BFX_GPIO_GPIOCFGF_GPIO40INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO40INTD)) >> (BFP_GPIO_GPIOCFGF_GPIO40INTD))
#define BFW_GPIO_GPIOCFGF_GPIO40INTD(v)         (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO40INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO40INTD)) & (BFM_GPIO_GPIOCFGF_GPIO40INTD)) ))
#define BFR_GPIO_GPIOCFGF_GPIO40INTD()          ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO40INTD))>>(BFP_GPIO_GPIOCFGF_GPIO40INTD))

#define BFP_GPIO_GPIOCFGF_GPIO40OUTCFG          (1)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO40OUTCFG          ((uint32_t)0x00000006)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO40OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO40OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO40OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO40OUTCFG)) & (BFM_GPIO_GPIOCFGF_GPIO40OUTCFG))
#define BFX_GPIO_GPIOCFGF_GPIO40OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO40OUTCFG)) >> (BFP_GPIO_GPIOCFGF_GPIO40OUTCFG))
#define BFW_GPIO_GPIOCFGF_GPIO40OUTCFG(v)       (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO40OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO40OUTCFG)) & (BFM_GPIO_GPIOCFGF_GPIO40OUTCFG)) ))
#define BFR_GPIO_GPIOCFGF_GPIO40OUTCFG()        ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO40OUTCFG))>>(BFP_GPIO_GPIOCFGF_GPIO40OUTCFG))

#define BFP_GPIO_GPIOCFGF_GPIO40INCFG           (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGF_GPIO40INCFG           ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGF_GPIO40INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGF_GPIO40INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGF_GPIO40INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGF_GPIO40INCFG)) & (BFM_GPIO_GPIOCFGF_GPIO40INCFG))
#define BFX_GPIO_GPIOCFGF_GPIO40INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGF_GPIO40INCFG)) >> (BFP_GPIO_GPIOCFGF_GPIO40INCFG))
#define BFW_GPIO_GPIOCFGF_GPIO40INCFG(v)        (REG_GPIO_GPIOCFGF.U32 = ( (REG_GPIO_GPIOCFGF.U32 & ~(BFM_GPIO_GPIOCFGF_GPIO40INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGF_GPIO40INCFG)) & (BFM_GPIO_GPIOCFGF_GPIO40INCFG)) ))
#define BFR_GPIO_GPIOCFGF_GPIO40INCFG()         ((REG_GPIO_GPIOCFGF.U32 & (BFM_GPIO_GPIOCFGF_GPIO40INCFG))>>(BFP_GPIO_GPIOCFGF_GPIO40INCFG))


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOCFGG - GPIO Configuration Register G                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned GPIO49INTD                 :  1;
        unsigned GPIO49OUTCFG               :  2;
        unsigned GPIO49INCFG                :  1;
        unsigned GPIO48INTD                 :  1;
        unsigned GPIO48OUTCFG               :  2;
        unsigned GPIO48INCFG                :  1;
    } B;
} reg_gpio_gpiocfgg_t;

#define REG_GPIO_GPIOCFGG_ADDR                  (REG_GPIO_BASEADDR + 0x00000058UL)
#define REG_GPIO_GPIOCFGG                       (*(volatile reg_gpio_gpiocfgg_t *) REG_GPIO_GPIOCFGG_ADDR)
#define REG_GPIO_GPIOCFGG_RD()                  (REG_GPIO_GPIOCFGG.U32)
#define REG_GPIO_GPIOCFGG_WR(v)                 (REG_GPIO_GPIOCFGG.U32 = (v))
#define REG_GPIO_GPIOCFGG_CLR(m)                (REG_GPIO_GPIOCFGG.U32 = ((REG_GPIO_GPIOCFGG.U32) & ~(m)))
#define REG_GPIO_GPIOCFGG_SET(m)                (REG_GPIO_GPIOCFGG.U32 = ((REG_GPIO_GPIOCFGG.U32) | (m)))
#define REG_GPIO_GPIOCFGG_DEF                   0x00000000

#define BFP_GPIO_GPIOCFGG_RSVD_8                (8)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGG_RSVD_8                ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGG_RSVD_8                (24)                    /* bitfield width */
#define BFD_GPIO_GPIOCFGG_RSVD_8                (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGG_RSVD_8(v)             ((((uint32_t) v) << (BFP_GPIO_GPIOCFGG_RSVD_8)) & (BFM_GPIO_GPIOCFGG_RSVD_8))
#define BFX_GPIO_GPIOCFGG_RSVD_8(v)             ((((uint32_t) v) & (BFM_GPIO_GPIOCFGG_RSVD_8)) >> (BFP_GPIO_GPIOCFGG_RSVD_8))
#define BFW_GPIO_GPIOCFGG_RSVD_8(v)             (REG_GPIO_GPIOCFGG.U32 = ( (REG_GPIO_GPIOCFGG.U32 & ~(BFM_GPIO_GPIOCFGG_RSVD_8)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGG_RSVD_8)) & (BFM_GPIO_GPIOCFGG_RSVD_8)) ))
#define BFR_GPIO_GPIOCFGG_RSVD_8()              ((REG_GPIO_GPIOCFGG.U32 & (BFM_GPIO_GPIOCFGG_RSVD_8))>>(BFP_GPIO_GPIOCFGG_RSVD_8))

#define BFP_GPIO_GPIOCFGG_GPIO49INTD            (7)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGG_GPIO49INTD            ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGG_GPIO49INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGG_GPIO49INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGG_GPIO49INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGG_GPIO49INTD)) & (BFM_GPIO_GPIOCFGG_GPIO49INTD))
#define BFX_GPIO_GPIOCFGG_GPIO49INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGG_GPIO49INTD)) >> (BFP_GPIO_GPIOCFGG_GPIO49INTD))
#define BFW_GPIO_GPIOCFGG_GPIO49INTD(v)         (REG_GPIO_GPIOCFGG.U32 = ( (REG_GPIO_GPIOCFGG.U32 & ~(BFM_GPIO_GPIOCFGG_GPIO49INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGG_GPIO49INTD)) & (BFM_GPIO_GPIOCFGG_GPIO49INTD)) ))
#define BFR_GPIO_GPIOCFGG_GPIO49INTD()          ((REG_GPIO_GPIOCFGG.U32 & (BFM_GPIO_GPIOCFGG_GPIO49INTD))>>(BFP_GPIO_GPIOCFGG_GPIO49INTD))

#define BFP_GPIO_GPIOCFGG_GPIO49OUTCFG          (5)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGG_GPIO49OUTCFG          ((uint32_t)0x00000060)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGG_GPIO49OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGG_GPIO49OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGG_GPIO49OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGG_GPIO49OUTCFG)) & (BFM_GPIO_GPIOCFGG_GPIO49OUTCFG))
#define BFX_GPIO_GPIOCFGG_GPIO49OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGG_GPIO49OUTCFG)) >> (BFP_GPIO_GPIOCFGG_GPIO49OUTCFG))
#define BFW_GPIO_GPIOCFGG_GPIO49OUTCFG(v)       (REG_GPIO_GPIOCFGG.U32 = ( (REG_GPIO_GPIOCFGG.U32 & ~(BFM_GPIO_GPIOCFGG_GPIO49OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGG_GPIO49OUTCFG)) & (BFM_GPIO_GPIOCFGG_GPIO49OUTCFG)) ))
#define BFR_GPIO_GPIOCFGG_GPIO49OUTCFG()        ((REG_GPIO_GPIOCFGG.U32 & (BFM_GPIO_GPIOCFGG_GPIO49OUTCFG))>>(BFP_GPIO_GPIOCFGG_GPIO49OUTCFG))

#define BFP_GPIO_GPIOCFGG_GPIO49INCFG           (4)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGG_GPIO49INCFG           ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGG_GPIO49INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGG_GPIO49INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGG_GPIO49INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGG_GPIO49INCFG)) & (BFM_GPIO_GPIOCFGG_GPIO49INCFG))
#define BFX_GPIO_GPIOCFGG_GPIO49INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGG_GPIO49INCFG)) >> (BFP_GPIO_GPIOCFGG_GPIO49INCFG))
#define BFW_GPIO_GPIOCFGG_GPIO49INCFG(v)        (REG_GPIO_GPIOCFGG.U32 = ( (REG_GPIO_GPIOCFGG.U32 & ~(BFM_GPIO_GPIOCFGG_GPIO49INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGG_GPIO49INCFG)) & (BFM_GPIO_GPIOCFGG_GPIO49INCFG)) ))
#define BFR_GPIO_GPIOCFGG_GPIO49INCFG()         ((REG_GPIO_GPIOCFGG.U32 & (BFM_GPIO_GPIOCFGG_GPIO49INCFG))>>(BFP_GPIO_GPIOCFGG_GPIO49INCFG))

#define BFP_GPIO_GPIOCFGG_GPIO48INTD            (3)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGG_GPIO48INTD            ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGG_GPIO48INTD            (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGG_GPIO48INTD            (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGG_GPIO48INTD(v)         ((((uint32_t) v) << (BFP_GPIO_GPIOCFGG_GPIO48INTD)) & (BFM_GPIO_GPIOCFGG_GPIO48INTD))
#define BFX_GPIO_GPIOCFGG_GPIO48INTD(v)         ((((uint32_t) v) & (BFM_GPIO_GPIOCFGG_GPIO48INTD)) >> (BFP_GPIO_GPIOCFGG_GPIO48INTD))
#define BFW_GPIO_GPIOCFGG_GPIO48INTD(v)         (REG_GPIO_GPIOCFGG.U32 = ( (REG_GPIO_GPIOCFGG.U32 & ~(BFM_GPIO_GPIOCFGG_GPIO48INTD)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGG_GPIO48INTD)) & (BFM_GPIO_GPIOCFGG_GPIO48INTD)) ))
#define BFR_GPIO_GPIOCFGG_GPIO48INTD()          ((REG_GPIO_GPIOCFGG.U32 & (BFM_GPIO_GPIOCFGG_GPIO48INTD))>>(BFP_GPIO_GPIOCFGG_GPIO48INTD))

#define BFP_GPIO_GPIOCFGG_GPIO48OUTCFG          (1)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGG_GPIO48OUTCFG          ((uint32_t)0x00000006)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGG_GPIO48OUTCFG          (2)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGG_GPIO48OUTCFG          (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGG_GPIO48OUTCFG(v)       ((((uint32_t) v) << (BFP_GPIO_GPIOCFGG_GPIO48OUTCFG)) & (BFM_GPIO_GPIOCFGG_GPIO48OUTCFG))
#define BFX_GPIO_GPIOCFGG_GPIO48OUTCFG(v)       ((((uint32_t) v) & (BFM_GPIO_GPIOCFGG_GPIO48OUTCFG)) >> (BFP_GPIO_GPIOCFGG_GPIO48OUTCFG))
#define BFW_GPIO_GPIOCFGG_GPIO48OUTCFG(v)       (REG_GPIO_GPIOCFGG.U32 = ( (REG_GPIO_GPIOCFGG.U32 & ~(BFM_GPIO_GPIOCFGG_GPIO48OUTCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGG_GPIO48OUTCFG)) & (BFM_GPIO_GPIOCFGG_GPIO48OUTCFG)) ))
#define BFR_GPIO_GPIOCFGG_GPIO48OUTCFG()        ((REG_GPIO_GPIOCFGG.U32 & (BFM_GPIO_GPIOCFGG_GPIO48OUTCFG))>>(BFP_GPIO_GPIOCFGG_GPIO48OUTCFG))

#define BFP_GPIO_GPIOCFGG_GPIO48INCFG           (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOCFGG_GPIO48INCFG           ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_GPIOCFGG_GPIO48INCFG           (1)                     /* bitfield width */
#define BFD_GPIO_GPIOCFGG_GPIO48INCFG           (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOCFGG_GPIO48INCFG(v)        ((((uint32_t) v) << (BFP_GPIO_GPIOCFGG_GPIO48INCFG)) & (BFM_GPIO_GPIOCFGG_GPIO48INCFG))
#define BFX_GPIO_GPIOCFGG_GPIO48INCFG(v)        ((((uint32_t) v) & (BFM_GPIO_GPIOCFGG_GPIO48INCFG)) >> (BFP_GPIO_GPIOCFGG_GPIO48INCFG))
#define BFW_GPIO_GPIOCFGG_GPIO48INCFG(v)        (REG_GPIO_GPIOCFGG.U32 = ( (REG_GPIO_GPIOCFGG.U32 & ~(BFM_GPIO_GPIOCFGG_GPIO48INCFG)) | ((((uint32_t) v)<<(BFP_GPIO_GPIOCFGG_GPIO48INCFG)) & (BFM_GPIO_GPIOCFGG_GPIO48INCFG)) ))
#define BFR_GPIO_GPIOCFGG_GPIO48INCFG()         ((REG_GPIO_GPIOCFGG.U32 & (BFM_GPIO_GPIOCFGG_GPIO48INCFG))>>(BFP_GPIO_GPIOCFGG_GPIO48INCFG))


// *****************************************************************************
//                                                                             *
//  GPIO_PADKEY - Key Register for all pad configuration registers             *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_0                     : 32;
    } B;
} reg_gpio_padkey_t;

#define REG_GPIO_PADKEY_ADDR                    (REG_GPIO_BASEADDR + 0x00000060UL)
#define REG_GPIO_PADKEY                         (*(volatile reg_gpio_padkey_t *) REG_GPIO_PADKEY_ADDR)
#define REG_GPIO_PADKEY_RD()                    (REG_GPIO_PADKEY.U32)
#define REG_GPIO_PADKEY_WR(v)                   (REG_GPIO_PADKEY.U32 = (v))
#define REG_GPIO_PADKEY_CLR(m)                  (REG_GPIO_PADKEY.U32 = ((REG_GPIO_PADKEY.U32) & ~(m)))
#define REG_GPIO_PADKEY_SET(m)                  (REG_GPIO_PADKEY.U32 = ((REG_GPIO_PADKEY.U32) | (m)))
#define REG_GPIO_PADKEY_DEF                     0x00000000


// *****************************************************************************
//                                                                             *
//  GPIO_GPIORDA - GPIO Input Register A                                       *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned GPIORDA                    : 32;
    } B;
} reg_gpio_gpiorda_t;

#define REG_GPIO_GPIORDA_ADDR                   (REG_GPIO_BASEADDR + 0x00000080UL)
#define REG_GPIO_GPIORDA                        (*(volatile reg_gpio_gpiorda_t *) REG_GPIO_GPIORDA_ADDR)
#define REG_GPIO_GPIORDA_RD()                   (REG_GPIO_GPIORDA.U32)
#define REG_GPIO_GPIORDA_WR(v)                  (REG_GPIO_GPIORDA.U32 = (v))
#define REG_GPIO_GPIORDA_CLR(m)                 (REG_GPIO_GPIORDA.U32 = ((REG_GPIO_GPIORDA.U32) & ~(m)))
#define REG_GPIO_GPIORDA_SET(m)                 (REG_GPIO_GPIORDA.U32 = ((REG_GPIO_GPIORDA.U32) | (m)))
#define REG_GPIO_GPIORDA_DEF                    0x00000000

#define BFP_GPIO_GPIORDA_GPIORDA                (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIORDA_GPIORDA                ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_GPIO_GPIORDA_GPIORDA                (32)                    /* bitfield width */
#define BFD_GPIO_GPIORDA_GPIORDA                (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIORDA_GPIORDA(v)             ((((uint32_t) v) << (BFP_GPIO_GPIORDA_GPIORDA)) & (BFM_GPIO_GPIORDA_GPIORDA))
#define BFX_GPIO_GPIORDA_GPIORDA(v)             ((((uint32_t) v) & (BFM_GPIO_GPIORDA_GPIORDA)) >> (BFP_GPIO_GPIORDA_GPIORDA))
#define BFW_GPIO_GPIORDA_GPIORDA(v)             (REG_GPIO_GPIORDA.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIORDA_GPIORDA)) & (BFM_GPIO_GPIORDA_GPIORDA)) )
#define BFR_GPIO_GPIORDA_GPIORDA()              ((REG_GPIO_GPIORDA.U32 & (BFM_GPIO_GPIORDA_GPIORDA))>>(BFP_GPIO_GPIORDA_GPIORDA))


// *****************************************************************************
//                                                                             *
//  GPIO_GPIORDB - GPIO Input Register B                                       *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_18                    : 14;
        unsigned GPIORDB                    : 18;
    } B;
} reg_gpio_gpiordb_t;

#define REG_GPIO_GPIORDB_ADDR                   (REG_GPIO_BASEADDR + 0x00000084UL)
#define REG_GPIO_GPIORDB                        (*(volatile reg_gpio_gpiordb_t *) REG_GPIO_GPIORDB_ADDR)
#define REG_GPIO_GPIORDB_RD()                   (REG_GPIO_GPIORDB.U32)
#define REG_GPIO_GPIORDB_WR(v)                  (REG_GPIO_GPIORDB.U32 = (v))
#define REG_GPIO_GPIORDB_CLR(m)                 (REG_GPIO_GPIORDB.U32 = ((REG_GPIO_GPIORDB.U32) & ~(m)))
#define REG_GPIO_GPIORDB_SET(m)                 (REG_GPIO_GPIORDB.U32 = ((REG_GPIO_GPIORDB.U32) | (m)))
#define REG_GPIO_GPIORDB_DEF                    0x00000000

#define BFP_GPIO_GPIORDB_RSVD_18                (18)                    /* bitfield lsb */
#define BFM_GPIO_GPIORDB_RSVD_18                ((uint32_t)0xfffc0000)  /* bitfield mask */
#define BFN_GPIO_GPIORDB_RSVD_18                (14)                    /* bitfield width */
#define BFD_GPIO_GPIORDB_RSVD_18                (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIORDB_RSVD_18(v)             ((((uint32_t) v) << (BFP_GPIO_GPIORDB_RSVD_18)) & (BFM_GPIO_GPIORDB_RSVD_18))
#define BFX_GPIO_GPIORDB_RSVD_18(v)             ((((uint32_t) v) & (BFM_GPIO_GPIORDB_RSVD_18)) >> (BFP_GPIO_GPIORDB_RSVD_18))
#define BFW_GPIO_GPIORDB_RSVD_18(v)             (REG_GPIO_GPIORDB.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIORDB_RSVD_18)) & (BFM_GPIO_GPIORDB_RSVD_18)) )
#define BFR_GPIO_GPIORDB_RSVD_18()              ((REG_GPIO_GPIORDB.U32 & (BFM_GPIO_GPIORDB_RSVD_18))>>(BFP_GPIO_GPIORDB_RSVD_18))

#define BFP_GPIO_GPIORDB_GPIORDB                (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIORDB_GPIORDB                ((uint32_t)0x0003ffff)  /* bitfield mask */
#define BFN_GPIO_GPIORDB_GPIORDB                (18)                    /* bitfield width */
#define BFD_GPIO_GPIORDB_GPIORDB                (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIORDB_GPIORDB(v)             ((((uint32_t) v) << (BFP_GPIO_GPIORDB_GPIORDB)) & (BFM_GPIO_GPIORDB_GPIORDB))
#define BFX_GPIO_GPIORDB_GPIORDB(v)             ((((uint32_t) v) & (BFM_GPIO_GPIORDB_GPIORDB)) >> (BFP_GPIO_GPIORDB_GPIORDB))
#define BFW_GPIO_GPIORDB_GPIORDB(v)             (REG_GPIO_GPIORDB.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIORDB_GPIORDB)) & (BFM_GPIO_GPIORDB_GPIORDB)) )
#define BFR_GPIO_GPIORDB_GPIORDB()              ((REG_GPIO_GPIORDB.U32 & (BFM_GPIO_GPIORDB_GPIORDB))>>(BFP_GPIO_GPIORDB_GPIORDB))


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOWTA - GPIO Output Register A                                      *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned GPIOWTA                    : 32;
    } B;
} reg_gpio_gpiowta_t;

#define REG_GPIO_GPIOWTA_ADDR                   (REG_GPIO_BASEADDR + 0x00000088UL)
#define REG_GPIO_GPIOWTA                        (*(volatile reg_gpio_gpiowta_t *) REG_GPIO_GPIOWTA_ADDR)
#define REG_GPIO_GPIOWTA_RD()                   (REG_GPIO_GPIOWTA.U32)
#define REG_GPIO_GPIOWTA_WR(v)                  (REG_GPIO_GPIOWTA.U32 = (v))
#define REG_GPIO_GPIOWTA_CLR(m)                 (REG_GPIO_GPIOWTA.U32 = ((REG_GPIO_GPIOWTA.U32) & ~(m)))
#define REG_GPIO_GPIOWTA_SET(m)                 (REG_GPIO_GPIOWTA.U32 = ((REG_GPIO_GPIOWTA.U32) | (m)))
#define REG_GPIO_GPIOWTA_DEF                    0x00000000

#define BFP_GPIO_GPIOWTA_GPIOWTA                (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOWTA_GPIOWTA                ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_GPIO_GPIOWTA_GPIOWTA                (32)                    /* bitfield width */
#define BFD_GPIO_GPIOWTA_GPIOWTA                (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOWTA_GPIOWTA(v)             ((((uint32_t) v) << (BFP_GPIO_GPIOWTA_GPIOWTA)) & (BFM_GPIO_GPIOWTA_GPIOWTA))
#define BFX_GPIO_GPIOWTA_GPIOWTA(v)             ((((uint32_t) v) & (BFM_GPIO_GPIOWTA_GPIOWTA)) >> (BFP_GPIO_GPIOWTA_GPIOWTA))
#define BFW_GPIO_GPIOWTA_GPIOWTA(v)             (REG_GPIO_GPIOWTA.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOWTA_GPIOWTA)) & (BFM_GPIO_GPIOWTA_GPIOWTA)) )
#define BFR_GPIO_GPIOWTA_GPIOWTA()              ((REG_GPIO_GPIOWTA.U32 & (BFM_GPIO_GPIOWTA_GPIOWTA))>>(BFP_GPIO_GPIOWTA_GPIOWTA))


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOWTB - GPIO Output Register B                                      *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_18                    : 14;
        unsigned GPIOWTB                    : 18;
    } B;
} reg_gpio_gpiowtb_t;

#define REG_GPIO_GPIOWTB_ADDR                   (REG_GPIO_BASEADDR + 0x0000008CUL)
#define REG_GPIO_GPIOWTB                        (*(volatile reg_gpio_gpiowtb_t *) REG_GPIO_GPIOWTB_ADDR)
#define REG_GPIO_GPIOWTB_RD()                   (REG_GPIO_GPIOWTB.U32)
#define REG_GPIO_GPIOWTB_WR(v)                  (REG_GPIO_GPIOWTB.U32 = (v))
#define REG_GPIO_GPIOWTB_CLR(m)                 (REG_GPIO_GPIOWTB.U32 = ((REG_GPIO_GPIOWTB.U32) & ~(m)))
#define REG_GPIO_GPIOWTB_SET(m)                 (REG_GPIO_GPIOWTB.U32 = ((REG_GPIO_GPIOWTB.U32) | (m)))
#define REG_GPIO_GPIOWTB_DEF                    0x00000000

#define BFP_GPIO_GPIOWTB_RSVD_18                (18)                    /* bitfield lsb */
#define BFM_GPIO_GPIOWTB_RSVD_18                ((uint32_t)0xfffc0000)  /* bitfield mask */
#define BFN_GPIO_GPIOWTB_RSVD_18                (14)                    /* bitfield width */
#define BFD_GPIO_GPIOWTB_RSVD_18                (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOWTB_RSVD_18(v)             ((((uint32_t) v) << (BFP_GPIO_GPIOWTB_RSVD_18)) & (BFM_GPIO_GPIOWTB_RSVD_18))
#define BFX_GPIO_GPIOWTB_RSVD_18(v)             ((((uint32_t) v) & (BFM_GPIO_GPIOWTB_RSVD_18)) >> (BFP_GPIO_GPIOWTB_RSVD_18))
#define BFW_GPIO_GPIOWTB_RSVD_18(v)             (REG_GPIO_GPIOWTB.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOWTB_RSVD_18)) & (BFM_GPIO_GPIOWTB_RSVD_18)) )
#define BFR_GPIO_GPIOWTB_RSVD_18()              ((REG_GPIO_GPIOWTB.U32 & (BFM_GPIO_GPIOWTB_RSVD_18))>>(BFP_GPIO_GPIOWTB_RSVD_18))

#define BFP_GPIO_GPIOWTB_GPIOWTB                (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOWTB_GPIOWTB                ((uint32_t)0x0003ffff)  /* bitfield mask */
#define BFN_GPIO_GPIOWTB_GPIOWTB                (18)                    /* bitfield width */
#define BFD_GPIO_GPIOWTB_GPIOWTB                (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOWTB_GPIOWTB(v)             ((((uint32_t) v) << (BFP_GPIO_GPIOWTB_GPIOWTB)) & (BFM_GPIO_GPIOWTB_GPIOWTB))
#define BFX_GPIO_GPIOWTB_GPIOWTB(v)             ((((uint32_t) v) & (BFM_GPIO_GPIOWTB_GPIOWTB)) >> (BFP_GPIO_GPIOWTB_GPIOWTB))
#define BFW_GPIO_GPIOWTB_GPIOWTB(v)             (REG_GPIO_GPIOWTB.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOWTB_GPIOWTB)) & (BFM_GPIO_GPIOWTB_GPIOWTB)) )
#define BFR_GPIO_GPIOWTB_GPIOWTB()              ((REG_GPIO_GPIOWTB.U32 & (BFM_GPIO_GPIOWTB_GPIOWTB))>>(BFP_GPIO_GPIOWTB_GPIOWTB))


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOWTSA - GPIO Output Register A Set                                 *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned GPIOWTSA                   : 32;
    } B;
} reg_gpio_gpiowtsa_t;

#define REG_GPIO_GPIOWTSA_ADDR                  (REG_GPIO_BASEADDR + 0x00000090UL)
#define REG_GPIO_GPIOWTSA                       (*(volatile reg_gpio_gpiowtsa_t *) REG_GPIO_GPIOWTSA_ADDR)
#define REG_GPIO_GPIOWTSA_RD()                  (REG_GPIO_GPIOWTSA.U32)
#define REG_GPIO_GPIOWTSA_WR(v)                 (REG_GPIO_GPIOWTSA.U32 = (v))
#define REG_GPIO_GPIOWTSA_CLR(m)                (REG_GPIO_GPIOWTSA.U32 = ((REG_GPIO_GPIOWTSA.U32) & ~(m)))
#define REG_GPIO_GPIOWTSA_SET(m)                (REG_GPIO_GPIOWTSA.U32 = ((REG_GPIO_GPIOWTSA.U32) | (m)))
#define REG_GPIO_GPIOWTSA_DEF                   0x00000000

#define BFP_GPIO_GPIOWTSA_GPIOWTSA              (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOWTSA_GPIOWTSA              ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_GPIO_GPIOWTSA_GPIOWTSA              (32)                    /* bitfield width */
#define BFD_GPIO_GPIOWTSA_GPIOWTSA              (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOWTSA_GPIOWTSA(v)           ((((uint32_t) v) << (BFP_GPIO_GPIOWTSA_GPIOWTSA)) & (BFM_GPIO_GPIOWTSA_GPIOWTSA))
#define BFX_GPIO_GPIOWTSA_GPIOWTSA(v)           ((((uint32_t) v) & (BFM_GPIO_GPIOWTSA_GPIOWTSA)) >> (BFP_GPIO_GPIOWTSA_GPIOWTSA))
#define BFW_GPIO_GPIOWTSA_GPIOWTSA(v)           (REG_GPIO_GPIOWTSA.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOWTSA_GPIOWTSA)) & (BFM_GPIO_GPIOWTSA_GPIOWTSA)) )
#define BFR_GPIO_GPIOWTSA_GPIOWTSA()            ((REG_GPIO_GPIOWTSA.U32 & (BFM_GPIO_GPIOWTSA_GPIOWTSA))>>(BFP_GPIO_GPIOWTSA_GPIOWTSA))
#define BFS_GPIO_GPIOWTSA_GPIOWTSA()            (REG_GPIO_GPIOWTSA.U32 = (BFM_GPIO_GPIOWTSA_GPIOWTSA) )


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOWTSB - GPIO Output Register B Set                                 *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_18                    : 14;
        unsigned GPIOWTSB                   : 18;
    } B;
} reg_gpio_gpiowtsb_t;

#define REG_GPIO_GPIOWTSB_ADDR                  (REG_GPIO_BASEADDR + 0x00000094UL)
#define REG_GPIO_GPIOWTSB                       (*(volatile reg_gpio_gpiowtsb_t *) REG_GPIO_GPIOWTSB_ADDR)
#define REG_GPIO_GPIOWTSB_RD()                  (REG_GPIO_GPIOWTSB.U32)
#define REG_GPIO_GPIOWTSB_WR(v)                 (REG_GPIO_GPIOWTSB.U32 = (v))
#define REG_GPIO_GPIOWTSB_CLR(m)                (REG_GPIO_GPIOWTSB.U32 = ((REG_GPIO_GPIOWTSB.U32) & ~(m)))
#define REG_GPIO_GPIOWTSB_SET(m)                (REG_GPIO_GPIOWTSB.U32 = ((REG_GPIO_GPIOWTSB.U32) | (m)))
#define REG_GPIO_GPIOWTSB_DEF                   0x00000000

#define BFP_GPIO_GPIOWTSB_RSVD_18               (18)                    /* bitfield lsb */
#define BFM_GPIO_GPIOWTSB_RSVD_18               ((uint32_t)0xfffc0000)  /* bitfield mask */
#define BFN_GPIO_GPIOWTSB_RSVD_18               (14)                    /* bitfield width */
#define BFD_GPIO_GPIOWTSB_RSVD_18               (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOWTSB_RSVD_18(v)            ((((uint32_t) v) << (BFP_GPIO_GPIOWTSB_RSVD_18)) & (BFM_GPIO_GPIOWTSB_RSVD_18))
#define BFX_GPIO_GPIOWTSB_RSVD_18(v)            ((((uint32_t) v) & (BFM_GPIO_GPIOWTSB_RSVD_18)) >> (BFP_GPIO_GPIOWTSB_RSVD_18))
#define BFW_GPIO_GPIOWTSB_RSVD_18(v)            (REG_GPIO_GPIOWTSB.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOWTSB_RSVD_18)) & (BFM_GPIO_GPIOWTSB_RSVD_18)) )
#define BFR_GPIO_GPIOWTSB_RSVD_18()             ((REG_GPIO_GPIOWTSB.U32 & (BFM_GPIO_GPIOWTSB_RSVD_18))>>(BFP_GPIO_GPIOWTSB_RSVD_18))
#define BFS_GPIO_GPIOWTSB_RSVD_18()             (REG_GPIO_GPIOWTSB.U32 = (BFM_GPIO_GPIOWTSB_RSVD_18) )

#define BFP_GPIO_GPIOWTSB_GPIOWTSB              (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOWTSB_GPIOWTSB              ((uint32_t)0x0003ffff)  /* bitfield mask */
#define BFN_GPIO_GPIOWTSB_GPIOWTSB              (18)                    /* bitfield width */
#define BFD_GPIO_GPIOWTSB_GPIOWTSB              (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOWTSB_GPIOWTSB(v)           ((((uint32_t) v) << (BFP_GPIO_GPIOWTSB_GPIOWTSB)) & (BFM_GPIO_GPIOWTSB_GPIOWTSB))
#define BFX_GPIO_GPIOWTSB_GPIOWTSB(v)           ((((uint32_t) v) & (BFM_GPIO_GPIOWTSB_GPIOWTSB)) >> (BFP_GPIO_GPIOWTSB_GPIOWTSB))
#define BFW_GPIO_GPIOWTSB_GPIOWTSB(v)           (REG_GPIO_GPIOWTSB.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOWTSB_GPIOWTSB)) & (BFM_GPIO_GPIOWTSB_GPIOWTSB)) )
#define BFR_GPIO_GPIOWTSB_GPIOWTSB()            ((REG_GPIO_GPIOWTSB.U32 & (BFM_GPIO_GPIOWTSB_GPIOWTSB))>>(BFP_GPIO_GPIOWTSB_GPIOWTSB))
#define BFS_GPIO_GPIOWTSB_GPIOWTSB()            (REG_GPIO_GPIOWTSB.U32 = (BFM_GPIO_GPIOWTSB_GPIOWTSB) )


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOWTCA - GPIO Output Register A Clear                               *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned GPIOWTCA                   : 32;
    } B;
} reg_gpio_gpiowtca_t;

#define REG_GPIO_GPIOWTCA_ADDR                  (REG_GPIO_BASEADDR + 0x00000098UL)
#define REG_GPIO_GPIOWTCA                       (*(volatile reg_gpio_gpiowtca_t *) REG_GPIO_GPIOWTCA_ADDR)
#define REG_GPIO_GPIOWTCA_RD()                  (REG_GPIO_GPIOWTCA.U32)
#define REG_GPIO_GPIOWTCA_WR(v)                 (REG_GPIO_GPIOWTCA.U32 = (v))
#define REG_GPIO_GPIOWTCA_CLR(m)                (REG_GPIO_GPIOWTCA.U32 = ((REG_GPIO_GPIOWTCA.U32) & ~(m)))
#define REG_GPIO_GPIOWTCA_SET(m)                (REG_GPIO_GPIOWTCA.U32 = ((REG_GPIO_GPIOWTCA.U32) | (m)))
#define REG_GPIO_GPIOWTCA_DEF                   0x00000000

#define BFP_GPIO_GPIOWTCA_GPIOWTCA              (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOWTCA_GPIOWTCA              ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_GPIO_GPIOWTCA_GPIOWTCA              (32)                    /* bitfield width */
#define BFD_GPIO_GPIOWTCA_GPIOWTCA              (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOWTCA_GPIOWTCA(v)           ((((uint32_t) v) << (BFP_GPIO_GPIOWTCA_GPIOWTCA)) & (BFM_GPIO_GPIOWTCA_GPIOWTCA))
#define BFX_GPIO_GPIOWTCA_GPIOWTCA(v)           ((((uint32_t) v) & (BFM_GPIO_GPIOWTCA_GPIOWTCA)) >> (BFP_GPIO_GPIOWTCA_GPIOWTCA))
#define BFW_GPIO_GPIOWTCA_GPIOWTCA(v)           (REG_GPIO_GPIOWTCA.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOWTCA_GPIOWTCA)) & (BFM_GPIO_GPIOWTCA_GPIOWTCA)) )
#define BFR_GPIO_GPIOWTCA_GPIOWTCA()            ((REG_GPIO_GPIOWTCA.U32 & (BFM_GPIO_GPIOWTCA_GPIOWTCA))>>(BFP_GPIO_GPIOWTCA_GPIOWTCA))
#define BFS_GPIO_GPIOWTCA_GPIOWTCA()            (REG_GPIO_GPIOWTCA.U32 = (BFM_GPIO_GPIOWTCA_GPIOWTCA) )


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOWTCB - GPIO Output Register B Clear                               *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_18                    : 14;
        unsigned GPIOWTCB                   : 18;
    } B;
} reg_gpio_gpiowtcb_t;

#define REG_GPIO_GPIOWTCB_ADDR                  (REG_GPIO_BASEADDR + 0x0000009CUL)
#define REG_GPIO_GPIOWTCB                       (*(volatile reg_gpio_gpiowtcb_t *) REG_GPIO_GPIOWTCB_ADDR)
#define REG_GPIO_GPIOWTCB_RD()                  (REG_GPIO_GPIOWTCB.U32)
#define REG_GPIO_GPIOWTCB_WR(v)                 (REG_GPIO_GPIOWTCB.U32 = (v))
#define REG_GPIO_GPIOWTCB_CLR(m)                (REG_GPIO_GPIOWTCB.U32 = ((REG_GPIO_GPIOWTCB.U32) & ~(m)))
#define REG_GPIO_GPIOWTCB_SET(m)                (REG_GPIO_GPIOWTCB.U32 = ((REG_GPIO_GPIOWTCB.U32) | (m)))
#define REG_GPIO_GPIOWTCB_DEF                   0x00000000

#define BFP_GPIO_GPIOWTCB_RSVD_18               (18)                    /* bitfield lsb */
#define BFM_GPIO_GPIOWTCB_RSVD_18               ((uint32_t)0xfffc0000)  /* bitfield mask */
#define BFN_GPIO_GPIOWTCB_RSVD_18               (14)                    /* bitfield width */
#define BFD_GPIO_GPIOWTCB_RSVD_18               (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOWTCB_RSVD_18(v)            ((((uint32_t) v) << (BFP_GPIO_GPIOWTCB_RSVD_18)) & (BFM_GPIO_GPIOWTCB_RSVD_18))
#define BFX_GPIO_GPIOWTCB_RSVD_18(v)            ((((uint32_t) v) & (BFM_GPIO_GPIOWTCB_RSVD_18)) >> (BFP_GPIO_GPIOWTCB_RSVD_18))
#define BFW_GPIO_GPIOWTCB_RSVD_18(v)            (REG_GPIO_GPIOWTCB.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOWTCB_RSVD_18)) & (BFM_GPIO_GPIOWTCB_RSVD_18)) )
#define BFR_GPIO_GPIOWTCB_RSVD_18()             ((REG_GPIO_GPIOWTCB.U32 & (BFM_GPIO_GPIOWTCB_RSVD_18))>>(BFP_GPIO_GPIOWTCB_RSVD_18))
#define BFS_GPIO_GPIOWTCB_RSVD_18()             (REG_GPIO_GPIOWTCB.U32 = (BFM_GPIO_GPIOWTCB_RSVD_18) )

#define BFP_GPIO_GPIOWTCB_GPIOWTCB              (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOWTCB_GPIOWTCB              ((uint32_t)0x0003ffff)  /* bitfield mask */
#define BFN_GPIO_GPIOWTCB_GPIOWTCB              (18)                    /* bitfield width */
#define BFD_GPIO_GPIOWTCB_GPIOWTCB              (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOWTCB_GPIOWTCB(v)           ((((uint32_t) v) << (BFP_GPIO_GPIOWTCB_GPIOWTCB)) & (BFM_GPIO_GPIOWTCB_GPIOWTCB))
#define BFX_GPIO_GPIOWTCB_GPIOWTCB(v)           ((((uint32_t) v) & (BFM_GPIO_GPIOWTCB_GPIOWTCB)) >> (BFP_GPIO_GPIOWTCB_GPIOWTCB))
#define BFW_GPIO_GPIOWTCB_GPIOWTCB(v)           (REG_GPIO_GPIOWTCB.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOWTCB_GPIOWTCB)) & (BFM_GPIO_GPIOWTCB_GPIOWTCB)) )
#define BFR_GPIO_GPIOWTCB_GPIOWTCB()            ((REG_GPIO_GPIOWTCB.U32 & (BFM_GPIO_GPIOWTCB_GPIOWTCB))>>(BFP_GPIO_GPIOWTCB_GPIOWTCB))
#define BFS_GPIO_GPIOWTCB_GPIOWTCB()            (REG_GPIO_GPIOWTCB.U32 = (BFM_GPIO_GPIOWTCB_GPIOWTCB) )


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOENA - GPIO Enable Register A                                      *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned GPIOENA                    : 32;
    } B;
} reg_gpio_gpioena_t;

#define REG_GPIO_GPIOENA_ADDR                   (REG_GPIO_BASEADDR + 0x000000A0UL)
#define REG_GPIO_GPIOENA                        (*(volatile reg_gpio_gpioena_t *) REG_GPIO_GPIOENA_ADDR)
#define REG_GPIO_GPIOENA_RD()                   (REG_GPIO_GPIOENA.U32)
#define REG_GPIO_GPIOENA_WR(v)                  (REG_GPIO_GPIOENA.U32 = (v))
#define REG_GPIO_GPIOENA_CLR(m)                 (REG_GPIO_GPIOENA.U32 = ((REG_GPIO_GPIOENA.U32) & ~(m)))
#define REG_GPIO_GPIOENA_SET(m)                 (REG_GPIO_GPIOENA.U32 = ((REG_GPIO_GPIOENA.U32) | (m)))
#define REG_GPIO_GPIOENA_DEF                    0x00000000

#define BFP_GPIO_GPIOENA_GPIOENA                (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOENA_GPIOENA                ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_GPIO_GPIOENA_GPIOENA                (32)                    /* bitfield width */
#define BFD_GPIO_GPIOENA_GPIOENA                (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOENA_GPIOENA(v)             ((((uint32_t) v) << (BFP_GPIO_GPIOENA_GPIOENA)) & (BFM_GPIO_GPIOENA_GPIOENA))
#define BFX_GPIO_GPIOENA_GPIOENA(v)             ((((uint32_t) v) & (BFM_GPIO_GPIOENA_GPIOENA)) >> (BFP_GPIO_GPIOENA_GPIOENA))
#define BFW_GPIO_GPIOENA_GPIOENA(v)             (REG_GPIO_GPIOENA.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOENA_GPIOENA)) & (BFM_GPIO_GPIOENA_GPIOENA)) )
#define BFR_GPIO_GPIOENA_GPIOENA()              ((REG_GPIO_GPIOENA.U32 & (BFM_GPIO_GPIOENA_GPIOENA))>>(BFP_GPIO_GPIOENA_GPIOENA))


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOENB - GPIO Enable Register B                                      *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_18                    : 14;
        unsigned GPIOENB                    : 18;
    } B;
} reg_gpio_gpioenb_t;

#define REG_GPIO_GPIOENB_ADDR                   (REG_GPIO_BASEADDR + 0x000000A4UL)
#define REG_GPIO_GPIOENB                        (*(volatile reg_gpio_gpioenb_t *) REG_GPIO_GPIOENB_ADDR)
#define REG_GPIO_GPIOENB_RD()                   (REG_GPIO_GPIOENB.U32)
#define REG_GPIO_GPIOENB_WR(v)                  (REG_GPIO_GPIOENB.U32 = (v))
#define REG_GPIO_GPIOENB_CLR(m)                 (REG_GPIO_GPIOENB.U32 = ((REG_GPIO_GPIOENB.U32) & ~(m)))
#define REG_GPIO_GPIOENB_SET(m)                 (REG_GPIO_GPIOENB.U32 = ((REG_GPIO_GPIOENB.U32) | (m)))
#define REG_GPIO_GPIOENB_DEF                    0x00000000

#define BFP_GPIO_GPIOENB_RSVD_18                (18)                    /* bitfield lsb */
#define BFM_GPIO_GPIOENB_RSVD_18                ((uint32_t)0xfffc0000)  /* bitfield mask */
#define BFN_GPIO_GPIOENB_RSVD_18                (14)                    /* bitfield width */
#define BFD_GPIO_GPIOENB_RSVD_18                (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOENB_RSVD_18(v)             ((((uint32_t) v) << (BFP_GPIO_GPIOENB_RSVD_18)) & (BFM_GPIO_GPIOENB_RSVD_18))
#define BFX_GPIO_GPIOENB_RSVD_18(v)             ((((uint32_t) v) & (BFM_GPIO_GPIOENB_RSVD_18)) >> (BFP_GPIO_GPIOENB_RSVD_18))
#define BFW_GPIO_GPIOENB_RSVD_18(v)             (REG_GPIO_GPIOENB.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOENB_RSVD_18)) & (BFM_GPIO_GPIOENB_RSVD_18)) )
#define BFR_GPIO_GPIOENB_RSVD_18()              ((REG_GPIO_GPIOENB.U32 & (BFM_GPIO_GPIOENB_RSVD_18))>>(BFP_GPIO_GPIOENB_RSVD_18))

#define BFP_GPIO_GPIOENB_GPIOENB                (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOENB_GPIOENB                ((uint32_t)0x0003ffff)  /* bitfield mask */
#define BFN_GPIO_GPIOENB_GPIOENB                (18)                    /* bitfield width */
#define BFD_GPIO_GPIOENB_GPIOENB                (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOENB_GPIOENB(v)             ((((uint32_t) v) << (BFP_GPIO_GPIOENB_GPIOENB)) & (BFM_GPIO_GPIOENB_GPIOENB))
#define BFX_GPIO_GPIOENB_GPIOENB(v)             ((((uint32_t) v) & (BFM_GPIO_GPIOENB_GPIOENB)) >> (BFP_GPIO_GPIOENB_GPIOENB))
#define BFW_GPIO_GPIOENB_GPIOENB(v)             (REG_GPIO_GPIOENB.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOENB_GPIOENB)) & (BFM_GPIO_GPIOENB_GPIOENB)) )
#define BFR_GPIO_GPIOENB_GPIOENB()              ((REG_GPIO_GPIOENB.U32 & (BFM_GPIO_GPIOENB_GPIOENB))>>(BFP_GPIO_GPIOENB_GPIOENB))


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOENSA - GPIO Enable Register A Set                                 *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned GPIOENSA                   : 32;
    } B;
} reg_gpio_gpioensa_t;

#define REG_GPIO_GPIOENSA_ADDR                  (REG_GPIO_BASEADDR + 0x000000A8UL)
#define REG_GPIO_GPIOENSA                       (*(volatile reg_gpio_gpioensa_t *) REG_GPIO_GPIOENSA_ADDR)
#define REG_GPIO_GPIOENSA_RD()                  (REG_GPIO_GPIOENSA.U32)
#define REG_GPIO_GPIOENSA_WR(v)                 (REG_GPIO_GPIOENSA.U32 = (v))
#define REG_GPIO_GPIOENSA_CLR(m)                (REG_GPIO_GPIOENSA.U32 = ((REG_GPIO_GPIOENSA.U32) & ~(m)))
#define REG_GPIO_GPIOENSA_SET(m)                (REG_GPIO_GPIOENSA.U32 = ((REG_GPIO_GPIOENSA.U32) | (m)))
#define REG_GPIO_GPIOENSA_DEF                   0x00000000

#define BFP_GPIO_GPIOENSA_GPIOENSA              (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOENSA_GPIOENSA              ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_GPIO_GPIOENSA_GPIOENSA              (32)                    /* bitfield width */
#define BFD_GPIO_GPIOENSA_GPIOENSA              (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOENSA_GPIOENSA(v)           ((((uint32_t) v) << (BFP_GPIO_GPIOENSA_GPIOENSA)) & (BFM_GPIO_GPIOENSA_GPIOENSA))
#define BFX_GPIO_GPIOENSA_GPIOENSA(v)           ((((uint32_t) v) & (BFM_GPIO_GPIOENSA_GPIOENSA)) >> (BFP_GPIO_GPIOENSA_GPIOENSA))
#define BFW_GPIO_GPIOENSA_GPIOENSA(v)           (REG_GPIO_GPIOENSA.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOENSA_GPIOENSA)) & (BFM_GPIO_GPIOENSA_GPIOENSA)) )
#define BFR_GPIO_GPIOENSA_GPIOENSA()            ((REG_GPIO_GPIOENSA.U32 & (BFM_GPIO_GPIOENSA_GPIOENSA))>>(BFP_GPIO_GPIOENSA_GPIOENSA))


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOENSB - GPIO Enable Register B Set                                 *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_18                    : 14;
        unsigned GPIOENSB                   : 18;
    } B;
} reg_gpio_gpioensb_t;

#define REG_GPIO_GPIOENSB_ADDR                  (REG_GPIO_BASEADDR + 0x000000ACUL)
#define REG_GPIO_GPIOENSB                       (*(volatile reg_gpio_gpioensb_t *) REG_GPIO_GPIOENSB_ADDR)
#define REG_GPIO_GPIOENSB_RD()                  (REG_GPIO_GPIOENSB.U32)
#define REG_GPIO_GPIOENSB_WR(v)                 (REG_GPIO_GPIOENSB.U32 = (v))
#define REG_GPIO_GPIOENSB_CLR(m)                (REG_GPIO_GPIOENSB.U32 = ((REG_GPIO_GPIOENSB.U32) & ~(m)))
#define REG_GPIO_GPIOENSB_SET(m)                (REG_GPIO_GPIOENSB.U32 = ((REG_GPIO_GPIOENSB.U32) | (m)))
#define REG_GPIO_GPIOENSB_DEF                   0x00000000

#define BFP_GPIO_GPIOENSB_RSVD_18               (18)                    /* bitfield lsb */
#define BFM_GPIO_GPIOENSB_RSVD_18               ((uint32_t)0xfffc0000)  /* bitfield mask */
#define BFN_GPIO_GPIOENSB_RSVD_18               (14)                    /* bitfield width */
#define BFD_GPIO_GPIOENSB_RSVD_18               (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOENSB_RSVD_18(v)            ((((uint32_t) v) << (BFP_GPIO_GPIOENSB_RSVD_18)) & (BFM_GPIO_GPIOENSB_RSVD_18))
#define BFX_GPIO_GPIOENSB_RSVD_18(v)            ((((uint32_t) v) & (BFM_GPIO_GPIOENSB_RSVD_18)) >> (BFP_GPIO_GPIOENSB_RSVD_18))
#define BFW_GPIO_GPIOENSB_RSVD_18(v)            (REG_GPIO_GPIOENSB.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOENSB_RSVD_18)) & (BFM_GPIO_GPIOENSB_RSVD_18)) )
#define BFR_GPIO_GPIOENSB_RSVD_18()             ((REG_GPIO_GPIOENSB.U32 & (BFM_GPIO_GPIOENSB_RSVD_18))>>(BFP_GPIO_GPIOENSB_RSVD_18))

#define BFP_GPIO_GPIOENSB_GPIOENSB              (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOENSB_GPIOENSB              ((uint32_t)0x0003ffff)  /* bitfield mask */
#define BFN_GPIO_GPIOENSB_GPIOENSB              (18)                    /* bitfield width */
#define BFD_GPIO_GPIOENSB_GPIOENSB              (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOENSB_GPIOENSB(v)           ((((uint32_t) v) << (BFP_GPIO_GPIOENSB_GPIOENSB)) & (BFM_GPIO_GPIOENSB_GPIOENSB))
#define BFX_GPIO_GPIOENSB_GPIOENSB(v)           ((((uint32_t) v) & (BFM_GPIO_GPIOENSB_GPIOENSB)) >> (BFP_GPIO_GPIOENSB_GPIOENSB))
#define BFW_GPIO_GPIOENSB_GPIOENSB(v)           (REG_GPIO_GPIOENSB.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOENSB_GPIOENSB)) & (BFM_GPIO_GPIOENSB_GPIOENSB)) )
#define BFR_GPIO_GPIOENSB_GPIOENSB()            ((REG_GPIO_GPIOENSB.U32 & (BFM_GPIO_GPIOENSB_GPIOENSB))>>(BFP_GPIO_GPIOENSB_GPIOENSB))


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOENCA - GPIO Enable Register A Clear                               *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned GPIOENCA                   : 32;
    } B;
} reg_gpio_gpioenca_t;

#define REG_GPIO_GPIOENCA_ADDR                  (REG_GPIO_BASEADDR + 0x000000B4UL)
#define REG_GPIO_GPIOENCA                       (*(volatile reg_gpio_gpioenca_t *) REG_GPIO_GPIOENCA_ADDR)
#define REG_GPIO_GPIOENCA_RD()                  (REG_GPIO_GPIOENCA.U32)
#define REG_GPIO_GPIOENCA_WR(v)                 (REG_GPIO_GPIOENCA.U32 = (v))
#define REG_GPIO_GPIOENCA_CLR(m)                (REG_GPIO_GPIOENCA.U32 = ((REG_GPIO_GPIOENCA.U32) & ~(m)))
#define REG_GPIO_GPIOENCA_SET(m)                (REG_GPIO_GPIOENCA.U32 = ((REG_GPIO_GPIOENCA.U32) | (m)))
#define REG_GPIO_GPIOENCA_DEF                   0x00000000

#define BFP_GPIO_GPIOENCA_GPIOENCA              (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOENCA_GPIOENCA              ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_GPIO_GPIOENCA_GPIOENCA              (32)                    /* bitfield width */
#define BFD_GPIO_GPIOENCA_GPIOENCA              (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOENCA_GPIOENCA(v)           ((((uint32_t) v) << (BFP_GPIO_GPIOENCA_GPIOENCA)) & (BFM_GPIO_GPIOENCA_GPIOENCA))
#define BFX_GPIO_GPIOENCA_GPIOENCA(v)           ((((uint32_t) v) & (BFM_GPIO_GPIOENCA_GPIOENCA)) >> (BFP_GPIO_GPIOENCA_GPIOENCA))
#define BFW_GPIO_GPIOENCA_GPIOENCA(v)           (REG_GPIO_GPIOENCA.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOENCA_GPIOENCA)) & (BFM_GPIO_GPIOENCA_GPIOENCA)) )
#define BFR_GPIO_GPIOENCA_GPIOENCA()            ((REG_GPIO_GPIOENCA.U32 & (BFM_GPIO_GPIOENCA_GPIOENCA))>>(BFP_GPIO_GPIOENCA_GPIOENCA))


// *****************************************************************************
//                                                                             *
//  GPIO_GPIOENCB - GPIO Enable Register B Clear                               *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_18                    : 14;
        unsigned GPIOENCB                   : 18;
    } B;
} reg_gpio_gpioencb_t;

#define REG_GPIO_GPIOENCB_ADDR                  (REG_GPIO_BASEADDR + 0x000000B8UL)
#define REG_GPIO_GPIOENCB                       (*(volatile reg_gpio_gpioencb_t *) REG_GPIO_GPIOENCB_ADDR)
#define REG_GPIO_GPIOENCB_RD()                  (REG_GPIO_GPIOENCB.U32)
#define REG_GPIO_GPIOENCB_WR(v)                 (REG_GPIO_GPIOENCB.U32 = (v))
#define REG_GPIO_GPIOENCB_CLR(m)                (REG_GPIO_GPIOENCB.U32 = ((REG_GPIO_GPIOENCB.U32) & ~(m)))
#define REG_GPIO_GPIOENCB_SET(m)                (REG_GPIO_GPIOENCB.U32 = ((REG_GPIO_GPIOENCB.U32) | (m)))
#define REG_GPIO_GPIOENCB_DEF                   0x00000000

#define BFP_GPIO_GPIOENCB_RSVD_18               (18)                    /* bitfield lsb */
#define BFM_GPIO_GPIOENCB_RSVD_18               ((uint32_t)0xfffc0000)  /* bitfield mask */
#define BFN_GPIO_GPIOENCB_RSVD_18               (14)                    /* bitfield width */
#define BFD_GPIO_GPIOENCB_RSVD_18               (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOENCB_RSVD_18(v)            ((((uint32_t) v) << (BFP_GPIO_GPIOENCB_RSVD_18)) & (BFM_GPIO_GPIOENCB_RSVD_18))
#define BFX_GPIO_GPIOENCB_RSVD_18(v)            ((((uint32_t) v) & (BFM_GPIO_GPIOENCB_RSVD_18)) >> (BFP_GPIO_GPIOENCB_RSVD_18))
#define BFW_GPIO_GPIOENCB_RSVD_18(v)            (REG_GPIO_GPIOENCB.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOENCB_RSVD_18)) & (BFM_GPIO_GPIOENCB_RSVD_18)) )
#define BFR_GPIO_GPIOENCB_RSVD_18()             ((REG_GPIO_GPIOENCB.U32 & (BFM_GPIO_GPIOENCB_RSVD_18))>>(BFP_GPIO_GPIOENCB_RSVD_18))

#define BFP_GPIO_GPIOENCB_GPIOENCB              (0)                     /* bitfield lsb */
#define BFM_GPIO_GPIOENCB_GPIOENCB              ((uint32_t)0x0003ffff)  /* bitfield mask */
#define BFN_GPIO_GPIOENCB_GPIOENCB              (18)                    /* bitfield width */
#define BFD_GPIO_GPIOENCB_GPIOENCB              (0x0)                   /* bitfield default value */
#define BFV_GPIO_GPIOENCB_GPIOENCB(v)           ((((uint32_t) v) << (BFP_GPIO_GPIOENCB_GPIOENCB)) & (BFM_GPIO_GPIOENCB_GPIOENCB))
#define BFX_GPIO_GPIOENCB_GPIOENCB(v)           ((((uint32_t) v) & (BFM_GPIO_GPIOENCB_GPIOENCB)) >> (BFP_GPIO_GPIOENCB_GPIOENCB))
#define BFW_GPIO_GPIOENCB_GPIOENCB(v)           (REG_GPIO_GPIOENCB.U32 = ( (((uint32_t) v)<<(BFP_GPIO_GPIOENCB_GPIOENCB)) & (BFM_GPIO_GPIOENCB_GPIOENCB)) )
#define BFR_GPIO_GPIOENCB_GPIOENCB()            ((REG_GPIO_GPIOENCB.U32 & (BFM_GPIO_GPIOENCB_GPIOENCB))>>(BFP_GPIO_GPIOENCB_GPIOENCB))


// *****************************************************************************
//                                                                             *
//  GPIO_INTRPT0EN - GPIO Interrupt Registers 31-0                             *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned GPIO31                     :  1;
        unsigned GPIO30                     :  1;
        unsigned GPIO29                     :  1;
        unsigned GPIO28                     :  1;
        unsigned GPIO27                     :  1;
        unsigned GPIO26                     :  1;
        unsigned GPIO25                     :  1;
        unsigned GPIO24                     :  1;
        unsigned GPIO23                     :  1;
        unsigned GPIO22                     :  1;
        unsigned GPIO21                     :  1;
        unsigned GPIO20                     :  1;
        unsigned GPIO19                     :  1;
        unsigned GPIO18                     :  1;
        unsigned GPIO17                     :  1;
        unsigned GPIO16                     :  1;
        unsigned GPIO15                     :  1;
        unsigned GPIO14                     :  1;
        unsigned GPIO13                     :  1;
        unsigned GPIO12                     :  1;
        unsigned GPIO11                     :  1;
        unsigned GPIO10                     :  1;
        unsigned GPIO9                      :  1;
        unsigned GPIO8                      :  1;
        unsigned GPIO7                      :  1;
        unsigned GPIO6                      :  1;
        unsigned GPIO5                      :  1;
        unsigned GPIO4                      :  1;
        unsigned GPIO3                      :  1;
        unsigned GPIO2                      :  1;
        unsigned GPIO1                      :  1;
        unsigned GPIO0                      :  1;
    } B;
} reg_gpio_intrpt0en_t;

#define REG_GPIO_INTRPT0EN_ADDR                 (REG_GPIO_BASEADDR + 0x00000200UL)
#define REG_GPIO_INTRPT0EN                      (*(volatile reg_gpio_intrpt0en_t *) REG_GPIO_INTRPT0EN_ADDR)
#define REG_GPIO_INTRPT0EN_RD()                 (REG_GPIO_INTRPT0EN.U32)
#define REG_GPIO_INTRPT0EN_WR(v)                (REG_GPIO_INTRPT0EN.U32 = (v))
#define REG_GPIO_INTRPT0EN_CLR(m)               (REG_GPIO_INTRPT0EN.U32 = ((REG_GPIO_INTRPT0EN.U32) & ~(m)))
#define REG_GPIO_INTRPT0EN_SET(m)               (REG_GPIO_INTRPT0EN.U32 = ((REG_GPIO_INTRPT0EN.U32) | (m)))
#define REG_GPIO_INTRPT0EN_DEF                  0x00000000

#define BFP_GPIO_INTRPT0EN_GPIO31               (31)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO31               ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO31               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO31               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO31(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO31)) & (BFM_GPIO_INTRPT0EN_GPIO31))
#define BFX_GPIO_INTRPT0EN_GPIO31(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO31)) >> (BFP_GPIO_INTRPT0EN_GPIO31))
#define BFW_GPIO_INTRPT0EN_GPIO31(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO31)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO31)) & (BFM_GPIO_INTRPT0EN_GPIO31)) ))
#define BFR_GPIO_INTRPT0EN_GPIO31()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO31))>>(BFP_GPIO_INTRPT0EN_GPIO31))

#define BFP_GPIO_INTRPT0EN_GPIO30               (30)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO30               ((uint32_t)0x40000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO30               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO30               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO30(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO30)) & (BFM_GPIO_INTRPT0EN_GPIO30))
#define BFX_GPIO_INTRPT0EN_GPIO30(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO30)) >> (BFP_GPIO_INTRPT0EN_GPIO30))
#define BFW_GPIO_INTRPT0EN_GPIO30(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO30)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO30)) & (BFM_GPIO_INTRPT0EN_GPIO30)) ))
#define BFR_GPIO_INTRPT0EN_GPIO30()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO30))>>(BFP_GPIO_INTRPT0EN_GPIO30))

#define BFP_GPIO_INTRPT0EN_GPIO29               (29)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO29               ((uint32_t)0x20000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO29               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO29               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO29(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO29)) & (BFM_GPIO_INTRPT0EN_GPIO29))
#define BFX_GPIO_INTRPT0EN_GPIO29(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO29)) >> (BFP_GPIO_INTRPT0EN_GPIO29))
#define BFW_GPIO_INTRPT0EN_GPIO29(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO29)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO29)) & (BFM_GPIO_INTRPT0EN_GPIO29)) ))
#define BFR_GPIO_INTRPT0EN_GPIO29()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO29))>>(BFP_GPIO_INTRPT0EN_GPIO29))

#define BFP_GPIO_INTRPT0EN_GPIO28               (28)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO28               ((uint32_t)0x10000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO28               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO28               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO28(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO28)) & (BFM_GPIO_INTRPT0EN_GPIO28))
#define BFX_GPIO_INTRPT0EN_GPIO28(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO28)) >> (BFP_GPIO_INTRPT0EN_GPIO28))
#define BFW_GPIO_INTRPT0EN_GPIO28(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO28)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO28)) & (BFM_GPIO_INTRPT0EN_GPIO28)) ))
#define BFR_GPIO_INTRPT0EN_GPIO28()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO28))>>(BFP_GPIO_INTRPT0EN_GPIO28))

#define BFP_GPIO_INTRPT0EN_GPIO27               (27)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO27               ((uint32_t)0x08000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO27               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO27               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO27(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO27)) & (BFM_GPIO_INTRPT0EN_GPIO27))
#define BFX_GPIO_INTRPT0EN_GPIO27(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO27)) >> (BFP_GPIO_INTRPT0EN_GPIO27))
#define BFW_GPIO_INTRPT0EN_GPIO27(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO27)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO27)) & (BFM_GPIO_INTRPT0EN_GPIO27)) ))
#define BFR_GPIO_INTRPT0EN_GPIO27()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO27))>>(BFP_GPIO_INTRPT0EN_GPIO27))

#define BFP_GPIO_INTRPT0EN_GPIO26               (26)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO26               ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO26               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO26               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO26(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO26)) & (BFM_GPIO_INTRPT0EN_GPIO26))
#define BFX_GPIO_INTRPT0EN_GPIO26(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO26)) >> (BFP_GPIO_INTRPT0EN_GPIO26))
#define BFW_GPIO_INTRPT0EN_GPIO26(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO26)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO26)) & (BFM_GPIO_INTRPT0EN_GPIO26)) ))
#define BFR_GPIO_INTRPT0EN_GPIO26()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO26))>>(BFP_GPIO_INTRPT0EN_GPIO26))

#define BFP_GPIO_INTRPT0EN_GPIO25               (25)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO25               ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO25               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO25               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO25(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO25)) & (BFM_GPIO_INTRPT0EN_GPIO25))
#define BFX_GPIO_INTRPT0EN_GPIO25(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO25)) >> (BFP_GPIO_INTRPT0EN_GPIO25))
#define BFW_GPIO_INTRPT0EN_GPIO25(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO25)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO25)) & (BFM_GPIO_INTRPT0EN_GPIO25)) ))
#define BFR_GPIO_INTRPT0EN_GPIO25()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO25))>>(BFP_GPIO_INTRPT0EN_GPIO25))

#define BFP_GPIO_INTRPT0EN_GPIO24               (24)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO24               ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO24               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO24               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO24(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO24)) & (BFM_GPIO_INTRPT0EN_GPIO24))
#define BFX_GPIO_INTRPT0EN_GPIO24(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO24)) >> (BFP_GPIO_INTRPT0EN_GPIO24))
#define BFW_GPIO_INTRPT0EN_GPIO24(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO24)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO24)) & (BFM_GPIO_INTRPT0EN_GPIO24)) ))
#define BFR_GPIO_INTRPT0EN_GPIO24()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO24))>>(BFP_GPIO_INTRPT0EN_GPIO24))

#define BFP_GPIO_INTRPT0EN_GPIO23               (23)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO23               ((uint32_t)0x00800000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO23               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO23               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO23(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO23)) & (BFM_GPIO_INTRPT0EN_GPIO23))
#define BFX_GPIO_INTRPT0EN_GPIO23(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO23)) >> (BFP_GPIO_INTRPT0EN_GPIO23))
#define BFW_GPIO_INTRPT0EN_GPIO23(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO23)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO23)) & (BFM_GPIO_INTRPT0EN_GPIO23)) ))
#define BFR_GPIO_INTRPT0EN_GPIO23()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO23))>>(BFP_GPIO_INTRPT0EN_GPIO23))

#define BFP_GPIO_INTRPT0EN_GPIO22               (22)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO22               ((uint32_t)0x00400000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO22               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO22               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO22(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO22)) & (BFM_GPIO_INTRPT0EN_GPIO22))
#define BFX_GPIO_INTRPT0EN_GPIO22(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO22)) >> (BFP_GPIO_INTRPT0EN_GPIO22))
#define BFW_GPIO_INTRPT0EN_GPIO22(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO22)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO22)) & (BFM_GPIO_INTRPT0EN_GPIO22)) ))
#define BFR_GPIO_INTRPT0EN_GPIO22()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO22))>>(BFP_GPIO_INTRPT0EN_GPIO22))

#define BFP_GPIO_INTRPT0EN_GPIO21               (21)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO21               ((uint32_t)0x00200000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO21               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO21               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO21(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO21)) & (BFM_GPIO_INTRPT0EN_GPIO21))
#define BFX_GPIO_INTRPT0EN_GPIO21(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO21)) >> (BFP_GPIO_INTRPT0EN_GPIO21))
#define BFW_GPIO_INTRPT0EN_GPIO21(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO21)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO21)) & (BFM_GPIO_INTRPT0EN_GPIO21)) ))
#define BFR_GPIO_INTRPT0EN_GPIO21()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO21))>>(BFP_GPIO_INTRPT0EN_GPIO21))

#define BFP_GPIO_INTRPT0EN_GPIO20               (20)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO20               ((uint32_t)0x00100000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO20               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO20               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO20(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO20)) & (BFM_GPIO_INTRPT0EN_GPIO20))
#define BFX_GPIO_INTRPT0EN_GPIO20(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO20)) >> (BFP_GPIO_INTRPT0EN_GPIO20))
#define BFW_GPIO_INTRPT0EN_GPIO20(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO20)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO20)) & (BFM_GPIO_INTRPT0EN_GPIO20)) ))
#define BFR_GPIO_INTRPT0EN_GPIO20()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO20))>>(BFP_GPIO_INTRPT0EN_GPIO20))

#define BFP_GPIO_INTRPT0EN_GPIO19               (19)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO19               ((uint32_t)0x00080000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO19               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO19               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO19(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO19)) & (BFM_GPIO_INTRPT0EN_GPIO19))
#define BFX_GPIO_INTRPT0EN_GPIO19(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO19)) >> (BFP_GPIO_INTRPT0EN_GPIO19))
#define BFW_GPIO_INTRPT0EN_GPIO19(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO19)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO19)) & (BFM_GPIO_INTRPT0EN_GPIO19)) ))
#define BFR_GPIO_INTRPT0EN_GPIO19()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO19))>>(BFP_GPIO_INTRPT0EN_GPIO19))

#define BFP_GPIO_INTRPT0EN_GPIO18               (18)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO18               ((uint32_t)0x00040000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO18               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO18               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO18(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO18)) & (BFM_GPIO_INTRPT0EN_GPIO18))
#define BFX_GPIO_INTRPT0EN_GPIO18(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO18)) >> (BFP_GPIO_INTRPT0EN_GPIO18))
#define BFW_GPIO_INTRPT0EN_GPIO18(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO18)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO18)) & (BFM_GPIO_INTRPT0EN_GPIO18)) ))
#define BFR_GPIO_INTRPT0EN_GPIO18()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO18))>>(BFP_GPIO_INTRPT0EN_GPIO18))

#define BFP_GPIO_INTRPT0EN_GPIO17               (17)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO17               ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO17               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO17               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO17(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO17)) & (BFM_GPIO_INTRPT0EN_GPIO17))
#define BFX_GPIO_INTRPT0EN_GPIO17(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO17)) >> (BFP_GPIO_INTRPT0EN_GPIO17))
#define BFW_GPIO_INTRPT0EN_GPIO17(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO17)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO17)) & (BFM_GPIO_INTRPT0EN_GPIO17)) ))
#define BFR_GPIO_INTRPT0EN_GPIO17()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO17))>>(BFP_GPIO_INTRPT0EN_GPIO17))

#define BFP_GPIO_INTRPT0EN_GPIO16               (16)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO16               ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO16               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO16               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO16(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO16)) & (BFM_GPIO_INTRPT0EN_GPIO16))
#define BFX_GPIO_INTRPT0EN_GPIO16(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO16)) >> (BFP_GPIO_INTRPT0EN_GPIO16))
#define BFW_GPIO_INTRPT0EN_GPIO16(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO16)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO16)) & (BFM_GPIO_INTRPT0EN_GPIO16)) ))
#define BFR_GPIO_INTRPT0EN_GPIO16()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO16))>>(BFP_GPIO_INTRPT0EN_GPIO16))

#define BFP_GPIO_INTRPT0EN_GPIO15               (15)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO15               ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO15               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO15               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO15(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO15)) & (BFM_GPIO_INTRPT0EN_GPIO15))
#define BFX_GPIO_INTRPT0EN_GPIO15(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO15)) >> (BFP_GPIO_INTRPT0EN_GPIO15))
#define BFW_GPIO_INTRPT0EN_GPIO15(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO15)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO15)) & (BFM_GPIO_INTRPT0EN_GPIO15)) ))
#define BFR_GPIO_INTRPT0EN_GPIO15()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO15))>>(BFP_GPIO_INTRPT0EN_GPIO15))

#define BFP_GPIO_INTRPT0EN_GPIO14               (14)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO14               ((uint32_t)0x00004000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO14               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO14               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO14(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO14)) & (BFM_GPIO_INTRPT0EN_GPIO14))
#define BFX_GPIO_INTRPT0EN_GPIO14(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO14)) >> (BFP_GPIO_INTRPT0EN_GPIO14))
#define BFW_GPIO_INTRPT0EN_GPIO14(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO14)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO14)) & (BFM_GPIO_INTRPT0EN_GPIO14)) ))
#define BFR_GPIO_INTRPT0EN_GPIO14()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO14))>>(BFP_GPIO_INTRPT0EN_GPIO14))

#define BFP_GPIO_INTRPT0EN_GPIO13               (13)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO13               ((uint32_t)0x00002000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO13               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO13               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO13(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO13)) & (BFM_GPIO_INTRPT0EN_GPIO13))
#define BFX_GPIO_INTRPT0EN_GPIO13(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO13)) >> (BFP_GPIO_INTRPT0EN_GPIO13))
#define BFW_GPIO_INTRPT0EN_GPIO13(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO13)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO13)) & (BFM_GPIO_INTRPT0EN_GPIO13)) ))
#define BFR_GPIO_INTRPT0EN_GPIO13()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO13))>>(BFP_GPIO_INTRPT0EN_GPIO13))

#define BFP_GPIO_INTRPT0EN_GPIO12               (12)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO12               ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO12               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO12               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO12(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO12)) & (BFM_GPIO_INTRPT0EN_GPIO12))
#define BFX_GPIO_INTRPT0EN_GPIO12(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO12)) >> (BFP_GPIO_INTRPT0EN_GPIO12))
#define BFW_GPIO_INTRPT0EN_GPIO12(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO12)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO12)) & (BFM_GPIO_INTRPT0EN_GPIO12)) ))
#define BFR_GPIO_INTRPT0EN_GPIO12()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO12))>>(BFP_GPIO_INTRPT0EN_GPIO12))

#define BFP_GPIO_INTRPT0EN_GPIO11               (11)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO11               ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO11               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO11               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO11(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO11)) & (BFM_GPIO_INTRPT0EN_GPIO11))
#define BFX_GPIO_INTRPT0EN_GPIO11(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO11)) >> (BFP_GPIO_INTRPT0EN_GPIO11))
#define BFW_GPIO_INTRPT0EN_GPIO11(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO11)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO11)) & (BFM_GPIO_INTRPT0EN_GPIO11)) ))
#define BFR_GPIO_INTRPT0EN_GPIO11()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO11))>>(BFP_GPIO_INTRPT0EN_GPIO11))

#define BFP_GPIO_INTRPT0EN_GPIO10               (10)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO10               ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO10               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO10               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO10(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO10)) & (BFM_GPIO_INTRPT0EN_GPIO10))
#define BFX_GPIO_INTRPT0EN_GPIO10(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO10)) >> (BFP_GPIO_INTRPT0EN_GPIO10))
#define BFW_GPIO_INTRPT0EN_GPIO10(v)            (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO10)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO10)) & (BFM_GPIO_INTRPT0EN_GPIO10)) ))
#define BFR_GPIO_INTRPT0EN_GPIO10()             ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO10))>>(BFP_GPIO_INTRPT0EN_GPIO10))

#define BFP_GPIO_INTRPT0EN_GPIO9                (9)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO9                ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO9                (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO9                (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO9(v)             ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO9)) & (BFM_GPIO_INTRPT0EN_GPIO9))
#define BFX_GPIO_INTRPT0EN_GPIO9(v)             ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO9)) >> (BFP_GPIO_INTRPT0EN_GPIO9))
#define BFW_GPIO_INTRPT0EN_GPIO9(v)             (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO9)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO9)) & (BFM_GPIO_INTRPT0EN_GPIO9)) ))
#define BFR_GPIO_INTRPT0EN_GPIO9()              ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO9))>>(BFP_GPIO_INTRPT0EN_GPIO9))

#define BFP_GPIO_INTRPT0EN_GPIO8                (8)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO8                ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO8                (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO8                (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO8(v)             ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO8)) & (BFM_GPIO_INTRPT0EN_GPIO8))
#define BFX_GPIO_INTRPT0EN_GPIO8(v)             ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO8)) >> (BFP_GPIO_INTRPT0EN_GPIO8))
#define BFW_GPIO_INTRPT0EN_GPIO8(v)             (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO8)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO8)) & (BFM_GPIO_INTRPT0EN_GPIO8)) ))
#define BFR_GPIO_INTRPT0EN_GPIO8()              ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO8))>>(BFP_GPIO_INTRPT0EN_GPIO8))

#define BFP_GPIO_INTRPT0EN_GPIO7                (7)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO7                ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO7                (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO7                (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO7(v)             ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO7)) & (BFM_GPIO_INTRPT0EN_GPIO7))
#define BFX_GPIO_INTRPT0EN_GPIO7(v)             ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO7)) >> (BFP_GPIO_INTRPT0EN_GPIO7))
#define BFW_GPIO_INTRPT0EN_GPIO7(v)             (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO7)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO7)) & (BFM_GPIO_INTRPT0EN_GPIO7)) ))
#define BFR_GPIO_INTRPT0EN_GPIO7()              ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO7))>>(BFP_GPIO_INTRPT0EN_GPIO7))

#define BFP_GPIO_INTRPT0EN_GPIO6                (6)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO6                ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO6                (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO6                (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO6(v)             ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO6)) & (BFM_GPIO_INTRPT0EN_GPIO6))
#define BFX_GPIO_INTRPT0EN_GPIO6(v)             ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO6)) >> (BFP_GPIO_INTRPT0EN_GPIO6))
#define BFW_GPIO_INTRPT0EN_GPIO6(v)             (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO6)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO6)) & (BFM_GPIO_INTRPT0EN_GPIO6)) ))
#define BFR_GPIO_INTRPT0EN_GPIO6()              ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO6))>>(BFP_GPIO_INTRPT0EN_GPIO6))

#define BFP_GPIO_INTRPT0EN_GPIO5                (5)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO5                ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO5                (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO5                (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO5(v)             ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO5)) & (BFM_GPIO_INTRPT0EN_GPIO5))
#define BFX_GPIO_INTRPT0EN_GPIO5(v)             ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO5)) >> (BFP_GPIO_INTRPT0EN_GPIO5))
#define BFW_GPIO_INTRPT0EN_GPIO5(v)             (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO5)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO5)) & (BFM_GPIO_INTRPT0EN_GPIO5)) ))
#define BFR_GPIO_INTRPT0EN_GPIO5()              ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO5))>>(BFP_GPIO_INTRPT0EN_GPIO5))

#define BFP_GPIO_INTRPT0EN_GPIO4                (4)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO4                ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO4                (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO4                (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO4(v)             ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO4)) & (BFM_GPIO_INTRPT0EN_GPIO4))
#define BFX_GPIO_INTRPT0EN_GPIO4(v)             ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO4)) >> (BFP_GPIO_INTRPT0EN_GPIO4))
#define BFW_GPIO_INTRPT0EN_GPIO4(v)             (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO4)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO4)) & (BFM_GPIO_INTRPT0EN_GPIO4)) ))
#define BFR_GPIO_INTRPT0EN_GPIO4()              ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO4))>>(BFP_GPIO_INTRPT0EN_GPIO4))

#define BFP_GPIO_INTRPT0EN_GPIO3                (3)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO3                ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO3                (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO3                (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO3(v)             ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO3)) & (BFM_GPIO_INTRPT0EN_GPIO3))
#define BFX_GPIO_INTRPT0EN_GPIO3(v)             ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO3)) >> (BFP_GPIO_INTRPT0EN_GPIO3))
#define BFW_GPIO_INTRPT0EN_GPIO3(v)             (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO3)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO3)) & (BFM_GPIO_INTRPT0EN_GPIO3)) ))
#define BFR_GPIO_INTRPT0EN_GPIO3()              ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO3))>>(BFP_GPIO_INTRPT0EN_GPIO3))

#define BFP_GPIO_INTRPT0EN_GPIO2                (2)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO2                ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO2                (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO2                (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO2(v)             ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO2)) & (BFM_GPIO_INTRPT0EN_GPIO2))
#define BFX_GPIO_INTRPT0EN_GPIO2(v)             ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO2)) >> (BFP_GPIO_INTRPT0EN_GPIO2))
#define BFW_GPIO_INTRPT0EN_GPIO2(v)             (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO2)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO2)) & (BFM_GPIO_INTRPT0EN_GPIO2)) ))
#define BFR_GPIO_INTRPT0EN_GPIO2()              ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO2))>>(BFP_GPIO_INTRPT0EN_GPIO2))

#define BFP_GPIO_INTRPT0EN_GPIO1                (1)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO1                ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO1                (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO1                (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO1(v)             ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO1)) & (BFM_GPIO_INTRPT0EN_GPIO1))
#define BFX_GPIO_INTRPT0EN_GPIO1(v)             ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO1)) >> (BFP_GPIO_INTRPT0EN_GPIO1))
#define BFW_GPIO_INTRPT0EN_GPIO1(v)             (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO1)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO1)) & (BFM_GPIO_INTRPT0EN_GPIO1)) ))
#define BFR_GPIO_INTRPT0EN_GPIO1()              ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO1))>>(BFP_GPIO_INTRPT0EN_GPIO1))

#define BFP_GPIO_INTRPT0EN_GPIO0                (0)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0EN_GPIO0                ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_INTRPT0EN_GPIO0                (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0EN_GPIO0                (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0EN_GPIO0(v)             ((((uint32_t) v) << (BFP_GPIO_INTRPT0EN_GPIO0)) & (BFM_GPIO_INTRPT0EN_GPIO0))
#define BFX_GPIO_INTRPT0EN_GPIO0(v)             ((((uint32_t) v) & (BFM_GPIO_INTRPT0EN_GPIO0)) >> (BFP_GPIO_INTRPT0EN_GPIO0))
#define BFW_GPIO_INTRPT0EN_GPIO0(v)             (REG_GPIO_INTRPT0EN.U32 = ( (REG_GPIO_INTRPT0EN.U32 & ~(BFM_GPIO_INTRPT0EN_GPIO0)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0EN_GPIO0)) & (BFM_GPIO_INTRPT0EN_GPIO0)) ))
#define BFR_GPIO_INTRPT0EN_GPIO0()              ((REG_GPIO_INTRPT0EN.U32 & (BFM_GPIO_INTRPT0EN_GPIO0))>>(BFP_GPIO_INTRPT0EN_GPIO0))


// *****************************************************************************
//                                                                             *
//  GPIO_INTRPT0STAT - GPIO Interrupt Registers 31-0                           *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned GPIO31                     :  1;
        unsigned GPIO30                     :  1;
        unsigned GPIO29                     :  1;
        unsigned GPIO28                     :  1;
        unsigned GPIO27                     :  1;
        unsigned GPIO26                     :  1;
        unsigned GPIO25                     :  1;
        unsigned GPIO24                     :  1;
        unsigned GPIO23                     :  1;
        unsigned GPIO22                     :  1;
        unsigned GPIO21                     :  1;
        unsigned GPIO20                     :  1;
        unsigned GPIO19                     :  1;
        unsigned GPIO18                     :  1;
        unsigned GPIO17                     :  1;
        unsigned GPIO16                     :  1;
        unsigned GPIO15                     :  1;
        unsigned GPIO14                     :  1;
        unsigned GPIO13                     :  1;
        unsigned GPIO12                     :  1;
        unsigned GPIO11                     :  1;
        unsigned GPIO10                     :  1;
        unsigned GPIO9                      :  1;
        unsigned GPIO8                      :  1;
        unsigned GPIO7                      :  1;
        unsigned GPIO6                      :  1;
        unsigned GPIO5                      :  1;
        unsigned GPIO4                      :  1;
        unsigned GPIO3                      :  1;
        unsigned GPIO2                      :  1;
        unsigned GPIO1                      :  1;
        unsigned GPIO0                      :  1;
    } B;
} reg_gpio_intrpt0stat_t;

#define REG_GPIO_INTRPT0STAT_ADDR               (REG_GPIO_BASEADDR + 0x00000204UL)
#define REG_GPIO_INTRPT0STAT                    (*(volatile reg_gpio_intrpt0stat_t *) REG_GPIO_INTRPT0STAT_ADDR)
#define REG_GPIO_INTRPT0STAT_RD()               (REG_GPIO_INTRPT0STAT.U32)
#define REG_GPIO_INTRPT0STAT_WR(v)              (REG_GPIO_INTRPT0STAT.U32 = (v))
#define REG_GPIO_INTRPT0STAT_CLR(m)             (REG_GPIO_INTRPT0STAT.U32 = ((REG_GPIO_INTRPT0STAT.U32) & ~(m)))
#define REG_GPIO_INTRPT0STAT_SET(m)             (REG_GPIO_INTRPT0STAT.U32 = ((REG_GPIO_INTRPT0STAT.U32) | (m)))
#define REG_GPIO_INTRPT0STAT_DEF                0x00000000

#define BFP_GPIO_INTRPT0STAT_GPIO31             (31)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO31             ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO31             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO31             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO31(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO31)) & (BFM_GPIO_INTRPT0STAT_GPIO31))
#define BFX_GPIO_INTRPT0STAT_GPIO31(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO31)) >> (BFP_GPIO_INTRPT0STAT_GPIO31))
#define BFW_GPIO_INTRPT0STAT_GPIO31(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO31)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO31)) & (BFM_GPIO_INTRPT0STAT_GPIO31)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO31()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO31))>>(BFP_GPIO_INTRPT0STAT_GPIO31))

#define BFP_GPIO_INTRPT0STAT_GPIO30             (30)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO30             ((uint32_t)0x40000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO30             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO30             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO30(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO30)) & (BFM_GPIO_INTRPT0STAT_GPIO30))
#define BFX_GPIO_INTRPT0STAT_GPIO30(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO30)) >> (BFP_GPIO_INTRPT0STAT_GPIO30))
#define BFW_GPIO_INTRPT0STAT_GPIO30(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO30)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO30)) & (BFM_GPIO_INTRPT0STAT_GPIO30)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO30()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO30))>>(BFP_GPIO_INTRPT0STAT_GPIO30))

#define BFP_GPIO_INTRPT0STAT_GPIO29             (29)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO29             ((uint32_t)0x20000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO29             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO29             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO29(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO29)) & (BFM_GPIO_INTRPT0STAT_GPIO29))
#define BFX_GPIO_INTRPT0STAT_GPIO29(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO29)) >> (BFP_GPIO_INTRPT0STAT_GPIO29))
#define BFW_GPIO_INTRPT0STAT_GPIO29(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO29)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO29)) & (BFM_GPIO_INTRPT0STAT_GPIO29)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO29()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO29))>>(BFP_GPIO_INTRPT0STAT_GPIO29))

#define BFP_GPIO_INTRPT0STAT_GPIO28             (28)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO28             ((uint32_t)0x10000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO28             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO28             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO28(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO28)) & (BFM_GPIO_INTRPT0STAT_GPIO28))
#define BFX_GPIO_INTRPT0STAT_GPIO28(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO28)) >> (BFP_GPIO_INTRPT0STAT_GPIO28))
#define BFW_GPIO_INTRPT0STAT_GPIO28(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO28)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO28)) & (BFM_GPIO_INTRPT0STAT_GPIO28)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO28()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO28))>>(BFP_GPIO_INTRPT0STAT_GPIO28))

#define BFP_GPIO_INTRPT0STAT_GPIO27             (27)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO27             ((uint32_t)0x08000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO27             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO27             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO27(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO27)) & (BFM_GPIO_INTRPT0STAT_GPIO27))
#define BFX_GPIO_INTRPT0STAT_GPIO27(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO27)) >> (BFP_GPIO_INTRPT0STAT_GPIO27))
#define BFW_GPIO_INTRPT0STAT_GPIO27(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO27)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO27)) & (BFM_GPIO_INTRPT0STAT_GPIO27)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO27()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO27))>>(BFP_GPIO_INTRPT0STAT_GPIO27))

#define BFP_GPIO_INTRPT0STAT_GPIO26             (26)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO26             ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO26             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO26             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO26(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO26)) & (BFM_GPIO_INTRPT0STAT_GPIO26))
#define BFX_GPIO_INTRPT0STAT_GPIO26(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO26)) >> (BFP_GPIO_INTRPT0STAT_GPIO26))
#define BFW_GPIO_INTRPT0STAT_GPIO26(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO26)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO26)) & (BFM_GPIO_INTRPT0STAT_GPIO26)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO26()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO26))>>(BFP_GPIO_INTRPT0STAT_GPIO26))

#define BFP_GPIO_INTRPT0STAT_GPIO25             (25)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO25             ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO25             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO25             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO25(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO25)) & (BFM_GPIO_INTRPT0STAT_GPIO25))
#define BFX_GPIO_INTRPT0STAT_GPIO25(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO25)) >> (BFP_GPIO_INTRPT0STAT_GPIO25))
#define BFW_GPIO_INTRPT0STAT_GPIO25(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO25)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO25)) & (BFM_GPIO_INTRPT0STAT_GPIO25)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO25()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO25))>>(BFP_GPIO_INTRPT0STAT_GPIO25))

#define BFP_GPIO_INTRPT0STAT_GPIO24             (24)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO24             ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO24             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO24             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO24(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO24)) & (BFM_GPIO_INTRPT0STAT_GPIO24))
#define BFX_GPIO_INTRPT0STAT_GPIO24(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO24)) >> (BFP_GPIO_INTRPT0STAT_GPIO24))
#define BFW_GPIO_INTRPT0STAT_GPIO24(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO24)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO24)) & (BFM_GPIO_INTRPT0STAT_GPIO24)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO24()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO24))>>(BFP_GPIO_INTRPT0STAT_GPIO24))

#define BFP_GPIO_INTRPT0STAT_GPIO23             (23)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO23             ((uint32_t)0x00800000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO23             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO23             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO23(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO23)) & (BFM_GPIO_INTRPT0STAT_GPIO23))
#define BFX_GPIO_INTRPT0STAT_GPIO23(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO23)) >> (BFP_GPIO_INTRPT0STAT_GPIO23))
#define BFW_GPIO_INTRPT0STAT_GPIO23(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO23)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO23)) & (BFM_GPIO_INTRPT0STAT_GPIO23)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO23()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO23))>>(BFP_GPIO_INTRPT0STAT_GPIO23))

#define BFP_GPIO_INTRPT0STAT_GPIO22             (22)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO22             ((uint32_t)0x00400000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO22             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO22             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO22(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO22)) & (BFM_GPIO_INTRPT0STAT_GPIO22))
#define BFX_GPIO_INTRPT0STAT_GPIO22(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO22)) >> (BFP_GPIO_INTRPT0STAT_GPIO22))
#define BFW_GPIO_INTRPT0STAT_GPIO22(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO22)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO22)) & (BFM_GPIO_INTRPT0STAT_GPIO22)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO22()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO22))>>(BFP_GPIO_INTRPT0STAT_GPIO22))

#define BFP_GPIO_INTRPT0STAT_GPIO21             (21)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO21             ((uint32_t)0x00200000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO21             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO21             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO21(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO21)) & (BFM_GPIO_INTRPT0STAT_GPIO21))
#define BFX_GPIO_INTRPT0STAT_GPIO21(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO21)) >> (BFP_GPIO_INTRPT0STAT_GPIO21))
#define BFW_GPIO_INTRPT0STAT_GPIO21(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO21)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO21)) & (BFM_GPIO_INTRPT0STAT_GPIO21)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO21()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO21))>>(BFP_GPIO_INTRPT0STAT_GPIO21))

#define BFP_GPIO_INTRPT0STAT_GPIO20             (20)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO20             ((uint32_t)0x00100000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO20             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO20             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO20(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO20)) & (BFM_GPIO_INTRPT0STAT_GPIO20))
#define BFX_GPIO_INTRPT0STAT_GPIO20(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO20)) >> (BFP_GPIO_INTRPT0STAT_GPIO20))
#define BFW_GPIO_INTRPT0STAT_GPIO20(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO20)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO20)) & (BFM_GPIO_INTRPT0STAT_GPIO20)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO20()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO20))>>(BFP_GPIO_INTRPT0STAT_GPIO20))

#define BFP_GPIO_INTRPT0STAT_GPIO19             (19)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO19             ((uint32_t)0x00080000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO19             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO19             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO19(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO19)) & (BFM_GPIO_INTRPT0STAT_GPIO19))
#define BFX_GPIO_INTRPT0STAT_GPIO19(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO19)) >> (BFP_GPIO_INTRPT0STAT_GPIO19))
#define BFW_GPIO_INTRPT0STAT_GPIO19(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO19)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO19)) & (BFM_GPIO_INTRPT0STAT_GPIO19)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO19()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO19))>>(BFP_GPIO_INTRPT0STAT_GPIO19))

#define BFP_GPIO_INTRPT0STAT_GPIO18             (18)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO18             ((uint32_t)0x00040000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO18             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO18             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO18(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO18)) & (BFM_GPIO_INTRPT0STAT_GPIO18))
#define BFX_GPIO_INTRPT0STAT_GPIO18(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO18)) >> (BFP_GPIO_INTRPT0STAT_GPIO18))
#define BFW_GPIO_INTRPT0STAT_GPIO18(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO18)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO18)) & (BFM_GPIO_INTRPT0STAT_GPIO18)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO18()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO18))>>(BFP_GPIO_INTRPT0STAT_GPIO18))

#define BFP_GPIO_INTRPT0STAT_GPIO17             (17)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO17             ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO17             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO17             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO17(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO17)) & (BFM_GPIO_INTRPT0STAT_GPIO17))
#define BFX_GPIO_INTRPT0STAT_GPIO17(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO17)) >> (BFP_GPIO_INTRPT0STAT_GPIO17))
#define BFW_GPIO_INTRPT0STAT_GPIO17(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO17)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO17)) & (BFM_GPIO_INTRPT0STAT_GPIO17)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO17()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO17))>>(BFP_GPIO_INTRPT0STAT_GPIO17))

#define BFP_GPIO_INTRPT0STAT_GPIO16             (16)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO16             ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO16             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO16             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO16(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO16)) & (BFM_GPIO_INTRPT0STAT_GPIO16))
#define BFX_GPIO_INTRPT0STAT_GPIO16(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO16)) >> (BFP_GPIO_INTRPT0STAT_GPIO16))
#define BFW_GPIO_INTRPT0STAT_GPIO16(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO16)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO16)) & (BFM_GPIO_INTRPT0STAT_GPIO16)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO16()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO16))>>(BFP_GPIO_INTRPT0STAT_GPIO16))

#define BFP_GPIO_INTRPT0STAT_GPIO15             (15)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO15             ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO15             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO15             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO15(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO15)) & (BFM_GPIO_INTRPT0STAT_GPIO15))
#define BFX_GPIO_INTRPT0STAT_GPIO15(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO15)) >> (BFP_GPIO_INTRPT0STAT_GPIO15))
#define BFW_GPIO_INTRPT0STAT_GPIO15(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO15)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO15)) & (BFM_GPIO_INTRPT0STAT_GPIO15)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO15()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO15))>>(BFP_GPIO_INTRPT0STAT_GPIO15))

#define BFP_GPIO_INTRPT0STAT_GPIO14             (14)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO14             ((uint32_t)0x00004000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO14             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO14             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO14(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO14)) & (BFM_GPIO_INTRPT0STAT_GPIO14))
#define BFX_GPIO_INTRPT0STAT_GPIO14(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO14)) >> (BFP_GPIO_INTRPT0STAT_GPIO14))
#define BFW_GPIO_INTRPT0STAT_GPIO14(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO14)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO14)) & (BFM_GPIO_INTRPT0STAT_GPIO14)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO14()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO14))>>(BFP_GPIO_INTRPT0STAT_GPIO14))

#define BFP_GPIO_INTRPT0STAT_GPIO13             (13)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO13             ((uint32_t)0x00002000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO13             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO13             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO13(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO13)) & (BFM_GPIO_INTRPT0STAT_GPIO13))
#define BFX_GPIO_INTRPT0STAT_GPIO13(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO13)) >> (BFP_GPIO_INTRPT0STAT_GPIO13))
#define BFW_GPIO_INTRPT0STAT_GPIO13(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO13)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO13)) & (BFM_GPIO_INTRPT0STAT_GPIO13)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO13()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO13))>>(BFP_GPIO_INTRPT0STAT_GPIO13))

#define BFP_GPIO_INTRPT0STAT_GPIO12             (12)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO12             ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO12             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO12             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO12(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO12)) & (BFM_GPIO_INTRPT0STAT_GPIO12))
#define BFX_GPIO_INTRPT0STAT_GPIO12(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO12)) >> (BFP_GPIO_INTRPT0STAT_GPIO12))
#define BFW_GPIO_INTRPT0STAT_GPIO12(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO12)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO12)) & (BFM_GPIO_INTRPT0STAT_GPIO12)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO12()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO12))>>(BFP_GPIO_INTRPT0STAT_GPIO12))

#define BFP_GPIO_INTRPT0STAT_GPIO11             (11)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO11             ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO11             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO11             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO11(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO11)) & (BFM_GPIO_INTRPT0STAT_GPIO11))
#define BFX_GPIO_INTRPT0STAT_GPIO11(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO11)) >> (BFP_GPIO_INTRPT0STAT_GPIO11))
#define BFW_GPIO_INTRPT0STAT_GPIO11(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO11)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO11)) & (BFM_GPIO_INTRPT0STAT_GPIO11)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO11()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO11))>>(BFP_GPIO_INTRPT0STAT_GPIO11))

#define BFP_GPIO_INTRPT0STAT_GPIO10             (10)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO10             ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO10             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO10             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO10(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO10)) & (BFM_GPIO_INTRPT0STAT_GPIO10))
#define BFX_GPIO_INTRPT0STAT_GPIO10(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO10)) >> (BFP_GPIO_INTRPT0STAT_GPIO10))
#define BFW_GPIO_INTRPT0STAT_GPIO10(v)          (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO10)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO10)) & (BFM_GPIO_INTRPT0STAT_GPIO10)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO10()           ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO10))>>(BFP_GPIO_INTRPT0STAT_GPIO10))

#define BFP_GPIO_INTRPT0STAT_GPIO9              (9)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO9              ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO9              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO9              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO9(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO9)) & (BFM_GPIO_INTRPT0STAT_GPIO9))
#define BFX_GPIO_INTRPT0STAT_GPIO9(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO9)) >> (BFP_GPIO_INTRPT0STAT_GPIO9))
#define BFW_GPIO_INTRPT0STAT_GPIO9(v)           (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO9)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO9)) & (BFM_GPIO_INTRPT0STAT_GPIO9)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO9()            ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO9))>>(BFP_GPIO_INTRPT0STAT_GPIO9))

#define BFP_GPIO_INTRPT0STAT_GPIO8              (8)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO8              ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO8              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO8              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO8(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO8)) & (BFM_GPIO_INTRPT0STAT_GPIO8))
#define BFX_GPIO_INTRPT0STAT_GPIO8(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO8)) >> (BFP_GPIO_INTRPT0STAT_GPIO8))
#define BFW_GPIO_INTRPT0STAT_GPIO8(v)           (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO8)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO8)) & (BFM_GPIO_INTRPT0STAT_GPIO8)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO8()            ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO8))>>(BFP_GPIO_INTRPT0STAT_GPIO8))

#define BFP_GPIO_INTRPT0STAT_GPIO7              (7)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO7              ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO7              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO7              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO7(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO7)) & (BFM_GPIO_INTRPT0STAT_GPIO7))
#define BFX_GPIO_INTRPT0STAT_GPIO7(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO7)) >> (BFP_GPIO_INTRPT0STAT_GPIO7))
#define BFW_GPIO_INTRPT0STAT_GPIO7(v)           (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO7)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO7)) & (BFM_GPIO_INTRPT0STAT_GPIO7)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO7()            ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO7))>>(BFP_GPIO_INTRPT0STAT_GPIO7))

#define BFP_GPIO_INTRPT0STAT_GPIO6              (6)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO6              ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO6              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO6              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO6(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO6)) & (BFM_GPIO_INTRPT0STAT_GPIO6))
#define BFX_GPIO_INTRPT0STAT_GPIO6(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO6)) >> (BFP_GPIO_INTRPT0STAT_GPIO6))
#define BFW_GPIO_INTRPT0STAT_GPIO6(v)           (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO6)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO6)) & (BFM_GPIO_INTRPT0STAT_GPIO6)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO6()            ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO6))>>(BFP_GPIO_INTRPT0STAT_GPIO6))

#define BFP_GPIO_INTRPT0STAT_GPIO5              (5)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO5              ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO5              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO5              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO5(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO5)) & (BFM_GPIO_INTRPT0STAT_GPIO5))
#define BFX_GPIO_INTRPT0STAT_GPIO5(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO5)) >> (BFP_GPIO_INTRPT0STAT_GPIO5))
#define BFW_GPIO_INTRPT0STAT_GPIO5(v)           (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO5)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO5)) & (BFM_GPIO_INTRPT0STAT_GPIO5)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO5()            ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO5))>>(BFP_GPIO_INTRPT0STAT_GPIO5))

#define BFP_GPIO_INTRPT0STAT_GPIO4              (4)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO4              ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO4              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO4              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO4(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO4)) & (BFM_GPIO_INTRPT0STAT_GPIO4))
#define BFX_GPIO_INTRPT0STAT_GPIO4(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO4)) >> (BFP_GPIO_INTRPT0STAT_GPIO4))
#define BFW_GPIO_INTRPT0STAT_GPIO4(v)           (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO4)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO4)) & (BFM_GPIO_INTRPT0STAT_GPIO4)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO4()            ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO4))>>(BFP_GPIO_INTRPT0STAT_GPIO4))

#define BFP_GPIO_INTRPT0STAT_GPIO3              (3)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO3              ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO3              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO3              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO3(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO3)) & (BFM_GPIO_INTRPT0STAT_GPIO3))
#define BFX_GPIO_INTRPT0STAT_GPIO3(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO3)) >> (BFP_GPIO_INTRPT0STAT_GPIO3))
#define BFW_GPIO_INTRPT0STAT_GPIO3(v)           (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO3)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO3)) & (BFM_GPIO_INTRPT0STAT_GPIO3)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO3()            ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO3))>>(BFP_GPIO_INTRPT0STAT_GPIO3))

#define BFP_GPIO_INTRPT0STAT_GPIO2              (2)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO2              ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO2              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO2              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO2(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO2)) & (BFM_GPIO_INTRPT0STAT_GPIO2))
#define BFX_GPIO_INTRPT0STAT_GPIO2(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO2)) >> (BFP_GPIO_INTRPT0STAT_GPIO2))
#define BFW_GPIO_INTRPT0STAT_GPIO2(v)           (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO2)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO2)) & (BFM_GPIO_INTRPT0STAT_GPIO2)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO2()            ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO2))>>(BFP_GPIO_INTRPT0STAT_GPIO2))

#define BFP_GPIO_INTRPT0STAT_GPIO1              (1)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO1              ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO1              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO1              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO1(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO1)) & (BFM_GPIO_INTRPT0STAT_GPIO1))
#define BFX_GPIO_INTRPT0STAT_GPIO1(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO1)) >> (BFP_GPIO_INTRPT0STAT_GPIO1))
#define BFW_GPIO_INTRPT0STAT_GPIO1(v)           (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO1)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO1)) & (BFM_GPIO_INTRPT0STAT_GPIO1)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO1()            ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO1))>>(BFP_GPIO_INTRPT0STAT_GPIO1))

#define BFP_GPIO_INTRPT0STAT_GPIO0              (0)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0STAT_GPIO0              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_INTRPT0STAT_GPIO0              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0STAT_GPIO0              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0STAT_GPIO0(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0STAT_GPIO0)) & (BFM_GPIO_INTRPT0STAT_GPIO0))
#define BFX_GPIO_INTRPT0STAT_GPIO0(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0STAT_GPIO0)) >> (BFP_GPIO_INTRPT0STAT_GPIO0))
#define BFW_GPIO_INTRPT0STAT_GPIO0(v)           (REG_GPIO_INTRPT0STAT.U32 = ( (REG_GPIO_INTRPT0STAT.U32 & ~(BFM_GPIO_INTRPT0STAT_GPIO0)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0STAT_GPIO0)) & (BFM_GPIO_INTRPT0STAT_GPIO0)) ))
#define BFR_GPIO_INTRPT0STAT_GPIO0()            ((REG_GPIO_INTRPT0STAT.U32 & (BFM_GPIO_INTRPT0STAT_GPIO0))>>(BFP_GPIO_INTRPT0STAT_GPIO0))


// *****************************************************************************
//                                                                             *
//  GPIO_INTRPT0CLR - GPIO Interrupt Registers 31-0                            *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned GPIO31                     :  1;
        unsigned GPIO30                     :  1;
        unsigned GPIO29                     :  1;
        unsigned GPIO28                     :  1;
        unsigned GPIO27                     :  1;
        unsigned GPIO26                     :  1;
        unsigned GPIO25                     :  1;
        unsigned GPIO24                     :  1;
        unsigned GPIO23                     :  1;
        unsigned GPIO22                     :  1;
        unsigned GPIO21                     :  1;
        unsigned GPIO20                     :  1;
        unsigned GPIO19                     :  1;
        unsigned GPIO18                     :  1;
        unsigned GPIO17                     :  1;
        unsigned GPIO16                     :  1;
        unsigned GPIO15                     :  1;
        unsigned GPIO14                     :  1;
        unsigned GPIO13                     :  1;
        unsigned GPIO12                     :  1;
        unsigned GPIO11                     :  1;
        unsigned GPIO10                     :  1;
        unsigned GPIO9                      :  1;
        unsigned GPIO8                      :  1;
        unsigned GPIO7                      :  1;
        unsigned GPIO6                      :  1;
        unsigned GPIO5                      :  1;
        unsigned GPIO4                      :  1;
        unsigned GPIO3                      :  1;
        unsigned GPIO2                      :  1;
        unsigned GPIO1                      :  1;
        unsigned GPIO0                      :  1;
    } B;
} reg_gpio_intrpt0clr_t;

#define REG_GPIO_INTRPT0CLR_ADDR                (REG_GPIO_BASEADDR + 0x00000208UL)
#define REG_GPIO_INTRPT0CLR                     (*(volatile reg_gpio_intrpt0clr_t *) REG_GPIO_INTRPT0CLR_ADDR)
#define REG_GPIO_INTRPT0CLR_RD()                (REG_GPIO_INTRPT0CLR.U32)
#define REG_GPIO_INTRPT0CLR_WR(v)               (REG_GPIO_INTRPT0CLR.U32 = (v))
#define REG_GPIO_INTRPT0CLR_CLR(m)              (REG_GPIO_INTRPT0CLR.U32 = ((REG_GPIO_INTRPT0CLR.U32) & ~(m)))
#define REG_GPIO_INTRPT0CLR_SET(m)              (REG_GPIO_INTRPT0CLR.U32 = ((REG_GPIO_INTRPT0CLR.U32) | (m)))
#define REG_GPIO_INTRPT0CLR_DEF                 0x00000000

#define BFP_GPIO_INTRPT0CLR_GPIO31              (31)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO31              ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO31              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO31              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO31(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO31)) & (BFM_GPIO_INTRPT0CLR_GPIO31))
#define BFX_GPIO_INTRPT0CLR_GPIO31(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO31)) >> (BFP_GPIO_INTRPT0CLR_GPIO31))
#define BFW_GPIO_INTRPT0CLR_GPIO31(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO31)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO31)) & (BFM_GPIO_INTRPT0CLR_GPIO31)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO31()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO31))>>(BFP_GPIO_INTRPT0CLR_GPIO31))

#define BFP_GPIO_INTRPT0CLR_GPIO30              (30)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO30              ((uint32_t)0x40000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO30              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO30              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO30(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO30)) & (BFM_GPIO_INTRPT0CLR_GPIO30))
#define BFX_GPIO_INTRPT0CLR_GPIO30(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO30)) >> (BFP_GPIO_INTRPT0CLR_GPIO30))
#define BFW_GPIO_INTRPT0CLR_GPIO30(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO30)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO30)) & (BFM_GPIO_INTRPT0CLR_GPIO30)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO30()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO30))>>(BFP_GPIO_INTRPT0CLR_GPIO30))

#define BFP_GPIO_INTRPT0CLR_GPIO29              (29)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO29              ((uint32_t)0x20000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO29              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO29              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO29(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO29)) & (BFM_GPIO_INTRPT0CLR_GPIO29))
#define BFX_GPIO_INTRPT0CLR_GPIO29(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO29)) >> (BFP_GPIO_INTRPT0CLR_GPIO29))
#define BFW_GPIO_INTRPT0CLR_GPIO29(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO29)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO29)) & (BFM_GPIO_INTRPT0CLR_GPIO29)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO29()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO29))>>(BFP_GPIO_INTRPT0CLR_GPIO29))

#define BFP_GPIO_INTRPT0CLR_GPIO28              (28)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO28              ((uint32_t)0x10000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO28              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO28              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO28(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO28)) & (BFM_GPIO_INTRPT0CLR_GPIO28))
#define BFX_GPIO_INTRPT0CLR_GPIO28(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO28)) >> (BFP_GPIO_INTRPT0CLR_GPIO28))
#define BFW_GPIO_INTRPT0CLR_GPIO28(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO28)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO28)) & (BFM_GPIO_INTRPT0CLR_GPIO28)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO28()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO28))>>(BFP_GPIO_INTRPT0CLR_GPIO28))

#define BFP_GPIO_INTRPT0CLR_GPIO27              (27)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO27              ((uint32_t)0x08000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO27              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO27              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO27(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO27)) & (BFM_GPIO_INTRPT0CLR_GPIO27))
#define BFX_GPIO_INTRPT0CLR_GPIO27(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO27)) >> (BFP_GPIO_INTRPT0CLR_GPIO27))
#define BFW_GPIO_INTRPT0CLR_GPIO27(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO27)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO27)) & (BFM_GPIO_INTRPT0CLR_GPIO27)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO27()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO27))>>(BFP_GPIO_INTRPT0CLR_GPIO27))

#define BFP_GPIO_INTRPT0CLR_GPIO26              (26)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO26              ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO26              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO26              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO26(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO26)) & (BFM_GPIO_INTRPT0CLR_GPIO26))
#define BFX_GPIO_INTRPT0CLR_GPIO26(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO26)) >> (BFP_GPIO_INTRPT0CLR_GPIO26))
#define BFW_GPIO_INTRPT0CLR_GPIO26(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO26)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO26)) & (BFM_GPIO_INTRPT0CLR_GPIO26)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO26()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO26))>>(BFP_GPIO_INTRPT0CLR_GPIO26))

#define BFP_GPIO_INTRPT0CLR_GPIO25              (25)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO25              ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO25              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO25              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO25(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO25)) & (BFM_GPIO_INTRPT0CLR_GPIO25))
#define BFX_GPIO_INTRPT0CLR_GPIO25(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO25)) >> (BFP_GPIO_INTRPT0CLR_GPIO25))
#define BFW_GPIO_INTRPT0CLR_GPIO25(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO25)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO25)) & (BFM_GPIO_INTRPT0CLR_GPIO25)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO25()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO25))>>(BFP_GPIO_INTRPT0CLR_GPIO25))

#define BFP_GPIO_INTRPT0CLR_GPIO24              (24)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO24              ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO24              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO24              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO24(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO24)) & (BFM_GPIO_INTRPT0CLR_GPIO24))
#define BFX_GPIO_INTRPT0CLR_GPIO24(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO24)) >> (BFP_GPIO_INTRPT0CLR_GPIO24))
#define BFW_GPIO_INTRPT0CLR_GPIO24(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO24)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO24)) & (BFM_GPIO_INTRPT0CLR_GPIO24)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO24()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO24))>>(BFP_GPIO_INTRPT0CLR_GPIO24))

#define BFP_GPIO_INTRPT0CLR_GPIO23              (23)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO23              ((uint32_t)0x00800000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO23              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO23              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO23(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO23)) & (BFM_GPIO_INTRPT0CLR_GPIO23))
#define BFX_GPIO_INTRPT0CLR_GPIO23(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO23)) >> (BFP_GPIO_INTRPT0CLR_GPIO23))
#define BFW_GPIO_INTRPT0CLR_GPIO23(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO23)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO23)) & (BFM_GPIO_INTRPT0CLR_GPIO23)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO23()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO23))>>(BFP_GPIO_INTRPT0CLR_GPIO23))

#define BFP_GPIO_INTRPT0CLR_GPIO22              (22)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO22              ((uint32_t)0x00400000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO22              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO22              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO22(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO22)) & (BFM_GPIO_INTRPT0CLR_GPIO22))
#define BFX_GPIO_INTRPT0CLR_GPIO22(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO22)) >> (BFP_GPIO_INTRPT0CLR_GPIO22))
#define BFW_GPIO_INTRPT0CLR_GPIO22(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO22)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO22)) & (BFM_GPIO_INTRPT0CLR_GPIO22)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO22()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO22))>>(BFP_GPIO_INTRPT0CLR_GPIO22))

#define BFP_GPIO_INTRPT0CLR_GPIO21              (21)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO21              ((uint32_t)0x00200000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO21              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO21              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO21(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO21)) & (BFM_GPIO_INTRPT0CLR_GPIO21))
#define BFX_GPIO_INTRPT0CLR_GPIO21(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO21)) >> (BFP_GPIO_INTRPT0CLR_GPIO21))
#define BFW_GPIO_INTRPT0CLR_GPIO21(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO21)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO21)) & (BFM_GPIO_INTRPT0CLR_GPIO21)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO21()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO21))>>(BFP_GPIO_INTRPT0CLR_GPIO21))

#define BFP_GPIO_INTRPT0CLR_GPIO20              (20)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO20              ((uint32_t)0x00100000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO20              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO20              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO20(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO20)) & (BFM_GPIO_INTRPT0CLR_GPIO20))
#define BFX_GPIO_INTRPT0CLR_GPIO20(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO20)) >> (BFP_GPIO_INTRPT0CLR_GPIO20))
#define BFW_GPIO_INTRPT0CLR_GPIO20(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO20)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO20)) & (BFM_GPIO_INTRPT0CLR_GPIO20)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO20()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO20))>>(BFP_GPIO_INTRPT0CLR_GPIO20))

#define BFP_GPIO_INTRPT0CLR_GPIO19              (19)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO19              ((uint32_t)0x00080000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO19              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO19              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO19(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO19)) & (BFM_GPIO_INTRPT0CLR_GPIO19))
#define BFX_GPIO_INTRPT0CLR_GPIO19(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO19)) >> (BFP_GPIO_INTRPT0CLR_GPIO19))
#define BFW_GPIO_INTRPT0CLR_GPIO19(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO19)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO19)) & (BFM_GPIO_INTRPT0CLR_GPIO19)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO19()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO19))>>(BFP_GPIO_INTRPT0CLR_GPIO19))

#define BFP_GPIO_INTRPT0CLR_GPIO18              (18)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO18              ((uint32_t)0x00040000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO18              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO18              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO18(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO18)) & (BFM_GPIO_INTRPT0CLR_GPIO18))
#define BFX_GPIO_INTRPT0CLR_GPIO18(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO18)) >> (BFP_GPIO_INTRPT0CLR_GPIO18))
#define BFW_GPIO_INTRPT0CLR_GPIO18(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO18)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO18)) & (BFM_GPIO_INTRPT0CLR_GPIO18)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO18()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO18))>>(BFP_GPIO_INTRPT0CLR_GPIO18))

#define BFP_GPIO_INTRPT0CLR_GPIO17              (17)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO17              ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO17              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO17              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO17(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO17)) & (BFM_GPIO_INTRPT0CLR_GPIO17))
#define BFX_GPIO_INTRPT0CLR_GPIO17(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO17)) >> (BFP_GPIO_INTRPT0CLR_GPIO17))
#define BFW_GPIO_INTRPT0CLR_GPIO17(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO17)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO17)) & (BFM_GPIO_INTRPT0CLR_GPIO17)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO17()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO17))>>(BFP_GPIO_INTRPT0CLR_GPIO17))

#define BFP_GPIO_INTRPT0CLR_GPIO16              (16)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO16              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO16              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO16              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO16(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO16)) & (BFM_GPIO_INTRPT0CLR_GPIO16))
#define BFX_GPIO_INTRPT0CLR_GPIO16(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO16)) >> (BFP_GPIO_INTRPT0CLR_GPIO16))
#define BFW_GPIO_INTRPT0CLR_GPIO16(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO16)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO16)) & (BFM_GPIO_INTRPT0CLR_GPIO16)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO16()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO16))>>(BFP_GPIO_INTRPT0CLR_GPIO16))

#define BFP_GPIO_INTRPT0CLR_GPIO15              (15)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO15              ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO15              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO15              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO15(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO15)) & (BFM_GPIO_INTRPT0CLR_GPIO15))
#define BFX_GPIO_INTRPT0CLR_GPIO15(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO15)) >> (BFP_GPIO_INTRPT0CLR_GPIO15))
#define BFW_GPIO_INTRPT0CLR_GPIO15(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO15)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO15)) & (BFM_GPIO_INTRPT0CLR_GPIO15)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO15()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO15))>>(BFP_GPIO_INTRPT0CLR_GPIO15))

#define BFP_GPIO_INTRPT0CLR_GPIO14              (14)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO14              ((uint32_t)0x00004000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO14              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO14              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO14(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO14)) & (BFM_GPIO_INTRPT0CLR_GPIO14))
#define BFX_GPIO_INTRPT0CLR_GPIO14(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO14)) >> (BFP_GPIO_INTRPT0CLR_GPIO14))
#define BFW_GPIO_INTRPT0CLR_GPIO14(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO14)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO14)) & (BFM_GPIO_INTRPT0CLR_GPIO14)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO14()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO14))>>(BFP_GPIO_INTRPT0CLR_GPIO14))

#define BFP_GPIO_INTRPT0CLR_GPIO13              (13)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO13              ((uint32_t)0x00002000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO13              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO13              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO13(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO13)) & (BFM_GPIO_INTRPT0CLR_GPIO13))
#define BFX_GPIO_INTRPT0CLR_GPIO13(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO13)) >> (BFP_GPIO_INTRPT0CLR_GPIO13))
#define BFW_GPIO_INTRPT0CLR_GPIO13(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO13)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO13)) & (BFM_GPIO_INTRPT0CLR_GPIO13)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO13()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO13))>>(BFP_GPIO_INTRPT0CLR_GPIO13))

#define BFP_GPIO_INTRPT0CLR_GPIO12              (12)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO12              ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO12              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO12              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO12(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO12)) & (BFM_GPIO_INTRPT0CLR_GPIO12))
#define BFX_GPIO_INTRPT0CLR_GPIO12(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO12)) >> (BFP_GPIO_INTRPT0CLR_GPIO12))
#define BFW_GPIO_INTRPT0CLR_GPIO12(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO12)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO12)) & (BFM_GPIO_INTRPT0CLR_GPIO12)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO12()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO12))>>(BFP_GPIO_INTRPT0CLR_GPIO12))

#define BFP_GPIO_INTRPT0CLR_GPIO11              (11)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO11              ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO11              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO11              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO11(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO11)) & (BFM_GPIO_INTRPT0CLR_GPIO11))
#define BFX_GPIO_INTRPT0CLR_GPIO11(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO11)) >> (BFP_GPIO_INTRPT0CLR_GPIO11))
#define BFW_GPIO_INTRPT0CLR_GPIO11(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO11)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO11)) & (BFM_GPIO_INTRPT0CLR_GPIO11)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO11()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO11))>>(BFP_GPIO_INTRPT0CLR_GPIO11))

#define BFP_GPIO_INTRPT0CLR_GPIO10              (10)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO10              ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO10              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO10              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO10(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO10)) & (BFM_GPIO_INTRPT0CLR_GPIO10))
#define BFX_GPIO_INTRPT0CLR_GPIO10(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO10)) >> (BFP_GPIO_INTRPT0CLR_GPIO10))
#define BFW_GPIO_INTRPT0CLR_GPIO10(v)           (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO10)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO10)) & (BFM_GPIO_INTRPT0CLR_GPIO10)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO10()            ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO10))>>(BFP_GPIO_INTRPT0CLR_GPIO10))

#define BFP_GPIO_INTRPT0CLR_GPIO9               (9)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO9               ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO9               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO9               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO9(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO9)) & (BFM_GPIO_INTRPT0CLR_GPIO9))
#define BFX_GPIO_INTRPT0CLR_GPIO9(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO9)) >> (BFP_GPIO_INTRPT0CLR_GPIO9))
#define BFW_GPIO_INTRPT0CLR_GPIO9(v)            (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO9)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO9)) & (BFM_GPIO_INTRPT0CLR_GPIO9)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO9()             ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO9))>>(BFP_GPIO_INTRPT0CLR_GPIO9))

#define BFP_GPIO_INTRPT0CLR_GPIO8               (8)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO8               ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO8               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO8               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO8(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO8)) & (BFM_GPIO_INTRPT0CLR_GPIO8))
#define BFX_GPIO_INTRPT0CLR_GPIO8(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO8)) >> (BFP_GPIO_INTRPT0CLR_GPIO8))
#define BFW_GPIO_INTRPT0CLR_GPIO8(v)            (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO8)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO8)) & (BFM_GPIO_INTRPT0CLR_GPIO8)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO8()             ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO8))>>(BFP_GPIO_INTRPT0CLR_GPIO8))

#define BFP_GPIO_INTRPT0CLR_GPIO7               (7)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO7               ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO7               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO7               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO7(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO7)) & (BFM_GPIO_INTRPT0CLR_GPIO7))
#define BFX_GPIO_INTRPT0CLR_GPIO7(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO7)) >> (BFP_GPIO_INTRPT0CLR_GPIO7))
#define BFW_GPIO_INTRPT0CLR_GPIO7(v)            (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO7)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO7)) & (BFM_GPIO_INTRPT0CLR_GPIO7)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO7()             ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO7))>>(BFP_GPIO_INTRPT0CLR_GPIO7))

#define BFP_GPIO_INTRPT0CLR_GPIO6               (6)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO6               ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO6               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO6               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO6(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO6)) & (BFM_GPIO_INTRPT0CLR_GPIO6))
#define BFX_GPIO_INTRPT0CLR_GPIO6(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO6)) >> (BFP_GPIO_INTRPT0CLR_GPIO6))
#define BFW_GPIO_INTRPT0CLR_GPIO6(v)            (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO6)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO6)) & (BFM_GPIO_INTRPT0CLR_GPIO6)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO6()             ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO6))>>(BFP_GPIO_INTRPT0CLR_GPIO6))

#define BFP_GPIO_INTRPT0CLR_GPIO5               (5)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO5               ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO5               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO5               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO5(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO5)) & (BFM_GPIO_INTRPT0CLR_GPIO5))
#define BFX_GPIO_INTRPT0CLR_GPIO5(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO5)) >> (BFP_GPIO_INTRPT0CLR_GPIO5))
#define BFW_GPIO_INTRPT0CLR_GPIO5(v)            (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO5)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO5)) & (BFM_GPIO_INTRPT0CLR_GPIO5)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO5()             ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO5))>>(BFP_GPIO_INTRPT0CLR_GPIO5))

#define BFP_GPIO_INTRPT0CLR_GPIO4               (4)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO4               ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO4               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO4               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO4(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO4)) & (BFM_GPIO_INTRPT0CLR_GPIO4))
#define BFX_GPIO_INTRPT0CLR_GPIO4(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO4)) >> (BFP_GPIO_INTRPT0CLR_GPIO4))
#define BFW_GPIO_INTRPT0CLR_GPIO4(v)            (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO4)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO4)) & (BFM_GPIO_INTRPT0CLR_GPIO4)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO4()             ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO4))>>(BFP_GPIO_INTRPT0CLR_GPIO4))

#define BFP_GPIO_INTRPT0CLR_GPIO3               (3)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO3               ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO3               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO3               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO3(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO3)) & (BFM_GPIO_INTRPT0CLR_GPIO3))
#define BFX_GPIO_INTRPT0CLR_GPIO3(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO3)) >> (BFP_GPIO_INTRPT0CLR_GPIO3))
#define BFW_GPIO_INTRPT0CLR_GPIO3(v)            (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO3)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO3)) & (BFM_GPIO_INTRPT0CLR_GPIO3)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO3()             ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO3))>>(BFP_GPIO_INTRPT0CLR_GPIO3))

#define BFP_GPIO_INTRPT0CLR_GPIO2               (2)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO2               ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO2               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO2               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO2(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO2)) & (BFM_GPIO_INTRPT0CLR_GPIO2))
#define BFX_GPIO_INTRPT0CLR_GPIO2(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO2)) >> (BFP_GPIO_INTRPT0CLR_GPIO2))
#define BFW_GPIO_INTRPT0CLR_GPIO2(v)            (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO2)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO2)) & (BFM_GPIO_INTRPT0CLR_GPIO2)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO2()             ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO2))>>(BFP_GPIO_INTRPT0CLR_GPIO2))

#define BFP_GPIO_INTRPT0CLR_GPIO1               (1)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO1               ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO1               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO1               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO1(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO1)) & (BFM_GPIO_INTRPT0CLR_GPIO1))
#define BFX_GPIO_INTRPT0CLR_GPIO1(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO1)) >> (BFP_GPIO_INTRPT0CLR_GPIO1))
#define BFW_GPIO_INTRPT0CLR_GPIO1(v)            (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO1)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO1)) & (BFM_GPIO_INTRPT0CLR_GPIO1)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO1()             ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO1))>>(BFP_GPIO_INTRPT0CLR_GPIO1))

#define BFP_GPIO_INTRPT0CLR_GPIO0               (0)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0CLR_GPIO0               ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_INTRPT0CLR_GPIO0               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0CLR_GPIO0               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0CLR_GPIO0(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0CLR_GPIO0)) & (BFM_GPIO_INTRPT0CLR_GPIO0))
#define BFX_GPIO_INTRPT0CLR_GPIO0(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0CLR_GPIO0)) >> (BFP_GPIO_INTRPT0CLR_GPIO0))
#define BFW_GPIO_INTRPT0CLR_GPIO0(v)            (REG_GPIO_INTRPT0CLR.U32 = ( (REG_GPIO_INTRPT0CLR.U32 & ~(BFM_GPIO_INTRPT0CLR_GPIO0)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0CLR_GPIO0)) & (BFM_GPIO_INTRPT0CLR_GPIO0)) ))
#define BFR_GPIO_INTRPT0CLR_GPIO0()             ((REG_GPIO_INTRPT0CLR.U32 & (BFM_GPIO_INTRPT0CLR_GPIO0))>>(BFP_GPIO_INTRPT0CLR_GPIO0))


// *****************************************************************************
//                                                                             *
//  GPIO_INTRPT0SET - GPIO Interrupt Registers 31-0                            *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned GPIO31                     :  1;
        unsigned GPIO30                     :  1;
        unsigned GPIO29                     :  1;
        unsigned GPIO28                     :  1;
        unsigned GPIO27                     :  1;
        unsigned GPIO26                     :  1;
        unsigned GPIO25                     :  1;
        unsigned GPIO24                     :  1;
        unsigned GPIO23                     :  1;
        unsigned GPIO22                     :  1;
        unsigned GPIO21                     :  1;
        unsigned GPIO20                     :  1;
        unsigned GPIO19                     :  1;
        unsigned GPIO18                     :  1;
        unsigned GPIO17                     :  1;
        unsigned GPIO16                     :  1;
        unsigned GPIO15                     :  1;
        unsigned GPIO14                     :  1;
        unsigned GPIO13                     :  1;
        unsigned GPIO12                     :  1;
        unsigned GPIO11                     :  1;
        unsigned GPIO10                     :  1;
        unsigned GPIO9                      :  1;
        unsigned GPIO8                      :  1;
        unsigned GPIO7                      :  1;
        unsigned GPIO6                      :  1;
        unsigned GPIO5                      :  1;
        unsigned GPIO4                      :  1;
        unsigned GPIO3                      :  1;
        unsigned GPIO2                      :  1;
        unsigned GPIO1                      :  1;
        unsigned GPIO0                      :  1;
    } B;
} reg_gpio_intrpt0set_t;

#define REG_GPIO_INTRPT0SET_ADDR                (REG_GPIO_BASEADDR + 0x0000020CUL)
#define REG_GPIO_INTRPT0SET                     (*(volatile reg_gpio_intrpt0set_t *) REG_GPIO_INTRPT0SET_ADDR)
#define REG_GPIO_INTRPT0SET_RD()                (REG_GPIO_INTRPT0SET.U32)
#define REG_GPIO_INTRPT0SET_WR(v)               (REG_GPIO_INTRPT0SET.U32 = (v))
#define REG_GPIO_INTRPT0SET_CLR(m)              (REG_GPIO_INTRPT0SET.U32 = ((REG_GPIO_INTRPT0SET.U32) & ~(m)))
#define REG_GPIO_INTRPT0SET_SET(m)              (REG_GPIO_INTRPT0SET.U32 = ((REG_GPIO_INTRPT0SET.U32) | (m)))
#define REG_GPIO_INTRPT0SET_DEF                 0x00000000

#define BFP_GPIO_INTRPT0SET_GPIO31              (31)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO31              ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO31              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO31              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO31(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO31)) & (BFM_GPIO_INTRPT0SET_GPIO31))
#define BFX_GPIO_INTRPT0SET_GPIO31(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO31)) >> (BFP_GPIO_INTRPT0SET_GPIO31))
#define BFW_GPIO_INTRPT0SET_GPIO31(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO31)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO31)) & (BFM_GPIO_INTRPT0SET_GPIO31)) ))
#define BFR_GPIO_INTRPT0SET_GPIO31()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO31))>>(BFP_GPIO_INTRPT0SET_GPIO31))

#define BFP_GPIO_INTRPT0SET_GPIO30              (30)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO30              ((uint32_t)0x40000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO30              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO30              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO30(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO30)) & (BFM_GPIO_INTRPT0SET_GPIO30))
#define BFX_GPIO_INTRPT0SET_GPIO30(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO30)) >> (BFP_GPIO_INTRPT0SET_GPIO30))
#define BFW_GPIO_INTRPT0SET_GPIO30(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO30)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO30)) & (BFM_GPIO_INTRPT0SET_GPIO30)) ))
#define BFR_GPIO_INTRPT0SET_GPIO30()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO30))>>(BFP_GPIO_INTRPT0SET_GPIO30))

#define BFP_GPIO_INTRPT0SET_GPIO29              (29)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO29              ((uint32_t)0x20000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO29              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO29              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO29(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO29)) & (BFM_GPIO_INTRPT0SET_GPIO29))
#define BFX_GPIO_INTRPT0SET_GPIO29(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO29)) >> (BFP_GPIO_INTRPT0SET_GPIO29))
#define BFW_GPIO_INTRPT0SET_GPIO29(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO29)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO29)) & (BFM_GPIO_INTRPT0SET_GPIO29)) ))
#define BFR_GPIO_INTRPT0SET_GPIO29()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO29))>>(BFP_GPIO_INTRPT0SET_GPIO29))

#define BFP_GPIO_INTRPT0SET_GPIO28              (28)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO28              ((uint32_t)0x10000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO28              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO28              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO28(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO28)) & (BFM_GPIO_INTRPT0SET_GPIO28))
#define BFX_GPIO_INTRPT0SET_GPIO28(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO28)) >> (BFP_GPIO_INTRPT0SET_GPIO28))
#define BFW_GPIO_INTRPT0SET_GPIO28(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO28)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO28)) & (BFM_GPIO_INTRPT0SET_GPIO28)) ))
#define BFR_GPIO_INTRPT0SET_GPIO28()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO28))>>(BFP_GPIO_INTRPT0SET_GPIO28))

#define BFP_GPIO_INTRPT0SET_GPIO27              (27)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO27              ((uint32_t)0x08000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO27              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO27              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO27(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO27)) & (BFM_GPIO_INTRPT0SET_GPIO27))
#define BFX_GPIO_INTRPT0SET_GPIO27(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO27)) >> (BFP_GPIO_INTRPT0SET_GPIO27))
#define BFW_GPIO_INTRPT0SET_GPIO27(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO27)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO27)) & (BFM_GPIO_INTRPT0SET_GPIO27)) ))
#define BFR_GPIO_INTRPT0SET_GPIO27()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO27))>>(BFP_GPIO_INTRPT0SET_GPIO27))

#define BFP_GPIO_INTRPT0SET_GPIO26              (26)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO26              ((uint32_t)0x04000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO26              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO26              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO26(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO26)) & (BFM_GPIO_INTRPT0SET_GPIO26))
#define BFX_GPIO_INTRPT0SET_GPIO26(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO26)) >> (BFP_GPIO_INTRPT0SET_GPIO26))
#define BFW_GPIO_INTRPT0SET_GPIO26(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO26)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO26)) & (BFM_GPIO_INTRPT0SET_GPIO26)) ))
#define BFR_GPIO_INTRPT0SET_GPIO26()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO26))>>(BFP_GPIO_INTRPT0SET_GPIO26))

#define BFP_GPIO_INTRPT0SET_GPIO25              (25)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO25              ((uint32_t)0x02000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO25              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO25              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO25(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO25)) & (BFM_GPIO_INTRPT0SET_GPIO25))
#define BFX_GPIO_INTRPT0SET_GPIO25(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO25)) >> (BFP_GPIO_INTRPT0SET_GPIO25))
#define BFW_GPIO_INTRPT0SET_GPIO25(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO25)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO25)) & (BFM_GPIO_INTRPT0SET_GPIO25)) ))
#define BFR_GPIO_INTRPT0SET_GPIO25()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO25))>>(BFP_GPIO_INTRPT0SET_GPIO25))

#define BFP_GPIO_INTRPT0SET_GPIO24              (24)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO24              ((uint32_t)0x01000000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO24              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO24              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO24(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO24)) & (BFM_GPIO_INTRPT0SET_GPIO24))
#define BFX_GPIO_INTRPT0SET_GPIO24(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO24)) >> (BFP_GPIO_INTRPT0SET_GPIO24))
#define BFW_GPIO_INTRPT0SET_GPIO24(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO24)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO24)) & (BFM_GPIO_INTRPT0SET_GPIO24)) ))
#define BFR_GPIO_INTRPT0SET_GPIO24()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO24))>>(BFP_GPIO_INTRPT0SET_GPIO24))

#define BFP_GPIO_INTRPT0SET_GPIO23              (23)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO23              ((uint32_t)0x00800000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO23              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO23              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO23(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO23)) & (BFM_GPIO_INTRPT0SET_GPIO23))
#define BFX_GPIO_INTRPT0SET_GPIO23(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO23)) >> (BFP_GPIO_INTRPT0SET_GPIO23))
#define BFW_GPIO_INTRPT0SET_GPIO23(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO23)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO23)) & (BFM_GPIO_INTRPT0SET_GPIO23)) ))
#define BFR_GPIO_INTRPT0SET_GPIO23()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO23))>>(BFP_GPIO_INTRPT0SET_GPIO23))

#define BFP_GPIO_INTRPT0SET_GPIO22              (22)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO22              ((uint32_t)0x00400000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO22              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO22              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO22(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO22)) & (BFM_GPIO_INTRPT0SET_GPIO22))
#define BFX_GPIO_INTRPT0SET_GPIO22(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO22)) >> (BFP_GPIO_INTRPT0SET_GPIO22))
#define BFW_GPIO_INTRPT0SET_GPIO22(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO22)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO22)) & (BFM_GPIO_INTRPT0SET_GPIO22)) ))
#define BFR_GPIO_INTRPT0SET_GPIO22()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO22))>>(BFP_GPIO_INTRPT0SET_GPIO22))

#define BFP_GPIO_INTRPT0SET_GPIO21              (21)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO21              ((uint32_t)0x00200000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO21              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO21              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO21(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO21)) & (BFM_GPIO_INTRPT0SET_GPIO21))
#define BFX_GPIO_INTRPT0SET_GPIO21(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO21)) >> (BFP_GPIO_INTRPT0SET_GPIO21))
#define BFW_GPIO_INTRPT0SET_GPIO21(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO21)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO21)) & (BFM_GPIO_INTRPT0SET_GPIO21)) ))
#define BFR_GPIO_INTRPT0SET_GPIO21()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO21))>>(BFP_GPIO_INTRPT0SET_GPIO21))

#define BFP_GPIO_INTRPT0SET_GPIO20              (20)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO20              ((uint32_t)0x00100000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO20              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO20              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO20(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO20)) & (BFM_GPIO_INTRPT0SET_GPIO20))
#define BFX_GPIO_INTRPT0SET_GPIO20(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO20)) >> (BFP_GPIO_INTRPT0SET_GPIO20))
#define BFW_GPIO_INTRPT0SET_GPIO20(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO20)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO20)) & (BFM_GPIO_INTRPT0SET_GPIO20)) ))
#define BFR_GPIO_INTRPT0SET_GPIO20()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO20))>>(BFP_GPIO_INTRPT0SET_GPIO20))

#define BFP_GPIO_INTRPT0SET_GPIO19              (19)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO19              ((uint32_t)0x00080000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO19              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO19              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO19(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO19)) & (BFM_GPIO_INTRPT0SET_GPIO19))
#define BFX_GPIO_INTRPT0SET_GPIO19(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO19)) >> (BFP_GPIO_INTRPT0SET_GPIO19))
#define BFW_GPIO_INTRPT0SET_GPIO19(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO19)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO19)) & (BFM_GPIO_INTRPT0SET_GPIO19)) ))
#define BFR_GPIO_INTRPT0SET_GPIO19()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO19))>>(BFP_GPIO_INTRPT0SET_GPIO19))

#define BFP_GPIO_INTRPT0SET_GPIO18              (18)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO18              ((uint32_t)0x00040000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO18              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO18              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO18(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO18)) & (BFM_GPIO_INTRPT0SET_GPIO18))
#define BFX_GPIO_INTRPT0SET_GPIO18(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO18)) >> (BFP_GPIO_INTRPT0SET_GPIO18))
#define BFW_GPIO_INTRPT0SET_GPIO18(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO18)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO18)) & (BFM_GPIO_INTRPT0SET_GPIO18)) ))
#define BFR_GPIO_INTRPT0SET_GPIO18()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO18))>>(BFP_GPIO_INTRPT0SET_GPIO18))

#define BFP_GPIO_INTRPT0SET_GPIO17              (17)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO17              ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO17              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO17              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO17(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO17)) & (BFM_GPIO_INTRPT0SET_GPIO17))
#define BFX_GPIO_INTRPT0SET_GPIO17(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO17)) >> (BFP_GPIO_INTRPT0SET_GPIO17))
#define BFW_GPIO_INTRPT0SET_GPIO17(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO17)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO17)) & (BFM_GPIO_INTRPT0SET_GPIO17)) ))
#define BFR_GPIO_INTRPT0SET_GPIO17()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO17))>>(BFP_GPIO_INTRPT0SET_GPIO17))

#define BFP_GPIO_INTRPT0SET_GPIO16              (16)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO16              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO16              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO16              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO16(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO16)) & (BFM_GPIO_INTRPT0SET_GPIO16))
#define BFX_GPIO_INTRPT0SET_GPIO16(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO16)) >> (BFP_GPIO_INTRPT0SET_GPIO16))
#define BFW_GPIO_INTRPT0SET_GPIO16(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO16)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO16)) & (BFM_GPIO_INTRPT0SET_GPIO16)) ))
#define BFR_GPIO_INTRPT0SET_GPIO16()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO16))>>(BFP_GPIO_INTRPT0SET_GPIO16))

#define BFP_GPIO_INTRPT0SET_GPIO15              (15)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO15              ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO15              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO15              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO15(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO15)) & (BFM_GPIO_INTRPT0SET_GPIO15))
#define BFX_GPIO_INTRPT0SET_GPIO15(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO15)) >> (BFP_GPIO_INTRPT0SET_GPIO15))
#define BFW_GPIO_INTRPT0SET_GPIO15(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO15)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO15)) & (BFM_GPIO_INTRPT0SET_GPIO15)) ))
#define BFR_GPIO_INTRPT0SET_GPIO15()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO15))>>(BFP_GPIO_INTRPT0SET_GPIO15))

#define BFP_GPIO_INTRPT0SET_GPIO14              (14)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO14              ((uint32_t)0x00004000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO14              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO14              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO14(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO14)) & (BFM_GPIO_INTRPT0SET_GPIO14))
#define BFX_GPIO_INTRPT0SET_GPIO14(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO14)) >> (BFP_GPIO_INTRPT0SET_GPIO14))
#define BFW_GPIO_INTRPT0SET_GPIO14(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO14)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO14)) & (BFM_GPIO_INTRPT0SET_GPIO14)) ))
#define BFR_GPIO_INTRPT0SET_GPIO14()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO14))>>(BFP_GPIO_INTRPT0SET_GPIO14))

#define BFP_GPIO_INTRPT0SET_GPIO13              (13)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO13              ((uint32_t)0x00002000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO13              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO13              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO13(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO13)) & (BFM_GPIO_INTRPT0SET_GPIO13))
#define BFX_GPIO_INTRPT0SET_GPIO13(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO13)) >> (BFP_GPIO_INTRPT0SET_GPIO13))
#define BFW_GPIO_INTRPT0SET_GPIO13(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO13)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO13)) & (BFM_GPIO_INTRPT0SET_GPIO13)) ))
#define BFR_GPIO_INTRPT0SET_GPIO13()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO13))>>(BFP_GPIO_INTRPT0SET_GPIO13))

#define BFP_GPIO_INTRPT0SET_GPIO12              (12)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO12              ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO12              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO12              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO12(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO12)) & (BFM_GPIO_INTRPT0SET_GPIO12))
#define BFX_GPIO_INTRPT0SET_GPIO12(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO12)) >> (BFP_GPIO_INTRPT0SET_GPIO12))
#define BFW_GPIO_INTRPT0SET_GPIO12(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO12)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO12)) & (BFM_GPIO_INTRPT0SET_GPIO12)) ))
#define BFR_GPIO_INTRPT0SET_GPIO12()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO12))>>(BFP_GPIO_INTRPT0SET_GPIO12))

#define BFP_GPIO_INTRPT0SET_GPIO11              (11)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO11              ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO11              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO11              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO11(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO11)) & (BFM_GPIO_INTRPT0SET_GPIO11))
#define BFX_GPIO_INTRPT0SET_GPIO11(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO11)) >> (BFP_GPIO_INTRPT0SET_GPIO11))
#define BFW_GPIO_INTRPT0SET_GPIO11(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO11)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO11)) & (BFM_GPIO_INTRPT0SET_GPIO11)) ))
#define BFR_GPIO_INTRPT0SET_GPIO11()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO11))>>(BFP_GPIO_INTRPT0SET_GPIO11))

#define BFP_GPIO_INTRPT0SET_GPIO10              (10)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO10              ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO10              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO10              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO10(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO10)) & (BFM_GPIO_INTRPT0SET_GPIO10))
#define BFX_GPIO_INTRPT0SET_GPIO10(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO10)) >> (BFP_GPIO_INTRPT0SET_GPIO10))
#define BFW_GPIO_INTRPT0SET_GPIO10(v)           (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO10)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO10)) & (BFM_GPIO_INTRPT0SET_GPIO10)) ))
#define BFR_GPIO_INTRPT0SET_GPIO10()            ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO10))>>(BFP_GPIO_INTRPT0SET_GPIO10))

#define BFP_GPIO_INTRPT0SET_GPIO9               (9)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO9               ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO9               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO9               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO9(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO9)) & (BFM_GPIO_INTRPT0SET_GPIO9))
#define BFX_GPIO_INTRPT0SET_GPIO9(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO9)) >> (BFP_GPIO_INTRPT0SET_GPIO9))
#define BFW_GPIO_INTRPT0SET_GPIO9(v)            (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO9)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO9)) & (BFM_GPIO_INTRPT0SET_GPIO9)) ))
#define BFR_GPIO_INTRPT0SET_GPIO9()             ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO9))>>(BFP_GPIO_INTRPT0SET_GPIO9))

#define BFP_GPIO_INTRPT0SET_GPIO8               (8)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO8               ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO8               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO8               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO8(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO8)) & (BFM_GPIO_INTRPT0SET_GPIO8))
#define BFX_GPIO_INTRPT0SET_GPIO8(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO8)) >> (BFP_GPIO_INTRPT0SET_GPIO8))
#define BFW_GPIO_INTRPT0SET_GPIO8(v)            (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO8)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO8)) & (BFM_GPIO_INTRPT0SET_GPIO8)) ))
#define BFR_GPIO_INTRPT0SET_GPIO8()             ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO8))>>(BFP_GPIO_INTRPT0SET_GPIO8))

#define BFP_GPIO_INTRPT0SET_GPIO7               (7)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO7               ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO7               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO7               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO7(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO7)) & (BFM_GPIO_INTRPT0SET_GPIO7))
#define BFX_GPIO_INTRPT0SET_GPIO7(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO7)) >> (BFP_GPIO_INTRPT0SET_GPIO7))
#define BFW_GPIO_INTRPT0SET_GPIO7(v)            (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO7)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO7)) & (BFM_GPIO_INTRPT0SET_GPIO7)) ))
#define BFR_GPIO_INTRPT0SET_GPIO7()             ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO7))>>(BFP_GPIO_INTRPT0SET_GPIO7))

#define BFP_GPIO_INTRPT0SET_GPIO6               (6)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO6               ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO6               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO6               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO6(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO6)) & (BFM_GPIO_INTRPT0SET_GPIO6))
#define BFX_GPIO_INTRPT0SET_GPIO6(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO6)) >> (BFP_GPIO_INTRPT0SET_GPIO6))
#define BFW_GPIO_INTRPT0SET_GPIO6(v)            (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO6)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO6)) & (BFM_GPIO_INTRPT0SET_GPIO6)) ))
#define BFR_GPIO_INTRPT0SET_GPIO6()             ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO6))>>(BFP_GPIO_INTRPT0SET_GPIO6))

#define BFP_GPIO_INTRPT0SET_GPIO5               (5)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO5               ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO5               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO5               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO5(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO5)) & (BFM_GPIO_INTRPT0SET_GPIO5))
#define BFX_GPIO_INTRPT0SET_GPIO5(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO5)) >> (BFP_GPIO_INTRPT0SET_GPIO5))
#define BFW_GPIO_INTRPT0SET_GPIO5(v)            (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO5)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO5)) & (BFM_GPIO_INTRPT0SET_GPIO5)) ))
#define BFR_GPIO_INTRPT0SET_GPIO5()             ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO5))>>(BFP_GPIO_INTRPT0SET_GPIO5))

#define BFP_GPIO_INTRPT0SET_GPIO4               (4)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO4               ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO4               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO4               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO4(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO4)) & (BFM_GPIO_INTRPT0SET_GPIO4))
#define BFX_GPIO_INTRPT0SET_GPIO4(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO4)) >> (BFP_GPIO_INTRPT0SET_GPIO4))
#define BFW_GPIO_INTRPT0SET_GPIO4(v)            (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO4)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO4)) & (BFM_GPIO_INTRPT0SET_GPIO4)) ))
#define BFR_GPIO_INTRPT0SET_GPIO4()             ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO4))>>(BFP_GPIO_INTRPT0SET_GPIO4))

#define BFP_GPIO_INTRPT0SET_GPIO3               (3)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO3               ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO3               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO3               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO3(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO3)) & (BFM_GPIO_INTRPT0SET_GPIO3))
#define BFX_GPIO_INTRPT0SET_GPIO3(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO3)) >> (BFP_GPIO_INTRPT0SET_GPIO3))
#define BFW_GPIO_INTRPT0SET_GPIO3(v)            (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO3)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO3)) & (BFM_GPIO_INTRPT0SET_GPIO3)) ))
#define BFR_GPIO_INTRPT0SET_GPIO3()             ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO3))>>(BFP_GPIO_INTRPT0SET_GPIO3))

#define BFP_GPIO_INTRPT0SET_GPIO2               (2)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO2               ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO2               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO2               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO2(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO2)) & (BFM_GPIO_INTRPT0SET_GPIO2))
#define BFX_GPIO_INTRPT0SET_GPIO2(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO2)) >> (BFP_GPIO_INTRPT0SET_GPIO2))
#define BFW_GPIO_INTRPT0SET_GPIO2(v)            (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO2)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO2)) & (BFM_GPIO_INTRPT0SET_GPIO2)) ))
#define BFR_GPIO_INTRPT0SET_GPIO2()             ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO2))>>(BFP_GPIO_INTRPT0SET_GPIO2))

#define BFP_GPIO_INTRPT0SET_GPIO1               (1)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO1               ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO1               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO1               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO1(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO1)) & (BFM_GPIO_INTRPT0SET_GPIO1))
#define BFX_GPIO_INTRPT0SET_GPIO1(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO1)) >> (BFP_GPIO_INTRPT0SET_GPIO1))
#define BFW_GPIO_INTRPT0SET_GPIO1(v)            (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO1)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO1)) & (BFM_GPIO_INTRPT0SET_GPIO1)) ))
#define BFR_GPIO_INTRPT0SET_GPIO1()             ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO1))>>(BFP_GPIO_INTRPT0SET_GPIO1))

#define BFP_GPIO_INTRPT0SET_GPIO0               (0)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT0SET_GPIO0               ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_INTRPT0SET_GPIO0               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT0SET_GPIO0               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT0SET_GPIO0(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT0SET_GPIO0)) & (BFM_GPIO_INTRPT0SET_GPIO0))
#define BFX_GPIO_INTRPT0SET_GPIO0(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT0SET_GPIO0)) >> (BFP_GPIO_INTRPT0SET_GPIO0))
#define BFW_GPIO_INTRPT0SET_GPIO0(v)            (REG_GPIO_INTRPT0SET.U32 = ( (REG_GPIO_INTRPT0SET.U32 & ~(BFM_GPIO_INTRPT0SET_GPIO0)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT0SET_GPIO0)) & (BFM_GPIO_INTRPT0SET_GPIO0)) ))
#define BFR_GPIO_INTRPT0SET_GPIO0()             ((REG_GPIO_INTRPT0SET.U32 & (BFM_GPIO_INTRPT0SET_GPIO0))>>(BFP_GPIO_INTRPT0SET_GPIO0))


// *****************************************************************************
//                                                                             *
//  GPIO_INTRPT1EN - GPIO Interrupt Registers 49-32                            *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_18                    : 14;
        unsigned GPIO49                     :  1;
        unsigned GPIO48                     :  1;
        unsigned GPIO47                     :  1;
        unsigned GPIO46                     :  1;
        unsigned GPIO45                     :  1;
        unsigned GPIO44                     :  1;
        unsigned GPIO43                     :  1;
        unsigned GPIO42                     :  1;
        unsigned GPIO41                     :  1;
        unsigned GPIO40                     :  1;
        unsigned GPIO39                     :  1;
        unsigned GPIO38                     :  1;
        unsigned GPIO37                     :  1;
        unsigned GPIO36                     :  1;
        unsigned GPIO35                     :  1;
        unsigned GPIO34                     :  1;
        unsigned GPIO33                     :  1;
        unsigned GPIO32                     :  1;
    } B;
} reg_gpio_intrpt1en_t;

#define REG_GPIO_INTRPT1EN_ADDR                 (REG_GPIO_BASEADDR + 0x00000210UL)
#define REG_GPIO_INTRPT1EN                      (*(volatile reg_gpio_intrpt1en_t *) REG_GPIO_INTRPT1EN_ADDR)
#define REG_GPIO_INTRPT1EN_RD()                 (REG_GPIO_INTRPT1EN.U32)
#define REG_GPIO_INTRPT1EN_WR(v)                (REG_GPIO_INTRPT1EN.U32 = (v))
#define REG_GPIO_INTRPT1EN_CLR(m)               (REG_GPIO_INTRPT1EN.U32 = ((REG_GPIO_INTRPT1EN.U32) & ~(m)))
#define REG_GPIO_INTRPT1EN_SET(m)               (REG_GPIO_INTRPT1EN.U32 = ((REG_GPIO_INTRPT1EN.U32) | (m)))
#define REG_GPIO_INTRPT1EN_DEF                  0x00000000

#define BFP_GPIO_INTRPT1EN_RSVD_18              (18)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_RSVD_18              ((uint32_t)0xfffc0000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_RSVD_18              (14)                    /* bitfield width */
#define BFD_GPIO_INTRPT1EN_RSVD_18              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_RSVD_18(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_RSVD_18)) & (BFM_GPIO_INTRPT1EN_RSVD_18))
#define BFX_GPIO_INTRPT1EN_RSVD_18(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_RSVD_18)) >> (BFP_GPIO_INTRPT1EN_RSVD_18))
#define BFW_GPIO_INTRPT1EN_RSVD_18(v)           (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_RSVD_18)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_RSVD_18)) & (BFM_GPIO_INTRPT1EN_RSVD_18)) ))
#define BFR_GPIO_INTRPT1EN_RSVD_18()            ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_RSVD_18))>>(BFP_GPIO_INTRPT1EN_RSVD_18))

#define BFP_GPIO_INTRPT1EN_GPIO49               (17)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO49               ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO49               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO49               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO49(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO49)) & (BFM_GPIO_INTRPT1EN_GPIO49))
#define BFX_GPIO_INTRPT1EN_GPIO49(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO49)) >> (BFP_GPIO_INTRPT1EN_GPIO49))
#define BFW_GPIO_INTRPT1EN_GPIO49(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO49)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO49)) & (BFM_GPIO_INTRPT1EN_GPIO49)) ))
#define BFR_GPIO_INTRPT1EN_GPIO49()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO49))>>(BFP_GPIO_INTRPT1EN_GPIO49))

#define BFP_GPIO_INTRPT1EN_GPIO48               (16)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO48               ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO48               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO48               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO48(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO48)) & (BFM_GPIO_INTRPT1EN_GPIO48))
#define BFX_GPIO_INTRPT1EN_GPIO48(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO48)) >> (BFP_GPIO_INTRPT1EN_GPIO48))
#define BFW_GPIO_INTRPT1EN_GPIO48(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO48)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO48)) & (BFM_GPIO_INTRPT1EN_GPIO48)) ))
#define BFR_GPIO_INTRPT1EN_GPIO48()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO48))>>(BFP_GPIO_INTRPT1EN_GPIO48))

#define BFP_GPIO_INTRPT1EN_GPIO47               (15)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO47               ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO47               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO47               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO47(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO47)) & (BFM_GPIO_INTRPT1EN_GPIO47))
#define BFX_GPIO_INTRPT1EN_GPIO47(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO47)) >> (BFP_GPIO_INTRPT1EN_GPIO47))
#define BFW_GPIO_INTRPT1EN_GPIO47(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO47)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO47)) & (BFM_GPIO_INTRPT1EN_GPIO47)) ))
#define BFR_GPIO_INTRPT1EN_GPIO47()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO47))>>(BFP_GPIO_INTRPT1EN_GPIO47))

#define BFP_GPIO_INTRPT1EN_GPIO46               (14)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO46               ((uint32_t)0x00004000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO46               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO46               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO46(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO46)) & (BFM_GPIO_INTRPT1EN_GPIO46))
#define BFX_GPIO_INTRPT1EN_GPIO46(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO46)) >> (BFP_GPIO_INTRPT1EN_GPIO46))
#define BFW_GPIO_INTRPT1EN_GPIO46(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO46)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO46)) & (BFM_GPIO_INTRPT1EN_GPIO46)) ))
#define BFR_GPIO_INTRPT1EN_GPIO46()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO46))>>(BFP_GPIO_INTRPT1EN_GPIO46))

#define BFP_GPIO_INTRPT1EN_GPIO45               (13)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO45               ((uint32_t)0x00002000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO45               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO45               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO45(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO45)) & (BFM_GPIO_INTRPT1EN_GPIO45))
#define BFX_GPIO_INTRPT1EN_GPIO45(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO45)) >> (BFP_GPIO_INTRPT1EN_GPIO45))
#define BFW_GPIO_INTRPT1EN_GPIO45(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO45)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO45)) & (BFM_GPIO_INTRPT1EN_GPIO45)) ))
#define BFR_GPIO_INTRPT1EN_GPIO45()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO45))>>(BFP_GPIO_INTRPT1EN_GPIO45))

#define BFP_GPIO_INTRPT1EN_GPIO44               (12)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO44               ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO44               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO44               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO44(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO44)) & (BFM_GPIO_INTRPT1EN_GPIO44))
#define BFX_GPIO_INTRPT1EN_GPIO44(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO44)) >> (BFP_GPIO_INTRPT1EN_GPIO44))
#define BFW_GPIO_INTRPT1EN_GPIO44(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO44)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO44)) & (BFM_GPIO_INTRPT1EN_GPIO44)) ))
#define BFR_GPIO_INTRPT1EN_GPIO44()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO44))>>(BFP_GPIO_INTRPT1EN_GPIO44))

#define BFP_GPIO_INTRPT1EN_GPIO43               (11)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO43               ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO43               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO43               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO43(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO43)) & (BFM_GPIO_INTRPT1EN_GPIO43))
#define BFX_GPIO_INTRPT1EN_GPIO43(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO43)) >> (BFP_GPIO_INTRPT1EN_GPIO43))
#define BFW_GPIO_INTRPT1EN_GPIO43(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO43)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO43)) & (BFM_GPIO_INTRPT1EN_GPIO43)) ))
#define BFR_GPIO_INTRPT1EN_GPIO43()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO43))>>(BFP_GPIO_INTRPT1EN_GPIO43))

#define BFP_GPIO_INTRPT1EN_GPIO42               (10)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO42               ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO42               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO42               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO42(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO42)) & (BFM_GPIO_INTRPT1EN_GPIO42))
#define BFX_GPIO_INTRPT1EN_GPIO42(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO42)) >> (BFP_GPIO_INTRPT1EN_GPIO42))
#define BFW_GPIO_INTRPT1EN_GPIO42(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO42)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO42)) & (BFM_GPIO_INTRPT1EN_GPIO42)) ))
#define BFR_GPIO_INTRPT1EN_GPIO42()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO42))>>(BFP_GPIO_INTRPT1EN_GPIO42))

#define BFP_GPIO_INTRPT1EN_GPIO41               (9)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO41               ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO41               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO41               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO41(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO41)) & (BFM_GPIO_INTRPT1EN_GPIO41))
#define BFX_GPIO_INTRPT1EN_GPIO41(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO41)) >> (BFP_GPIO_INTRPT1EN_GPIO41))
#define BFW_GPIO_INTRPT1EN_GPIO41(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO41)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO41)) & (BFM_GPIO_INTRPT1EN_GPIO41)) ))
#define BFR_GPIO_INTRPT1EN_GPIO41()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO41))>>(BFP_GPIO_INTRPT1EN_GPIO41))

#define BFP_GPIO_INTRPT1EN_GPIO40               (8)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO40               ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO40               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO40               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO40(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO40)) & (BFM_GPIO_INTRPT1EN_GPIO40))
#define BFX_GPIO_INTRPT1EN_GPIO40(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO40)) >> (BFP_GPIO_INTRPT1EN_GPIO40))
#define BFW_GPIO_INTRPT1EN_GPIO40(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO40)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO40)) & (BFM_GPIO_INTRPT1EN_GPIO40)) ))
#define BFR_GPIO_INTRPT1EN_GPIO40()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO40))>>(BFP_GPIO_INTRPT1EN_GPIO40))

#define BFP_GPIO_INTRPT1EN_GPIO39               (7)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO39               ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO39               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO39               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO39(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO39)) & (BFM_GPIO_INTRPT1EN_GPIO39))
#define BFX_GPIO_INTRPT1EN_GPIO39(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO39)) >> (BFP_GPIO_INTRPT1EN_GPIO39))
#define BFW_GPIO_INTRPT1EN_GPIO39(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO39)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO39)) & (BFM_GPIO_INTRPT1EN_GPIO39)) ))
#define BFR_GPIO_INTRPT1EN_GPIO39()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO39))>>(BFP_GPIO_INTRPT1EN_GPIO39))

#define BFP_GPIO_INTRPT1EN_GPIO38               (6)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO38               ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO38               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO38               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO38(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO38)) & (BFM_GPIO_INTRPT1EN_GPIO38))
#define BFX_GPIO_INTRPT1EN_GPIO38(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO38)) >> (BFP_GPIO_INTRPT1EN_GPIO38))
#define BFW_GPIO_INTRPT1EN_GPIO38(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO38)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO38)) & (BFM_GPIO_INTRPT1EN_GPIO38)) ))
#define BFR_GPIO_INTRPT1EN_GPIO38()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO38))>>(BFP_GPIO_INTRPT1EN_GPIO38))

#define BFP_GPIO_INTRPT1EN_GPIO37               (5)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO37               ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO37               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO37               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO37(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO37)) & (BFM_GPIO_INTRPT1EN_GPIO37))
#define BFX_GPIO_INTRPT1EN_GPIO37(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO37)) >> (BFP_GPIO_INTRPT1EN_GPIO37))
#define BFW_GPIO_INTRPT1EN_GPIO37(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO37)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO37)) & (BFM_GPIO_INTRPT1EN_GPIO37)) ))
#define BFR_GPIO_INTRPT1EN_GPIO37()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO37))>>(BFP_GPIO_INTRPT1EN_GPIO37))

#define BFP_GPIO_INTRPT1EN_GPIO36               (4)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO36               ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO36               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO36               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO36(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO36)) & (BFM_GPIO_INTRPT1EN_GPIO36))
#define BFX_GPIO_INTRPT1EN_GPIO36(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO36)) >> (BFP_GPIO_INTRPT1EN_GPIO36))
#define BFW_GPIO_INTRPT1EN_GPIO36(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO36)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO36)) & (BFM_GPIO_INTRPT1EN_GPIO36)) ))
#define BFR_GPIO_INTRPT1EN_GPIO36()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO36))>>(BFP_GPIO_INTRPT1EN_GPIO36))

#define BFP_GPIO_INTRPT1EN_GPIO35               (3)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO35               ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO35               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO35               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO35(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO35)) & (BFM_GPIO_INTRPT1EN_GPIO35))
#define BFX_GPIO_INTRPT1EN_GPIO35(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO35)) >> (BFP_GPIO_INTRPT1EN_GPIO35))
#define BFW_GPIO_INTRPT1EN_GPIO35(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO35)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO35)) & (BFM_GPIO_INTRPT1EN_GPIO35)) ))
#define BFR_GPIO_INTRPT1EN_GPIO35()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO35))>>(BFP_GPIO_INTRPT1EN_GPIO35))

#define BFP_GPIO_INTRPT1EN_GPIO34               (2)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO34               ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO34               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO34               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO34(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO34)) & (BFM_GPIO_INTRPT1EN_GPIO34))
#define BFX_GPIO_INTRPT1EN_GPIO34(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO34)) >> (BFP_GPIO_INTRPT1EN_GPIO34))
#define BFW_GPIO_INTRPT1EN_GPIO34(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO34)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO34)) & (BFM_GPIO_INTRPT1EN_GPIO34)) ))
#define BFR_GPIO_INTRPT1EN_GPIO34()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO34))>>(BFP_GPIO_INTRPT1EN_GPIO34))

#define BFP_GPIO_INTRPT1EN_GPIO33               (1)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO33               ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO33               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO33               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO33(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO33)) & (BFM_GPIO_INTRPT1EN_GPIO33))
#define BFX_GPIO_INTRPT1EN_GPIO33(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO33)) >> (BFP_GPIO_INTRPT1EN_GPIO33))
#define BFW_GPIO_INTRPT1EN_GPIO33(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO33)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO33)) & (BFM_GPIO_INTRPT1EN_GPIO33)) ))
#define BFR_GPIO_INTRPT1EN_GPIO33()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO33))>>(BFP_GPIO_INTRPT1EN_GPIO33))

#define BFP_GPIO_INTRPT1EN_GPIO32               (0)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1EN_GPIO32               ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_INTRPT1EN_GPIO32               (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1EN_GPIO32               (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1EN_GPIO32(v)            ((((uint32_t) v) << (BFP_GPIO_INTRPT1EN_GPIO32)) & (BFM_GPIO_INTRPT1EN_GPIO32))
#define BFX_GPIO_INTRPT1EN_GPIO32(v)            ((((uint32_t) v) & (BFM_GPIO_INTRPT1EN_GPIO32)) >> (BFP_GPIO_INTRPT1EN_GPIO32))
#define BFW_GPIO_INTRPT1EN_GPIO32(v)            (REG_GPIO_INTRPT1EN.U32 = ( (REG_GPIO_INTRPT1EN.U32 & ~(BFM_GPIO_INTRPT1EN_GPIO32)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1EN_GPIO32)) & (BFM_GPIO_INTRPT1EN_GPIO32)) ))
#define BFR_GPIO_INTRPT1EN_GPIO32()             ((REG_GPIO_INTRPT1EN.U32 & (BFM_GPIO_INTRPT1EN_GPIO32))>>(BFP_GPIO_INTRPT1EN_GPIO32))


// *****************************************************************************
//                                                                             *
//  GPIO_INTRPT1STAT - GPIO Interrupt Registers 49-32                          *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_18                    : 14;
        unsigned GPIO49                     :  1;
        unsigned GPIO48                     :  1;
        unsigned GPIO47                     :  1;
        unsigned GPIO46                     :  1;
        unsigned GPIO45                     :  1;
        unsigned GPIO44                     :  1;
        unsigned GPIO43                     :  1;
        unsigned GPIO42                     :  1;
        unsigned GPIO41                     :  1;
        unsigned GPIO40                     :  1;
        unsigned GPIO39                     :  1;
        unsigned GPIO38                     :  1;
        unsigned GPIO37                     :  1;
        unsigned GPIO36                     :  1;
        unsigned GPIO35                     :  1;
        unsigned GPIO34                     :  1;
        unsigned GPIO33                     :  1;
        unsigned GPIO32                     :  1;
    } B;
} reg_gpio_intrpt1stat_t;

#define REG_GPIO_INTRPT1STAT_ADDR               (REG_GPIO_BASEADDR + 0x00000214UL)
#define REG_GPIO_INTRPT1STAT                    (*(volatile reg_gpio_intrpt1stat_t *) REG_GPIO_INTRPT1STAT_ADDR)
#define REG_GPIO_INTRPT1STAT_RD()               (REG_GPIO_INTRPT1STAT.U32)
#define REG_GPIO_INTRPT1STAT_WR(v)              (REG_GPIO_INTRPT1STAT.U32 = (v))
#define REG_GPIO_INTRPT1STAT_CLR(m)             (REG_GPIO_INTRPT1STAT.U32 = ((REG_GPIO_INTRPT1STAT.U32) & ~(m)))
#define REG_GPIO_INTRPT1STAT_SET(m)             (REG_GPIO_INTRPT1STAT.U32 = ((REG_GPIO_INTRPT1STAT.U32) | (m)))
#define REG_GPIO_INTRPT1STAT_DEF                0x00000000

#define BFP_GPIO_INTRPT1STAT_RSVD_18            (18)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_RSVD_18            ((uint32_t)0xfffc0000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_RSVD_18            (14)                    /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_RSVD_18            (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_RSVD_18(v)         ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_RSVD_18)) & (BFM_GPIO_INTRPT1STAT_RSVD_18))
#define BFX_GPIO_INTRPT1STAT_RSVD_18(v)         ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_RSVD_18)) >> (BFP_GPIO_INTRPT1STAT_RSVD_18))
#define BFW_GPIO_INTRPT1STAT_RSVD_18(v)         (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_RSVD_18)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_RSVD_18)) & (BFM_GPIO_INTRPT1STAT_RSVD_18)) ))
#define BFR_GPIO_INTRPT1STAT_RSVD_18()          ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_RSVD_18))>>(BFP_GPIO_INTRPT1STAT_RSVD_18))

#define BFP_GPIO_INTRPT1STAT_GPIO49             (17)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO49             ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO49             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO49             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO49(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO49)) & (BFM_GPIO_INTRPT1STAT_GPIO49))
#define BFX_GPIO_INTRPT1STAT_GPIO49(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO49)) >> (BFP_GPIO_INTRPT1STAT_GPIO49))
#define BFW_GPIO_INTRPT1STAT_GPIO49(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO49)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO49)) & (BFM_GPIO_INTRPT1STAT_GPIO49)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO49()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO49))>>(BFP_GPIO_INTRPT1STAT_GPIO49))

#define BFP_GPIO_INTRPT1STAT_GPIO48             (16)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO48             ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO48             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO48             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO48(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO48)) & (BFM_GPIO_INTRPT1STAT_GPIO48))
#define BFX_GPIO_INTRPT1STAT_GPIO48(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO48)) >> (BFP_GPIO_INTRPT1STAT_GPIO48))
#define BFW_GPIO_INTRPT1STAT_GPIO48(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO48)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO48)) & (BFM_GPIO_INTRPT1STAT_GPIO48)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO48()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO48))>>(BFP_GPIO_INTRPT1STAT_GPIO48))

#define BFP_GPIO_INTRPT1STAT_GPIO47             (15)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO47             ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO47             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO47             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO47(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO47)) & (BFM_GPIO_INTRPT1STAT_GPIO47))
#define BFX_GPIO_INTRPT1STAT_GPIO47(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO47)) >> (BFP_GPIO_INTRPT1STAT_GPIO47))
#define BFW_GPIO_INTRPT1STAT_GPIO47(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO47)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO47)) & (BFM_GPIO_INTRPT1STAT_GPIO47)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO47()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO47))>>(BFP_GPIO_INTRPT1STAT_GPIO47))

#define BFP_GPIO_INTRPT1STAT_GPIO46             (14)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO46             ((uint32_t)0x00004000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO46             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO46             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO46(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO46)) & (BFM_GPIO_INTRPT1STAT_GPIO46))
#define BFX_GPIO_INTRPT1STAT_GPIO46(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO46)) >> (BFP_GPIO_INTRPT1STAT_GPIO46))
#define BFW_GPIO_INTRPT1STAT_GPIO46(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO46)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO46)) & (BFM_GPIO_INTRPT1STAT_GPIO46)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO46()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO46))>>(BFP_GPIO_INTRPT1STAT_GPIO46))

#define BFP_GPIO_INTRPT1STAT_GPIO45             (13)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO45             ((uint32_t)0x00002000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO45             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO45             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO45(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO45)) & (BFM_GPIO_INTRPT1STAT_GPIO45))
#define BFX_GPIO_INTRPT1STAT_GPIO45(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO45)) >> (BFP_GPIO_INTRPT1STAT_GPIO45))
#define BFW_GPIO_INTRPT1STAT_GPIO45(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO45)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO45)) & (BFM_GPIO_INTRPT1STAT_GPIO45)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO45()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO45))>>(BFP_GPIO_INTRPT1STAT_GPIO45))

#define BFP_GPIO_INTRPT1STAT_GPIO44             (12)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO44             ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO44             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO44             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO44(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO44)) & (BFM_GPIO_INTRPT1STAT_GPIO44))
#define BFX_GPIO_INTRPT1STAT_GPIO44(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO44)) >> (BFP_GPIO_INTRPT1STAT_GPIO44))
#define BFW_GPIO_INTRPT1STAT_GPIO44(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO44)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO44)) & (BFM_GPIO_INTRPT1STAT_GPIO44)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO44()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO44))>>(BFP_GPIO_INTRPT1STAT_GPIO44))

#define BFP_GPIO_INTRPT1STAT_GPIO43             (11)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO43             ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO43             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO43             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO43(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO43)) & (BFM_GPIO_INTRPT1STAT_GPIO43))
#define BFX_GPIO_INTRPT1STAT_GPIO43(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO43)) >> (BFP_GPIO_INTRPT1STAT_GPIO43))
#define BFW_GPIO_INTRPT1STAT_GPIO43(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO43)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO43)) & (BFM_GPIO_INTRPT1STAT_GPIO43)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO43()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO43))>>(BFP_GPIO_INTRPT1STAT_GPIO43))

#define BFP_GPIO_INTRPT1STAT_GPIO42             (10)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO42             ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO42             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO42             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO42(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO42)) & (BFM_GPIO_INTRPT1STAT_GPIO42))
#define BFX_GPIO_INTRPT1STAT_GPIO42(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO42)) >> (BFP_GPIO_INTRPT1STAT_GPIO42))
#define BFW_GPIO_INTRPT1STAT_GPIO42(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO42)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO42)) & (BFM_GPIO_INTRPT1STAT_GPIO42)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO42()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO42))>>(BFP_GPIO_INTRPT1STAT_GPIO42))

#define BFP_GPIO_INTRPT1STAT_GPIO41             (9)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO41             ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO41             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO41             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO41(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO41)) & (BFM_GPIO_INTRPT1STAT_GPIO41))
#define BFX_GPIO_INTRPT1STAT_GPIO41(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO41)) >> (BFP_GPIO_INTRPT1STAT_GPIO41))
#define BFW_GPIO_INTRPT1STAT_GPIO41(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO41)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO41)) & (BFM_GPIO_INTRPT1STAT_GPIO41)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO41()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO41))>>(BFP_GPIO_INTRPT1STAT_GPIO41))

#define BFP_GPIO_INTRPT1STAT_GPIO40             (8)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO40             ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO40             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO40             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO40(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO40)) & (BFM_GPIO_INTRPT1STAT_GPIO40))
#define BFX_GPIO_INTRPT1STAT_GPIO40(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO40)) >> (BFP_GPIO_INTRPT1STAT_GPIO40))
#define BFW_GPIO_INTRPT1STAT_GPIO40(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO40)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO40)) & (BFM_GPIO_INTRPT1STAT_GPIO40)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO40()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO40))>>(BFP_GPIO_INTRPT1STAT_GPIO40))

#define BFP_GPIO_INTRPT1STAT_GPIO39             (7)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO39             ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO39             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO39             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO39(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO39)) & (BFM_GPIO_INTRPT1STAT_GPIO39))
#define BFX_GPIO_INTRPT1STAT_GPIO39(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO39)) >> (BFP_GPIO_INTRPT1STAT_GPIO39))
#define BFW_GPIO_INTRPT1STAT_GPIO39(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO39)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO39)) & (BFM_GPIO_INTRPT1STAT_GPIO39)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO39()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO39))>>(BFP_GPIO_INTRPT1STAT_GPIO39))

#define BFP_GPIO_INTRPT1STAT_GPIO38             (6)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO38             ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO38             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO38             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO38(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO38)) & (BFM_GPIO_INTRPT1STAT_GPIO38))
#define BFX_GPIO_INTRPT1STAT_GPIO38(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO38)) >> (BFP_GPIO_INTRPT1STAT_GPIO38))
#define BFW_GPIO_INTRPT1STAT_GPIO38(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO38)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO38)) & (BFM_GPIO_INTRPT1STAT_GPIO38)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO38()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO38))>>(BFP_GPIO_INTRPT1STAT_GPIO38))

#define BFP_GPIO_INTRPT1STAT_GPIO37             (5)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO37             ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO37             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO37             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO37(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO37)) & (BFM_GPIO_INTRPT1STAT_GPIO37))
#define BFX_GPIO_INTRPT1STAT_GPIO37(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO37)) >> (BFP_GPIO_INTRPT1STAT_GPIO37))
#define BFW_GPIO_INTRPT1STAT_GPIO37(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO37)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO37)) & (BFM_GPIO_INTRPT1STAT_GPIO37)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO37()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO37))>>(BFP_GPIO_INTRPT1STAT_GPIO37))

#define BFP_GPIO_INTRPT1STAT_GPIO36             (4)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO36             ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO36             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO36             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO36(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO36)) & (BFM_GPIO_INTRPT1STAT_GPIO36))
#define BFX_GPIO_INTRPT1STAT_GPIO36(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO36)) >> (BFP_GPIO_INTRPT1STAT_GPIO36))
#define BFW_GPIO_INTRPT1STAT_GPIO36(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO36)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO36)) & (BFM_GPIO_INTRPT1STAT_GPIO36)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO36()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO36))>>(BFP_GPIO_INTRPT1STAT_GPIO36))

#define BFP_GPIO_INTRPT1STAT_GPIO35             (3)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO35             ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO35             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO35             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO35(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO35)) & (BFM_GPIO_INTRPT1STAT_GPIO35))
#define BFX_GPIO_INTRPT1STAT_GPIO35(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO35)) >> (BFP_GPIO_INTRPT1STAT_GPIO35))
#define BFW_GPIO_INTRPT1STAT_GPIO35(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO35)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO35)) & (BFM_GPIO_INTRPT1STAT_GPIO35)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO35()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO35))>>(BFP_GPIO_INTRPT1STAT_GPIO35))

#define BFP_GPIO_INTRPT1STAT_GPIO34             (2)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO34             ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO34             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO34             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO34(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO34)) & (BFM_GPIO_INTRPT1STAT_GPIO34))
#define BFX_GPIO_INTRPT1STAT_GPIO34(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO34)) >> (BFP_GPIO_INTRPT1STAT_GPIO34))
#define BFW_GPIO_INTRPT1STAT_GPIO34(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO34)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO34)) & (BFM_GPIO_INTRPT1STAT_GPIO34)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO34()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO34))>>(BFP_GPIO_INTRPT1STAT_GPIO34))

#define BFP_GPIO_INTRPT1STAT_GPIO33             (1)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO33             ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO33             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO33             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO33(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO33)) & (BFM_GPIO_INTRPT1STAT_GPIO33))
#define BFX_GPIO_INTRPT1STAT_GPIO33(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO33)) >> (BFP_GPIO_INTRPT1STAT_GPIO33))
#define BFW_GPIO_INTRPT1STAT_GPIO33(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO33)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO33)) & (BFM_GPIO_INTRPT1STAT_GPIO33)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO33()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO33))>>(BFP_GPIO_INTRPT1STAT_GPIO33))

#define BFP_GPIO_INTRPT1STAT_GPIO32             (0)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1STAT_GPIO32             ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_INTRPT1STAT_GPIO32             (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1STAT_GPIO32             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1STAT_GPIO32(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1STAT_GPIO32)) & (BFM_GPIO_INTRPT1STAT_GPIO32))
#define BFX_GPIO_INTRPT1STAT_GPIO32(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1STAT_GPIO32)) >> (BFP_GPIO_INTRPT1STAT_GPIO32))
#define BFW_GPIO_INTRPT1STAT_GPIO32(v)          (REG_GPIO_INTRPT1STAT.U32 = ( (REG_GPIO_INTRPT1STAT.U32 & ~(BFM_GPIO_INTRPT1STAT_GPIO32)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1STAT_GPIO32)) & (BFM_GPIO_INTRPT1STAT_GPIO32)) ))
#define BFR_GPIO_INTRPT1STAT_GPIO32()           ((REG_GPIO_INTRPT1STAT.U32 & (BFM_GPIO_INTRPT1STAT_GPIO32))>>(BFP_GPIO_INTRPT1STAT_GPIO32))


// *****************************************************************************
//                                                                             *
//  GPIO_INTRPT1CLR - GPIO Interrupt Registers 49-32                           *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_18                    : 14;
        unsigned GPIO49                     :  1;
        unsigned GPIO48                     :  1;
        unsigned GPIO47                     :  1;
        unsigned GPIO46                     :  1;
        unsigned GPIO45                     :  1;
        unsigned GPIO44                     :  1;
        unsigned GPIO43                     :  1;
        unsigned GPIO42                     :  1;
        unsigned GPIO41                     :  1;
        unsigned GPIO40                     :  1;
        unsigned GPIO39                     :  1;
        unsigned GPIO38                     :  1;
        unsigned GPIO37                     :  1;
        unsigned GPIO36                     :  1;
        unsigned GPIO35                     :  1;
        unsigned GPIO34                     :  1;
        unsigned GPIO33                     :  1;
        unsigned GPIO32                     :  1;
    } B;
} reg_gpio_intrpt1clr_t;

#define REG_GPIO_INTRPT1CLR_ADDR                (REG_GPIO_BASEADDR + 0x00000218UL)
#define REG_GPIO_INTRPT1CLR                     (*(volatile reg_gpio_intrpt1clr_t *) REG_GPIO_INTRPT1CLR_ADDR)
#define REG_GPIO_INTRPT1CLR_RD()                (REG_GPIO_INTRPT1CLR.U32)
#define REG_GPIO_INTRPT1CLR_WR(v)               (REG_GPIO_INTRPT1CLR.U32 = (v))
#define REG_GPIO_INTRPT1CLR_CLR(m)              (REG_GPIO_INTRPT1CLR.U32 = ((REG_GPIO_INTRPT1CLR.U32) & ~(m)))
#define REG_GPIO_INTRPT1CLR_SET(m)              (REG_GPIO_INTRPT1CLR.U32 = ((REG_GPIO_INTRPT1CLR.U32) | (m)))
#define REG_GPIO_INTRPT1CLR_DEF                 0x00000000

#define BFP_GPIO_INTRPT1CLR_RSVD_18             (18)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_RSVD_18             ((uint32_t)0xfffc0000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_RSVD_18             (14)                    /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_RSVD_18             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_RSVD_18(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_RSVD_18)) & (BFM_GPIO_INTRPT1CLR_RSVD_18))
#define BFX_GPIO_INTRPT1CLR_RSVD_18(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_RSVD_18)) >> (BFP_GPIO_INTRPT1CLR_RSVD_18))
#define BFW_GPIO_INTRPT1CLR_RSVD_18(v)          (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_RSVD_18)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_RSVD_18)) & (BFM_GPIO_INTRPT1CLR_RSVD_18)) ))
#define BFR_GPIO_INTRPT1CLR_RSVD_18()           ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_RSVD_18))>>(BFP_GPIO_INTRPT1CLR_RSVD_18))

#define BFP_GPIO_INTRPT1CLR_GPIO49              (17)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO49              ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO49              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO49              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO49(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO49)) & (BFM_GPIO_INTRPT1CLR_GPIO49))
#define BFX_GPIO_INTRPT1CLR_GPIO49(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO49)) >> (BFP_GPIO_INTRPT1CLR_GPIO49))
#define BFW_GPIO_INTRPT1CLR_GPIO49(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO49)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO49)) & (BFM_GPIO_INTRPT1CLR_GPIO49)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO49()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO49))>>(BFP_GPIO_INTRPT1CLR_GPIO49))

#define BFP_GPIO_INTRPT1CLR_GPIO48              (16)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO48              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO48              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO48              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO48(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO48)) & (BFM_GPIO_INTRPT1CLR_GPIO48))
#define BFX_GPIO_INTRPT1CLR_GPIO48(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO48)) >> (BFP_GPIO_INTRPT1CLR_GPIO48))
#define BFW_GPIO_INTRPT1CLR_GPIO48(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO48)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO48)) & (BFM_GPIO_INTRPT1CLR_GPIO48)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO48()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO48))>>(BFP_GPIO_INTRPT1CLR_GPIO48))

#define BFP_GPIO_INTRPT1CLR_GPIO47              (15)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO47              ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO47              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO47              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO47(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO47)) & (BFM_GPIO_INTRPT1CLR_GPIO47))
#define BFX_GPIO_INTRPT1CLR_GPIO47(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO47)) >> (BFP_GPIO_INTRPT1CLR_GPIO47))
#define BFW_GPIO_INTRPT1CLR_GPIO47(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO47)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO47)) & (BFM_GPIO_INTRPT1CLR_GPIO47)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO47()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO47))>>(BFP_GPIO_INTRPT1CLR_GPIO47))

#define BFP_GPIO_INTRPT1CLR_GPIO46              (14)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO46              ((uint32_t)0x00004000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO46              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO46              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO46(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO46)) & (BFM_GPIO_INTRPT1CLR_GPIO46))
#define BFX_GPIO_INTRPT1CLR_GPIO46(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO46)) >> (BFP_GPIO_INTRPT1CLR_GPIO46))
#define BFW_GPIO_INTRPT1CLR_GPIO46(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO46)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO46)) & (BFM_GPIO_INTRPT1CLR_GPIO46)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO46()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO46))>>(BFP_GPIO_INTRPT1CLR_GPIO46))

#define BFP_GPIO_INTRPT1CLR_GPIO45              (13)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO45              ((uint32_t)0x00002000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO45              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO45              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO45(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO45)) & (BFM_GPIO_INTRPT1CLR_GPIO45))
#define BFX_GPIO_INTRPT1CLR_GPIO45(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO45)) >> (BFP_GPIO_INTRPT1CLR_GPIO45))
#define BFW_GPIO_INTRPT1CLR_GPIO45(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO45)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO45)) & (BFM_GPIO_INTRPT1CLR_GPIO45)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO45()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO45))>>(BFP_GPIO_INTRPT1CLR_GPIO45))

#define BFP_GPIO_INTRPT1CLR_GPIO44              (12)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO44              ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO44              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO44              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO44(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO44)) & (BFM_GPIO_INTRPT1CLR_GPIO44))
#define BFX_GPIO_INTRPT1CLR_GPIO44(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO44)) >> (BFP_GPIO_INTRPT1CLR_GPIO44))
#define BFW_GPIO_INTRPT1CLR_GPIO44(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO44)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO44)) & (BFM_GPIO_INTRPT1CLR_GPIO44)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO44()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO44))>>(BFP_GPIO_INTRPT1CLR_GPIO44))

#define BFP_GPIO_INTRPT1CLR_GPIO43              (11)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO43              ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO43              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO43              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO43(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO43)) & (BFM_GPIO_INTRPT1CLR_GPIO43))
#define BFX_GPIO_INTRPT1CLR_GPIO43(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO43)) >> (BFP_GPIO_INTRPT1CLR_GPIO43))
#define BFW_GPIO_INTRPT1CLR_GPIO43(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO43)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO43)) & (BFM_GPIO_INTRPT1CLR_GPIO43)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO43()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO43))>>(BFP_GPIO_INTRPT1CLR_GPIO43))

#define BFP_GPIO_INTRPT1CLR_GPIO42              (10)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO42              ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO42              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO42              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO42(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO42)) & (BFM_GPIO_INTRPT1CLR_GPIO42))
#define BFX_GPIO_INTRPT1CLR_GPIO42(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO42)) >> (BFP_GPIO_INTRPT1CLR_GPIO42))
#define BFW_GPIO_INTRPT1CLR_GPIO42(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO42)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO42)) & (BFM_GPIO_INTRPT1CLR_GPIO42)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO42()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO42))>>(BFP_GPIO_INTRPT1CLR_GPIO42))

#define BFP_GPIO_INTRPT1CLR_GPIO41              (9)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO41              ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO41              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO41              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO41(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO41)) & (BFM_GPIO_INTRPT1CLR_GPIO41))
#define BFX_GPIO_INTRPT1CLR_GPIO41(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO41)) >> (BFP_GPIO_INTRPT1CLR_GPIO41))
#define BFW_GPIO_INTRPT1CLR_GPIO41(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO41)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO41)) & (BFM_GPIO_INTRPT1CLR_GPIO41)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO41()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO41))>>(BFP_GPIO_INTRPT1CLR_GPIO41))

#define BFP_GPIO_INTRPT1CLR_GPIO40              (8)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO40              ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO40              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO40              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO40(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO40)) & (BFM_GPIO_INTRPT1CLR_GPIO40))
#define BFX_GPIO_INTRPT1CLR_GPIO40(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO40)) >> (BFP_GPIO_INTRPT1CLR_GPIO40))
#define BFW_GPIO_INTRPT1CLR_GPIO40(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO40)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO40)) & (BFM_GPIO_INTRPT1CLR_GPIO40)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO40()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO40))>>(BFP_GPIO_INTRPT1CLR_GPIO40))

#define BFP_GPIO_INTRPT1CLR_GPIO39              (7)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO39              ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO39              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO39              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO39(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO39)) & (BFM_GPIO_INTRPT1CLR_GPIO39))
#define BFX_GPIO_INTRPT1CLR_GPIO39(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO39)) >> (BFP_GPIO_INTRPT1CLR_GPIO39))
#define BFW_GPIO_INTRPT1CLR_GPIO39(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO39)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO39)) & (BFM_GPIO_INTRPT1CLR_GPIO39)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO39()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO39))>>(BFP_GPIO_INTRPT1CLR_GPIO39))

#define BFP_GPIO_INTRPT1CLR_GPIO38              (6)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO38              ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO38              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO38              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO38(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO38)) & (BFM_GPIO_INTRPT1CLR_GPIO38))
#define BFX_GPIO_INTRPT1CLR_GPIO38(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO38)) >> (BFP_GPIO_INTRPT1CLR_GPIO38))
#define BFW_GPIO_INTRPT1CLR_GPIO38(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO38)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO38)) & (BFM_GPIO_INTRPT1CLR_GPIO38)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO38()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO38))>>(BFP_GPIO_INTRPT1CLR_GPIO38))

#define BFP_GPIO_INTRPT1CLR_GPIO37              (5)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO37              ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO37              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO37              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO37(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO37)) & (BFM_GPIO_INTRPT1CLR_GPIO37))
#define BFX_GPIO_INTRPT1CLR_GPIO37(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO37)) >> (BFP_GPIO_INTRPT1CLR_GPIO37))
#define BFW_GPIO_INTRPT1CLR_GPIO37(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO37)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO37)) & (BFM_GPIO_INTRPT1CLR_GPIO37)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO37()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO37))>>(BFP_GPIO_INTRPT1CLR_GPIO37))

#define BFP_GPIO_INTRPT1CLR_GPIO36              (4)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO36              ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO36              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO36              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO36(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO36)) & (BFM_GPIO_INTRPT1CLR_GPIO36))
#define BFX_GPIO_INTRPT1CLR_GPIO36(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO36)) >> (BFP_GPIO_INTRPT1CLR_GPIO36))
#define BFW_GPIO_INTRPT1CLR_GPIO36(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO36)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO36)) & (BFM_GPIO_INTRPT1CLR_GPIO36)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO36()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO36))>>(BFP_GPIO_INTRPT1CLR_GPIO36))

#define BFP_GPIO_INTRPT1CLR_GPIO35              (3)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO35              ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO35              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO35              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO35(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO35)) & (BFM_GPIO_INTRPT1CLR_GPIO35))
#define BFX_GPIO_INTRPT1CLR_GPIO35(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO35)) >> (BFP_GPIO_INTRPT1CLR_GPIO35))
#define BFW_GPIO_INTRPT1CLR_GPIO35(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO35)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO35)) & (BFM_GPIO_INTRPT1CLR_GPIO35)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO35()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO35))>>(BFP_GPIO_INTRPT1CLR_GPIO35))

#define BFP_GPIO_INTRPT1CLR_GPIO34              (2)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO34              ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO34              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO34              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO34(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO34)) & (BFM_GPIO_INTRPT1CLR_GPIO34))
#define BFX_GPIO_INTRPT1CLR_GPIO34(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO34)) >> (BFP_GPIO_INTRPT1CLR_GPIO34))
#define BFW_GPIO_INTRPT1CLR_GPIO34(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO34)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO34)) & (BFM_GPIO_INTRPT1CLR_GPIO34)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO34()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO34))>>(BFP_GPIO_INTRPT1CLR_GPIO34))

#define BFP_GPIO_INTRPT1CLR_GPIO33              (1)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO33              ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO33              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO33              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO33(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO33)) & (BFM_GPIO_INTRPT1CLR_GPIO33))
#define BFX_GPIO_INTRPT1CLR_GPIO33(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO33)) >> (BFP_GPIO_INTRPT1CLR_GPIO33))
#define BFW_GPIO_INTRPT1CLR_GPIO33(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO33)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO33)) & (BFM_GPIO_INTRPT1CLR_GPIO33)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO33()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO33))>>(BFP_GPIO_INTRPT1CLR_GPIO33))

#define BFP_GPIO_INTRPT1CLR_GPIO32              (0)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1CLR_GPIO32              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_INTRPT1CLR_GPIO32              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1CLR_GPIO32              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1CLR_GPIO32(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1CLR_GPIO32)) & (BFM_GPIO_INTRPT1CLR_GPIO32))
#define BFX_GPIO_INTRPT1CLR_GPIO32(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1CLR_GPIO32)) >> (BFP_GPIO_INTRPT1CLR_GPIO32))
#define BFW_GPIO_INTRPT1CLR_GPIO32(v)           (REG_GPIO_INTRPT1CLR.U32 = ( (REG_GPIO_INTRPT1CLR.U32 & ~(BFM_GPIO_INTRPT1CLR_GPIO32)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1CLR_GPIO32)) & (BFM_GPIO_INTRPT1CLR_GPIO32)) ))
#define BFR_GPIO_INTRPT1CLR_GPIO32()            ((REG_GPIO_INTRPT1CLR.U32 & (BFM_GPIO_INTRPT1CLR_GPIO32))>>(BFP_GPIO_INTRPT1CLR_GPIO32))


// *****************************************************************************
//                                                                             *
//  GPIO_INTRPT1SET - GPIO Interrupt Registers 49-32                           *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_18                    : 14;
        unsigned GPIO49                     :  1;
        unsigned GPIO48                     :  1;
        unsigned GPIO47                     :  1;
        unsigned GPIO46                     :  1;
        unsigned GPIO45                     :  1;
        unsigned GPIO44                     :  1;
        unsigned GPIO43                     :  1;
        unsigned GPIO42                     :  1;
        unsigned GPIO41                     :  1;
        unsigned GPIO40                     :  1;
        unsigned GPIO39                     :  1;
        unsigned GPIO38                     :  1;
        unsigned GPIO37                     :  1;
        unsigned GPIO36                     :  1;
        unsigned GPIO35                     :  1;
        unsigned GPIO34                     :  1;
        unsigned GPIO33                     :  1;
        unsigned GPIO32                     :  1;
    } B;
} reg_gpio_intrpt1set_t;

#define REG_GPIO_INTRPT1SET_ADDR                (REG_GPIO_BASEADDR + 0x0000021CUL)
#define REG_GPIO_INTRPT1SET                     (*(volatile reg_gpio_intrpt1set_t *) REG_GPIO_INTRPT1SET_ADDR)
#define REG_GPIO_INTRPT1SET_RD()                (REG_GPIO_INTRPT1SET.U32)
#define REG_GPIO_INTRPT1SET_WR(v)               (REG_GPIO_INTRPT1SET.U32 = (v))
#define REG_GPIO_INTRPT1SET_CLR(m)              (REG_GPIO_INTRPT1SET.U32 = ((REG_GPIO_INTRPT1SET.U32) & ~(m)))
#define REG_GPIO_INTRPT1SET_SET(m)              (REG_GPIO_INTRPT1SET.U32 = ((REG_GPIO_INTRPT1SET.U32) | (m)))
#define REG_GPIO_INTRPT1SET_DEF                 0x00000000

#define BFP_GPIO_INTRPT1SET_RSVD_18             (18)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_RSVD_18             ((uint32_t)0xfffc0000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_RSVD_18             (14)                    /* bitfield width */
#define BFD_GPIO_INTRPT1SET_RSVD_18             (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_RSVD_18(v)          ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_RSVD_18)) & (BFM_GPIO_INTRPT1SET_RSVD_18))
#define BFX_GPIO_INTRPT1SET_RSVD_18(v)          ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_RSVD_18)) >> (BFP_GPIO_INTRPT1SET_RSVD_18))
#define BFW_GPIO_INTRPT1SET_RSVD_18(v)          (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_RSVD_18)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_RSVD_18)) & (BFM_GPIO_INTRPT1SET_RSVD_18)) ))
#define BFR_GPIO_INTRPT1SET_RSVD_18()           ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_RSVD_18))>>(BFP_GPIO_INTRPT1SET_RSVD_18))

#define BFP_GPIO_INTRPT1SET_GPIO49              (17)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO49              ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO49              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO49              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO49(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO49)) & (BFM_GPIO_INTRPT1SET_GPIO49))
#define BFX_GPIO_INTRPT1SET_GPIO49(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO49)) >> (BFP_GPIO_INTRPT1SET_GPIO49))
#define BFW_GPIO_INTRPT1SET_GPIO49(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO49)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO49)) & (BFM_GPIO_INTRPT1SET_GPIO49)) ))
#define BFR_GPIO_INTRPT1SET_GPIO49()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO49))>>(BFP_GPIO_INTRPT1SET_GPIO49))

#define BFP_GPIO_INTRPT1SET_GPIO48              (16)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO48              ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO48              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO48              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO48(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO48)) & (BFM_GPIO_INTRPT1SET_GPIO48))
#define BFX_GPIO_INTRPT1SET_GPIO48(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO48)) >> (BFP_GPIO_INTRPT1SET_GPIO48))
#define BFW_GPIO_INTRPT1SET_GPIO48(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO48)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO48)) & (BFM_GPIO_INTRPT1SET_GPIO48)) ))
#define BFR_GPIO_INTRPT1SET_GPIO48()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO48))>>(BFP_GPIO_INTRPT1SET_GPIO48))

#define BFP_GPIO_INTRPT1SET_GPIO47              (15)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO47              ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO47              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO47              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO47(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO47)) & (BFM_GPIO_INTRPT1SET_GPIO47))
#define BFX_GPIO_INTRPT1SET_GPIO47(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO47)) >> (BFP_GPIO_INTRPT1SET_GPIO47))
#define BFW_GPIO_INTRPT1SET_GPIO47(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO47)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO47)) & (BFM_GPIO_INTRPT1SET_GPIO47)) ))
#define BFR_GPIO_INTRPT1SET_GPIO47()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO47))>>(BFP_GPIO_INTRPT1SET_GPIO47))

#define BFP_GPIO_INTRPT1SET_GPIO46              (14)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO46              ((uint32_t)0x00004000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO46              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO46              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO46(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO46)) & (BFM_GPIO_INTRPT1SET_GPIO46))
#define BFX_GPIO_INTRPT1SET_GPIO46(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO46)) >> (BFP_GPIO_INTRPT1SET_GPIO46))
#define BFW_GPIO_INTRPT1SET_GPIO46(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO46)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO46)) & (BFM_GPIO_INTRPT1SET_GPIO46)) ))
#define BFR_GPIO_INTRPT1SET_GPIO46()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO46))>>(BFP_GPIO_INTRPT1SET_GPIO46))

#define BFP_GPIO_INTRPT1SET_GPIO45              (13)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO45              ((uint32_t)0x00002000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO45              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO45              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO45(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO45)) & (BFM_GPIO_INTRPT1SET_GPIO45))
#define BFX_GPIO_INTRPT1SET_GPIO45(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO45)) >> (BFP_GPIO_INTRPT1SET_GPIO45))
#define BFW_GPIO_INTRPT1SET_GPIO45(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO45)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO45)) & (BFM_GPIO_INTRPT1SET_GPIO45)) ))
#define BFR_GPIO_INTRPT1SET_GPIO45()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO45))>>(BFP_GPIO_INTRPT1SET_GPIO45))

#define BFP_GPIO_INTRPT1SET_GPIO44              (12)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO44              ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO44              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO44              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO44(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO44)) & (BFM_GPIO_INTRPT1SET_GPIO44))
#define BFX_GPIO_INTRPT1SET_GPIO44(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO44)) >> (BFP_GPIO_INTRPT1SET_GPIO44))
#define BFW_GPIO_INTRPT1SET_GPIO44(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO44)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO44)) & (BFM_GPIO_INTRPT1SET_GPIO44)) ))
#define BFR_GPIO_INTRPT1SET_GPIO44()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO44))>>(BFP_GPIO_INTRPT1SET_GPIO44))

#define BFP_GPIO_INTRPT1SET_GPIO43              (11)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO43              ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO43              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO43              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO43(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO43)) & (BFM_GPIO_INTRPT1SET_GPIO43))
#define BFX_GPIO_INTRPT1SET_GPIO43(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO43)) >> (BFP_GPIO_INTRPT1SET_GPIO43))
#define BFW_GPIO_INTRPT1SET_GPIO43(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO43)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO43)) & (BFM_GPIO_INTRPT1SET_GPIO43)) ))
#define BFR_GPIO_INTRPT1SET_GPIO43()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO43))>>(BFP_GPIO_INTRPT1SET_GPIO43))

#define BFP_GPIO_INTRPT1SET_GPIO42              (10)                    /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO42              ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO42              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO42              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO42(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO42)) & (BFM_GPIO_INTRPT1SET_GPIO42))
#define BFX_GPIO_INTRPT1SET_GPIO42(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO42)) >> (BFP_GPIO_INTRPT1SET_GPIO42))
#define BFW_GPIO_INTRPT1SET_GPIO42(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO42)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO42)) & (BFM_GPIO_INTRPT1SET_GPIO42)) ))
#define BFR_GPIO_INTRPT1SET_GPIO42()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO42))>>(BFP_GPIO_INTRPT1SET_GPIO42))

#define BFP_GPIO_INTRPT1SET_GPIO41              (9)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO41              ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO41              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO41              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO41(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO41)) & (BFM_GPIO_INTRPT1SET_GPIO41))
#define BFX_GPIO_INTRPT1SET_GPIO41(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO41)) >> (BFP_GPIO_INTRPT1SET_GPIO41))
#define BFW_GPIO_INTRPT1SET_GPIO41(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO41)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO41)) & (BFM_GPIO_INTRPT1SET_GPIO41)) ))
#define BFR_GPIO_INTRPT1SET_GPIO41()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO41))>>(BFP_GPIO_INTRPT1SET_GPIO41))

#define BFP_GPIO_INTRPT1SET_GPIO40              (8)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO40              ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO40              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO40              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO40(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO40)) & (BFM_GPIO_INTRPT1SET_GPIO40))
#define BFX_GPIO_INTRPT1SET_GPIO40(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO40)) >> (BFP_GPIO_INTRPT1SET_GPIO40))
#define BFW_GPIO_INTRPT1SET_GPIO40(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO40)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO40)) & (BFM_GPIO_INTRPT1SET_GPIO40)) ))
#define BFR_GPIO_INTRPT1SET_GPIO40()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO40))>>(BFP_GPIO_INTRPT1SET_GPIO40))

#define BFP_GPIO_INTRPT1SET_GPIO39              (7)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO39              ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO39              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO39              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO39(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO39)) & (BFM_GPIO_INTRPT1SET_GPIO39))
#define BFX_GPIO_INTRPT1SET_GPIO39(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO39)) >> (BFP_GPIO_INTRPT1SET_GPIO39))
#define BFW_GPIO_INTRPT1SET_GPIO39(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO39)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO39)) & (BFM_GPIO_INTRPT1SET_GPIO39)) ))
#define BFR_GPIO_INTRPT1SET_GPIO39()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO39))>>(BFP_GPIO_INTRPT1SET_GPIO39))

#define BFP_GPIO_INTRPT1SET_GPIO38              (6)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO38              ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO38              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO38              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO38(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO38)) & (BFM_GPIO_INTRPT1SET_GPIO38))
#define BFX_GPIO_INTRPT1SET_GPIO38(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO38)) >> (BFP_GPIO_INTRPT1SET_GPIO38))
#define BFW_GPIO_INTRPT1SET_GPIO38(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO38)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO38)) & (BFM_GPIO_INTRPT1SET_GPIO38)) ))
#define BFR_GPIO_INTRPT1SET_GPIO38()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO38))>>(BFP_GPIO_INTRPT1SET_GPIO38))

#define BFP_GPIO_INTRPT1SET_GPIO37              (5)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO37              ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO37              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO37              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO37(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO37)) & (BFM_GPIO_INTRPT1SET_GPIO37))
#define BFX_GPIO_INTRPT1SET_GPIO37(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO37)) >> (BFP_GPIO_INTRPT1SET_GPIO37))
#define BFW_GPIO_INTRPT1SET_GPIO37(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO37)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO37)) & (BFM_GPIO_INTRPT1SET_GPIO37)) ))
#define BFR_GPIO_INTRPT1SET_GPIO37()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO37))>>(BFP_GPIO_INTRPT1SET_GPIO37))

#define BFP_GPIO_INTRPT1SET_GPIO36              (4)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO36              ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO36              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO36              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO36(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO36)) & (BFM_GPIO_INTRPT1SET_GPIO36))
#define BFX_GPIO_INTRPT1SET_GPIO36(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO36)) >> (BFP_GPIO_INTRPT1SET_GPIO36))
#define BFW_GPIO_INTRPT1SET_GPIO36(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO36)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO36)) & (BFM_GPIO_INTRPT1SET_GPIO36)) ))
#define BFR_GPIO_INTRPT1SET_GPIO36()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO36))>>(BFP_GPIO_INTRPT1SET_GPIO36))

#define BFP_GPIO_INTRPT1SET_GPIO35              (3)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO35              ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO35              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO35              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO35(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO35)) & (BFM_GPIO_INTRPT1SET_GPIO35))
#define BFX_GPIO_INTRPT1SET_GPIO35(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO35)) >> (BFP_GPIO_INTRPT1SET_GPIO35))
#define BFW_GPIO_INTRPT1SET_GPIO35(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO35)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO35)) & (BFM_GPIO_INTRPT1SET_GPIO35)) ))
#define BFR_GPIO_INTRPT1SET_GPIO35()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO35))>>(BFP_GPIO_INTRPT1SET_GPIO35))

#define BFP_GPIO_INTRPT1SET_GPIO34              (2)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO34              ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO34              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO34              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO34(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO34)) & (BFM_GPIO_INTRPT1SET_GPIO34))
#define BFX_GPIO_INTRPT1SET_GPIO34(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO34)) >> (BFP_GPIO_INTRPT1SET_GPIO34))
#define BFW_GPIO_INTRPT1SET_GPIO34(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO34)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO34)) & (BFM_GPIO_INTRPT1SET_GPIO34)) ))
#define BFR_GPIO_INTRPT1SET_GPIO34()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO34))>>(BFP_GPIO_INTRPT1SET_GPIO34))

#define BFP_GPIO_INTRPT1SET_GPIO33              (1)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO33              ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO33              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO33              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO33(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO33)) & (BFM_GPIO_INTRPT1SET_GPIO33))
#define BFX_GPIO_INTRPT1SET_GPIO33(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO33)) >> (BFP_GPIO_INTRPT1SET_GPIO33))
#define BFW_GPIO_INTRPT1SET_GPIO33(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO33)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO33)) & (BFM_GPIO_INTRPT1SET_GPIO33)) ))
#define BFR_GPIO_INTRPT1SET_GPIO33()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO33))>>(BFP_GPIO_INTRPT1SET_GPIO33))

#define BFP_GPIO_INTRPT1SET_GPIO32              (0)                     /* bitfield lsb */
#define BFM_GPIO_INTRPT1SET_GPIO32              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_GPIO_INTRPT1SET_GPIO32              (1)                     /* bitfield width */
#define BFD_GPIO_INTRPT1SET_GPIO32              (0x0)                   /* bitfield default value */
#define BFV_GPIO_INTRPT1SET_GPIO32(v)           ((((uint32_t) v) << (BFP_GPIO_INTRPT1SET_GPIO32)) & (BFM_GPIO_INTRPT1SET_GPIO32))
#define BFX_GPIO_INTRPT1SET_GPIO32(v)           ((((uint32_t) v) & (BFM_GPIO_INTRPT1SET_GPIO32)) >> (BFP_GPIO_INTRPT1SET_GPIO32))
#define BFW_GPIO_INTRPT1SET_GPIO32(v)           (REG_GPIO_INTRPT1SET.U32 = ( (REG_GPIO_INTRPT1SET.U32 & ~(BFM_GPIO_INTRPT1SET_GPIO32)) | ((((uint32_t) v)<<(BFP_GPIO_INTRPT1SET_GPIO32)) & (BFM_GPIO_INTRPT1SET_GPIO32)) ))
#define BFR_GPIO_INTRPT1SET_GPIO32()            ((REG_GPIO_INTRPT1SET.U32 & (BFM_GPIO_INTRPT1SET_GPIO32))>>(BFP_GPIO_INTRPT1SET_GPIO32))

#define REG_GPIO_LASTREG_ADDR                   (REG_GPIO_INTRPT1SET_ADDR)



#endif  // __GPIO_H

