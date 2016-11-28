//*****************************************************************************
//
//! @file am_devices_spiscs.h
//!
//! @brief Slave-side functions for the SPISC protocol
//!
//! Slave-side functions for the SPI "switched configuration" protocol.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_DEVICES_SPISCS_H
#define AM_DEVICES_SPISCS_H

#ifdef __cplusplus
extern "C"
{
#endif
//*****************************************************************************
//
// Macro definitions
//
//*****************************************************************************

//*****************************************************************************
//
// External variable definitions
//
//*****************************************************************************

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern void am_devices_spiscs_init(void);
extern void am_devices_spiscs_fifo_service(uint32_t ui32Status);
extern void am_devices_spiscs_acc_service(uint32_t ui32Status);
extern void am_devices_spiscs_write(uint8_t *pui8Data, uint8_t ui8Size);
extern uint32_t am_devices_spiscs_read(uint8_t *pui8Data, uint32_t ui32MaxSize);
extern bool am_devices_spiscs_check(void);


#ifdef __cplusplus
}
#endif

#endif // AM_DEVICES_SPISCS_H

