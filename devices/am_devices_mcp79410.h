//*****************************************************************************
//
//! @file am_devices_mcp79410.h
//!
//! @brief This is a driver for the Micochip MCP79410 RTC.
//!
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************

#ifndef AM_DEVICES_MCP79410_H
#define AM_DEVICES_MCP79410_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Device Addresses
//
//*****************************************************************************
#define AM_DEVICES_MCP79410_ADDRESS_RTCC                 0x6F
#define AM_DEVICES_MCP79410_ADDRESS_EEPROM               0x57

//*****************************************************************************
//
// Register Defines
//
//*****************************************************************************

//*****************************************************************************
//
// Time Keeping
//
//*****************************************************************************
#define AM_DEVICES_MCP79410_RTCSEC          0x0
#define AM_DEVICES_MCP79410_RTCMIN          0x1
#define AM_DEVICES_MCP79410_RTCHOUR         0x2
#define AM_DEVICES_MCP79410_RTCWKDAY        0x3
#define AM_DEVICES_MCP79410_RTCDATE         0x4
#define AM_DEVICES_MCP79410_RTCMTH          0x5
#define AM_DEVICES_MCP79410_RTCYEAR         0x6

// Control
#define AM_DEVICES_MCP79410_CONTROL         0x7
#define AM_DEVICES_MCP79410_OSCTRIM         0x8
#define AM_DEVICES_MCP79410_EEUNLOCK        0x9

//*****************************************************************************
//
// Alarm 0 Register description.
//
//*****************************************************************************
#define AM_DEVICES_MCP79410_ALM0SEC         0xA
#define AM_DEVICES_MCP79410_ALM0MIN         0xB
#define AM_DEVICES_MCP79410_ALM0HOUR        0xC
#define AM_DEVICES_MCP79410_ALM0WKDAY       0xD
#define AM_DEVICES_MCP79410_ALM0DATE        0xE
#define AM_DEVICES_MCP79410_ALM0MTH         0xF

//*****************************************************************************
//
// Alarm 1 Register description.
//
//*****************************************************************************
#define AM_DEVICES_MCP79410_ALM1SEC         0x11
#define AM_DEVICES_MCP79410_ALM1MIN         0x12
#define AM_DEVICES_MCP79410_ALM1HOUR        0x13
#define AM_DEVICES_MCP79410_ALM1WKDAY       0x14
#define AM_DEVICES_MCP79410_ALM1DATE        0x15
#define AM_DEVICES_MCP79410_ALM1MTH         0x16

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
    // Bus address to use for I2C.
    //
    uint32_t ui32BusAddress;
}
am_devices_mcp79410_t;

//*****************************************************************************
//
//! The basic time structure used by the MCP79410.
//
//*****************************************************************************
typedef struct am_devices_mcp79410_time_struct
{
    uint32_t ReadError;
    uint32_t CenturyEnable;
    uint32_t Weekday;
    uint32_t Century;
    uint32_t Year;
    uint32_t Month;
    uint32_t DayOfMonth;
    uint32_t Hour;
    uint32_t Minute;
    uint32_t Second;
    uint32_t Hundredths;
}am_devices_mcp79410_time_t;

//*****************************************************************************
//
// External function definitions.
//
//*****************************************************************************
extern void am_devices_mcp79410_init(am_hal_iom_i2c_device_t *psIOMSettings);
extern int am_devices_mcp79410_start(void);
extern int am_devices_mcp79410_stop(void);
extern int am_devices_mcp79410_vbat_enable(void);
extern int am_devices_mcp79410_time_set(am_devices_mcp79410_time_t *pTime);
extern int am_devices_mcp79410_time_get(am_devices_mcp79410_time_t *pTime);
extern int am_devices_mcp79410_alarm_set(am_devices_mcp79410_time_t *pTime);
extern int am_devices_mcp79410_alarm_get(am_devices_mcp79410_time_t *pTime);

#ifdef __cplusplus
}
#endif

#endif // AM_DEVICES_MCP79410_H

