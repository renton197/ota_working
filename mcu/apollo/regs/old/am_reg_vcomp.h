/*******************************************************************************
*                                                                              *
*   Copyright (c) 2013-2014 Ambiq Micro                                        *
*                                                                              *
********************************************************************************
*                                                                              *
*   File:       vcomp.h                                                        *
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


#ifndef __VCOMP_H
#define __VCOMP_H

#include "../am_mcu_apollo.h"


// *****************************************************************************
//                                                                             *
//  VCOMP_VCMP_CFG - Configuration Register                                    *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_20                    : 12;
        unsigned LVLSEL                     :  4;
        unsigned RSVD_10                    :  6;
        unsigned NSEL                       :  2;
        unsigned RSVD_2                     :  6;
        unsigned PSEL                       :  2;
    } B;
} reg_vcomp_vcmp_cfg_t;

#define REG_VCOMP_VCMP_CFG_ADDR                 (REG_VCOMP_BASEADDR + 0x00000000UL)
#define REG_VCOMP_VCMP_CFG                      (*(volatile reg_vcomp_vcmp_cfg_t *) REG_VCOMP_VCMP_CFG_ADDR)
#define REG_VCOMP_VCMP_CFG_RD()                 (REG_VCOMP_VCMP_CFG.U32)
#define REG_VCOMP_VCMP_CFG_WR(v)                (REG_VCOMP_VCMP_CFG.U32 = (v))
#define REG_VCOMP_VCMP_CFG_CLR(m)               (REG_VCOMP_VCMP_CFG.U32 = ((REG_VCOMP_VCMP_CFG.U32) & ~(m)))
#define REG_VCOMP_VCMP_CFG_SET(m)               (REG_VCOMP_VCMP_CFG.U32 = ((REG_VCOMP_VCMP_CFG.U32) | (m)))
#define REG_VCOMP_VCMP_CFG_DEF                  0x00000000

#define BFP_VCOMP_VCMP_CFG_RSVD_20              (20)                    /* bitfield lsb */
#define BFM_VCOMP_VCMP_CFG_RSVD_20              ((uint32_t)0xfff00000)  /* bitfield mask */
#define BFN_VCOMP_VCMP_CFG_RSVD_20              (12)                    /* bitfield width */
#define BFD_VCOMP_VCMP_CFG_RSVD_20              (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_CFG_RSVD_20(v)           ((((uint32_t) v) << (BFP_VCOMP_VCMP_CFG_RSVD_20)) & (BFM_VCOMP_VCMP_CFG_RSVD_20))
#define BFX_VCOMP_VCMP_CFG_RSVD_20(v)           ((((uint32_t) v) & (BFM_VCOMP_VCMP_CFG_RSVD_20)) >> (BFP_VCOMP_VCMP_CFG_RSVD_20))
#define BFW_VCOMP_VCMP_CFG_RSVD_20(v)           (REG_VCOMP_VCMP_CFG.U32 = ( (REG_VCOMP_VCMP_CFG.U32 & ~(BFM_VCOMP_VCMP_CFG_RSVD_20)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_CFG_RSVD_20)) & (BFM_VCOMP_VCMP_CFG_RSVD_20)) ))
#define BFR_VCOMP_VCMP_CFG_RSVD_20()            ((REG_VCOMP_VCMP_CFG.U32 & (BFM_VCOMP_VCMP_CFG_RSVD_20))>>(BFP_VCOMP_VCMP_CFG_RSVD_20))

#define BFP_VCOMP_VCMP_CFG_LVLSEL               (16)                    /* bitfield lsb */
#define BFM_VCOMP_VCMP_CFG_LVLSEL               ((uint32_t)0x000f0000)  /* bitfield mask */
#define BFN_VCOMP_VCMP_CFG_LVLSEL               (4)                     /* bitfield width */
#define BFD_VCOMP_VCMP_CFG_LVLSEL               (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_CFG_LVLSEL(v)            ((((uint32_t) v) << (BFP_VCOMP_VCMP_CFG_LVLSEL)) & (BFM_VCOMP_VCMP_CFG_LVLSEL))
#define BFX_VCOMP_VCMP_CFG_LVLSEL(v)            ((((uint32_t) v) & (BFM_VCOMP_VCMP_CFG_LVLSEL)) >> (BFP_VCOMP_VCMP_CFG_LVLSEL))
#define BFW_VCOMP_VCMP_CFG_LVLSEL(v)            (REG_VCOMP_VCMP_CFG.U32 = ( (REG_VCOMP_VCMP_CFG.U32 & ~(BFM_VCOMP_VCMP_CFG_LVLSEL)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_CFG_LVLSEL)) & (BFM_VCOMP_VCMP_CFG_LVLSEL)) ))
#define BFR_VCOMP_VCMP_CFG_LVLSEL()             ((REG_VCOMP_VCMP_CFG.U32 & (BFM_VCOMP_VCMP_CFG_LVLSEL))>>(BFP_VCOMP_VCMP_CFG_LVLSEL))

