/*******************************************************************************
*                                                                              *
*   Copyright (c) 2013-2014 Ambiq Micro                                        *
*                                                                              *
********************************************************************************
*                                                                              *
*   File:       ioslave.h                                                      *
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


#ifndef __IOSLAVE_H
#define __IOSLAVE_H

#include "../am_mcu_apollo.h"

// *****************************************************************************
//                                                                             *
//  IOSLAVE_IORAM -                                                            *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_0                     : 32;
    } B;
} reg_ioslave_ioram_t;

#define REG_IOSLAVE_IORAM_ADDR                  (REG_IOSLAVE_BASEADDR + 0x00000000UL)
#define REG_IOSLAVE_IORAM                       (*(volatile reg_ioslave_ioram_t *) REG_IOSLAVE_IORAM_ADDR)
#define REG_IOSLAVE_IORAM_RD()                  (REG_IOSLAVE_IORAM.U32)
#define REG_IOSLAVE_IORAM_WR(v)                 (REG_IOSLAVE_IORAM.U32 = (v))
#define REG_IOSLAVE_IORAM_CLR(m)                (REG_IOSLAVE_IORAM.U32 = ((REG_IOSLAVE_IORAM.U32) & ~(m)))
#define REG_IOSLAVE_IORAM_SET(m)                (REG_IOSLAVE_IORAM.U32 = ((REG_IOSLAVE_IORAM.U32) | (m)))
#define REG_IOSLAVE_IORAM_DEF                   0x00000000


// *****************************************************************************
//                                                                             *
//  IOSLAVE_FIFOPTR - Current FIFO Pointer                                     *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_16                    : 16;
        unsigned FIFOSIZ                    :  8;
        unsigned FIFOPTR                    :  8;
    } B;
} reg_ioslave_fifoptr_t;

#define REG_IOSLAVE_FIFOPTR_ADDR                (REG_IOSLAVE_BASEADDR + 0x00000100UL)
#define REG_IOSLAVE_FIFOPTR                     (*(volatile reg_ioslave_fifoptr_t *) REG_IOSLAVE_FIFOPTR_ADDR)
#define REG_IOSLAVE_FIFOPTR_RD()                (REG_IOSLAVE_FIFOPTR.U32)
#define REG_IOSLAVE_FIFOPTR_WR(v)               (REG_IOSLAVE_FIFOPTR.U32 = (v))
#define REG_IOSLAVE_FIFOPTR_CLR(m)              (REG_IOSLAVE_FIFOPTR.U32 = ((REG_IOSLAVE_FIFOPTR.U32) & ~(m)))
#define REG_IOSLAVE_FIFOPTR_SET(m)              (REG_IOSLAVE_FIFOPTR.U32 = ((REG_IOSLAVE_FIFOPTR.U32) | (m)))
#define REG_IOSLAVE_FIFOPTR_DEF                 0x00000000

#define BFP_IOSLAVE_FIFOPTR_RSVD_16             (16)                    /* bitfield lsb */
#define BFM_IOSLAVE_FIFOPTR_RSVD_16             ((uint32_t)0xffff0000)  /* bitfield mask */
#define BFN_IOSLAVE_FIFOPTR_RSVD_16             (16)                    /* bitfield width */
#define BFD_IOSLAVE_FIFOPTR_RSVD_16             (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FIFOPTR_RSVD_16(v)          ((((uint32_t) v) << (BFP_IOSLAVE_FIFOPTR_RSVD_16)) & (BFM_IOSLAVE_FIFOPTR_RSVD_16))
#define BFX_IOSLAVE_FIFOPTR_RSVD_16(v)          ((((uint32_t) v) & (BFM_IOSLAVE_FIFOPTR_RSVD_16)) >> (BFP_IOSLAVE_FIFOPTR_RSVD_16))
#define BFW_IOSLAVE_FIFOPTR_RSVD_16(v)          (REG_IOSLAVE_FIFOPTR.U32 = ( (REG_IOSLAVE_FIFOPTR.U32 & ~(BFM_IOSLAVE_FIFOPTR_RSVD_16)) | ((((uint32_t) v)<<(BFP_IOSLAVE_FIFOPTR_RSVD_16)) & (BFM_IOSLAVE_FIFOPTR_RSVD_16)) ))
#define BFR_IOSLAVE_FIFOPTR_RSVD_16()           ((REG_IOSLAVE_FIFOPTR.U32 & (BFM_IOSLAVE_FIFOPTR_RSVD_16))>>(BFP_IOSLAVE_FIFOPTR_RSVD_16))

#define BFP_IOSLAVE_FIFOPTR_FIFOSIZ             (8)                     /* bitfield lsb */
#define BFM_IOSLAVE_FIFOPTR_FIFOSIZ             ((uint32_t)0x0000ff00)  /* bitfield mask */
#define BFN_IOSLAVE_FIFOPTR_FIFOSIZ             (8)                     /* bitfield width */
#define BFD_IOSLAVE_FIFOPTR_FIFOSIZ             (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FIFOPTR_FIFOSIZ(v)          ((((uint32_t) v) << (BFP_IOSLAVE_FIFOPTR_FIFOSIZ)) & (BFM_IOSLAVE_FIFOPTR_FIFOSIZ))
#define BFX_IOSLAVE_FIFOPTR_FIFOSIZ(v)          ((((uint32_t) v) & (BFM_IOSLAVE_FIFOPTR_FIFOSIZ)) >> (BFP_IOSLAVE_FIFOPTR_FIFOSIZ))
#define BFW_IOSLAVE_FIFOPTR_FIFOSIZ(v)          (REG_IOSLAVE_FIFOPTR.U32 = ( (REG_IOSLAVE_FIFOPTR.U32 & ~(BFM_IOSLAVE_FIFOPTR_FIFOSIZ)) | ((((uint32_t) v)<<(BFP_IOSLAVE_FIFOPTR_FIFOSIZ)) & (BFM_IOSLAVE_FIFOPTR_FIFOSIZ)) ))
#define BFR_IOSLAVE_FIFOPTR_FIFOSIZ()           ((REG_IOSLAVE_FIFOPTR.U32 & (BFM_IOSLAVE_FIFOPTR_FIFOSIZ))>>(BFP_IOSLAVE_FIFOPTR_FIFOSIZ))

#define BFP_IOSLAVE_FIFOPTR_FIFOPTR             (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_FIFOPTR_FIFOPTR             ((uint32_t)0x000000ff)  /* bitfield mask */
#define BFN_IOSLAVE_FIFOPTR_FIFOPTR             (8)                     /* bitfield width */
#define BFD_IOSLAVE_FIFOPTR_FIFOPTR             (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FIFOPTR_FIFOPTR(v)          ((((uint32_t) v) << (BFP_IOSLAVE_FIFOPTR_FIFOPTR)) & (BFM_IOSLAVE_FIFOPTR_FIFOPTR))
#define BFX_IOSLAVE_FIFOPTR_FIFOPTR(v)          ((((uint32_t) v) & (BFM_IOSLAVE_FIFOPTR_FIFOPTR)) >> (BFP_IOSLAVE_FIFOPTR_FIFOPTR))
#define BFW_IOSLAVE_FIFOPTR_FIFOPTR(v)          (REG_IOSLAVE_FIFOPTR.U32 = ( (REG_IOSLAVE_FIFOPTR.U32 & ~(BFM_IOSLAVE_FIFOPTR_FIFOPTR)) | ((((uint32_t) v)<<(BFP_IOSLAVE_FIFOPTR_FIFOPTR)) & (BFM_IOSLAVE_FIFOPTR_FIFOPTR)) ))
#define BFR_IOSLAVE_FIFOPTR_FIFOPTR()           ((REG_IOSLAVE_FIFOPTR.U32 & (BFM_IOSLAVE_FIFOPTR_FIFOPTR))>>(BFP_IOSLAVE_FIFOPTR_FIFOPTR))


// *****************************************************************************
//                                                                             *
//  IOSLAVE_FIFOCFG - FIFO Configuration                                       *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_30                    :  2;
        unsigned ROBASE                     :  6;
        unsigned RSVD_16                    :  8;
        unsigned RSVD_14                    :  2;
        unsigned FIFOMAX                    :  6;
        unsigned RSVD_5                     :  3;
        unsigned FIFOBASE                   :  5;
    } B;
} reg_ioslave_fifocfg_t;

#define REG_IOSLAVE_FIFOCFG_ADDR                (REG_IOSLAVE_BASEADDR + 0x00000104UL)
#define REG_IOSLAVE_FIFOCFG                     (*(volatile reg_ioslave_fifocfg_t *) REG_IOSLAVE_FIFOCFG_ADDR)
#define REG_IOSLAVE_FIFOCFG_RD()                (REG_IOSLAVE_FIFOCFG.U32)
#define REG_IOSLAVE_FIFOCFG_WR(v)               (REG_IOSLAVE_FIFOCFG.U32 = (v))
#define REG_IOSLAVE_FIFOCFG_CLR(m)              (REG_IOSLAVE_FIFOCFG.U32 = ((REG_IOSLAVE_FIFOCFG.U32) & ~(m)))
#define REG_IOSLAVE_FIFOCFG_SET(m)              (REG_IOSLAVE_FIFOCFG.U32 = ((REG_IOSLAVE_FIFOCFG.U32) | (m)))
#define REG_IOSLAVE_FIFOCFG_DEF                 0x20000000

#define BFP_IOSLAVE_FIFOCFG_RSVD_30             (30)                    /* bitfield lsb */
#define BFM_IOSLAVE_FIFOCFG_RSVD_30             ((uint32_t)0xc0000000)  /* bitfield mask */
#define BFN_IOSLAVE_FIFOCFG_RSVD_30             (2)                     /* bitfield width */
#define BFD_IOSLAVE_FIFOCFG_RSVD_30             (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FIFOCFG_RSVD_30(v)          ((((uint32_t) v) << (BFP_IOSLAVE_FIFOCFG_RSVD_30)) & (BFM_IOSLAVE_FIFOCFG_RSVD_30))
#define BFX_IOSLAVE_FIFOCFG_RSVD_30(v)          ((((uint32_t) v) & (BFM_IOSLAVE_FIFOCFG_RSVD_30)) >> (BFP_IOSLAVE_FIFOCFG_RSVD_30))
#define BFW_IOSLAVE_FIFOCFG_RSVD_30(v)          (REG_IOSLAVE_FIFOCFG.U32 = ( (REG_IOSLAVE_FIFOCFG.U32 & ~(BFM_IOSLAVE_FIFOCFG_RSVD_30)) | ((((uint32_t) v)<<(BFP_IOSLAVE_FIFOCFG_RSVD_30)) & (BFM_IOSLAVE_FIFOCFG_RSVD_30)) ))
#define BFR_IOSLAVE_FIFOCFG_RSVD_30()           ((REG_IOSLAVE_FIFOCFG.U32 & (BFM_IOSLAVE_FIFOCFG_RSVD_30))>>(BFP_IOSLAVE_FIFOCFG_RSVD_30))

#define BFP_IOSLAVE_FIFOCFG_ROBASE              (24)                    /* bitfield lsb */
#define BFM_IOSLAVE_FIFOCFG_ROBASE              ((uint32_t)0x3f000000)  /* bitfield mask */
#define BFN_IOSLAVE_FIFOCFG_ROBASE              (6)                     /* bitfield width */
#define BFD_IOSLAVE_FIFOCFG_ROBASE              (0x20)                  /* bitfield default value */
#define BFV_IOSLAVE_FIFOCFG_ROBASE(v)           ((((uint32_t) v) << (BFP_IOSLAVE_FIFOCFG_ROBASE)) & (BFM_IOSLAVE_FIFOCFG_ROBASE))
#define BFX_IOSLAVE_FIFOCFG_ROBASE(v)           ((((uint32_t) v) & (BFM_IOSLAVE_FIFOCFG_ROBASE)) >> (BFP_IOSLAVE_FIFOCFG_ROBASE))
#define BFW_IOSLAVE_FIFOCFG_ROBASE(v)           (REG_IOSLAVE_FIFOCFG.U32 = ( (REG_IOSLAVE_FIFOCFG.U32 & ~(BFM_IOSLAVE_FIFOCFG_ROBASE)) | ((((uint32_t) v)<<(BFP_IOSLAVE_FIFOCFG_ROBASE)) & (BFM_IOSLAVE_FIFOCFG_ROBASE)) ))
#define BFR_IOSLAVE_FIFOCFG_ROBASE()            ((REG_IOSLAVE_FIFOCFG.U32 & (BFM_IOSLAVE_FIFOCFG_ROBASE))>>(BFP_IOSLAVE_FIFOCFG_ROBASE))

#define BFP_IOSLAVE_FIFOCFG_RSVD_16             (16)                    /* bitfield lsb */
#define BFM_IOSLAVE_FIFOCFG_RSVD_16             ((uint32_t)0x00ff0000)  /* bitfield mask */
#define BFN_IOSLAVE_FIFOCFG_RSVD_16             (8)                     /* bitfield width */
#define BFD_IOSLAVE_FIFOCFG_RSVD_16             (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FIFOCFG_RSVD_16(v)          ((((uint32_t) v) << (BFP_IOSLAVE_FIFOCFG_RSVD_16)) & (BFM_IOSLAVE_FIFOCFG_RSVD_16))
#define BFX_IOSLAVE_FIFOCFG_RSVD_16(v)          ((((uint32_t) v) & (BFM_IOSLAVE_FIFOCFG_RSVD_16)) >> (BFP_IOSLAVE_FIFOCFG_RSVD_16))
#define BFW_IOSLAVE_FIFOCFG_RSVD_16(v)          (REG_IOSLAVE_FIFOCFG.U32 = ( (REG_IOSLAVE_FIFOCFG.U32 & ~(BFM_IOSLAVE_FIFOCFG_RSVD_16)) | ((((uint32_t) v)<<(BFP_IOSLAVE_FIFOCFG_RSVD_16)) & (BFM_IOSLAVE_FIFOCFG_RSVD_16)) ))
#define BFR_IOSLAVE_FIFOCFG_RSVD_16()           ((REG_IOSLAVE_FIFOCFG.U32 & (BFM_IOSLAVE_FIFOCFG_RSVD_16))>>(BFP_IOSLAVE_FIFOCFG_RSVD_16))

#define BFP_IOSLAVE_FIFOCFG_RSVD_14             (14)                    /* bitfield lsb */
#define BFM_IOSLAVE_FIFOCFG_RSVD_14             ((uint32_t)0x0000c000)  /* bitfield mask */
#define BFN_IOSLAVE_FIFOCFG_RSVD_14             (2)                     /* bitfield width */
#define BFD_IOSLAVE_FIFOCFG_RSVD_14             (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FIFOCFG_RSVD_14(v)          ((((uint32_t) v) << (BFP_IOSLAVE_FIFOCFG_RSVD_14)) & (BFM_IOSLAVE_FIFOCFG_RSVD_14))
#define BFX_IOSLAVE_FIFOCFG_RSVD_14(v)          ((((uint32_t) v) & (BFM_IOSLAVE_FIFOCFG_RSVD_14)) >> (BFP_IOSLAVE_FIFOCFG_RSVD_14))
#define BFW_IOSLAVE_FIFOCFG_RSVD_14(v)          (REG_IOSLAVE_FIFOCFG.U32 = ( (REG_IOSLAVE_FIFOCFG.U32 & ~(BFM_IOSLAVE_FIFOCFG_RSVD_14)) | ((((uint32_t) v)<<(BFP_IOSLAVE_FIFOCFG_RSVD_14)) & (BFM_IOSLAVE_FIFOCFG_RSVD_14)) ))
#define BFR_IOSLAVE_FIFOCFG_RSVD_14()           ((REG_IOSLAVE_FIFOCFG.U32 & (BFM_IOSLAVE_FIFOCFG_RSVD_14))>>(BFP_IOSLAVE_FIFOCFG_RSVD_14))

