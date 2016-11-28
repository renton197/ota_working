/*******************************************************************************
*                                                                              *
*   Copyright (c) 2013-2014 Ambiq Micro                                        *
*                                                                              *
********************************************************************************
*                                                                              *
*   File:       rstgen.h                                                       *
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


#ifndef __RSTGEN_REGS_H
#define __RSTGEN_REGS_H

#include "../am_mcu_apollo.h"


// *****************************************************************************
//                                                                             *
//  RSTGEN_RST_CFG - Configuration Register                                    *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_2                     : 30;
        unsigned WDREN                      :  1;
        unsigned BODHREN                    :  1;
    } B;
} reg_rstgen_rst_cfg_t;

#define REG_RSTGEN_RST_CFG_ADDR                 (REG_RSTGEN_BASEADDR + 0x00000000UL)
#define REG_RSTGEN_RST_CFG                      (*(volatile reg_rstgen_rst_cfg_t *) REG_RSTGEN_RST_CFG_ADDR)
#define REG_RSTGEN_RST_CFG_RD()                 (REG_RSTGEN_RST_CFG.U32)
#define REG_RSTGEN_RST_CFG_WR(v)                (REG_RSTGEN_RST_CFG.U32 = (v))
#define REG_RSTGEN_RST_CFG_CLR(m)               (REG_RSTGEN_RST_CFG.U32 = ((REG_RSTGEN_RST_CFG.U32) & ~(m)))
#define REG_RSTGEN_RST_CFG_SET(m)               (REG_RSTGEN_RST_CFG.U32 = ((REG_RSTGEN_RST_CFG.U32) | (m)))
#define REG_RSTGEN_RST_CFG_DEF                  0x00000000

#define BFP_RSTGEN_RST_CFG_RSVD_2               (2)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_CFG_RSVD_2               ((uint32_t)0xfffffffc)  /* bitfield mask */
#define BFN_RSTGEN_RST_CFG_RSVD_2               (30)                    /* bitfield width */
#define BFD_RSTGEN_RST_CFG_RSVD_2               (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_CFG_RSVD_2(v)            ((((uint32_t) v) << (BFP_RSTGEN_RST_CFG_RSVD_2)) & (BFM_RSTGEN_RST_CFG_RSVD_2))
#define BFX_RSTGEN_RST_CFG_RSVD_2(v)            ((((uint32_t) v) & (BFM_RSTGEN_RST_CFG_RSVD_2)) >> (BFP_RSTGEN_RST_CFG_RSVD_2))
#define BFW_RSTGEN_RST_CFG_RSVD_2(v)            (REG_RSTGEN_RST_CFG.U32 = ( (REG_RSTGEN_RST_CFG.U32 & ~(BFM_RSTGEN_RST_CFG_RSVD_2)) | ((((uint32_t) v)<<(BFP_RSTGEN_RST_CFG_RSVD_2)) & (BFM_RSTGEN_RST_CFG_RSVD_2)) ))
#define BFR_RSTGEN_RST_CFG_RSVD_2()             ((REG_RSTGEN_RST_CFG.U32 & (BFM_RSTGEN_RST_CFG_RSVD_2))>>(BFP_RSTGEN_RST_CFG_RSVD_2))

#define BFP_RSTGEN_RST_CFG_WDREN                (1)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_CFG_WDREN                ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_RSTGEN_RST_CFG_WDREN                (1)                     /* bitfield width */
#define BFD_RSTGEN_RST_CFG_WDREN                (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_CFG_WDREN(v)             ((((uint32_t) v) << (BFP_RSTGEN_RST_CFG_WDREN)) & (BFM_RSTGEN_RST_CFG_WDREN))
#define BFX_RSTGEN_RST_CFG_WDREN(v)             ((((uint32_t) v) & (BFM_RSTGEN_RST_CFG_WDREN)) >> (BFP_RSTGEN_RST_CFG_WDREN))
#define BFW_RSTGEN_RST_CFG_WDREN(v)             (REG_RSTGEN_RST_CFG.U32 = ( (REG_RSTGEN_RST_CFG.U32 & ~(BFM_RSTGEN_RST_CFG_WDREN)) | ((((uint32_t) v)<<(BFP_RSTGEN_RST_CFG_WDREN)) & (BFM_RSTGEN_RST_CFG_WDREN)) ))
#define BFR_RSTGEN_RST_CFG_WDREN()              ((REG_RSTGEN_RST_CFG.U32 & (BFM_RSTGEN_RST_CFG_WDREN))>>(BFP_RSTGEN_RST_CFG_WDREN))

#define BFP_RSTGEN_RST_CFG_BODHREN              (0)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_CFG_BODHREN              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_RSTGEN_RST_CFG_BODHREN              (1)                     /* bitfield width */
#define BFD_RSTGEN_RST_CFG_BODHREN              (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_CFG_BODHREN(v)           ((((uint32_t) v) << (BFP_RSTGEN_RST_CFG_BODHREN)) & (BFM_RSTGEN_RST_CFG_BODHREN))
#define BFX_RSTGEN_RST_CFG_BODHREN(v)           ((((uint32_t) v) & (BFM_RSTGEN_RST_CFG_BODHREN)) >> (BFP_RSTGEN_RST_CFG_BODHREN))
#define BFW_RSTGEN_RST_CFG_BODHREN(v)           (REG_RSTGEN_RST_CFG.U32 = ( (REG_RSTGEN_RST_CFG.U32 & ~(BFM_RSTGEN_RST_CFG_BODHREN)) | ((((uint32_t) v)<<(BFP_RSTGEN_RST_CFG_BODHREN)) & (BFM_RSTGEN_RST_CFG_BODHREN)) ))
#define BFR_RSTGEN_RST_CFG_BODHREN()            ((REG_RSTGEN_RST_CFG.U32 & (BFM_RSTGEN_RST_CFG_BODHREN))>>(BFP_RSTGEN_RST_CFG_BODHREN))


// *****************************************************************************
//                                                                             *
//  RSTGEN_SWPOI - Software POI Reset                                          *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned SWPOIKEY                   :  8;
    } B;
} reg_rstgen_swpoi_t;

