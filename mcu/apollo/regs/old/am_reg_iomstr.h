/*******************************************************************************
*                                                                              *
*   Copyright (c) 2013-2014 Ambiq Micro                                        *
*                                                                              *
********************************************************************************
*                                                                              *
*   File:       iomstr_regs.h                                                  *
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


#ifndef __IOMSTR_H
#define __IOMSTR_H

#include "../am_mcu_apollo.h"

// *****************************************************************************
//                                                                             *
//  IOMSTR_FIFO - FIFO Access Port                                             *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned FIFO                       : 32;
    } B;
} reg_iomstr_fifo_t;

#define REG_IOMSTR_FIFO_ADDR(n)                 (REG_IOMSTR_BASEADDR + (n*0x1000) + 0x00000000UL)
#define REG_IOMSTR_FIFO(n)                      (*(volatile reg_iomstr_fifo_t *) REG_IOMSTR_FIFO_ADDR(n))
#define REG_IOMSTR_FIFO_RD(n)                   (REG_IOMSTR_FIFO(n).U32)
#define REG_IOMSTR_FIFO_WR(n,v)                 (REG_IOMSTR_FIFO(n).U32 = (v))
#define REG_IOMSTR_FIFO_CLR(n,m)                (REG_IOMSTR_FIFO(n).U32 = ((REG_IOMSTR_FIFO(n).U32) & ~(m)))
#define REG_IOMSTR_FIFO_SET(n,m)                (REG_IOMSTR_FIFO(n).U32 = ((REG_IOMSTR_FIFO(n).U32) | (m)))
#define REG_IOMSTR_FIFO_DEF                     0x00000000

#define BFP_IOMSTR_FIFO_FIFO                    (0)                     /* bitfield lsb */
#define BFM_IOMSTR_FIFO_FIFO                    ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_IOMSTR_FIFO_FIFO                    (32)                    /* bitfield width */
#define BFD_IOMSTR_FIFO_FIFO                    (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_FIFO_FIFO(v)                 ((((uint32_t) v) << (BFP_IOMSTR_FIFO_FIFO)) & (BFM_IOMSTR_FIFO_FIFO))
#define BFX_IOMSTR_FIFO_FIFO(v)                 ((((uint32_t) v) & (BFM_IOMSTR_FIFO_FIFO)) >> (BFP_IOMSTR_FIFO_FIFO))
#define BFW_IOMSTR_FIFO_FIFO(n,v)               (REG_IOMSTR_FIFO(n).U32 = ( (((uint32_t) v)<<(BFP_IOMSTR_FIFO_FIFO)) & (BFM_IOMSTR_FIFO_FIFO)) )
#define BFR_IOMSTR_FIFO_FIFO(n)                 ((REG_IOMSTR_FIFO(n).U32 & (BFM_IOMSTR_FIFO_FIFO))>>(BFP_IOMSTR_FIFO_FIFO))


// *****************************************************************************
//                                                                             *
//  IOMSTR_FIFOPTR - Current FIFO Pointers                                     *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_23                    :  9;
        unsigned FIFOREM                    :  7;
        unsigned RSVD_7                     :  9;
        unsigned FIFOSIZ                    :  7;
    } B;
} reg_iomstr_fifoptr_t;

#define REG_IOMSTR_FIFOPTR_ADDR(n)              (REG_IOMSTR_BASEADDR + (n*0x1000) + 0x00000100UL)
#define REG_IOMSTR_FIFOPTR(n)                   (*(volatile reg_iomstr_fifoptr_t *) REG_IOMSTR_FIFOPTR_ADDR(n))
#define REG_IOMSTR_FIFOPTR_RD(n)                (REG_IOMSTR_FIFOPTR(n).U32)
#define REG_IOMSTR_FIFOPTR_WR(n,v)              (REG_IOMSTR_FIFOPTR(n).U32 = (v))
#define REG_IOMSTR_FIFOPTR_CLR(n,m)             (REG_IOMSTR_FIFOPTR(n).U32 = ((REG_IOMSTR_FIFOPTR(n).U32) & ~(m)))
#define REG_IOMSTR_FIFOPTR_SET(n,m)             (REG_IOMSTR_FIFOPTR(n).U32 = ((REG_IOMSTR_FIFOPTR(n).U32) | (m)))
#define REG_IOMSTR_FIFOPTR_DEF                  0x00000000

#define BFP_IOMSTR_FIFOPTR_RSVD_23              (23)                    /* bitfield lsb */
#define BFM_IOMSTR_FIFOPTR_RSVD_23              ((uint32_t)0xff800000)  /* bitfield mask */
#define BFN_IOMSTR_FIFOPTR_RSVD_23              (9)                     /* bitfield width */
#define BFD_IOMSTR_FIFOPTR_RSVD_23              (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_FIFOPTR_RSVD_23(v)           ((((uint32_t) v) << (BFP_IOMSTR_FIFOPTR_RSVD_23)) & (BFM_IOMSTR_FIFOPTR_RSVD_23))
#define BFX_IOMSTR_FIFOPTR_RSVD_23(v)           ((((uint32_t) v) & (BFM_IOMSTR_FIFOPTR_RSVD_23)) >> (BFP_IOMSTR_FIFOPTR_RSVD_23))
#define BFW_IOMSTR_FIFOPTR_RSVD_23(n,v)         (REG_IOMSTR_FIFOPTR(n).U32 = ( (REG_IOMSTR_FIFOPTR(n).U32 & ~(BFM_IOMSTR_FIFOPTR_RSVD_23)) | ((((uint32_t) v)<<(BFP_IOMSTR_FIFOPTR_RSVD_23)) & (BFM_IOMSTR_FIFOPTR_RSVD_23)) ))
#define BFR_IOMSTR_FIFOPTR_RSVD_23(n)           ((REG_IOMSTR_FIFOPTR(n).U32 & (BFM_IOMSTR_FIFOPTR_RSVD_23))>>(BFP_IOMSTR_FIFOPTR_RSVD_23))

#define BFP_IOMSTR_FIFOPTR_FIFOREM              (16)                    /* bitfield lsb */
#define BFM_IOMSTR_FIFOPTR_FIFOREM              ((uint32_t)0x007f0000)  /* bitfield mask */
#define BFN_IOMSTR_FIFOPTR_FIFOREM              (7)                     /* bitfield width */
#define BFD_IOMSTR_FIFOPTR_FIFOREM              (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_FIFOPTR_FIFOREM(v)           ((((uint32_t) v) << (BFP_IOMSTR_FIFOPTR_FIFOREM)) & (BFM_IOMSTR_FIFOPTR_FIFOREM))
#define BFX_IOMSTR_FIFOPTR_FIFOREM(v)           ((((uint32_t) v) & (BFM_IOMSTR_FIFOPTR_FIFOREM)) >> (BFP_IOMSTR_FIFOPTR_FIFOREM))
#define BFW_IOMSTR_FIFOPTR_FIFOREM(n,v)         (REG_IOMSTR_FIFOPTR(n).U32 = ( (REG_IOMSTR_FIFOPTR(n).U32 & ~(BFM_IOMSTR_FIFOPTR_FIFOREM)) | ((((uint32_t) v)<<(BFP_IOMSTR_FIFOPTR_FIFOREM)) & (BFM_IOMSTR_FIFOPTR_FIFOREM)) ))
#define BFR_IOMSTR_FIFOPTR_FIFOREM(n)           ((REG_IOMSTR_FIFOPTR(n).U32 & (BFM_IOMSTR_FIFOPTR_FIFOREM))>>(BFP_IOMSTR_FIFOPTR_FIFOREM))

#define BFP_IOMSTR_FIFOPTR_RSVD_7               (7)                     /* bitfield lsb */
#define BFM_IOMSTR_FIFOPTR_RSVD_7               ((uint32_t)0x0000ff80)  /* bitfield mask */
#define BFN_IOMSTR_FIFOPTR_RSVD_7               (9)                     /* bitfield width */
#define BFD_IOMSTR_FIFOPTR_RSVD_7               (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_FIFOPTR_RSVD_7(v)            ((((uint32_t) v) << (BFP_IOMSTR_FIFOPTR_RSVD_7)) & (BFM_IOMSTR_FIFOPTR_RSVD_7))
#define BFX_IOMSTR_FIFOPTR_RSVD_7(v)            ((((uint32_t) v) & (BFM_IOMSTR_FIFOPTR_RSVD_7)) >> (BFP_IOMSTR_FIFOPTR_RSVD_7))
#define BFW_IOMSTR_FIFOPTR_RSVD_7(n,v)          (REG_IOMSTR_FIFOPTR(n).U32 = ( (REG_IOMSTR_FIFOPTR(n).U32 & ~(BFM_IOMSTR_FIFOPTR_RSVD_7)) | ((((uint32_t) v)<<(BFP_IOMSTR_FIFOPTR_RSVD_7)) & (BFM_IOMSTR_FIFOPTR_RSVD_7)) ))
#define BFR_IOMSTR_FIFOPTR_RSVD_7(n)            ((REG_IOMSTR_FIFOPTR(n).U32 & (BFM_IOMSTR_FIFOPTR_RSVD_7))>>(BFP_IOMSTR_FIFOPTR_RSVD_7))

#define BFP_IOMSTR_FIFOPTR_FIFOSIZ              (0)                     /* bitfield lsb */
#define BFM_IOMSTR_FIFOPTR_FIFOSIZ              ((uint32_t)0x0000007f)  /* bitfield mask */
#define BFN_IOMSTR_FIFOPTR_FIFOSIZ              (7)                     /* bitfield width */
#define BFD_IOMSTR_FIFOPTR_FIFOSIZ              (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_FIFOPTR_FIFOSIZ(v)           ((((uint32_t) v) << (BFP_IOMSTR_FIFOPTR_FIFOSIZ)) & (BFM_IOMSTR_FIFOPTR_FIFOSIZ))
#define BFX_IOMSTR_FIFOPTR_FIFOSIZ(v)           ((((uint32_t) v) & (BFM_IOMSTR_FIFOPTR_FIFOSIZ)) >> (BFP_IOMSTR_FIFOPTR_FIFOSIZ))
#define BFW_IOMSTR_FIFOPTR_FIFOSIZ(n,v)         (REG_IOMSTR_FIFOPTR(n).U32 = ( (REG_IOMSTR_FIFOPTR(n).U32 & ~(BFM_IOMSTR_FIFOPTR_FIFOSIZ)) | ((((uint32_t) v)<<(BFP_IOMSTR_FIFOPTR_FIFOSIZ)) & (BFM_IOMSTR_FIFOPTR_FIFOSIZ)) ))
#define BFR_IOMSTR_FIFOPTR_FIFOSIZ(n)           ((REG_IOMSTR_FIFOPTR(n).U32 & (BFM_IOMSTR_FIFOPTR_FIFOSIZ))>>(BFP_IOMSTR_FIFOPTR_FIFOSIZ))


// *****************************************************************************
//                                                                             *
//  IOMSTR_TLNGTH - Transfer Length                                            *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_12                    : 20;
        unsigned TLNGTH                     : 12;
    } B;
} reg_iomstr_tlngth_t;

#define REG_IOMSTR_TLNGTH_ADDR(n)               (REG_IOMSTR_BASEADDR + (n*0x1000) + 0x00000104UL)
#define REG_IOMSTR_TLNGTH(n)                    (*(volatile reg_iomstr_tlngth_t *) REG_IOMSTR_TLNGTH_ADDR(n))
#define REG_IOMSTR_TLNGTH_RD(n)                 (REG_IOMSTR_TLNGTH(n).U32)
#define REG_IOMSTR_TLNGTH_WR(n,v)               (REG_IOMSTR_TLNGTH(n).U32 = (v))
#define REG_IOMSTR_TLNGTH_CLR(n,m)              (REG_IOMSTR_TLNGTH(n).U32 = ((REG_IOMSTR_TLNGTH(n).U32) & ~(m)))
#define REG_IOMSTR_TLNGTH_SET(n,m)              (REG_IOMSTR_TLNGTH(n).U32 = ((REG_IOMSTR_TLNGTH(n).U32) | (m)))
#define REG_IOMSTR_TLNGTH_DEF                   0x00000000

#define BFP_IOMSTR_TLNGTH_RSVD_12               (12)                    /* bitfield lsb */
#define BFM_IOMSTR_TLNGTH_RSVD_12               ((uint32_t)0xfffff000)  /* bitfield mask */
#define BFN_IOMSTR_TLNGTH_RSVD_12               (20)                    /* bitfield width */
#define BFD_IOMSTR_TLNGTH_RSVD_12               (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_TLNGTH_RSVD_12(v)            ((((uint32_t) v) << (BFP_IOMSTR_TLNGTH_RSVD_12)) & (BFM_IOMSTR_TLNGTH_RSVD_12))
#define BFX_IOMSTR_TLNGTH_RSVD_12(v)            ((((uint32_t) v) & (BFM_IOMSTR_TLNGTH_RSVD_12)) >> (BFP_IOMSTR_TLNGTH_RSVD_12))
#define BFW_IOMSTR_TLNGTH_RSVD_12(n,v)          (REG_IOMSTR_TLNGTH(n).U32 = ( (((uint32_t) v)<<(BFP_IOMSTR_TLNGTH_RSVD_12)) & (BFM_IOMSTR_TLNGTH_RSVD_12)) )
#define BFR_IOMSTR_TLNGTH_RSVD_12(n)            ((REG_IOMSTR_TLNGTH(n).U32 & (BFM_IOMSTR_TLNGTH_RSVD_12))>>(BFP_IOMSTR_TLNGTH_RSVD_12))

#define BFP_IOMSTR_TLNGTH_TLNGTH                (0)                     /* bitfield lsb */
#define BFM_IOMSTR_TLNGTH_TLNGTH                ((uint32_t)0x00000fff)  /* bitfield mask */
#define BFN_IOMSTR_TLNGTH_TLNGTH                (12)                    /* bitfield width */
#define BFD_IOMSTR_TLNGTH_TLNGTH                (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_TLNGTH_TLNGTH(v)             ((((uint32_t) v) << (BFP_IOMSTR_TLNGTH_TLNGTH)) & (BFM_IOMSTR_TLNGTH_TLNGTH))
#define BFX_IOMSTR_TLNGTH_TLNGTH(v)             ((((uint32_t) v) & (BFM_IOMSTR_TLNGTH_TLNGTH)) >> (BFP_IOMSTR_TLNGTH_TLNGTH))
#define BFW_IOMSTR_TLNGTH_TLNGTH(n,v)           (REG_IOMSTR_TLNGTH(n).U32 = ( (((uint32_t) v)<<(BFP_IOMSTR_TLNGTH_TLNGTH)) & (BFM_IOMSTR_TLNGTH_TLNGTH)) )
#define BFR_IOMSTR_TLNGTH_TLNGTH(n)             ((REG_IOMSTR_TLNGTH(n).U32 & (BFM_IOMSTR_TLNGTH_TLNGTH))>>(BFP_IOMSTR_TLNGTH_TLNGTH))


// *****************************************************************************
//                                                                             *
//  IOMSTR_FIFOTHR - FIFO Threshold Configuration                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_14                    : 18;
        unsigned FIFOWTHR                   :  6;
        unsigned RSVD_6                     :  2;
        unsigned FIFORTHR                   :  6;
    } B;
} reg_iomstr_fifothr_t;

#define REG_IOMSTR_FIFOTHR_ADDR(n)              (REG_IOMSTR_BASEADDR + (n*0x1000) + 0x00000108UL)
#define REG_IOMSTR_FIFOTHR(n)                   (*(volatile reg_iomstr_fifothr_t *) REG_IOMSTR_FIFOTHR_ADDR(n))
#define REG_IOMSTR_FIFOTHR_RD(n)                (REG_IOMSTR_FIFOTHR(n).U32)
#define REG_IOMSTR_FIFOTHR_WR(n,v)              (REG_IOMSTR_FIFOTHR(n).U32 = (v))
#define REG_IOMSTR_FIFOTHR_CLR(n,m)             (REG_IOMSTR_FIFOTHR(n).U32 = ((REG_IOMSTR_FIFOTHR(n).U32) & ~(m)))
#define REG_IOMSTR_FIFOTHR_SET(n,m)             (REG_IOMSTR_FIFOTHR(n).U32 = ((REG_IOMSTR_FIFOTHR(n).U32) | (m)))
#define REG_IOMSTR_FIFOTHR_DEF                  0x00000000

#define BFP_IOMSTR_FIFOTHR_RSVD_14              (14)                    /* bitfield lsb */
#define BFM_IOMSTR_FIFOTHR_RSVD_14              ((uint32_t)0xffffc000)  /* bitfield mask */
#define BFN_IOMSTR_FIFOTHR_RSVD_14              (18)                    /* bitfield width */
#define BFD_IOMSTR_FIFOTHR_RSVD_14              (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_FIFOTHR_RSVD_14(v)           ((((uint32_t) v) << (BFP_IOMSTR_FIFOTHR_RSVD_14)) & (BFM_IOMSTR_FIFOTHR_RSVD_14))
#define BFX_IOMSTR_FIFOTHR_RSVD_14(v)           ((((uint32_t) v) & (BFM_IOMSTR_FIFOTHR_RSVD_14)) >> (BFP_IOMSTR_FIFOTHR_RSVD_14))
#define BFW_IOMSTR_FIFOTHR_RSVD_14(n,v)         (REG_IOMSTR_FIFOTHR(n).U32 = ( (REG_IOMSTR_FIFOTHR(n).U32 & ~(BFM_IOMSTR_FIFOTHR_RSVD_14)) | ((((uint32_t) v)<<(BFP_IOMSTR_FIFOTHR_RSVD_14)) & (BFM_IOMSTR_FIFOTHR_RSVD_14)) ))
#define BFR_IOMSTR_FIFOTHR_RSVD_14(n)           ((REG_IOMSTR_FIFOTHR(n).U32 & (BFM_IOMSTR_FIFOTHR_RSVD_14))>>(BFP_IOMSTR_FIFOTHR_RSVD_14))

