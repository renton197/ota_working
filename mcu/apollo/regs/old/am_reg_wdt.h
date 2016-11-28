/*******************************************************************************
*                                                                              *
*   Copyright (c) 2013-2014 Ambiq Micro                                        *
*                                                                              *
********************************************************************************
*                                                                              *
*   File:       wdt.h                                                          *
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


#ifndef __WDT_H
#define __WDT_H

#include "../am_mcu_apollo.h"


// *****************************************************************************
//                                                                             *
//  WDT_WDTCFG - Configuration Register                                        *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_24                    :  8;
        unsigned INTVAL                     :  8;
        unsigned RESVAL                     :  8;
        unsigned RSVD_3                     :  5;
        unsigned RESEN                      :  1;
        unsigned INTEN                      :  1;
        unsigned WDTEN                      :  1;
    } B;
} reg_wdt_wdtcfg_t;

#define REG_WDT_WDTCFG_ADDR                     (REG_WDT_BASEADDR + 0x00000000UL)
#define REG_WDT_WDTCFG                          (*(volatile reg_wdt_wdtcfg_t *) REG_WDT_WDTCFG_ADDR)
#define REG_WDT_WDTCFG_RD()                     (REG_WDT_WDTCFG.U32)
#define REG_WDT_WDTCFG_WR(v)                    (REG_WDT_WDTCFG.U32 = (v))
#define REG_WDT_WDTCFG_CLR(m)                   (REG_WDT_WDTCFG.U32 = ((REG_WDT_WDTCFG.U32) & ~(m)))
#define REG_WDT_WDTCFG_SET(m)                   (REG_WDT_WDTCFG.U32 = ((REG_WDT_WDTCFG.U32) | (m)))
#define REG_WDT_WDTCFG_DEF                      0x00000000

#define BFP_WDT_WDTCFG_RSVD_24                  (24)                    /* bitfield lsb */
#define BFM_WDT_WDTCFG_RSVD_24                  ((uint32_t)0xff000000)  /* bitfield mask */
#define BFN_WDT_WDTCFG_RSVD_24                  (8)                     /* bitfield width */
#define BFD_WDT_WDTCFG_RSVD_24                  (0x0)                   /* bitfield default value */
#define BFV_WDT_WDTCFG_RSVD_24(v)               ((((uint32_t) v) << (BFP_WDT_WDTCFG_RSVD_24)) & (BFM_WDT_WDTCFG_RSVD_24))
#define BFX_WDT_WDTCFG_RSVD_24(v)               ((((uint32_t) v) & (BFM_WDT_WDTCFG_RSVD_24)) >> (BFP_WDT_WDTCFG_RSVD_24))
#define BFW_WDT_WDTCFG_RSVD_24(v)               (REG_WDT_WDTCFG.U32 = ( (REG_WDT_WDTCFG.U32 & ~(BFM_WDT_WDTCFG_RSVD_24)) | ((((uint32_t) v)<<(BFP_WDT_WDTCFG_RSVD_24)) & (BFM_WDT_WDTCFG_RSVD_24)) ))
#define BFR_WDT_WDTCFG_RSVD_24()                ((REG_WDT_WDTCFG.U32 & (BFM_WDT_WDTCFG_RSVD_24))>>(BFP_WDT_WDTCFG_RSVD_24))
#define BFS_WDT_WDTCFG_RSVD_24()                (REG_WDT_WDTCFG.U32 = (BFM_WDT_WDTCFG_RSVD_24) )

#define BFP_WDT_WDTCFG_INTVAL                   (16)                    /* bitfield lsb */
#define BFM_WDT_WDTCFG_INTVAL                   ((uint32_t)0x00ff0000)  /* bitfield mask */
#define BFN_WDT_WDTCFG_INTVAL                   (8)                     /* bitfield width */
#define BFD_WDT_WDTCFG_INTVAL                   (0x0)                   /* bitfield default value */
#define BFV_WDT_WDTCFG_INTVAL(v)                ((((uint32_t) v) << (BFP_WDT_WDTCFG_INTVAL)) & (BFM_WDT_WDTCFG_INTVAL))
#define BFX_WDT_WDTCFG_INTVAL(v)                ((((uint32_t) v) & (BFM_WDT_WDTCFG_INTVAL)) >> (BFP_WDT_WDTCFG_INTVAL))
#define BFW_WDT_WDTCFG_INTVAL(v)                (REG_WDT_WDTCFG.U32 = ( (REG_WDT_WDTCFG.U32 & ~(BFM_WDT_WDTCFG_INTVAL)) | ((((uint32_t) v)<<(BFP_WDT_WDTCFG_INTVAL)) & (BFM_WDT_WDTCFG_INTVAL)) ))
#define BFR_WDT_WDTCFG_INTVAL()                 ((REG_WDT_WDTCFG.U32 & (BFM_WDT_WDTCFG_INTVAL))>>(BFP_WDT_WDTCFG_INTVAL))
#define BFS_WDT_WDTCFG_INTVAL()                 (REG_WDT_WDTCFG.U32 = (BFM_WDT_WDTCFG_INTVAL) )