#define REG_RSTGEN_SWPOI_ADDR                   (REG_RSTGEN_BASEADDR + 0x00000004UL)
#define REG_RSTGEN_SWPOI                        (*(volatile reg_rstgen_swpoi_t *) REG_RSTGEN_SWPOI_ADDR)
#define REG_RSTGEN_SWPOI_RD()                   (REG_RSTGEN_SWPOI.U32)
#define REG_RSTGEN_SWPOI_WR(v)                  (REG_RSTGEN_SWPOI.U32 = (v))
#define REG_RSTGEN_SWPOI_CLR(m)                 (REG_RSTGEN_SWPOI.U32 = ((REG_RSTGEN_SWPOI.U32) & ~(m)))
#define REG_RSTGEN_SWPOI_SET(m)                 (REG_RSTGEN_SWPOI.U32 = ((REG_RSTGEN_SWPOI.U32) | (m)))
#define REG_RSTGEN_SWPOI_DEF                    0x00000000

#define BFP_RSTGEN_SWPOI_RSVD_8                 (8)                     /* bitfield lsb */
#define BFM_RSTGEN_SWPOI_RSVD_8                 ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_RSTGEN_SWPOI_RSVD_8                 (24)                    /* bitfield width */
#define BFD_RSTGEN_SWPOI_RSVD_8                 (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_SWPOI_RSVD_8(v)              ((((uint32_t) v) << (BFP_RSTGEN_SWPOI_RSVD_8)) & (BFM_RSTGEN_SWPOI_RSVD_8))
#define BFX_RSTGEN_SWPOI_RSVD_8(v)              ((((uint32_t) v) & (BFM_RSTGEN_SWPOI_RSVD_8)) >> (BFP_RSTGEN_SWPOI_RSVD_8))
#define BFW_RSTGEN_SWPOI_RSVD_8(v)              (REG_RSTGEN_SWPOI.U32 = ( (((uint32_t) v)<<(BFP_RSTGEN_SWPOI_RSVD_8)) & (BFM_RSTGEN_SWPOI_RSVD_8)) )
#define BFR_RSTGEN_SWPOI_RSVD_8()               ((REG_RSTGEN_SWPOI.U32 & (BFM_RSTGEN_SWPOI_RSVD_8))>>(BFP_RSTGEN_SWPOI_RSVD_8))

#define BFP_RSTGEN_SWPOI_SWPOIKEY               (0)                     /* bitfield lsb */
#define BFM_RSTGEN_SWPOI_SWPOIKEY               ((uint32_t)0x000000ff)  /* bitfield mask */
#define BFN_RSTGEN_SWPOI_SWPOIKEY               (8)                     /* bitfield width */
#define BFD_RSTGEN_SWPOI_SWPOIKEY               (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_SWPOI_SWPOIKEY(v)            ((((uint32_t) v) << (BFP_RSTGEN_SWPOI_SWPOIKEY)) & (BFM_RSTGEN_SWPOI_SWPOIKEY))
#define BFX_RSTGEN_SWPOI_SWPOIKEY(v)            ((((uint32_t) v) & (BFM_RSTGEN_SWPOI_SWPOIKEY)) >> (BFP_RSTGEN_SWPOI_SWPOIKEY))
#define BFW_RSTGEN_SWPOI_SWPOIKEY(v)            (REG_RSTGEN_SWPOI.U32 = ( (((uint32_t) v)<<(BFP_RSTGEN_SWPOI_SWPOIKEY)) & (BFM_RSTGEN_SWPOI_SWPOIKEY)) )
#define BFR_RSTGEN_SWPOI_SWPOIKEY()             ((REG_RSTGEN_SWPOI.U32 & (BFM_RSTGEN_SWPOI_SWPOIKEY))>>(BFP_RSTGEN_SWPOI_SWPOIKEY))


// *****************************************************************************
//                                                                             *
//  RSTGEN_SWPOR - Software POR Reset                                          *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned SWPORKEY                   :  8;
    } B;
} reg_rstgen_swpor_t;

#define REG_RSTGEN_SWPOR_ADDR                   (REG_RSTGEN_BASEADDR + 0x00000008UL)
#define REG_RSTGEN_SWPOR                        (*(volatile reg_rstgen_swpor_t *) REG_RSTGEN_SWPOR_ADDR)
#define REG_RSTGEN_SWPOR_RD()                   (REG_RSTGEN_SWPOR.U32)
#define REG_RSTGEN_SWPOR_WR(v)                  (REG_RSTGEN_SWPOR.U32 = (v))
#define REG_RSTGEN_SWPOR_CLR(m)                 (REG_RSTGEN_SWPOR.U32 = ((REG_RSTGEN_SWPOR.U32) & ~(m)))
#define REG_RSTGEN_SWPOR_SET(m)                 (REG_RSTGEN_SWPOR.U32 = ((REG_RSTGEN_SWPOR.U32) | (m)))
#define REG_RSTGEN_SWPOR_DEF                    0x00000000

#define BFP_RSTGEN_SWPOR_RSVD_8                 (8)                     /* bitfield lsb */
#define BFM_RSTGEN_SWPOR_RSVD_8                 ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_RSTGEN_SWPOR_RSVD_8                 (24)                    /* bitfield width */
#define BFD_RSTGEN_SWPOR_RSVD_8                 (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_SWPOR_RSVD_8(v)              ((((uint32_t) v) << (BFP_RSTGEN_SWPOR_RSVD_8)) & (BFM_RSTGEN_SWPOR_RSVD_8))
#define BFX_RSTGEN_SWPOR_RSVD_8(v)              ((((uint32_t) v) & (BFM_RSTGEN_SWPOR_RSVD_8)) >> (BFP_RSTGEN_SWPOR_RSVD_8))
#define BFW_RSTGEN_SWPOR_RSVD_8(v)              (REG_RSTGEN_SWPOR.U32 = ( (((uint32_t) v)<<(BFP_RSTGEN_SWPOR_RSVD_8)) & (BFM_RSTGEN_SWPOR_RSVD_8)) )
#define BFR_RSTGEN_SWPOR_RSVD_8()               ((REG_RSTGEN_SWPOR.U32 & (BFM_RSTGEN_SWPOR_RSVD_8))>>(BFP_RSTGEN_SWPOR_RSVD_8))