#define BFP_VCOMP_VCMP_CFG_RSVD_10              (10)                    /* bitfield lsb */
#define BFM_VCOMP_VCMP_CFG_RSVD_10              ((uint32_t)0x0000fc00)  /* bitfield mask */
#define BFN_VCOMP_VCMP_CFG_RSVD_10              (6)                     /* bitfield width */
#define BFD_VCOMP_VCMP_CFG_RSVD_10              (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_CFG_RSVD_10(v)           ((((uint32_t) v) << (BFP_VCOMP_VCMP_CFG_RSVD_10)) & (BFM_VCOMP_VCMP_CFG_RSVD_10))
#define BFX_VCOMP_VCMP_CFG_RSVD_10(v)           ((((uint32_t) v) & (BFM_VCOMP_VCMP_CFG_RSVD_10)) >> (BFP_VCOMP_VCMP_CFG_RSVD_10))
#define BFW_VCOMP_VCMP_CFG_RSVD_10(v)           (REG_VCOMP_VCMP_CFG.U32 = ( (REG_VCOMP_VCMP_CFG.U32 & ~(BFM_VCOMP_VCMP_CFG_RSVD_10)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_CFG_RSVD_10)) & (BFM_VCOMP_VCMP_CFG_RSVD_10)) ))
#define BFR_VCOMP_VCMP_CFG_RSVD_10()            ((REG_VCOMP_VCMP_CFG.U32 & (BFM_VCOMP_VCMP_CFG_RSVD_10))>>(BFP_VCOMP_VCMP_CFG_RSVD_10))

#define BFP_VCOMP_VCMP_CFG_NSEL                 (8)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_CFG_NSEL                 ((uint32_t)0x00000300)  /* bitfield mask */
#define BFN_VCOMP_VCMP_CFG_NSEL                 (2)                     /* bitfield width */
#define BFD_VCOMP_VCMP_CFG_NSEL                 (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_CFG_NSEL(v)              ((((uint32_t) v) << (BFP_VCOMP_VCMP_CFG_NSEL)) & (BFM_VCOMP_VCMP_CFG_NSEL))
#define BFX_VCOMP_VCMP_CFG_NSEL(v)              ((((uint32_t) v) & (BFM_VCOMP_VCMP_CFG_NSEL)) >> (BFP_VCOMP_VCMP_CFG_NSEL))
#define BFW_VCOMP_VCMP_CFG_NSEL(v)              (REG_VCOMP_VCMP_CFG.U32 = ( (REG_VCOMP_VCMP_CFG.U32 & ~(BFM_VCOMP_VCMP_CFG_NSEL)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_CFG_NSEL)) & (BFM_VCOMP_VCMP_CFG_NSEL)) ))
#define BFR_VCOMP_VCMP_CFG_NSEL()               ((REG_VCOMP_VCMP_CFG.U32 & (BFM_VCOMP_VCMP_CFG_NSEL))>>(BFP_VCOMP_VCMP_CFG_NSEL))

#define BFP_VCOMP_VCMP_CFG_RSVD_2               (2)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_CFG_RSVD_2               ((uint32_t)0x000000fc)  /* bitfield mask */
#define BFN_VCOMP_VCMP_CFG_RSVD_2               (6)                     /* bitfield width */
#define BFD_VCOMP_VCMP_CFG_RSVD_2               (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_CFG_RSVD_2(v)            ((((uint32_t) v) << (BFP_VCOMP_VCMP_CFG_RSVD_2)) & (BFM_VCOMP_VCMP_CFG_RSVD_2))
#define BFX_VCOMP_VCMP_CFG_RSVD_2(v)            ((((uint32_t) v) & (BFM_VCOMP_VCMP_CFG_RSVD_2)) >> (BFP_VCOMP_VCMP_CFG_RSVD_2))
#define BFW_VCOMP_VCMP_CFG_RSVD_2(v)            (REG_VCOMP_VCMP_CFG.U32 = ( (REG_VCOMP_VCMP_CFG.U32 & ~(BFM_VCOMP_VCMP_CFG_RSVD_2)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_CFG_RSVD_2)) & (BFM_VCOMP_VCMP_CFG_RSVD_2)) ))
#define BFR_VCOMP_VCMP_CFG_RSVD_2()             ((REG_VCOMP_VCMP_CFG.U32 & (BFM_VCOMP_VCMP_CFG_RSVD_2))>>(BFP_VCOMP_VCMP_CFG_RSVD_2))

#define BFP_VCOMP_VCMP_CFG_PSEL                 (0)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_CFG_PSEL                 ((uint32_t)0x00000003)  /* bitfield mask */
#define BFN_VCOMP_VCMP_CFG_PSEL                 (2)                     /* bitfield width */
#define BFD_VCOMP_VCMP_CFG_PSEL                 (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_CFG_PSEL(v)              ((((uint32_t) v) << (BFP_VCOMP_VCMP_CFG_PSEL)) & (BFM_VCOMP_VCMP_CFG_PSEL))
#define BFX_VCOMP_VCMP_CFG_PSEL(v)              ((((uint32_t) v) & (BFM_VCOMP_VCMP_CFG_PSEL)) >> (BFP_VCOMP_VCMP_CFG_PSEL))
#define BFW_VCOMP_VCMP_CFG_PSEL(v)              (REG_VCOMP_VCMP_CFG.U32 = ( (REG_VCOMP_VCMP_CFG.U32 & ~(BFM_VCOMP_VCMP_CFG_PSEL)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_CFG_PSEL)) & (BFM_VCOMP_VCMP_CFG_PSEL)) ))
#define BFR_VCOMP_VCMP_CFG_PSEL()               ((REG_VCOMP_VCMP_CFG.U32 & (BFM_VCOMP_VCMP_CFG_PSEL))>>(BFP_VCOMP_VCMP_CFG_PSEL))


