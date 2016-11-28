//*****************************************************************************
//
//! @file am_devices_spifram.c
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

#include "am_mcu_apollo.h"
#include "am_devices_spifram.h"

// IOM Queue size depends upon this.
#define TRANSFERSIZE (256)

//*****************************************************************************
//
// Global variables.
//
//*****************************************************************************
am_devices_spifram_t *g_psIOMSettings;
static volatile bool bComplete = false;
am_hal_iom_callback_t iom_yield;
am_hal_iom_callback_t iom_callback;


//*****************************************************************************
//
// Static helper functions (These should be HAL calls.)
//
//*****************************************************************************
static void
IOMCallBack(void)
{
    bComplete = true;
}

static void
IOMYield(void)
{
    while(!bComplete);
    bComplete = false;
}

//*****************************************************************************
//
//! @brief Configure the callbacks for the IOM to enable nonblocking functionality.
//!
//! @param pfnYield - pointer to function used while waiting for the IOM to complete.
//! @param pfnCallback - pointer to function used when transaction are complete.
//!
//! This function configures the function pointers used during IOM transactions
//! to allow for nonblocking transfers. If not configured the transfers will be
//! blocking.
//!
//! @return None.
//
//*****************************************************************************
void
am_devices_iom_callbacks_config(am_hal_iom_callback_t pfnYield,
                                am_hal_iom_callback_t pfnCallback)
{
    if (pfnYield && pfnCallback)
    {
        iom_yield = pfnYield;
        iom_callback = pfnCallback;
    }
}

//*****************************************************************************
//
//! @brief Initialize the spifram driver.
//!
//! @param psIOMSettings - IOM device structure describing the target spifram.
//! @param pfnWriteFunc - Function to use for spi writes.
//! @param pfnReadFunc - Function to use for spi reads.
//!
//! This function should be called before any other am_devices_spifram
//! functions. It is used to set tell the other functions how to communicate
//! with the external spifram hardware.
//!
//! The \e pfnWriteFunc and \e pfnReadFunc variables may be used to provide
//! alternate implementations of SPI write and read functions respectively. If
//! they are left set to 0, the default functions am_hal_iom_spi_write() and
//! am_hal_iom_spi_read() will be used.
//!
//! @return None.
//
//*****************************************************************************
void
am_devices_spifram_init(am_devices_spifram_t *psIOMSettings)
{
    //
    // Initialize the IOM settings from the application.
    //
    g_psIOMSettings = psIOMSettings;

    //
    // Initialize the IOM callbacks.
    //
    am_devices_iom_callbacks_config(IOMYield, IOMCallBack);
}

//*****************************************************************************
//
//! @brief Reads the current status of the external fram
//!
//! @param ui32DeviceNumber - Device number of the external fram
//!
//! This function reads the status register of the external fram, and returns
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
am_devices_spifram_status(void)
{
    am_hal_iom_buffer(1) psResponse;

    //
    // Send the command and read the response.
    //
    if (g_psIOMSettings->hal_iom_mode == IOM_QUEUE)
    {
        am_hal_iom_queue_spi_read(g_psIOMSettings->ui32IOMModule,
                            g_psIOMSettings->ui32ChipSelect,
                            psResponse.words, 1,
                            AM_HAL_IOM_OFFSET(AM_DEVICES_SPIFRAM_RDRSR),
                            iom_callback);
        iom_yield();
    }
    else if (g_psIOMSettings->hal_iom_mode == IOM_POLL)
    {
        am_hal_iom_spi_read(g_psIOMSettings->ui32IOMModule,
                            g_psIOMSettings->ui32ChipSelect,
                            psResponse.words, 1,
                            AM_HAL_IOM_OFFSET(AM_DEVICES_SPIFRAM_RDRSR));
    }

    //
    // Return the status read from the external fram.
    //
    return psResponse.bytes[0];
}