#define BFP_RSTGEN_SWPOR_SWPORKEY               (0)                     /* bitfield lsb */
#define BFM_RSTGEN_SWPOR_SWPORKEY               ((uint32_t)0x000000ff)  /* bitfield mask */
#define BFN_RSTGEN_SWPOR_SWPORKEY               (8)                     /* bitfield width */
#define BFD_RSTGEN_SWPOR_SWPORKEY               (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_SWPOR_SWPORKEY(v)            ((((uint32_t) v) << (BFP_RSTGEN_SWPOR_SWPORKEY)) & (BFM_RSTGEN_SWPOR_SWPORKEY))
#define BFX_RSTGEN_SWPOR_SWPORKEY(v)            ((((uint32_t) v) & (BFM_RSTGEN_SWPOR_SWPORKEY)) >> (BFP_RSTGEN_SWPOR_SWPORKEY))
#define BFW_RSTGEN_SWPOR_SWPORKEY(v)            (REG_RSTGEN_SWPOR.U32 = ( (((uint32_t) v)<<(BFP_RSTGEN_SWPOR_SWPORKEY)) & (BFM_RSTGEN_SWPOR_SWPORKEY)) )
#define BFR_RSTGEN_SWPOR_SWPORKEY()             ((REG_RSTGEN_SWPOR.U32 & (BFM_RSTGEN_SWPOR_SWPORKEY))>>(BFP_RSTGEN_SWPOR_SWPORKEY))


// *****************************************************************************
//                                                                             *
//  RSTGEN_RST_STAT - Status Register                                          *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_7                     : 25;
        unsigned WDRSTAT                    :  1;
        unsigned DBGRSTAT                   :  1;
        unsigned POIRSTAT                   :  1;
        unsigned SWRSTAT                    :  1;
        unsigned BORSTAT                    :  1;
        unsigned PORSTAT                    :  1;
        unsigned EXRSTAT                    :  1;
    } B;
} reg_rstgen_rst_stat_t;

#define REG_RSTGEN_RST_STAT_ADDR                (REG_RSTGEN_BASEADDR + 0x0000000CUL)
#define REG_RSTGEN_RST_STAT                     (*(volatile reg_rstgen_rst_stat_t *) REG_RSTGEN_RST_STAT_ADDR)
#define REG_RSTGEN_RST_STAT_RD()                (REG_RSTGEN_RST_STAT.U32)
#define REG_RSTGEN_RST_STAT_WR(v)               (REG_RSTGEN_RST_STAT.U32 = (v))
#define REG_RSTGEN_RST_STAT_CLR(m)              (REG_RSTGEN_RST_STAT.U32 = ((REG_RSTGEN_RST_STAT.U32) & ~(m)))
#define REG_RSTGEN_RST_STAT_SET(m)              (REG_RSTGEN_RST_STAT.U32 = ((REG_RSTGEN_RST_STAT.U32) | (m)))
#define REG_RSTGEN_RST_STAT_DEF                 0x00000000

#define BFP_RSTGEN_RST_STAT_RSVD_7              (7)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_STAT_RSVD_7              ((uint32_t)0xffffff80)  /* bitfield mask */
#define BFN_RSTGEN_RST_STAT_RSVD_7              (25)                    /* bitfield width */
#define BFD_RSTGEN_RST_STAT_RSVD_7              (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_STAT_RSVD_7(v)           ((((uint32_t) v) << (BFP_RSTGEN_RST_STAT_RSVD_7)) & (BFM_RSTGEN_RST_STAT_RSVD_7))
#define BFX_RSTGEN_RST_STAT_RSVD_7(v)           ((((uint32_t) v) & (BFM_RSTGEN_RST_STAT_RSVD_7)) >> (BFP_RSTGEN_RST_STAT_RSVD_7))
#define BFW_RSTGEN_RST_STAT_RSVD_7(v)           (REG_RSTGEN_RST_STAT.U32 = ( (REG_RSTGEN_RST_STAT.U32 & ~(BFM_RSTGEN_RST_STAT_RSVD_7)) | ((((uint32_t) v)<<(BFP_RSTGEN_RST_STAT_RSVD_7)) & (BFM_RSTGEN_RST_STAT_RSVD_7)) ))
#define BFR_RSTGEN_RST_STAT_RSVD_7()            ((REG_RSTGEN_RST_STAT.U32 & (BFM_RSTGEN_RST_STAT_RSVD_7))>>(BFP_RSTGEN_RST_STAT_RSVD_7))

#define BFP_RSTGEN_RST_STAT_WDRSTAT             (6)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_STAT_WDRSTAT             ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_RSTGEN_RST_STAT_WDRSTAT             (1)                     /* bitfield width */
#define BFD_RSTGEN_RST_STAT_WDRSTAT             (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_STAT_WDRSTAT(v)          ((((uint32_t) v) << (BFP_RSTGEN_RST_STAT_WDRSTAT)) & (BFM_RSTGEN_RST_STAT_WDRSTAT))
#define BFX_RSTGEN_RST_STAT_WDRSTAT(v)          ((((uint32_t) v) & (BFM_RSTGEN_RST_STAT_WDRSTAT)) >> (BFP_RSTGEN_RST_STAT_WDRSTAT))
#define BFW_RSTGEN_RST_STAT_WDRSTAT(v)          (REG_RSTGEN_RST_STAT.U32 = ( (REG_RSTGEN_RST_STAT.U32 & ~(BFM_RSTGEN_RST_STAT_WDRSTAT)) | ((((uint32_t) v)<<(BFP_RSTGEN_RST_STAT_WDRSTAT)) & (BFM_RSTGEN_RST_STAT_WDRSTAT)) ))
#define BFR_RSTGEN_RST_STAT_WDRSTAT()           ((REG_RSTGEN_RST_STAT.U32 & (BFM_RSTGEN_RST_STAT_WDRSTAT))>>(BFP_RSTGEN_RST_STAT_WDRSTAT))

