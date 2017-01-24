//*****************************************************************************
//
//! @file amotas_main.c
//!
//! @brief Description of the purpose of the c file.
//!
//! This file is a dummy c file used to demonstrate some important aspects of
//! the Ambiq Micro coding standard.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "wsf_types.h"
#include "wsf_assert.h"
#include "wsf_trace.h"
#include "bstream.h"
#include "att_api.h"
#include "svc_ch.h"
#include "svc_amotas.h"
#include "app_api.h"
#include "app_hw.h"
#include "amotas_api.h"
#include "am_util_debug.h"
#include "crc32.h"

#include "am_mcu_apollo.h"
#include "am_devices.h"
#include "am_bsp.h"
#include "am_util.h"
#include "am_bootloader.h"
#include "image_boot_handlers.h"

#include "exactle_fit_amota_multi_boot_config.h"

//*****************************************************************************
//
// Macro definitions
//
//*****************************************************************************
#define AMOTA_SPI_FLASH_STORAGE_START_ADDRESS 0 //fixed start address defined by user

/* amota states */
typedef enum
{
    AMOTA_STATE_INIT,
    AMOTA_STATE_GETTING_FW,
    AMOTA_STATE_VERIFY,
    AMOTA_STATE_COMPLETE,
    AMOTA_STATE_MAX
}eAmotaState;

/* amota commands */
typedef enum
{
    AMOTA_CMD_UNKNOWN,
    AMOTA_CMD_FW_HEADER,
    AMOTA_CMD_FW_DATA,
    AMOTA_CMD_FW_VERIFY,
    AMOTA_CMD_FW_RESET,
    AMOTA_CMD_MAX
}eAmotaCommand;

/* amota status */
typedef enum
{
    AMOTA_STATUS_SUCCESS,
    AMOTA_STATUS_CRC_ERROR,
    AMOTA_STATUS_INVALID_HEADER_INFO,
    AMOTA_STATUS_INVALID_PKT_LENGTH,
    AMOTA_STATUS_INSUFFICIENT_BUFFER,
    AMOTA_STATUS_INSUFFICIENT_FLASH,
    AMOTA_STATUS_UNKNOWN_ERROR,
    AMOTA_STATUS_MAX
}eAmotaStatus;


/* FW header information */
typedef struct
{
    uint32_t    encrypted;
    uint32_t    fwStartAddr;
    uint32_t    fwLength;
    uint32_t    fwCrc;
    uint32_t    overridePin;            // RFU
    uint32_t    overridePolarity;       // RFU
    uint32_t    appStackPointer;        // RFU
    uint32_t    appProgramCouter;       // RFU
    uint32_t    version;
    uint32_t    fwDataType;             //binary type
    uint32_t    storageType;
    uint32_t    reserved;               // RFU

}
amotaHeaderInfo_t;

/* FW header information */
typedef struct
{
    uint16_t    offset;
    uint16_t    len;                        // data plus checksum
    eAmotaCommand type;
    uint8_t     data[AMOTA_PACKET_SIZE]  __attribute__((aligned(4)));   //--RMA
}
amotaPacket_t;

/* Connection control block */
typedef struct
{
    dmConnId_t    connId;               /* Connection ID */
    bool_t        amotaToSend;          /* amotas notify ready to be sent on this channel */
}
amotasConn_t;


typedef struct
{
    uint32_t    addr;
    uint32_t    offset;
}
amotasNewFwFlashInfo_t;


/* Control block */
static struct
{
    amotasConn_t            conn[DM_CONN_MAX];    /* connection control block */
    bool_t                  txReady;              /* TRUE if ready to send notifications */
    wsfHandlerId_t          appHandlerId;
    AmotasCfg_t             cfg;                  /* configurable parameters */
    eAmotaState             state;
    amotaHeaderInfo_t       fwHeader;
    amotaPacket_t           pkt;
    amotasNewFwFlashInfo_t  newFwFlashInfo;
    wsfTimer_t              resetTimer;           /* reset timer after OTA update done */
}
amotasCb;

// data structure for external spi flash operation
typedef struct
{
    uint8_t     writeBuffer[AM_DEVICES_SPIFLASH_PAGE_SIZE]   __attribute__((aligned(4)));   //--RMA
    uint16_t    bufferIndex;
}amotasSpiFlashOp_t;

amotasSpiFlashOp_t amotasSpiFlash = {
    .bufferIndex = 0,
};

