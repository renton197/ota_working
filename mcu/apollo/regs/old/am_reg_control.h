/*******************************************************************************
*                                                                              *
*   Copyright (c) 2013-2014 Ambiq Micro                                        *
*                                                                              *
********************************************************************************
*                                                                              *
*   File:       control.h                                                 *
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


#ifndef __CONTROL_H
#define __CONTROL_H

#include "../am_mcu_apollo.h"

// *****************************************************************************
//                                                                             *
//  CONTROL_CHIPPN - Chip Information Register 1                               *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned PARTNUM                    : 32;
    } B;
} reg_control_chippn_t;

#define REG_CONTROL_CHIPPN_ADDR                 (REG_CONTROL_BASEADDR + 0x00000000UL)
#define REG_CONTROL_CHIPPN                      (*(volatile reg_control_chippn_t *) REG_CONTROL_CHIPPN_ADDR)
#define REG_CONTROL_CHIPPN_RD()                 (REG_CONTROL_CHIPPN.U32)
#define REG_CONTROL_CHIPPN_WR(v)                (REG_CONTROL_CHIPPN.U32 = (v))
#define REG_CONTROL_CHIPPN_CLR(m)               (REG_CONTROL_CHIPPN.U32 = ((REG_CONTROL_CHIPPN.U32) & ~(m)))
#define REG_CONTROL_CHIPPN_SET(m)               (REG_CONTROL_CHIPPN.U32 = ((REG_CONTROL_CHIPPN.U32) | (m)))
#define REG_CONTROL_CHIPPN_DEF                  0x00000000

#define BFP_CONTROL_CHIPPN_PARTNUM              (0)                     /* bitfield lsb */
#define BFM_CONTROL_CHIPPN_PARTNUM              ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_CONTROL_CHIPPN_PARTNUM              (32)                    /* bitfield width */
#define BFD_CONTROL_CHIPPN_PARTNUM              (0x0)                   /* bitfield default value */
#define BFV_CONTROL_CHIPPN_PARTNUM(v)           ((((uint32_t) v) << (BFP_CONTROL_CHIPPN_PARTNUM)) & (BFM_CONTROL_CHIPPN_PARTNUM))
#define BFX_CONTROL_CHIPPN_PARTNUM(v)           ((((uint32_t) v) & (BFM_CONTROL_CHIPPN_PARTNUM)) >> (BFP_CONTROL_CHIPPN_PARTNUM))
#define BFW_CONTROL_CHIPPN_PARTNUM(v)           (REG_CONTROL_CHIPPN.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_CHIPPN_PARTNUM)) & (BFM_CONTROL_CHIPPN_PARTNUM)) )
#define BFR_CONTROL_CHIPPN_PARTNUM()            ((REG_CONTROL_CHIPPN.U32 & (BFM_CONTROL_CHIPPN_PARTNUM))>>(BFP_CONTROL_CHIPPN_PARTNUM))


// *****************************************************************************
//                                                                             *
//  CONTROL_CHIPID0 - Unique Chip ID 0                                         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CHIPID0                    : 32;
    } B;
} reg_control_chipid0_t;

#define REG_CONTROL_CHIPID0_ADDR                (REG_CONTROL_BASEADDR + 0x00000004UL)
#define REG_CONTROL_CHIPID0                     (*(volatile reg_control_chipid0_t *) REG_CONTROL_CHIPID0_ADDR)
#define REG_CONTROL_CHIPID0_RD()                (REG_CONTROL_CHIPID0.U32)
#define REG_CONTROL_CHIPID0_WR(v)               (REG_CONTROL_CHIPID0.U32 = (v))
#define REG_CONTROL_CHIPID0_CLR(m)              (REG_CONTROL_CHIPID0.U32 = ((REG_CONTROL_CHIPID0.U32) & ~(m)))
#define REG_CONTROL_CHIPID0_SET(m)              (REG_CONTROL_CHIPID0.U32 = ((REG_CONTROL_CHIPID0.U32) | (m)))
#define REG_CONTROL_CHIPID0_DEF                 0x00000000

#define BFP_CONTROL_CHIPID0_CHIPID0             (0)                     /* bitfield lsb */
#define BFM_CONTROL_CHIPID0_CHIPID0             ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_CONTROL_CHIPID0_CHIPID0             (32)                    /* bitfield width */
#define BFD_CONTROL_CHIPID0_CHIPID0             (0x0)                   /* bitfield default value */
#define BFV_CONTROL_CHIPID0_CHIPID0(v)          ((((uint32_t) v) << (BFP_CONTROL_CHIPID0_CHIPID0)) & (BFM_CONTROL_CHIPID0_CHIPID0))
#define BFX_CONTROL_CHIPID0_CHIPID0(v)          ((((uint32_t) v) & (BFM_CONTROL_CHIPID0_CHIPID0)) >> (BFP_CONTROL_CHIPID0_CHIPID0))
#define BFW_CONTROL_CHIPID0_CHIPID0(v)          (REG_CONTROL_CHIPID0.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_CHIPID0_CHIPID0)) & (BFM_CONTROL_CHIPID0_CHIPID0)) )
#define BFR_CONTROL_CHIPID0_CHIPID0()           ((REG_CONTROL_CHIPID0.U32 & (BFM_CONTROL_CHIPID0_CHIPID0))>>(BFP_CONTROL_CHIPID0_CHIPID0))


// *****************************************************************************
//                                                                             *
//  CONTROL_CHIPID1 - Unique Chip ID 1                                         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CHIPID1                    : 32;
    } B;
} reg_control_chipid1_t;

#define REG_CONTROL_CHIPID1_ADDR                (REG_CONTROL_BASEADDR + 0x00000008UL)
#define REG_CONTROL_CHIPID1                     (*(volatile reg_control_chipid1_t *) REG_CONTROL_CHIPID1_ADDR)
#define REG_CONTROL_CHIPID1_RD()                (REG_CONTROL_CHIPID1.U32)
#define REG_CONTROL_CHIPID1_WR(v)               (REG_CONTROL_CHIPID1.U32 = (v))
#define REG_CONTROL_CHIPID1_CLR(m)              (REG_CONTROL_CHIPID1.U32 = ((REG_CONTROL_CHIPID1.U32) & ~(m)))
#define REG_CONTROL_CHIPID1_SET(m)              (REG_CONTROL_CHIPID1.U32 = ((REG_CONTROL_CHIPID1.U32) | (m)))
#define REG_CONTROL_CHIPID1_DEF                 0x00000000

#define BFP_CONTROL_CHIPID1_CHIPID1             (0)                     /* bitfield lsb */
#define BFM_CONTROL_CHIPID1_CHIPID1             ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_CONTROL_CHIPID1_CHIPID1             (32)                    /* bitfield width */
#define BFD_CONTROL_CHIPID1_CHIPID1             (0x0)                   /* bitfield default value */
#define BFV_CONTROL_CHIPID1_CHIPID1(v)          ((((uint32_t) v) << (BFP_CONTROL_CHIPID1_CHIPID1)) & (BFM_CONTROL_CHIPID1_CHIPID1))
#define BFX_CONTROL_CHIPID1_CHIPID1(v)          ((((uint32_t) v) & (BFM_CONTROL_CHIPID1_CHIPID1)) >> (BFP_CONTROL_CHIPID1_CHIPID1))
#define BFW_CONTROL_CHIPID1_CHIPID1(v)          (REG_CONTROL_CHIPID1.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_CHIPID1_CHIPID1)) & (BFM_CONTROL_CHIPID1_CHIPID1)) )
#define BFR_CONTROL_CHIPID1_CHIPID1()           ((REG_CONTROL_CHIPID1.U32 & (BFM_CONTROL_CHIPID1_CHIPID1))>>(BFP_CONTROL_CHIPID1_CHIPID1))


// *****************************************************************************
//                                                                             *
//  CONTROL_CHIPREV - Chip Revision                                            *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned CHIPREV                    :  8;
    } B;
} reg_control_chiprev_t;

#define REG_CONTROL_CHIPREV_ADDR                (REG_CONTROL_BASEADDR + 0x0000000CUL)
#define REG_CONTROL_CHIPREV                     (*(volatile reg_control_chiprev_t *) REG_CONTROL_CHIPREV_ADDR)
#define REG_CONTROL_CHIPREV_RD()                (REG_CONTROL_CHIPREV.U32)
#define REG_CONTROL_CHIPREV_WR(v)               (REG_CONTROL_CHIPREV.U32 = (v))
#define REG_CONTROL_CHIPREV_CLR(m)              (REG_CONTROL_CHIPREV.U32 = ((REG_CONTROL_CHIPREV.U32) & ~(m)))
#define REG_CONTROL_CHIPREV_SET(m)              (REG_CONTROL_CHIPREV.U32 = ((REG_CONTROL_CHIPREV.U32) | (m)))
#define REG_CONTROL_CHIPREV_DEF                 0x00000000

#define BFP_CONTROL_CHIPREV_RSVD_8              (8)                     /* bitfield lsb */
#define BFM_CONTROL_CHIPREV_RSVD_8              ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_CONTROL_CHIPREV_RSVD_8              (24)                    /* bitfield width */
#define BFD_CONTROL_CHIPREV_RSVD_8              (0x0)                   /* bitfield default value */
#define BFV_CONTROL_CHIPREV_RSVD_8(v)           ((((uint32_t) v) << (BFP_CONTROL_CHIPREV_RSVD_8)) & (BFM_CONTROL_CHIPREV_RSVD_8))
#define BFX_CONTROL_CHIPREV_RSVD_8(v)           ((((uint32_t) v) & (BFM_CONTROL_CHIPREV_RSVD_8)) >> (BFP_CONTROL_CHIPREV_RSVD_8))
#define BFW_CONTROL_CHIPREV_RSVD_8(v)           (REG_CONTROL_CHIPREV.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_CHIPREV_RSVD_8)) & (BFM_CONTROL_CHIPREV_RSVD_8)) )
#define BFR_CONTROL_CHIPREV_RSVD_8()            ((REG_CONTROL_CHIPREV.U32 & (BFM_CONTROL_CHIPREV_RSVD_8))>>(BFP_CONTROL_CHIPREV_RSVD_8))

#define BFP_CONTROL_CHIPREV_CHIPREV             (0)                     /* bitfield lsb */
#define BFM_CONTROL_CHIPREV_CHIPREV             ((uint32_t)0x000000ff)  /* bitfield mask */
#define BFN_CONTROL_CHIPREV_CHIPREV             (8)                     /* bitfield width */
#define BFD_CONTROL_CHIPREV_CHIPREV             (0x0)                   /* bitfield default value */
#define BFV_CONTROL_CHIPREV_CHIPREV(v)          ((((uint32_t) v) << (BFP_CONTROL_CHIPREV_CHIPREV)) & (BFM_CONTROL_CHIPREV_CHIPREV))
#define BFX_CONTROL_CHIPREV_CHIPREV(v)          ((((uint32_t) v) & (BFM_CONTROL_CHIPREV_CHIPREV)) >> (BFP_CONTROL_CHIPREV_CHIPREV))
#define BFW_CONTROL_CHIPREV_CHIPREV(v)          (REG_CONTROL_CHIPREV.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_CHIPREV_CHIPREV)) & (BFM_CONTROL_CHIPREV_CHIPREV)) )
#define BFR_CONTROL_CHIPREV_CHIPREV()           ((REG_CONTROL_CHIPREV.U32 & (BFM_CONTROL_CHIPREV_CHIPREV))>>(BFP_CONTROL_CHIPREV_CHIPREV))


// *****************************************************************************
//                                                                             *
//  CONTROL_SUPPLYSRC - Memory and Core Voltage Supply Source Select Register  *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_2                     : 30;
        unsigned COREBUCKEN                 :  1;
        unsigned MEMBUCKEN                  :  1;
    } B;
} reg_control_supplysrc_t;

#define REG_CONTROL_SUPPLYSRC_ADDR              (REG_CONTROL_BASEADDR + 0x00000010UL)
#define REG_CONTROL_SUPPLYSRC                   (*(volatile reg_control_supplysrc_t *) REG_CONTROL_SUPPLYSRC_ADDR)
#define REG_CONTROL_SUPPLYSRC_RD()              (REG_CONTROL_SUPPLYSRC.U32)
#define REG_CONTROL_SUPPLYSRC_WR(v)             (REG_CONTROL_SUPPLYSRC.U32 = (v))
#define REG_CONTROL_SUPPLYSRC_CLR(m)            (REG_CONTROL_SUPPLYSRC.U32 = ((REG_CONTROL_SUPPLYSRC.U32) & ~(m)))
#define REG_CONTROL_SUPPLYSRC_SET(m)            (REG_CONTROL_SUPPLYSRC.U32 = ((REG_CONTROL_SUPPLYSRC.U32) | (m)))
#define REG_CONTROL_SUPPLYSRC_DEF               0x00000000

#define BFP_CONTROL_SUPPLYSRC_RSVD_2            (2)                     /* bitfield lsb */
#define BFM_CONTROL_SUPPLYSRC_RSVD_2            ((uint32_t)0xfffffffc)  /* bitfield mask */
#define BFN_CONTROL_SUPPLYSRC_RSVD_2            (30)                    /* bitfield width */
#define BFD_CONTROL_SUPPLYSRC_RSVD_2            (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SUPPLYSRC_RSVD_2(v)         ((((uint32_t) v) << (BFP_CONTROL_SUPPLYSRC_RSVD_2)) & (BFM_CONTROL_SUPPLYSRC_RSVD_2))
#define BFX_CONTROL_SUPPLYSRC_RSVD_2(v)         ((((uint32_t) v) & (BFM_CONTROL_SUPPLYSRC_RSVD_2)) >> (BFP_CONTROL_SUPPLYSRC_RSVD_2))
#define BFW_CONTROL_SUPPLYSRC_RSVD_2(v)         (REG_CONTROL_SUPPLYSRC.U32 = ( (REG_CONTROL_SUPPLYSRC.U32 & ~(BFM_CONTROL_SUPPLYSRC_RSVD_2)) | ((((uint32_t) v)<<(BFP_CONTROL_SUPPLYSRC_RSVD_2)) & (BFM_CONTROL_SUPPLYSRC_RSVD_2)) ))
#define BFR_CONTROL_SUPPLYSRC_RSVD_2()          ((REG_CONTROL_SUPPLYSRC.U32 & (BFM_CONTROL_SUPPLYSRC_RSVD_2))>>(BFP_CONTROL_SUPPLYSRC_RSVD_2))

#define BFP_CONTROL_SUPPLYSRC_COREBUCKEN        (1)                     /* bitfield lsb */
#define BFM_CONTROL_SUPPLYSRC_COREBUCKEN        ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CONTROL_SUPPLYSRC_COREBUCKEN        (1)                     /* bitfield width */
#define BFD_CONTROL_SUPPLYSRC_COREBUCKEN        (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SUPPLYSRC_COREBUCKEN(v)     ((((uint32_t) v) << (BFP_CONTROL_SUPPLYSRC_COREBUCKEN)) & (BFM_CONTROL_SUPPLYSRC_COREBUCKEN))
#define BFX_CONTROL_SUPPLYSRC_COREBUCKEN(v)     ((((uint32_t) v) & (BFM_CONTROL_SUPPLYSRC_COREBUCKEN)) >> (BFP_CONTROL_SUPPLYSRC_COREBUCKEN))
#define BFW_CONTROL_SUPPLYSRC_COREBUCKEN(v)     (REG_CONTROL_SUPPLYSRC.U32 = ( (REG_CONTROL_SUPPLYSRC.U32 & ~(BFM_CONTROL_SUPPLYSRC_COREBUCKEN)) | ((((uint32_t) v)<<(BFP_CONTROL_SUPPLYSRC_COREBUCKEN)) & (BFM_CONTROL_SUPPLYSRC_COREBUCKEN)) ))
#define BFR_CONTROL_SUPPLYSRC_COREBUCKEN()      ((REG_CONTROL_SUPPLYSRC.U32 & (BFM_CONTROL_SUPPLYSRC_COREBUCKEN))>>(BFP_CONTROL_SUPPLYSRC_COREBUCKEN))

#define BFP_CONTROL_SUPPLYSRC_MEMBUCKEN         (0)                     /* bitfield lsb */
#define BFM_CONTROL_SUPPLYSRC_MEMBUCKEN         ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_SUPPLYSRC_MEMBUCKEN         (1)                     /* bitfield width */
#define BFD_CONTROL_SUPPLYSRC_MEMBUCKEN         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SUPPLYSRC_MEMBUCKEN(v)      ((((uint32_t) v) << (BFP_CONTROL_SUPPLYSRC_MEMBUCKEN)) & (BFM_CONTROL_SUPPLYSRC_MEMBUCKEN))
#define BFX_CONTROL_SUPPLYSRC_MEMBUCKEN(v)      ((((uint32_t) v) & (BFM_CONTROL_SUPPLYSRC_MEMBUCKEN)) >> (BFP_CONTROL_SUPPLYSRC_MEMBUCKEN))
#define BFW_CONTROL_SUPPLYSRC_MEMBUCKEN(v)      (REG_CONTROL_SUPPLYSRC.U32 = ( (REG_CONTROL_SUPPLYSRC.U32 & ~(BFM_CONTROL_SUPPLYSRC_MEMBUCKEN)) | ((((uint32_t) v)<<(BFP_CONTROL_SUPPLYSRC_MEMBUCKEN)) & (BFM_CONTROL_SUPPLYSRC_MEMBUCKEN)) ))
#define BFR_CONTROL_SUPPLYSRC_MEMBUCKEN()       ((REG_CONTROL_SUPPLYSRC.U32 & (BFM_CONTROL_SUPPLYSRC_MEMBUCKEN))>>(BFP_CONTROL_SUPPLYSRC_MEMBUCKEN))


// *****************************************************************************
//                                                                             *
//  CONTROL_SUPPLYSTATUS - Memory and Core Voltage Supply Source Status Register*
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_2                     : 30;
        unsigned COREBUCKON                 :  1;
        unsigned MEMBUCKON                  :  1;
    } B;
} reg_control_supplystatus_t;

#define REG_CONTROL_SUPPLYSTATUS_ADDR           (REG_CONTROL_BASEADDR + 0x00000014UL)
#define REG_CONTROL_SUPPLYSTATUS                (*(volatile reg_control_supplystatus_t *) REG_CONTROL_SUPPLYSTATUS_ADDR)
#define REG_CONTROL_SUPPLYSTATUS_RD()           (REG_CONTROL_SUPPLYSTATUS.U32)
#define REG_CONTROL_SUPPLYSTATUS_WR(v)          (REG_CONTROL_SUPPLYSTATUS.U32 = (v))
#define REG_CONTROL_SUPPLYSTATUS_CLR(m)         (REG_CONTROL_SUPPLYSTATUS.U32 = ((REG_CONTROL_SUPPLYSTATUS.U32) & ~(m)))
#define REG_CONTROL_SUPPLYSTATUS_SET(m)         (REG_CONTROL_SUPPLYSTATUS.U32 = ((REG_CONTROL_SUPPLYSTATUS.U32) | (m)))
#define REG_CONTROL_SUPPLYSTATUS_DEF            0x00000000

#define BFP_CONTROL_SUPPLYSTATUS_RSVD_2         (2)                     /* bitfield lsb */
#define BFM_CONTROL_SUPPLYSTATUS_RSVD_2         ((uint32_t)0xfffffffc)  /* bitfield mask */
#define BFN_CONTROL_SUPPLYSTATUS_RSVD_2         (30)                    /* bitfield width */
#define BFD_CONTROL_SUPPLYSTATUS_RSVD_2         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SUPPLYSTATUS_RSVD_2(v)      ((((uint32_t) v) << (BFP_CONTROL_SUPPLYSTATUS_RSVD_2)) & (BFM_CONTROL_SUPPLYSTATUS_RSVD_2))
#define BFX_CONTROL_SUPPLYSTATUS_RSVD_2(v)      ((((uint32_t) v) & (BFM_CONTROL_SUPPLYSTATUS_RSVD_2)) >> (BFP_CONTROL_SUPPLYSTATUS_RSVD_2))
#define BFW_CONTROL_SUPPLYSTATUS_RSVD_2(v)      (REG_CONTROL_SUPPLYSTATUS.U32 = ( (REG_CONTROL_SUPPLYSTATUS.U32 & ~(BFM_CONTROL_SUPPLYSTATUS_RSVD_2)) | ((((uint32_t) v)<<(BFP_CONTROL_SUPPLYSTATUS_RSVD_2)) & (BFM_CONTROL_SUPPLYSTATUS_RSVD_2)) ))
#define BFR_CONTROL_SUPPLYSTATUS_RSVD_2()       ((REG_CONTROL_SUPPLYSTATUS.U32 & (BFM_CONTROL_SUPPLYSTATUS_RSVD_2))>>(BFP_CONTROL_SUPPLYSTATUS_RSVD_2))

#define BFP_CONTROL_SUPPLYSTATUS_COREBUCKON     (1)                     /* bitfield lsb */
#define BFM_CONTROL_SUPPLYSTATUS_COREBUCKON     ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CONTROL_SUPPLYSTATUS_COREBUCKON     (1)                     /* bitfield width */
#define BFD_CONTROL_SUPPLYSTATUS_COREBUCKON     (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SUPPLYSTATUS_COREBUCKON(v)  ((((uint32_t) v) << (BFP_CONTROL_SUPPLYSTATUS_COREBUCKON)) & (BFM_CONTROL_SUPPLYSTATUS_COREBUCKON))
#define BFX_CONTROL_SUPPLYSTATUS_COREBUCKON(v)  ((((uint32_t) v) & (BFM_CONTROL_SUPPLYSTATUS_COREBUCKON)) >> (BFP_CONTROL_SUPPLYSTATUS_COREBUCKON))
#define BFW_CONTROL_SUPPLYSTATUS_COREBUCKON(v)  (REG_CONTROL_SUPPLYSTATUS.U32 = ( (REG_CONTROL_SUPPLYSTATUS.U32 & ~(BFM_CONTROL_SUPPLYSTATUS_COREBUCKON)) | ((((uint32_t) v)<<(BFP_CONTROL_SUPPLYSTATUS_COREBUCKON)) & (BFM_CONTROL_SUPPLYSTATUS_COREBUCKON)) ))
#define BFR_CONTROL_SUPPLYSTATUS_COREBUCKON()   ((REG_CONTROL_SUPPLYSTATUS.U32 & (BFM_CONTROL_SUPPLYSTATUS_COREBUCKON))>>(BFP_CONTROL_SUPPLYSTATUS_COREBUCKON))

#define BFP_CONTROL_SUPPLYSTATUS_MEMBUCKON      (0)                     /* bitfield lsb */
#define BFM_CONTROL_SUPPLYSTATUS_MEMBUCKON      ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_SUPPLYSTATUS_MEMBUCKON      (1)                     /* bitfield width */
#define BFD_CONTROL_SUPPLYSTATUS_MEMBUCKON      (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SUPPLYSTATUS_MEMBUCKON(v)   ((((uint32_t) v) << (BFP_CONTROL_SUPPLYSTATUS_MEMBUCKON)) & (BFM_CONTROL_SUPPLYSTATUS_MEMBUCKON))
#define BFX_CONTROL_SUPPLYSTATUS_MEMBUCKON(v)   ((((uint32_t) v) & (BFM_CONTROL_SUPPLYSTATUS_MEMBUCKON)) >> (BFP_CONTROL_SUPPLYSTATUS_MEMBUCKON))
#define BFW_CONTROL_SUPPLYSTATUS_MEMBUCKON(v)   (REG_CONTROL_SUPPLYSTATUS.U32 = ( (REG_CONTROL_SUPPLYSTATUS.U32 & ~(BFM_CONTROL_SUPPLYSTATUS_MEMBUCKON)) | ((((uint32_t) v)<<(BFP_CONTROL_SUPPLYSTATUS_MEMBUCKON)) & (BFM_CONTROL_SUPPLYSTATUS_MEMBUCKON)) ))
#define BFR_CONTROL_SUPPLYSTATUS_MEMBUCKON()    ((REG_CONTROL_SUPPLYSTATUS.U32 & (BFM_CONTROL_SUPPLYSTATUS_MEMBUCKON))>>(BFP_CONTROL_SUPPLYSTATUS_MEMBUCKON))


// *****************************************************************************
//                                                                             *
//  CONTROL_CCRG - Calibrated Current Reference Generator Control              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_9                     : 23;
        unsigned CCRGTRIM                   :  8;
        unsigned CCRGPWD                    :  1;
    } B;
} reg_control_ccrg_t;

#define REG_CONTROL_CCRG_ADDR                   (REG_CONTROL_BASEADDR + 0x00000020UL)
#define REG_CONTROL_CCRG                        (*(volatile reg_control_ccrg_t *) REG_CONTROL_CCRG_ADDR)
#define REG_CONTROL_CCRG_RD()                   (REG_CONTROL_CCRG.U32)
#define REG_CONTROL_CCRG_WR(v)                  (REG_CONTROL_CCRG.U32 = (v))
#define REG_CONTROL_CCRG_CLR(m)                 (REG_CONTROL_CCRG.U32 = ((REG_CONTROL_CCRG.U32) & ~(m)))
#define REG_CONTROL_CCRG_SET(m)                 (REG_CONTROL_CCRG.U32 = ((REG_CONTROL_CCRG.U32) | (m)))
#define REG_CONTROL_CCRG_DEF                    0x00000000

#define BFP_CONTROL_CCRG_RSVD_9                 (9)                     /* bitfield lsb */
#define BFM_CONTROL_CCRG_RSVD_9                 ((uint32_t)0xfffffe00)  /* bitfield mask */
#define BFN_CONTROL_CCRG_RSVD_9                 (23)                    /* bitfield width */
#define BFD_CONTROL_CCRG_RSVD_9                 (0x0)                   /* bitfield default value */
#define BFV_CONTROL_CCRG_RSVD_9(v)              ((((uint32_t) v) << (BFP_CONTROL_CCRG_RSVD_9)) & (BFM_CONTROL_CCRG_RSVD_9))
#define BFX_CONTROL_CCRG_RSVD_9(v)              ((((uint32_t) v) & (BFM_CONTROL_CCRG_RSVD_9)) >> (BFP_CONTROL_CCRG_RSVD_9))
#define BFW_CONTROL_CCRG_RSVD_9(v)              (REG_CONTROL_CCRG.U32 = ( (REG_CONTROL_CCRG.U32 & ~(BFM_CONTROL_CCRG_RSVD_9)) | ((((uint32_t) v)<<(BFP_CONTROL_CCRG_RSVD_9)) & (BFM_CONTROL_CCRG_RSVD_9)) ))
#define BFR_CONTROL_CCRG_RSVD_9()               ((REG_CONTROL_CCRG.U32 & (BFM_CONTROL_CCRG_RSVD_9))>>(BFP_CONTROL_CCRG_RSVD_9))

#define BFP_CONTROL_CCRG_CCRGTRIM               (1)                     /* bitfield lsb */
#define BFM_CONTROL_CCRG_CCRGTRIM               ((uint32_t)0x000001fe)  /* bitfield mask */
#define BFN_CONTROL_CCRG_CCRGTRIM               (8)                     /* bitfield width */
#define BFD_CONTROL_CCRG_CCRGTRIM               (0x0)                   /* bitfield default value */
#define BFV_CONTROL_CCRG_CCRGTRIM(v)            ((((uint32_t) v) << (BFP_CONTROL_CCRG_CCRGTRIM)) & (BFM_CONTROL_CCRG_CCRGTRIM))
#define BFX_CONTROL_CCRG_CCRGTRIM(v)            ((((uint32_t) v) & (BFM_CONTROL_CCRG_CCRGTRIM)) >> (BFP_CONTROL_CCRG_CCRGTRIM))
#define BFW_CONTROL_CCRG_CCRGTRIM(v)            (REG_CONTROL_CCRG.U32 = ( (REG_CONTROL_CCRG.U32 & ~(BFM_CONTROL_CCRG_CCRGTRIM)) | ((((uint32_t) v)<<(BFP_CONTROL_CCRG_CCRGTRIM)) & (BFM_CONTROL_CCRG_CCRGTRIM)) ))
#define BFR_CONTROL_CCRG_CCRGTRIM()             ((REG_CONTROL_CCRG.U32 & (BFM_CONTROL_CCRG_CCRGTRIM))>>(BFP_CONTROL_CCRG_CCRGTRIM))

#define BFP_CONTROL_CCRG_CCRGPWD                (0)                     /* bitfield lsb */
#define BFM_CONTROL_CCRG_CCRGPWD                ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_CCRG_CCRGPWD                (1)                     /* bitfield width */
#define BFD_CONTROL_CCRG_CCRGPWD                (0x0)                   /* bitfield default value */
#define BFV_CONTROL_CCRG_CCRGPWD(v)             ((((uint32_t) v) << (BFP_CONTROL_CCRG_CCRGPWD)) & (BFM_CONTROL_CCRG_CCRGPWD))
#define BFX_CONTROL_CCRG_CCRGPWD(v)             ((((uint32_t) v) & (BFM_CONTROL_CCRG_CCRGPWD)) >> (BFP_CONTROL_CCRG_CCRGPWD))
#define BFW_CONTROL_CCRG_CCRGPWD(v)             (REG_CONTROL_CCRG.U32 = ( (REG_CONTROL_CCRG.U32 & ~(BFM_CONTROL_CCRG_CCRGPWD)) | ((((uint32_t) v)<<(BFP_CONTROL_CCRG_CCRGPWD)) & (BFM_CONTROL_CCRG_CCRGPWD)) ))
#define BFR_CONTROL_CCRG_CCRGPWD()              ((REG_CONTROL_CCRG.U32 & (BFM_CONTROL_CCRG_CCRGPWD))>>(BFP_CONTROL_CCRG_CCRGPWD))


// *****************************************************************************
//                                                                             *
//  CONTROL_VREFGEN - Voltage Reference Generator Control                      *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_13                    : 19;
        unsigned PWDCVREF                   :  1;
        unsigned CVREFHADJ                  :  5;
        unsigned CVREFLADJ                  :  3;
        unsigned CVREFBTRIM                 :  4;
    } B;
} reg_control_vrefgen_t;