#define BFP_RSTGEN_RST_STAT_DBGRSTAT            (5)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_STAT_DBGRSTAT            ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_RSTGEN_RST_STAT_DBGRSTAT            (1)                     /* bitfield width */
#define BFD_RSTGEN_RST_STAT_DBGRSTAT            (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_STAT_DBGRSTAT(v)         ((((uint32_t) v) << (BFP_RSTGEN_RST_STAT_DBGRSTAT)) & (BFM_RSTGEN_RST_STAT_DBGRSTAT))
#define BFX_RSTGEN_RST_STAT_DBGRSTAT(v)         ((((uint32_t) v) & (BFM_RSTGEN_RST_STAT_DBGRSTAT)) >> (BFP_RSTGEN_RST_STAT_DBGRSTAT))
#define BFW_RSTGEN_RST_STAT_DBGRSTAT(v)         (REG_RSTGEN_RST_STAT.U32 = ( (REG_RSTGEN_RST_STAT.U32 & ~(BFM_RSTGEN_RST_STAT_DBGRSTAT)) | ((((uint32_t) v)<<(BFP_RSTGEN_RST_STAT_DBGRSTAT)) & (BFM_RSTGEN_RST_STAT_DBGRSTAT)) ))
#define BFR_RSTGEN_RST_STAT_DBGRSTAT()          ((REG_RSTGEN_RST_STAT.U32 & (BFM_RSTGEN_RST_STAT_DBGRSTAT))>>(BFP_RSTGEN_RST_STAT_DBGRSTAT))

#define BFP_RSTGEN_RST_STAT_POIRSTAT            (4)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_STAT_POIRSTAT            ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_RSTGEN_RST_STAT_POIRSTAT            (1)                     /* bitfield width */
#define BFD_RSTGEN_RST_STAT_POIRSTAT            (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_STAT_POIRSTAT(v)         ((((uint32_t) v) << (BFP_RSTGEN_RST_STAT_POIRSTAT)) & (BFM_RSTGEN_RST_STAT_POIRSTAT))
#define BFX_RSTGEN_RST_STAT_POIRSTAT(v)         ((((uint32_t) v) & (BFM_RSTGEN_RST_STAT_POIRSTAT)) >> (BFP_RSTGEN_RST_STAT_POIRSTAT))
#define BFW_RSTGEN_RST_STAT_POIRSTAT(v)         (REG_RSTGEN_RST_STAT.U32 = ( (REG_RSTGEN_RST_STAT.U32 & ~(BFM_RSTGEN_RST_STAT_POIRSTAT)) | ((((uint32_t) v)<<(BFP_RSTGEN_RST_STAT_POIRSTAT)) & (BFM_RSTGEN_RST_STAT_POIRSTAT)) ))
#define BFR_RSTGEN_RST_STAT_POIRSTAT()          ((REG_RSTGEN_RST_STAT.U32 & (BFM_RSTGEN_RST_STAT_POIRSTAT))>>(BFP_RSTGEN_RST_STAT_POIRSTAT))

#define BFP_RSTGEN_RST_STAT_SWRSTAT             (3)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_STAT_SWRSTAT             ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_RSTGEN_RST_STAT_SWRSTAT             (1)                     /* bitfield width */
#define BFD_RSTGEN_RST_STAT_SWRSTAT             (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_STAT_SWRSTAT(v)          ((((uint32_t) v) << (BFP_RSTGEN_RST_STAT_SWRSTAT)) & (BFM_RSTGEN_RST_STAT_SWRSTAT))
#define BFX_RSTGEN_RST_STAT_SWRSTAT(v)          ((((uint32_t) v) & (BFM_RSTGEN_RST_STAT_SWRSTAT)) >> (BFP_RSTGEN_RST_STAT_SWRSTAT))
#define BFW_RSTGEN_RST_STAT_SWRSTAT(v)          (REG_RSTGEN_RST_STAT.U32 = ( (REG_RSTGEN_RST_STAT.U32 & ~(BFM_RSTGEN_RST_STAT_SWRSTAT)) | ((((uint32_t) v)<<(BFP_RSTGEN_RST_STAT_SWRSTAT)) & (BFM_RSTGEN_RST_STAT_SWRSTAT)) ))
#define BFR_RSTGEN_RST_STAT_SWRSTAT()           ((REG_RSTGEN_RST_STAT.U32 & (BFM_RSTGEN_RST_STAT_SWRSTAT))>>(BFP_RSTGEN_RST_STAT_SWRSTAT))

#define BFP_RSTGEN_RST_STAT_BORSTAT             (2)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_STAT_BORSTAT             ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_RSTGEN_RST_STAT_BORSTAT             (1)                     /* bitfield width */
#define BFD_RSTGEN_RST_STAT_BORSTAT             (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_STAT_BORSTAT(v)          ((((uint32_t) v) << (BFP_RSTGEN_RST_STAT_BORSTAT)) & (BFM_RSTGEN_RST_STAT_BORSTAT))
#define BFX_RSTGEN_RST_STAT_BORSTAT(v)          ((((uint32_t) v) & (BFM_RSTGEN_RST_STAT_BORSTAT)) >> (BFP_RSTGEN_RST_STAT_BORSTAT))
#define BFW_RSTGEN_RST_STAT_BORSTAT(v)          (REG_RSTGEN_RST_STAT.U32 = ( (REG_RSTGEN_RST_STAT.U32 & ~(BFM_RSTGEN_RST_STAT_BORSTAT)) | ((((uint32_t) v)<<(BFP_RSTGEN_RST_STAT_BORSTAT)) & (BFM_RSTGEN_RST_STAT_BORSTAT)) ))
#define BFR_RSTGEN_RST_STAT_BORSTAT()           ((REG_RSTGEN_RST_STAT.U32 & (BFM_RSTGEN_RST_STAT_BORSTAT))>>(BFP_RSTGEN_RST_STAT_BORSTAT))