#define BFP_IOMSTR_FIFOTHR_FIFOWTHR             (8)                     /* bitfield lsb */
#define BFM_IOMSTR_FIFOTHR_FIFOWTHR             ((uint32_t)0x00003f00)  /* bitfield mask */
#define BFN_IOMSTR_FIFOTHR_FIFOWTHR             (6)                     /* bitfield width */
#define BFD_IOMSTR_FIFOTHR_FIFOWTHR             (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_FIFOTHR_FIFOWTHR(v)          ((((uint32_t) v) << (BFP_IOMSTR_FIFOTHR_FIFOWTHR)) & (BFM_IOMSTR_FIFOTHR_FIFOWTHR))
#define BFX_IOMSTR_FIFOTHR_FIFOWTHR(v)          ((((uint32_t) v) & (BFM_IOMSTR_FIFOTHR_FIFOWTHR)) >> (BFP_IOMSTR_FIFOTHR_FIFOWTHR))
#define BFW_IOMSTR_FIFOTHR_FIFOWTHR(n,v)        (REG_IOMSTR_FIFOTHR(n).U32 = ( (REG_IOMSTR_FIFOTHR(n).U32 & ~(BFM_IOMSTR_FIFOTHR_FIFOWTHR)) | ((((uint32_t) v)<<(BFP_IOMSTR_FIFOTHR_FIFOWTHR)) & (BFM_IOMSTR_FIFOTHR_FIFOWTHR)) ))
#define BFR_IOMSTR_FIFOTHR_FIFOWTHR(n)          ((REG_IOMSTR_FIFOTHR(n).U32 & (BFM_IOMSTR_FIFOTHR_FIFOWTHR))>>(BFP_IOMSTR_FIFOTHR_FIFOWTHR))

#define BFP_IOMSTR_FIFOTHR_RSVD_6               (6)                     /* bitfield lsb */
#define BFM_IOMSTR_FIFOTHR_RSVD_6               ((uint32_t)0x000000c0)  /* bitfield mask */
#define BFN_IOMSTR_FIFOTHR_RSVD_6               (2)                     /* bitfield width */
#define BFD_IOMSTR_FIFOTHR_RSVD_6               (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_FIFOTHR_RSVD_6(v)            ((((uint32_t) v) << (BFP_IOMSTR_FIFOTHR_RSVD_6)) & (BFM_IOMSTR_FIFOTHR_RSVD_6))
#define BFX_IOMSTR_FIFOTHR_RSVD_6(v)            ((((uint32_t) v) & (BFM_IOMSTR_FIFOTHR_RSVD_6)) >> (BFP_IOMSTR_FIFOTHR_RSVD_6))
#define BFW_IOMSTR_FIFOTHR_RSVD_6(n,v)          (REG_IOMSTR_FIFOTHR(n).U32 = ( (REG_IOMSTR_FIFOTHR(n).U32 & ~(BFM_IOMSTR_FIFOTHR_RSVD_6)) | ((((uint32_t) v)<<(BFP_IOMSTR_FIFOTHR_RSVD_6)) & (BFM_IOMSTR_FIFOTHR_RSVD_6)) ))
#define BFR_IOMSTR_FIFOTHR_RSVD_6(n)            ((REG_IOMSTR_FIFOTHR(n).U32 & (BFM_IOMSTR_FIFOTHR_RSVD_6))>>(BFP_IOMSTR_FIFOTHR_RSVD_6))

#define BFP_IOMSTR_FIFOTHR_FIFORTHR             (0)                     /* bitfield lsb */
#define BFM_IOMSTR_FIFOTHR_FIFORTHR             ((uint32_t)0x0000003f)  /* bitfield mask */
#define BFN_IOMSTR_FIFOTHR_FIFORTHR             (6)                     /* bitfield width */
#define BFD_IOMSTR_FIFOTHR_FIFORTHR             (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_FIFOTHR_FIFORTHR(v)          ((((uint32_t) v) << (BFP_IOMSTR_FIFOTHR_FIFORTHR)) & (BFM_IOMSTR_FIFOTHR_FIFORTHR))
#define BFX_IOMSTR_FIFOTHR_FIFORTHR(v)          ((((uint32_t) v) & (BFM_IOMSTR_FIFOTHR_FIFORTHR)) >> (BFP_IOMSTR_FIFOTHR_FIFORTHR))
#define BFW_IOMSTR_FIFOTHR_FIFORTHR(n,v)        (REG_IOMSTR_FIFOTHR(n).U32 = ( (REG_IOMSTR_FIFOTHR(n).U32 & ~(BFM_IOMSTR_FIFOTHR_FIFORTHR)) | ((((uint32_t) v)<<(BFP_IOMSTR_FIFOTHR_FIFORTHR)) & (BFM_IOMSTR_FIFOTHR_FIFORTHR)) ))
#define BFR_IOMSTR_FIFOTHR_FIFORTHR(n)          ((REG_IOMSTR_FIFOTHR(n).U32 & (BFM_IOMSTR_FIFOTHR_FIFORTHR))>>(BFP_IOMSTR_FIFOTHR_FIFORTHR))


// *****************************************************************************
//                                                                             *
//  IOMSTR_CLKCFG - I/O Clock Configuration                                    *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned TOTPER                     :  8;
        unsigned LOWPER                     :  8;
        unsigned RSVD_13                    :  3;
        unsigned DIVEN                      :  1;
        unsigned DIV3                       :  1;
        unsigned FSEL                       :  3;
        unsigned RSVD_0                     :  8;
    } B;
} reg_iomstr_clkcfg_t;

#define REG_IOMSTR_CLKCFG_ADDR(n)               (REG_IOMSTR_BASEADDR + (n*0x1000) + 0x0000010CUL)
#define REG_IOMSTR_CLKCFG(n)                    (*(volatile reg_iomstr_clkcfg_t *) REG_IOMSTR_CLKCFG_ADDR(n))
#define REG_IOMSTR_CLKCFG_RD(n)                 (REG_IOMSTR_CLKCFG(n).U32)
#define REG_IOMSTR_CLKCFG_WR(n,v)               (REG_IOMSTR_CLKCFG(n).U32 = (v))
#define REG_IOMSTR_CLKCFG_CLR(n,m)              (REG_IOMSTR_CLKCFG(n).U32 = ((REG_IOMSTR_CLKCFG(n).U32) & ~(m)))
#define REG_IOMSTR_CLKCFG_SET(n,m)              (REG_IOMSTR_CLKCFG(n).U32 = ((REG_IOMSTR_CLKCFG(n).U32) | (m)))
#define REG_IOMSTR_CLKCFG_DEF                   0x00000000

#define BFP_IOMSTR_CLKCFG_TOTPER                (24)                    /* bitfield lsb */
#define BFM_IOMSTR_CLKCFG_TOTPER                ((uint32_t)0xff000000)  /* bitfield mask */
#define BFN_IOMSTR_CLKCFG_TOTPER                (8)                     /* bitfield width */
#define BFD_IOMSTR_CLKCFG_TOTPER                (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_CLKCFG_TOTPER(v)             ((((uint32_t) v) << (BFP_IOMSTR_CLKCFG_TOTPER)) & (BFM_IOMSTR_CLKCFG_TOTPER))
#define BFX_IOMSTR_CLKCFG_TOTPER(v)             ((((uint32_t) v) & (BFM_IOMSTR_CLKCFG_TOTPER)) >> (BFP_IOMSTR_CLKCFG_TOTPER))
#define BFW_IOMSTR_CLKCFG_TOTPER(n,v)           (REG_IOMSTR_CLKCFG(n).U32 = ( (REG_IOMSTR_CLKCFG(n).U32 & ~(BFM_IOMSTR_CLKCFG_TOTPER)) | ((((uint32_t) v)<<(BFP_IOMSTR_CLKCFG_TOTPER)) & (BFM_IOMSTR_CLKCFG_TOTPER)) ))
#define BFR_IOMSTR_CLKCFG_TOTPER(n)             ((REG_IOMSTR_CLKCFG(n).U32 & (BFM_IOMSTR_CLKCFG_TOTPER))>>(BFP_IOMSTR_CLKCFG_TOTPER))

#define BFP_IOMSTR_CLKCFG_LOWPER                (16)                    /* bitfield lsb */
#define BFM_IOMSTR_CLKCFG_LOWPER                ((uint32_t)0x00ff0000)  /* bitfield mask */
#define BFN_IOMSTR_CLKCFG_LOWPER                (8)                     /* bitfield width */
#define BFD_IOMSTR_CLKCFG_LOWPER                (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_CLKCFG_LOWPER(v)             ((((uint32_t) v) << (BFP_IOMSTR_CLKCFG_LOWPER)) & (BFM_IOMSTR_CLKCFG_LOWPER))
#define BFX_IOMSTR_CLKCFG_LOWPER(v)             ((((uint32_t) v) & (BFM_IOMSTR_CLKCFG_LOWPER)) >> (BFP_IOMSTR_CLKCFG_LOWPER))
#define BFW_IOMSTR_CLKCFG_LOWPER(n,v)           (REG_IOMSTR_CLKCFG(n).U32 = ( (REG_IOMSTR_CLKCFG(n).U32 & ~(BFM_IOMSTR_CLKCFG_LOWPER)) | ((((uint32_t) v)<<(BFP_IOMSTR_CLKCFG_LOWPER)) & (BFM_IOMSTR_CLKCFG_LOWPER)) ))
#define BFR_IOMSTR_CLKCFG_LOWPER(n)             ((REG_IOMSTR_CLKCFG(n).U32 & (BFM_IOMSTR_CLKCFG_LOWPER))>>(BFP_IOMSTR_CLKCFG_LOWPER))

#define BFP_IOMSTR_CLKCFG_RSVD_13               (13)                    /* bitfield lsb */
#define BFM_IOMSTR_CLKCFG_RSVD_13               ((uint32_t)0x0000e000)  /* bitfield mask */
#define BFN_IOMSTR_CLKCFG_RSVD_13               (3)                     /* bitfield width */
#define BFD_IOMSTR_CLKCFG_RSVD_13               (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_CLKCFG_RSVD_13(v)            ((((uint32_t) v) << (BFP_IOMSTR_CLKCFG_RSVD_13)) & (BFM_IOMSTR_CLKCFG_RSVD_13))
#define BFX_IOMSTR_CLKCFG_RSVD_13(v)            ((((uint32_t) v) & (BFM_IOMSTR_CLKCFG_RSVD_13)) >> (BFP_IOMSTR_CLKCFG_RSVD_13))
#define BFW_IOMSTR_CLKCFG_RSVD_13(n,v)          (REG_IOMSTR_CLKCFG(n).U32 = ( (REG_IOMSTR_CLKCFG(n).U32 & ~(BFM_IOMSTR_CLKCFG_RSVD_13)) | ((((uint32_t) v)<<(BFP_IOMSTR_CLKCFG_RSVD_13)) & (BFM_IOMSTR_CLKCFG_RSVD_13)) ))
#define BFR_IOMSTR_CLKCFG_RSVD_13(n)            ((REG_IOMSTR_CLKCFG(n).U32 & (BFM_IOMSTR_CLKCFG_RSVD_13))>>(BFP_IOMSTR_CLKCFG_RSVD_13))

#define BFP_IOMSTR_CLKCFG_DIVEN                 (12)                    /* bitfield lsb */
#define BFM_IOMSTR_CLKCFG_DIVEN                 ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_IOMSTR_CLKCFG_DIVEN                 (1)                     /* bitfield width */
#define BFD_IOMSTR_CLKCFG_DIVEN                 (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_CLKCFG_DIVEN(v)              ((((uint32_t) v) << (BFP_IOMSTR_CLKCFG_DIVEN)) & (BFM_IOMSTR_CLKCFG_DIVEN))
#define BFX_IOMSTR_CLKCFG_DIVEN(v)              ((((uint32_t) v) & (BFM_IOMSTR_CLKCFG_DIVEN)) >> (BFP_IOMSTR_CLKCFG_DIVEN))
#define BFW_IOMSTR_CLKCFG_DIVEN(n,v)            (REG_IOMSTR_CLKCFG(n).U32 = ( (REG_IOMSTR_CLKCFG(n).U32 & ~(BFM_IOMSTR_CLKCFG_DIVEN)) | ((((uint32_t) v)<<(BFP_IOMSTR_CLKCFG_DIVEN)) & (BFM_IOMSTR_CLKCFG_DIVEN)) ))
#define BFR_IOMSTR_CLKCFG_DIVEN(n)              ((REG_IOMSTR_CLKCFG(n).U32 & (BFM_IOMSTR_CLKCFG_DIVEN))>>(BFP_IOMSTR_CLKCFG_DIVEN))

#define BFP_IOMSTR_CLKCFG_DIV3                  (11)                    /* bitfield lsb */
#define BFM_IOMSTR_CLKCFG_DIV3                  ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_IOMSTR_CLKCFG_DIV3                  (1)                     /* bitfield width */
#define BFD_IOMSTR_CLKCFG_DIV3                  (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_CLKCFG_DIV3(v)               ((((uint32_t) v) << (BFP_IOMSTR_CLKCFG_DIV3)) & (BFM_IOMSTR_CLKCFG_DIV3))
#define BFX_IOMSTR_CLKCFG_DIV3(v)               ((((uint32_t) v) & (BFM_IOMSTR_CLKCFG_DIV3)) >> (BFP_IOMSTR_CLKCFG_DIV3))
#define BFW_IOMSTR_CLKCFG_DIV3(n,v)             (REG_IOMSTR_CLKCFG(n).U32 = ( (REG_IOMSTR_CLKCFG(n).U32 & ~(BFM_IOMSTR_CLKCFG_DIV3)) | ((((uint32_t) v)<<(BFP_IOMSTR_CLKCFG_DIV3)) & (BFM_IOMSTR_CLKCFG_DIV3)) ))
#define BFR_IOMSTR_CLKCFG_DIV3(n)               ((REG_IOMSTR_CLKCFG(n).U32 & (BFM_IOMSTR_CLKCFG_DIV3))>>(BFP_IOMSTR_CLKCFG_DIV3))

#define BFP_IOMSTR_CLKCFG_FSEL                  (8)                     /* bitfield lsb */
#define BFM_IOMSTR_CLKCFG_FSEL                  ((uint32_t)0x00000700)  /* bitfield mask */
#define BFN_IOMSTR_CLKCFG_FSEL                  (3)                     /* bitfield width */
#define BFD_IOMSTR_CLKCFG_FSEL                  (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_CLKCFG_FSEL(v)               ((((uint32_t) v) << (BFP_IOMSTR_CLKCFG_FSEL)) & (BFM_IOMSTR_CLKCFG_FSEL))
#define BFX_IOMSTR_CLKCFG_FSEL(v)               ((((uint32_t) v) & (BFM_IOMSTR_CLKCFG_FSEL)) >> (BFP_IOMSTR_CLKCFG_FSEL))
#define BFW_IOMSTR_CLKCFG_FSEL(n,v)             (REG_IOMSTR_CLKCFG(n).U32 = ( (REG_IOMSTR_CLKCFG(n).U32 & ~(BFM_IOMSTR_CLKCFG_FSEL)) | ((((uint32_t) v)<<(BFP_IOMSTR_CLKCFG_FSEL)) & (BFM_IOMSTR_CLKCFG_FSEL)) ))
#define BFR_IOMSTR_CLKCFG_FSEL(n)               ((REG_IOMSTR_CLKCFG(n).U32 & (BFM_IOMSTR_CLKCFG_FSEL))>>(BFP_IOMSTR_CLKCFG_FSEL))

#define BFP_IOMSTR_CLKCFG_RSVD_0                (0)                     /* bitfield lsb */
#define BFM_IOMSTR_CLKCFG_RSVD_0                ((uint32_t)0x000000ff)  /* bitfield mask */
#define BFN_IOMSTR_CLKCFG_RSVD_0                (8)                     /* bitfield width */
#define BFD_IOMSTR_CLKCFG_RSVD_0                (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_CLKCFG_RSVD_0(v)             ((((uint32_t) v) << (BFP_IOMSTR_CLKCFG_RSVD_0)) & (BFM_IOMSTR_CLKCFG_RSVD_0))
#define BFX_IOMSTR_CLKCFG_RSVD_0(v)             ((((uint32_t) v) & (BFM_IOMSTR_CLKCFG_RSVD_0)) >> (BFP_IOMSTR_CLKCFG_RSVD_0))
#define BFW_IOMSTR_CLKCFG_RSVD_0(n,v)           (REG_IOMSTR_CLKCFG(n).U32 = ( (REG_IOMSTR_CLKCFG(n).U32 & ~(BFM_IOMSTR_CLKCFG_RSVD_0)) | ((((uint32_t) v)<<(BFP_IOMSTR_CLKCFG_RSVD_0)) & (BFM_IOMSTR_CLKCFG_RSVD_0)) ))
#define BFR_IOMSTR_CLKCFG_RSVD_0(n)             ((REG_IOMSTR_CLKCFG(n).U32 & (BFM_IOMSTR_CLKCFG_RSVD_0))>>(BFP_IOMSTR_CLKCFG_RSVD_0))