#define BFP_WDT_WDTCFG_RESVAL                   (8)                     /* bitfield lsb */
#define BFM_WDT_WDTCFG_RESVAL                   ((uint32_t)0x0000ff00)  /* bitfield mask */
#define BFN_WDT_WDTCFG_RESVAL                   (8)                     /* bitfield width */
#define BFD_WDT_WDTCFG_RESVAL                   (0x0)                   /* bitfield default value */
#define BFV_WDT_WDTCFG_RESVAL(v)                ((((uint32_t) v) << (BFP_WDT_WDTCFG_RESVAL)) & (BFM_WDT_WDTCFG_RESVAL))
#define BFX_WDT_WDTCFG_RESVAL(v)                ((((uint32_t) v) & (BFM_WDT_WDTCFG_RESVAL)) >> (BFP_WDT_WDTCFG_RESVAL))
#define BFW_WDT_WDTCFG_RESVAL(v)                (REG_WDT_WDTCFG.U32 = ( (REG_WDT_WDTCFG.U32 & ~(BFM_WDT_WDTCFG_RESVAL)) | ((((uint32_t) v)<<(BFP_WDT_WDTCFG_RESVAL)) & (BFM_WDT_WDTCFG_RESVAL)) ))
#define BFR_WDT_WDTCFG_RESVAL()                 ((REG_WDT_WDTCFG.U32 & (BFM_WDT_WDTCFG_RESVAL))>>(BFP_WDT_WDTCFG_RESVAL))
#define BFS_WDT_WDTCFG_RESVAL()                 (REG_WDT_WDTCFG.U32 = (BFM_WDT_WDTCFG_RESVAL) )

#define BFP_WDT_WDTCFG_RSVD_3                   (3)                     /* bitfield lsb */
#define BFM_WDT_WDTCFG_RSVD_3                   ((uint32_t)0x000000f8)  /* bitfield mask */
#define BFN_WDT_WDTCFG_RSVD_3                   (5)                     /* bitfield width */
#define BFD_WDT_WDTCFG_RSVD_3                   (0x0)                   /* bitfield default value */
#define BFV_WDT_WDTCFG_RSVD_3(v)                ((((uint32_t) v) << (BFP_WDT_WDTCFG_RSVD_3)) & (BFM_WDT_WDTCFG_RSVD_3))
#define BFX_WDT_WDTCFG_RSVD_3(v)                ((((uint32_t) v) & (BFM_WDT_WDTCFG_RSVD_3)) >> (BFP_WDT_WDTCFG_RSVD_3))
#define BFW_WDT_WDTCFG_RSVD_3(v)                (REG_WDT_WDTCFG.U32 = ( (REG_WDT_WDTCFG.U32 & ~(BFM_WDT_WDTCFG_RSVD_3)) | ((((uint32_t) v)<<(BFP_WDT_WDTCFG_RSVD_3)) & (BFM_WDT_WDTCFG_RSVD_3)) ))
#define BFR_WDT_WDTCFG_RSVD_3()                 ((REG_WDT_WDTCFG.U32 & (BFM_WDT_WDTCFG_RSVD_3))>>(BFP_WDT_WDTCFG_RSVD_3))
#define BFS_WDT_WDTCFG_RSVD_3()                 (REG_WDT_WDTCFG.U32 = (BFM_WDT_WDTCFG_RSVD_3) )

#define BFP_WDT_WDTCFG_RESEN                    (2)                     /* bitfield lsb */
#define BFM_WDT_WDTCFG_RESEN                    ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_WDT_WDTCFG_RESEN                    (1)                     /* bitfield width */
#define BFD_WDT_WDTCFG_RESEN                    (0x0)                   /* bitfield default value */
#define BFV_WDT_WDTCFG_RESEN(v)                 ((((uint32_t) v) << (BFP_WDT_WDTCFG_RESEN)) & (BFM_WDT_WDTCFG_RESEN))
#define BFX_WDT_WDTCFG_RESEN(v)                 ((((uint32_t) v) & (BFM_WDT_WDTCFG_RESEN)) >> (BFP_WDT_WDTCFG_RESEN))
#define BFW_WDT_WDTCFG_RESEN(v)                 (REG_WDT_WDTCFG.U32 = ( (REG_WDT_WDTCFG.U32 & ~(BFM_WDT_WDTCFG_RESEN)) | ((((uint32_t) v)<<(BFP_WDT_WDTCFG_RESEN)) & (BFM_WDT_WDTCFG_RESEN)) ))
#define BFR_WDT_WDTCFG_RESEN()                  ((REG_WDT_WDTCFG.U32 & (BFM_WDT_WDTCFG_RESEN))>>(BFP_WDT_WDTCFG_RESEN))
#define BFS_WDT_WDTCFG_RESEN()                  (REG_WDT_WDTCFG.U32 = (BFM_WDT_WDTCFG_RESEN) )

