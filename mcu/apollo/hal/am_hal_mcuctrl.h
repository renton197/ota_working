//*****************************************************************************
//
//! @file am_hal_mcuctrl.h
//!
//! @brief Functions for accessing and configuring the MCUCTRL.
//!
//! @addtogroup hal Hardware Abstraction Layer (HAL)
//! @addtogroup mcuctrl MCU Control (MCUCTRL)
//! @ingroup hal
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_HAL_MCUCTRL_H
#define AM_HAL_MCUCTRL_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Apollo Number Decode.
//
//*****************************************************************************
extern const uint32_t am_hal_mcuctrl_flash_size[];
extern const uint32_t am_hal_mcuctrl_sram_size[];

//*****************************************************************************
//
// FLASH Bank Power defines.
//
//*****************************************************************************
#define AM_HAL_MCUCTRL_FLASH_POWER_DOWN_NONE    0x0
#define AM_HAL_MCUCTRL_FLASH_POWER_DOWN_0       0x1
#define AM_HAL_MCUCTRL_FLASH_POWER_DOWN_1       0x2
#define AM_HAL_MCUCTRL_FLASH_POWER_DOWN_ALL     0x3

//*****************************************************************************
//
// SRAM Bank Power defines.
//
//*****************************************************************************
#define AM_HAL_MCUCTRL_SRAM_POWER_DOWN_NONE    0x0
#define AM_HAL_MCUCTRL_SRAM_POWER_DOWN_0       0x1
#define AM_HAL_MCUCTRL_SRAM_POWER_DOWN_1       0x2
#define AM_HAL_MCUCTRL_SRAM_POWER_DOWN_2       0x4
#define AM_HAL_MCUCTRL_SRAM_POWER_DOWN_3       0x8
#define AM_HAL_MCUCTRL_SRAM_POWER_DOWN_4       0x10
#define AM_HAL_MCUCTRL_SRAM_POWER_DOWN_5       0x20
#define AM_HAL_MCUCTRL_SRAM_POWER_DOWN_6       0x40
#define AM_HAL_MCUCTRL_SRAM_POWER_DOWN_7       0x80
#define AM_HAL_MCUCTRL_SRAM_POWER_DOWN_ALL     0xFF

//*****************************************************************************
//
//! MCUCTRL fault structure
//
//*****************************************************************************
typedef struct
{
    //
    //! ICODE bus fault occurred.
    //
    bool bICODE;

    //
    //! ICODE bus fault address.
    //
    uint32_t ui32ICODE;

    //
    //! DCODE bus fault occurred.
    //
    bool bDCODE;

    //
    //! DCODE bus fault address.
    //
    uint32_t ui32DCODE;

    //
    //! SYS bus fault occurred.
    //
    bool bSYS;

    //
    //! SYS bus fault address.
    //
    uint32_t ui32SYS;
}
am_hal_mcuctrl_fault_t;

//*****************************************************************************
//
//! MCUCTRL device structure
//
//*****************************************************************************
typedef struct
{
    //
    //! Device part number. (BCD format)
    //
    uint32_t ui32ChipPN;

    //
    //! Unique Chip ID 0.
    //
    uint32_t ui32ChipID0;

    //
    //! Unique Chip ID 1.
    //
    uint32_t ui32ChipID1;

    //
    //! Chip Revision.
    //
    uint32_t ui32ChipRev;

    //
    //! Flash Size.
    //
    uint32_t ui32FlashSize;

    //
    //! SRAM Size.
    //
    uint32_t ui32SRAMSize;
}
am_hal_mcuctrl_device_t;

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern void am_hal_mcuctrl_device_info_get(am_hal_mcuctrl_device_t *psDevice);
extern void am_hal_mcuctrl_fault_capture_enable(void);
extern void am_hal_mcuctrl_fault_capture_disable(void);
extern void am_hal_mcuctrl_fault_status(am_hal_mcuctrl_fault_t *psFault);
extern void am_hal_mcuctrl_flash_power_set(uint32_t ui32FlashPower);
extern void am_hal_mcuctrl_sram_power_set(uint32_t ui32SRAMPower,
                                         uint32_t ui32SRAMPowerDeepSleep);
extern void am_hal_mcuctrl_bandgap_enable(void);
extern void am_hal_mcuctrl_bandgap_disable(void);
extern void am_hal_mcuctrl_bucks_enable(void);
extern void am_hal_mcuctrl_bucks_disable(void);

#ifdef __cplusplus
}
#endif

#endif // AM_HAL_MCUCTRL_H

//*****************************************************************************
//
// End Doxygen group.
//! @}
//
//*****************************************************************************