// *****************************************************************************
//                                                                             *
//  IOMSTR_CMD - Command Register                                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CMD                        : 32;
    } B;
} reg_iomstr_cmd_t;

#define REG_IOMSTR_CMD_ADDR(n)                  (REG_IOMSTR_BASEADDR + (n*0x1000) + 0x00000110UL)
#define REG_IOMSTR_CMD(n)                       (*(volatile reg_iomstr_cmd_t *) REG_IOMSTR_CMD_ADDR(n))
#define REG_IOMSTR_CMD_RD(n)                    (REG_IOMSTR_CMD(n).U32)
#define REG_IOMSTR_CMD_WR(n,v)                  (REG_IOMSTR_CMD(n).U32 = (v))
#define REG_IOMSTR_CMD_CLR(n,m)                 (REG_IOMSTR_CMD(n).U32 = ((REG_IOMSTR_CMD(n).U32) & ~(m)))
#define REG_IOMSTR_CMD_SET(n,m)                 (REG_IOMSTR_CMD(n).U32 = ((REG_IOMSTR_CMD(n).U32) | (m)))
#define REG_IOMSTR_CMD_DEF                      0x00000000

#define BFP_IOMSTR_CMD_CMD                      (0)                     /* bitfield lsb */
#define BFM_IOMSTR_CMD_CMD                      ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_IOMSTR_CMD_CMD                      (32)                    /* bitfield width */
#define BFD_IOMSTR_CMD_CMD                      (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_CMD_CMD(v)                   ((((uint32_t) v) << (BFP_IOMSTR_CMD_CMD)) & (BFM_IOMSTR_CMD_CMD))
#define BFX_IOMSTR_CMD_CMD(v)                   ((((uint32_t) v) & (BFM_IOMSTR_CMD_CMD)) >> (BFP_IOMSTR_CMD_CMD))
#define BFW_IOMSTR_CMD_CMD(n,v)                 (REG_IOMSTR_CMD(n).U32 = ( (((uint32_t) v)<<(BFP_IOMSTR_CMD_CMD)) & (BFM_IOMSTR_CMD_CMD)) )
#define BFR_IOMSTR_CMD_CMD(n)                   ((REG_IOMSTR_CMD(n).U32 & (BFM_IOMSTR_CMD_CMD))>>(BFP_IOMSTR_CMD_CMD))


// *****************************************************************************
//                                                                             *
//  IOMSTR_CMDRPT - Command Repeat Register                                    *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_5                     : 27;
        unsigned CMDRPT                     :  5;
    } B;
} reg_iomstr_cmdrpt_t;

#define REG_IOMSTR_CMDRPT_ADDR(n)               (REG_IOMSTR_BASEADDR + (n*0x1000) + 0x00000114UL)
#define REG_IOMSTR_CMDRPT(n)                    (*(volatile reg_iomstr_cmdrpt_t *) REG_IOMSTR_CMDRPT_ADDR(n))
#define REG_IOMSTR_CMDRPT_RD(n)                 (REG_IOMSTR_CMDRPT(n).U32)
#define REG_IOMSTR_CMDRPT_WR(n,v)               (REG_IOMSTR_CMDRPT(n).U32 = (v))
#define REG_IOMSTR_CMDRPT_CLR(n,m)              (REG_IOMSTR_CMDRPT(n).U32 = ((REG_IOMSTR_CMDRPT(n).U32) & ~(m)))
#define REG_IOMSTR_CMDRPT_SET(n,m)              (REG_IOMSTR_CMDRPT(n).U32 = ((REG_IOMSTR_CMDRPT(n).U32) | (m)))
#define REG_IOMSTR_CMDRPT_DEF                   0x00000000

#define BFP_IOMSTR_CMDRPT_RSVD_5                (5)                     /* bitfield lsb */
#define BFM_IOMSTR_CMDRPT_RSVD_5                ((uint32_t)0xffffffe0)  /* bitfield mask */
#define BFN_IOMSTR_CMDRPT_RSVD_5                (27)                    /* bitfield width */
#define BFD_IOMSTR_CMDRPT_RSVD_5                (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_CMDRPT_RSVD_5(v)             ((((uint32_t) v) << (BFP_IOMSTR_CMDRPT_RSVD_5)) & (BFM_IOMSTR_CMDRPT_RSVD_5))
#define BFX_IOMSTR_CMDRPT_RSVD_5(v)             ((((uint32_t) v) & (BFM_IOMSTR_CMDRPT_RSVD_5)) >> (BFP_IOMSTR_CMDRPT_RSVD_5))
#define BFW_IOMSTR_CMDRPT_RSVD_5(n,v)           (REG_IOMSTR_CMDRPT(n).U32 = ( (((uint32_t) v)<<(BFP_IOMSTR_CMDRPT_RSVD_5)) & (BFM_IOMSTR_CMDRPT_RSVD_5)) )
#define BFR_IOMSTR_CMDRPT_RSVD_5(n)             ((REG_IOMSTR_CMDRPT(n).U32 & (BFM_IOMSTR_CMDRPT_RSVD_5))>>(BFP_IOMSTR_CMDRPT_RSVD_5))

#define BFP_IOMSTR_CMDRPT_CMDRPT                (0)                     /* bitfield lsb */
#define BFM_IOMSTR_CMDRPT_CMDRPT                ((uint32_t)0x0000001f)  /* bitfield mask */
#define BFN_IOMSTR_CMDRPT_CMDRPT                (5)                     /* bitfield width */
#define BFD_IOMSTR_CMDRPT_CMDRPT                (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_CMDRPT_CMDRPT(v)             ((((uint32_t) v) << (BFP_IOMSTR_CMDRPT_CMDRPT)) & (BFM_IOMSTR_CMDRPT_CMDRPT))
#define BFX_IOMSTR_CMDRPT_CMDRPT(v)             ((((uint32_t) v) & (BFM_IOMSTR_CMDRPT_CMDRPT)) >> (BFP_IOMSTR_CMDRPT_CMDRPT))
#define BFW_IOMSTR_CMDRPT_CMDRPT(n,v)           (REG_IOMSTR_CMDRPT(n).U32 = ( (((uint32_t) v)<<(BFP_IOMSTR_CMDRPT_CMDRPT)) & (BFM_IOMSTR_CMDRPT_CMDRPT)) )
#define BFR_IOMSTR_CMDRPT_CMDRPT(n)             ((REG_IOMSTR_CMDRPT(n).U32 & (BFM_IOMSTR_CMDRPT_CMDRPT))>>(BFP_IOMSTR_CMDRPT_CMDRPT))


// *****************************************************************************
//                                                                             *
//  IOMSTR_STATUS - Status Register                                            *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_3                     : 29;
        unsigned IDLEST                     :  1;
        unsigned CMDACT                     :  1;
        unsigned ERR                        :  1;
    } B;
} reg_iomstr_status_t;

#define REG_IOMSTR_STATUS_ADDR(n)               (REG_IOMSTR_BASEADDR + (n*0x1000) + 0x00000118UL)
#define REG_IOMSTR_STATUS(n)                    (*(volatile reg_iomstr_status_t *) REG_IOMSTR_STATUS_ADDR(n))
#define REG_IOMSTR_STATUS_RD(n)                 (REG_IOMSTR_STATUS(n).U32)
#define REG_IOMSTR_STATUS_WR(n,v)               (REG_IOMSTR_STATUS(n).U32 = (v))
#define REG_IOMSTR_STATUS_CLR(n,m)              (REG_IOMSTR_STATUS(n).U32 = ((REG_IOMSTR_STATUS(n).U32) & ~(m)))
#define REG_IOMSTR_STATUS_SET(n,m)              (REG_IOMSTR_STATUS(n).U32 = ((REG_IOMSTR_STATUS(n).U32) | (m)))
#define REG_IOMSTR_STATUS_DEF                   0x00000000

#define BFP_IOMSTR_STATUS_RSVD_3                (3)                     /* bitfield lsb */
#define BFM_IOMSTR_STATUS_RSVD_3                ((uint32_t)0xfffffff8)  /* bitfield mask */
#define BFN_IOMSTR_STATUS_RSVD_3                (29)                    /* bitfield width */
#define BFD_IOMSTR_STATUS_RSVD_3                (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_STATUS_RSVD_3(v)             ((((uint32_t) v) << (BFP_IOMSTR_STATUS_RSVD_3)) & (BFM_IOMSTR_STATUS_RSVD_3))
#define BFX_IOMSTR_STATUS_RSVD_3(v)             ((((uint32_t) v) & (BFM_IOMSTR_STATUS_RSVD_3)) >> (BFP_IOMSTR_STATUS_RSVD_3))
#define BFW_IOMSTR_STATUS_RSVD_3(n,v)           (REG_IOMSTR_STATUS(n).U32 = ( (REG_IOMSTR_STATUS(n).U32 & ~(BFM_IOMSTR_STATUS_RSVD_3)) | ((((uint32_t) v)<<(BFP_IOMSTR_STATUS_RSVD_3)) & (BFM_IOMSTR_STATUS_RSVD_3)) ))
#define BFR_IOMSTR_STATUS_RSVD_3(n)             ((REG_IOMSTR_STATUS(n).U32 & (BFM_IOMSTR_STATUS_RSVD_3))>>(BFP_IOMSTR_STATUS_RSVD_3))

#define BFP_IOMSTR_STATUS_IDLEST                (2)                     /* bitfield lsb */
#define BFM_IOMSTR_STATUS_IDLEST                ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_IOMSTR_STATUS_IDLEST                (1)                     /* bitfield width */
#define BFD_IOMSTR_STATUS_IDLEST                (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_STATUS_IDLEST(v)             ((((uint32_t) v) << (BFP_IOMSTR_STATUS_IDLEST)) & (BFM_IOMSTR_STATUS_IDLEST))
#define BFX_IOMSTR_STATUS_IDLEST(v)             ((((uint32_t) v) & (BFM_IOMSTR_STATUS_IDLEST)) >> (BFP_IOMSTR_STATUS_IDLEST))
#define BFW_IOMSTR_STATUS_IDLEST(n,v)           (REG_IOMSTR_STATUS(n).U32 = ( (REG_IOMSTR_STATUS(n).U32 & ~(BFM_IOMSTR_STATUS_IDLEST)) | ((((uint32_t) v)<<(BFP_IOMSTR_STATUS_IDLEST)) & (BFM_IOMSTR_STATUS_IDLEST)) ))
#define BFR_IOMSTR_STATUS_IDLEST(n)             ((REG_IOMSTR_STATUS(n).U32 & (BFM_IOMSTR_STATUS_IDLEST))>>(BFP_IOMSTR_STATUS_IDLEST))

#define BFP_IOMSTR_STATUS_CMDACT                (1)                     /* bitfield lsb */
#define BFM_IOMSTR_STATUS_CMDACT                ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_IOMSTR_STATUS_CMDACT                (1)                     /* bitfield width */
#define BFD_IOMSTR_STATUS_CMDACT                (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_STATUS_CMDACT(v)             ((((uint32_t) v) << (BFP_IOMSTR_STATUS_CMDACT)) & (BFM_IOMSTR_STATUS_CMDACT))
#define BFX_IOMSTR_STATUS_CMDACT(v)             ((((uint32_t) v) & (BFM_IOMSTR_STATUS_CMDACT)) >> (BFP_IOMSTR_STATUS_CMDACT))
#define BFW_IOMSTR_STATUS_CMDACT(n,v)           (REG_IOMSTR_STATUS(n).U32 = ( (REG_IOMSTR_STATUS(n).U32 & ~(BFM_IOMSTR_STATUS_CMDACT)) | ((((uint32_t) v)<<(BFP_IOMSTR_STATUS_CMDACT)) & (BFM_IOMSTR_STATUS_CMDACT)) ))
#define BFR_IOMSTR_STATUS_CMDACT(n)             ((REG_IOMSTR_STATUS(n).U32 & (BFM_IOMSTR_STATUS_CMDACT))>>(BFP_IOMSTR_STATUS_CMDACT))

#define BFP_IOMSTR_STATUS_ERR                   (0)                     /* bitfield lsb */
#define BFM_IOMSTR_STATUS_ERR                   ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_IOMSTR_STATUS_ERR                   (1)                     /* bitfield width */
#define BFD_IOMSTR_STATUS_ERR                   (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_STATUS_ERR(v)                ((((uint32_t) v) << (BFP_IOMSTR_STATUS_ERR)) & (BFM_IOMSTR_STATUS_ERR))
#define BFX_IOMSTR_STATUS_ERR(v)                ((((uint32_t) v) & (BFM_IOMSTR_STATUS_ERR)) >> (BFP_IOMSTR_STATUS_ERR))
#define BFW_IOMSTR_STATUS_ERR(n,v)              (REG_IOMSTR_STATUS(n).U32 = ( (REG_IOMSTR_STATUS(n).U32 & ~(BFM_IOMSTR_STATUS_ERR)) | ((((uint32_t) v)<<(BFP_IOMSTR_STATUS_ERR)) & (BFM_IOMSTR_STATUS_ERR)) ))
#define BFR_IOMSTR_STATUS_ERR(n)                ((REG_IOMSTR_STATUS(n).U32 & (BFM_IOMSTR_STATUS_ERR))>>(BFP_IOMSTR_STATUS_ERR))


// *****************************************************************************
//                                                                             *
//  IOMSTR_IOMCFG - I/O Master Configuration                                   *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned IFCEN                      :  1;
        unsigned RSVD_4                     : 27;
        unsigned RSVD_3                     :  1;
        unsigned SPHA                       :  1;
        unsigned SPOL                       :  1;
        unsigned IFCSEL                     :  1;
    } B;
} reg_iomstr_iomcfg_t;

#define REG_IOMSTR_IOMCFG_ADDR(n)               (REG_IOMSTR_BASEADDR + (n*0x1000) + 0x0000011CUL)
#define REG_IOMSTR_IOMCFG(n)                    (*(volatile reg_iomstr_iomcfg_t *) REG_IOMSTR_IOMCFG_ADDR(n))
#define REG_IOMSTR_IOMCFG_RD(n)                 (REG_IOMSTR_IOMCFG(n).U32)
#define REG_IOMSTR_IOMCFG_WR(n,v)               (REG_IOMSTR_IOMCFG(n).U32 = (v))
#define REG_IOMSTR_IOMCFG_CLR(n,m)              (REG_IOMSTR_IOMCFG(n).U32 = ((REG_IOMSTR_IOMCFG(n).U32) & ~(m)))
#define REG_IOMSTR_IOMCFG_SET(n,m)              (REG_IOMSTR_IOMCFG(n).U32 = ((REG_IOMSTR_IOMCFG(n).U32) | (m)))
#define REG_IOMSTR_IOMCFG_DEF                   0x00000000

#define BFP_IOMSTR_IOMCFG_IFCEN                 (31)                    /* bitfield lsb */
#define BFM_IOMSTR_IOMCFG_IFCEN                 ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_IOMSTR_IOMCFG_IFCEN                 (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMCFG_IFCEN                 (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMCFG_IFCEN(v)              ((((uint32_t) v) << (BFP_IOMSTR_IOMCFG_IFCEN)) & (BFM_IOMSTR_IOMCFG_IFCEN))
#define BFX_IOMSTR_IOMCFG_IFCEN(v)              ((((uint32_t) v) & (BFM_IOMSTR_IOMCFG_IFCEN)) >> (BFP_IOMSTR_IOMCFG_IFCEN))
#define BFW_IOMSTR_IOMCFG_IFCEN(n,v)            (REG_IOMSTR_IOMCFG(n).U32 = ( (REG_IOMSTR_IOMCFG(n).U32 & ~(BFM_IOMSTR_IOMCFG_IFCEN)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMCFG_IFCEN)) & (BFM_IOMSTR_IOMCFG_IFCEN)) ))
#define BFR_IOMSTR_IOMCFG_IFCEN(n)              ((REG_IOMSTR_IOMCFG(n).U32 & (BFM_IOMSTR_IOMCFG_IFCEN))>>(BFP_IOMSTR_IOMCFG_IFCEN))

#define BFP_IOMSTR_IOMCFG_RSVD_4                (4)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMCFG_RSVD_4                ((uint32_t)0x7ffffff0)  /* bitfield mask */
#define BFN_IOMSTR_IOMCFG_RSVD_4                (27)                    /* bitfield width */
#define BFD_IOMSTR_IOMCFG_RSVD_4                (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMCFG_RSVD_4(v)             ((((uint32_t) v) << (BFP_IOMSTR_IOMCFG_RSVD_4)) & (BFM_IOMSTR_IOMCFG_RSVD_4))
#define BFX_IOMSTR_IOMCFG_RSVD_4(v)             ((((uint32_t) v) & (BFM_IOMSTR_IOMCFG_RSVD_4)) >> (BFP_IOMSTR_IOMCFG_RSVD_4))
#define BFW_IOMSTR_IOMCFG_RSVD_4(n,v)           (REG_IOMSTR_IOMCFG(n).U32 = ( (REG_IOMSTR_IOMCFG(n).U32 & ~(BFM_IOMSTR_IOMCFG_RSVD_4)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMCFG_RSVD_4)) & (BFM_IOMSTR_IOMCFG_RSVD_4)) ))
#define BFR_IOMSTR_IOMCFG_RSVD_4(n)             ((REG_IOMSTR_IOMCFG(n).U32 & (BFM_IOMSTR_IOMCFG_RSVD_4))>>(BFP_IOMSTR_IOMCFG_RSVD_4))

