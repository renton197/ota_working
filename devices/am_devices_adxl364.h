//*****************************************************************************
//
//! @file am_devices_adxl364.h
//!
//! @brief Driver to interface with the ADXL364
//!
//! These functions implement the ADXL364 support routines for use on Ambiq
//! Micro MCUs.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************

#ifndef AM_DEVICES_ADXL364_H
#define AM_DEVICES_ADXL364_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Defines
//
//*****************************************************************************
#define AM_DEVICES_ADXL_IS_X_AXIS(sample)   ((sample&0x000000001)!=0)

//*****************************************************************************
//
// Function pointers for SPI write and read.
//
//*****************************************************************************
typedef bool (*am_devices_adxl364_write_t)(uint32_t ui32Module,
                                           uint32_t ui32ChipSelect,
                                           uint32_t *pui32Data,
                                           uint32_t ui32NumBytes,
                                           uint32_t ui32Options);

typedef bool (*am_devices_adxl364_read_t)(uint32_t ui32Module,
                                          uint32_t ui32ChipSelect,
                                          uint32_t *pui32Data,
                                          uint32_t ui32NumBytes,
                                          uint32_t ui32Options);

//*****************************************************************************
//
// Device structure used for communication.
//
//*****************************************************************************
typedef struct
{
    //
    // Module number to use for IOM access.
    //
    uint32_t ui32IOMModule;

    //
    // Chip Select number to use for IOM access.
    //
    uint32_t ui32ChipSelect;
}
am_devices_adxl364_t;

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern void am_devices_adxl364_driver_init(am_hal_iom_spi_device_t *psIOMSettings,
                                           am_devices_adxl364_write_t pfnWriteFunc,
                                           am_devices_adxl364_read_t pfnReadFunc);

extern int  am_devices_adxl364_init(bool bSyncMode, uint32_t ui32ClockFreqHz);
extern void am_devices_adxl364_reset(void);
extern int  am_devices_adxl364_measurement_mode_set(void);
extern int  am_devices_adxl364_fifo_depth_get(uint32_t * p);
extern int  am_devices_adxl364_sample_get(int Number, uint32_t * p);
extern int  am_devices_adxl364_sample_get_nonblocking(int Number);
extern int  am_devices_adxl364_ctrl_reg_state_get(uint32_t * p);
extern void am_devices_adxl364_device_id_get(uint32_t * p);

#ifdef __cplusplus
}
#endif

#endif // AM_DEVICES_ADXL364_H

