//*****************************************************************************
//
//! @file am_util_ring_buffer.h
//!
//! @brief Some helper functions for implementing and managing a ring buffer.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_UTIL_RING_BUFFER_H
#define AM_UTIL_RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif
//*****************************************************************************
//
// External variable definitions
//
//*****************************************************************************
typedef struct
{
    volatile uint8_t *pui8Data;
    volatile uint32_t ui32WriteIndex;
    volatile uint32_t ui32ReadIndex;
    volatile uint32_t ui32Length;
    volatile uint32_t ui32Capacity;
}
am_util_ring_buffer_t;

//*****************************************************************************
//
// Function-like macros.
//
//*****************************************************************************
#define am_util_ring_buffer_empty(psBuffer)                                   \
    ((psBuffer)->ui32Length == 0)

#define am_util_ring_buffer_full(psBuffer)                                    \
    ((psBuffer)->ui32Length == (psBuffer)->ui32Capacity)

#define am_util_ring_buffer_space_left(psBuffer)                              \
    ((psBuffer)->ui32Capacity - (psBuffer)->ui32Length)

#define am_util_ring_buffer_data_left(psBuffer)                               \
    ((psBuffer)->ui32Length)

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
void am_util_ring_buffer_init(am_util_ring_buffer_t *psBuffer,
                              void *pvArray, uint32_t ui32Bytes);

bool am_util_ring_buffer_write(am_util_ring_buffer_t *psBuffer,
                               void *pvSource, uint32_t ui32Bytes);

bool am_util_ring_buffer_read(am_util_ring_buffer_t *psBuffer,
                              void *pvDest, uint32_t ui32Bytes);

#ifdef __cplusplus
}
#endif

#endif // AM_UTIL_RING_BUFFER_H