#define BFP_RSTGEN_RST_STAT_PORSTAT             (1)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_STAT_PORSTAT             ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_RSTGEN_RST_STAT_PORSTAT             (1)                     /* bitfield width */
#define BFD_RSTGEN_RST_STAT_PORSTAT             (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_STAT_PORSTAT(v)          ((((uint32_t) v) << (BFP_RSTGEN_RST_STAT_PORSTAT)) & (BFM_RSTGEN_RST_STAT_PORSTAT))
#define BFX_RSTGEN_RST_STAT_PORSTAT(v)          ((((uint32_t) v) & (BFM_RSTGEN_RST_STAT_PORSTAT)) >> (BFP_RSTGEN_RST_STAT_PORSTAT))
#define BFW_RSTGEN_RST_STAT_PORSTAT(v)          (REG_RSTGEN_RST_STAT.U32 = ( (REG_RSTGEN_RST_STAT.U32 & ~(BFM_RSTGEN_RST_STAT_PORSTAT)) | ((((uint32_t) v)<<(BFP_RSTGEN_RST_STAT_PORSTAT)) & (BFM_RSTGEN_RST_STAT_PORSTAT)) ))
#define BFR_RSTGEN_RST_STAT_PORSTAT()           ((REG_RSTGEN_RST_STAT.U32 & (BFM_RSTGEN_RST_STAT_PORSTAT))>>(BFP_RSTGEN_RST_STAT_PORSTAT))

#define BFP_RSTGEN_RST_STAT_EXRSTAT             (0)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_STAT_EXRSTAT             ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_RSTGEN_RST_STAT_EXRSTAT             (1)                     /* bitfield width */
#define BFD_RSTGEN_RST_STAT_EXRSTAT             (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_STAT_EXRSTAT(v)          ((((uint32_t) v) << (BFP_RSTGEN_RST_STAT_EXRSTAT)) & (BFM_RSTGEN_RST_STAT_EXRSTAT))
#define BFX_RSTGEN_RST_STAT_EXRSTAT(v)          ((((uint32_t) v) & (BFM_RSTGEN_RST_STAT_EXRSTAT)) >> (BFP_RSTGEN_RST_STAT_EXRSTAT))
#define BFW_RSTGEN_RST_STAT_EXRSTAT(v)          (REG_RSTGEN_RST_STAT.U32 = ( (REG_RSTGEN_RST_STAT.U32 & ~(BFM_RSTGEN_RST_STAT_EXRSTAT)) | ((((uint32_t) v)<<(BFP_RSTGEN_RST_STAT_EXRSTAT)) & (BFM_RSTGEN_RST_STAT_EXRSTAT)) ))
#define BFR_RSTGEN_RST_STAT_EXRSTAT()           ((REG_RSTGEN_RST_STAT.U32 & (BFM_RSTGEN_RST_STAT_EXRSTAT))>>(BFP_RSTGEN_RST_STAT_EXRSTAT))


// *****************************************************************************
//                                                                             *
//  RSTGEN_RST_CLRSTAT - Clear the status register                             *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_1                     : 31;
        unsigned CLRSTAT                    :  1;
    } B;
} reg_rstgen_rst_clrstat_t;

#define REG_RSTGEN_RST_CLRSTAT_ADDR             (REG_RSTGEN_BASEADDR + 0x00000010UL)
#define REG_RSTGEN_RST_CLRSTAT                  (*(volatile reg_rstgen_rst_clrstat_t *) REG_RSTGEN_RST_CLRSTAT_ADDR)
#define REG_RSTGEN_RST_CLRSTAT_RD()             (REG_RSTGEN_RST_CLRSTAT.U32)
#define REG_RSTGEN_RST_CLRSTAT_WR(v)            (REG_RSTGEN_RST_CLRSTAT.U32 = (v))
#define REG_RSTGEN_RST_CLRSTAT_CLR(m)           (REG_RSTGEN_RST_CLRSTAT.U32 = ((REG_RSTGEN_RST_CLRSTAT.U32) & ~(m)))
#define REG_RSTGEN_RST_CLRSTAT_SET(m)           (REG_RSTGEN_RST_CLRSTAT.U32 = ((REG_RSTGEN_RST_CLRSTAT.U32) | (m)))
#define REG_RSTGEN_RST_CLRSTAT_DEF              0x00000000

#define BFP_RSTGEN_RST_CLRSTAT_RSVD_1           (1)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_CLRSTAT_RSVD_1           ((uint32_t)0xfffffffe)  /* bitfield mask */
#define BFN_RSTGEN_RST_CLRSTAT_RSVD_1           (31)                    /* bitfield width */
#define BFD_RSTGEN_RST_CLRSTAT_RSVD_1           (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_CLRSTAT_RSVD_1(v)        ((((uint32_t) v) << (BFP_RSTGEN_RST_CLRSTAT_RSVD_1)) & (BFM_RSTGEN_RST_CLRSTAT_RSVD_1))
#define BFX_RSTGEN_RST_CLRSTAT_RSVD_1(v)        ((((uint32_t) v) & (BFM_RSTGEN_RST_CLRSTAT_RSVD_1)) >> (BFP_RSTGEN_RST_CLRSTAT_RSVD_1))
#define BFW_RSTGEN_RST_CLRSTAT_RSVD_1(v)        (REG_RSTGEN_RST_CLRSTAT.U32 = ( (((uint32_t) v)<<(BFP_RSTGEN_RST_CLRSTAT_RSVD_1)) & (BFM_RSTGEN_RST_CLRSTAT_RSVD_1)) )
#define BFR_RSTGEN_RST_CLRSTAT_RSVD_1()         ((REG_RSTGEN_RST_CLRSTAT.U32 & (BFM_RSTGEN_RST_CLRSTAT_RSVD_1))>>(BFP_RSTGEN_RST_CLRSTAT_RSVD_1))
#define BFS_RSTGEN_RST_CLRSTAT_RSVD_1()         (REG_RSTGEN_RST_CLRSTAT.U32 = (BFM_RSTGEN_RST_CLRSTAT_RSVD_1) )

