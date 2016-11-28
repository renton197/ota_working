/*******************************************************************************
*                                                                              *
*   File:       adc.h                                                          *
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

#ifndef __ADC_H
#define __ADC_H

#include "../am_mcu_apollo.h"
// *****************************************************************************
//                                                                             *
//  ADC_ADCCFG - Configuration Register                                        *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_26                    :  6;
        unsigned CLKSEL                     :  2;
        unsigned RSVD_21                    :  3;
        unsigned TRIGPOL                    :  1;
        unsigned TRIGSEL                    :  4;
        unsigned RSVD_10                    :  6;
        unsigned REFSEL                     :  2;
        unsigned OPMODE                     :  3;
        unsigned LPMODE                     :  2;
        unsigned RPTEN                      :  1;
        unsigned TMPSEN                     :  1;
        unsigned ADCEN                      :  1;
    } B;
} reg_adc_adccfg_t;

#define REG_ADC_ADCCFG_ADDR                     (REG_ADC_BASEADDR + 0x00000000UL)
#define REG_ADC_ADCCFG                          (*(volatile reg_adc_adccfg_t *) REG_ADC_ADCCFG_ADDR)
#define REG_ADC_ADCCFG_RD()                     (REG_ADC_ADCCFG.U32)
#define REG_ADC_ADCCFG_WR(v)                    (REG_ADC_ADCCFG.U32 = (v))
#define REG_ADC_ADCCFG_CLR(m)                   (REG_ADC_ADCCFG.U32 = ((REG_ADC_ADCCFG.U32) & ~(m)))
#define REG_ADC_ADCCFG_SET(m)                   (REG_ADC_ADCCFG.U32 = ((REG_ADC_ADCCFG.U32) | (m)))
#define REG_ADC_ADCCFG_DEF                      0x00000000

#define BFP_ADC_ADCCFG_RSVD_26                  (26)                    /* bitfield lsb */
#define BFM_ADC_ADCCFG_RSVD_26                  ((uint32_t)0xfc000000)  /* bitfield mask */
#define BFN_ADC_ADCCFG_RSVD_26                  (6)                     /* bitfield width */
#define BFD_ADC_ADCCFG_RSVD_26                  (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCCFG_RSVD_26(v)               ((((uint32_t) v) << (BFP_ADC_ADCCFG_RSVD_26)) & (BFM_ADC_ADCCFG_RSVD_26))
#define BFX_ADC_ADCCFG_RSVD_26(v)               ((((uint32_t) v) & (BFM_ADC_ADCCFG_RSVD_26)) >> (BFP_ADC_ADCCFG_RSVD_26))
#define BFW_ADC_ADCCFG_RSVD_26(v)               (REG_ADC_ADCCFG.U32 = ( (REG_ADC_ADCCFG.U32 & ~(BFM_ADC_ADCCFG_RSVD_26)) | ((((uint32_t) v)<<(BFP_ADC_ADCCFG_RSVD_26)) & (BFM_ADC_ADCCFG_RSVD_26)) ))
#define BFR_ADC_ADCCFG_RSVD_26()                ((REG_ADC_ADCCFG.U32 & (BFM_ADC_ADCCFG_RSVD_26))>>(BFP_ADC_ADCCFG_RSVD_26))

#define BFP_ADC_ADCCFG_CLKSEL                   (24)                    /* bitfield lsb */
#define BFM_ADC_ADCCFG_CLKSEL                   ((uint32_t)0x03000000)  /* bitfield mask */
#define BFN_ADC_ADCCFG_CLKSEL                   (2)                     /* bitfield width */
#define BFD_ADC_ADCCFG_CLKSEL                   (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCCFG_CLKSEL(v)                ((((uint32_t) v) << (BFP_ADC_ADCCFG_CLKSEL)) & (BFM_ADC_ADCCFG_CLKSEL))
#define BFX_ADC_ADCCFG_CLKSEL(v)                ((((uint32_t) v) & (BFM_ADC_ADCCFG_CLKSEL)) >> (BFP_ADC_ADCCFG_CLKSEL))
#define BFW_ADC_ADCCFG_CLKSEL(v)                (REG_ADC_ADCCFG.U32 = ( (REG_ADC_ADCCFG.U32 & ~(BFM_ADC_ADCCFG_CLKSEL)) | ((((uint32_t) v)<<(BFP_ADC_ADCCFG_CLKSEL)) & (BFM_ADC_ADCCFG_CLKSEL)) ))
#define BFR_ADC_ADCCFG_CLKSEL()                 ((REG_ADC_ADCCFG.U32 & (BFM_ADC_ADCCFG_CLKSEL))>>(BFP_ADC_ADCCFG_CLKSEL))

#define BFP_ADC_ADCCFG_RSVD_21                  (21)                    /* bitfield lsb */
#define BFM_ADC_ADCCFG_RSVD_21                  ((uint32_t)0x00e00000)  /* bitfield mask */
#define BFN_ADC_ADCCFG_RSVD_21                  (3)                     /* bitfield width */
#define BFD_ADC_ADCCFG_RSVD_21                  (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCCFG_RSVD_21(v)               ((((uint32_t) v) << (BFP_ADC_ADCCFG_RSVD_21)) & (BFM_ADC_ADCCFG_RSVD_21))
#define BFX_ADC_ADCCFG_RSVD_21(v)               ((((uint32_t) v) & (BFM_ADC_ADCCFG_RSVD_21)) >> (BFP_ADC_ADCCFG_RSVD_21))
#define BFW_ADC_ADCCFG_RSVD_21(v)               (REG_ADC_ADCCFG.U32 = ( (REG_ADC_ADCCFG.U32 & ~(BFM_ADC_ADCCFG_RSVD_21)) | ((((uint32_t) v)<<(BFP_ADC_ADCCFG_RSVD_21)) & (BFM_ADC_ADCCFG_RSVD_21)) ))
#define BFR_ADC_ADCCFG_RSVD_21()                ((REG_ADC_ADCCFG.U32 & (BFM_ADC_ADCCFG_RSVD_21))>>(BFP_ADC_ADCCFG_RSVD_21))

#define BFP_ADC_ADCCFG_TRIGPOL                  (20)                    /* bitfield lsb */
#define BFM_ADC_ADCCFG_TRIGPOL                  ((uint32_t)0x00100000)  /* bitfield mask */
#define BFN_ADC_ADCCFG_TRIGPOL                  (1)                     /* bitfield width */
#define BFD_ADC_ADCCFG_TRIGPOL                  (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCCFG_TRIGPOL(v)               ((((uint32_t) v) << (BFP_ADC_ADCCFG_TRIGPOL)) & (BFM_ADC_ADCCFG_TRIGPOL))
#define BFX_ADC_ADCCFG_TRIGPOL(v)               ((((uint32_t) v) & (BFM_ADC_ADCCFG_TRIGPOL)) >> (BFP_ADC_ADCCFG_TRIGPOL))
#define BFW_ADC_ADCCFG_TRIGPOL(v)               (REG_ADC_ADCCFG.U32 = ( (REG_ADC_ADCCFG.U32 & ~(BFM_ADC_ADCCFG_TRIGPOL)) | ((((uint32_t) v)<<(BFP_ADC_ADCCFG_TRIGPOL)) & (BFM_ADC_ADCCFG_TRIGPOL)) ))
#define BFR_ADC_ADCCFG_TRIGPOL()                ((REG_ADC_ADCCFG.U32 & (BFM_ADC_ADCCFG_TRIGPOL))>>(BFP_ADC_ADCCFG_TRIGPOL))

#define BFP_ADC_ADCCFG_TRIGSEL                  (16)                    /* bitfield lsb */
#define BFM_ADC_ADCCFG_TRIGSEL                  ((uint32_t)0x000f0000)  /* bitfield mask */
#define BFN_ADC_ADCCFG_TRIGSEL                  (4)                     /* bitfield width */
#define BFD_ADC_ADCCFG_TRIGSEL                  (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCCFG_TRIGSEL(v)               ((((uint32_t) v) << (BFP_ADC_ADCCFG_TRIGSEL)) & (BFM_ADC_ADCCFG_TRIGSEL))
#define BFX_ADC_ADCCFG_TRIGSEL(v)               ((((uint32_t) v) & (BFM_ADC_ADCCFG_TRIGSEL)) >> (BFP_ADC_ADCCFG_TRIGSEL))
#define BFW_ADC_ADCCFG_TRIGSEL(v)               (REG_ADC_ADCCFG.U32 = ( (REG_ADC_ADCCFG.U32 & ~(BFM_ADC_ADCCFG_TRIGSEL)) | ((((uint32_t) v)<<(BFP_ADC_ADCCFG_TRIGSEL)) & (BFM_ADC_ADCCFG_TRIGSEL)) ))
#define BFR_ADC_ADCCFG_TRIGSEL()                ((REG_ADC_ADCCFG.U32 & (BFM_ADC_ADCCFG_TRIGSEL))>>(BFP_ADC_ADCCFG_TRIGSEL))

#define BFP_ADC_ADCCFG_RSVD_10                  (10)                    /* bitfield lsb */
#define BFM_ADC_ADCCFG_RSVD_10                  ((uint32_t)0x0000fc00)  /* bitfield mask */
#define BFN_ADC_ADCCFG_RSVD_10                  (6)                     /* bitfield width */
#define BFD_ADC_ADCCFG_RSVD_10                  (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCCFG_RSVD_10(v)               ((((uint32_t) v) << (BFP_ADC_ADCCFG_RSVD_10)) & (BFM_ADC_ADCCFG_RSVD_10))
#define BFX_ADC_ADCCFG_RSVD_10(v)               ((((uint32_t) v) & (BFM_ADC_ADCCFG_RSVD_10)) >> (BFP_ADC_ADCCFG_RSVD_10))
#define BFW_ADC_ADCCFG_RSVD_10(v)               (REG_ADC_ADCCFG.U32 = ( (REG_ADC_ADCCFG.U32 & ~(BFM_ADC_ADCCFG_RSVD_10)) | ((((uint32_t) v)<<(BFP_ADC_ADCCFG_RSVD_10)) & (BFM_ADC_ADCCFG_RSVD_10)) ))
#define BFR_ADC_ADCCFG_RSVD_10()                ((REG_ADC_ADCCFG.U32 & (BFM_ADC_ADCCFG_RSVD_10))>>(BFP_ADC_ADCCFG_RSVD_10))

#define BFP_ADC_ADCCFG_REFSEL                   (8)                     /* bitfield lsb */
#define BFM_ADC_ADCCFG_REFSEL                   ((uint32_t)0x00000300)  /* bitfield mask */
#define BFN_ADC_ADCCFG_REFSEL                   (2)                     /* bitfield width */
#define BFD_ADC_ADCCFG_REFSEL                   (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCCFG_REFSEL(v)                ((((uint32_t) v) << (BFP_ADC_ADCCFG_REFSEL)) & (BFM_ADC_ADCCFG_REFSEL))
#define BFX_ADC_ADCCFG_REFSEL(v)                ((((uint32_t) v) & (BFM_ADC_ADCCFG_REFSEL)) >> (BFP_ADC_ADCCFG_REFSEL))
#define BFW_ADC_ADCCFG_REFSEL(v)                (REG_ADC_ADCCFG.U32 = ( (REG_ADC_ADCCFG.U32 & ~(BFM_ADC_ADCCFG_REFSEL)) | ((((uint32_t) v)<<(BFP_ADC_ADCCFG_REFSEL)) & (BFM_ADC_ADCCFG_REFSEL)) ))
#define BFR_ADC_ADCCFG_REFSEL()                 ((REG_ADC_ADCCFG.U32 & (BFM_ADC_ADCCFG_REFSEL))>>(BFP_ADC_ADCCFG_REFSEL))

#define BFP_ADC_ADCCFG_OPMODE                   (5)                     /* bitfield lsb */
#define BFM_ADC_ADCCFG_OPMODE                   ((uint32_t)0x000000e0)  /* bitfield mask */
#define BFN_ADC_ADCCFG_OPMODE                   (3)                     /* bitfield width */
#define BFD_ADC_ADCCFG_OPMODE                   (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCCFG_OPMODE(v)                ((((uint32_t) v) << (BFP_ADC_ADCCFG_OPMODE)) & (BFM_ADC_ADCCFG_OPMODE))
#define BFX_ADC_ADCCFG_OPMODE(v)                ((((uint32_t) v) & (BFM_ADC_ADCCFG_OPMODE)) >> (BFP_ADC_ADCCFG_OPMODE))
#define BFW_ADC_ADCCFG_OPMODE(v)                (REG_ADC_ADCCFG.U32 = ( (REG_ADC_ADCCFG.U32 & ~(BFM_ADC_ADCCFG_OPMODE)) | ((((uint32_t) v)<<(BFP_ADC_ADCCFG_OPMODE)) & (BFM_ADC_ADCCFG_OPMODE)) ))
#define BFR_ADC_ADCCFG_OPMODE()                 ((REG_ADC_ADCCFG.U32 & (BFM_ADC_ADCCFG_OPMODE))>>(BFP_ADC_ADCCFG_OPMODE))

#define BFP_ADC_ADCCFG_LPMODE                   (3)                     /* bitfield lsb */
#define BFM_ADC_ADCCFG_LPMODE                   ((uint32_t)0x00000018)  /* bitfield mask */
#define BFN_ADC_ADCCFG_LPMODE                   (2)                     /* bitfield width */
#define BFD_ADC_ADCCFG_LPMODE                   (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCCFG_LPMODE(v)                ((((uint32_t) v) << (BFP_ADC_ADCCFG_LPMODE)) & (BFM_ADC_ADCCFG_LPMODE))
#define BFX_ADC_ADCCFG_LPMODE(v)                ((((uint32_t) v) & (BFM_ADC_ADCCFG_LPMODE)) >> (BFP_ADC_ADCCFG_LPMODE))
#define BFW_ADC_ADCCFG_LPMODE(v)                (REG_ADC_ADCCFG.U32 = ( (REG_ADC_ADCCFG.U32 & ~(BFM_ADC_ADCCFG_LPMODE)) | ((((uint32_t) v)<<(BFP_ADC_ADCCFG_LPMODE)) & (BFM_ADC_ADCCFG_LPMODE)) ))
#define BFR_ADC_ADCCFG_LPMODE()                 ((REG_ADC_ADCCFG.U32 & (BFM_ADC_ADCCFG_LPMODE))>>(BFP_ADC_ADCCFG_LPMODE))

#define BFP_ADC_ADCCFG_RPTEN                    (2)                     /* bitfield lsb */
#define BFM_ADC_ADCCFG_RPTEN                    ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_ADC_ADCCFG_RPTEN                    (1)                     /* bitfield width */
#define BFD_ADC_ADCCFG_RPTEN                    (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCCFG_RPTEN(v)                 ((((uint32_t) v) << (BFP_ADC_ADCCFG_RPTEN)) & (BFM_ADC_ADCCFG_RPTEN))
#define BFX_ADC_ADCCFG_RPTEN(v)                 ((((uint32_t) v) & (BFM_ADC_ADCCFG_RPTEN)) >> (BFP_ADC_ADCCFG_RPTEN))
#define BFW_ADC_ADCCFG_RPTEN(v)                 (REG_ADC_ADCCFG.U32 = ( (REG_ADC_ADCCFG.U32 & ~(BFM_ADC_ADCCFG_RPTEN)) | ((((uint32_t) v)<<(BFP_ADC_ADCCFG_RPTEN)) & (BFM_ADC_ADCCFG_RPTEN)) ))
#define BFR_ADC_ADCCFG_RPTEN()                  ((REG_ADC_ADCCFG.U32 & (BFM_ADC_ADCCFG_RPTEN))>>(BFP_ADC_ADCCFG_RPTEN))

#define BFP_ADC_ADCCFG_TMPSEN                   (1)                     /* bitfield lsb */
#define BFM_ADC_ADCCFG_TMPSEN                   ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_ADC_ADCCFG_TMPSEN                   (1)                     /* bitfield width */
#define BFD_ADC_ADCCFG_TMPSEN                   (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCCFG_TMPSEN(v)                ((((uint32_t) v) << (BFP_ADC_ADCCFG_TMPSEN)) & (BFM_ADC_ADCCFG_TMPSEN))
#define BFX_ADC_ADCCFG_TMPSEN(v)                ((((uint32_t) v) & (BFM_ADC_ADCCFG_TMPSEN)) >> (BFP_ADC_ADCCFG_TMPSEN))
#define BFW_ADC_ADCCFG_TMPSEN(v)                (REG_ADC_ADCCFG.U32 = ( (REG_ADC_ADCCFG.U32 & ~(BFM_ADC_ADCCFG_TMPSEN)) | ((((uint32_t) v)<<(BFP_ADC_ADCCFG_TMPSEN)) & (BFM_ADC_ADCCFG_TMPSEN)) ))
#define BFR_ADC_ADCCFG_TMPSEN()                 ((REG_ADC_ADCCFG.U32 & (BFM_ADC_ADCCFG_TMPSEN))>>(BFP_ADC_ADCCFG_TMPSEN))

#define BFP_ADC_ADCCFG_ADCEN                    (0)                     /* bitfield lsb */
#define BFM_ADC_ADCCFG_ADCEN                    ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_ADC_ADCCFG_ADCEN                    (1)                     /* bitfield width */
#define BFD_ADC_ADCCFG_ADCEN                    (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCCFG_ADCEN(v)                 ((((uint32_t) v) << (BFP_ADC_ADCCFG_ADCEN)) & (BFM_ADC_ADCCFG_ADCEN))
#define BFX_ADC_ADCCFG_ADCEN(v)                 ((((uint32_t) v) & (BFM_ADC_ADCCFG_ADCEN)) >> (BFP_ADC_ADCCFG_ADCEN))
#define BFW_ADC_ADCCFG_ADCEN(v)                 (REG_ADC_ADCCFG.U32 = ( (REG_ADC_ADCCFG.U32 & ~(BFM_ADC_ADCCFG_ADCEN)) | ((((uint32_t) v)<<(BFP_ADC_ADCCFG_ADCEN)) & (BFM_ADC_ADCCFG_ADCEN)) ))
#define BFR_ADC_ADCCFG_ADCEN()                  ((REG_ADC_ADCCFG.U32 & (BFM_ADC_ADCCFG_ADCEN))>>(BFP_ADC_ADCCFG_ADCEN))


// *****************************************************************************
//                                                                             *
//  ADC_ADCSTAT - Chip Revision                                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_2                     : 30;
        unsigned PWDSTAT                    :  2;
    } B;
} reg_adc_adcstat_t;

#define REG_ADC_ADCSTAT_ADDR                    (REG_ADC_BASEADDR + 0x00000004UL)
#define REG_ADC_ADCSTAT                         (*(volatile reg_adc_adcstat_t *) REG_ADC_ADCSTAT_ADDR)
#define REG_ADC_ADCSTAT_RD()                    (REG_ADC_ADCSTAT.U32)
#define REG_ADC_ADCSTAT_WR(v)                   (REG_ADC_ADCSTAT.U32 = (v))
#define REG_ADC_ADCSTAT_CLR(m)                  (REG_ADC_ADCSTAT.U32 = ((REG_ADC_ADCSTAT.U32) & ~(m)))
#define REG_ADC_ADCSTAT_SET(m)                  (REG_ADC_ADCSTAT.U32 = ((REG_ADC_ADCSTAT.U32) | (m)))
#define REG_ADC_ADCSTAT_DEF                     0x00000000

#define BFP_ADC_ADCSTAT_RSVD_2                  (2)                     /* bitfield lsb */
#define BFM_ADC_ADCSTAT_RSVD_2                  ((uint32_t)0xfffffffc)  /* bitfield mask */
#define BFN_ADC_ADCSTAT_RSVD_2                  (30)                    /* bitfield width */
#define BFD_ADC_ADCSTAT_RSVD_2                  (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSTAT_RSVD_2(v)               ((((uint32_t) v) << (BFP_ADC_ADCSTAT_RSVD_2)) & (BFM_ADC_ADCSTAT_RSVD_2))
#define BFX_ADC_ADCSTAT_RSVD_2(v)               ((((uint32_t) v) & (BFM_ADC_ADCSTAT_RSVD_2)) >> (BFP_ADC_ADCSTAT_RSVD_2))
#define BFW_ADC_ADCSTAT_RSVD_2(v)               (REG_ADC_ADCSTAT.U32 = ( (((uint32_t) v)<<(BFP_ADC_ADCSTAT_RSVD_2)) & (BFM_ADC_ADCSTAT_RSVD_2)) )
#define BFR_ADC_ADCSTAT_RSVD_2()                ((REG_ADC_ADCSTAT.U32 & (BFM_ADC_ADCSTAT_RSVD_2))>>(BFP_ADC_ADCSTAT_RSVD_2))

#define BFP_ADC_ADCSTAT_PWDSTAT                 (0)                     /* bitfield lsb */
#define BFM_ADC_ADCSTAT_PWDSTAT                 ((uint32_t)0x00000003)  /* bitfield mask */
#define BFN_ADC_ADCSTAT_PWDSTAT                 (2)                     /* bitfield width */
#define BFD_ADC_ADCSTAT_PWDSTAT                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSTAT_PWDSTAT(v)              ((((uint32_t) v) << (BFP_ADC_ADCSTAT_PWDSTAT)) & (BFM_ADC_ADCSTAT_PWDSTAT))
#define BFX_ADC_ADCSTAT_PWDSTAT(v)              ((((uint32_t) v) & (BFM_ADC_ADCSTAT_PWDSTAT)) >> (BFP_ADC_ADCSTAT_PWDSTAT))
#define BFW_ADC_ADCSTAT_PWDSTAT(v)              (REG_ADC_ADCSTAT.U32 = ( (((uint32_t) v)<<(BFP_ADC_ADCSTAT_PWDSTAT)) & (BFM_ADC_ADCSTAT_PWDSTAT)) )
#define BFR_ADC_ADCSTAT_PWDSTAT()               ((REG_ADC_ADCSTAT.U32 & (BFM_ADC_ADCSTAT_PWDSTAT))>>(BFP_ADC_ADCSTAT_PWDSTAT))


// *****************************************************************************
//                                                                             *
//  ADC_ADCSWT - Software trigger for conversion                               *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned ADCSWT                     :  8;
    } B;
} reg_adc_adcswt_t;

#define REG_ADC_ADCSWT_ADDR                     (REG_ADC_BASEADDR + 0x00000008UL)
#define REG_ADC_ADCSWT                          (*(volatile reg_adc_adcswt_t *) REG_ADC_ADCSWT_ADDR)
#define REG_ADC_ADCSWT_RD()                     (REG_ADC_ADCSWT.U32)
#define REG_ADC_ADCSWT_WR(v)                    (REG_ADC_ADCSWT.U32 = (v))
#define REG_ADC_ADCSWT_CLR(m)                   (REG_ADC_ADCSWT.U32 = ((REG_ADC_ADCSWT.U32) & ~(m)))
#define REG_ADC_ADCSWT_SET(m)                   (REG_ADC_ADCSWT.U32 = ((REG_ADC_ADCSWT.U32) | (m)))
#define REG_ADC_ADCSWT_DEF                      0x00000000

