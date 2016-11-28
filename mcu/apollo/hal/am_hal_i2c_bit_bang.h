//*****************************************************************************
//
//! @file am_hal_i2c_bit_bang.h
//!
//! @brief I2C bit bang module.
//!
//! These functions implement the I2C bit bang utility
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_HAL_I2C_BIT_BANG_H
#define AM_HAL_I2C_BIT_BANG_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Enumerated return constants
//
//*****************************************************************************
typedef enum
{
    AM_HAL_I2C_BIT_BANG_SUCCESS = 0,
    AM_HAL_I2C_BIT_BANG_ADDRESS_NAKED,
    AM_HAL_I2C_BIT_BANG_DATA_NAKED
}am_hal_i2c_bit_bang_enum_t;

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern void am_hal_i2c_bit_bang_init(uint32_t sck_gpio_number,
                                     uint32_t sda_gpio_number);

extern am_hal_i2c_bit_bang_enum_t am_hal_i2c_bit_bang_send(uint8_t address,
                                                    uint32_t number_of_bytes,
                                                    uint8_t *pData,
                                                    uint8_t ui8Offset,
                                                    bool bUseOffset);

extern am_hal_i2c_bit_bang_enum_t am_hal_i2c_bit_bang_receive(uint8_t address,
                                                    uint32_t number_of_bytes,
                                                    uint8_t *pData,
                                                    uint8_t ui8Offset,
                                                    bool bUseOffset);
#ifdef __cplusplus
}
#endif

#endif //AM_HAL_I2C_BIT_BANG_H

//*****************************************************************************
//
// End Doxygen group.
//! @}
//
//*****************************************************************************
