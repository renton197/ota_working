/*******************************************************************************
*                                                                              *
*   File:       clk_gen.h                                                 *
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


#ifndef __CLK_GEN_H
#define __CLK_GEN_H

#include "../am_mcu_apollo.h"



// *****************************************************************************
//                                                                             *
//  CLK_GEN_CALXT - XT Oscillator Control                                      *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_11                    : 21;
        unsigned CALXT                      : 11;
    } B;
} reg_clk_gen_calxt_t;

#define REG_CLK_GEN_CALXT_ADDR                  (REG_CLKGEN_BASEADDR + 0x00000000UL)
#define REG_CLK_GEN_CALXT                       (*(volatile reg_clk_gen_calxt_t *) REG_CLK_GEN_CALXT_ADDR)
#define REG_CLK_GEN_CALXT_RD()                  (REG_CLK_GEN_CALXT.U32)
#define REG_CLK_GEN_CALXT_WR(v)                 (REG_CLK_GEN_CALXT.U32 = (v))
#define REG_CLK_GEN_CALXT_CLR(m)                (REG_CLK_GEN_CALXT.U32 = ((REG_CLK_GEN_CALXT.U32) & ~(m)))
#define REG_CLK_GEN_CALXT_SET(m)                (REG_CLK_GEN_CALXT.U32 = ((REG_CLK_GEN_CALXT.U32) | (m)))
#define REG_CLK_GEN_CALXT_DEF                   0x00000000

#define BFP_CLK_GEN_CALXT_RSVD_11               (11)                    /* bitfield lsb */
#define BFM_CLK_GEN_CALXT_RSVD_11               ((uint32_t)0xfffff800)  /* bitfield mask */
#define BFN_CLK_GEN_CALXT_RSVD_11               (21)                    /* bitfield width */
#define BFD_CLK_GEN_CALXT_RSVD_11               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CALXT_RSVD_11(v)            ((((uint32_t) v) << (BFP_CLK_GEN_CALXT_RSVD_11)) & (BFM_CLK_GEN_CALXT_RSVD_11))
#define BFX_CLK_GEN_CALXT_RSVD_11(v)            ((((uint32_t) v) & (BFM_CLK_GEN_CALXT_RSVD_11)) >> (BFP_CLK_GEN_CALXT_RSVD_11))
#define BFW_CLK_GEN_CALXT_RSVD_11(v)            (REG_CLK_GEN_CALXT.U32 = ( (((uint32_t) v)<<(BFP_CLK_GEN_CALXT_RSVD_11)) & (BFM_CLK_GEN_CALXT_RSVD_11)) )
#define BFR_CLK_GEN_CALXT_RSVD_11()             ((REG_CLK_GEN_CALXT.U32 & (BFM_CLK_GEN_CALXT_RSVD_11))>>(BFP_CLK_GEN_CALXT_RSVD_11))

#define BFP_CLK_GEN_CALXT_CALXT                 (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_CALXT_CALXT                 ((uint32_t)0x000007ff)  /* bitfield mask */
#define BFN_CLK_GEN_CALXT_CALXT                 (11)                    /* bitfield width */
#define BFD_CLK_GEN_CALXT_CALXT                 (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CALXT_CALXT(v)              ((((uint32_t) v) << (BFP_CLK_GEN_CALXT_CALXT)) & (BFM_CLK_GEN_CALXT_CALXT))
#define BFX_CLK_GEN_CALXT_CALXT(v)              ((((uint32_t) v) & (BFM_CLK_GEN_CALXT_CALXT)) >> (BFP_CLK_GEN_CALXT_CALXT))
#define BFW_CLK_GEN_CALXT_CALXT(v)              (REG_CLK_GEN_CALXT.U32 = ( (((uint32_t) v)<<(BFP_CLK_GEN_CALXT_CALXT)) & (BFM_CLK_GEN_CALXT_CALXT)) )
#define BFR_CLK_GEN_CALXT_CALXT()               ((REG_CLK_GEN_CALXT.U32 & (BFM_CLK_GEN_CALXT_CALXT))>>(BFP_CLK_GEN_CALXT_CALXT))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_CALRC - RC Oscillator Control                                      *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_18                    : 14;
        unsigned CALRC                      : 18;
    } B;
} reg_clk_gen_calrc_t;

#define REG_CLK_GEN_CALRC_ADDR                  (REG_CLKGEN_BASEADDR + 0x00000004UL)
#define REG_CLK_GEN_CALRC                       (*(volatile reg_clk_gen_calrc_t *) REG_CLK_GEN_CALRC_ADDR)
#define REG_CLK_GEN_CALRC_RD()                  (REG_CLK_GEN_CALRC.U32)
#define REG_CLK_GEN_CALRC_WR(v)                 (REG_CLK_GEN_CALRC.U32 = (v))
#define REG_CLK_GEN_CALRC_CLR(m)                (REG_CLK_GEN_CALRC.U32 = ((REG_CLK_GEN_CALRC.U32) & ~(m)))
#define REG_CLK_GEN_CALRC_SET(m)                (REG_CLK_GEN_CALRC.U32 = ((REG_CLK_GEN_CALRC.U32) | (m)))
#define REG_CLK_GEN_CALRC_DEF                   0x00000000

#define BFP_CLK_GEN_CALRC_RSVD_18               (18)                    /* bitfield lsb */
#define BFM_CLK_GEN_CALRC_RSVD_18               ((uint32_t)0xfffc0000)  /* bitfield mask */
#define BFN_CLK_GEN_CALRC_RSVD_18               (14)                    /* bitfield width */
#define BFD_CLK_GEN_CALRC_RSVD_18               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CALRC_RSVD_18(v)            ((((uint32_t) v) << (BFP_CLK_GEN_CALRC_RSVD_18)) & (BFM_CLK_GEN_CALRC_RSVD_18))
#define BFX_CLK_GEN_CALRC_RSVD_18(v)            ((((uint32_t) v) & (BFM_CLK_GEN_CALRC_RSVD_18)) >> (BFP_CLK_GEN_CALRC_RSVD_18))
#define BFW_CLK_GEN_CALRC_RSVD_18(v)            (REG_CLK_GEN_CALRC.U32 = ( (((uint32_t) v)<<(BFP_CLK_GEN_CALRC_RSVD_18)) & (BFM_CLK_GEN_CALRC_RSVD_18)) )
#define BFR_CLK_GEN_CALRC_RSVD_18()             ((REG_CLK_GEN_CALRC.U32 & (BFM_CLK_GEN_CALRC_RSVD_18))>>(BFP_CLK_GEN_CALRC_RSVD_18))

#define BFP_CLK_GEN_CALRC_CALRC                 (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_CALRC_CALRC                 ((uint32_t)0x0003ffff)  /* bitfield mask */
#define BFN_CLK_GEN_CALRC_CALRC                 (18)                    /* bitfield width */
#define BFD_CLK_GEN_CALRC_CALRC                 (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CALRC_CALRC(v)              ((((uint32_t) v) << (BFP_CLK_GEN_CALRC_CALRC)) & (BFM_CLK_GEN_CALRC_CALRC))
#define BFX_CLK_GEN_CALRC_CALRC(v)              ((((uint32_t) v) & (BFM_CLK_GEN_CALRC_CALRC)) >> (BFP_CLK_GEN_CALRC_CALRC))
#define BFW_CLK_GEN_CALRC_CALRC(v)              (REG_CLK_GEN_CALRC.U32 = ( (((uint32_t) v)<<(BFP_CLK_GEN_CALRC_CALRC)) & (BFM_CLK_GEN_CALRC_CALRC)) )
#define BFR_CLK_GEN_CALRC_CALRC()               ((REG_CLK_GEN_CALRC.U32 & (BFM_CLK_GEN_CALRC_CALRC))>>(BFP_CLK_GEN_CALRC_CALRC))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_ACALCTR - Autocalibration Counter                                  *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_24                    :  8;
        unsigned ACALCTR                    : 24;
    } B;
} reg_clk_gen_acalctr_t;

#define REG_CLK_GEN_ACALCTR_ADDR                (REG_CLKGEN_BASEADDR + 0x00000008UL)
#define REG_CLK_GEN_ACALCTR                     (*(volatile reg_clk_gen_acalctr_t *) REG_CLK_GEN_ACALCTR_ADDR)
#define REG_CLK_GEN_ACALCTR_RD()                (REG_CLK_GEN_ACALCTR.U32)
#define REG_CLK_GEN_ACALCTR_WR(v)               (REG_CLK_GEN_ACALCTR.U32 = (v))
#define REG_CLK_GEN_ACALCTR_CLR(m)              (REG_CLK_GEN_ACALCTR.U32 = ((REG_CLK_GEN_ACALCTR.U32) & ~(m)))
#define REG_CLK_GEN_ACALCTR_SET(m)              (REG_CLK_GEN_ACALCTR.U32 = ((REG_CLK_GEN_ACALCTR.U32) | (m)))
#define REG_CLK_GEN_ACALCTR_DEF                 0x00000000

#define BFP_CLK_GEN_ACALCTR_RSVD_24             (24)                    /* bitfield lsb */
#define BFM_CLK_GEN_ACALCTR_RSVD_24             ((uint32_t)0xff000000)  /* bitfield mask */
#define BFN_CLK_GEN_ACALCTR_RSVD_24             (8)                     /* bitfield width */
#define BFD_CLK_GEN_ACALCTR_RSVD_24             (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_ACALCTR_RSVD_24(v)          ((((uint32_t) v) << (BFP_CLK_GEN_ACALCTR_RSVD_24)) & (BFM_CLK_GEN_ACALCTR_RSVD_24))
#define BFX_CLK_GEN_ACALCTR_RSVD_24(v)          ((((uint32_t) v) & (BFM_CLK_GEN_ACALCTR_RSVD_24)) >> (BFP_CLK_GEN_ACALCTR_RSVD_24))
#define BFW_CLK_GEN_ACALCTR_RSVD_24(v)          (REG_CLK_GEN_ACALCTR.U32 = ( (((uint32_t) v)<<(BFP_CLK_GEN_ACALCTR_RSVD_24)) & (BFM_CLK_GEN_ACALCTR_RSVD_24)) )
#define BFR_CLK_GEN_ACALCTR_RSVD_24()           ((REG_CLK_GEN_ACALCTR.U32 & (BFM_CLK_GEN_ACALCTR_RSVD_24))>>(BFP_CLK_GEN_ACALCTR_RSVD_24))

#define BFP_CLK_GEN_ACALCTR_ACALCTR             (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_ACALCTR_ACALCTR             ((uint32_t)0x00ffffff)  /* bitfield mask */
#define BFN_CLK_GEN_ACALCTR_ACALCTR             (24)                    /* bitfield width */
#define BFD_CLK_GEN_ACALCTR_ACALCTR             (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_ACALCTR_ACALCTR(v)          ((((uint32_t) v) << (BFP_CLK_GEN_ACALCTR_ACALCTR)) & (BFM_CLK_GEN_ACALCTR_ACALCTR))
#define BFX_CLK_GEN_ACALCTR_ACALCTR(v)          ((((uint32_t) v) & (BFM_CLK_GEN_ACALCTR_ACALCTR)) >> (BFP_CLK_GEN_ACALCTR_ACALCTR))
#define BFW_CLK_GEN_ACALCTR_ACALCTR(v)          (REG_CLK_GEN_ACALCTR.U32 = ( (((uint32_t) v)<<(BFP_CLK_GEN_ACALCTR_ACALCTR)) & (BFM_CLK_GEN_ACALCTR_ACALCTR)) )
#define BFR_CLK_GEN_ACALCTR_ACALCTR()           ((REG_CLK_GEN_ACALCTR.U32 & (BFM_CLK_GEN_ACALCTR_ACALCTR))>>(BFP_CLK_GEN_ACALCTR_ACALCTR))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_OCTRL - Oscillator Control                                         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_11                    : 21;
        unsigned ACAL                       :  3;
        unsigned OSEL                       :  1;
        unsigned FOS                        :  1;
        unsigned RSVD_2                     :  4;
        unsigned STOPRC                     :  1;
        unsigned STOPXT                     :  1;
    } B;
} reg_clk_gen_octrl_t;

#define REG_CLK_GEN_OCTRL_ADDR                  (REG_CLKGEN_BASEADDR + 0x0000000CUL)
#define REG_CLK_GEN_OCTRL                       (*(volatile reg_clk_gen_octrl_t *) REG_CLK_GEN_OCTRL_ADDR)
#define REG_CLK_GEN_OCTRL_RD()                  (REG_CLK_GEN_OCTRL.U32)
#define REG_CLK_GEN_OCTRL_WR(v)                 (REG_CLK_GEN_OCTRL.U32 = (v))
#define REG_CLK_GEN_OCTRL_CLR(m)                (REG_CLK_GEN_OCTRL.U32 = ((REG_CLK_GEN_OCTRL.U32) & ~(m)))
#define REG_CLK_GEN_OCTRL_SET(m)                (REG_CLK_GEN_OCTRL.U32 = ((REG_CLK_GEN_OCTRL.U32) | (m)))
#define REG_CLK_GEN_OCTRL_DEF                   0x00000000

#define BFP_CLK_GEN_OCTRL_RSVD_11               (11)                    /* bitfield lsb */
#define BFM_CLK_GEN_OCTRL_RSVD_11               ((uint32_t)0xfffff800)  /* bitfield mask */
#define BFN_CLK_GEN_OCTRL_RSVD_11               (21)                    /* bitfield width */
#define BFD_CLK_GEN_OCTRL_RSVD_11               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_OCTRL_RSVD_11(v)            ((((uint32_t) v) << (BFP_CLK_GEN_OCTRL_RSVD_11)) & (BFM_CLK_GEN_OCTRL_RSVD_11))
#define BFX_CLK_GEN_OCTRL_RSVD_11(v)            ((((uint32_t) v) & (BFM_CLK_GEN_OCTRL_RSVD_11)) >> (BFP_CLK_GEN_OCTRL_RSVD_11))
#define BFW_CLK_GEN_OCTRL_RSVD_11(v)            (REG_CLK_GEN_OCTRL.U32 = ( (REG_CLK_GEN_OCTRL.U32 & ~(BFM_CLK_GEN_OCTRL_RSVD_11)) | ((((uint32_t) v)<<(BFP_CLK_GEN_OCTRL_RSVD_11)) & (BFM_CLK_GEN_OCTRL_RSVD_11)) ))
#define BFR_CLK_GEN_OCTRL_RSVD_11()             ((REG_CLK_GEN_OCTRL.U32 & (BFM_CLK_GEN_OCTRL_RSVD_11))>>(BFP_CLK_GEN_OCTRL_RSVD_11))

#define BFP_CLK_GEN_OCTRL_ACAL                  (8)                     /* bitfield lsb */
#define BFM_CLK_GEN_OCTRL_ACAL                  ((uint32_t)0x00000700)  /* bitfield mask */
#define BFN_CLK_GEN_OCTRL_ACAL                  (3)                     /* bitfield width */
#define BFD_CLK_GEN_OCTRL_ACAL                  (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_OCTRL_ACAL(v)               ((((uint32_t) v) << (BFP_CLK_GEN_OCTRL_ACAL)) & (BFM_CLK_GEN_OCTRL_ACAL))
#define BFX_CLK_GEN_OCTRL_ACAL(v)               ((((uint32_t) v) & (BFM_CLK_GEN_OCTRL_ACAL)) >> (BFP_CLK_GEN_OCTRL_ACAL))
#define BFW_CLK_GEN_OCTRL_ACAL(v)               (REG_CLK_GEN_OCTRL.U32 = ( (REG_CLK_GEN_OCTRL.U32 & ~(BFM_CLK_GEN_OCTRL_ACAL)) | ((((uint32_t) v)<<(BFP_CLK_GEN_OCTRL_ACAL)) & (BFM_CLK_GEN_OCTRL_ACAL)) ))
#define BFR_CLK_GEN_OCTRL_ACAL()                ((REG_CLK_GEN_OCTRL.U32 & (BFM_CLK_GEN_OCTRL_ACAL))>>(BFP_CLK_GEN_OCTRL_ACAL))

#define BFP_CLK_GEN_OCTRL_OSEL                  (7)                     /* bitfield lsb */
#define BFM_CLK_GEN_OCTRL_OSEL                  ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_CLK_GEN_OCTRL_OSEL                  (1)                     /* bitfield width */
#define BFD_CLK_GEN_OCTRL_OSEL                  (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_OCTRL_OSEL(v)               ((((uint32_t) v) << (BFP_CLK_GEN_OCTRL_OSEL)) & (BFM_CLK_GEN_OCTRL_OSEL))
#define BFX_CLK_GEN_OCTRL_OSEL(v)               ((((uint32_t) v) & (BFM_CLK_GEN_OCTRL_OSEL)) >> (BFP_CLK_GEN_OCTRL_OSEL))
#define BFW_CLK_GEN_OCTRL_OSEL(v)               (REG_CLK_GEN_OCTRL.U32 = ( (REG_CLK_GEN_OCTRL.U32 & ~(BFM_CLK_GEN_OCTRL_OSEL)) | ((((uint32_t) v)<<(BFP_CLK_GEN_OCTRL_OSEL)) & (BFM_CLK_GEN_OCTRL_OSEL)) ))
#define BFR_CLK_GEN_OCTRL_OSEL()                ((REG_CLK_GEN_OCTRL.U32 & (BFM_CLK_GEN_OCTRL_OSEL))>>(BFP_CLK_GEN_OCTRL_OSEL))

#define BFP_CLK_GEN_OCTRL_FOS                   (6)                     /* bitfield lsb */
#define BFM_CLK_GEN_OCTRL_FOS                   ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_CLK_GEN_OCTRL_FOS                   (1)                     /* bitfield width */
#define BFD_CLK_GEN_OCTRL_FOS                   (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_OCTRL_FOS(v)                ((((uint32_t) v) << (BFP_CLK_GEN_OCTRL_FOS)) & (BFM_CLK_GEN_OCTRL_FOS))
#define BFX_CLK_GEN_OCTRL_FOS(v)                ((((uint32_t) v) & (BFM_CLK_GEN_OCTRL_FOS)) >> (BFP_CLK_GEN_OCTRL_FOS))
#define BFW_CLK_GEN_OCTRL_FOS(v)                (REG_CLK_GEN_OCTRL.U32 = ( (REG_CLK_GEN_OCTRL.U32 & ~(BFM_CLK_GEN_OCTRL_FOS)) | ((((uint32_t) v)<<(BFP_CLK_GEN_OCTRL_FOS)) & (BFM_CLK_GEN_OCTRL_FOS)) ))
#define BFR_CLK_GEN_OCTRL_FOS()                 ((REG_CLK_GEN_OCTRL.U32 & (BFM_CLK_GEN_OCTRL_FOS))>>(BFP_CLK_GEN_OCTRL_FOS))

