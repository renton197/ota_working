//*****************************************************************************
//
//! @file am_devices_lis3mdl.h
//!
//! @brief Driver for the ST Microelectronics LIS3MDL magnetometer
//!
//! @addtogroup devices External Device Control Library
//! @addtogroup lis3mdl SPI Device Control for the LIS3MDL External Magnetometer
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

#ifndef AM_DEVICES_LIS3MDL_H
#define AM_DEVICES_LIS3MDL_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// LIS3MDL Registers.
//
//*****************************************************************************
#define AM_DEVICES_LIS3MDL_WHO_AM_I         0x0F
#define AM_DEVICES_LIS3MDL_CTRL_REG1        0x20
#define AM_DEVICES_LIS3MDL_CTRL_REG2        0x21
#define AM_DEVICES_LIS3MDL_CTRL_REG3        0x22
#define AM_DEVICES_LIS3MDL_CTRL_REG4        0x23
#define AM_DEVICES_LIS3MDL_CTRL_REG5        0x24
#define AM_DEVICES_LIS3MDL_STATUS_REG       0x27
#define AM_DEVICES_LIS3MDL_OUT_X_L          0x28
#define AM_DEVICES_LIS3MDL_OUT_X_H          0x29
#define AM_DEVICES_LIS3MDL_OUT_Y_L          0x2A
#define AM_DEVICES_LIS3MDL_OUT_Y_H          0x2B
#define AM_DEVICES_LIS3MDL_OUT_Z_L          0x2C
#define AM_DEVICES_LIS3MDL_OUT_Z_H          0x2D
#define AM_DEVICES_LIS3MDL_TEMP_OUT_L       0x2E
#define AM_DEVICES_LIS3MDL_TEMP_OUT_H       0x2F
#define AM_DEVICES_LIS3MDL_INT_CFG          0x30
#define AM_DEVICES_LIS3MDL_INT_SRC          0x31
#define AM_DEVICES_LIS3MDL_INT_THS_L        0x32
#define AM_DEVICES_LIS3MDL_INT_THS_H        0x33

//*****************************************************************************
//
// Structure for holding information about the LIS3MDL
//
//*****************************************************************************
typedef struct
{
    uint32_t ui32IOMModule;
    uint32_t ui32ChipSelect;
}
am_devices_lis3mdl_t;

//*****************************************************************************
//
// Buffer type to make reading lis3mdl samples easier.
//
//*****************************************************************************
#define am_devices_lis3mdl_sample(n)                                          \
    union                                                                     \
    {                                                                         \
        uint32_t words[((3 * n) + 1) >> 1];                                   \
        int16_t samples[3 * n];                                               \
    }

//*****************************************************************************
//
// Useful types for handling data transfers to and from the LIS3MDL
//
//*****************************************************************************
#define am_hal_lis3mdl_regs(n)              am_hal_iom_buffer(n)

//*****************************************************************************
//
// External function definitions.
//
//*****************************************************************************
extern void am_devices_lis3mdl_config(const am_devices_lis3mdl_t *psDevice);
extern void am_devices_lis3mdl_trigger(const am_devices_lis3mdl_t *psDevice);

extern void am_devices_lis3mdl_sample_get(
                                         const am_devices_lis3mdl_t *psDevice,
                                         uint32_t *psData,
                                         am_hal_iom_callback_t pfnCallback);

extern uint8_t am_devices_lis3mdl_reg_read(const am_devices_lis3mdl_t *psDevice,
                                         uint8_t ui8Register);

extern void am_devices_lis3mdl_reg_block_read(
                                         const am_devices_lis3mdl_t *psDevice,
                                         uint8_t ui8StartRegister,
                                         uint32_t *pui32Values, uint32_t
                                         ui32NumBytes,
                                         am_hal_iom_callback_t
                                         pfnCallback);

extern void am_devices_lis3mdl_reg_write(const am_devices_lis3mdl_t *psDevice,
                                         uint8_t ui8Register, uint8_t ui8Value);

extern void am_devices_lis3mdl_reg_block_write(
                                         const am_devices_lis3mdl_t *psDevice,
                                         uint8_t ui8StartRegister,
                                         uint32_t *pui32Values,
                                         uint32_t ui32NumBytes,
                                         am_hal_iom_callback_t pfnCallback);

extern uint8_t am_devices_lis3mdl_device_id_get(
                                         const am_devices_lis3mdl_t *psDevice);

extern void am_devices_lis3mdl_reset(const am_devices_lis3mdl_t *psDevice);

#ifdef __cplusplus
}
#endif

#endif // AM_DEVICES_LIS3MDL_H

//*****************************************************************************
//
// End Doxygen group.
//! @}
//
//*****************************************************************************