static void
amotas_conn_open(dmEvt_t *pMsg)
{
    hciLeConnCmplEvt_t *evt = (hciLeConnCmplEvt_t*) pMsg;
    amotasCb.txReady = TRUE;

    WsfTrace("connection opened");
    WsfTrace("handle = 0x%x", evt->handle);
    WsfTrace("role = 0x%x", evt->role);
    WsfTrace("addr = %02x%02x%02x%02x%02x%02x", evt->peerAddr[0], evt->peerAddr[1],
        evt->peerAddr[2], evt->peerAddr[3], evt->peerAddr[4], evt->peerAddr[5]);
    WsfTrace("connInterval = 0x%x", evt->connInterval);
    WsfTrace("connLatency = 0x%x", evt->connLatency);
    WsfTrace("supTimeout = 0x%x", evt->supTimeout);
}

static void
amotas_conn_update(dmEvt_t *pMsg)
{
    hciLeConnUpdateCmplEvt_t *evt = (hciLeConnUpdateCmplEvt_t*) pMsg;

    WsfTrace("connection update status = 0x%x", evt->status);
    WsfTrace("handle = 0x%x", evt->handle);
    WsfTrace("connInterval = 0x%x", evt->connInterval);
    WsfTrace("connLatency = 0x%x", evt->connLatency);
    WsfTrace("supTimeout = 0x%x", evt->supTimeout);
}

static void
amotas_reset_board(void)
{
    //
    // Perform a POI reset
    //
    am_hal_reset_poi();
}

void
amotas_reset_timer_expired(wsfMsgHdr_t *pMsg)
{
    WsfTrace("amotas_reset_board");
    am_util_delay_ms(10);
    amotas_reset_board();
}


static amotasConn_t*
amotas_find_next2send(void)
{
    amotasConn_t *pConn = amotasCb.conn;
    uint8_t i;

    for (i = 0; i < DM_CONN_MAX; i++, pConn++)
    {
        if (pConn->connId != DM_CONN_ID_NONE && pConn->amotaToSend)
        {
            //if (AttsCccEnabled(pConn->connId, cccIdx))
            return pConn;
        }
    }
    return NULL;
}

static void
amotas_send_data(uint8_t *buf, uint16_t len)
{
    amotasConn_t *pConn = amotas_find_next2send();
    /* send notification */
    if (pConn)
    {
        WsfTrace("Send to connId = %d", pConn->connId);
        AttsHandleValueNtf(pConn->connId, AMOTAS_TX_HDL, len, buf);
    } else
        WsfTrace("Invalid Conn");
}

static void
amotas_reply_to_client(eAmotaCommand cmd, eAmotaStatus status, uint8_t *data, uint16_t len)
{
    uint8_t buf[ATT_DEFAULT_PAYLOAD_LEN] = {0};
    buf[0] = (len + 1) & 0xff;
    buf[1] = ((len + 1) >> 8) & 0xff;
    buf[2] = cmd;
    buf[3] = status;
    if (len > 0)
        memcpy(buf + 4, data, len);
    amotas_send_data(buf, len + 4);
}

//return true if success, otherwise false
static bool
amotas_set_fw_addr(void)
{
    bool bResult = false;

    amotasCb.newFwFlashInfo.addr = 0;
    amotasCb.newFwFlashInfo.offset = 0;

    //
    // Check storage type
    //
    if(amotasCb.fwHeader.storageType == AMOTA_FW_STORAGE_INTERNAL)
    {
        //storage in internal flash
        uint32_t ui32TestSpaceLeft;

        bResult = image_get_storage_information_internal(g_psBootImage, 
                                                    amotasCb.fwHeader.fwLength,
                                                    &amotasCb.newFwFlashInfo.addr,
                                                    &ui32TestSpaceLeft);
        if(bResult == true)
        {
#ifdef __BATCH_ERASE_INTERNAL__
            bool bFlag = image_flash_erase((uint32_t *)amotasCb.newFwFlashInfo.addr,amotasCb.fwHeader.fwLength);
            if(bFlag == true)
            {
                WsfTrace("Internal flash erase done.");
            }
            else
            {
                WsfTrace("Internal flash erase failed.");
            }
#endif // __BATCH_ERASE_INTERNAL__
            WsfTrace("storage address = 0x%x, space left in flash = %d bytes", 
                               amotasCb.newFwFlashInfo.addr, ui32TestSpaceLeft);
        }
        else
        {
            WsfTrace("target image length = %d bytes, space left in flash = %d bytes", 
                               amotasCb.fwHeader.fwLength, ui32TestSpaceLeft);
            WsfTrace("not enough space left");
        }

    }
    else if(amotasCb.fwHeader.storageType == AMOTA_FW_STORAGE_EXTERNAL)
    {
        //storage in external flash

        //
        // initialize spi interface with external flash
        //
        am_hal_iom_config(AM_BSP_FLASH_IOM, &g_sIOMConfig);

        //
        // configure pins for iom interface
        //
        configure_spiflash_pins();

        //
        // Initialize the spiflash driver with the IOM information for the second
        // flash device.
        //
        am_devices_spiflash_init(&g_sSpiFlash);

        //
        // Erase necessary sectors in the flash according to length of the image.
        // Starting from a fixed address. (in this case, 0)
        image_spiflash_erase(AMOTA_SPI_FLASH_STORAGE_START_ADDRESS, amotasCb.fwHeader.fwLength);

        //
        // update target address information
        //
        amotasCb.newFwFlashInfo.addr = AMOTA_SPI_FLASH_STORAGE_START_ADDRESS;

        bResult = true;
    }
    else
    {
        // reserved state
    }
    return bResult;
}

