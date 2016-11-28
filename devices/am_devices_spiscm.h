//*****************************************************************************
//
//! @file am_devices_spiscm.h
//!
//! @brief Master-side functions for working with the SPISC
//!
//! Master-side functions for communicating to devices using the SPI "switched
//! configuration" protocol.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_DEVICES_SPISCM_H
#define AM_DEVICES_SPISCM_H

#ifdef __cplusplus
extern "C"
{
#endif
//*****************************************************************************
//
// Function pointers for SPI write and read.
//
//*****************************************************************************
typedef bool (*am_devices_spiscm_write_t)(am_hal_iom_spi_device_t *psDevice,
                                          uint32_t *pui32Data,
                                          uint32_t ui32NumBytes,
                                          uint32_t ui32Options);

typedef bool (*am_devices_spiscm_read_t)(am_hal_iom_spi_device_t *psDevice,
                                         uint32_t *pui32Data,
                                         uint32_t ui32NumBytes,
                                         uint32_t ui32Options);

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern void am_devices_spiscm_init(am_hal_iom_spi_device_t *psSlaveInterface,
                                   am_devices_spiscm_write_t pfnWriteFunc,
                                   am_devices_spiscm_read_t pfnReadFunc);
extern void am_devices_spiscm_write(uint32_t *pui32Data, uint32_t ui32NumBytes);
extern uint32_t am_devices_spiscm_read(uint32_t *ui32Data);
extern bool am_devices_spiscm_message_check(void);

#ifdef __cplusplus
}
#endif

#endif // AM_DEVICES_SPISCM_H