// *****************************************************************************
//                                                                             *
//  VCOMP_VCMP_STAT - Status Register                                          *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_2                     : 30;
        unsigned PWDSTAT                    :  1;
        unsigned CMPOUT                     :  1;
    } B;
} reg_vcomp_vcmp_stat_t;

#define REG_VCOMP_VCMP_STAT_ADDR                (REG_VCOMP_BASEADDR + 0x00000004UL)
#define REG_VCOMP_VCMP_STAT                     (*(volatile reg_vcomp_vcmp_stat_t *) REG_VCOMP_VCMP_STAT_ADDR)
#define REG_VCOMP_VCMP_STAT_RD()                (REG_VCOMP_VCMP_STAT.U32)
#define REG_VCOMP_VCMP_STAT_WR(v)               (REG_VCOMP_VCMP_STAT.U32 = (v))
#define REG_VCOMP_VCMP_STAT_CLR(m)              (REG_VCOMP_VCMP_STAT.U32 = ((REG_VCOMP_VCMP_STAT.U32) & ~(m)))
#define REG_VCOMP_VCMP_STAT_SET(m)              (REG_VCOMP_VCMP_STAT.U32 = ((REG_VCOMP_VCMP_STAT.U32) | (m)))
#define REG_VCOMP_VCMP_STAT_DEF                 0x00000000

#define BFP_VCOMP_VCMP_STAT_RSVD_2              (2)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_STAT_RSVD_2              ((uint32_t)0xfffffffc)  /* bitfield mask */
#define BFN_VCOMP_VCMP_STAT_RSVD_2              (30)                    /* bitfield width */
#define BFD_VCOMP_VCMP_STAT_RSVD_2              (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_STAT_RSVD_2(v)           ((((uint32_t) v) << (BFP_VCOMP_VCMP_STAT_RSVD_2)) & (BFM_VCOMP_VCMP_STAT_RSVD_2))
#define BFX_VCOMP_VCMP_STAT_RSVD_2(v)           ((((uint32_t) v) & (BFM_VCOMP_VCMP_STAT_RSVD_2)) >> (BFP_VCOMP_VCMP_STAT_RSVD_2))
#define BFW_VCOMP_VCMP_STAT_RSVD_2(v)           (REG_VCOMP_VCMP_STAT.U32 = ( (REG_VCOMP_VCMP_STAT.U32 & ~(BFM_VCOMP_VCMP_STAT_RSVD_2)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_STAT_RSVD_2)) & (BFM_VCOMP_VCMP_STAT_RSVD_2)) ))
#define BFR_VCOMP_VCMP_STAT_RSVD_2()            ((REG_VCOMP_VCMP_STAT.U32 & (BFM_VCOMP_VCMP_STAT_RSVD_2))>>(BFP_VCOMP_VCMP_STAT_RSVD_2))

#define BFP_VCOMP_VCMP_STAT_PWDSTAT             (1)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_STAT_PWDSTAT             ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_VCOMP_VCMP_STAT_PWDSTAT             (1)                     /* bitfield width */
#define BFD_VCOMP_VCMP_STAT_PWDSTAT             (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_STAT_PWDSTAT(v)          ((((uint32_t) v) << (BFP_VCOMP_VCMP_STAT_PWDSTAT)) & (BFM_VCOMP_VCMP_STAT_PWDSTAT))
#define BFX_VCOMP_VCMP_STAT_PWDSTAT(v)          ((((uint32_t) v) & (BFM_VCOMP_VCMP_STAT_PWDSTAT)) >> (BFP_VCOMP_VCMP_STAT_PWDSTAT))
#define BFW_VCOMP_VCMP_STAT_PWDSTAT(v)          (REG_VCOMP_VCMP_STAT.U32 = ( (REG_VCOMP_VCMP_STAT.U32 & ~(BFM_VCOMP_VCMP_STAT_PWDSTAT)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_STAT_PWDSTAT)) & (BFM_VCOMP_VCMP_STAT_PWDSTAT)) ))
#define BFR_VCOMP_VCMP_STAT_PWDSTAT()           ((REG_VCOMP_VCMP_STAT.U32 & (BFM_VCOMP_VCMP_STAT_PWDSTAT))>>(BFP_VCOMP_VCMP_STAT_PWDSTAT))