#define BFP_ADC_ADCSWT_RSVD_8                   (8)                     /* bitfield lsb */
#define BFM_ADC_ADCSWT_RSVD_8                   ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_ADC_ADCSWT_RSVD_8                   (24)                    /* bitfield width */
#define BFD_ADC_ADCSWT_RSVD_8                   (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSWT_RSVD_8(v)                ((((uint32_t) v) << (BFP_ADC_ADCSWT_RSVD_8)) & (BFM_ADC_ADCSWT_RSVD_8))
#define BFX_ADC_ADCSWT_RSVD_8(v)                ((((uint32_t) v) & (BFM_ADC_ADCSWT_RSVD_8)) >> (BFP_ADC_ADCSWT_RSVD_8))
#define BFW_ADC_ADCSWT_RSVD_8(v)                (REG_ADC_ADCSWT.U32 = ( (((uint32_t) v)<<(BFP_ADC_ADCSWT_RSVD_8)) & (BFM_ADC_ADCSWT_RSVD_8)) )
#define BFR_ADC_ADCSWT_RSVD_8()                 ((REG_ADC_ADCSWT.U32 & (BFM_ADC_ADCSWT_RSVD_8))>>(BFP_ADC_ADCSWT_RSVD_8))

#define BFP_ADC_ADCSWT_ADCSWT                   (0)                     /* bitfield lsb */
#define BFM_ADC_ADCSWT_ADCSWT                   ((uint32_t)0x000000ff)  /* bitfield mask */
#define BFN_ADC_ADCSWT_ADCSWT                   (8)                     /* bitfield width */
#define BFD_ADC_ADCSWT_ADCSWT                   (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSWT_ADCSWT(v)                ((((uint32_t) v) << (BFP_ADC_ADCSWT_ADCSWT)) & (BFM_ADC_ADCSWT_ADCSWT))
#define BFX_ADC_ADCSWT_ADCSWT(v)                ((((uint32_t) v) & (BFM_ADC_ADCSWT_ADCSWT)) >> (BFP_ADC_ADCSWT_ADCSWT))
#define BFW_ADC_ADCSWT_ADCSWT(v)                (REG_ADC_ADCSWT.U32 = ( (((uint32_t) v)<<(BFP_ADC_ADCSWT_ADCSWT)) & (BFM_ADC_ADCSWT_ADCSWT)) )
#define BFR_ADC_ADCSWT_ADCSWT()                 ((REG_ADC_ADCSWT.U32 & (BFM_ADC_ADCSWT_ADCSWT))>>(BFP_ADC_ADCSWT_ADCSWT))


// *****************************************************************************
//                                                                             *
//  ADC_ADCSL0CFG - Slot 0 Configuration Register                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_27                    :  5;
        unsigned ADSEL0                     :  3;
        unsigned RSVD_19                    :  5;
        unsigned THSEL0                     :  3;
        unsigned RSVD_12                    :  4;
        unsigned CHSEL0                     :  4;
        unsigned RSVD_2                     :  6;
        unsigned WCEN0                      :  1;
        unsigned SLEN0                      :  1;
    } B;
} reg_adc_adcsl0cfg_t;

#define REG_ADC_ADCSL0CFG_ADDR                  (REG_ADC_BASEADDR + 0x0000000CUL)
#define REG_ADC_ADCSL0CFG                       (*(volatile reg_adc_adcsl0cfg_t *) REG_ADC_ADCSL0CFG_ADDR)
#define REG_ADC_ADCSL0CFG_RD()                  (REG_ADC_ADCSL0CFG.U32)
#define REG_ADC_ADCSL0CFG_WR(v)                 (REG_ADC_ADCSL0CFG.U32 = (v))
#define REG_ADC_ADCSL0CFG_CLR(m)                (REG_ADC_ADCSL0CFG.U32 = ((REG_ADC_ADCSL0CFG.U32) & ~(m)))
#define REG_ADC_ADCSL0CFG_SET(m)                (REG_ADC_ADCSL0CFG.U32 = ((REG_ADC_ADCSL0CFG.U32) | (m)))
#define REG_ADC_ADCSL0CFG_DEF                   0x00000000

#define BFP_ADC_ADCSL0CFG_RSVD_27               (27)                    /* bitfield lsb */
#define BFM_ADC_ADCSL0CFG_RSVD_27               ((uint32_t)0xf8000000)  /* bitfield mask */
#define BFN_ADC_ADCSL0CFG_RSVD_27               (5)                     /* bitfield width */
#define BFD_ADC_ADCSL0CFG_RSVD_27               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL0CFG_RSVD_27(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL0CFG_RSVD_27)) & (BFM_ADC_ADCSL0CFG_RSVD_27))
#define BFX_ADC_ADCSL0CFG_RSVD_27(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL0CFG_RSVD_27)) >> (BFP_ADC_ADCSL0CFG_RSVD_27))
#define BFW_ADC_ADCSL0CFG_RSVD_27(v)            (REG_ADC_ADCSL0CFG.U32 = ( (REG_ADC_ADCSL0CFG.U32 & ~(BFM_ADC_ADCSL0CFG_RSVD_27)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL0CFG_RSVD_27)) & (BFM_ADC_ADCSL0CFG_RSVD_27)) ))
#define BFR_ADC_ADCSL0CFG_RSVD_27()             ((REG_ADC_ADCSL0CFG.U32 & (BFM_ADC_ADCSL0CFG_RSVD_27))>>(BFP_ADC_ADCSL0CFG_RSVD_27))

#define BFP_ADC_ADCSL0CFG_ADSEL0                (24)                    /* bitfield lsb */
#define BFM_ADC_ADCSL0CFG_ADSEL0                ((uint32_t)0x07000000)  /* bitfield mask */
#define BFN_ADC_ADCSL0CFG_ADSEL0                (3)                     /* bitfield width */
#define BFD_ADC_ADCSL0CFG_ADSEL0                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL0CFG_ADSEL0(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL0CFG_ADSEL0)) & (BFM_ADC_ADCSL0CFG_ADSEL0))
#define BFX_ADC_ADCSL0CFG_ADSEL0(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL0CFG_ADSEL0)) >> (BFP_ADC_ADCSL0CFG_ADSEL0))
#define BFW_ADC_ADCSL0CFG_ADSEL0(v)             (REG_ADC_ADCSL0CFG.U32 = ( (REG_ADC_ADCSL0CFG.U32 & ~(BFM_ADC_ADCSL0CFG_ADSEL0)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL0CFG_ADSEL0)) & (BFM_ADC_ADCSL0CFG_ADSEL0)) ))
#define BFR_ADC_ADCSL0CFG_ADSEL0()              ((REG_ADC_ADCSL0CFG.U32 & (BFM_ADC_ADCSL0CFG_ADSEL0))>>(BFP_ADC_ADCSL0CFG_ADSEL0))

#define BFP_ADC_ADCSL0CFG_RSVD_19               (19)                    /* bitfield lsb */
#define BFM_ADC_ADCSL0CFG_RSVD_19               ((uint32_t)0x00f80000)  /* bitfield mask */
#define BFN_ADC_ADCSL0CFG_RSVD_19               (5)                     /* bitfield width */
#define BFD_ADC_ADCSL0CFG_RSVD_19               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL0CFG_RSVD_19(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL0CFG_RSVD_19)) & (BFM_ADC_ADCSL0CFG_RSVD_19))
#define BFX_ADC_ADCSL0CFG_RSVD_19(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL0CFG_RSVD_19)) >> (BFP_ADC_ADCSL0CFG_RSVD_19))
#define BFW_ADC_ADCSL0CFG_RSVD_19(v)            (REG_ADC_ADCSL0CFG.U32 = ( (REG_ADC_ADCSL0CFG.U32 & ~(BFM_ADC_ADCSL0CFG_RSVD_19)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL0CFG_RSVD_19)) & (BFM_ADC_ADCSL0CFG_RSVD_19)) ))
#define BFR_ADC_ADCSL0CFG_RSVD_19()             ((REG_ADC_ADCSL0CFG.U32 & (BFM_ADC_ADCSL0CFG_RSVD_19))>>(BFP_ADC_ADCSL0CFG_RSVD_19))

#define BFP_ADC_ADCSL0CFG_THSEL0                (16)                    /* bitfield lsb */
#define BFM_ADC_ADCSL0CFG_THSEL0                ((uint32_t)0x00070000)  /* bitfield mask */
#define BFN_ADC_ADCSL0CFG_THSEL0                (3)                     /* bitfield width */
#define BFD_ADC_ADCSL0CFG_THSEL0                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL0CFG_THSEL0(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL0CFG_THSEL0)) & (BFM_ADC_ADCSL0CFG_THSEL0))
#define BFX_ADC_ADCSL0CFG_THSEL0(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL0CFG_THSEL0)) >> (BFP_ADC_ADCSL0CFG_THSEL0))
#define BFW_ADC_ADCSL0CFG_THSEL0(v)             (REG_ADC_ADCSL0CFG.U32 = ( (REG_ADC_ADCSL0CFG.U32 & ~(BFM_ADC_ADCSL0CFG_THSEL0)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL0CFG_THSEL0)) & (BFM_ADC_ADCSL0CFG_THSEL0)) ))
#define BFR_ADC_ADCSL0CFG_THSEL0()              ((REG_ADC_ADCSL0CFG.U32 & (BFM_ADC_ADCSL0CFG_THSEL0))>>(BFP_ADC_ADCSL0CFG_THSEL0))

#define BFP_ADC_ADCSL0CFG_RSVD_12               (12)                    /* bitfield lsb */
#define BFM_ADC_ADCSL0CFG_RSVD_12               ((uint32_t)0x0000f000)  /* bitfield mask */
#define BFN_ADC_ADCSL0CFG_RSVD_12               (4)                     /* bitfield width */
#define BFD_ADC_ADCSL0CFG_RSVD_12               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL0CFG_RSVD_12(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL0CFG_RSVD_12)) & (BFM_ADC_ADCSL0CFG_RSVD_12))
#define BFX_ADC_ADCSL0CFG_RSVD_12(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL0CFG_RSVD_12)) >> (BFP_ADC_ADCSL0CFG_RSVD_12))
#define BFW_ADC_ADCSL0CFG_RSVD_12(v)            (REG_ADC_ADCSL0CFG.U32 = ( (REG_ADC_ADCSL0CFG.U32 & ~(BFM_ADC_ADCSL0CFG_RSVD_12)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL0CFG_RSVD_12)) & (BFM_ADC_ADCSL0CFG_RSVD_12)) ))
#define BFR_ADC_ADCSL0CFG_RSVD_12()             ((REG_ADC_ADCSL0CFG.U32 & (BFM_ADC_ADCSL0CFG_RSVD_12))>>(BFP_ADC_ADCSL0CFG_RSVD_12))

#define BFP_ADC_ADCSL0CFG_CHSEL0                (8)                     /* bitfield lsb */
#define BFM_ADC_ADCSL0CFG_CHSEL0                ((uint32_t)0x00000f00)  /* bitfield mask */
#define BFN_ADC_ADCSL0CFG_CHSEL0                (4)                     /* bitfield width */
#define BFD_ADC_ADCSL0CFG_CHSEL0                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL0CFG_CHSEL0(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL0CFG_CHSEL0)) & (BFM_ADC_ADCSL0CFG_CHSEL0))
#define BFX_ADC_ADCSL0CFG_CHSEL0(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL0CFG_CHSEL0)) >> (BFP_ADC_ADCSL0CFG_CHSEL0))
#define BFW_ADC_ADCSL0CFG_CHSEL0(v)             (REG_ADC_ADCSL0CFG.U32 = ( (REG_ADC_ADCSL0CFG.U32 & ~(BFM_ADC_ADCSL0CFG_CHSEL0)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL0CFG_CHSEL0)) & (BFM_ADC_ADCSL0CFG_CHSEL0)) ))
#define BFR_ADC_ADCSL0CFG_CHSEL0()              ((REG_ADC_ADCSL0CFG.U32 & (BFM_ADC_ADCSL0CFG_CHSEL0))>>(BFP_ADC_ADCSL0CFG_CHSEL0))

#define BFP_ADC_ADCSL0CFG_RSVD_2                (2)                     /* bitfield lsb */
#define BFM_ADC_ADCSL0CFG_RSVD_2                ((uint32_t)0x000000fc)  /* bitfield mask */
#define BFN_ADC_ADCSL0CFG_RSVD_2                (6)                     /* bitfield width */
#define BFD_ADC_ADCSL0CFG_RSVD_2                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL0CFG_RSVD_2(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL0CFG_RSVD_2)) & (BFM_ADC_ADCSL0CFG_RSVD_2))
#define BFX_ADC_ADCSL0CFG_RSVD_2(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL0CFG_RSVD_2)) >> (BFP_ADC_ADCSL0CFG_RSVD_2))
#define BFW_ADC_ADCSL0CFG_RSVD_2(v)             (REG_ADC_ADCSL0CFG.U32 = ( (REG_ADC_ADCSL0CFG.U32 & ~(BFM_ADC_ADCSL0CFG_RSVD_2)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL0CFG_RSVD_2)) & (BFM_ADC_ADCSL0CFG_RSVD_2)) ))
#define BFR_ADC_ADCSL0CFG_RSVD_2()              ((REG_ADC_ADCSL0CFG.U32 & (BFM_ADC_ADCSL0CFG_RSVD_2))>>(BFP_ADC_ADCSL0CFG_RSVD_2))

#define BFP_ADC_ADCSL0CFG_WCEN0                 (1)                     /* bitfield lsb */
#define BFM_ADC_ADCSL0CFG_WCEN0                 ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_ADC_ADCSL0CFG_WCEN0                 (1)                     /* bitfield width */
#define BFD_ADC_ADCSL0CFG_WCEN0                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL0CFG_WCEN0(v)              ((((uint32_t) v) << (BFP_ADC_ADCSL0CFG_WCEN0)) & (BFM_ADC_ADCSL0CFG_WCEN0))
#define BFX_ADC_ADCSL0CFG_WCEN0(v)              ((((uint32_t) v) & (BFM_ADC_ADCSL0CFG_WCEN0)) >> (BFP_ADC_ADCSL0CFG_WCEN0))
#define BFW_ADC_ADCSL0CFG_WCEN0(v)              (REG_ADC_ADCSL0CFG.U32 = ( (REG_ADC_ADCSL0CFG.U32 & ~(BFM_ADC_ADCSL0CFG_WCEN0)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL0CFG_WCEN0)) & (BFM_ADC_ADCSL0CFG_WCEN0)) ))
#define BFR_ADC_ADCSL0CFG_WCEN0()               ((REG_ADC_ADCSL0CFG.U32 & (BFM_ADC_ADCSL0CFG_WCEN0))>>(BFP_ADC_ADCSL0CFG_WCEN0))

#define BFP_ADC_ADCSL0CFG_SLEN0                 (0)                     /* bitfield lsb */
#define BFM_ADC_ADCSL0CFG_SLEN0                 ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_ADC_ADCSL0CFG_SLEN0                 (1)                     /* bitfield width */
#define BFD_ADC_ADCSL0CFG_SLEN0                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL0CFG_SLEN0(v)              ((((uint32_t) v) << (BFP_ADC_ADCSL0CFG_SLEN0)) & (BFM_ADC_ADCSL0CFG_SLEN0))
#define BFX_ADC_ADCSL0CFG_SLEN0(v)              ((((uint32_t) v) & (BFM_ADC_ADCSL0CFG_SLEN0)) >> (BFP_ADC_ADCSL0CFG_SLEN0))
#define BFW_ADC_ADCSL0CFG_SLEN0(v)              (REG_ADC_ADCSL0CFG.U32 = ( (REG_ADC_ADCSL0CFG.U32 & ~(BFM_ADC_ADCSL0CFG_SLEN0)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL0CFG_SLEN0)) & (BFM_ADC_ADCSL0CFG_SLEN0)) ))
#define BFR_ADC_ADCSL0CFG_SLEN0()               ((REG_ADC_ADCSL0CFG.U32 & (BFM_ADC_ADCSL0CFG_SLEN0))>>(BFP_ADC_ADCSL0CFG_SLEN0))


// *****************************************************************************
//                                                                             *
//  ADC_ADCSL1CFG - Slot 1 Configuration Register                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_27                    :  5;
        unsigned ADSEL1                     :  3;
        unsigned RSVD_19                    :  5;
        unsigned THSEL1                     :  3;
        unsigned RSVD_12                    :  4;
        unsigned CHSEL1                     :  4;
        unsigned RSVD_2                     :  6;
        unsigned WCEN1                      :  1;
        unsigned SLEN1                      :  1;
    } B;
} reg_adc_adcsl1cfg_t;

#define REG_ADC_ADCSL1CFG_ADDR                  (REG_ADC_BASEADDR + 0x00000010UL)
#define REG_ADC_ADCSL1CFG                       (*(volatile reg_adc_adcsl1cfg_t *) REG_ADC_ADCSL1CFG_ADDR)
#define REG_ADC_ADCSL1CFG_RD()                  (REG_ADC_ADCSL1CFG.U32)
#define REG_ADC_ADCSL1CFG_WR(v)                 (REG_ADC_ADCSL1CFG.U32 = (v))
#define REG_ADC_ADCSL1CFG_CLR(m)                (REG_ADC_ADCSL1CFG.U32 = ((REG_ADC_ADCSL1CFG.U32) & ~(m)))
#define REG_ADC_ADCSL1CFG_SET(m)                (REG_ADC_ADCSL1CFG.U32 = ((REG_ADC_ADCSL1CFG.U32) | (m)))
#define REG_ADC_ADCSL1CFG_DEF                   0x00000000

#define BFP_ADC_ADCSL1CFG_RSVD_27               (27)                    /* bitfield lsb */
#define BFM_ADC_ADCSL1CFG_RSVD_27               ((uint32_t)0xf8000000)  /* bitfield mask */
#define BFN_ADC_ADCSL1CFG_RSVD_27               (5)                     /* bitfield width */
#define BFD_ADC_ADCSL1CFG_RSVD_27               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL1CFG_RSVD_27(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL1CFG_RSVD_27)) & (BFM_ADC_ADCSL1CFG_RSVD_27))
#define BFX_ADC_ADCSL1CFG_RSVD_27(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL1CFG_RSVD_27)) >> (BFP_ADC_ADCSL1CFG_RSVD_27))
#define BFW_ADC_ADCSL1CFG_RSVD_27(v)            (REG_ADC_ADCSL1CFG.U32 = ( (REG_ADC_ADCSL1CFG.U32 & ~(BFM_ADC_ADCSL1CFG_RSVD_27)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL1CFG_RSVD_27)) & (BFM_ADC_ADCSL1CFG_RSVD_27)) ))
#define BFR_ADC_ADCSL1CFG_RSVD_27()             ((REG_ADC_ADCSL1CFG.U32 & (BFM_ADC_ADCSL1CFG_RSVD_27))>>(BFP_ADC_ADCSL1CFG_RSVD_27))

#define BFP_ADC_ADCSL1CFG_ADSEL1                (24)                    /* bitfield lsb */
#define BFM_ADC_ADCSL1CFG_ADSEL1                ((uint32_t)0x07000000)  /* bitfield mask */
#define BFN_ADC_ADCSL1CFG_ADSEL1                (3)                     /* bitfield width */
#define BFD_ADC_ADCSL1CFG_ADSEL1                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL1CFG_ADSEL1(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL1CFG_ADSEL1)) & (BFM_ADC_ADCSL1CFG_ADSEL1))
#define BFX_ADC_ADCSL1CFG_ADSEL1(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL1CFG_ADSEL1)) >> (BFP_ADC_ADCSL1CFG_ADSEL1))
#define BFW_ADC_ADCSL1CFG_ADSEL1(v)             (REG_ADC_ADCSL1CFG.U32 = ( (REG_ADC_ADCSL1CFG.U32 & ~(BFM_ADC_ADCSL1CFG_ADSEL1)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL1CFG_ADSEL1)) & (BFM_ADC_ADCSL1CFG_ADSEL1)) ))
#define BFR_ADC_ADCSL1CFG_ADSEL1()              ((REG_ADC_ADCSL1CFG.U32 & (BFM_ADC_ADCSL1CFG_ADSEL1))>>(BFP_ADC_ADCSL1CFG_ADSEL1))

#define BFP_ADC_ADCSL1CFG_RSVD_19               (19)                    /* bitfield lsb */
#define BFM_ADC_ADCSL1CFG_RSVD_19               ((uint32_t)0x00f80000)  /* bitfield mask */
#define BFN_ADC_ADCSL1CFG_RSVD_19               (5)                     /* bitfield width */
#define BFD_ADC_ADCSL1CFG_RSVD_19               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL1CFG_RSVD_19(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL1CFG_RSVD_19)) & (BFM_ADC_ADCSL1CFG_RSVD_19))
#define BFX_ADC_ADCSL1CFG_RSVD_19(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL1CFG_RSVD_19)) >> (BFP_ADC_ADCSL1CFG_RSVD_19))
#define BFW_ADC_ADCSL1CFG_RSVD_19(v)            (REG_ADC_ADCSL1CFG.U32 = ( (REG_ADC_ADCSL1CFG.U32 & ~(BFM_ADC_ADCSL1CFG_RSVD_19)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL1CFG_RSVD_19)) & (BFM_ADC_ADCSL1CFG_RSVD_19)) ))
#define BFR_ADC_ADCSL1CFG_RSVD_19()             ((REG_ADC_ADCSL1CFG.U32 & (BFM_ADC_ADCSL1CFG_RSVD_19))>>(BFP_ADC_ADCSL1CFG_RSVD_19))

#define BFP_ADC_ADCSL1CFG_THSEL1                (16)                    /* bitfield lsb */
#define BFM_ADC_ADCSL1CFG_THSEL1                ((uint32_t)0x00070000)  /* bitfield mask */
#define BFN_ADC_ADCSL1CFG_THSEL1                (3)                     /* bitfield width */
#define BFD_ADC_ADCSL1CFG_THSEL1                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL1CFG_THSEL1(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL1CFG_THSEL1)) & (BFM_ADC_ADCSL1CFG_THSEL1))
#define BFX_ADC_ADCSL1CFG_THSEL1(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL1CFG_THSEL1)) >> (BFP_ADC_ADCSL1CFG_THSEL1))
#define BFW_ADC_ADCSL1CFG_THSEL1(v)             (REG_ADC_ADCSL1CFG.U32 = ( (REG_ADC_ADCSL1CFG.U32 & ~(BFM_ADC_ADCSL1CFG_THSEL1)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL1CFG_THSEL1)) & (BFM_ADC_ADCSL1CFG_THSEL1)) ))
#define BFR_ADC_ADCSL1CFG_THSEL1()              ((REG_ADC_ADCSL1CFG.U32 & (BFM_ADC_ADCSL1CFG_THSEL1))>>(BFP_ADC_ADCSL1CFG_THSEL1))

#define BFP_ADC_ADCSL1CFG_RSVD_12               (12)                    /* bitfield lsb */
#define BFM_ADC_ADCSL1CFG_RSVD_12               ((uint32_t)0x0000f000)  /* bitfield mask */
#define BFN_ADC_ADCSL1CFG_RSVD_12               (4)                     /* bitfield width */
#define BFD_ADC_ADCSL1CFG_RSVD_12               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL1CFG_RSVD_12(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL1CFG_RSVD_12)) & (BFM_ADC_ADCSL1CFG_RSVD_12))
#define BFX_ADC_ADCSL1CFG_RSVD_12(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL1CFG_RSVD_12)) >> (BFP_ADC_ADCSL1CFG_RSVD_12))
#define BFW_ADC_ADCSL1CFG_RSVD_12(v)            (REG_ADC_ADCSL1CFG.U32 = ( (REG_ADC_ADCSL1CFG.U32 & ~(BFM_ADC_ADCSL1CFG_RSVD_12)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL1CFG_RSVD_12)) & (BFM_ADC_ADCSL1CFG_RSVD_12)) ))
#define BFR_ADC_ADCSL1CFG_RSVD_12()             ((REG_ADC_ADCSL1CFG.U32 & (BFM_ADC_ADCSL1CFG_RSVD_12))>>(BFP_ADC_ADCSL1CFG_RSVD_12))