#define BFP_IOSLAVE_FIFOCFG_FIFOMAX             (8)                     /* bitfield lsb */
#define BFM_IOSLAVE_FIFOCFG_FIFOMAX             ((uint32_t)0x00003f00)  /* bitfield mask */
#define BFN_IOSLAVE_FIFOCFG_FIFOMAX             (6)                     /* bitfield width */
#define BFD_IOSLAVE_FIFOCFG_FIFOMAX             (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FIFOCFG_FIFOMAX(v)          ((((uint32_t) v) << (BFP_IOSLAVE_FIFOCFG_FIFOMAX)) & (BFM_IOSLAVE_FIFOCFG_FIFOMAX))
#define BFX_IOSLAVE_FIFOCFG_FIFOMAX(v)          ((((uint32_t) v) & (BFM_IOSLAVE_FIFOCFG_FIFOMAX)) >> (BFP_IOSLAVE_FIFOCFG_FIFOMAX))
#define BFW_IOSLAVE_FIFOCFG_FIFOMAX(v)          (REG_IOSLAVE_FIFOCFG.U32 = ( (REG_IOSLAVE_FIFOCFG.U32 & ~(BFM_IOSLAVE_FIFOCFG_FIFOMAX)) | ((((uint32_t) v)<<(BFP_IOSLAVE_FIFOCFG_FIFOMAX)) & (BFM_IOSLAVE_FIFOCFG_FIFOMAX)) ))
#define BFR_IOSLAVE_FIFOCFG_FIFOMAX()           ((REG_IOSLAVE_FIFOCFG.U32 & (BFM_IOSLAVE_FIFOCFG_FIFOMAX))>>(BFP_IOSLAVE_FIFOCFG_FIFOMAX))

#define BFP_IOSLAVE_FIFOCFG_RSVD_5              (5)                     /* bitfield lsb */
#define BFM_IOSLAVE_FIFOCFG_RSVD_5              ((uint32_t)0x000000e0)  /* bitfield mask */
#define BFN_IOSLAVE_FIFOCFG_RSVD_5              (3)                     /* bitfield width */
#define BFD_IOSLAVE_FIFOCFG_RSVD_5              (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FIFOCFG_RSVD_5(v)           ((((uint32_t) v) << (BFP_IOSLAVE_FIFOCFG_RSVD_5)) & (BFM_IOSLAVE_FIFOCFG_RSVD_5))
#define BFX_IOSLAVE_FIFOCFG_RSVD_5(v)           ((((uint32_t) v) & (BFM_IOSLAVE_FIFOCFG_RSVD_5)) >> (BFP_IOSLAVE_FIFOCFG_RSVD_5))
#define BFW_IOSLAVE_FIFOCFG_RSVD_5(v)           (REG_IOSLAVE_FIFOCFG.U32 = ( (REG_IOSLAVE_FIFOCFG.U32 & ~(BFM_IOSLAVE_FIFOCFG_RSVD_5)) | ((((uint32_t) v)<<(BFP_IOSLAVE_FIFOCFG_RSVD_5)) & (BFM_IOSLAVE_FIFOCFG_RSVD_5)) ))
#define BFR_IOSLAVE_FIFOCFG_RSVD_5()            ((REG_IOSLAVE_FIFOCFG.U32 & (BFM_IOSLAVE_FIFOCFG_RSVD_5))>>(BFP_IOSLAVE_FIFOCFG_RSVD_5))

#define BFP_IOSLAVE_FIFOCFG_FIFOBASE            (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_FIFOCFG_FIFOBASE            ((uint32_t)0x0000001f)  /* bitfield mask */
#define BFN_IOSLAVE_FIFOCFG_FIFOBASE            (5)                     /* bitfield width */
#define BFD_IOSLAVE_FIFOCFG_FIFOBASE            (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FIFOCFG_FIFOBASE(v)         ((((uint32_t) v) << (BFP_IOSLAVE_FIFOCFG_FIFOBASE)) & (BFM_IOSLAVE_FIFOCFG_FIFOBASE))
#define BFX_IOSLAVE_FIFOCFG_FIFOBASE(v)         ((((uint32_t) v) & (BFM_IOSLAVE_FIFOCFG_FIFOBASE)) >> (BFP_IOSLAVE_FIFOCFG_FIFOBASE))
#define BFW_IOSLAVE_FIFOCFG_FIFOBASE(v)         (REG_IOSLAVE_FIFOCFG.U32 = ( (REG_IOSLAVE_FIFOCFG.U32 & ~(BFM_IOSLAVE_FIFOCFG_FIFOBASE)) | ((((uint32_t) v)<<(BFP_IOSLAVE_FIFOCFG_FIFOBASE)) & (BFM_IOSLAVE_FIFOCFG_FIFOBASE)) ))
#define BFR_IOSLAVE_FIFOCFG_FIFOBASE()          ((REG_IOSLAVE_FIFOCFG.U32 & (BFM_IOSLAVE_FIFOCFG_FIFOBASE))>>(BFP_IOSLAVE_FIFOCFG_FIFOBASE))


// *****************************************************************************
//                                                                             *
//  IOSLAVE_FIFOTHR - FIFO Threshold Configuration                             *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned FIFOTHR                    :  8;
    } B;
} reg_ioslave_fifothr_t;

#define REG_IOSLAVE_FIFOTHR_ADDR                (REG_IOSLAVE_BASEADDR + 0x00000108UL)
#define REG_IOSLAVE_FIFOTHR                     (*(volatile reg_ioslave_fifothr_t *) REG_IOSLAVE_FIFOTHR_ADDR)
#define REG_IOSLAVE_FIFOTHR_RD()                (REG_IOSLAVE_FIFOTHR.U32)
#define REG_IOSLAVE_FIFOTHR_WR(v)               (REG_IOSLAVE_FIFOTHR.U32 = (v))
#define REG_IOSLAVE_FIFOTHR_CLR(m)              (REG_IOSLAVE_FIFOTHR.U32 = ((REG_IOSLAVE_FIFOTHR.U32) & ~(m)))
#define REG_IOSLAVE_FIFOTHR_SET(m)              (REG_IOSLAVE_FIFOTHR.U32 = ((REG_IOSLAVE_FIFOTHR.U32) | (m)))
#define REG_IOSLAVE_FIFOTHR_DEF                 0x00000000

#define BFP_IOSLAVE_FIFOTHR_RSVD_8              (8)                     /* bitfield lsb */
#define BFM_IOSLAVE_FIFOTHR_RSVD_8              ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_IOSLAVE_FIFOTHR_RSVD_8              (24)                    /* bitfield width */
#define BFD_IOSLAVE_FIFOTHR_RSVD_8              (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FIFOTHR_RSVD_8(v)           ((((uint32_t) v) << (BFP_IOSLAVE_FIFOTHR_RSVD_8)) & (BFM_IOSLAVE_FIFOTHR_RSVD_8))
#define BFX_IOSLAVE_FIFOTHR_RSVD_8(v)           ((((uint32_t) v) & (BFM_IOSLAVE_FIFOTHR_RSVD_8)) >> (BFP_IOSLAVE_FIFOTHR_RSVD_8))
#define BFW_IOSLAVE_FIFOTHR_RSVD_8(v)           (REG_IOSLAVE_FIFOTHR.U32 = ( (((uint32_t) v)<<(BFP_IOSLAVE_FIFOTHR_RSVD_8)) & (BFM_IOSLAVE_FIFOTHR_RSVD_8)) )
#define BFR_IOSLAVE_FIFOTHR_RSVD_8()            ((REG_IOSLAVE_FIFOTHR.U32 & (BFM_IOSLAVE_FIFOTHR_RSVD_8))>>(BFP_IOSLAVE_FIFOTHR_RSVD_8))

#define BFP_IOSLAVE_FIFOTHR_FIFOTHR             (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_FIFOTHR_FIFOTHR             ((uint32_t)0x000000ff)  /* bitfield mask */
#define BFN_IOSLAVE_FIFOTHR_FIFOTHR             (8)                     /* bitfield width */
#define BFD_IOSLAVE_FIFOTHR_FIFOTHR             (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FIFOTHR_FIFOTHR(v)          ((((uint32_t) v) << (BFP_IOSLAVE_FIFOTHR_FIFOTHR)) & (BFM_IOSLAVE_FIFOTHR_FIFOTHR))
#define BFX_IOSLAVE_FIFOTHR_FIFOTHR(v)          ((((uint32_t) v) & (BFM_IOSLAVE_FIFOTHR_FIFOTHR)) >> (BFP_IOSLAVE_FIFOTHR_FIFOTHR))
#define BFW_IOSLAVE_FIFOTHR_FIFOTHR(v)          (REG_IOSLAVE_FIFOTHR.U32 = ( (((uint32_t) v)<<(BFP_IOSLAVE_FIFOTHR_FIFOTHR)) & (BFM_IOSLAVE_FIFOTHR_FIFOTHR)) )
#define BFR_IOSLAVE_FIFOTHR_FIFOTHR()           ((REG_IOSLAVE_FIFOTHR.U32 & (BFM_IOSLAVE_FIFOTHR_FIFOTHR))>>(BFP_IOSLAVE_FIFOTHR_FIFOTHR))


// *****************************************************************************
//                                                                             *
//  IOSLAVE_FUPD - FIFO Configuration                                          *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_2                     : 30;
        unsigned IOREAD                     :  1;
        unsigned FIFOUPD                    :  1;
    } B;
} reg_ioslave_fupd_t;

#define REG_IOSLAVE_FUPD_ADDR                   (REG_IOSLAVE_BASEADDR + 0x0000010CUL)
#define REG_IOSLAVE_FUPD                        (*(volatile reg_ioslave_fupd_t *) REG_IOSLAVE_FUPD_ADDR)
#define REG_IOSLAVE_FUPD_RD()                   (REG_IOSLAVE_FUPD.U32)
#define REG_IOSLAVE_FUPD_WR(v)                  (REG_IOSLAVE_FUPD.U32 = (v))
#define REG_IOSLAVE_FUPD_CLR(m)                 (REG_IOSLAVE_FUPD.U32 = ((REG_IOSLAVE_FUPD.U32) & ~(m)))
#define REG_IOSLAVE_FUPD_SET(m)                 (REG_IOSLAVE_FUPD.U32 = ((REG_IOSLAVE_FUPD.U32) | (m)))
#define REG_IOSLAVE_FUPD_DEF                    0x00000000

#define BFP_IOSLAVE_FUPD_RSVD_2                 (2)                     /* bitfield lsb */
#define BFM_IOSLAVE_FUPD_RSVD_2                 ((uint32_t)0xfffffffc)  /* bitfield mask */
#define BFN_IOSLAVE_FUPD_RSVD_2                 (30)                    /* bitfield width */
#define BFD_IOSLAVE_FUPD_RSVD_2                 (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FUPD_RSVD_2(v)              ((((uint32_t) v) << (BFP_IOSLAVE_FUPD_RSVD_2)) & (BFM_IOSLAVE_FUPD_RSVD_2))
#define BFX_IOSLAVE_FUPD_RSVD_2(v)              ((((uint32_t) v) & (BFM_IOSLAVE_FUPD_RSVD_2)) >> (BFP_IOSLAVE_FUPD_RSVD_2))
#define BFW_IOSLAVE_FUPD_RSVD_2(v)              (REG_IOSLAVE_FUPD.U32 = ( (REG_IOSLAVE_FUPD.U32 & ~(BFM_IOSLAVE_FUPD_RSVD_2)) | ((((uint32_t) v)<<(BFP_IOSLAVE_FUPD_RSVD_2)) & (BFM_IOSLAVE_FUPD_RSVD_2)) ))
#define BFR_IOSLAVE_FUPD_RSVD_2()               ((REG_IOSLAVE_FUPD.U32 & (BFM_IOSLAVE_FUPD_RSVD_2))>>(BFP_IOSLAVE_FUPD_RSVD_2))

#define BFP_IOSLAVE_FUPD_IOREAD                 (1)                     /* bitfield lsb */
#define BFM_IOSLAVE_FUPD_IOREAD                 ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_IOSLAVE_FUPD_IOREAD                 (1)                     /* bitfield width */
#define BFD_IOSLAVE_FUPD_IOREAD                 (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FUPD_IOREAD(v)              ((((uint32_t) v) << (BFP_IOSLAVE_FUPD_IOREAD)) & (BFM_IOSLAVE_FUPD_IOREAD))
#define BFX_IOSLAVE_FUPD_IOREAD(v)              ((((uint32_t) v) & (BFM_IOSLAVE_FUPD_IOREAD)) >> (BFP_IOSLAVE_FUPD_IOREAD))
#define BFW_IOSLAVE_FUPD_IOREAD(v)              (REG_IOSLAVE_FUPD.U32 = ( (REG_IOSLAVE_FUPD.U32 & ~(BFM_IOSLAVE_FUPD_IOREAD)) | ((((uint32_t) v)<<(BFP_IOSLAVE_FUPD_IOREAD)) & (BFM_IOSLAVE_FUPD_IOREAD)) ))
#define BFR_IOSLAVE_FUPD_IOREAD()               ((REG_IOSLAVE_FUPD.U32 & (BFM_IOSLAVE_FUPD_IOREAD))>>(BFP_IOSLAVE_FUPD_IOREAD))

#define BFP_IOSLAVE_FUPD_FIFOUPD                (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_FUPD_FIFOUPD                ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_IOSLAVE_FUPD_FIFOUPD                (1)                     /* bitfield width */
#define BFD_IOSLAVE_FUPD_FIFOUPD                (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FUPD_FIFOUPD(v)             ((((uint32_t) v) << (BFP_IOSLAVE_FUPD_FIFOUPD)) & (BFM_IOSLAVE_FUPD_FIFOUPD))
#define BFX_IOSLAVE_FUPD_FIFOUPD(v)             ((((uint32_t) v) & (BFM_IOSLAVE_FUPD_FIFOUPD)) >> (BFP_IOSLAVE_FUPD_FIFOUPD))
#define BFW_IOSLAVE_FUPD_FIFOUPD(v)             (REG_IOSLAVE_FUPD.U32 = ( (REG_IOSLAVE_FUPD.U32 & ~(BFM_IOSLAVE_FUPD_FIFOUPD)) | ((((uint32_t) v)<<(BFP_IOSLAVE_FUPD_FIFOUPD)) & (BFM_IOSLAVE_FUPD_FIFOUPD)) ))
#define BFR_IOSLAVE_FUPD_FIFOUPD()              ((REG_IOSLAVE_FUPD.U32 & (BFM_IOSLAVE_FUPD_FIFOUPD))>>(BFP_IOSLAVE_FUPD_FIFOUPD))


// *****************************************************************************
//                                                                             *
//  IOSLAVE_FIFOCTR - Overall FIFO Counter                                     *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_10                    : 22;
        unsigned FIFOCTR                    : 10;
    } B;
} reg_ioslave_fifoctr_t;

#define REG_IOSLAVE_FIFOCTR_ADDR                (REG_IOSLAVE_BASEADDR + 0x00000110UL)
#define REG_IOSLAVE_FIFOCTR                     (*(volatile reg_ioslave_fifoctr_t *) REG_IOSLAVE_FIFOCTR_ADDR)
#define REG_IOSLAVE_FIFOCTR_RD()                (REG_IOSLAVE_FIFOCTR.U32)
#define REG_IOSLAVE_FIFOCTR_WR(v)               (REG_IOSLAVE_FIFOCTR.U32 = (v))
#define REG_IOSLAVE_FIFOCTR_CLR(m)              (REG_IOSLAVE_FIFOCTR.U32 = ((REG_IOSLAVE_FIFOCTR.U32) & ~(m)))
#define REG_IOSLAVE_FIFOCTR_SET(m)              (REG_IOSLAVE_FIFOCTR.U32 = ((REG_IOSLAVE_FIFOCTR.U32) | (m)))
#define REG_IOSLAVE_FIFOCTR_DEF                 0x00000000