#define BFP_VCOMP_VCMP_STAT_CMPOUT              (0)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_STAT_CMPOUT              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_VCOMP_VCMP_STAT_CMPOUT              (1)                     /* bitfield width */
#define BFD_VCOMP_VCMP_STAT_CMPOUT              (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_STAT_CMPOUT(v)           ((((uint32_t) v) << (BFP_VCOMP_VCMP_STAT_CMPOUT)) & (BFM_VCOMP_VCMP_STAT_CMPOUT))
#define BFX_VCOMP_VCMP_STAT_CMPOUT(v)           ((((uint32_t) v) & (BFM_VCOMP_VCMP_STAT_CMPOUT)) >> (BFP_VCOMP_VCMP_STAT_CMPOUT))
#define BFW_VCOMP_VCMP_STAT_CMPOUT(v)           (REG_VCOMP_VCMP_STAT.U32 = ( (REG_VCOMP_VCMP_STAT.U32 & ~(BFM_VCOMP_VCMP_STAT_CMPOUT)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_STAT_CMPOUT)) & (BFM_VCOMP_VCMP_STAT_CMPOUT)) ))
#define BFR_VCOMP_VCMP_STAT_CMPOUT()            ((REG_VCOMP_VCMP_STAT.U32 & (BFM_VCOMP_VCMP_STAT_CMPOUT))>>(BFP_VCOMP_VCMP_STAT_CMPOUT))


// *****************************************************************************
//                                                                             *
//  VCOMP_VCMP_PWDKEY - Key Register for Powering Down the Voltage Comparator  *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_0                     : 32;
    } B;
} reg_vcomp_vcmp_pwdkey_t;

#define REG_VCOMP_VCMP_PWDKEY_ADDR              (REG_VCOMP_BASEADDR + 0x00000008UL)
#define REG_VCOMP_VCMP_PWDKEY                   (*(volatile reg_vcomp_vcmp_pwdkey_t *) REG_VCOMP_VCMP_PWDKEY_ADDR)
#define REG_VCOMP_VCMP_PWDKEY_RD()              (REG_VCOMP_VCMP_PWDKEY.U32)
#define REG_VCOMP_VCMP_PWDKEY_WR(v)             (REG_VCOMP_VCMP_PWDKEY.U32 = (v))
#define REG_VCOMP_VCMP_PWDKEY_CLR(m)            (REG_VCOMP_VCMP_PWDKEY.U32 = ((REG_VCOMP_VCMP_PWDKEY.U32) & ~(m)))
#define REG_VCOMP_VCMP_PWDKEY_SET(m)            (REG_VCOMP_VCMP_PWDKEY.U32 = ((REG_VCOMP_VCMP_PWDKEY.U32) | (m)))
#define REG_VCOMP_VCMP_PWDKEY_DEF               0x00000000


// *****************************************************************************
//                                                                             *
//  VCOMP_VCMP_IEREN - Votage Comparator Interrupt registers                   *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_2                     : 30;
        unsigned OUTHI                      :  1;
        unsigned OUTLOW                     :  1;
    } B;
} reg_vcomp_vcmp_ieren_t;

#define REG_VCOMP_VCMP_IEREN_ADDR               (REG_VCOMP_BASEADDR + 0x00000200UL)
#define REG_VCOMP_VCMP_IEREN                    (*(volatile reg_vcomp_vcmp_ieren_t *) REG_VCOMP_VCMP_IEREN_ADDR)
#define REG_VCOMP_VCMP_IEREN_RD()               (REG_VCOMP_VCMP_IEREN.U32)
#define REG_VCOMP_VCMP_IEREN_WR(v)              (REG_VCOMP_VCMP_IEREN.U32 = (v))
#define REG_VCOMP_VCMP_IEREN_CLR(m)             (REG_VCOMP_VCMP_IEREN.U32 = ((REG_VCOMP_VCMP_IEREN.U32) & ~(m)))
#define REG_VCOMP_VCMP_IEREN_SET(m)             (REG_VCOMP_VCMP_IEREN.U32 = ((REG_VCOMP_VCMP_IEREN.U32) | (m)))
#define REG_VCOMP_VCMP_IEREN_DEF                0x00000000

#define BFP_VCOMP_VCMP_IEREN_RSVD_2             (2)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_IEREN_RSVD_2             ((uint32_t)0xfffffffc)  /* bitfield mask */
#define BFN_VCOMP_VCMP_IEREN_RSVD_2             (30)                    /* bitfield width */
#define BFD_VCOMP_VCMP_IEREN_RSVD_2             (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_IEREN_RSVD_2(v)          ((((uint32_t) v) << (BFP_VCOMP_VCMP_IEREN_RSVD_2)) & (BFM_VCOMP_VCMP_IEREN_RSVD_2))
#define BFX_VCOMP_VCMP_IEREN_RSVD_2(v)          ((((uint32_t) v) & (BFM_VCOMP_VCMP_IEREN_RSVD_2)) >> (BFP_VCOMP_VCMP_IEREN_RSVD_2))
#define BFW_VCOMP_VCMP_IEREN_RSVD_2(v)          (REG_VCOMP_VCMP_IEREN.U32 = ( (REG_VCOMP_VCMP_IEREN.U32 & ~(BFM_VCOMP_VCMP_IEREN_RSVD_2)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_IEREN_RSVD_2)) & (BFM_VCOMP_VCMP_IEREN_RSVD_2)) ))
#define BFR_VCOMP_VCMP_IEREN_RSVD_2()           ((REG_VCOMP_VCMP_IEREN.U32 & (BFM_VCOMP_VCMP_IEREN_RSVD_2))>>(BFP_VCOMP_VCMP_IEREN_RSVD_2))