#define BFP_IOMSTR_IOMCFG_RSVD_3                (3)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMCFG_RSVD_3                ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_IOMSTR_IOMCFG_RSVD_3                (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMCFG_RSVD_3                (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMCFG_RSVD_3(v)             ((((uint32_t) v) << (BFP_IOMSTR_IOMCFG_RSVD_3)) & (BFM_IOMSTR_IOMCFG_RSVD_3))
#define BFX_IOMSTR_IOMCFG_RSVD_3(v)             ((((uint32_t) v) & (BFM_IOMSTR_IOMCFG_RSVD_3)) >> (BFP_IOMSTR_IOMCFG_RSVD_3))
#define BFW_IOMSTR_IOMCFG_RSVD_3(n,v)           (REG_IOMSTR_IOMCFG(n).U32 = ( (REG_IOMSTR_IOMCFG(n).U32 & ~(BFM_IOMSTR_IOMCFG_RSVD_3)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMCFG_RSVD_3)) & (BFM_IOMSTR_IOMCFG_RSVD_3)) ))
#define BFR_IOMSTR_IOMCFG_RSVD_3(n)             ((REG_IOMSTR_IOMCFG(n).U32 & (BFM_IOMSTR_IOMCFG_RSVD_3))>>(BFP_IOMSTR_IOMCFG_RSVD_3))

#define BFP_IOMSTR_IOMCFG_SPHA                  (2)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMCFG_SPHA                  ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_IOMSTR_IOMCFG_SPHA                  (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMCFG_SPHA                  (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMCFG_SPHA(v)               ((((uint32_t) v) << (BFP_IOMSTR_IOMCFG_SPHA)) & (BFM_IOMSTR_IOMCFG_SPHA))
#define BFX_IOMSTR_IOMCFG_SPHA(v)               ((((uint32_t) v) & (BFM_IOMSTR_IOMCFG_SPHA)) >> (BFP_IOMSTR_IOMCFG_SPHA))
#define BFW_IOMSTR_IOMCFG_SPHA(n,v)             (REG_IOMSTR_IOMCFG(n).U32 = ( (REG_IOMSTR_IOMCFG(n).U32 & ~(BFM_IOMSTR_IOMCFG_SPHA)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMCFG_SPHA)) & (BFM_IOMSTR_IOMCFG_SPHA)) ))
#define BFR_IOMSTR_IOMCFG_SPHA(n)               ((REG_IOMSTR_IOMCFG(n).U32 & (BFM_IOMSTR_IOMCFG_SPHA))>>(BFP_IOMSTR_IOMCFG_SPHA))

#define BFP_IOMSTR_IOMCFG_SPOL                  (1)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMCFG_SPOL                  ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_IOMSTR_IOMCFG_SPOL                  (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMCFG_SPOL                  (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMCFG_SPOL(v)               ((((uint32_t) v) << (BFP_IOMSTR_IOMCFG_SPOL)) & (BFM_IOMSTR_IOMCFG_SPOL))
#define BFX_IOMSTR_IOMCFG_SPOL(v)               ((((uint32_t) v) & (BFM_IOMSTR_IOMCFG_SPOL)) >> (BFP_IOMSTR_IOMCFG_SPOL))
#define BFW_IOMSTR_IOMCFG_SPOL(n,v)             (REG_IOMSTR_IOMCFG(n).U32 = ( (REG_IOMSTR_IOMCFG(n).U32 & ~(BFM_IOMSTR_IOMCFG_SPOL)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMCFG_SPOL)) & (BFM_IOMSTR_IOMCFG_SPOL)) ))
#define BFR_IOMSTR_IOMCFG_SPOL(n)               ((REG_IOMSTR_IOMCFG(n).U32 & (BFM_IOMSTR_IOMCFG_SPOL))>>(BFP_IOMSTR_IOMCFG_SPOL))

#define BFP_IOMSTR_IOMCFG_IFCSEL                (0)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMCFG_IFCSEL                ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_IOMSTR_IOMCFG_IFCSEL                (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMCFG_IFCSEL                (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMCFG_IFCSEL(v)             ((((uint32_t) v) << (BFP_IOMSTR_IOMCFG_IFCSEL)) & (BFM_IOMSTR_IOMCFG_IFCSEL))
#define BFX_IOMSTR_IOMCFG_IFCSEL(v)             ((((uint32_t) v) & (BFM_IOMSTR_IOMCFG_IFCSEL)) >> (BFP_IOMSTR_IOMCFG_IFCSEL))
#define BFW_IOMSTR_IOMCFG_IFCSEL(n,v)           (REG_IOMSTR_IOMCFG(n).U32 = ( (REG_IOMSTR_IOMCFG(n).U32 & ~(BFM_IOMSTR_IOMCFG_IFCSEL)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMCFG_IFCSEL)) & (BFM_IOMSTR_IOMCFG_IFCSEL)) ))
#define BFR_IOMSTR_IOMCFG_IFCSEL(n)             ((REG_IOMSTR_IOMCFG(n).U32 & (BFM_IOMSTR_IOMCFG_IFCSEL))>>(BFP_IOMSTR_IOMCFG_IFCSEL))


// *****************************************************************************
//                                                                             *
//  IOMSTR_IOMSTRINTEN - IO Master Interrupts                                  *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_11                    : 21;
        unsigned ARB                        :  1;
        unsigned STOP                       :  1;
        unsigned START                      :  1;
        unsigned ICMD                       :  1;
        unsigned IACC                       :  1;
        unsigned WTLEN                      :  1;
        unsigned NAK                        :  1;
        unsigned FOVFL                      :  1;
        unsigned FUNDFL                     :  1;
        unsigned THR                        :  1;
        unsigned CMDCMP                     :  1;
    } B;
} reg_iomstr_iomstrinten_t;

#define REG_IOMSTR_IOMSTRINTEN_ADDR(n)          (REG_IOMSTR_BASEADDR + (n*0x1000) + 0x00000200UL)
#define REG_IOMSTR_IOMSTRINTEN(n)               (*(volatile reg_iomstr_iomstrinten_t *) REG_IOMSTR_IOMSTRINTEN_ADDR(n))
#define REG_IOMSTR_IOMSTRINTEN_RD(n)            (REG_IOMSTR_IOMSTRINTEN(n).U32)
#define REG_IOMSTR_IOMSTRINTEN_WR(n,v)          (REG_IOMSTR_IOMSTRINTEN(n).U32 = (v))
#define REG_IOMSTR_IOMSTRINTEN_CLR(n,m)         (REG_IOMSTR_IOMSTRINTEN(n).U32 = ((REG_IOMSTR_IOMSTRINTEN(n).U32) & ~(m)))
#define REG_IOMSTR_IOMSTRINTEN_SET(n,m)         (REG_IOMSTR_IOMSTRINTEN(n).U32 = ((REG_IOMSTR_IOMSTRINTEN(n).U32) | (m)))
#define REG_IOMSTR_IOMSTRINTEN_DEF              0x00000000

#define BFP_IOMSTR_IOMSTRINTEN_RSVD_11          (11)                    /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTEN_RSVD_11          ((uint32_t)0xfffff800)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTEN_RSVD_11          (21)                    /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTEN_RSVD_11          (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTEN_RSVD_11(v)       ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTEN_RSVD_11)) & (BFM_IOMSTR_IOMSTRINTEN_RSVD_11))
#define BFX_IOMSTR_IOMSTRINTEN_RSVD_11(v)       ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTEN_RSVD_11)) >> (BFP_IOMSTR_IOMSTRINTEN_RSVD_11))
#define BFW_IOMSTR_IOMSTRINTEN_RSVD_11(n,v)     (REG_IOMSTR_IOMSTRINTEN(n).U32 = ( (REG_IOMSTR_IOMSTRINTEN(n).U32 & ~(BFM_IOMSTR_IOMSTRINTEN_RSVD_11)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTEN_RSVD_11)) & (BFM_IOMSTR_IOMSTRINTEN_RSVD_11)) ))
#define BFR_IOMSTR_IOMSTRINTEN_RSVD_11(n)       ((REG_IOMSTR_IOMSTRINTEN(n).U32 & (BFM_IOMSTR_IOMSTRINTEN_RSVD_11))>>(BFP_IOMSTR_IOMSTRINTEN_RSVD_11))
#define BFS_IOMSTR_IOMSTRINTEN_RSVD_11(n)       (REG_IOMSTR_IOMSTRINTEN(n).U32 = (BFM_IOMSTR_IOMSTRINTEN_RSVD_11) )

#define BFP_IOMSTR_IOMSTRINTEN_ARB              (10)                    /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTEN_ARB              ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTEN_ARB              (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTEN_ARB              (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTEN_ARB(v)           ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTEN_ARB)) & (BFM_IOMSTR_IOMSTRINTEN_ARB))
#define BFX_IOMSTR_IOMSTRINTEN_ARB(v)           ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTEN_ARB)) >> (BFP_IOMSTR_IOMSTRINTEN_ARB))
#define BFW_IOMSTR_IOMSTRINTEN_ARB(n,v)         (REG_IOMSTR_IOMSTRINTEN(n).U32 = ( (REG_IOMSTR_IOMSTRINTEN(n).U32 & ~(BFM_IOMSTR_IOMSTRINTEN_ARB)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTEN_ARB)) & (BFM_IOMSTR_IOMSTRINTEN_ARB)) ))
#define BFR_IOMSTR_IOMSTRINTEN_ARB(n)           ((REG_IOMSTR_IOMSTRINTEN(n).U32 & (BFM_IOMSTR_IOMSTRINTEN_ARB))>>(BFP_IOMSTR_IOMSTRINTEN_ARB))
#define BFS_IOMSTR_IOMSTRINTEN_ARB(n)           (REG_IOMSTR_IOMSTRINTEN(n).U32 = (BFM_IOMSTR_IOMSTRINTEN_ARB) )

#define BFP_IOMSTR_IOMSTRINTEN_STOP             (9)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTEN_STOP             ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTEN_STOP             (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTEN_STOP             (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTEN_STOP(v)          ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTEN_STOP)) & (BFM_IOMSTR_IOMSTRINTEN_STOP))
#define BFX_IOMSTR_IOMSTRINTEN_STOP(v)          ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTEN_STOP)) >> (BFP_IOMSTR_IOMSTRINTEN_STOP))
#define BFW_IOMSTR_IOMSTRINTEN_STOP(n,v)        (REG_IOMSTR_IOMSTRINTEN(n).U32 = ( (REG_IOMSTR_IOMSTRINTEN(n).U32 & ~(BFM_IOMSTR_IOMSTRINTEN_STOP)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTEN_STOP)) & (BFM_IOMSTR_IOMSTRINTEN_STOP)) ))
#define BFR_IOMSTR_IOMSTRINTEN_STOP(n)          ((REG_IOMSTR_IOMSTRINTEN(n).U32 & (BFM_IOMSTR_IOMSTRINTEN_STOP))>>(BFP_IOMSTR_IOMSTRINTEN_STOP))
#define BFS_IOMSTR_IOMSTRINTEN_STOP(n)          (REG_IOMSTR_IOMSTRINTEN(n).U32 = (BFM_IOMSTR_IOMSTRINTEN_STOP) )

#define BFP_IOMSTR_IOMSTRINTEN_START            (8)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTEN_START            ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTEN_START            (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTEN_START            (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTEN_START(v)         ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTEN_START)) & (BFM_IOMSTR_IOMSTRINTEN_START))
#define BFX_IOMSTR_IOMSTRINTEN_START(v)         ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTEN_START)) >> (BFP_IOMSTR_IOMSTRINTEN_START))
#define BFW_IOMSTR_IOMSTRINTEN_START(n,v)       (REG_IOMSTR_IOMSTRINTEN(n).U32 = ( (REG_IOMSTR_IOMSTRINTEN(n).U32 & ~(BFM_IOMSTR_IOMSTRINTEN_START)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTEN_START)) & (BFM_IOMSTR_IOMSTRINTEN_START)) ))
#define BFR_IOMSTR_IOMSTRINTEN_START(n)         ((REG_IOMSTR_IOMSTRINTEN(n).U32 & (BFM_IOMSTR_IOMSTRINTEN_START))>>(BFP_IOMSTR_IOMSTRINTEN_START))
#define BFS_IOMSTR_IOMSTRINTEN_START(n)         (REG_IOMSTR_IOMSTRINTEN(n).U32 = (BFM_IOMSTR_IOMSTRINTEN_START) )

#define BFP_IOMSTR_IOMSTRINTEN_ICMD             (7)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTEN_ICMD             ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTEN_ICMD             (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTEN_ICMD             (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTEN_ICMD(v)          ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTEN_ICMD)) & (BFM_IOMSTR_IOMSTRINTEN_ICMD))
#define BFX_IOMSTR_IOMSTRINTEN_ICMD(v)          ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTEN_ICMD)) >> (BFP_IOMSTR_IOMSTRINTEN_ICMD))
#define BFW_IOMSTR_IOMSTRINTEN_ICMD(n,v)        (REG_IOMSTR_IOMSTRINTEN(n).U32 = ( (REG_IOMSTR_IOMSTRINTEN(n).U32 & ~(BFM_IOMSTR_IOMSTRINTEN_ICMD)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTEN_ICMD)) & (BFM_IOMSTR_IOMSTRINTEN_ICMD)) ))
#define BFR_IOMSTR_IOMSTRINTEN_ICMD(n)          ((REG_IOMSTR_IOMSTRINTEN(n).U32 & (BFM_IOMSTR_IOMSTRINTEN_ICMD))>>(BFP_IOMSTR_IOMSTRINTEN_ICMD))
#define BFS_IOMSTR_IOMSTRINTEN_ICMD(n)          (REG_IOMSTR_IOMSTRINTEN(n).U32 = (BFM_IOMSTR_IOMSTRINTEN_ICMD) )

#define BFP_IOMSTR_IOMSTRINTEN_IACC             (6)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTEN_IACC             ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTEN_IACC             (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTEN_IACC             (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTEN_IACC(v)          ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTEN_IACC)) & (BFM_IOMSTR_IOMSTRINTEN_IACC))
#define BFX_IOMSTR_IOMSTRINTEN_IACC(v)          ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTEN_IACC)) >> (BFP_IOMSTR_IOMSTRINTEN_IACC))
#define BFW_IOMSTR_IOMSTRINTEN_IACC(n,v)        (REG_IOMSTR_IOMSTRINTEN(n).U32 = ( (REG_IOMSTR_IOMSTRINTEN(n).U32 & ~(BFM_IOMSTR_IOMSTRINTEN_IACC)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTEN_IACC)) & (BFM_IOMSTR_IOMSTRINTEN_IACC)) ))
#define BFR_IOMSTR_IOMSTRINTEN_IACC(n)          ((REG_IOMSTR_IOMSTRINTEN(n).U32 & (BFM_IOMSTR_IOMSTRINTEN_IACC))>>(BFP_IOMSTR_IOMSTRINTEN_IACC))
#define BFS_IOMSTR_IOMSTRINTEN_IACC(n)          (REG_IOMSTR_IOMSTRINTEN(n).U32 = (BFM_IOMSTR_IOMSTRINTEN_IACC) )

#define BFP_IOMSTR_IOMSTRINTEN_WTLEN            (5)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTEN_WTLEN            ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTEN_WTLEN            (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTEN_WTLEN            (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTEN_WTLEN(v)         ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTEN_WTLEN)) & (BFM_IOMSTR_IOMSTRINTEN_WTLEN))
#define BFX_IOMSTR_IOMSTRINTEN_WTLEN(v)         ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTEN_WTLEN)) >> (BFP_IOMSTR_IOMSTRINTEN_WTLEN))
#define BFW_IOMSTR_IOMSTRINTEN_WTLEN(n,v)       (REG_IOMSTR_IOMSTRINTEN(n).U32 = ( (REG_IOMSTR_IOMSTRINTEN(n).U32 & ~(BFM_IOMSTR_IOMSTRINTEN_WTLEN)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTEN_WTLEN)) & (BFM_IOMSTR_IOMSTRINTEN_WTLEN)) ))
#define BFR_IOMSTR_IOMSTRINTEN_WTLEN(n)         ((REG_IOMSTR_IOMSTRINTEN(n).U32 & (BFM_IOMSTR_IOMSTRINTEN_WTLEN))>>(BFP_IOMSTR_IOMSTRINTEN_WTLEN))
#define BFS_IOMSTR_IOMSTRINTEN_WTLEN(n)         (REG_IOMSTR_IOMSTRINTEN(n).U32 = (BFM_IOMSTR_IOMSTRINTEN_WTLEN) )

