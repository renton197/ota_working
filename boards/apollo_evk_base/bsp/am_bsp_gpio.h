//*****************************************************************************
//
//! @file am_bsp_gpio.h
//!
//! @brief Functions to aid with configuring the GPIOs.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_BSP_GPIO_H
#define AM_BSP_GPIO_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Miscellaneous pins.
//
//*****************************************************************************
#define AM_BSP_GPIO_BUTTON0             39
#define AM_BSP_GPIO_BUTTON1             26
#define AM_BSP_GPIO_BUTTON2             24
#define AM_BSP_GPIO_IOS_IRQ             2
#define AM_BSP_GPIO_LED0                43
#define AM_BSP_GPIO_LED1                44
#define AM_BSP_GPIO_LED2                45
#define AM_BSP_GPIO_LED3                47

//*****************************************************************************
//
// BOOTLOADER_UART pins.
//
//*****************************************************************************
#define AM_BSP_GPIO_BOOTLOADER_UART_RX  36
#define AM_BSP_GPIO_CFG_BOOTLOADER_UART_RX AM_HAL_PIN_36_UARTRX
#define AM_BSP_GPIO_BOOTLOADER_UART_TX  35
#define AM_BSP_GPIO_CFG_BOOTLOADER_UART_TX AM_HAL_PIN_35_UARTTX

//*****************************************************************************
//
// CLKOUT pins.
//
//*****************************************************************************
#define AM_BSP_GPIO_CLKOUT_PIN          24
#define AM_BSP_GPIO_CFG_CLKOUT_PIN      AM_HAL_PIN_24_CLKOUT

//*****************************************************************************
//
// COM_UART pins.
//
//*****************************************************************************
#define AM_BSP_GPIO_COM_UART_CTS        38
#define AM_BSP_GPIO_CFG_COM_UART_CTS    AM_HAL_PIN_INPUT
#define AM_BSP_GPIO_COM_UART_RTS        37
#define AM_BSP_GPIO_CFG_COM_UART_RTS    AM_HAL_PIN_INPUT
#define AM_BSP_GPIO_COM_UART_RX         36
#define AM_BSP_GPIO_CFG_COM_UART_RX     AM_HAL_PIN_36_UARTRX
#define AM_BSP_GPIO_COM_UART_TX         35
#define AM_BSP_GPIO_CFG_COM_UART_TX     AM_HAL_PIN_35_UARTTX

//*****************************************************************************
//
// CORE pins.
//
//*****************************************************************************
#define AM_BSP_GPIO_CORE_SWDCK          20
#define AM_BSP_GPIO_CFG_CORE_SWDCK      AM_HAL_PIN_20_SWDCK
#define AM_BSP_GPIO_CORE_SWDIO          21
#define AM_BSP_GPIO_CFG_CORE_SWDIO      AM_HAL_PIN_21_SWDIO

//*****************************************************************************
//
// DISPLAY pins.
//
//*****************************************************************************
#define AM_BSP_GPIO_DISPLAY_BACKLT      29
#define AM_BSP_GPIO_CFG_DISPLAY_BACKLT  AM_HAL_PIN_OUTPUT
#define AM_BSP_GPIO_DISPLAY_D_C         31
#define AM_BSP_GPIO_CFG_DISPLAY_D_C     AM_HAL_PIN_OUTPUT

//*****************************************************************************
//
// FLASH pins.
//
//*****************************************************************************
#define AM_BSP_GPIO_FLASH_CS            29
#define AM_BSP_GPIO_CFG_FLASH_CS        AM_HAL_PIN_29_M1nCE6

//*****************************************************************************
//
// IOM0 pins.
//
//*****************************************************************************
#define AM_BSP_GPIO_IOM0_I2C_SCK        5
#define AM_BSP_GPIO_CFG_IOM0_I2C_SCK    (AM_HAL_PIN_5_M0SCL | AM_HAL_GPIO_PULL1_5K)
#define AM_BSP_GPIO_IOM0_I2C_SDA        6
#define AM_BSP_GPIO_CFG_IOM0_I2C_SDA    (AM_HAL_PIN_6_M0SDA | AM_HAL_GPIO_PULL1_5K)

//*****************************************************************************
//
// IOM1 pins.
//
//*****************************************************************************
#define AM_BSP_GPIO_IOM1_DISPLAY_CS     12
#define AM_BSP_GPIO_CFG_IOM1_DISPLAY_CS AM_HAL_PIN_OUTPUT
#define AM_BSP_GPIO_IOM1_MISO           9
#define AM_BSP_GPIO_CFG_IOM1_MISO       AM_HAL_PIN_9_M1MISO
#define AM_BSP_GPIO_IOM1_MOSI           10
#define AM_BSP_GPIO_CFG_IOM1_MOSI       AM_HAL_PIN_10_M1MOSI
#define AM_BSP_GPIO_IOM1_SCK            8
#define AM_BSP_GPIO_CFG_IOM1_SCK        (AM_HAL_PIN_8_M1SCK | AM_HAL_GPIO_HIGH_DRIVE)

//*****************************************************************************
//
// ITM pins.
//
//*****************************************************************************
#define AM_BSP_GPIO_ITM_SWO             41
#define AM_BSP_GPIO_CFG_ITM_SWO         AM_HAL_PIN_41_SWO

//*****************************************************************************
//
// PWM pins.
//
//*****************************************************************************
#define AM_BSP_GPIO_PWM_LED             43
#define AM_BSP_GPIO_CFG_PWM_LED         AM_HAL_PIN_43_TCTB0

//*****************************************************************************
//
// VCOMP pins.
//
//*****************************************************************************
#define AM_BSP_GPIO_VCOMP_RXO           42
#define AM_BSP_GPIO_CFG_VCOMP_RXO       AM_HAL_PIN_OUTPUT
#define AM_BSP_GPIO_VCOMP_RXO_CMP       18
#define AM_BSP_GPIO_CFG_VCOMP_RXO_CMP   AM_HAL_PIN_18_CMPAD1

//*****************************************************************************
//
// Convenience macros for enabling and disabling pins by function.
//
//*****************************************************************************
#define am_bsp_pin_enable(name)                                               \
    am_hal_gpio_pin_config(AM_BSP_GPIO_ ## name, AM_BSP_GPIO_CFG_ ## name);

#define am_bsp_pin_disable(name)                                              \
    am_hal_gpio_pin_config(AM_BSP_GPIO_ ## name, AM_HAL_PIN_DISABLE);

#ifdef __cplusplus
}
#endif

#endif // AM_BSP_GPIO_H
