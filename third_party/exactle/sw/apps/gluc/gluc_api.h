/*************************************************************************************************/
/*!
 *  \file   gluc_api.h
 *
 *  \brief  Glucose sensor sample application interface.
 *
 *          $Date: 2012-06-07 11:59:12 -0700 (Thu, 07 Jun 2012) $
 *          $Revision: 331 $
 *
 *  Copyright (c) 2012 Wicentric, Inc., all rights reserved.
 *  Wicentric confidential and proprietary.
 *
 *  IMPORTANT.  Your use of this file is governed by a Software License Agreement
 *  ("Agreement") that must be accepted in order to download or otherwise receive a
 *  copy of this file.  You may not use or copy this file for any purpose other than
 *  as described in the Agreement.  If you do not agree to all of the terms of the
 *  Agreement do not use this file and delete all copies in your possession or control;
 *  if you do not have a copy of the Agreement, you must contact Wicentric, Inc. prior
 *  to any use, copying or further distribution of this software.
 */
/*************************************************************************************************/
#ifndef GLUC_API_H
#define GLUC_API_H

#include "wsf_os.h"

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/
/*************************************************************************************************/
/*!
 *  \fn     GlucStart
 *        
 *  \brief  Start the application.
 *
 *  \return None.
 */
/*************************************************************************************************/
void GlucStart(void);

/*************************************************************************************************/
/*!
 *  \fn     GlucHandlerInit
 *        
 *  \brief  Application handler init function called during system initialization.
 *
 *  \param  handlerID  WSF handler ID for App.
 *
 *  \return None.
 */
/*************************************************************************************************/
void GlucHandlerInit(wsfHandlerId_t handlerId);


/*************************************************************************************************/
/*!
 *  \fn     GlucHandler
 *        
 *  \brief  WSF event handler for the application.
 *
 *  \param  event   WSF event mask.
 *  \param  pMsg    WSF message.
 *
 *  \return None.
 */
/*************************************************************************************************/
void GlucHandler(wsfEventMask_t event, wsfMsgHdr_t *pMsg);

#ifdef __cplusplus
};
#endif

#endif /* GLUC_API_H */