#define BFP_CLK_GEN_OCTRL_RSVD_2                (2)                     /* bitfield lsb */
#define BFM_CLK_GEN_OCTRL_RSVD_2                ((uint32_t)0x0000003c)  /* bitfield mask */
#define BFN_CLK_GEN_OCTRL_RSVD_2                (4)                     /* bitfield width */
#define BFD_CLK_GEN_OCTRL_RSVD_2                (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_OCTRL_RSVD_2(v)             ((((uint32_t) v) << (BFP_CLK_GEN_OCTRL_RSVD_2)) & (BFM_CLK_GEN_OCTRL_RSVD_2))
#define BFX_CLK_GEN_OCTRL_RSVD_2(v)             ((((uint32_t) v) & (BFM_CLK_GEN_OCTRL_RSVD_2)) >> (BFP_CLK_GEN_OCTRL_RSVD_2))
#define BFW_CLK_GEN_OCTRL_RSVD_2(v)             (REG_CLK_GEN_OCTRL.U32 = ( (REG_CLK_GEN_OCTRL.U32 & ~(BFM_CLK_GEN_OCTRL_RSVD_2)) | ((((uint32_t) v)<<(BFP_CLK_GEN_OCTRL_RSVD_2)) & (BFM_CLK_GEN_OCTRL_RSVD_2)) ))
#define BFR_CLK_GEN_OCTRL_RSVD_2()              ((REG_CLK_GEN_OCTRL.U32 & (BFM_CLK_GEN_OCTRL_RSVD_2))>>(BFP_CLK_GEN_OCTRL_RSVD_2))

#define BFP_CLK_GEN_OCTRL_STOPRC                (1)                     /* bitfield lsb */
#define BFM_CLK_GEN_OCTRL_STOPRC                ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CLK_GEN_OCTRL_STOPRC                (1)                     /* bitfield width */
#define BFD_CLK_GEN_OCTRL_STOPRC                (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_OCTRL_STOPRC(v)             ((((uint32_t) v) << (BFP_CLK_GEN_OCTRL_STOPRC)) & (BFM_CLK_GEN_OCTRL_STOPRC))
#define BFX_CLK_GEN_OCTRL_STOPRC(v)             ((((uint32_t) v) & (BFM_CLK_GEN_OCTRL_STOPRC)) >> (BFP_CLK_GEN_OCTRL_STOPRC))
#define BFW_CLK_GEN_OCTRL_STOPRC(v)             (REG_CLK_GEN_OCTRL.U32 = ( (REG_CLK_GEN_OCTRL.U32 & ~(BFM_CLK_GEN_OCTRL_STOPRC)) | ((((uint32_t) v)<<(BFP_CLK_GEN_OCTRL_STOPRC)) & (BFM_CLK_GEN_OCTRL_STOPRC)) ))
#define BFR_CLK_GEN_OCTRL_STOPRC()              ((REG_CLK_GEN_OCTRL.U32 & (BFM_CLK_GEN_OCTRL_STOPRC))>>(BFP_CLK_GEN_OCTRL_STOPRC))

#define BFP_CLK_GEN_OCTRL_STOPXT                (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_OCTRL_STOPXT                ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CLK_GEN_OCTRL_STOPXT                (1)                     /* bitfield width */
#define BFD_CLK_GEN_OCTRL_STOPXT                (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_OCTRL_STOPXT(v)             ((((uint32_t) v) << (BFP_CLK_GEN_OCTRL_STOPXT)) & (BFM_CLK_GEN_OCTRL_STOPXT))
#define BFX_CLK_GEN_OCTRL_STOPXT(v)             ((((uint32_t) v) & (BFM_CLK_GEN_OCTRL_STOPXT)) >> (BFP_CLK_GEN_OCTRL_STOPXT))
#define BFW_CLK_GEN_OCTRL_STOPXT(v)             (REG_CLK_GEN_OCTRL.U32 = ( (REG_CLK_GEN_OCTRL.U32 & ~(BFM_CLK_GEN_OCTRL_STOPXT)) | ((((uint32_t) v)<<(BFP_CLK_GEN_OCTRL_STOPXT)) & (BFM_CLK_GEN_OCTRL_STOPXT)) ))
#define BFR_CLK_GEN_OCTRL_STOPXT()              ((REG_CLK_GEN_OCTRL.U32 & (BFM_CLK_GEN_OCTRL_STOPXT))>>(BFP_CLK_GEN_OCTRL_STOPXT))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_CLKOUT - CLKOUT Frequency Select                                   *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_8                     : 24;
        unsigned CKEN                       :  1;
        unsigned RSVD_6                     :  1;
        unsigned CKSEL                      :  6;
    } B;
} reg_clk_gen_clkout_t;

#define REG_CLK_GEN_CLKOUT_ADDR                 (REG_CLKGEN_BASEADDR + 0x00000010UL)
#define REG_CLK_GEN_CLKOUT                      (*(volatile reg_clk_gen_clkout_t *) REG_CLK_GEN_CLKOUT_ADDR)
#define REG_CLK_GEN_CLKOUT_RD()                 (REG_CLK_GEN_CLKOUT.U32)
#define REG_CLK_GEN_CLKOUT_WR(v)                (REG_CLK_GEN_CLKOUT.U32 = (v))
#define REG_CLK_GEN_CLKOUT_CLR(m)               (REG_CLK_GEN_CLKOUT.U32 = ((REG_CLK_GEN_CLKOUT.U32) & ~(m)))
#define REG_CLK_GEN_CLKOUT_SET(m)               (REG_CLK_GEN_CLKOUT.U32 = ((REG_CLK_GEN_CLKOUT.U32) | (m)))
#define REG_CLK_GEN_CLKOUT_DEF                  0x00000000

#define BFP_CLK_GEN_CLKOUT_RSVD_8               (8)                     /* bitfield lsb */
#define BFM_CLK_GEN_CLKOUT_RSVD_8               ((uint32_t)0xffffff00)  /* bitfield mask */
#define BFN_CLK_GEN_CLKOUT_RSVD_8               (24)                    /* bitfield width */
#define BFD_CLK_GEN_CLKOUT_RSVD_8               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CLKOUT_RSVD_8(v)            ((((uint32_t) v) << (BFP_CLK_GEN_CLKOUT_RSVD_8)) & (BFM_CLK_GEN_CLKOUT_RSVD_8))
#define BFX_CLK_GEN_CLKOUT_RSVD_8(v)            ((((uint32_t) v) & (BFM_CLK_GEN_CLKOUT_RSVD_8)) >> (BFP_CLK_GEN_CLKOUT_RSVD_8))
#define BFW_CLK_GEN_CLKOUT_RSVD_8(v)            (REG_CLK_GEN_CLKOUT.U32 = ( (REG_CLK_GEN_CLKOUT.U32 & ~(BFM_CLK_GEN_CLKOUT_RSVD_8)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CLKOUT_RSVD_8)) & (BFM_CLK_GEN_CLKOUT_RSVD_8)) ))
#define BFR_CLK_GEN_CLKOUT_RSVD_8()             ((REG_CLK_GEN_CLKOUT.U32 & (BFM_CLK_GEN_CLKOUT_RSVD_8))>>(BFP_CLK_GEN_CLKOUT_RSVD_8))

#define BFP_CLK_GEN_CLKOUT_CKEN                 (7)                     /* bitfield lsb */
#define BFM_CLK_GEN_CLKOUT_CKEN                 ((uint32_t)0x00000080)  /* bitfield mask */
#define BFN_CLK_GEN_CLKOUT_CKEN                 (1)                     /* bitfield width */
#define BFD_CLK_GEN_CLKOUT_CKEN                 (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CLKOUT_CKEN(v)              ((((uint32_t) v) << (BFP_CLK_GEN_CLKOUT_CKEN)) & (BFM_CLK_GEN_CLKOUT_CKEN))
#define BFX_CLK_GEN_CLKOUT_CKEN(v)              ((((uint32_t) v) & (BFM_CLK_GEN_CLKOUT_CKEN)) >> (BFP_CLK_GEN_CLKOUT_CKEN))
#define BFW_CLK_GEN_CLKOUT_CKEN(v)              (REG_CLK_GEN_CLKOUT.U32 = ( (REG_CLK_GEN_CLKOUT.U32 & ~(BFM_CLK_GEN_CLKOUT_CKEN)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CLKOUT_CKEN)) & (BFM_CLK_GEN_CLKOUT_CKEN)) ))
#define BFR_CLK_GEN_CLKOUT_CKEN()               ((REG_CLK_GEN_CLKOUT.U32 & (BFM_CLK_GEN_CLKOUT_CKEN))>>(BFP_CLK_GEN_CLKOUT_CKEN))

#define BFP_CLK_GEN_CLKOUT_RSVD_6               (6)                     /* bitfield lsb */
#define BFM_CLK_GEN_CLKOUT_RSVD_6               ((uint32_t)0x00000040)  /* bitfield mask */
#define BFN_CLK_GEN_CLKOUT_RSVD_6               (1)                     /* bitfield width */
#define BFD_CLK_GEN_CLKOUT_RSVD_6               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CLKOUT_RSVD_6(v)            ((((uint32_t) v) << (BFP_CLK_GEN_CLKOUT_RSVD_6)) & (BFM_CLK_GEN_CLKOUT_RSVD_6))
#define BFX_CLK_GEN_CLKOUT_RSVD_6(v)            ((((uint32_t) v) & (BFM_CLK_GEN_CLKOUT_RSVD_6)) >> (BFP_CLK_GEN_CLKOUT_RSVD_6))
#define BFW_CLK_GEN_CLKOUT_RSVD_6(v)            (REG_CLK_GEN_CLKOUT.U32 = ( (REG_CLK_GEN_CLKOUT.U32 & ~(BFM_CLK_GEN_CLKOUT_RSVD_6)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CLKOUT_RSVD_6)) & (BFM_CLK_GEN_CLKOUT_RSVD_6)) ))
#define BFR_CLK_GEN_CLKOUT_RSVD_6()             ((REG_CLK_GEN_CLKOUT.U32 & (BFM_CLK_GEN_CLKOUT_RSVD_6))>>(BFP_CLK_GEN_CLKOUT_RSVD_6))

#define BFP_CLK_GEN_CLKOUT_CKSEL                (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_CLKOUT_CKSEL                ((uint32_t)0x0000003f)  /* bitfield mask */
#define BFN_CLK_GEN_CLKOUT_CKSEL                (6)                     /* bitfield width */
#define BFD_CLK_GEN_CLKOUT_CKSEL                (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CLKOUT_CKSEL(v)             ((((uint32_t) v) << (BFP_CLK_GEN_CLKOUT_CKSEL)) & (BFM_CLK_GEN_CLKOUT_CKSEL))
#define BFX_CLK_GEN_CLKOUT_CKSEL(v)             ((((uint32_t) v) & (BFM_CLK_GEN_CLKOUT_CKSEL)) >> (BFP_CLK_GEN_CLKOUT_CKSEL))
#define BFW_CLK_GEN_CLKOUT_CKSEL(v)             (REG_CLK_GEN_CLKOUT.U32 = ( (REG_CLK_GEN_CLKOUT.U32 & ~(BFM_CLK_GEN_CLKOUT_CKSEL)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CLKOUT_CKSEL)) & (BFM_CLK_GEN_CLKOUT_CKSEL)) ))
#define BFR_CLK_GEN_CLKOUT_CKSEL()              ((REG_CLK_GEN_CLKOUT.U32 & (BFM_CLK_GEN_CLKOUT_CKSEL))>>(BFP_CLK_GEN_CLKOUT_CKSEL))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_CCTRL - HFRC Clock Control                                         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_4                     : 28;
        unsigned MEMSEL                     :  1;
        unsigned CORESEL                    :  3;
    } B;
} reg_clk_gen_cctrl_t;

#define REG_CLK_GEN_CCTRL_ADDR                  (REG_CLKGEN_BASEADDR + 0x00000018UL)
#define REG_CLK_GEN_CCTRL                       (*(volatile reg_clk_gen_cctrl_t *) REG_CLK_GEN_CCTRL_ADDR)
#define REG_CLK_GEN_CCTRL_RD()                  (REG_CLK_GEN_CCTRL.U32)
#define REG_CLK_GEN_CCTRL_WR(v)                 (REG_CLK_GEN_CCTRL.U32 = (v))
#define REG_CLK_GEN_CCTRL_CLR(m)                (REG_CLK_GEN_CCTRL.U32 = ((REG_CLK_GEN_CCTRL.U32) & ~(m)))
#define REG_CLK_GEN_CCTRL_SET(m)                (REG_CLK_GEN_CCTRL.U32 = ((REG_CLK_GEN_CCTRL.U32) | (m)))
#define REG_CLK_GEN_CCTRL_DEF                   0x00000007

#define BFP_CLK_GEN_CCTRL_RSVD_4                (4)                     /* bitfield lsb */
#define BFM_CLK_GEN_CCTRL_RSVD_4                ((uint32_t)0xfffffff0)  /* bitfield mask */
#define BFN_CLK_GEN_CCTRL_RSVD_4                (28)                    /* bitfield width */
#define BFD_CLK_GEN_CCTRL_RSVD_4                (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CCTRL_RSVD_4(v)             ((((uint32_t) v) << (BFP_CLK_GEN_CCTRL_RSVD_4)) & (BFM_CLK_GEN_CCTRL_RSVD_4))
#define BFX_CLK_GEN_CCTRL_RSVD_4(v)             ((((uint32_t) v) & (BFM_CLK_GEN_CCTRL_RSVD_4)) >> (BFP_CLK_GEN_CCTRL_RSVD_4))
#define BFW_CLK_GEN_CCTRL_RSVD_4(v)             (REG_CLK_GEN_CCTRL.U32 = ( (REG_CLK_GEN_CCTRL.U32 & ~(BFM_CLK_GEN_CCTRL_RSVD_4)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CCTRL_RSVD_4)) & (BFM_CLK_GEN_CCTRL_RSVD_4)) ))
#define BFR_CLK_GEN_CCTRL_RSVD_4()              ((REG_CLK_GEN_CCTRL.U32 & (BFM_CLK_GEN_CCTRL_RSVD_4))>>(BFP_CLK_GEN_CCTRL_RSVD_4))

#define BFP_CLK_GEN_CCTRL_MEMSEL                (3)                     /* bitfield lsb */
#define BFM_CLK_GEN_CCTRL_MEMSEL                ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_CLK_GEN_CCTRL_MEMSEL                (1)                     /* bitfield width */
#define BFD_CLK_GEN_CCTRL_MEMSEL                (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CCTRL_MEMSEL(v)             ((((uint32_t) v) << (BFP_CLK_GEN_CCTRL_MEMSEL)) & (BFM_CLK_GEN_CCTRL_MEMSEL))
#define BFX_CLK_GEN_CCTRL_MEMSEL(v)             ((((uint32_t) v) & (BFM_CLK_GEN_CCTRL_MEMSEL)) >> (BFP_CLK_GEN_CCTRL_MEMSEL))
#define BFW_CLK_GEN_CCTRL_MEMSEL(v)             (REG_CLK_GEN_CCTRL.U32 = ( (REG_CLK_GEN_CCTRL.U32 & ~(BFM_CLK_GEN_CCTRL_MEMSEL)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CCTRL_MEMSEL)) & (BFM_CLK_GEN_CCTRL_MEMSEL)) ))
#define BFR_CLK_GEN_CCTRL_MEMSEL()              ((REG_CLK_GEN_CCTRL.U32 & (BFM_CLK_GEN_CCTRL_MEMSEL))>>(BFP_CLK_GEN_CCTRL_MEMSEL))

#define BFP_CLK_GEN_CCTRL_CORESEL               (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_CCTRL_CORESEL               ((uint32_t)0x00000007)  /* bitfield mask */
#define BFN_CLK_GEN_CCTRL_CORESEL               (3)                     /* bitfield width */
#define BFD_CLK_GEN_CCTRL_CORESEL               (0x7)                   /* bitfield default value */
#define BFV_CLK_GEN_CCTRL_CORESEL(v)            ((((uint32_t) v) << (BFP_CLK_GEN_CCTRL_CORESEL)) & (BFM_CLK_GEN_CCTRL_CORESEL))
#define BFX_CLK_GEN_CCTRL_CORESEL(v)            ((((uint32_t) v) & (BFM_CLK_GEN_CCTRL_CORESEL)) >> (BFP_CLK_GEN_CCTRL_CORESEL))
#define BFW_CLK_GEN_CCTRL_CORESEL(v)            (REG_CLK_GEN_CCTRL.U32 = ( (REG_CLK_GEN_CCTRL.U32 & ~(BFM_CLK_GEN_CCTRL_CORESEL)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CCTRL_CORESEL)) & (BFM_CLK_GEN_CCTRL_CORESEL)) ))
#define BFR_CLK_GEN_CCTRL_CORESEL()             ((REG_CLK_GEN_CCTRL.U32 & (BFM_CLK_GEN_CCTRL_CORESEL))>>(BFP_CLK_GEN_CCTRL_CORESEL))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_CLKKEY - Key Register for Clock Control Register                   *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_0                     : 32;
    } B;
} reg_clk_gen_clkkey_t;

#define REG_CLK_GEN_CLKKEY_ADDR                 (REG_CLKGEN_BASEADDR + 0x00000014UL)
#define REG_CLK_GEN_CLKKEY                      (*(volatile reg_clk_gen_clkkey_t *) REG_CLK_GEN_CLKKEY_ADDR)
#define REG_CLK_GEN_CLKKEY_RD()                 (REG_CLK_GEN_CLKKEY.U32)
#define REG_CLK_GEN_CLKKEY_WR(v)                (REG_CLK_GEN_CLKKEY.U32 = (v))
#define REG_CLK_GEN_CLKKEY_CLR(m)               (REG_CLK_GEN_CLKKEY.U32 = ((REG_CLK_GEN_CLKKEY.U32) & ~(m)))
#define REG_CLK_GEN_CLKKEY_SET(m)               (REG_CLK_GEN_CLKKEY.U32 = ((REG_CLK_GEN_CLKKEY.U32) | (m)))
#define REG_CLK_GEN_CLKKEY_DEF                  0x00000000


// *****************************************************************************
//                                                                             *
//  CLK_GEN_STATUS - Clock Generator Status                                    *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_2                     : 30;
        unsigned OSCF                       :  1;
        unsigned OMODE                      :  1;
    } B;
} reg_clk_gen_status_t;

#define REG_CLK_GEN_STATUS_ADDR                 (REG_CLKGEN_BASEADDR + 0x0000001CUL)
#define REG_CLK_GEN_STATUS                      (*(volatile reg_clk_gen_status_t *) REG_CLK_GEN_STATUS_ADDR)
#define REG_CLK_GEN_STATUS_RD()                 (REG_CLK_GEN_STATUS.U32)
#define REG_CLK_GEN_STATUS_WR(v)                (REG_CLK_GEN_STATUS.U32 = (v))
#define REG_CLK_GEN_STATUS_CLR(m)               (REG_CLK_GEN_STATUS.U32 = ((REG_CLK_GEN_STATUS.U32) & ~(m)))
#define REG_CLK_GEN_STATUS_SET(m)               (REG_CLK_GEN_STATUS.U32 = ((REG_CLK_GEN_STATUS.U32) | (m)))
#define REG_CLK_GEN_STATUS_DEF                  0x00000000