static bool amotas_write2external_flash(uint16_t len, uint8_t *buf, uint32_t addr, bool lastPktFlag)
{
    uint16_t ui16BytesRemaining = len;
    uint32_t ui32TargetAddress = 0;
    uint8_t ui8PageCount = 0;
    uint16_t ui16TempBufIndex = 0;
    bool bResult = false;

    //
    // Set up IOM1 SPI pins and turn on the IOM for this operation.
    //
    am_bsp_iom_spi_pins_enable(AM_BSP_FLASH_IOM);
    am_hal_iom_enable(AM_BSP_FLASH_IOM);

    //
    // Write to flash when there is data more than 1 page size
    //
    while((amotasSpiFlash.bufferIndex + ui16BytesRemaining) >= AM_DEVICES_SPIFLASH_PAGE_SIZE)
    {
        // move data into buffer
        for(uint16_t i = 0; i < AM_DEVICES_SPIFLASH_PAGE_SIZE - amotasSpiFlash.bufferIndex; i++)
        {   
            // avoid using memcpy
            amotasSpiFlash.writeBuffer[amotasSpiFlash.bufferIndex + i] = buf[ui16TempBufIndex];
            ui16TempBufIndex++;
        }
        ui16BytesRemaining -= (AM_DEVICES_SPIFLASH_PAGE_SIZE - amotasSpiFlash.bufferIndex);
        ui32TargetAddress = (addr + ui8PageCount*AM_DEVICES_SPIFLASH_PAGE_SIZE) & 0xFFFFFF00;

        am_devices_spiflash_write(amotasSpiFlash.writeBuffer, ui32TargetAddress, 
                                    AM_DEVICES_SPIFLASH_PAGE_SIZE); //make sure to write to page boundary

        // read back and check
        uint32_t* temp = malloc(AM_DEVICES_SPIFLASH_PAGE_SIZE);
        am_devices_spiflash_read((uint8_t*)temp, ui32TargetAddress, AM_DEVICES_SPIFLASH_PAGE_SIZE);
            
        bResult = memcmp((uint8_t*)temp, amotasSpiFlash.writeBuffer, AM_DEVICES_SPIFLASH_PAGE_SIZE);
        free(temp);
        amotasSpiFlash.bufferIndex = 0;
        if(bResult != false)
        {
            // there is write failure happened.
            WsfTrace("spi flash write failed. address 0x%x. length %d", ui32TargetAddress, AM_DEVICES_SPIFLASH_PAGE_SIZE);
            return false;   
        }
        ui8PageCount++;

        WsfTrace("spi flash write succeeded to address 0x%x. length %d", ui32TargetAddress, AM_DEVICES_SPIFLASH_PAGE_SIZE);
        bResult = true;
    }
   
    if(ui16BytesRemaining != 0)
    {
        for(uint16_t i = 0; i < ui16BytesRemaining; i++)
        {   
            // avoid using memcpy
            amotasSpiFlash.writeBuffer[amotasSpiFlash.bufferIndex + i] = buf[ui16TempBufIndex];
            ui16TempBufIndex++;
        }
        amotasSpiFlash.bufferIndex += ui16BytesRemaining;    
        bResult = true;
    }

    if(lastPktFlag == true)
    {
        // this is the last packet
        // write to flash even if data is not 256 bytes
        ui32TargetAddress = (addr + ui8PageCount*AM_DEVICES_SPIFLASH_PAGE_SIZE) & 0xFFFFFF00;

        am_devices_spiflash_write(amotasSpiFlash.writeBuffer, ui32TargetAddress, 
                                    AM_DEVICES_SPIFLASH_PAGE_SIZE); //make sure to write to page boundary

        // read back and check
        uint32_t* temp = malloc(ui16BytesRemaining + amotasSpiFlash.bufferIndex + 1);
        am_devices_spiflash_read((uint8_t*)temp, ui32TargetAddress, ui16BytesRemaining + amotasSpiFlash.bufferIndex + 1);
            
        bool bResult = memcmp((uint8_t*)temp, amotasSpiFlash.writeBuffer, ui16BytesRemaining + amotasSpiFlash.bufferIndex + 1);
        free(temp);
        if(bResult != false)
        {
            // there is write failure happened.
            WsfTrace("spi flash write last pkt failed. address 0x%x. length %d", ui32TargetAddress, ui16BytesRemaining + amotasSpiFlash.bufferIndex + 1);
            amotasSpiFlash.bufferIndex = 0;
            return false;   
        }

        bResult = true;
        WsfTrace("spi flash write last pkt succeeded to address 0x%x. length %d", ui32TargetAddress, ui16BytesRemaining + amotasSpiFlash.bufferIndex + 1);
        amotasSpiFlash.bufferIndex = 0;
    }
    else
    {
        WsfTrace("spi flash write not performed. Buffer depth %d.", amotasSpiFlash.bufferIndex);
        bResult = true;
    }

    //
    // Disable IOM1 SPI pins and turn off the IOM
    //
    am_bsp_iom_spi_pins_disable(AM_BSP_FLASH_IOM);
    am_hal_iom_disable(AM_BSP_FLASH_IOM);

    //
    // If we get here, operations are done correctly
    //
    return bResult; 
}