#define REG_CONTROL_VREFGEN_ADDR                (REG_CONTROL_BASEADDR + 0x00000040UL)
#define REG_CONTROL_VREFGEN                     (*(volatile reg_control_vrefgen_t *) REG_CONTROL_VREFGEN_ADDR)
#define REG_CONTROL_VREFGEN_RD()                (REG_CONTROL_VREFGEN.U32)
#define REG_CONTROL_VREFGEN_WR(v)               (REG_CONTROL_VREFGEN.U32 = (v))
#define REG_CONTROL_VREFGEN_CLR(m)              (REG_CONTROL_VREFGEN.U32 = ((REG_CONTROL_VREFGEN.U32) & ~(m)))
#define REG_CONTROL_VREFGEN_SET(m)              (REG_CONTROL_VREFGEN.U32 = ((REG_CONTROL_VREFGEN.U32) | (m)))
#define REG_CONTROL_VREFGEN_DEF                 0x00000000

#define BFP_CONTROL_VREFGEN_RSVD_13             (13)                    /* bitfield lsb */
#define BFM_CONTROL_VREFGEN_RSVD_13             ((uint32_t)0xffffe000)  /* bitfield mask */
#define BFN_CONTROL_VREFGEN_RSVD_13             (19)                    /* bitfield width */
#define BFD_CONTROL_VREFGEN_RSVD_13             (0x0)                   /* bitfield default value */
#define BFV_CONTROL_VREFGEN_RSVD_13(v)          ((((uint32_t) v) << (BFP_CONTROL_VREFGEN_RSVD_13)) & (BFM_CONTROL_VREFGEN_RSVD_13))
#define BFX_CONTROL_VREFGEN_RSVD_13(v)          ((((uint32_t) v) & (BFM_CONTROL_VREFGEN_RSVD_13)) >> (BFP_CONTROL_VREFGEN_RSVD_13))
#define BFW_CONTROL_VREFGEN_RSVD_13(v)          (REG_CONTROL_VREFGEN.U32 = ( (REG_CONTROL_VREFGEN.U32 & ~(BFM_CONTROL_VREFGEN_RSVD_13)) | ((((uint32_t) v)<<(BFP_CONTROL_VREFGEN_RSVD_13)) & (BFM_CONTROL_VREFGEN_RSVD_13)) ))
#define BFR_CONTROL_VREFGEN_RSVD_13()           ((REG_CONTROL_VREFGEN.U32 & (BFM_CONTROL_VREFGEN_RSVD_13))>>(BFP_CONTROL_VREFGEN_RSVD_13))

#define BFP_CONTROL_VREFGEN_PWDCVREF            (12)                    /* bitfield lsb */
#define BFM_CONTROL_VREFGEN_PWDCVREF            ((uint32_t)0x00001000)  /* bitfield mask */
#define BFN_CONTROL_VREFGEN_PWDCVREF            (1)                     /* bitfield width */
#define BFD_CONTROL_VREFGEN_PWDCVREF            (0x0)                   /* bitfield default value */
#define BFV_CONTROL_VREFGEN_PWDCVREF(v)         ((((uint32_t) v) << (BFP_CONTROL_VREFGEN_PWDCVREF)) & (BFM_CONTROL_VREFGEN_PWDCVREF))
#define BFX_CONTROL_VREFGEN_PWDCVREF(v)         ((((uint32_t) v) & (BFM_CONTROL_VREFGEN_PWDCVREF)) >> (BFP_CONTROL_VREFGEN_PWDCVREF))
#define BFW_CONTROL_VREFGEN_PWDCVREF(v)         (REG_CONTROL_VREFGEN.U32 = ( (REG_CONTROL_VREFGEN.U32 & ~(BFM_CONTROL_VREFGEN_PWDCVREF)) | ((((uint32_t) v)<<(BFP_CONTROL_VREFGEN_PWDCVREF)) & (BFM_CONTROL_VREFGEN_PWDCVREF)) ))
#define BFR_CONTROL_VREFGEN_PWDCVREF()          ((REG_CONTROL_VREFGEN.U32 & (BFM_CONTROL_VREFGEN_PWDCVREF))>>(BFP_CONTROL_VREFGEN_PWDCVREF))

#define BFP_CONTROL_VREFGEN_CVREFHADJ           (7)                     /* bitfield lsb */
#define BFM_CONTROL_VREFGEN_CVREFHADJ           ((uint32_t)0x00000f80)  /* bitfield mask */
#define BFN_CONTROL_VREFGEN_CVREFHADJ           (5)                     /* bitfield width */
#define BFD_CONTROL_VREFGEN_CVREFHADJ           (0x0)                   /* bitfield default value */
#define BFV_CONTROL_VREFGEN_CVREFHADJ(v)        ((((uint32_t) v) << (BFP_CONTROL_VREFGEN_CVREFHADJ)) & (BFM_CONTROL_VREFGEN_CVREFHADJ))
#define BFX_CONTROL_VREFGEN_CVREFHADJ(v)        ((((uint32_t) v) & (BFM_CONTROL_VREFGEN_CVREFHADJ)) >> (BFP_CONTROL_VREFGEN_CVREFHADJ))
#define BFW_CONTROL_VREFGEN_CVREFHADJ(v)        (REG_CONTROL_VREFGEN.U32 = ( (REG_CONTROL_VREFGEN.U32 & ~(BFM_CONTROL_VREFGEN_CVREFHADJ)) | ((((uint32_t) v)<<(BFP_CONTROL_VREFGEN_CVREFHADJ)) & (BFM_CONTROL_VREFGEN_CVREFHADJ)) ))
#define BFR_CONTROL_VREFGEN_CVREFHADJ()         ((REG_CONTROL_VREFGEN.U32 & (BFM_CONTROL_VREFGEN_CVREFHADJ))>>(BFP_CONTROL_VREFGEN_CVREFHADJ))

#define BFP_CONTROL_VREFGEN_CVREFLADJ           (4)                     /* bitfield lsb */
#define BFM_CONTROL_VREFGEN_CVREFLADJ           ((uint32_t)0x00000070)  /* bitfield mask */
#define BFN_CONTROL_VREFGEN_CVREFLADJ           (3)                     /* bitfield width */
#define BFD_CONTROL_VREFGEN_CVREFLADJ           (0x0)                   /* bitfield default value */
#define BFV_CONTROL_VREFGEN_CVREFLADJ(v)        ((((uint32_t) v) << (BFP_CONTROL_VREFGEN_CVREFLADJ)) & (BFM_CONTROL_VREFGEN_CVREFLADJ))
#define BFX_CONTROL_VREFGEN_CVREFLADJ(v)        ((((uint32_t) v) & (BFM_CONTROL_VREFGEN_CVREFLADJ)) >> (BFP_CONTROL_VREFGEN_CVREFLADJ))
#define BFW_CONTROL_VREFGEN_CVREFLADJ(v)        (REG_CONTROL_VREFGEN.U32 = ( (REG_CONTROL_VREFGEN.U32 & ~(BFM_CONTROL_VREFGEN_CVREFLADJ)) | ((((uint32_t) v)<<(BFP_CONTROL_VREFGEN_CVREFLADJ)) & (BFM_CONTROL_VREFGEN_CVREFLADJ)) ))
#define BFR_CONTROL_VREFGEN_CVREFLADJ()         ((REG_CONTROL_VREFGEN.U32 & (BFM_CONTROL_VREFGEN_CVREFLADJ))>>(BFP_CONTROL_VREFGEN_CVREFLADJ))

#define BFP_CONTROL_VREFGEN_CVREFBTRIM          (0)                     /* bitfield lsb */
#define BFM_CONTROL_VREFGEN_CVREFBTRIM          ((uint32_t)0x0000000f)  /* bitfield mask */
#define BFN_CONTROL_VREFGEN_CVREFBTRIM          (4)                     /* bitfield width */
#define BFD_CONTROL_VREFGEN_CVREFBTRIM          (0x0)                   /* bitfield default value */
#define BFV_CONTROL_VREFGEN_CVREFBTRIM(v)       ((((uint32_t) v) << (BFP_CONTROL_VREFGEN_CVREFBTRIM)) & (BFM_CONTROL_VREFGEN_CVREFBTRIM))
#define BFX_CONTROL_VREFGEN_CVREFBTRIM(v)       ((((uint32_t) v) & (BFM_CONTROL_VREFGEN_CVREFBTRIM)) >> (BFP_CONTROL_VREFGEN_CVREFBTRIM))
#define BFW_CONTROL_VREFGEN_CVREFBTRIM(v)       (REG_CONTROL_VREFGEN.U32 = ( (REG_CONTROL_VREFGEN.U32 & ~(BFM_CONTROL_VREFGEN_CVREFBTRIM)) | ((((uint32_t) v)<<(BFP_CONTROL_VREFGEN_CVREFBTRIM)) & (BFM_CONTROL_VREFGEN_CVREFBTRIM)) ))
#define BFR_CONTROL_VREFGEN_CVREFBTRIM()        ((REG_CONTROL_VREFGEN.U32 & (BFM_CONTROL_VREFGEN_CVREFBTRIM))>>(BFP_CONTROL_VREFGEN_CVREFBTRIM))


// *****************************************************************************
//                                                                             *
//  CONTROL_BUCK - Analog Buck Control                                         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_6                     : 26;
        unsigned BYPBUCKMEM                 :  1;
        unsigned ENBUCKMEM                  :  1;
        unsigned SLEEPBUCKANA               :  1;
        unsigned ENBUCKCORE                 :  1;
        unsigned BYPBUCKCORE                :  1;
        unsigned BUCKSWE                    :  1;
    } B;
} reg_control_buck_t;

#define REG_CONTROL_BUCK_ADDR                   (REG_CONTROL_BASEADDR + 0x00000060UL)
#define REG_CONTROL_BUCK                        (*(volatile reg_control_buck_t *) REG_CONTROL_BUCK_ADDR)
#define REG_CONTROL_BUCK_RD()                   (REG_CONTROL_BUCK.U32)
#define REG_CONTROL_BUCK_WR(v)                  (REG_CONTROL_BUCK.U32 = (v))
#define REG_CONTROL_BUCK_CLR(m)                 (REG_CONTROL_BUCK.U32 = ((REG_CONTROL_BUCK.U32) & ~(m)))
#define REG_CONTROL_BUCK_SET(m)                 (REG_CONTROL_BUCK.U32 = ((REG_CONTROL_BUCK.U32) | (m)))
#define REG_CONTROL_BUCK_DEF                    0x00000000

#define BFP_CONTROL_BUCK_RSVD_6                 (6)                     /* bitfield lsb */
#define BFM_CONTROL_BUCK_RSVD_6                 ((uint32_t)0xffffffc0)  /* bitfield mask */
#define BFN_CONTROL_BUCK_RSVD_6                 (26)                    /* bitfield width */
#define BFD_CONTROL_BUCK_RSVD_6                 (0x0)                   /* bitfield default value */
#define BFV_CONTROL_BUCK_RSVD_6(v)              ((((uint32_t) v) << (BFP_CONTROL_BUCK_RSVD_6)) & (BFM_CONTROL_BUCK_RSVD_6))
#define BFX_CONTROL_BUCK_RSVD_6(v)              ((((uint32_t) v) & (BFM_CONTROL_BUCK_RSVD_6)) >> (BFP_CONTROL_BUCK_RSVD_6))
#define BFW_CONTROL_BUCK_RSVD_6(v)              (REG_CONTROL_BUCK.U32 = ( (REG_CONTROL_BUCK.U32 & ~(BFM_CONTROL_BUCK_RSVD_6)) | ((((uint32_t) v)<<(BFP_CONTROL_BUCK_RSVD_6)) & (BFM_CONTROL_BUCK_RSVD_6)) ))
#define BFR_CONTROL_BUCK_RSVD_6()               ((REG_CONTROL_BUCK.U32 & (BFM_CONTROL_BUCK_RSVD_6))>>(BFP_CONTROL_BUCK_RSVD_6))

#define BFP_CONTROL_BUCK_BYPBUCKMEM             (5)                     /* bitfield lsb */
#define BFM_CONTROL_BUCK_BYPBUCKMEM             ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_CONTROL_BUCK_BYPBUCKMEM             (1)                     /* bitfield width */
#define BFD_CONTROL_BUCK_BYPBUCKMEM             (0x0)                   /* bitfield default value */
#define BFV_CONTROL_BUCK_BYPBUCKMEM(v)          ((((uint32_t) v) << (BFP_CONTROL_BUCK_BYPBUCKMEM)) & (BFM_CONTROL_BUCK_BYPBUCKMEM))
#define BFX_CONTROL_BUCK_BYPBUCKMEM(v)          ((((uint32_t) v) & (BFM_CONTROL_BUCK_BYPBUCKMEM)) >> (BFP_CONTROL_BUCK_BYPBUCKMEM))
#define BFW_CONTROL_BUCK_BYPBUCKMEM(v)          (REG_CONTROL_BUCK.U32 = ( (REG_CONTROL_BUCK.U32 & ~(BFM_CONTROL_BUCK_BYPBUCKMEM)) | ((((uint32_t) v)<<(BFP_CONTROL_BUCK_BYPBUCKMEM)) & (BFM_CONTROL_BUCK_BYPBUCKMEM)) ))
#define BFR_CONTROL_BUCK_BYPBUCKMEM()           ((REG_CONTROL_BUCK.U32 & (BFM_CONTROL_BUCK_BYPBUCKMEM))>>(BFP_CONTROL_BUCK_BYPBUCKMEM))

#define BFP_CONTROL_BUCK_ENBUCKMEM              (4)                     /* bitfield lsb */
#define BFM_CONTROL_BUCK_ENBUCKMEM              ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_CONTROL_BUCK_ENBUCKMEM              (1)                     /* bitfield width */
#define BFD_CONTROL_BUCK_ENBUCKMEM              (0x0)                   /* bitfield default value */
#define BFV_CONTROL_BUCK_ENBUCKMEM(v)           ((((uint32_t) v) << (BFP_CONTROL_BUCK_ENBUCKMEM)) & (BFM_CONTROL_BUCK_ENBUCKMEM))
#define BFX_CONTROL_BUCK_ENBUCKMEM(v)           ((((uint32_t) v) & (BFM_CONTROL_BUCK_ENBUCKMEM)) >> (BFP_CONTROL_BUCK_ENBUCKMEM))
#define BFW_CONTROL_BUCK_ENBUCKMEM(v)           (REG_CONTROL_BUCK.U32 = ( (REG_CONTROL_BUCK.U32 & ~(BFM_CONTROL_BUCK_ENBUCKMEM)) | ((((uint32_t) v)<<(BFP_CONTROL_BUCK_ENBUCKMEM)) & (BFM_CONTROL_BUCK_ENBUCKMEM)) ))
#define BFR_CONTROL_BUCK_ENBUCKMEM()            ((REG_CONTROL_BUCK.U32 & (BFM_CONTROL_BUCK_ENBUCKMEM))>>(BFP_CONTROL_BUCK_ENBUCKMEM))

#define BFP_CONTROL_BUCK_SLEEPBUCKANA           (3)                     /* bitfield lsb */
#define BFM_CONTROL_BUCK_SLEEPBUCKANA           ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_CONTROL_BUCK_SLEEPBUCKANA           (1)                     /* bitfield width */
#define BFD_CONTROL_BUCK_SLEEPBUCKANA           (0x0)                   /* bitfield default value */
#define BFV_CONTROL_BUCK_SLEEPBUCKANA(v)        ((((uint32_t) v) << (BFP_CONTROL_BUCK_SLEEPBUCKANA)) & (BFM_CONTROL_BUCK_SLEEPBUCKANA))
#define BFX_CONTROL_BUCK_SLEEPBUCKANA(v)        ((((uint32_t) v) & (BFM_CONTROL_BUCK_SLEEPBUCKANA)) >> (BFP_CONTROL_BUCK_SLEEPBUCKANA))
#define BFW_CONTROL_BUCK_SLEEPBUCKANA(v)        (REG_CONTROL_BUCK.U32 = ( (REG_CONTROL_BUCK.U32 & ~(BFM_CONTROL_BUCK_SLEEPBUCKANA)) | ((((uint32_t) v)<<(BFP_CONTROL_BUCK_SLEEPBUCKANA)) & (BFM_CONTROL_BUCK_SLEEPBUCKANA)) ))
#define BFR_CONTROL_BUCK_SLEEPBUCKANA()         ((REG_CONTROL_BUCK.U32 & (BFM_CONTROL_BUCK_SLEEPBUCKANA))>>(BFP_CONTROL_BUCK_SLEEPBUCKANA))

#define BFP_CONTROL_BUCK_ENBUCKCORE             (2)                     /* bitfield lsb */
#define BFM_CONTROL_BUCK_ENBUCKCORE             ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_CONTROL_BUCK_ENBUCKCORE             (1)                     /* bitfield width */
#define BFD_CONTROL_BUCK_ENBUCKCORE             (0x0)                   /* bitfield default value */
#define BFV_CONTROL_BUCK_ENBUCKCORE(v)          ((((uint32_t) v) << (BFP_CONTROL_BUCK_ENBUCKCORE)) & (BFM_CONTROL_BUCK_ENBUCKCORE))
#define BFX_CONTROL_BUCK_ENBUCKCORE(v)          ((((uint32_t) v) & (BFM_CONTROL_BUCK_ENBUCKCORE)) >> (BFP_CONTROL_BUCK_ENBUCKCORE))
#define BFW_CONTROL_BUCK_ENBUCKCORE(v)          (REG_CONTROL_BUCK.U32 = ( (REG_CONTROL_BUCK.U32 & ~(BFM_CONTROL_BUCK_ENBUCKCORE)) | ((((uint32_t) v)<<(BFP_CONTROL_BUCK_ENBUCKCORE)) & (BFM_CONTROL_BUCK_ENBUCKCORE)) ))
#define BFR_CONTROL_BUCK_ENBUCKCORE()           ((REG_CONTROL_BUCK.U32 & (BFM_CONTROL_BUCK_ENBUCKCORE))>>(BFP_CONTROL_BUCK_ENBUCKCORE))

#define BFP_CONTROL_BUCK_BYPBUCKCORE            (1)                     /* bitfield lsb */
#define BFM_CONTROL_BUCK_BYPBUCKCORE            ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CONTROL_BUCK_BYPBUCKCORE            (1)                     /* bitfield width */
#define BFD_CONTROL_BUCK_BYPBUCKCORE            (0x0)                   /* bitfield default value */
#define BFV_CONTROL_BUCK_BYPBUCKCORE(v)         ((((uint32_t) v) << (BFP_CONTROL_BUCK_BYPBUCKCORE)) & (BFM_CONTROL_BUCK_BYPBUCKCORE))
#define BFX_CONTROL_BUCK_BYPBUCKCORE(v)         ((((uint32_t) v) & (BFM_CONTROL_BUCK_BYPBUCKCORE)) >> (BFP_CONTROL_BUCK_BYPBUCKCORE))
#define BFW_CONTROL_BUCK_BYPBUCKCORE(v)         (REG_CONTROL_BUCK.U32 = ( (REG_CONTROL_BUCK.U32 & ~(BFM_CONTROL_BUCK_BYPBUCKCORE)) | ((((uint32_t) v)<<(BFP_CONTROL_BUCK_BYPBUCKCORE)) & (BFM_CONTROL_BUCK_BYPBUCKCORE)) ))
#define BFR_CONTROL_BUCK_BYPBUCKCORE()          ((REG_CONTROL_BUCK.U32 & (BFM_CONTROL_BUCK_BYPBUCKCORE))>>(BFP_CONTROL_BUCK_BYPBUCKCORE))

#define BFP_CONTROL_BUCK_BUCKSWE                (0)                     /* bitfield lsb */
#define BFM_CONTROL_BUCK_BUCKSWE                ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_BUCK_BUCKSWE                (1)                     /* bitfield width */
#define BFD_CONTROL_BUCK_BUCKSWE                (0x0)                   /* bitfield default value */
#define BFV_CONTROL_BUCK_BUCKSWE(v)             ((((uint32_t) v) << (BFP_CONTROL_BUCK_BUCKSWE)) & (BFM_CONTROL_BUCK_BUCKSWE))
#define BFX_CONTROL_BUCK_BUCKSWE(v)             ((((uint32_t) v) & (BFM_CONTROL_BUCK_BUCKSWE)) >> (BFP_CONTROL_BUCK_BUCKSWE))
#define BFW_CONTROL_BUCK_BUCKSWE(v)             (REG_CONTROL_BUCK.U32 = ( (REG_CONTROL_BUCK.U32 & ~(BFM_CONTROL_BUCK_BUCKSWE)) | ((((uint32_t) v)<<(BFP_CONTROL_BUCK_BUCKSWE)) & (BFM_CONTROL_BUCK_BUCKSWE)) ))
#define BFR_CONTROL_BUCK_BUCKSWE()              ((REG_CONTROL_BUCK.U32 & (BFM_CONTROL_BUCK_BUCKSWE))>>(BFP_CONTROL_BUCK_BUCKSWE))


// *****************************************************************************
//                                                                             *
//  CONTROL_BUCK2 - Buck Control Reg2                                          *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_12                    : 20;
        unsigned BUCKLFCLKSEL               :  2;
        unsigned HYSTBUCKCORE               :  1;
        unsigned HYSTBUCKMEM                :  1;
        unsigned BMEMTONSEL                 :  4;
        unsigned BCORETONSEL                :  4;
    } B;
} reg_control_buck2_t;

#define REG_CONTROL_BUCK2_ADDR                  (REG_CONTROL_BASEADDR + 0x00000064UL)
#define REG_CONTROL_BUCK2                       (*(volatile reg_control_buck2_t *) REG_CONTROL_BUCK2_ADDR)
#define REG_CONTROL_BUCK2_RD()                  (REG_CONTROL_BUCK2.U32)
#define REG_CONTROL_BUCK2_WR(v)                 (REG_CONTROL_BUCK2.U32 = (v))
#define REG_CONTROL_BUCK2_CLR(m)                (REG_CONTROL_BUCK2.U32 = ((REG_CONTROL_BUCK2.U32) & ~(m)))
#define REG_CONTROL_BUCK2_SET(m)                (REG_CONTROL_BUCK2.U32 = ((REG_CONTROL_BUCK2.U32) | (m)))
#define REG_CONTROL_BUCK2_DEF                   0x00000000

#define BFP_CONTROL_BUCK2_RSVD_12               (12)                    /* bitfield lsb */
#define BFM_CONTROL_BUCK2_RSVD_12               ((uint32_t)0xfffff000)  /* bitfield mask */
#define BFN_CONTROL_BUCK2_RSVD_12               (20)                    /* bitfield width */
#define BFD_CONTROL_BUCK2_RSVD_12               (0x0)                   /* bitfield default value */
#define BFV_CONTROL_BUCK2_RSVD_12(v)            ((((uint32_t) v) << (BFP_CONTROL_BUCK2_RSVD_12)) & (BFM_CONTROL_BUCK2_RSVD_12))
#define BFX_CONTROL_BUCK2_RSVD_12(v)            ((((uint32_t) v) & (BFM_CONTROL_BUCK2_RSVD_12)) >> (BFP_CONTROL_BUCK2_RSVD_12))
#define BFW_CONTROL_BUCK2_RSVD_12(v)            (REG_CONTROL_BUCK2.U32 = ( (REG_CONTROL_BUCK2.U32 & ~(BFM_CONTROL_BUCK2_RSVD_12)) | ((((uint32_t) v)<<(BFP_CONTROL_BUCK2_RSVD_12)) & (BFM_CONTROL_BUCK2_RSVD_12)) ))
#define BFR_CONTROL_BUCK2_RSVD_12()             ((REG_CONTROL_BUCK2.U32 & (BFM_CONTROL_BUCK2_RSVD_12))>>(BFP_CONTROL_BUCK2_RSVD_12))

#define BFP_CONTROL_BUCK2_BUCKLFCLKSEL          (10)                    /* bitfield lsb */
#define BFM_CONTROL_BUCK2_BUCKLFCLKSEL          ((uint32_t)0x00000c00)  /* bitfield mask */
#define BFN_CONTROL_BUCK2_BUCKLFCLKSEL          (2)                     /* bitfield width */
#define BFD_CONTROL_BUCK2_BUCKLFCLKSEL          (0x0)                   /* bitfield default value */
#define BFV_CONTROL_BUCK2_BUCKLFCLKSEL(v)       ((((uint32_t) v) << (BFP_CONTROL_BUCK2_BUCKLFCLKSEL)) & (BFM_CONTROL_BUCK2_BUCKLFCLKSEL))
#define BFX_CONTROL_BUCK2_BUCKLFCLKSEL(v)       ((((uint32_t) v) & (BFM_CONTROL_BUCK2_BUCKLFCLKSEL)) >> (BFP_CONTROL_BUCK2_BUCKLFCLKSEL))
#define BFW_CONTROL_BUCK2_BUCKLFCLKSEL(v)       (REG_CONTROL_BUCK2.U32 = ( (REG_CONTROL_BUCK2.U32 & ~(BFM_CONTROL_BUCK2_BUCKLFCLKSEL)) | ((((uint32_t) v)<<(BFP_CONTROL_BUCK2_BUCKLFCLKSEL)) & (BFM_CONTROL_BUCK2_BUCKLFCLKSEL)) ))
#define BFR_CONTROL_BUCK2_BUCKLFCLKSEL()        ((REG_CONTROL_BUCK2.U32 & (BFM_CONTROL_BUCK2_BUCKLFCLKSEL))>>(BFP_CONTROL_BUCK2_BUCKLFCLKSEL))

#define BFP_CONTROL_BUCK2_HYSTBUCKCORE          (9)                     /* bitfield lsb */
#define BFM_CONTROL_BUCK2_HYSTBUCKCORE          ((uint32_t)0x00000200)  /* bitfield mask */
#define BFN_CONTROL_BUCK2_HYSTBUCKCORE          (1)                     /* bitfield width */
#define BFD_CONTROL_BUCK2_HYSTBUCKCORE          (0x0)                   /* bitfield default value */
#define BFV_CONTROL_BUCK2_HYSTBUCKCORE(v)       ((((uint32_t) v) << (BFP_CONTROL_BUCK2_HYSTBUCKCORE)) & (BFM_CONTROL_BUCK2_HYSTBUCKCORE))
#define BFX_CONTROL_BUCK2_HYSTBUCKCORE(v)       ((((uint32_t) v) & (BFM_CONTROL_BUCK2_HYSTBUCKCORE)) >> (BFP_CONTROL_BUCK2_HYSTBUCKCORE))
#define BFW_CONTROL_BUCK2_HYSTBUCKCORE(v)       (REG_CONTROL_BUCK2.U32 = ( (REG_CONTROL_BUCK2.U32 & ~(BFM_CONTROL_BUCK2_HYSTBUCKCORE)) | ((((uint32_t) v)<<(BFP_CONTROL_BUCK2_HYSTBUCKCORE)) & (BFM_CONTROL_BUCK2_HYSTBUCKCORE)) ))
#define BFR_CONTROL_BUCK2_HYSTBUCKCORE()        ((REG_CONTROL_BUCK2.U32 & (BFM_CONTROL_BUCK2_HYSTBUCKCORE))>>(BFP_CONTROL_BUCK2_HYSTBUCKCORE))

#define BFP_CONTROL_BUCK2_HYSTBUCKMEM           (8)                     /* bitfield lsb */
#define BFM_CONTROL_BUCK2_HYSTBUCKMEM           ((uint32_t)0x00000100)  /* bitfield mask */
#define BFN_CONTROL_BUCK2_HYSTBUCKMEM           (1)                     /* bitfield width */
#define BFD_CONTROL_BUCK2_HYSTBUCKMEM           (0x0)                   /* bitfield default value */
#define BFV_CONTROL_BUCK2_HYSTBUCKMEM(v)        ((((uint32_t) v) << (BFP_CONTROL_BUCK2_HYSTBUCKMEM)) & (BFM_CONTROL_BUCK2_HYSTBUCKMEM))
#define BFX_CONTROL_BUCK2_HYSTBUCKMEM(v)        ((((uint32_t) v) & (BFM_CONTROL_BUCK2_HYSTBUCKMEM)) >> (BFP_CONTROL_BUCK2_HYSTBUCKMEM))
#define BFW_CONTROL_BUCK2_HYSTBUCKMEM(v)        (REG_CONTROL_BUCK2.U32 = ( (REG_CONTROL_BUCK2.U32 & ~(BFM_CONTROL_BUCK2_HYSTBUCKMEM)) | ((((uint32_t) v)<<(BFP_CONTROL_BUCK2_HYSTBUCKMEM)) & (BFM_CONTROL_BUCK2_HYSTBUCKMEM)) ))
#define BFR_CONTROL_BUCK2_HYSTBUCKMEM()         ((REG_CONTROL_BUCK2.U32 & (BFM_CONTROL_BUCK2_HYSTBUCKMEM))>>(BFP_CONTROL_BUCK2_HYSTBUCKMEM))

#define BFP_CONTROL_BUCK2_BMEMTONSEL            (4)                     /* bitfield lsb */
#define BFM_CONTROL_BUCK2_BMEMTONSEL            ((uint32_t)0x000000f0)  /* bitfield mask */
#define BFN_CONTROL_BUCK2_BMEMTONSEL            (4)                     /* bitfield width */
#define BFD_CONTROL_BUCK2_BMEMTONSEL            (0x0)                   /* bitfield default value */
#define BFV_CONTROL_BUCK2_BMEMTONSEL(v)         ((((uint32_t) v) << (BFP_CONTROL_BUCK2_BMEMTONSEL)) & (BFM_CONTROL_BUCK2_BMEMTONSEL))
#define BFX_CONTROL_BUCK2_BMEMTONSEL(v)         ((((uint32_t) v) & (BFM_CONTROL_BUCK2_BMEMTONSEL)) >> (BFP_CONTROL_BUCK2_BMEMTONSEL))
#define BFW_CONTROL_BUCK2_BMEMTONSEL(v)         (REG_CONTROL_BUCK2.U32 = ( (REG_CONTROL_BUCK2.U32 & ~(BFM_CONTROL_BUCK2_BMEMTONSEL)) | ((((uint32_t) v)<<(BFP_CONTROL_BUCK2_BMEMTONSEL)) & (BFM_CONTROL_BUCK2_BMEMTONSEL)) ))
#define BFR_CONTROL_BUCK2_BMEMTONSEL()          ((REG_CONTROL_BUCK2.U32 & (BFM_CONTROL_BUCK2_BMEMTONSEL))>>(BFP_CONTROL_BUCK2_BMEMTONSEL))

