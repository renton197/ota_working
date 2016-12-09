//*****************************************************************************
//
//! @file coding_standard.c
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
#include "am_bootloader.h"
#include "image_boot_handlers.h"

//*****************************************************************************
//
// Macro definitions
//
//*****************************************************************************
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
    AMOTA_STATUS_UNKNOWN_ERROR,
    AMOTA_STATUS_MAX
}eAmotaStatus;


/* FW header information */
typedef struct
{
    uint32_t    version;
    uint32_t    fwLength;
    uint32_t    fwCrc;
    uint32_t    fwStartAddr;
    uint32_t    fwDataType;
    uint32_t    receivedBytes;
}
amotaHeaderInfo_t;

/* FW header information */
typedef struct
{
    uint16_t    offset;
    uint16_t    len;                        // data plus checksum
    eAmotaCommand type;
    uint8_t     data[AMOTA_PACKET_SIZE];
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
}
amotasCb;


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
        AttsHandleValueNtf(pConn->connId, AMOTAS_TX_HDL, len, buf);
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

static void
amotas_set_fw_addr(void)
{
    // TODO: get real flash info here
    amotasCb.newFwFlashInfo.addr = 0;
    amotasCb.newFwFlashInfo.offset = 0;

    uint32_t ui32TestSpaceLeft;
    bool bResult;

    bResult = image_get_storage_information_internal(g_psBootImage, 
                                                amotasCb.fwHeader.fwLength,
                                                &amotasCb.newFwFlashInfo.addr,
                                                &ui32TestSpaceLeft);
    if(bResult == true)
    {
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

static void
amotas_write2flash(uint16_t len, uint8_t *buf, uint32_t addr)
{
    // TODO: write to flash here
    WsfTrace("write to flash addr = 0x%x, len = 0x%x", addr, len);

    //
    // Check the target flash address to ensure we do not operation the wrong address
    //
    if((uint32_t)g_psBootImage->pui32StorageAddressNewImage > addr)
    {
        //
        // application is trying to write to wrong address 
        //
        return;
    }


    //RMA: Add flash operation here
    if(image_flash_write_from_sram( (uint32_t*)addr, (uint32_t*)buf, len))
    {
        WsfTrace("flash write succeeded.");
    }
    else
    {
        WsfTrace("flash write failed.");
    }
}

static bool_t
amotas_verify_firmware_crc(void)
{
    
    // read back the whole firmware image from flash and calculate CRC
    bool bResult = false;
    uint32_t ui32CRC = 0;
    ui32CRC = am_bootloader_fast_crc32(&amotasCb.fwHeader.fwStartAddr,  
                                                                        amotasCb.fwHeader.fwLength);

    return (ui32CRC == amotasCb.fwHeader.fwCrc);
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
amotas_packet_handler(eAmotaCommand cmd, uint16_t len, uint8_t *buf)
{
    eAmotaStatus status = AMOTA_STATUS_SUCCESS;
    uint8_t data[4] = {0};
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
            BYTES_TO_UINT32(amotasCb.fwHeader.version, buf);
            BYTES_TO_UINT32(amotasCb.fwHeader.fwLength, buf + 4);
            BYTES_TO_UINT32(amotasCb.fwHeader.fwCrc, buf + 8);
            BYTES_TO_UINT32(amotasCb.fwHeader.fwStartAddr, buf + 12);
            BYTES_TO_UINT32(amotasCb.fwHeader.fwDataType, buf + 16);
            BYTES_TO_UINT32(amotasCb.fwHeader.receivedBytes, buf + 16);
            amotas_set_fw_addr();
            amotasCb.state = AMOTA_STATE_GETTING_FW;
#ifdef AMOTA_DEBUG_ON
            WsfTrace("============= fw header start ===============");
            WsfTrace("version = 0x%x", amotasCb.fwHeader.version);
            WsfTrace("fwLength = 0x%x", amotasCb.fwHeader.fwLength);
            WsfTrace("fwCrc = 0x%x", amotasCb.fwHeader.fwCrc);
            WsfTrace("fwStartAddr = 0x%x", amotasCb.fwHeader.fwStartAddr);
            WsfTrace("fwDataType = 0x%x", amotasCb.fwHeader.fwDataType);
            WsfTrace("receivedBytes = 0x%x", amotasCb.fwHeader.receivedBytes);
            WsfTrace("============= fw header end ===============");
#endif
            data[0] = ((amotasCb.newFwFlashInfo.offset) & 0xff);
            data[1] = ((amotasCb.newFwFlashInfo.offset >> 8) & 0xff);
            data[2] = ((amotasCb.newFwFlashInfo.offset >> 16) & 0xff);
            data[3] = ((amotasCb.newFwFlashInfo.offset >> 24) & 0xff);
            amotas_reply_to_client(cmd, AMOTA_STATUS_SUCCESS, data, sizeof(data));
        break;

        case AMOTA_CMD_FW_DATA:
            amotas_write2flash(len, buf, amotasCb.newFwFlashInfo.addr + amotasCb.newFwFlashInfo.offset);
            amotasCb.newFwFlashInfo.offset += len;
            data[0] = ((amotasCb.newFwFlashInfo.offset) & 0xff);
            data[1] = ((amotasCb.newFwFlashInfo.offset >> 8) & 0xff);
            data[2] = ((amotasCb.newFwFlashInfo.offset >> 16) & 0xff);
            data[3] = ((amotasCb.newFwFlashInfo.offset >> 24) & 0xff);
            amotas_reply_to_client(cmd, AMOTA_STATUS_SUCCESS, data, sizeof(data));
        break;

        case AMOTA_CMD_FW_VERIFY:
            if (amotas_verify_firmware_crc())
            {
                amotas_reply_to_client(cmd, AMOTA_STATUS_SUCCESS, NULL, 0);
                amotasCb.state = AMOTA_STATE_VERIFY;
            }
            else
            {
                amotas_reply_to_client(cmd, AMOTA_STATUS_CRC_ERROR, NULL, 0);
            }
        break;

        case AMOTA_CMD_FW_RESET:
            amotas_reply_to_client(cmd, AMOTA_STATUS_SUCCESS, NULL, 0);
            amotas_reset_board();
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
    for (int i = 0; i < DM_CONN_MAX; i++)
        amotasCb.conn[i].connId = DM_CONN_ID_NONE;
}

void
amotas_conn_close(dmConnId_t connId)
{
    /* clear connection */
    amotasCb.conn[connId - 1].connId = DM_CONN_ID_NONE;
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
        calDataCrc = CalcCrc32(amotasCb.pkt.len - AMOTA_CRC_SIZE_IN_PKT, amotasCb.pkt.data);
#ifdef AMOTA_DEBUG_ON
        WsfTrace("calDataCrc = 0x%x", calDataCrc);
        WsfTrace("peerCrc = 0x%x", peerCrc);
#endif

        if (peerCrc != calDataCrc)
        {
            amotas_reply_to_client(amotasCb.pkt.type, AMOTA_STATUS_CRC_ERROR, NULL, 0);
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
amotas_start(dmConnId_t connId, uint8_t amotaCccIdx)
{
    /* set conn id */
    amotasCb.conn[connId - 1].connId = connId;
    amotasCb.conn[connId - 1].amotaToSend = TRUE;
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
    switch(pMsg->event)
    {
        case DM_CONN_OPEN_IND:
            amotas_conn_open((dmEvt_t *) pMsg);
        break;
        case DM_CONN_UPDATE_IND:
            amotas_conn_update((dmEvt_t *) pMsg);
        break;
        
        default:
            break;
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
