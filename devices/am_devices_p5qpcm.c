//*****************************************************************************
//
//! @file am_devices_p5qpcm.c
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

#include "am_mcu_apollo.h"
#include "am_devices_p5qpcm.h"

//*****************************************************************************
//
// Global variables.
//
//*****************************************************************************
am_hal_iom_spi_device_t *g_psIOMSettings;
static am_devices_p5qpcm_write_t g_pfnSpiWrite = 0;
static am_devices_p5qpcm_read_t g_pfnSpiRead = 0;

//*****************************************************************************
//
//! @brief ShortDesc
//!
//! @param
//!
//! LongDesc
//!
//! @return
//
//*****************************************************************************
void
am_devices_p5qpcm_init(am_hal_iom_spi_device_t *psIOMSettings,
                       am_devices_p5qpcm_write_t pfnWriteFunc,
                       am_devices_p5qpcm_read_t pfnReadFunc)
{
    //
    // Initialize the IOM settings for the P5QPCM.
    //
    g_psIOMSettings = psIOMSettings;

    g_pfnSpiWrite = pfnWriteFunc ? pfnWriteFunc :
        (am_devices_p5qpcm_write_t) am_hal_iom_spi_write;

    g_pfnSpiRead = pfnReadFunc ? pfnReadFunc :
        (am_devices_p5qpcm_read_t) am_hal_iom_spi_read;
}

//*****************************************************************************
//
//! @brief Reads the current status of the external flash
//!
//! @param ui32DeviceNumber - Device number of the external flash
//!
//! This function reads the status register of the external flash, and returns
//! the result as an 8-bit unsigned integer value. The processor will block
//! during the data transfer process, but will return as soon as the status
//! register had been read.
//!
//! Macro definitions for interpreting the contents of the status register are
//! included in the header file.
//!
//! @return 8-bit status register contents
//
//*****************************************************************************
uint8_t
am_devices_p5qpcm_status(void)
{
    am_hal_iom_buffer(1) psResponse;

    //
    // Send the command and read the response.
    //
    g_pfnSpiRead(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                 psResponse.words, 1,
                 AM_HAL_IOM_OFFSET(AM_DEVICES_P5QPCM_RDRSR));

    //
    // Return the status read from the external flash.
    //
    return psResponse.bytes[0];
}

//*****************************************************************************
//!
//! @brief Reads the ID register for the external flash
//!
//! @param ui32DeviceNumber - Device number of the external flash
//!
//! This function reads the ID register of the external flash, and returns the
//! result as a 32-bit unsigned integer value. The processor will block during
//! the data transfer process, but will return as soon as the ID register had
//! been read. The ID contents for this flash only contains 24 bits of data, so
//! the result will be stored in the lower 24 bits of the return value.
//!
//! @return 32-bit ID register contents
//!
//*****************************************************************************
uint32_t
am_devices_p5qpcm_id(void)
{
    am_hal_iom_buffer(3) psResponse;

    //
    // Send a command to read the ID register in the external flash.
    //
    g_pfnSpiRead(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                 psResponse.words, 3,
                 AM_HAL_IOM_OFFSET(AM_DEVICES_P5QPCM_RDID));

    //
    // Return the ID
    //
    return psResponse.words[0] & 0x00FFFFFF;
}