#define BFP_CONTROL_BUCK2_BCORETONSEL           (0)                     /* bitfield lsb */
#define BFM_CONTROL_BUCK2_BCORETONSEL           ((uint32_t)0x0000000f)  /* bitfield mask */
#define BFN_CONTROL_BUCK2_BCORETONSEL           (4)                     /* bitfield width */
#define BFD_CONTROL_BUCK2_BCORETONSEL           (0x0)                   /* bitfield default value */
#define BFV_CONTROL_BUCK2_BCORETONSEL(v)        ((((uint32_t) v) << (BFP_CONTROL_BUCK2_BCORETONSEL)) & (BFM_CONTROL_BUCK2_BCORETONSEL))
#define BFX_CONTROL_BUCK2_BCORETONSEL(v)        ((((uint32_t) v) & (BFM_CONTROL_BUCK2_BCORETONSEL)) >> (BFP_CONTROL_BUCK2_BCORETONSEL))
#define BFW_CONTROL_BUCK2_BCORETONSEL(v)        (REG_CONTROL_BUCK2.U32 = ( (REG_CONTROL_BUCK2.U32 & ~(BFM_CONTROL_BUCK2_BCORETONSEL)) | ((((uint32_t) v)<<(BFP_CONTROL_BUCK2_BCORETONSEL)) & (BFM_CONTROL_BUCK2_BCORETONSEL)) ))
#define BFR_CONTROL_BUCK2_BCORETONSEL()         ((REG_CONTROL_BUCK2.U32 & (BFM_CONTROL_BUCK2_BCORETONSEL))>>(BFP_CONTROL_BUCK2_BCORETONSEL))


// *****************************************************************************
//                                                                             *
//  CONTROL_LDOREG1 - Analog LDO Reg 1                                         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_26                    :  6;
        unsigned TRIMCORELDOR3              :  7;
        unsigned TRIMCORELDOR2              : 10;
        unsigned TRIMCORELDOR1              :  9;
    } B;
} reg_control_ldoreg1_t;

#define REG_CONTROL_LDOREG1_ADDR                (REG_CONTROL_BASEADDR + 0x00000080UL)
#define REG_CONTROL_LDOREG1                     (*(volatile reg_control_ldoreg1_t *) REG_CONTROL_LDOREG1_ADDR)
#define REG_CONTROL_LDOREG1_RD()                (REG_CONTROL_LDOREG1.U32)
#define REG_CONTROL_LDOREG1_WR(v)               (REG_CONTROL_LDOREG1.U32 = (v))
#define REG_CONTROL_LDOREG1_CLR(m)              (REG_CONTROL_LDOREG1.U32 = ((REG_CONTROL_LDOREG1.U32) & ~(m)))
#define REG_CONTROL_LDOREG1_SET(m)              (REG_CONTROL_LDOREG1.U32 = ((REG_CONTROL_LDOREG1.U32) | (m)))
#define REG_CONTROL_LDOREG1_DEF                 0x00000000

#define BFP_CONTROL_LDOREG1_RSVD_26             (26)                    /* bitfield lsb */
#define BFM_CONTROL_LDOREG1_RSVD_26             ((uint32_t)0xfc000000)  /* bitfield mask */
#define BFN_CONTROL_LDOREG1_RSVD_26             (6)                     /* bitfield width */
#define BFD_CONTROL_LDOREG1_RSVD_26             (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG1_RSVD_26(v)          ((((uint32_t) v) << (BFP_CONTROL_LDOREG1_RSVD_26)) & (BFM_CONTROL_LDOREG1_RSVD_26))
#define BFX_CONTROL_LDOREG1_RSVD_26(v)          ((((uint32_t) v) & (BFM_CONTROL_LDOREG1_RSVD_26)) >> (BFP_CONTROL_LDOREG1_RSVD_26))
#define BFW_CONTROL_LDOREG1_RSVD_26(v)          (REG_CONTROL_LDOREG1.U32 = ( (REG_CONTROL_LDOREG1.U32 & ~(BFM_CONTROL_LDOREG1_RSVD_26)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG1_RSVD_26)) & (BFM_CONTROL_LDOREG1_RSVD_26)) ))
#define BFR_CONTROL_LDOREG1_RSVD_26()           ((REG_CONTROL_LDOREG1.U32 & (BFM_CONTROL_LDOREG1_RSVD_26))>>(BFP_CONTROL_LDOREG1_RSVD_26))

#define BFP_CONTROL_LDOREG1_TRIMCORELDOR3       (19)                    /* bitfield lsb */
#define BFM_CONTROL_LDOREG1_TRIMCORELDOR3       ((uint32_t)0x03f80000)  /* bitfield mask */
#define BFN_CONTROL_LDOREG1_TRIMCORELDOR3       (7)                     /* bitfield width */
#define BFD_CONTROL_LDOREG1_TRIMCORELDOR3       (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG1_TRIMCORELDOR3(v)    ((((uint32_t) v) << (BFP_CONTROL_LDOREG1_TRIMCORELDOR3)) & (BFM_CONTROL_LDOREG1_TRIMCORELDOR3))
#define BFX_CONTROL_LDOREG1_TRIMCORELDOR3(v)    ((((uint32_t) v) & (BFM_CONTROL_LDOREG1_TRIMCORELDOR3)) >> (BFP_CONTROL_LDOREG1_TRIMCORELDOR3))
#define BFW_CONTROL_LDOREG1_TRIMCORELDOR3(v)    (REG_CONTROL_LDOREG1.U32 = ( (REG_CONTROL_LDOREG1.U32 & ~(BFM_CONTROL_LDOREG1_TRIMCORELDOR3)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG1_TRIMCORELDOR3)) & (BFM_CONTROL_LDOREG1_TRIMCORELDOR3)) ))
#define BFR_CONTROL_LDOREG1_TRIMCORELDOR3()     ((REG_CONTROL_LDOREG1.U32 & (BFM_CONTROL_LDOREG1_TRIMCORELDOR3))>>(BFP_CONTROL_LDOREG1_TRIMCORELDOR3))

#define BFP_CONTROL_LDOREG1_TRIMCORELDOR2       (9)                     /* bitfield lsb */
#define BFM_CONTROL_LDOREG1_TRIMCORELDOR2       ((uint32_t)0x0007fe00)  /* bitfield mask */
#define BFN_CONTROL_LDOREG1_TRIMCORELDOR2       (10)                    /* bitfield width */
#define BFD_CONTROL_LDOREG1_TRIMCORELDOR2       (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG1_TRIMCORELDOR2(v)    ((((uint32_t) v) << (BFP_CONTROL_LDOREG1_TRIMCORELDOR2)) & (BFM_CONTROL_LDOREG1_TRIMCORELDOR2))
#define BFX_CONTROL_LDOREG1_TRIMCORELDOR2(v)    ((((uint32_t) v) & (BFM_CONTROL_LDOREG1_TRIMCORELDOR2)) >> (BFP_CONTROL_LDOREG1_TRIMCORELDOR2))
#define BFW_CONTROL_LDOREG1_TRIMCORELDOR2(v)    (REG_CONTROL_LDOREG1.U32 = ( (REG_CONTROL_LDOREG1.U32 & ~(BFM_CONTROL_LDOREG1_TRIMCORELDOR2)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG1_TRIMCORELDOR2)) & (BFM_CONTROL_LDOREG1_TRIMCORELDOR2)) ))
#define BFR_CONTROL_LDOREG1_TRIMCORELDOR2()     ((REG_CONTROL_LDOREG1.U32 & (BFM_CONTROL_LDOREG1_TRIMCORELDOR2))>>(BFP_CONTROL_LDOREG1_TRIMCORELDOR2))

#define BFP_CONTROL_LDOREG1_TRIMCORELDOR1       (0)                     /* bitfield lsb */
#define BFM_CONTROL_LDOREG1_TRIMCORELDOR1       ((uint32_t)0x000001ff)  /* bitfield mask */
#define BFN_CONTROL_LDOREG1_TRIMCORELDOR1       (9)                     /* bitfield width */
#define BFD_CONTROL_LDOREG1_TRIMCORELDOR1       (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG1_TRIMCORELDOR1(v)    ((((uint32_t) v) << (BFP_CONTROL_LDOREG1_TRIMCORELDOR1)) & (BFM_CONTROL_LDOREG1_TRIMCORELDOR1))
#define BFX_CONTROL_LDOREG1_TRIMCORELDOR1(v)    ((((uint32_t) v) & (BFM_CONTROL_LDOREG1_TRIMCORELDOR1)) >> (BFP_CONTROL_LDOREG1_TRIMCORELDOR1))
#define BFW_CONTROL_LDOREG1_TRIMCORELDOR1(v)    (REG_CONTROL_LDOREG1.U32 = ( (REG_CONTROL_LDOREG1.U32 & ~(BFM_CONTROL_LDOREG1_TRIMCORELDOR1)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG1_TRIMCORELDOR1)) & (BFM_CONTROL_LDOREG1_TRIMCORELDOR1)) ))
#define BFR_CONTROL_LDOREG1_TRIMCORELDOR1()     ((REG_CONTROL_LDOREG1.U32 & (BFM_CONTROL_LDOREG1_TRIMCORELDOR1))>>(BFP_CONTROL_LDOREG1_TRIMCORELDOR1))


// *****************************************************************************
//                                                                             *
//  CONTROL_LDOREG2 - LDO Control Register 2                                   *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_23                    :  9;
        unsigned PWDANALDO                  :  1;
        unsigned PWDMEMLDO                  :  1;
        unsigned PWDCORELDO                 :  1;
        unsigned SLEEPANALDO                :  1;
        unsigned SLEEPMEMLDO                :  1;
        unsigned SLEEPCORELDO               :  1;
        unsigned VREFSELANALDO              :  1;
        unsigned VREFSELSRAMLDO             :  1;
        unsigned VREFSELFLASHLDO            :  1;
        unsigned VREFSELCORELDO             :  1;
        unsigned TRIMANALDO                 :  4;
        unsigned TRIMSRAMLDO                :  4;
        unsigned TRIMLDOMEM                 :  4;
        unsigned LDO2SWE                    :  1;
    } B;
} reg_control_ldoreg2_t;

#define REG_CONTROL_LDOREG2_ADDR                (REG_CONTROL_BASEADDR + 0x00000084UL)
#define REG_CONTROL_LDOREG2                     (*(volatile reg_control_ldoreg2_t *) REG_CONTROL_LDOREG2_ADDR)
#define REG_CONTROL_LDOREG2_RD()                (REG_CONTROL_LDOREG2.U32)
#define REG_CONTROL_LDOREG2_WR(v)               (REG_CONTROL_LDOREG2.U32 = (v))
#define REG_CONTROL_LDOREG2_CLR(m)              (REG_CONTROL_LDOREG2.U32 = ((REG_CONTROL_LDOREG2.U32) & ~(m)))
#define REG_CONTROL_LDOREG2_SET(m)              (REG_CONTROL_LDOREG2.U32 = ((REG_CONTROL_LDOREG2.U32) | (m)))
#define REG_CONTROL_LDOREG2_DEF                 0x00000000

#define BFP_CONTROL_LDOREG2_RSVD_23             (23)                    /* bitfield lsb */
#define BFM_CONTROL_LDOREG2_RSVD_23             ((uint32_t)0xff800000)  /* bitfield mask */
#define BFN_CONTROL_LDOREG2_RSVD_23             (9)                     /* bitfield width */
#define BFD_CONTROL_LDOREG2_RSVD_23             (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG2_RSVD_23(v)          ((((uint32_t) v) << (BFP_CONTROL_LDOREG2_RSVD_23)) & (BFM_CONTROL_LDOREG2_RSVD_23))
#define BFX_CONTROL_LDOREG2_RSVD_23(v)          ((((uint32_t) v) & (BFM_CONTROL_LDOREG2_RSVD_23)) >> (BFP_CONTROL_LDOREG2_RSVD_23))
#define BFW_CONTROL_LDOREG2_RSVD_23(v)          (REG_CONTROL_LDOREG2.U32 = ( (REG_CONTROL_LDOREG2.U32 & ~(BFM_CONTROL_LDOREG2_RSVD_23)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG2_RSVD_23)) & (BFM_CONTROL_LDOREG2_RSVD_23)) ))
#define BFR_CONTROL_LDOREG2_RSVD_23()           ((REG_CONTROL_LDOREG2.U32 & (BFM_CONTROL_LDOREG2_RSVD_23))>>(BFP_CONTROL_LDOREG2_RSVD_23))

#define BFP_CONTROL_LDOREG2_PWDANALDO           (22)                    /* bitfield lsb */
#define BFM_CONTROL_LDOREG2_PWDANALDO           ((uint32_t)0x00400000)  /* bitfield mask */
#define BFN_CONTROL_LDOREG2_PWDANALDO           (1)                     /* bitfield width */
#define BFD_CONTROL_LDOREG2_PWDANALDO           (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG2_PWDANALDO(v)        ((((uint32_t) v) << (BFP_CONTROL_LDOREG2_PWDANALDO)) & (BFM_CONTROL_LDOREG2_PWDANALDO))
#define BFX_CONTROL_LDOREG2_PWDANALDO(v)        ((((uint32_t) v) & (BFM_CONTROL_LDOREG2_PWDANALDO)) >> (BFP_CONTROL_LDOREG2_PWDANALDO))
#define BFW_CONTROL_LDOREG2_PWDANALDO(v)        (REG_CONTROL_LDOREG2.U32 = ( (REG_CONTROL_LDOREG2.U32 & ~(BFM_CONTROL_LDOREG2_PWDANALDO)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG2_PWDANALDO)) & (BFM_CONTROL_LDOREG2_PWDANALDO)) ))
#define BFR_CONTROL_LDOREG2_PWDANALDO()         ((REG_CONTROL_LDOREG2.U32 & (BFM_CONTROL_LDOREG2_PWDANALDO))>>(BFP_CONTROL_LDOREG2_PWDANALDO))

#define BFP_CONTROL_LDOREG2_PWDMEMLDO           (21)                    /* bitfield lsb */
#define BFM_CONTROL_LDOREG2_PWDMEMLDO           ((uint32_t)0x00200000)  /* bitfield mask */
#define BFN_CONTROL_LDOREG2_PWDMEMLDO           (1)                     /* bitfield width */
#define BFD_CONTROL_LDOREG2_PWDMEMLDO           (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG2_PWDMEMLDO(v)        ((((uint32_t) v) << (BFP_CONTROL_LDOREG2_PWDMEMLDO)) & (BFM_CONTROL_LDOREG2_PWDMEMLDO))
#define BFX_CONTROL_LDOREG2_PWDMEMLDO(v)        ((((uint32_t) v) & (BFM_CONTROL_LDOREG2_PWDMEMLDO)) >> (BFP_CONTROL_LDOREG2_PWDMEMLDO))
#define BFW_CONTROL_LDOREG2_PWDMEMLDO(v)        (REG_CONTROL_LDOREG2.U32 = ( (REG_CONTROL_LDOREG2.U32 & ~(BFM_CONTROL_LDOREG2_PWDMEMLDO)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG2_PWDMEMLDO)) & (BFM_CONTROL_LDOREG2_PWDMEMLDO)) ))
#define BFR_CONTROL_LDOREG2_PWDMEMLDO()         ((REG_CONTROL_LDOREG2.U32 & (BFM_CONTROL_LDOREG2_PWDMEMLDO))>>(BFP_CONTROL_LDOREG2_PWDMEMLDO))

#define BFP_CONTROL_LDOREG2_PWDCORELDO          (20)                    /* bitfield lsb */
#define BFM_CONTROL_LDOREG2_PWDCORELDO          ((uint32_t)0x00100000)  /* bitfield mask */
#define BFN_CONTROL_LDOREG2_PWDCORELDO          (1)                     /* bitfield width */
#define BFD_CONTROL_LDOREG2_PWDCORELDO          (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG2_PWDCORELDO(v)       ((((uint32_t) v) << (BFP_CONTROL_LDOREG2_PWDCORELDO)) & (BFM_CONTROL_LDOREG2_PWDCORELDO))
#define BFX_CONTROL_LDOREG2_PWDCORELDO(v)       ((((uint32_t) v) & (BFM_CONTROL_LDOREG2_PWDCORELDO)) >> (BFP_CONTROL_LDOREG2_PWDCORELDO))
#define BFW_CONTROL_LDOREG2_PWDCORELDO(v)       (REG_CONTROL_LDOREG2.U32 = ( (REG_CONTROL_LDOREG2.U32 & ~(BFM_CONTROL_LDOREG2_PWDCORELDO)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG2_PWDCORELDO)) & (BFM_CONTROL_LDOREG2_PWDCORELDO)) ))
#define BFR_CONTROL_LDOREG2_PWDCORELDO()        ((REG_CONTROL_LDOREG2.U32 & (BFM_CONTROL_LDOREG2_PWDCORELDO))>>(BFP_CONTROL_LDOREG2_PWDCORELDO))

#define BFP_CONTROL_LDOREG2_SLEEPANALDO         (19)                    /* bitfield lsb */
#define BFM_CONTROL_LDOREG2_SLEEPANALDO         ((uint32_t)0x00080000)  /* bitfield mask */
#define BFN_CONTROL_LDOREG2_SLEEPANALDO         (1)                     /* bitfield width */
#define BFD_CONTROL_LDOREG2_SLEEPANALDO         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG2_SLEEPANALDO(v)      ((((uint32_t) v) << (BFP_CONTROL_LDOREG2_SLEEPANALDO)) & (BFM_CONTROL_LDOREG2_SLEEPANALDO))
#define BFX_CONTROL_LDOREG2_SLEEPANALDO(v)      ((((uint32_t) v) & (BFM_CONTROL_LDOREG2_SLEEPANALDO)) >> (BFP_CONTROL_LDOREG2_SLEEPANALDO))
#define BFW_CONTROL_LDOREG2_SLEEPANALDO(v)      (REG_CONTROL_LDOREG2.U32 = ( (REG_CONTROL_LDOREG2.U32 & ~(BFM_CONTROL_LDOREG2_SLEEPANALDO)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG2_SLEEPANALDO)) & (BFM_CONTROL_LDOREG2_SLEEPANALDO)) ))
#define BFR_CONTROL_LDOREG2_SLEEPANALDO()       ((REG_CONTROL_LDOREG2.U32 & (BFM_CONTROL_LDOREG2_SLEEPANALDO))>>(BFP_CONTROL_LDOREG2_SLEEPANALDO))

#define BFP_CONTROL_LDOREG2_SLEEPMEMLDO         (18)                    /* bitfield lsb */
#define BFM_CONTROL_LDOREG2_SLEEPMEMLDO         ((uint32_t)0x00040000)  /* bitfield mask */
#define BFN_CONTROL_LDOREG2_SLEEPMEMLDO         (1)                     /* bitfield width */
#define BFD_CONTROL_LDOREG2_SLEEPMEMLDO         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG2_SLEEPMEMLDO(v)      ((((uint32_t) v) << (BFP_CONTROL_LDOREG2_SLEEPMEMLDO)) & (BFM_CONTROL_LDOREG2_SLEEPMEMLDO))
#define BFX_CONTROL_LDOREG2_SLEEPMEMLDO(v)      ((((uint32_t) v) & (BFM_CONTROL_LDOREG2_SLEEPMEMLDO)) >> (BFP_CONTROL_LDOREG2_SLEEPMEMLDO))
#define BFW_CONTROL_LDOREG2_SLEEPMEMLDO(v)      (REG_CONTROL_LDOREG2.U32 = ( (REG_CONTROL_LDOREG2.U32 & ~(BFM_CONTROL_LDOREG2_SLEEPMEMLDO)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG2_SLEEPMEMLDO)) & (BFM_CONTROL_LDOREG2_SLEEPMEMLDO)) ))
#define BFR_CONTROL_LDOREG2_SLEEPMEMLDO()       ((REG_CONTROL_LDOREG2.U32 & (BFM_CONTROL_LDOREG2_SLEEPMEMLDO))>>(BFP_CONTROL_LDOREG2_SLEEPMEMLDO))

#define BFP_CONTROL_LDOREG2_SLEEPCORELDO        (17)                    /* bitfield lsb */
#define BFM_CONTROL_LDOREG2_SLEEPCORELDO        ((uint32_t)0x00020000)  /* bitfield mask */
#define BFN_CONTROL_LDOREG2_SLEEPCORELDO        (1)                     /* bitfield width */
#define BFD_CONTROL_LDOREG2_SLEEPCORELDO        (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG2_SLEEPCORELDO(v)     ((((uint32_t) v) << (BFP_CONTROL_LDOREG2_SLEEPCORELDO)) & (BFM_CONTROL_LDOREG2_SLEEPCORELDO))
#define BFX_CONTROL_LDOREG2_SLEEPCORELDO(v)     ((((uint32_t) v) & (BFM_CONTROL_LDOREG2_SLEEPCORELDO)) >> (BFP_CONTROL_LDOREG2_SLEEPCORELDO))
#define BFW_CONTROL_LDOREG2_SLEEPCORELDO(v)     (REG_CONTROL_LDOREG2.U32 = ( (REG_CONTROL_LDOREG2.U32 & ~(BFM_CONTROL_LDOREG2_SLEEPCORELDO)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG2_SLEEPCORELDO)) & (BFM_CONTROL_LDOREG2_SLEEPCORELDO)) ))
#define BFR_CONTROL_LDOREG2_SLEEPCORELDO()      ((REG_CONTROL_LDOREG2.U32 & (BFM_CONTROL_LDOREG2_SLEEPCORELDO))>>(BFP_CONTROL_LDOREG2_SLEEPCORELDO))

#define BFP_CONTROL_LDOREG2_VREFSELANALDO       (16)                    /* bitfield lsb */
#define BFM_CONTROL_LDOREG2_VREFSELANALDO       ((uint32_t)0x00010000)  /* bitfield mask */
#define BFN_CONTROL_LDOREG2_VREFSELANALDO       (1)                     /* bitfield width */
#define BFD_CONTROL_LDOREG2_VREFSELANALDO       (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG2_VREFSELANALDO(v)    ((((uint32_t) v) << (BFP_CONTROL_LDOREG2_VREFSELANALDO)) & (BFM_CONTROL_LDOREG2_VREFSELANALDO))
#define BFX_CONTROL_LDOREG2_VREFSELANALDO(v)    ((((uint32_t) v) & (BFM_CONTROL_LDOREG2_VREFSELANALDO)) >> (BFP_CONTROL_LDOREG2_VREFSELANALDO))
#define BFW_CONTROL_LDOREG2_VREFSELANALDO(v)    (REG_CONTROL_LDOREG2.U32 = ( (REG_CONTROL_LDOREG2.U32 & ~(BFM_CONTROL_LDOREG2_VREFSELANALDO)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG2_VREFSELANALDO)) & (BFM_CONTROL_LDOREG2_VREFSELANALDO)) ))
#define BFR_CONTROL_LDOREG2_VREFSELANALDO()     ((REG_CONTROL_LDOREG2.U32 & (BFM_CONTROL_LDOREG2_VREFSELANALDO))>>(BFP_CONTROL_LDOREG2_VREFSELANALDO))

#define BFP_CONTROL_LDOREG2_VREFSELSRAMLDO      (15)                    /* bitfield lsb */
#define BFM_CONTROL_LDOREG2_VREFSELSRAMLDO      ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_CONTROL_LDOREG2_VREFSELSRAMLDO      (1)                     /* bitfield width */
#define BFD_CONTROL_LDOREG2_VREFSELSRAMLDO      (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG2_VREFSELSRAMLDO(v)   ((((uint32_t) v) << (BFP_CONTROL_LDOREG2_VREFSELSRAMLDO)) & (BFM_CONTROL_LDOREG2_VREFSELSRAMLDO))
#define BFX_CONTROL_LDOREG2_VREFSELSRAMLDO(v)   ((((uint32_t) v) & (BFM_CONTROL_LDOREG2_VREFSELSRAMLDO)) >> (BFP_CONTROL_LDOREG2_VREFSELSRAMLDO))
#define BFW_CONTROL_LDOREG2_VREFSELSRAMLDO(v)   (REG_CONTROL_LDOREG2.U32 = ( (REG_CONTROL_LDOREG2.U32 & ~(BFM_CONTROL_LDOREG2_VREFSELSRAMLDO)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG2_VREFSELSRAMLDO)) & (BFM_CONTROL_LDOREG2_VREFSELSRAMLDO)) ))
#define BFR_CONTROL_LDOREG2_VREFSELSRAMLDO()    ((REG_CONTROL_LDOREG2.U32 & (BFM_CONTROL_LDOREG2_VREFSELSRAMLDO))>>(BFP_CONTROL_LDOREG2_VREFSELSRAMLDO))

#define BFP_CONTROL_LDOREG2_VREFSELFLASHLDO     (14)                    /* bitfield lsb */
#define BFM_CONTROL_LDOREG2_VREFSELFLASHLDO     ((uint32_t)0x00004000)  /* bitfield mask */
#define BFN_CONTROL_LDOREG2_VREFSELFLASHLDO     (1)                     /* bitfield width */
#define BFD_CONTROL_LDOREG2_VREFSELFLASHLDO     (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG2_VREFSELFLASHLDO(v)  ((((uint32_t) v) << (BFP_CONTROL_LDOREG2_VREFSELFLASHLDO)) & (BFM_CONTROL_LDOREG2_VREFSELFLASHLDO))
#define BFX_CONTROL_LDOREG2_VREFSELFLASHLDO(v)  ((((uint32_t) v) & (BFM_CONTROL_LDOREG2_VREFSELFLASHLDO)) >> (BFP_CONTROL_LDOREG2_VREFSELFLASHLDO))
#define BFW_CONTROL_LDOREG2_VREFSELFLASHLDO(v)  (REG_CONTROL_LDOREG2.U32 = ( (REG_CONTROL_LDOREG2.U32 & ~(BFM_CONTROL_LDOREG2_VREFSELFLASHLDO)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG2_VREFSELFLASHLDO)) & (BFM_CONTROL_LDOREG2_VREFSELFLASHLDO)) ))
#define BFR_CONTROL_LDOREG2_VREFSELFLASHLDO()   ((REG_CONTROL_LDOREG2.U32 & (BFM_CONTROL_LDOREG2_VREFSELFLASHLDO))>>(BFP_CONTROL_LDOREG2_VREFSELFLASHLDO))

#define BFP_CONTROL_LDOREG2_VREFSELCORELDO      (13)                    /* bitfield lsb */
#define BFM_CONTROL_LDOREG2_VREFSELCORELDO      ((uint32_t)0x00002000)  /* bitfield mask */
#define BFN_CONTROL_LDOREG2_VREFSELCORELDO      (1)                     /* bitfield width */
#define BFD_CONTROL_LDOREG2_VREFSELCORELDO      (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG2_VREFSELCORELDO(v)   ((((uint32_t) v) << (BFP_CONTROL_LDOREG2_VREFSELCORELDO)) & (BFM_CONTROL_LDOREG2_VREFSELCORELDO))
#define BFX_CONTROL_LDOREG2_VREFSELCORELDO(v)   ((((uint32_t) v) & (BFM_CONTROL_LDOREG2_VREFSELCORELDO)) >> (BFP_CONTROL_LDOREG2_VREFSELCORELDO))
#define BFW_CONTROL_LDOREG2_VREFSELCORELDO(v)   (REG_CONTROL_LDOREG2.U32 = ( (REG_CONTROL_LDOREG2.U32 & ~(BFM_CONTROL_LDOREG2_VREFSELCORELDO)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG2_VREFSELCORELDO)) & (BFM_CONTROL_LDOREG2_VREFSELCORELDO)) ))
#define BFR_CONTROL_LDOREG2_VREFSELCORELDO()    ((REG_CONTROL_LDOREG2.U32 & (BFM_CONTROL_LDOREG2_VREFSELCORELDO))>>(BFP_CONTROL_LDOREG2_VREFSELCORELDO))

#define BFP_CONTROL_LDOREG2_TRIMANALDO          (9)                     /* bitfield lsb */
#define BFM_CONTROL_LDOREG2_TRIMANALDO          ((uint32_t)0x00001e00)  /* bitfield mask */
#define BFN_CONTROL_LDOREG2_TRIMANALDO          (4)                     /* bitfield width */
#define BFD_CONTROL_LDOREG2_TRIMANALDO          (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG2_TRIMANALDO(v)       ((((uint32_t) v) << (BFP_CONTROL_LDOREG2_TRIMANALDO)) & (BFM_CONTROL_LDOREG2_TRIMANALDO))
#define BFX_CONTROL_LDOREG2_TRIMANALDO(v)       ((((uint32_t) v) & (BFM_CONTROL_LDOREG2_TRIMANALDO)) >> (BFP_CONTROL_LDOREG2_TRIMANALDO))
#define BFW_CONTROL_LDOREG2_TRIMANALDO(v)       (REG_CONTROL_LDOREG2.U32 = ( (REG_CONTROL_LDOREG2.U32 & ~(BFM_CONTROL_LDOREG2_TRIMANALDO)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG2_TRIMANALDO)) & (BFM_CONTROL_LDOREG2_TRIMANALDO)) ))
#define BFR_CONTROL_LDOREG2_TRIMANALDO()        ((REG_CONTROL_LDOREG2.U32 & (BFM_CONTROL_LDOREG2_TRIMANALDO))>>(BFP_CONTROL_LDOREG2_TRIMANALDO))