#define BFP_CLK_GEN_STATUS_RSVD_2               (2)                     /* bitfield lsb */
#define BFM_CLK_GEN_STATUS_RSVD_2               ((uint32_t)0xfffffffc)  /* bitfield mask */
#define BFN_CLK_GEN_STATUS_RSVD_2               (30)                    /* bitfield width */
#define BFD_CLK_GEN_STATUS_RSVD_2               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_STATUS_RSVD_2(v)            ((((uint32_t) v) << (BFP_CLK_GEN_STATUS_RSVD_2)) & (BFM_CLK_GEN_STATUS_RSVD_2))
#define BFX_CLK_GEN_STATUS_RSVD_2(v)            ((((uint32_t) v) & (BFM_CLK_GEN_STATUS_RSVD_2)) >> (BFP_CLK_GEN_STATUS_RSVD_2))
#define BFW_CLK_GEN_STATUS_RSVD_2(v)            (REG_CLK_GEN_STATUS.U32 = ( (REG_CLK_GEN_STATUS.U32 & ~(BFM_CLK_GEN_STATUS_RSVD_2)) | ((((uint32_t) v)<<(BFP_CLK_GEN_STATUS_RSVD_2)) & (BFM_CLK_GEN_STATUS_RSVD_2)) ))
#define BFR_CLK_GEN_STATUS_RSVD_2()             ((REG_CLK_GEN_STATUS.U32 & (BFM_CLK_GEN_STATUS_RSVD_2))>>(BFP_CLK_GEN_STATUS_RSVD_2))

#define BFP_CLK_GEN_STATUS_OSCF                 (1)                     /* bitfield lsb */
#define BFM_CLK_GEN_STATUS_OSCF                 ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CLK_GEN_STATUS_OSCF                 (1)                     /* bitfield width */
#define BFD_CLK_GEN_STATUS_OSCF                 (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_STATUS_OSCF(v)              ((((uint32_t) v) << (BFP_CLK_GEN_STATUS_OSCF)) & (BFM_CLK_GEN_STATUS_OSCF))
#define BFX_CLK_GEN_STATUS_OSCF(v)              ((((uint32_t) v) & (BFM_CLK_GEN_STATUS_OSCF)) >> (BFP_CLK_GEN_STATUS_OSCF))
#define BFW_CLK_GEN_STATUS_OSCF(v)              (REG_CLK_GEN_STATUS.U32 = ( (REG_CLK_GEN_STATUS.U32 & ~(BFM_CLK_GEN_STATUS_OSCF)) | ((((uint32_t) v)<<(BFP_CLK_GEN_STATUS_OSCF)) & (BFM_CLK_GEN_STATUS_OSCF)) ))
#define BFR_CLK_GEN_STATUS_OSCF()               ((REG_CLK_GEN_STATUS.U32 & (BFM_CLK_GEN_STATUS_OSCF))>>(BFP_CLK_GEN_STATUS_OSCF))

#define BFP_CLK_GEN_STATUS_OMODE                (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_STATUS_OMODE                ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CLK_GEN_STATUS_OMODE                (1)                     /* bitfield width */
#define BFD_CLK_GEN_STATUS_OMODE                (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_STATUS_OMODE(v)             ((((uint32_t) v) << (BFP_CLK_GEN_STATUS_OMODE)) & (BFM_CLK_GEN_STATUS_OMODE))
#define BFX_CLK_GEN_STATUS_OMODE(v)             ((((uint32_t) v) & (BFM_CLK_GEN_STATUS_OMODE)) >> (BFP_CLK_GEN_STATUS_OMODE))
#define BFW_CLK_GEN_STATUS_OMODE(v)             (REG_CLK_GEN_STATUS.U32 = ( (REG_CLK_GEN_STATUS.U32 & ~(BFM_CLK_GEN_STATUS_OMODE)) | ((((uint32_t) v)<<(BFP_CLK_GEN_STATUS_OMODE)) & (BFM_CLK_GEN_STATUS_OMODE)) ))
#define BFR_CLK_GEN_STATUS_OMODE()              ((REG_CLK_GEN_STATUS.U32 & (BFM_CLK_GEN_STATUS_OMODE))>>(BFP_CLK_GEN_STATUS_OMODE))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_HFADJ - HFRC Adjustment                                            *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_20                    : 12;
        unsigned HFWARMUP                   :  1;
        unsigned HFXTADJ                    : 11;
        unsigned RSVD_4                     :  4;
        unsigned HFADJCK                    :  3;
        unsigned HFADJEN                    :  1;
    } B;
} reg_clk_gen_hfadj_t;

#define REG_CLK_GEN_HFADJ_ADDR                  (REG_CLKGEN_BASEADDR + 0x00000020UL)
#define REG_CLK_GEN_HFADJ                       (*(volatile reg_clk_gen_hfadj_t *) REG_CLK_GEN_HFADJ_ADDR)
#define REG_CLK_GEN_HFADJ_RD()                  (REG_CLK_GEN_HFADJ.U32)
#define REG_CLK_GEN_HFADJ_WR(v)                 (REG_CLK_GEN_HFADJ.U32 = (v))
#define REG_CLK_GEN_HFADJ_CLR(m)                (REG_CLK_GEN_HFADJ.U32 = ((REG_CLK_GEN_HFADJ.U32) & ~(m)))
#define REG_CLK_GEN_HFADJ_SET(m)                (REG_CLK_GEN_HFADJ.U32 = ((REG_CLK_GEN_HFADJ.U32) | (m)))
#define REG_CLK_GEN_HFADJ_DEF                   0x00000000

#define BFP_CLK_GEN_HFADJ_RSVD_20               (20)                    /* bitfield lsb */
#define BFM_CLK_GEN_HFADJ_RSVD_20               ((uint32_t)0xfff00000)  /* bitfield mask */
#define BFN_CLK_GEN_HFADJ_RSVD_20               (12)                    /* bitfield width */
#define BFD_CLK_GEN_HFADJ_RSVD_20               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_HFADJ_RSVD_20(v)            ((((uint32_t) v) << (BFP_CLK_GEN_HFADJ_RSVD_20)) & (BFM_CLK_GEN_HFADJ_RSVD_20))
#define BFX_CLK_GEN_HFADJ_RSVD_20(v)            ((((uint32_t) v) & (BFM_CLK_GEN_HFADJ_RSVD_20)) >> (BFP_CLK_GEN_HFADJ_RSVD_20))
#define BFW_CLK_GEN_HFADJ_RSVD_20(v)            (REG_CLK_GEN_HFADJ.U32 = ( (REG_CLK_GEN_HFADJ.U32 & ~(BFM_CLK_GEN_HFADJ_RSVD_20)) | ((((uint32_t) v)<<(BFP_CLK_GEN_HFADJ_RSVD_20)) & (BFM_CLK_GEN_HFADJ_RSVD_20)) ))
#define BFR_CLK_GEN_HFADJ_RSVD_20()             ((REG_CLK_GEN_HFADJ.U32 & (BFM_CLK_GEN_HFADJ_RSVD_20))>>(BFP_CLK_GEN_HFADJ_RSVD_20))

#define BFP_CLK_GEN_HFADJ_HFWARMUP              (19)                    /* bitfield lsb */
#define BFM_CLK_GEN_HFADJ_HFWARMUP              ((uint32_t)0x00080000)  /* bitfield mask */
#define BFN_CLK_GEN_HFADJ_HFWARMUP              (1)                     /* bitfield width */
#define BFD_CLK_GEN_HFADJ_HFWARMUP              (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_HFADJ_HFWARMUP(v)           ((((uint32_t) v) << (BFP_CLK_GEN_HFADJ_HFWARMUP)) & (BFM_CLK_GEN_HFADJ_HFWARMUP))
#define BFX_CLK_GEN_HFADJ_HFWARMUP(v)           ((((uint32_t) v) & (BFM_CLK_GEN_HFADJ_HFWARMUP)) >> (BFP_CLK_GEN_HFADJ_HFWARMUP))
#define BFW_CLK_GEN_HFADJ_HFWARMUP(v)           (REG_CLK_GEN_HFADJ.U32 = ( (REG_CLK_GEN_HFADJ.U32 & ~(BFM_CLK_GEN_HFADJ_HFWARMUP)) | ((((uint32_t) v)<<(BFP_CLK_GEN_HFADJ_HFWARMUP)) & (BFM_CLK_GEN_HFADJ_HFWARMUP)) ))
#define BFR_CLK_GEN_HFADJ_HFWARMUP()            ((REG_CLK_GEN_HFADJ.U32 & (BFM_CLK_GEN_HFADJ_HFWARMUP))>>(BFP_CLK_GEN_HFADJ_HFWARMUP))

#define BFP_CLK_GEN_HFADJ_HFXTADJ               (8)                     /* bitfield lsb */
#define BFM_CLK_GEN_HFADJ_HFXTADJ               ((uint32_t)0x0007ff00)  /* bitfield mask */
#define BFN_CLK_GEN_HFADJ_HFXTADJ               (11)                    /* bitfield width */
#define BFD_CLK_GEN_HFADJ_HFXTADJ               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_HFADJ_HFXTADJ(v)            ((((uint32_t) v) << (BFP_CLK_GEN_HFADJ_HFXTADJ)) & (BFM_CLK_GEN_HFADJ_HFXTADJ))
#define BFX_CLK_GEN_HFADJ_HFXTADJ(v)            ((((uint32_t) v) & (BFM_CLK_GEN_HFADJ_HFXTADJ)) >> (BFP_CLK_GEN_HFADJ_HFXTADJ))
#define BFW_CLK_GEN_HFADJ_HFXTADJ(v)            (REG_CLK_GEN_HFADJ.U32 = ( (REG_CLK_GEN_HFADJ.U32 & ~(BFM_CLK_GEN_HFADJ_HFXTADJ)) | ((((uint32_t) v)<<(BFP_CLK_GEN_HFADJ_HFXTADJ)) & (BFM_CLK_GEN_HFADJ_HFXTADJ)) ))
#define BFR_CLK_GEN_HFADJ_HFXTADJ()             ((REG_CLK_GEN_HFADJ.U32 & (BFM_CLK_GEN_HFADJ_HFXTADJ))>>(BFP_CLK_GEN_HFADJ_HFXTADJ))

#define BFP_CLK_GEN_HFADJ_RSVD_4                (4)                     /* bitfield lsb */
#define BFM_CLK_GEN_HFADJ_RSVD_4                ((uint32_t)0x000000f0)  /* bitfield mask */
#define BFN_CLK_GEN_HFADJ_RSVD_4                (4)                     /* bitfield width */
#define BFD_CLK_GEN_HFADJ_RSVD_4                (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_HFADJ_RSVD_4(v)             ((((uint32_t) v) << (BFP_CLK_GEN_HFADJ_RSVD_4)) & (BFM_CLK_GEN_HFADJ_RSVD_4))
#define BFX_CLK_GEN_HFADJ_RSVD_4(v)             ((((uint32_t) v) & (BFM_CLK_GEN_HFADJ_RSVD_4)) >> (BFP_CLK_GEN_HFADJ_RSVD_4))
#define BFW_CLK_GEN_HFADJ_RSVD_4(v)             (REG_CLK_GEN_HFADJ.U32 = ( (REG_CLK_GEN_HFADJ.U32 & ~(BFM_CLK_GEN_HFADJ_RSVD_4)) | ((((uint32_t) v)<<(BFP_CLK_GEN_HFADJ_RSVD_4)) & (BFM_CLK_GEN_HFADJ_RSVD_4)) ))
#define BFR_CLK_GEN_HFADJ_RSVD_4()              ((REG_CLK_GEN_HFADJ.U32 & (BFM_CLK_GEN_HFADJ_RSVD_4))>>(BFP_CLK_GEN_HFADJ_RSVD_4))

#define BFP_CLK_GEN_HFADJ_HFADJCK               (1)                     /* bitfield lsb */
#define BFM_CLK_GEN_HFADJ_HFADJCK               ((uint32_t)0x0000000e)  /* bitfield mask */
#define BFN_CLK_GEN_HFADJ_HFADJCK               (3)                     /* bitfield width */
#define BFD_CLK_GEN_HFADJ_HFADJCK               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_HFADJ_HFADJCK(v)            ((((uint32_t) v) << (BFP_CLK_GEN_HFADJ_HFADJCK)) & (BFM_CLK_GEN_HFADJ_HFADJCK))
#define BFX_CLK_GEN_HFADJ_HFADJCK(v)            ((((uint32_t) v) & (BFM_CLK_GEN_HFADJ_HFADJCK)) >> (BFP_CLK_GEN_HFADJ_HFADJCK))
#define BFW_CLK_GEN_HFADJ_HFADJCK(v)            (REG_CLK_GEN_HFADJ.U32 = ( (REG_CLK_GEN_HFADJ.U32 & ~(BFM_CLK_GEN_HFADJ_HFADJCK)) | ((((uint32_t) v)<<(BFP_CLK_GEN_HFADJ_HFADJCK)) & (BFM_CLK_GEN_HFADJ_HFADJCK)) ))
#define BFR_CLK_GEN_HFADJ_HFADJCK()             ((REG_CLK_GEN_HFADJ.U32 & (BFM_CLK_GEN_HFADJ_HFADJCK))>>(BFP_CLK_GEN_HFADJ_HFADJCK))

#define BFP_CLK_GEN_HFADJ_HFADJEN               (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_HFADJ_HFADJEN               ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CLK_GEN_HFADJ_HFADJEN               (1)                     /* bitfield width */
#define BFD_CLK_GEN_HFADJ_HFADJEN               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_HFADJ_HFADJEN(v)            ((((uint32_t) v) << (BFP_CLK_GEN_HFADJ_HFADJEN)) & (BFM_CLK_GEN_HFADJ_HFADJEN))
#define BFX_CLK_GEN_HFADJ_HFADJEN(v)            ((((uint32_t) v) & (BFM_CLK_GEN_HFADJ_HFADJEN)) >> (BFP_CLK_GEN_HFADJ_HFADJEN))
#define BFW_CLK_GEN_HFADJ_HFADJEN(v)            (REG_CLK_GEN_HFADJ.U32 = ( (REG_CLK_GEN_HFADJ.U32 & ~(BFM_CLK_GEN_HFADJ_HFADJEN)) | ((((uint32_t) v)<<(BFP_CLK_GEN_HFADJ_HFADJEN)) & (BFM_CLK_GEN_HFADJ_HFADJEN)) ))
#define BFR_CLK_GEN_HFADJ_HFADJEN()             ((REG_CLK_GEN_HFADJ.U32 & (BFM_CLK_GEN_HFADJ_HFADJEN))>>(BFP_CLK_GEN_HFADJ_HFADJEN))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_HFVAL - HFADJ readback                                             *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_11                    : 21;
        unsigned HFTUNERB                   : 11;
    } B;
} reg_clk_gen_hfval_t;

#define REG_CLK_GEN_HFVAL_ADDR                  (REG_CLKGEN_BASEADDR + 0x00000024UL)
#define REG_CLK_GEN_HFVAL                       (*(volatile reg_clk_gen_hfval_t *) REG_CLK_GEN_HFVAL_ADDR)
#define REG_CLK_GEN_HFVAL_RD()                  (REG_CLK_GEN_HFVAL.U32)
#define REG_CLK_GEN_HFVAL_WR(v)                 (REG_CLK_GEN_HFVAL.U32 = (v))
#define REG_CLK_GEN_HFVAL_CLR(m)                (REG_CLK_GEN_HFVAL.U32 = ((REG_CLK_GEN_HFVAL.U32) & ~(m)))
#define REG_CLK_GEN_HFVAL_SET(m)                (REG_CLK_GEN_HFVAL.U32 = ((REG_CLK_GEN_HFVAL.U32) | (m)))
#define REG_CLK_GEN_HFVAL_DEF                   0x00000000

#define BFP_CLK_GEN_HFVAL_RSVD_11               (11)                    /* bitfield lsb */
#define BFM_CLK_GEN_HFVAL_RSVD_11               ((uint32_t)0xfffff800)  /* bitfield mask */
#define BFN_CLK_GEN_HFVAL_RSVD_11               (21)                    /* bitfield width */
#define BFD_CLK_GEN_HFVAL_RSVD_11               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_HFVAL_RSVD_11(v)            ((((uint32_t) v) << (BFP_CLK_GEN_HFVAL_RSVD_11)) & (BFM_CLK_GEN_HFVAL_RSVD_11))
#define BFX_CLK_GEN_HFVAL_RSVD_11(v)            ((((uint32_t) v) & (BFM_CLK_GEN_HFVAL_RSVD_11)) >> (BFP_CLK_GEN_HFVAL_RSVD_11))
#define BFW_CLK_GEN_HFVAL_RSVD_11(v)            (REG_CLK_GEN_HFVAL.U32 = ( (((uint32_t) v)<<(BFP_CLK_GEN_HFVAL_RSVD_11)) & (BFM_CLK_GEN_HFVAL_RSVD_11)) )
#define BFR_CLK_GEN_HFVAL_RSVD_11()             ((REG_CLK_GEN_HFVAL.U32 & (BFM_CLK_GEN_HFVAL_RSVD_11))>>(BFP_CLK_GEN_HFVAL_RSVD_11))

#define BFP_CLK_GEN_HFVAL_HFTUNERB              (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_HFVAL_HFTUNERB              ((uint32_t)0x000007ff)  /* bitfield mask */
#define BFN_CLK_GEN_HFVAL_HFTUNERB              (11)                    /* bitfield width */
#define BFD_CLK_GEN_HFVAL_HFTUNERB              (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_HFVAL_HFTUNERB(v)           ((((uint32_t) v) << (BFP_CLK_GEN_HFVAL_HFTUNERB)) & (BFM_CLK_GEN_HFVAL_HFTUNERB))
#define BFX_CLK_GEN_HFVAL_HFTUNERB(v)           ((((uint32_t) v) & (BFM_CLK_GEN_HFVAL_HFTUNERB)) >> (BFP_CLK_GEN_HFVAL_HFTUNERB))
#define BFW_CLK_GEN_HFVAL_HFTUNERB(v)           (REG_CLK_GEN_HFVAL.U32 = ( (((uint32_t) v)<<(BFP_CLK_GEN_HFVAL_HFTUNERB)) & (BFM_CLK_GEN_HFVAL_HFTUNERB)) )
#define BFR_CLK_GEN_HFVAL_HFTUNERB()            ((REG_CLK_GEN_HFVAL.U32 & (BFM_CLK_GEN_HFVAL_HFTUNERB))>>(BFP_CLK_GEN_HFVAL_HFTUNERB))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_CLOCKEN - Clock Enable Status                                      *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CLOCKEN                    : 32;
    } B;
} reg_clk_gen_clocken_t;