#define BFP_RSTGEN_RST_CLRSTAT_CLRSTAT          (0)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_CLRSTAT_CLRSTAT          ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_RSTGEN_RST_CLRSTAT_CLRSTAT          (1)                     /* bitfield width */
#define BFD_RSTGEN_RST_CLRSTAT_CLRSTAT          (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_CLRSTAT_CLRSTAT(v)       ((((uint32_t) v) << (BFP_RSTGEN_RST_CLRSTAT_CLRSTAT)) & (BFM_RSTGEN_RST_CLRSTAT_CLRSTAT))
#define BFX_RSTGEN_RST_CLRSTAT_CLRSTAT(v)       ((((uint32_t) v) & (BFM_RSTGEN_RST_CLRSTAT_CLRSTAT)) >> (BFP_RSTGEN_RST_CLRSTAT_CLRSTAT))
#define BFW_RSTGEN_RST_CLRSTAT_CLRSTAT(v)       (REG_RSTGEN_RST_CLRSTAT.U32 = ( (((uint32_t) v)<<(BFP_RSTGEN_RST_CLRSTAT_CLRSTAT)) & (BFM_RSTGEN_RST_CLRSTAT_CLRSTAT)) )
#define BFR_RSTGEN_RST_CLRSTAT_CLRSTAT()        ((REG_RSTGEN_RST_CLRSTAT.U32 & (BFM_RSTGEN_RST_CLRSTAT_CLRSTAT))>>(BFP_RSTGEN_RST_CLRSTAT_CLRSTAT))
#define BFS_RSTGEN_RST_CLRSTAT_CLRSTAT()        (REG_RSTGEN_RST_CLRSTAT.U32 = (BFM_RSTGEN_RST_CLRSTAT_CLRSTAT) )


// *****************************************************************************
//                                                                             *
//  RSTGEN_RST_IEREN - Reset Interrupt register                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_1                     : 31;
        unsigned BODH                       :  1;
    } B;
} reg_rstgen_rst_ieren_t;

#define REG_RSTGEN_RST_IEREN_ADDR               (REG_RSTGEN_BASEADDR + 0x00000200UL)
#define REG_RSTGEN_RST_IEREN                    (*(volatile reg_rstgen_rst_ieren_t *) REG_RSTGEN_RST_IEREN_ADDR)
#define REG_RSTGEN_RST_IEREN_RD()               (REG_RSTGEN_RST_IEREN.U32)
#define REG_RSTGEN_RST_IEREN_WR(v)              (REG_RSTGEN_RST_IEREN.U32 = (v))
#define REG_RSTGEN_RST_IEREN_CLR(m)             (REG_RSTGEN_RST_IEREN.U32 = ((REG_RSTGEN_RST_IEREN.U32) & ~(m)))
#define REG_RSTGEN_RST_IEREN_SET(m)             (REG_RSTGEN_RST_IEREN.U32 = ((REG_RSTGEN_RST_IEREN.U32) | (m)))
#define REG_RSTGEN_RST_IEREN_DEF                0x00000000

#define BFP_RSTGEN_RST_IEREN_RSVD_1             (1)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_IEREN_RSVD_1             ((uint32_t)0xfffffffe)  /* bitfield mask */
#define BFN_RSTGEN_RST_IEREN_RSVD_1             (31)                    /* bitfield width */
#define BFD_RSTGEN_RST_IEREN_RSVD_1             (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_IEREN_RSVD_1(v)          ((((uint32_t) v) << (BFP_RSTGEN_RST_IEREN_RSVD_1)) & (BFM_RSTGEN_RST_IEREN_RSVD_1))
#define BFX_RSTGEN_RST_IEREN_RSVD_1(v)          ((((uint32_t) v) & (BFM_RSTGEN_RST_IEREN_RSVD_1)) >> (BFP_RSTGEN_RST_IEREN_RSVD_1))
#define BFW_RSTGEN_RST_IEREN_RSVD_1(v)          (REG_RSTGEN_RST_IEREN.U32 = ( (((uint32_t) v)<<(BFP_RSTGEN_RST_IEREN_RSVD_1)) & (BFM_RSTGEN_RST_IEREN_RSVD_1)) )
#define BFR_RSTGEN_RST_IEREN_RSVD_1()           ((REG_RSTGEN_RST_IEREN.U32 & (BFM_RSTGEN_RST_IEREN_RSVD_1))>>(BFP_RSTGEN_RST_IEREN_RSVD_1))

#define BFP_RSTGEN_RST_IEREN_BODH               (0)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_IEREN_BODH               ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_RSTGEN_RST_IEREN_BODH               (1)                     /* bitfield width */
#define BFD_RSTGEN_RST_IEREN_BODH               (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_IEREN_BODH(v)            ((((uint32_t) v) << (BFP_RSTGEN_RST_IEREN_BODH)) & (BFM_RSTGEN_RST_IEREN_BODH))
#define BFX_RSTGEN_RST_IEREN_BODH(v)            ((((uint32_t) v) & (BFM_RSTGEN_RST_IEREN_BODH)) >> (BFP_RSTGEN_RST_IEREN_BODH))
#define BFW_RSTGEN_RST_IEREN_BODH(v)            (REG_RSTGEN_RST_IEREN.U32 = ( (((uint32_t) v)<<(BFP_RSTGEN_RST_IEREN_BODH)) & (BFM_RSTGEN_RST_IEREN_BODH)) )
#define BFR_RSTGEN_RST_IEREN_BODH()             ((REG_RSTGEN_RST_IEREN.U32 & (BFM_RSTGEN_RST_IEREN_BODH))>>(BFP_RSTGEN_RST_IEREN_BODH))


// *****************************************************************************
//                                                                             *
//  RSTGEN_RST_IERSTAT - Reset Interrupt register                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_1                     : 31;
        unsigned BODH                       :  1;
    } B;
} reg_rstgen_rst_ierstat_t;