#define BFP_ADC_ADCSL1CFG_CHSEL1                (8)                     /* bitfield lsb */
#define BFM_ADC_ADCSL1CFG_CHSEL1                ((uint32_t)0x00000f00)  /* bitfield mask */
#define BFN_ADC_ADCSL1CFG_CHSEL1                (4)                     /* bitfield width */
#define BFD_ADC_ADCSL1CFG_CHSEL1                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL1CFG_CHSEL1(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL1CFG_CHSEL1)) & (BFM_ADC_ADCSL1CFG_CHSEL1))
#define BFX_ADC_ADCSL1CFG_CHSEL1(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL1CFG_CHSEL1)) >> (BFP_ADC_ADCSL1CFG_CHSEL1))
#define BFW_ADC_ADCSL1CFG_CHSEL1(v)             (REG_ADC_ADCSL1CFG.U32 = ( (REG_ADC_ADCSL1CFG.U32 & ~(BFM_ADC_ADCSL1CFG_CHSEL1)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL1CFG_CHSEL1)) & (BFM_ADC_ADCSL1CFG_CHSEL1)) ))
#define BFR_ADC_ADCSL1CFG_CHSEL1()              ((REG_ADC_ADCSL1CFG.U32 & (BFM_ADC_ADCSL1CFG_CHSEL1))>>(BFP_ADC_ADCSL1CFG_CHSEL1))

#define BFP_ADC_ADCSL1CFG_RSVD_2                (2)                     /* bitfield lsb */
#define BFM_ADC_ADCSL1CFG_RSVD_2                ((uint32_t)0x000000fc)  /* bitfield mask */
#define BFN_ADC_ADCSL1CFG_RSVD_2                (6)                     /* bitfield width */
#define BFD_ADC_ADCSL1CFG_RSVD_2                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL1CFG_RSVD_2(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL1CFG_RSVD_2)) & (BFM_ADC_ADCSL1CFG_RSVD_2))
#define BFX_ADC_ADCSL1CFG_RSVD_2(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL1CFG_RSVD_2)) >> (BFP_ADC_ADCSL1CFG_RSVD_2))
#define BFW_ADC_ADCSL1CFG_RSVD_2(v)             (REG_ADC_ADCSL1CFG.U32 = ( (REG_ADC_ADCSL1CFG.U32 & ~(BFM_ADC_ADCSL1CFG_RSVD_2)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL1CFG_RSVD_2)) & (BFM_ADC_ADCSL1CFG_RSVD_2)) ))
#define BFR_ADC_ADCSL1CFG_RSVD_2()              ((REG_ADC_ADCSL1CFG.U32 & (BFM_ADC_ADCSL1CFG_RSVD_2))>>(BFP_ADC_ADCSL1CFG_RSVD_2))

#define BFP_ADC_ADCSL1CFG_WCEN1                 (1)                     /* bitfield lsb */
#define BFM_ADC_ADCSL1CFG_WCEN1                 ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_ADC_ADCSL1CFG_WCEN1                 (1)                     /* bitfield width */
#define BFD_ADC_ADCSL1CFG_WCEN1                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL1CFG_WCEN1(v)              ((((uint32_t) v) << (BFP_ADC_ADCSL1CFG_WCEN1)) & (BFM_ADC_ADCSL1CFG_WCEN1))
#define BFX_ADC_ADCSL1CFG_WCEN1(v)              ((((uint32_t) v) & (BFM_ADC_ADCSL1CFG_WCEN1)) >> (BFP_ADC_ADCSL1CFG_WCEN1))
#define BFW_ADC_ADCSL1CFG_WCEN1(v)              (REG_ADC_ADCSL1CFG.U32 = ( (REG_ADC_ADCSL1CFG.U32 & ~(BFM_ADC_ADCSL1CFG_WCEN1)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL1CFG_WCEN1)) & (BFM_ADC_ADCSL1CFG_WCEN1)) ))
#define BFR_ADC_ADCSL1CFG_WCEN1()               ((REG_ADC_ADCSL1CFG.U32 & (BFM_ADC_ADCSL1CFG_WCEN1))>>(BFP_ADC_ADCSL1CFG_WCEN1))

#define BFP_ADC_ADCSL1CFG_SLEN1                 (0)                     /* bitfield lsb */
#define BFM_ADC_ADCSL1CFG_SLEN1                 ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_ADC_ADCSL1CFG_SLEN1                 (1)                     /* bitfield width */
#define BFD_ADC_ADCSL1CFG_SLEN1                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL1CFG_SLEN1(v)              ((((uint32_t) v) << (BFP_ADC_ADCSL1CFG_SLEN1)) & (BFM_ADC_ADCSL1CFG_SLEN1))
#define BFX_ADC_ADCSL1CFG_SLEN1(v)              ((((uint32_t) v) & (BFM_ADC_ADCSL1CFG_SLEN1)) >> (BFP_ADC_ADCSL1CFG_SLEN1))
#define BFW_ADC_ADCSL1CFG_SLEN1(v)              (REG_ADC_ADCSL1CFG.U32 = ( (REG_ADC_ADCSL1CFG.U32 & ~(BFM_ADC_ADCSL1CFG_SLEN1)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL1CFG_SLEN1)) & (BFM_ADC_ADCSL1CFG_SLEN1)) ))
#define BFR_ADC_ADCSL1CFG_SLEN1()               ((REG_ADC_ADCSL1CFG.U32 & (BFM_ADC_ADCSL1CFG_SLEN1))>>(BFP_ADC_ADCSL1CFG_SLEN1))


// *****************************************************************************
//                                                                             *
//  ADC_ADCSL2CFG - Slot 2 Configuration Register                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_27                    :  5;
        unsigned ADSEL2                     :  3;
        unsigned RSVD_19                    :  5;
        unsigned THSEL2                     :  3;
        unsigned RSVD_12                    :  4;
        unsigned CHSEL2                     :  4;
        unsigned RSVD_2                     :  6;
        unsigned WCEN2                      :  1;
        unsigned SLEN2                      :  1;
    } B;
} reg_adc_adcsl2cfg_t;

#define REG_ADC_ADCSL2CFG_ADDR                  (REG_ADC_BASEADDR + 0x00000014UL)
#define REG_ADC_ADCSL2CFG                       (*(volatile reg_adc_adcsl2cfg_t *) REG_ADC_ADCSL2CFG_ADDR)
#define REG_ADC_ADCSL2CFG_RD()                  (REG_ADC_ADCSL2CFG.U32)
#define REG_ADC_ADCSL2CFG_WR(v)                 (REG_ADC_ADCSL2CFG.U32 = (v))
#define REG_ADC_ADCSL2CFG_CLR(m)                (REG_ADC_ADCSL2CFG.U32 = ((REG_ADC_ADCSL2CFG.U32) & ~(m)))
#define REG_ADC_ADCSL2CFG_SET(m)                (REG_ADC_ADCSL2CFG.U32 = ((REG_ADC_ADCSL2CFG.U32) | (m)))
#define REG_ADC_ADCSL2CFG_DEF                   0x00000000

#define BFP_ADC_ADCSL2CFG_RSVD_27               (27)                    /* bitfield lsb */
#define BFM_ADC_ADCSL2CFG_RSVD_27               ((uint32_t)0xf8000000)  /* bitfield mask */
#define BFN_ADC_ADCSL2CFG_RSVD_27               (5)                     /* bitfield width */
#define BFD_ADC_ADCSL2CFG_RSVD_27               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL2CFG_RSVD_27(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL2CFG_RSVD_27)) & (BFM_ADC_ADCSL2CFG_RSVD_27))
#define BFX_ADC_ADCSL2CFG_RSVD_27(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL2CFG_RSVD_27)) >> (BFP_ADC_ADCSL2CFG_RSVD_27))
#define BFW_ADC_ADCSL2CFG_RSVD_27(v)            (REG_ADC_ADCSL2CFG.U32 = ( (REG_ADC_ADCSL2CFG.U32 & ~(BFM_ADC_ADCSL2CFG_RSVD_27)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL2CFG_RSVD_27)) & (BFM_ADC_ADCSL2CFG_RSVD_27)) ))
#define BFR_ADC_ADCSL2CFG_RSVD_27()             ((REG_ADC_ADCSL2CFG.U32 & (BFM_ADC_ADCSL2CFG_RSVD_27))>>(BFP_ADC_ADCSL2CFG_RSVD_27))

#define BFP_ADC_ADCSL2CFG_ADSEL2                (24)                    /* bitfield lsb */
#define BFM_ADC_ADCSL2CFG_ADSEL2                ((uint32_t)0x07000000)  /* bitfield mask */
#define BFN_ADC_ADCSL2CFG_ADSEL2                (3)                     /* bitfield width */
#define BFD_ADC_ADCSL2CFG_ADSEL2                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL2CFG_ADSEL2(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL2CFG_ADSEL2)) & (BFM_ADC_ADCSL2CFG_ADSEL2))
#define BFX_ADC_ADCSL2CFG_ADSEL2(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL2CFG_ADSEL2)) >> (BFP_ADC_ADCSL2CFG_ADSEL2))
#define BFW_ADC_ADCSL2CFG_ADSEL2(v)             (REG_ADC_ADCSL2CFG.U32 = ( (REG_ADC_ADCSL2CFG.U32 & ~(BFM_ADC_ADCSL2CFG_ADSEL2)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL2CFG_ADSEL2)) & (BFM_ADC_ADCSL2CFG_ADSEL2)) ))
#define BFR_ADC_ADCSL2CFG_ADSEL2()              ((REG_ADC_ADCSL2CFG.U32 & (BFM_ADC_ADCSL2CFG_ADSEL2))>>(BFP_ADC_ADCSL2CFG_ADSEL2))

#define BFP_ADC_ADCSL2CFG_RSVD_19               (19)                    /* bitfield lsb */
#define BFM_ADC_ADCSL2CFG_RSVD_19               ((uint32_t)0x00f80000)  /* bitfield mask */
#define BFN_ADC_ADCSL2CFG_RSVD_19               (5)                     /* bitfield width */
#define BFD_ADC_ADCSL2CFG_RSVD_19               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL2CFG_RSVD_19(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL2CFG_RSVD_19)) & (BFM_ADC_ADCSL2CFG_RSVD_19))
#define BFX_ADC_ADCSL2CFG_RSVD_19(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL2CFG_RSVD_19)) >> (BFP_ADC_ADCSL2CFG_RSVD_19))
#define BFW_ADC_ADCSL2CFG_RSVD_19(v)            (REG_ADC_ADCSL2CFG.U32 = ( (REG_ADC_ADCSL2CFG.U32 & ~(BFM_ADC_ADCSL2CFG_RSVD_19)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL2CFG_RSVD_19)) & (BFM_ADC_ADCSL2CFG_RSVD_19)) ))
#define BFR_ADC_ADCSL2CFG_RSVD_19()             ((REG_ADC_ADCSL2CFG.U32 & (BFM_ADC_ADCSL2CFG_RSVD_19))>>(BFP_ADC_ADCSL2CFG_RSVD_19))

#define BFP_ADC_ADCSL2CFG_THSEL2                (16)                    /* bitfield lsb */
#define BFM_ADC_ADCSL2CFG_THSEL2                ((uint32_t)0x00070000)  /* bitfield mask */
#define BFN_ADC_ADCSL2CFG_THSEL2                (3)                     /* bitfield width */
#define BFD_ADC_ADCSL2CFG_THSEL2                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL2CFG_THSEL2(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL2CFG_THSEL2)) & (BFM_ADC_ADCSL2CFG_THSEL2))
#define BFX_ADC_ADCSL2CFG_THSEL2(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL2CFG_THSEL2)) >> (BFP_ADC_ADCSL2CFG_THSEL2))
#define BFW_ADC_ADCSL2CFG_THSEL2(v)             (REG_ADC_ADCSL2CFG.U32 = ( (REG_ADC_ADCSL2CFG.U32 & ~(BFM_ADC_ADCSL2CFG_THSEL2)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL2CFG_THSEL2)) & (BFM_ADC_ADCSL2CFG_THSEL2)) ))
#define BFR_ADC_ADCSL2CFG_THSEL2()              ((REG_ADC_ADCSL2CFG.U32 & (BFM_ADC_ADCSL2CFG_THSEL2))>>(BFP_ADC_ADCSL2CFG_THSEL2))

#define BFP_ADC_ADCSL2CFG_RSVD_12               (12)                    /* bitfield lsb */
#define BFM_ADC_ADCSL2CFG_RSVD_12               ((uint32_t)0x0000f000)  /* bitfield mask */
#define BFN_ADC_ADCSL2CFG_RSVD_12               (4)                     /* bitfield width */
#define BFD_ADC_ADCSL2CFG_RSVD_12               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL2CFG_RSVD_12(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL2CFG_RSVD_12)) & (BFM_ADC_ADCSL2CFG_RSVD_12))
#define BFX_ADC_ADCSL2CFG_RSVD_12(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL2CFG_RSVD_12)) >> (BFP_ADC_ADCSL2CFG_RSVD_12))
#define BFW_ADC_ADCSL2CFG_RSVD_12(v)            (REG_ADC_ADCSL2CFG.U32 = ( (REG_ADC_ADCSL2CFG.U32 & ~(BFM_ADC_ADCSL2CFG_RSVD_12)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL2CFG_RSVD_12)) & (BFM_ADC_ADCSL2CFG_RSVD_12)) ))
#define BFR_ADC_ADCSL2CFG_RSVD_12()             ((REG_ADC_ADCSL2CFG.U32 & (BFM_ADC_ADCSL2CFG_RSVD_12))>>(BFP_ADC_ADCSL2CFG_RSVD_12))

#define BFP_ADC_ADCSL2CFG_CHSEL2                (8)                     /* bitfield lsb */
#define BFM_ADC_ADCSL2CFG_CHSEL2                ((uint32_t)0x00000f00)  /* bitfield mask */
#define BFN_ADC_ADCSL2CFG_CHSEL2                (4)                     /* bitfield width */
#define BFD_ADC_ADCSL2CFG_CHSEL2                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL2CFG_CHSEL2(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL2CFG_CHSEL2)) & (BFM_ADC_ADCSL2CFG_CHSEL2))
#define BFX_ADC_ADCSL2CFG_CHSEL2(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL2CFG_CHSEL2)) >> (BFP_ADC_ADCSL2CFG_CHSEL2))
#define BFW_ADC_ADCSL2CFG_CHSEL2(v)             (REG_ADC_ADCSL2CFG.U32 = ( (REG_ADC_ADCSL2CFG.U32 & ~(BFM_ADC_ADCSL2CFG_CHSEL2)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL2CFG_CHSEL2)) & (BFM_ADC_ADCSL2CFG_CHSEL2)) ))
#define BFR_ADC_ADCSL2CFG_CHSEL2()              ((REG_ADC_ADCSL2CFG.U32 & (BFM_ADC_ADCSL2CFG_CHSEL2))>>(BFP_ADC_ADCSL2CFG_CHSEL2))

#define BFP_ADC_ADCSL2CFG_RSVD_2                (2)                     /* bitfield lsb */
#define BFM_ADC_ADCSL2CFG_RSVD_2                ((uint32_t)0x000000fc)  /* bitfield mask */
#define BFN_ADC_ADCSL2CFG_RSVD_2                (6)                     /* bitfield width */
#define BFD_ADC_ADCSL2CFG_RSVD_2                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL2CFG_RSVD_2(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL2CFG_RSVD_2)) & (BFM_ADC_ADCSL2CFG_RSVD_2))
#define BFX_ADC_ADCSL2CFG_RSVD_2(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL2CFG_RSVD_2)) >> (BFP_ADC_ADCSL2CFG_RSVD_2))
#define BFW_ADC_ADCSL2CFG_RSVD_2(v)             (REG_ADC_ADCSL2CFG.U32 = ( (REG_ADC_ADCSL2CFG.U32 & ~(BFM_ADC_ADCSL2CFG_RSVD_2)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL2CFG_RSVD_2)) & (BFM_ADC_ADCSL2CFG_RSVD_2)) ))
#define BFR_ADC_ADCSL2CFG_RSVD_2()              ((REG_ADC_ADCSL2CFG.U32 & (BFM_ADC_ADCSL2CFG_RSVD_2))>>(BFP_ADC_ADCSL2CFG_RSVD_2))

#define BFP_ADC_ADCSL2CFG_WCEN2                 (1)                     /* bitfield lsb */
#define BFM_ADC_ADCSL2CFG_WCEN2                 ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_ADC_ADCSL2CFG_WCEN2                 (1)                     /* bitfield width */
#define BFD_ADC_ADCSL2CFG_WCEN2                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL2CFG_WCEN2(v)              ((((uint32_t) v) << (BFP_ADC_ADCSL2CFG_WCEN2)) & (BFM_ADC_ADCSL2CFG_WCEN2))
#define BFX_ADC_ADCSL2CFG_WCEN2(v)              ((((uint32_t) v) & (BFM_ADC_ADCSL2CFG_WCEN2)) >> (BFP_ADC_ADCSL2CFG_WCEN2))
#define BFW_ADC_ADCSL2CFG_WCEN2(v)              (REG_ADC_ADCSL2CFG.U32 = ( (REG_ADC_ADCSL2CFG.U32 & ~(BFM_ADC_ADCSL2CFG_WCEN2)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL2CFG_WCEN2)) & (BFM_ADC_ADCSL2CFG_WCEN2)) ))
#define BFR_ADC_ADCSL2CFG_WCEN2()               ((REG_ADC_ADCSL2CFG.U32 & (BFM_ADC_ADCSL2CFG_WCEN2))>>(BFP_ADC_ADCSL2CFG_WCEN2))

#define BFP_ADC_ADCSL2CFG_SLEN2                 (0)                     /* bitfield lsb */
#define BFM_ADC_ADCSL2CFG_SLEN2                 ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_ADC_ADCSL2CFG_SLEN2                 (1)                     /* bitfield width */
#define BFD_ADC_ADCSL2CFG_SLEN2                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL2CFG_SLEN2(v)              ((((uint32_t) v) << (BFP_ADC_ADCSL2CFG_SLEN2)) & (BFM_ADC_ADCSL2CFG_SLEN2))
#define BFX_ADC_ADCSL2CFG_SLEN2(v)              ((((uint32_t) v) & (BFM_ADC_ADCSL2CFG_SLEN2)) >> (BFP_ADC_ADCSL2CFG_SLEN2))
#define BFW_ADC_ADCSL2CFG_SLEN2(v)              (REG_ADC_ADCSL2CFG.U32 = ( (REG_ADC_ADCSL2CFG.U32 & ~(BFM_ADC_ADCSL2CFG_SLEN2)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL2CFG_SLEN2)) & (BFM_ADC_ADCSL2CFG_SLEN2)) ))
#define BFR_ADC_ADCSL2CFG_SLEN2()               ((REG_ADC_ADCSL2CFG.U32 & (BFM_ADC_ADCSL2CFG_SLEN2))>>(BFP_ADC_ADCSL2CFG_SLEN2))


// *****************************************************************************
//                                                                             *
//  ADC_ADCSL3CFG - Slot 3 Configuration Register                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_27                    :  5;
        unsigned ADSEL3                     :  3;
        unsigned RSVD_19                    :  5;
        unsigned THSEL3                     :  3;
        unsigned RSVD_12                    :  4;
        unsigned CHSEL3                     :  4;
        unsigned RSVD_2                     :  6;
        unsigned WCEN3                      :  1;
        unsigned SLEN3                      :  1;
    } B;
} reg_adc_adcsl3cfg_t;

#define REG_ADC_ADCSL3CFG_ADDR                  (REG_ADC_BASEADDR + 0x00000018UL)
#define REG_ADC_ADCSL3CFG                       (*(volatile reg_adc_adcsl3cfg_t *) REG_ADC_ADCSL3CFG_ADDR)
#define REG_ADC_ADCSL3CFG_RD()                  (REG_ADC_ADCSL3CFG.U32)
#define REG_ADC_ADCSL3CFG_WR(v)                 (REG_ADC_ADCSL3CFG.U32 = (v))
#define REG_ADC_ADCSL3CFG_CLR(m)                (REG_ADC_ADCSL3CFG.U32 = ((REG_ADC_ADCSL3CFG.U32) & ~(m)))
#define REG_ADC_ADCSL3CFG_SET(m)                (REG_ADC_ADCSL3CFG.U32 = ((REG_ADC_ADCSL3CFG.U32) | (m)))
#define REG_ADC_ADCSL3CFG_DEF                   0x00000000

#define BFP_ADC_ADCSL3CFG_RSVD_27               (27)                    /* bitfield lsb */
#define BFM_ADC_ADCSL3CFG_RSVD_27               ((uint32_t)0xf8000000)  /* bitfield mask */
#define BFN_ADC_ADCSL3CFG_RSVD_27               (5)                     /* bitfield width */
#define BFD_ADC_ADCSL3CFG_RSVD_27               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL3CFG_RSVD_27(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL3CFG_RSVD_27)) & (BFM_ADC_ADCSL3CFG_RSVD_27))
#define BFX_ADC_ADCSL3CFG_RSVD_27(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL3CFG_RSVD_27)) >> (BFP_ADC_ADCSL3CFG_RSVD_27))
#define BFW_ADC_ADCSL3CFG_RSVD_27(v)            (REG_ADC_ADCSL3CFG.U32 = ( (REG_ADC_ADCSL3CFG.U32 & ~(BFM_ADC_ADCSL3CFG_RSVD_27)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL3CFG_RSVD_27)) & (BFM_ADC_ADCSL3CFG_RSVD_27)) ))
#define BFR_ADC_ADCSL3CFG_RSVD_27()             ((REG_ADC_ADCSL3CFG.U32 & (BFM_ADC_ADCSL3CFG_RSVD_27))>>(BFP_ADC_ADCSL3CFG_RSVD_27))

#define BFP_ADC_ADCSL3CFG_ADSEL3                (24)                    /* bitfield lsb */
#define BFM_ADC_ADCSL3CFG_ADSEL3                ((uint32_t)0x07000000)  /* bitfield mask */
#define BFN_ADC_ADCSL3CFG_ADSEL3                (3)                     /* bitfield width */
#define BFD_ADC_ADCSL3CFG_ADSEL3                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL3CFG_ADSEL3(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL3CFG_ADSEL3)) & (BFM_ADC_ADCSL3CFG_ADSEL3))
#define BFX_ADC_ADCSL3CFG_ADSEL3(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL3CFG_ADSEL3)) >> (BFP_ADC_ADCSL3CFG_ADSEL3))
#define BFW_ADC_ADCSL3CFG_ADSEL3(v)             (REG_ADC_ADCSL3CFG.U32 = ( (REG_ADC_ADCSL3CFG.U32 & ~(BFM_ADC_ADCSL3CFG_ADSEL3)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL3CFG_ADSEL3)) & (BFM_ADC_ADCSL3CFG_ADSEL3)) ))
#define BFR_ADC_ADCSL3CFG_ADSEL3()              ((REG_ADC_ADCSL3CFG.U32 & (BFM_ADC_ADCSL3CFG_ADSEL3))>>(BFP_ADC_ADCSL3CFG_ADSEL3))

