#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "am_mcu_apollo.h"
#include "am_bsp.h"
#include "am_devices.h"
#include "am_bootloader.h"
#include "exactle_fit_amota_multi_boot_config.h"

#ifdef BOOTLOADER_DEBUG
#include "am_util_stdio.h"
#include "am_util_delay.h"
// might need va_list someday, but not so far today.
#define DPRINTF(x) am_util_stdio_printf x
#else
#define DPRINTF(x)
#endif

uint32_t g_ui32FlashLoadingBuffer[AM_HAL_FLASH_PAGE_SIZE / 4];  //global SRAM buffer to perform flash operation.


//*****************************************************************************
//
// Flag page information.
//
//*****************************************************************************
extern am_bootloader_image_t *g_psBootImage;

//*****************************************************************************
//
// Device structure for the SPI flash.
//
//*****************************************************************************
am_devices_spiflash_t g_sSpiFlash =
{
    .ui32IOMModule = AM_BSP_FLASH_IOM,
    .ui32ChipSelect = AM_BSP_FLASH_CS,
};

//*****************************************************************************
//
// Configuration structure for the IO Master.
//
//*****************************************************************************
am_hal_iom_config_t g_sIOMConfig =
{
    .ui32InterfaceMode = AM_HAL_IOM_SPIMODE,
    .ui32ClockFrequency = AM_HAL_IOM_8MHZ,//AM_HAL_IOM_4MHZ,
    .bSPHA = 0,
    .bSPOL = 0,
    .ui8WriteThreshold = 0,
    .ui8ReadThreshold = 60,
};

//*****************************************************************************
//
// Configure GPIOs for communicating with a SPI flash
//
//*****************************************************************************
void
configure_spiflash_pins(void)
{
    //
    // Set up IOM1 SPI pins.
    //
    am_bsp_iom_spi_pins_enable(AM_BSP_FLASH_IOM);

    //
    // Enable the chip-select and data-ready pins for the SPI FLASH
    //
    am_bsp_pin_enable(FLASH_CS);
}