#define BFP_VCOMP_VCMP_IEREN_OUTHI              (1)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_IEREN_OUTHI              ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_VCOMP_VCMP_IEREN_OUTHI              (1)                     /* bitfield width */
#define BFD_VCOMP_VCMP_IEREN_OUTHI              (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_IEREN_OUTHI(v)           ((((uint32_t) v) << (BFP_VCOMP_VCMP_IEREN_OUTHI)) & (BFM_VCOMP_VCMP_IEREN_OUTHI))
#define BFX_VCOMP_VCMP_IEREN_OUTHI(v)           ((((uint32_t) v) & (BFM_VCOMP_VCMP_IEREN_OUTHI)) >> (BFP_VCOMP_VCMP_IEREN_OUTHI))
#define BFW_VCOMP_VCMP_IEREN_OUTHI(v)           (REG_VCOMP_VCMP_IEREN.U32 = ( (REG_VCOMP_VCMP_IEREN.U32 & ~(BFM_VCOMP_VCMP_IEREN_OUTHI)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_IEREN_OUTHI)) & (BFM_VCOMP_VCMP_IEREN_OUTHI)) ))
#define BFR_VCOMP_VCMP_IEREN_OUTHI()            ((REG_VCOMP_VCMP_IEREN.U32 & (BFM_VCOMP_VCMP_IEREN_OUTHI))>>(BFP_VCOMP_VCMP_IEREN_OUTHI))

#define BFP_VCOMP_VCMP_IEREN_OUTLOW             (0)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_IEREN_OUTLOW             ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_VCOMP_VCMP_IEREN_OUTLOW             (1)                     /* bitfield width */
#define BFD_VCOMP_VCMP_IEREN_OUTLOW             (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_IEREN_OUTLOW(v)          ((((uint32_t) v) << (BFP_VCOMP_VCMP_IEREN_OUTLOW)) & (BFM_VCOMP_VCMP_IEREN_OUTLOW))
#define BFX_VCOMP_VCMP_IEREN_OUTLOW(v)          ((((uint32_t) v) & (BFM_VCOMP_VCMP_IEREN_OUTLOW)) >> (BFP_VCOMP_VCMP_IEREN_OUTLOW))
#define BFW_VCOMP_VCMP_IEREN_OUTLOW(v)          (REG_VCOMP_VCMP_IEREN.U32 = ( (REG_VCOMP_VCMP_IEREN.U32 & ~(BFM_VCOMP_VCMP_IEREN_OUTLOW)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_IEREN_OUTLOW)) & (BFM_VCOMP_VCMP_IEREN_OUTLOW)) ))
#define BFR_VCOMP_VCMP_IEREN_OUTLOW()           ((REG_VCOMP_VCMP_IEREN.U32 & (BFM_VCOMP_VCMP_IEREN_OUTLOW))>>(BFP_VCOMP_VCMP_IEREN_OUTLOW))


// *****************************************************************************
//                                                                             *
//  VCOMP_VCMP_IERSTAT - Votage Comparator Interrupt registers                 *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_2                     : 30;
        unsigned OUTHI                      :  1;
        unsigned OUTLOW                     :  1;
    } B;
} reg_vcomp_vcmp_ierstat_t;

#define REG_VCOMP_VCMP_IERSTAT_ADDR             (REG_VCOMP_BASEADDR + 0x00000204UL)
#define REG_VCOMP_VCMP_IERSTAT                  (*(volatile reg_vcomp_vcmp_ierstat_t *) REG_VCOMP_VCMP_IERSTAT_ADDR)
#define REG_VCOMP_VCMP_IERSTAT_RD()             (REG_VCOMP_VCMP_IERSTAT.U32)
#define REG_VCOMP_VCMP_IERSTAT_WR(v)            (REG_VCOMP_VCMP_IERSTAT.U32 = (v))
#define REG_VCOMP_VCMP_IERSTAT_CLR(m)           (REG_VCOMP_VCMP_IERSTAT.U32 = ((REG_VCOMP_VCMP_IERSTAT.U32) & ~(m)))
#define REG_VCOMP_VCMP_IERSTAT_SET(m)           (REG_VCOMP_VCMP_IERSTAT.U32 = ((REG_VCOMP_VCMP_IERSTAT.U32) | (m)))
#define REG_VCOMP_VCMP_IERSTAT_DEF              0x00000000

#define BFP_VCOMP_VCMP_IERSTAT_RSVD_2           (2)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_IERSTAT_RSVD_2           ((uint32_t)0xfffffffc)  /* bitfield mask */
#define BFN_VCOMP_VCMP_IERSTAT_RSVD_2           (30)                    /* bitfield width */
#define BFD_VCOMP_VCMP_IERSTAT_RSVD_2           (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_IERSTAT_RSVD_2(v)        ((((uint32_t) v) << (BFP_VCOMP_VCMP_IERSTAT_RSVD_2)) & (BFM_VCOMP_VCMP_IERSTAT_RSVD_2))
#define BFX_VCOMP_VCMP_IERSTAT_RSVD_2(v)        ((((uint32_t) v) & (BFM_VCOMP_VCMP_IERSTAT_RSVD_2)) >> (BFP_VCOMP_VCMP_IERSTAT_RSVD_2))
#define BFW_VCOMP_VCMP_IERSTAT_RSVD_2(v)        (REG_VCOMP_VCMP_IERSTAT.U32 = ( (REG_VCOMP_VCMP_IERSTAT.U32 & ~(BFM_VCOMP_VCMP_IERSTAT_RSVD_2)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_IERSTAT_RSVD_2)) & (BFM_VCOMP_VCMP_IERSTAT_RSVD_2)) ))
#define BFR_VCOMP_VCMP_IERSTAT_RSVD_2()         ((REG_VCOMP_VCMP_IERSTAT.U32 & (BFM_VCOMP_VCMP_IERSTAT_RSVD_2))>>(BFP_VCOMP_VCMP_IERSTAT_RSVD_2))

