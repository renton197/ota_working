//*****************************************************************************
//
//! @file image_boot_handlers.h
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

#ifndef IMAGE_BOOT_HANDLERS_H
#define IMAGE_BOOT_HANDLERS_H

#ifdef __cplusplus
extern "C"
{
#endif

extern bool image_get_storage_information_internal( am_bootloader_image_t *psImage, 
                                                    uint32_t ui32NumBytesNewImage,
                                                    uint32_t* pui32StorageAddressNewImage,
                                                    uint32_t* pui32NumBytesSpaceLeft);
extern void image_load_from_internal_flash( uint32_t* pui32TargetAddress, 
                                            uint32_t* pui32StorageAddress, 
                                            uint32_t ui32NumberBytes);
extern bool image_flash_write_from_sram( uint32_t* pui32DstAddr, uint32_t* pui32SrcAddr, 
                                            uint32_t ui32NumberBytes);


#ifdef __cplusplus
}
#endif

#endif // IMAGE_BOOT_HANDLERS_H