#define BFP_CONTROL_LDOREG2_TRIMSRAMLDO         (5)                     /* bitfield lsb */
#define BFM_CONTROL_LDOREG2_TRIMSRAMLDO         ((uint32_t)0x000001e0)  /* bitfield mask */
#define BFN_CONTROL_LDOREG2_TRIMSRAMLDO         (4)                     /* bitfield width */
#define BFD_CONTROL_LDOREG2_TRIMSRAMLDO         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG2_TRIMSRAMLDO(v)      ((((uint32_t) v) << (BFP_CONTROL_LDOREG2_TRIMSRAMLDO)) & (BFM_CONTROL_LDOREG2_TRIMSRAMLDO))
#define BFX_CONTROL_LDOREG2_TRIMSRAMLDO(v)      ((((uint32_t) v) & (BFM_CONTROL_LDOREG2_TRIMSRAMLDO)) >> (BFP_CONTROL_LDOREG2_TRIMSRAMLDO))
#define BFW_CONTROL_LDOREG2_TRIMSRAMLDO(v)      (REG_CONTROL_LDOREG2.U32 = ( (REG_CONTROL_LDOREG2.U32 & ~(BFM_CONTROL_LDOREG2_TRIMSRAMLDO)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG2_TRIMSRAMLDO)) & (BFM_CONTROL_LDOREG2_TRIMSRAMLDO)) ))
#define BFR_CONTROL_LDOREG2_TRIMSRAMLDO()       ((REG_CONTROL_LDOREG2.U32 & (BFM_CONTROL_LDOREG2_TRIMSRAMLDO))>>(BFP_CONTROL_LDOREG2_TRIMSRAMLDO))

#define BFP_CONTROL_LDOREG2_TRIMLDOMEM          (1)                     /* bitfield lsb */
#define BFM_CONTROL_LDOREG2_TRIMLDOMEM          ((uint32_t)0x0000001e)  /* bitfield mask */
#define BFN_CONTROL_LDOREG2_TRIMLDOMEM          (4)                     /* bitfield width */
#define BFD_CONTROL_LDOREG2_TRIMLDOMEM          (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG2_TRIMLDOMEM(v)       ((((uint32_t) v) << (BFP_CONTROL_LDOREG2_TRIMLDOMEM)) & (BFM_CONTROL_LDOREG2_TRIMLDOMEM))
#define BFX_CONTROL_LDOREG2_TRIMLDOMEM(v)       ((((uint32_t) v) & (BFM_CONTROL_LDOREG2_TRIMLDOMEM)) >> (BFP_CONTROL_LDOREG2_TRIMLDOMEM))
#define BFW_CONTROL_LDOREG2_TRIMLDOMEM(v)       (REG_CONTROL_LDOREG2.U32 = ( (REG_CONTROL_LDOREG2.U32 & ~(BFM_CONTROL_LDOREG2_TRIMLDOMEM)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG2_TRIMLDOMEM)) & (BFM_CONTROL_LDOREG2_TRIMLDOMEM)) ))
#define BFR_CONTROL_LDOREG2_TRIMLDOMEM()        ((REG_CONTROL_LDOREG2.U32 & (BFM_CONTROL_LDOREG2_TRIMLDOMEM))>>(BFP_CONTROL_LDOREG2_TRIMLDOMEM))

#define BFP_CONTROL_LDOREG2_LDO2SWE             (0)                     /* bitfield lsb */
#define BFM_CONTROL_LDOREG2_LDO2SWE             ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_LDOREG2_LDO2SWE             (1)                     /* bitfield width */
#define BFD_CONTROL_LDOREG2_LDO2SWE             (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LDOREG2_LDO2SWE(v)          ((((uint32_t) v) << (BFP_CONTROL_LDOREG2_LDO2SWE)) & (BFM_CONTROL_LDOREG2_LDO2SWE))
#define BFX_CONTROL_LDOREG2_LDO2SWE(v)          ((((uint32_t) v) & (BFM_CONTROL_LDOREG2_LDO2SWE)) >> (BFP_CONTROL_LDOREG2_LDO2SWE))
#define BFW_CONTROL_LDOREG2_LDO2SWE(v)          (REG_CONTROL_LDOREG2.U32 = ( (REG_CONTROL_LDOREG2.U32 & ~(BFM_CONTROL_LDOREG2_LDO2SWE)) | ((((uint32_t) v)<<(BFP_CONTROL_LDOREG2_LDO2SWE)) & (BFM_CONTROL_LDOREG2_LDO2SWE)) ))
#define BFR_CONTROL_LDOREG2_LDO2SWE()           ((REG_CONTROL_LDOREG2.U32 & (BFM_CONTROL_LDOREG2_LDO2SWE))>>(BFP_CONTROL_LDOREG2_LDO2SWE))


// *****************************************************************************
//                                                                             *
//  CONTROL_UNCALVREF - Uncalibrated VREF Control                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_1                     : 31;
        unsigned PWDUNCALVREF               :  1;
    } B;
} reg_control_uncalvref_t;

#define REG_CONTROL_UNCALVREF_ADDR              (REG_CONTROL_BASEADDR + 0x000000A0UL)
#define REG_CONTROL_UNCALVREF                   (*(volatile reg_control_uncalvref_t *) REG_CONTROL_UNCALVREF_ADDR)
#define REG_CONTROL_UNCALVREF_RD()              (REG_CONTROL_UNCALVREF.U32)
#define REG_CONTROL_UNCALVREF_WR(v)             (REG_CONTROL_UNCALVREF.U32 = (v))
#define REG_CONTROL_UNCALVREF_CLR(m)            (REG_CONTROL_UNCALVREF.U32 = ((REG_CONTROL_UNCALVREF.U32) & ~(m)))
#define REG_CONTROL_UNCALVREF_SET(m)            (REG_CONTROL_UNCALVREF.U32 = ((REG_CONTROL_UNCALVREF.U32) | (m)))
#define REG_CONTROL_UNCALVREF_DEF               0x00000000

#define BFP_CONTROL_UNCALVREF_RSVD_1            (1)                     /* bitfield lsb */
#define BFM_CONTROL_UNCALVREF_RSVD_1            ((uint32_t)0xfffffffe)  /* bitfield mask */
#define BFN_CONTROL_UNCALVREF_RSVD_1            (31)                    /* bitfield width */
#define BFD_CONTROL_UNCALVREF_RSVD_1            (0x0)                   /* bitfield default value */
#define BFV_CONTROL_UNCALVREF_RSVD_1(v)         ((((uint32_t) v) << (BFP_CONTROL_UNCALVREF_RSVD_1)) & (BFM_CONTROL_UNCALVREF_RSVD_1))
#define BFX_CONTROL_UNCALVREF_RSVD_1(v)         ((((uint32_t) v) & (BFM_CONTROL_UNCALVREF_RSVD_1)) >> (BFP_CONTROL_UNCALVREF_RSVD_1))
#define BFW_CONTROL_UNCALVREF_RSVD_1(v)         (REG_CONTROL_UNCALVREF.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_UNCALVREF_RSVD_1)) & (BFM_CONTROL_UNCALVREF_RSVD_1)) )
#define BFR_CONTROL_UNCALVREF_RSVD_1()          ((REG_CONTROL_UNCALVREF.U32 & (BFM_CONTROL_UNCALVREF_RSVD_1))>>(BFP_CONTROL_UNCALVREF_RSVD_1))

#define BFP_CONTROL_UNCALVREF_PWDUNCALVREF      (0)                     /* bitfield lsb */
#define BFM_CONTROL_UNCALVREF_PWDUNCALVREF      ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_UNCALVREF_PWDUNCALVREF      (1)                     /* bitfield width */
#define BFD_CONTROL_UNCALVREF_PWDUNCALVREF      (0x0)                   /* bitfield default value */
#define BFV_CONTROL_UNCALVREF_PWDUNCALVREF(v)   ((((uint32_t) v) << (BFP_CONTROL_UNCALVREF_PWDUNCALVREF)) & (BFM_CONTROL_UNCALVREF_PWDUNCALVREF))
#define BFX_CONTROL_UNCALVREF_PWDUNCALVREF(v)   ((((uint32_t) v) & (BFM_CONTROL_UNCALVREF_PWDUNCALVREF)) >> (BFP_CONTROL_UNCALVREF_PWDUNCALVREF))
#define BFW_CONTROL_UNCALVREF_PWDUNCALVREF(v)   (REG_CONTROL_UNCALVREF.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_UNCALVREF_PWDUNCALVREF)) & (BFM_CONTROL_UNCALVREF_PWDUNCALVREF)) )
#define BFR_CONTROL_UNCALVREF_PWDUNCALVREF()    ((REG_CONTROL_UNCALVREF.U32 & (BFM_CONTROL_UNCALVREF_PWDUNCALVREF))>>(BFP_CONTROL_UNCALVREF_PWDUNCALVREF))


// *****************************************************************************
//                                                                             *
//  CONTROL_HFRC - HFRC Control                                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_21                    : 11;
        unsigned HFTUNE                     : 11;
        unsigned HFRCDEL                    :  5;
        unsigned DISABLEHFRC                :  1;
        unsigned OUTLOWHFRC                 :  1;
        unsigned TRIMCOEFFHFRC              :  2;
        unsigned HFRCSWE                    :  1;
    } B;
} reg_control_hfrc_t;

#define REG_CONTROL_HFRC_ADDR                   (REG_CONTROL_BASEADDR + 0x000000C0UL)
#define REG_CONTROL_HFRC                        (*(volatile reg_control_hfrc_t *) REG_CONTROL_HFRC_ADDR)
#define REG_CONTROL_HFRC_RD()                   (REG_CONTROL_HFRC.U32)
#define REG_CONTROL_HFRC_WR(v)                  (REG_CONTROL_HFRC.U32 = (v))
#define REG_CONTROL_HFRC_CLR(m)                 (REG_CONTROL_HFRC.U32 = ((REG_CONTROL_HFRC.U32) & ~(m)))
#define REG_CONTROL_HFRC_SET(m)                 (REG_CONTROL_HFRC.U32 = ((REG_CONTROL_HFRC.U32) | (m)))
#define REG_CONTROL_HFRC_DEF                    0x00000000

#define BFP_CONTROL_HFRC_RSVD_21                (21)                    /* bitfield lsb */
#define BFM_CONTROL_HFRC_RSVD_21                ((uint32_t)0xffe00000)  /* bitfield mask */
#define BFN_CONTROL_HFRC_RSVD_21                (11)                    /* bitfield width */
#define BFD_CONTROL_HFRC_RSVD_21                (0x0)                   /* bitfield default value */
#define BFV_CONTROL_HFRC_RSVD_21(v)             ((((uint32_t) v) << (BFP_CONTROL_HFRC_RSVD_21)) & (BFM_CONTROL_HFRC_RSVD_21))
#define BFX_CONTROL_HFRC_RSVD_21(v)             ((((uint32_t) v) & (BFM_CONTROL_HFRC_RSVD_21)) >> (BFP_CONTROL_HFRC_RSVD_21))
#define BFW_CONTROL_HFRC_RSVD_21(v)             (REG_CONTROL_HFRC.U32 = ( (REG_CONTROL_HFRC.U32 & ~(BFM_CONTROL_HFRC_RSVD_21)) | ((((uint32_t) v)<<(BFP_CONTROL_HFRC_RSVD_21)) & (BFM_CONTROL_HFRC_RSVD_21)) ))
#define BFR_CONTROL_HFRC_RSVD_21()              ((REG_CONTROL_HFRC.U32 & (BFM_CONTROL_HFRC_RSVD_21))>>(BFP_CONTROL_HFRC_RSVD_21))

#define BFP_CONTROL_HFRC_HFTUNE                 (10)                    /* bitfield lsb */
#define BFM_CONTROL_HFRC_HFTUNE                 ((uint32_t)0x001ffc00)  /* bitfield mask */
#define BFN_CONTROL_HFRC_HFTUNE                 (11)                    /* bitfield width */
#define BFD_CONTROL_HFRC_HFTUNE                 (0x0)                   /* bitfield default value */
#define BFV_CONTROL_HFRC_HFTUNE(v)              ((((uint32_t) v) << (BFP_CONTROL_HFRC_HFTUNE)) & (BFM_CONTROL_HFRC_HFTUNE))
#define BFX_CONTROL_HFRC_HFTUNE(v)              ((((uint32_t) v) & (BFM_CONTROL_HFRC_HFTUNE)) >> (BFP_CONTROL_HFRC_HFTUNE))
#define BFW_CONTROL_HFRC_HFTUNE(v)              (REG_CONTROL_HFRC.U32 = ( (REG_CONTROL_HFRC.U32 & ~(BFM_CONTROL_HFRC_HFTUNE)) | ((((uint32_t) v)<<(BFP_CONTROL_HFRC_HFTUNE)) & (BFM_CONTROL_HFRC_HFTUNE)) ))
#define BFR_CONTROL_HFRC_HFTUNE()               ((REG_CONTROL_HFRC.U32 & (BFM_CONTROL_HFRC_HFTUNE))>>(BFP_CONTROL_HFRC_HFTUNE))

#define BFP_CONTROL_HFRC_HFRCDEL                (5)                     /* bitfield lsb */
#define BFM_CONTROL_HFRC_HFRCDEL                ((uint32_t)0x000003e0)  /* bitfield mask */
#define BFN_CONTROL_HFRC_HFRCDEL                (5)                     /* bitfield width */
#define BFD_CONTROL_HFRC_HFRCDEL                (0x0)                   /* bitfield default value */
#define BFV_CONTROL_HFRC_HFRCDEL(v)             ((((uint32_t) v) << (BFP_CONTROL_HFRC_HFRCDEL)) & (BFM_CONTROL_HFRC_HFRCDEL))
#define BFX_CONTROL_HFRC_HFRCDEL(v)             ((((uint32_t) v) & (BFM_CONTROL_HFRC_HFRCDEL)) >> (BFP_CONTROL_HFRC_HFRCDEL))
#define BFW_CONTROL_HFRC_HFRCDEL(v)             (REG_CONTROL_HFRC.U32 = ( (REG_CONTROL_HFRC.U32 & ~(BFM_CONTROL_HFRC_HFRCDEL)) | ((((uint32_t) v)<<(BFP_CONTROL_HFRC_HFRCDEL)) & (BFM_CONTROL_HFRC_HFRCDEL)) ))
#define BFR_CONTROL_HFRC_HFRCDEL()              ((REG_CONTROL_HFRC.U32 & (BFM_CONTROL_HFRC_HFRCDEL))>>(BFP_CONTROL_HFRC_HFRCDEL))

#define BFP_CONTROL_HFRC_DISABLEHFRC            (4)                     /* bitfield lsb */
#define BFM_CONTROL_HFRC_DISABLEHFRC            ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_CONTROL_HFRC_DISABLEHFRC            (1)                     /* bitfield width */
#define BFD_CONTROL_HFRC_DISABLEHFRC            (0x0)                   /* bitfield default value */
#define BFV_CONTROL_HFRC_DISABLEHFRC(v)         ((((uint32_t) v) << (BFP_CONTROL_HFRC_DISABLEHFRC)) & (BFM_CONTROL_HFRC_DISABLEHFRC))
#define BFX_CONTROL_HFRC_DISABLEHFRC(v)         ((((uint32_t) v) & (BFM_CONTROL_HFRC_DISABLEHFRC)) >> (BFP_CONTROL_HFRC_DISABLEHFRC))
#define BFW_CONTROL_HFRC_DISABLEHFRC(v)         (REG_CONTROL_HFRC.U32 = ( (REG_CONTROL_HFRC.U32 & ~(BFM_CONTROL_HFRC_DISABLEHFRC)) | ((((uint32_t) v)<<(BFP_CONTROL_HFRC_DISABLEHFRC)) & (BFM_CONTROL_HFRC_DISABLEHFRC)) ))
#define BFR_CONTROL_HFRC_DISABLEHFRC()          ((REG_CONTROL_HFRC.U32 & (BFM_CONTROL_HFRC_DISABLEHFRC))>>(BFP_CONTROL_HFRC_DISABLEHFRC))

#define BFP_CONTROL_HFRC_OUTLOWHFRC             (3)                     /* bitfield lsb */
#define BFM_CONTROL_HFRC_OUTLOWHFRC             ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_CONTROL_HFRC_OUTLOWHFRC             (1)                     /* bitfield width */
#define BFD_CONTROL_HFRC_OUTLOWHFRC             (0x0)                   /* bitfield default value */
#define BFV_CONTROL_HFRC_OUTLOWHFRC(v)          ((((uint32_t) v) << (BFP_CONTROL_HFRC_OUTLOWHFRC)) & (BFM_CONTROL_HFRC_OUTLOWHFRC))
#define BFX_CONTROL_HFRC_OUTLOWHFRC(v)          ((((uint32_t) v) & (BFM_CONTROL_HFRC_OUTLOWHFRC)) >> (BFP_CONTROL_HFRC_OUTLOWHFRC))
#define BFW_CONTROL_HFRC_OUTLOWHFRC(v)          (REG_CONTROL_HFRC.U32 = ( (REG_CONTROL_HFRC.U32 & ~(BFM_CONTROL_HFRC_OUTLOWHFRC)) | ((((uint32_t) v)<<(BFP_CONTROL_HFRC_OUTLOWHFRC)) & (BFM_CONTROL_HFRC_OUTLOWHFRC)) ))
#define BFR_CONTROL_HFRC_OUTLOWHFRC()           ((REG_CONTROL_HFRC.U32 & (BFM_CONTROL_HFRC_OUTLOWHFRC))>>(BFP_CONTROL_HFRC_OUTLOWHFRC))

#define BFP_CONTROL_HFRC_TRIMCOEFFHFRC          (1)                     /* bitfield lsb */
#define BFM_CONTROL_HFRC_TRIMCOEFFHFRC          ((uint32_t)0x00000006)  /* bitfield mask */
#define BFN_CONTROL_HFRC_TRIMCOEFFHFRC          (2)                     /* bitfield width */
#define BFD_CONTROL_HFRC_TRIMCOEFFHFRC          (0x0)                   /* bitfield default value */
#define BFV_CONTROL_HFRC_TRIMCOEFFHFRC(v)       ((((uint32_t) v) << (BFP_CONTROL_HFRC_TRIMCOEFFHFRC)) & (BFM_CONTROL_HFRC_TRIMCOEFFHFRC))
#define BFX_CONTROL_HFRC_TRIMCOEFFHFRC(v)       ((((uint32_t) v) & (BFM_CONTROL_HFRC_TRIMCOEFFHFRC)) >> (BFP_CONTROL_HFRC_TRIMCOEFFHFRC))
#define BFW_CONTROL_HFRC_TRIMCOEFFHFRC(v)       (REG_CONTROL_HFRC.U32 = ( (REG_CONTROL_HFRC.U32 & ~(BFM_CONTROL_HFRC_TRIMCOEFFHFRC)) | ((((uint32_t) v)<<(BFP_CONTROL_HFRC_TRIMCOEFFHFRC)) & (BFM_CONTROL_HFRC_TRIMCOEFFHFRC)) ))
#define BFR_CONTROL_HFRC_TRIMCOEFFHFRC()        ((REG_CONTROL_HFRC.U32 & (BFM_CONTROL_HFRC_TRIMCOEFFHFRC))>>(BFP_CONTROL_HFRC_TRIMCOEFFHFRC))

#define BFP_CONTROL_HFRC_HFRCSWE                (0)                     /* bitfield lsb */
#define BFM_CONTROL_HFRC_HFRCSWE                ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_HFRC_HFRCSWE                (1)                     /* bitfield width */
#define BFD_CONTROL_HFRC_HFRCSWE                (0x0)                   /* bitfield default value */
#define BFV_CONTROL_HFRC_HFRCSWE(v)             ((((uint32_t) v) << (BFP_CONTROL_HFRC_HFRCSWE)) & (BFM_CONTROL_HFRC_HFRCSWE))
#define BFX_CONTROL_HFRC_HFRCSWE(v)             ((((uint32_t) v) & (BFM_CONTROL_HFRC_HFRCSWE)) >> (BFP_CONTROL_HFRC_HFRCSWE))
#define BFW_CONTROL_HFRC_HFRCSWE(v)             (REG_CONTROL_HFRC.U32 = ( (REG_CONTROL_HFRC.U32 & ~(BFM_CONTROL_HFRC_HFRCSWE)) | ((((uint32_t) v)<<(BFP_CONTROL_HFRC_HFRCSWE)) & (BFM_CONTROL_HFRC_HFRCSWE)) ))
#define BFR_CONTROL_HFRC_HFRCSWE()              ((REG_CONTROL_HFRC.U32 & (BFM_CONTROL_HFRC_HFRCSWE))>>(BFP_CONTROL_HFRC_HFRCSWE))


// *****************************************************************************
//                                                                             *
//  CONTROL_LFRC - LFRC Control                                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned RESETLFRC                  :  1;
        unsigned PWDLFRC                    :  1;
        unsigned TRIMTUNELFRC               :  5;
        unsigned LFRCSWE                    :  1;
    } B;
} reg_control_lfrc_t;

#define REG_CONTROL_LFRC_ADDR                   (REG_CONTROL_BASEADDR + 0x000000E0UL)
#define REG_CONTROL_LFRC                        (*(volatile reg_control_lfrc_t *) REG_CONTROL_LFRC_ADDR)
#define REG_CONTROL_LFRC_RD()                   (REG_CONTROL_LFRC.U32)
#define REG_CONTROL_LFRC_WR(v)                  (REG_CONTROL_LFRC.U32 = (v))
#define REG_CONTROL_LFRC_CLR(m)                 (REG_CONTROL_LFRC.U32 = ((REG_CONTROL_LFRC.U32) & ~(m)))
#define REG_CONTROL_LFRC_SET(m)                 (REG_CONTROL_LFRC.U32 = ((REG_CONTROL_LFRC.U32) | (m)))
#define REG_CONTROL_LFRC_DEF                    0x00000000

#define BFP_CONTROL_LFRC_RSVD_8                 (8)                     /* bitfield lsb */
#define BFM_CONTROL_LFRC_RSVD_8                 ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_CONTROL_LFRC_RSVD_8                 (24)                    /* bitfield width */
#define BFD_CONTROL_LFRC_RSVD_8                 (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LFRC_RSVD_8(v)              ((((uint32_t) v) << (BFP_CONTROL_LFRC_RSVD_8)) & (BFM_CONTROL_LFRC_RSVD_8))
#define BFX_CONTROL_LFRC_RSVD_8(v)              ((((uint32_t) v) & (BFM_CONTROL_LFRC_RSVD_8)) >> (BFP_CONTROL_LFRC_RSVD_8))
#define BFW_CONTROL_LFRC_RSVD_8(v)              (REG_CONTROL_LFRC.U32 = ( (REG_CONTROL_LFRC.U32 & ~(BFM_CONTROL_LFRC_RSVD_8)) | ((((uint32_t) v)<<(BFP_CONTROL_LFRC_RSVD_8)) & (BFM_CONTROL_LFRC_RSVD_8)) ))
#define BFR_CONTROL_LFRC_RSVD_8()               ((REG_CONTROL_LFRC.U32 & (BFM_CONTROL_LFRC_RSVD_8))>>(BFP_CONTROL_LFRC_RSVD_8))

#define BFP_CONTROL_LFRC_RESETLFRC              (7)                     /* bitfield lsb */
#define BFM_CONTROL_LFRC_RESETLFRC              ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_CONTROL_LFRC_RESETLFRC              (1)                     /* bitfield width */
#define BFD_CONTROL_LFRC_RESETLFRC              (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LFRC_RESETLFRC(v)           ((((uint32_t) v) << (BFP_CONTROL_LFRC_RESETLFRC)) & (BFM_CONTROL_LFRC_RESETLFRC))
#define BFX_CONTROL_LFRC_RESETLFRC(v)           ((((uint32_t) v) & (BFM_CONTROL_LFRC_RESETLFRC)) >> (BFP_CONTROL_LFRC_RESETLFRC))
#define BFW_CONTROL_LFRC_RESETLFRC(v)           (REG_CONTROL_LFRC.U32 = ( (REG_CONTROL_LFRC.U32 & ~(BFM_CONTROL_LFRC_RESETLFRC)) | ((((uint32_t) v)<<(BFP_CONTROL_LFRC_RESETLFRC)) & (BFM_CONTROL_LFRC_RESETLFRC)) ))
#define BFR_CONTROL_LFRC_RESETLFRC()            ((REG_CONTROL_LFRC.U32 & (BFM_CONTROL_LFRC_RESETLFRC))>>(BFP_CONTROL_LFRC_RESETLFRC))

#define BFP_CONTROL_LFRC_PWDLFRC                (6)                     /* bitfield lsb */
#define BFM_CONTROL_LFRC_PWDLFRC                ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_CONTROL_LFRC_PWDLFRC                (1)                     /* bitfield width */
#define BFD_CONTROL_LFRC_PWDLFRC                (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LFRC_PWDLFRC(v)             ((((uint32_t) v) << (BFP_CONTROL_LFRC_PWDLFRC)) & (BFM_CONTROL_LFRC_PWDLFRC))
#define BFX_CONTROL_LFRC_PWDLFRC(v)             ((((uint32_t) v) & (BFM_CONTROL_LFRC_PWDLFRC)) >> (BFP_CONTROL_LFRC_PWDLFRC))
#define BFW_CONTROL_LFRC_PWDLFRC(v)             (REG_CONTROL_LFRC.U32 = ( (REG_CONTROL_LFRC.U32 & ~(BFM_CONTROL_LFRC_PWDLFRC)) | ((((uint32_t) v)<<(BFP_CONTROL_LFRC_PWDLFRC)) & (BFM_CONTROL_LFRC_PWDLFRC)) ))
#define BFR_CONTROL_LFRC_PWDLFRC()              ((REG_CONTROL_LFRC.U32 & (BFM_CONTROL_LFRC_PWDLFRC))>>(BFP_CONTROL_LFRC_PWDLFRC))

#define BFP_CONTROL_LFRC_TRIMTUNELFRC           (1)                     /* bitfield lsb */
#define BFM_CONTROL_LFRC_TRIMTUNELFRC           ((uint32_t)0x0000003e)  /* bitfield mask */
#define BFN_CONTROL_LFRC_TRIMTUNELFRC           (5)                     /* bitfield width */
#define BFD_CONTROL_LFRC_TRIMTUNELFRC           (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LFRC_TRIMTUNELFRC(v)        ((((uint32_t) v) << (BFP_CONTROL_LFRC_TRIMTUNELFRC)) & (BFM_CONTROL_LFRC_TRIMTUNELFRC))
#define BFX_CONTROL_LFRC_TRIMTUNELFRC(v)        ((((uint32_t) v) & (BFM_CONTROL_LFRC_TRIMTUNELFRC)) >> (BFP_CONTROL_LFRC_TRIMTUNELFRC))
#define BFW_CONTROL_LFRC_TRIMTUNELFRC(v)        (REG_CONTROL_LFRC.U32 = ( (REG_CONTROL_LFRC.U32 & ~(BFM_CONTROL_LFRC_TRIMTUNELFRC)) | ((((uint32_t) v)<<(BFP_CONTROL_LFRC_TRIMTUNELFRC)) & (BFM_CONTROL_LFRC_TRIMTUNELFRC)) ))
#define BFR_CONTROL_LFRC_TRIMTUNELFRC()         ((REG_CONTROL_LFRC.U32 & (BFM_CONTROL_LFRC_TRIMTUNELFRC))>>(BFP_CONTROL_LFRC_TRIMTUNELFRC))

#define BFP_CONTROL_LFRC_LFRCSWE                (0)                     /* bitfield lsb */
#define BFM_CONTROL_LFRC_LFRCSWE                ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_LFRC_LFRCSWE                (1)                     /* bitfield width */
#define BFD_CONTROL_LFRC_LFRCSWE                (0x0)                   /* bitfield default value */
#define BFV_CONTROL_LFRC_LFRCSWE(v)             ((((uint32_t) v) << (BFP_CONTROL_LFRC_LFRCSWE)) & (BFM_CONTROL_LFRC_LFRCSWE))
#define BFX_CONTROL_LFRC_LFRCSWE(v)             ((((uint32_t) v) & (BFM_CONTROL_LFRC_LFRCSWE)) >> (BFP_CONTROL_LFRC_LFRCSWE))
#define BFW_CONTROL_LFRC_LFRCSWE(v)             (REG_CONTROL_LFRC.U32 = ( (REG_CONTROL_LFRC.U32 & ~(BFM_CONTROL_LFRC_LFRCSWE)) | ((((uint32_t) v)<<(BFP_CONTROL_LFRC_LFRCSWE)) & (BFM_CONTROL_LFRC_LFRCSWE)) ))
#define BFR_CONTROL_LFRC_LFRCSWE()              ((REG_CONTROL_LFRC.U32 & (BFM_CONTROL_LFRC_LFRCSWE))>>(BFP_CONTROL_LFRC_LFRCSWE))


// *****************************************************************************
//                                                                             *
//  CONTROL_BANDGAPEN - Band Gap Enable                                        *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_1                     : 31;
        unsigned BGPEN                      :  1;
    } B;
} reg_control_bandgapen_t;

#define REG_CONTROL_BANDGAPEN_ADDR              (REG_CONTROL_BASEADDR + 0x000000FCUL)
#define REG_CONTROL_BANDGAPEN                   (*(volatile reg_control_bandgapen_t *) REG_CONTROL_BANDGAPEN_ADDR)
#define REG_CONTROL_BANDGAPEN_RD()              (REG_CONTROL_BANDGAPEN.U32)
#define REG_CONTROL_BANDGAPEN_WR(v)             (REG_CONTROL_BANDGAPEN.U32 = (v))
#define REG_CONTROL_BANDGAPEN_CLR(m)            (REG_CONTROL_BANDGAPEN.U32 = ((REG_CONTROL_BANDGAPEN.U32) & ~(m)))
#define REG_CONTROL_BANDGAPEN_SET(m)            (REG_CONTROL_BANDGAPEN.U32 = ((REG_CONTROL_BANDGAPEN.U32) | (m)))
#define REG_CONTROL_BANDGAPEN_DEF               0x00000000

