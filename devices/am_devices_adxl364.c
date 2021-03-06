//*****************************************************************************
//
//! @file am_devices_adxl364.c
//!
//! @brief Driver to interface with the ADXL364
//!
//! These functions implement the ADXL364 support routines for use on Ambiq
//! Micro MCUs.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************

#include "am_bsp.h"
#include "am_devices_adxl364.h"
#include "am_util_delay.h"

//*****************************************************************************
//
// Globals
//
//*****************************************************************************
am_hal_iom_spi_device_t *g_psIOMSettings;
static am_devices_adxl364_write_t g_pfnSpiWrite = 0;
static am_devices_adxl364_read_t g_pfnSpiRead = 0;

//*****************************************************************************
//
//! @brief Initialize the ADXL364 driver.
//!
//! @param am_hal_iom_spi_device_t - Device structure describing how to
//! communicate with the ADXL over the IO master SPI bus.
//!
//! This function sets up the interface between the IO master and the ADXL.
//!
//! @return None.
//
//*****************************************************************************
void
am_devices_adxl364_driver_init(am_hal_iom_spi_device_t *psIOMSettings,
                               am_devices_adxl364_write_t pfnWriteFunc,
                               am_devices_adxl364_read_t pfnReadFunc)
{
    //
    // Initialize the IOM settings for the ADXL364.
    //
    g_psIOMSettings = psIOMSettings;

    g_pfnSpiWrite = pfnWriteFunc ? pfnWriteFunc :
        (am_devices_adxl364_write_t) am_hal_iom_spi_write;

    g_pfnSpiRead = pfnReadFunc ? pfnReadFunc :
        (am_devices_adxl364_read_t) am_hal_iom_spi_read;
}

//*****************************************************************************
//
//! @brief Initialize the ADXL364.
//!
//! This function sends a few commands to initialize the ADXL for normal usage.
//!
//! We stop short of setting measurement mode.
//! We set the sample rate to 400 Samples/second.
//! We set the FIFO high water mark at 210 samples or 420 bytes.
//!
//! @note You can recall this any time to reinitialize the device.
//!
//! @param bSyncMode true --> use ctimer to trigger samples
//! @param ui32ClockFreqHz CPU core clock in Hertz
//!
//! @return Zero if successful.
//
//*****************************************************************************
int
am_devices_adxl364_init(bool bSyncMode, uint32_t ui32ClockFreqHz)
{

    uint32_t pui32Command[8];
    uint8_t *pui8Command;

    pui8Command = (uint8_t *) pui32Command;
    //
    // Use polled IOM send routine to reset the ADXL364.
    //
    pui8Command[2] = 0x52; // R for reset is a required parameter
    pui8Command[1] = 0x2D; // register SOFT_RESET on ADXL364
    pui8Command[0] = 0x0A; // SPI WRITE
    g_pfnSpiWrite(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                  pui32Command, 3, AM_HAL_IOM_RAW);

    //
    // Add some delay.
    //
    //am_util_delay_ms(100,ui32ClockFreqHz);
    am_util_delay_cycles(24000*100);

    //
    // Setup command string to send to adxl364
    //
    pui8Command = (uint8_t *) pui32Command;
    pui8Command[20] = 0x00;     // reg #2B STANDBY
    pui8Command[19] = 0x01;     // reg #2A PWR_CTL
    pui8Command[18] = 0x00;     // reg #29 EXT_ADC
    pui8Command[17] = 0x25;     // reg #28 FILTER_CTL   400Hz sample rate
    pui8Command[16] = 0x00;     // reg #27 INT_LOW
    pui8Command[15] = 0x02;     // reg #26 INTMAP2    Interrupt on FIFO ready
    pui8Command[14] = 0x04;     // reg #25 INTMAP1    Interrupt on water mark
    pui8Command[13] = 0xD2;     // reg #24 FIFO_SAMPLES == 210 (0x0D2) NOTE: AH = 0
    pui8Command[12] = 0x02;     // reg #23 FIFO_CTRL   AH=0  FIFO MODE = stream mode
    pui8Command[11] = 0x00;     // reg #22 TIMER_CTL
    pui8Command[10] = 0x00;     // reg #21 ACT_INACT_CTL
    pui8Command[9]  = 0x00;     // reg #20 ACT_MASK
    pui8Command[8]  = 0x02;     // reg #1F TIME_INACT_H
    pui8Command[7]  = 0x00;     // reg #1E TIME_INACT_L
    pui8Command[6]  = 0x00;     // reg #1D THRESHOLD_INACT_H
    pui8Command[5]  = 0x80;     // reg #1C THRESHOLD_INACT_L
    pui8Command[4]  = 0x20;     // reg #1B TIME_ACT
    pui8Command[3]  = 0x02;     // reg #1A THRESHOLD_ACT_H
    pui8Command[2]  = 0x00;     // reg #19 THRESHOLD_ACT_L
    pui8Command[1]  = 0x19;     // register address of THRESHOLD_ACT_L
    pui8Command[0]  = 0x0A;     // SPI WRITE command for the ADXL364


    //
    // Handle optional synchronous sampling mode
    //
    if (bSyncMode)
    {
        pui8Command[11] = 0x40; // reg #22 TIMER_CTL   synchronous sample mode
        pui8Command[15] = 0x00; // reg #26 INTMAP2    Not available in sync mode
    }

    //
    // Use polled IOM send routine to load the command registers.
    //
    g_pfnSpiWrite(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                  pui32Command, 21, AM_HAL_IOM_RAW);

    return 0;
}