#define BFP_IOSLAVE_FIFOCTR_RSVD_10             (10)                    /* bitfield lsb */
#define BFM_IOSLAVE_FIFOCTR_RSVD_10             ((uint32_t)0xfffffc00)  /* bitfield mask */
#define BFN_IOSLAVE_FIFOCTR_RSVD_10             (22)                    /* bitfield width */
#define BFD_IOSLAVE_FIFOCTR_RSVD_10             (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FIFOCTR_RSVD_10(v)          ((((uint32_t) v) << (BFP_IOSLAVE_FIFOCTR_RSVD_10)) & (BFM_IOSLAVE_FIFOCTR_RSVD_10))
#define BFX_IOSLAVE_FIFOCTR_RSVD_10(v)          ((((uint32_t) v) & (BFM_IOSLAVE_FIFOCTR_RSVD_10)) >> (BFP_IOSLAVE_FIFOCTR_RSVD_10))
#define BFW_IOSLAVE_FIFOCTR_RSVD_10(v)          (REG_IOSLAVE_FIFOCTR.U32 = ( (((uint32_t) v)<<(BFP_IOSLAVE_FIFOCTR_RSVD_10)) & (BFM_IOSLAVE_FIFOCTR_RSVD_10)) )
#define BFR_IOSLAVE_FIFOCTR_RSVD_10()           ((REG_IOSLAVE_FIFOCTR.U32 & (BFM_IOSLAVE_FIFOCTR_RSVD_10))>>(BFP_IOSLAVE_FIFOCTR_RSVD_10))

#define BFP_IOSLAVE_FIFOCTR_FIFOCTR             (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_FIFOCTR_FIFOCTR             ((uint32_t)0x000003ff)  /* bitfield mask */
#define BFN_IOSLAVE_FIFOCTR_FIFOCTR             (10)                    /* bitfield width */
#define BFD_IOSLAVE_FIFOCTR_FIFOCTR             (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FIFOCTR_FIFOCTR(v)          ((((uint32_t) v) << (BFP_IOSLAVE_FIFOCTR_FIFOCTR)) & (BFM_IOSLAVE_FIFOCTR_FIFOCTR))
#define BFX_IOSLAVE_FIFOCTR_FIFOCTR(v)          ((((uint32_t) v) & (BFM_IOSLAVE_FIFOCTR_FIFOCTR)) >> (BFP_IOSLAVE_FIFOCTR_FIFOCTR))
#define BFW_IOSLAVE_FIFOCTR_FIFOCTR(v)          (REG_IOSLAVE_FIFOCTR.U32 = ( (((uint32_t) v)<<(BFP_IOSLAVE_FIFOCTR_FIFOCTR)) & (BFM_IOSLAVE_FIFOCTR_FIFOCTR)) )
#define BFR_IOSLAVE_FIFOCTR_FIFOCTR()           ((REG_IOSLAVE_FIFOCTR.U32 & (BFM_IOSLAVE_FIFOCTR_FIFOCTR))>>(BFP_IOSLAVE_FIFOCTR_FIFOCTR))


// *****************************************************************************
//                                                                             *
//  IOSLAVE_FIFOINC - Overall FIFO Counter Increment                           *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_10                    : 22;
        unsigned FIFOINC                    : 10;
    } B;
} reg_ioslave_fifoinc_t;

#define REG_IOSLAVE_FIFOINC_ADDR                (REG_IOSLAVE_BASEADDR + 0x00000114UL)
#define REG_IOSLAVE_FIFOINC                     (*(volatile reg_ioslave_fifoinc_t *) REG_IOSLAVE_FIFOINC_ADDR)
#define REG_IOSLAVE_FIFOINC_RD()                (REG_IOSLAVE_FIFOINC.U32)
#define REG_IOSLAVE_FIFOINC_WR(v)               (REG_IOSLAVE_FIFOINC.U32 = (v))
#define REG_IOSLAVE_FIFOINC_CLR(m)              (REG_IOSLAVE_FIFOINC.U32 = ((REG_IOSLAVE_FIFOINC.U32) & ~(m)))
#define REG_IOSLAVE_FIFOINC_SET(m)              (REG_IOSLAVE_FIFOINC.U32 = ((REG_IOSLAVE_FIFOINC.U32) | (m)))
#define REG_IOSLAVE_FIFOINC_DEF                 0x00000000

#define BFP_IOSLAVE_FIFOINC_RSVD_10             (10)                    /* bitfield lsb */
#define BFM_IOSLAVE_FIFOINC_RSVD_10             ((uint32_t)0xfffffc00)  /* bitfield mask */
#define BFN_IOSLAVE_FIFOINC_RSVD_10             (22)                    /* bitfield width */
#define BFD_IOSLAVE_FIFOINC_RSVD_10             (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FIFOINC_RSVD_10(v)          ((((uint32_t) v) << (BFP_IOSLAVE_FIFOINC_RSVD_10)) & (BFM_IOSLAVE_FIFOINC_RSVD_10))
#define BFX_IOSLAVE_FIFOINC_RSVD_10(v)          ((((uint32_t) v) & (BFM_IOSLAVE_FIFOINC_RSVD_10)) >> (BFP_IOSLAVE_FIFOINC_RSVD_10))
#define BFW_IOSLAVE_FIFOINC_RSVD_10(v)          (REG_IOSLAVE_FIFOINC.U32 = ( (((uint32_t) v)<<(BFP_IOSLAVE_FIFOINC_RSVD_10)) & (BFM_IOSLAVE_FIFOINC_RSVD_10)) )
#define BFR_IOSLAVE_FIFOINC_RSVD_10()           ((REG_IOSLAVE_FIFOINC.U32 & (BFM_IOSLAVE_FIFOINC_RSVD_10))>>(BFP_IOSLAVE_FIFOINC_RSVD_10))

#define BFP_IOSLAVE_FIFOINC_FIFOINC             (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_FIFOINC_FIFOINC             ((uint32_t)0x000003ff)  /* bitfield mask */
#define BFN_IOSLAVE_FIFOINC_FIFOINC             (10)                    /* bitfield width */
#define BFD_IOSLAVE_FIFOINC_FIFOINC             (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_FIFOINC_FIFOINC(v)          ((((uint32_t) v) << (BFP_IOSLAVE_FIFOINC_FIFOINC)) & (BFM_IOSLAVE_FIFOINC_FIFOINC))
#define BFX_IOSLAVE_FIFOINC_FIFOINC(v)          ((((uint32_t) v) & (BFM_IOSLAVE_FIFOINC_FIFOINC)) >> (BFP_IOSLAVE_FIFOINC_FIFOINC))
#define BFW_IOSLAVE_FIFOINC_FIFOINC(v)          (REG_IOSLAVE_FIFOINC.U32 = ( (((uint32_t) v)<<(BFP_IOSLAVE_FIFOINC_FIFOINC)) & (BFM_IOSLAVE_FIFOINC_FIFOINC)) )
#define BFR_IOSLAVE_FIFOINC_FIFOINC()           ((REG_IOSLAVE_FIFOINC.U32 & (BFM_IOSLAVE_FIFOINC_FIFOINC))>>(BFP_IOSLAVE_FIFOINC_FIFOINC))


// *****************************************************************************
//                                                                             *
//  IOSLAVE_IOSCFG - I/O Slave Configuration                                   *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned IFCEN                      :  1;
        unsigned RSVD_20                    : 11;
        unsigned I2CADDR                    : 12;
        unsigned RSVD_5                     :  3;
        unsigned STARTRD                    :  1;
        unsigned RSVD_3                     :  1;
        unsigned LSB                        :  1;
        unsigned SPOL                       :  1;
        unsigned IFCSEL                     :  1;
    } B;
} reg_ioslave_ioscfg_t;

#define REG_IOSLAVE_IOSCFG_ADDR                 (REG_IOSLAVE_BASEADDR + 0x00000118UL)
#define REG_IOSLAVE_IOSCFG                      (*(volatile reg_ioslave_ioscfg_t *) REG_IOSLAVE_IOSCFG_ADDR)
#define REG_IOSLAVE_IOSCFG_RD()                 (REG_IOSLAVE_IOSCFG.U32)
#define REG_IOSLAVE_IOSCFG_WR(v)                (REG_IOSLAVE_IOSCFG.U32 = (v))
#define REG_IOSLAVE_IOSCFG_CLR(m)               (REG_IOSLAVE_IOSCFG.U32 = ((REG_IOSLAVE_IOSCFG.U32) & ~(m)))
#define REG_IOSLAVE_IOSCFG_SET(m)               (REG_IOSLAVE_IOSCFG.U32 = ((REG_IOSLAVE_IOSCFG.U32) | (m)))
#define REG_IOSLAVE_IOSCFG_DEF                  0x00000000

#define BFP_IOSLAVE_IOSCFG_IFCEN                (31)                    /* bitfield lsb */
#define BFM_IOSLAVE_IOSCFG_IFCEN                ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_IOSLAVE_IOSCFG_IFCEN                (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSCFG_IFCEN                (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSCFG_IFCEN(v)             ((((uint32_t) v) << (BFP_IOSLAVE_IOSCFG_IFCEN)) & (BFM_IOSLAVE_IOSCFG_IFCEN))
#define BFX_IOSLAVE_IOSCFG_IFCEN(v)             ((((uint32_t) v) & (BFM_IOSLAVE_IOSCFG_IFCEN)) >> (BFP_IOSLAVE_IOSCFG_IFCEN))
#define BFW_IOSLAVE_IOSCFG_IFCEN(v)             (REG_IOSLAVE_IOSCFG.U32 = ( (REG_IOSLAVE_IOSCFG.U32 & ~(BFM_IOSLAVE_IOSCFG_IFCEN)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSCFG_IFCEN)) & (BFM_IOSLAVE_IOSCFG_IFCEN)) ))
#define BFR_IOSLAVE_IOSCFG_IFCEN()              ((REG_IOSLAVE_IOSCFG.U32 & (BFM_IOSLAVE_IOSCFG_IFCEN))>>(BFP_IOSLAVE_IOSCFG_IFCEN))

#define BFP_IOSLAVE_IOSCFG_RSVD_20              (20)                    /* bitfield lsb */
#define BFM_IOSLAVE_IOSCFG_RSVD_20              ((uint32_t)0x7ff00000)  /* bitfield mask */
#define BFN_IOSLAVE_IOSCFG_RSVD_20              (11)                    /* bitfield width */
#define BFD_IOSLAVE_IOSCFG_RSVD_20              (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSCFG_RSVD_20(v)           ((((uint32_t) v) << (BFP_IOSLAVE_IOSCFG_RSVD_20)) & (BFM_IOSLAVE_IOSCFG_RSVD_20))
#define BFX_IOSLAVE_IOSCFG_RSVD_20(v)           ((((uint32_t) v) & (BFM_IOSLAVE_IOSCFG_RSVD_20)) >> (BFP_IOSLAVE_IOSCFG_RSVD_20))
#define BFW_IOSLAVE_IOSCFG_RSVD_20(v)           (REG_IOSLAVE_IOSCFG.U32 = ( (REG_IOSLAVE_IOSCFG.U32 & ~(BFM_IOSLAVE_IOSCFG_RSVD_20)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSCFG_RSVD_20)) & (BFM_IOSLAVE_IOSCFG_RSVD_20)) ))
#define BFR_IOSLAVE_IOSCFG_RSVD_20()            ((REG_IOSLAVE_IOSCFG.U32 & (BFM_IOSLAVE_IOSCFG_RSVD_20))>>(BFP_IOSLAVE_IOSCFG_RSVD_20))

#define BFP_IOSLAVE_IOSCFG_I2CADDR              (8)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSCFG_I2CADDR              ((uint32_t)0x000fff00)  /* bitfield mask */
#define BFN_IOSLAVE_IOSCFG_I2CADDR              (12)                    /* bitfield width */
#define BFD_IOSLAVE_IOSCFG_I2CADDR              (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSCFG_I2CADDR(v)           ((((uint32_t) v) << (BFP_IOSLAVE_IOSCFG_I2CADDR)) & (BFM_IOSLAVE_IOSCFG_I2CADDR))
#define BFX_IOSLAVE_IOSCFG_I2CADDR(v)           ((((uint32_t) v) & (BFM_IOSLAVE_IOSCFG_I2CADDR)) >> (BFP_IOSLAVE_IOSCFG_I2CADDR))
#define BFW_IOSLAVE_IOSCFG_I2CADDR(v)           (REG_IOSLAVE_IOSCFG.U32 = ( (REG_IOSLAVE_IOSCFG.U32 & ~(BFM_IOSLAVE_IOSCFG_I2CADDR)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSCFG_I2CADDR)) & (BFM_IOSLAVE_IOSCFG_I2CADDR)) ))
#define BFR_IOSLAVE_IOSCFG_I2CADDR()            ((REG_IOSLAVE_IOSCFG.U32 & (BFM_IOSLAVE_IOSCFG_I2CADDR))>>(BFP_IOSLAVE_IOSCFG_I2CADDR))

#define BFP_IOSLAVE_IOSCFG_RSVD_5               (5)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSCFG_RSVD_5               ((uint32_t)0x000000e0)  /* bitfield mask */
#define BFN_IOSLAVE_IOSCFG_RSVD_5               (3)                     /* bitfield width */
#define BFD_IOSLAVE_IOSCFG_RSVD_5               (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSCFG_RSVD_5(v)            ((((uint32_t) v) << (BFP_IOSLAVE_IOSCFG_RSVD_5)) & (BFM_IOSLAVE_IOSCFG_RSVD_5))
#define BFX_IOSLAVE_IOSCFG_RSVD_5(v)            ((((uint32_t) v) & (BFM_IOSLAVE_IOSCFG_RSVD_5)) >> (BFP_IOSLAVE_IOSCFG_RSVD_5))
#define BFW_IOSLAVE_IOSCFG_RSVD_5(v)            (REG_IOSLAVE_IOSCFG.U32 = ( (REG_IOSLAVE_IOSCFG.U32 & ~(BFM_IOSLAVE_IOSCFG_RSVD_5)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSCFG_RSVD_5)) & (BFM_IOSLAVE_IOSCFG_RSVD_5)) ))
#define BFR_IOSLAVE_IOSCFG_RSVD_5()             ((REG_IOSLAVE_IOSCFG.U32 & (BFM_IOSLAVE_IOSCFG_RSVD_5))>>(BFP_IOSLAVE_IOSCFG_RSVD_5))

#define BFP_IOSLAVE_IOSCFG_STARTRD              (4)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSCFG_STARTRD              ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_IOSLAVE_IOSCFG_STARTRD              (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSCFG_STARTRD              (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSCFG_STARTRD(v)           ((((uint32_t) v) << (BFP_IOSLAVE_IOSCFG_STARTRD)) & (BFM_IOSLAVE_IOSCFG_STARTRD))
#define BFX_IOSLAVE_IOSCFG_STARTRD(v)           ((((uint32_t) v) & (BFM_IOSLAVE_IOSCFG_STARTRD)) >> (BFP_IOSLAVE_IOSCFG_STARTRD))
#define BFW_IOSLAVE_IOSCFG_STARTRD(v)           (REG_IOSLAVE_IOSCFG.U32 = ( (REG_IOSLAVE_IOSCFG.U32 & ~(BFM_IOSLAVE_IOSCFG_STARTRD)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSCFG_STARTRD)) & (BFM_IOSLAVE_IOSCFG_STARTRD)) ))
#define BFR_IOSLAVE_IOSCFG_STARTRD()            ((REG_IOSLAVE_IOSCFG.U32 & (BFM_IOSLAVE_IOSCFG_STARTRD))>>(BFP_IOSLAVE_IOSCFG_STARTRD))

#define BFP_IOSLAVE_IOSCFG_RSVD_3               (3)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSCFG_RSVD_3               ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_IOSLAVE_IOSCFG_RSVD_3               (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSCFG_RSVD_3               (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSCFG_RSVD_3(v)            ((((uint32_t) v) << (BFP_IOSLAVE_IOSCFG_RSVD_3)) & (BFM_IOSLAVE_IOSCFG_RSVD_3))
#define BFX_IOSLAVE_IOSCFG_RSVD_3(v)            ((((uint32_t) v) & (BFM_IOSLAVE_IOSCFG_RSVD_3)) >> (BFP_IOSLAVE_IOSCFG_RSVD_3))
#define BFW_IOSLAVE_IOSCFG_RSVD_3(v)            (REG_IOSLAVE_IOSCFG.U32 = ( (REG_IOSLAVE_IOSCFG.U32 & ~(BFM_IOSLAVE_IOSCFG_RSVD_3)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSCFG_RSVD_3)) & (BFM_IOSLAVE_IOSCFG_RSVD_3)) ))
#define BFR_IOSLAVE_IOSCFG_RSVD_3()             ((REG_IOSLAVE_IOSCFG.U32 & (BFM_IOSLAVE_IOSCFG_RSVD_3))>>(BFP_IOSLAVE_IOSCFG_RSVD_3))