#define BFP_CONTROL_BANDGAPEN_RSVD_1            (1)                     /* bitfield lsb */
#define BFM_CONTROL_BANDGAPEN_RSVD_1            ((uint32_t)0xfffffffe)  /* bitfield mask */
#define BFN_CONTROL_BANDGAPEN_RSVD_1            (31)                    /* bitfield width */
#define BFD_CONTROL_BANDGAPEN_RSVD_1            (0x0)                   /* bitfield default value */
#define BFV_CONTROL_BANDGAPEN_RSVD_1(v)         ((((uint32_t) v) << (BFP_CONTROL_BANDGAPEN_RSVD_1)) & (BFM_CONTROL_BANDGAPEN_RSVD_1))
#define BFX_CONTROL_BANDGAPEN_RSVD_1(v)         ((((uint32_t) v) & (BFM_CONTROL_BANDGAPEN_RSVD_1)) >> (BFP_CONTROL_BANDGAPEN_RSVD_1))
#define BFW_CONTROL_BANDGAPEN_RSVD_1(v)         (REG_CONTROL_BANDGAPEN.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_BANDGAPEN_RSVD_1)) & (BFM_CONTROL_BANDGAPEN_RSVD_1)) )
#define BFR_CONTROL_BANDGAPEN_RSVD_1()          ((REG_CONTROL_BANDGAPEN.U32 & (BFM_CONTROL_BANDGAPEN_RSVD_1))>>(BFP_CONTROL_BANDGAPEN_RSVD_1))

#define BFP_CONTROL_BANDGAPEN_BGPEN             (0)                     /* bitfield lsb */
#define BFM_CONTROL_BANDGAPEN_BGPEN             ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_BANDGAPEN_BGPEN             (1)                     /* bitfield width */
#define BFD_CONTROL_BANDGAPEN_BGPEN             (0x0)                   /* bitfield default value */
#define BFV_CONTROL_BANDGAPEN_BGPEN(v)          ((((uint32_t) v) << (BFP_CONTROL_BANDGAPEN_BGPEN)) & (BFM_CONTROL_BANDGAPEN_BGPEN))
#define BFX_CONTROL_BANDGAPEN_BGPEN(v)          ((((uint32_t) v) & (BFM_CONTROL_BANDGAPEN_BGPEN)) >> (BFP_CONTROL_BANDGAPEN_BGPEN))
#define BFW_CONTROL_BANDGAPEN_BGPEN(v)          (REG_CONTROL_BANDGAPEN.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_BANDGAPEN_BGPEN)) & (BFM_CONTROL_BANDGAPEN_BGPEN)) )
#define BFR_CONTROL_BANDGAPEN_BGPEN()           ((REG_CONTROL_BANDGAPEN.U32 & (BFM_CONTROL_BANDGAPEN_BGPEN))>>(BFP_CONTROL_BANDGAPEN_BGPEN))


// *****************************************************************************
//                                                                             *
//  CONTROL_TEMPSCTRL - Temp Sensor Control                                    *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned BGTRIM                     :  4;
        unsigned TSTRIM                     :  4;
    } B;
} reg_control_tempsctrl_t;

#define REG_CONTROL_TEMPSCTRL_ADDR              (REG_CONTROL_BASEADDR + 0x00000100UL)
#define REG_CONTROL_TEMPSCTRL                   (*(volatile reg_control_tempsctrl_t *) REG_CONTROL_TEMPSCTRL_ADDR)
#define REG_CONTROL_TEMPSCTRL_RD()              (REG_CONTROL_TEMPSCTRL.U32)
#define REG_CONTROL_TEMPSCTRL_WR(v)             (REG_CONTROL_TEMPSCTRL.U32 = (v))
#define REG_CONTROL_TEMPSCTRL_CLR(m)            (REG_CONTROL_TEMPSCTRL.U32 = ((REG_CONTROL_TEMPSCTRL.U32) & ~(m)))
#define REG_CONTROL_TEMPSCTRL_SET(m)            (REG_CONTROL_TEMPSCTRL.U32 = ((REG_CONTROL_TEMPSCTRL.U32) | (m)))
#define REG_CONTROL_TEMPSCTRL_DEF               0x00000000

#define BFP_CONTROL_TEMPSCTRL_RSVD_8            (8)                     /* bitfield lsb */
#define BFM_CONTROL_TEMPSCTRL_RSVD_8            ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_CONTROL_TEMPSCTRL_RSVD_8            (24)                    /* bitfield width */
#define BFD_CONTROL_TEMPSCTRL_RSVD_8            (0x0)                   /* bitfield default value */
#define BFV_CONTROL_TEMPSCTRL_RSVD_8(v)         ((((uint32_t) v) << (BFP_CONTROL_TEMPSCTRL_RSVD_8)) & (BFM_CONTROL_TEMPSCTRL_RSVD_8))
#define BFX_CONTROL_TEMPSCTRL_RSVD_8(v)         ((((uint32_t) v) & (BFM_CONTROL_TEMPSCTRL_RSVD_8)) >> (BFP_CONTROL_TEMPSCTRL_RSVD_8))
#define BFW_CONTROL_TEMPSCTRL_RSVD_8(v)         (REG_CONTROL_TEMPSCTRL.U32 = ( (REG_CONTROL_TEMPSCTRL.U32 & ~(BFM_CONTROL_TEMPSCTRL_RSVD_8)) | ((((uint32_t) v)<<(BFP_CONTROL_TEMPSCTRL_RSVD_8)) & (BFM_CONTROL_TEMPSCTRL_RSVD_8)) ))
#define BFR_CONTROL_TEMPSCTRL_RSVD_8()          ((REG_CONTROL_TEMPSCTRL.U32 & (BFM_CONTROL_TEMPSCTRL_RSVD_8))>>(BFP_CONTROL_TEMPSCTRL_RSVD_8))

#define BFP_CONTROL_TEMPSCTRL_BGTRIM            (4)                     /* bitfield lsb */
#define BFM_CONTROL_TEMPSCTRL_BGTRIM            ((uint32_t)0x000000f0)  /* bitfield mask */
#define BFN_CONTROL_TEMPSCTRL_BGTRIM            (4)                     /* bitfield width */
#define BFD_CONTROL_TEMPSCTRL_BGTRIM            (0x0)                   /* bitfield default value */
#define BFV_CONTROL_TEMPSCTRL_BGTRIM(v)         ((((uint32_t) v) << (BFP_CONTROL_TEMPSCTRL_BGTRIM)) & (BFM_CONTROL_TEMPSCTRL_BGTRIM))
#define BFX_CONTROL_TEMPSCTRL_BGTRIM(v)         ((((uint32_t) v) & (BFM_CONTROL_TEMPSCTRL_BGTRIM)) >> (BFP_CONTROL_TEMPSCTRL_BGTRIM))
#define BFW_CONTROL_TEMPSCTRL_BGTRIM(v)         (REG_CONTROL_TEMPSCTRL.U32 = ( (REG_CONTROL_TEMPSCTRL.U32 & ~(BFM_CONTROL_TEMPSCTRL_BGTRIM)) | ((((uint32_t) v)<<(BFP_CONTROL_TEMPSCTRL_BGTRIM)) & (BFM_CONTROL_TEMPSCTRL_BGTRIM)) ))
#define BFR_CONTROL_TEMPSCTRL_BGTRIM()          ((REG_CONTROL_TEMPSCTRL.U32 & (BFM_CONTROL_TEMPSCTRL_BGTRIM))>>(BFP_CONTROL_TEMPSCTRL_BGTRIM))

#define BFP_CONTROL_TEMPSCTRL_TSTRIM            (0)                     /* bitfield lsb */
#define BFM_CONTROL_TEMPSCTRL_TSTRIM            ((uint32_t)0x0000000f)  /* bitfield mask */
#define BFN_CONTROL_TEMPSCTRL_TSTRIM            (4)                     /* bitfield width */
#define BFD_CONTROL_TEMPSCTRL_TSTRIM            (0x0)                   /* bitfield default value */
#define BFV_CONTROL_TEMPSCTRL_TSTRIM(v)         ((((uint32_t) v) << (BFP_CONTROL_TEMPSCTRL_TSTRIM)) & (BFM_CONTROL_TEMPSCTRL_TSTRIM))
#define BFX_CONTROL_TEMPSCTRL_TSTRIM(v)         ((((uint32_t) v) & (BFM_CONTROL_TEMPSCTRL_TSTRIM)) >> (BFP_CONTROL_TEMPSCTRL_TSTRIM))
#define BFW_CONTROL_TEMPSCTRL_TSTRIM(v)         (REG_CONTROL_TEMPSCTRL.U32 = ( (REG_CONTROL_TEMPSCTRL.U32 & ~(BFM_CONTROL_TEMPSCTRL_TSTRIM)) | ((((uint32_t) v)<<(BFP_CONTROL_TEMPSCTRL_TSTRIM)) & (BFM_CONTROL_TEMPSCTRL_TSTRIM)) ))
#define BFR_CONTROL_TEMPSCTRL_TSTRIM()          ((REG_CONTROL_TEMPSCTRL.U32 & (BFM_CONTROL_TEMPSCTRL_TSTRIM))>>(BFP_CONTROL_TEMPSCTRL_TSTRIM))


// *****************************************************************************
//                                                                             *
//  CONTROL_XTALCTRL - XTAL Oscillator Control                                 *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_12                    : 20;
        unsigned PWDCMPRXTAL                :  1;
        unsigned PWDCOREXTAL                :  1;
        unsigned ACWARMUP                   :  2;
        unsigned BYPCMPRXTAL                :  1;
        unsigned FDBKDSBLXTAL               :  1;
        unsigned TRIMCOREBXTAL              :  5;
        unsigned XTALSWE                    :  1;
    } B;
} reg_control_xtalctrl_t;

#define REG_CONTROL_XTALCTRL_ADDR               (REG_CONTROL_BASEADDR + 0x00000120UL)
#define REG_CONTROL_XTALCTRL                    (*(volatile reg_control_xtalctrl_t *) REG_CONTROL_XTALCTRL_ADDR)
#define REG_CONTROL_XTALCTRL_RD()               (REG_CONTROL_XTALCTRL.U32)
#define REG_CONTROL_XTALCTRL_WR(v)              (REG_CONTROL_XTALCTRL.U32 = (v))
#define REG_CONTROL_XTALCTRL_CLR(m)             (REG_CONTROL_XTALCTRL.U32 = ((REG_CONTROL_XTALCTRL.U32) & ~(m)))
#define REG_CONTROL_XTALCTRL_SET(m)             (REG_CONTROL_XTALCTRL.U32 = ((REG_CONTROL_XTALCTRL.U32) | (m)))
#define REG_CONTROL_XTALCTRL_DEF                0x00000000

#define BFP_CONTROL_XTALCTRL_RSVD_12            (12)                    /* bitfield lsb */
#define BFM_CONTROL_XTALCTRL_RSVD_12            ((uint32_t)0xfffff000)  /* bitfield mask */
#define BFN_CONTROL_XTALCTRL_RSVD_12            (20)                    /* bitfield width */
#define BFD_CONTROL_XTALCTRL_RSVD_12            (0x0)                   /* bitfield default value */
#define BFV_CONTROL_XTALCTRL_RSVD_12(v)         ((((uint32_t) v) << (BFP_CONTROL_XTALCTRL_RSVD_12)) & (BFM_CONTROL_XTALCTRL_RSVD_12))
#define BFX_CONTROL_XTALCTRL_RSVD_12(v)         ((((uint32_t) v) & (BFM_CONTROL_XTALCTRL_RSVD_12)) >> (BFP_CONTROL_XTALCTRL_RSVD_12))
#define BFW_CONTROL_XTALCTRL_RSVD_12(v)         (REG_CONTROL_XTALCTRL.U32 = ( (REG_CONTROL_XTALCTRL.U32 & ~(BFM_CONTROL_XTALCTRL_RSVD_12)) | ((((uint32_t) v)<<(BFP_CONTROL_XTALCTRL_RSVD_12)) & (BFM_CONTROL_XTALCTRL_RSVD_12)) ))
#define BFR_CONTROL_XTALCTRL_RSVD_12()          ((REG_CONTROL_XTALCTRL.U32 & (BFM_CONTROL_XTALCTRL_RSVD_12))>>(BFP_CONTROL_XTALCTRL_RSVD_12))

#define BFP_CONTROL_XTALCTRL_PWDCMPRXTAL        (11)                    /* bitfield lsb */
#define BFM_CONTROL_XTALCTRL_PWDCMPRXTAL        ((uint32_t)0x00000800)  /* bitfield mask */
#define BFN_CONTROL_XTALCTRL_PWDCMPRXTAL        (1)                     /* bitfield width */
#define BFD_CONTROL_XTALCTRL_PWDCMPRXTAL        (0x0)                   /* bitfield default value */
#define BFV_CONTROL_XTALCTRL_PWDCMPRXTAL(v)     ((((uint32_t) v) << (BFP_CONTROL_XTALCTRL_PWDCMPRXTAL)) & (BFM_CONTROL_XTALCTRL_PWDCMPRXTAL))
#define BFX_CONTROL_XTALCTRL_PWDCMPRXTAL(v)     ((((uint32_t) v) & (BFM_CONTROL_XTALCTRL_PWDCMPRXTAL)) >> (BFP_CONTROL_XTALCTRL_PWDCMPRXTAL))
#define BFW_CONTROL_XTALCTRL_PWDCMPRXTAL(v)     (REG_CONTROL_XTALCTRL.U32 = ( (REG_CONTROL_XTALCTRL.U32 & ~(BFM_CONTROL_XTALCTRL_PWDCMPRXTAL)) | ((((uint32_t) v)<<(BFP_CONTROL_XTALCTRL_PWDCMPRXTAL)) & (BFM_CONTROL_XTALCTRL_PWDCMPRXTAL)) ))
#define BFR_CONTROL_XTALCTRL_PWDCMPRXTAL()      ((REG_CONTROL_XTALCTRL.U32 & (BFM_CONTROL_XTALCTRL_PWDCMPRXTAL))>>(BFP_CONTROL_XTALCTRL_PWDCMPRXTAL))

#define BFP_CONTROL_XTALCTRL_PWDCOREXTAL        (10)                    /* bitfield lsb */
#define BFM_CONTROL_XTALCTRL_PWDCOREXTAL        ((uint32_t)0x00000400)  /* bitfield mask */
#define BFN_CONTROL_XTALCTRL_PWDCOREXTAL        (1)                     /* bitfield width */
#define BFD_CONTROL_XTALCTRL_PWDCOREXTAL        (0x0)                   /* bitfield default value */
#define BFV_CONTROL_XTALCTRL_PWDCOREXTAL(v)     ((((uint32_t) v) << (BFP_CONTROL_XTALCTRL_PWDCOREXTAL)) & (BFM_CONTROL_XTALCTRL_PWDCOREXTAL))
#define BFX_CONTROL_XTALCTRL_PWDCOREXTAL(v)     ((((uint32_t) v) & (BFM_CONTROL_XTALCTRL_PWDCOREXTAL)) >> (BFP_CONTROL_XTALCTRL_PWDCOREXTAL))
#define BFW_CONTROL_XTALCTRL_PWDCOREXTAL(v)     (REG_CONTROL_XTALCTRL.U32 = ( (REG_CONTROL_XTALCTRL.U32 & ~(BFM_CONTROL_XTALCTRL_PWDCOREXTAL)) | ((((uint32_t) v)<<(BFP_CONTROL_XTALCTRL_PWDCOREXTAL)) & (BFM_CONTROL_XTALCTRL_PWDCOREXTAL)) ))
#define BFR_CONTROL_XTALCTRL_PWDCOREXTAL()      ((REG_CONTROL_XTALCTRL.U32 & (BFM_CONTROL_XTALCTRL_PWDCOREXTAL))>>(BFP_CONTROL_XTALCTRL_PWDCOREXTAL))

#define BFP_CONTROL_XTALCTRL_ACWARMUP           (8)                     /* bitfield lsb */
#define BFM_CONTROL_XTALCTRL_ACWARMUP           ((uint32_t)0x00000300)  /* bitfield mask */
#define BFN_CONTROL_XTALCTRL_ACWARMUP           (2)                     /* bitfield width */
#define BFD_CONTROL_XTALCTRL_ACWARMUP           (0x0)                   /* bitfield default value */
#define BFV_CONTROL_XTALCTRL_ACWARMUP(v)        ((((uint32_t) v) << (BFP_CONTROL_XTALCTRL_ACWARMUP)) & (BFM_CONTROL_XTALCTRL_ACWARMUP))
#define BFX_CONTROL_XTALCTRL_ACWARMUP(v)        ((((uint32_t) v) & (BFM_CONTROL_XTALCTRL_ACWARMUP)) >> (BFP_CONTROL_XTALCTRL_ACWARMUP))
#define BFW_CONTROL_XTALCTRL_ACWARMUP(v)        (REG_CONTROL_XTALCTRL.U32 = ( (REG_CONTROL_XTALCTRL.U32 & ~(BFM_CONTROL_XTALCTRL_ACWARMUP)) | ((((uint32_t) v)<<(BFP_CONTROL_XTALCTRL_ACWARMUP)) & (BFM_CONTROL_XTALCTRL_ACWARMUP)) ))
#define BFR_CONTROL_XTALCTRL_ACWARMUP()         ((REG_CONTROL_XTALCTRL.U32 & (BFM_CONTROL_XTALCTRL_ACWARMUP))>>(BFP_CONTROL_XTALCTRL_ACWARMUP))

#define BFP_CONTROL_XTALCTRL_BYPCMPRXTAL        (7)                     /* bitfield lsb */
#define BFM_CONTROL_XTALCTRL_BYPCMPRXTAL        ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_CONTROL_XTALCTRL_BYPCMPRXTAL        (1)                     /* bitfield width */
#define BFD_CONTROL_XTALCTRL_BYPCMPRXTAL        (0x0)                   /* bitfield default value */
#define BFV_CONTROL_XTALCTRL_BYPCMPRXTAL(v)     ((((uint32_t) v) << (BFP_CONTROL_XTALCTRL_BYPCMPRXTAL)) & (BFM_CONTROL_XTALCTRL_BYPCMPRXTAL))
#define BFX_CONTROL_XTALCTRL_BYPCMPRXTAL(v)     ((((uint32_t) v) & (BFM_CONTROL_XTALCTRL_BYPCMPRXTAL)) >> (BFP_CONTROL_XTALCTRL_BYPCMPRXTAL))
#define BFW_CONTROL_XTALCTRL_BYPCMPRXTAL(v)     (REG_CONTROL_XTALCTRL.U32 = ( (REG_CONTROL_XTALCTRL.U32 & ~(BFM_CONTROL_XTALCTRL_BYPCMPRXTAL)) | ((((uint32_t) v)<<(BFP_CONTROL_XTALCTRL_BYPCMPRXTAL)) & (BFM_CONTROL_XTALCTRL_BYPCMPRXTAL)) ))
#define BFR_CONTROL_XTALCTRL_BYPCMPRXTAL()      ((REG_CONTROL_XTALCTRL.U32 & (BFM_CONTROL_XTALCTRL_BYPCMPRXTAL))>>(BFP_CONTROL_XTALCTRL_BYPCMPRXTAL))

#define BFP_CONTROL_XTALCTRL_FDBKDSBLXTAL       (6)                     /* bitfield lsb */
#define BFM_CONTROL_XTALCTRL_FDBKDSBLXTAL       ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_CONTROL_XTALCTRL_FDBKDSBLXTAL       (1)                     /* bitfield width */
#define BFD_CONTROL_XTALCTRL_FDBKDSBLXTAL       (0x0)                   /* bitfield default value */
#define BFV_CONTROL_XTALCTRL_FDBKDSBLXTAL(v)    ((((uint32_t) v) << (BFP_CONTROL_XTALCTRL_FDBKDSBLXTAL)) & (BFM_CONTROL_XTALCTRL_FDBKDSBLXTAL))
#define BFX_CONTROL_XTALCTRL_FDBKDSBLXTAL(v)    ((((uint32_t) v) & (BFM_CONTROL_XTALCTRL_FDBKDSBLXTAL)) >> (BFP_CONTROL_XTALCTRL_FDBKDSBLXTAL))
#define BFW_CONTROL_XTALCTRL_FDBKDSBLXTAL(v)    (REG_CONTROL_XTALCTRL.U32 = ( (REG_CONTROL_XTALCTRL.U32 & ~(BFM_CONTROL_XTALCTRL_FDBKDSBLXTAL)) | ((((uint32_t) v)<<(BFP_CONTROL_XTALCTRL_FDBKDSBLXTAL)) & (BFM_CONTROL_XTALCTRL_FDBKDSBLXTAL)) ))
#define BFR_CONTROL_XTALCTRL_FDBKDSBLXTAL()     ((REG_CONTROL_XTALCTRL.U32 & (BFM_CONTROL_XTALCTRL_FDBKDSBLXTAL))>>(BFP_CONTROL_XTALCTRL_FDBKDSBLXTAL))

#define BFP_CONTROL_XTALCTRL_TRIMCOREBXTAL      (1)                     /* bitfield lsb */
#define BFM_CONTROL_XTALCTRL_TRIMCOREBXTAL      ((uint32_t)0x0000003e)  /* bitfield mask */
#define BFN_CONTROL_XTALCTRL_TRIMCOREBXTAL      (5)                     /* bitfield width */
#define BFD_CONTROL_XTALCTRL_TRIMCOREBXTAL      (0x0)                   /* bitfield default value */
#define BFV_CONTROL_XTALCTRL_TRIMCOREBXTAL(v)   ((((uint32_t) v) << (BFP_CONTROL_XTALCTRL_TRIMCOREBXTAL)) & (BFM_CONTROL_XTALCTRL_TRIMCOREBXTAL))
#define BFX_CONTROL_XTALCTRL_TRIMCOREBXTAL(v)   ((((uint32_t) v) & (BFM_CONTROL_XTALCTRL_TRIMCOREBXTAL)) >> (BFP_CONTROL_XTALCTRL_TRIMCOREBXTAL))
#define BFW_CONTROL_XTALCTRL_TRIMCOREBXTAL(v)   (REG_CONTROL_XTALCTRL.U32 = ( (REG_CONTROL_XTALCTRL.U32 & ~(BFM_CONTROL_XTALCTRL_TRIMCOREBXTAL)) | ((((uint32_t) v)<<(BFP_CONTROL_XTALCTRL_TRIMCOREBXTAL)) & (BFM_CONTROL_XTALCTRL_TRIMCOREBXTAL)) ))
#define BFR_CONTROL_XTALCTRL_TRIMCOREBXTAL()    ((REG_CONTROL_XTALCTRL.U32 & (BFM_CONTROL_XTALCTRL_TRIMCOREBXTAL))>>(BFP_CONTROL_XTALCTRL_TRIMCOREBXTAL))

#define BFP_CONTROL_XTALCTRL_XTALSWE            (0)                     /* bitfield lsb */
#define BFM_CONTROL_XTALCTRL_XTALSWE            ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_XTALCTRL_XTALSWE            (1)                     /* bitfield width */
#define BFD_CONTROL_XTALCTRL_XTALSWE            (0x0)                   /* bitfield default value */
#define BFV_CONTROL_XTALCTRL_XTALSWE(v)         ((((uint32_t) v) << (BFP_CONTROL_XTALCTRL_XTALSWE)) & (BFM_CONTROL_XTALCTRL_XTALSWE))
#define BFX_CONTROL_XTALCTRL_XTALSWE(v)         ((((uint32_t) v) & (BFM_CONTROL_XTALCTRL_XTALSWE)) >> (BFP_CONTROL_XTALCTRL_XTALSWE))
#define BFW_CONTROL_XTALCTRL_XTALSWE(v)         (REG_CONTROL_XTALCTRL.U32 = ( (REG_CONTROL_XTALCTRL.U32 & ~(BFM_CONTROL_XTALCTRL_XTALSWE)) | ((((uint32_t) v)<<(BFP_CONTROL_XTALCTRL_XTALSWE)) & (BFM_CONTROL_XTALCTRL_XTALSWE)) ))
#define BFR_CONTROL_XTALCTRL_XTALSWE()          ((REG_CONTROL_XTALCTRL.U32 & (BFM_CONTROL_XTALCTRL_XTALSWE))>>(BFP_CONTROL_XTALCTRL_XTALSWE))


// *****************************************************************************
//                                                                             *
//  CONTROL_SRAMPWDINSLEEP - Powerdown an SRAM Bank in Deep Sleep mode         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned BANK7PWDINSLEEP            :  1;
        unsigned BANK6PWDINSLEEP            :  1;
        unsigned BANK5PWDINSLEEP            :  1;
        unsigned BANK4PWDINSLEEP            :  1;
        unsigned BANK3PWDINSLEEP            :  1;
        unsigned BANK2PWDINSLEEP            :  1;
        unsigned BANK1PWDINSLEEP            :  1;
        unsigned BANK0PWDINSLEEP            :  1;
    } B;
} reg_control_srampwdinsleep_t;

#define REG_CONTROL_SRAMPWDINSLEEP_ADDR         (REG_CONTROL_BASEADDR + 0x00000140UL)
#define REG_CONTROL_SRAMPWDINSLEEP              (*(volatile reg_control_srampwdinsleep_t *) REG_CONTROL_SRAMPWDINSLEEP_ADDR)
#define REG_CONTROL_SRAMPWDINSLEEP_RD()         (REG_CONTROL_SRAMPWDINSLEEP.U32)
#define REG_CONTROL_SRAMPWDINSLEEP_WR(v)        (REG_CONTROL_SRAMPWDINSLEEP.U32 = (v))
#define REG_CONTROL_SRAMPWDINSLEEP_CLR(m)       (REG_CONTROL_SRAMPWDINSLEEP.U32 = ((REG_CONTROL_SRAMPWDINSLEEP.U32) & ~(m)))
#define REG_CONTROL_SRAMPWDINSLEEP_SET(m)       (REG_CONTROL_SRAMPWDINSLEEP.U32 = ((REG_CONTROL_SRAMPWDINSLEEP.U32) | (m)))
#define REG_CONTROL_SRAMPWDINSLEEP_DEF          0x00000000

#define BFP_CONTROL_SRAMPWDINSLEEP_RSVD_8       (8)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWDINSLEEP_RSVD_8       ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWDINSLEEP_RSVD_8       (24)                    /* bitfield width */
#define BFD_CONTROL_SRAMPWDINSLEEP_RSVD_8       (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWDINSLEEP_RSVD_8(v)    ((((uint32_t) v) << (BFP_CONTROL_SRAMPWDINSLEEP_RSVD_8)) & (BFM_CONTROL_SRAMPWDINSLEEP_RSVD_8))
#define BFX_CONTROL_SRAMPWDINSLEEP_RSVD_8(v)    ((((uint32_t) v) & (BFM_CONTROL_SRAMPWDINSLEEP_RSVD_8)) >> (BFP_CONTROL_SRAMPWDINSLEEP_RSVD_8))
#define BFW_CONTROL_SRAMPWDINSLEEP_RSVD_8(v)    (REG_CONTROL_SRAMPWDINSLEEP.U32 = ( (REG_CONTROL_SRAMPWDINSLEEP.U32 & ~(BFM_CONTROL_SRAMPWDINSLEEP_RSVD_8)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWDINSLEEP_RSVD_8)) & (BFM_CONTROL_SRAMPWDINSLEEP_RSVD_8)) ))
#define BFR_CONTROL_SRAMPWDINSLEEP_RSVD_8()     ((REG_CONTROL_SRAMPWDINSLEEP.U32 & (BFM_CONTROL_SRAMPWDINSLEEP_RSVD_8))>>(BFP_CONTROL_SRAMPWDINSLEEP_RSVD_8))

#define BFP_CONTROL_SRAMPWDINSLEEP_BANK7PWDINSLEEP (7)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWDINSLEEP_BANK7PWDINSLEEP ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWDINSLEEP_BANK7PWDINSLEEP (1)                     /* bitfield width */
#define BFD_CONTROL_SRAMPWDINSLEEP_BANK7PWDINSLEEP (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWDINSLEEP_BANK7PWDINSLEEP(v) ((((uint32_t) v) << (BFP_CONTROL_SRAMPWDINSLEEP_BANK7PWDINSLEEP)) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK7PWDINSLEEP))
#define BFX_CONTROL_SRAMPWDINSLEEP_BANK7PWDINSLEEP(v) ((((uint32_t) v) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK7PWDINSLEEP)) >> (BFP_CONTROL_SRAMPWDINSLEEP_BANK7PWDINSLEEP))
#define BFW_CONTROL_SRAMPWDINSLEEP_BANK7PWDINSLEEP(v) (REG_CONTROL_SRAMPWDINSLEEP.U32 = ( (REG_CONTROL_SRAMPWDINSLEEP.U32 & ~(BFM_CONTROL_SRAMPWDINSLEEP_BANK7PWDINSLEEP)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWDINSLEEP_BANK7PWDINSLEEP)) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK7PWDINSLEEP)) ))
#define BFR_CONTROL_SRAMPWDINSLEEP_BANK7PWDINSLEEP() ((REG_CONTROL_SRAMPWDINSLEEP.U32 & (BFM_CONTROL_SRAMPWDINSLEEP_BANK7PWDINSLEEP))>>(BFP_CONTROL_SRAMPWDINSLEEP_BANK7PWDINSLEEP))