#define REG_RSTGEN_RST_IERSTAT_ADDR             (REG_RSTGEN_BASEADDR + 0x00000204UL)
#define REG_RSTGEN_RST_IERSTAT                  (*(volatile reg_rstgen_rst_ierstat_t *) REG_RSTGEN_RST_IERSTAT_ADDR)
#define REG_RSTGEN_RST_IERSTAT_RD()             (REG_RSTGEN_RST_IERSTAT.U32)
#define REG_RSTGEN_RST_IERSTAT_WR(v)            (REG_RSTGEN_RST_IERSTAT.U32 = (v))
#define REG_RSTGEN_RST_IERSTAT_CLR(m)           (REG_RSTGEN_RST_IERSTAT.U32 = ((REG_RSTGEN_RST_IERSTAT.U32) & ~(m)))
#define REG_RSTGEN_RST_IERSTAT_SET(m)           (REG_RSTGEN_RST_IERSTAT.U32 = ((REG_RSTGEN_RST_IERSTAT.U32) | (m)))
#define REG_RSTGEN_RST_IERSTAT_DEF              0x00000000

#define BFP_RSTGEN_RST_IERSTAT_RSVD_1           (1)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_IERSTAT_RSVD_1           ((uint32_t)0xfffffffe)  /* bitfield mask */
#define BFN_RSTGEN_RST_IERSTAT_RSVD_1           (31)                    /* bitfield width */
#define BFD_RSTGEN_RST_IERSTAT_RSVD_1           (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_IERSTAT_RSVD_1(v)        ((((uint32_t) v) << (BFP_RSTGEN_RST_IERSTAT_RSVD_1)) & (BFM_RSTGEN_RST_IERSTAT_RSVD_1))
#define BFX_RSTGEN_RST_IERSTAT_RSVD_1(v)        ((((uint32_t) v) & (BFM_RSTGEN_RST_IERSTAT_RSVD_1)) >> (BFP_RSTGEN_RST_IERSTAT_RSVD_1))
#define BFW_RSTGEN_RST_IERSTAT_RSVD_1(v)        (REG_RSTGEN_RST_IERSTAT.U32 = ( (((uint32_t) v)<<(BFP_RSTGEN_RST_IERSTAT_RSVD_1)) & (BFM_RSTGEN_RST_IERSTAT_RSVD_1)) )
#define BFR_RSTGEN_RST_IERSTAT_RSVD_1()         ((REG_RSTGEN_RST_IERSTAT.U32 & (BFM_RSTGEN_RST_IERSTAT_RSVD_1))>>(BFP_RSTGEN_RST_IERSTAT_RSVD_1))

#define BFP_RSTGEN_RST_IERSTAT_BODH             (0)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_IERSTAT_BODH             ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_RSTGEN_RST_IERSTAT_BODH             (1)                     /* bitfield width */
#define BFD_RSTGEN_RST_IERSTAT_BODH             (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_IERSTAT_BODH(v)          ((((uint32_t) v) << (BFP_RSTGEN_RST_IERSTAT_BODH)) & (BFM_RSTGEN_RST_IERSTAT_BODH))
#define BFX_RSTGEN_RST_IERSTAT_BODH(v)          ((((uint32_t) v) & (BFM_RSTGEN_RST_IERSTAT_BODH)) >> (BFP_RSTGEN_RST_IERSTAT_BODH))
#define BFW_RSTGEN_RST_IERSTAT_BODH(v)          (REG_RSTGEN_RST_IERSTAT.U32 = ( (((uint32_t) v)<<(BFP_RSTGEN_RST_IERSTAT_BODH)) & (BFM_RSTGEN_RST_IERSTAT_BODH)) )
#define BFR_RSTGEN_RST_IERSTAT_BODH()           ((REG_RSTGEN_RST_IERSTAT.U32 & (BFM_RSTGEN_RST_IERSTAT_BODH))>>(BFP_RSTGEN_RST_IERSTAT_BODH))


// *****************************************************************************
//                                                                             *
//  RSTGEN_RST_IERCLR - Reset Interrupt register                               *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_1                     : 31;
        unsigned BODH                       :  1;
    } B;
} reg_rstgen_rst_ierclr_t;

#define REG_RSTGEN_RST_IERCLR_ADDR              (REG_RSTGEN_BASEADDR + 0x00000208UL)
#define REG_RSTGEN_RST_IERCLR                   (*(volatile reg_rstgen_rst_ierclr_t *) REG_RSTGEN_RST_IERCLR_ADDR)
#define REG_RSTGEN_RST_IERCLR_RD()              (REG_RSTGEN_RST_IERCLR.U32)
#define REG_RSTGEN_RST_IERCLR_WR(v)             (REG_RSTGEN_RST_IERCLR.U32 = (v))
#define REG_RSTGEN_RST_IERCLR_CLR(m)            (REG_RSTGEN_RST_IERCLR.U32 = ((REG_RSTGEN_RST_IERCLR.U32) & ~(m)))
#define REG_RSTGEN_RST_IERCLR_SET(m)            (REG_RSTGEN_RST_IERCLR.U32 = ((REG_RSTGEN_RST_IERCLR.U32) | (m)))
#define REG_RSTGEN_RST_IERCLR_DEF               0x00000000

#define BFP_RSTGEN_RST_IERCLR_RSVD_1            (1)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_IERCLR_RSVD_1            ((uint32_t)0xfffffffe)  /* bitfield mask */
#define BFN_RSTGEN_RST_IERCLR_RSVD_1            (31)                    /* bitfield width */
#define BFD_RSTGEN_RST_IERCLR_RSVD_1            (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_IERCLR_RSVD_1(v)         ((((uint32_t) v) << (BFP_RSTGEN_RST_IERCLR_RSVD_1)) & (BFM_RSTGEN_RST_IERCLR_RSVD_1))
#define BFX_RSTGEN_RST_IERCLR_RSVD_1(v)         ((((uint32_t) v) & (BFM_RSTGEN_RST_IERCLR_RSVD_1)) >> (BFP_RSTGEN_RST_IERCLR_RSVD_1))
#define BFW_RSTGEN_RST_IERCLR_RSVD_1(v)         (REG_RSTGEN_RST_IERCLR.U32 = ( (((uint32_t) v)<<(BFP_RSTGEN_RST_IERCLR_RSVD_1)) & (BFM_RSTGEN_RST_IERCLR_RSVD_1)) )
#define BFR_RSTGEN_RST_IERCLR_RSVD_1()          ((REG_RSTGEN_RST_IERCLR.U32 & (BFM_RSTGEN_RST_IERCLR_RSVD_1))>>(BFP_RSTGEN_RST_IERCLR_RSVD_1))