//*****************************************************************************
//
//! @brief Load a pre-stored image from internal flash on to its target address
//!
//! @param pui32TargetAddress is the target flash address to write to.
//! @param pui32StorageAddress is the flash start address where the image is stored.
//! @param ui32NumberBytes is the length of the image.
//!
//! This function reads the pre-stored image from the internal flash and writes 
//! to its target address in flash.
//! This function requires a RAM buffer for data buffering.
//! By default, the RAM buffer is a 2KB global data array.
//! @return None.
//
//*****************************************************************************
void
image_load_from_internal_flash( uint32_t* pui32TargetAddress, uint32_t* pui32StorageAddress, 
                                uint32_t ui32NumberBytes)
{
    uint32_t i;
    uint32_t ui32CurrentPage, ui32CurrentBlock;
    uint32_t ui32Critical;

    //
    // Loop through the data, copying it into the global buffer and load to flash.
    //
    for(i = 0; i < ui32NumberBytes/AM_HAL_FLASH_PAGE_SIZE; i++)
    {
        //
        // Load data from internal flash to SRAM buffer to avoid operation from same bank
        // Always operate in unit of page size
        memcpy((uint8_t*)g_ui32FlashLoadingBuffer, (uint8_t*)(pui32StorageAddress 
                            + i*AM_HAL_FLASH_PAGE_SIZE / 4), AM_HAL_FLASH_PAGE_SIZE);

        //
        // Figure out what page and block we're working on.
        //
        ui32CurrentPage =  AM_HAL_FLASH_ADDR2PAGE((uint32_t)(pui32TargetAddress 
                                            + i * AM_HAL_FLASH_PAGE_SIZE / 4));
        ui32CurrentBlock = AM_HAL_FLASH_ADDR2INST((uint32_t)(pui32TargetAddress 
                                            + i * AM_HAL_FLASH_PAGE_SIZE / 4));

        //
        // Start a critical section.
        //
        ui32Critical = am_hal_interrupt_master_disable();
        am_hal_flash_page_erase(AM_HAL_FLASH_PROGRAM_KEY,
                                    ui32CurrentBlock, ui32CurrentPage);
            
        //
        // Program the flash page with the data.
        //
        am_hal_flash_program_main(AM_HAL_FLASH_PROGRAM_KEY, g_ui32FlashLoadingBuffer,
                                (pui32TargetAddress + i * AM_HAL_FLASH_PAGE_SIZE / 4), 
                                AM_HAL_FLASH_PAGE_SIZE / 4);
        //
        // Exit the critical section.
        //
        am_hal_interrupt_master_set(ui32Critical);
    }

    //
    // Load the remaining bytes (must be word padded) into the flash, if there is any
    //
    uint32_t ui32RemainderBytes = ui32NumberBytes%AM_HAL_FLASH_PAGE_SIZE;
    if(ui32RemainderBytes)
    {
        //
        // Load data from internal flash to SRAM buffer to avoid operation from same bank
        // Always operate in unit of page size
        memcpy((uint8_t*)g_ui32FlashLoadingBuffer, (uint8_t*)(pui32StorageAddress 
                + (ui32NumberBytes - ui32RemainderBytes) / 4), ui32RemainderBytes);

        //
        // Figure out what page and block we're working on.
        //
        ui32CurrentPage =  AM_HAL_FLASH_ADDR2PAGE((uint32_t)(pui32TargetAddress 
                                    + (ui32NumberBytes - ui32RemainderBytes) / 4));
        ui32CurrentBlock = AM_HAL_FLASH_ADDR2INST((uint32_t)(pui32TargetAddress 
                                    + (ui32NumberBytes - ui32RemainderBytes) / 4));

        //
        // Start a critical section.
        //
        ui32Critical = am_hal_interrupt_master_disable();
        am_hal_flash_page_erase(AM_HAL_FLASH_PROGRAM_KEY,
                                    ui32CurrentBlock, ui32CurrentPage);

        //
        // Program the flash page with the data.
        //
        am_hal_flash_program_main(AM_HAL_FLASH_PROGRAM_KEY, g_ui32FlashLoadingBuffer,
                    (pui32TargetAddress + (ui32NumberBytes - ui32RemainderBytes) / 4), 
                    ui32RemainderBytes / 4);
        //
        // Exit the critical section.
        //
        am_hal_interrupt_master_set(ui32Critical);
    }
}
//*****************************************************************************
//
//! @brief Load a pre-stored image from external flash on to its target address
//!
//! @param pui32TargetAddress is the target flash address to write to.
//! @param pui32StorageAddress is the flash start address where the image is stored.
//! @param ui32NumberBytes is the length of the image.
//!
//! This function reads the pre-stored image from the internal flash and writes 
//! to its target address in flash.
//! This function requires a RAM buffer for data buffering.
//! By default, the RAM buffer is a 2KB global data array.
//! @return None.
//
//*****************************************************************************
void
image_load_from_external_flash( uint32_t* pui32TargetAddress, uint32_t ui32StorageAddress, 
                                uint32_t ui32NumberBytes)
{
    uint32_t i;
    uint32_t ui32CurrentPage, ui32CurrentBlock;
    uint32_t ui32Critical;

    //
    // Turn on the IOM for this operation.
    //
    am_bsp_iom_spi_pins_enable(AM_BSP_FLASH_IOM);
    am_hal_iom_enable(AM_BSP_FLASH_IOM);

    //
    // Loop through the data, copying it into the global buffer and load to flash.
    //
    for(i = 0; i < ui32NumberBytes/AM_HAL_FLASH_PAGE_SIZE; i++)
    {
        //
        // Load data from external flash to SRAM buffer
        // Always operate in unit of page size
        am_devices_spiflash_read((uint8_t*)g_ui32FlashLoadingBuffer, 
                                    ((uint32_t)ui32StorageAddress 
                                        + i*AM_HAL_FLASH_PAGE_SIZE), 
                                    AM_HAL_FLASH_PAGE_SIZE);

        //
        // Figure out what page and block we're working on.
        //
        ui32CurrentPage =  AM_HAL_FLASH_ADDR2PAGE((uint32_t)(pui32TargetAddress 
                                            + i * AM_HAL_FLASH_PAGE_SIZE / 4));
        ui32CurrentBlock = AM_HAL_FLASH_ADDR2INST((uint32_t)(pui32TargetAddress 
                                            + i * AM_HAL_FLASH_PAGE_SIZE / 4));

        //
        // Start a critical section.
        //
        ui32Critical = am_hal_interrupt_master_disable();
        am_hal_flash_page_erase(AM_HAL_FLASH_PROGRAM_KEY,
                                    ui32CurrentBlock, ui32CurrentPage);
            
        //
        // Program the flash page with the data.
        //
        am_hal_flash_program_main(AM_HAL_FLASH_PROGRAM_KEY, g_ui32FlashLoadingBuffer,
                                (pui32TargetAddress + i * AM_HAL_FLASH_PAGE_SIZE / 4), 
                                AM_HAL_FLASH_PAGE_SIZE / 4);
        //
        // Exit the critical section.
        //
        am_hal_interrupt_master_set(ui32Critical);
    }

    //
    // Load the remaining bytes (must be word padded) into the flash, if there is any
    //
    uint32_t ui32RemainderBytes = ui32NumberBytes%AM_HAL_FLASH_PAGE_SIZE;
    if(ui32RemainderBytes)
    {
        //
        // Load data from external flash to SRAM buffer
        // Always operate in unit of page size
        am_devices_spiflash_read((uint8_t*)g_ui32FlashLoadingBuffer, 
                                    ((uint32_t)ui32StorageAddress 
                                        + (ui32NumberBytes - ui32RemainderBytes)), 
                                    ui32RemainderBytes);
        //
        // Figure out what page and block we're working on.
        //
        ui32CurrentPage =  AM_HAL_FLASH_ADDR2PAGE((uint32_t)(pui32TargetAddress 
                                    + (ui32NumberBytes - ui32RemainderBytes) / 4));
        ui32CurrentBlock = AM_HAL_FLASH_ADDR2INST((uint32_t)(pui32TargetAddress 
                                    + (ui32NumberBytes - ui32RemainderBytes) / 4));

        //
        // Start a critical section.
        //
        ui32Critical = am_hal_interrupt_master_disable();
        am_hal_flash_page_erase(AM_HAL_FLASH_PROGRAM_KEY,
                                    ui32CurrentBlock, ui32CurrentPage);

        //
        // Program the flash page with the data.
        //
        am_hal_flash_program_main(AM_HAL_FLASH_PROGRAM_KEY, g_ui32FlashLoadingBuffer,
                    (pui32TargetAddress + (ui32NumberBytes - ui32RemainderBytes) / 4), 
                    ui32RemainderBytes / 4);
        //
        // Exit the critical section.
        //
        am_hal_interrupt_master_set(ui32Critical);
    }

    //
    // Disable IOM1 SPI pins and turn off the IOM for this operation.
    //
    am_bsp_iom_spi_pins_disable(AM_BSP_FLASH_IOM);
    am_hal_iom_disable(AM_BSP_FLASH_IOM);

}
#ifdef __BATCH_ERASE_INTERNAL__
//*****************************************************************************
//
//! @brief Erase necessary pages in internal flash
//!
//! @param pui32DstAddr is the target flash address to start erasing.
//! @param ui32NumberBytes is the length of the image in bytes.
//!
//! This function erases the necessary flash pages that is required to 
//! store the incoming image.
//! @return true if success, false if not.
//
//*****************************************************************************
bool
image_flash_erase( uint32_t* pui32DstAddr, uint32_t ui32NumberBytes)
{
    uint32_t ui32Critical;
    int16_t i16Result = 0;

    //
    // Check if the destination address is in the flash
    //
    am_hal_mcuctrl_device_t device;
    am_hal_mcuctrl_device_info_get(&device);
    if((uint32_t)pui32DstAddr + ui32NumberBytes > device.ui32FlashSize)
    {
        // target address exceed max flash address of the chip
        return false;
    }

    //
    // Check if we are at flash page boundries
    //
    if((uint32_t)pui32DstAddr & 0x000007FF)
    {
        // target address not at flash page boundaries
        // page alignment is done by image_get_storage_information_internal()
        // make sure to call this function after calling 
        // image_get_storage_information_internal()
        return false;
    }

    uint32_t ui32PageCount;
    if(ui32NumberBytes%AM_HAL_FLASH_PAGE_SIZE)
    {
        ui32PageCount = (ui32NumberBytes/AM_HAL_FLASH_PAGE_SIZE) + 1;
    }
    else
    {
        ui32PageCount = (ui32NumberBytes/AM_HAL_FLASH_PAGE_SIZE);
    }

    for(uint16_t i = 0; i < ui32PageCount; i++)
    {
        //
        // Figure out what page and block we're working on.
        //
        uint32_t ui32CurrentPage, ui32CurrentBlock;
        ui32CurrentPage =  AM_HAL_FLASH_ADDR2PAGE((uint32_t)(pui32DstAddr + i*AM_HAL_FLASH_PAGE_SIZE / 4));
        ui32CurrentBlock = AM_HAL_FLASH_ADDR2INST((uint32_t)(pui32DstAddr + i*AM_HAL_FLASH_PAGE_SIZE / 4));

        //
        // Start a critical section.
        //
        ui32Critical = am_hal_interrupt_master_disable();
        i16Result = am_hal_flash_page_erase(AM_HAL_FLASH_PROGRAM_KEY,
                                    ui32CurrentBlock, ui32CurrentPage);
        //
        // Exit the critical section.
        //
        am_hal_interrupt_master_set(ui32Critical);

        if(i16Result != 0)
        {   
            // flash operation failed.
            // flash helpers return non-zero for false, zero for success
            return false;
        }
    }

    return true;
}
#endif // __BATCH_ERASE_INTERNAL__
//*****************************************************************************
//
//! @brief Write data from SRAM into internal flash
//!
//! @param pui32DstAddr is the target flash address to write to.
//! @param pui32SrcAddr is the pointer to the data source.
//! @param ui32NumberBytes is the length of the data package.
//!
//! This function writes the data from source pointer into target flash address 
//! with automatic flash page erase function. The function supports writing starts
//! from any location inside a flash page and erases the next flash page to be 
//! written when necessary.
//! Input data and length must be word padded.
//! Do not perform cross flash block (0/1) operation.
//! @return true if success, false if not.
//
//*****************************************************************************
bool
image_flash_write_from_sram( uint32_t* pui32DstAddr, uint32_t* pui32SrcAddr, 
                                uint32_t ui32NumberBytes)
{
    uint32_t ui32Critical;
    int16_t i16Result = 0;

    //
    // Check if the destination address is in the flash
    //
    am_hal_mcuctrl_device_t device;
    am_hal_mcuctrl_device_info_get(&device);
    if((uint32_t)pui32DstAddr + ui32NumberBytes > device.ui32FlashSize)
    {
        // target address exceed max flash address of the chip
        return false;
    }

    //
    // Check if the number of bytes is word padded
    //
    if(ui32NumberBytes%4)
    {
        // data length is not word padded, quit operation
        return false;
    }
    
    //
    // Check if the number of bytes is larger than a page size
    //
    if(ui32NumberBytes > AM_HAL_FLASH_PAGE_SIZE)
    {
        // data length is larger than a page, quit operation
        // probably need to use image_load_from_internal_flash() function call
        return false;
    }

#ifndef __BATCH_ERASE_INTERNAL__
    //
    // Check if we are at flash page boundries
    //
    if((uint32_t)pui32DstAddr & 0x000007FF)
    {
        //
        // We are not at flash page boundries.
        // Check if we need to erase the next flash page
        // 
        uint16_t check_count = 0;   // used to check whether the remaining flash page is empty
        if((0x800 - ((uint32_t)pui32DstAddr & 0x000007FF)) < ui32NumberBytes)
        {
            // we need to erase the next flash page
            check_count = 0x800 - ((uint32_t)pui32DstAddr & 0x000007FF);
            
            //
            // Figure out what page and block we're working on.
            //
            uint32_t ui32CurrentPage, ui32CurrentBlock;
            ui32CurrentPage =  AM_HAL_FLASH_ADDR2PAGE((uint32_t)pui32DstAddr);
            ui32CurrentBlock = AM_HAL_FLASH_ADDR2INST((uint32_t)pui32DstAddr);

            if(ui32CurrentPage == 127)
            {
                // flash write operation does not support cross block (0/1) operation
                return false;

//                if(ui32CurrentBlock == 0)
//                {
//                    ui32CurrentBlock = 1;
//                    ui32CurrentPage = 0;
//                }
//                else
//                {
//                    // though this shall not happen...
//                    return false;
//                }
            }
            else
            {
                ui32CurrentPage++;
            }

            //
            // Start a critical section.
            //
            ui32Critical = am_hal_interrupt_master_disable();
            i16Result = am_hal_flash_page_erase(AM_HAL_FLASH_PROGRAM_KEY,
                                        ui32CurrentBlock, ui32CurrentPage);
            //
            // Exit the critical section.
            //
            am_hal_interrupt_master_set(ui32Critical);

            if(i16Result != 0)
            {   
                // flash operation failed.
                // flash helpers return non-zero for false, zero for success
                return false;
            }

        }
        else
        {
            // we don't need to erase the next flash page
            check_count = ui32NumberBytes;
        }

        //
        // Check whether the remaining space in this page is empty        
        //
        for(uint16_t i = 0; i < (check_count / 4); i++)
        {
            if(*(pui32DstAddr + i) != 0xFFFFFFFF)
            {
                // target flash not empty
                return false;
            }
        }
    }
    else
    {
        //
        // We are at starting address of the flash page
        // Figure out what page and block we're working on.
        //
        uint32_t ui32CurrentPage, ui32CurrentBlock;
        ui32CurrentPage =  AM_HAL_FLASH_ADDR2PAGE((uint32_t)pui32DstAddr);
        ui32CurrentBlock = AM_HAL_FLASH_ADDR2INST((uint32_t)pui32DstAddr);

        //
        // Start a critical section.
        //
        ui32Critical = am_hal_interrupt_master_disable();
        i16Result = am_hal_flash_page_erase(AM_HAL_FLASH_PROGRAM_KEY,
                                        ui32CurrentBlock, ui32CurrentPage);
        //
        // Exit the critical section.
        //
        am_hal_interrupt_master_set(ui32Critical);

        if(i16Result != 0)
        {   
            // flash operation failed.
            // flash helpers return non-zero for false, zero for success
            return false;
        }

    }
#endif //__BATCH_ERASE_INTERNAL__

    //
    // Program the flash page with the data.
    // Start a critical section.
    //
    ui32Critical = am_hal_interrupt_master_disable();
    i16Result = am_hal_flash_program_main(AM_HAL_FLASH_PROGRAM_KEY, pui32SrcAddr, 
                                            pui32DstAddr, ui32NumberBytes / 4);
    //
    // Exit the critical section.
    //
    am_hal_interrupt_master_set(ui32Critical);
    
    if(i16Result != 0)
    {
        // flash helpers return non-zero for false, zero for success
        return false;
    }
    else
    {
        //
        // Check whether the content written into flash matches source content in SRAM 
        //
        uint32_t i;
        for(i = 0; i < ui32NumberBytes / 4; i++)
        {
            if(pui32SrcAddr[i] == pui32DstAddr[i])
            {
                //keep checking
            }
            else
            {   
                //
                // Content mismatch, return false status
                //
                return false;
            }
        }
        return true;
    }
}