#define BFP_CONTROL_SRAMPWDINSLEEP_BANK6PWDINSLEEP (6)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWDINSLEEP_BANK6PWDINSLEEP ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWDINSLEEP_BANK6PWDINSLEEP (1)                     /* bitfield width */
#define BFD_CONTROL_SRAMPWDINSLEEP_BANK6PWDINSLEEP (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWDINSLEEP_BANK6PWDINSLEEP(v) ((((uint32_t) v) << (BFP_CONTROL_SRAMPWDINSLEEP_BANK6PWDINSLEEP)) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK6PWDINSLEEP))
#define BFX_CONTROL_SRAMPWDINSLEEP_BANK6PWDINSLEEP(v) ((((uint32_t) v) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK6PWDINSLEEP)) >> (BFP_CONTROL_SRAMPWDINSLEEP_BANK6PWDINSLEEP))
#define BFW_CONTROL_SRAMPWDINSLEEP_BANK6PWDINSLEEP(v) (REG_CONTROL_SRAMPWDINSLEEP.U32 = ( (REG_CONTROL_SRAMPWDINSLEEP.U32 & ~(BFM_CONTROL_SRAMPWDINSLEEP_BANK6PWDINSLEEP)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWDINSLEEP_BANK6PWDINSLEEP)) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK6PWDINSLEEP)) ))
#define BFR_CONTROL_SRAMPWDINSLEEP_BANK6PWDINSLEEP() ((REG_CONTROL_SRAMPWDINSLEEP.U32 & (BFM_CONTROL_SRAMPWDINSLEEP_BANK6PWDINSLEEP))>>(BFP_CONTROL_SRAMPWDINSLEEP_BANK6PWDINSLEEP))

#define BFP_CONTROL_SRAMPWDINSLEEP_BANK5PWDINSLEEP (5)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWDINSLEEP_BANK5PWDINSLEEP ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWDINSLEEP_BANK5PWDINSLEEP (1)                     /* bitfield width */
#define BFD_CONTROL_SRAMPWDINSLEEP_BANK5PWDINSLEEP (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWDINSLEEP_BANK5PWDINSLEEP(v) ((((uint32_t) v) << (BFP_CONTROL_SRAMPWDINSLEEP_BANK5PWDINSLEEP)) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK5PWDINSLEEP))
#define BFX_CONTROL_SRAMPWDINSLEEP_BANK5PWDINSLEEP(v) ((((uint32_t) v) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK5PWDINSLEEP)) >> (BFP_CONTROL_SRAMPWDINSLEEP_BANK5PWDINSLEEP))
#define BFW_CONTROL_SRAMPWDINSLEEP_BANK5PWDINSLEEP(v) (REG_CONTROL_SRAMPWDINSLEEP.U32 = ( (REG_CONTROL_SRAMPWDINSLEEP.U32 & ~(BFM_CONTROL_SRAMPWDINSLEEP_BANK5PWDINSLEEP)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWDINSLEEP_BANK5PWDINSLEEP)) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK5PWDINSLEEP)) ))
#define BFR_CONTROL_SRAMPWDINSLEEP_BANK5PWDINSLEEP() ((REG_CONTROL_SRAMPWDINSLEEP.U32 & (BFM_CONTROL_SRAMPWDINSLEEP_BANK5PWDINSLEEP))>>(BFP_CONTROL_SRAMPWDINSLEEP_BANK5PWDINSLEEP))

#define BFP_CONTROL_SRAMPWDINSLEEP_BANK4PWDINSLEEP (4)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWDINSLEEP_BANK4PWDINSLEEP ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWDINSLEEP_BANK4PWDINSLEEP (1)                     /* bitfield width */
#define BFD_CONTROL_SRAMPWDINSLEEP_BANK4PWDINSLEEP (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWDINSLEEP_BANK4PWDINSLEEP(v) ((((uint32_t) v) << (BFP_CONTROL_SRAMPWDINSLEEP_BANK4PWDINSLEEP)) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK4PWDINSLEEP))
#define BFX_CONTROL_SRAMPWDINSLEEP_BANK4PWDINSLEEP(v) ((((uint32_t) v) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK4PWDINSLEEP)) >> (BFP_CONTROL_SRAMPWDINSLEEP_BANK4PWDINSLEEP))
#define BFW_CONTROL_SRAMPWDINSLEEP_BANK4PWDINSLEEP(v) (REG_CONTROL_SRAMPWDINSLEEP.U32 = ( (REG_CONTROL_SRAMPWDINSLEEP.U32 & ~(BFM_CONTROL_SRAMPWDINSLEEP_BANK4PWDINSLEEP)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWDINSLEEP_BANK4PWDINSLEEP)) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK4PWDINSLEEP)) ))
#define BFR_CONTROL_SRAMPWDINSLEEP_BANK4PWDINSLEEP() ((REG_CONTROL_SRAMPWDINSLEEP.U32 & (BFM_CONTROL_SRAMPWDINSLEEP_BANK4PWDINSLEEP))>>(BFP_CONTROL_SRAMPWDINSLEEP_BANK4PWDINSLEEP))

#define BFP_CONTROL_SRAMPWDINSLEEP_BANK3PWDINSLEEP (3)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWDINSLEEP_BANK3PWDINSLEEP ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWDINSLEEP_BANK3PWDINSLEEP (1)                     /* bitfield width */
#define BFD_CONTROL_SRAMPWDINSLEEP_BANK3PWDINSLEEP (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWDINSLEEP_BANK3PWDINSLEEP(v) ((((uint32_t) v) << (BFP_CONTROL_SRAMPWDINSLEEP_BANK3PWDINSLEEP)) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK3PWDINSLEEP))
#define BFX_CONTROL_SRAMPWDINSLEEP_BANK3PWDINSLEEP(v) ((((uint32_t) v) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK3PWDINSLEEP)) >> (BFP_CONTROL_SRAMPWDINSLEEP_BANK3PWDINSLEEP))
#define BFW_CONTROL_SRAMPWDINSLEEP_BANK3PWDINSLEEP(v) (REG_CONTROL_SRAMPWDINSLEEP.U32 = ( (REG_CONTROL_SRAMPWDINSLEEP.U32 & ~(BFM_CONTROL_SRAMPWDINSLEEP_BANK3PWDINSLEEP)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWDINSLEEP_BANK3PWDINSLEEP)) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK3PWDINSLEEP)) ))
#define BFR_CONTROL_SRAMPWDINSLEEP_BANK3PWDINSLEEP() ((REG_CONTROL_SRAMPWDINSLEEP.U32 & (BFM_CONTROL_SRAMPWDINSLEEP_BANK3PWDINSLEEP))>>(BFP_CONTROL_SRAMPWDINSLEEP_BANK3PWDINSLEEP))

#define BFP_CONTROL_SRAMPWDINSLEEP_BANK2PWDINSLEEP (2)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWDINSLEEP_BANK2PWDINSLEEP ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWDINSLEEP_BANK2PWDINSLEEP (1)                     /* bitfield width */
#define BFD_CONTROL_SRAMPWDINSLEEP_BANK2PWDINSLEEP (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWDINSLEEP_BANK2PWDINSLEEP(v) ((((uint32_t) v) << (BFP_CONTROL_SRAMPWDINSLEEP_BANK2PWDINSLEEP)) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK2PWDINSLEEP))
#define BFX_CONTROL_SRAMPWDINSLEEP_BANK2PWDINSLEEP(v) ((((uint32_t) v) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK2PWDINSLEEP)) >> (BFP_CONTROL_SRAMPWDINSLEEP_BANK2PWDINSLEEP))
#define BFW_CONTROL_SRAMPWDINSLEEP_BANK2PWDINSLEEP(v) (REG_CONTROL_SRAMPWDINSLEEP.U32 = ( (REG_CONTROL_SRAMPWDINSLEEP.U32 & ~(BFM_CONTROL_SRAMPWDINSLEEP_BANK2PWDINSLEEP)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWDINSLEEP_BANK2PWDINSLEEP)) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK2PWDINSLEEP)) ))
#define BFR_CONTROL_SRAMPWDINSLEEP_BANK2PWDINSLEEP() ((REG_CONTROL_SRAMPWDINSLEEP.U32 & (BFM_CONTROL_SRAMPWDINSLEEP_BANK2PWDINSLEEP))>>(BFP_CONTROL_SRAMPWDINSLEEP_BANK2PWDINSLEEP))

#define BFP_CONTROL_SRAMPWDINSLEEP_BANK1PWDINSLEEP (1)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWDINSLEEP_BANK1PWDINSLEEP ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWDINSLEEP_BANK1PWDINSLEEP (1)                     /* bitfield width */
#define BFD_CONTROL_SRAMPWDINSLEEP_BANK1PWDINSLEEP (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWDINSLEEP_BANK1PWDINSLEEP(v) ((((uint32_t) v) << (BFP_CONTROL_SRAMPWDINSLEEP_BANK1PWDINSLEEP)) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK1PWDINSLEEP))
#define BFX_CONTROL_SRAMPWDINSLEEP_BANK1PWDINSLEEP(v) ((((uint32_t) v) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK1PWDINSLEEP)) >> (BFP_CONTROL_SRAMPWDINSLEEP_BANK1PWDINSLEEP))
#define BFW_CONTROL_SRAMPWDINSLEEP_BANK1PWDINSLEEP(v) (REG_CONTROL_SRAMPWDINSLEEP.U32 = ( (REG_CONTROL_SRAMPWDINSLEEP.U32 & ~(BFM_CONTROL_SRAMPWDINSLEEP_BANK1PWDINSLEEP)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWDINSLEEP_BANK1PWDINSLEEP)) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK1PWDINSLEEP)) ))
#define BFR_CONTROL_SRAMPWDINSLEEP_BANK1PWDINSLEEP() ((REG_CONTROL_SRAMPWDINSLEEP.U32 & (BFM_CONTROL_SRAMPWDINSLEEP_BANK1PWDINSLEEP))>>(BFP_CONTROL_SRAMPWDINSLEEP_BANK1PWDINSLEEP))

#define BFP_CONTROL_SRAMPWDINSLEEP_BANK0PWDINSLEEP (0)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWDINSLEEP_BANK0PWDINSLEEP ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWDINSLEEP_BANK0PWDINSLEEP (1)                     /* bitfield width */
#define BFD_CONTROL_SRAMPWDINSLEEP_BANK0PWDINSLEEP (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWDINSLEEP_BANK0PWDINSLEEP(v) ((((uint32_t) v) << (BFP_CONTROL_SRAMPWDINSLEEP_BANK0PWDINSLEEP)) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK0PWDINSLEEP))
#define BFX_CONTROL_SRAMPWDINSLEEP_BANK0PWDINSLEEP(v) ((((uint32_t) v) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK0PWDINSLEEP)) >> (BFP_CONTROL_SRAMPWDINSLEEP_BANK0PWDINSLEEP))
#define BFW_CONTROL_SRAMPWDINSLEEP_BANK0PWDINSLEEP(v) (REG_CONTROL_SRAMPWDINSLEEP.U32 = ( (REG_CONTROL_SRAMPWDINSLEEP.U32 & ~(BFM_CONTROL_SRAMPWDINSLEEP_BANK0PWDINSLEEP)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWDINSLEEP_BANK0PWDINSLEEP)) & (BFM_CONTROL_SRAMPWDINSLEEP_BANK0PWDINSLEEP)) ))
#define BFR_CONTROL_SRAMPWDINSLEEP_BANK0PWDINSLEEP() ((REG_CONTROL_SRAMPWDINSLEEP.U32 & (BFM_CONTROL_SRAMPWDINSLEEP_BANK0PWDINSLEEP))>>(BFP_CONTROL_SRAMPWDINSLEEP_BANK0PWDINSLEEP))


// *****************************************************************************
//                                                                             *
//  CONTROL_SRAMPWRDIS - Disables individual banks of the SRAM array           *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned VDDR7DIS                   :  1;
        unsigned VDDR6DIS                   :  1;
        unsigned VDDR5DIS                   :  1;
        unsigned VDDR4DIS                   :  1;
        unsigned VDDR3DIS                   :  1;
        unsigned VDDR2DIS                   :  1;
        unsigned VDDR1DIS                   :  1;
        unsigned VDDR0DIS                   :  1;
    } B;
} reg_control_srampwrdis_t;

#define REG_CONTROL_SRAMPWRDIS_ADDR             (REG_CONTROL_BASEADDR + 0x00000144UL)
#define REG_CONTROL_SRAMPWRDIS                  (*(volatile reg_control_srampwrdis_t *) REG_CONTROL_SRAMPWRDIS_ADDR)
#define REG_CONTROL_SRAMPWRDIS_RD()             (REG_CONTROL_SRAMPWRDIS.U32)
#define REG_CONTROL_SRAMPWRDIS_WR(v)            (REG_CONTROL_SRAMPWRDIS.U32 = (v))
#define REG_CONTROL_SRAMPWRDIS_CLR(m)           (REG_CONTROL_SRAMPWRDIS.U32 = ((REG_CONTROL_SRAMPWRDIS.U32) & ~(m)))
#define REG_CONTROL_SRAMPWRDIS_SET(m)           (REG_CONTROL_SRAMPWRDIS.U32 = ((REG_CONTROL_SRAMPWRDIS.U32) | (m)))
#define REG_CONTROL_SRAMPWRDIS_DEF              0x00000000

#define BFP_CONTROL_SRAMPWRDIS_RSVD_8           (8)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWRDIS_RSVD_8           ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWRDIS_RSVD_8           (24)                    /* bitfield width */
#define BFD_CONTROL_SRAMPWRDIS_RSVD_8           (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWRDIS_RSVD_8(v)        ((((uint32_t) v) << (BFP_CONTROL_SRAMPWRDIS_RSVD_8)) & (BFM_CONTROL_SRAMPWRDIS_RSVD_8))
#define BFX_CONTROL_SRAMPWRDIS_RSVD_8(v)        ((((uint32_t) v) & (BFM_CONTROL_SRAMPWRDIS_RSVD_8)) >> (BFP_CONTROL_SRAMPWRDIS_RSVD_8))
#define BFW_CONTROL_SRAMPWRDIS_RSVD_8(v)        (REG_CONTROL_SRAMPWRDIS.U32 = ( (REG_CONTROL_SRAMPWRDIS.U32 & ~(BFM_CONTROL_SRAMPWRDIS_RSVD_8)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWRDIS_RSVD_8)) & (BFM_CONTROL_SRAMPWRDIS_RSVD_8)) ))
#define BFR_CONTROL_SRAMPWRDIS_RSVD_8()         ((REG_CONTROL_SRAMPWRDIS.U32 & (BFM_CONTROL_SRAMPWRDIS_RSVD_8))>>(BFP_CONTROL_SRAMPWRDIS_RSVD_8))

#define BFP_CONTROL_SRAMPWRDIS_VDDR7DIS         (7)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWRDIS_VDDR7DIS         ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWRDIS_VDDR7DIS         (1)                     /* bitfield width */
#define BFD_CONTROL_SRAMPWRDIS_VDDR7DIS         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWRDIS_VDDR7DIS(v)      ((((uint32_t) v) << (BFP_CONTROL_SRAMPWRDIS_VDDR7DIS)) & (BFM_CONTROL_SRAMPWRDIS_VDDR7DIS))
#define BFX_CONTROL_SRAMPWRDIS_VDDR7DIS(v)      ((((uint32_t) v) & (BFM_CONTROL_SRAMPWRDIS_VDDR7DIS)) >> (BFP_CONTROL_SRAMPWRDIS_VDDR7DIS))
#define BFW_CONTROL_SRAMPWRDIS_VDDR7DIS(v)      (REG_CONTROL_SRAMPWRDIS.U32 = ( (REG_CONTROL_SRAMPWRDIS.U32 & ~(BFM_CONTROL_SRAMPWRDIS_VDDR7DIS)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWRDIS_VDDR7DIS)) & (BFM_CONTROL_SRAMPWRDIS_VDDR7DIS)) ))
#define BFR_CONTROL_SRAMPWRDIS_VDDR7DIS()       ((REG_CONTROL_SRAMPWRDIS.U32 & (BFM_CONTROL_SRAMPWRDIS_VDDR7DIS))>>(BFP_CONTROL_SRAMPWRDIS_VDDR7DIS))

#define BFP_CONTROL_SRAMPWRDIS_VDDR6DIS         (6)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWRDIS_VDDR6DIS         ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWRDIS_VDDR6DIS         (1)                     /* bitfield width */
#define BFD_CONTROL_SRAMPWRDIS_VDDR6DIS         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWRDIS_VDDR6DIS(v)      ((((uint32_t) v) << (BFP_CONTROL_SRAMPWRDIS_VDDR6DIS)) & (BFM_CONTROL_SRAMPWRDIS_VDDR6DIS))
#define BFX_CONTROL_SRAMPWRDIS_VDDR6DIS(v)      ((((uint32_t) v) & (BFM_CONTROL_SRAMPWRDIS_VDDR6DIS)) >> (BFP_CONTROL_SRAMPWRDIS_VDDR6DIS))
#define BFW_CONTROL_SRAMPWRDIS_VDDR6DIS(v)      (REG_CONTROL_SRAMPWRDIS.U32 = ( (REG_CONTROL_SRAMPWRDIS.U32 & ~(BFM_CONTROL_SRAMPWRDIS_VDDR6DIS)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWRDIS_VDDR6DIS)) & (BFM_CONTROL_SRAMPWRDIS_VDDR6DIS)) ))
#define BFR_CONTROL_SRAMPWRDIS_VDDR6DIS()       ((REG_CONTROL_SRAMPWRDIS.U32 & (BFM_CONTROL_SRAMPWRDIS_VDDR6DIS))>>(BFP_CONTROL_SRAMPWRDIS_VDDR6DIS))

#define BFP_CONTROL_SRAMPWRDIS_VDDR5DIS         (5)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWRDIS_VDDR5DIS         ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWRDIS_VDDR5DIS         (1)                     /* bitfield width */
#define BFD_CONTROL_SRAMPWRDIS_VDDR5DIS         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWRDIS_VDDR5DIS(v)      ((((uint32_t) v) << (BFP_CONTROL_SRAMPWRDIS_VDDR5DIS)) & (BFM_CONTROL_SRAMPWRDIS_VDDR5DIS))
#define BFX_CONTROL_SRAMPWRDIS_VDDR5DIS(v)      ((((uint32_t) v) & (BFM_CONTROL_SRAMPWRDIS_VDDR5DIS)) >> (BFP_CONTROL_SRAMPWRDIS_VDDR5DIS))
#define BFW_CONTROL_SRAMPWRDIS_VDDR5DIS(v)      (REG_CONTROL_SRAMPWRDIS.U32 = ( (REG_CONTROL_SRAMPWRDIS.U32 & ~(BFM_CONTROL_SRAMPWRDIS_VDDR5DIS)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWRDIS_VDDR5DIS)) & (BFM_CONTROL_SRAMPWRDIS_VDDR5DIS)) ))
#define BFR_CONTROL_SRAMPWRDIS_VDDR5DIS()       ((REG_CONTROL_SRAMPWRDIS.U32 & (BFM_CONTROL_SRAMPWRDIS_VDDR5DIS))>>(BFP_CONTROL_SRAMPWRDIS_VDDR5DIS))

#define BFP_CONTROL_SRAMPWRDIS_VDDR4DIS         (4)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWRDIS_VDDR4DIS         ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWRDIS_VDDR4DIS         (1)                     /* bitfield width */
#define BFD_CONTROL_SRAMPWRDIS_VDDR4DIS         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWRDIS_VDDR4DIS(v)      ((((uint32_t) v) << (BFP_CONTROL_SRAMPWRDIS_VDDR4DIS)) & (BFM_CONTROL_SRAMPWRDIS_VDDR4DIS))
#define BFX_CONTROL_SRAMPWRDIS_VDDR4DIS(v)      ((((uint32_t) v) & (BFM_CONTROL_SRAMPWRDIS_VDDR4DIS)) >> (BFP_CONTROL_SRAMPWRDIS_VDDR4DIS))
#define BFW_CONTROL_SRAMPWRDIS_VDDR4DIS(v)      (REG_CONTROL_SRAMPWRDIS.U32 = ( (REG_CONTROL_SRAMPWRDIS.U32 & ~(BFM_CONTROL_SRAMPWRDIS_VDDR4DIS)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWRDIS_VDDR4DIS)) & (BFM_CONTROL_SRAMPWRDIS_VDDR4DIS)) ))
#define BFR_CONTROL_SRAMPWRDIS_VDDR4DIS()       ((REG_CONTROL_SRAMPWRDIS.U32 & (BFM_CONTROL_SRAMPWRDIS_VDDR4DIS))>>(BFP_CONTROL_SRAMPWRDIS_VDDR4DIS))

#define BFP_CONTROL_SRAMPWRDIS_VDDR3DIS         (3)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWRDIS_VDDR3DIS         ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWRDIS_VDDR3DIS         (1)                     /* bitfield width */
#define BFD_CONTROL_SRAMPWRDIS_VDDR3DIS         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWRDIS_VDDR3DIS(v)      ((((uint32_t) v) << (BFP_CONTROL_SRAMPWRDIS_VDDR3DIS)) & (BFM_CONTROL_SRAMPWRDIS_VDDR3DIS))
#define BFX_CONTROL_SRAMPWRDIS_VDDR3DIS(v)      ((((uint32_t) v) & (BFM_CONTROL_SRAMPWRDIS_VDDR3DIS)) >> (BFP_CONTROL_SRAMPWRDIS_VDDR3DIS))
#define BFW_CONTROL_SRAMPWRDIS_VDDR3DIS(v)      (REG_CONTROL_SRAMPWRDIS.U32 = ( (REG_CONTROL_SRAMPWRDIS.U32 & ~(BFM_CONTROL_SRAMPWRDIS_VDDR3DIS)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWRDIS_VDDR3DIS)) & (BFM_CONTROL_SRAMPWRDIS_VDDR3DIS)) ))
#define BFR_CONTROL_SRAMPWRDIS_VDDR3DIS()       ((REG_CONTROL_SRAMPWRDIS.U32 & (BFM_CONTROL_SRAMPWRDIS_VDDR3DIS))>>(BFP_CONTROL_SRAMPWRDIS_VDDR3DIS))

#define BFP_CONTROL_SRAMPWRDIS_VDDR2DIS         (2)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWRDIS_VDDR2DIS         ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWRDIS_VDDR2DIS         (1)                     /* bitfield width */
#define BFD_CONTROL_SRAMPWRDIS_VDDR2DIS         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWRDIS_VDDR2DIS(v)      ((((uint32_t) v) << (BFP_CONTROL_SRAMPWRDIS_VDDR2DIS)) & (BFM_CONTROL_SRAMPWRDIS_VDDR2DIS))
#define BFX_CONTROL_SRAMPWRDIS_VDDR2DIS(v)      ((((uint32_t) v) & (BFM_CONTROL_SRAMPWRDIS_VDDR2DIS)) >> (BFP_CONTROL_SRAMPWRDIS_VDDR2DIS))
#define BFW_CONTROL_SRAMPWRDIS_VDDR2DIS(v)      (REG_CONTROL_SRAMPWRDIS.U32 = ( (REG_CONTROL_SRAMPWRDIS.U32 & ~(BFM_CONTROL_SRAMPWRDIS_VDDR2DIS)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWRDIS_VDDR2DIS)) & (BFM_CONTROL_SRAMPWRDIS_VDDR2DIS)) ))
#define BFR_CONTROL_SRAMPWRDIS_VDDR2DIS()       ((REG_CONTROL_SRAMPWRDIS.U32 & (BFM_CONTROL_SRAMPWRDIS_VDDR2DIS))>>(BFP_CONTROL_SRAMPWRDIS_VDDR2DIS))

#define BFP_CONTROL_SRAMPWRDIS_VDDR1DIS         (1)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWRDIS_VDDR1DIS         ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWRDIS_VDDR1DIS         (1)                     /* bitfield width */
#define BFD_CONTROL_SRAMPWRDIS_VDDR1DIS         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWRDIS_VDDR1DIS(v)      ((((uint32_t) v) << (BFP_CONTROL_SRAMPWRDIS_VDDR1DIS)) & (BFM_CONTROL_SRAMPWRDIS_VDDR1DIS))
#define BFX_CONTROL_SRAMPWRDIS_VDDR1DIS(v)      ((((uint32_t) v) & (BFM_CONTROL_SRAMPWRDIS_VDDR1DIS)) >> (BFP_CONTROL_SRAMPWRDIS_VDDR1DIS))
#define BFW_CONTROL_SRAMPWRDIS_VDDR1DIS(v)      (REG_CONTROL_SRAMPWRDIS.U32 = ( (REG_CONTROL_SRAMPWRDIS.U32 & ~(BFM_CONTROL_SRAMPWRDIS_VDDR1DIS)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWRDIS_VDDR1DIS)) & (BFM_CONTROL_SRAMPWRDIS_VDDR1DIS)) ))
#define BFR_CONTROL_SRAMPWRDIS_VDDR1DIS()       ((REG_CONTROL_SRAMPWRDIS.U32 & (BFM_CONTROL_SRAMPWRDIS_VDDR1DIS))>>(BFP_CONTROL_SRAMPWRDIS_VDDR1DIS))

#define BFP_CONTROL_SRAMPWRDIS_VDDR0DIS         (0)                     /* bitfield lsb */
#define BFM_CONTROL_SRAMPWRDIS_VDDR0DIS         ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_SRAMPWRDIS_VDDR0DIS         (1)                     /* bitfield width */
#define BFD_CONTROL_SRAMPWRDIS_VDDR0DIS         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SRAMPWRDIS_VDDR0DIS(v)      ((((uint32_t) v) << (BFP_CONTROL_SRAMPWRDIS_VDDR0DIS)) & (BFM_CONTROL_SRAMPWRDIS_VDDR0DIS))
#define BFX_CONTROL_SRAMPWRDIS_VDDR0DIS(v)      ((((uint32_t) v) & (BFM_CONTROL_SRAMPWRDIS_VDDR0DIS)) >> (BFP_CONTROL_SRAMPWRDIS_VDDR0DIS))
#define BFW_CONTROL_SRAMPWRDIS_VDDR0DIS(v)      (REG_CONTROL_SRAMPWRDIS.U32 = ( (REG_CONTROL_SRAMPWRDIS.U32 & ~(BFM_CONTROL_SRAMPWRDIS_VDDR0DIS)) | ((((uint32_t) v)<<(BFP_CONTROL_SRAMPWRDIS_VDDR0DIS)) & (BFM_CONTROL_SRAMPWRDIS_VDDR0DIS)) ))
#define BFR_CONTROL_SRAMPWRDIS_VDDR0DIS()       ((REG_CONTROL_SRAMPWRDIS.U32 & (BFM_CONTROL_SRAMPWRDIS_VDDR0DIS))>>(BFP_CONTROL_SRAMPWRDIS_VDDR0DIS))


// *****************************************************************************
//                                                                             *
//  CONTROL_FLASHPWRDIS - Disables individual banks of the Flash array         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_2                     : 30;
        unsigned VDDF1DIS                   :  1;
        unsigned VDDF0DIS                   :  1;
    } B;
} reg_control_flashpwrdis_t;

#define REG_CONTROL_FLASHPWRDIS_ADDR            (REG_CONTROL_BASEADDR + 0x00000148UL)
#define REG_CONTROL_FLASHPWRDIS                 (*(volatile reg_control_flashpwrdis_t *) REG_CONTROL_FLASHPWRDIS_ADDR)
#define REG_CONTROL_FLASHPWRDIS_RD()            (REG_CONTROL_FLASHPWRDIS.U32)
#define REG_CONTROL_FLASHPWRDIS_WR(v)           (REG_CONTROL_FLASHPWRDIS.U32 = (v))
#define REG_CONTROL_FLASHPWRDIS_CLR(m)          (REG_CONTROL_FLASHPWRDIS.U32 = ((REG_CONTROL_FLASHPWRDIS.U32) & ~(m)))
#define REG_CONTROL_FLASHPWRDIS_SET(m)          (REG_CONTROL_FLASHPWRDIS.U32 = ((REG_CONTROL_FLASHPWRDIS.U32) | (m)))
#define REG_CONTROL_FLASHPWRDIS_DEF             0x00000000

#define BFP_CONTROL_FLASHPWRDIS_RSVD_2          (2)                     /* bitfield lsb */
#define BFM_CONTROL_FLASHPWRDIS_RSVD_2          ((uint32_t)0xfffffffc)  /* bitfield mask */
#define BFN_CONTROL_FLASHPWRDIS_RSVD_2          (30)                    /* bitfield width */
#define BFD_CONTROL_FLASHPWRDIS_RSVD_2          (0x0)                   /* bitfield default value */
#define BFV_CONTROL_FLASHPWRDIS_RSVD_2(v)       ((((uint32_t) v) << (BFP_CONTROL_FLASHPWRDIS_RSVD_2)) & (BFM_CONTROL_FLASHPWRDIS_RSVD_2))
#define BFX_CONTROL_FLASHPWRDIS_RSVD_2(v)       ((((uint32_t) v) & (BFM_CONTROL_FLASHPWRDIS_RSVD_2)) >> (BFP_CONTROL_FLASHPWRDIS_RSVD_2))
#define BFW_CONTROL_FLASHPWRDIS_RSVD_2(v)       (REG_CONTROL_FLASHPWRDIS.U32 = ( (REG_CONTROL_FLASHPWRDIS.U32 & ~(BFM_CONTROL_FLASHPWRDIS_RSVD_2)) | ((((uint32_t) v)<<(BFP_CONTROL_FLASHPWRDIS_RSVD_2)) & (BFM_CONTROL_FLASHPWRDIS_RSVD_2)) ))
#define BFR_CONTROL_FLASHPWRDIS_RSVD_2()        ((REG_CONTROL_FLASHPWRDIS.U32 & (BFM_CONTROL_FLASHPWRDIS_RSVD_2))>>(BFP_CONTROL_FLASHPWRDIS_RSVD_2))