#define BFP_RSTGEN_RST_IERCLR_BODH              (0)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_IERCLR_BODH              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_RSTGEN_RST_IERCLR_BODH              (1)                     /* bitfield width */
#define BFD_RSTGEN_RST_IERCLR_BODH              (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_IERCLR_BODH(v)           ((((uint32_t) v) << (BFP_RSTGEN_RST_IERCLR_BODH)) & (BFM_RSTGEN_RST_IERCLR_BODH))
#define BFX_RSTGEN_RST_IERCLR_BODH(v)           ((((uint32_t) v) & (BFM_RSTGEN_RST_IERCLR_BODH)) >> (BFP_RSTGEN_RST_IERCLR_BODH))
#define BFW_RSTGEN_RST_IERCLR_BODH(v)           (REG_RSTGEN_RST_IERCLR.U32 = ( (((uint32_t) v)<<(BFP_RSTGEN_RST_IERCLR_BODH)) & (BFM_RSTGEN_RST_IERCLR_BODH)) )
#define BFR_RSTGEN_RST_IERCLR_BODH()            ((REG_RSTGEN_RST_IERCLR.U32 & (BFM_RSTGEN_RST_IERCLR_BODH))>>(BFP_RSTGEN_RST_IERCLR_BODH))


// *****************************************************************************
//                                                                             *
//  RSTGEN_RST_IERSET - Reset Interrupt register                               *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_1                     : 31;
        unsigned BODH                       :  1;
    } B;
} reg_rstgen_rst_ierset_t;

#define REG_RSTGEN_RST_IERSET_ADDR              (REG_RSTGEN_BASEADDR + 0x0000020CUL)
#define REG_RSTGEN_RST_IERSET                   (*(volatile reg_rstgen_rst_ierset_t *) REG_RSTGEN_RST_IERSET_ADDR)
#define REG_RSTGEN_RST_IERSET_RD()              (REG_RSTGEN_RST_IERSET.U32)
#define REG_RSTGEN_RST_IERSET_WR(v)             (REG_RSTGEN_RST_IERSET.U32 = (v))
#define REG_RSTGEN_RST_IERSET_CLR(m)            (REG_RSTGEN_RST_IERSET.U32 = ((REG_RSTGEN_RST_IERSET.U32) & ~(m)))
#define REG_RSTGEN_RST_IERSET_SET(m)            (REG_RSTGEN_RST_IERSET.U32 = ((REG_RSTGEN_RST_IERSET.U32) | (m)))
#define REG_RSTGEN_RST_IERSET_DEF               0x00000000

#define BFP_RSTGEN_RST_IERSET_RSVD_1            (1)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_IERSET_RSVD_1            ((uint32_t)0xfffffffe)  /* bitfield mask */
#define BFN_RSTGEN_RST_IERSET_RSVD_1            (31)                    /* bitfield width */
#define BFD_RSTGEN_RST_IERSET_RSVD_1            (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_IERSET_RSVD_1(v)         ((((uint32_t) v) << (BFP_RSTGEN_RST_IERSET_RSVD_1)) & (BFM_RSTGEN_RST_IERSET_RSVD_1))
#define BFX_RSTGEN_RST_IERSET_RSVD_1(v)         ((((uint32_t) v) & (BFM_RSTGEN_RST_IERSET_RSVD_1)) >> (BFP_RSTGEN_RST_IERSET_RSVD_1))
#define BFW_RSTGEN_RST_IERSET_RSVD_1(v)         (REG_RSTGEN_RST_IERSET.U32 = ( (((uint32_t) v)<<(BFP_RSTGEN_RST_IERSET_RSVD_1)) & (BFM_RSTGEN_RST_IERSET_RSVD_1)) )
#define BFR_RSTGEN_RST_IERSET_RSVD_1()          ((REG_RSTGEN_RST_IERSET.U32 & (BFM_RSTGEN_RST_IERSET_RSVD_1))>>(BFP_RSTGEN_RST_IERSET_RSVD_1))

#define BFP_RSTGEN_RST_IERSET_BODH              (0)                     /* bitfield lsb */
#define BFM_RSTGEN_RST_IERSET_BODH              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_RSTGEN_RST_IERSET_BODH              (1)                     /* bitfield width */
#define BFD_RSTGEN_RST_IERSET_BODH              (0x0)                   /* bitfield default value */
#define BFV_RSTGEN_RST_IERSET_BODH(v)           ((((uint32_t) v) << (BFP_RSTGEN_RST_IERSET_BODH)) & (BFM_RSTGEN_RST_IERSET_BODH))
#define BFX_RSTGEN_RST_IERSET_BODH(v)           ((((uint32_t) v) & (BFM_RSTGEN_RST_IERSET_BODH)) >> (BFP_RSTGEN_RST_IERSET_BODH))
#define BFW_RSTGEN_RST_IERSET_BODH(v)           (REG_RSTGEN_RST_IERSET.U32 = ( (((uint32_t) v)<<(BFP_RSTGEN_RST_IERSET_BODH)) & (BFM_RSTGEN_RST_IERSET_BODH)) )
#define BFR_RSTGEN_RST_IERSET_BODH()            ((REG_RSTGEN_RST_IERSET.U32 & (BFM_RSTGEN_RST_IERSET_BODH))>>(BFP_RSTGEN_RST_IERSET_BODH))



#endif  // __RSTGEN_REGS_H