static bool
amotas_write2flash(uint16_t len, uint8_t *buf, uint32_t addr)
{
    bool bResult = false;

    WsfTrace("write to flash addr = 0x%x, len = 0x%x", addr, len);

    //
    // Check storage type
    //
    if(amotasCb.fwHeader.storageType == AMOTA_FW_STORAGE_INTERNAL)
    {
        // write to internal flash

        //
        // Check the target flash address to ensure we do not operation the wrong address
        //
        if((uint32_t)amotasCb.newFwFlashInfo.addr > addr)
        {
            //
            // application is trying to write to wrong address 
            //
            return false;
        }

        bResult = image_flash_write_from_sram( (uint32_t*)addr, (uint32_t*)buf, len);
        if(bResult == true)
        {
            WsfTrace("flash write succeeded.");
        }
        else
        {
            WsfTrace("flash write failed.");
        }
    }
    else if(amotasCb.fwHeader.storageType == AMOTA_FW_STORAGE_EXTERNAL)
    {
        // write to external flash
        bResult = amotas_write2external_flash(len, buf, addr - amotasCb.newFwFlashInfo.addr, false);
    }
    else
    {
        // reserved state
    }

    return bResult;
}

static bool_t
amotas_verify_firmware_crc(void)
{
    // read back the whole firmware image from flash and calculate CRC
    uint32_t ui32CRC = 0;
    
    //
    // Check storage type
    //
    if(amotasCb.fwHeader.storageType == AMOTA_FW_STORAGE_INTERNAL)
    {
        // check crc in internal flash
        ui32CRC = am_bootloader_fast_crc32((uint32_t *)amotasCb.newFwFlashInfo.addr,  
                                             amotasCb.fwHeader.fwLength);
    }
    else if(amotasCb.fwHeader.storageType == AMOTA_FW_STORAGE_EXTERNAL)
    {
        //
        // Check crc in external flash
        // Set up IOM1 SPI pins and turn on the IOM for this operation.
        //
        am_bsp_iom_spi_pins_enable(AM_BSP_FLASH_IOM);
        am_hal_iom_enable(AM_BSP_FLASH_IOM);

        // read from spi flash and calculate CRC32
        uint8_t* temp = malloc(AMOTA_PACKET_SIZE);     //use packet size as buffer size

        for(uint16_t i = 0; i < (amotasCb.fwHeader.fwLength / AMOTA_PACKET_SIZE); i++)
        {
            am_devices_spiflash_read((uint8_t*)temp, 
                (AMOTA_SPI_FLASH_STORAGE_START_ADDRESS + i*AMOTA_PACKET_SIZE), 
                AMOTA_PACKET_SIZE);

            am_bootloader_partial_crc32(temp, AMOTA_PACKET_SIZE, &ui32CRC);
        }

        uint32_t ui32Remainder = amotasCb.fwHeader.fwLength % AMOTA_PACKET_SIZE;
        if(ui32Remainder)
        {
            am_devices_spiflash_read((uint8_t*)temp, 
                (AMOTA_SPI_FLASH_STORAGE_START_ADDRESS + amotasCb.fwHeader.fwLength - ui32Remainder), ui32Remainder);

            am_bootloader_partial_crc32(temp, ui32Remainder, &ui32CRC);
        }
        
        free(temp);

        //
        // Disable IOM1 SPI pins and turn off the IOM for this operation.
        //
        am_bsp_iom_spi_pins_disable(AM_BSP_FLASH_IOM);
        am_hal_iom_disable(AM_BSP_FLASH_IOM);

    }
    else
    {
        // reserved state
    }

    return (ui32CRC == amotasCb.fwHeader.fwCrc);
}