#define BFP_ADC_ADCSL3CFG_RSVD_19               (19)                    /* bitfield lsb */
#define BFM_ADC_ADCSL3CFG_RSVD_19               ((uint32_t)0x00f80000)  /* bitfield mask */
#define BFN_ADC_ADCSL3CFG_RSVD_19               (5)                     /* bitfield width */
#define BFD_ADC_ADCSL3CFG_RSVD_19               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL3CFG_RSVD_19(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL3CFG_RSVD_19)) & (BFM_ADC_ADCSL3CFG_RSVD_19))
#define BFX_ADC_ADCSL3CFG_RSVD_19(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL3CFG_RSVD_19)) >> (BFP_ADC_ADCSL3CFG_RSVD_19))
#define BFW_ADC_ADCSL3CFG_RSVD_19(v)            (REG_ADC_ADCSL3CFG.U32 = ( (REG_ADC_ADCSL3CFG.U32 & ~(BFM_ADC_ADCSL3CFG_RSVD_19)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL3CFG_RSVD_19)) & (BFM_ADC_ADCSL3CFG_RSVD_19)) ))
#define BFR_ADC_ADCSL3CFG_RSVD_19()             ((REG_ADC_ADCSL3CFG.U32 & (BFM_ADC_ADCSL3CFG_RSVD_19))>>(BFP_ADC_ADCSL3CFG_RSVD_19))

#define BFP_ADC_ADCSL3CFG_THSEL3                (16)                    /* bitfield lsb */
#define BFM_ADC_ADCSL3CFG_THSEL3                ((uint32_t)0x00070000)  /* bitfield mask */
#define BFN_ADC_ADCSL3CFG_THSEL3                (3)                     /* bitfield width */
#define BFD_ADC_ADCSL3CFG_THSEL3                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL3CFG_THSEL3(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL3CFG_THSEL3)) & (BFM_ADC_ADCSL3CFG_THSEL3))
#define BFX_ADC_ADCSL3CFG_THSEL3(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL3CFG_THSEL3)) >> (BFP_ADC_ADCSL3CFG_THSEL3))
#define BFW_ADC_ADCSL3CFG_THSEL3(v)             (REG_ADC_ADCSL3CFG.U32 = ( (REG_ADC_ADCSL3CFG.U32 & ~(BFM_ADC_ADCSL3CFG_THSEL3)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL3CFG_THSEL3)) & (BFM_ADC_ADCSL3CFG_THSEL3)) ))
#define BFR_ADC_ADCSL3CFG_THSEL3()              ((REG_ADC_ADCSL3CFG.U32 & (BFM_ADC_ADCSL3CFG_THSEL3))>>(BFP_ADC_ADCSL3CFG_THSEL3))

#define BFP_ADC_ADCSL3CFG_RSVD_12               (12)                    /* bitfield lsb */
#define BFM_ADC_ADCSL3CFG_RSVD_12               ((uint32_t)0x0000f000)  /* bitfield mask */
#define BFN_ADC_ADCSL3CFG_RSVD_12               (4)                     /* bitfield width */
#define BFD_ADC_ADCSL3CFG_RSVD_12               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL3CFG_RSVD_12(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL3CFG_RSVD_12)) & (BFM_ADC_ADCSL3CFG_RSVD_12))
#define BFX_ADC_ADCSL3CFG_RSVD_12(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL3CFG_RSVD_12)) >> (BFP_ADC_ADCSL3CFG_RSVD_12))
#define BFW_ADC_ADCSL3CFG_RSVD_12(v)            (REG_ADC_ADCSL3CFG.U32 = ( (REG_ADC_ADCSL3CFG.U32 & ~(BFM_ADC_ADCSL3CFG_RSVD_12)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL3CFG_RSVD_12)) & (BFM_ADC_ADCSL3CFG_RSVD_12)) ))
#define BFR_ADC_ADCSL3CFG_RSVD_12()             ((REG_ADC_ADCSL3CFG.U32 & (BFM_ADC_ADCSL3CFG_RSVD_12))>>(BFP_ADC_ADCSL3CFG_RSVD_12))

#define BFP_ADC_ADCSL3CFG_CHSEL3                (8)                     /* bitfield lsb */
#define BFM_ADC_ADCSL3CFG_CHSEL3                ((uint32_t)0x00000f00)  /* bitfield mask */
#define BFN_ADC_ADCSL3CFG_CHSEL3                (4)                     /* bitfield width */
#define BFD_ADC_ADCSL3CFG_CHSEL3                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL3CFG_CHSEL3(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL3CFG_CHSEL3)) & (BFM_ADC_ADCSL3CFG_CHSEL3))
#define BFX_ADC_ADCSL3CFG_CHSEL3(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL3CFG_CHSEL3)) >> (BFP_ADC_ADCSL3CFG_CHSEL3))
#define BFW_ADC_ADCSL3CFG_CHSEL3(v)             (REG_ADC_ADCSL3CFG.U32 = ( (REG_ADC_ADCSL3CFG.U32 & ~(BFM_ADC_ADCSL3CFG_CHSEL3)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL3CFG_CHSEL3)) & (BFM_ADC_ADCSL3CFG_CHSEL3)) ))
#define BFR_ADC_ADCSL3CFG_CHSEL3()              ((REG_ADC_ADCSL3CFG.U32 & (BFM_ADC_ADCSL3CFG_CHSEL3))>>(BFP_ADC_ADCSL3CFG_CHSEL3))

#define BFP_ADC_ADCSL3CFG_RSVD_2                (2)                     /* bitfield lsb */
#define BFM_ADC_ADCSL3CFG_RSVD_2                ((uint32_t)0x000000fc)  /* bitfield mask */
#define BFN_ADC_ADCSL3CFG_RSVD_2                (6)                     /* bitfield width */
#define BFD_ADC_ADCSL3CFG_RSVD_2                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL3CFG_RSVD_2(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL3CFG_RSVD_2)) & (BFM_ADC_ADCSL3CFG_RSVD_2))
#define BFX_ADC_ADCSL3CFG_RSVD_2(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL3CFG_RSVD_2)) >> (BFP_ADC_ADCSL3CFG_RSVD_2))
#define BFW_ADC_ADCSL3CFG_RSVD_2(v)             (REG_ADC_ADCSL3CFG.U32 = ( (REG_ADC_ADCSL3CFG.U32 & ~(BFM_ADC_ADCSL3CFG_RSVD_2)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL3CFG_RSVD_2)) & (BFM_ADC_ADCSL3CFG_RSVD_2)) ))
#define BFR_ADC_ADCSL3CFG_RSVD_2()              ((REG_ADC_ADCSL3CFG.U32 & (BFM_ADC_ADCSL3CFG_RSVD_2))>>(BFP_ADC_ADCSL3CFG_RSVD_2))

#define BFP_ADC_ADCSL3CFG_WCEN3                 (1)                     /* bitfield lsb */
#define BFM_ADC_ADCSL3CFG_WCEN3                 ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_ADC_ADCSL3CFG_WCEN3                 (1)                     /* bitfield width */
#define BFD_ADC_ADCSL3CFG_WCEN3                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL3CFG_WCEN3(v)              ((((uint32_t) v) << (BFP_ADC_ADCSL3CFG_WCEN3)) & (BFM_ADC_ADCSL3CFG_WCEN3))
#define BFX_ADC_ADCSL3CFG_WCEN3(v)              ((((uint32_t) v) & (BFM_ADC_ADCSL3CFG_WCEN3)) >> (BFP_ADC_ADCSL3CFG_WCEN3))
#define BFW_ADC_ADCSL3CFG_WCEN3(v)              (REG_ADC_ADCSL3CFG.U32 = ( (REG_ADC_ADCSL3CFG.U32 & ~(BFM_ADC_ADCSL3CFG_WCEN3)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL3CFG_WCEN3)) & (BFM_ADC_ADCSL3CFG_WCEN3)) ))
#define BFR_ADC_ADCSL3CFG_WCEN3()               ((REG_ADC_ADCSL3CFG.U32 & (BFM_ADC_ADCSL3CFG_WCEN3))>>(BFP_ADC_ADCSL3CFG_WCEN3))

#define BFP_ADC_ADCSL3CFG_SLEN3                 (0)                     /* bitfield lsb */
#define BFM_ADC_ADCSL3CFG_SLEN3                 ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_ADC_ADCSL3CFG_SLEN3                 (1)                     /* bitfield width */
#define BFD_ADC_ADCSL3CFG_SLEN3                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL3CFG_SLEN3(v)              ((((uint32_t) v) << (BFP_ADC_ADCSL3CFG_SLEN3)) & (BFM_ADC_ADCSL3CFG_SLEN3))
#define BFX_ADC_ADCSL3CFG_SLEN3(v)              ((((uint32_t) v) & (BFM_ADC_ADCSL3CFG_SLEN3)) >> (BFP_ADC_ADCSL3CFG_SLEN3))
#define BFW_ADC_ADCSL3CFG_SLEN3(v)              (REG_ADC_ADCSL3CFG.U32 = ( (REG_ADC_ADCSL3CFG.U32 & ~(BFM_ADC_ADCSL3CFG_SLEN3)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL3CFG_SLEN3)) & (BFM_ADC_ADCSL3CFG_SLEN3)) ))
#define BFR_ADC_ADCSL3CFG_SLEN3()               ((REG_ADC_ADCSL3CFG.U32 & (BFM_ADC_ADCSL3CFG_SLEN3))>>(BFP_ADC_ADCSL3CFG_SLEN3))


// *****************************************************************************
//                                                                             *
//  ADC_ADCSL4CFG - Slot 4 Configuration Register                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_27                    :  5;
        unsigned ADSEL4                     :  3;
        unsigned RSVD_19                    :  5;
        unsigned THSEL4                     :  3;
        unsigned RSVD_12                    :  4;
        unsigned CHSEL4                     :  4;
        unsigned RSVD_2                     :  6;
        unsigned WCEN4                      :  1;
        unsigned SLEN4                      :  1;
    } B;
} reg_adc_adcsl4cfg_t;

#define REG_ADC_ADCSL4CFG_ADDR                  (REG_ADC_BASEADDR + 0x0000001CUL)
#define REG_ADC_ADCSL4CFG                       (*(volatile reg_adc_adcsl4cfg_t *) REG_ADC_ADCSL4CFG_ADDR)
#define REG_ADC_ADCSL4CFG_RD()                  (REG_ADC_ADCSL4CFG.U32)
#define REG_ADC_ADCSL4CFG_WR(v)                 (REG_ADC_ADCSL4CFG.U32 = (v))
#define REG_ADC_ADCSL4CFG_CLR(m)                (REG_ADC_ADCSL4CFG.U32 = ((REG_ADC_ADCSL4CFG.U32) & ~(m)))
#define REG_ADC_ADCSL4CFG_SET(m)                (REG_ADC_ADCSL4CFG.U32 = ((REG_ADC_ADCSL4CFG.U32) | (m)))
#define REG_ADC_ADCSL4CFG_DEF                   0x00000000

#define BFP_ADC_ADCSL4CFG_RSVD_27               (27)                    /* bitfield lsb */
#define BFM_ADC_ADCSL4CFG_RSVD_27               ((uint32_t)0xf8000000)  /* bitfield mask */
#define BFN_ADC_ADCSL4CFG_RSVD_27               (5)                     /* bitfield width */
#define BFD_ADC_ADCSL4CFG_RSVD_27               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL4CFG_RSVD_27(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL4CFG_RSVD_27)) & (BFM_ADC_ADCSL4CFG_RSVD_27))
#define BFX_ADC_ADCSL4CFG_RSVD_27(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL4CFG_RSVD_27)) >> (BFP_ADC_ADCSL4CFG_RSVD_27))
#define BFW_ADC_ADCSL4CFG_RSVD_27(v)            (REG_ADC_ADCSL4CFG.U32 = ( (REG_ADC_ADCSL4CFG.U32 & ~(BFM_ADC_ADCSL4CFG_RSVD_27)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL4CFG_RSVD_27)) & (BFM_ADC_ADCSL4CFG_RSVD_27)) ))
#define BFR_ADC_ADCSL4CFG_RSVD_27()             ((REG_ADC_ADCSL4CFG.U32 & (BFM_ADC_ADCSL4CFG_RSVD_27))>>(BFP_ADC_ADCSL4CFG_RSVD_27))

#define BFP_ADC_ADCSL4CFG_ADSEL4                (24)                    /* bitfield lsb */
#define BFM_ADC_ADCSL4CFG_ADSEL4                ((uint32_t)0x07000000)  /* bitfield mask */
#define BFN_ADC_ADCSL4CFG_ADSEL4                (3)                     /* bitfield width */
#define BFD_ADC_ADCSL4CFG_ADSEL4                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL4CFG_ADSEL4(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL4CFG_ADSEL4)) & (BFM_ADC_ADCSL4CFG_ADSEL4))
#define BFX_ADC_ADCSL4CFG_ADSEL4(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL4CFG_ADSEL4)) >> (BFP_ADC_ADCSL4CFG_ADSEL4))
#define BFW_ADC_ADCSL4CFG_ADSEL4(v)             (REG_ADC_ADCSL4CFG.U32 = ( (REG_ADC_ADCSL4CFG.U32 & ~(BFM_ADC_ADCSL4CFG_ADSEL4)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL4CFG_ADSEL4)) & (BFM_ADC_ADCSL4CFG_ADSEL4)) ))
#define BFR_ADC_ADCSL4CFG_ADSEL4()              ((REG_ADC_ADCSL4CFG.U32 & (BFM_ADC_ADCSL4CFG_ADSEL4))>>(BFP_ADC_ADCSL4CFG_ADSEL4))

#define BFP_ADC_ADCSL4CFG_RSVD_19               (19)                    /* bitfield lsb */
#define BFM_ADC_ADCSL4CFG_RSVD_19               ((uint32_t)0x00f80000)  /* bitfield mask */
#define BFN_ADC_ADCSL4CFG_RSVD_19               (5)                     /* bitfield width */
#define BFD_ADC_ADCSL4CFG_RSVD_19               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL4CFG_RSVD_19(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL4CFG_RSVD_19)) & (BFM_ADC_ADCSL4CFG_RSVD_19))
#define BFX_ADC_ADCSL4CFG_RSVD_19(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL4CFG_RSVD_19)) >> (BFP_ADC_ADCSL4CFG_RSVD_19))
#define BFW_ADC_ADCSL4CFG_RSVD_19(v)            (REG_ADC_ADCSL4CFG.U32 = ( (REG_ADC_ADCSL4CFG.U32 & ~(BFM_ADC_ADCSL4CFG_RSVD_19)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL4CFG_RSVD_19)) & (BFM_ADC_ADCSL4CFG_RSVD_19)) ))
#define BFR_ADC_ADCSL4CFG_RSVD_19()             ((REG_ADC_ADCSL4CFG.U32 & (BFM_ADC_ADCSL4CFG_RSVD_19))>>(BFP_ADC_ADCSL4CFG_RSVD_19))

#define BFP_ADC_ADCSL4CFG_THSEL4                (16)                    /* bitfield lsb */
#define BFM_ADC_ADCSL4CFG_THSEL4                ((uint32_t)0x00070000)  /* bitfield mask */
#define BFN_ADC_ADCSL4CFG_THSEL4                (3)                     /* bitfield width */
#define BFD_ADC_ADCSL4CFG_THSEL4                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL4CFG_THSEL4(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL4CFG_THSEL4)) & (BFM_ADC_ADCSL4CFG_THSEL4))
#define BFX_ADC_ADCSL4CFG_THSEL4(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL4CFG_THSEL4)) >> (BFP_ADC_ADCSL4CFG_THSEL4))
#define BFW_ADC_ADCSL4CFG_THSEL4(v)             (REG_ADC_ADCSL4CFG.U32 = ( (REG_ADC_ADCSL4CFG.U32 & ~(BFM_ADC_ADCSL4CFG_THSEL4)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL4CFG_THSEL4)) & (BFM_ADC_ADCSL4CFG_THSEL4)) ))
#define BFR_ADC_ADCSL4CFG_THSEL4()              ((REG_ADC_ADCSL4CFG.U32 & (BFM_ADC_ADCSL4CFG_THSEL4))>>(BFP_ADC_ADCSL4CFG_THSEL4))

#define BFP_ADC_ADCSL4CFG_RSVD_12               (12)                    /* bitfield lsb */
#define BFM_ADC_ADCSL4CFG_RSVD_12               ((uint32_t)0x0000f000)  /* bitfield mask */
#define BFN_ADC_ADCSL4CFG_RSVD_12               (4)                     /* bitfield width */
#define BFD_ADC_ADCSL4CFG_RSVD_12               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL4CFG_RSVD_12(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL4CFG_RSVD_12)) & (BFM_ADC_ADCSL4CFG_RSVD_12))
#define BFX_ADC_ADCSL4CFG_RSVD_12(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL4CFG_RSVD_12)) >> (BFP_ADC_ADCSL4CFG_RSVD_12))
#define BFW_ADC_ADCSL4CFG_RSVD_12(v)            (REG_ADC_ADCSL4CFG.U32 = ( (REG_ADC_ADCSL4CFG.U32 & ~(BFM_ADC_ADCSL4CFG_RSVD_12)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL4CFG_RSVD_12)) & (BFM_ADC_ADCSL4CFG_RSVD_12)) ))
#define BFR_ADC_ADCSL4CFG_RSVD_12()             ((REG_ADC_ADCSL4CFG.U32 & (BFM_ADC_ADCSL4CFG_RSVD_12))>>(BFP_ADC_ADCSL4CFG_RSVD_12))

#define BFP_ADC_ADCSL4CFG_CHSEL4                (8)                     /* bitfield lsb */
#define BFM_ADC_ADCSL4CFG_CHSEL4                ((uint32_t)0x00000f00)  /* bitfield mask */
#define BFN_ADC_ADCSL4CFG_CHSEL4                (4)                     /* bitfield width */
#define BFD_ADC_ADCSL4CFG_CHSEL4                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL4CFG_CHSEL4(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL4CFG_CHSEL4)) & (BFM_ADC_ADCSL4CFG_CHSEL4))
#define BFX_ADC_ADCSL4CFG_CHSEL4(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL4CFG_CHSEL4)) >> (BFP_ADC_ADCSL4CFG_CHSEL4))
#define BFW_ADC_ADCSL4CFG_CHSEL4(v)             (REG_ADC_ADCSL4CFG.U32 = ( (REG_ADC_ADCSL4CFG.U32 & ~(BFM_ADC_ADCSL4CFG_CHSEL4)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL4CFG_CHSEL4)) & (BFM_ADC_ADCSL4CFG_CHSEL4)) ))
#define BFR_ADC_ADCSL4CFG_CHSEL4()              ((REG_ADC_ADCSL4CFG.U32 & (BFM_ADC_ADCSL4CFG_CHSEL4))>>(BFP_ADC_ADCSL4CFG_CHSEL4))

#define BFP_ADC_ADCSL4CFG_RSVD_2                (2)                     /* bitfield lsb */
#define BFM_ADC_ADCSL4CFG_RSVD_2                ((uint32_t)0x000000fc)  /* bitfield mask */
#define BFN_ADC_ADCSL4CFG_RSVD_2                (6)                     /* bitfield width */
#define BFD_ADC_ADCSL4CFG_RSVD_2                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL4CFG_RSVD_2(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL4CFG_RSVD_2)) & (BFM_ADC_ADCSL4CFG_RSVD_2))
#define BFX_ADC_ADCSL4CFG_RSVD_2(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL4CFG_RSVD_2)) >> (BFP_ADC_ADCSL4CFG_RSVD_2))
#define BFW_ADC_ADCSL4CFG_RSVD_2(v)             (REG_ADC_ADCSL4CFG.U32 = ( (REG_ADC_ADCSL4CFG.U32 & ~(BFM_ADC_ADCSL4CFG_RSVD_2)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL4CFG_RSVD_2)) & (BFM_ADC_ADCSL4CFG_RSVD_2)) ))
#define BFR_ADC_ADCSL4CFG_RSVD_2()              ((REG_ADC_ADCSL4CFG.U32 & (BFM_ADC_ADCSL4CFG_RSVD_2))>>(BFP_ADC_ADCSL4CFG_RSVD_2))

#define BFP_ADC_ADCSL4CFG_WCEN4                 (1)                     /* bitfield lsb */
#define BFM_ADC_ADCSL4CFG_WCEN4                 ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_ADC_ADCSL4CFG_WCEN4                 (1)                     /* bitfield width */
#define BFD_ADC_ADCSL4CFG_WCEN4                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL4CFG_WCEN4(v)              ((((uint32_t) v) << (BFP_ADC_ADCSL4CFG_WCEN4)) & (BFM_ADC_ADCSL4CFG_WCEN4))
#define BFX_ADC_ADCSL4CFG_WCEN4(v)              ((((uint32_t) v) & (BFM_ADC_ADCSL4CFG_WCEN4)) >> (BFP_ADC_ADCSL4CFG_WCEN4))
#define BFW_ADC_ADCSL4CFG_WCEN4(v)              (REG_ADC_ADCSL4CFG.U32 = ( (REG_ADC_ADCSL4CFG.U32 & ~(BFM_ADC_ADCSL4CFG_WCEN4)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL4CFG_WCEN4)) & (BFM_ADC_ADCSL4CFG_WCEN4)) ))
#define BFR_ADC_ADCSL4CFG_WCEN4()               ((REG_ADC_ADCSL4CFG.U32 & (BFM_ADC_ADCSL4CFG_WCEN4))>>(BFP_ADC_ADCSL4CFG_WCEN4))

#define BFP_ADC_ADCSL4CFG_SLEN4                 (0)                     /* bitfield lsb */
#define BFM_ADC_ADCSL4CFG_SLEN4                 ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_ADC_ADCSL4CFG_SLEN4                 (1)                     /* bitfield width */
#define BFD_ADC_ADCSL4CFG_SLEN4                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL4CFG_SLEN4(v)              ((((uint32_t) v) << (BFP_ADC_ADCSL4CFG_SLEN4)) & (BFM_ADC_ADCSL4CFG_SLEN4))
#define BFX_ADC_ADCSL4CFG_SLEN4(v)              ((((uint32_t) v) & (BFM_ADC_ADCSL4CFG_SLEN4)) >> (BFP_ADC_ADCSL4CFG_SLEN4))
#define BFW_ADC_ADCSL4CFG_SLEN4(v)              (REG_ADC_ADCSL4CFG.U32 = ( (REG_ADC_ADCSL4CFG.U32 & ~(BFM_ADC_ADCSL4CFG_SLEN4)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL4CFG_SLEN4)) & (BFM_ADC_ADCSL4CFG_SLEN4)) ))
#define BFR_ADC_ADCSL4CFG_SLEN4()               ((REG_ADC_ADCSL4CFG.U32 & (BFM_ADC_ADCSL4CFG_SLEN4))>>(BFP_ADC_ADCSL4CFG_SLEN4))


// *****************************************************************************
//                                                                             *
//  ADC_ADCSL5CFG - Slot 5 Configuration Register                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_27                    :  5;
        unsigned ADSEL5                     :  3;
        unsigned RSVD_19                    :  5;
        unsigned THSEL5                     :  3;
        unsigned RSVD_12                    :  4;
        unsigned CHSEL5                     :  4;
        unsigned RSVD_2                     :  6;
        unsigned WCEN5                      :  1;
        unsigned SLEN5                      :  1;
    } B;
} reg_adc_adcsl5cfg_t;

#define REG_ADC_ADCSL5CFG_ADDR                  (REG_ADC_BASEADDR + 0x00000020UL)
#define REG_ADC_ADCSL5CFG                       (*(volatile reg_adc_adcsl5cfg_t *) REG_ADC_ADCSL5CFG_ADDR)
#define REG_ADC_ADCSL5CFG_RD()                  (REG_ADC_ADCSL5CFG.U32)
#define REG_ADC_ADCSL5CFG_WR(v)                 (REG_ADC_ADCSL5CFG.U32 = (v))
#define REG_ADC_ADCSL5CFG_CLR(m)                (REG_ADC_ADCSL5CFG.U32 = ((REG_ADC_ADCSL5CFG.U32) & ~(m)))
#define REG_ADC_ADCSL5CFG_SET(m)                (REG_ADC_ADCSL5CFG.U32 = ((REG_ADC_ADCSL5CFG.U32) | (m)))
#define REG_ADC_ADCSL5CFG_DEF                   0x00000000

