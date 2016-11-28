//*****************************************************************************
//
//! @file am_hal_ttp.h
//!
//! @brief Functions for handling the "two time program" interface.
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
#ifndef AM_HAL_TTP_H
#define AM_HAL_TTP_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Function prototypes
//
//*****************************************************************************
extern int am_hal_ttp_unlock(uint32_t ui32Keyval, uint8_t *pui8_1024Bytes);

#ifdef __cplusplus
}
#endif

#endif // AM_HAL_TTP_H

//*****************************************************************************
//
// End Doxygen group.
//! @}
//
//*****************************************************************************

