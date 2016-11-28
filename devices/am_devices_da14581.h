//*****************************************************************************
//
//! @file am_devices_da14581.h
//!
//! @brief Support functions for the Dialog Semiconductor DA14581 BTLE radio.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_DEVICES_DA14581_H
#define AM_DEVICES_DA14581_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Defines
//
//*****************************************************************************
#define AM_DEVICES_DA14581_UART_MODE         (0)
#define AM_DEVICES_DA14581_SPI_MODE          (1)

#define AM_DEVICES_DA14581_SPI_XPORT_CTS     (0x06)
#define AM_DEVICES_DA14581_SPI_XPORT_NOT_CTS (0x07)

//*****************************************************************************
//
// DA14581 device structure
//
//*****************************************************************************
typedef struct
{
    //
    // MODE UART vs IOM SPI
    //
    uint32_t ui32Mode;

    //
    // IOM Module #
    //
    uint32_t ui32IOMModule;

    //
    // IOM Chip Select NOTE: this driver uses GPIO for chip selects
    //
    uint32_t ui32IOMChipSelect;

    //
    // GPIO # for DA14581 DREADY signal
    //
    uint32_t ui32DREADY;
}
am_devices_da14581_t;

#ifdef __cplusplus
}
#endif

#endif // AM_DEVICES_DA14581_H
