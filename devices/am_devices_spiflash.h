//*****************************************************************************
//
//! @file am_devices_spiflash.h
//!
//! @brief Generic spiflash driver.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************

#ifndef AM_DEVICES_SPIFLASH_H
#define AM_DEVICES_SPIFLASH_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Global definitions for flash commands
//
//*****************************************************************************
#define AM_DEVICES_SPIFLASH_WREN        0x06        // Write enable
#define AM_DEVICES_SPIFLASH_WRDI        0x04        // Write disable
#define AM_DEVICES_SPIFLASH_RDID        0x9E        // Read Identification
#define AM_DEVICES_SPIFLASH_RDRSR       0x05        // Read status register
#define AM_DEVICES_SPIFLASH_WRSR        0x01        // Write status register
#define AM_DEVICES_SPIFLASH_READ        0x03        // Read data bytes
#define AM_DEVICES_SPIFLASH_PP          0x02        // Page program
#define AM_DEVICES_SPIFLASH_SE          0xD8        // Sector Erase
#define AM_DEVICES_SPIFLASH_BE          0xC7        // Bulk Erase

//*****************************************************************************
//
// Global definitions for the flash status register
//
//*****************************************************************************
#define AM_DEVICES_SPIFLASH_WEL         0x02        // Write enable latch
#define AM_DEVICES_SPIFLASH_WIP         0x01        // Write in progress

//*****************************************************************************
//
// Function pointers for SPI write and read.
//
//*****************************************************************************
typedef bool (*am_devices_spiflash_write_t)(uint32_t ui32Module,
                                            uint32_t ui32ChipSelect,
                                            uint32_t *pui32Data,
                                            uint32_t ui32NumBytes,
                                            uint32_t ui32Options);

typedef bool (*am_devices_spiflash_read_t)(uint32_t ui32Module,
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
am_devices_spiflash_t;

//*****************************************************************************
//
// External function definitions.
//
//*****************************************************************************
extern void am_devices_spiflash_init(am_devices_spiflash_t *psIOMSettings);

extern uint8_t am_devices_spiflash_status(void);

extern uint32_t am_devices_spiflash_id(void);

extern void am_devices_spiflash_read(uint8_t *pui8RxBuffer,
                                     uint32_t ui32ReadAddress,
                                     uint32_t ui32NumBytes);

extern void am_devices_spiflash_write(uint8_t *ui8TxBuffer,
                                      uint32_t ui32WriteAddress,
                                      uint32_t ui32NumBytes);

extern void am_devices_spiflash_mass_erase(void);

extern void am_devices_spiflash_sector_erase(uint32_t ui32SectorAddress);

#ifdef __cplusplus
}
#endif

#endif // AM_DEVICES_SPIFLASH_H

