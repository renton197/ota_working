/*******************************************************************************
*                                                                              *
* Copyright (c) 2013 Ambiq Micro                                               *
* All rights reserved.                                                         *
*                                                                              *
********************************************************************************
*                                                                              *
* File:     mem_macros.h                                                       *
*                                                                              *
* Title:    General Access Macros (memory or hardware)                         *
*                                                                              *
* Abstract: This module contains macros to help with memory or hw access.      *
*                                                                              *
* Date:     07/29/2013                                                         *
*                                                                              *
* Author:   Ron Hemphill                                                       *
*                                                                              *
* Target:   Ambiq MCU                                                          *
*                                                                              *
********************************************************************************
*                                                                              *
* Usage of the general access macros:                                          *
*                                                                              *
*   MEM_RD8(memaddr)     : Read the byte at memory location, memaddr.          *
*   MEM_RD16(memaddr)    : Read the half-word at memory location, memaddr.     *
*   MEM_RD32(memaddr)    : Read the word at memory location, memaddr.          *
*                                                                              *
*   MEM_WR8(memaddr,v)   : Write the byte at memory location, memaddr.         *
*   MEM_WR16(memaddr,v)  : Write the half-word at memory location, memaddr.    *
*   MEM_WR32(memaddr,v)  : Write the word at memory location, memaddr.         *
*                                                                              *
*                                                                              *
*   NOTE: In the following macros, memaddr is the 32-bit Word address.         *
*         The offsets within the word are handled by the macro.                *
*         For byte access, n=0,1,2, or 3.                                      *
*         For 16-bit, n=L or H.                                                *
*   MEM_RD8_n(memaddr)   : Read the nth BYTE value at memory location, memaddr.*
*   MEM_RD16_n(memaddr)  : Read the nth 16-bit value at mem location, memaddr. *
*   MEM_RD32(memaddr)    : Read the 32-bit value at memory location, memaddr.  *
*                                                                              *
*   MEM_WR8_n(memaddr,v) : Write the nth BYTE value at memory location,memaddr.*
*   MEM_WR16_n(memaddr,v): Write the nth 16-bit value to mem location, memaddr.*
*   MEM_WR32(memaddr,v):   Write the 32-bit value to memory location, memaddr. *
*                                                                              *
*   MEM_SET8_n(memaddr,m): Set the 8 bits given by mask, m, at the nth byte    *
*                          of memaddr.                                         *
*   MEM_SET16_n(memaddr,m):Set the 16 bits given by mask, m, at the low or     *
*                          high half-word of memaddr.                          *
*   MEM_SET32(memaddr,m) : Set the 32 bits given by mask, m, at memaddr.       *
*                                                                              *
*   MEM_CLR8_n(memaddr,m): Clear the 16 bits given by mask, m, at the nth      *
*                          byte of memaddr.                                    *
*   MEM_CLR16_n(memaddr,m):Clear the 16 bits given by mask, m, at the low or   *
*                          high half-word of memaddr.                          *
*   MEM_CLR32(memaddr,m) : Clear the 32 bits given by mask, m, at memaddr.     *
*                                                                              *
* NOTES:                                                                       *
*   - The Ambiq MCU is Little Endian.                                          *
*                                                                              *
*******************************************************************************/

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************

#ifndef __MEM_GENMACROS_H
#define __MEM_GENMACROS_H

// *****************************************************************************
// Include files
// *****************************************************************************
#include "../am_mcu_apollo.h"

// *****************************************************************************
// Defines
// *****************************************************************************
#define MCU_LITTLE_ENDIAN  1

#if MCU_LITTLE_ENDIAN
#define ADDR_0 0
#define ADDR_1 1
#define ADDR_2 2
#define ADDR_3 3
#define ADDR_L 0
#define ADDR_H 2
#else // Big Endian
#define ADDR_0 3
#define ADDR_1 2
#define ADDR_2 1
#define ADDR_3 0
#define ADDR_L 2
#define ADDR_H 0
#endif


// *************************************
// 8-bit General Accessor Macros
// *************************************
#define MEM_RD8(memaddr)        (*(volatile uint8_t *)(memaddr))            // Read byte at memaddr
#define MEM_RD8_0(memaddr)      (*(volatile uint8_t *)(memaddr+ADDR_0))     // Read byte0
#define MEM_RD8_1(memaddr)      (*(volatile uint8_t *)(memaddr+ADDR_1))     // Read byte1
#define MEM_RD8_2(memaddr)      (*(volatile uint8_t *)(memaddr+ADDR_2))     // Read byte2
#define MEM_RD8_3(memaddr)      (*(volatile uint8_t *)(memaddr+ADDR_3))     // Read byte3

#define MEM_WR8(memaddr,v)      (*(volatile uint8_t *)(memaddr)=(v))        // Write byte at memaddr
#define MEM_WR8_0(memaddr,v)    (*(volatile uint8_t *)(memaddr+ADDR_0)=(v)) // Write byte0
#define MEM_WR8_1(memaddr,v)    (*(volatile uint8_t *)(memaddr+ADDR_1)=(v)) // Write byte1
#define MEM_WR8_2(memaddr,v)    (*(volatile uint8_t *)(memaddr+ADDR_2)=(v)) // Write byte2
#define MEM_WR8_3(memaddr,v)    (*(volatile uint8_t *)(memaddr+ADDR_3)=(v)) // Write byte3