#define BFP_VCOMP_VCMP_IERSTAT_OUTHI            (1)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_IERSTAT_OUTHI            ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_VCOMP_VCMP_IERSTAT_OUTHI            (1)                     /* bitfield width */
#define BFD_VCOMP_VCMP_IERSTAT_OUTHI            (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_IERSTAT_OUTHI(v)         ((((uint32_t) v) << (BFP_VCOMP_VCMP_IERSTAT_OUTHI)) & (BFM_VCOMP_VCMP_IERSTAT_OUTHI))
#define BFX_VCOMP_VCMP_IERSTAT_OUTHI(v)         ((((uint32_t) v) & (BFM_VCOMP_VCMP_IERSTAT_OUTHI)) >> (BFP_VCOMP_VCMP_IERSTAT_OUTHI))
#define BFW_VCOMP_VCMP_IERSTAT_OUTHI(v)         (REG_VCOMP_VCMP_IERSTAT.U32 = ( (REG_VCOMP_VCMP_IERSTAT.U32 & ~(BFM_VCOMP_VCMP_IERSTAT_OUTHI)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_IERSTAT_OUTHI)) & (BFM_VCOMP_VCMP_IERSTAT_OUTHI)) ))
#define BFR_VCOMP_VCMP_IERSTAT_OUTHI()          ((REG_VCOMP_VCMP_IERSTAT.U32 & (BFM_VCOMP_VCMP_IERSTAT_OUTHI))>>(BFP_VCOMP_VCMP_IERSTAT_OUTHI))

#define BFP_VCOMP_VCMP_IERSTAT_OUTLOW           (0)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_IERSTAT_OUTLOW           ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_VCOMP_VCMP_IERSTAT_OUTLOW           (1)                     /* bitfield width */
#define BFD_VCOMP_VCMP_IERSTAT_OUTLOW           (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_IERSTAT_OUTLOW(v)        ((((uint32_t) v) << (BFP_VCOMP_VCMP_IERSTAT_OUTLOW)) & (BFM_VCOMP_VCMP_IERSTAT_OUTLOW))
#define BFX_VCOMP_VCMP_IERSTAT_OUTLOW(v)        ((((uint32_t) v) & (BFM_VCOMP_VCMP_IERSTAT_OUTLOW)) >> (BFP_VCOMP_VCMP_IERSTAT_OUTLOW))
#define BFW_VCOMP_VCMP_IERSTAT_OUTLOW(v)        (REG_VCOMP_VCMP_IERSTAT.U32 = ( (REG_VCOMP_VCMP_IERSTAT.U32 & ~(BFM_VCOMP_VCMP_IERSTAT_OUTLOW)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_IERSTAT_OUTLOW)) & (BFM_VCOMP_VCMP_IERSTAT_OUTLOW)) ))
#define BFR_VCOMP_VCMP_IERSTAT_OUTLOW()         ((REG_VCOMP_VCMP_IERSTAT.U32 & (BFM_VCOMP_VCMP_IERSTAT_OUTLOW))>>(BFP_VCOMP_VCMP_IERSTAT_OUTLOW))


// *****************************************************************************
//                                                                             *
//  VCOMP_VCMP_IERCLR - Votage Comparator Interrupt registers                  *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_2                     : 30;
        unsigned OUTHI                      :  1;
        unsigned OUTLOW                     :  1;
    } B;
} reg_vcomp_vcmp_ierclr_t;

#define REG_VCOMP_VCMP_IERCLR_ADDR              (REG_VCOMP_BASEADDR + 0x00000208UL)
#define REG_VCOMP_VCMP_IERCLR                   (*(volatile reg_vcomp_vcmp_ierclr_t *) REG_VCOMP_VCMP_IERCLR_ADDR)
#define REG_VCOMP_VCMP_IERCLR_RD()              (REG_VCOMP_VCMP_IERCLR.U32)
#define REG_VCOMP_VCMP_IERCLR_WR(v)             (REG_VCOMP_VCMP_IERCLR.U32 = (v))
#define REG_VCOMP_VCMP_IERCLR_CLR(m)            (REG_VCOMP_VCMP_IERCLR.U32 = ((REG_VCOMP_VCMP_IERCLR.U32) & ~(m)))
#define REG_VCOMP_VCMP_IERCLR_SET(m)            (REG_VCOMP_VCMP_IERCLR.U32 = ((REG_VCOMP_VCMP_IERCLR.U32) | (m)))
#define REG_VCOMP_VCMP_IERCLR_DEF               0x00000000