#define BFP_IOSLAVE_IOSCFG_LSB                  (2)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSCFG_LSB                  ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_IOSLAVE_IOSCFG_LSB                  (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSCFG_LSB                  (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSCFG_LSB(v)               ((((uint32_t) v) << (BFP_IOSLAVE_IOSCFG_LSB)) & (BFM_IOSLAVE_IOSCFG_LSB))
#define BFX_IOSLAVE_IOSCFG_LSB(v)               ((((uint32_t) v) & (BFM_IOSLAVE_IOSCFG_LSB)) >> (BFP_IOSLAVE_IOSCFG_LSB))
#define BFW_IOSLAVE_IOSCFG_LSB(v)               (REG_IOSLAVE_IOSCFG.U32 = ( (REG_IOSLAVE_IOSCFG.U32 & ~(BFM_IOSLAVE_IOSCFG_LSB)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSCFG_LSB)) & (BFM_IOSLAVE_IOSCFG_LSB)) ))
#define BFR_IOSLAVE_IOSCFG_LSB()                ((REG_IOSLAVE_IOSCFG.U32 & (BFM_IOSLAVE_IOSCFG_LSB))>>(BFP_IOSLAVE_IOSCFG_LSB))

#define BFP_IOSLAVE_IOSCFG_SPOL                 (1)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSCFG_SPOL                 ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_IOSLAVE_IOSCFG_SPOL                 (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSCFG_SPOL                 (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSCFG_SPOL(v)              ((((uint32_t) v) << (BFP_IOSLAVE_IOSCFG_SPOL)) & (BFM_IOSLAVE_IOSCFG_SPOL))
#define BFX_IOSLAVE_IOSCFG_SPOL(v)              ((((uint32_t) v) & (BFM_IOSLAVE_IOSCFG_SPOL)) >> (BFP_IOSLAVE_IOSCFG_SPOL))
#define BFW_IOSLAVE_IOSCFG_SPOL(v)              (REG_IOSLAVE_IOSCFG.U32 = ( (REG_IOSLAVE_IOSCFG.U32 & ~(BFM_IOSLAVE_IOSCFG_SPOL)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSCFG_SPOL)) & (BFM_IOSLAVE_IOSCFG_SPOL)) ))
#define BFR_IOSLAVE_IOSCFG_SPOL()               ((REG_IOSLAVE_IOSCFG.U32 & (BFM_IOSLAVE_IOSCFG_SPOL))>>(BFP_IOSLAVE_IOSCFG_SPOL))

#define BFP_IOSLAVE_IOSCFG_IFCSEL               (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSCFG_IFCSEL               ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_IOSLAVE_IOSCFG_IFCSEL               (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSCFG_IFCSEL               (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSCFG_IFCSEL(v)            ((((uint32_t) v) << (BFP_IOSLAVE_IOSCFG_IFCSEL)) & (BFM_IOSLAVE_IOSCFG_IFCSEL))
#define BFX_IOSLAVE_IOSCFG_IFCSEL(v)            ((((uint32_t) v) & (BFM_IOSLAVE_IOSCFG_IFCSEL)) >> (BFP_IOSLAVE_IOSCFG_IFCSEL))
#define BFW_IOSLAVE_IOSCFG_IFCSEL(v)            (REG_IOSLAVE_IOSCFG.U32 = ( (REG_IOSLAVE_IOSCFG.U32 & ~(BFM_IOSLAVE_IOSCFG_IFCSEL)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSCFG_IFCSEL)) & (BFM_IOSLAVE_IOSCFG_IFCSEL)) ))
#define BFR_IOSLAVE_IOSCFG_IFCSEL()             ((REG_IOSLAVE_IOSCFG.U32 & (BFM_IOSLAVE_IOSCFG_IFCSEL))>>(BFP_IOSLAVE_IOSCFG_IFCSEL))


// *****************************************************************************
//                                                                             *
//  IOSLAVE_PRENC - I/O Slave Configuration                                    *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_5                     : 27;
        unsigned PRENC                      :  5;
    } B;
} reg_ioslave_prenc_t;

#define REG_IOSLAVE_PRENC_ADDR                  (REG_IOSLAVE_BASEADDR + 0x0000011CUL)
#define REG_IOSLAVE_PRENC                       (*(volatile reg_ioslave_prenc_t *) REG_IOSLAVE_PRENC_ADDR)
#define REG_IOSLAVE_PRENC_RD()                  (REG_IOSLAVE_PRENC.U32)
#define REG_IOSLAVE_PRENC_WR(v)                 (REG_IOSLAVE_PRENC.U32 = (v))
#define REG_IOSLAVE_PRENC_CLR(m)                (REG_IOSLAVE_PRENC.U32 = ((REG_IOSLAVE_PRENC.U32) & ~(m)))
#define REG_IOSLAVE_PRENC_SET(m)                (REG_IOSLAVE_PRENC.U32 = ((REG_IOSLAVE_PRENC.U32) | (m)))
#define REG_IOSLAVE_PRENC_DEF                   0x00000000

#define BFP_IOSLAVE_PRENC_RSVD_5                (5)                     /* bitfield lsb */
#define BFM_IOSLAVE_PRENC_RSVD_5                ((uint32_t)0xffffffe0)  /* bitfield mask */
#define BFN_IOSLAVE_PRENC_RSVD_5                (27)                    /* bitfield width */
#define BFD_IOSLAVE_PRENC_RSVD_5                (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_PRENC_RSVD_5(v)             ((((uint32_t) v) << (BFP_IOSLAVE_PRENC_RSVD_5)) & (BFM_IOSLAVE_PRENC_RSVD_5))
#define BFX_IOSLAVE_PRENC_RSVD_5(v)             ((((uint32_t) v) & (BFM_IOSLAVE_PRENC_RSVD_5)) >> (BFP_IOSLAVE_PRENC_RSVD_5))
#define BFW_IOSLAVE_PRENC_RSVD_5(v)             (REG_IOSLAVE_PRENC.U32 = ( (((uint32_t) v)<<(BFP_IOSLAVE_PRENC_RSVD_5)) & (BFM_IOSLAVE_PRENC_RSVD_5)) )
#define BFR_IOSLAVE_PRENC_RSVD_5()              ((REG_IOSLAVE_PRENC.U32 & (BFM_IOSLAVE_PRENC_RSVD_5))>>(BFP_IOSLAVE_PRENC_RSVD_5))

#define BFP_IOSLAVE_PRENC_PRENC                 (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_PRENC_PRENC                 ((uint32_t)0x0000001f)  /* bitfield mask */
#define BFN_IOSLAVE_PRENC_PRENC                 (5)                     /* bitfield width */
#define BFD_IOSLAVE_PRENC_PRENC                 (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_PRENC_PRENC(v)              ((((uint32_t) v) << (BFP_IOSLAVE_PRENC_PRENC)) & (BFM_IOSLAVE_PRENC_PRENC))
#define BFX_IOSLAVE_PRENC_PRENC(v)              ((((uint32_t) v) & (BFM_IOSLAVE_PRENC_PRENC)) >> (BFP_IOSLAVE_PRENC_PRENC))
#define BFW_IOSLAVE_PRENC_PRENC(v)              (REG_IOSLAVE_PRENC.U32 = ( (((uint32_t) v)<<(BFP_IOSLAVE_PRENC_PRENC)) & (BFM_IOSLAVE_PRENC_PRENC)) )
#define BFR_IOSLAVE_PRENC_PRENC()               ((REG_IOSLAVE_PRENC.U32 & (BFM_IOSLAVE_PRENC_PRENC))>>(BFP_IOSLAVE_PRENC_PRENC))


// *****************************************************************************
//                                                                             *
//  IOSLAVE_IOINTCTL - I/O Interrupt Control                                   *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned IOINTSET                   :  8;
        unsigned RSVD_17                    :  7;
        unsigned IOINTCLR                   :  1;
        unsigned IOINT                      :  8;
        unsigned IOINTEN                    :  8;
    } B;
} reg_ioslave_iointctl_t;

#define REG_IOSLAVE_IOINTCTL_ADDR               (REG_IOSLAVE_BASEADDR + 0x00000120UL)
#define REG_IOSLAVE_IOINTCTL                    (*(volatile reg_ioslave_iointctl_t *) REG_IOSLAVE_IOINTCTL_ADDR)
#define REG_IOSLAVE_IOINTCTL_RD()               (REG_IOSLAVE_IOINTCTL.U32)
#define REG_IOSLAVE_IOINTCTL_WR(v)              (REG_IOSLAVE_IOINTCTL.U32 = (v))
#define REG_IOSLAVE_IOINTCTL_CLR(m)             (REG_IOSLAVE_IOINTCTL.U32 = ((REG_IOSLAVE_IOINTCTL.U32) & ~(m)))
#define REG_IOSLAVE_IOINTCTL_SET(m)             (REG_IOSLAVE_IOINTCTL.U32 = ((REG_IOSLAVE_IOINTCTL.U32) | (m)))
#define REG_IOSLAVE_IOINTCTL_DEF                0x00000000

#define BFP_IOSLAVE_IOINTCTL_IOINTSET           (24)                    /* bitfield lsb */
#define BFM_IOSLAVE_IOINTCTL_IOINTSET           ((uint32_t)0xff000000)  /* bitfield mask */
#define BFN_IOSLAVE_IOINTCTL_IOINTSET           (8)                     /* bitfield width */
#define BFD_IOSLAVE_IOINTCTL_IOINTSET           (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOINTCTL_IOINTSET(v)        ((((uint32_t) v) << (BFP_IOSLAVE_IOINTCTL_IOINTSET)) & (BFM_IOSLAVE_IOINTCTL_IOINTSET))
#define BFX_IOSLAVE_IOINTCTL_IOINTSET(v)        ((((uint32_t) v) & (BFM_IOSLAVE_IOINTCTL_IOINTSET)) >> (BFP_IOSLAVE_IOINTCTL_IOINTSET))
#define BFW_IOSLAVE_IOINTCTL_IOINTSET(v)        (REG_IOSLAVE_IOINTCTL.U32 = ( (REG_IOSLAVE_IOINTCTL.U32 & ~(BFM_IOSLAVE_IOINTCTL_IOINTSET)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOINTCTL_IOINTSET)) & (BFM_IOSLAVE_IOINTCTL_IOINTSET)) ))
#define BFR_IOSLAVE_IOINTCTL_IOINTSET()         ((REG_IOSLAVE_IOINTCTL.U32 & (BFM_IOSLAVE_IOINTCTL_IOINTSET))>>(BFP_IOSLAVE_IOINTCTL_IOINTSET))

#define BFP_IOSLAVE_IOINTCTL_RSVD_17            (17)                    /* bitfield lsb */
#define BFM_IOSLAVE_IOINTCTL_RSVD_17            ((uint32_t)0x00fe0000)  /* bitfield mask */
#define BFN_IOSLAVE_IOINTCTL_RSVD_17            (7)                     /* bitfield width */
#define BFD_IOSLAVE_IOINTCTL_RSVD_17            (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOINTCTL_RSVD_17(v)         ((((uint32_t) v) << (BFP_IOSLAVE_IOINTCTL_RSVD_17)) & (BFM_IOSLAVE_IOINTCTL_RSVD_17))
#define BFX_IOSLAVE_IOINTCTL_RSVD_17(v)         ((((uint32_t) v) & (BFM_IOSLAVE_IOINTCTL_RSVD_17)) >> (BFP_IOSLAVE_IOINTCTL_RSVD_17))
#define BFW_IOSLAVE_IOINTCTL_RSVD_17(v)         (REG_IOSLAVE_IOINTCTL.U32 = ( (REG_IOSLAVE_IOINTCTL.U32 & ~(BFM_IOSLAVE_IOINTCTL_RSVD_17)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOINTCTL_RSVD_17)) & (BFM_IOSLAVE_IOINTCTL_RSVD_17)) ))
#define BFR_IOSLAVE_IOINTCTL_RSVD_17()          ((REG_IOSLAVE_IOINTCTL.U32 & (BFM_IOSLAVE_IOINTCTL_RSVD_17))>>(BFP_IOSLAVE_IOINTCTL_RSVD_17))

#define BFP_IOSLAVE_IOINTCTL_IOINTCLR           (16)                    /* bitfield lsb */
#define BFM_IOSLAVE_IOINTCTL_IOINTCLR           ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_IOSLAVE_IOINTCTL_IOINTCLR           (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOINTCTL_IOINTCLR           (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOINTCTL_IOINTCLR(v)        ((((uint32_t) v) << (BFP_IOSLAVE_IOINTCTL_IOINTCLR)) & (BFM_IOSLAVE_IOINTCTL_IOINTCLR))
#define BFX_IOSLAVE_IOINTCTL_IOINTCLR(v)        ((((uint32_t) v) & (BFM_IOSLAVE_IOINTCTL_IOINTCLR)) >> (BFP_IOSLAVE_IOINTCTL_IOINTCLR))
#define BFW_IOSLAVE_IOINTCTL_IOINTCLR(v)        (REG_IOSLAVE_IOINTCTL.U32 = ( (REG_IOSLAVE_IOINTCTL.U32 & ~(BFM_IOSLAVE_IOINTCTL_IOINTCLR)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOINTCTL_IOINTCLR)) & (BFM_IOSLAVE_IOINTCTL_IOINTCLR)) ))
#define BFR_IOSLAVE_IOINTCTL_IOINTCLR()         ((REG_IOSLAVE_IOINTCTL.U32 & (BFM_IOSLAVE_IOINTCTL_IOINTCLR))>>(BFP_IOSLAVE_IOINTCTL_IOINTCLR))

#define BFP_IOSLAVE_IOINTCTL_IOINT              (8)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOINTCTL_IOINT              ((uint32_t)0x0000ff00)  /* bitfield mask */
#define BFN_IOSLAVE_IOINTCTL_IOINT              (8)                     /* bitfield width */
#define BFD_IOSLAVE_IOINTCTL_IOINT              (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOINTCTL_IOINT(v)           ((((uint32_t) v) << (BFP_IOSLAVE_IOINTCTL_IOINT)) & (BFM_IOSLAVE_IOINTCTL_IOINT))
#define BFX_IOSLAVE_IOINTCTL_IOINT(v)           ((((uint32_t) v) & (BFM_IOSLAVE_IOINTCTL_IOINT)) >> (BFP_IOSLAVE_IOINTCTL_IOINT))
#define BFW_IOSLAVE_IOINTCTL_IOINT(v)           (REG_IOSLAVE_IOINTCTL.U32 = ( (REG_IOSLAVE_IOINTCTL.U32 & ~(BFM_IOSLAVE_IOINTCTL_IOINT)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOINTCTL_IOINT)) & (BFM_IOSLAVE_IOINTCTL_IOINT)) ))
#define BFR_IOSLAVE_IOINTCTL_IOINT()            ((REG_IOSLAVE_IOINTCTL.U32 & (BFM_IOSLAVE_IOINTCTL_IOINT))>>(BFP_IOSLAVE_IOINTCTL_IOINT))

#define BFP_IOSLAVE_IOINTCTL_IOINTEN            (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOINTCTL_IOINTEN            ((uint32_t)0x000000ff)  /* bitfield mask */
#define BFN_IOSLAVE_IOINTCTL_IOINTEN            (8)                     /* bitfield width */
#define BFD_IOSLAVE_IOINTCTL_IOINTEN            (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOINTCTL_IOINTEN(v)         ((((uint32_t) v) << (BFP_IOSLAVE_IOINTCTL_IOINTEN)) & (BFM_IOSLAVE_IOINTCTL_IOINTEN))
#define BFX_IOSLAVE_IOINTCTL_IOINTEN(v)         ((((uint32_t) v) & (BFM_IOSLAVE_IOINTCTL_IOINTEN)) >> (BFP_IOSLAVE_IOINTCTL_IOINTEN))
#define BFW_IOSLAVE_IOINTCTL_IOINTEN(v)         (REG_IOSLAVE_IOINTCTL.U32 = ( (REG_IOSLAVE_IOINTCTL.U32 & ~(BFM_IOSLAVE_IOINTCTL_IOINTEN)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOINTCTL_IOINTEN)) & (BFM_IOSLAVE_IOINTCTL_IOINTEN)) ))
#define BFR_IOSLAVE_IOINTCTL_IOINTEN()          ((REG_IOSLAVE_IOINTCTL.U32 & (BFM_IOSLAVE_IOINTCTL_IOINTEN))>>(BFP_IOSLAVE_IOINTCTL_IOINTEN))