static void
amotas_update_flag_page(void)
{
    //
    // Update flash flag page here
    //
    am_bootloader_image_t FlagImage;
    FlagImage.pui32LinkAddress = (uint32_t*)amotasCb.fwHeader.fwStartAddr;
    FlagImage.ui32NumBytes = amotasCb.fwHeader.fwLength;
    FlagImage.ui32CRC = amotasCb.fwHeader.fwCrc;

    //override pin is not used here.
    FlagImage.ui32OverrideGPIO = 0xffffffff;        
    FlagImage.ui32OverridePolarity = 0x00000000;

   
    //
    // Check storage type
    //
    if(amotasCb.fwHeader.storageType == AMOTA_FW_STORAGE_INTERNAL)
    {
        FlagImage.pui32StackPointer = (uint32_t*)(((uint32_t*)amotasCb.newFwFlashInfo.addr)[0]);
        FlagImage.pui32ResetVector = (uint32_t*)(((uint32_t*)amotasCb.newFwFlashInfo.addr)[1]);
 
        FlagImage.ui32Options = BOOT_NEW_IMAGE_INTERNAL_FLASH;
        FlagImage.pui32StorageAddressNewImage = (uint32_t*)amotasCb.newFwFlashInfo.addr;
    }
    else if(amotasCb.fwHeader.storageType == AMOTA_FW_STORAGE_EXTERNAL)
    {
        //
        // Set up IOM1 SPI pins and turn on the IOM for this operation.
        //
        am_bsp_iom_spi_pins_enable(AM_BSP_FLASH_IOM);
        am_hal_iom_enable(AM_BSP_FLASH_IOM);
       
        // read application stack pointer and reset vector value
        uint32_t ui32Temp[2];
        
        am_devices_spiflash_read((uint8_t*)ui32Temp, 
                                    (uint32_t)(AMOTA_SPI_FLASH_STORAGE_START_ADDRESS)
                                    , 8);
        //
        // Disable IOM1 SPI pins and turn off the IOM for this operation.
        //
        am_bsp_iom_spi_pins_disable(AM_BSP_FLASH_IOM);
        am_hal_iom_disable(AM_BSP_FLASH_IOM);

        FlagImage.pui32StackPointer = (uint32_t*)(ui32Temp[0]);
        FlagImage.pui32ResetVector = (uint32_t*)(ui32Temp[1]);
 
        FlagImage.ui32Options = BOOT_NEW_IMAGE_EXTERNAL_FLASH;
        FlagImage.pui32StorageAddressNewImage = AMOTA_SPI_FLASH_STORAGE_START_ADDRESS;  // always address 0 in external flash
    }
    else
    {
        // reserved state
    }

    FlagImage.bEncrypted = false;

    am_bootloader_flag_page_update(&FlagImage, (uint32_t *)g_psBootImage);
    
}