#define BFP_IOMSTR_IOMSTRINTEN_NAK              (4)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTEN_NAK              ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTEN_NAK              (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTEN_NAK              (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTEN_NAK(v)           ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTEN_NAK)) & (BFM_IOMSTR_IOMSTRINTEN_NAK))
#define BFX_IOMSTR_IOMSTRINTEN_NAK(v)           ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTEN_NAK)) >> (BFP_IOMSTR_IOMSTRINTEN_NAK))
#define BFW_IOMSTR_IOMSTRINTEN_NAK(n,v)         (REG_IOMSTR_IOMSTRINTEN(n).U32 = ( (REG_IOMSTR_IOMSTRINTEN(n).U32 & ~(BFM_IOMSTR_IOMSTRINTEN_NAK)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTEN_NAK)) & (BFM_IOMSTR_IOMSTRINTEN_NAK)) ))
#define BFR_IOMSTR_IOMSTRINTEN_NAK(n)           ((REG_IOMSTR_IOMSTRINTEN(n).U32 & (BFM_IOMSTR_IOMSTRINTEN_NAK))>>(BFP_IOMSTR_IOMSTRINTEN_NAK))
#define BFS_IOMSTR_IOMSTRINTEN_NAK(n)           (REG_IOMSTR_IOMSTRINTEN(n).U32 = (BFM_IOMSTR_IOMSTRINTEN_NAK) )

#define BFP_IOMSTR_IOMSTRINTEN_FOVFL            (3)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTEN_FOVFL            ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTEN_FOVFL            (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTEN_FOVFL            (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTEN_FOVFL(v)         ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTEN_FOVFL)) & (BFM_IOMSTR_IOMSTRINTEN_FOVFL))
#define BFX_IOMSTR_IOMSTRINTEN_FOVFL(v)         ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTEN_FOVFL)) >> (BFP_IOMSTR_IOMSTRINTEN_FOVFL))
#define BFW_IOMSTR_IOMSTRINTEN_FOVFL(n,v)       (REG_IOMSTR_IOMSTRINTEN(n).U32 = ( (REG_IOMSTR_IOMSTRINTEN(n).U32 & ~(BFM_IOMSTR_IOMSTRINTEN_FOVFL)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTEN_FOVFL)) & (BFM_IOMSTR_IOMSTRINTEN_FOVFL)) ))
#define BFR_IOMSTR_IOMSTRINTEN_FOVFL(n)         ((REG_IOMSTR_IOMSTRINTEN(n).U32 & (BFM_IOMSTR_IOMSTRINTEN_FOVFL))>>(BFP_IOMSTR_IOMSTRINTEN_FOVFL))
#define BFS_IOMSTR_IOMSTRINTEN_FOVFL(n)         (REG_IOMSTR_IOMSTRINTEN(n).U32 = (BFM_IOMSTR_IOMSTRINTEN_FOVFL) )

#define BFP_IOMSTR_IOMSTRINTEN_FUNDFL           (2)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTEN_FUNDFL           ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTEN_FUNDFL           (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTEN_FUNDFL           (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTEN_FUNDFL(v)        ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTEN_FUNDFL)) & (BFM_IOMSTR_IOMSTRINTEN_FUNDFL))
#define BFX_IOMSTR_IOMSTRINTEN_FUNDFL(v)        ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTEN_FUNDFL)) >> (BFP_IOMSTR_IOMSTRINTEN_FUNDFL))
#define BFW_IOMSTR_IOMSTRINTEN_FUNDFL(n,v)      (REG_IOMSTR_IOMSTRINTEN(n).U32 = ( (REG_IOMSTR_IOMSTRINTEN(n).U32 & ~(BFM_IOMSTR_IOMSTRINTEN_FUNDFL)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTEN_FUNDFL)) & (BFM_IOMSTR_IOMSTRINTEN_FUNDFL)) ))
#define BFR_IOMSTR_IOMSTRINTEN_FUNDFL(n)        ((REG_IOMSTR_IOMSTRINTEN(n).U32 & (BFM_IOMSTR_IOMSTRINTEN_FUNDFL))>>(BFP_IOMSTR_IOMSTRINTEN_FUNDFL))
#define BFS_IOMSTR_IOMSTRINTEN_FUNDFL(n)        (REG_IOMSTR_IOMSTRINTEN(n).U32 = (BFM_IOMSTR_IOMSTRINTEN_FUNDFL) )

#define BFP_IOMSTR_IOMSTRINTEN_THR              (1)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTEN_THR              ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTEN_THR              (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTEN_THR              (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTEN_THR(v)           ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTEN_THR)) & (BFM_IOMSTR_IOMSTRINTEN_THR))
#define BFX_IOMSTR_IOMSTRINTEN_THR(v)           ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTEN_THR)) >> (BFP_IOMSTR_IOMSTRINTEN_THR))
#define BFW_IOMSTR_IOMSTRINTEN_THR(n,v)         (REG_IOMSTR_IOMSTRINTEN(n).U32 = ( (REG_IOMSTR_IOMSTRINTEN(n).U32 & ~(BFM_IOMSTR_IOMSTRINTEN_THR)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTEN_THR)) & (BFM_IOMSTR_IOMSTRINTEN_THR)) ))
#define BFR_IOMSTR_IOMSTRINTEN_THR(n)           ((REG_IOMSTR_IOMSTRINTEN(n).U32 & (BFM_IOMSTR_IOMSTRINTEN_THR))>>(BFP_IOMSTR_IOMSTRINTEN_THR))
#define BFS_IOMSTR_IOMSTRINTEN_THR(n)           (REG_IOMSTR_IOMSTRINTEN(n).U32 = (BFM_IOMSTR_IOMSTRINTEN_THR) )

#define BFP_IOMSTR_IOMSTRINTEN_CMDCMP           (0)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTEN_CMDCMP           ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTEN_CMDCMP           (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTEN_CMDCMP           (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTEN_CMDCMP(v)        ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTEN_CMDCMP)) & (BFM_IOMSTR_IOMSTRINTEN_CMDCMP))
#define BFX_IOMSTR_IOMSTRINTEN_CMDCMP(v)        ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTEN_CMDCMP)) >> (BFP_IOMSTR_IOMSTRINTEN_CMDCMP))
#define BFW_IOMSTR_IOMSTRINTEN_CMDCMP(n,v)      (REG_IOMSTR_IOMSTRINTEN(n).U32 = ( (REG_IOMSTR_IOMSTRINTEN(n).U32 & ~(BFM_IOMSTR_IOMSTRINTEN_CMDCMP)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTEN_CMDCMP)) & (BFM_IOMSTR_IOMSTRINTEN_CMDCMP)) ))
#define BFR_IOMSTR_IOMSTRINTEN_CMDCMP(n)        ((REG_IOMSTR_IOMSTRINTEN(n).U32 & (BFM_IOMSTR_IOMSTRINTEN_CMDCMP))>>(BFP_IOMSTR_IOMSTRINTEN_CMDCMP))
#define BFS_IOMSTR_IOMSTRINTEN_CMDCMP(n)        (REG_IOMSTR_IOMSTRINTEN(n).U32 = (BFM_IOMSTR_IOMSTRINTEN_CMDCMP) )


// *****************************************************************************
//                                                                             *
//  IOMSTR_IOMSTRINTSTAT - IO Master Interrupts                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_11                    : 21;
        unsigned ARB                        :  1;
        unsigned STOP                       :  1;
        unsigned START                      :  1;
        unsigned ICMD                       :  1;
        unsigned IACC                       :  1;
        unsigned WTLEN                      :  1;
        unsigned NAK                        :  1;
        unsigned FOVFL                      :  1;
        unsigned FUNDFL                     :  1;
        unsigned THR                        :  1;
        unsigned CMDCMP                     :  1;
    } B;
} reg_iomstr_iomstrintstat_t;

#define REG_IOMSTR_IOMSTRINTSTAT_ADDR(n)        (REG_IOMSTR_BASEADDR + (n*0x1000) + 0x00000204UL)
#define REG_IOMSTR_IOMSTRINTSTAT(n)             (*(volatile reg_iomstr_iomstrintstat_t *) REG_IOMSTR_IOMSTRINTSTAT_ADDR(n))
#define REG_IOMSTR_IOMSTRINTSTAT_RD(n)          (REG_IOMSTR_IOMSTRINTSTAT(n).U32)
#define REG_IOMSTR_IOMSTRINTSTAT_WR(n,v)        (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = (v))
#define REG_IOMSTR_IOMSTRINTSTAT_CLR(n,m)       (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = ((REG_IOMSTR_IOMSTRINTSTAT(n).U32) & ~(m)))
#define REG_IOMSTR_IOMSTRINTSTAT_SET(n,m)       (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = ((REG_IOMSTR_IOMSTRINTSTAT(n).U32) | (m)))
#define REG_IOMSTR_IOMSTRINTSTAT_DEF            0x00000000

#define BFP_IOMSTR_IOMSTRINTSTAT_RSVD_11        (11)                    /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSTAT_RSVD_11        ((uint32_t)0xfffff800)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSTAT_RSVD_11        (21)                    /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSTAT_RSVD_11        (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSTAT_RSVD_11(v)     ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSTAT_RSVD_11)) & (BFM_IOMSTR_IOMSTRINTSTAT_RSVD_11))
#define BFX_IOMSTR_IOMSTRINTSTAT_RSVD_11(v)     ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSTAT_RSVD_11)) >> (BFP_IOMSTR_IOMSTRINTSTAT_RSVD_11))
#define BFW_IOMSTR_IOMSTRINTSTAT_RSVD_11(n,v)   (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = ( (REG_IOMSTR_IOMSTRINTSTAT(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSTAT_RSVD_11)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSTAT_RSVD_11)) & (BFM_IOMSTR_IOMSTRINTSTAT_RSVD_11)) ))
#define BFR_IOMSTR_IOMSTRINTSTAT_RSVD_11(n)     ((REG_IOMSTR_IOMSTRINTSTAT(n).U32 & (BFM_IOMSTR_IOMSTRINTSTAT_RSVD_11))>>(BFP_IOMSTR_IOMSTRINTSTAT_RSVD_11))
#define BFS_IOMSTR_IOMSTRINTSTAT_RSVD_11(n)     (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = (BFM_IOMSTR_IOMSTRINTSTAT_RSVD_11) )

#define BFP_IOMSTR_IOMSTRINTSTAT_ARB            (10)                    /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSTAT_ARB            ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSTAT_ARB            (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSTAT_ARB            (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSTAT_ARB(v)         ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSTAT_ARB)) & (BFM_IOMSTR_IOMSTRINTSTAT_ARB))
#define BFX_IOMSTR_IOMSTRINTSTAT_ARB(v)         ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSTAT_ARB)) >> (BFP_IOMSTR_IOMSTRINTSTAT_ARB))
#define BFW_IOMSTR_IOMSTRINTSTAT_ARB(n,v)       (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = ( (REG_IOMSTR_IOMSTRINTSTAT(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSTAT_ARB)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSTAT_ARB)) & (BFM_IOMSTR_IOMSTRINTSTAT_ARB)) ))
#define BFR_IOMSTR_IOMSTRINTSTAT_ARB(n)         ((REG_IOMSTR_IOMSTRINTSTAT(n).U32 & (BFM_IOMSTR_IOMSTRINTSTAT_ARB))>>(BFP_IOMSTR_IOMSTRINTSTAT_ARB))
#define BFS_IOMSTR_IOMSTRINTSTAT_ARB(n)         (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = (BFM_IOMSTR_IOMSTRINTSTAT_ARB) )

#define BFP_IOMSTR_IOMSTRINTSTAT_STOP           (9)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSTAT_STOP           ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSTAT_STOP           (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSTAT_STOP           (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSTAT_STOP(v)        ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSTAT_STOP)) & (BFM_IOMSTR_IOMSTRINTSTAT_STOP))
#define BFX_IOMSTR_IOMSTRINTSTAT_STOP(v)        ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSTAT_STOP)) >> (BFP_IOMSTR_IOMSTRINTSTAT_STOP))
#define BFW_IOMSTR_IOMSTRINTSTAT_STOP(n,v)      (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = ( (REG_IOMSTR_IOMSTRINTSTAT(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSTAT_STOP)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSTAT_STOP)) & (BFM_IOMSTR_IOMSTRINTSTAT_STOP)) ))
#define BFR_IOMSTR_IOMSTRINTSTAT_STOP(n)        ((REG_IOMSTR_IOMSTRINTSTAT(n).U32 & (BFM_IOMSTR_IOMSTRINTSTAT_STOP))>>(BFP_IOMSTR_IOMSTRINTSTAT_STOP))
#define BFS_IOMSTR_IOMSTRINTSTAT_STOP(n)        (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = (BFM_IOMSTR_IOMSTRINTSTAT_STOP) )

#define BFP_IOMSTR_IOMSTRINTSTAT_START          (8)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSTAT_START          ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSTAT_START          (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSTAT_START          (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSTAT_START(v)       ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSTAT_START)) & (BFM_IOMSTR_IOMSTRINTSTAT_START))
#define BFX_IOMSTR_IOMSTRINTSTAT_START(v)       ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSTAT_START)) >> (BFP_IOMSTR_IOMSTRINTSTAT_START))
#define BFW_IOMSTR_IOMSTRINTSTAT_START(n,v)     (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = ( (REG_IOMSTR_IOMSTRINTSTAT(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSTAT_START)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSTAT_START)) & (BFM_IOMSTR_IOMSTRINTSTAT_START)) ))
#define BFR_IOMSTR_IOMSTRINTSTAT_START(n)       ((REG_IOMSTR_IOMSTRINTSTAT(n).U32 & (BFM_IOMSTR_IOMSTRINTSTAT_START))>>(BFP_IOMSTR_IOMSTRINTSTAT_START))
#define BFS_IOMSTR_IOMSTRINTSTAT_START(n)       (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = (BFM_IOMSTR_IOMSTRINTSTAT_START) )

#define BFP_IOMSTR_IOMSTRINTSTAT_ICMD           (7)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSTAT_ICMD           ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSTAT_ICMD           (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSTAT_ICMD           (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSTAT_ICMD(v)        ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSTAT_ICMD)) & (BFM_IOMSTR_IOMSTRINTSTAT_ICMD))
#define BFX_IOMSTR_IOMSTRINTSTAT_ICMD(v)        ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSTAT_ICMD)) >> (BFP_IOMSTR_IOMSTRINTSTAT_ICMD))
#define BFW_IOMSTR_IOMSTRINTSTAT_ICMD(n,v)      (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = ( (REG_IOMSTR_IOMSTRINTSTAT(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSTAT_ICMD)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSTAT_ICMD)) & (BFM_IOMSTR_IOMSTRINTSTAT_ICMD)) ))
#define BFR_IOMSTR_IOMSTRINTSTAT_ICMD(n)        ((REG_IOMSTR_IOMSTRINTSTAT(n).U32 & (BFM_IOMSTR_IOMSTRINTSTAT_ICMD))>>(BFP_IOMSTR_IOMSTRINTSTAT_ICMD))
#define BFS_IOMSTR_IOMSTRINTSTAT_ICMD(n)        (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = (BFM_IOMSTR_IOMSTRINTSTAT_ICMD) )

#define BFP_IOMSTR_IOMSTRINTSTAT_IACC           (6)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSTAT_IACC           ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSTAT_IACC           (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSTAT_IACC           (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSTAT_IACC(v)        ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSTAT_IACC)) & (BFM_IOMSTR_IOMSTRINTSTAT_IACC))
#define BFX_IOMSTR_IOMSTRINTSTAT_IACC(v)        ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSTAT_IACC)) >> (BFP_IOMSTR_IOMSTRINTSTAT_IACC))
#define BFW_IOMSTR_IOMSTRINTSTAT_IACC(n,v)      (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = ( (REG_IOMSTR_IOMSTRINTSTAT(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSTAT_IACC)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSTAT_IACC)) & (BFM_IOMSTR_IOMSTRINTSTAT_IACC)) ))
#define BFR_IOMSTR_IOMSTRINTSTAT_IACC(n)        ((REG_IOMSTR_IOMSTRINTSTAT(n).U32 & (BFM_IOMSTR_IOMSTRINTSTAT_IACC))>>(BFP_IOMSTR_IOMSTRINTSTAT_IACC))
#define BFS_IOMSTR_IOMSTRINTSTAT_IACC(n)        (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = (BFM_IOMSTR_IOMSTRINTSTAT_IACC) )

#define BFP_IOMSTR_IOMSTRINTSTAT_WTLEN          (5)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSTAT_WTLEN          ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSTAT_WTLEN          (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSTAT_WTLEN          (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSTAT_WTLEN(v)       ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSTAT_WTLEN)) & (BFM_IOMSTR_IOMSTRINTSTAT_WTLEN))
#define BFX_IOMSTR_IOMSTRINTSTAT_WTLEN(v)       ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSTAT_WTLEN)) >> (BFP_IOMSTR_IOMSTRINTSTAT_WTLEN))
#define BFW_IOMSTR_IOMSTRINTSTAT_WTLEN(n,v)     (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = ( (REG_IOMSTR_IOMSTRINTSTAT(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSTAT_WTLEN)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSTAT_WTLEN)) & (BFM_IOMSTR_IOMSTRINTSTAT_WTLEN)) ))
#define BFR_IOMSTR_IOMSTRINTSTAT_WTLEN(n)       ((REG_IOMSTR_IOMSTRINTSTAT(n).U32 & (BFM_IOMSTR_IOMSTRINTSTAT_WTLEN))>>(BFP_IOMSTR_IOMSTRINTSTAT_WTLEN))
#define BFS_IOMSTR_IOMSTRINTSTAT_WTLEN(n)       (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = (BFM_IOMSTR_IOMSTRINTSTAT_WTLEN) )