#define BFP_ADC_ADCSL5CFG_RSVD_27               (27)                    /* bitfield lsb */
#define BFM_ADC_ADCSL5CFG_RSVD_27               ((uint32_t)0xf8000000)  /* bitfield mask */
#define BFN_ADC_ADCSL5CFG_RSVD_27               (5)                     /* bitfield width */
#define BFD_ADC_ADCSL5CFG_RSVD_27               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL5CFG_RSVD_27(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL5CFG_RSVD_27)) & (BFM_ADC_ADCSL5CFG_RSVD_27))
#define BFX_ADC_ADCSL5CFG_RSVD_27(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL5CFG_RSVD_27)) >> (BFP_ADC_ADCSL5CFG_RSVD_27))
#define BFW_ADC_ADCSL5CFG_RSVD_27(v)            (REG_ADC_ADCSL5CFG.U32 = ( (REG_ADC_ADCSL5CFG.U32 & ~(BFM_ADC_ADCSL5CFG_RSVD_27)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL5CFG_RSVD_27)) & (BFM_ADC_ADCSL5CFG_RSVD_27)) ))
#define BFR_ADC_ADCSL5CFG_RSVD_27()             ((REG_ADC_ADCSL5CFG.U32 & (BFM_ADC_ADCSL5CFG_RSVD_27))>>(BFP_ADC_ADCSL5CFG_RSVD_27))

#define BFP_ADC_ADCSL5CFG_ADSEL5                (24)                    /* bitfield lsb */
#define BFM_ADC_ADCSL5CFG_ADSEL5                ((uint32_t)0x07000000)  /* bitfield mask */
#define BFN_ADC_ADCSL5CFG_ADSEL5                (3)                     /* bitfield width */
#define BFD_ADC_ADCSL5CFG_ADSEL5                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL5CFG_ADSEL5(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL5CFG_ADSEL5)) & (BFM_ADC_ADCSL5CFG_ADSEL5))
#define BFX_ADC_ADCSL5CFG_ADSEL5(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL5CFG_ADSEL5)) >> (BFP_ADC_ADCSL5CFG_ADSEL5))
#define BFW_ADC_ADCSL5CFG_ADSEL5(v)             (REG_ADC_ADCSL5CFG.U32 = ( (REG_ADC_ADCSL5CFG.U32 & ~(BFM_ADC_ADCSL5CFG_ADSEL5)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL5CFG_ADSEL5)) & (BFM_ADC_ADCSL5CFG_ADSEL5)) ))
#define BFR_ADC_ADCSL5CFG_ADSEL5()              ((REG_ADC_ADCSL5CFG.U32 & (BFM_ADC_ADCSL5CFG_ADSEL5))>>(BFP_ADC_ADCSL5CFG_ADSEL5))

#define BFP_ADC_ADCSL5CFG_RSVD_19               (19)                    /* bitfield lsb */
#define BFM_ADC_ADCSL5CFG_RSVD_19               ((uint32_t)0x00f80000)  /* bitfield mask */
#define BFN_ADC_ADCSL5CFG_RSVD_19               (5)                     /* bitfield width */
#define BFD_ADC_ADCSL5CFG_RSVD_19               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL5CFG_RSVD_19(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL5CFG_RSVD_19)) & (BFM_ADC_ADCSL5CFG_RSVD_19))
#define BFX_ADC_ADCSL5CFG_RSVD_19(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL5CFG_RSVD_19)) >> (BFP_ADC_ADCSL5CFG_RSVD_19))
#define BFW_ADC_ADCSL5CFG_RSVD_19(v)            (REG_ADC_ADCSL5CFG.U32 = ( (REG_ADC_ADCSL5CFG.U32 & ~(BFM_ADC_ADCSL5CFG_RSVD_19)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL5CFG_RSVD_19)) & (BFM_ADC_ADCSL5CFG_RSVD_19)) ))
#define BFR_ADC_ADCSL5CFG_RSVD_19()             ((REG_ADC_ADCSL5CFG.U32 & (BFM_ADC_ADCSL5CFG_RSVD_19))>>(BFP_ADC_ADCSL5CFG_RSVD_19))

#define BFP_ADC_ADCSL5CFG_THSEL5                (16)                    /* bitfield lsb */
#define BFM_ADC_ADCSL5CFG_THSEL5                ((uint32_t)0x00070000)  /* bitfield mask */
#define BFN_ADC_ADCSL5CFG_THSEL5                (3)                     /* bitfield width */
#define BFD_ADC_ADCSL5CFG_THSEL5                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL5CFG_THSEL5(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL5CFG_THSEL5)) & (BFM_ADC_ADCSL5CFG_THSEL5))
#define BFX_ADC_ADCSL5CFG_THSEL5(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL5CFG_THSEL5)) >> (BFP_ADC_ADCSL5CFG_THSEL5))
#define BFW_ADC_ADCSL5CFG_THSEL5(v)             (REG_ADC_ADCSL5CFG.U32 = ( (REG_ADC_ADCSL5CFG.U32 & ~(BFM_ADC_ADCSL5CFG_THSEL5)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL5CFG_THSEL5)) & (BFM_ADC_ADCSL5CFG_THSEL5)) ))
#define BFR_ADC_ADCSL5CFG_THSEL5()              ((REG_ADC_ADCSL5CFG.U32 & (BFM_ADC_ADCSL5CFG_THSEL5))>>(BFP_ADC_ADCSL5CFG_THSEL5))

#define BFP_ADC_ADCSL5CFG_RSVD_12               (12)                    /* bitfield lsb */
#define BFM_ADC_ADCSL5CFG_RSVD_12               ((uint32_t)0x0000f000)  /* bitfield mask */
#define BFN_ADC_ADCSL5CFG_RSVD_12               (4)                     /* bitfield width */
#define BFD_ADC_ADCSL5CFG_RSVD_12               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL5CFG_RSVD_12(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL5CFG_RSVD_12)) & (BFM_ADC_ADCSL5CFG_RSVD_12))
#define BFX_ADC_ADCSL5CFG_RSVD_12(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL5CFG_RSVD_12)) >> (BFP_ADC_ADCSL5CFG_RSVD_12))
#define BFW_ADC_ADCSL5CFG_RSVD_12(v)            (REG_ADC_ADCSL5CFG.U32 = ( (REG_ADC_ADCSL5CFG.U32 & ~(BFM_ADC_ADCSL5CFG_RSVD_12)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL5CFG_RSVD_12)) & (BFM_ADC_ADCSL5CFG_RSVD_12)) ))
#define BFR_ADC_ADCSL5CFG_RSVD_12()             ((REG_ADC_ADCSL5CFG.U32 & (BFM_ADC_ADCSL5CFG_RSVD_12))>>(BFP_ADC_ADCSL5CFG_RSVD_12))

#define BFP_ADC_ADCSL5CFG_CHSEL5                (8)                     /* bitfield lsb */
#define BFM_ADC_ADCSL5CFG_CHSEL5                ((uint32_t)0x00000f00)  /* bitfield mask */
#define BFN_ADC_ADCSL5CFG_CHSEL5                (4)                     /* bitfield width */
#define BFD_ADC_ADCSL5CFG_CHSEL5                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL5CFG_CHSEL5(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL5CFG_CHSEL5)) & (BFM_ADC_ADCSL5CFG_CHSEL5))
#define BFX_ADC_ADCSL5CFG_CHSEL5(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL5CFG_CHSEL5)) >> (BFP_ADC_ADCSL5CFG_CHSEL5))
#define BFW_ADC_ADCSL5CFG_CHSEL5(v)             (REG_ADC_ADCSL5CFG.U32 = ( (REG_ADC_ADCSL5CFG.U32 & ~(BFM_ADC_ADCSL5CFG_CHSEL5)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL5CFG_CHSEL5)) & (BFM_ADC_ADCSL5CFG_CHSEL5)) ))
#define BFR_ADC_ADCSL5CFG_CHSEL5()              ((REG_ADC_ADCSL5CFG.U32 & (BFM_ADC_ADCSL5CFG_CHSEL5))>>(BFP_ADC_ADCSL5CFG_CHSEL5))

#define BFP_ADC_ADCSL5CFG_RSVD_2                (2)                     /* bitfield lsb */
#define BFM_ADC_ADCSL5CFG_RSVD_2                ((uint32_t)0x000000fc)  /* bitfield mask */
#define BFN_ADC_ADCSL5CFG_RSVD_2                (6)                     /* bitfield width */
#define BFD_ADC_ADCSL5CFG_RSVD_2                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL5CFG_RSVD_2(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL5CFG_RSVD_2)) & (BFM_ADC_ADCSL5CFG_RSVD_2))
#define BFX_ADC_ADCSL5CFG_RSVD_2(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL5CFG_RSVD_2)) >> (BFP_ADC_ADCSL5CFG_RSVD_2))
#define BFW_ADC_ADCSL5CFG_RSVD_2(v)             (REG_ADC_ADCSL5CFG.U32 = ( (REG_ADC_ADCSL5CFG.U32 & ~(BFM_ADC_ADCSL5CFG_RSVD_2)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL5CFG_RSVD_2)) & (BFM_ADC_ADCSL5CFG_RSVD_2)) ))
#define BFR_ADC_ADCSL5CFG_RSVD_2()              ((REG_ADC_ADCSL5CFG.U32 & (BFM_ADC_ADCSL5CFG_RSVD_2))>>(BFP_ADC_ADCSL5CFG_RSVD_2))

#define BFP_ADC_ADCSL5CFG_WCEN5                 (1)                     /* bitfield lsb */
#define BFM_ADC_ADCSL5CFG_WCEN5                 ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_ADC_ADCSL5CFG_WCEN5                 (1)                     /* bitfield width */
#define BFD_ADC_ADCSL5CFG_WCEN5                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL5CFG_WCEN5(v)              ((((uint32_t) v) << (BFP_ADC_ADCSL5CFG_WCEN5)) & (BFM_ADC_ADCSL5CFG_WCEN5))
#define BFX_ADC_ADCSL5CFG_WCEN5(v)              ((((uint32_t) v) & (BFM_ADC_ADCSL5CFG_WCEN5)) >> (BFP_ADC_ADCSL5CFG_WCEN5))
#define BFW_ADC_ADCSL5CFG_WCEN5(v)              (REG_ADC_ADCSL5CFG.U32 = ( (REG_ADC_ADCSL5CFG.U32 & ~(BFM_ADC_ADCSL5CFG_WCEN5)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL5CFG_WCEN5)) & (BFM_ADC_ADCSL5CFG_WCEN5)) ))
#define BFR_ADC_ADCSL5CFG_WCEN5()               ((REG_ADC_ADCSL5CFG.U32 & (BFM_ADC_ADCSL5CFG_WCEN5))>>(BFP_ADC_ADCSL5CFG_WCEN5))

#define BFP_ADC_ADCSL5CFG_SLEN5                 (0)                     /* bitfield lsb */
#define BFM_ADC_ADCSL5CFG_SLEN5                 ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_ADC_ADCSL5CFG_SLEN5                 (1)                     /* bitfield width */
#define BFD_ADC_ADCSL5CFG_SLEN5                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL5CFG_SLEN5(v)              ((((uint32_t) v) << (BFP_ADC_ADCSL5CFG_SLEN5)) & (BFM_ADC_ADCSL5CFG_SLEN5))
#define BFX_ADC_ADCSL5CFG_SLEN5(v)              ((((uint32_t) v) & (BFM_ADC_ADCSL5CFG_SLEN5)) >> (BFP_ADC_ADCSL5CFG_SLEN5))
#define BFW_ADC_ADCSL5CFG_SLEN5(v)              (REG_ADC_ADCSL5CFG.U32 = ( (REG_ADC_ADCSL5CFG.U32 & ~(BFM_ADC_ADCSL5CFG_SLEN5)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL5CFG_SLEN5)) & (BFM_ADC_ADCSL5CFG_SLEN5)) ))
#define BFR_ADC_ADCSL5CFG_SLEN5()               ((REG_ADC_ADCSL5CFG.U32 & (BFM_ADC_ADCSL5CFG_SLEN5))>>(BFP_ADC_ADCSL5CFG_SLEN5))


// *****************************************************************************
//                                                                             *
//  ADC_ADCSL6CFG - Slot 6 Configuration Register                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_27                    :  5;
        unsigned ADSEL6                     :  3;
        unsigned RSVD_19                    :  5;
        unsigned THSEL6                     :  3;
        unsigned RSVD_12                    :  4;
        unsigned CHSEL6                     :  4;
        unsigned RSVD_2                     :  6;
        unsigned WCEN6                      :  1;
        unsigned SLEN6                      :  1;
    } B;
} reg_adc_adcsl6cfg_t;

#define REG_ADC_ADCSL6CFG_ADDR                  (REG_ADC_BASEADDR + 0x00000024UL)
#define REG_ADC_ADCSL6CFG                       (*(volatile reg_adc_adcsl6cfg_t *) REG_ADC_ADCSL6CFG_ADDR)
#define REG_ADC_ADCSL6CFG_RD()                  (REG_ADC_ADCSL6CFG.U32)
#define REG_ADC_ADCSL6CFG_WR(v)                 (REG_ADC_ADCSL6CFG.U32 = (v))
#define REG_ADC_ADCSL6CFG_CLR(m)                (REG_ADC_ADCSL6CFG.U32 = ((REG_ADC_ADCSL6CFG.U32) & ~(m)))
#define REG_ADC_ADCSL6CFG_SET(m)                (REG_ADC_ADCSL6CFG.U32 = ((REG_ADC_ADCSL6CFG.U32) | (m)))
#define REG_ADC_ADCSL6CFG_DEF                   0x00000000

#define BFP_ADC_ADCSL6CFG_RSVD_27               (27)                    /* bitfield lsb */
#define BFM_ADC_ADCSL6CFG_RSVD_27               ((uint32_t)0xf8000000)  /* bitfield mask */
#define BFN_ADC_ADCSL6CFG_RSVD_27               (5)                     /* bitfield width */
#define BFD_ADC_ADCSL6CFG_RSVD_27               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL6CFG_RSVD_27(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL6CFG_RSVD_27)) & (BFM_ADC_ADCSL6CFG_RSVD_27))
#define BFX_ADC_ADCSL6CFG_RSVD_27(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL6CFG_RSVD_27)) >> (BFP_ADC_ADCSL6CFG_RSVD_27))
#define BFW_ADC_ADCSL6CFG_RSVD_27(v)            (REG_ADC_ADCSL6CFG.U32 = ( (REG_ADC_ADCSL6CFG.U32 & ~(BFM_ADC_ADCSL6CFG_RSVD_27)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL6CFG_RSVD_27)) & (BFM_ADC_ADCSL6CFG_RSVD_27)) ))
#define BFR_ADC_ADCSL6CFG_RSVD_27()             ((REG_ADC_ADCSL6CFG.U32 & (BFM_ADC_ADCSL6CFG_RSVD_27))>>(BFP_ADC_ADCSL6CFG_RSVD_27))

#define BFP_ADC_ADCSL6CFG_ADSEL6                (24)                    /* bitfield lsb */
#define BFM_ADC_ADCSL6CFG_ADSEL6                ((uint32_t)0x07000000)  /* bitfield mask */
#define BFN_ADC_ADCSL6CFG_ADSEL6                (3)                     /* bitfield width */
#define BFD_ADC_ADCSL6CFG_ADSEL6                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL6CFG_ADSEL6(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL6CFG_ADSEL6)) & (BFM_ADC_ADCSL6CFG_ADSEL6))
#define BFX_ADC_ADCSL6CFG_ADSEL6(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL6CFG_ADSEL6)) >> (BFP_ADC_ADCSL6CFG_ADSEL6))
#define BFW_ADC_ADCSL6CFG_ADSEL6(v)             (REG_ADC_ADCSL6CFG.U32 = ( (REG_ADC_ADCSL6CFG.U32 & ~(BFM_ADC_ADCSL6CFG_ADSEL6)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL6CFG_ADSEL6)) & (BFM_ADC_ADCSL6CFG_ADSEL6)) ))
#define BFR_ADC_ADCSL6CFG_ADSEL6()              ((REG_ADC_ADCSL6CFG.U32 & (BFM_ADC_ADCSL6CFG_ADSEL6))>>(BFP_ADC_ADCSL6CFG_ADSEL6))

#define BFP_ADC_ADCSL6CFG_RSVD_19               (19)                    /* bitfield lsb */
#define BFM_ADC_ADCSL6CFG_RSVD_19               ((uint32_t)0x00f80000)  /* bitfield mask */
#define BFN_ADC_ADCSL6CFG_RSVD_19               (5)                     /* bitfield width */
#define BFD_ADC_ADCSL6CFG_RSVD_19               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL6CFG_RSVD_19(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL6CFG_RSVD_19)) & (BFM_ADC_ADCSL6CFG_RSVD_19))
#define BFX_ADC_ADCSL6CFG_RSVD_19(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL6CFG_RSVD_19)) >> (BFP_ADC_ADCSL6CFG_RSVD_19))
#define BFW_ADC_ADCSL6CFG_RSVD_19(v)            (REG_ADC_ADCSL6CFG.U32 = ( (REG_ADC_ADCSL6CFG.U32 & ~(BFM_ADC_ADCSL6CFG_RSVD_19)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL6CFG_RSVD_19)) & (BFM_ADC_ADCSL6CFG_RSVD_19)) ))
#define BFR_ADC_ADCSL6CFG_RSVD_19()             ((REG_ADC_ADCSL6CFG.U32 & (BFM_ADC_ADCSL6CFG_RSVD_19))>>(BFP_ADC_ADCSL6CFG_RSVD_19))

#define BFP_ADC_ADCSL6CFG_THSEL6                (16)                    /* bitfield lsb */
#define BFM_ADC_ADCSL6CFG_THSEL6                ((uint32_t)0x00070000)  /* bitfield mask */
#define BFN_ADC_ADCSL6CFG_THSEL6                (3)                     /* bitfield width */
#define BFD_ADC_ADCSL6CFG_THSEL6                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL6CFG_THSEL6(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL6CFG_THSEL6)) & (BFM_ADC_ADCSL6CFG_THSEL6))
#define BFX_ADC_ADCSL6CFG_THSEL6(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL6CFG_THSEL6)) >> (BFP_ADC_ADCSL6CFG_THSEL6))
#define BFW_ADC_ADCSL6CFG_THSEL6(v)             (REG_ADC_ADCSL6CFG.U32 = ( (REG_ADC_ADCSL6CFG.U32 & ~(BFM_ADC_ADCSL6CFG_THSEL6)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL6CFG_THSEL6)) & (BFM_ADC_ADCSL6CFG_THSEL6)) ))
#define BFR_ADC_ADCSL6CFG_THSEL6()              ((REG_ADC_ADCSL6CFG.U32 & (BFM_ADC_ADCSL6CFG_THSEL6))>>(BFP_ADC_ADCSL6CFG_THSEL6))

#define BFP_ADC_ADCSL6CFG_RSVD_12               (12)                    /* bitfield lsb */
#define BFM_ADC_ADCSL6CFG_RSVD_12               ((uint32_t)0x0000f000)  /* bitfield mask */
#define BFN_ADC_ADCSL6CFG_RSVD_12               (4)                     /* bitfield width */
#define BFD_ADC_ADCSL6CFG_RSVD_12               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL6CFG_RSVD_12(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL6CFG_RSVD_12)) & (BFM_ADC_ADCSL6CFG_RSVD_12))
#define BFX_ADC_ADCSL6CFG_RSVD_12(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL6CFG_RSVD_12)) >> (BFP_ADC_ADCSL6CFG_RSVD_12))
#define BFW_ADC_ADCSL6CFG_RSVD_12(v)            (REG_ADC_ADCSL6CFG.U32 = ( (REG_ADC_ADCSL6CFG.U32 & ~(BFM_ADC_ADCSL6CFG_RSVD_12)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL6CFG_RSVD_12)) & (BFM_ADC_ADCSL6CFG_RSVD_12)) ))
#define BFR_ADC_ADCSL6CFG_RSVD_12()             ((REG_ADC_ADCSL6CFG.U32 & (BFM_ADC_ADCSL6CFG_RSVD_12))>>(BFP_ADC_ADCSL6CFG_RSVD_12))

#define BFP_ADC_ADCSL6CFG_CHSEL6                (8)                     /* bitfield lsb */
#define BFM_ADC_ADCSL6CFG_CHSEL6                ((uint32_t)0x00000f00)  /* bitfield mask */
#define BFN_ADC_ADCSL6CFG_CHSEL6                (4)                     /* bitfield width */
#define BFD_ADC_ADCSL6CFG_CHSEL6                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL6CFG_CHSEL6(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL6CFG_CHSEL6)) & (BFM_ADC_ADCSL6CFG_CHSEL6))
#define BFX_ADC_ADCSL6CFG_CHSEL6(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL6CFG_CHSEL6)) >> (BFP_ADC_ADCSL6CFG_CHSEL6))
#define BFW_ADC_ADCSL6CFG_CHSEL6(v)             (REG_ADC_ADCSL6CFG.U32 = ( (REG_ADC_ADCSL6CFG.U32 & ~(BFM_ADC_ADCSL6CFG_CHSEL6)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL6CFG_CHSEL6)) & (BFM_ADC_ADCSL6CFG_CHSEL6)) ))
#define BFR_ADC_ADCSL6CFG_CHSEL6()              ((REG_ADC_ADCSL6CFG.U32 & (BFM_ADC_ADCSL6CFG_CHSEL6))>>(BFP_ADC_ADCSL6CFG_CHSEL6))

#define BFP_ADC_ADCSL6CFG_RSVD_2                (2)                     /* bitfield lsb */
#define BFM_ADC_ADCSL6CFG_RSVD_2                ((uint32_t)0x000000fc)  /* bitfield mask */
#define BFN_ADC_ADCSL6CFG_RSVD_2                (6)                     /* bitfield width */
#define BFD_ADC_ADCSL6CFG_RSVD_2                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL6CFG_RSVD_2(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL6CFG_RSVD_2)) & (BFM_ADC_ADCSL6CFG_RSVD_2))
#define BFX_ADC_ADCSL6CFG_RSVD_2(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL6CFG_RSVD_2)) >> (BFP_ADC_ADCSL6CFG_RSVD_2))
#define BFW_ADC_ADCSL6CFG_RSVD_2(v)             (REG_ADC_ADCSL6CFG.U32 = ( (REG_ADC_ADCSL6CFG.U32 & ~(BFM_ADC_ADCSL6CFG_RSVD_2)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL6CFG_RSVD_2)) & (BFM_ADC_ADCSL6CFG_RSVD_2)) ))
#define BFR_ADC_ADCSL6CFG_RSVD_2()              ((REG_ADC_ADCSL6CFG.U32 & (BFM_ADC_ADCSL6CFG_RSVD_2))>>(BFP_ADC_ADCSL6CFG_RSVD_2))

#define BFP_ADC_ADCSL6CFG_WCEN6                 (1)                     /* bitfield lsb */
#define BFM_ADC_ADCSL6CFG_WCEN6                 ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_ADC_ADCSL6CFG_WCEN6                 (1)                     /* bitfield width */
#define BFD_ADC_ADCSL6CFG_WCEN6                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL6CFG_WCEN6(v)              ((((uint32_t) v) << (BFP_ADC_ADCSL6CFG_WCEN6)) & (BFM_ADC_ADCSL6CFG_WCEN6))
#define BFX_ADC_ADCSL6CFG_WCEN6(v)              ((((uint32_t) v) & (BFM_ADC_ADCSL6CFG_WCEN6)) >> (BFP_ADC_ADCSL6CFG_WCEN6))
#define BFW_ADC_ADCSL6CFG_WCEN6(v)              (REG_ADC_ADCSL6CFG.U32 = ( (REG_ADC_ADCSL6CFG.U32 & ~(BFM_ADC_ADCSL6CFG_WCEN6)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL6CFG_WCEN6)) & (BFM_ADC_ADCSL6CFG_WCEN6)) ))
#define BFR_ADC_ADCSL6CFG_WCEN6()               ((REG_ADC_ADCSL6CFG.U32 & (BFM_ADC_ADCSL6CFG_WCEN6))>>(BFP_ADC_ADCSL6CFG_WCEN6))