#define REG_CLK_GEN_CLOCKEN_ADDR                (REG_CLKGEN_BASEADDR + 0x00000028UL)
#define REG_CLK_GEN_CLOCKEN                     (*(volatile reg_clk_gen_clocken_t *) REG_CLK_GEN_CLOCKEN_ADDR)
#define REG_CLK_GEN_CLOCKEN_RD()                (REG_CLK_GEN_CLOCKEN.U32)
#define REG_CLK_GEN_CLOCKEN_WR(v)               (REG_CLK_GEN_CLOCKEN.U32 = (v))
#define REG_CLK_GEN_CLOCKEN_CLR(m)              (REG_CLK_GEN_CLOCKEN.U32 = ((REG_CLK_GEN_CLOCKEN.U32) & ~(m)))
#define REG_CLK_GEN_CLOCKEN_SET(m)              (REG_CLK_GEN_CLOCKEN.U32 = ((REG_CLK_GEN_CLOCKEN.U32) | (m)))
#define REG_CLK_GEN_CLOCKEN_DEF                 0x00000000

#define BFP_CLK_GEN_CLOCKEN_CLOCKEN             (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_CLOCKEN_CLOCKEN             ((uint32_t)0xffffffff)  /* bitfield mask */
#define BFN_CLK_GEN_CLOCKEN_CLOCKEN             (32)                    /* bitfield width */
#define BFD_CLK_GEN_CLOCKEN_CLOCKEN             (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CLOCKEN_CLOCKEN(v)          ((((uint32_t) v) << (BFP_CLK_GEN_CLOCKEN_CLOCKEN)) & (BFM_CLK_GEN_CLOCKEN_CLOCKEN))
#define BFX_CLK_GEN_CLOCKEN_CLOCKEN(v)          ((((uint32_t) v) & (BFM_CLK_GEN_CLOCKEN_CLOCKEN)) >> (BFP_CLK_GEN_CLOCKEN_CLOCKEN))
#define BFW_CLK_GEN_CLOCKEN_CLOCKEN(v)          (REG_CLK_GEN_CLOCKEN.U32 = ( (((uint32_t) v)<<(BFP_CLK_GEN_CLOCKEN_CLOCKEN)) & (BFM_CLK_GEN_CLOCKEN_CLOCKEN)) )
#define BFR_CLK_GEN_CLOCKEN_CLOCKEN()           ((REG_CLK_GEN_CLOCKEN.U32 & (BFM_CLK_GEN_CLOCKEN_CLOCKEN))>>(BFP_CLK_GEN_CLOCKEN_CLOCKEN))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_UARTEN - UART Enable                                               *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_1                     : 31;
        unsigned UARTEN                     :  1;
    } B;
} reg_clk_gen_uarten_t;

#define REG_CLK_GEN_UARTEN_ADDR                 (REG_CLKGEN_BASEADDR + 0x0000002CUL)
#define REG_CLK_GEN_UARTEN                      (*(volatile reg_clk_gen_uarten_t *) REG_CLK_GEN_UARTEN_ADDR)
#define REG_CLK_GEN_UARTEN_RD()                 (REG_CLK_GEN_UARTEN.U32)
#define REG_CLK_GEN_UARTEN_WR(v)                (REG_CLK_GEN_UARTEN.U32 = (v))
#define REG_CLK_GEN_UARTEN_CLR(m)               (REG_CLK_GEN_UARTEN.U32 = ((REG_CLK_GEN_UARTEN.U32) & ~(m)))
#define REG_CLK_GEN_UARTEN_SET(m)               (REG_CLK_GEN_UARTEN.U32 = ((REG_CLK_GEN_UARTEN.U32) | (m)))
#define REG_CLK_GEN_UARTEN_DEF                  0x00000000

#define BFP_CLK_GEN_UARTEN_RSVD_1               (1)                     /* bitfield lsb */
#define BFM_CLK_GEN_UARTEN_RSVD_1               ((uint32_t)0xfffffffe)  /* bitfield mask */
#define BFN_CLK_GEN_UARTEN_RSVD_1               (31)                    /* bitfield width */
#define BFD_CLK_GEN_UARTEN_RSVD_1               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_UARTEN_RSVD_1(v)            ((((uint32_t) v) << (BFP_CLK_GEN_UARTEN_RSVD_1)) & (BFM_CLK_GEN_UARTEN_RSVD_1))
#define BFX_CLK_GEN_UARTEN_RSVD_1(v)            ((((uint32_t) v) & (BFM_CLK_GEN_UARTEN_RSVD_1)) >> (BFP_CLK_GEN_UARTEN_RSVD_1))
#define BFW_CLK_GEN_UARTEN_RSVD_1(v)            (REG_CLK_GEN_UARTEN.U32 = ( (((uint32_t) v)<<(BFP_CLK_GEN_UARTEN_RSVD_1)) & (BFM_CLK_GEN_UARTEN_RSVD_1)) )
#define BFR_CLK_GEN_UARTEN_RSVD_1()             ((REG_CLK_GEN_UARTEN.U32 & (BFM_CLK_GEN_UARTEN_RSVD_1))>>(BFP_CLK_GEN_UARTEN_RSVD_1))

#define BFP_CLK_GEN_UARTEN_UARTEN               (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_UARTEN_UARTEN               ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CLK_GEN_UARTEN_UARTEN               (1)                     /* bitfield width */
#define BFD_CLK_GEN_UARTEN_UARTEN               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_UARTEN_UARTEN(v)            ((((uint32_t) v) << (BFP_CLK_GEN_UARTEN_UARTEN)) & (BFM_CLK_GEN_UARTEN_UARTEN))
#define BFX_CLK_GEN_UARTEN_UARTEN(v)            ((((uint32_t) v) & (BFM_CLK_GEN_UARTEN_UARTEN)) >> (BFP_CLK_GEN_UARTEN_UARTEN))
#define BFW_CLK_GEN_UARTEN_UARTEN(v)            (REG_CLK_GEN_UARTEN.U32 = ( (((uint32_t) v)<<(BFP_CLK_GEN_UARTEN_UARTEN)) & (BFM_CLK_GEN_UARTEN_UARTEN)) )
#define BFR_CLK_GEN_UARTEN_UARTEN()             ((REG_CLK_GEN_UARTEN.U32 & (BFM_CLK_GEN_UARTEN_UARTEN))>>(BFP_CLK_GEN_UARTEN_UARTEN))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_CTRLOW - RTC Counters Lower                                        *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_30                    :  2;
        unsigned CTRHR                      :  6;
        unsigned RSVD_23                    :  1;
        unsigned CTRMIN                     :  7;
        unsigned RSVD_15                    :  1;
        unsigned CTRSEC                     :  7;
        unsigned CTR100                     :  8;
    } B;
} reg_clk_gen_ctrlow_t;

#define REG_CLK_GEN_CTRLOW_ADDR                 (REG_CLKGEN_BASEADDR + 0x00000040UL)
#define REG_CLK_GEN_CTRLOW                      (*(volatile reg_clk_gen_ctrlow_t *) REG_CLK_GEN_CTRLOW_ADDR)
#define REG_CLK_GEN_CTRLOW_RD()                 (REG_CLK_GEN_CTRLOW.U32)
#define REG_CLK_GEN_CTRLOW_WR(v)                (REG_CLK_GEN_CTRLOW.U32 = (v))
#define REG_CLK_GEN_CTRLOW_CLR(m)               (REG_CLK_GEN_CTRLOW.U32 = ((REG_CLK_GEN_CTRLOW.U32) & ~(m)))
#define REG_CLK_GEN_CTRLOW_SET(m)               (REG_CLK_GEN_CTRLOW.U32 = ((REG_CLK_GEN_CTRLOW.U32) | (m)))
#define REG_CLK_GEN_CTRLOW_DEF                  0x01000000

#define BFP_CLK_GEN_CTRLOW_RSVD_30              (30)                    /* bitfield lsb */
#define BFM_CLK_GEN_CTRLOW_RSVD_30              ((uint32_t)0xc0000000)  /* bitfield mask */
#define BFN_CLK_GEN_CTRLOW_RSVD_30              (2)                     /* bitfield width */
#define BFD_CLK_GEN_CTRLOW_RSVD_30              (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CTRLOW_RSVD_30(v)           ((((uint32_t) v) << (BFP_CLK_GEN_CTRLOW_RSVD_30)) & (BFM_CLK_GEN_CTRLOW_RSVD_30))
#define BFX_CLK_GEN_CTRLOW_RSVD_30(v)           ((((uint32_t) v) & (BFM_CLK_GEN_CTRLOW_RSVD_30)) >> (BFP_CLK_GEN_CTRLOW_RSVD_30))
#define BFW_CLK_GEN_CTRLOW_RSVD_30(v)           (REG_CLK_GEN_CTRLOW.U32 = ( (REG_CLK_GEN_CTRLOW.U32 & ~(BFM_CLK_GEN_CTRLOW_RSVD_30)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CTRLOW_RSVD_30)) & (BFM_CLK_GEN_CTRLOW_RSVD_30)) ))
#define BFR_CLK_GEN_CTRLOW_RSVD_30()            ((REG_CLK_GEN_CTRLOW.U32 & (BFM_CLK_GEN_CTRLOW_RSVD_30))>>(BFP_CLK_GEN_CTRLOW_RSVD_30))

#define BFP_CLK_GEN_CTRLOW_CTRHR                (24)                    /* bitfield lsb */
#define BFM_CLK_GEN_CTRLOW_CTRHR                ((uint32_t)0x3f000000)  /* bitfield mask */
#define BFN_CLK_GEN_CTRLOW_CTRHR                (6)                     /* bitfield width */
#define BFD_CLK_GEN_CTRLOW_CTRHR                (0x1)                   /* bitfield default value */
#define BFV_CLK_GEN_CTRLOW_CTRHR(v)             ((((uint32_t) v) << (BFP_CLK_GEN_CTRLOW_CTRHR)) & (BFM_CLK_GEN_CTRLOW_CTRHR))
#define BFX_CLK_GEN_CTRLOW_CTRHR(v)             ((((uint32_t) v) & (BFM_CLK_GEN_CTRLOW_CTRHR)) >> (BFP_CLK_GEN_CTRLOW_CTRHR))
#define BFW_CLK_GEN_CTRLOW_CTRHR(v)             (REG_CLK_GEN_CTRLOW.U32 = ( (REG_CLK_GEN_CTRLOW.U32 & ~(BFM_CLK_GEN_CTRLOW_CTRHR)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CTRLOW_CTRHR)) & (BFM_CLK_GEN_CTRLOW_CTRHR)) ))
#define BFR_CLK_GEN_CTRLOW_CTRHR()              ((REG_CLK_GEN_CTRLOW.U32 & (BFM_CLK_GEN_CTRLOW_CTRHR))>>(BFP_CLK_GEN_CTRLOW_CTRHR))

#define BFP_CLK_GEN_CTRLOW_RSVD_23              (23)                    /* bitfield lsb */
#define BFM_CLK_GEN_CTRLOW_RSVD_23              ((uint32_t)0x00800000)  /* bitfield mask */
#define BFN_CLK_GEN_CTRLOW_RSVD_23              (1)                     /* bitfield width */
#define BFD_CLK_GEN_CTRLOW_RSVD_23              (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CTRLOW_RSVD_23(v)           ((((uint32_t) v) << (BFP_CLK_GEN_CTRLOW_RSVD_23)) & (BFM_CLK_GEN_CTRLOW_RSVD_23))
#define BFX_CLK_GEN_CTRLOW_RSVD_23(v)           ((((uint32_t) v) & (BFM_CLK_GEN_CTRLOW_RSVD_23)) >> (BFP_CLK_GEN_CTRLOW_RSVD_23))
#define BFW_CLK_GEN_CTRLOW_RSVD_23(v)           (REG_CLK_GEN_CTRLOW.U32 = ( (REG_CLK_GEN_CTRLOW.U32 & ~(BFM_CLK_GEN_CTRLOW_RSVD_23)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CTRLOW_RSVD_23)) & (BFM_CLK_GEN_CTRLOW_RSVD_23)) ))
#define BFR_CLK_GEN_CTRLOW_RSVD_23()            ((REG_CLK_GEN_CTRLOW.U32 & (BFM_CLK_GEN_CTRLOW_RSVD_23))>>(BFP_CLK_GEN_CTRLOW_RSVD_23))

#define BFP_CLK_GEN_CTRLOW_CTRMIN               (16)                    /* bitfield lsb */
#define BFM_CLK_GEN_CTRLOW_CTRMIN               ((uint32_t)0x007f0000)  /* bitfield mask */
#define BFN_CLK_GEN_CTRLOW_CTRMIN               (7)                     /* bitfield width */
#define BFD_CLK_GEN_CTRLOW_CTRMIN               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CTRLOW_CTRMIN(v)            ((((uint32_t) v) << (BFP_CLK_GEN_CTRLOW_CTRMIN)) & (BFM_CLK_GEN_CTRLOW_CTRMIN))
#define BFX_CLK_GEN_CTRLOW_CTRMIN(v)            ((((uint32_t) v) & (BFM_CLK_GEN_CTRLOW_CTRMIN)) >> (BFP_CLK_GEN_CTRLOW_CTRMIN))
#define BFW_CLK_GEN_CTRLOW_CTRMIN(v)            (REG_CLK_GEN_CTRLOW.U32 = ( (REG_CLK_GEN_CTRLOW.U32 & ~(BFM_CLK_GEN_CTRLOW_CTRMIN)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CTRLOW_CTRMIN)) & (BFM_CLK_GEN_CTRLOW_CTRMIN)) ))
#define BFR_CLK_GEN_CTRLOW_CTRMIN()             ((REG_CLK_GEN_CTRLOW.U32 & (BFM_CLK_GEN_CTRLOW_CTRMIN))>>(BFP_CLK_GEN_CTRLOW_CTRMIN))

#define BFP_CLK_GEN_CTRLOW_RSVD_15              (15)                    /* bitfield lsb */
#define BFM_CLK_GEN_CTRLOW_RSVD_15              ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_CLK_GEN_CTRLOW_RSVD_15              (1)                     /* bitfield width */
#define BFD_CLK_GEN_CTRLOW_RSVD_15              (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CTRLOW_RSVD_15(v)           ((((uint32_t) v) << (BFP_CLK_GEN_CTRLOW_RSVD_15)) & (BFM_CLK_GEN_CTRLOW_RSVD_15))
#define BFX_CLK_GEN_CTRLOW_RSVD_15(v)           ((((uint32_t) v) & (BFM_CLK_GEN_CTRLOW_RSVD_15)) >> (BFP_CLK_GEN_CTRLOW_RSVD_15))
#define BFW_CLK_GEN_CTRLOW_RSVD_15(v)           (REG_CLK_GEN_CTRLOW.U32 = ( (REG_CLK_GEN_CTRLOW.U32 & ~(BFM_CLK_GEN_CTRLOW_RSVD_15)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CTRLOW_RSVD_15)) & (BFM_CLK_GEN_CTRLOW_RSVD_15)) ))
#define BFR_CLK_GEN_CTRLOW_RSVD_15()            ((REG_CLK_GEN_CTRLOW.U32 & (BFM_CLK_GEN_CTRLOW_RSVD_15))>>(BFP_CLK_GEN_CTRLOW_RSVD_15))

#define BFP_CLK_GEN_CTRLOW_CTRSEC               (8)                     /* bitfield lsb */
#define BFM_CLK_GEN_CTRLOW_CTRSEC               ((uint32_t)0x00007f00)  /* bitfield mask */
#define BFN_CLK_GEN_CTRLOW_CTRSEC               (7)                     /* bitfield width */
#define BFD_CLK_GEN_CTRLOW_CTRSEC               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CTRLOW_CTRSEC(v)            ((((uint32_t) v) << (BFP_CLK_GEN_CTRLOW_CTRSEC)) & (BFM_CLK_GEN_CTRLOW_CTRSEC))
#define BFX_CLK_GEN_CTRLOW_CTRSEC(v)            ((((uint32_t) v) & (BFM_CLK_GEN_CTRLOW_CTRSEC)) >> (BFP_CLK_GEN_CTRLOW_CTRSEC))
#define BFW_CLK_GEN_CTRLOW_CTRSEC(v)            (REG_CLK_GEN_CTRLOW.U32 = ( (REG_CLK_GEN_CTRLOW.U32 & ~(BFM_CLK_GEN_CTRLOW_CTRSEC)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CTRLOW_CTRSEC)) & (BFM_CLK_GEN_CTRLOW_CTRSEC)) ))
#define BFR_CLK_GEN_CTRLOW_CTRSEC()             ((REG_CLK_GEN_CTRLOW.U32 & (BFM_CLK_GEN_CTRLOW_CTRSEC))>>(BFP_CLK_GEN_CTRLOW_CTRSEC))

#define BFP_CLK_GEN_CTRLOW_CTR100               (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_CTRLOW_CTR100               ((uint32_t)0x000000ff)  /* bitfield mask */
#define BFN_CLK_GEN_CTRLOW_CTR100               (8)                     /* bitfield width */
#define BFD_CLK_GEN_CTRLOW_CTR100               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CTRLOW_CTR100(v)            ((((uint32_t) v) << (BFP_CLK_GEN_CTRLOW_CTR100)) & (BFM_CLK_GEN_CTRLOW_CTR100))
#define BFX_CLK_GEN_CTRLOW_CTR100(v)            ((((uint32_t) v) & (BFM_CLK_GEN_CTRLOW_CTR100)) >> (BFP_CLK_GEN_CTRLOW_CTR100))
#define BFW_CLK_GEN_CTRLOW_CTR100(v)            (REG_CLK_GEN_CTRLOW.U32 = ( (REG_CLK_GEN_CTRLOW.U32 & ~(BFM_CLK_GEN_CTRLOW_CTR100)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CTRLOW_CTR100)) & (BFM_CLK_GEN_CTRLOW_CTR100)) ))
#define BFR_CLK_GEN_CTRLOW_CTR100()             ((REG_CLK_GEN_CTRLOW.U32 & (BFM_CLK_GEN_CTRLOW_CTR100))>>(BFP_CLK_GEN_CTRLOW_CTR100))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_CTRUP - RTC Counters Upper                                         *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned CTERR                      :  1;
        unsigned RSVD_29                    :  2;
        unsigned CEB                        :  1;
        unsigned CB                         :  1;
        unsigned CTRWKDY                    :  3;
        unsigned CTRYR                      :  8;
        unsigned RSVD_13                    :  3;
        unsigned CTRMO                      :  5;
        unsigned RSVD_6                     :  2;
        unsigned CTRDATE                    :  6;
    } B;
} reg_clk_gen_ctrup_t;

#define REG_CLK_GEN_CTRUP_ADDR                  (REG_CLKGEN_BASEADDR + 0x00000044UL)
#define REG_CLK_GEN_CTRUP                       (*(volatile reg_clk_gen_ctrup_t *) REG_CLK_GEN_CTRUP_ADDR)
#define REG_CLK_GEN_CTRUP_RD()                  (REG_CLK_GEN_CTRUP.U32)
#define REG_CLK_GEN_CTRUP_WR(v)                 (REG_CLK_GEN_CTRUP.U32 = (v))
#define REG_CLK_GEN_CTRUP_CLR(m)                (REG_CLK_GEN_CTRUP.U32 = ((REG_CLK_GEN_CTRUP.U32) & ~(m)))
#define REG_CLK_GEN_CTRUP_SET(m)                (REG_CLK_GEN_CTRUP.U32 = ((REG_CLK_GEN_CTRUP.U32) | (m)))
#define REG_CLK_GEN_CTRUP_DEF                   0x00000000

