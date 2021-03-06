//*****************************************************************************
//
//! @file am_devices_adxl362.h
//!
//! @brief Driver to interface with the ADXL362
//!
//! These functions implement the ADXL362 support routines for use on Ambiq
//! Micro MCUs.
//!
//! @addtogroup devices External Device Control Library
//! @addtogroup ADXL362 SPI Device Control for the ADXL362 External Accelerometer
//! @ingroup devices
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************

#ifndef AM_DEVICES_ADXL362_H
#define AM_DEVICES_ADXL362_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Defines
//
//*****************************************************************************
#define AM_DEVICES_ADXL_IS_X_AXIS(sample)   ((sample & 0x00000001) != 0)

typedef enum
{
    AM_DEVICES_ADXL362_400HZ,
    AM_DEVICES_ADXL362_200HZ,
    AM_DEVICES_ADXL362_100HZ,
}eADXL362SampleRate;

typedef enum
{
    AM_DEVICES_ADXL362_2G,
    AM_DEVICES_ADXL362_4G,
    AM_DEVICES_ADXL362_8G,
}eADXL362Range;

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

    //
    // Number of samples to collect before interrupt.  1 sample consists of
    // 6 bytes (2 bytes/axis)
    uint32_t ui32Samples;

    //
    // Sensor sample rate.
    // Valid values are:
    //    AM_DEVICES_ADXL362_100HZ
    //    AM_DEVICES_ADXL362_200HZ
    //    AM_DEVICES_ADXL362_400HZ
    //
    eADXL362SampleRate ui32SampleRate;

    //
    // Accelerometer measurement range.
    // Valid values are:
    //    AM_DEVICES_ADXL362_2G
    //    AM_DEVICES_ADXL362_4G
    //    AM_DEVICES_ADXL362_8G
    //
    eADXL362Range ui32Range;

    //
    // Half bandwidth mode?
    //
    bool bHalfBandwidth;

    //
    // Sync mode?
    //
    bool bSyncMode;
}
am_devices_adxl362_t;

//*****************************************************************************
//
// Typedef to make sample/word conversion easier to deal with.
//
//*****************************************************************************
#define am_devices_adxl362_sample(n)                                          \
    union                                                                     \
    {                                                                         \
        uint32_t words[((3 * n) + 1) >> 1];                                   \
        int16_t samples[3 * n];                                               \
    }

//*****************************************************************************
//
// Macro for retrieving the sign-extended magnitude of a 16-bit ADXL sample.
//
//*****************************************************************************
#define AM_DEVICES_ADXL362_VALUE(x)    (x ? (((int16_t) ((x) << 2)) / 4) : 0)

//*****************************************************************************
//
// Function pointer used for callbacks.
//
//*****************************************************************************
typedef void (*am_devices_adxl362_callback_t)(void);

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern void am_devices_adxl362_config(const am_devices_adxl362_t *psDevice);

extern void am_devices_adxl362_reset(const am_devices_adxl362_t *psDevice);

extern void am_devices_adxl362_measurement_mode_set(const am_devices_adxl362_t *psDevice);

extern void am_devices_adxl362_fifo_depth_get(const am_devices_adxl362_t *psDevice,
                                              uint32_t *pui32Return);

extern void am_devices_adxl362_sample_get(const am_devices_adxl362_t *psDevice,
                                          uint32_t ui32NumSamples,
                                          uint32_t *pui32ReturnBuffer,
                                          am_devices_adxl362_callback_t pfnCallback);

extern void am_devices_adxl362_ctrl_reg_state_get(const am_devices_adxl362_t *psDevice,
                                                  uint32_t *pui32Return);

extern void am_devices_adxl362_device_id_get(const am_devices_adxl362_t *psDevice,
                                             uint32_t *pui32Return);

extern void am_devices_adxl362_reg_write(const am_devices_adxl362_t *psDevice,
                                         uint8_t *pui8RegValues,
                                         uint8_t ui8StartReg,
                                         uint32_t ui32Number);

extern void am_devices_adxl362_ctrl_reg_read(const am_devices_adxl362_t *psDevice,
                                             uint8_t *pui8Return,
                                             uint8_t ui8StartReg,
                                             uint32_t ui32Number);

#ifdef __cplusplus
}
#endif

#endif // AM_DEVICES_ADXL362_H

//*****************************************************************************
//
// End Doxygen group.
//! @}
//
//*****************************************************************************