#define BFP_ADC_ADCSL6CFG_SLEN6                 (0)                     /* bitfield lsb */
#define BFM_ADC_ADCSL6CFG_SLEN6                 ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_ADC_ADCSL6CFG_SLEN6                 (1)                     /* bitfield width */
#define BFD_ADC_ADCSL6CFG_SLEN6                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL6CFG_SLEN6(v)              ((((uint32_t) v) << (BFP_ADC_ADCSL6CFG_SLEN6)) & (BFM_ADC_ADCSL6CFG_SLEN6))
#define BFX_ADC_ADCSL6CFG_SLEN6(v)              ((((uint32_t) v) & (BFM_ADC_ADCSL6CFG_SLEN6)) >> (BFP_ADC_ADCSL6CFG_SLEN6))
#define BFW_ADC_ADCSL6CFG_SLEN6(v)              (REG_ADC_ADCSL6CFG.U32 = ( (REG_ADC_ADCSL6CFG.U32 & ~(BFM_ADC_ADCSL6CFG_SLEN6)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL6CFG_SLEN6)) & (BFM_ADC_ADCSL6CFG_SLEN6)) ))
#define BFR_ADC_ADCSL6CFG_SLEN6()               ((REG_ADC_ADCSL6CFG.U32 & (BFM_ADC_ADCSL6CFG_SLEN6))>>(BFP_ADC_ADCSL6CFG_SLEN6))


// *****************************************************************************
//                                                                             *
//  ADC_ADCSL7CFG - Slot 7 Configuration Register                              *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_27                    :  5;
        unsigned ADSEL7                     :  3;
        unsigned RSVD_19                    :  5;
        unsigned THSEL7                     :  3;
        unsigned RSVD_12                    :  4;
        unsigned CHSEL7                     :  4;
        unsigned RSVD_2                     :  6;
        unsigned WCEN7                      :  1;
        unsigned SLEN7                      :  1;
    } B;
} reg_adc_adcsl7cfg_t;

#define REG_ADC_ADCSL7CFG_ADDR                  (REG_ADC_BASEADDR + 0x00000028UL)
#define REG_ADC_ADCSL7CFG                       (*(volatile reg_adc_adcsl7cfg_t *) REG_ADC_ADCSL7CFG_ADDR)
#define REG_ADC_ADCSL7CFG_RD()                  (REG_ADC_ADCSL7CFG.U32)
#define REG_ADC_ADCSL7CFG_WR(v)                 (REG_ADC_ADCSL7CFG.U32 = (v))
#define REG_ADC_ADCSL7CFG_CLR(m)                (REG_ADC_ADCSL7CFG.U32 = ((REG_ADC_ADCSL7CFG.U32) & ~(m)))
#define REG_ADC_ADCSL7CFG_SET(m)                (REG_ADC_ADCSL7CFG.U32 = ((REG_ADC_ADCSL7CFG.U32) | (m)))
#define REG_ADC_ADCSL7CFG_DEF                   0x00000000

#define BFP_ADC_ADCSL7CFG_RSVD_27               (27)                    /* bitfield lsb */
#define BFM_ADC_ADCSL7CFG_RSVD_27               ((uint32_t)0xf8000000)  /* bitfield mask */
#define BFN_ADC_ADCSL7CFG_RSVD_27               (5)                     /* bitfield width */
#define BFD_ADC_ADCSL7CFG_RSVD_27               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL7CFG_RSVD_27(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL7CFG_RSVD_27)) & (BFM_ADC_ADCSL7CFG_RSVD_27))
#define BFX_ADC_ADCSL7CFG_RSVD_27(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL7CFG_RSVD_27)) >> (BFP_ADC_ADCSL7CFG_RSVD_27))
#define BFW_ADC_ADCSL7CFG_RSVD_27(v)            (REG_ADC_ADCSL7CFG.U32 = ( (REG_ADC_ADCSL7CFG.U32 & ~(BFM_ADC_ADCSL7CFG_RSVD_27)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL7CFG_RSVD_27)) & (BFM_ADC_ADCSL7CFG_RSVD_27)) ))
#define BFR_ADC_ADCSL7CFG_RSVD_27()             ((REG_ADC_ADCSL7CFG.U32 & (BFM_ADC_ADCSL7CFG_RSVD_27))>>(BFP_ADC_ADCSL7CFG_RSVD_27))

#define BFP_ADC_ADCSL7CFG_ADSEL7                (24)                    /* bitfield lsb */
#define BFM_ADC_ADCSL7CFG_ADSEL7                ((uint32_t)0x07000000)  /* bitfield mask */
#define BFN_ADC_ADCSL7CFG_ADSEL7                (3)                     /* bitfield width */
#define BFD_ADC_ADCSL7CFG_ADSEL7                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL7CFG_ADSEL7(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL7CFG_ADSEL7)) & (BFM_ADC_ADCSL7CFG_ADSEL7))
#define BFX_ADC_ADCSL7CFG_ADSEL7(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL7CFG_ADSEL7)) >> (BFP_ADC_ADCSL7CFG_ADSEL7))
#define BFW_ADC_ADCSL7CFG_ADSEL7(v)             (REG_ADC_ADCSL7CFG.U32 = ( (REG_ADC_ADCSL7CFG.U32 & ~(BFM_ADC_ADCSL7CFG_ADSEL7)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL7CFG_ADSEL7)) & (BFM_ADC_ADCSL7CFG_ADSEL7)) ))
#define BFR_ADC_ADCSL7CFG_ADSEL7()              ((REG_ADC_ADCSL7CFG.U32 & (BFM_ADC_ADCSL7CFG_ADSEL7))>>(BFP_ADC_ADCSL7CFG_ADSEL7))

#define BFP_ADC_ADCSL7CFG_RSVD_19               (19)                    /* bitfield lsb */
#define BFM_ADC_ADCSL7CFG_RSVD_19               ((uint32_t)0x00f80000)  /* bitfield mask */
#define BFN_ADC_ADCSL7CFG_RSVD_19               (5)                     /* bitfield width */
#define BFD_ADC_ADCSL7CFG_RSVD_19               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL7CFG_RSVD_19(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL7CFG_RSVD_19)) & (BFM_ADC_ADCSL7CFG_RSVD_19))
#define BFX_ADC_ADCSL7CFG_RSVD_19(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL7CFG_RSVD_19)) >> (BFP_ADC_ADCSL7CFG_RSVD_19))
#define BFW_ADC_ADCSL7CFG_RSVD_19(v)            (REG_ADC_ADCSL7CFG.U32 = ( (REG_ADC_ADCSL7CFG.U32 & ~(BFM_ADC_ADCSL7CFG_RSVD_19)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL7CFG_RSVD_19)) & (BFM_ADC_ADCSL7CFG_RSVD_19)) ))
#define BFR_ADC_ADCSL7CFG_RSVD_19()             ((REG_ADC_ADCSL7CFG.U32 & (BFM_ADC_ADCSL7CFG_RSVD_19))>>(BFP_ADC_ADCSL7CFG_RSVD_19))

#define BFP_ADC_ADCSL7CFG_THSEL7                (16)                    /* bitfield lsb */
#define BFM_ADC_ADCSL7CFG_THSEL7                ((uint32_t)0x00070000)  /* bitfield mask */
#define BFN_ADC_ADCSL7CFG_THSEL7                (3)                     /* bitfield width */
#define BFD_ADC_ADCSL7CFG_THSEL7                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL7CFG_THSEL7(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL7CFG_THSEL7)) & (BFM_ADC_ADCSL7CFG_THSEL7))
#define BFX_ADC_ADCSL7CFG_THSEL7(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL7CFG_THSEL7)) >> (BFP_ADC_ADCSL7CFG_THSEL7))
#define BFW_ADC_ADCSL7CFG_THSEL7(v)             (REG_ADC_ADCSL7CFG.U32 = ( (REG_ADC_ADCSL7CFG.U32 & ~(BFM_ADC_ADCSL7CFG_THSEL7)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL7CFG_THSEL7)) & (BFM_ADC_ADCSL7CFG_THSEL7)) ))
#define BFR_ADC_ADCSL7CFG_THSEL7()              ((REG_ADC_ADCSL7CFG.U32 & (BFM_ADC_ADCSL7CFG_THSEL7))>>(BFP_ADC_ADCSL7CFG_THSEL7))

#define BFP_ADC_ADCSL7CFG_RSVD_12               (12)                    /* bitfield lsb */
#define BFM_ADC_ADCSL7CFG_RSVD_12               ((uint32_t)0x0000f000)  /* bitfield mask */
#define BFN_ADC_ADCSL7CFG_RSVD_12               (4)                     /* bitfield width */
#define BFD_ADC_ADCSL7CFG_RSVD_12               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL7CFG_RSVD_12(v)            ((((uint32_t) v) << (BFP_ADC_ADCSL7CFG_RSVD_12)) & (BFM_ADC_ADCSL7CFG_RSVD_12))
#define BFX_ADC_ADCSL7CFG_RSVD_12(v)            ((((uint32_t) v) & (BFM_ADC_ADCSL7CFG_RSVD_12)) >> (BFP_ADC_ADCSL7CFG_RSVD_12))
#define BFW_ADC_ADCSL7CFG_RSVD_12(v)            (REG_ADC_ADCSL7CFG.U32 = ( (REG_ADC_ADCSL7CFG.U32 & ~(BFM_ADC_ADCSL7CFG_RSVD_12)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL7CFG_RSVD_12)) & (BFM_ADC_ADCSL7CFG_RSVD_12)) ))
#define BFR_ADC_ADCSL7CFG_RSVD_12()             ((REG_ADC_ADCSL7CFG.U32 & (BFM_ADC_ADCSL7CFG_RSVD_12))>>(BFP_ADC_ADCSL7CFG_RSVD_12))

#define BFP_ADC_ADCSL7CFG_CHSEL7                (8)                     /* bitfield lsb */
#define BFM_ADC_ADCSL7CFG_CHSEL7                ((uint32_t)0x00000f00)  /* bitfield mask */
#define BFN_ADC_ADCSL7CFG_CHSEL7                (4)                     /* bitfield width */
#define BFD_ADC_ADCSL7CFG_CHSEL7                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL7CFG_CHSEL7(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL7CFG_CHSEL7)) & (BFM_ADC_ADCSL7CFG_CHSEL7))
#define BFX_ADC_ADCSL7CFG_CHSEL7(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL7CFG_CHSEL7)) >> (BFP_ADC_ADCSL7CFG_CHSEL7))
#define BFW_ADC_ADCSL7CFG_CHSEL7(v)             (REG_ADC_ADCSL7CFG.U32 = ( (REG_ADC_ADCSL7CFG.U32 & ~(BFM_ADC_ADCSL7CFG_CHSEL7)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL7CFG_CHSEL7)) & (BFM_ADC_ADCSL7CFG_CHSEL7)) ))
#define BFR_ADC_ADCSL7CFG_CHSEL7()              ((REG_ADC_ADCSL7CFG.U32 & (BFM_ADC_ADCSL7CFG_CHSEL7))>>(BFP_ADC_ADCSL7CFG_CHSEL7))

#define BFP_ADC_ADCSL7CFG_RSVD_2                (2)                     /* bitfield lsb */
#define BFM_ADC_ADCSL7CFG_RSVD_2                ((uint32_t)0x000000fc)  /* bitfield mask */
#define BFN_ADC_ADCSL7CFG_RSVD_2                (6)                     /* bitfield width */
#define BFD_ADC_ADCSL7CFG_RSVD_2                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL7CFG_RSVD_2(v)             ((((uint32_t) v) << (BFP_ADC_ADCSL7CFG_RSVD_2)) & (BFM_ADC_ADCSL7CFG_RSVD_2))
#define BFX_ADC_ADCSL7CFG_RSVD_2(v)             ((((uint32_t) v) & (BFM_ADC_ADCSL7CFG_RSVD_2)) >> (BFP_ADC_ADCSL7CFG_RSVD_2))
#define BFW_ADC_ADCSL7CFG_RSVD_2(v)             (REG_ADC_ADCSL7CFG.U32 = ( (REG_ADC_ADCSL7CFG.U32 & ~(BFM_ADC_ADCSL7CFG_RSVD_2)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL7CFG_RSVD_2)) & (BFM_ADC_ADCSL7CFG_RSVD_2)) ))
#define BFR_ADC_ADCSL7CFG_RSVD_2()              ((REG_ADC_ADCSL7CFG.U32 & (BFM_ADC_ADCSL7CFG_RSVD_2))>>(BFP_ADC_ADCSL7CFG_RSVD_2))

#define BFP_ADC_ADCSL7CFG_WCEN7                 (1)                     /* bitfield lsb */
#define BFM_ADC_ADCSL7CFG_WCEN7                 ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_ADC_ADCSL7CFG_WCEN7                 (1)                     /* bitfield width */
#define BFD_ADC_ADCSL7CFG_WCEN7                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL7CFG_WCEN7(v)              ((((uint32_t) v) << (BFP_ADC_ADCSL7CFG_WCEN7)) & (BFM_ADC_ADCSL7CFG_WCEN7))
#define BFX_ADC_ADCSL7CFG_WCEN7(v)              ((((uint32_t) v) & (BFM_ADC_ADCSL7CFG_WCEN7)) >> (BFP_ADC_ADCSL7CFG_WCEN7))
#define BFW_ADC_ADCSL7CFG_WCEN7(v)              (REG_ADC_ADCSL7CFG.U32 = ( (REG_ADC_ADCSL7CFG.U32 & ~(BFM_ADC_ADCSL7CFG_WCEN7)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL7CFG_WCEN7)) & (BFM_ADC_ADCSL7CFG_WCEN7)) ))
#define BFR_ADC_ADCSL7CFG_WCEN7()               ((REG_ADC_ADCSL7CFG.U32 & (BFM_ADC_ADCSL7CFG_WCEN7))>>(BFP_ADC_ADCSL7CFG_WCEN7))

#define BFP_ADC_ADCSL7CFG_SLEN7                 (0)                     /* bitfield lsb */
#define BFM_ADC_ADCSL7CFG_SLEN7                 ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_ADC_ADCSL7CFG_SLEN7                 (1)                     /* bitfield width */
#define BFD_ADC_ADCSL7CFG_SLEN7                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCSL7CFG_SLEN7(v)              ((((uint32_t) v) << (BFP_ADC_ADCSL7CFG_SLEN7)) & (BFM_ADC_ADCSL7CFG_SLEN7))
#define BFX_ADC_ADCSL7CFG_SLEN7(v)              ((((uint32_t) v) & (BFM_ADC_ADCSL7CFG_SLEN7)) >> (BFP_ADC_ADCSL7CFG_SLEN7))
#define BFW_ADC_ADCSL7CFG_SLEN7(v)              (REG_ADC_ADCSL7CFG.U32 = ( (REG_ADC_ADCSL7CFG.U32 & ~(BFM_ADC_ADCSL7CFG_SLEN7)) | ((((uint32_t) v)<<(BFP_ADC_ADCSL7CFG_SLEN7)) & (BFM_ADC_ADCSL7CFG_SLEN7)) ))
#define BFR_ADC_ADCSL7CFG_SLEN7()               ((REG_ADC_ADCSL7CFG.U32 & (BFM_ADC_ADCSL7CFG_SLEN7))>>(BFP_ADC_ADCSL7CFG_SLEN7))


// *****************************************************************************
//                                                                             *
//  ADC_ADCWLIM - Window Comparator Limits Register                            *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned ULIM                       : 16;
        unsigned LLIM                       : 16;
    } B;
} reg_adc_adcwlim_t;

#define REG_ADC_ADCWLIM_ADDR                    (REG_ADC_BASEADDR + 0x0000002CUL)
#define REG_ADC_ADCWLIM                         (*(volatile reg_adc_adcwlim_t *) REG_ADC_ADCWLIM_ADDR)
#define REG_ADC_ADCWLIM_RD()                    (REG_ADC_ADCWLIM.U32)
#define REG_ADC_ADCWLIM_WR(v)                   (REG_ADC_ADCWLIM.U32 = (v))
#define REG_ADC_ADCWLIM_CLR(m)                  (REG_ADC_ADCWLIM.U32 = ((REG_ADC_ADCWLIM.U32) & ~(m)))
#define REG_ADC_ADCWLIM_SET(m)                  (REG_ADC_ADCWLIM.U32 = ((REG_ADC_ADCWLIM.U32) | (m)))
#define REG_ADC_ADCWLIM_DEF                     0x00000000

#define BFP_ADC_ADCWLIM_ULIM                    (16)                    /* bitfield lsb */
#define BFM_ADC_ADCWLIM_ULIM                    ((uint32_t)0xffff0000)  /* bitfield mask */
#define BFN_ADC_ADCWLIM_ULIM                    (16)                    /* bitfield width */
#define BFD_ADC_ADCWLIM_ULIM                    (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCWLIM_ULIM(v)                 ((((uint32_t) v) << (BFP_ADC_ADCWLIM_ULIM)) & (BFM_ADC_ADCWLIM_ULIM))
#define BFX_ADC_ADCWLIM_ULIM(v)                 ((((uint32_t) v) & (BFM_ADC_ADCWLIM_ULIM)) >> (BFP_ADC_ADCWLIM_ULIM))
#define BFW_ADC_ADCWLIM_ULIM(v)                 (REG_ADC_ADCWLIM.U32 = ( (REG_ADC_ADCWLIM.U32 & ~(BFM_ADC_ADCWLIM_ULIM)) | ((((uint32_t) v)<<(BFP_ADC_ADCWLIM_ULIM)) & (BFM_ADC_ADCWLIM_ULIM)) ))
#define BFR_ADC_ADCWLIM_ULIM()                  ((REG_ADC_ADCWLIM.U32 & (BFM_ADC_ADCWLIM_ULIM))>>(BFP_ADC_ADCWLIM_ULIM))

#define BFP_ADC_ADCWLIM_LLIM                    (0)                     /* bitfield lsb */
#define BFM_ADC_ADCWLIM_LLIM                    ((uint32_t)0x0000ffff)  /* bitfield mask */
#define BFN_ADC_ADCWLIM_LLIM                    (16)                    /* bitfield width */
#define BFD_ADC_ADCWLIM_LLIM                    (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCWLIM_LLIM(v)                 ((((uint32_t) v) << (BFP_ADC_ADCWLIM_LLIM)) & (BFM_ADC_ADCWLIM_LLIM))
#define BFX_ADC_ADCWLIM_LLIM(v)                 ((((uint32_t) v) & (BFM_ADC_ADCWLIM_LLIM)) >> (BFP_ADC_ADCWLIM_LLIM))
#define BFW_ADC_ADCWLIM_LLIM(v)                 (REG_ADC_ADCWLIM.U32 = ( (REG_ADC_ADCWLIM.U32 & ~(BFM_ADC_ADCWLIM_LLIM)) | ((((uint32_t) v)<<(BFP_ADC_ADCWLIM_LLIM)) & (BFM_ADC_ADCWLIM_LLIM)) ))
#define BFR_ADC_ADCWLIM_LLIM()                  ((REG_ADC_ADCWLIM.U32 & (BFM_ADC_ADCWLIM_LLIM))>>(BFP_ADC_ADCWLIM_LLIM))


// *****************************************************************************
//                                                                             *
//  ADC_ADCFIFO - Current FIFO Pointer                                         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_27                    :  5;
        unsigned SLOTNUM                    :  3;
        unsigned RSVD_20                    :  4;
        unsigned FIFOCNT                    :  4;
        unsigned FIFODATA                   : 16;
    } B;
} reg_adc_adcfifo_t;

#define REG_ADC_ADCFIFO_ADDR                    (REG_ADC_BASEADDR + 0x00000030UL)
#define REG_ADC_ADCFIFO                         (*(volatile reg_adc_adcfifo_t *) REG_ADC_ADCFIFO_ADDR)
#define REG_ADC_ADCFIFO_RD()                    (REG_ADC_ADCFIFO.U32)
#define REG_ADC_ADCFIFO_WR(v)                   (REG_ADC_ADCFIFO.U32 = (v))
#define REG_ADC_ADCFIFO_CLR(m)                  (REG_ADC_ADCFIFO.U32 = ((REG_ADC_ADCFIFO.U32) & ~(m)))
#define REG_ADC_ADCFIFO_SET(m)                  (REG_ADC_ADCFIFO.U32 = ((REG_ADC_ADCFIFO.U32) | (m)))
#define REG_ADC_ADCFIFO_DEF                     0x00000000

#define BFP_ADC_ADCFIFO_RSVD_27                 (27)                    /* bitfield lsb */
#define BFM_ADC_ADCFIFO_RSVD_27                 ((uint32_t)0xf8000000)  /* bitfield mask */
#define BFN_ADC_ADCFIFO_RSVD_27                 (5)                     /* bitfield width */
#define BFD_ADC_ADCFIFO_RSVD_27                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCFIFO_RSVD_27(v)              ((((uint32_t) v) << (BFP_ADC_ADCFIFO_RSVD_27)) & (BFM_ADC_ADCFIFO_RSVD_27))
#define BFX_ADC_ADCFIFO_RSVD_27(v)              ((((uint32_t) v) & (BFM_ADC_ADCFIFO_RSVD_27)) >> (BFP_ADC_ADCFIFO_RSVD_27))
#define BFW_ADC_ADCFIFO_RSVD_27(v)              (REG_ADC_ADCFIFO.U32 = ( (REG_ADC_ADCFIFO.U32 & ~(BFM_ADC_ADCFIFO_RSVD_27)) | ((((uint32_t) v)<<(BFP_ADC_ADCFIFO_RSVD_27)) & (BFM_ADC_ADCFIFO_RSVD_27)) ))
#define BFR_ADC_ADCFIFO_RSVD_27()               ((REG_ADC_ADCFIFO.U32 & (BFM_ADC_ADCFIFO_RSVD_27))>>(BFP_ADC_ADCFIFO_RSVD_27))

#define BFP_ADC_ADCFIFO_SLOTNUM                 (24)                    /* bitfield lsb */
#define BFM_ADC_ADCFIFO_SLOTNUM                 ((uint32_t)0x07000000)  /* bitfield mask */
#define BFN_ADC_ADCFIFO_SLOTNUM                 (3)                     /* bitfield width */
#define BFD_ADC_ADCFIFO_SLOTNUM                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCFIFO_SLOTNUM(v)              ((((uint32_t) v) << (BFP_ADC_ADCFIFO_SLOTNUM)) & (BFM_ADC_ADCFIFO_SLOTNUM))
#define BFX_ADC_ADCFIFO_SLOTNUM(v)              ((((uint32_t) v) & (BFM_ADC_ADCFIFO_SLOTNUM)) >> (BFP_ADC_ADCFIFO_SLOTNUM))
#define BFW_ADC_ADCFIFO_SLOTNUM(v)              (REG_ADC_ADCFIFO.U32 = ( (REG_ADC_ADCFIFO.U32 & ~(BFM_ADC_ADCFIFO_SLOTNUM)) | ((((uint32_t) v)<<(BFP_ADC_ADCFIFO_SLOTNUM)) & (BFM_ADC_ADCFIFO_SLOTNUM)) ))
#define BFR_ADC_ADCFIFO_SLOTNUM()               ((REG_ADC_ADCFIFO.U32 & (BFM_ADC_ADCFIFO_SLOTNUM))>>(BFP_ADC_ADCFIFO_SLOTNUM))