void
amotas_packet_handler(eAmotaCommand cmd, uint16_t len, uint8_t *buf)
{
    eAmotaStatus status = AMOTA_STATUS_SUCCESS;
    uint8_t data[4] = {0};
    bool bResult = false;
    uint32_t ver, fwCrc;
    ver = fwCrc = 0;
    bool_t resumeTransfer = FALSE;

    WsfTrace("received packet cmd = 0x%x, len = 0x%x", cmd, len);

    switch(cmd)
    {
        case AMOTA_CMD_FW_HEADER:
            if (len < AMOTA_FW_HEADER_SIZE)
            {
                status = AMOTA_STATUS_INVALID_HEADER_INFO;
                amotas_reply_to_client(cmd, status, NULL, 0);
                break;
            }

            if (amotasCb.state == AMOTA_STATE_GETTING_FW)
            {
                BYTES_TO_UINT32(ver, buf + 32);
                BYTES_TO_UINT32(fwCrc, buf + 12);

                if (ver == amotasCb.fwHeader.version && fwCrc == amotasCb.fwHeader.fwCrc)
                    resumeTransfer = TRUE;
            }
            
            BYTES_TO_UINT32(amotasCb.fwHeader.encrypted, buf);
            BYTES_TO_UINT32(amotasCb.fwHeader.fwStartAddr, buf + 4);
            BYTES_TO_UINT32(amotasCb.fwHeader.fwLength, buf + 8);
            BYTES_TO_UINT32(amotasCb.fwHeader.fwCrc, buf + 12);
            BYTES_TO_UINT32(amotasCb.fwHeader.version, buf + 32);
            BYTES_TO_UINT32(amotasCb.fwHeader.fwDataType, buf + 36);
            BYTES_TO_UINT32(amotasCb.fwHeader.storageType, buf + 40);

            if (resumeTransfer)
            {
                WsfTrace("OTA process start from offset = 0x%x", amotasCb.newFwFlashInfo.offset);
                WsfTrace("beginning of flash addr = 0x%x", amotasCb.newFwFlashInfo.addr);
            }
            else
            {
                WsfTrace("OTA process start from beginning");
                bResult = amotas_set_fw_addr();
                
                if(bResult == false)
                {
                    amotas_reply_to_client(cmd, AMOTA_STATUS_INSUFFICIENT_FLASH, NULL, 0);
                    amotasCb.state = AMOTA_STATE_INIT;
                    return;
                }
                
                amotasCb.state = AMOTA_STATE_GETTING_FW;
            }
#ifdef AMOTA_DEBUG_ON
            WsfTrace("============= fw header start ===============");
            WsfTrace("encrypted = 0x%x", amotasCb.fwHeader.encrypted);
            WsfTrace("version = 0x%x", amotasCb.fwHeader.version);
            WsfTrace("fwLength = 0x%x", amotasCb.fwHeader.fwLength);
            WsfTrace("fwCrc = 0x%x", amotasCb.fwHeader.fwCrc);
            WsfTrace("fwStartAddr = 0x%x", amotasCb.fwHeader.fwStartAddr);
            WsfTrace("fwDataType = 0x%x", amotasCb.fwHeader.fwDataType);
            WsfTrace("storageType = 0x%x", amotasCb.fwHeader.storageType);
            WsfTrace("============= fw header end ===============");
#endif // AMOTA_DEBUG_ON
            data[0] = ((amotasCb.newFwFlashInfo.offset) & 0xff);
            data[1] = ((amotasCb.newFwFlashInfo.offset >> 8) & 0xff);
            data[2] = ((amotasCb.newFwFlashInfo.offset >> 16) & 0xff);
            data[3] = ((amotasCb.newFwFlashInfo.offset >> 24) & 0xff);
            amotas_reply_to_client(cmd, AMOTA_STATUS_SUCCESS, data, sizeof(data));
        break;

        case AMOTA_CMD_FW_DATA:
            bResult = amotas_write2flash(len, buf, amotasCb.newFwFlashInfo.addr + amotasCb.newFwFlashInfo.offset);

            if(bResult == false)
            {
                data[0] = ((amotasCb.newFwFlashInfo.offset) & 0xff);
                data[1] = ((amotasCb.newFwFlashInfo.offset >> 8) & 0xff);
                data[2] = ((amotasCb.newFwFlashInfo.offset >> 16) & 0xff);
                data[3] = ((amotasCb.newFwFlashInfo.offset >> 24) & 0xff);
                amotas_reply_to_client(cmd, AMOTA_STATUS_CRC_ERROR, data, sizeof(data));
            }
            else
            {
                amotasCb.newFwFlashInfo.offset += len;
    
                //
                // Trigger a write operation to the flash
                //
                if((amotasCb.newFwFlashInfo.offset == amotasCb.fwHeader.fwLength)&&(amotasCb.fwHeader.storageType == AMOTA_FW_STORAGE_EXTERNAL))
                {
                    amotas_write2external_flash(0, NULL, amotasCb.newFwFlashInfo.offset, true);
                }
                data[0] = ((amotasCb.newFwFlashInfo.offset) & 0xff);
                data[1] = ((amotasCb.newFwFlashInfo.offset >> 8) & 0xff);
                data[2] = ((amotasCb.newFwFlashInfo.offset >> 16) & 0xff);
                data[3] = ((amotasCb.newFwFlashInfo.offset >> 24) & 0xff);
                amotas_reply_to_client(cmd, AMOTA_STATUS_SUCCESS, data, sizeof(data));
            }
        break;

        case AMOTA_CMD_FW_VERIFY:
            amotasCb.state = AMOTA_STATE_VERIFY;
            if (amotas_verify_firmware_crc())
            {
                WsfTrace("crc verify success");

                amotas_reply_to_client(cmd, AMOTA_STATUS_SUCCESS, NULL, 0);

                //
                // Update flash flag page here
                //
                amotas_update_flag_page();
            }
            else
            {
                WsfTrace("crc verify failed");
                amotas_reply_to_client(cmd, AMOTA_STATUS_CRC_ERROR, NULL, 0);
            }
        break;

        case AMOTA_CMD_FW_RESET:
            WsfTrace("Apollo will reset itself in 500ms.");
            amotas_reply_to_client(cmd, AMOTA_STATUS_SUCCESS, NULL, 0);
            
            //
            // Delay here to let packet go through the RF before we reset
            //
            WsfTimerStartMs(&amotasCb.resetTimer, 500);
        break;

        default:
        break;
    }
}