#define MEM_CLR8(memaddr,m)     (*(volatile uint8_t *)(memaddr+3)=((*(volatile uint8_t *)(memaddr+ADDR_0)) & ~(m)))
#define MEM_CLR8_0(memaddr,m)   (*(volatile uint8_t *)(memaddr+3)=((*(volatile uint8_t *)(memaddr+ADDR_0)) & ~(m)))
#define MEM_CLR8_1(memaddr,m)   (*(volatile uint8_t *)(memaddr+2)=((*(volatile uint8_t *)(memaddr+ADDR_1)) & ~(m)))
#define MEM_CLR8_2(memaddr,m)   (*(volatile uint8_t *)(memaddr+1)=((*(volatile uint8_t *)(memaddr+ADDR_2)) & ~(m)))
#define MEM_CLR8_3(memaddr,m)   (*(volatile uint8_t *)(memaddr+0)=((*(volatile uint8_t *)(memaddr+ADDR_3)) & ~(m)))

#define MEM_SET8_0(memaddr,m)   (*(volatile uint8_t *)(memaddr+3)=((*(volatile uint8_t *)(memaddr+ADDR_0)) | (m)))
#define MEM_SET8_1(memaddr,m)   (*(volatile uint8_t *)(memaddr+2)=((*(volatile uint8_t *)(memaddr+ADDR_1)) | (m)))
#define MEM_SET8_2(memaddr,m)   (*(volatile uint8_t *)(memaddr+1)=((*(volatile uint8_t *)(memaddr+ADDR_2)) | (m)))
#define MEM_SET8_3(memaddr,m)   (*(volatile uint8_t *)(memaddr+0)=((*(volatile uint8_t *)(memaddr+ADDR_3)) | (m)))


// *************************************
// 16-bit General Accessor Macros
// *************************************
#define MEM_RD16(memaddr)       (*(volatile uint16_t *)(memaddr))           // Read 16-bit low value
#define MEM_RD16_L(memaddr)     (*(volatile uint16_t *)(memaddr+ADDR_L))    // Read 16-bit low value
#define MEM_RD16_H(memaddr)     (*(volatile uint16_t *)(memaddr+ADDR_H))    // Read 16-bit high value
#define MEM_RD16_0(memaddr)     (*(volatile uint16_t *)(memaddr+ADDR_L))    //  alias of MEM_RD16_L
#define MEM_RD16_1(memaddr)     (*(volatile uint16_t *)(memaddr+ADDR_H))    //  alias of MEM_RD16_H

#define MEM_WR16(memaddr,v)     (*(volatile uint16_t *)(memaddr)=(v))       // Write 16-bit word0
#define MEM_WR16_L(memaddr,v)   (*(volatile uint16_t *)(memaddr+ADDR_L)=(v))// Write 16-bit word0
#define MEM_WR16_H(memaddr,v)   (*(volatile uint16_t *)(memaddr+ADDR_H)=(v))// Write 16-bit word1
#define MEM_WR16_0(memaddr,v)   (*(volatile uint16_t *)(memaddr+ADDR_L)=(v))//  (alias of MEM_WR16_L)
#define MEM_WR16_1(memaddr,v)   (*(volatile uint16_t *)(memaddr+ADDR_H)=(v))//  (alias of MEM_WR16_H)

#define MEM_CLR16(memaddr,m)    (*(volatile uint16_t *)(memaddr)=((*(volatile uint16_t *)(memaddr)) & ~(m)))
#define MEM_CLR16_L(memaddr,m)  (*(volatile uint16_t *)(memaddr+ADDR_L)=((*(volatile uint16_t *)(memaddr+ADDR_L)) & ~(m)))
#define MEM_CLR16_H(memaddr,m)  (*(volatile uint16_t *)(memaddr+ADDR_H)=((*(volatile uint16_t *)(memaddr+ADDR_H)) & ~(m)))
#define MEM_CLR16_0(memaddr,m)  (*(volatile uint16_t *)(memaddr+ADDR_L)=((*(volatile uint16_t *)(memaddr+ADDR_L)) & ~(m)))
#define MEM_CLR16_1(memaddr,m)  (*(volatile uint16_t *)(memaddr+ADDR_H)=((*(volatile uint16_t *)(memaddr+ADDR_H)) & ~(m)))

#define MEM_SET16(memaddr,m)    (*(volatile uint16_t *)(memaddr)=((*(volatile uint16_t *)(memaddr)) | (m)))
#define MEM_SET16_L(memaddr,m)  (*(volatile uint16_t *)(memaddr+ADDR_L)=((*(volatile uint16_t *)(memaddr+ADDR_L)) | (m)))
#define MEM_SET16_H(memaddr,m)  (*(volatile uint16_t *)(memaddr+ADDR_H)=((*(volatile uint16_t *)(memaddr+ADDR_H)) | (m)))
#define MEM_SET16_0(memaddr,m)  (*(volatile uint16_t *)(memaddr+ADDR_L)=((*(volatile uint16_t *)(memaddr+ADDR_L)) | (m)))
#define MEM_SET16_1(memaddr,m)  (*(volatile uint16_t *)(memaddr+ADDR_H)=((*(volatile uint16_t *)(memaddr+ADDR_H)) | (m)))


// *************************************
// 32-bit General Accessor Macros
// *************************************
#define MEM_RD32(memaddr)       (*(volatile uint32_t *)(memaddr))
#define MEM_WR32(memaddr,v)     (*(volatile uint32_t *)(memaddr)=(v))       // Write 32-bit word
#define MEM_CLR32(memaddr,m)    (*(volatile uint32_t *)(memaddr)=((*(volatile uint32_t *)(memaddr)) & ~(m)))
#define MEM_SET32(memaddr,m)    (*(volatile uint32_t *)(memaddr)=((*(volatile uint32_t *)(memaddr)) | (m)))


#endif // __MEM_GENMACROS_H