#define BFP_WDT_WDTCFG_INTEN                    (1)                     /* bitfield lsb */
#define BFM_WDT_WDTCFG_INTEN                    ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_WDT_WDTCFG_INTEN                    (1)                     /* bitfield width */
#define BFD_WDT_WDTCFG_INTEN                    (0x0)                   /* bitfield default value */
#define BFV_WDT_WDTCFG_INTEN(v)                 ((((uint32_t) v) << (BFP_WDT_WDTCFG_INTEN)) & (BFM_WDT_WDTCFG_INTEN))
#define BFX_WDT_WDTCFG_INTEN(v)                 ((((uint32_t) v) & (BFM_WDT_WDTCFG_INTEN)) >> (BFP_WDT_WDTCFG_INTEN))
#define BFW_WDT_WDTCFG_INTEN(v)                 (REG_WDT_WDTCFG.U32 = ( (REG_WDT_WDTCFG.U32 & ~(BFM_WDT_WDTCFG_INTEN)) | ((((uint32_t) v)<<(BFP_WDT_WDTCFG_INTEN)) & (BFM_WDT_WDTCFG_INTEN)) ))
#define BFR_WDT_WDTCFG_INTEN()                  ((REG_WDT_WDTCFG.U32 & (BFM_WDT_WDTCFG_INTEN))>>(BFP_WDT_WDTCFG_INTEN))
#define BFS_WDT_WDTCFG_INTEN()                  (REG_WDT_WDTCFG.U32 = (BFM_WDT_WDTCFG_INTEN) )

#define BFP_WDT_WDTCFG_WDTEN                    (0)                     /* bitfield lsb */
#define BFM_WDT_WDTCFG_WDTEN                    ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_WDT_WDTCFG_WDTEN                    (1)                     /* bitfield width */
#define BFD_WDT_WDTCFG_WDTEN                    (0x0)                   /* bitfield default value */
#define BFV_WDT_WDTCFG_WDTEN(v)                 ((((uint32_t) v) << (BFP_WDT_WDTCFG_WDTEN)) & (BFM_WDT_WDTCFG_WDTEN))
#define BFX_WDT_WDTCFG_WDTEN(v)                 ((((uint32_t) v) & (BFM_WDT_WDTCFG_WDTEN)) >> (BFP_WDT_WDTCFG_WDTEN))
#define BFW_WDT_WDTCFG_WDTEN(v)                 (REG_WDT_WDTCFG.U32 = ( (REG_WDT_WDTCFG.U32 & ~(BFM_WDT_WDTCFG_WDTEN)) | ((((uint32_t) v)<<(BFP_WDT_WDTCFG_WDTEN)) & (BFM_WDT_WDTCFG_WDTEN)) ))
#define BFR_WDT_WDTCFG_WDTEN()                  ((REG_WDT_WDTCFG.U32 & (BFM_WDT_WDTCFG_WDTEN))>>(BFP_WDT_WDTCFG_WDTEN))
#define BFS_WDT_WDTCFG_WDTEN()                  (REG_WDT_WDTCFG.U32 = (BFM_WDT_WDTCFG_WDTEN) )


// *****************************************************************************
//                                                                             *
//  WDT_WDTRSTRT - Restart the watchdog timer                                  *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned WDTRSTRT                   :  8;
    } B;
} reg_wdt_wdtrstrt_t;

#define REG_WDT_WDTRSTRT_ADDR                   (REG_WDT_BASEADDR + 0x00000004UL)
#define REG_WDT_WDTRSTRT                        (*(volatile reg_wdt_wdtrstrt_t *) REG_WDT_WDTRSTRT_ADDR)
#define REG_WDT_WDTRSTRT_RD()                   (REG_WDT_WDTRSTRT.U32)
#define REG_WDT_WDTRSTRT_WR(v)                  (REG_WDT_WDTRSTRT.U32 = (v))
#define REG_WDT_WDTRSTRT_CLR(m)                 (REG_WDT_WDTRSTRT.U32 = ((REG_WDT_WDTRSTRT.U32) & ~(m)))
#define REG_WDT_WDTRSTRT_SET(m)                 (REG_WDT_WDTRSTRT.U32 = ((REG_WDT_WDTRSTRT.U32) | (m)))
#define REG_WDT_WDTRSTRT_DEF                    0x00000000