#define BFP_CLK_GEN_CTRUP_CTERR                 (31)                    /* bitfield lsb */
#define BFM_CLK_GEN_CTRUP_CTERR                 ((uint32_t)0x80000000)  /* bitfield mask */
#define BFN_CLK_GEN_CTRUP_CTERR                 (1)                     /* bitfield width */
#define BFD_CLK_GEN_CTRUP_CTERR                 (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CTRUP_CTERR(v)              ((((uint32_t) v) << (BFP_CLK_GEN_CTRUP_CTERR)) & (BFM_CLK_GEN_CTRUP_CTERR))
#define BFX_CLK_GEN_CTRUP_CTERR(v)              ((((uint32_t) v) & (BFM_CLK_GEN_CTRUP_CTERR)) >> (BFP_CLK_GEN_CTRUP_CTERR))
#define BFW_CLK_GEN_CTRUP_CTERR(v)              (REG_CLK_GEN_CTRUP.U32 = ( (REG_CLK_GEN_CTRUP.U32 & ~(BFM_CLK_GEN_CTRUP_CTERR)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CTRUP_CTERR)) & (BFM_CLK_GEN_CTRUP_CTERR)) ))
#define BFR_CLK_GEN_CTRUP_CTERR()               ((REG_CLK_GEN_CTRUP.U32 & (BFM_CLK_GEN_CTRUP_CTERR))>>(BFP_CLK_GEN_CTRUP_CTERR))

#define BFP_CLK_GEN_CTRUP_RSVD_29               (29)                    /* bitfield lsb */
#define BFM_CLK_GEN_CTRUP_RSVD_29               ((uint32_t)0x60000000)  /* bitfield mask */
#define BFN_CLK_GEN_CTRUP_RSVD_29               (2)                     /* bitfield width */
#define BFD_CLK_GEN_CTRUP_RSVD_29               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CTRUP_RSVD_29(v)            ((((uint32_t) v) << (BFP_CLK_GEN_CTRUP_RSVD_29)) & (BFM_CLK_GEN_CTRUP_RSVD_29))
#define BFX_CLK_GEN_CTRUP_RSVD_29(v)            ((((uint32_t) v) & (BFM_CLK_GEN_CTRUP_RSVD_29)) >> (BFP_CLK_GEN_CTRUP_RSVD_29))
#define BFW_CLK_GEN_CTRUP_RSVD_29(v)            (REG_CLK_GEN_CTRUP.U32 = ( (REG_CLK_GEN_CTRUP.U32 & ~(BFM_CLK_GEN_CTRUP_RSVD_29)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CTRUP_RSVD_29)) & (BFM_CLK_GEN_CTRUP_RSVD_29)) ))
#define BFR_CLK_GEN_CTRUP_RSVD_29()             ((REG_CLK_GEN_CTRUP.U32 & (BFM_CLK_GEN_CTRUP_RSVD_29))>>(BFP_CLK_GEN_CTRUP_RSVD_29))

#define BFP_CLK_GEN_CTRUP_CEB                   (28)                    /* bitfield lsb */
#define BFM_CLK_GEN_CTRUP_CEB                   ((uint32_t)0x10000000)  /* bitfield mask */
#define BFN_CLK_GEN_CTRUP_CEB                   (1)                     /* bitfield width */
#define BFD_CLK_GEN_CTRUP_CEB                   (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CTRUP_CEB(v)                ((((uint32_t) v) << (BFP_CLK_GEN_CTRUP_CEB)) & (BFM_CLK_GEN_CTRUP_CEB))
#define BFX_CLK_GEN_CTRUP_CEB(v)                ((((uint32_t) v) & (BFM_CLK_GEN_CTRUP_CEB)) >> (BFP_CLK_GEN_CTRUP_CEB))
#define BFW_CLK_GEN_CTRUP_CEB(v)                (REG_CLK_GEN_CTRUP.U32 = ( (REG_CLK_GEN_CTRUP.U32 & ~(BFM_CLK_GEN_CTRUP_CEB)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CTRUP_CEB)) & (BFM_CLK_GEN_CTRUP_CEB)) ))
#define BFR_CLK_GEN_CTRUP_CEB()                 ((REG_CLK_GEN_CTRUP.U32 & (BFM_CLK_GEN_CTRUP_CEB))>>(BFP_CLK_GEN_CTRUP_CEB))

#define BFP_CLK_GEN_CTRUP_CB                    (27)                    /* bitfield lsb */
#define BFM_CLK_GEN_CTRUP_CB                    ((uint32_t)0x08000000)  /* bitfield mask */
#define BFN_CLK_GEN_CTRUP_CB                    (1)                     /* bitfield width */
#define BFD_CLK_GEN_CTRUP_CB                    (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CTRUP_CB(v)                 ((((uint32_t) v) << (BFP_CLK_GEN_CTRUP_CB)) & (BFM_CLK_GEN_CTRUP_CB))
#define BFX_CLK_GEN_CTRUP_CB(v)                 ((((uint32_t) v) & (BFM_CLK_GEN_CTRUP_CB)) >> (BFP_CLK_GEN_CTRUP_CB))
#define BFW_CLK_GEN_CTRUP_CB(v)                 (REG_CLK_GEN_CTRUP.U32 = ( (REG_CLK_GEN_CTRUP.U32 & ~(BFM_CLK_GEN_CTRUP_CB)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CTRUP_CB)) & (BFM_CLK_GEN_CTRUP_CB)) ))
#define BFR_CLK_GEN_CTRUP_CB()                  ((REG_CLK_GEN_CTRUP.U32 & (BFM_CLK_GEN_CTRUP_CB))>>(BFP_CLK_GEN_CTRUP_CB))

#define BFP_CLK_GEN_CTRUP_CTRWKDY               (24)                    /* bitfield lsb */
#define BFM_CLK_GEN_CTRUP_CTRWKDY               ((uint32_t)0x07000000)  /* bitfield mask */
#define BFN_CLK_GEN_CTRUP_CTRWKDY               (3)                     /* bitfield width */
#define BFD_CLK_GEN_CTRUP_CTRWKDY               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CTRUP_CTRWKDY(v)            ((((uint32_t) v) << (BFP_CLK_GEN_CTRUP_CTRWKDY)) & (BFM_CLK_GEN_CTRUP_CTRWKDY))
#define BFX_CLK_GEN_CTRUP_CTRWKDY(v)            ((((uint32_t) v) & (BFM_CLK_GEN_CTRUP_CTRWKDY)) >> (BFP_CLK_GEN_CTRUP_CTRWKDY))
#define BFW_CLK_GEN_CTRUP_CTRWKDY(v)            (REG_CLK_GEN_CTRUP.U32 = ( (REG_CLK_GEN_CTRUP.U32 & ~(BFM_CLK_GEN_CTRUP_CTRWKDY)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CTRUP_CTRWKDY)) & (BFM_CLK_GEN_CTRUP_CTRWKDY)) ))
#define BFR_CLK_GEN_CTRUP_CTRWKDY()             ((REG_CLK_GEN_CTRUP.U32 & (BFM_CLK_GEN_CTRUP_CTRWKDY))>>(BFP_CLK_GEN_CTRUP_CTRWKDY))

#define BFP_CLK_GEN_CTRUP_CTRYR                 (16)                    /* bitfield lsb */
#define BFM_CLK_GEN_CTRUP_CTRYR                 ((uint32_t)0x00ff0000)  /* bitfield mask */
#define BFN_CLK_GEN_CTRUP_CTRYR                 (8)                     /* bitfield width */
#define BFD_CLK_GEN_CTRUP_CTRYR                 (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CTRUP_CTRYR(v)              ((((uint32_t) v) << (BFP_CLK_GEN_CTRUP_CTRYR)) & (BFM_CLK_GEN_CTRUP_CTRYR))
#define BFX_CLK_GEN_CTRUP_CTRYR(v)              ((((uint32_t) v) & (BFM_CLK_GEN_CTRUP_CTRYR)) >> (BFP_CLK_GEN_CTRUP_CTRYR))
#define BFW_CLK_GEN_CTRUP_CTRYR(v)              (REG_CLK_GEN_CTRUP.U32 = ( (REG_CLK_GEN_CTRUP.U32 & ~(BFM_CLK_GEN_CTRUP_CTRYR)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CTRUP_CTRYR)) & (BFM_CLK_GEN_CTRUP_CTRYR)) ))
#define BFR_CLK_GEN_CTRUP_CTRYR()               ((REG_CLK_GEN_CTRUP.U32 & (BFM_CLK_GEN_CTRUP_CTRYR))>>(BFP_CLK_GEN_CTRUP_CTRYR))

#define BFP_CLK_GEN_CTRUP_RSVD_13               (13)                    /* bitfield lsb */
#define BFM_CLK_GEN_CTRUP_RSVD_13               ((uint32_t)0x0000e000)  /* bitfield mask */
#define BFN_CLK_GEN_CTRUP_RSVD_13               (3)                     /* bitfield width */
#define BFD_CLK_GEN_CTRUP_RSVD_13               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CTRUP_RSVD_13(v)            ((((uint32_t) v) << (BFP_CLK_GEN_CTRUP_RSVD_13)) & (BFM_CLK_GEN_CTRUP_RSVD_13))
#define BFX_CLK_GEN_CTRUP_RSVD_13(v)            ((((uint32_t) v) & (BFM_CLK_GEN_CTRUP_RSVD_13)) >> (BFP_CLK_GEN_CTRUP_RSVD_13))
#define BFW_CLK_GEN_CTRUP_RSVD_13(v)            (REG_CLK_GEN_CTRUP.U32 = ( (REG_CLK_GEN_CTRUP.U32 & ~(BFM_CLK_GEN_CTRUP_RSVD_13)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CTRUP_RSVD_13)) & (BFM_CLK_GEN_CTRUP_RSVD_13)) ))
#define BFR_CLK_GEN_CTRUP_RSVD_13()             ((REG_CLK_GEN_CTRUP.U32 & (BFM_CLK_GEN_CTRUP_RSVD_13))>>(BFP_CLK_GEN_CTRUP_RSVD_13))

#define BFP_CLK_GEN_CTRUP_CTRMO                 (8)                     /* bitfield lsb */
#define BFM_CLK_GEN_CTRUP_CTRMO                 ((uint32_t)0x00001f00)  /* bitfield mask */
#define BFN_CLK_GEN_CTRUP_CTRMO                 (5)                     /* bitfield width */
#define BFD_CLK_GEN_CTRUP_CTRMO                 (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CTRUP_CTRMO(v)              ((((uint32_t) v) << (BFP_CLK_GEN_CTRUP_CTRMO)) & (BFM_CLK_GEN_CTRUP_CTRMO))
#define BFX_CLK_GEN_CTRUP_CTRMO(v)              ((((uint32_t) v) & (BFM_CLK_GEN_CTRUP_CTRMO)) >> (BFP_CLK_GEN_CTRUP_CTRMO))
#define BFW_CLK_GEN_CTRUP_CTRMO(v)              (REG_CLK_GEN_CTRUP.U32 = ( (REG_CLK_GEN_CTRUP.U32 & ~(BFM_CLK_GEN_CTRUP_CTRMO)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CTRUP_CTRMO)) & (BFM_CLK_GEN_CTRUP_CTRMO)) ))
#define BFR_CLK_GEN_CTRUP_CTRMO()               ((REG_CLK_GEN_CTRUP.U32 & (BFM_CLK_GEN_CTRUP_CTRMO))>>(BFP_CLK_GEN_CTRUP_CTRMO))

#define BFP_CLK_GEN_CTRUP_RSVD_6                (6)                     /* bitfield lsb */
#define BFM_CLK_GEN_CTRUP_RSVD_6                ((uint32_t)0x000000c0)  /* bitfield mask */
#define BFN_CLK_GEN_CTRUP_RSVD_6                (2)                     /* bitfield width */
#define BFD_CLK_GEN_CTRUP_RSVD_6                (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CTRUP_RSVD_6(v)             ((((uint32_t) v) << (BFP_CLK_GEN_CTRUP_RSVD_6)) & (BFM_CLK_GEN_CTRUP_RSVD_6))
#define BFX_CLK_GEN_CTRUP_RSVD_6(v)             ((((uint32_t) v) & (BFM_CLK_GEN_CTRUP_RSVD_6)) >> (BFP_CLK_GEN_CTRUP_RSVD_6))
#define BFW_CLK_GEN_CTRUP_RSVD_6(v)             (REG_CLK_GEN_CTRUP.U32 = ( (REG_CLK_GEN_CTRUP.U32 & ~(BFM_CLK_GEN_CTRUP_RSVD_6)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CTRUP_RSVD_6)) & (BFM_CLK_GEN_CTRUP_RSVD_6)) ))
#define BFR_CLK_GEN_CTRUP_RSVD_6()              ((REG_CLK_GEN_CTRUP.U32 & (BFM_CLK_GEN_CTRUP_RSVD_6))>>(BFP_CLK_GEN_CTRUP_RSVD_6))

#define BFP_CLK_GEN_CTRUP_CTRDATE               (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_CTRUP_CTRDATE               ((uint32_t)0x0000003f)  /* bitfield mask */
#define BFN_CLK_GEN_CTRUP_CTRDATE               (6)                     /* bitfield width */
#define BFD_CLK_GEN_CTRUP_CTRDATE               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_CTRUP_CTRDATE(v)            ((((uint32_t) v) << (BFP_CLK_GEN_CTRUP_CTRDATE)) & (BFM_CLK_GEN_CTRUP_CTRDATE))
#define BFX_CLK_GEN_CTRUP_CTRDATE(v)            ((((uint32_t) v) & (BFM_CLK_GEN_CTRUP_CTRDATE)) >> (BFP_CLK_GEN_CTRUP_CTRDATE))
#define BFW_CLK_GEN_CTRUP_CTRDATE(v)            (REG_CLK_GEN_CTRUP.U32 = ( (REG_CLK_GEN_CTRUP.U32 & ~(BFM_CLK_GEN_CTRUP_CTRDATE)) | ((((uint32_t) v)<<(BFP_CLK_GEN_CTRUP_CTRDATE)) & (BFM_CLK_GEN_CTRUP_CTRDATE)) ))
#define BFR_CLK_GEN_CTRUP_CTRDATE()             ((REG_CLK_GEN_CTRUP.U32 & (BFM_CLK_GEN_CTRUP_CTRDATE))>>(BFP_CLK_GEN_CTRUP_CTRDATE))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_ALMLOW - RTC Alarms Lower                                          *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_30                    :  2;
        unsigned ALMHR                      :  6;
        unsigned RSVD_23                    :  1;
        unsigned ALMMIN                     :  7;
        unsigned RSVD_15                    :  1;
        unsigned ALMSEC                     :  7;
        unsigned ALM100                     :  8;
    } B;
} reg_clk_gen_almlow_t;

#define REG_CLK_GEN_ALMLOW_ADDR                 (REG_CLKGEN_BASEADDR + 0x00000048UL)
#define REG_CLK_GEN_ALMLOW                      (*(volatile reg_clk_gen_almlow_t *) REG_CLK_GEN_ALMLOW_ADDR)
#define REG_CLK_GEN_ALMLOW_RD()                 (REG_CLK_GEN_ALMLOW.U32)
#define REG_CLK_GEN_ALMLOW_WR(v)                (REG_CLK_GEN_ALMLOW.U32 = (v))
#define REG_CLK_GEN_ALMLOW_CLR(m)               (REG_CLK_GEN_ALMLOW.U32 = ((REG_CLK_GEN_ALMLOW.U32) & ~(m)))
#define REG_CLK_GEN_ALMLOW_SET(m)               (REG_CLK_GEN_ALMLOW.U32 = ((REG_CLK_GEN_ALMLOW.U32) | (m)))
#define REG_CLK_GEN_ALMLOW_DEF                  0x00000000

#define BFP_CLK_GEN_ALMLOW_RSVD_30              (30)                    /* bitfield lsb */
#define BFM_CLK_GEN_ALMLOW_RSVD_30              ((uint32_t)0xc0000000)  /* bitfield mask */
#define BFN_CLK_GEN_ALMLOW_RSVD_30              (2)                     /* bitfield width */
#define BFD_CLK_GEN_ALMLOW_RSVD_30              (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_ALMLOW_RSVD_30(v)           ((((uint32_t) v) << (BFP_CLK_GEN_ALMLOW_RSVD_30)) & (BFM_CLK_GEN_ALMLOW_RSVD_30))
#define BFX_CLK_GEN_ALMLOW_RSVD_30(v)           ((((uint32_t) v) & (BFM_CLK_GEN_ALMLOW_RSVD_30)) >> (BFP_CLK_GEN_ALMLOW_RSVD_30))
#define BFW_CLK_GEN_ALMLOW_RSVD_30(v)           (REG_CLK_GEN_ALMLOW.U32 = ( (REG_CLK_GEN_ALMLOW.U32 & ~(BFM_CLK_GEN_ALMLOW_RSVD_30)) | ((((uint32_t) v)<<(BFP_CLK_GEN_ALMLOW_RSVD_30)) & (BFM_CLK_GEN_ALMLOW_RSVD_30)) ))
#define BFR_CLK_GEN_ALMLOW_RSVD_30()            ((REG_CLK_GEN_ALMLOW.U32 & (BFM_CLK_GEN_ALMLOW_RSVD_30))>>(BFP_CLK_GEN_ALMLOW_RSVD_30))

#define BFP_CLK_GEN_ALMLOW_ALMHR                (24)                    /* bitfield lsb */
#define BFM_CLK_GEN_ALMLOW_ALMHR                ((uint32_t)0x3f000000)  /* bitfield mask */
#define BFN_CLK_GEN_ALMLOW_ALMHR                (6)                     /* bitfield width */
#define BFD_CLK_GEN_ALMLOW_ALMHR                (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_ALMLOW_ALMHR(v)             ((((uint32_t) v) << (BFP_CLK_GEN_ALMLOW_ALMHR)) & (BFM_CLK_GEN_ALMLOW_ALMHR))
#define BFX_CLK_GEN_ALMLOW_ALMHR(v)             ((((uint32_t) v) & (BFM_CLK_GEN_ALMLOW_ALMHR)) >> (BFP_CLK_GEN_ALMLOW_ALMHR))
#define BFW_CLK_GEN_ALMLOW_ALMHR(v)             (REG_CLK_GEN_ALMLOW.U32 = ( (REG_CLK_GEN_ALMLOW.U32 & ~(BFM_CLK_GEN_ALMLOW_ALMHR)) | ((((uint32_t) v)<<(BFP_CLK_GEN_ALMLOW_ALMHR)) & (BFM_CLK_GEN_ALMLOW_ALMHR)) ))
#define BFR_CLK_GEN_ALMLOW_ALMHR()              ((REG_CLK_GEN_ALMLOW.U32 & (BFM_CLK_GEN_ALMLOW_ALMHR))>>(BFP_CLK_GEN_ALMLOW_ALMHR))

