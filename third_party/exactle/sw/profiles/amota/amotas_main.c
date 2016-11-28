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
    uint16_t    version;
    uint32_t    fwLength;
    uint32_t    fwCrc;
    uint32_t    fwStartAddr;
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

/* Connection control block */
typedef struct
{
    uint32_t    addr;               /* Connection ID */
    uint32_t    offset;          /* amotas notify ready to be sent on this channel */
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
    amotasCb.txReady = TRUE;
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
amotas_reply_to_client(eAmotaCommand cmd, eAmotaStatus status)
{
    uint8_t buf[ATT_DEFAULT_PAYLOAD_LEN] = {0};
    buf[0] = 1;
    buf[1] = 0;
    buf[2] = cmd;
    buf[3] = status;
    amotas_send_data(buf, sizeof(buf));
}

static void
amotas_set_fw_addr(void)
{
    // TODO: get real flash info here
    amotasCb.newFwFlashInfo.addr = 0;
    amotasCb.newFwFlashInfo.offset = 0;
}

static void
amotas_write2flash(uint16_t len, uint8_t *buf, uint32_t addr)
{
    // TODO: write to flash here
    WsfTrace("write to flash addr = 0x%x, len = 0x%x", addr, len);
}

static void
amotas_reset_board(void)
{
}


static uint8_t
amotas_packet_handler(eAmotaCommand cmd, uint16_t len, uint8_t *buf)
{
    eAmotaStatus status = AMOTA_STATUS_SUCCESS;
    WsfTrace("received packet cmd = 0x%x, len = 0x%x", cmd, len);
    switch(cmd)
    {
        case AMOTA_CMD_FW_HEADER:
            if (len < AMOTA_FW_HEADER_SIZE)
            {
                status = AMOTA_STATUS_INVALID_HEADER_INFO;
                break;
            }
            BYTES_TO_UINT16(amotasCb.fwHeader.version, buf);
            BYTES_TO_UINT32(amotasCb.fwHeader.fwLength, buf + 2);
            BYTES_TO_UINT32(amotasCb.fwHeader.fwCrc, buf + 6);
            BYTES_TO_UINT32(amotasCb.fwHeader.fwStartAddr, buf + 10);
            BYTES_TO_UINT32(amotasCb.fwHeader.receivedBytes, buf + 14);
            amotas_set_fw_addr();
            amotasCb.state = AMOTA_STATE_GETTING_FW;
#ifdef AMOTA_DEBUG_ON
            WsfTrace("============= fw header start ===============");
            WsfTrace("version = 0x%x", amotasCb.fwHeader.version);
            WsfTrace("fwLength = 0x%x", amotasCb.fwHeader.fwLength);
            WsfTrace("fwCrc = 0x%x", amotasCb.fwHeader.fwCrc);
            WsfTrace("fwStartAddr = 0x%x", amotasCb.fwHeader.fwStartAddr);
            WsfTrace("receivedBytes = 0x%x", amotasCb.fwHeader.receivedBytes);
            WsfTrace("============= fw header end ===============");
#endif
        break;

        case AMOTA_CMD_FW_DATA:
            amotas_write2flash(len, buf, amotasCb.newFwFlashInfo.addr + amotasCb.newFwFlashInfo.offset);
            amotasCb.newFwFlashInfo.offset += len;
        break;

        case AMOTA_CMD_FW_VERIFY:
        break;

        case AMOTA_CMD_FW_RESET:
            amotas_reset_board();
        break;

        default:
        break;
    }
    return status;
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
    eAmotaStatus status = AMOTA_STATUS_SUCCESS;
    uint32_t calDataCrc = 0;
#ifdef AMOTA_DEBUG_ON
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
        amotas_reply_to_client(AMOTA_CMD_FW_HEADER, AMOTA_STATUS_INVALID_PKT_LENGTH);
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
        amotas_reply_to_client(amotasCb.pkt.type, AMOTA_STATUS_INSUFFICIENT_BUFFER);
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
            amotas_reply_to_client(amotasCb.pkt.type, AMOTA_STATUS_CRC_ERROR);
            return ATT_SUCCESS;
        }

        status = (eAmotaStatus) amotas_packet_handler(amotasCb.pkt.type, amotasCb.pkt.len - AMOTA_CRC_SIZE_IN_PKT, amotasCb.pkt.data);
        // clear pkt after handled
        amotasCb.pkt.offset = 0;
        amotasCb.pkt.type = AMOTA_CMD_UNKNOWN;
        amotasCb.pkt.len = 0;
        amotas_reply_to_client(amotasCb.pkt.type, status);
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