#define BFP_WDT_WDTRSTRT_RSVD_8                 (8)                     /* bitfield lsb */
#define BFM_WDT_WDTRSTRT_RSVD_8                 ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_WDT_WDTRSTRT_RSVD_8                 (24)                    /* bitfield width */
#define BFD_WDT_WDTRSTRT_RSVD_8                 (0x0)                   /* bitfield default value */
#define BFV_WDT_WDTRSTRT_RSVD_8(v)              ((((uint32_t) v) << (BFP_WDT_WDTRSTRT_RSVD_8)) & (BFM_WDT_WDTRSTRT_RSVD_8))
#define BFX_WDT_WDTRSTRT_RSVD_8(v)              ((((uint32_t) v) & (BFM_WDT_WDTRSTRT_RSVD_8)) >> (BFP_WDT_WDTRSTRT_RSVD_8))
#define BFW_WDT_WDTRSTRT_RSVD_8(v)              (REG_WDT_WDTRSTRT.U32 = ( (((uint32_t) v)<<(BFP_WDT_WDTRSTRT_RSVD_8)) & (BFM_WDT_WDTRSTRT_RSVD_8)) )
#define BFR_WDT_WDTRSTRT_RSVD_8()               ((REG_WDT_WDTRSTRT.U32 & (BFM_WDT_WDTRSTRT_RSVD_8))>>(BFP_WDT_WDTRSTRT_RSVD_8))

#define BFP_WDT_WDTRSTRT_WDTRSTRT               (0)                     /* bitfield lsb */
#define BFM_WDT_WDTRSTRT_WDTRSTRT               ((uint32_t)0x000000ff)  /* bitfield mask */
#define BFN_WDT_WDTRSTRT_WDTRSTRT               (8)                     /* bitfield width */
#define BFD_WDT_WDTRSTRT_WDTRSTRT               (0x0)                   /* bitfield default value */
#define BFV_WDT_WDTRSTRT_WDTRSTRT(v)            ((((uint32_t) v) << (BFP_WDT_WDTRSTRT_WDTRSTRT)) & (BFM_WDT_WDTRSTRT_WDTRSTRT))
#define BFX_WDT_WDTRSTRT_WDTRSTRT(v)            ((((uint32_t) v) & (BFM_WDT_WDTRSTRT_WDTRSTRT)) >> (BFP_WDT_WDTRSTRT_WDTRSTRT))
#define BFW_WDT_WDTRSTRT_WDTRSTRT(v)            (REG_WDT_WDTRSTRT.U32 = ( (((uint32_t) v)<<(BFP_WDT_WDTRSTRT_WDTRSTRT)) & (BFM_WDT_WDTRSTRT_WDTRSTRT)) )
#define BFR_WDT_WDTRSTRT_WDTRSTRT()             ((REG_WDT_WDTRSTRT.U32 & (BFM_WDT_WDTRSTRT_WDTRSTRT))>>(BFP_WDT_WDTRSTRT_WDTRSTRT))


// *****************************************************************************
//                                                                             *
//  WDT_WDTLOCK - Locks the WDT                                                *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned WDTLOCK                    :  8;
    } B;
} reg_wdt_wdtlock_t;

#define REG_WDT_WDTLOCK_ADDR                    (REG_WDT_BASEADDR + 0x00000008UL)
#define REG_WDT_WDTLOCK                         (*(volatile reg_wdt_wdtlock_t *) REG_WDT_WDTLOCK_ADDR)
#define REG_WDT_WDTLOCK_RD()                    (REG_WDT_WDTLOCK.U32)
#define REG_WDT_WDTLOCK_WR(v)                   (REG_WDT_WDTLOCK.U32 = (v))
#define REG_WDT_WDTLOCK_CLR(m)                  (REG_WDT_WDTLOCK.U32 = ((REG_WDT_WDTLOCK.U32) & ~(m)))
#define REG_WDT_WDTLOCK_SET(m)                  (REG_WDT_WDTLOCK.U32 = ((REG_WDT_WDTLOCK.U32) | (m)))
#define REG_WDT_WDTLOCK_DEF                     0x00000000