#define BFP_CLK_GEN_ALMLOW_RSVD_23              (23)                    /* bitfield lsb */
#define BFM_CLK_GEN_ALMLOW_RSVD_23              ((uint32_t)0x00800000)  /* bitfield mask */
#define BFN_CLK_GEN_ALMLOW_RSVD_23              (1)                     /* bitfield width */
#define BFD_CLK_GEN_ALMLOW_RSVD_23              (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_ALMLOW_RSVD_23(v)           ((((uint32_t) v) << (BFP_CLK_GEN_ALMLOW_RSVD_23)) & (BFM_CLK_GEN_ALMLOW_RSVD_23))
#define BFX_CLK_GEN_ALMLOW_RSVD_23(v)           ((((uint32_t) v) & (BFM_CLK_GEN_ALMLOW_RSVD_23)) >> (BFP_CLK_GEN_ALMLOW_RSVD_23))
#define BFW_CLK_GEN_ALMLOW_RSVD_23(v)           (REG_CLK_GEN_ALMLOW.U32 = ( (REG_CLK_GEN_ALMLOW.U32 & ~(BFM_CLK_GEN_ALMLOW_RSVD_23)) | ((((uint32_t) v)<<(BFP_CLK_GEN_ALMLOW_RSVD_23)) & (BFM_CLK_GEN_ALMLOW_RSVD_23)) ))
#define BFR_CLK_GEN_ALMLOW_RSVD_23()            ((REG_CLK_GEN_ALMLOW.U32 & (BFM_CLK_GEN_ALMLOW_RSVD_23))>>(BFP_CLK_GEN_ALMLOW_RSVD_23))

#define BFP_CLK_GEN_ALMLOW_ALMMIN               (16)                    /* bitfield lsb */
#define BFM_CLK_GEN_ALMLOW_ALMMIN               ((uint32_t)0x007f0000)  /* bitfield mask */
#define BFN_CLK_GEN_ALMLOW_ALMMIN               (7)                     /* bitfield width */
#define BFD_CLK_GEN_ALMLOW_ALMMIN               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_ALMLOW_ALMMIN(v)            ((((uint32_t) v) << (BFP_CLK_GEN_ALMLOW_ALMMIN)) & (BFM_CLK_GEN_ALMLOW_ALMMIN))
#define BFX_CLK_GEN_ALMLOW_ALMMIN(v)            ((((uint32_t) v) & (BFM_CLK_GEN_ALMLOW_ALMMIN)) >> (BFP_CLK_GEN_ALMLOW_ALMMIN))
#define BFW_CLK_GEN_ALMLOW_ALMMIN(v)            (REG_CLK_GEN_ALMLOW.U32 = ( (REG_CLK_GEN_ALMLOW.U32 & ~(BFM_CLK_GEN_ALMLOW_ALMMIN)) | ((((uint32_t) v)<<(BFP_CLK_GEN_ALMLOW_ALMMIN)) & (BFM_CLK_GEN_ALMLOW_ALMMIN)) ))
#define BFR_CLK_GEN_ALMLOW_ALMMIN()             ((REG_CLK_GEN_ALMLOW.U32 & (BFM_CLK_GEN_ALMLOW_ALMMIN))>>(BFP_CLK_GEN_ALMLOW_ALMMIN))

#define BFP_CLK_GEN_ALMLOW_RSVD_15              (15)                    /* bitfield lsb */
#define BFM_CLK_GEN_ALMLOW_RSVD_15              ((uint32_t)0x00008000)  /* bitfield mask */
#define BFN_CLK_GEN_ALMLOW_RSVD_15              (1)                     /* bitfield width */
#define BFD_CLK_GEN_ALMLOW_RSVD_15              (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_ALMLOW_RSVD_15(v)           ((((uint32_t) v) << (BFP_CLK_GEN_ALMLOW_RSVD_15)) & (BFM_CLK_GEN_ALMLOW_RSVD_15))
#define BFX_CLK_GEN_ALMLOW_RSVD_15(v)           ((((uint32_t) v) & (BFM_CLK_GEN_ALMLOW_RSVD_15)) >> (BFP_CLK_GEN_ALMLOW_RSVD_15))
#define BFW_CLK_GEN_ALMLOW_RSVD_15(v)           (REG_CLK_GEN_ALMLOW.U32 = ( (REG_CLK_GEN_ALMLOW.U32 & ~(BFM_CLK_GEN_ALMLOW_RSVD_15)) | ((((uint32_t) v)<<(BFP_CLK_GEN_ALMLOW_RSVD_15)) & (BFM_CLK_GEN_ALMLOW_RSVD_15)) ))
#define BFR_CLK_GEN_ALMLOW_RSVD_15()            ((REG_CLK_GEN_ALMLOW.U32 & (BFM_CLK_GEN_ALMLOW_RSVD_15))>>(BFP_CLK_GEN_ALMLOW_RSVD_15))

#define BFP_CLK_GEN_ALMLOW_ALMSEC               (8)                     /* bitfield lsb */
#define BFM_CLK_GEN_ALMLOW_ALMSEC               ((uint32_t)0x00007f00)  /* bitfield mask */
#define BFN_CLK_GEN_ALMLOW_ALMSEC               (7)                     /* bitfield width */
#define BFD_CLK_GEN_ALMLOW_ALMSEC               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_ALMLOW_ALMSEC(v)            ((((uint32_t) v) << (BFP_CLK_GEN_ALMLOW_ALMSEC)) & (BFM_CLK_GEN_ALMLOW_ALMSEC))
#define BFX_CLK_GEN_ALMLOW_ALMSEC(v)            ((((uint32_t) v) & (BFM_CLK_GEN_ALMLOW_ALMSEC)) >> (BFP_CLK_GEN_ALMLOW_ALMSEC))
#define BFW_CLK_GEN_ALMLOW_ALMSEC(v)            (REG_CLK_GEN_ALMLOW.U32 = ( (REG_CLK_GEN_ALMLOW.U32 & ~(BFM_CLK_GEN_ALMLOW_ALMSEC)) | ((((uint32_t) v)<<(BFP_CLK_GEN_ALMLOW_ALMSEC)) & (BFM_CLK_GEN_ALMLOW_ALMSEC)) ))
#define BFR_CLK_GEN_ALMLOW_ALMSEC()             ((REG_CLK_GEN_ALMLOW.U32 & (BFM_CLK_GEN_ALMLOW_ALMSEC))>>(BFP_CLK_GEN_ALMLOW_ALMSEC))

#define BFP_CLK_GEN_ALMLOW_ALM100               (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_ALMLOW_ALM100               ((uint32_t)0x000000ff)  /* bitfield mask */
#define BFN_CLK_GEN_ALMLOW_ALM100               (8)                     /* bitfield width */
#define BFD_CLK_GEN_ALMLOW_ALM100               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_ALMLOW_ALM100(v)            ((((uint32_t) v) << (BFP_CLK_GEN_ALMLOW_ALM100)) & (BFM_CLK_GEN_ALMLOW_ALM100))
#define BFX_CLK_GEN_ALMLOW_ALM100(v)            ((((uint32_t) v) & (BFM_CLK_GEN_ALMLOW_ALM100)) >> (BFP_CLK_GEN_ALMLOW_ALM100))
#define BFW_CLK_GEN_ALMLOW_ALM100(v)            (REG_CLK_GEN_ALMLOW.U32 = ( (REG_CLK_GEN_ALMLOW.U32 & ~(BFM_CLK_GEN_ALMLOW_ALM100)) | ((((uint32_t) v)<<(BFP_CLK_GEN_ALMLOW_ALM100)) & (BFM_CLK_GEN_ALMLOW_ALM100)) ))
#define BFR_CLK_GEN_ALMLOW_ALM100()             ((REG_CLK_GEN_ALMLOW.U32 & (BFM_CLK_GEN_ALMLOW_ALM100))>>(BFP_CLK_GEN_ALMLOW_ALM100))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_ALMUP - RTC Alarms Upper                                           *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_19                    : 13;
        unsigned ALMWKDY                    :  3;
        unsigned RSVD_13                    :  3;
        unsigned ALMMO                      :  5;
        unsigned RSVD_6                     :  2;
        unsigned ALMDATE                    :  6;
    } B;
} reg_clk_gen_almup_t;

#define REG_CLK_GEN_ALMUP_ADDR                  (REG_CLKGEN_BASEADDR + 0x0000004CUL)
#define REG_CLK_GEN_ALMUP                       (*(volatile reg_clk_gen_almup_t *) REG_CLK_GEN_ALMUP_ADDR)
#define REG_CLK_GEN_ALMUP_RD()                  (REG_CLK_GEN_ALMUP.U32)
#define REG_CLK_GEN_ALMUP_WR(v)                 (REG_CLK_GEN_ALMUP.U32 = (v))
#define REG_CLK_GEN_ALMUP_CLR(m)                (REG_CLK_GEN_ALMUP.U32 = ((REG_CLK_GEN_ALMUP.U32) & ~(m)))
#define REG_CLK_GEN_ALMUP_SET(m)                (REG_CLK_GEN_ALMUP.U32 = ((REG_CLK_GEN_ALMUP.U32) | (m)))
#define REG_CLK_GEN_ALMUP_DEF                   0x00000000

#define BFP_CLK_GEN_ALMUP_RSVD_19               (19)                    /* bitfield lsb */
#define BFM_CLK_GEN_ALMUP_RSVD_19               ((uint32_t)0xfff80000)  /* bitfield mask */
#define BFN_CLK_GEN_ALMUP_RSVD_19               (13)                    /* bitfield width */
#define BFD_CLK_GEN_ALMUP_RSVD_19               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_ALMUP_RSVD_19(v)            ((((uint32_t) v) << (BFP_CLK_GEN_ALMUP_RSVD_19)) & (BFM_CLK_GEN_ALMUP_RSVD_19))
#define BFX_CLK_GEN_ALMUP_RSVD_19(v)            ((((uint32_t) v) & (BFM_CLK_GEN_ALMUP_RSVD_19)) >> (BFP_CLK_GEN_ALMUP_RSVD_19))
#define BFW_CLK_GEN_ALMUP_RSVD_19(v)            (REG_CLK_GEN_ALMUP.U32 = ( (REG_CLK_GEN_ALMUP.U32 & ~(BFM_CLK_GEN_ALMUP_RSVD_19)) | ((((uint32_t) v)<<(BFP_CLK_GEN_ALMUP_RSVD_19)) & (BFM_CLK_GEN_ALMUP_RSVD_19)) ))
#define BFR_CLK_GEN_ALMUP_RSVD_19()             ((REG_CLK_GEN_ALMUP.U32 & (BFM_CLK_GEN_ALMUP_RSVD_19))>>(BFP_CLK_GEN_ALMUP_RSVD_19))

#define BFP_CLK_GEN_ALMUP_ALMWKDY               (16)                    /* bitfield lsb */
#define BFM_CLK_GEN_ALMUP_ALMWKDY               ((uint32_t)0x00070000)  /* bitfield mask */
#define BFN_CLK_GEN_ALMUP_ALMWKDY               (3)                     /* bitfield width */
#define BFD_CLK_GEN_ALMUP_ALMWKDY               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_ALMUP_ALMWKDY(v)            ((((uint32_t) v) << (BFP_CLK_GEN_ALMUP_ALMWKDY)) & (BFM_CLK_GEN_ALMUP_ALMWKDY))
#define BFX_CLK_GEN_ALMUP_ALMWKDY(v)            ((((uint32_t) v) & (BFM_CLK_GEN_ALMUP_ALMWKDY)) >> (BFP_CLK_GEN_ALMUP_ALMWKDY))
#define BFW_CLK_GEN_ALMUP_ALMWKDY(v)            (REG_CLK_GEN_ALMUP.U32 = ( (REG_CLK_GEN_ALMUP.U32 & ~(BFM_CLK_GEN_ALMUP_ALMWKDY)) | ((((uint32_t) v)<<(BFP_CLK_GEN_ALMUP_ALMWKDY)) & (BFM_CLK_GEN_ALMUP_ALMWKDY)) ))
#define BFR_CLK_GEN_ALMUP_ALMWKDY()             ((REG_CLK_GEN_ALMUP.U32 & (BFM_CLK_GEN_ALMUP_ALMWKDY))>>(BFP_CLK_GEN_ALMUP_ALMWKDY))

#define BFP_CLK_GEN_ALMUP_RSVD_13               (13)                    /* bitfield lsb */
#define BFM_CLK_GEN_ALMUP_RSVD_13               ((uint32_t)0x0000e000)  /* bitfield mask */
#define BFN_CLK_GEN_ALMUP_RSVD_13               (3)                     /* bitfield width */
#define BFD_CLK_GEN_ALMUP_RSVD_13               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_ALMUP_RSVD_13(v)            ((((uint32_t) v) << (BFP_CLK_GEN_ALMUP_RSVD_13)) & (BFM_CLK_GEN_ALMUP_RSVD_13))
#define BFX_CLK_GEN_ALMUP_RSVD_13(v)            ((((uint32_t) v) & (BFM_CLK_GEN_ALMUP_RSVD_13)) >> (BFP_CLK_GEN_ALMUP_RSVD_13))
#define BFW_CLK_GEN_ALMUP_RSVD_13(v)            (REG_CLK_GEN_ALMUP.U32 = ( (REG_CLK_GEN_ALMUP.U32 & ~(BFM_CLK_GEN_ALMUP_RSVD_13)) | ((((uint32_t) v)<<(BFP_CLK_GEN_ALMUP_RSVD_13)) & (BFM_CLK_GEN_ALMUP_RSVD_13)) ))
#define BFR_CLK_GEN_ALMUP_RSVD_13()             ((REG_CLK_GEN_ALMUP.U32 & (BFM_CLK_GEN_ALMUP_RSVD_13))>>(BFP_CLK_GEN_ALMUP_RSVD_13))

#define BFP_CLK_GEN_ALMUP_ALMMO                 (8)                     /* bitfield lsb */
#define BFM_CLK_GEN_ALMUP_ALMMO                 ((uint32_t)0x00001f00)  /* bitfield mask */
#define BFN_CLK_GEN_ALMUP_ALMMO                 (5)                     /* bitfield width */
#define BFD_CLK_GEN_ALMUP_ALMMO                 (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_ALMUP_ALMMO(v)              ((((uint32_t) v) << (BFP_CLK_GEN_ALMUP_ALMMO)) & (BFM_CLK_GEN_ALMUP_ALMMO))
#define BFX_CLK_GEN_ALMUP_ALMMO(v)              ((((uint32_t) v) & (BFM_CLK_GEN_ALMUP_ALMMO)) >> (BFP_CLK_GEN_ALMUP_ALMMO))
#define BFW_CLK_GEN_ALMUP_ALMMO(v)              (REG_CLK_GEN_ALMUP.U32 = ( (REG_CLK_GEN_ALMUP.U32 & ~(BFM_CLK_GEN_ALMUP_ALMMO)) | ((((uint32_t) v)<<(BFP_CLK_GEN_ALMUP_ALMMO)) & (BFM_CLK_GEN_ALMUP_ALMMO)) ))
#define BFR_CLK_GEN_ALMUP_ALMMO()               ((REG_CLK_GEN_ALMUP.U32 & (BFM_CLK_GEN_ALMUP_ALMMO))>>(BFP_CLK_GEN_ALMUP_ALMMO))

#define BFP_CLK_GEN_ALMUP_RSVD_6                (6)                     /* bitfield lsb */
#define BFM_CLK_GEN_ALMUP_RSVD_6                ((uint32_t)0x000000c0)  /* bitfield mask */
#define BFN_CLK_GEN_ALMUP_RSVD_6                (2)                     /* bitfield width */
#define BFD_CLK_GEN_ALMUP_RSVD_6                (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_ALMUP_RSVD_6(v)             ((((uint32_t) v) << (BFP_CLK_GEN_ALMUP_RSVD_6)) & (BFM_CLK_GEN_ALMUP_RSVD_6))
#define BFX_CLK_GEN_ALMUP_RSVD_6(v)             ((((uint32_t) v) & (BFM_CLK_GEN_ALMUP_RSVD_6)) >> (BFP_CLK_GEN_ALMUP_RSVD_6))
#define BFW_CLK_GEN_ALMUP_RSVD_6(v)             (REG_CLK_GEN_ALMUP.U32 = ( (REG_CLK_GEN_ALMUP.U32 & ~(BFM_CLK_GEN_ALMUP_RSVD_6)) | ((((uint32_t) v)<<(BFP_CLK_GEN_ALMUP_RSVD_6)) & (BFM_CLK_GEN_ALMUP_RSVD_6)) ))
#define BFR_CLK_GEN_ALMUP_RSVD_6()              ((REG_CLK_GEN_ALMUP.U32 & (BFM_CLK_GEN_ALMUP_RSVD_6))>>(BFP_CLK_GEN_ALMUP_RSVD_6))

#define BFP_CLK_GEN_ALMUP_ALMDATE               (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_ALMUP_ALMDATE               ((uint32_t)0x0000003f)  /* bitfield mask */
#define BFN_CLK_GEN_ALMUP_ALMDATE               (6)                     /* bitfield width */
#define BFD_CLK_GEN_ALMUP_ALMDATE               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_ALMUP_ALMDATE(v)            ((((uint32_t) v) << (BFP_CLK_GEN_ALMUP_ALMDATE)) & (BFM_CLK_GEN_ALMUP_ALMDATE))
#define BFX_CLK_GEN_ALMUP_ALMDATE(v)            ((((uint32_t) v) & (BFM_CLK_GEN_ALMUP_ALMDATE)) >> (BFP_CLK_GEN_ALMUP_ALMDATE))
#define BFW_CLK_GEN_ALMUP_ALMDATE(v)            (REG_CLK_GEN_ALMUP.U32 = ( (REG_CLK_GEN_ALMUP.U32 & ~(BFM_CLK_GEN_ALMUP_ALMDATE)) | ((((uint32_t) v)<<(BFP_CLK_GEN_ALMUP_ALMDATE)) & (BFM_CLK_GEN_ALMUP_ALMDATE)) ))
#define BFR_CLK_GEN_ALMUP_ALMDATE()             ((REG_CLK_GEN_ALMUP.U32 & (BFM_CLK_GEN_ALMUP_ALMDATE))>>(BFP_CLK_GEN_ALMUP_ALMDATE))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_RTCCTL - RTC Control Register                                      *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_6                     : 26;
        unsigned HR1224                     :  1;
        unsigned RSTOP                      :  1;
        unsigned RPT                        :  3;
        unsigned WRTC                       :  1;
    } B;
} reg_clk_gen_rtcctl_t;