//*****************************************************************************
//
//! @brief Reads the ID register for the external fram
//!
//! @param ui32DeviceNumber - Device number of the external fram
//!
//! This function reads the ID register of the external fram, and returns the
//! result as a 32-bit unsigned integer value. The processor will block during
//! the data transfer process, but will return as soon as the ID register had
//! been read. The ID contents for this fram only contains 24 bits of data, so
//! the result will be stored in the lower 24 bits of the return value.
//!
//! @return 32-bit ID register contents
//
//*****************************************************************************
uint32_t
am_devices_spifram_id(uint8_t *manufacturerID, uint16_t *productID)
{
    am_hal_iom_buffer(4) psResponse;

    //
    // Send a command to read the ID register in the external fram.
    //
    //
    // Check to see if the callback pointer is valid.
    //
    if (g_psIOMSettings->hal_iom_mode == IOM_QUEUE)
    {
        //
        // If so, use a queue call with a callback.
        //
        am_hal_iom_queue_spi_read(g_psIOMSettings->ui32IOMModule,
                            g_psIOMSettings->ui32ChipSelect,
                            psResponse.words, 4,
                            AM_HAL_IOM_OFFSET(AM_DEVICES_SPIFRAM_RDID),
                            iom_callback);
        iom_yield();
    }
    else if (g_psIOMSettings->hal_iom_mode == IOM_POLL)
    {
        am_hal_iom_spi_read(g_psIOMSettings->ui32IOMModule,
                            g_psIOMSettings->ui32ChipSelect,
                            psResponse.words, 4,
                            AM_HAL_IOM_OFFSET(AM_DEVICES_SPIFRAM_RDID));
    }

    //
    // Return the ID
    //
    /* Shift values to separate manuf and prod IDs */
    //manufacturerID = (a[0]);
    //productID = (a[2] << 8) + a[3];
    *manufacturerID = (psResponse.words[0] & 0x000000FF);
    *productID = ((psResponse.words[0] & 0xFF000000 ) >> 24) +
                 ((psResponse.words[0] & 0x00FF0000 ) >>  8);

    return psResponse.words[0];
}

