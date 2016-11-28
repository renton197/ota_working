//*****************************************************************************
//
//! @file am_devices_button.h
//!
//! @brief Functions for controlling an array of buttons.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_DEVICES_BUTTON_H
#define AM_DEVICES_BUTTON_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Number of "ticks" to delay before registering a button press or release.
//
//*****************************************************************************
#define AM_DEVICES_BUTTON_DEBOUNCE_DELAY    0x4

//*****************************************************************************
//
// Button polarity macros
//
//*****************************************************************************
#define AM_DEVICES_BUTTON_NORMAL_HIGH       0x1
#define AM_DEVICES_BUTTON_NORMAL_LOW        0x0

//*****************************************************************************
//
// Structure for keeping track of buttons.
//
//*****************************************************************************
typedef struct
{
    uint32_t ui32GPIONumber;
    uint32_t ui32Polarity;
    uint32_t ui32Count;
    bool bPressed;
    bool bChanged;
}
am_devices_button_t;

//*****************************************************************************
//
// Macro for declaring a button structure.
//
//*****************************************************************************
#define AM_DEVICES_BUTTON(ui32GPIONumber, ui32Polarity)                       \
    {ui32GPIONumber, ui32Polarity, 0, 0, 0}

//*****************************************************************************
//
// Macros for checking button state.
//
//*****************************************************************************
#define am_devices_button_is_up(button)                                       \
    ((button).bPressed == false)

#define am_devices_button_is_down(button)                                     \
    ((button).bPressed == true)

#define am_devices_button_pressed(button)                                     \
    (((button).bPressed == true) && ((button).bChanged == true))

#define am_devices_button_released(button)                                    \
    (((button).bPressed == false) && ((button).bChanged == true))


//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern void am_devices_button_init(am_devices_button_t *psButton);

extern void am_devices_button_array_init(am_devices_button_t *psButtons,
                                         uint32_t ui32NumButtons);
extern void am_devices_button_tick(am_devices_button_t *psButton);

extern void am_devices_button_array_tick(am_devices_button_t *psButtons,
                                         uint32_t ui32NumButtons);
#ifdef __cplusplus
}
#endif

#endif // AM_DEVICES_BUTTON_H