#define REG_CLK_GEN_RTCCTL_ADDR                 (REG_CLKGEN_BASEADDR + 0x00000050UL)
#define REG_CLK_GEN_RTCCTL                      (*(volatile reg_clk_gen_rtcctl_t *) REG_CLK_GEN_RTCCTL_ADDR)
#define REG_CLK_GEN_RTCCTL_RD()                 (REG_CLK_GEN_RTCCTL.U32)
#define REG_CLK_GEN_RTCCTL_WR(v)                (REG_CLK_GEN_RTCCTL.U32 = (v))
#define REG_CLK_GEN_RTCCTL_CLR(m)               (REG_CLK_GEN_RTCCTL.U32 = ((REG_CLK_GEN_RTCCTL.U32) & ~(m)))
#define REG_CLK_GEN_RTCCTL_SET(m)               (REG_CLK_GEN_RTCCTL.U32 = ((REG_CLK_GEN_RTCCTL.U32) | (m)))
#define REG_CLK_GEN_RTCCTL_DEF                  0x00000000

#define BFP_CLK_GEN_RTCCTL_RSVD_6               (6)                     /* bitfield lsb */
#define BFM_CLK_GEN_RTCCTL_RSVD_6               ((uint32_t)0xffffffc0)  /* bitfield mask */
#define BFN_CLK_GEN_RTCCTL_RSVD_6               (26)                    /* bitfield width */
#define BFD_CLK_GEN_RTCCTL_RSVD_6               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_RTCCTL_RSVD_6(v)            ((((uint32_t) v) << (BFP_CLK_GEN_RTCCTL_RSVD_6)) & (BFM_CLK_GEN_RTCCTL_RSVD_6))
#define BFX_CLK_GEN_RTCCTL_RSVD_6(v)            ((((uint32_t) v) & (BFM_CLK_GEN_RTCCTL_RSVD_6)) >> (BFP_CLK_GEN_RTCCTL_RSVD_6))
#define BFW_CLK_GEN_RTCCTL_RSVD_6(v)            (REG_CLK_GEN_RTCCTL.U32 = ( (REG_CLK_GEN_RTCCTL.U32 & ~(BFM_CLK_GEN_RTCCTL_RSVD_6)) | ((((uint32_t) v)<<(BFP_CLK_GEN_RTCCTL_RSVD_6)) & (BFM_CLK_GEN_RTCCTL_RSVD_6)) ))
#define BFR_CLK_GEN_RTCCTL_RSVD_6()             ((REG_CLK_GEN_RTCCTL.U32 & (BFM_CLK_GEN_RTCCTL_RSVD_6))>>(BFP_CLK_GEN_RTCCTL_RSVD_6))

#define BFP_CLK_GEN_RTCCTL_HR1224               (5)                     /* bitfield lsb */
#define BFM_CLK_GEN_RTCCTL_HR1224               ((uint32_t)0x00000020)  /* bitfield mask */
#define BFN_CLK_GEN_RTCCTL_HR1224               (1)                     /* bitfield width */
#define BFD_CLK_GEN_RTCCTL_HR1224               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_RTCCTL_HR1224(v)            ((((uint32_t) v) << (BFP_CLK_GEN_RTCCTL_HR1224)) & (BFM_CLK_GEN_RTCCTL_HR1224))
#define BFX_CLK_GEN_RTCCTL_HR1224(v)            ((((uint32_t) v) & (BFM_CLK_GEN_RTCCTL_HR1224)) >> (BFP_CLK_GEN_RTCCTL_HR1224))
#define BFW_CLK_GEN_RTCCTL_HR1224(v)            (REG_CLK_GEN_RTCCTL.U32 = ( (REG_CLK_GEN_RTCCTL.U32 & ~(BFM_CLK_GEN_RTCCTL_HR1224)) | ((((uint32_t) v)<<(BFP_CLK_GEN_RTCCTL_HR1224)) & (BFM_CLK_GEN_RTCCTL_HR1224)) ))
#define BFR_CLK_GEN_RTCCTL_HR1224()             ((REG_CLK_GEN_RTCCTL.U32 & (BFM_CLK_GEN_RTCCTL_HR1224))>>(BFP_CLK_GEN_RTCCTL_HR1224))

#define BFP_CLK_GEN_RTCCTL_RSTOP                (4)                     /* bitfield lsb */
#define BFM_CLK_GEN_RTCCTL_RSTOP                ((uint32_t)0x00000010)  /* bitfield mask */
#define BFN_CLK_GEN_RTCCTL_RSTOP                (1)                     /* bitfield width */
#define BFD_CLK_GEN_RTCCTL_RSTOP                (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_RTCCTL_RSTOP(v)             ((((uint32_t) v) << (BFP_CLK_GEN_RTCCTL_RSTOP)) & (BFM_CLK_GEN_RTCCTL_RSTOP))
#define BFX_CLK_GEN_RTCCTL_RSTOP(v)             ((((uint32_t) v) & (BFM_CLK_GEN_RTCCTL_RSTOP)) >> (BFP_CLK_GEN_RTCCTL_RSTOP))
#define BFW_CLK_GEN_RTCCTL_RSTOP(v)             (REG_CLK_GEN_RTCCTL.U32 = ( (REG_CLK_GEN_RTCCTL.U32 & ~(BFM_CLK_GEN_RTCCTL_RSTOP)) | ((((uint32_t) v)<<(BFP_CLK_GEN_RTCCTL_RSTOP)) & (BFM_CLK_GEN_RTCCTL_RSTOP)) ))
#define BFR_CLK_GEN_RTCCTL_RSTOP()              ((REG_CLK_GEN_RTCCTL.U32 & (BFM_CLK_GEN_RTCCTL_RSTOP))>>(BFP_CLK_GEN_RTCCTL_RSTOP))

#define BFP_CLK_GEN_RTCCTL_RPT                  (1)                     /* bitfield lsb */
#define BFM_CLK_GEN_RTCCTL_RPT                  ((uint32_t)0x0000000e)  /* bitfield mask */
#define BFN_CLK_GEN_RTCCTL_RPT                  (3)                     /* bitfield width */
#define BFD_CLK_GEN_RTCCTL_RPT                  (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_RTCCTL_RPT(v)               ((((uint32_t) v) << (BFP_CLK_GEN_RTCCTL_RPT)) & (BFM_CLK_GEN_RTCCTL_RPT))
#define BFX_CLK_GEN_RTCCTL_RPT(v)               ((((uint32_t) v) & (BFM_CLK_GEN_RTCCTL_RPT)) >> (BFP_CLK_GEN_RTCCTL_RPT))
#define BFW_CLK_GEN_RTCCTL_RPT(v)               (REG_CLK_GEN_RTCCTL.U32 = ( (REG_CLK_GEN_RTCCTL.U32 & ~(BFM_CLK_GEN_RTCCTL_RPT)) | ((((uint32_t) v)<<(BFP_CLK_GEN_RTCCTL_RPT)) & (BFM_CLK_GEN_RTCCTL_RPT)) ))
#define BFR_CLK_GEN_RTCCTL_RPT()                ((REG_CLK_GEN_RTCCTL.U32 & (BFM_CLK_GEN_RTCCTL_RPT))>>(BFP_CLK_GEN_RTCCTL_RPT))

#define BFP_CLK_GEN_RTCCTL_WRTC                 (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_RTCCTL_WRTC                 ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CLK_GEN_RTCCTL_WRTC                 (1)                     /* bitfield width */
#define BFD_CLK_GEN_RTCCTL_WRTC                 (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_RTCCTL_WRTC(v)              ((((uint32_t) v) << (BFP_CLK_GEN_RTCCTL_WRTC)) & (BFM_CLK_GEN_RTCCTL_WRTC))
#define BFX_CLK_GEN_RTCCTL_WRTC(v)              ((((uint32_t) v) & (BFM_CLK_GEN_RTCCTL_WRTC)) >> (BFP_CLK_GEN_RTCCTL_WRTC))
#define BFW_CLK_GEN_RTCCTL_WRTC(v)              (REG_CLK_GEN_RTCCTL.U32 = ( (REG_CLK_GEN_RTCCTL.U32 & ~(BFM_CLK_GEN_RTCCTL_WRTC)) | ((((uint32_t) v)<<(BFP_CLK_GEN_RTCCTL_WRTC)) & (BFM_CLK_GEN_RTCCTL_WRTC)) ))
#define BFR_CLK_GEN_RTCCTL_WRTC()               ((REG_CLK_GEN_RTCCTL.U32 & (BFM_CLK_GEN_RTCCTL_WRTC))>>(BFP_CLK_GEN_RTCCTL_WRTC))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_INTRPTEN - CLK_GEN Interrupt Registers                             *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_4                     : 28;
        unsigned ALM                        :  1;
        unsigned OF                         :  1;
        unsigned ACC                        :  1;
        unsigned ACF                        :  1;
    } B;
} reg_clk_gen_intrpten_t;

#define REG_CLK_GEN_INTRPTEN_ADDR               (REG_CLKGEN_BASEADDR + 0x00000100UL)
#define REG_CLK_GEN_INTRPTEN                    (*(volatile reg_clk_gen_intrpten_t *) REG_CLK_GEN_INTRPTEN_ADDR)
#define REG_CLK_GEN_INTRPTEN_RD()               (REG_CLK_GEN_INTRPTEN.U32)
#define REG_CLK_GEN_INTRPTEN_WR(v)              (REG_CLK_GEN_INTRPTEN.U32 = (v))
#define REG_CLK_GEN_INTRPTEN_CLR(m)             (REG_CLK_GEN_INTRPTEN.U32 = ((REG_CLK_GEN_INTRPTEN.U32) & ~(m)))
#define REG_CLK_GEN_INTRPTEN_SET(m)             (REG_CLK_GEN_INTRPTEN.U32 = ((REG_CLK_GEN_INTRPTEN.U32) | (m)))
#define REG_CLK_GEN_INTRPTEN_DEF                0x00000004

#define BFP_CLK_GEN_INTRPTEN_RSVD_4             (4)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTEN_RSVD_4             ((uint32_t)0xfffffff0)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTEN_RSVD_4             (28)                    /* bitfield width */
#define BFD_CLK_GEN_INTRPTEN_RSVD_4             (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTEN_RSVD_4(v)          ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTEN_RSVD_4)) & (BFM_CLK_GEN_INTRPTEN_RSVD_4))
#define BFX_CLK_GEN_INTRPTEN_RSVD_4(v)          ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTEN_RSVD_4)) >> (BFP_CLK_GEN_INTRPTEN_RSVD_4))
#define BFW_CLK_GEN_INTRPTEN_RSVD_4(v)          (REG_CLK_GEN_INTRPTEN.U32 = ( (REG_CLK_GEN_INTRPTEN.U32 & ~(BFM_CLK_GEN_INTRPTEN_RSVD_4)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTEN_RSVD_4)) & (BFM_CLK_GEN_INTRPTEN_RSVD_4)) ))
#define BFR_CLK_GEN_INTRPTEN_RSVD_4()           ((REG_CLK_GEN_INTRPTEN.U32 & (BFM_CLK_GEN_INTRPTEN_RSVD_4))>>(BFP_CLK_GEN_INTRPTEN_RSVD_4))

#define BFP_CLK_GEN_INTRPTEN_ALM                (3)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTEN_ALM                ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTEN_ALM                (1)                     /* bitfield width */
#define BFD_CLK_GEN_INTRPTEN_ALM                (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTEN_ALM(v)             ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTEN_ALM)) & (BFM_CLK_GEN_INTRPTEN_ALM))
#define BFX_CLK_GEN_INTRPTEN_ALM(v)             ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTEN_ALM)) >> (BFP_CLK_GEN_INTRPTEN_ALM))
#define BFW_CLK_GEN_INTRPTEN_ALM(v)             (REG_CLK_GEN_INTRPTEN.U32 = ( (REG_CLK_GEN_INTRPTEN.U32 & ~(BFM_CLK_GEN_INTRPTEN_ALM)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTEN_ALM)) & (BFM_CLK_GEN_INTRPTEN_ALM)) ))
#define BFR_CLK_GEN_INTRPTEN_ALM()              ((REG_CLK_GEN_INTRPTEN.U32 & (BFM_CLK_GEN_INTRPTEN_ALM))>>(BFP_CLK_GEN_INTRPTEN_ALM))

#define BFP_CLK_GEN_INTRPTEN_OF                 (2)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTEN_OF                 ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTEN_OF                 (1)                     /* bitfield width */
#define BFD_CLK_GEN_INTRPTEN_OF                 (0x1)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTEN_OF(v)              ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTEN_OF)) & (BFM_CLK_GEN_INTRPTEN_OF))
#define BFX_CLK_GEN_INTRPTEN_OF(v)              ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTEN_OF)) >> (BFP_CLK_GEN_INTRPTEN_OF))
#define BFW_CLK_GEN_INTRPTEN_OF(v)              (REG_CLK_GEN_INTRPTEN.U32 = ( (REG_CLK_GEN_INTRPTEN.U32 & ~(BFM_CLK_GEN_INTRPTEN_OF)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTEN_OF)) & (BFM_CLK_GEN_INTRPTEN_OF)) ))
#define BFR_CLK_GEN_INTRPTEN_OF()               ((REG_CLK_GEN_INTRPTEN.U32 & (BFM_CLK_GEN_INTRPTEN_OF))>>(BFP_CLK_GEN_INTRPTEN_OF))

#define BFP_CLK_GEN_INTRPTEN_ACC                (1)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTEN_ACC                ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTEN_ACC                (1)                     /* bitfield width */
#define BFD_CLK_GEN_INTRPTEN_ACC                (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTEN_ACC(v)             ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTEN_ACC)) & (BFM_CLK_GEN_INTRPTEN_ACC))
#define BFX_CLK_GEN_INTRPTEN_ACC(v)             ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTEN_ACC)) >> (BFP_CLK_GEN_INTRPTEN_ACC))
#define BFW_CLK_GEN_INTRPTEN_ACC(v)             (REG_CLK_GEN_INTRPTEN.U32 = ( (REG_CLK_GEN_INTRPTEN.U32 & ~(BFM_CLK_GEN_INTRPTEN_ACC)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTEN_ACC)) & (BFM_CLK_GEN_INTRPTEN_ACC)) ))
#define BFR_CLK_GEN_INTRPTEN_ACC()              ((REG_CLK_GEN_INTRPTEN.U32 & (BFM_CLK_GEN_INTRPTEN_ACC))>>(BFP_CLK_GEN_INTRPTEN_ACC))

#define BFP_CLK_GEN_INTRPTEN_ACF                (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTEN_ACF                ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTEN_ACF                (1)                     /* bitfield width */
#define BFD_CLK_GEN_INTRPTEN_ACF                (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTEN_ACF(v)             ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTEN_ACF)) & (BFM_CLK_GEN_INTRPTEN_ACF))
#define BFX_CLK_GEN_INTRPTEN_ACF(v)             ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTEN_ACF)) >> (BFP_CLK_GEN_INTRPTEN_ACF))
#define BFW_CLK_GEN_INTRPTEN_ACF(v)             (REG_CLK_GEN_INTRPTEN.U32 = ( (REG_CLK_GEN_INTRPTEN.U32 & ~(BFM_CLK_GEN_INTRPTEN_ACF)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTEN_ACF)) & (BFM_CLK_GEN_INTRPTEN_ACF)) ))
#define BFR_CLK_GEN_INTRPTEN_ACF()              ((REG_CLK_GEN_INTRPTEN.U32 & (BFM_CLK_GEN_INTRPTEN_ACF))>>(BFP_CLK_GEN_INTRPTEN_ACF))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_INTRPTSTAT - CLK_GEN Interrupt Registers                           *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_4                     : 28;
        unsigned ALM                        :  1;
        unsigned OF                         :  1;
        unsigned ACC                        :  1;
        unsigned ACF                        :  1;
    } B;
} reg_clk_gen_intrptstat_t;

#define REG_CLK_GEN_INTRPTSTAT_ADDR             (REG_CLKGEN_BASEADDR + 0x00000104UL)
#define REG_CLK_GEN_INTRPTSTAT                  (*(volatile reg_clk_gen_intrptstat_t *) REG_CLK_GEN_INTRPTSTAT_ADDR)
#define REG_CLK_GEN_INTRPTSTAT_RD()             (REG_CLK_GEN_INTRPTSTAT.U32)
#define REG_CLK_GEN_INTRPTSTAT_WR(v)            (REG_CLK_GEN_INTRPTSTAT.U32 = (v))
#define REG_CLK_GEN_INTRPTSTAT_CLR(m)           (REG_CLK_GEN_INTRPTSTAT.U32 = ((REG_CLK_GEN_INTRPTSTAT.U32) & ~(m)))
#define REG_CLK_GEN_INTRPTSTAT_SET(m)           (REG_CLK_GEN_INTRPTSTAT.U32 = ((REG_CLK_GEN_INTRPTSTAT.U32) | (m)))
#define REG_CLK_GEN_INTRPTSTAT_DEF              0x00000004

#define BFP_CLK_GEN_INTRPTSTAT_RSVD_4           (4)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTSTAT_RSVD_4           ((uint32_t)0xfffffff0)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTSTAT_RSVD_4           (28)                    /* bitfield width */
#define BFD_CLK_GEN_INTRPTSTAT_RSVD_4           (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTSTAT_RSVD_4(v)        ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTSTAT_RSVD_4)) & (BFM_CLK_GEN_INTRPTSTAT_RSVD_4))
#define BFX_CLK_GEN_INTRPTSTAT_RSVD_4(v)        ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTSTAT_RSVD_4)) >> (BFP_CLK_GEN_INTRPTSTAT_RSVD_4))
#define BFW_CLK_GEN_INTRPTSTAT_RSVD_4(v)        (REG_CLK_GEN_INTRPTSTAT.U32 = ( (REG_CLK_GEN_INTRPTSTAT.U32 & ~(BFM_CLK_GEN_INTRPTSTAT_RSVD_4)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTSTAT_RSVD_4)) & (BFM_CLK_GEN_INTRPTSTAT_RSVD_4)) ))
#define BFR_CLK_GEN_INTRPTSTAT_RSVD_4()         ((REG_CLK_GEN_INTRPTSTAT.U32 & (BFM_CLK_GEN_INTRPTSTAT_RSVD_4))>>(BFP_CLK_GEN_INTRPTSTAT_RSVD_4))

#define BFP_CLK_GEN_INTRPTSTAT_ALM              (3)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTSTAT_ALM              ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTSTAT_ALM              (1)                     /* bitfield width */
#define BFD_CLK_GEN_INTRPTSTAT_ALM              (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTSTAT_ALM(v)           ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTSTAT_ALM)) & (BFM_CLK_GEN_INTRPTSTAT_ALM))
#define BFX_CLK_GEN_INTRPTSTAT_ALM(v)           ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTSTAT_ALM)) >> (BFP_CLK_GEN_INTRPTSTAT_ALM))
#define BFW_CLK_GEN_INTRPTSTAT_ALM(v)           (REG_CLK_GEN_INTRPTSTAT.U32 = ( (REG_CLK_GEN_INTRPTSTAT.U32 & ~(BFM_CLK_GEN_INTRPTSTAT_ALM)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTSTAT_ALM)) & (BFM_CLK_GEN_INTRPTSTAT_ALM)) ))
#define BFR_CLK_GEN_INTRPTSTAT_ALM()            ((REG_CLK_GEN_INTRPTSTAT.U32 & (BFM_CLK_GEN_INTRPTSTAT_ALM))>>(BFP_CLK_GEN_INTRPTSTAT_ALM))