// *****************************************************************************
//                                                                             *
//  IOSLAVE_GENADD - General Address Data                                      *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned GADATA                     :  8;
    } B;
} reg_ioslave_genadd_t;

#define REG_IOSLAVE_GENADD_ADDR                 (REG_IOSLAVE_BASEADDR + 0x00000124UL)
#define REG_IOSLAVE_GENADD                      (*(volatile reg_ioslave_genadd_t *) REG_IOSLAVE_GENADD_ADDR)
#define REG_IOSLAVE_GENADD_RD()                 (REG_IOSLAVE_GENADD.U32)
#define REG_IOSLAVE_GENADD_WR(v)                (REG_IOSLAVE_GENADD.U32 = (v))
#define REG_IOSLAVE_GENADD_CLR(m)               (REG_IOSLAVE_GENADD.U32 = ((REG_IOSLAVE_GENADD.U32) & ~(m)))
#define REG_IOSLAVE_GENADD_SET(m)               (REG_IOSLAVE_GENADD.U32 = ((REG_IOSLAVE_GENADD.U32) | (m)))
#define REG_IOSLAVE_GENADD_DEF                  0x00000000

#define BFP_IOSLAVE_GENADD_RSVD_8               (8)                     /* bitfield lsb */
#define BFM_IOSLAVE_GENADD_RSVD_8               ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_IOSLAVE_GENADD_RSVD_8               (24)                    /* bitfield width */
#define BFD_IOSLAVE_GENADD_RSVD_8               (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_GENADD_RSVD_8(v)            ((((uint32_t) v) << (BFP_IOSLAVE_GENADD_RSVD_8)) & (BFM_IOSLAVE_GENADD_RSVD_8))
#define BFX_IOSLAVE_GENADD_RSVD_8(v)            ((((uint32_t) v) & (BFM_IOSLAVE_GENADD_RSVD_8)) >> (BFP_IOSLAVE_GENADD_RSVD_8))
#define BFW_IOSLAVE_GENADD_RSVD_8(v)            (REG_IOSLAVE_GENADD.U32 = ( (((uint32_t) v)<<(BFP_IOSLAVE_GENADD_RSVD_8)) & (BFM_IOSLAVE_GENADD_RSVD_8)) )
#define BFR_IOSLAVE_GENADD_RSVD_8()             ((REG_IOSLAVE_GENADD.U32 & (BFM_IOSLAVE_GENADD_RSVD_8))>>(BFP_IOSLAVE_GENADD_RSVD_8))

#define BFP_IOSLAVE_GENADD_GADATA               (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_GENADD_GADATA               ((uint32_t)0x000000ff)  /* bitfield mask */
#define BFN_IOSLAVE_GENADD_GADATA               (8)                     /* bitfield width */
#define BFD_IOSLAVE_GENADD_GADATA               (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_GENADD_GADATA(v)            ((((uint32_t) v) << (BFP_IOSLAVE_GENADD_GADATA)) & (BFM_IOSLAVE_GENADD_GADATA))
#define BFX_IOSLAVE_GENADD_GADATA(v)            ((((uint32_t) v) & (BFM_IOSLAVE_GENADD_GADATA)) >> (BFP_IOSLAVE_GENADD_GADATA))
#define BFW_IOSLAVE_GENADD_GADATA(v)            (REG_IOSLAVE_GENADD.U32 = ( (((uint32_t) v)<<(BFP_IOSLAVE_GENADD_GADATA)) & (BFM_IOSLAVE_GENADD_GADATA)) )
#define BFR_IOSLAVE_GENADD_GADATA()             ((REG_IOSLAVE_GENADD.U32 & (BFM_IOSLAVE_GENADD_GADATA))>>(BFP_IOSLAVE_GENADD_GADATA))


// *****************************************************************************
//                                                                             *
//  IOSLAVE_IOSLAVEINTEN - IO Slave Interrupts                                 *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_6                     : 26;
        unsigned IOINTW                     :  1;
        unsigned GENAD                      :  1;
        unsigned FRDERR                     :  1;
        unsigned FUNDFL                     :  1;
        unsigned FOVFL                      :  1;
        unsigned FSIZE                      :  1;
    } B;
} reg_ioslave_ioslaveinten_t;

#define REG_IOSLAVE_IOSLAVEINTEN_ADDR           (REG_IOSLAVE_BASEADDR + 0x00000200UL)
#define REG_IOSLAVE_IOSLAVEINTEN                (*(volatile reg_ioslave_ioslaveinten_t *) REG_IOSLAVE_IOSLAVEINTEN_ADDR)
#define REG_IOSLAVE_IOSLAVEINTEN_RD()           (REG_IOSLAVE_IOSLAVEINTEN.U32)
#define REG_IOSLAVE_IOSLAVEINTEN_WR(v)          (REG_IOSLAVE_IOSLAVEINTEN.U32 = (v))
#define REG_IOSLAVE_IOSLAVEINTEN_CLR(m)         (REG_IOSLAVE_IOSLAVEINTEN.U32 = ((REG_IOSLAVE_IOSLAVEINTEN.U32) & ~(m)))
#define REG_IOSLAVE_IOSLAVEINTEN_SET(m)         (REG_IOSLAVE_IOSLAVEINTEN.U32 = ((REG_IOSLAVE_IOSLAVEINTEN.U32) | (m)))
#define REG_IOSLAVE_IOSLAVEINTEN_DEF            0x00000000

#define BFP_IOSLAVE_IOSLAVEINTEN_RSVD_6         (6)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTEN_RSVD_6         ((uint32_t)0xffffffc0)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTEN_RSVD_6         (26)                    /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTEN_RSVD_6         (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTEN_RSVD_6(v)      ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTEN_RSVD_6)) & (BFM_IOSLAVE_IOSLAVEINTEN_RSVD_6))
#define BFX_IOSLAVE_IOSLAVEINTEN_RSVD_6(v)      ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTEN_RSVD_6)) >> (BFP_IOSLAVE_IOSLAVEINTEN_RSVD_6))
#define BFW_IOSLAVE_IOSLAVEINTEN_RSVD_6(v)      (REG_IOSLAVE_IOSLAVEINTEN.U32 = ( (REG_IOSLAVE_IOSLAVEINTEN.U32 & ~(BFM_IOSLAVE_IOSLAVEINTEN_RSVD_6)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTEN_RSVD_6)) & (BFM_IOSLAVE_IOSLAVEINTEN_RSVD_6)) ))
#define BFR_IOSLAVE_IOSLAVEINTEN_RSVD_6()       ((REG_IOSLAVE_IOSLAVEINTEN.U32 & (BFM_IOSLAVE_IOSLAVEINTEN_RSVD_6))>>(BFP_IOSLAVE_IOSLAVEINTEN_RSVD_6))
#define BFS_IOSLAVE_IOSLAVEINTEN_RSVD_6()       (REG_IOSLAVE_IOSLAVEINTEN.U32 = (BFM_IOSLAVE_IOSLAVEINTEN_RSVD_6) )

#define BFP_IOSLAVE_IOSLAVEINTEN_IOINTW         (5)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTEN_IOINTW         ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTEN_IOINTW         (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTEN_IOINTW         (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTEN_IOINTW(v)      ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTEN_IOINTW)) & (BFM_IOSLAVE_IOSLAVEINTEN_IOINTW))
#define BFX_IOSLAVE_IOSLAVEINTEN_IOINTW(v)      ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTEN_IOINTW)) >> (BFP_IOSLAVE_IOSLAVEINTEN_IOINTW))
#define BFW_IOSLAVE_IOSLAVEINTEN_IOINTW(v)      (REG_IOSLAVE_IOSLAVEINTEN.U32 = ( (REG_IOSLAVE_IOSLAVEINTEN.U32 & ~(BFM_IOSLAVE_IOSLAVEINTEN_IOINTW)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTEN_IOINTW)) & (BFM_IOSLAVE_IOSLAVEINTEN_IOINTW)) ))
#define BFR_IOSLAVE_IOSLAVEINTEN_IOINTW()       ((REG_IOSLAVE_IOSLAVEINTEN.U32 & (BFM_IOSLAVE_IOSLAVEINTEN_IOINTW))>>(BFP_IOSLAVE_IOSLAVEINTEN_IOINTW))
#define BFS_IOSLAVE_IOSLAVEINTEN_IOINTW()       (REG_IOSLAVE_IOSLAVEINTEN.U32 = (BFM_IOSLAVE_IOSLAVEINTEN_IOINTW) )

#define BFP_IOSLAVE_IOSLAVEINTEN_GENAD          (4)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTEN_GENAD          ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTEN_GENAD          (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTEN_GENAD          (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTEN_GENAD(v)       ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTEN_GENAD)) & (BFM_IOSLAVE_IOSLAVEINTEN_GENAD))
#define BFX_IOSLAVE_IOSLAVEINTEN_GENAD(v)       ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTEN_GENAD)) >> (BFP_IOSLAVE_IOSLAVEINTEN_GENAD))
#define BFW_IOSLAVE_IOSLAVEINTEN_GENAD(v)       (REG_IOSLAVE_IOSLAVEINTEN.U32 = ( (REG_IOSLAVE_IOSLAVEINTEN.U32 & ~(BFM_IOSLAVE_IOSLAVEINTEN_GENAD)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTEN_GENAD)) & (BFM_IOSLAVE_IOSLAVEINTEN_GENAD)) ))
#define BFR_IOSLAVE_IOSLAVEINTEN_GENAD()        ((REG_IOSLAVE_IOSLAVEINTEN.U32 & (BFM_IOSLAVE_IOSLAVEINTEN_GENAD))>>(BFP_IOSLAVE_IOSLAVEINTEN_GENAD))
#define BFS_IOSLAVE_IOSLAVEINTEN_GENAD()        (REG_IOSLAVE_IOSLAVEINTEN.U32 = (BFM_IOSLAVE_IOSLAVEINTEN_GENAD) )

#define BFP_IOSLAVE_IOSLAVEINTEN_FRDERR         (3)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTEN_FRDERR         ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTEN_FRDERR         (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTEN_FRDERR         (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTEN_FRDERR(v)      ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTEN_FRDERR)) & (BFM_IOSLAVE_IOSLAVEINTEN_FRDERR))
#define BFX_IOSLAVE_IOSLAVEINTEN_FRDERR(v)      ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTEN_FRDERR)) >> (BFP_IOSLAVE_IOSLAVEINTEN_FRDERR))
#define BFW_IOSLAVE_IOSLAVEINTEN_FRDERR(v)      (REG_IOSLAVE_IOSLAVEINTEN.U32 = ( (REG_IOSLAVE_IOSLAVEINTEN.U32 & ~(BFM_IOSLAVE_IOSLAVEINTEN_FRDERR)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTEN_FRDERR)) & (BFM_IOSLAVE_IOSLAVEINTEN_FRDERR)) ))
#define BFR_IOSLAVE_IOSLAVEINTEN_FRDERR()       ((REG_IOSLAVE_IOSLAVEINTEN.U32 & (BFM_IOSLAVE_IOSLAVEINTEN_FRDERR))>>(BFP_IOSLAVE_IOSLAVEINTEN_FRDERR))
#define BFS_IOSLAVE_IOSLAVEINTEN_FRDERR()       (REG_IOSLAVE_IOSLAVEINTEN.U32 = (BFM_IOSLAVE_IOSLAVEINTEN_FRDERR) )

#define BFP_IOSLAVE_IOSLAVEINTEN_FUNDFL         (2)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTEN_FUNDFL         ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTEN_FUNDFL         (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTEN_FUNDFL         (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTEN_FUNDFL(v)      ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTEN_FUNDFL)) & (BFM_IOSLAVE_IOSLAVEINTEN_FUNDFL))
#define BFX_IOSLAVE_IOSLAVEINTEN_FUNDFL(v)      ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTEN_FUNDFL)) >> (BFP_IOSLAVE_IOSLAVEINTEN_FUNDFL))
#define BFW_IOSLAVE_IOSLAVEINTEN_FUNDFL(v)      (REG_IOSLAVE_IOSLAVEINTEN.U32 = ( (REG_IOSLAVE_IOSLAVEINTEN.U32 & ~(BFM_IOSLAVE_IOSLAVEINTEN_FUNDFL)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTEN_FUNDFL)) & (BFM_IOSLAVE_IOSLAVEINTEN_FUNDFL)) ))
#define BFR_IOSLAVE_IOSLAVEINTEN_FUNDFL()       ((REG_IOSLAVE_IOSLAVEINTEN.U32 & (BFM_IOSLAVE_IOSLAVEINTEN_FUNDFL))>>(BFP_IOSLAVE_IOSLAVEINTEN_FUNDFL))
#define BFS_IOSLAVE_IOSLAVEINTEN_FUNDFL()       (REG_IOSLAVE_IOSLAVEINTEN.U32 = (BFM_IOSLAVE_IOSLAVEINTEN_FUNDFL) )

#define BFP_IOSLAVE_IOSLAVEINTEN_FOVFL          (1)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTEN_FOVFL          ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTEN_FOVFL          (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTEN_FOVFL          (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTEN_FOVFL(v)       ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTEN_FOVFL)) & (BFM_IOSLAVE_IOSLAVEINTEN_FOVFL))
#define BFX_IOSLAVE_IOSLAVEINTEN_FOVFL(v)       ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTEN_FOVFL)) >> (BFP_IOSLAVE_IOSLAVEINTEN_FOVFL))
#define BFW_IOSLAVE_IOSLAVEINTEN_FOVFL(v)       (REG_IOSLAVE_IOSLAVEINTEN.U32 = ( (REG_IOSLAVE_IOSLAVEINTEN.U32 & ~(BFM_IOSLAVE_IOSLAVEINTEN_FOVFL)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTEN_FOVFL)) & (BFM_IOSLAVE_IOSLAVEINTEN_FOVFL)) ))
#define BFR_IOSLAVE_IOSLAVEINTEN_FOVFL()        ((REG_IOSLAVE_IOSLAVEINTEN.U32 & (BFM_IOSLAVE_IOSLAVEINTEN_FOVFL))>>(BFP_IOSLAVE_IOSLAVEINTEN_FOVFL))
#define BFS_IOSLAVE_IOSLAVEINTEN_FOVFL()        (REG_IOSLAVE_IOSLAVEINTEN.U32 = (BFM_IOSLAVE_IOSLAVEINTEN_FOVFL) )

#define BFP_IOSLAVE_IOSLAVEINTEN_FSIZE          (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTEN_FSIZE          ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTEN_FSIZE          (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTEN_FSIZE          (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTEN_FSIZE(v)       ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTEN_FSIZE)) & (BFM_IOSLAVE_IOSLAVEINTEN_FSIZE))
#define BFX_IOSLAVE_IOSLAVEINTEN_FSIZE(v)       ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTEN_FSIZE)) >> (BFP_IOSLAVE_IOSLAVEINTEN_FSIZE))
#define BFW_IOSLAVE_IOSLAVEINTEN_FSIZE(v)       (REG_IOSLAVE_IOSLAVEINTEN.U32 = ( (REG_IOSLAVE_IOSLAVEINTEN.U32 & ~(BFM_IOSLAVE_IOSLAVEINTEN_FSIZE)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTEN_FSIZE)) & (BFM_IOSLAVE_IOSLAVEINTEN_FSIZE)) ))
#define BFR_IOSLAVE_IOSLAVEINTEN_FSIZE()        ((REG_IOSLAVE_IOSLAVEINTEN.U32 & (BFM_IOSLAVE_IOSLAVEINTEN_FSIZE))>>(BFP_IOSLAVE_IOSLAVEINTEN_FSIZE))
#define BFS_IOSLAVE_IOSLAVEINTEN_FSIZE()        (REG_IOSLAVE_IOSLAVEINTEN.U32 = (BFM_IOSLAVE_IOSLAVEINTEN_FSIZE) )