//*****************************************************************************
//
//! @brief initialize amota service
//!
//! @param handlerId - connection handle
//! @param pCfg - configuration parameters
//!
//! @return None
//
//*****************************************************************************
void
amotas_init(wsfHandlerId_t handlerId, AmotasCfg_t *pCfg)
{
    memset(&amotasCb, 0, sizeof(amotasCb));
    amotasCb.appHandlerId = handlerId;
    amotasCb.txReady = FALSE;
    amotasCb.state = AMOTA_STATE_INIT;
    amotasCb.resetTimer.handlerId = handlerId;
    for (int i = 0; i < DM_CONN_MAX; i++)
        amotasCb.conn[i].connId = DM_CONN_ID_NONE;
}

void
amotas_conn_close(dmConnId_t connId)
{
    /* clear connection */
    amotasCb.conn[connId - 1].connId = DM_CONN_ID_NONE;
    amotasCb.conn[connId - 1].amotaToSend = FALSE;

    amotasCb.pkt.offset = 0;
    amotasCb.pkt.len = 0;
    amotasCb.pkt.type = AMOTA_CMD_UNKNOWN;
}

uint8_t
amotas_write_cback(dmConnId_t connId, uint16_t handle, uint8_t operation,
                       uint16_t offset, uint16_t len, uint8_t *pValue, attsAttr_t *pAttr)
{
    uint8_t dataIdx = 0;
    uint32_t calDataCrc = 0;
#if 0
    uint16_t i = 0;
    WsfTrace("============= data arrived start ===============");
    for (i = 0; i < len; i++)
    {
        am_util_debug_printf("%x\t", pValue[i]);
    }
    WsfTrace("");
    WsfTrace("============= data arrived end ===============");
#endif
    if (amotasCb.pkt.offset == 0 && len < AMOTA_HEADER_SIZE_IN_PKT)
    {
        WsfTrace("Invalid packet!!!");
        amotas_reply_to_client(AMOTA_CMD_FW_HEADER, AMOTA_STATUS_INVALID_PKT_LENGTH, NULL, 0);
        return ATT_SUCCESS;
    }

    // new packet
    if (amotasCb.pkt.offset == 0)
    {
        BYTES_TO_UINT16(amotasCb.pkt.len, pValue);
        amotasCb.pkt.type = (eAmotaCommand) pValue[2];
        dataIdx = 3;
#ifdef AMOTA_DEBUG_ON
        WsfTrace("pkt.len = 0x%x", amotasCb.pkt.len);
        WsfTrace("pkt.type = 0x%x", amotasCb.pkt.type);
#endif
    }

    // make sure we have enough space for new data
    if (amotasCb.pkt.offset + len - dataIdx > AMOTA_PACKET_SIZE)
    {
        WsfTrace("not enough buffer size!!!");
        amotas_reply_to_client(amotasCb.pkt.type, AMOTA_STATUS_INSUFFICIENT_BUFFER, NULL, 0);
        return ATT_SUCCESS;
    }

    // copy new data into buffer and also save crc into it if it's the last frame in a packet
    // 4 bytes crc is included in pkt length
    memcpy(amotasCb.pkt.data + amotasCb.pkt.offset, pValue + dataIdx, len - dataIdx);
    amotasCb.pkt.offset += (len - dataIdx);

    // whole packet received
    if (amotasCb.pkt.offset >= amotasCb.pkt.len) {
        uint32_t peerCrc = 0;
        // check CRC
        BYTES_TO_UINT32(peerCrc, amotasCb.pkt.data + amotasCb.pkt.len - AMOTA_CRC_SIZE_IN_PKT);
        calDataCrc = CalcCrc32(0xFFFFFFFFU, amotasCb.pkt.len - AMOTA_CRC_SIZE_IN_PKT, amotasCb.pkt.data);
#ifdef AMOTA_DEBUG_ON
        WsfTrace("calDataCrc = 0x%x", calDataCrc);
        WsfTrace("peerCrc = 0x%x", peerCrc);
#endif

        if (peerCrc != calDataCrc)
        {
            amotas_reply_to_client(amotasCb.pkt.type, AMOTA_STATUS_CRC_ERROR, NULL, 0);

            // clear pkt
            amotasCb.pkt.offset = 0;
            amotasCb.pkt.type = AMOTA_CMD_UNKNOWN;
            amotasCb.pkt.len = 0;

            return ATT_SUCCESS;
        }

        amotas_packet_handler(amotasCb.pkt.type, amotasCb.pkt.len - AMOTA_CRC_SIZE_IN_PKT, amotasCb.pkt.data);
        // clear pkt after handled
        amotasCb.pkt.offset = 0;
        amotasCb.pkt.type = AMOTA_CMD_UNKNOWN;
        amotasCb.pkt.len = 0;
    }

    return ATT_SUCCESS;
}