#define BFP_WDT_WDTLOCK_RSVD_8                  (8)                     /* bitfield lsb */
#define BFM_WDT_WDTLOCK_RSVD_8                  ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_WDT_WDTLOCK_RSVD_8                  (24)                    /* bitfield width */
#define BFD_WDT_WDTLOCK_RSVD_8                  (0x0)                   /* bitfield default value */
#define BFV_WDT_WDTLOCK_RSVD_8(v)               ((((uint32_t) v) << (BFP_WDT_WDTLOCK_RSVD_8)) & (BFM_WDT_WDTLOCK_RSVD_8))
#define BFX_WDT_WDTLOCK_RSVD_8(v)               ((((uint32_t) v) & (BFM_WDT_WDTLOCK_RSVD_8)) >> (BFP_WDT_WDTLOCK_RSVD_8))
#define BFW_WDT_WDTLOCK_RSVD_8(v)               (REG_WDT_WDTLOCK.U32 = ( (((uint32_t) v)<<(BFP_WDT_WDTLOCK_RSVD_8)) & (BFM_WDT_WDTLOCK_RSVD_8)) )
#define BFR_WDT_WDTLOCK_RSVD_8()                ((REG_WDT_WDTLOCK.U32 & (BFM_WDT_WDTLOCK_RSVD_8))>>(BFP_WDT_WDTLOCK_RSVD_8))

#define BFP_WDT_WDTLOCK_WDTLOCK                 (0)                     /* bitfield lsb */
#define BFM_WDT_WDTLOCK_WDTLOCK                 ((uint32_t)0x000000ff)  /* bitfield mask */
#define BFN_WDT_WDTLOCK_WDTLOCK                 (8)                     /* bitfield width */
#define BFD_WDT_WDTLOCK_WDTLOCK                 (0x0)                   /* bitfield default value */
#define BFV_WDT_WDTLOCK_WDTLOCK(v)              ((((uint32_t) v) << (BFP_WDT_WDTLOCK_WDTLOCK)) & (BFM_WDT_WDTLOCK_WDTLOCK))
#define BFX_WDT_WDTLOCK_WDTLOCK(v)              ((((uint32_t) v) & (BFM_WDT_WDTLOCK_WDTLOCK)) >> (BFP_WDT_WDTLOCK_WDTLOCK))
#define BFW_WDT_WDTLOCK_WDTLOCK(v)              (REG_WDT_WDTLOCK.U32 = ( (((uint32_t) v)<<(BFP_WDT_WDTLOCK_WDTLOCK)) & (BFM_WDT_WDTLOCK_WDTLOCK)) )
#define BFR_WDT_WDTLOCK_WDTLOCK()               ((REG_WDT_WDTLOCK.U32 & (BFM_WDT_WDTLOCK_WDTLOCK))>>(BFP_WDT_WDTLOCK_WDTLOCK))


// *****************************************************************************
//                                                                             *
//  WDT_WDT_IEREN - WDT Interrupt register                                     *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_1                     : 31;
        unsigned WDT                        :  1;
    } B;
} reg_wdt_wdt_ieren_t;

#define REG_WDT_WDT_IEREN_ADDR                  (REG_WDT_BASEADDR + 0x00000200UL)
#define REG_WDT_WDT_IEREN                       (*(volatile reg_wdt_wdt_ieren_t *) REG_WDT_WDT_IEREN_ADDR)
#define REG_WDT_WDT_IEREN_RD()                  (REG_WDT_WDT_IEREN.U32)
#define REG_WDT_WDT_IEREN_WR(v)                 (REG_WDT_WDT_IEREN.U32 = (v))
#define REG_WDT_WDT_IEREN_CLR(m)                (REG_WDT_WDT_IEREN.U32 = ((REG_WDT_WDT_IEREN.U32) & ~(m)))
#define REG_WDT_WDT_IEREN_SET(m)                (REG_WDT_WDT_IEREN.U32 = ((REG_WDT_WDT_IEREN.U32) | (m)))
#define REG_WDT_WDT_IEREN_DEF                   0x00000000

#define BFP_WDT_WDT_IEREN_RSVD_1                (1)                     /* bitfield lsb */
#define BFM_WDT_WDT_IEREN_RSVD_1                ((uint32_t)0xfffffffe)  /* bitfield mask */
#define BFN_WDT_WDT_IEREN_RSVD_1                (31)                    /* bitfield width */
#define BFD_WDT_WDT_IEREN_RSVD_1                (0x0)                   /* bitfield default value */
#define BFV_WDT_WDT_IEREN_RSVD_1(v)             ((((uint32_t) v) << (BFP_WDT_WDT_IEREN_RSVD_1)) & (BFM_WDT_WDT_IEREN_RSVD_1))
#define BFX_WDT_WDT_IEREN_RSVD_1(v)             ((((uint32_t) v) & (BFM_WDT_WDT_IEREN_RSVD_1)) >> (BFP_WDT_WDT_IEREN_RSVD_1))
#define BFW_WDT_WDT_IEREN_RSVD_1(v)             (REG_WDT_WDT_IEREN.U32 = ( (((uint32_t) v)<<(BFP_WDT_WDT_IEREN_RSVD_1)) & (BFM_WDT_WDT_IEREN_RSVD_1)) )
#define BFR_WDT_WDT_IEREN_RSVD_1()              ((REG_WDT_WDT_IEREN.U32 & (BFM_WDT_WDT_IEREN_RSVD_1))>>(BFP_WDT_WDT_IEREN_RSVD_1))