// *****************************************************************************
//                                                                             *
//  IOSLAVE_IOSLAVEINTSTAT - IO Slave Interrupts                               *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_6                     : 26;
        unsigned IOINTW                     :  1;
        unsigned GENAD                      :  1;
        unsigned FRDERR                     :  1;
        unsigned FUNDFL                     :  1;
        unsigned FOVFL                      :  1;
        unsigned FSIZE                      :  1;
    } B;
} reg_ioslave_ioslaveintstat_t;

#define REG_IOSLAVE_IOSLAVEINTSTAT_ADDR         (REG_IOSLAVE_BASEADDR + 0x00000204UL)
#define REG_IOSLAVE_IOSLAVEINTSTAT              (*(volatile reg_ioslave_ioslaveintstat_t *) REG_IOSLAVE_IOSLAVEINTSTAT_ADDR)
#define REG_IOSLAVE_IOSLAVEINTSTAT_RD()         (REG_IOSLAVE_IOSLAVEINTSTAT.U32)
#define REG_IOSLAVE_IOSLAVEINTSTAT_WR(v)        (REG_IOSLAVE_IOSLAVEINTSTAT.U32 = (v))
#define REG_IOSLAVE_IOSLAVEINTSTAT_CLR(m)       (REG_IOSLAVE_IOSLAVEINTSTAT.U32 = ((REG_IOSLAVE_IOSLAVEINTSTAT.U32) & ~(m)))
#define REG_IOSLAVE_IOSLAVEINTSTAT_SET(m)       (REG_IOSLAVE_IOSLAVEINTSTAT.U32 = ((REG_IOSLAVE_IOSLAVEINTSTAT.U32) | (m)))
#define REG_IOSLAVE_IOSLAVEINTSTAT_DEF          0x00000000

#define BFP_IOSLAVE_IOSLAVEINTSTAT_RSVD_6       (6)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTSTAT_RSVD_6       ((uint32_t)0xffffffc0)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTSTAT_RSVD_6       (26)                    /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTSTAT_RSVD_6       (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTSTAT_RSVD_6(v)    ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTSTAT_RSVD_6)) & (BFM_IOSLAVE_IOSLAVEINTSTAT_RSVD_6))
#define BFX_IOSLAVE_IOSLAVEINTSTAT_RSVD_6(v)    ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTSTAT_RSVD_6)) >> (BFP_IOSLAVE_IOSLAVEINTSTAT_RSVD_6))
#define BFW_IOSLAVE_IOSLAVEINTSTAT_RSVD_6(v)    (REG_IOSLAVE_IOSLAVEINTSTAT.U32 = ( (REG_IOSLAVE_IOSLAVEINTSTAT.U32 & ~(BFM_IOSLAVE_IOSLAVEINTSTAT_RSVD_6)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTSTAT_RSVD_6)) & (BFM_IOSLAVE_IOSLAVEINTSTAT_RSVD_6)) ))
#define BFR_IOSLAVE_IOSLAVEINTSTAT_RSVD_6()     ((REG_IOSLAVE_IOSLAVEINTSTAT.U32 & (BFM_IOSLAVE_IOSLAVEINTSTAT_RSVD_6))>>(BFP_IOSLAVE_IOSLAVEINTSTAT_RSVD_6))
#define BFS_IOSLAVE_IOSLAVEINTSTAT_RSVD_6()     (REG_IOSLAVE_IOSLAVEINTSTAT.U32 = (BFM_IOSLAVE_IOSLAVEINTSTAT_RSVD_6) )

#define BFP_IOSLAVE_IOSLAVEINTSTAT_IOINTW       (5)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTSTAT_IOINTW       ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTSTAT_IOINTW       (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTSTAT_IOINTW       (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTSTAT_IOINTW(v)    ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTSTAT_IOINTW)) & (BFM_IOSLAVE_IOSLAVEINTSTAT_IOINTW))
#define BFX_IOSLAVE_IOSLAVEINTSTAT_IOINTW(v)    ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTSTAT_IOINTW)) >> (BFP_IOSLAVE_IOSLAVEINTSTAT_IOINTW))
#define BFW_IOSLAVE_IOSLAVEINTSTAT_IOINTW(v)    (REG_IOSLAVE_IOSLAVEINTSTAT.U32 = ( (REG_IOSLAVE_IOSLAVEINTSTAT.U32 & ~(BFM_IOSLAVE_IOSLAVEINTSTAT_IOINTW)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTSTAT_IOINTW)) & (BFM_IOSLAVE_IOSLAVEINTSTAT_IOINTW)) ))
#define BFR_IOSLAVE_IOSLAVEINTSTAT_IOINTW()     ((REG_IOSLAVE_IOSLAVEINTSTAT.U32 & (BFM_IOSLAVE_IOSLAVEINTSTAT_IOINTW))>>(BFP_IOSLAVE_IOSLAVEINTSTAT_IOINTW))
#define BFS_IOSLAVE_IOSLAVEINTSTAT_IOINTW()     (REG_IOSLAVE_IOSLAVEINTSTAT.U32 = (BFM_IOSLAVE_IOSLAVEINTSTAT_IOINTW) )

#define BFP_IOSLAVE_IOSLAVEINTSTAT_GENAD        (4)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTSTAT_GENAD        ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTSTAT_GENAD        (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTSTAT_GENAD        (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTSTAT_GENAD(v)     ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTSTAT_GENAD)) & (BFM_IOSLAVE_IOSLAVEINTSTAT_GENAD))
#define BFX_IOSLAVE_IOSLAVEINTSTAT_GENAD(v)     ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTSTAT_GENAD)) >> (BFP_IOSLAVE_IOSLAVEINTSTAT_GENAD))
#define BFW_IOSLAVE_IOSLAVEINTSTAT_GENAD(v)     (REG_IOSLAVE_IOSLAVEINTSTAT.U32 = ( (REG_IOSLAVE_IOSLAVEINTSTAT.U32 & ~(BFM_IOSLAVE_IOSLAVEINTSTAT_GENAD)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTSTAT_GENAD)) & (BFM_IOSLAVE_IOSLAVEINTSTAT_GENAD)) ))
#define BFR_IOSLAVE_IOSLAVEINTSTAT_GENAD()      ((REG_IOSLAVE_IOSLAVEINTSTAT.U32 & (BFM_IOSLAVE_IOSLAVEINTSTAT_GENAD))>>(BFP_IOSLAVE_IOSLAVEINTSTAT_GENAD))
#define BFS_IOSLAVE_IOSLAVEINTSTAT_GENAD()      (REG_IOSLAVE_IOSLAVEINTSTAT.U32 = (BFM_IOSLAVE_IOSLAVEINTSTAT_GENAD) )

#define BFP_IOSLAVE_IOSLAVEINTSTAT_FRDERR       (3)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTSTAT_FRDERR       ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTSTAT_FRDERR       (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTSTAT_FRDERR       (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTSTAT_FRDERR(v)    ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTSTAT_FRDERR)) & (BFM_IOSLAVE_IOSLAVEINTSTAT_FRDERR))
#define BFX_IOSLAVE_IOSLAVEINTSTAT_FRDERR(v)    ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTSTAT_FRDERR)) >> (BFP_IOSLAVE_IOSLAVEINTSTAT_FRDERR))
#define BFW_IOSLAVE_IOSLAVEINTSTAT_FRDERR(v)    (REG_IOSLAVE_IOSLAVEINTSTAT.U32 = ( (REG_IOSLAVE_IOSLAVEINTSTAT.U32 & ~(BFM_IOSLAVE_IOSLAVEINTSTAT_FRDERR)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTSTAT_FRDERR)) & (BFM_IOSLAVE_IOSLAVEINTSTAT_FRDERR)) ))
#define BFR_IOSLAVE_IOSLAVEINTSTAT_FRDERR()     ((REG_IOSLAVE_IOSLAVEINTSTAT.U32 & (BFM_IOSLAVE_IOSLAVEINTSTAT_FRDERR))>>(BFP_IOSLAVE_IOSLAVEINTSTAT_FRDERR))
#define BFS_IOSLAVE_IOSLAVEINTSTAT_FRDERR()     (REG_IOSLAVE_IOSLAVEINTSTAT.U32 = (BFM_IOSLAVE_IOSLAVEINTSTAT_FRDERR) )

#define BFP_IOSLAVE_IOSLAVEINTSTAT_FUNDFL       (2)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTSTAT_FUNDFL       ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTSTAT_FUNDFL       (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTSTAT_FUNDFL       (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTSTAT_FUNDFL(v)    ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTSTAT_FUNDFL)) & (BFM_IOSLAVE_IOSLAVEINTSTAT_FUNDFL))
#define BFX_IOSLAVE_IOSLAVEINTSTAT_FUNDFL(v)    ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTSTAT_FUNDFL)) >> (BFP_IOSLAVE_IOSLAVEINTSTAT_FUNDFL))
#define BFW_IOSLAVE_IOSLAVEINTSTAT_FUNDFL(v)    (REG_IOSLAVE_IOSLAVEINTSTAT.U32 = ( (REG_IOSLAVE_IOSLAVEINTSTAT.U32 & ~(BFM_IOSLAVE_IOSLAVEINTSTAT_FUNDFL)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTSTAT_FUNDFL)) & (BFM_IOSLAVE_IOSLAVEINTSTAT_FUNDFL)) ))
#define BFR_IOSLAVE_IOSLAVEINTSTAT_FUNDFL()     ((REG_IOSLAVE_IOSLAVEINTSTAT.U32 & (BFM_IOSLAVE_IOSLAVEINTSTAT_FUNDFL))>>(BFP_IOSLAVE_IOSLAVEINTSTAT_FUNDFL))
#define BFS_IOSLAVE_IOSLAVEINTSTAT_FUNDFL()     (REG_IOSLAVE_IOSLAVEINTSTAT.U32 = (BFM_IOSLAVE_IOSLAVEINTSTAT_FUNDFL) )

#define BFP_IOSLAVE_IOSLAVEINTSTAT_FOVFL        (1)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTSTAT_FOVFL        ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTSTAT_FOVFL        (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTSTAT_FOVFL        (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTSTAT_FOVFL(v)     ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTSTAT_FOVFL)) & (BFM_IOSLAVE_IOSLAVEINTSTAT_FOVFL))
#define BFX_IOSLAVE_IOSLAVEINTSTAT_FOVFL(v)     ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTSTAT_FOVFL)) >> (BFP_IOSLAVE_IOSLAVEINTSTAT_FOVFL))
#define BFW_IOSLAVE_IOSLAVEINTSTAT_FOVFL(v)     (REG_IOSLAVE_IOSLAVEINTSTAT.U32 = ( (REG_IOSLAVE_IOSLAVEINTSTAT.U32 & ~(BFM_IOSLAVE_IOSLAVEINTSTAT_FOVFL)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTSTAT_FOVFL)) & (BFM_IOSLAVE_IOSLAVEINTSTAT_FOVFL)) ))
#define BFR_IOSLAVE_IOSLAVEINTSTAT_FOVFL()      ((REG_IOSLAVE_IOSLAVEINTSTAT.U32 & (BFM_IOSLAVE_IOSLAVEINTSTAT_FOVFL))>>(BFP_IOSLAVE_IOSLAVEINTSTAT_FOVFL))
#define BFS_IOSLAVE_IOSLAVEINTSTAT_FOVFL()      (REG_IOSLAVE_IOSLAVEINTSTAT.U32 = (BFM_IOSLAVE_IOSLAVEINTSTAT_FOVFL) )

#define BFP_IOSLAVE_IOSLAVEINTSTAT_FSIZE        (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTSTAT_FSIZE        ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTSTAT_FSIZE        (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTSTAT_FSIZE        (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTSTAT_FSIZE(v)     ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTSTAT_FSIZE)) & (BFM_IOSLAVE_IOSLAVEINTSTAT_FSIZE))
#define BFX_IOSLAVE_IOSLAVEINTSTAT_FSIZE(v)     ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTSTAT_FSIZE)) >> (BFP_IOSLAVE_IOSLAVEINTSTAT_FSIZE))
#define BFW_IOSLAVE_IOSLAVEINTSTAT_FSIZE(v)     (REG_IOSLAVE_IOSLAVEINTSTAT.U32 = ( (REG_IOSLAVE_IOSLAVEINTSTAT.U32 & ~(BFM_IOSLAVE_IOSLAVEINTSTAT_FSIZE)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTSTAT_FSIZE)) & (BFM_IOSLAVE_IOSLAVEINTSTAT_FSIZE)) ))
#define BFR_IOSLAVE_IOSLAVEINTSTAT_FSIZE()      ((REG_IOSLAVE_IOSLAVEINTSTAT.U32 & (BFM_IOSLAVE_IOSLAVEINTSTAT_FSIZE))>>(BFP_IOSLAVE_IOSLAVEINTSTAT_FSIZE))
#define BFS_IOSLAVE_IOSLAVEINTSTAT_FSIZE()      (REG_IOSLAVE_IOSLAVEINTSTAT.U32 = (BFM_IOSLAVE_IOSLAVEINTSTAT_FSIZE) )


// *****************************************************************************
//                                                                             *
//  IOSLAVE_IOSLAVEINTCLR - IO Slave Interrupts                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_6                     : 26;
        unsigned IOINTW                     :  1;
        unsigned GENAD                      :  1;
        unsigned FRDERR                     :  1;
        unsigned FUNDFL                     :  1;
        unsigned FOVFL                      :  1;
        unsigned FSIZE                      :  1;
    } B;
} reg_ioslave_ioslaveintclr_t;

#define REG_IOSLAVE_IOSLAVEINTCLR_ADDR          (REG_IOSLAVE_BASEADDR + 0x00000208UL)
#define REG_IOSLAVE_IOSLAVEINTCLR               (*(volatile reg_ioslave_ioslaveintclr_t *) REG_IOSLAVE_IOSLAVEINTCLR_ADDR)
#define REG_IOSLAVE_IOSLAVEINTCLR_RD()          (REG_IOSLAVE_IOSLAVEINTCLR.U32)
#define REG_IOSLAVE_IOSLAVEINTCLR_WR(v)         (REG_IOSLAVE_IOSLAVEINTCLR.U32 = (v))
#define REG_IOSLAVE_IOSLAVEINTCLR_CLR(m)        (REG_IOSLAVE_IOSLAVEINTCLR.U32 = ((REG_IOSLAVE_IOSLAVEINTCLR.U32) & ~(m)))
#define REG_IOSLAVE_IOSLAVEINTCLR_SET(m)        (REG_IOSLAVE_IOSLAVEINTCLR.U32 = ((REG_IOSLAVE_IOSLAVEINTCLR.U32) | (m)))
#define REG_IOSLAVE_IOSLAVEINTCLR_DEF           0x00000000

#define BFP_IOSLAVE_IOSLAVEINTCLR_RSVD_6        (6)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTCLR_RSVD_6        ((uint32_t)0xffffffc0)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTCLR_RSVD_6        (26)                    /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTCLR_RSVD_6        (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTCLR_RSVD_6(v)     ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTCLR_RSVD_6)) & (BFM_IOSLAVE_IOSLAVEINTCLR_RSVD_6))
#define BFX_IOSLAVE_IOSLAVEINTCLR_RSVD_6(v)     ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTCLR_RSVD_6)) >> (BFP_IOSLAVE_IOSLAVEINTCLR_RSVD_6))
#define BFW_IOSLAVE_IOSLAVEINTCLR_RSVD_6(v)     (REG_IOSLAVE_IOSLAVEINTCLR.U32 = ( (REG_IOSLAVE_IOSLAVEINTCLR.U32 & ~(BFM_IOSLAVE_IOSLAVEINTCLR_RSVD_6)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTCLR_RSVD_6)) & (BFM_IOSLAVE_IOSLAVEINTCLR_RSVD_6)) ))
#define BFR_IOSLAVE_IOSLAVEINTCLR_RSVD_6()      ((REG_IOSLAVE_IOSLAVEINTCLR.U32 & (BFM_IOSLAVE_IOSLAVEINTCLR_RSVD_6))>>(BFP_IOSLAVE_IOSLAVEINTCLR_RSVD_6))
#define BFS_IOSLAVE_IOSLAVEINTCLR_RSVD_6()      (REG_IOSLAVE_IOSLAVEINTCLR.U32 = (BFM_IOSLAVE_IOSLAVEINTCLR_RSVD_6) )