#define BFP_ADC_ADCFIFO_RSVD_20                 (20)                    /* bitfield lsb */
#define BFM_ADC_ADCFIFO_RSVD_20                 ((uint32_t)0x00f00000)  /* bitfield mask */
#define BFN_ADC_ADCFIFO_RSVD_20                 (4)                     /* bitfield width */
#define BFD_ADC_ADCFIFO_RSVD_20                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCFIFO_RSVD_20(v)              ((((uint32_t) v) << (BFP_ADC_ADCFIFO_RSVD_20)) & (BFM_ADC_ADCFIFO_RSVD_20))
#define BFX_ADC_ADCFIFO_RSVD_20(v)              ((((uint32_t) v) & (BFM_ADC_ADCFIFO_RSVD_20)) >> (BFP_ADC_ADCFIFO_RSVD_20))
#define BFW_ADC_ADCFIFO_RSVD_20(v)              (REG_ADC_ADCFIFO.U32 = ( (REG_ADC_ADCFIFO.U32 & ~(BFM_ADC_ADCFIFO_RSVD_20)) | ((((uint32_t) v)<<(BFP_ADC_ADCFIFO_RSVD_20)) & (BFM_ADC_ADCFIFO_RSVD_20)) ))
#define BFR_ADC_ADCFIFO_RSVD_20()               ((REG_ADC_ADCFIFO.U32 & (BFM_ADC_ADCFIFO_RSVD_20))>>(BFP_ADC_ADCFIFO_RSVD_20))

#define BFP_ADC_ADCFIFO_FIFOCNT                 (16)                    /* bitfield lsb */
#define BFM_ADC_ADCFIFO_FIFOCNT                 ((uint32_t)0x000f0000)  /* bitfield mask */
#define BFN_ADC_ADCFIFO_FIFOCNT                 (4)                     /* bitfield width */
#define BFD_ADC_ADCFIFO_FIFOCNT                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCFIFO_FIFOCNT(v)              ((((uint32_t) v) << (BFP_ADC_ADCFIFO_FIFOCNT)) & (BFM_ADC_ADCFIFO_FIFOCNT))
#define BFX_ADC_ADCFIFO_FIFOCNT(v)              ((((uint32_t) v) & (BFM_ADC_ADCFIFO_FIFOCNT)) >> (BFP_ADC_ADCFIFO_FIFOCNT))
#define BFW_ADC_ADCFIFO_FIFOCNT(v)              (REG_ADC_ADCFIFO.U32 = ( (REG_ADC_ADCFIFO.U32 & ~(BFM_ADC_ADCFIFO_FIFOCNT)) | ((((uint32_t) v)<<(BFP_ADC_ADCFIFO_FIFOCNT)) & (BFM_ADC_ADCFIFO_FIFOCNT)) ))
#define BFR_ADC_ADCFIFO_FIFOCNT()               ((REG_ADC_ADCFIFO.U32 & (BFM_ADC_ADCFIFO_FIFOCNT))>>(BFP_ADC_ADCFIFO_FIFOCNT))

#define BFP_ADC_ADCFIFO_FIFODATA                (0)                     /* bitfield lsb */
#define BFM_ADC_ADCFIFO_FIFODATA                ((uint32_t)0x0000ffff)  /* bitfield mask */
#define BFN_ADC_ADCFIFO_FIFODATA                (16)                    /* bitfield width */
#define BFD_ADC_ADCFIFO_FIFODATA                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADCFIFO_FIFODATA(v)             ((((uint32_t) v) << (BFP_ADC_ADCFIFO_FIFODATA)) & (BFM_ADC_ADCFIFO_FIFODATA))
#define BFX_ADC_ADCFIFO_FIFODATA(v)             ((((uint32_t) v) & (BFM_ADC_ADCFIFO_FIFODATA)) >> (BFP_ADC_ADCFIFO_FIFODATA))
#define BFW_ADC_ADCFIFO_FIFODATA(v)             (REG_ADC_ADCFIFO.U32 = ( (REG_ADC_ADCFIFO.U32 & ~(BFM_ADC_ADCFIFO_FIFODATA)) | ((((uint32_t) v)<<(BFP_ADC_ADCFIFO_FIFODATA)) & (BFM_ADC_ADCFIFO_FIFODATA)) ))
#define BFR_ADC_ADCFIFO_FIFODATA()              ((REG_ADC_ADCFIFO.U32 & (BFM_ADC_ADCFIFO_FIFODATA))>>(BFP_ADC_ADCFIFO_FIFODATA))


// *****************************************************************************
//                                                                             *
//  ADC_ADC_IEREN - ADC Interrupt registers                                    *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_6                     : 26;
        unsigned WCINC                      :  1;
        unsigned WCEXC                      :  1;
        unsigned FIFOOVR2                   :  1;
        unsigned FIFOOVR1                   :  1;
        unsigned SCNCMP                     :  1;
        unsigned CNVCMP                     :  1;
    } B;
} reg_adc_adc_ieren_t;

#define REG_ADC_ADC_IEREN_ADDR                  (REG_ADC_BASEADDR + 0x00000200UL)
#define REG_ADC_ADC_IEREN                       (*(volatile reg_adc_adc_ieren_t *) REG_ADC_ADC_IEREN_ADDR)
#define REG_ADC_ADC_IEREN_RD()                  (REG_ADC_ADC_IEREN.U32)
#define REG_ADC_ADC_IEREN_WR(v)                 (REG_ADC_ADC_IEREN.U32 = (v))
#define REG_ADC_ADC_IEREN_CLR(m)                (REG_ADC_ADC_IEREN.U32 = ((REG_ADC_ADC_IEREN.U32) & ~(m)))
#define REG_ADC_ADC_IEREN_SET(m)                (REG_ADC_ADC_IEREN.U32 = ((REG_ADC_ADC_IEREN.U32) | (m)))
#define REG_ADC_ADC_IEREN_DEF                   0x00000000

#define BFP_ADC_ADC_IEREN_RSVD_6                (6)                     /* bitfield lsb */
#define BFM_ADC_ADC_IEREN_RSVD_6                ((uint32_t)0xffffffc0)  /* bitfield mask */
#define BFN_ADC_ADC_IEREN_RSVD_6                (26)                    /* bitfield width */
#define BFD_ADC_ADC_IEREN_RSVD_6                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IEREN_RSVD_6(v)             ((((uint32_t) v) << (BFP_ADC_ADC_IEREN_RSVD_6)) & (BFM_ADC_ADC_IEREN_RSVD_6))
#define BFX_ADC_ADC_IEREN_RSVD_6(v)             ((((uint32_t) v) & (BFM_ADC_ADC_IEREN_RSVD_6)) >> (BFP_ADC_ADC_IEREN_RSVD_6))
#define BFW_ADC_ADC_IEREN_RSVD_6(v)             (REG_ADC_ADC_IEREN.U32 = ( (REG_ADC_ADC_IEREN.U32 & ~(BFM_ADC_ADC_IEREN_RSVD_6)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IEREN_RSVD_6)) & (BFM_ADC_ADC_IEREN_RSVD_6)) ))
#define BFR_ADC_ADC_IEREN_RSVD_6()              ((REG_ADC_ADC_IEREN.U32 & (BFM_ADC_ADC_IEREN_RSVD_6))>>(BFP_ADC_ADC_IEREN_RSVD_6))

#define BFP_ADC_ADC_IEREN_WCINC                 (5)                     /* bitfield lsb */
#define BFM_ADC_ADC_IEREN_WCINC                 ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_ADC_ADC_IEREN_WCINC                 (1)                     /* bitfield width */
#define BFD_ADC_ADC_IEREN_WCINC                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IEREN_WCINC(v)              ((((uint32_t) v) << (BFP_ADC_ADC_IEREN_WCINC)) & (BFM_ADC_ADC_IEREN_WCINC))
#define BFX_ADC_ADC_IEREN_WCINC(v)              ((((uint32_t) v) & (BFM_ADC_ADC_IEREN_WCINC)) >> (BFP_ADC_ADC_IEREN_WCINC))
#define BFW_ADC_ADC_IEREN_WCINC(v)              (REG_ADC_ADC_IEREN.U32 = ( (REG_ADC_ADC_IEREN.U32 & ~(BFM_ADC_ADC_IEREN_WCINC)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IEREN_WCINC)) & (BFM_ADC_ADC_IEREN_WCINC)) ))
#define BFR_ADC_ADC_IEREN_WCINC()               ((REG_ADC_ADC_IEREN.U32 & (BFM_ADC_ADC_IEREN_WCINC))>>(BFP_ADC_ADC_IEREN_WCINC))

#define BFP_ADC_ADC_IEREN_WCEXC                 (4)                     /* bitfield lsb */
#define BFM_ADC_ADC_IEREN_WCEXC                 ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_ADC_ADC_IEREN_WCEXC                 (1)                     /* bitfield width */
#define BFD_ADC_ADC_IEREN_WCEXC                 (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IEREN_WCEXC(v)              ((((uint32_t) v) << (BFP_ADC_ADC_IEREN_WCEXC)) & (BFM_ADC_ADC_IEREN_WCEXC))
#define BFX_ADC_ADC_IEREN_WCEXC(v)              ((((uint32_t) v) & (BFM_ADC_ADC_IEREN_WCEXC)) >> (BFP_ADC_ADC_IEREN_WCEXC))
#define BFW_ADC_ADC_IEREN_WCEXC(v)              (REG_ADC_ADC_IEREN.U32 = ( (REG_ADC_ADC_IEREN.U32 & ~(BFM_ADC_ADC_IEREN_WCEXC)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IEREN_WCEXC)) & (BFM_ADC_ADC_IEREN_WCEXC)) ))
#define BFR_ADC_ADC_IEREN_WCEXC()               ((REG_ADC_ADC_IEREN.U32 & (BFM_ADC_ADC_IEREN_WCEXC))>>(BFP_ADC_ADC_IEREN_WCEXC))

#define BFP_ADC_ADC_IEREN_FIFOOVR2              (3)                     /* bitfield lsb */
#define BFM_ADC_ADC_IEREN_FIFOOVR2              ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_ADC_ADC_IEREN_FIFOOVR2              (1)                     /* bitfield width */
#define BFD_ADC_ADC_IEREN_FIFOOVR2              (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IEREN_FIFOOVR2(v)           ((((uint32_t) v) << (BFP_ADC_ADC_IEREN_FIFOOVR2)) & (BFM_ADC_ADC_IEREN_FIFOOVR2))
#define BFX_ADC_ADC_IEREN_FIFOOVR2(v)           ((((uint32_t) v) & (BFM_ADC_ADC_IEREN_FIFOOVR2)) >> (BFP_ADC_ADC_IEREN_FIFOOVR2))
#define BFW_ADC_ADC_IEREN_FIFOOVR2(v)           (REG_ADC_ADC_IEREN.U32 = ( (REG_ADC_ADC_IEREN.U32 & ~(BFM_ADC_ADC_IEREN_FIFOOVR2)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IEREN_FIFOOVR2)) & (BFM_ADC_ADC_IEREN_FIFOOVR2)) ))
#define BFR_ADC_ADC_IEREN_FIFOOVR2()            ((REG_ADC_ADC_IEREN.U32 & (BFM_ADC_ADC_IEREN_FIFOOVR2))>>(BFP_ADC_ADC_IEREN_FIFOOVR2))

#define BFP_ADC_ADC_IEREN_FIFOOVR1              (2)                     /* bitfield lsb */
#define BFM_ADC_ADC_IEREN_FIFOOVR1              ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_ADC_ADC_IEREN_FIFOOVR1              (1)                     /* bitfield width */
#define BFD_ADC_ADC_IEREN_FIFOOVR1              (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IEREN_FIFOOVR1(v)           ((((uint32_t) v) << (BFP_ADC_ADC_IEREN_FIFOOVR1)) & (BFM_ADC_ADC_IEREN_FIFOOVR1))
#define BFX_ADC_ADC_IEREN_FIFOOVR1(v)           ((((uint32_t) v) & (BFM_ADC_ADC_IEREN_FIFOOVR1)) >> (BFP_ADC_ADC_IEREN_FIFOOVR1))
#define BFW_ADC_ADC_IEREN_FIFOOVR1(v)           (REG_ADC_ADC_IEREN.U32 = ( (REG_ADC_ADC_IEREN.U32 & ~(BFM_ADC_ADC_IEREN_FIFOOVR1)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IEREN_FIFOOVR1)) & (BFM_ADC_ADC_IEREN_FIFOOVR1)) ))
#define BFR_ADC_ADC_IEREN_FIFOOVR1()            ((REG_ADC_ADC_IEREN.U32 & (BFM_ADC_ADC_IEREN_FIFOOVR1))>>(BFP_ADC_ADC_IEREN_FIFOOVR1))

#define BFP_ADC_ADC_IEREN_SCNCMP                (1)                     /* bitfield lsb */
#define BFM_ADC_ADC_IEREN_SCNCMP                ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_ADC_ADC_IEREN_SCNCMP                (1)                     /* bitfield width */
#define BFD_ADC_ADC_IEREN_SCNCMP                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IEREN_SCNCMP(v)             ((((uint32_t) v) << (BFP_ADC_ADC_IEREN_SCNCMP)) & (BFM_ADC_ADC_IEREN_SCNCMP))
#define BFX_ADC_ADC_IEREN_SCNCMP(v)             ((((uint32_t) v) & (BFM_ADC_ADC_IEREN_SCNCMP)) >> (BFP_ADC_ADC_IEREN_SCNCMP))
#define BFW_ADC_ADC_IEREN_SCNCMP(v)             (REG_ADC_ADC_IEREN.U32 = ( (REG_ADC_ADC_IEREN.U32 & ~(BFM_ADC_ADC_IEREN_SCNCMP)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IEREN_SCNCMP)) & (BFM_ADC_ADC_IEREN_SCNCMP)) ))
#define BFR_ADC_ADC_IEREN_SCNCMP()              ((REG_ADC_ADC_IEREN.U32 & (BFM_ADC_ADC_IEREN_SCNCMP))>>(BFP_ADC_ADC_IEREN_SCNCMP))

#define BFP_ADC_ADC_IEREN_CNVCMP                (0)                     /* bitfield lsb */
#define BFM_ADC_ADC_IEREN_CNVCMP                ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_ADC_ADC_IEREN_CNVCMP                (1)                     /* bitfield width */
#define BFD_ADC_ADC_IEREN_CNVCMP                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IEREN_CNVCMP(v)             ((((uint32_t) v) << (BFP_ADC_ADC_IEREN_CNVCMP)) & (BFM_ADC_ADC_IEREN_CNVCMP))
#define BFX_ADC_ADC_IEREN_CNVCMP(v)             ((((uint32_t) v) & (BFM_ADC_ADC_IEREN_CNVCMP)) >> (BFP_ADC_ADC_IEREN_CNVCMP))
#define BFW_ADC_ADC_IEREN_CNVCMP(v)             (REG_ADC_ADC_IEREN.U32 = ( (REG_ADC_ADC_IEREN.U32 & ~(BFM_ADC_ADC_IEREN_CNVCMP)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IEREN_CNVCMP)) & (BFM_ADC_ADC_IEREN_CNVCMP)) ))
#define BFR_ADC_ADC_IEREN_CNVCMP()              ((REG_ADC_ADC_IEREN.U32 & (BFM_ADC_ADC_IEREN_CNVCMP))>>(BFP_ADC_ADC_IEREN_CNVCMP))


// *****************************************************************************
//                                                                             *
//  ADC_ADC_IERSTAT - ADC Interrupt registers                                  *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_6                     : 26;
        unsigned WCINC                      :  1;
        unsigned WCEXC                      :  1;
        unsigned FIFOOVR2                   :  1;
        unsigned FIFOOVR1                   :  1;
        unsigned SCNCMP                     :  1;
        unsigned CNVCMP                     :  1;
    } B;
} reg_adc_adc_ierstat_t;

#define REG_ADC_ADC_IERSTAT_ADDR                (REG_ADC_BASEADDR + 0x00000204UL)
#define REG_ADC_ADC_IERSTAT                     (*(volatile reg_adc_adc_ierstat_t *) REG_ADC_ADC_IERSTAT_ADDR)
#define REG_ADC_ADC_IERSTAT_RD()                (REG_ADC_ADC_IERSTAT.U32)
#define REG_ADC_ADC_IERSTAT_WR(v)               (REG_ADC_ADC_IERSTAT.U32 = (v))
#define REG_ADC_ADC_IERSTAT_CLR(m)              (REG_ADC_ADC_IERSTAT.U32 = ((REG_ADC_ADC_IERSTAT.U32) & ~(m)))
#define REG_ADC_ADC_IERSTAT_SET(m)              (REG_ADC_ADC_IERSTAT.U32 = ((REG_ADC_ADC_IERSTAT.U32) | (m)))
#define REG_ADC_ADC_IERSTAT_DEF                 0x00000000

#define BFP_ADC_ADC_IERSTAT_RSVD_6              (6)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERSTAT_RSVD_6              ((uint32_t)0xffffffc0)  /* bitfield mask */
#define BFN_ADC_ADC_IERSTAT_RSVD_6              (26)                    /* bitfield width */
#define BFD_ADC_ADC_IERSTAT_RSVD_6              (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERSTAT_RSVD_6(v)           ((((uint32_t) v) << (BFP_ADC_ADC_IERSTAT_RSVD_6)) & (BFM_ADC_ADC_IERSTAT_RSVD_6))
#define BFX_ADC_ADC_IERSTAT_RSVD_6(v)           ((((uint32_t) v) & (BFM_ADC_ADC_IERSTAT_RSVD_6)) >> (BFP_ADC_ADC_IERSTAT_RSVD_6))
#define BFW_ADC_ADC_IERSTAT_RSVD_6(v)           (REG_ADC_ADC_IERSTAT.U32 = ( (REG_ADC_ADC_IERSTAT.U32 & ~(BFM_ADC_ADC_IERSTAT_RSVD_6)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERSTAT_RSVD_6)) & (BFM_ADC_ADC_IERSTAT_RSVD_6)) ))
#define BFR_ADC_ADC_IERSTAT_RSVD_6()            ((REG_ADC_ADC_IERSTAT.U32 & (BFM_ADC_ADC_IERSTAT_RSVD_6))>>(BFP_ADC_ADC_IERSTAT_RSVD_6))

#define BFP_ADC_ADC_IERSTAT_WCINC               (5)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERSTAT_WCINC               ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_ADC_ADC_IERSTAT_WCINC               (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERSTAT_WCINC               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERSTAT_WCINC(v)            ((((uint32_t) v) << (BFP_ADC_ADC_IERSTAT_WCINC)) & (BFM_ADC_ADC_IERSTAT_WCINC))
#define BFX_ADC_ADC_IERSTAT_WCINC(v)            ((((uint32_t) v) & (BFM_ADC_ADC_IERSTAT_WCINC)) >> (BFP_ADC_ADC_IERSTAT_WCINC))
#define BFW_ADC_ADC_IERSTAT_WCINC(v)            (REG_ADC_ADC_IERSTAT.U32 = ( (REG_ADC_ADC_IERSTAT.U32 & ~(BFM_ADC_ADC_IERSTAT_WCINC)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERSTAT_WCINC)) & (BFM_ADC_ADC_IERSTAT_WCINC)) ))
#define BFR_ADC_ADC_IERSTAT_WCINC()             ((REG_ADC_ADC_IERSTAT.U32 & (BFM_ADC_ADC_IERSTAT_WCINC))>>(BFP_ADC_ADC_IERSTAT_WCINC))

#define BFP_ADC_ADC_IERSTAT_WCEXC               (4)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERSTAT_WCEXC               ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_ADC_ADC_IERSTAT_WCEXC               (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERSTAT_WCEXC               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERSTAT_WCEXC(v)            ((((uint32_t) v) << (BFP_ADC_ADC_IERSTAT_WCEXC)) & (BFM_ADC_ADC_IERSTAT_WCEXC))
#define BFX_ADC_ADC_IERSTAT_WCEXC(v)            ((((uint32_t) v) & (BFM_ADC_ADC_IERSTAT_WCEXC)) >> (BFP_ADC_ADC_IERSTAT_WCEXC))
#define BFW_ADC_ADC_IERSTAT_WCEXC(v)            (REG_ADC_ADC_IERSTAT.U32 = ( (REG_ADC_ADC_IERSTAT.U32 & ~(BFM_ADC_ADC_IERSTAT_WCEXC)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERSTAT_WCEXC)) & (BFM_ADC_ADC_IERSTAT_WCEXC)) ))
#define BFR_ADC_ADC_IERSTAT_WCEXC()             ((REG_ADC_ADC_IERSTAT.U32 & (BFM_ADC_ADC_IERSTAT_WCEXC))>>(BFP_ADC_ADC_IERSTAT_WCEXC))

#define BFP_ADC_ADC_IERSTAT_FIFOOVR2            (3)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERSTAT_FIFOOVR2            ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_ADC_ADC_IERSTAT_FIFOOVR2            (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERSTAT_FIFOOVR2            (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERSTAT_FIFOOVR2(v)         ((((uint32_t) v) << (BFP_ADC_ADC_IERSTAT_FIFOOVR2)) & (BFM_ADC_ADC_IERSTAT_FIFOOVR2))
#define BFX_ADC_ADC_IERSTAT_FIFOOVR2(v)         ((((uint32_t) v) & (BFM_ADC_ADC_IERSTAT_FIFOOVR2)) >> (BFP_ADC_ADC_IERSTAT_FIFOOVR2))
#define BFW_ADC_ADC_IERSTAT_FIFOOVR2(v)         (REG_ADC_ADC_IERSTAT.U32 = ( (REG_ADC_ADC_IERSTAT.U32 & ~(BFM_ADC_ADC_IERSTAT_FIFOOVR2)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERSTAT_FIFOOVR2)) & (BFM_ADC_ADC_IERSTAT_FIFOOVR2)) ))
#define BFR_ADC_ADC_IERSTAT_FIFOOVR2()          ((REG_ADC_ADC_IERSTAT.U32 & (BFM_ADC_ADC_IERSTAT_FIFOOVR2))>>(BFP_ADC_ADC_IERSTAT_FIFOOVR2))

#define BFP_ADC_ADC_IERSTAT_FIFOOVR1            (2)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERSTAT_FIFOOVR1            ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_ADC_ADC_IERSTAT_FIFOOVR1            (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERSTAT_FIFOOVR1            (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERSTAT_FIFOOVR1(v)         ((((uint32_t) v) << (BFP_ADC_ADC_IERSTAT_FIFOOVR1)) & (BFM_ADC_ADC_IERSTAT_FIFOOVR1))
#define BFX_ADC_ADC_IERSTAT_FIFOOVR1(v)         ((((uint32_t) v) & (BFM_ADC_ADC_IERSTAT_FIFOOVR1)) >> (BFP_ADC_ADC_IERSTAT_FIFOOVR1))
#define BFW_ADC_ADC_IERSTAT_FIFOOVR1(v)         (REG_ADC_ADC_IERSTAT.U32 = ( (REG_ADC_ADC_IERSTAT.U32 & ~(BFM_ADC_ADC_IERSTAT_FIFOOVR1)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERSTAT_FIFOOVR1)) & (BFM_ADC_ADC_IERSTAT_FIFOOVR1)) ))
#define BFR_ADC_ADC_IERSTAT_FIFOOVR1()          ((REG_ADC_ADC_IERSTAT.U32 & (BFM_ADC_ADC_IERSTAT_FIFOOVR1))>>(BFP_ADC_ADC_IERSTAT_FIFOOVR1))

