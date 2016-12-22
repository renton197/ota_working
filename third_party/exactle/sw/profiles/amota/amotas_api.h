//*****************************************************************************
//
//! @file amotas_api.h
//!
//! @brief Brief description of the header. No need to get fancy here.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AMOTAS_API_H
#define AMOTAS_API_H

#include "wsf_timer.h"
#include "att_api.h"

// enable debug print for AMOTA profile
#define AMOTA_DEBUG_ON

#ifdef __cplusplus
extern "C"
{
#endif
//*****************************************************************************
//
// Macro definitions
//
//*****************************************************************************
#define AMOTA_PACKET_SIZE           512 + 16    // Bytes
#define AMOTA_LENGTH_SIZE_IN_PKT    2
#define AMOTA_CMD_SIZE_IN_PKT       1
#define AMOTA_CRC_SIZE_IN_PKT       4
#define AMOTA_HEADER_SIZE_IN_PKT    AMOTA_LENGTH_SIZE_IN_PKT + AMOTA_CMD_SIZE_IN_PKT

#define AMOTA_FW_HEADER_SIZE        18

/*! Configurable parameters */
typedef struct
{
    //! Short description of each member should go here.
    uint32_t reserved;
}
AmotasCfg_t;

//*****************************************************************************
//
// External variable definitions
//
//*****************************************************************************


//*****************************************************************************
//
// External function definitions.
//
//*****************************************************************************

//*****************************************************************************
//
// function definitions
//
//*****************************************************************************

void amotas_init(wsfHandlerId_t handlerId, AmotasCfg_t *pCfg);

void amotas_proc_msg(wsfMsgHdr_t *pMsg);

uint8_t amotas_write_cback(dmConnId_t connId, uint16_t handle, uint8_t operation,
                       uint16_t offset, uint16_t len, uint8_t *pValue, attsAttr_t *pAttr);

void amotas_start(dmConnId_t connId, uint8_t timerEvt, uint8_t amotaCccIdx);

void amotas_stop(dmConnId_t connId);

extern void amotas_conn_close(dmConnId_t connId);

#ifdef __cplusplus
}
#endif

#endif // AMOTAS_API_H