void image_spiflash_erase(uint32_t ui32DstAddr, uint32_t ui32NumberBytes)
{
    uint16_t ui16SectorCount = ui32NumberBytes/AM_DEVICES_SPIFLASH_SECTOR_SIZE;

    //
    // Turn on the IOM for this operation.
    //
    am_bsp_iom_spi_pins_enable(AM_BSP_FLASH_IOM);
    am_hal_iom_enable(AM_BSP_FLASH_IOM);

    for(uint16_t i = 0; i < ui16SectorCount; i++)
    {
        am_devices_spiflash_sector_erase(ui32DstAddr + i * AM_DEVICES_SPIFLASH_SECTOR_SIZE);
    }

    if(ui32NumberBytes%AM_DEVICES_SPIFLASH_SECTOR_SIZE)
    {
        am_devices_spiflash_sector_erase(ui32DstAddr + ui16SectorCount * AM_DEVICES_SPIFLASH_SECTOR_SIZE);
    }

    //
    // Disable IOM1 SPI pins and turn off the IOM for this operation.
    //
    am_bsp_iom_spi_pins_disable(AM_BSP_FLASH_IOM);
    am_hal_iom_disable(AM_BSP_FLASH_IOM);
}

//*****************************************************************************
//
//! @brief Checks where to store the received new image in internal flash
//!
//! @param[in] psImage is the pointer that points to the flash flag page.
//! @param[in] ui32NumBytesNewImage is the length of the new image in bytes.
//! @param[out] pui32StorageAddressNewImage the available storage start address.
//! @param[out] pui32NumBytesSpaceLeft is space left in internal flash (in bytes).
//!
//! This function reads the flash flag page informatin to determine the available
//! storage start address and space left in the internal flash. It compares the 
//! space left in the internal flash with the new image length and returns whether
//! there is enough space left to store the image.
//! The last page of the internal flash is reserved for future usage, therefore
//! not counted in the space left.
//!
//! @return true if there is enough space to store the new image.
//!         false if there is not.
//
//*****************************************************************************
bool
image_get_storage_information_internal(am_bootloader_image_t *psImage, 
                                        uint32_t ui32NumBytesNewImage,
                                        uint32_t* pui32StorageAddressNewImage,
                                        uint32_t* pui32NumBytesSpaceLeft)
{

    uint32_t ui32SpaceLeft;
    //
    // Read device information to determine total flash available
    //
    am_hal_mcuctrl_device_t device;
    am_hal_mcuctrl_device_info_get(&device);

    //
    // Calculate space left in internal flash according to flag page inforamtion.
    // Last page of the internal flash is reserved.
    // (effective LinkAddress shall be equal to or larger than 0x4000)
    //
    if((device.ui32FlashSize < ((uint32_t)(psImage->pui32LinkAddress) 
        + (uint32_t)(psImage->ui32NumBytes) + AM_HAL_FLASH_PAGE_SIZE))
        ||((uint32_t)(psImage->pui32LinkAddress) > device.ui32FlashSize)
        ||((uint32_t)(psImage->ui32NumBytes) > device.ui32FlashSize))
    {
        //image size error, or flash flag page info error
        *pui32StorageAddressNewImage = 0xFFFFFFFF; 
        *pui32NumBytesSpaceLeft = 0xFFFFFFFF;
        return false;
    }
    ui32SpaceLeft = device.ui32FlashSize - (uint32_t)(psImage->pui32LinkAddress) 
                    - (uint32_t)(psImage->ui32NumBytes) - AM_HAL_FLASH_PAGE_SIZE;
    ui32SpaceLeft &= 0xFFFFF800;    //storage starts from page boundries

#if USE_LAST_PAGE_FOR_FLAG
    if(ui32SpaceLeft > AM_HAL_FLASH_PAGE_SIZE)
    {
        ui32SpaceLeft -= AM_HAL_FLASH_PAGE_SIZE;
    }
    else
    {
        //
        // Not enought space left in the internal flash to store the new image
        //
        *pui32NumBytesSpaceLeft = ui32SpaceLeft;
        *pui32StorageAddressNewImage = 0xFFFFFFFF;  
        return false;
    }
#endif 

    if(ui32NumBytesNewImage > ui32SpaceLeft) 
    {
        //
        // Not enought space left in the internal flash to store the new image
        //
        *pui32NumBytesSpaceLeft = ui32SpaceLeft;
        *pui32StorageAddressNewImage = 0xFFFFFFFF;  
        return false;
    }
    else
    {
        //
        // Find the right address in internal flash to store the new image.
        // The starting address of the first available flash page
        //
        *pui32NumBytesSpaceLeft = ui32SpaceLeft;
        *pui32StorageAddressNewImage = (((uint32_t)(psImage->pui32LinkAddress)
                                        + (uint32_t)(psImage->ui32NumBytes))
                                        | 0x000007FF) + 1;  
        return true;
    }
}