#define BFP_IOMSTR_IOMSTRINTSTAT_NAK            (4)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSTAT_NAK            ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSTAT_NAK            (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSTAT_NAK            (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSTAT_NAK(v)         ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSTAT_NAK)) & (BFM_IOMSTR_IOMSTRINTSTAT_NAK))
#define BFX_IOMSTR_IOMSTRINTSTAT_NAK(v)         ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSTAT_NAK)) >> (BFP_IOMSTR_IOMSTRINTSTAT_NAK))
#define BFW_IOMSTR_IOMSTRINTSTAT_NAK(n,v)       (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = ( (REG_IOMSTR_IOMSTRINTSTAT(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSTAT_NAK)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSTAT_NAK)) & (BFM_IOMSTR_IOMSTRINTSTAT_NAK)) ))
#define BFR_IOMSTR_IOMSTRINTSTAT_NAK(n)         ((REG_IOMSTR_IOMSTRINTSTAT(n).U32 & (BFM_IOMSTR_IOMSTRINTSTAT_NAK))>>(BFP_IOMSTR_IOMSTRINTSTAT_NAK))
#define BFS_IOMSTR_IOMSTRINTSTAT_NAK(n)         (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = (BFM_IOMSTR_IOMSTRINTSTAT_NAK) )

#define BFP_IOMSTR_IOMSTRINTSTAT_FOVFL          (3)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSTAT_FOVFL          ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSTAT_FOVFL          (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSTAT_FOVFL          (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSTAT_FOVFL(v)       ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSTAT_FOVFL)) & (BFM_IOMSTR_IOMSTRINTSTAT_FOVFL))
#define BFX_IOMSTR_IOMSTRINTSTAT_FOVFL(v)       ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSTAT_FOVFL)) >> (BFP_IOMSTR_IOMSTRINTSTAT_FOVFL))
#define BFW_IOMSTR_IOMSTRINTSTAT_FOVFL(n,v)     (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = ( (REG_IOMSTR_IOMSTRINTSTAT(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSTAT_FOVFL)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSTAT_FOVFL)) & (BFM_IOMSTR_IOMSTRINTSTAT_FOVFL)) ))
#define BFR_IOMSTR_IOMSTRINTSTAT_FOVFL(n)       ((REG_IOMSTR_IOMSTRINTSTAT(n).U32 & (BFM_IOMSTR_IOMSTRINTSTAT_FOVFL))>>(BFP_IOMSTR_IOMSTRINTSTAT_FOVFL))
#define BFS_IOMSTR_IOMSTRINTSTAT_FOVFL(n)       (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = (BFM_IOMSTR_IOMSTRINTSTAT_FOVFL) )

#define BFP_IOMSTR_IOMSTRINTSTAT_FUNDFL         (2)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSTAT_FUNDFL         ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSTAT_FUNDFL         (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSTAT_FUNDFL         (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSTAT_FUNDFL(v)      ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSTAT_FUNDFL)) & (BFM_IOMSTR_IOMSTRINTSTAT_FUNDFL))
#define BFX_IOMSTR_IOMSTRINTSTAT_FUNDFL(v)      ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSTAT_FUNDFL)) >> (BFP_IOMSTR_IOMSTRINTSTAT_FUNDFL))
#define BFW_IOMSTR_IOMSTRINTSTAT_FUNDFL(n,v)    (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = ( (REG_IOMSTR_IOMSTRINTSTAT(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSTAT_FUNDFL)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSTAT_FUNDFL)) & (BFM_IOMSTR_IOMSTRINTSTAT_FUNDFL)) ))
#define BFR_IOMSTR_IOMSTRINTSTAT_FUNDFL(n)      ((REG_IOMSTR_IOMSTRINTSTAT(n).U32 & (BFM_IOMSTR_IOMSTRINTSTAT_FUNDFL))>>(BFP_IOMSTR_IOMSTRINTSTAT_FUNDFL))
#define BFS_IOMSTR_IOMSTRINTSTAT_FUNDFL(n)      (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = (BFM_IOMSTR_IOMSTRINTSTAT_FUNDFL) )

#define BFP_IOMSTR_IOMSTRINTSTAT_THR            (1)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSTAT_THR            ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSTAT_THR            (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSTAT_THR            (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSTAT_THR(v)         ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSTAT_THR)) & (BFM_IOMSTR_IOMSTRINTSTAT_THR))
#define BFX_IOMSTR_IOMSTRINTSTAT_THR(v)         ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSTAT_THR)) >> (BFP_IOMSTR_IOMSTRINTSTAT_THR))
#define BFW_IOMSTR_IOMSTRINTSTAT_THR(n,v)       (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = ( (REG_IOMSTR_IOMSTRINTSTAT(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSTAT_THR)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSTAT_THR)) & (BFM_IOMSTR_IOMSTRINTSTAT_THR)) ))
#define BFR_IOMSTR_IOMSTRINTSTAT_THR(n)         ((REG_IOMSTR_IOMSTRINTSTAT(n).U32 & (BFM_IOMSTR_IOMSTRINTSTAT_THR))>>(BFP_IOMSTR_IOMSTRINTSTAT_THR))
#define BFS_IOMSTR_IOMSTRINTSTAT_THR(n)         (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = (BFM_IOMSTR_IOMSTRINTSTAT_THR) )

#define BFP_IOMSTR_IOMSTRINTSTAT_CMDCMP         (0)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSTAT_CMDCMP         ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSTAT_CMDCMP         (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSTAT_CMDCMP         (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSTAT_CMDCMP(v)      ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSTAT_CMDCMP)) & (BFM_IOMSTR_IOMSTRINTSTAT_CMDCMP))
#define BFX_IOMSTR_IOMSTRINTSTAT_CMDCMP(v)      ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSTAT_CMDCMP)) >> (BFP_IOMSTR_IOMSTRINTSTAT_CMDCMP))
#define BFW_IOMSTR_IOMSTRINTSTAT_CMDCMP(n,v)    (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = ( (REG_IOMSTR_IOMSTRINTSTAT(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSTAT_CMDCMP)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSTAT_CMDCMP)) & (BFM_IOMSTR_IOMSTRINTSTAT_CMDCMP)) ))
#define BFR_IOMSTR_IOMSTRINTSTAT_CMDCMP(n)      ((REG_IOMSTR_IOMSTRINTSTAT(n).U32 & (BFM_IOMSTR_IOMSTRINTSTAT_CMDCMP))>>(BFP_IOMSTR_IOMSTRINTSTAT_CMDCMP))
#define BFS_IOMSTR_IOMSTRINTSTAT_CMDCMP(n)      (REG_IOMSTR_IOMSTRINTSTAT(n).U32 = (BFM_IOMSTR_IOMSTRINTSTAT_CMDCMP) )


// *****************************************************************************
//                                                                             *
//  IOMSTR_IOMSTRINTCLR - IO Master Interrupts                                 *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_11                    : 21;
        unsigned ARB                        :  1;
        unsigned STOP                       :  1;
        unsigned START                      :  1;
        unsigned ICMD                       :  1;
        unsigned IACC                       :  1;
        unsigned WTLEN                      :  1;
        unsigned NAK                        :  1;
        unsigned FOVFL                      :  1;
        unsigned FUNDFL                     :  1;
        unsigned THR                        :  1;
        unsigned CMDCMP                     :  1;
    } B;
} reg_iomstr_iomstrintclr_t;

#define REG_IOMSTR_IOMSTRINTCLR_ADDR(n)         (REG_IOMSTR_BASEADDR + (n*0x1000) + 0x00000208UL)
#define REG_IOMSTR_IOMSTRINTCLR(n)              (*(volatile reg_iomstr_iomstrintclr_t *) REG_IOMSTR_IOMSTRINTCLR_ADDR(n))
#define REG_IOMSTR_IOMSTRINTCLR_RD(n)           (REG_IOMSTR_IOMSTRINTCLR(n).U32)
#define REG_IOMSTR_IOMSTRINTCLR_WR(n,v)         (REG_IOMSTR_IOMSTRINTCLR(n).U32 = (v))
#define REG_IOMSTR_IOMSTRINTCLR_CLR(n,m)        (REG_IOMSTR_IOMSTRINTCLR(n).U32 = ((REG_IOMSTR_IOMSTRINTCLR(n).U32) & ~(m)))
#define REG_IOMSTR_IOMSTRINTCLR_SET(n,m)        (REG_IOMSTR_IOMSTRINTCLR(n).U32 = ((REG_IOMSTR_IOMSTRINTCLR(n).U32) | (m)))
#define REG_IOMSTR_IOMSTRINTCLR_DEF             0x00000000

#define BFP_IOMSTR_IOMSTRINTCLR_RSVD_11         (11)                    /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTCLR_RSVD_11         ((uint32_t)0xfffff800)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTCLR_RSVD_11         (21)                    /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTCLR_RSVD_11         (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTCLR_RSVD_11(v)      ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTCLR_RSVD_11)) & (BFM_IOMSTR_IOMSTRINTCLR_RSVD_11))
#define BFX_IOMSTR_IOMSTRINTCLR_RSVD_11(v)      ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTCLR_RSVD_11)) >> (BFP_IOMSTR_IOMSTRINTCLR_RSVD_11))
#define BFW_IOMSTR_IOMSTRINTCLR_RSVD_11(n,v)    (REG_IOMSTR_IOMSTRINTCLR(n).U32 = ( (REG_IOMSTR_IOMSTRINTCLR(n).U32 & ~(BFM_IOMSTR_IOMSTRINTCLR_RSVD_11)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTCLR_RSVD_11)) & (BFM_IOMSTR_IOMSTRINTCLR_RSVD_11)) ))
#define BFR_IOMSTR_IOMSTRINTCLR_RSVD_11(n)      ((REG_IOMSTR_IOMSTRINTCLR(n).U32 & (BFM_IOMSTR_IOMSTRINTCLR_RSVD_11))>>(BFP_IOMSTR_IOMSTRINTCLR_RSVD_11))
#define BFS_IOMSTR_IOMSTRINTCLR_RSVD_11(n)      (REG_IOMSTR_IOMSTRINTCLR(n).U32 = (BFM_IOMSTR_IOMSTRINTCLR_RSVD_11) )

#define BFP_IOMSTR_IOMSTRINTCLR_ARB             (10)                    /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTCLR_ARB             ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTCLR_ARB             (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTCLR_ARB             (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTCLR_ARB(v)          ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTCLR_ARB)) & (BFM_IOMSTR_IOMSTRINTCLR_ARB))
#define BFX_IOMSTR_IOMSTRINTCLR_ARB(v)          ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTCLR_ARB)) >> (BFP_IOMSTR_IOMSTRINTCLR_ARB))
#define BFW_IOMSTR_IOMSTRINTCLR_ARB(n,v)        (REG_IOMSTR_IOMSTRINTCLR(n).U32 = ( (REG_IOMSTR_IOMSTRINTCLR(n).U32 & ~(BFM_IOMSTR_IOMSTRINTCLR_ARB)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTCLR_ARB)) & (BFM_IOMSTR_IOMSTRINTCLR_ARB)) ))
#define BFR_IOMSTR_IOMSTRINTCLR_ARB(n)          ((REG_IOMSTR_IOMSTRINTCLR(n).U32 & (BFM_IOMSTR_IOMSTRINTCLR_ARB))>>(BFP_IOMSTR_IOMSTRINTCLR_ARB))
#define BFS_IOMSTR_IOMSTRINTCLR_ARB(n)          (REG_IOMSTR_IOMSTRINTCLR(n).U32 = (BFM_IOMSTR_IOMSTRINTCLR_ARB) )

#define BFP_IOMSTR_IOMSTRINTCLR_STOP            (9)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTCLR_STOP            ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTCLR_STOP            (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTCLR_STOP            (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTCLR_STOP(v)         ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTCLR_STOP)) & (BFM_IOMSTR_IOMSTRINTCLR_STOP))
#define BFX_IOMSTR_IOMSTRINTCLR_STOP(v)         ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTCLR_STOP)) >> (BFP_IOMSTR_IOMSTRINTCLR_STOP))
#define BFW_IOMSTR_IOMSTRINTCLR_STOP(n,v)       (REG_IOMSTR_IOMSTRINTCLR(n).U32 = ( (REG_IOMSTR_IOMSTRINTCLR(n).U32 & ~(BFM_IOMSTR_IOMSTRINTCLR_STOP)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTCLR_STOP)) & (BFM_IOMSTR_IOMSTRINTCLR_STOP)) ))
#define BFR_IOMSTR_IOMSTRINTCLR_STOP(n)         ((REG_IOMSTR_IOMSTRINTCLR(n).U32 & (BFM_IOMSTR_IOMSTRINTCLR_STOP))>>(BFP_IOMSTR_IOMSTRINTCLR_STOP))
#define BFS_IOMSTR_IOMSTRINTCLR_STOP(n)         (REG_IOMSTR_IOMSTRINTCLR(n).U32 = (BFM_IOMSTR_IOMSTRINTCLR_STOP) )

#define BFP_IOMSTR_IOMSTRINTCLR_START           (8)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTCLR_START           ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTCLR_START           (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTCLR_START           (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTCLR_START(v)        ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTCLR_START)) & (BFM_IOMSTR_IOMSTRINTCLR_START))
#define BFX_IOMSTR_IOMSTRINTCLR_START(v)        ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTCLR_START)) >> (BFP_IOMSTR_IOMSTRINTCLR_START))
#define BFW_IOMSTR_IOMSTRINTCLR_START(n,v)      (REG_IOMSTR_IOMSTRINTCLR(n).U32 = ( (REG_IOMSTR_IOMSTRINTCLR(n).U32 & ~(BFM_IOMSTR_IOMSTRINTCLR_START)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTCLR_START)) & (BFM_IOMSTR_IOMSTRINTCLR_START)) ))
#define BFR_IOMSTR_IOMSTRINTCLR_START(n)        ((REG_IOMSTR_IOMSTRINTCLR(n).U32 & (BFM_IOMSTR_IOMSTRINTCLR_START))>>(BFP_IOMSTR_IOMSTRINTCLR_START))
#define BFS_IOMSTR_IOMSTRINTCLR_START(n)        (REG_IOMSTR_IOMSTRINTCLR(n).U32 = (BFM_IOMSTR_IOMSTRINTCLR_START) )

#define BFP_IOMSTR_IOMSTRINTCLR_ICMD            (7)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTCLR_ICMD            ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTCLR_ICMD            (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTCLR_ICMD            (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTCLR_ICMD(v)         ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTCLR_ICMD)) & (BFM_IOMSTR_IOMSTRINTCLR_ICMD))
#define BFX_IOMSTR_IOMSTRINTCLR_ICMD(v)         ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTCLR_ICMD)) >> (BFP_IOMSTR_IOMSTRINTCLR_ICMD))
#define BFW_IOMSTR_IOMSTRINTCLR_ICMD(n,v)       (REG_IOMSTR_IOMSTRINTCLR(n).U32 = ( (REG_IOMSTR_IOMSTRINTCLR(n).U32 & ~(BFM_IOMSTR_IOMSTRINTCLR_ICMD)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTCLR_ICMD)) & (BFM_IOMSTR_IOMSTRINTCLR_ICMD)) ))
#define BFR_IOMSTR_IOMSTRINTCLR_ICMD(n)         ((REG_IOMSTR_IOMSTRINTCLR(n).U32 & (BFM_IOMSTR_IOMSTRINTCLR_ICMD))>>(BFP_IOMSTR_IOMSTRINTCLR_ICMD))
#define BFS_IOMSTR_IOMSTRINTCLR_ICMD(n)         (REG_IOMSTR_IOMSTRINTCLR(n).U32 = (BFM_IOMSTR_IOMSTRINTCLR_ICMD) )

#define BFP_IOMSTR_IOMSTRINTCLR_IACC            (6)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTCLR_IACC            ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTCLR_IACC            (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTCLR_IACC            (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTCLR_IACC(v)         ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTCLR_IACC)) & (BFM_IOMSTR_IOMSTRINTCLR_IACC))
#define BFX_IOMSTR_IOMSTRINTCLR_IACC(v)         ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTCLR_IACC)) >> (BFP_IOMSTR_IOMSTRINTCLR_IACC))
#define BFW_IOMSTR_IOMSTRINTCLR_IACC(n,v)       (REG_IOMSTR_IOMSTRINTCLR(n).U32 = ( (REG_IOMSTR_IOMSTRINTCLR(n).U32 & ~(BFM_IOMSTR_IOMSTRINTCLR_IACC)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTCLR_IACC)) & (BFM_IOMSTR_IOMSTRINTCLR_IACC)) ))
#define BFR_IOMSTR_IOMSTRINTCLR_IACC(n)         ((REG_IOMSTR_IOMSTRINTCLR(n).U32 & (BFM_IOMSTR_IOMSTRINTCLR_IACC))>>(BFP_IOMSTR_IOMSTRINTCLR_IACC))
#define BFS_IOMSTR_IOMSTRINTCLR_IACC(n)         (REG_IOMSTR_IOMSTRINTCLR(n).U32 = (BFM_IOMSTR_IOMSTRINTCLR_IACC) )