#define BFP_IOSLAVE_IOSLAVEINTCLR_IOINTW        (5)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTCLR_IOINTW        ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTCLR_IOINTW        (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTCLR_IOINTW        (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTCLR_IOINTW(v)     ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTCLR_IOINTW)) & (BFM_IOSLAVE_IOSLAVEINTCLR_IOINTW))
#define BFX_IOSLAVE_IOSLAVEINTCLR_IOINTW(v)     ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTCLR_IOINTW)) >> (BFP_IOSLAVE_IOSLAVEINTCLR_IOINTW))
#define BFW_IOSLAVE_IOSLAVEINTCLR_IOINTW(v)     (REG_IOSLAVE_IOSLAVEINTCLR.U32 = ( (REG_IOSLAVE_IOSLAVEINTCLR.U32 & ~(BFM_IOSLAVE_IOSLAVEINTCLR_IOINTW)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTCLR_IOINTW)) & (BFM_IOSLAVE_IOSLAVEINTCLR_IOINTW)) ))
#define BFR_IOSLAVE_IOSLAVEINTCLR_IOINTW()      ((REG_IOSLAVE_IOSLAVEINTCLR.U32 & (BFM_IOSLAVE_IOSLAVEINTCLR_IOINTW))>>(BFP_IOSLAVE_IOSLAVEINTCLR_IOINTW))
#define BFS_IOSLAVE_IOSLAVEINTCLR_IOINTW()      (REG_IOSLAVE_IOSLAVEINTCLR.U32 = (BFM_IOSLAVE_IOSLAVEINTCLR_IOINTW) )

#define BFP_IOSLAVE_IOSLAVEINTCLR_GENAD         (4)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTCLR_GENAD         ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTCLR_GENAD         (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTCLR_GENAD         (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTCLR_GENAD(v)      ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTCLR_GENAD)) & (BFM_IOSLAVE_IOSLAVEINTCLR_GENAD))
#define BFX_IOSLAVE_IOSLAVEINTCLR_GENAD(v)      ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTCLR_GENAD)) >> (BFP_IOSLAVE_IOSLAVEINTCLR_GENAD))
#define BFW_IOSLAVE_IOSLAVEINTCLR_GENAD(v)      (REG_IOSLAVE_IOSLAVEINTCLR.U32 = ( (REG_IOSLAVE_IOSLAVEINTCLR.U32 & ~(BFM_IOSLAVE_IOSLAVEINTCLR_GENAD)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTCLR_GENAD)) & (BFM_IOSLAVE_IOSLAVEINTCLR_GENAD)) ))
#define BFR_IOSLAVE_IOSLAVEINTCLR_GENAD()       ((REG_IOSLAVE_IOSLAVEINTCLR.U32 & (BFM_IOSLAVE_IOSLAVEINTCLR_GENAD))>>(BFP_IOSLAVE_IOSLAVEINTCLR_GENAD))
#define BFS_IOSLAVE_IOSLAVEINTCLR_GENAD()       (REG_IOSLAVE_IOSLAVEINTCLR.U32 = (BFM_IOSLAVE_IOSLAVEINTCLR_GENAD) )

#define BFP_IOSLAVE_IOSLAVEINTCLR_FRDERR        (3)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTCLR_FRDERR        ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTCLR_FRDERR        (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTCLR_FRDERR        (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTCLR_FRDERR(v)     ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTCLR_FRDERR)) & (BFM_IOSLAVE_IOSLAVEINTCLR_FRDERR))
#define BFX_IOSLAVE_IOSLAVEINTCLR_FRDERR(v)     ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTCLR_FRDERR)) >> (BFP_IOSLAVE_IOSLAVEINTCLR_FRDERR))
#define BFW_IOSLAVE_IOSLAVEINTCLR_FRDERR(v)     (REG_IOSLAVE_IOSLAVEINTCLR.U32 = ( (REG_IOSLAVE_IOSLAVEINTCLR.U32 & ~(BFM_IOSLAVE_IOSLAVEINTCLR_FRDERR)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTCLR_FRDERR)) & (BFM_IOSLAVE_IOSLAVEINTCLR_FRDERR)) ))
#define BFR_IOSLAVE_IOSLAVEINTCLR_FRDERR()      ((REG_IOSLAVE_IOSLAVEINTCLR.U32 & (BFM_IOSLAVE_IOSLAVEINTCLR_FRDERR))>>(BFP_IOSLAVE_IOSLAVEINTCLR_FRDERR))
#define BFS_IOSLAVE_IOSLAVEINTCLR_FRDERR()      (REG_IOSLAVE_IOSLAVEINTCLR.U32 = (BFM_IOSLAVE_IOSLAVEINTCLR_FRDERR) )

#define BFP_IOSLAVE_IOSLAVEINTCLR_FUNDFL        (2)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTCLR_FUNDFL        ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTCLR_FUNDFL        (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTCLR_FUNDFL        (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTCLR_FUNDFL(v)     ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTCLR_FUNDFL)) & (BFM_IOSLAVE_IOSLAVEINTCLR_FUNDFL))
#define BFX_IOSLAVE_IOSLAVEINTCLR_FUNDFL(v)     ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTCLR_FUNDFL)) >> (BFP_IOSLAVE_IOSLAVEINTCLR_FUNDFL))
#define BFW_IOSLAVE_IOSLAVEINTCLR_FUNDFL(v)     (REG_IOSLAVE_IOSLAVEINTCLR.U32 = ( (REG_IOSLAVE_IOSLAVEINTCLR.U32 & ~(BFM_IOSLAVE_IOSLAVEINTCLR_FUNDFL)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTCLR_FUNDFL)) & (BFM_IOSLAVE_IOSLAVEINTCLR_FUNDFL)) ))
#define BFR_IOSLAVE_IOSLAVEINTCLR_FUNDFL()      ((REG_IOSLAVE_IOSLAVEINTCLR.U32 & (BFM_IOSLAVE_IOSLAVEINTCLR_FUNDFL))>>(BFP_IOSLAVE_IOSLAVEINTCLR_FUNDFL))
#define BFS_IOSLAVE_IOSLAVEINTCLR_FUNDFL()      (REG_IOSLAVE_IOSLAVEINTCLR.U32 = (BFM_IOSLAVE_IOSLAVEINTCLR_FUNDFL) )

#define BFP_IOSLAVE_IOSLAVEINTCLR_FOVFL         (1)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTCLR_FOVFL         ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTCLR_FOVFL         (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTCLR_FOVFL         (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTCLR_FOVFL(v)      ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTCLR_FOVFL)) & (BFM_IOSLAVE_IOSLAVEINTCLR_FOVFL))
#define BFX_IOSLAVE_IOSLAVEINTCLR_FOVFL(v)      ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTCLR_FOVFL)) >> (BFP_IOSLAVE_IOSLAVEINTCLR_FOVFL))
#define BFW_IOSLAVE_IOSLAVEINTCLR_FOVFL(v)      (REG_IOSLAVE_IOSLAVEINTCLR.U32 = ( (REG_IOSLAVE_IOSLAVEINTCLR.U32 & ~(BFM_IOSLAVE_IOSLAVEINTCLR_FOVFL)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTCLR_FOVFL)) & (BFM_IOSLAVE_IOSLAVEINTCLR_FOVFL)) ))
#define BFR_IOSLAVE_IOSLAVEINTCLR_FOVFL()       ((REG_IOSLAVE_IOSLAVEINTCLR.U32 & (BFM_IOSLAVE_IOSLAVEINTCLR_FOVFL))>>(BFP_IOSLAVE_IOSLAVEINTCLR_FOVFL))
#define BFS_IOSLAVE_IOSLAVEINTCLR_FOVFL()       (REG_IOSLAVE_IOSLAVEINTCLR.U32 = (BFM_IOSLAVE_IOSLAVEINTCLR_FOVFL) )

#define BFP_IOSLAVE_IOSLAVEINTCLR_FSIZE         (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTCLR_FSIZE         ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTCLR_FSIZE         (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTCLR_FSIZE         (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTCLR_FSIZE(v)      ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTCLR_FSIZE)) & (BFM_IOSLAVE_IOSLAVEINTCLR_FSIZE))
#define BFX_IOSLAVE_IOSLAVEINTCLR_FSIZE(v)      ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTCLR_FSIZE)) >> (BFP_IOSLAVE_IOSLAVEINTCLR_FSIZE))
#define BFW_IOSLAVE_IOSLAVEINTCLR_FSIZE(v)      (REG_IOSLAVE_IOSLAVEINTCLR.U32 = ( (REG_IOSLAVE_IOSLAVEINTCLR.U32 & ~(BFM_IOSLAVE_IOSLAVEINTCLR_FSIZE)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTCLR_FSIZE)) & (BFM_IOSLAVE_IOSLAVEINTCLR_FSIZE)) ))
#define BFR_IOSLAVE_IOSLAVEINTCLR_FSIZE()       ((REG_IOSLAVE_IOSLAVEINTCLR.U32 & (BFM_IOSLAVE_IOSLAVEINTCLR_FSIZE))>>(BFP_IOSLAVE_IOSLAVEINTCLR_FSIZE))
#define BFS_IOSLAVE_IOSLAVEINTCLR_FSIZE()       (REG_IOSLAVE_IOSLAVEINTCLR.U32 = (BFM_IOSLAVE_IOSLAVEINTCLR_FSIZE) )


// *****************************************************************************
//                                                                             *
//  IOSLAVE_IOSLAVEINTSET - IO Slave Interrupts                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_6                     : 26;
        unsigned IOINTW                     :  1;
        unsigned GENAD                      :  1;
        unsigned FRDERR                     :  1;
        unsigned FUNDFL                     :  1;
        unsigned FOVFL                      :  1;
        unsigned FSIZE                      :  1;
    } B;
} reg_ioslave_ioslaveintset_t;

#define REG_IOSLAVE_IOSLAVEINTSET_ADDR          (REG_IOSLAVE_BASEADDR + 0x0000020CUL)
#define REG_IOSLAVE_IOSLAVEINTSET               (*(volatile reg_ioslave_ioslaveintset_t *) REG_IOSLAVE_IOSLAVEINTSET_ADDR)
#define REG_IOSLAVE_IOSLAVEINTSET_RD()          (REG_IOSLAVE_IOSLAVEINTSET.U32)
#define REG_IOSLAVE_IOSLAVEINTSET_WR(v)         (REG_IOSLAVE_IOSLAVEINTSET.U32 = (v))
#define REG_IOSLAVE_IOSLAVEINTSET_CLR(m)        (REG_IOSLAVE_IOSLAVEINTSET.U32 = ((REG_IOSLAVE_IOSLAVEINTSET.U32) & ~(m)))
#define REG_IOSLAVE_IOSLAVEINTSET_SET(m)        (REG_IOSLAVE_IOSLAVEINTSET.U32 = ((REG_IOSLAVE_IOSLAVEINTSET.U32) | (m)))
#define REG_IOSLAVE_IOSLAVEINTSET_DEF           0x00000000

#define BFP_IOSLAVE_IOSLAVEINTSET_RSVD_6        (6)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTSET_RSVD_6        ((uint32_t)0xffffffc0)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTSET_RSVD_6        (26)                    /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTSET_RSVD_6        (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTSET_RSVD_6(v)     ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTSET_RSVD_6)) & (BFM_IOSLAVE_IOSLAVEINTSET_RSVD_6))
#define BFX_IOSLAVE_IOSLAVEINTSET_RSVD_6(v)     ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTSET_RSVD_6)) >> (BFP_IOSLAVE_IOSLAVEINTSET_RSVD_6))
#define BFW_IOSLAVE_IOSLAVEINTSET_RSVD_6(v)     (REG_IOSLAVE_IOSLAVEINTSET.U32 = ( (REG_IOSLAVE_IOSLAVEINTSET.U32 & ~(BFM_IOSLAVE_IOSLAVEINTSET_RSVD_6)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTSET_RSVD_6)) & (BFM_IOSLAVE_IOSLAVEINTSET_RSVD_6)) ))
#define BFR_IOSLAVE_IOSLAVEINTSET_RSVD_6()      ((REG_IOSLAVE_IOSLAVEINTSET.U32 & (BFM_IOSLAVE_IOSLAVEINTSET_RSVD_6))>>(BFP_IOSLAVE_IOSLAVEINTSET_RSVD_6))
#define BFS_IOSLAVE_IOSLAVEINTSET_RSVD_6()      (REG_IOSLAVE_IOSLAVEINTSET.U32 = (BFM_IOSLAVE_IOSLAVEINTSET_RSVD_6) )

#define BFP_IOSLAVE_IOSLAVEINTSET_IOINTW        (5)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTSET_IOINTW        ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTSET_IOINTW        (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTSET_IOINTW        (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTSET_IOINTW(v)     ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTSET_IOINTW)) & (BFM_IOSLAVE_IOSLAVEINTSET_IOINTW))
#define BFX_IOSLAVE_IOSLAVEINTSET_IOINTW(v)     ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTSET_IOINTW)) >> (BFP_IOSLAVE_IOSLAVEINTSET_IOINTW))
#define BFW_IOSLAVE_IOSLAVEINTSET_IOINTW(v)     (REG_IOSLAVE_IOSLAVEINTSET.U32 = ( (REG_IOSLAVE_IOSLAVEINTSET.U32 & ~(BFM_IOSLAVE_IOSLAVEINTSET_IOINTW)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTSET_IOINTW)) & (BFM_IOSLAVE_IOSLAVEINTSET_IOINTW)) ))
#define BFR_IOSLAVE_IOSLAVEINTSET_IOINTW()      ((REG_IOSLAVE_IOSLAVEINTSET.U32 & (BFM_IOSLAVE_IOSLAVEINTSET_IOINTW))>>(BFP_IOSLAVE_IOSLAVEINTSET_IOINTW))
#define BFS_IOSLAVE_IOSLAVEINTSET_IOINTW()      (REG_IOSLAVE_IOSLAVEINTSET.U32 = (BFM_IOSLAVE_IOSLAVEINTSET_IOINTW) )

#define BFP_IOSLAVE_IOSLAVEINTSET_GENAD         (4)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTSET_GENAD         ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTSET_GENAD         (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTSET_GENAD         (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTSET_GENAD(v)      ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTSET_GENAD)) & (BFM_IOSLAVE_IOSLAVEINTSET_GENAD))
#define BFX_IOSLAVE_IOSLAVEINTSET_GENAD(v)      ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTSET_GENAD)) >> (BFP_IOSLAVE_IOSLAVEINTSET_GENAD))
#define BFW_IOSLAVE_IOSLAVEINTSET_GENAD(v)      (REG_IOSLAVE_IOSLAVEINTSET.U32 = ( (REG_IOSLAVE_IOSLAVEINTSET.U32 & ~(BFM_IOSLAVE_IOSLAVEINTSET_GENAD)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTSET_GENAD)) & (BFM_IOSLAVE_IOSLAVEINTSET_GENAD)) ))
#define BFR_IOSLAVE_IOSLAVEINTSET_GENAD()       ((REG_IOSLAVE_IOSLAVEINTSET.U32 & (BFM_IOSLAVE_IOSLAVEINTSET_GENAD))>>(BFP_IOSLAVE_IOSLAVEINTSET_GENAD))
#define BFS_IOSLAVE_IOSLAVEINTSET_GENAD()       (REG_IOSLAVE_IOSLAVEINTSET.U32 = (BFM_IOSLAVE_IOSLAVEINTSET_GENAD) )

#define BFP_IOSLAVE_IOSLAVEINTSET_FRDERR        (3)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTSET_FRDERR        ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTSET_FRDERR        (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTSET_FRDERR        (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTSET_FRDERR(v)     ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTSET_FRDERR)) & (BFM_IOSLAVE_IOSLAVEINTSET_FRDERR))
#define BFX_IOSLAVE_IOSLAVEINTSET_FRDERR(v)     ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTSET_FRDERR)) >> (BFP_IOSLAVE_IOSLAVEINTSET_FRDERR))
#define BFW_IOSLAVE_IOSLAVEINTSET_FRDERR(v)     (REG_IOSLAVE_IOSLAVEINTSET.U32 = ( (REG_IOSLAVE_IOSLAVEINTSET.U32 & ~(BFM_IOSLAVE_IOSLAVEINTSET_FRDERR)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTSET_FRDERR)) & (BFM_IOSLAVE_IOSLAVEINTSET_FRDERR)) ))
#define BFR_IOSLAVE_IOSLAVEINTSET_FRDERR()      ((REG_IOSLAVE_IOSLAVEINTSET.U32 & (BFM_IOSLAVE_IOSLAVEINTSET_FRDERR))>>(BFP_IOSLAVE_IOSLAVEINTSET_FRDERR))
#define BFS_IOSLAVE_IOSLAVEINTSET_FRDERR()      (REG_IOSLAVE_IOSLAVEINTSET.U32 = (BFM_IOSLAVE_IOSLAVEINTSET_FRDERR) )

