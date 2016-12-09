//*****************************************************************************
//
//! @file am_bootloader.h
//!
//! @brief
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#include <stdint.h>
#include <stdbool.h>

#ifndef AM_BOOTLOADER_H
#define AM_BOOTLOADER_H

//*****************************************************************************
//
// Macros
//
//*****************************************************************************
#define AM_BOOTLOADER_DISABLE_OVERRIDE_PIN      (0xFFFFFFFF)
#define AM_BOOTLOADER_OVERRIDE_HIGH             (0x1)
#define AM_BOOTLOADER_OVERRIDE_LOW              (0x0)
#define AM_BOOTLOADER_FLASH_ADDRESS_MAX         (AM_HAL_FLASH_TOTAL_SIZE)

#ifdef __cplusplus
extern "C"
{
#endif

// macro definitions for boot options
#define BOOT_NEW_IMAGE_INTERNAL_FLASH   0x00000001
#define BOOT_NEW_IMAGE_EXTERNAL_FLASH   0x00000002
#define BOOT_NO_NEW_IMAGE               0xFFFFFFFF

//*****************************************************************************
//
// Structure to keep track of boot image information (0x3c00).
//
//*****************************************************************************
typedef struct
{
    // Starting address where the image was linked to run.
    uint32_t *pui32LinkAddress;

    // Length of the executable image in bytes.
    uint32_t ui32NumBytes;

    // CRC-32 Value for the full image.
    uint32_t ui32CRC;

    // Override GPIO number. (Can be used to force a new image load)
    uint32_t ui32OverrideGPIO;

    // Polarity for the override pin.
    uint32_t ui32OverridePolarity;

    // Stack pointer location.
    uint32_t *pui32StackPointer;

    // Reset vector location.
    uint32_t *pui32ResetVector;

    // Boot Options. -- RMA
    uint32_t ui32Options;

    // Version Informatin of the Current Image -- RMA
    uint32_t ui32Version;

    // Version Informatin of the New Image -- RMA
    // Only used to confirm the image being received.
    uint32_t ui32VersionNewImage;

    // Starting address where the new image was stored. -- RMA
    uint32_t *pui32StorageAddressNewImage;

    // Length of the new image being received in bytes. -- RMA
    // Only used to confirm the image being received.
    uint32_t ui32TotalNumBytesNewImage;

    // Bytes already received and stored. -- RMA
    uint32_t ui32StoredNumBytesNewImage;

    // CRC-32 Value for the new image being received. -- RMA
    // Only used to confirm the image being received.
    uint32_t ui32CRCNewImage;

    // Is the image encrypted?
    bool bEncrypted;
}
am_bootloader_image_t;

//*****************************************************************************
//
// External Variable declarations.
//
//*****************************************************************************
extern am_bootloader_image_t *g_psBootImage;

//*****************************************************************************
//
// External function declarations.
//
//*****************************************************************************
extern uint32_t am_bootloader_crc32(const void *pvData, uint32_t ui32Length);
extern uint32_t am_bootloader_fast_crc32(const void *pvData, uint32_t ui32NumBytes);
extern void am_bootloader_partial_crc32(const void *pvData, uint32_t ui32NumBytes, uint32_t *pui32CRC);
extern bool am_bootloader_image_check(am_bootloader_image_t *psImage);
extern bool am_bootloader_flash_check(am_bootloader_image_t *psImage);
extern int am_bootloader_flag_page_update(am_bootloader_image_t *psImage, uint32_t *pui32FlagPage);

#ifdef gcc
extern void __attribute__((naked)) am_bootloader_image_run(am_bootloader_image_t *psImage);
#endif

#ifdef keil
extern __asm void am_bootloader_image_run(am_bootloader_image_t *psImage);
#endif

#ifdef iar
extern void am_bootloader_image_run(am_bootloader_image_t *psImage);
#endif

#ifdef __cplusplus
}
#endif

#endif // AM_BOOTLOADER_H