#define BFP_WDT_WDT_IEREN_WDT                   (0)                     /* bitfield lsb */
#define BFM_WDT_WDT_IEREN_WDT                   ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_WDT_WDT_IEREN_WDT                   (1)                     /* bitfield width */
#define BFD_WDT_WDT_IEREN_WDT                   (0x0)                   /* bitfield default value */
#define BFV_WDT_WDT_IEREN_WDT(v)                ((((uint32_t) v) << (BFP_WDT_WDT_IEREN_WDT)) & (BFM_WDT_WDT_IEREN_WDT))
#define BFX_WDT_WDT_IEREN_WDT(v)                ((((uint32_t) v) & (BFM_WDT_WDT_IEREN_WDT)) >> (BFP_WDT_WDT_IEREN_WDT))
#define BFW_WDT_WDT_IEREN_WDT(v)                (REG_WDT_WDT_IEREN.U32 = ( (((uint32_t) v)<<(BFP_WDT_WDT_IEREN_WDT)) & (BFM_WDT_WDT_IEREN_WDT)) )
#define BFR_WDT_WDT_IEREN_WDT()                 ((REG_WDT_WDT_IEREN.U32 & (BFM_WDT_WDT_IEREN_WDT))>>(BFP_WDT_WDT_IEREN_WDT))


// *****************************************************************************
//                                                                             *
//  WDT_WDT_IERSTAT - WDT Interrupt register                                   *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_1                     : 31;
        unsigned WDT                        :  1;
    } B;
} reg_wdt_wdt_ierstat_t;

#define REG_WDT_WDT_IERSTAT_ADDR                (REG_WDT_BASEADDR + 0x00000204UL)
#define REG_WDT_WDT_IERSTAT                     (*(volatile reg_wdt_wdt_ierstat_t *) REG_WDT_WDT_IERSTAT_ADDR)
#define REG_WDT_WDT_IERSTAT_RD()                (REG_WDT_WDT_IERSTAT.U32)
#define REG_WDT_WDT_IERSTAT_WR(v)               (REG_WDT_WDT_IERSTAT.U32 = (v))
#define REG_WDT_WDT_IERSTAT_CLR(m)              (REG_WDT_WDT_IERSTAT.U32 = ((REG_WDT_WDT_IERSTAT.U32) & ~(m)))
#define REG_WDT_WDT_IERSTAT_SET(m)              (REG_WDT_WDT_IERSTAT.U32 = ((REG_WDT_WDT_IERSTAT.U32) | (m)))
#define REG_WDT_WDT_IERSTAT_DEF                 0x00000000

#define BFP_WDT_WDT_IERSTAT_RSVD_1              (1)                     /* bitfield lsb */
#define BFM_WDT_WDT_IERSTAT_RSVD_1              ((uint32_t)0xfffffffe)  /* bitfield mask */
#define BFN_WDT_WDT_IERSTAT_RSVD_1              (31)                    /* bitfield width */
#define BFD_WDT_WDT_IERSTAT_RSVD_1              (0x0)                   /* bitfield default value */
#define BFV_WDT_WDT_IERSTAT_RSVD_1(v)           ((((uint32_t) v) << (BFP_WDT_WDT_IERSTAT_RSVD_1)) & (BFM_WDT_WDT_IERSTAT_RSVD_1))
#define BFX_WDT_WDT_IERSTAT_RSVD_1(v)           ((((uint32_t) v) & (BFM_WDT_WDT_IERSTAT_RSVD_1)) >> (BFP_WDT_WDT_IERSTAT_RSVD_1))
#define BFW_WDT_WDT_IERSTAT_RSVD_1(v)           (REG_WDT_WDT_IERSTAT.U32 = ( (((uint32_t) v)<<(BFP_WDT_WDT_IERSTAT_RSVD_1)) & (BFM_WDT_WDT_IERSTAT_RSVD_1)) )
#define BFR_WDT_WDT_IERSTAT_RSVD_1()            ((REG_WDT_WDT_IERSTAT.U32 & (BFM_WDT_WDT_IERSTAT_RSVD_1))>>(BFP_WDT_WDT_IERSTAT_RSVD_1))