#define BFP_CONTROL_FLASHPWRDIS_VDDF1DIS        (1)                     /* bitfield lsb */
#define BFM_CONTROL_FLASHPWRDIS_VDDF1DIS        ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CONTROL_FLASHPWRDIS_VDDF1DIS        (1)                     /* bitfield width */
#define BFD_CONTROL_FLASHPWRDIS_VDDF1DIS        (0x0)                   /* bitfield default value */
#define BFV_CONTROL_FLASHPWRDIS_VDDF1DIS(v)     ((((uint32_t) v) << (BFP_CONTROL_FLASHPWRDIS_VDDF1DIS)) & (BFM_CONTROL_FLASHPWRDIS_VDDF1DIS))
#define BFX_CONTROL_FLASHPWRDIS_VDDF1DIS(v)     ((((uint32_t) v) & (BFM_CONTROL_FLASHPWRDIS_VDDF1DIS)) >> (BFP_CONTROL_FLASHPWRDIS_VDDF1DIS))
#define BFW_CONTROL_FLASHPWRDIS_VDDF1DIS(v)     (REG_CONTROL_FLASHPWRDIS.U32 = ( (REG_CONTROL_FLASHPWRDIS.U32 & ~(BFM_CONTROL_FLASHPWRDIS_VDDF1DIS)) | ((((uint32_t) v)<<(BFP_CONTROL_FLASHPWRDIS_VDDF1DIS)) & (BFM_CONTROL_FLASHPWRDIS_VDDF1DIS)) ))
#define BFR_CONTROL_FLASHPWRDIS_VDDF1DIS()      ((REG_CONTROL_FLASHPWRDIS.U32 & (BFM_CONTROL_FLASHPWRDIS_VDDF1DIS))>>(BFP_CONTROL_FLASHPWRDIS_VDDF1DIS))

#define BFP_CONTROL_FLASHPWRDIS_VDDF0DIS        (0)                     /* bitfield lsb */
#define BFM_CONTROL_FLASHPWRDIS_VDDF0DIS        ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_FLASHPWRDIS_VDDF0DIS        (1)                     /* bitfield width */
#define BFD_CONTROL_FLASHPWRDIS_VDDF0DIS        (0x0)                   /* bitfield default value */
#define BFV_CONTROL_FLASHPWRDIS_VDDF0DIS(v)     ((((uint32_t) v) << (BFP_CONTROL_FLASHPWRDIS_VDDF0DIS)) & (BFM_CONTROL_FLASHPWRDIS_VDDF0DIS))
#define BFX_CONTROL_FLASHPWRDIS_VDDF0DIS(v)     ((((uint32_t) v) & (BFM_CONTROL_FLASHPWRDIS_VDDF0DIS)) >> (BFP_CONTROL_FLASHPWRDIS_VDDF0DIS))
#define BFW_CONTROL_FLASHPWRDIS_VDDF0DIS(v)     (REG_CONTROL_FLASHPWRDIS.U32 = ( (REG_CONTROL_FLASHPWRDIS.U32 & ~(BFM_CONTROL_FLASHPWRDIS_VDDF0DIS)) | ((((uint32_t) v)<<(BFP_CONTROL_FLASHPWRDIS_VDDF0DIS)) & (BFM_CONTROL_FLASHPWRDIS_VDDF0DIS)) ))
#define BFR_CONTROL_FLASHPWRDIS_VDDF0DIS()      ((REG_CONTROL_FLASHPWRDIS.U32 & (BFM_CONTROL_FLASHPWRDIS_VDDF0DIS))>>(BFP_CONTROL_FLASHPWRDIS_VDDF0DIS))


// *****************************************************************************
//                                                                             *
//  CONTROL_PWRONRSTDLY - Power On Sequence Delay Register                     *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_24                    :  8;
        unsigned PORDLY3                    :  8;
        unsigned PORDLY2                    :  8;
        unsigned PORDLY1                    :  8;
    } B;
} reg_control_pwronrstdly_t;

#define REG_CONTROL_PWRONRSTDLY_ADDR            (REG_CONTROL_BASEADDR + 0x00000180UL)
#define REG_CONTROL_PWRONRSTDLY                 (*(volatile reg_control_pwronrstdly_t *) REG_CONTROL_PWRONRSTDLY_ADDR)
#define REG_CONTROL_PWRONRSTDLY_RD()            (REG_CONTROL_PWRONRSTDLY.U32)
#define REG_CONTROL_PWRONRSTDLY_WR(v)           (REG_CONTROL_PWRONRSTDLY.U32 = (v))
#define REG_CONTROL_PWRONRSTDLY_CLR(m)          (REG_CONTROL_PWRONRSTDLY.U32 = ((REG_CONTROL_PWRONRSTDLY.U32) & ~(m)))
#define REG_CONTROL_PWRONRSTDLY_SET(m)          (REG_CONTROL_PWRONRSTDLY.U32 = ((REG_CONTROL_PWRONRSTDLY.U32) | (m)))
#define REG_CONTROL_PWRONRSTDLY_DEF             0x00000000

#define BFP_CONTROL_PWRONRSTDLY_RSVD_24         (24)                    /* bitfield lsb */
#define BFM_CONTROL_PWRONRSTDLY_RSVD_24         ((uint32_t)0xff000000)  /* bitfield mask */
#define BFN_CONTROL_PWRONRSTDLY_RSVD_24         (8)                     /* bitfield width */
#define BFD_CONTROL_PWRONRSTDLY_RSVD_24         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_PWRONRSTDLY_RSVD_24(v)      ((((uint32_t) v) << (BFP_CONTROL_PWRONRSTDLY_RSVD_24)) & (BFM_CONTROL_PWRONRSTDLY_RSVD_24))
#define BFX_CONTROL_PWRONRSTDLY_RSVD_24(v)      ((((uint32_t) v) & (BFM_CONTROL_PWRONRSTDLY_RSVD_24)) >> (BFP_CONTROL_PWRONRSTDLY_RSVD_24))
#define BFW_CONTROL_PWRONRSTDLY_RSVD_24(v)      (REG_CONTROL_PWRONRSTDLY.U32 = ( (REG_CONTROL_PWRONRSTDLY.U32 & ~(BFM_CONTROL_PWRONRSTDLY_RSVD_24)) | ((((uint32_t) v)<<(BFP_CONTROL_PWRONRSTDLY_RSVD_24)) & (BFM_CONTROL_PWRONRSTDLY_RSVD_24)) ))
#define BFR_CONTROL_PWRONRSTDLY_RSVD_24()       ((REG_CONTROL_PWRONRSTDLY.U32 & (BFM_CONTROL_PWRONRSTDLY_RSVD_24))>>(BFP_CONTROL_PWRONRSTDLY_RSVD_24))

#define BFP_CONTROL_PWRONRSTDLY_PORDLY3         (16)                    /* bitfield lsb */
#define BFM_CONTROL_PWRONRSTDLY_PORDLY3         ((uint32_t)0x00ff0000)  /* bitfield mask */
#define BFN_CONTROL_PWRONRSTDLY_PORDLY3         (8)                     /* bitfield width */
#define BFD_CONTROL_PWRONRSTDLY_PORDLY3         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_PWRONRSTDLY_PORDLY3(v)      ((((uint32_t) v) << (BFP_CONTROL_PWRONRSTDLY_PORDLY3)) & (BFM_CONTROL_PWRONRSTDLY_PORDLY3))
#define BFX_CONTROL_PWRONRSTDLY_PORDLY3(v)      ((((uint32_t) v) & (BFM_CONTROL_PWRONRSTDLY_PORDLY3)) >> (BFP_CONTROL_PWRONRSTDLY_PORDLY3))
#define BFW_CONTROL_PWRONRSTDLY_PORDLY3(v)      (REG_CONTROL_PWRONRSTDLY.U32 = ( (REG_CONTROL_PWRONRSTDLY.U32 & ~(BFM_CONTROL_PWRONRSTDLY_PORDLY3)) | ((((uint32_t) v)<<(BFP_CONTROL_PWRONRSTDLY_PORDLY3)) & (BFM_CONTROL_PWRONRSTDLY_PORDLY3)) ))
#define BFR_CONTROL_PWRONRSTDLY_PORDLY3()       ((REG_CONTROL_PWRONRSTDLY.U32 & (BFM_CONTROL_PWRONRSTDLY_PORDLY3))>>(BFP_CONTROL_PWRONRSTDLY_PORDLY3))

#define BFP_CONTROL_PWRONRSTDLY_PORDLY2         (8)                     /* bitfield lsb */
#define BFM_CONTROL_PWRONRSTDLY_PORDLY2         ((uint32_t)0x0000ff00)  /* bitfield mask */
#define BFN_CONTROL_PWRONRSTDLY_PORDLY2         (8)                     /* bitfield width */
#define BFD_CONTROL_PWRONRSTDLY_PORDLY2         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_PWRONRSTDLY_PORDLY2(v)      ((((uint32_t) v) << (BFP_CONTROL_PWRONRSTDLY_PORDLY2)) & (BFM_CONTROL_PWRONRSTDLY_PORDLY2))
#define BFX_CONTROL_PWRONRSTDLY_PORDLY2(v)      ((((uint32_t) v) & (BFM_CONTROL_PWRONRSTDLY_PORDLY2)) >> (BFP_CONTROL_PWRONRSTDLY_PORDLY2))
#define BFW_CONTROL_PWRONRSTDLY_PORDLY2(v)      (REG_CONTROL_PWRONRSTDLY.U32 = ( (REG_CONTROL_PWRONRSTDLY.U32 & ~(BFM_CONTROL_PWRONRSTDLY_PORDLY2)) | ((((uint32_t) v)<<(BFP_CONTROL_PWRONRSTDLY_PORDLY2)) & (BFM_CONTROL_PWRONRSTDLY_PORDLY2)) ))
#define BFR_CONTROL_PWRONRSTDLY_PORDLY2()       ((REG_CONTROL_PWRONRSTDLY.U32 & (BFM_CONTROL_PWRONRSTDLY_PORDLY2))>>(BFP_CONTROL_PWRONRSTDLY_PORDLY2))

#define BFP_CONTROL_PWRONRSTDLY_PORDLY1         (0)                     /* bitfield lsb */
#define BFM_CONTROL_PWRONRSTDLY_PORDLY1         ((uint32_t)0x000000ff)  /* bitfield mask */
#define BFN_CONTROL_PWRONRSTDLY_PORDLY1         (8)                     /* bitfield width */
#define BFD_CONTROL_PWRONRSTDLY_PORDLY1         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_PWRONRSTDLY_PORDLY1(v)      ((((uint32_t) v) << (BFP_CONTROL_PWRONRSTDLY_PORDLY1)) & (BFM_CONTROL_PWRONRSTDLY_PORDLY1))
#define BFX_CONTROL_PWRONRSTDLY_PORDLY1(v)      ((((uint32_t) v) & (BFM_CONTROL_PWRONRSTDLY_PORDLY1)) >> (BFP_CONTROL_PWRONRSTDLY_PORDLY1))
#define BFW_CONTROL_PWRONRSTDLY_PORDLY1(v)      (REG_CONTROL_PWRONRSTDLY.U32 = ( (REG_CONTROL_PWRONRSTDLY.U32 & ~(BFM_CONTROL_PWRONRSTDLY_PORDLY1)) | ((((uint32_t) v)<<(BFP_CONTROL_PWRONRSTDLY_PORDLY1)) & (BFM_CONTROL_PWRONRSTDLY_PORDLY1)) ))
#define BFR_CONTROL_PWRONRSTDLY_PORDLY1()       ((REG_CONTROL_PWRONRSTDLY.U32 & (BFM_CONTROL_PWRONRSTDLY_PORDLY1))>>(BFP_CONTROL_PWRONRSTDLY_PORDLY1))


// *****************************************************************************
//                                                                             *
//  CONTROL_BOOTLOADERLOW - This register determines whether the bootloader code is visible at address 0x00000000*
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_1                     : 31;
        unsigned BOOTLOADERLOW              :  1;
    } B;
} reg_control_bootloaderlow_t;

#define REG_CONTROL_BOOTLOADERLOW_ADDR          (REG_CONTROL_BASEADDR + 0x000001A0UL)
#define REG_CONTROL_BOOTLOADERLOW               (*(volatile reg_control_bootloaderlow_t *) REG_CONTROL_BOOTLOADERLOW_ADDR)
#define REG_CONTROL_BOOTLOADERLOW_RD()          (REG_CONTROL_BOOTLOADERLOW.U32)
#define REG_CONTROL_BOOTLOADERLOW_WR(v)         (REG_CONTROL_BOOTLOADERLOW.U32 = (v))
#define REG_CONTROL_BOOTLOADERLOW_CLR(m)        (REG_CONTROL_BOOTLOADERLOW.U32 = ((REG_CONTROL_BOOTLOADERLOW.U32) & ~(m)))
#define REG_CONTROL_BOOTLOADERLOW_SET(m)        (REG_CONTROL_BOOTLOADERLOW.U32 = ((REG_CONTROL_BOOTLOADERLOW.U32) | (m)))
#define REG_CONTROL_BOOTLOADERLOW_DEF           0x00000001

#define BFP_CONTROL_BOOTLOADERLOW_RSVD_1        (1)                     /* bitfield lsb */
#define BFM_CONTROL_BOOTLOADERLOW_RSVD_1        ((uint32_t)0xfffffffe)  /* bitfield mask */
#define BFN_CONTROL_BOOTLOADERLOW_RSVD_1        (31)                    /* bitfield width */
#define BFD_CONTROL_BOOTLOADERLOW_RSVD_1        (0x0)                   /* bitfield default value */
#define BFV_CONTROL_BOOTLOADERLOW_RSVD_1(v)     ((((uint32_t) v) << (BFP_CONTROL_BOOTLOADERLOW_RSVD_1)) & (BFM_CONTROL_BOOTLOADERLOW_RSVD_1))
#define BFX_CONTROL_BOOTLOADERLOW_RSVD_1(v)     ((((uint32_t) v) & (BFM_CONTROL_BOOTLOADERLOW_RSVD_1)) >> (BFP_CONTROL_BOOTLOADERLOW_RSVD_1))
#define BFW_CONTROL_BOOTLOADERLOW_RSVD_1(v)     (REG_CONTROL_BOOTLOADERLOW.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_BOOTLOADERLOW_RSVD_1)) & (BFM_CONTROL_BOOTLOADERLOW_RSVD_1)) )
#define BFR_CONTROL_BOOTLOADERLOW_RSVD_1()      ((REG_CONTROL_BOOTLOADERLOW.U32 & (BFM_CONTROL_BOOTLOADERLOW_RSVD_1))>>(BFP_CONTROL_BOOTLOADERLOW_RSVD_1))

#define BFP_CONTROL_BOOTLOADERLOW_BOOTLOADERLOW (0)                     /* bitfield lsb */
#define BFM_CONTROL_BOOTLOADERLOW_BOOTLOADERLOW ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_BOOTLOADERLOW_BOOTLOADERLOW (1)                     /* bitfield width */
#define BFD_CONTROL_BOOTLOADERLOW_BOOTLOADERLOW (0x1)                   /* bitfield default value */
#define BFV_CONTROL_BOOTLOADERLOW_BOOTLOADERLOW(v) ((((uint32_t) v) << (BFP_CONTROL_BOOTLOADERLOW_BOOTLOADERLOW)) & (BFM_CONTROL_BOOTLOADERLOW_BOOTLOADERLOW))
#define BFX_CONTROL_BOOTLOADERLOW_BOOTLOADERLOW(v) ((((uint32_t) v) & (BFM_CONTROL_BOOTLOADERLOW_BOOTLOADERLOW)) >> (BFP_CONTROL_BOOTLOADERLOW_BOOTLOADERLOW))
#define BFW_CONTROL_BOOTLOADERLOW_BOOTLOADERLOW(v) (REG_CONTROL_BOOTLOADERLOW.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_BOOTLOADERLOW_BOOTLOADERLOW)) & (BFM_CONTROL_BOOTLOADERLOW_BOOTLOADERLOW)) )
#define BFR_CONTROL_BOOTLOADERLOW_BOOTLOADERLOW() ((REG_CONTROL_BOOTLOADERLOW.U32 & (BFM_CONTROL_BOOTLOADERLOW_BOOTLOADERLOW))>>(BFP_CONTROL_BOOTLOADERLOW_BOOTLOADERLOW))


// *****************************************************************************
//                                                                             *
//  CONTROL_SHADOWVALID - Register to indicate whether the shadow registers are valid*
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_1                     : 31;
        unsigned SHADOWVALID                :  1;
    } B;
} reg_control_shadowvalid_t;

#define REG_CONTROL_SHADOWVALID_ADDR            (REG_CONTROL_BASEADDR + 0x000001A4UL)
#define REG_CONTROL_SHADOWVALID                 (*(volatile reg_control_shadowvalid_t *) REG_CONTROL_SHADOWVALID_ADDR)
#define REG_CONTROL_SHADOWVALID_RD()            (REG_CONTROL_SHADOWVALID.U32)
#define REG_CONTROL_SHADOWVALID_WR(v)           (REG_CONTROL_SHADOWVALID.U32 = (v))
#define REG_CONTROL_SHADOWVALID_CLR(m)          (REG_CONTROL_SHADOWVALID.U32 = ((REG_CONTROL_SHADOWVALID.U32) & ~(m)))
#define REG_CONTROL_SHADOWVALID_SET(m)          (REG_CONTROL_SHADOWVALID.U32 = ((REG_CONTROL_SHADOWVALID.U32) | (m)))
#define REG_CONTROL_SHADOWVALID_DEF             0x00000001

#define BFP_CONTROL_SHADOWVALID_RSVD_1          (1)                     /* bitfield lsb */
#define BFM_CONTROL_SHADOWVALID_RSVD_1          ((uint32_t)0xfffffffe)  /* bitfield mask */
#define BFN_CONTROL_SHADOWVALID_RSVD_1          (31)                    /* bitfield width */
#define BFD_CONTROL_SHADOWVALID_RSVD_1          (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SHADOWVALID_RSVD_1(v)       ((((uint32_t) v) << (BFP_CONTROL_SHADOWVALID_RSVD_1)) & (BFM_CONTROL_SHADOWVALID_RSVD_1))
#define BFX_CONTROL_SHADOWVALID_RSVD_1(v)       ((((uint32_t) v) & (BFM_CONTROL_SHADOWVALID_RSVD_1)) >> (BFP_CONTROL_SHADOWVALID_RSVD_1))
#define BFW_CONTROL_SHADOWVALID_RSVD_1(v)       (REG_CONTROL_SHADOWVALID.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_SHADOWVALID_RSVD_1)) & (BFM_CONTROL_SHADOWVALID_RSVD_1)) )
#define BFR_CONTROL_SHADOWVALID_RSVD_1()        ((REG_CONTROL_SHADOWVALID.U32 & (BFM_CONTROL_SHADOWVALID_RSVD_1))>>(BFP_CONTROL_SHADOWVALID_RSVD_1))

#define BFP_CONTROL_SHADOWVALID_SHADOWVALID     (0)                     /* bitfield lsb */
#define BFM_CONTROL_SHADOWVALID_SHADOWVALID     ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_SHADOWVALID_SHADOWVALID     (1)                     /* bitfield width */
#define BFD_CONTROL_SHADOWVALID_SHADOWVALID     (0x1)                   /* bitfield default value */
#define BFV_CONTROL_SHADOWVALID_SHADOWVALID(v)  ((((uint32_t) v) << (BFP_CONTROL_SHADOWVALID_SHADOWVALID)) & (BFM_CONTROL_SHADOWVALID_SHADOWVALID))
#define BFX_CONTROL_SHADOWVALID_SHADOWVALID(v)  ((((uint32_t) v) & (BFM_CONTROL_SHADOWVALID_SHADOWVALID)) >> (BFP_CONTROL_SHADOWVALID_SHADOWVALID))
#define BFW_CONTROL_SHADOWVALID_SHADOWVALID(v)  (REG_CONTROL_SHADOWVALID.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_SHADOWVALID_SHADOWVALID)) & (BFM_CONTROL_SHADOWVALID_SHADOWVALID)) )
#define BFR_CONTROL_SHADOWVALID_SHADOWVALID()   ((REG_CONTROL_SHADOWVALID.U32 & (BFM_CONTROL_SHADOWVALID_SHADOWVALID))>>(BFP_CONTROL_SHADOWVALID_SHADOWVALID))


// *****************************************************************************
//                                                                             *
//  CONTROL_ICODEFAULTADDR - Register to capture the address on the ICODE bus observed which causes a bus fault*
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned ICODEFAULTADDR             : 32;
    } B;
} reg_control_icodefaultaddr_t;

#define REG_CONTROL_ICODEFAULTADDR_ADDR         (REG_CONTROL_BASEADDR + 0x000001C0UL)
#define REG_CONTROL_ICODEFAULTADDR              (*(volatile reg_control_icodefaultaddr_t *) REG_CONTROL_ICODEFAULTADDR_ADDR)
#define REG_CONTROL_ICODEFAULTADDR_RD()         (REG_CONTROL_ICODEFAULTADDR.U32)
#define REG_CONTROL_ICODEFAULTADDR_WR(v)        (REG_CONTROL_ICODEFAULTADDR.U32 = (v))
#define REG_CONTROL_ICODEFAULTADDR_CLR(m)       (REG_CONTROL_ICODEFAULTADDR.U32 = ((REG_CONTROL_ICODEFAULTADDR.U32) & ~(m)))
#define REG_CONTROL_ICODEFAULTADDR_SET(m)       (REG_CONTROL_ICODEFAULTADDR.U32 = ((REG_CONTROL_ICODEFAULTADDR.U32) | (m)))
#define REG_CONTROL_ICODEFAULTADDR_DEF          0x00000000

#define BFP_CONTROL_ICODEFAULTADDR_ICODEFAULTADDR (0)                     /* bitfield lsb */
#define BFM_CONTROL_ICODEFAULTADDR_ICODEFAULTADDR ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_CONTROL_ICODEFAULTADDR_ICODEFAULTADDR (32)                    /* bitfield width */
#define BFD_CONTROL_ICODEFAULTADDR_ICODEFAULTADDR (0x0)                   /* bitfield default value */
#define BFV_CONTROL_ICODEFAULTADDR_ICODEFAULTADDR(v) ((((uint32_t) v) << (BFP_CONTROL_ICODEFAULTADDR_ICODEFAULTADDR)) & (BFM_CONTROL_ICODEFAULTADDR_ICODEFAULTADDR))
#define BFX_CONTROL_ICODEFAULTADDR_ICODEFAULTADDR(v) ((((uint32_t) v) & (BFM_CONTROL_ICODEFAULTADDR_ICODEFAULTADDR)) >> (BFP_CONTROL_ICODEFAULTADDR_ICODEFAULTADDR))
#define BFW_CONTROL_ICODEFAULTADDR_ICODEFAULTADDR(v) (REG_CONTROL_ICODEFAULTADDR.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_ICODEFAULTADDR_ICODEFAULTADDR)) & (BFM_CONTROL_ICODEFAULTADDR_ICODEFAULTADDR)) )
#define BFR_CONTROL_ICODEFAULTADDR_ICODEFAULTADDR() ((REG_CONTROL_ICODEFAULTADDR.U32 & (BFM_CONTROL_ICODEFAULTADDR_ICODEFAULTADDR))>>(BFP_CONTROL_ICODEFAULTADDR_ICODEFAULTADDR))


// *****************************************************************************
//                                                                             *
//  CONTROL_DCODEFAULTADDR - Register to capture the address on the DCODE bus observed which causes a bus fault*
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned DCODEFAULTADDR             : 32;
    } B;
} reg_control_dcodefaultaddr_t;

#define REG_CONTROL_DCODEFAULTADDR_ADDR         (REG_CONTROL_BASEADDR + 0x000001C4UL)
#define REG_CONTROL_DCODEFAULTADDR              (*(volatile reg_control_dcodefaultaddr_t *) REG_CONTROL_DCODEFAULTADDR_ADDR)
#define REG_CONTROL_DCODEFAULTADDR_RD()         (REG_CONTROL_DCODEFAULTADDR.U32)
#define REG_CONTROL_DCODEFAULTADDR_WR(v)        (REG_CONTROL_DCODEFAULTADDR.U32 = (v))
#define REG_CONTROL_DCODEFAULTADDR_CLR(m)       (REG_CONTROL_DCODEFAULTADDR.U32 = ((REG_CONTROL_DCODEFAULTADDR.U32) & ~(m)))
#define REG_CONTROL_DCODEFAULTADDR_SET(m)       (REG_CONTROL_DCODEFAULTADDR.U32 = ((REG_CONTROL_DCODEFAULTADDR.U32) | (m)))
#define REG_CONTROL_DCODEFAULTADDR_DEF          0x00000000

#define BFP_CONTROL_DCODEFAULTADDR_DCODEFAULTADDR (0)                     /* bitfield lsb */
#define BFM_CONTROL_DCODEFAULTADDR_DCODEFAULTADDR ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_CONTROL_DCODEFAULTADDR_DCODEFAULTADDR (32)                    /* bitfield width */
#define BFD_CONTROL_DCODEFAULTADDR_DCODEFAULTADDR (0x0)                   /* bitfield default value */
#define BFV_CONTROL_DCODEFAULTADDR_DCODEFAULTADDR(v) ((((uint32_t) v) << (BFP_CONTROL_DCODEFAULTADDR_DCODEFAULTADDR)) & (BFM_CONTROL_DCODEFAULTADDR_DCODEFAULTADDR))
#define BFX_CONTROL_DCODEFAULTADDR_DCODEFAULTADDR(v) ((((uint32_t) v) & (BFM_CONTROL_DCODEFAULTADDR_DCODEFAULTADDR)) >> (BFP_CONTROL_DCODEFAULTADDR_DCODEFAULTADDR))
#define BFW_CONTROL_DCODEFAULTADDR_DCODEFAULTADDR(v) (REG_CONTROL_DCODEFAULTADDR.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_DCODEFAULTADDR_DCODEFAULTADDR)) & (BFM_CONTROL_DCODEFAULTADDR_DCODEFAULTADDR)) )
#define BFR_CONTROL_DCODEFAULTADDR_DCODEFAULTADDR() ((REG_CONTROL_DCODEFAULTADDR.U32 & (BFM_CONTROL_DCODEFAULTADDR_DCODEFAULTADDR))>>(BFP_CONTROL_DCODEFAULTADDR_DCODEFAULTADDR))


// *****************************************************************************
//                                                                             *
//  CONTROL_SYSFAULTADDR - Register to capture the address on the SYS bus observed which causes a bus fault*
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned SYSFAULTADDR               : 32;
    } B;
} reg_control_sysfaultaddr_t;

#define REG_CONTROL_SYSFAULTADDR_ADDR           (REG_CONTROL_BASEADDR + 0x000001C8UL)
#define REG_CONTROL_SYSFAULTADDR                (*(volatile reg_control_sysfaultaddr_t *) REG_CONTROL_SYSFAULTADDR_ADDR)
#define REG_CONTROL_SYSFAULTADDR_RD()           (REG_CONTROL_SYSFAULTADDR.U32)
#define REG_CONTROL_SYSFAULTADDR_WR(v)          (REG_CONTROL_SYSFAULTADDR.U32 = (v))
#define REG_CONTROL_SYSFAULTADDR_CLR(m)         (REG_CONTROL_SYSFAULTADDR.U32 = ((REG_CONTROL_SYSFAULTADDR.U32) & ~(m)))
#define REG_CONTROL_SYSFAULTADDR_SET(m)         (REG_CONTROL_SYSFAULTADDR.U32 = ((REG_CONTROL_SYSFAULTADDR.U32) | (m)))
#define REG_CONTROL_SYSFAULTADDR_DEF            0x00000000

#define BFP_CONTROL_SYSFAULTADDR_SYSFAULTADDR   (0)                     /* bitfield lsb */
#define BFM_CONTROL_SYSFAULTADDR_SYSFAULTADDR   ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_CONTROL_SYSFAULTADDR_SYSFAULTADDR   (32)                    /* bitfield width */
#define BFD_CONTROL_SYSFAULTADDR_SYSFAULTADDR   (0x0)                   /* bitfield default value */
#define BFV_CONTROL_SYSFAULTADDR_SYSFAULTADDR(v) ((((uint32_t) v) << (BFP_CONTROL_SYSFAULTADDR_SYSFAULTADDR)) & (BFM_CONTROL_SYSFAULTADDR_SYSFAULTADDR))
#define BFX_CONTROL_SYSFAULTADDR_SYSFAULTADDR(v) ((((uint32_t) v) & (BFM_CONTROL_SYSFAULTADDR_SYSFAULTADDR)) >> (BFP_CONTROL_SYSFAULTADDR_SYSFAULTADDR))
#define BFW_CONTROL_SYSFAULTADDR_SYSFAULTADDR(v) (REG_CONTROL_SYSFAULTADDR.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_SYSFAULTADDR_SYSFAULTADDR)) & (BFM_CONTROL_SYSFAULTADDR_SYSFAULTADDR)) )
#define BFR_CONTROL_SYSFAULTADDR_SYSFAULTADDR() ((REG_CONTROL_SYSFAULTADDR.U32 & (BFM_CONTROL_SYSFAULTADDR_SYSFAULTADDR))>>(BFP_CONTROL_SYSFAULTADDR_SYSFAULTADDR))


// *****************************************************************************
//                                                                             *
//  CONTROL_FAULTSTATUS - Register to reflect the status of the bus decoders' fault detection.*
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_3                     : 29;
        unsigned SYSFAULT                   :  1;
        unsigned DCODEFAULT                 :  1;
        unsigned ICODEFAULT                 :  1;
    } B;
} reg_control_faultstatus_t;

#define REG_CONTROL_FAULTSTATUS_ADDR            (REG_CONTROL_BASEADDR + 0x000001CCUL)
#define REG_CONTROL_FAULTSTATUS                 (*(volatile reg_control_faultstatus_t *) REG_CONTROL_FAULTSTATUS_ADDR)
#define REG_CONTROL_FAULTSTATUS_RD()            (REG_CONTROL_FAULTSTATUS.U32)
#define REG_CONTROL_FAULTSTATUS_WR(v)           (REG_CONTROL_FAULTSTATUS.U32 = (v))
#define REG_CONTROL_FAULTSTATUS_CLR(m)          (REG_CONTROL_FAULTSTATUS.U32 = ((REG_CONTROL_FAULTSTATUS.U32) & ~(m)))
#define REG_CONTROL_FAULTSTATUS_SET(m)          (REG_CONTROL_FAULTSTATUS.U32 = ((REG_CONTROL_FAULTSTATUS.U32) | (m)))
#define REG_CONTROL_FAULTSTATUS_DEF             0x00000000