#define BFP_IOSLAVE_IOSLAVEINTSET_FUNDFL        (2)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTSET_FUNDFL        ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTSET_FUNDFL        (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTSET_FUNDFL        (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTSET_FUNDFL(v)     ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTSET_FUNDFL)) & (BFM_IOSLAVE_IOSLAVEINTSET_FUNDFL))
#define BFX_IOSLAVE_IOSLAVEINTSET_FUNDFL(v)     ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTSET_FUNDFL)) >> (BFP_IOSLAVE_IOSLAVEINTSET_FUNDFL))
#define BFW_IOSLAVE_IOSLAVEINTSET_FUNDFL(v)     (REG_IOSLAVE_IOSLAVEINTSET.U32 = ( (REG_IOSLAVE_IOSLAVEINTSET.U32 & ~(BFM_IOSLAVE_IOSLAVEINTSET_FUNDFL)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTSET_FUNDFL)) & (BFM_IOSLAVE_IOSLAVEINTSET_FUNDFL)) ))
#define BFR_IOSLAVE_IOSLAVEINTSET_FUNDFL()      ((REG_IOSLAVE_IOSLAVEINTSET.U32 & (BFM_IOSLAVE_IOSLAVEINTSET_FUNDFL))>>(BFP_IOSLAVE_IOSLAVEINTSET_FUNDFL))
#define BFS_IOSLAVE_IOSLAVEINTSET_FUNDFL()      (REG_IOSLAVE_IOSLAVEINTSET.U32 = (BFM_IOSLAVE_IOSLAVEINTSET_FUNDFL) )

#define BFP_IOSLAVE_IOSLAVEINTSET_FOVFL         (1)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTSET_FOVFL         ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTSET_FOVFL         (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTSET_FOVFL         (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTSET_FOVFL(v)      ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTSET_FOVFL)) & (BFM_IOSLAVE_IOSLAVEINTSET_FOVFL))
#define BFX_IOSLAVE_IOSLAVEINTSET_FOVFL(v)      ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTSET_FOVFL)) >> (BFP_IOSLAVE_IOSLAVEINTSET_FOVFL))
#define BFW_IOSLAVE_IOSLAVEINTSET_FOVFL(v)      (REG_IOSLAVE_IOSLAVEINTSET.U32 = ( (REG_IOSLAVE_IOSLAVEINTSET.U32 & ~(BFM_IOSLAVE_IOSLAVEINTSET_FOVFL)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTSET_FOVFL)) & (BFM_IOSLAVE_IOSLAVEINTSET_FOVFL)) ))
#define BFR_IOSLAVE_IOSLAVEINTSET_FOVFL()       ((REG_IOSLAVE_IOSLAVEINTSET.U32 & (BFM_IOSLAVE_IOSLAVEINTSET_FOVFL))>>(BFP_IOSLAVE_IOSLAVEINTSET_FOVFL))
#define BFS_IOSLAVE_IOSLAVEINTSET_FOVFL()       (REG_IOSLAVE_IOSLAVEINTSET.U32 = (BFM_IOSLAVE_IOSLAVEINTSET_FOVFL) )

#define BFP_IOSLAVE_IOSLAVEINTSET_FSIZE         (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_IOSLAVEINTSET_FSIZE         ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_IOSLAVE_IOSLAVEINTSET_FSIZE         (1)                     /* bitfield width */
#define BFD_IOSLAVE_IOSLAVEINTSET_FSIZE         (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_IOSLAVEINTSET_FSIZE(v)      ((((uint32_t) v) << (BFP_IOSLAVE_IOSLAVEINTSET_FSIZE)) & (BFM_IOSLAVE_IOSLAVEINTSET_FSIZE))
#define BFX_IOSLAVE_IOSLAVEINTSET_FSIZE(v)      ((((uint32_t) v) & (BFM_IOSLAVE_IOSLAVEINTSET_FSIZE)) >> (BFP_IOSLAVE_IOSLAVEINTSET_FSIZE))
#define BFW_IOSLAVE_IOSLAVEINTSET_FSIZE(v)      (REG_IOSLAVE_IOSLAVEINTSET.U32 = ( (REG_IOSLAVE_IOSLAVEINTSET.U32 & ~(BFM_IOSLAVE_IOSLAVEINTSET_FSIZE)) | ((((uint32_t) v)<<(BFP_IOSLAVE_IOSLAVEINTSET_FSIZE)) & (BFM_IOSLAVE_IOSLAVEINTSET_FSIZE)) ))
#define BFR_IOSLAVE_IOSLAVEINTSET_FSIZE()       ((REG_IOSLAVE_IOSLAVEINTSET.U32 & (BFM_IOSLAVE_IOSLAVEINTSET_FSIZE))>>(BFP_IOSLAVE_IOSLAVEINTSET_FSIZE))
#define BFS_IOSLAVE_IOSLAVEINTSET_FSIZE()       (REG_IOSLAVE_IOSLAVEINTSET.U32 = (BFM_IOSLAVE_IOSLAVEINTSET_FSIZE) )


// *****************************************************************************
//                                                                             *
//  IOSLAVE_REGACCINTEN - Register Access Interrupts                           *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned REGACC                     : 32;
    } B;
} reg_ioslave_regaccinten_t;

#define REG_IOSLAVE_REGACCINTEN_ADDR            (REG_IOSLAVE_BASEADDR + 0x00000210UL)
#define REG_IOSLAVE_REGACCINTEN                 (*(volatile reg_ioslave_regaccinten_t *) REG_IOSLAVE_REGACCINTEN_ADDR)
#define REG_IOSLAVE_REGACCINTEN_RD()            (REG_IOSLAVE_REGACCINTEN.U32)
#define REG_IOSLAVE_REGACCINTEN_WR(v)           (REG_IOSLAVE_REGACCINTEN.U32 = (v))
#define REG_IOSLAVE_REGACCINTEN_CLR(m)          (REG_IOSLAVE_REGACCINTEN.U32 = ((REG_IOSLAVE_REGACCINTEN.U32) & ~(m)))
#define REG_IOSLAVE_REGACCINTEN_SET(m)          (REG_IOSLAVE_REGACCINTEN.U32 = ((REG_IOSLAVE_REGACCINTEN.U32) | (m)))
#define REG_IOSLAVE_REGACCINTEN_DEF             0x00000000

#define BFP_IOSLAVE_REGACCINTEN_REGACC          (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_REGACCINTEN_REGACC          ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_IOSLAVE_REGACCINTEN_REGACC          (32)                    /* bitfield width */
#define BFD_IOSLAVE_REGACCINTEN_REGACC          (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_REGACCINTEN_REGACC(v)       ((((uint32_t) v) << (BFP_IOSLAVE_REGACCINTEN_REGACC)) & (BFM_IOSLAVE_REGACCINTEN_REGACC))
#define BFX_IOSLAVE_REGACCINTEN_REGACC(v)       ((((uint32_t) v) & (BFM_IOSLAVE_REGACCINTEN_REGACC)) >> (BFP_IOSLAVE_REGACCINTEN_REGACC))
#define BFW_IOSLAVE_REGACCINTEN_REGACC(v)       (REG_IOSLAVE_REGACCINTEN.U32 = ( (((uint32_t) v)<<(BFP_IOSLAVE_REGACCINTEN_REGACC)) & (BFM_IOSLAVE_REGACCINTEN_REGACC)) )
#define BFR_IOSLAVE_REGACCINTEN_REGACC()        ((REG_IOSLAVE_REGACCINTEN.U32 & (BFM_IOSLAVE_REGACCINTEN_REGACC))>>(BFP_IOSLAVE_REGACCINTEN_REGACC))


// *****************************************************************************
//                                                                             *
//  IOSLAVE_REGACCINTSTAT - Register Access Interrupts                         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned REGACC                     : 32;
    } B;
} reg_ioslave_regaccintstat_t;

#define REG_IOSLAVE_REGACCINTSTAT_ADDR          (REG_IOSLAVE_BASEADDR + 0x00000214UL)
#define REG_IOSLAVE_REGACCINTSTAT               (*(volatile reg_ioslave_regaccintstat_t *) REG_IOSLAVE_REGACCINTSTAT_ADDR)
#define REG_IOSLAVE_REGACCINTSTAT_RD()          (REG_IOSLAVE_REGACCINTSTAT.U32)
#define REG_IOSLAVE_REGACCINTSTAT_WR(v)         (REG_IOSLAVE_REGACCINTSTAT.U32 = (v))
#define REG_IOSLAVE_REGACCINTSTAT_CLR(m)        (REG_IOSLAVE_REGACCINTSTAT.U32 = ((REG_IOSLAVE_REGACCINTSTAT.U32) & ~(m)))
#define REG_IOSLAVE_REGACCINTSTAT_SET(m)        (REG_IOSLAVE_REGACCINTSTAT.U32 = ((REG_IOSLAVE_REGACCINTSTAT.U32) | (m)))
#define REG_IOSLAVE_REGACCINTSTAT_DEF           0x00000000

#define BFP_IOSLAVE_REGACCINTSTAT_REGACC        (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_REGACCINTSTAT_REGACC        ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_IOSLAVE_REGACCINTSTAT_REGACC        (32)                    /* bitfield width */
#define BFD_IOSLAVE_REGACCINTSTAT_REGACC        (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_REGACCINTSTAT_REGACC(v)     ((((uint32_t) v) << (BFP_IOSLAVE_REGACCINTSTAT_REGACC)) & (BFM_IOSLAVE_REGACCINTSTAT_REGACC))
#define BFX_IOSLAVE_REGACCINTSTAT_REGACC(v)     ((((uint32_t) v) & (BFM_IOSLAVE_REGACCINTSTAT_REGACC)) >> (BFP_IOSLAVE_REGACCINTSTAT_REGACC))
#define BFW_IOSLAVE_REGACCINTSTAT_REGACC(v)     (REG_IOSLAVE_REGACCINTSTAT.U32 = ( (((uint32_t) v)<<(BFP_IOSLAVE_REGACCINTSTAT_REGACC)) & (BFM_IOSLAVE_REGACCINTSTAT_REGACC)) )
#define BFR_IOSLAVE_REGACCINTSTAT_REGACC()      ((REG_IOSLAVE_REGACCINTSTAT.U32 & (BFM_IOSLAVE_REGACCINTSTAT_REGACC))>>(BFP_IOSLAVE_REGACCINTSTAT_REGACC))


// *****************************************************************************
//                                                                             *
//  IOSLAVE_REGACCINTCLR - Register Access Interrupts                          *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned REGACC                     : 32;
    } B;
} reg_ioslave_regaccintclr_t;

#define REG_IOSLAVE_REGACCINTCLR_ADDR           (REG_IOSLAVE_BASEADDR + 0x00000218UL)
#define REG_IOSLAVE_REGACCINTCLR                (*(volatile reg_ioslave_regaccintclr_t *) REG_IOSLAVE_REGACCINTCLR_ADDR)
#define REG_IOSLAVE_REGACCINTCLR_RD()           (REG_IOSLAVE_REGACCINTCLR.U32)
#define REG_IOSLAVE_REGACCINTCLR_WR(v)          (REG_IOSLAVE_REGACCINTCLR.U32 = (v))
#define REG_IOSLAVE_REGACCINTCLR_CLR(m)         (REG_IOSLAVE_REGACCINTCLR.U32 = ((REG_IOSLAVE_REGACCINTCLR.U32) & ~(m)))
#define REG_IOSLAVE_REGACCINTCLR_SET(m)         (REG_IOSLAVE_REGACCINTCLR.U32 = ((REG_IOSLAVE_REGACCINTCLR.U32) | (m)))
#define REG_IOSLAVE_REGACCINTCLR_DEF            0x00000000

#define BFP_IOSLAVE_REGACCINTCLR_REGACC         (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_REGACCINTCLR_REGACC         ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_IOSLAVE_REGACCINTCLR_REGACC         (32)                    /* bitfield width */
#define BFD_IOSLAVE_REGACCINTCLR_REGACC         (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_REGACCINTCLR_REGACC(v)      ((((uint32_t) v) << (BFP_IOSLAVE_REGACCINTCLR_REGACC)) & (BFM_IOSLAVE_REGACCINTCLR_REGACC))
#define BFX_IOSLAVE_REGACCINTCLR_REGACC(v)      ((((uint32_t) v) & (BFM_IOSLAVE_REGACCINTCLR_REGACC)) >> (BFP_IOSLAVE_REGACCINTCLR_REGACC))
#define BFW_IOSLAVE_REGACCINTCLR_REGACC(v)      (REG_IOSLAVE_REGACCINTCLR.U32 = ( (((uint32_t) v)<<(BFP_IOSLAVE_REGACCINTCLR_REGACC)) & (BFM_IOSLAVE_REGACCINTCLR_REGACC)) )
#define BFR_IOSLAVE_REGACCINTCLR_REGACC()       ((REG_IOSLAVE_REGACCINTCLR.U32 & (BFM_IOSLAVE_REGACCINTCLR_REGACC))>>(BFP_IOSLAVE_REGACCINTCLR_REGACC))


// *****************************************************************************
//                                                                             *
//  IOSLAVE_REGACCINTSET - Register Access Interrupts                          *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned REGACC                     : 32;
    } B;
} reg_ioslave_regaccintset_t;

#define REG_IOSLAVE_REGACCINTSET_ADDR           (REG_IOSLAVE_BASEADDR + 0x0000021CUL)
#define REG_IOSLAVE_REGACCINTSET                (*(volatile reg_ioslave_regaccintset_t *) REG_IOSLAVE_REGACCINTSET_ADDR)
#define REG_IOSLAVE_REGACCINTSET_RD()           (REG_IOSLAVE_REGACCINTSET.U32)
#define REG_IOSLAVE_REGACCINTSET_WR(v)          (REG_IOSLAVE_REGACCINTSET.U32 = (v))
#define REG_IOSLAVE_REGACCINTSET_CLR(m)         (REG_IOSLAVE_REGACCINTSET.U32 = ((REG_IOSLAVE_REGACCINTSET.U32) & ~(m)))
#define REG_IOSLAVE_REGACCINTSET_SET(m)         (REG_IOSLAVE_REGACCINTSET.U32 = ((REG_IOSLAVE_REGACCINTSET.U32) | (m)))
#define REG_IOSLAVE_REGACCINTSET_DEF            0x00000000

#define BFP_IOSLAVE_REGACCINTSET_REGACC         (0)                     /* bitfield lsb */
#define BFM_IOSLAVE_REGACCINTSET_REGACC         ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_IOSLAVE_REGACCINTSET_REGACC         (32)                    /* bitfield width */
#define BFD_IOSLAVE_REGACCINTSET_REGACC         (0x0)                   /* bitfield default value */
#define BFV_IOSLAVE_REGACCINTSET_REGACC(v)      ((((uint32_t) v) << (BFP_IOSLAVE_REGACCINTSET_REGACC)) & (BFM_IOSLAVE_REGACCINTSET_REGACC))
#define BFX_IOSLAVE_REGACCINTSET_REGACC(v)      ((((uint32_t) v) & (BFM_IOSLAVE_REGACCINTSET_REGACC)) >> (BFP_IOSLAVE_REGACCINTSET_REGACC))
#define BFW_IOSLAVE_REGACCINTSET_REGACC(v)      (REG_IOSLAVE_REGACCINTSET.U32 = ( (((uint32_t) v)<<(BFP_IOSLAVE_REGACCINTSET_REGACC)) & (BFM_IOSLAVE_REGACCINTSET_REGACC)) )
#define BFR_IOSLAVE_REGACCINTSET_REGACC()       ((REG_IOSLAVE_REGACCINTSET.U32 & (BFM_IOSLAVE_REGACCINTSET_REGACC))>>(BFP_IOSLAVE_REGACCINTSET_REGACC))


#endif  // __IOSLAVE_H