#define BFP_WDT_WDT_IERSTAT_WDT                 (0)                     /* bitfield lsb */
#define BFM_WDT_WDT_IERSTAT_WDT                 ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_WDT_WDT_IERSTAT_WDT                 (1)                     /* bitfield width */
#define BFD_WDT_WDT_IERSTAT_WDT                 (0x0)                   /* bitfield default value */
#define BFV_WDT_WDT_IERSTAT_WDT(v)              ((((uint32_t) v) << (BFP_WDT_WDT_IERSTAT_WDT)) & (BFM_WDT_WDT_IERSTAT_WDT))
#define BFX_WDT_WDT_IERSTAT_WDT(v)              ((((uint32_t) v) & (BFM_WDT_WDT_IERSTAT_WDT)) >> (BFP_WDT_WDT_IERSTAT_WDT))
#define BFW_WDT_WDT_IERSTAT_WDT(v)              (REG_WDT_WDT_IERSTAT.U32 = ( (((uint32_t) v)<<(BFP_WDT_WDT_IERSTAT_WDT)) & (BFM_WDT_WDT_IERSTAT_WDT)) )
#define BFR_WDT_WDT_IERSTAT_WDT()               ((REG_WDT_WDT_IERSTAT.U32 & (BFM_WDT_WDT_IERSTAT_WDT))>>(BFP_WDT_WDT_IERSTAT_WDT))


// *****************************************************************************
//                                                                             *
//  WDT_WDT_IERCLR - WDT Interrupt register                                    *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_1                     : 31;
        unsigned WDT                        :  1;
    } B;
} reg_wdt_wdt_ierclr_t;

#define REG_WDT_WDT_IERCLR_ADDR                 (REG_WDT_BASEADDR + 0x00000208UL)
#define REG_WDT_WDT_IERCLR                      (*(volatile reg_wdt_wdt_ierclr_t *) REG_WDT_WDT_IERCLR_ADDR)
#define REG_WDT_WDT_IERCLR_RD()                 (REG_WDT_WDT_IERCLR.U32)
#define REG_WDT_WDT_IERCLR_WR(v)                (REG_WDT_WDT_IERCLR.U32 = (v))
#define REG_WDT_WDT_IERCLR_CLR(m)               (REG_WDT_WDT_IERCLR.U32 = ((REG_WDT_WDT_IERCLR.U32) & ~(m)))
#define REG_WDT_WDT_IERCLR_SET(m)               (REG_WDT_WDT_IERCLR.U32 = ((REG_WDT_WDT_IERCLR.U32) | (m)))
#define REG_WDT_WDT_IERCLR_DEF                  0x00000000

#define BFP_WDT_WDT_IERCLR_RSVD_1               (1)                     /* bitfield lsb */
#define BFM_WDT_WDT_IERCLR_RSVD_1               ((uint32_t)0xfffffffe)  /* bitfield mask */
#define BFN_WDT_WDT_IERCLR_RSVD_1               (31)                    /* bitfield width */
#define BFD_WDT_WDT_IERCLR_RSVD_1               (0x0)                   /* bitfield default value */
#define BFV_WDT_WDT_IERCLR_RSVD_1(v)            ((((uint32_t) v) << (BFP_WDT_WDT_IERCLR_RSVD_1)) & (BFM_WDT_WDT_IERCLR_RSVD_1))
#define BFX_WDT_WDT_IERCLR_RSVD_1(v)            ((((uint32_t) v) & (BFM_WDT_WDT_IERCLR_RSVD_1)) >> (BFP_WDT_WDT_IERCLR_RSVD_1))
#define BFW_WDT_WDT_IERCLR_RSVD_1(v)            (REG_WDT_WDT_IERCLR.U32 = ( (((uint32_t) v)<<(BFP_WDT_WDT_IERCLR_RSVD_1)) & (BFM_WDT_WDT_IERCLR_RSVD_1)) )
#define BFR_WDT_WDT_IERCLR_RSVD_1()             ((REG_WDT_WDT_IERCLR.U32 & (BFM_WDT_WDT_IERCLR_RSVD_1))>>(BFP_WDT_WDT_IERCLR_RSVD_1))