//*****************************************************************************
//
//! @brief Reads the contents of the external flash into a buffer.
//!
//! @param ui32DeviceNumber - Device number of the external flash
//! @param pui8RxBuffer - Buffer to store the received data from the flash
//! @param ui32ReadAddress - Address of desired data in external flash
//! @param ui32NumBytes - Number of bytes to read from external flash
//!
//! This function reads the external flash at the provided address and stores
//! the received data into the provided buffer location. This function will
//! only store ui32NumBytes worth of data.
//
//*****************************************************************************
void
am_devices_p5qpcm_read(uint8_t *pui8RxBuffer, uint32_t ui32ReadAddress,
                       uint32_t ui32NumBytes)
{
    uint32_t i, ui32BytesRemaining, ui32TransferSize, ui32CurrentReadAddress;
    uint8_t *pui8Dest;

    uint32_t pui32WriteBuffer[1];
    uint8_t *pui8WritePtr;

    uint32_t pui32ReadBuffer[16];
    uint8_t *pui8ReadPtr;

    pui8WritePtr = (uint8_t *)(&pui32WriteBuffer);
    pui8ReadPtr = (uint8_t *)(&pui32ReadBuffer);

    //
    // Set the total number of bytes,and the starting transfer destination.
    //
    ui32BytesRemaining = ui32NumBytes;
    pui8Dest = pui8RxBuffer;
    ui32CurrentReadAddress = ui32ReadAddress;

    while ( ui32BytesRemaining )
    {
        //
        // Set the transfer size to either 64, or the number of remaining
        // bytes, whichever is smaller.
        //
        ui32TransferSize = ui32BytesRemaining > 64 ? 64 : ui32BytesRemaining;

        pui8WritePtr[0] = AM_DEVICES_P5QPCM_READ;
        pui8WritePtr[1] = (ui32CurrentReadAddress & 0x00FF0000) >> 16;
        pui8WritePtr[2] = (ui32CurrentReadAddress & 0x0000FF00) >> 8;
        pui8WritePtr[3] = ui32CurrentReadAddress & 0x000000FF;

        //
        // Send the read command.
        //
        g_pfnSpiWrite(g_psIOMSettings->ui32Module,
                      g_psIOMSettings->ui32ChipSelect, pui32WriteBuffer, 4,
                      AM_HAL_IOM_CS_LOW | AM_HAL_IOM_RAW);

        g_pfnSpiRead(g_psIOMSettings->ui32Module,
                     g_psIOMSettings->ui32ChipSelect, pui32ReadBuffer,
                     ui32TransferSize, AM_HAL_IOM_RAW);

        //
        // Copy the received bytes over to the RxBuffer
        //
        for ( i = 0; i < ui32TransferSize; i++ )
        {
            pui8Dest[i] = pui8ReadPtr[i];
        }

        //
        // Update the number of bytes remaining and the destination.
        //
        ui32BytesRemaining -= ui32TransferSize;
        pui8Dest += ui32TransferSize;
        ui32CurrentReadAddress += ui32TransferSize;
    }
}

//*****************************************************************************
//!
//! @brief Programs the given range of flash addresses.
//!
//! @param ui32DeviceNumber - Device number of the external flash
//! @param pui8TxBuffer - Buffer to write the external flash data from
//! @param ui32WriteAddress - Address to write to in the external flash
//! @param ui32NumBytes - Number of bytes to write to the external flash
//!
//! This function uses the data in the provided pui8TxBuffer and copies it to
//! the external flash at the address given by ui32WriteAddress. It will copy
//! exactly ui32NumBytes of data from the original pui8TxBuffer pointer. The
//! user is responsible for ensuring that they do not overflow the target flash
//! memory or underflow the pui8TxBuffer array
//!
//*****************************************************************************
void
am_devices_p5qpcm_write(uint8_t *pui8TxBuffer, uint32_t ui32WriteAddress,
                        uint32_t ui32NumBytes)
{
    uint32_t i;
    uint32_t ui32DestAddress;
    uint32_t ui32BytesRemaining;
    uint32_t ui32TransferSize;
    uint8_t *pui8Source;

    am_hal_iom_buffer(1) psEnableCommand;
    am_hal_iom_buffer(64) psWriteCommand;

    //
    // Prepare the command for write-enable.
    //
    psEnableCommand.bytes[0] = AM_DEVICES_P5QPCM_WREN;

    //
    // Set the total number of bytes, and the starting transfer destination.
    //
    ui32BytesRemaining = ui32NumBytes;
    pui8Source = pui8TxBuffer;
    ui32DestAddress = ui32WriteAddress;

    while ( ui32BytesRemaining )
    {
        //
        // Set up a write command to hit the beginning of the next "chunk" of
        // flash.
        //
        psWriteCommand.bytes[0] = AM_DEVICES_P5QPCM_PP;
        psWriteCommand.bytes[1] = (ui32DestAddress & 0x00FF0000) >> 16;
        psWriteCommand.bytes[2] = (ui32DestAddress & 0x0000FF00) >> 8;
        psWriteCommand.bytes[3] = ui32DestAddress & 0x000000FF;

        //
        // Set the transfer size to either 32, or the number of remaining
        // bytes, whichever is smaller.
        //
        ui32TransferSize = ui32BytesRemaining > 32 ? 32 : ui32BytesRemaining;

        //
        // Fill the rest of the command buffer with the data that we actually
        // want to write to flash.
        //
        for ( i = 0; i < ui32TransferSize; i++ )
        {
            psWriteCommand.bytes[4 + i] = pui8Source[i];
        }

        //
        // Send the write-enable command to prepare the external flash for
        // program operations, and wait for the write-enable latch to be set in
        // the status register.
        //
        g_pfnSpiWrite(g_psIOMSettings->ui32Module,
                      g_psIOMSettings->ui32ChipSelect, psEnableCommand.words,
                      1, AM_HAL_IOM_RAW);

        while ( !(am_devices_p5qpcm_status() & AM_DEVICES_P5QPCM_WEL) );

        //
        // Send the write command.
        //
        g_pfnSpiWrite(g_psIOMSettings->ui32Module,
                      g_psIOMSettings->ui32ChipSelect, psWriteCommand.words,
                      (ui32TransferSize + 4), AM_HAL_IOM_RAW);

        //
        // Wait for status to indicate that the write is no longer in progress.
        //
        while ( am_devices_p5qpcm_status() & AM_DEVICES_P5QPCM_WIP );

        //
        // Update the number of bytes remaining, as well as the source and
        // destination pointers
        //
        ui32BytesRemaining -= ui32TransferSize;
        pui8Source += ui32TransferSize;
        ui32DestAddress += ui32TransferSize;
    }

    return;
}