void
amotas_start(dmConnId_t connId, uint8_t timerEvt, uint8_t amotaCccIdx)
{
    /* set conn id */
    amotasCb.conn[connId - 1].connId = connId;
    amotasCb.conn[connId - 1].amotaToSend = TRUE;

    amotasCb.resetTimer.msg.event = timerEvt;
}

void
amotas_stop(dmConnId_t connId)
{
    /* clear connection */
    amotasCb.conn[connId - 1].connId = DM_CONN_ID_NONE;
    amotasCb.conn[connId - 1].amotaToSend = FALSE;
}


//*****************************************************************************
//
//! @brief initialize amota service
//!
//! @param pMsg - WSF message
//!
//! @return None
//
void amotas_proc_msg(wsfMsgHdr_t *pMsg)
{
    if (pMsg->event == DM_CONN_OPEN_IND)
    {
        amotas_conn_open((dmEvt_t *) pMsg);
    }
    else if (pMsg->event == DM_CONN_UPDATE_IND)
    {
        amotas_conn_update((dmEvt_t *) pMsg);
    }
    else if (pMsg->event == amotasCb.resetTimer.msg.event)
    {
        amotas_reset_timer_expired(pMsg);
    }
}


/*
void
coding_standard_function_name(uint32_t ui32InputVariable, uint32_t *ui32Output,
                              char *pcStr, char *pcStr2)
{
    uint8_t ui8Index, ui8LocalVar;

    ui8Index = 2;

    switch(ui8LocalVar)
    {
        case 1:
            do_things();
            do_more_things();
        break;

        case 2:
            do_different_things();
        break;

        default:
            do_default_things();
        break;
    }

    while(1);

    //
    // Check something.
    //
    if(something)
    {
        //
        // If something is true, we do_this()
        //
        do_this();
    }
    else
    {
        //
        // Otherwise, we do_this_other_thing()
        //
        do_this_other_thing();
    }

    do
    {
        //
        // Things
        //
        do_some_stuff();
    }
    while(condition);
}
*/