#define BFP_VCOMP_VCMP_IERCLR_RSVD_2            (2)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_IERCLR_RSVD_2            ((uint32_t)0xfffffffc)  /* bitfield mask */
#define BFN_VCOMP_VCMP_IERCLR_RSVD_2            (30)                    /* bitfield width */
#define BFD_VCOMP_VCMP_IERCLR_RSVD_2            (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_IERCLR_RSVD_2(v)         ((((uint32_t) v) << (BFP_VCOMP_VCMP_IERCLR_RSVD_2)) & (BFM_VCOMP_VCMP_IERCLR_RSVD_2))
#define BFX_VCOMP_VCMP_IERCLR_RSVD_2(v)         ((((uint32_t) v) & (BFM_VCOMP_VCMP_IERCLR_RSVD_2)) >> (BFP_VCOMP_VCMP_IERCLR_RSVD_2))
#define BFW_VCOMP_VCMP_IERCLR_RSVD_2(v)         (REG_VCOMP_VCMP_IERCLR.U32 = ( (REG_VCOMP_VCMP_IERCLR.U32 & ~(BFM_VCOMP_VCMP_IERCLR_RSVD_2)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_IERCLR_RSVD_2)) & (BFM_VCOMP_VCMP_IERCLR_RSVD_2)) ))
#define BFR_VCOMP_VCMP_IERCLR_RSVD_2()          ((REG_VCOMP_VCMP_IERCLR.U32 & (BFM_VCOMP_VCMP_IERCLR_RSVD_2))>>(BFP_VCOMP_VCMP_IERCLR_RSVD_2))

#define BFP_VCOMP_VCMP_IERCLR_OUTHI             (1)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_IERCLR_OUTHI             ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_VCOMP_VCMP_IERCLR_OUTHI             (1)                     /* bitfield width */
#define BFD_VCOMP_VCMP_IERCLR_OUTHI             (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_IERCLR_OUTHI(v)          ((((uint32_t) v) << (BFP_VCOMP_VCMP_IERCLR_OUTHI)) & (BFM_VCOMP_VCMP_IERCLR_OUTHI))
#define BFX_VCOMP_VCMP_IERCLR_OUTHI(v)          ((((uint32_t) v) & (BFM_VCOMP_VCMP_IERCLR_OUTHI)) >> (BFP_VCOMP_VCMP_IERCLR_OUTHI))
#define BFW_VCOMP_VCMP_IERCLR_OUTHI(v)          (REG_VCOMP_VCMP_IERCLR.U32 = ( (REG_VCOMP_VCMP_IERCLR.U32 & ~(BFM_VCOMP_VCMP_IERCLR_OUTHI)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_IERCLR_OUTHI)) & (BFM_VCOMP_VCMP_IERCLR_OUTHI)) ))
#define BFR_VCOMP_VCMP_IERCLR_OUTHI()           ((REG_VCOMP_VCMP_IERCLR.U32 & (BFM_VCOMP_VCMP_IERCLR_OUTHI))>>(BFP_VCOMP_VCMP_IERCLR_OUTHI))

#define BFP_VCOMP_VCMP_IERCLR_OUTLOW            (0)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_IERCLR_OUTLOW            ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_VCOMP_VCMP_IERCLR_OUTLOW            (1)                     /* bitfield width */
#define BFD_VCOMP_VCMP_IERCLR_OUTLOW            (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_IERCLR_OUTLOW(v)         ((((uint32_t) v) << (BFP_VCOMP_VCMP_IERCLR_OUTLOW)) & (BFM_VCOMP_VCMP_IERCLR_OUTLOW))
#define BFX_VCOMP_VCMP_IERCLR_OUTLOW(v)         ((((uint32_t) v) & (BFM_VCOMP_VCMP_IERCLR_OUTLOW)) >> (BFP_VCOMP_VCMP_IERCLR_OUTLOW))
#define BFW_VCOMP_VCMP_IERCLR_OUTLOW(v)         (REG_VCOMP_VCMP_IERCLR.U32 = ( (REG_VCOMP_VCMP_IERCLR.U32 & ~(BFM_VCOMP_VCMP_IERCLR_OUTLOW)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_IERCLR_OUTLOW)) & (BFM_VCOMP_VCMP_IERCLR_OUTLOW)) ))
#define BFR_VCOMP_VCMP_IERCLR_OUTLOW()          ((REG_VCOMP_VCMP_IERCLR.U32 & (BFM_VCOMP_VCMP_IERCLR_OUTLOW))>>(BFP_VCOMP_VCMP_IERCLR_OUTLOW))


// *****************************************************************************
//                                                                             *
//  VCOMP_VCMP_IERSET - Votage Comparator Interrupt registers                  *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_2                     : 30;
        unsigned OUTHI                      :  1;
        unsigned OUTLOW                     :  1;
    } B;
} reg_vcomp_vcmp_ierset_t;

