//*****************************************************************************
//
//! @file am_devices_p5qpcm.h
//!
//! @brief Driver for the Micron P5Q PCM SPI Flash.
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

#ifndef AM_DEVICES_P5QPCM_H
#define AM_DEVICES_P5QPCM_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Global definitions for flash commands
//
//*****************************************************************************
#define AM_DEVICES_P5QPCM_WREN            0x06        // Write enable
#define AM_DEVICES_P5QPCM_WRDI            0x04        // Write disable
#define AM_DEVICES_P5QPCM_RDID            0x9E        // Read Identification
#define AM_DEVICES_P5QPCM_RDRSR           0x05        // Read status register
#define AM_DEVICES_P5QPCM_WRSR            0x01        // Write status register
#define AM_DEVICES_P5QPCM_READ            0x03        // Read data bytes
#define AM_DEVICES_P5QPCM_PP              0x22        // Page program (bit-alterable)
#define AM_DEVICES_P5QPCM_SE              0xD8        // Sector Erase
#define AM_DEVICES_P5QPCM_BE              0xC7        // Bulk Erase

//*****************************************************************************
//
// Global definitions for the flash status register
//
//*****************************************************************************
#define AM_DEVICES_P5QPCM_SRWD           0x80        // Status register write protect
#define AM_DEVICES_P5QPCM_BP3            0x40        // Block protect 3
#define AM_DEVICES_P5QPCM_TB             0x20        // Top/Bottom bit
#define AM_DEVICES_P5QPCM_BP2            0x10        // Block protect 2
#define AM_DEVICES_P5QPCM_BP1            0x08        // Block protect 1
#define AM_DEVICES_P5QPCM_BP0            0x04        // Block protect 0
#define AM_DEVICES_P5QPCM_WEL            0x02        // Write enable latch
#define AM_DEVICES_P5QPCM_WIP            0x01        // Write in progress

//*****************************************************************************
//
// Function pointers for SPI write and read.
//
//*****************************************************************************
typedef bool (*am_devices_p5qpcm_write_t)(uint32_t ui32Module,
                                          uint32_t ui32ChipSelect,
                                          uint32_t *pui32Data,
                                          uint32_t ui32NumBytes,
                                          uint32_t ui32Options);

typedef bool (*am_devices_p5qpcm_read_t)(uint32_t ui32Module,
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
am_devices_p5qpcm_t;

//*****************************************************************************
//
// External function definitions.
//
//*****************************************************************************
extern void am_devices_p5qpcm_init(am_hal_iom_spi_device_t *psIOMSettings,
                                   am_devices_p5qpcm_write_t pfnWriteFunc,
                                   am_devices_p5qpcm_read_t pfnReadFunc);

extern uint8_t am_devices_p5qpcm_status(void);

extern uint32_t am_devices_p5qpcm_id(void);

extern void am_devices_p5qpcm_read(uint8_t *pui8RxBuffer,
                                   uint32_t ui32ReadAddress,
                                   uint32_t ui32NumBytes);

extern void am_devices_p5qpcm_write(uint8_t *ui8TxBuffer,
                                    uint32_t ui32WriteAddress,
                                    uint32_t ui32NumBytes);

extern void am_devices_p5qpcm_mass_erase(void);

extern void am_devices_p5qpcm_sector_erase(uint32_t ui32SectorAddress);

#ifdef __cplusplus
}
#endif

#endif // AM_DEVICES_P5QPCM_H