//*****************************************************************************
//
//! @brief Reads the contents of the external fram into a buffer.
//!
//! @param ui32DeviceNumber - Device number of the external fram
//! @param pui8RxBuffer - Buffer to store the received data from the fram
//! @param ui32ReadAddress - Address of desired data in external fram
//! @param ui32NumBytes - Number of bytes to read from external fram
//!
//! This function reads the external fram at the provided address and stores
//! the received data into the provided buffer location. This function will
//! only store ui32NumBytes worth of data.
//
//*****************************************************************************
void
am_devices_spifram_read(uint8_t *pui8RxBuffer, uint32_t ui32ReadAddress,
                        uint32_t ui32NumBytes)
{
    uint32_t i, ui32BytesRemaining, ui32TransferSize, ui32CurrentReadAddress;
    uint8_t *pui8Dest;

    uint32_t pui32WriteBuffer[1];
    uint8_t *pui8WritePtr;

    uint32_t pui32ReadBuffer[TRANSFERSIZE / sizeof(uint32_t)];
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
        // Set the transfer size to either TRANSFERSIZE,
        // or the number of remaining bytes, whichever is smaller.
        //
        ui32TransferSize = ui32BytesRemaining > TRANSFERSIZE ? TRANSFERSIZE : ui32BytesRemaining;

        // 16 bit address.
        pui8WritePtr[0] = AM_DEVICES_SPIFRAM_READ;
        pui8WritePtr[1] = (ui32CurrentReadAddress & 0x0000FF00) >> 8;
        pui8WritePtr[2] = ui32CurrentReadAddress & 0x000000FF;
        pui8WritePtr[3] = 0;

        //
        // Send the read command.
        //
        if (g_psIOMSettings->hal_iom_mode == IOM_QUEUE)
        {
            am_hal_iom_queue_spi_write(g_psIOMSettings->ui32IOMModule,
                                 g_psIOMSettings->ui32ChipSelect,
                                 pui32WriteBuffer, 4,
                                 AM_HAL_IOM_CS_LOW | AM_HAL_IOM_RAW,
                                 iom_callback);
            iom_yield();
            am_hal_iom_queue_spi_read(g_psIOMSettings->ui32IOMModule,
                                g_psIOMSettings->ui32ChipSelect, pui32ReadBuffer,
                                ui32TransferSize, AM_HAL_IOM_RAW,
                                 iom_callback);
            iom_yield();
        }
        else
        {
            am_hal_iom_spi_write(g_psIOMSettings->ui32IOMModule,
                                 g_psIOMSettings->ui32ChipSelect,
                                 pui32WriteBuffer, 4,
                                 AM_HAL_IOM_CS_LOW | AM_HAL_IOM_RAW);

            am_hal_iom_spi_read(g_psIOMSettings->ui32IOMModule,
                                g_psIOMSettings->ui32ChipSelect, pui32ReadBuffer,
                                ui32TransferSize, AM_HAL_IOM_RAW);
        }

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
//
//! @brief Programs the given range of fram addresses.
//!
//! @param ui32DeviceNumber - Device number of the external fram
//! @param pui8TxBuffer - Buffer to write the external fram data from
//! @param ui32WriteAddress - Address to write to in the external fram
//! @param ui32NumBytes - Number of bytes to write to the external fram
//!
//! This function uses the data in the provided pui8TxBuffer and copies it to
//! the external fram at the address given by ui32WriteAddress. It will copy
//! exactly ui32NumBytes of data from the original pui8TxBuffer pointer. The
//! user is responsible for ensuring that they do not overflow the target fram
//! memory or underflow the pui8TxBuffer array
//
//*****************************************************************************
void
am_devices_spifram_write(uint8_t *pui8TxBuffer, uint32_t ui32WriteAddress,
                         uint32_t ui32NumBytes)
{
    uint32_t ui32DestAddress;
    uint32_t ui32BytesRemaining;
    uint32_t ui32TransferSize = 8;
    uint8_t *pui8Source;

    am_hal_iom_buffer(1) psEnableCommand;
    am_hal_iom_buffer(TRANSFERSIZE) psWriteCommand;

    //
    // Prepare the command for write-enable.
    //
    psEnableCommand.bytes[0] = AM_DEVICES_SPIFRAM_WREN;

    //
    // Set the total number of bytes, and the starting transfer destination.
    //
    ui32BytesRemaining = ui32NumBytes;
    pui8Source = pui8TxBuffer;
    ui32DestAddress = ui32WriteAddress;

    while ( ui32BytesRemaining )
    {
        //
        // Set up a write command, 16 bit address.
        //
        psWriteCommand.bytes[0] = AM_DEVICES_SPIFRAM_WRITE;
        psWriteCommand.bytes[1] = (ui32DestAddress & 0x0000FF00) >> 8;
        psWriteCommand.bytes[2] = ui32DestAddress & 0x000000FF;
        psWriteCommand.bytes[3] = 0;

        //
        // Set the transfer size to either 32, or the number of remaining
        // bytes, whichever is smaller.
        //
        ui32TransferSize = ui32BytesRemaining > TRANSFERSIZE ? TRANSFERSIZE : ui32BytesRemaining;

        //
        // Fill the rest of the command buffer with the data that we actually
        // want to write to fram.
        //
        for ( int i = 0; i < ui32TransferSize; i++ )
        {
            psWriteCommand.bytes[4 + i] = pui8Source[i];
        }

        //
        // Send the write-enable command to prepare the external fram for
        // program operations, and wait for the write-enable latch to be set in
        // the status register.
        //
        if (g_psIOMSettings->hal_iom_mode == IOM_QUEUE)
        {
            am_hal_iom_queue_spi_write(g_psIOMSettings->ui32IOMModule,
                                 g_psIOMSettings->ui32ChipSelect,
                                 psEnableCommand.words,
                                 1, AM_HAL_IOM_RAW,
                                 iom_callback);
            iom_yield();

            //
            // Send the write command.
            //
            am_hal_iom_queue_spi_write(g_psIOMSettings->ui32IOMModule,
                                 g_psIOMSettings->ui32ChipSelect,
                                 psWriteCommand.words,
                                 (ui32TransferSize + 4), AM_HAL_IOM_RAW,
                                 iom_callback);
            iom_yield();
        }
        else
        {
            am_hal_iom_spi_write(g_psIOMSettings->ui32IOMModule,
                                 g_psIOMSettings->ui32ChipSelect,
                                 psEnableCommand.words,
                                 1, AM_HAL_IOM_RAW);

            //
            // Send the write command.
            //
            am_hal_iom_spi_write(g_psIOMSettings->ui32IOMModule,
                                 g_psIOMSettings->ui32ChipSelect,
                                 psWriteCommand.words,
                                 (ui32TransferSize + 4), AM_HAL_IOM_RAW);
        }

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