//*****************************************************************************
//
//! @brief Reset the ADXL364
//!
//! Sends a reset command to the ADXL364 over SPI.
//!
//! @return Zero if successful.
//
//*****************************************************************************
void
am_devices_adxl364_reset(void)
{
    int i;
    uint32_t pui32Command[1];
    uint8_t *pui8Command;

    pui8Command = (uint8_t *) pui32Command;

    // use polled IOM send routine to reset the ADXL364
    pui8Command[2] = 0x52; // R for reset is a required parameter
    pui8Command[1] = 0x2D; // register SOFT_RESET on ADXL364
    pui8Command[0] = 0x0A; // SPI WRITE
    g_pfnSpiWrite(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                  pui32Command, 3, AM_HAL_IOM_RAW);

    // add some delay
    for (i = 0; i < 10000; i++)
    {
        *((volatile uint32_t  *) 0x04ffff080 ) = i;
    }
}

//*****************************************************************************
//
//! @brief Set measurement mode for the ADXL364
//!
//! @return Zero if successful.
//
//*****************************************************************************
int
am_devices_adxl364_measurement_mode_set(void)
{
#ifdef NOTDEF
    //fixme 364 does not need to set measurement mode separately
    uint32_t pui32Command[1];
    uint8_t *pui8Command;

    pui8Command = (uint8_t *) pui32Command;

    // use polled IOM send routine
    pui8Command[2] = 0x01; // reg #2D POWER_CTL  set measurement mode
    pui8Command[1] = 0x2A; // register address of POWER_CTL
    pui8Command[0] = 0x0A; // SPI WRITE command for the ADXL364

    g_pfnSpiWrite(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                  pui32Command, 3, AM_HAL_IOM_RAW);
#endif

    return 0;
}

//*****************************************************************************
//
//! @brief Get FIFO depth for the ADXL364
//!
//! Called from am_devices_3dof  task
//!
//! @return Zero if successful.
//
//*****************************************************************************
int
am_devices_adxl364_fifo_depth_get(uint32_t * p)
{
    uint32_t pui32Command[1];
    uint8_t *pui8Command;

    pui8Command = (uint8_t *) pui32Command;

    // use polled IOM send routine
    pui8Command[1] = 0x0A; // register FIFO ENTRIES LOW
    pui8Command[0] = 0x0B; // READ

    g_pfnSpiWrite(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                  pui32Command, 2, AM_HAL_IOM_CS_LOW | AM_HAL_IOM_RAW);

    g_pfnSpiRead(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                 p, 2, AM_HAL_IOM_RAW);

    *p &= 0x0000ffff;

    return 0;
}