#define REG_VCOMP_VCMP_IERSET_ADDR              (REG_VCOMP_BASEADDR + 0x0000020CUL)
#define REG_VCOMP_VCMP_IERSET                   (*(volatile reg_vcomp_vcmp_ierset_t *) REG_VCOMP_VCMP_IERSET_ADDR)
#define REG_VCOMP_VCMP_IERSET_RD()              (REG_VCOMP_VCMP_IERSET.U32)
#define REG_VCOMP_VCMP_IERSET_WR(v)             (REG_VCOMP_VCMP_IERSET.U32 = (v))
#define REG_VCOMP_VCMP_IERSET_CLR(m)            (REG_VCOMP_VCMP_IERSET.U32 = ((REG_VCOMP_VCMP_IERSET.U32) & ~(m)))
#define REG_VCOMP_VCMP_IERSET_SET(m)            (REG_VCOMP_VCMP_IERSET.U32 = ((REG_VCOMP_VCMP_IERSET.U32) | (m)))
#define REG_VCOMP_VCMP_IERSET_DEF               0x00000000

#define BFP_VCOMP_VCMP_IERSET_RSVD_2            (2)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_IERSET_RSVD_2            ((uint32_t)0xfffffffc)  /* bitfield mask */
#define BFN_VCOMP_VCMP_IERSET_RSVD_2            (30)                    /* bitfield width */
#define BFD_VCOMP_VCMP_IERSET_RSVD_2            (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_IERSET_RSVD_2(v)         ((((uint32_t) v) << (BFP_VCOMP_VCMP_IERSET_RSVD_2)) & (BFM_VCOMP_VCMP_IERSET_RSVD_2))
#define BFX_VCOMP_VCMP_IERSET_RSVD_2(v)         ((((uint32_t) v) & (BFM_VCOMP_VCMP_IERSET_RSVD_2)) >> (BFP_VCOMP_VCMP_IERSET_RSVD_2))
#define BFW_VCOMP_VCMP_IERSET_RSVD_2(v)         (REG_VCOMP_VCMP_IERSET.U32 = ( (REG_VCOMP_VCMP_IERSET.U32 & ~(BFM_VCOMP_VCMP_IERSET_RSVD_2)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_IERSET_RSVD_2)) & (BFM_VCOMP_VCMP_IERSET_RSVD_2)) ))
#define BFR_VCOMP_VCMP_IERSET_RSVD_2()          ((REG_VCOMP_VCMP_IERSET.U32 & (BFM_VCOMP_VCMP_IERSET_RSVD_2))>>(BFP_VCOMP_VCMP_IERSET_RSVD_2))

#define BFP_VCOMP_VCMP_IERSET_OUTHI             (1)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_IERSET_OUTHI             ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_VCOMP_VCMP_IERSET_OUTHI             (1)                     /* bitfield width */
#define BFD_VCOMP_VCMP_IERSET_OUTHI             (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_IERSET_OUTHI(v)          ((((uint32_t) v) << (BFP_VCOMP_VCMP_IERSET_OUTHI)) & (BFM_VCOMP_VCMP_IERSET_OUTHI))
#define BFX_VCOMP_VCMP_IERSET_OUTHI(v)          ((((uint32_t) v) & (BFM_VCOMP_VCMP_IERSET_OUTHI)) >> (BFP_VCOMP_VCMP_IERSET_OUTHI))
#define BFW_VCOMP_VCMP_IERSET_OUTHI(v)          (REG_VCOMP_VCMP_IERSET.U32 = ( (REG_VCOMP_VCMP_IERSET.U32 & ~(BFM_VCOMP_VCMP_IERSET_OUTHI)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_IERSET_OUTHI)) & (BFM_VCOMP_VCMP_IERSET_OUTHI)) ))
#define BFR_VCOMP_VCMP_IERSET_OUTHI()           ((REG_VCOMP_VCMP_IERSET.U32 & (BFM_VCOMP_VCMP_IERSET_OUTHI))>>(BFP_VCOMP_VCMP_IERSET_OUTHI))

#define BFP_VCOMP_VCMP_IERSET_OUTLOW            (0)                     /* bitfield lsb */
#define BFM_VCOMP_VCMP_IERSET_OUTLOW            ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_VCOMP_VCMP_IERSET_OUTLOW            (1)                     /* bitfield width */
#define BFD_VCOMP_VCMP_IERSET_OUTLOW            (0x0)                   /* bitfield default value */
#define BFV_VCOMP_VCMP_IERSET_OUTLOW(v)         ((((uint32_t) v) << (BFP_VCOMP_VCMP_IERSET_OUTLOW)) & (BFM_VCOMP_VCMP_IERSET_OUTLOW))
#define BFX_VCOMP_VCMP_IERSET_OUTLOW(v)         ((((uint32_t) v) & (BFM_VCOMP_VCMP_IERSET_OUTLOW)) >> (BFP_VCOMP_VCMP_IERSET_OUTLOW))
#define BFW_VCOMP_VCMP_IERSET_OUTLOW(v)         (REG_VCOMP_VCMP_IERSET.U32 = ( (REG_VCOMP_VCMP_IERSET.U32 & ~(BFM_VCOMP_VCMP_IERSET_OUTLOW)) | ((((uint32_t) v)<<(BFP_VCOMP_VCMP_IERSET_OUTLOW)) & (BFM_VCOMP_VCMP_IERSET_OUTLOW)) ))
#define BFR_VCOMP_VCMP_IERSET_OUTLOW()          ((REG_VCOMP_VCMP_IERSET.U32 & (BFM_VCOMP_VCMP_IERSET_OUTLOW))>>(BFP_VCOMP_VCMP_IERSET_OUTLOW))




#endif  // __VCOMP_H

