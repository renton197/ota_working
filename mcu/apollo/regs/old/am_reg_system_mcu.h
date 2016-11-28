/*
 *-----------------------------------------------------------------------------
 * The confidential and proprietary information contained in this file may
 * only be used by a person authorised under and to the extent permitted
 * by a subsisting licensing agreement from ARM Limited.
 *
 *            (C) COPYRIGHT 2011-2012 ARM Limited.
 *                ALL RIGHTS RESERVED
 *
 * This entire notice must be reproduced on all copies of this file
 * and copies of this file may only be made by a person if such person is
 * permitted to do so under the terms of a subsisting license agreement
 * from ARM Limited.
 *
 *      SVN Information
 *
 *      Checked In          : $Date: 2012-03-14 10:10:18 +0000 (Wed, 14 Mar 2012) $
 *
 *      Revision            : $Revision: 204406 $
 *
 *      Release Information : Cortex-M0+ AT590-r0p1-00rel0
 *-----------------------------------------------------------------------------
 */

#ifndef __SYSTEM_MCU_H
#define __SYSTEM_MCU_H

extern uint32_t SystemFrequency;                   /*!< System Clock Frequency (Core Clock) */


/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system
 *         Initialise GPIO directions and values
 */
extern                   void SystemInit     (void);
#endif // __SYSTEM_MCU_H