//*****************************************************************************
//
//! @brief Get a sample from the ADXL364
//!
//! For now, Number of samples has to be less than or equal to 32
//!
//! @return Zero if successful.
//
//*****************************************************************************
int
am_devices_adxl364_sample_get(int Number, uint32_t *p)
{
    uint32_t pui32Command[1];
    uint8_t *pui8Command;

    pui8Command = (uint8_t *) pui32Command;

    //
    // use polled IOM send routine
    //
    pui8Command[0] = 0x0D; // READ 2 BYTES FROM THE FIFO

    g_pfnSpiWrite(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                  pui32Command, 1, AM_HAL_IOM_CS_LOW | AM_HAL_IOM_RAW);

    g_pfnSpiRead(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                 p, Number << 1, AM_HAL_IOM_RAW);

    return 0;
}

//*****************************************************************************
//
//! @brief Triggers an IOM command to read a set of samples from the ADXL
//!
//! This function will start the SPI transfer, but doesn't wait for the
//! transfer to complete. Instead, the data will be transferred to the IOM
//! fifo, where they can be retrieved later. The IOM will issue a "fifo
//! threshold" interrupt when the fifo grows beyond the configured size, at
//! which point the caller will need to read the accumulated data into a
//! buffer. After the last byte is transferred, the IOM will issue a "command
//! complete" interrupt, and the bus may be used for other transfers.
//!
//! @return Zero if successful.
//
//*****************************************************************************
int
am_devices_adxl364_sample_get_nonblocking(int Number)
{
    //
    // Initiate a 'READ' command to get the ADXL data.
    //
    am_hal_iom_spi_cmd_run(AM_HAL_IOM_READ, g_psIOMSettings->ui32Module,
                           g_psIOMSettings->ui32ChipSelect, Number << 1,
                           AM_HAL_IOM_OFFSET(0x0D));
    return 0;
}

//*****************************************************************************
//
//! @brief Get the state of the control registers from  the ADXL364
//!
//! returns 21 bytes starting at 0x19
//!
//! Called from am_devices_3dof  task
//! @return Zero if successful.
//
//*****************************************************************************
int
am_devices_adxl364_ctrl_reg_state_get(uint32_t * p)
{
    uint32_t pui32Command[1];
    uint8_t *pui8Command;

    pui8Command = (uint8_t *) pui32Command;

    // use polled IOM send routine
    pui8Command[1] = 0x19;
    pui8Command[0] = 0x0B;

    g_pfnSpiWrite(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                  pui32Command, 2, AM_HAL_IOM_CS_LOW | AM_HAL_IOM_RAW);

    g_pfnSpiRead(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                 p, 21, AM_HAL_IOM_RAW);

    return 0;
}

//*****************************************************************************
//
//! \brief Get the device ID
//!
//! returns 4 bytes
//!
//! Called from am_devices_3dof  task
//! @return Zero if successful.
//
//*****************************************************************************
void
am_devices_adxl364_device_id_get(uint32_t * p)
{
    uint32_t pui32Command[1];
    uint8_t *pui8Command;

    pui8Command = (uint8_t *) pui32Command;

    // use polled IOM send routine
    pui8Command[1] = 0x00; // begining of Device ID
    pui8Command[0] = 0x0B;

    g_pfnSpiWrite(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                  pui32Command, 2, AM_HAL_IOM_CS_LOW | AM_HAL_IOM_RAW);

    g_pfnSpiRead(g_psIOMSettings->ui32Module, g_psIOMSettings->ui32ChipSelect,
                 p, 4, AM_HAL_IOM_RAW);
}