#define BFP_WDT_WDT_IERCLR_WDT                  (0)                     /* bitfield lsb */
#define BFM_WDT_WDT_IERCLR_WDT                  ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_WDT_WDT_IERCLR_WDT                  (1)                     /* bitfield width */
#define BFD_WDT_WDT_IERCLR_WDT                  (0x0)                   /* bitfield default value */
#define BFV_WDT_WDT_IERCLR_WDT(v)               ((((uint32_t) v) << (BFP_WDT_WDT_IERCLR_WDT)) & (BFM_WDT_WDT_IERCLR_WDT))
#define BFX_WDT_WDT_IERCLR_WDT(v)               ((((uint32_t) v) & (BFM_WDT_WDT_IERCLR_WDT)) >> (BFP_WDT_WDT_IERCLR_WDT))
#define BFW_WDT_WDT_IERCLR_WDT(v)               (REG_WDT_WDT_IERCLR.U32 = ( (((uint32_t) v)<<(BFP_WDT_WDT_IERCLR_WDT)) & (BFM_WDT_WDT_IERCLR_WDT)) )
#define BFR_WDT_WDT_IERCLR_WDT()                ((REG_WDT_WDT_IERCLR.U32 & (BFM_WDT_WDT_IERCLR_WDT))>>(BFP_WDT_WDT_IERCLR_WDT))


// *****************************************************************************
//                                                                             *
//  WDT_WDT_IERSET - WDT Interrupt register                                    *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_1                     : 31;
        unsigned WDT                        :  1;
    } B;
} reg_wdt_wdt_ierset_t;

#define REG_WDT_WDT_IERSET_ADDR                 (REG_WDT_BASEADDR + 0x0000020CUL)
#define REG_WDT_WDT_IERSET                      (*(volatile reg_wdt_wdt_ierset_t *) REG_WDT_WDT_IERSET_ADDR)
#define REG_WDT_WDT_IERSET_RD()                 (REG_WDT_WDT_IERSET.U32)
#define REG_WDT_WDT_IERSET_WR(v)                (REG_WDT_WDT_IERSET.U32 = (v))
#define REG_WDT_WDT_IERSET_CLR(m)               (REG_WDT_WDT_IERSET.U32 = ((REG_WDT_WDT_IERSET.U32) & ~(m)))
#define REG_WDT_WDT_IERSET_SET(m)               (REG_WDT_WDT_IERSET.U32 = ((REG_WDT_WDT_IERSET.U32) | (m)))
#define REG_WDT_WDT_IERSET_DEF                  0x00000000

#define BFP_WDT_WDT_IERSET_RSVD_1               (1)                     /* bitfield lsb */
#define BFM_WDT_WDT_IERSET_RSVD_1               ((uint32_t)0xfffffffe)  /* bitfield mask */
#define BFN_WDT_WDT_IERSET_RSVD_1               (31)                    /* bitfield width */
#define BFD_WDT_WDT_IERSET_RSVD_1               (0x0)                   /* bitfield default value */
#define BFV_WDT_WDT_IERSET_RSVD_1(v)            ((((uint32_t) v) << (BFP_WDT_WDT_IERSET_RSVD_1)) & (BFM_WDT_WDT_IERSET_RSVD_1))
#define BFX_WDT_WDT_IERSET_RSVD_1(v)            ((((uint32_t) v) & (BFM_WDT_WDT_IERSET_RSVD_1)) >> (BFP_WDT_WDT_IERSET_RSVD_1))
#define BFW_WDT_WDT_IERSET_RSVD_1(v)            (REG_WDT_WDT_IERSET.U32 = ( (((uint32_t) v)<<(BFP_WDT_WDT_IERSET_RSVD_1)) & (BFM_WDT_WDT_IERSET_RSVD_1)) )
#define BFR_WDT_WDT_IERSET_RSVD_1()             ((REG_WDT_WDT_IERSET.U32 & (BFM_WDT_WDT_IERSET_RSVD_1))>>(BFP_WDT_WDT_IERSET_RSVD_1))

#define BFP_WDT_WDT_IERSET_WDT                  (0)                     /* bitfield lsb */
#define BFM_WDT_WDT_IERSET_WDT                  ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_WDT_WDT_IERSET_WDT                  (1)                     /* bitfield width */
#define BFD_WDT_WDT_IERSET_WDT                  (0x0)                   /* bitfield default value */
#define BFV_WDT_WDT_IERSET_WDT(v)               ((((uint32_t) v) << (BFP_WDT_WDT_IERSET_WDT)) & (BFM_WDT_WDT_IERSET_WDT))
#define BFX_WDT_WDT_IERSET_WDT(v)               ((((uint32_t) v) & (BFM_WDT_WDT_IERSET_WDT)) >> (BFP_WDT_WDT_IERSET_WDT))
#define BFW_WDT_WDT_IERSET_WDT(v)               (REG_WDT_WDT_IERSET.U32 = ( (((uint32_t) v)<<(BFP_WDT_WDT_IERSET_WDT)) & (BFM_WDT_WDT_IERSET_WDT)) )
#define BFR_WDT_WDT_IERSET_WDT()                ((REG_WDT_WDT_IERSET.U32 & (BFM_WDT_WDT_IERSET_WDT))>>(BFP_WDT_WDT_IERSET_WDT))


#endif  // __WDT_H