#define BFP_CLK_GEN_INTRPTSTAT_OF               (2)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTSTAT_OF               ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTSTAT_OF               (1)                     /* bitfield width */
#define BFD_CLK_GEN_INTRPTSTAT_OF               (0x1)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTSTAT_OF(v)            ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTSTAT_OF)) & (BFM_CLK_GEN_INTRPTSTAT_OF))
#define BFX_CLK_GEN_INTRPTSTAT_OF(v)            ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTSTAT_OF)) >> (BFP_CLK_GEN_INTRPTSTAT_OF))
#define BFW_CLK_GEN_INTRPTSTAT_OF(v)            (REG_CLK_GEN_INTRPTSTAT.U32 = ( (REG_CLK_GEN_INTRPTSTAT.U32 & ~(BFM_CLK_GEN_INTRPTSTAT_OF)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTSTAT_OF)) & (BFM_CLK_GEN_INTRPTSTAT_OF)) ))
#define BFR_CLK_GEN_INTRPTSTAT_OF()             ((REG_CLK_GEN_INTRPTSTAT.U32 & (BFM_CLK_GEN_INTRPTSTAT_OF))>>(BFP_CLK_GEN_INTRPTSTAT_OF))

#define BFP_CLK_GEN_INTRPTSTAT_ACC              (1)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTSTAT_ACC              ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTSTAT_ACC              (1)                     /* bitfield width */
#define BFD_CLK_GEN_INTRPTSTAT_ACC              (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTSTAT_ACC(v)           ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTSTAT_ACC)) & (BFM_CLK_GEN_INTRPTSTAT_ACC))
#define BFX_CLK_GEN_INTRPTSTAT_ACC(v)           ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTSTAT_ACC)) >> (BFP_CLK_GEN_INTRPTSTAT_ACC))
#define BFW_CLK_GEN_INTRPTSTAT_ACC(v)           (REG_CLK_GEN_INTRPTSTAT.U32 = ( (REG_CLK_GEN_INTRPTSTAT.U32 & ~(BFM_CLK_GEN_INTRPTSTAT_ACC)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTSTAT_ACC)) & (BFM_CLK_GEN_INTRPTSTAT_ACC)) ))
#define BFR_CLK_GEN_INTRPTSTAT_ACC()            ((REG_CLK_GEN_INTRPTSTAT.U32 & (BFM_CLK_GEN_INTRPTSTAT_ACC))>>(BFP_CLK_GEN_INTRPTSTAT_ACC))

#define BFP_CLK_GEN_INTRPTSTAT_ACF              (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTSTAT_ACF              ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTSTAT_ACF              (1)                     /* bitfield width */
#define BFD_CLK_GEN_INTRPTSTAT_ACF              (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTSTAT_ACF(v)           ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTSTAT_ACF)) & (BFM_CLK_GEN_INTRPTSTAT_ACF))
#define BFX_CLK_GEN_INTRPTSTAT_ACF(v)           ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTSTAT_ACF)) >> (BFP_CLK_GEN_INTRPTSTAT_ACF))
#define BFW_CLK_GEN_INTRPTSTAT_ACF(v)           (REG_CLK_GEN_INTRPTSTAT.U32 = ( (REG_CLK_GEN_INTRPTSTAT.U32 & ~(BFM_CLK_GEN_INTRPTSTAT_ACF)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTSTAT_ACF)) & (BFM_CLK_GEN_INTRPTSTAT_ACF)) ))
#define BFR_CLK_GEN_INTRPTSTAT_ACF()            ((REG_CLK_GEN_INTRPTSTAT.U32 & (BFM_CLK_GEN_INTRPTSTAT_ACF))>>(BFP_CLK_GEN_INTRPTSTAT_ACF))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_INTRPTCLR - CLK_GEN Interrupt Registers                            *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_4                     : 28;
        unsigned ALM                        :  1;
        unsigned OF                         :  1;
        unsigned ACC                        :  1;
        unsigned ACF                        :  1;
    } B;
} reg_clk_gen_intrptclr_t;

#define REG_CLK_GEN_INTRPTCLR_ADDR              (REG_CLKGEN_BASEADDR + 0x00000108UL)
#define REG_CLK_GEN_INTRPTCLR                   (*(volatile reg_clk_gen_intrptclr_t *) REG_CLK_GEN_INTRPTCLR_ADDR)
#define REG_CLK_GEN_INTRPTCLR_RD()              (REG_CLK_GEN_INTRPTCLR.U32)
#define REG_CLK_GEN_INTRPTCLR_WR(v)             (REG_CLK_GEN_INTRPTCLR.U32 = (v))
#define REG_CLK_GEN_INTRPTCLR_CLR(m)            (REG_CLK_GEN_INTRPTCLR.U32 = ((REG_CLK_GEN_INTRPTCLR.U32) & ~(m)))
#define REG_CLK_GEN_INTRPTCLR_SET(m)            (REG_CLK_GEN_INTRPTCLR.U32 = ((REG_CLK_GEN_INTRPTCLR.U32) | (m)))
#define REG_CLK_GEN_INTRPTCLR_DEF               0x00000004

#define BFP_CLK_GEN_INTRPTCLR_RSVD_4            (4)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTCLR_RSVD_4            ((uint32_t)0xfffffff0)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTCLR_RSVD_4            (28)                    /* bitfield width */
#define BFD_CLK_GEN_INTRPTCLR_RSVD_4            (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTCLR_RSVD_4(v)         ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTCLR_RSVD_4)) & (BFM_CLK_GEN_INTRPTCLR_RSVD_4))
#define BFX_CLK_GEN_INTRPTCLR_RSVD_4(v)         ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTCLR_RSVD_4)) >> (BFP_CLK_GEN_INTRPTCLR_RSVD_4))
#define BFW_CLK_GEN_INTRPTCLR_RSVD_4(v)         (REG_CLK_GEN_INTRPTCLR.U32 = ( (REG_CLK_GEN_INTRPTCLR.U32 & ~(BFM_CLK_GEN_INTRPTCLR_RSVD_4)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTCLR_RSVD_4)) & (BFM_CLK_GEN_INTRPTCLR_RSVD_4)) ))
#define BFR_CLK_GEN_INTRPTCLR_RSVD_4()          ((REG_CLK_GEN_INTRPTCLR.U32 & (BFM_CLK_GEN_INTRPTCLR_RSVD_4))>>(BFP_CLK_GEN_INTRPTCLR_RSVD_4))

#define BFP_CLK_GEN_INTRPTCLR_ALM               (3)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTCLR_ALM               ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTCLR_ALM               (1)                     /* bitfield width */
#define BFD_CLK_GEN_INTRPTCLR_ALM               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTCLR_ALM(v)            ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTCLR_ALM)) & (BFM_CLK_GEN_INTRPTCLR_ALM))
#define BFX_CLK_GEN_INTRPTCLR_ALM(v)            ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTCLR_ALM)) >> (BFP_CLK_GEN_INTRPTCLR_ALM))
#define BFW_CLK_GEN_INTRPTCLR_ALM(v)            (REG_CLK_GEN_INTRPTCLR.U32 = ( (REG_CLK_GEN_INTRPTCLR.U32 & ~(BFM_CLK_GEN_INTRPTCLR_ALM)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTCLR_ALM)) & (BFM_CLK_GEN_INTRPTCLR_ALM)) ))
#define BFR_CLK_GEN_INTRPTCLR_ALM()             ((REG_CLK_GEN_INTRPTCLR.U32 & (BFM_CLK_GEN_INTRPTCLR_ALM))>>(BFP_CLK_GEN_INTRPTCLR_ALM))

#define BFP_CLK_GEN_INTRPTCLR_OF                (2)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTCLR_OF                ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTCLR_OF                (1)                     /* bitfield width */
#define BFD_CLK_GEN_INTRPTCLR_OF                (0x1)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTCLR_OF(v)             ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTCLR_OF)) & (BFM_CLK_GEN_INTRPTCLR_OF))
#define BFX_CLK_GEN_INTRPTCLR_OF(v)             ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTCLR_OF)) >> (BFP_CLK_GEN_INTRPTCLR_OF))
#define BFW_CLK_GEN_INTRPTCLR_OF(v)             (REG_CLK_GEN_INTRPTCLR.U32 = ( (REG_CLK_GEN_INTRPTCLR.U32 & ~(BFM_CLK_GEN_INTRPTCLR_OF)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTCLR_OF)) & (BFM_CLK_GEN_INTRPTCLR_OF)) ))
#define BFR_CLK_GEN_INTRPTCLR_OF()              ((REG_CLK_GEN_INTRPTCLR.U32 & (BFM_CLK_GEN_INTRPTCLR_OF))>>(BFP_CLK_GEN_INTRPTCLR_OF))

#define BFP_CLK_GEN_INTRPTCLR_ACC               (1)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTCLR_ACC               ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTCLR_ACC               (1)                     /* bitfield width */
#define BFD_CLK_GEN_INTRPTCLR_ACC               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTCLR_ACC(v)            ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTCLR_ACC)) & (BFM_CLK_GEN_INTRPTCLR_ACC))
#define BFX_CLK_GEN_INTRPTCLR_ACC(v)            ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTCLR_ACC)) >> (BFP_CLK_GEN_INTRPTCLR_ACC))
#define BFW_CLK_GEN_INTRPTCLR_ACC(v)            (REG_CLK_GEN_INTRPTCLR.U32 = ( (REG_CLK_GEN_INTRPTCLR.U32 & ~(BFM_CLK_GEN_INTRPTCLR_ACC)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTCLR_ACC)) & (BFM_CLK_GEN_INTRPTCLR_ACC)) ))
#define BFR_CLK_GEN_INTRPTCLR_ACC()             ((REG_CLK_GEN_INTRPTCLR.U32 & (BFM_CLK_GEN_INTRPTCLR_ACC))>>(BFP_CLK_GEN_INTRPTCLR_ACC))

#define BFP_CLK_GEN_INTRPTCLR_ACF               (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTCLR_ACF               ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTCLR_ACF               (1)                     /* bitfield width */
#define BFD_CLK_GEN_INTRPTCLR_ACF               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTCLR_ACF(v)            ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTCLR_ACF)) & (BFM_CLK_GEN_INTRPTCLR_ACF))
#define BFX_CLK_GEN_INTRPTCLR_ACF(v)            ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTCLR_ACF)) >> (BFP_CLK_GEN_INTRPTCLR_ACF))
#define BFW_CLK_GEN_INTRPTCLR_ACF(v)            (REG_CLK_GEN_INTRPTCLR.U32 = ( (REG_CLK_GEN_INTRPTCLR.U32 & ~(BFM_CLK_GEN_INTRPTCLR_ACF)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTCLR_ACF)) & (BFM_CLK_GEN_INTRPTCLR_ACF)) ))
#define BFR_CLK_GEN_INTRPTCLR_ACF()             ((REG_CLK_GEN_INTRPTCLR.U32 & (BFM_CLK_GEN_INTRPTCLR_ACF))>>(BFP_CLK_GEN_INTRPTCLR_ACF))


// *****************************************************************************
//                                                                             *
//  CLK_GEN_INTRPTSET - CLK_GEN Interrupt Registers                            *
//                                                                             *
// *****************************************************************************
typedef union
{
    uint32_t U32;
    struct
    {
        unsigned RSVD_4                     : 28;
        unsigned ALM                        :  1;
        unsigned OF                         :  1;
        unsigned ACC                        :  1;
        unsigned ACF                        :  1;
    } B;
} reg_clk_gen_intrptset_t;

#define REG_CLK_GEN_INTRPTSET_ADDR              (REG_CLKGEN_BASEADDR + 0x0000010CUL)
#define REG_CLK_GEN_INTRPTSET                   (*(volatile reg_clk_gen_intrptset_t *) REG_CLK_GEN_INTRPTSET_ADDR)
#define REG_CLK_GEN_INTRPTSET_RD()              (REG_CLK_GEN_INTRPTSET.U32)
#define REG_CLK_GEN_INTRPTSET_WR(v)             (REG_CLK_GEN_INTRPTSET.U32 = (v))
#define REG_CLK_GEN_INTRPTSET_CLR(m)            (REG_CLK_GEN_INTRPTSET.U32 = ((REG_CLK_GEN_INTRPTSET.U32) & ~(m)))
#define REG_CLK_GEN_INTRPTSET_SET(m)            (REG_CLK_GEN_INTRPTSET.U32 = ((REG_CLK_GEN_INTRPTSET.U32) | (m)))
#define REG_CLK_GEN_INTRPTSET_DEF               0x00000004

#define BFP_CLK_GEN_INTRPTSET_RSVD_4            (4)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTSET_RSVD_4            ((uint32_t)0xfffffff0)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTSET_RSVD_4            (28)                    /* bitfield width */
#define BFD_CLK_GEN_INTRPTSET_RSVD_4            (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTSET_RSVD_4(v)         ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTSET_RSVD_4)) & (BFM_CLK_GEN_INTRPTSET_RSVD_4))
#define BFX_CLK_GEN_INTRPTSET_RSVD_4(v)         ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTSET_RSVD_4)) >> (BFP_CLK_GEN_INTRPTSET_RSVD_4))
#define BFW_CLK_GEN_INTRPTSET_RSVD_4(v)         (REG_CLK_GEN_INTRPTSET.U32 = ( (REG_CLK_GEN_INTRPTSET.U32 & ~(BFM_CLK_GEN_INTRPTSET_RSVD_4)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTSET_RSVD_4)) & (BFM_CLK_GEN_INTRPTSET_RSVD_4)) ))
#define BFR_CLK_GEN_INTRPTSET_RSVD_4()          ((REG_CLK_GEN_INTRPTSET.U32 & (BFM_CLK_GEN_INTRPTSET_RSVD_4))>>(BFP_CLK_GEN_INTRPTSET_RSVD_4))

#define BFP_CLK_GEN_INTRPTSET_ALM               (3)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTSET_ALM               ((uint32_t)0x00000008)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTSET_ALM               (1)                     /* bitfield width */
#define BFD_CLK_GEN_INTRPTSET_ALM               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTSET_ALM(v)            ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTSET_ALM)) & (BFM_CLK_GEN_INTRPTSET_ALM))
#define BFX_CLK_GEN_INTRPTSET_ALM(v)            ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTSET_ALM)) >> (BFP_CLK_GEN_INTRPTSET_ALM))
#define BFW_CLK_GEN_INTRPTSET_ALM(v)            (REG_CLK_GEN_INTRPTSET.U32 = ( (REG_CLK_GEN_INTRPTSET.U32 & ~(BFM_CLK_GEN_INTRPTSET_ALM)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTSET_ALM)) & (BFM_CLK_GEN_INTRPTSET_ALM)) ))
#define BFR_CLK_GEN_INTRPTSET_ALM()             ((REG_CLK_GEN_INTRPTSET.U32 & (BFM_CLK_GEN_INTRPTSET_ALM))>>(BFP_CLK_GEN_INTRPTSET_ALM))

#define BFP_CLK_GEN_INTRPTSET_OF                (2)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTSET_OF                ((uint32_t)0x00000004)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTSET_OF                (1)                     /* bitfield width */
#define BFD_CLK_GEN_INTRPTSET_OF                (0x1)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTSET_OF(v)             ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTSET_OF)) & (BFM_CLK_GEN_INTRPTSET_OF))
#define BFX_CLK_GEN_INTRPTSET_OF(v)             ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTSET_OF)) >> (BFP_CLK_GEN_INTRPTSET_OF))
#define BFW_CLK_GEN_INTRPTSET_OF(v)             (REG_CLK_GEN_INTRPTSET.U32 = ( (REG_CLK_GEN_INTRPTSET.U32 & ~(BFM_CLK_GEN_INTRPTSET_OF)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTSET_OF)) & (BFM_CLK_GEN_INTRPTSET_OF)) ))
#define BFR_CLK_GEN_INTRPTSET_OF()              ((REG_CLK_GEN_INTRPTSET.U32 & (BFM_CLK_GEN_INTRPTSET_OF))>>(BFP_CLK_GEN_INTRPTSET_OF))

#define BFP_CLK_GEN_INTRPTSET_ACC               (1)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTSET_ACC               ((uint32_t)0x00000002)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTSET_ACC               (1)                     /* bitfield width */
#define BFD_CLK_GEN_INTRPTSET_ACC               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTSET_ACC(v)            ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTSET_ACC)) & (BFM_CLK_GEN_INTRPTSET_ACC))
#define BFX_CLK_GEN_INTRPTSET_ACC(v)            ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTSET_ACC)) >> (BFP_CLK_GEN_INTRPTSET_ACC))
#define BFW_CLK_GEN_INTRPTSET_ACC(v)            (REG_CLK_GEN_INTRPTSET.U32 = ( (REG_CLK_GEN_INTRPTSET.U32 & ~(BFM_CLK_GEN_INTRPTSET_ACC)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTSET_ACC)) & (BFM_CLK_GEN_INTRPTSET_ACC)) ))
#define BFR_CLK_GEN_INTRPTSET_ACC()             ((REG_CLK_GEN_INTRPTSET.U32 & (BFM_CLK_GEN_INTRPTSET_ACC))>>(BFP_CLK_GEN_INTRPTSET_ACC))

#define BFP_CLK_GEN_INTRPTSET_ACF               (0)                     /* bitfield lsb */
#define BFM_CLK_GEN_INTRPTSET_ACF               ((uint32_t)0x00000001)  /* bitfield mask */
#define BFN_CLK_GEN_INTRPTSET_ACF               (1)                     /* bitfield width */
#define BFD_CLK_GEN_INTRPTSET_ACF               (0x0)                   /* bitfield default value */
#define BFV_CLK_GEN_INTRPTSET_ACF(v)            ((((uint32_t) v) << (BFP_CLK_GEN_INTRPTSET_ACF)) & (BFM_CLK_GEN_INTRPTSET_ACF))
#define BFX_CLK_GEN_INTRPTSET_ACF(v)            ((((uint32_t) v) & (BFM_CLK_GEN_INTRPTSET_ACF)) >> (BFP_CLK_GEN_INTRPTSET_ACF))
#define BFW_CLK_GEN_INTRPTSET_ACF(v)            (REG_CLK_GEN_INTRPTSET.U32 = ( (REG_CLK_GEN_INTRPTSET.U32 & ~(BFM_CLK_GEN_INTRPTSET_ACF)) | ((((uint32_t) v)<<(BFP_CLK_GEN_INTRPTSET_ACF)) & (BFM_CLK_GEN_INTRPTSET_ACF)) ))
#define BFR_CLK_GEN_INTRPTSET_ACF()             ((REG_CLK_GEN_INTRPTSET.U32 & (BFM_CLK_GEN_INTRPTSET_ACF))>>(BFP_CLK_GEN_INTRPTSET_ACF))



#endif  // __CLK_GEN_H