#define BFP_ADC_ADC_IERSTAT_SCNCMP              (1)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERSTAT_SCNCMP              ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_ADC_ADC_IERSTAT_SCNCMP              (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERSTAT_SCNCMP              (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERSTAT_SCNCMP(v)           ((((uint32_t) v) << (BFP_ADC_ADC_IERSTAT_SCNCMP)) & (BFM_ADC_ADC_IERSTAT_SCNCMP))
#define BFX_ADC_ADC_IERSTAT_SCNCMP(v)           ((((uint32_t) v) & (BFM_ADC_ADC_IERSTAT_SCNCMP)) >> (BFP_ADC_ADC_IERSTAT_SCNCMP))
#define BFW_ADC_ADC_IERSTAT_SCNCMP(v)           (REG_ADC_ADC_IERSTAT.U32 = ( (REG_ADC_ADC_IERSTAT.U32 & ~(BFM_ADC_ADC_IERSTAT_SCNCMP)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERSTAT_SCNCMP)) & (BFM_ADC_ADC_IERSTAT_SCNCMP)) ))
#define BFR_ADC_ADC_IERSTAT_SCNCMP()            ((REG_ADC_ADC_IERSTAT.U32 & (BFM_ADC_ADC_IERSTAT_SCNCMP))>>(BFP_ADC_ADC_IERSTAT_SCNCMP))

#define BFP_ADC_ADC_IERSTAT_CNVCMP              (0)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERSTAT_CNVCMP              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_ADC_ADC_IERSTAT_CNVCMP              (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERSTAT_CNVCMP              (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERSTAT_CNVCMP(v)           ((((uint32_t) v) << (BFP_ADC_ADC_IERSTAT_CNVCMP)) & (BFM_ADC_ADC_IERSTAT_CNVCMP))
#define BFX_ADC_ADC_IERSTAT_CNVCMP(v)           ((((uint32_t) v) & (BFM_ADC_ADC_IERSTAT_CNVCMP)) >> (BFP_ADC_ADC_IERSTAT_CNVCMP))
#define BFW_ADC_ADC_IERSTAT_CNVCMP(v)           (REG_ADC_ADC_IERSTAT.U32 = ( (REG_ADC_ADC_IERSTAT.U32 & ~(BFM_ADC_ADC_IERSTAT_CNVCMP)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERSTAT_CNVCMP)) & (BFM_ADC_ADC_IERSTAT_CNVCMP)) ))
#define BFR_ADC_ADC_IERSTAT_CNVCMP()            ((REG_ADC_ADC_IERSTAT.U32 & (BFM_ADC_ADC_IERSTAT_CNVCMP))>>(BFP_ADC_ADC_IERSTAT_CNVCMP))


// *****************************************************************************
//                                                                             *
//  ADC_ADC_IERCLR - ADC Interrupt registers                                   *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_6                     : 26;
        unsigned WCINC                      :  1;
        unsigned WCEXC                      :  1;
        unsigned FIFOOVR2                   :  1;
        unsigned FIFOOVR1                   :  1;
        unsigned SCNCMP                     :  1;
        unsigned CNVCMP                     :  1;
    } B;
} reg_adc_adc_ierclr_t;

#define REG_ADC_ADC_IERCLR_ADDR                 (REG_ADC_BASEADDR + 0x00000208UL)
#define REG_ADC_ADC_IERCLR                      (*(volatile reg_adc_adc_ierclr_t *) REG_ADC_ADC_IERCLR_ADDR)
#define REG_ADC_ADC_IERCLR_RD()                 (REG_ADC_ADC_IERCLR.U32)
#define REG_ADC_ADC_IERCLR_WR(v)                (REG_ADC_ADC_IERCLR.U32 = (v))
#define REG_ADC_ADC_IERCLR_CLR(m)               (REG_ADC_ADC_IERCLR.U32 = ((REG_ADC_ADC_IERCLR.U32) & ~(m)))
#define REG_ADC_ADC_IERCLR_SET(m)               (REG_ADC_ADC_IERCLR.U32 = ((REG_ADC_ADC_IERCLR.U32) | (m)))
#define REG_ADC_ADC_IERCLR_DEF                  0x00000000

#define BFP_ADC_ADC_IERCLR_RSVD_6               (6)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERCLR_RSVD_6               ((uint32_t)0xffffffc0)  /* bitfield mask */
#define BFN_ADC_ADC_IERCLR_RSVD_6               (26)                    /* bitfield width */
#define BFD_ADC_ADC_IERCLR_RSVD_6               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERCLR_RSVD_6(v)            ((((uint32_t) v) << (BFP_ADC_ADC_IERCLR_RSVD_6)) & (BFM_ADC_ADC_IERCLR_RSVD_6))
#define BFX_ADC_ADC_IERCLR_RSVD_6(v)            ((((uint32_t) v) & (BFM_ADC_ADC_IERCLR_RSVD_6)) >> (BFP_ADC_ADC_IERCLR_RSVD_6))
#define BFW_ADC_ADC_IERCLR_RSVD_6(v)            (REG_ADC_ADC_IERCLR.U32 = ( (REG_ADC_ADC_IERCLR.U32 & ~(BFM_ADC_ADC_IERCLR_RSVD_6)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERCLR_RSVD_6)) & (BFM_ADC_ADC_IERCLR_RSVD_6)) ))
#define BFR_ADC_ADC_IERCLR_RSVD_6()             ((REG_ADC_ADC_IERCLR.U32 & (BFM_ADC_ADC_IERCLR_RSVD_6))>>(BFP_ADC_ADC_IERCLR_RSVD_6))

#define BFP_ADC_ADC_IERCLR_WCINC                (5)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERCLR_WCINC                ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_ADC_ADC_IERCLR_WCINC                (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERCLR_WCINC                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERCLR_WCINC(v)             ((((uint32_t) v) << (BFP_ADC_ADC_IERCLR_WCINC)) & (BFM_ADC_ADC_IERCLR_WCINC))
#define BFX_ADC_ADC_IERCLR_WCINC(v)             ((((uint32_t) v) & (BFM_ADC_ADC_IERCLR_WCINC)) >> (BFP_ADC_ADC_IERCLR_WCINC))
#define BFW_ADC_ADC_IERCLR_WCINC(v)             (REG_ADC_ADC_IERCLR.U32 = ( (REG_ADC_ADC_IERCLR.U32 & ~(BFM_ADC_ADC_IERCLR_WCINC)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERCLR_WCINC)) & (BFM_ADC_ADC_IERCLR_WCINC)) ))
#define BFR_ADC_ADC_IERCLR_WCINC()              ((REG_ADC_ADC_IERCLR.U32 & (BFM_ADC_ADC_IERCLR_WCINC))>>(BFP_ADC_ADC_IERCLR_WCINC))

#define BFP_ADC_ADC_IERCLR_WCEXC                (4)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERCLR_WCEXC                ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_ADC_ADC_IERCLR_WCEXC                (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERCLR_WCEXC                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERCLR_WCEXC(v)             ((((uint32_t) v) << (BFP_ADC_ADC_IERCLR_WCEXC)) & (BFM_ADC_ADC_IERCLR_WCEXC))
#define BFX_ADC_ADC_IERCLR_WCEXC(v)             ((((uint32_t) v) & (BFM_ADC_ADC_IERCLR_WCEXC)) >> (BFP_ADC_ADC_IERCLR_WCEXC))
#define BFW_ADC_ADC_IERCLR_WCEXC(v)             (REG_ADC_ADC_IERCLR.U32 = ( (REG_ADC_ADC_IERCLR.U32 & ~(BFM_ADC_ADC_IERCLR_WCEXC)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERCLR_WCEXC)) & (BFM_ADC_ADC_IERCLR_WCEXC)) ))
#define BFR_ADC_ADC_IERCLR_WCEXC()              ((REG_ADC_ADC_IERCLR.U32 & (BFM_ADC_ADC_IERCLR_WCEXC))>>(BFP_ADC_ADC_IERCLR_WCEXC))

#define BFP_ADC_ADC_IERCLR_FIFOOVR2             (3)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERCLR_FIFOOVR2             ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_ADC_ADC_IERCLR_FIFOOVR2             (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERCLR_FIFOOVR2             (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERCLR_FIFOOVR2(v)          ((((uint32_t) v) << (BFP_ADC_ADC_IERCLR_FIFOOVR2)) & (BFM_ADC_ADC_IERCLR_FIFOOVR2))
#define BFX_ADC_ADC_IERCLR_FIFOOVR2(v)          ((((uint32_t) v) & (BFM_ADC_ADC_IERCLR_FIFOOVR2)) >> (BFP_ADC_ADC_IERCLR_FIFOOVR2))
#define BFW_ADC_ADC_IERCLR_FIFOOVR2(v)          (REG_ADC_ADC_IERCLR.U32 = ( (REG_ADC_ADC_IERCLR.U32 & ~(BFM_ADC_ADC_IERCLR_FIFOOVR2)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERCLR_FIFOOVR2)) & (BFM_ADC_ADC_IERCLR_FIFOOVR2)) ))
#define BFR_ADC_ADC_IERCLR_FIFOOVR2()           ((REG_ADC_ADC_IERCLR.U32 & (BFM_ADC_ADC_IERCLR_FIFOOVR2))>>(BFP_ADC_ADC_IERCLR_FIFOOVR2))

#define BFP_ADC_ADC_IERCLR_FIFOOVR1             (2)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERCLR_FIFOOVR1             ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_ADC_ADC_IERCLR_FIFOOVR1             (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERCLR_FIFOOVR1             (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERCLR_FIFOOVR1(v)          ((((uint32_t) v) << (BFP_ADC_ADC_IERCLR_FIFOOVR1)) & (BFM_ADC_ADC_IERCLR_FIFOOVR1))
#define BFX_ADC_ADC_IERCLR_FIFOOVR1(v)          ((((uint32_t) v) & (BFM_ADC_ADC_IERCLR_FIFOOVR1)) >> (BFP_ADC_ADC_IERCLR_FIFOOVR1))
#define BFW_ADC_ADC_IERCLR_FIFOOVR1(v)          (REG_ADC_ADC_IERCLR.U32 = ( (REG_ADC_ADC_IERCLR.U32 & ~(BFM_ADC_ADC_IERCLR_FIFOOVR1)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERCLR_FIFOOVR1)) & (BFM_ADC_ADC_IERCLR_FIFOOVR1)) ))
#define BFR_ADC_ADC_IERCLR_FIFOOVR1()           ((REG_ADC_ADC_IERCLR.U32 & (BFM_ADC_ADC_IERCLR_FIFOOVR1))>>(BFP_ADC_ADC_IERCLR_FIFOOVR1))

#define BFP_ADC_ADC_IERCLR_SCNCMP               (1)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERCLR_SCNCMP               ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_ADC_ADC_IERCLR_SCNCMP               (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERCLR_SCNCMP               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERCLR_SCNCMP(v)            ((((uint32_t) v) << (BFP_ADC_ADC_IERCLR_SCNCMP)) & (BFM_ADC_ADC_IERCLR_SCNCMP))
#define BFX_ADC_ADC_IERCLR_SCNCMP(v)            ((((uint32_t) v) & (BFM_ADC_ADC_IERCLR_SCNCMP)) >> (BFP_ADC_ADC_IERCLR_SCNCMP))
#define BFW_ADC_ADC_IERCLR_SCNCMP(v)            (REG_ADC_ADC_IERCLR.U32 = ( (REG_ADC_ADC_IERCLR.U32 & ~(BFM_ADC_ADC_IERCLR_SCNCMP)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERCLR_SCNCMP)) & (BFM_ADC_ADC_IERCLR_SCNCMP)) ))
#define BFR_ADC_ADC_IERCLR_SCNCMP()             ((REG_ADC_ADC_IERCLR.U32 & (BFM_ADC_ADC_IERCLR_SCNCMP))>>(BFP_ADC_ADC_IERCLR_SCNCMP))

#define BFP_ADC_ADC_IERCLR_CNVCMP               (0)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERCLR_CNVCMP               ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_ADC_ADC_IERCLR_CNVCMP               (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERCLR_CNVCMP               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERCLR_CNVCMP(v)            ((((uint32_t) v) << (BFP_ADC_ADC_IERCLR_CNVCMP)) & (BFM_ADC_ADC_IERCLR_CNVCMP))
#define BFX_ADC_ADC_IERCLR_CNVCMP(v)            ((((uint32_t) v) & (BFM_ADC_ADC_IERCLR_CNVCMP)) >> (BFP_ADC_ADC_IERCLR_CNVCMP))
#define BFW_ADC_ADC_IERCLR_CNVCMP(v)            (REG_ADC_ADC_IERCLR.U32 = ( (REG_ADC_ADC_IERCLR.U32 & ~(BFM_ADC_ADC_IERCLR_CNVCMP)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERCLR_CNVCMP)) & (BFM_ADC_ADC_IERCLR_CNVCMP)) ))
#define BFR_ADC_ADC_IERCLR_CNVCMP()             ((REG_ADC_ADC_IERCLR.U32 & (BFM_ADC_ADC_IERCLR_CNVCMP))>>(BFP_ADC_ADC_IERCLR_CNVCMP))


// *****************************************************************************
//                                                                             *
//  ADC_ADC_IERSET - ADC Interrupt registers                                   *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_6                     : 26;
        unsigned WCINC                      :  1;
        unsigned WCEXC                      :  1;
        unsigned FIFOOVR2                   :  1;
        unsigned FIFOOVR1                   :  1;
        unsigned SCNCMP                     :  1;
        unsigned CNVCMP                     :  1;
    } B;
} reg_adc_adc_ierset_t;

#define REG_ADC_ADC_IERSET_ADDR                 (REG_ADC_BASEADDR + 0x0000020CUL)
#define REG_ADC_ADC_IERSET                      (*(volatile reg_adc_adc_ierset_t *) REG_ADC_ADC_IERSET_ADDR)
#define REG_ADC_ADC_IERSET_RD()                 (REG_ADC_ADC_IERSET.U32)
#define REG_ADC_ADC_IERSET_WR(v)                (REG_ADC_ADC_IERSET.U32 = (v))
#define REG_ADC_ADC_IERSET_CLR(m)               (REG_ADC_ADC_IERSET.U32 = ((REG_ADC_ADC_IERSET.U32) & ~(m)))
#define REG_ADC_ADC_IERSET_SET(m)               (REG_ADC_ADC_IERSET.U32 = ((REG_ADC_ADC_IERSET.U32) | (m)))
#define REG_ADC_ADC_IERSET_DEF                  0x00000000

#define BFP_ADC_ADC_IERSET_RSVD_6               (6)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERSET_RSVD_6               ((uint32_t)0xffffffc0)  /* bitfield mask */
#define BFN_ADC_ADC_IERSET_RSVD_6               (26)                    /* bitfield width */
#define BFD_ADC_ADC_IERSET_RSVD_6               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERSET_RSVD_6(v)            ((((uint32_t) v) << (BFP_ADC_ADC_IERSET_RSVD_6)) & (BFM_ADC_ADC_IERSET_RSVD_6))
#define BFX_ADC_ADC_IERSET_RSVD_6(v)            ((((uint32_t) v) & (BFM_ADC_ADC_IERSET_RSVD_6)) >> (BFP_ADC_ADC_IERSET_RSVD_6))
#define BFW_ADC_ADC_IERSET_RSVD_6(v)            (REG_ADC_ADC_IERSET.U32 = ( (REG_ADC_ADC_IERSET.U32 & ~(BFM_ADC_ADC_IERSET_RSVD_6)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERSET_RSVD_6)) & (BFM_ADC_ADC_IERSET_RSVD_6)) ))
#define BFR_ADC_ADC_IERSET_RSVD_6()             ((REG_ADC_ADC_IERSET.U32 & (BFM_ADC_ADC_IERSET_RSVD_6))>>(BFP_ADC_ADC_IERSET_RSVD_6))

#define BFP_ADC_ADC_IERSET_WCINC                (5)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERSET_WCINC                ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_ADC_ADC_IERSET_WCINC                (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERSET_WCINC                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERSET_WCINC(v)             ((((uint32_t) v) << (BFP_ADC_ADC_IERSET_WCINC)) & (BFM_ADC_ADC_IERSET_WCINC))
#define BFX_ADC_ADC_IERSET_WCINC(v)             ((((uint32_t) v) & (BFM_ADC_ADC_IERSET_WCINC)) >> (BFP_ADC_ADC_IERSET_WCINC))
#define BFW_ADC_ADC_IERSET_WCINC(v)             (REG_ADC_ADC_IERSET.U32 = ( (REG_ADC_ADC_IERSET.U32 & ~(BFM_ADC_ADC_IERSET_WCINC)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERSET_WCINC)) & (BFM_ADC_ADC_IERSET_WCINC)) ))
#define BFR_ADC_ADC_IERSET_WCINC()              ((REG_ADC_ADC_IERSET.U32 & (BFM_ADC_ADC_IERSET_WCINC))>>(BFP_ADC_ADC_IERSET_WCINC))

#define BFP_ADC_ADC_IERSET_WCEXC                (4)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERSET_WCEXC                ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_ADC_ADC_IERSET_WCEXC                (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERSET_WCEXC                (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERSET_WCEXC(v)             ((((uint32_t) v) << (BFP_ADC_ADC_IERSET_WCEXC)) & (BFM_ADC_ADC_IERSET_WCEXC))
#define BFX_ADC_ADC_IERSET_WCEXC(v)             ((((uint32_t) v) & (BFM_ADC_ADC_IERSET_WCEXC)) >> (BFP_ADC_ADC_IERSET_WCEXC))
#define BFW_ADC_ADC_IERSET_WCEXC(v)             (REG_ADC_ADC_IERSET.U32 = ( (REG_ADC_ADC_IERSET.U32 & ~(BFM_ADC_ADC_IERSET_WCEXC)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERSET_WCEXC)) & (BFM_ADC_ADC_IERSET_WCEXC)) ))
#define BFR_ADC_ADC_IERSET_WCEXC()              ((REG_ADC_ADC_IERSET.U32 & (BFM_ADC_ADC_IERSET_WCEXC))>>(BFP_ADC_ADC_IERSET_WCEXC))

#define BFP_ADC_ADC_IERSET_FIFOOVR2             (3)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERSET_FIFOOVR2             ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_ADC_ADC_IERSET_FIFOOVR2             (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERSET_FIFOOVR2             (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERSET_FIFOOVR2(v)          ((((uint32_t) v) << (BFP_ADC_ADC_IERSET_FIFOOVR2)) & (BFM_ADC_ADC_IERSET_FIFOOVR2))
#define BFX_ADC_ADC_IERSET_FIFOOVR2(v)          ((((uint32_t) v) & (BFM_ADC_ADC_IERSET_FIFOOVR2)) >> (BFP_ADC_ADC_IERSET_FIFOOVR2))
#define BFW_ADC_ADC_IERSET_FIFOOVR2(v)          (REG_ADC_ADC_IERSET.U32 = ( (REG_ADC_ADC_IERSET.U32 & ~(BFM_ADC_ADC_IERSET_FIFOOVR2)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERSET_FIFOOVR2)) & (BFM_ADC_ADC_IERSET_FIFOOVR2)) ))
#define BFR_ADC_ADC_IERSET_FIFOOVR2()           ((REG_ADC_ADC_IERSET.U32 & (BFM_ADC_ADC_IERSET_FIFOOVR2))>>(BFP_ADC_ADC_IERSET_FIFOOVR2))

#define BFP_ADC_ADC_IERSET_FIFOOVR1             (2)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERSET_FIFOOVR1             ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_ADC_ADC_IERSET_FIFOOVR1             (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERSET_FIFOOVR1             (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERSET_FIFOOVR1(v)          ((((uint32_t) v) << (BFP_ADC_ADC_IERSET_FIFOOVR1)) & (BFM_ADC_ADC_IERSET_FIFOOVR1))
#define BFX_ADC_ADC_IERSET_FIFOOVR1(v)          ((((uint32_t) v) & (BFM_ADC_ADC_IERSET_FIFOOVR1)) >> (BFP_ADC_ADC_IERSET_FIFOOVR1))
#define BFW_ADC_ADC_IERSET_FIFOOVR1(v)          (REG_ADC_ADC_IERSET.U32 = ( (REG_ADC_ADC_IERSET.U32 & ~(BFM_ADC_ADC_IERSET_FIFOOVR1)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERSET_FIFOOVR1)) & (BFM_ADC_ADC_IERSET_FIFOOVR1)) ))
#define BFR_ADC_ADC_IERSET_FIFOOVR1()           ((REG_ADC_ADC_IERSET.U32 & (BFM_ADC_ADC_IERSET_FIFOOVR1))>>(BFP_ADC_ADC_IERSET_FIFOOVR1))

#define BFP_ADC_ADC_IERSET_SCNCMP               (1)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERSET_SCNCMP               ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_ADC_ADC_IERSET_SCNCMP               (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERSET_SCNCMP               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERSET_SCNCMP(v)            ((((uint32_t) v) << (BFP_ADC_ADC_IERSET_SCNCMP)) & (BFM_ADC_ADC_IERSET_SCNCMP))
#define BFX_ADC_ADC_IERSET_SCNCMP(v)            ((((uint32_t) v) & (BFM_ADC_ADC_IERSET_SCNCMP)) >> (BFP_ADC_ADC_IERSET_SCNCMP))
#define BFW_ADC_ADC_IERSET_SCNCMP(v)            (REG_ADC_ADC_IERSET.U32 = ( (REG_ADC_ADC_IERSET.U32 & ~(BFM_ADC_ADC_IERSET_SCNCMP)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERSET_SCNCMP)) & (BFM_ADC_ADC_IERSET_SCNCMP)) ))
#define BFR_ADC_ADC_IERSET_SCNCMP()             ((REG_ADC_ADC_IERSET.U32 & (BFM_ADC_ADC_IERSET_SCNCMP))>>(BFP_ADC_ADC_IERSET_SCNCMP))

#define BFP_ADC_ADC_IERSET_CNVCMP               (0)                     /* bitfield lsb */
#define BFM_ADC_ADC_IERSET_CNVCMP               ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_ADC_ADC_IERSET_CNVCMP               (1)                     /* bitfield width */
#define BFD_ADC_ADC_IERSET_CNVCMP               (0x0)                   /* bitfield default value */
#define BFV_ADC_ADC_IERSET_CNVCMP(v)            ((((uint32_t) v) << (BFP_ADC_ADC_IERSET_CNVCMP)) & (BFM_ADC_ADC_IERSET_CNVCMP))
#define BFX_ADC_ADC_IERSET_CNVCMP(v)            ((((uint32_t) v) & (BFM_ADC_ADC_IERSET_CNVCMP)) >> (BFP_ADC_ADC_IERSET_CNVCMP))
#define BFW_ADC_ADC_IERSET_CNVCMP(v)            (REG_ADC_ADC_IERSET.U32 = ( (REG_ADC_ADC_IERSET.U32 & ~(BFM_ADC_ADC_IERSET_CNVCMP)) | ((((uint32_t) v)<<(BFP_ADC_ADC_IERSET_CNVCMP)) & (BFM_ADC_ADC_IERSET_CNVCMP)) ))
#define BFR_ADC_ADC_IERSET_CNVCMP()             ((REG_ADC_ADC_IERSET.U32 & (BFM_ADC_ADC_IERSET_CNVCMP))>>(BFP_ADC_ADC_IERSET_CNVCMP))


#endif  // __ADC_H