#define BFP_IOMSTR_IOMSTRINTCLR_WTLEN           (5)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTCLR_WTLEN           ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTCLR_WTLEN           (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTCLR_WTLEN           (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTCLR_WTLEN(v)        ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTCLR_WTLEN)) & (BFM_IOMSTR_IOMSTRINTCLR_WTLEN))
#define BFX_IOMSTR_IOMSTRINTCLR_WTLEN(v)        ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTCLR_WTLEN)) >> (BFP_IOMSTR_IOMSTRINTCLR_WTLEN))
#define BFW_IOMSTR_IOMSTRINTCLR_WTLEN(n,v)      (REG_IOMSTR_IOMSTRINTCLR(n).U32 = ( (REG_IOMSTR_IOMSTRINTCLR(n).U32 & ~(BFM_IOMSTR_IOMSTRINTCLR_WTLEN)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTCLR_WTLEN)) & (BFM_IOMSTR_IOMSTRINTCLR_WTLEN)) ))
#define BFR_IOMSTR_IOMSTRINTCLR_WTLEN(n)        ((REG_IOMSTR_IOMSTRINTCLR(n).U32 & (BFM_IOMSTR_IOMSTRINTCLR_WTLEN))>>(BFP_IOMSTR_IOMSTRINTCLR_WTLEN))
#define BFS_IOMSTR_IOMSTRINTCLR_WTLEN(n)        (REG_IOMSTR_IOMSTRINTCLR(n).U32 = (BFM_IOMSTR_IOMSTRINTCLR_WTLEN) )

#define BFP_IOMSTR_IOMSTRINTCLR_NAK             (4)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTCLR_NAK             ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTCLR_NAK             (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTCLR_NAK             (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTCLR_NAK(v)          ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTCLR_NAK)) & (BFM_IOMSTR_IOMSTRINTCLR_NAK))
#define BFX_IOMSTR_IOMSTRINTCLR_NAK(v)          ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTCLR_NAK)) >> (BFP_IOMSTR_IOMSTRINTCLR_NAK))
#define BFW_IOMSTR_IOMSTRINTCLR_NAK(n,v)        (REG_IOMSTR_IOMSTRINTCLR(n).U32 = ( (REG_IOMSTR_IOMSTRINTCLR(n).U32 & ~(BFM_IOMSTR_IOMSTRINTCLR_NAK)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTCLR_NAK)) & (BFM_IOMSTR_IOMSTRINTCLR_NAK)) ))
#define BFR_IOMSTR_IOMSTRINTCLR_NAK(n)          ((REG_IOMSTR_IOMSTRINTCLR(n).U32 & (BFM_IOMSTR_IOMSTRINTCLR_NAK))>>(BFP_IOMSTR_IOMSTRINTCLR_NAK))
#define BFS_IOMSTR_IOMSTRINTCLR_NAK(n)          (REG_IOMSTR_IOMSTRINTCLR(n).U32 = (BFM_IOMSTR_IOMSTRINTCLR_NAK) )

#define BFP_IOMSTR_IOMSTRINTCLR_FOVFL           (3)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTCLR_FOVFL           ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTCLR_FOVFL           (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTCLR_FOVFL           (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTCLR_FOVFL(v)        ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTCLR_FOVFL)) & (BFM_IOMSTR_IOMSTRINTCLR_FOVFL))
#define BFX_IOMSTR_IOMSTRINTCLR_FOVFL(v)        ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTCLR_FOVFL)) >> (BFP_IOMSTR_IOMSTRINTCLR_FOVFL))
#define BFW_IOMSTR_IOMSTRINTCLR_FOVFL(n,v)      (REG_IOMSTR_IOMSTRINTCLR(n).U32 = ( (REG_IOMSTR_IOMSTRINTCLR(n).U32 & ~(BFM_IOMSTR_IOMSTRINTCLR_FOVFL)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTCLR_FOVFL)) & (BFM_IOMSTR_IOMSTRINTCLR_FOVFL)) ))
#define BFR_IOMSTR_IOMSTRINTCLR_FOVFL(n)        ((REG_IOMSTR_IOMSTRINTCLR(n).U32 & (BFM_IOMSTR_IOMSTRINTCLR_FOVFL))>>(BFP_IOMSTR_IOMSTRINTCLR_FOVFL))
#define BFS_IOMSTR_IOMSTRINTCLR_FOVFL(n)        (REG_IOMSTR_IOMSTRINTCLR(n).U32 = (BFM_IOMSTR_IOMSTRINTCLR_FOVFL) )

#define BFP_IOMSTR_IOMSTRINTCLR_FUNDFL          (2)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTCLR_FUNDFL          ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTCLR_FUNDFL          (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTCLR_FUNDFL          (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTCLR_FUNDFL(v)       ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTCLR_FUNDFL)) & (BFM_IOMSTR_IOMSTRINTCLR_FUNDFL))
#define BFX_IOMSTR_IOMSTRINTCLR_FUNDFL(v)       ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTCLR_FUNDFL)) >> (BFP_IOMSTR_IOMSTRINTCLR_FUNDFL))
#define BFW_IOMSTR_IOMSTRINTCLR_FUNDFL(n,v)     (REG_IOMSTR_IOMSTRINTCLR(n).U32 = ( (REG_IOMSTR_IOMSTRINTCLR(n).U32 & ~(BFM_IOMSTR_IOMSTRINTCLR_FUNDFL)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTCLR_FUNDFL)) & (BFM_IOMSTR_IOMSTRINTCLR_FUNDFL)) ))
#define BFR_IOMSTR_IOMSTRINTCLR_FUNDFL(n)       ((REG_IOMSTR_IOMSTRINTCLR(n).U32 & (BFM_IOMSTR_IOMSTRINTCLR_FUNDFL))>>(BFP_IOMSTR_IOMSTRINTCLR_FUNDFL))
#define BFS_IOMSTR_IOMSTRINTCLR_FUNDFL(n)       (REG_IOMSTR_IOMSTRINTCLR(n).U32 = (BFM_IOMSTR_IOMSTRINTCLR_FUNDFL) )

#define BFP_IOMSTR_IOMSTRINTCLR_THR             (1)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTCLR_THR             ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTCLR_THR             (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTCLR_THR             (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTCLR_THR(v)          ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTCLR_THR)) & (BFM_IOMSTR_IOMSTRINTCLR_THR))
#define BFX_IOMSTR_IOMSTRINTCLR_THR(v)          ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTCLR_THR)) >> (BFP_IOMSTR_IOMSTRINTCLR_THR))
#define BFW_IOMSTR_IOMSTRINTCLR_THR(n,v)        (REG_IOMSTR_IOMSTRINTCLR(n).U32 = ( (REG_IOMSTR_IOMSTRINTCLR(n).U32 & ~(BFM_IOMSTR_IOMSTRINTCLR_THR)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTCLR_THR)) & (BFM_IOMSTR_IOMSTRINTCLR_THR)) ))
#define BFR_IOMSTR_IOMSTRINTCLR_THR(n)          ((REG_IOMSTR_IOMSTRINTCLR(n).U32 & (BFM_IOMSTR_IOMSTRINTCLR_THR))>>(BFP_IOMSTR_IOMSTRINTCLR_THR))
#define BFS_IOMSTR_IOMSTRINTCLR_THR(n)          (REG_IOMSTR_IOMSTRINTCLR(n).U32 = (BFM_IOMSTR_IOMSTRINTCLR_THR) )

#define BFP_IOMSTR_IOMSTRINTCLR_CMDCMP          (0)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTCLR_CMDCMP          ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTCLR_CMDCMP          (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTCLR_CMDCMP          (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTCLR_CMDCMP(v)       ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTCLR_CMDCMP)) & (BFM_IOMSTR_IOMSTRINTCLR_CMDCMP))
#define BFX_IOMSTR_IOMSTRINTCLR_CMDCMP(v)       ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTCLR_CMDCMP)) >> (BFP_IOMSTR_IOMSTRINTCLR_CMDCMP))
#define BFW_IOMSTR_IOMSTRINTCLR_CMDCMP(n,v)     (REG_IOMSTR_IOMSTRINTCLR(n).U32 = ( (REG_IOMSTR_IOMSTRINTCLR(n).U32 & ~(BFM_IOMSTR_IOMSTRINTCLR_CMDCMP)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTCLR_CMDCMP)) & (BFM_IOMSTR_IOMSTRINTCLR_CMDCMP)) ))
#define BFR_IOMSTR_IOMSTRINTCLR_CMDCMP(n)       ((REG_IOMSTR_IOMSTRINTCLR(n).U32 & (BFM_IOMSTR_IOMSTRINTCLR_CMDCMP))>>(BFP_IOMSTR_IOMSTRINTCLR_CMDCMP))
#define BFS_IOMSTR_IOMSTRINTCLR_CMDCMP(n)       (REG_IOMSTR_IOMSTRINTCLR(n).U32 = (BFM_IOMSTR_IOMSTRINTCLR_CMDCMP) )


// *****************************************************************************
//                                                                             *
//  IOMSTR_IOMSTRINTSET - IO Master Interrupts                                 *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_11                    : 21;
        unsigned ARB                        :  1;
        unsigned STOP                       :  1;
        unsigned START                      :  1;
        unsigned ICMD                       :  1;
        unsigned IACC                       :  1;
        unsigned WTLEN                      :  1;
        unsigned NAK                        :  1;
        unsigned FOVFL                      :  1;
        unsigned FUNDFL                     :  1;
        unsigned THR                        :  1;
        unsigned CMDCMP                     :  1;
    } B;
} reg_iomstr_iomstrintset_t;

#define REG_IOMSTR_IOMSTRINTSET_ADDR(n)         (REG_IOMSTR_BASEADDR + (n*0x1000) + 0x0000020CUL)
#define REG_IOMSTR_IOMSTRINTSET(n)              (*(volatile reg_iomstr_iomstrintset_t *) REG_IOMSTR_IOMSTRINTSET_ADDR(n))
#define REG_IOMSTR_IOMSTRINTSET_RD(n)           (REG_IOMSTR_IOMSTRINTSET(n).U32)
#define REG_IOMSTR_IOMSTRINTSET_WR(n,v)         (REG_IOMSTR_IOMSTRINTSET(n).U32 = (v))
#define REG_IOMSTR_IOMSTRINTSET_CLR(n,m)        (REG_IOMSTR_IOMSTRINTSET(n).U32 = ((REG_IOMSTR_IOMSTRINTSET(n).U32) & ~(m)))
#define REG_IOMSTR_IOMSTRINTSET_SET(n,m)        (REG_IOMSTR_IOMSTRINTSET(n).U32 = ((REG_IOMSTR_IOMSTRINTSET(n).U32) | (m)))
#define REG_IOMSTR_IOMSTRINTSET_DEF             0x00000000

#define BFP_IOMSTR_IOMSTRINTSET_RSVD_11         (11)                    /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSET_RSVD_11         ((uint32_t)0xfffff800)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSET_RSVD_11         (21)                    /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSET_RSVD_11         (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSET_RSVD_11(v)      ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSET_RSVD_11)) & (BFM_IOMSTR_IOMSTRINTSET_RSVD_11))
#define BFX_IOMSTR_IOMSTRINTSET_RSVD_11(v)      ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSET_RSVD_11)) >> (BFP_IOMSTR_IOMSTRINTSET_RSVD_11))
#define BFW_IOMSTR_IOMSTRINTSET_RSVD_11(n,v)    (REG_IOMSTR_IOMSTRINTSET(n).U32 = ( (REG_IOMSTR_IOMSTRINTSET(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSET_RSVD_11)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSET_RSVD_11)) & (BFM_IOMSTR_IOMSTRINTSET_RSVD_11)) ))
#define BFR_IOMSTR_IOMSTRINTSET_RSVD_11(n)      ((REG_IOMSTR_IOMSTRINTSET(n).U32 & (BFM_IOMSTR_IOMSTRINTSET_RSVD_11))>>(BFP_IOMSTR_IOMSTRINTSET_RSVD_11))
#define BFS_IOMSTR_IOMSTRINTSET_RSVD_11(n)      (REG_IOMSTR_IOMSTRINTSET(n).U32 = (BFM_IOMSTR_IOMSTRINTSET_RSVD_11) )

#define BFP_IOMSTR_IOMSTRINTSET_ARB             (10)                    /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSET_ARB             ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSET_ARB             (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSET_ARB             (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSET_ARB(v)          ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSET_ARB)) & (BFM_IOMSTR_IOMSTRINTSET_ARB))
#define BFX_IOMSTR_IOMSTRINTSET_ARB(v)          ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSET_ARB)) >> (BFP_IOMSTR_IOMSTRINTSET_ARB))
#define BFW_IOMSTR_IOMSTRINTSET_ARB(n,v)        (REG_IOMSTR_IOMSTRINTSET(n).U32 = ( (REG_IOMSTR_IOMSTRINTSET(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSET_ARB)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSET_ARB)) & (BFM_IOMSTR_IOMSTRINTSET_ARB)) ))
#define BFR_IOMSTR_IOMSTRINTSET_ARB(n)          ((REG_IOMSTR_IOMSTRINTSET(n).U32 & (BFM_IOMSTR_IOMSTRINTSET_ARB))>>(BFP_IOMSTR_IOMSTRINTSET_ARB))
#define BFS_IOMSTR_IOMSTRINTSET_ARB(n)          (REG_IOMSTR_IOMSTRINTSET(n).U32 = (BFM_IOMSTR_IOMSTRINTSET_ARB) )

#define BFP_IOMSTR_IOMSTRINTSET_STOP            (9)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSET_STOP            ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSET_STOP            (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSET_STOP            (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSET_STOP(v)         ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSET_STOP)) & (BFM_IOMSTR_IOMSTRINTSET_STOP))
#define BFX_IOMSTR_IOMSTRINTSET_STOP(v)         ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSET_STOP)) >> (BFP_IOMSTR_IOMSTRINTSET_STOP))
#define BFW_IOMSTR_IOMSTRINTSET_STOP(n,v)       (REG_IOMSTR_IOMSTRINTSET(n).U32 = ( (REG_IOMSTR_IOMSTRINTSET(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSET_STOP)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSET_STOP)) & (BFM_IOMSTR_IOMSTRINTSET_STOP)) ))
#define BFR_IOMSTR_IOMSTRINTSET_STOP(n)         ((REG_IOMSTR_IOMSTRINTSET(n).U32 & (BFM_IOMSTR_IOMSTRINTSET_STOP))>>(BFP_IOMSTR_IOMSTRINTSET_STOP))
#define BFS_IOMSTR_IOMSTRINTSET_STOP(n)         (REG_IOMSTR_IOMSTRINTSET(n).U32 = (BFM_IOMSTR_IOMSTRINTSET_STOP) )

#define BFP_IOMSTR_IOMSTRINTSET_START           (8)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSET_START           ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSET_START           (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSET_START           (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSET_START(v)        ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSET_START)) & (BFM_IOMSTR_IOMSTRINTSET_START))
#define BFX_IOMSTR_IOMSTRINTSET_START(v)        ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSET_START)) >> (BFP_IOMSTR_IOMSTRINTSET_START))
#define BFW_IOMSTR_IOMSTRINTSET_START(n,v)      (REG_IOMSTR_IOMSTRINTSET(n).U32 = ( (REG_IOMSTR_IOMSTRINTSET(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSET_START)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSET_START)) & (BFM_IOMSTR_IOMSTRINTSET_START)) ))
#define BFR_IOMSTR_IOMSTRINTSET_START(n)        ((REG_IOMSTR_IOMSTRINTSET(n).U32 & (BFM_IOMSTR_IOMSTRINTSET_START))>>(BFP_IOMSTR_IOMSTRINTSET_START))
#define BFS_IOMSTR_IOMSTRINTSET_START(n)        (REG_IOMSTR_IOMSTRINTSET(n).U32 = (BFM_IOMSTR_IOMSTRINTSET_START) )

#define BFP_IOMSTR_IOMSTRINTSET_ICMD            (7)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSET_ICMD            ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSET_ICMD            (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSET_ICMD            (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSET_ICMD(v)         ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSET_ICMD)) & (BFM_IOMSTR_IOMSTRINTSET_ICMD))
#define BFX_IOMSTR_IOMSTRINTSET_ICMD(v)         ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSET_ICMD)) >> (BFP_IOMSTR_IOMSTRINTSET_ICMD))
#define BFW_IOMSTR_IOMSTRINTSET_ICMD(n,v)       (REG_IOMSTR_IOMSTRINTSET(n).U32 = ( (REG_IOMSTR_IOMSTRINTSET(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSET_ICMD)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSET_ICMD)) & (BFM_IOMSTR_IOMSTRINTSET_ICMD)) ))
#define BFR_IOMSTR_IOMSTRINTSET_ICMD(n)         ((REG_IOMSTR_IOMSTRINTSET(n).U32 & (BFM_IOMSTR_IOMSTRINTSET_ICMD))>>(BFP_IOMSTR_IOMSTRINTSET_ICMD))
#define BFS_IOMSTR_IOMSTRINTSET_ICMD(n)         (REG_IOMSTR_IOMSTRINTSET(n).U32 = (BFM_IOMSTR_IOMSTRINTSET_ICMD) )

