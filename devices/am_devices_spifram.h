//*****************************************************************************
//
//! @file am_devices_spifram.h
//!
//! @brief Generic spifram driver.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************

#ifndef AM_DEVICES_SPIFRAM_H
#define AM_DEVICES_SPIFRAM_H

//*****************************************************************************
//
// Global definitions for fram commands
//
//*****************************************************************************

#define AM_DEVICES_SPIFRAM_WRSR        0x01      /* Write Status Register */
#define AM_DEVICES_SPIFRAM_WRITE       0x02      /* Write Memory */
#define AM_DEVICES_SPIFRAM_READ        0x03      /* Read Memory */
#define AM_DEVICES_SPIFRAM_WRDI        0x04      /* Reset Write Enable Latch */
#define AM_DEVICES_SPIFRAM_RDRSR       0x05      /* Read Status Register */
#define AM_DEVICES_SPIFRAM_WREN        0x06      /* Write Enable Latch */
#define AM_DEVICES_SPIFRAM_RDID        0x9F      /* Read Device ID */

//*****************************************************************************
//
// Global definitions for the fram status register
//
//*****************************************************************************
#define AM_DEVICES_SPIFRAM_WEL         0x02        // Write enable latch
#define AM_DEVICES_SPIFRAM_BP0         0x04        // Block Protect 0
#define AM_DEVICES_SPIFRAM_BP1         0x08        // Block Protect 0
#define AM_DEVICES_SPIFRAM_WPEN        0x80        // Status Register Write Protect

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Function pointers for SPI write and read.
//
//*****************************************************************************
typedef bool (*am_devices_spifram_write_t)(uint32_t ui32Module,
                                            uint32_t ui32ChipSelect,
                                            uint32_t *pui32Data,
                                            uint32_t ui32NumBytes,
                                            uint32_t ui32Options);

typedef bool (*am_devices_spifram_read_t)(uint32_t ui32Module,
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
    //*************************************************************************
    // Parameters supplied by application.
    //*************************************************************************

    //
    // Module number to use for IOM access.
    //
    uint32_t ui32IOMModule;

    //
    // Chip Select number to use for IOM access.
    //
    uint32_t ui32ChipSelect;

    //
    // HAL IOM Mode, Polling, Non-Blocking, or Queued.
    //
    int     hal_iom_mode;
}
am_devices_spifram_t;

//! HAL IOM Polled mode.
#define IOM_POLL     (0)
//! HAL IOM Non-Blocking interrupt mode.
#define IOM_NONBLOCK (1)
//! HAL IOM Queued interrupt mode.
#define IOM_QUEUE    (2)

//*****************************************************************************
//
// External function definitions.
//
//*****************************************************************************
extern void am_devices_spifram_init(am_devices_spifram_t *psIOMSettings);

extern uint8_t am_devices_spifram_status(void);

extern uint32_t am_devices_spifram_id(uint8_t *mID, uint16_t *pID);


extern void am_devices_spifram_read(uint8_t *pui8RxBuffer,
                                     uint32_t ui32ReadAddress,
                                     uint32_t ui32NumBytes);

extern void am_devices_spifram_write(uint8_t *ui8TxBuffer,
                                      uint32_t ui32WriteAddress,
                                      uint32_t ui32NumBytes);

#ifdef __cplusplus
}
#endif

#endif // AM_DEVICES_SPIFRAM_H