#define BFP_CONTROL_FAULTSTATUS_RSVD_3          (3)                     /* bitfield lsb */
#define BFM_CONTROL_FAULTSTATUS_RSVD_3          ((uint32_t)0xfffffff8)  /* bitfield mask */
#define BFN_CONTROL_FAULTSTATUS_RSVD_3          (29)                    /* bitfield width */
#define BFD_CONTROL_FAULTSTATUS_RSVD_3          (0x0)                   /* bitfield default value */
#define BFV_CONTROL_FAULTSTATUS_RSVD_3(v)       ((((uint32_t) v) << (BFP_CONTROL_FAULTSTATUS_RSVD_3)) & (BFM_CONTROL_FAULTSTATUS_RSVD_3))
#define BFX_CONTROL_FAULTSTATUS_RSVD_3(v)       ((((uint32_t) v) & (BFM_CONTROL_FAULTSTATUS_RSVD_3)) >> (BFP_CONTROL_FAULTSTATUS_RSVD_3))
#define BFW_CONTROL_FAULTSTATUS_RSVD_3(v)       (REG_CONTROL_FAULTSTATUS.U32 = ( (REG_CONTROL_FAULTSTATUS.U32 & ~(BFM_CONTROL_FAULTSTATUS_RSVD_3)) | ((((uint32_t) v)<<(BFP_CONTROL_FAULTSTATUS_RSVD_3)) & (BFM_CONTROL_FAULTSTATUS_RSVD_3)) ))
#define BFR_CONTROL_FAULTSTATUS_RSVD_3()        ((REG_CONTROL_FAULTSTATUS.U32 & (BFM_CONTROL_FAULTSTATUS_RSVD_3))>>(BFP_CONTROL_FAULTSTATUS_RSVD_3))

#define BFP_CONTROL_FAULTSTATUS_SYSFAULT        (2)                     /* bitfield lsb */
#define BFM_CONTROL_FAULTSTATUS_SYSFAULT        ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_CONTROL_FAULTSTATUS_SYSFAULT        (1)                     /* bitfield width */
#define BFD_CONTROL_FAULTSTATUS_SYSFAULT        (0x0)                   /* bitfield default value */
#define BFV_CONTROL_FAULTSTATUS_SYSFAULT(v)     ((((uint32_t) v) << (BFP_CONTROL_FAULTSTATUS_SYSFAULT)) & (BFM_CONTROL_FAULTSTATUS_SYSFAULT))
#define BFX_CONTROL_FAULTSTATUS_SYSFAULT(v)     ((((uint32_t) v) & (BFM_CONTROL_FAULTSTATUS_SYSFAULT)) >> (BFP_CONTROL_FAULTSTATUS_SYSFAULT))
#define BFW_CONTROL_FAULTSTATUS_SYSFAULT(v)     (REG_CONTROL_FAULTSTATUS.U32 = ( (REG_CONTROL_FAULTSTATUS.U32 & ~(BFM_CONTROL_FAULTSTATUS_SYSFAULT)) | ((((uint32_t) v)<<(BFP_CONTROL_FAULTSTATUS_SYSFAULT)) & (BFM_CONTROL_FAULTSTATUS_SYSFAULT)) ))
#define BFR_CONTROL_FAULTSTATUS_SYSFAULT()      ((REG_CONTROL_FAULTSTATUS.U32 & (BFM_CONTROL_FAULTSTATUS_SYSFAULT))>>(BFP_CONTROL_FAULTSTATUS_SYSFAULT))

#define BFP_CONTROL_FAULTSTATUS_DCODEFAULT      (1)                     /* bitfield lsb */
#define BFM_CONTROL_FAULTSTATUS_DCODEFAULT      ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CONTROL_FAULTSTATUS_DCODEFAULT      (1)                     /* bitfield width */
#define BFD_CONTROL_FAULTSTATUS_DCODEFAULT      (0x0)                   /* bitfield default value */
#define BFV_CONTROL_FAULTSTATUS_DCODEFAULT(v)   ((((uint32_t) v) << (BFP_CONTROL_FAULTSTATUS_DCODEFAULT)) & (BFM_CONTROL_FAULTSTATUS_DCODEFAULT))
#define BFX_CONTROL_FAULTSTATUS_DCODEFAULT(v)   ((((uint32_t) v) & (BFM_CONTROL_FAULTSTATUS_DCODEFAULT)) >> (BFP_CONTROL_FAULTSTATUS_DCODEFAULT))
#define BFW_CONTROL_FAULTSTATUS_DCODEFAULT(v)   (REG_CONTROL_FAULTSTATUS.U32 = ( (REG_CONTROL_FAULTSTATUS.U32 & ~(BFM_CONTROL_FAULTSTATUS_DCODEFAULT)) | ((((uint32_t) v)<<(BFP_CONTROL_FAULTSTATUS_DCODEFAULT)) & (BFM_CONTROL_FAULTSTATUS_DCODEFAULT)) ))
#define BFR_CONTROL_FAULTSTATUS_DCODEFAULT()    ((REG_CONTROL_FAULTSTATUS.U32 & (BFM_CONTROL_FAULTSTATUS_DCODEFAULT))>>(BFP_CONTROL_FAULTSTATUS_DCODEFAULT))

#define BFP_CONTROL_FAULTSTATUS_ICODEFAULT      (0)                     /* bitfield lsb */
#define BFM_CONTROL_FAULTSTATUS_ICODEFAULT      ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_FAULTSTATUS_ICODEFAULT      (1)                     /* bitfield width */
#define BFD_CONTROL_FAULTSTATUS_ICODEFAULT      (0x0)                   /* bitfield default value */
#define BFV_CONTROL_FAULTSTATUS_ICODEFAULT(v)   ((((uint32_t) v) << (BFP_CONTROL_FAULTSTATUS_ICODEFAULT)) & (BFM_CONTROL_FAULTSTATUS_ICODEFAULT))
#define BFX_CONTROL_FAULTSTATUS_ICODEFAULT(v)   ((((uint32_t) v) & (BFM_CONTROL_FAULTSTATUS_ICODEFAULT)) >> (BFP_CONTROL_FAULTSTATUS_ICODEFAULT))
#define BFW_CONTROL_FAULTSTATUS_ICODEFAULT(v)   (REG_CONTROL_FAULTSTATUS.U32 = ( (REG_CONTROL_FAULTSTATUS.U32 & ~(BFM_CONTROL_FAULTSTATUS_ICODEFAULT)) | ((((uint32_t) v)<<(BFP_CONTROL_FAULTSTATUS_ICODEFAULT)) & (BFM_CONTROL_FAULTSTATUS_ICODEFAULT)) ))
#define BFR_CONTROL_FAULTSTATUS_ICODEFAULT()    ((REG_CONTROL_FAULTSTATUS.U32 & (BFM_CONTROL_FAULTSTATUS_ICODEFAULT))>>(BFP_CONTROL_FAULTSTATUS_ICODEFAULT))


// *****************************************************************************
//                                                                             *
//  CONTROL_FAULTCAPTUREEN - Register to enable the fault capture registers    *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_1                     : 31;
        unsigned FAULTCAPTUREEN             :  1;
    } B;
} reg_control_faultcaptureen_t;

#define REG_CONTROL_FAULTCAPTUREEN_ADDR         (REG_CONTROL_BASEADDR + 0x000001D0UL)
#define REG_CONTROL_FAULTCAPTUREEN              (*(volatile reg_control_faultcaptureen_t *) REG_CONTROL_FAULTCAPTUREEN_ADDR)
#define REG_CONTROL_FAULTCAPTUREEN_RD()         (REG_CONTROL_FAULTCAPTUREEN.U32)
#define REG_CONTROL_FAULTCAPTUREEN_WR(v)        (REG_CONTROL_FAULTCAPTUREEN.U32 = (v))
#define REG_CONTROL_FAULTCAPTUREEN_CLR(m)       (REG_CONTROL_FAULTCAPTUREEN.U32 = ((REG_CONTROL_FAULTCAPTUREEN.U32) & ~(m)))
#define REG_CONTROL_FAULTCAPTUREEN_SET(m)       (REG_CONTROL_FAULTCAPTUREEN.U32 = ((REG_CONTROL_FAULTCAPTUREEN.U32) | (m)))
#define REG_CONTROL_FAULTCAPTUREEN_DEF          0x00000000

#define BFP_CONTROL_FAULTCAPTUREEN_RSVD_1       (1)                     /* bitfield lsb */
#define BFM_CONTROL_FAULTCAPTUREEN_RSVD_1       ((uint32_t)0xfffffffe)  /* bitfield mask */
#define BFN_CONTROL_FAULTCAPTUREEN_RSVD_1       (31)                    /* bitfield width */
#define BFD_CONTROL_FAULTCAPTUREEN_RSVD_1       (0x0)                   /* bitfield default value */
#define BFV_CONTROL_FAULTCAPTUREEN_RSVD_1(v)    ((((uint32_t) v) << (BFP_CONTROL_FAULTCAPTUREEN_RSVD_1)) & (BFM_CONTROL_FAULTCAPTUREEN_RSVD_1))
#define BFX_CONTROL_FAULTCAPTUREEN_RSVD_1(v)    ((((uint32_t) v) & (BFM_CONTROL_FAULTCAPTUREEN_RSVD_1)) >> (BFP_CONTROL_FAULTCAPTUREEN_RSVD_1))
#define BFW_CONTROL_FAULTCAPTUREEN_RSVD_1(v)    (REG_CONTROL_FAULTCAPTUREEN.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_FAULTCAPTUREEN_RSVD_1)) & (BFM_CONTROL_FAULTCAPTUREEN_RSVD_1)) )
#define BFR_CONTROL_FAULTCAPTUREEN_RSVD_1()     ((REG_CONTROL_FAULTCAPTUREEN.U32 & (BFM_CONTROL_FAULTCAPTUREEN_RSVD_1))>>(BFP_CONTROL_FAULTCAPTUREEN_RSVD_1))

#define BFP_CONTROL_FAULTCAPTUREEN_FAULTCAPTUREEN (0)                     /* bitfield lsb */
#define BFM_CONTROL_FAULTCAPTUREEN_FAULTCAPTUREEN ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_FAULTCAPTUREEN_FAULTCAPTUREEN (1)                     /* bitfield width */
#define BFD_CONTROL_FAULTCAPTUREEN_FAULTCAPTUREEN (0x0)                   /* bitfield default value */
#define BFV_CONTROL_FAULTCAPTUREEN_FAULTCAPTUREEN(v) ((((uint32_t) v) << (BFP_CONTROL_FAULTCAPTUREEN_FAULTCAPTUREEN)) & (BFM_CONTROL_FAULTCAPTUREEN_FAULTCAPTUREEN))
#define BFX_CONTROL_FAULTCAPTUREEN_FAULTCAPTUREEN(v) ((((uint32_t) v) & (BFM_CONTROL_FAULTCAPTUREEN_FAULTCAPTUREEN)) >> (BFP_CONTROL_FAULTCAPTUREEN_FAULTCAPTUREEN))
#define BFW_CONTROL_FAULTCAPTUREEN_FAULTCAPTUREEN(v) (REG_CONTROL_FAULTCAPTUREEN.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_FAULTCAPTUREEN_FAULTCAPTUREEN)) & (BFM_CONTROL_FAULTCAPTUREEN_FAULTCAPTUREEN)) )
#define BFR_CONTROL_FAULTCAPTUREEN_FAULTCAPTUREEN() ((REG_CONTROL_FAULTCAPTUREEN.U32 & (BFM_CONTROL_FAULTCAPTUREEN_FAULTCAPTUREEN))>>(BFP_CONTROL_FAULTCAPTUREEN_FAULTCAPTUREEN))


// *****************************************************************************
//                                                                             *
//  CONTROL_PMUENABLE - Control bit to enable/disable the PMU                  *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_1                     : 31;
        unsigned PMUENABLE                  :  1;
    } B;
} reg_control_pmuenable_t;

#define REG_CONTROL_PMUENABLE_ADDR              (REG_CONTROL_BASEADDR + 0x00000220UL)
#define REG_CONTROL_PMUENABLE                   (*(volatile reg_control_pmuenable_t *) REG_CONTROL_PMUENABLE_ADDR)
#define REG_CONTROL_PMUENABLE_RD()              (REG_CONTROL_PMUENABLE.U32)
#define REG_CONTROL_PMUENABLE_WR(v)             (REG_CONTROL_PMUENABLE.U32 = (v))
#define REG_CONTROL_PMUENABLE_CLR(m)            (REG_CONTROL_PMUENABLE.U32 = ((REG_CONTROL_PMUENABLE.U32) & ~(m)))
#define REG_CONTROL_PMUENABLE_SET(m)            (REG_CONTROL_PMUENABLE.U32 = ((REG_CONTROL_PMUENABLE.U32) | (m)))
#define REG_CONTROL_PMUENABLE_DEF               0x00000001

#define BFP_CONTROL_PMUENABLE_RSVD_1            (1)                     /* bitfield lsb */
#define BFM_CONTROL_PMUENABLE_RSVD_1            ((uint32_t)0xfffffffe)  /* bitfield mask */
#define BFN_CONTROL_PMUENABLE_RSVD_1            (31)                    /* bitfield width */
#define BFD_CONTROL_PMUENABLE_RSVD_1            (0x0)                   /* bitfield default value */
#define BFV_CONTROL_PMUENABLE_RSVD_1(v)         ((((uint32_t) v) << (BFP_CONTROL_PMUENABLE_RSVD_1)) & (BFM_CONTROL_PMUENABLE_RSVD_1))
#define BFX_CONTROL_PMUENABLE_RSVD_1(v)         ((((uint32_t) v) & (BFM_CONTROL_PMUENABLE_RSVD_1)) >> (BFP_CONTROL_PMUENABLE_RSVD_1))
#define BFW_CONTROL_PMUENABLE_RSVD_1(v)         (REG_CONTROL_PMUENABLE.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_PMUENABLE_RSVD_1)) & (BFM_CONTROL_PMUENABLE_RSVD_1)) )
#define BFR_CONTROL_PMUENABLE_RSVD_1()          ((REG_CONTROL_PMUENABLE.U32 & (BFM_CONTROL_PMUENABLE_RSVD_1))>>(BFP_CONTROL_PMUENABLE_RSVD_1))

#define BFP_CONTROL_PMUENABLE_PMUENABLE         (0)                     /* bitfield lsb */
#define BFM_CONTROL_PMUENABLE_PMUENABLE         ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_PMUENABLE_PMUENABLE         (1)                     /* bitfield width */
#define BFD_CONTROL_PMUENABLE_PMUENABLE         (0x1)                   /* bitfield default value */
#define BFV_CONTROL_PMUENABLE_PMUENABLE(v)      ((((uint32_t) v) << (BFP_CONTROL_PMUENABLE_PMUENABLE)) & (BFM_CONTROL_PMUENABLE_PMUENABLE))
#define BFX_CONTROL_PMUENABLE_PMUENABLE(v)      ((((uint32_t) v) & (BFM_CONTROL_PMUENABLE_PMUENABLE)) >> (BFP_CONTROL_PMUENABLE_PMUENABLE))
#define BFW_CONTROL_PMUENABLE_PMUENABLE(v)      (REG_CONTROL_PMUENABLE.U32 = ( (((uint32_t) v)<<(BFP_CONTROL_PMUENABLE_PMUENABLE)) & (BFM_CONTROL_PMUENABLE_PMUENABLE)) )
#define BFR_CONTROL_PMUENABLE_PMUENABLE()       ((REG_CONTROL_PMUENABLE.U32 & (BFM_CONTROL_PMUENABLE_PMUENABLE))>>(BFP_CONTROL_PMUENABLE_PMUENABLE))


// *****************************************************************************
//                                                                             *
//  CONTROL_MISCDEVST - Miscellaneous Device State                             *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_2                     : 30;
        unsigned FABD                       :  1;
        unsigned SRAMWIPED                  :  1;
    } B;
} reg_control_miscdevst_t;

#define REG_CONTROL_MISCDEVST_ADDR              (REG_CONTROL_BASEADDR + 0x00000240UL)
#define REG_CONTROL_MISCDEVST                   (*(volatile reg_control_miscdevst_t *) REG_CONTROL_MISCDEVST_ADDR)
#define REG_CONTROL_MISCDEVST_RD()              (REG_CONTROL_MISCDEVST.U32)
#define REG_CONTROL_MISCDEVST_WR(v)             (REG_CONTROL_MISCDEVST.U32 = (v))
#define REG_CONTROL_MISCDEVST_CLR(m)            (REG_CONTROL_MISCDEVST.U32 = ((REG_CONTROL_MISCDEVST.U32) & ~(m)))
#define REG_CONTROL_MISCDEVST_SET(m)            (REG_CONTROL_MISCDEVST.U32 = ((REG_CONTROL_MISCDEVST.U32) | (m)))
#define REG_CONTROL_MISCDEVST_DEF               0x00000000

#define BFP_CONTROL_MISCDEVST_RSVD_2            (2)                     /* bitfield lsb */
#define BFM_CONTROL_MISCDEVST_RSVD_2            ((uint32_t)0xfffffffc)  /* bitfield mask */
#define BFN_CONTROL_MISCDEVST_RSVD_2            (30)                    /* bitfield width */
#define BFD_CONTROL_MISCDEVST_RSVD_2            (0x0)                   /* bitfield default value */
#define BFV_CONTROL_MISCDEVST_RSVD_2(v)         ((((uint32_t) v) << (BFP_CONTROL_MISCDEVST_RSVD_2)) & (BFM_CONTROL_MISCDEVST_RSVD_2))
#define BFX_CONTROL_MISCDEVST_RSVD_2(v)         ((((uint32_t) v) & (BFM_CONTROL_MISCDEVST_RSVD_2)) >> (BFP_CONTROL_MISCDEVST_RSVD_2))
#define BFW_CONTROL_MISCDEVST_RSVD_2(v)         (REG_CONTROL_MISCDEVST.U32 = ( (REG_CONTROL_MISCDEVST.U32 & ~(BFM_CONTROL_MISCDEVST_RSVD_2)) | ((((uint32_t) v)<<(BFP_CONTROL_MISCDEVST_RSVD_2)) & (BFM_CONTROL_MISCDEVST_RSVD_2)) ))
#define BFR_CONTROL_MISCDEVST_RSVD_2()          ((REG_CONTROL_MISCDEVST.U32 & (BFM_CONTROL_MISCDEVST_RSVD_2))>>(BFP_CONTROL_MISCDEVST_RSVD_2))

#define BFP_CONTROL_MISCDEVST_FABD              (1)                     /* bitfield lsb */
#define BFM_CONTROL_MISCDEVST_FABD              ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CONTROL_MISCDEVST_FABD              (1)                     /* bitfield width */
#define BFD_CONTROL_MISCDEVST_FABD              (0x0)                   /* bitfield default value */
#define BFV_CONTROL_MISCDEVST_FABD(v)           ((((uint32_t) v) << (BFP_CONTROL_MISCDEVST_FABD)) & (BFM_CONTROL_MISCDEVST_FABD))
#define BFX_CONTROL_MISCDEVST_FABD(v)           ((((uint32_t) v) & (BFM_CONTROL_MISCDEVST_FABD)) >> (BFP_CONTROL_MISCDEVST_FABD))
#define BFW_CONTROL_MISCDEVST_FABD(v)           (REG_CONTROL_MISCDEVST.U32 = ( (REG_CONTROL_MISCDEVST.U32 & ~(BFM_CONTROL_MISCDEVST_FABD)) | ((((uint32_t) v)<<(BFP_CONTROL_MISCDEVST_FABD)) & (BFM_CONTROL_MISCDEVST_FABD)) ))
#define BFR_CONTROL_MISCDEVST_FABD()            ((REG_CONTROL_MISCDEVST.U32 & (BFM_CONTROL_MISCDEVST_FABD))>>(BFP_CONTROL_MISCDEVST_FABD))

#define BFP_CONTROL_MISCDEVST_SRAMWIPED         (0)                     /* bitfield lsb */
#define BFM_CONTROL_MISCDEVST_SRAMWIPED         ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_MISCDEVST_SRAMWIPED         (1)                     /* bitfield width */
#define BFD_CONTROL_MISCDEVST_SRAMWIPED         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_MISCDEVST_SRAMWIPED(v)      ((((uint32_t) v) << (BFP_CONTROL_MISCDEVST_SRAMWIPED)) & (BFM_CONTROL_MISCDEVST_SRAMWIPED))
#define BFX_CONTROL_MISCDEVST_SRAMWIPED(v)      ((((uint32_t) v) & (BFM_CONTROL_MISCDEVST_SRAMWIPED)) >> (BFP_CONTROL_MISCDEVST_SRAMWIPED))
#define BFW_CONTROL_MISCDEVST_SRAMWIPED(v)      (REG_CONTROL_MISCDEVST.U32 = ( (REG_CONTROL_MISCDEVST.U32 & ~(BFM_CONTROL_MISCDEVST_SRAMWIPED)) | ((((uint32_t) v)<<(BFP_CONTROL_MISCDEVST_SRAMWIPED)) & (BFM_CONTROL_MISCDEVST_SRAMWIPED)) ))
#define BFR_CONTROL_MISCDEVST_SRAMWIPED()       ((REG_CONTROL_MISCDEVST.U32 & (BFM_CONTROL_MISCDEVST_SRAMWIPED))>>(BFP_CONTROL_MISCDEVST_SRAMWIPED))


// *****************************************************************************
//                                                                             *
//  CONTROL_TPIUCTRL - TPIU Clock Enable / Select                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD1                      : 22;
        unsigned TPIUCLKSEL                 :  2;
        unsigned RSVD0                      :  7;
        unsigned TPIUENABLE                 :  1;
    } B;
} reg_control_tpiuctrl_t;

#define REG_CONTROL_TPIUCTRL_ADDR               (REG_CONTROL_BASEADDR + 0x00000250UL)
#define REG_CONTROL_TPIUCTRL                    (*(volatile reg_control_tpiuctrl_t *) REG_CONTROL_TPIUCTRL_ADDR)
#define REG_CONTROL_TPIUCTRL_RD()               (REG_CONTROL_TPIUCTRL.U32)
#define REG_CONTROL_TPIUCTRL_WR(v)              (REG_CONTROL_TPIUCTRL.U32 = (v))
#define REG_CONTROL_TPIUCTRL_CLR(m)             (REG_CONTROL_TPIUCTRL.U32 = ((REG_CONTROL_TPIUCTRL.U32) & ~(m)))
#define REG_CONTROL_TPIUCTRL_SET(m)             (REG_CONTROL_TPIUCTRL.U32 = ((REG_CONTROL_TPIUCTRL.U32) | (m)))
#define REG_CONTROL_TPIUCTRL_DEF                0x00000000

#define BFP_CONTROL_TPIUCTRL_RSVD1_10           (10)                    /* bitfield lsb */
#define BFM_CONTROL_TPIUCTRL_RSVD1_10           ((uint32_t)0xfffffc00)  /* bitfield mask */
#define BFN_CONTROL_TPIUCTRL_RSVD1_10           (22)                    /* bitfield width */
#define BFD_CONTROL_TPIUCTRL_RSVD1_10           (0x0)                   /* bitfield default value */
#define BFV_CONTROL_TPIUCTRL_RSVD1_10(v)        ((((uint32_t) v) << (BFP_CONTROL_TPIUCTRL_RSVD1_10)) & (BFM_CONTROL_TPIUCTRL_RSVD1_10))
#define BFX_CONTROL_TPIUCTRL_RSVD1_10(v)        ((((uint32_t) v) & (BFM_CONTROL_TPIUCTRL_RSVD1_10)) >> (BFP_CONTROL_TPIUCTRL_RSVD1_10))
#define BFW_CONTROL_TPIUCTRL_RSVD1_10(v)        (REG_CONTROL_TPIUCTRL.U32 = ( (REG_CONTROL_TPIUCTRL.U32 & ~(BFM_CONTROL_TPIUCTRL_RSVD1_10)) | ((((uint32_t) v)<<(BFP_CONTROL_TPIUCTRL_RSVD1_10)) & (BFM_CONTROL_TPIUCTRL_RSVD1_10)) ))
#define BFR_CONTROL_TPIUCTRL_RSVD1_10()         ((REG_CONTROL_TPIUCTRL.U32 & (BFM_CONTROL_TPIUCTRL_RSVD1_10))>>(BFP_CONTROL_TPIUCTRL_RSVD1_10))

#define BFP_CONTROL_TPIUCTRL_TPIUCLKSEL         (8)                     /* bitfield lsb */
#define BFM_CONTROL_TPIUCTRL_TPIUCLKSEL         ((uint32_t)0x00000300)  /* bitfield mask */
#define BFN_CONTROL_TPIUCTRL_TPIUCLKSEL         (2)                     /* bitfield width */
#define BFD_CONTROL_TPIUCTRL_TPIUCLKSEL         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_TPIUCTRL_TPIUCLKSEL(v)      ((((uint32_t) v) << (BFP_CONTROL_TPIUCTRL_TPIUCLKSEL)) & (BFM_CONTROL_TPIUCTRL_TPIUCLKSEL))
#define BFX_CONTROL_TPIUCTRL_TPIUCLKSEL(v)      ((((uint32_t) v) & (BFM_CONTROL_TPIUCTRL_TPIUCLKSEL)) >> (BFP_CONTROL_TPIUCTRL_TPIUCLKSEL))
#define BFW_CONTROL_TPIUCTRL_TPIUCLKSEL(v)      (REG_CONTROL_TPIUCTRL.U32 = ( (REG_CONTROL_TPIUCTRL.U32 & ~(BFM_CONTROL_TPIUCTRL_TPIUCLKSEL)) | ((((uint32_t) v)<<(BFP_CONTROL_TPIUCTRL_TPIUCLKSEL)) & (BFM_CONTROL_TPIUCTRL_TPIUCLKSEL)) ))
#define BFR_CONTROL_TPIUCTRL_TPIUCLKSEL()       ((REG_CONTROL_TPIUCTRL.U32 & (BFM_CONTROL_TPIUCTRL_TPIUCLKSEL))>>(BFP_CONTROL_TPIUCTRL_TPIUCLKSEL))

#define BFP_CONTROL_TPIUCTRL_RSVD0_1            (1)                     /* bitfield lsb */
#define BFM_CONTROL_TPIUCTRL_RSVD0_1            ((uint32_t)0x000000fe)  /* bitfield mask */
#define BFN_CONTROL_TPIUCTRL_RSVD0_1            (7)                     /* bitfield width */
#define BFD_CONTROL_TPIUCTRL_RSVD0_1            (0x0)                   /* bitfield default value */
#define BFV_CONTROL_TPIUCTRL_RSVD0_1(v)         ((((uint32_t) v) << (BFP_CONTROL_TPIUCTRL_RSVD0_1)) & (BFM_CONTROL_TPIUCTRL_RSVD0_1))
#define BFX_CONTROL_TPIUCTRL_RSVD0_1(v)         ((((uint32_t) v) & (BFM_CONTROL_TPIUCTRL_RSVD0_1)) >> (BFP_CONTROL_TPIUCTRL_RSVD0_1))
#define BFW_CONTROL_TPIUCTRL_RSVD0_1(v)         (REG_CONTROL_TPIUCTRL.U32 = ( (REG_CONTROL_TPIUCTRL.U32 & ~(BFM_CONTROL_TPIUCTRL_RSVD0_1)) | ((((uint32_t) v)<<(BFP_CONTROL_TPIUCTRL_RSVD0_1)) & (BFM_CONTROL_TPIUCTRL_RSVD0_1)) ))
#define BFR_CONTROL_TPIUCTRL_RSVD0_1()          ((REG_CONTROL_TPIUCTRL.U32 & (BFM_CONTROL_TPIUCTRL_RSVD0_1))>>(BFP_CONTROL_TPIUCTRL_RSVD0_1))

#define BFP_CONTROL_TPIUCTRL_TPIUENABLE         (0)                     /* bitfield lsb */
#define BFM_CONTROL_TPIUCTRL_TPIUENABLE         ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CONTROL_TPIUCTRL_TPIUENABLE         (1)                     /* bitfield width */
#define BFD_CONTROL_TPIUCTRL_TPIUENABLE         (0x0)                   /* bitfield default value */
#define BFV_CONTROL_TPIUCTRL_TPIUENABLE(v)      ((((uint32_t) v) << (BFP_CONTROL_TPIUCTRL_TPIUENABLE)) & (BFM_CONTROL_TPIUCTRL_TPIUENABLE))
#define BFX_CONTROL_TPIUCTRL_TPIUENABLE(v)      ((((uint32_t) v) & (BFM_CONTROL_TPIUCTRL_TPIUENABLE)) >> (BFP_CONTROL_TPIUCTRL_TPIUENABLE))
#define BFW_CONTROL_TPIUCTRL_TPIUENABLE(v)      (REG_CONTROL_TPIUCTRL.U32 = ( (REG_CONTROL_TPIUCTRL.U32 & ~(BFM_CONTROL_TPIUCTRL_TPIUENABLE)) | ((((uint32_t) v)<<(BFP_CONTROL_TPIUCTRL_TPIUENABLE)) & (BFM_CONTROL_TPIUCTRL_TPIUENABLE)) ))
#define BFR_CONTROL_TPIUCTRL_TPIUENABLE()       ((REG_CONTROL_TPIUCTRL.U32 & (BFM_CONTROL_TPIUCTRL_TPIUENABLE))>>(BFP_CONTROL_TPIUCTRL_TPIUENABLE))

#define REG_CONTROL_LASTREG_ADDR                (REG_CONTROL_TPIUCTRL_ADDR)



#endif  // __CONTROL_H