//*****************************************************************************
//!
//! @brief Erases the entire contents of the external flash
//!
//! @param ui32DeviceNumber - Device number of the external flash
//!
//! This function uses the "Bulk Erase" instruction to erase the entire
//! contents of the external flash.
//!
//*****************************************************************************
void
am_devices_p5qpcm_mass_erase(void)
{
    am_hal_iom_buffer(1) psCommand;

    //
    // Send the write-enable command to prepare the external flash for program
    // operations.
    //
    psCommand.bytes[0] = AM_DEVICES_P5QPCM_WREN;
    g_pfnSpiWrite(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                  psCommand.words, 1, AM_HAL_IOM_RAW);

    //
    // Wait for the write enable latch status bit.
    //
    while ( !(am_devices_p5qpcm_status() & AM_DEVICES_P5QPCM_WEL) );

    //
    // Send the bulk erase command.
    //
    psCommand.bytes[0] = AM_DEVICES_P5QPCM_BE;
    g_pfnSpiWrite(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                  psCommand.words, 1, AM_HAL_IOM_RAW);

    //
    // Wait for status to indicate that the write is no longer in progress.
    //
    while ( am_devices_p5qpcm_status() & AM_DEVICES_P5QPCM_WIP );

    return;
}

//*****************************************************************************
//!
//! @brief Erases the contents of a single sector of flash
//!
//! @param ui32DeviceNumber - Device number of the external flash
//! @param ui32SectorAddress - Address to erase in the external flash
//!
//! This function erases a single sector of the external flash as specified by
//! ui32EraseAddress. The entire sector where ui32EraseAddress will
//! be erased.
//!
//*****************************************************************************
void
am_devices_p5qpcm_sector_erase(uint32_t ui32SectorAddress)
{
    am_hal_iom_buffer(4) psCommand;

    //
    // Send the write-enable command to prepare the external flash for program
    // operations.
    //
    psCommand.bytes[0] = AM_DEVICES_P5QPCM_WREN;
    g_pfnSpiWrite(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                  psCommand.words, 1, AM_HAL_IOM_RAW);

    //
    // Wait for the write enable latch status bit.
    //
    while ( !(am_devices_p5qpcm_status() & AM_DEVICES_P5QPCM_WEL) );

    //
    // Prepare the sector erase command, followed by the three-byte external
    // flash address.
    //
    psCommand.bytes[0] = AM_DEVICES_P5QPCM_SE;
    psCommand.bytes[1] = (ui32SectorAddress & 0x00FF0000) >> 16;
    psCommand.bytes[2] = (ui32SectorAddress & 0x0000FF00) >> 8;
    psCommand.bytes[3] = ui32SectorAddress & 0x000000FF;

    //
    // Send the command to erase the desired sector.
    //
    g_pfnSpiWrite(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                  psCommand.words, 4, AM_HAL_IOM_RAW);

    //
    // Wait for status to indicate that the write is no longer in progress.
    //
    while ( am_devices_p5qpcm_status() & AM_DEVICES_P5QPCM_WIP );

    return;
}