#define BFP_IOMSTR_IOMSTRINTSET_IACC            (6)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSET_IACC            ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSET_IACC            (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSET_IACC            (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSET_IACC(v)         ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSET_IACC)) & (BFM_IOMSTR_IOMSTRINTSET_IACC))
#define BFX_IOMSTR_IOMSTRINTSET_IACC(v)         ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSET_IACC)) >> (BFP_IOMSTR_IOMSTRINTSET_IACC))
#define BFW_IOMSTR_IOMSTRINTSET_IACC(n,v)       (REG_IOMSTR_IOMSTRINTSET(n).U32 = ( (REG_IOMSTR_IOMSTRINTSET(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSET_IACC)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSET_IACC)) & (BFM_IOMSTR_IOMSTRINTSET_IACC)) ))
#define BFR_IOMSTR_IOMSTRINTSET_IACC(n)         ((REG_IOMSTR_IOMSTRINTSET(n).U32 & (BFM_IOMSTR_IOMSTRINTSET_IACC))>>(BFP_IOMSTR_IOMSTRINTSET_IACC))
#define BFS_IOMSTR_IOMSTRINTSET_IACC(n)         (REG_IOMSTR_IOMSTRINTSET(n).U32 = (BFM_IOMSTR_IOMSTRINTSET_IACC) )

#define BFP_IOMSTR_IOMSTRINTSET_WTLEN           (5)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSET_WTLEN           ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSET_WTLEN           (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSET_WTLEN           (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSET_WTLEN(v)        ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSET_WTLEN)) & (BFM_IOMSTR_IOMSTRINTSET_WTLEN))
#define BFX_IOMSTR_IOMSTRINTSET_WTLEN(v)        ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSET_WTLEN)) >> (BFP_IOMSTR_IOMSTRINTSET_WTLEN))
#define BFW_IOMSTR_IOMSTRINTSET_WTLEN(n,v)      (REG_IOMSTR_IOMSTRINTSET(n).U32 = ( (REG_IOMSTR_IOMSTRINTSET(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSET_WTLEN)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSET_WTLEN)) & (BFM_IOMSTR_IOMSTRINTSET_WTLEN)) ))
#define BFR_IOMSTR_IOMSTRINTSET_WTLEN(n)        ((REG_IOMSTR_IOMSTRINTSET(n).U32 & (BFM_IOMSTR_IOMSTRINTSET_WTLEN))>>(BFP_IOMSTR_IOMSTRINTSET_WTLEN))
#define BFS_IOMSTR_IOMSTRINTSET_WTLEN(n)        (REG_IOMSTR_IOMSTRINTSET(n).U32 = (BFM_IOMSTR_IOMSTRINTSET_WTLEN) )

#define BFP_IOMSTR_IOMSTRINTSET_NAK             (4)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSET_NAK             ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSET_NAK             (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSET_NAK             (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSET_NAK(v)          ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSET_NAK)) & (BFM_IOMSTR_IOMSTRINTSET_NAK))
#define BFX_IOMSTR_IOMSTRINTSET_NAK(v)          ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSET_NAK)) >> (BFP_IOMSTR_IOMSTRINTSET_NAK))
#define BFW_IOMSTR_IOMSTRINTSET_NAK(n,v)        (REG_IOMSTR_IOMSTRINTSET(n).U32 = ( (REG_IOMSTR_IOMSTRINTSET(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSET_NAK)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSET_NAK)) & (BFM_IOMSTR_IOMSTRINTSET_NAK)) ))
#define BFR_IOMSTR_IOMSTRINTSET_NAK(n)          ((REG_IOMSTR_IOMSTRINTSET(n).U32 & (BFM_IOMSTR_IOMSTRINTSET_NAK))>>(BFP_IOMSTR_IOMSTRINTSET_NAK))
#define BFS_IOMSTR_IOMSTRINTSET_NAK(n)          (REG_IOMSTR_IOMSTRINTSET(n).U32 = (BFM_IOMSTR_IOMSTRINTSET_NAK) )

#define BFP_IOMSTR_IOMSTRINTSET_FOVFL           (3)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSET_FOVFL           ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSET_FOVFL           (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSET_FOVFL           (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSET_FOVFL(v)        ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSET_FOVFL)) & (BFM_IOMSTR_IOMSTRINTSET_FOVFL))
#define BFX_IOMSTR_IOMSTRINTSET_FOVFL(v)        ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSET_FOVFL)) >> (BFP_IOMSTR_IOMSTRINTSET_FOVFL))
#define BFW_IOMSTR_IOMSTRINTSET_FOVFL(n,v)      (REG_IOMSTR_IOMSTRINTSET(n).U32 = ( (REG_IOMSTR_IOMSTRINTSET(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSET_FOVFL)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSET_FOVFL)) & (BFM_IOMSTR_IOMSTRINTSET_FOVFL)) ))
#define BFR_IOMSTR_IOMSTRINTSET_FOVFL(n)        ((REG_IOMSTR_IOMSTRINTSET(n).U32 & (BFM_IOMSTR_IOMSTRINTSET_FOVFL))>>(BFP_IOMSTR_IOMSTRINTSET_FOVFL))
#define BFS_IOMSTR_IOMSTRINTSET_FOVFL(n)        (REG_IOMSTR_IOMSTRINTSET(n).U32 = (BFM_IOMSTR_IOMSTRINTSET_FOVFL) )

#define BFP_IOMSTR_IOMSTRINTSET_FUNDFL          (2)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSET_FUNDFL          ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSET_FUNDFL          (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSET_FUNDFL          (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSET_FUNDFL(v)       ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSET_FUNDFL)) & (BFM_IOMSTR_IOMSTRINTSET_FUNDFL))
#define BFX_IOMSTR_IOMSTRINTSET_FUNDFL(v)       ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSET_FUNDFL)) >> (BFP_IOMSTR_IOMSTRINTSET_FUNDFL))
#define BFW_IOMSTR_IOMSTRINTSET_FUNDFL(n,v)     (REG_IOMSTR_IOMSTRINTSET(n).U32 = ( (REG_IOMSTR_IOMSTRINTSET(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSET_FUNDFL)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSET_FUNDFL)) & (BFM_IOMSTR_IOMSTRINTSET_FUNDFL)) ))
#define BFR_IOMSTR_IOMSTRINTSET_FUNDFL(n)       ((REG_IOMSTR_IOMSTRINTSET(n).U32 & (BFM_IOMSTR_IOMSTRINTSET_FUNDFL))>>(BFP_IOMSTR_IOMSTRINTSET_FUNDFL))
#define BFS_IOMSTR_IOMSTRINTSET_FUNDFL(n)       (REG_IOMSTR_IOMSTRINTSET(n).U32 = (BFM_IOMSTR_IOMSTRINTSET_FUNDFL) )

#define BFP_IOMSTR_IOMSTRINTSET_THR             (1)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSET_THR             ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSET_THR             (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSET_THR             (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSET_THR(v)          ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSET_THR)) & (BFM_IOMSTR_IOMSTRINTSET_THR))
#define BFX_IOMSTR_IOMSTRINTSET_THR(v)          ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSET_THR)) >> (BFP_IOMSTR_IOMSTRINTSET_THR))
#define BFW_IOMSTR_IOMSTRINTSET_THR(n,v)        (REG_IOMSTR_IOMSTRINTSET(n).U32 = ( (REG_IOMSTR_IOMSTRINTSET(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSET_THR)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSET_THR)) & (BFM_IOMSTR_IOMSTRINTSET_THR)) ))
#define BFR_IOMSTR_IOMSTRINTSET_THR(n)          ((REG_IOMSTR_IOMSTRINTSET(n).U32 & (BFM_IOMSTR_IOMSTRINTSET_THR))>>(BFP_IOMSTR_IOMSTRINTSET_THR))
#define BFS_IOMSTR_IOMSTRINTSET_THR(n)          (REG_IOMSTR_IOMSTRINTSET(n).U32 = (BFM_IOMSTR_IOMSTRINTSET_THR) )

#define BFP_IOMSTR_IOMSTRINTSET_CMDCMP          (0)                     /* bitfield lsb */
#define BFM_IOMSTR_IOMSTRINTSET_CMDCMP          ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_IOMSTR_IOMSTRINTSET_CMDCMP          (1)                     /* bitfield width */
#define BFD_IOMSTR_IOMSTRINTSET_CMDCMP          (0x0)                   /* bitfield default value */
#define BFV_IOMSTR_IOMSTRINTSET_CMDCMP(v)       ((((uint32_t) v) << (BFP_IOMSTR_IOMSTRINTSET_CMDCMP)) & (BFM_IOMSTR_IOMSTRINTSET_CMDCMP))
#define BFX_IOMSTR_IOMSTRINTSET_CMDCMP(v)       ((((uint32_t) v) & (BFM_IOMSTR_IOMSTRINTSET_CMDCMP)) >> (BFP_IOMSTR_IOMSTRINTSET_CMDCMP))
#define BFW_IOMSTR_IOMSTRINTSET_CMDCMP(n,v)     (REG_IOMSTR_IOMSTRINTSET(n).U32 = ( (REG_IOMSTR_IOMSTRINTSET(n).U32 & ~(BFM_IOMSTR_IOMSTRINTSET_CMDCMP)) | ((((uint32_t) v)<<(BFP_IOMSTR_IOMSTRINTSET_CMDCMP)) & (BFM_IOMSTR_IOMSTRINTSET_CMDCMP)) ))
#define BFR_IOMSTR_IOMSTRINTSET_CMDCMP(n)       ((REG_IOMSTR_IOMSTRINTSET(n).U32 & (BFM_IOMSTR_IOMSTRINTSET_CMDCMP))>>(BFP_IOMSTR_IOMSTRINTSET_CMDCMP))
#define BFS_IOMSTR_IOMSTRINTSET_CMDCMP(n)       (REG_IOMSTR_IOMSTRINTSET(n).U32 = (BFM_IOMSTR_IOMSTRINTSET_CMDCMP) )


// the following were hand generated by RH

//
// *************************************
// IOMSTR I2C command definitions
// *************************************
//      |31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|15|14|13|12|11|10| 9| 8| 7| 6| 5| 4| 3| 2| 1| 0|
//  I2C |--OPER--|CT|LB|10|--------|-------ADDRESS------|------- OFFSET --------|-------- LENGTH -------|
//  SPI |--OPER--|CT|LB|--UPLNGTH--|-- Rsvd ---|--CHN---|Rv|---- OFFSET --------|-------- LENGTH -------|
//  OPER: Write: 000, Read 100, Write Raw 010, Read Raw 110 (bit30 indicates RAW, IOMSTR_CMD_RAW)
//  I2C CMD fields: OPER, CONT, LSB, 10BIT, ADDRESS (7 or 10 bits), OFFSET, LENGTH
//  SPI CMD fields: OPER, CONT, LSB, UPLNGTH, Rsvd, CHANNEL, Rsvd, OFFSET, LENGTH
//                  SPI length is 10 bits, [26:25][7:0].
//  ** SPI OFFSET is 7 bits (bit15 is RSVD), I2C OFFSET is 8 bits.
//
#define BFP_IOMSTR_CMD_LENGTH           (0)
#define BFP_IOMSTR_CMD_OFFSET           (8)
#define BFP_IOMSTR_CMD_SPICHL           (16)
#define BFP_IOMSTR_CMD_I2CADDR          (16)
#define BFP_IOMSTR_CMD_I2CADDR10BIT     (16)
#define BFP_IOMSTR_CMD_I2C10BIT         (26)
#define BFP_IOMSTR_CMD_LSB              (27)
#define BFP_IOMSTR_CMD_CONT             (28)    // 1:hold SDA low at end of op (RESTART), 0:release SDA (START)
#define BFP_IOMSTR_CMD_COMMAND          (29)
#define BFP_IOMSTR_CMD_RAW              (30)    // This bit indicates a RAW operation

#define BFM_IOMSTR_CMD_LENGTH           ((uint32_t)0xff  << BFP_IOMSTR_CMD_LENGTH) // I2C or SPI
#define BFM_IOMSTR_CMD_OFFSET           ((uint32_t)0xff  << BFP_IOMSTR_CMD_OFFSET)
#define BFM_IOMSTR_CMD_SPICHL           ((uint32_t)0x07  << BFP_IOMSTR_CMD_SPICHL)
#define BFM_IOMSTR_CMD_I2CADDR          ((uint32_t)0x7f  << BFP_IOMSTR_CMD_I2CADDR)
#define BFM_IOMSTR_CMD_I2CADDR10BIT     ((uint32_t)0x3ff << BFP_IOMSTR_CMD_I2CADDR10BIT)
#define BFM_IOMSTR_CMD_I2C10BIT         ((uint32_t)0x1   << BFP_IOMSTR_CMD_I2C10BIT)
#define BFM_IOMSTR_CMD_LSB              ((uint32_t)0x1   << BFP_IOMSTR_CMD_LSB)
#define BFM_IOMSTR_CMD_CONT             ((uint32_t)0x1   << BFP_IOMSTR_CMD_CONT)
#define BFM_IOMSTR_CMD_COMMAND          ((uint32_t)0xe   << BFP_IOMSTR_CMD_COMMAND)
#define BFM_IOMSTR_CMD_RAW              ((uint32_t)0x1   << BFP_IOMSTR_CMD_RAW)

#define BFV_IOMSTR_CMD_LENGTH(v)        ((((uint32_t) v) << (BFP_IOMSTR_CMD_LENGTH)) & (BFM_IOMSTR_CMD_LENGTH))
#define BFV_IOMSTR_CMD_OFFSET(v)        ((((uint32_t) v) << (BFP_IOMSTR_CMD_OFFSET)) & (BFM_IOMSTR_CMD_OFFSET))
#define BFV_IOMSTR_CMD_SPICHL(v)        ((((uint32_t) v) << (BFP_IOMSTR_CMD_SPICHL)) & (BFM_IOMSTR_CMD_SPICHL))
#define BFV_IOMSTR_CMD_I2CADDR(v)       ((((uint32_t) v) << (BFP_IOMSTR_CMD_I2CADDR)) & (BFM_IOMSTR_CMD_I2CADDR))
#define BFV_IOMSTR_CMD_I2CADDR10BIT(v)  ((((uint32_t) v) << (BFP_IOMSTR_CMD_I2CADDR10BIT)) & (BFM_IOMSTR_CMD_I2CADDR10BIT))
#define BFV_IOMSTR_CMD_I2C10BIT(v)      ((((uint32_t) v) << (BFP_IOMSTR_CMD_I2C10BIT)) & (BFM_IOMSTR_CMD_I2C10BIT))
#define BFV_IOMSTR_CMD_LSB(v)           ((((uint32_t) v) << (BFP_IOMSTR_CMD_LSB)) & (BFM_IOMSTR_CMD_LSB))
#define BFV_IOMSTR_CMD_CONT(v)          ((((uint32_t) v) << (BFP_IOMSTR_CMD_CONT)) & (BFM_IOMSTR_CMD_CONT))
#define BFV_IOMSTR_CMD_COMMAND(v)       ((((uint32_t) v) << (BFP_IOMSTR_CMD_COMMAND)) & (BFM_IOMSTR_CMD_COMMAND))
#define BFV_IOMSTR_CMD_RAW(v)           ((((uint32_t) v) << (BFP_IOMSTR_CMD_RAW)) & (BFM_IOMSTR_CMD_RAW))


#define BFC_IOMSTR_CMD_I2C10BIT         ((uint32_t)1)           // I2C only
#define BFC_IOMSTR_CMD_LENGTH_MAXLEN    (127)                   // I2C only
#define BFC_IOMSTR_CMD_COMMAND_WRITE    ((uint32_t)0x0)         // I2C or SPI
#define BFC_IOMSTR_CMD_COMMAND_READ     ((uint32_t)0x4)         // I2C or SPI

#define BFC_IOMSTR_CMD_COMMAND_WR_RAW   ((uint32_t)0x2)         // I2C or SPI
#define BFC_IOMSTR_CMD_COMMAND_RD_RAW   ((uint32_t)0x6)         // I2C or SPI

/*
#define BFC_IOMSTR_CMD_COMMAND_RAW      (BFM_IOMSTR_CMD_RAW)    // I2C or SPI, this CMD bit indicates a RAW transfer
#define BFC_IOMSTR_CMD_COMMAND_WR_RAW   ((uint32_t)(BFC_IOMSTR_CMD_COMMAND_WRITE | BFC_IOMSTR_CMD_COMMAND_RAW))
#define BFC_IOMSTR_CMD_COMMAND_RD_RAW   ((uint32_t)(BFC_IOMSTR_CMD_COMMAND_READ  | BFC_IOMSTR_CMD_COMMAND_RAW))
*/


// *************************************
// IOMSTR SPI command definitions
// *************************************
#define BFP_IOMSTR_CMD_SPICHN           (16)
#define BFP_IOMSTR_CMD_UPLNGTH          (23)    // Upper 4 bits of SPI LENGTH field

#define BFM_IOMSTR_CMD_SPICHN           ((uint32_t)0x7   << BFP_IOMSTR_CMD_SPICHN)
#define BFM_IOMSTR_CMD_UPLNGTH          ((uint32_t)0xF   << BFP_IOMSTR_CMD_UPLNGTH)

#define BFV_IOMSTR_CMD_SPICHN(v)        ((((uint32_t) v) << (BFP_IOMSTR_CMD_SPICHN)) & (BFM_IOMSTR_CMD_SPICHN))

// The UPLNGTH BFE macro (BitField Extend) is a special macro since this field is
//  actually an extension of another field (LENGTH).  The goal will be to have
//  this macro extract the upper 4 bits of the address and return them in the
//  proper bit position.
#define BFE_IOMSTR_CMD_UPLNGTH(v)       ( (((uint32_t) v) & (0xF00)) << (BFP_IOMSTR_CMD_UPLNGTH-8) )





#endif  // __IOMSTR_H

