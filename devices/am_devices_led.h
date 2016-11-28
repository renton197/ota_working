//*****************************************************************************
//
//! @file am_devices_led.h
//!
//! @brief Functions for controlling an array of LEDs
//!
//! @addtogroup devices External Device Control Library
//! @addtogroup LED SPI Device Control for programmable LEDs.
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
#ifndef AM_DEVICES_LED_H
#define AM_DEVICES_LED_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// LED polarity macros
//
//*****************************************************************************
#define AM_DEVICES_LED_POL_POLARITY_M       0x1
#define AM_DEVICES_LED_ON_HIGH              0x1
#define AM_DEVICES_LED_ON_LOW               0x0

//*****************************************************************************
//
// LED direct drive indicator macro
// Or this in with the polarity value to use the GPIO DATA register instead of
// the GPIO DATA ENABLE register to directly drive an LED buffer.
//
//*****************************************************************************
#define AM_DEVICES_LED_POL_DIRECT_DRIVE_M   0x2

//*****************************************************************************
//
// Structure for keeping track of LEDs
//
//*****************************************************************************
typedef struct
{
    uint32_t ui32GPIONumber;
    uint32_t ui32Polarity;
}
am_devices_led_t;

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern void am_devices_led_init(am_devices_led_t *psLED);
extern void am_devices_led_array_init(am_devices_led_t *psLEDs, uint32_t ui32NumLEDs);
extern void am_devices_led_array_disable(am_devices_led_t *psLEDs, uint32_t ui32NumLEDs);
extern void am_devices_led_on(am_devices_led_t *psLEDs, uint32_t ui32LEDNum);
extern void am_devices_led_off(am_devices_led_t *psLEDs, uint32_t ui32LEDNum);
extern void am_devices_led_toggle(am_devices_led_t *psLEDs, uint32_t ui32LEDNum);
extern bool am_devices_led_get(am_devices_led_t *psLEDs, uint32_t ui32LEDNum);
extern void am_devices_led_array_out(am_devices_led_t *psLEDs, uint32_t ui32NumLEDs,
                                     uint32_t ui32Value);
#ifdef __cplusplus
}
#endif

#endif // AM_DEVICES_LED_H

//*****************************************************************************
//
// End Doxygen group.
//! @}
//
//*****************************************************************************
