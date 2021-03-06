//*****************************************************************************
//
//! @file am_devices_amx8x5.c
//!
//! @brief Driver to interface with the AMx8x5 RTC.
//!
//! These functions implement the AMx8x5 support routines for use on Ambiq
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
#include "am_devices_amx8x5.h"
#include "am_util_delay.h"
#include "am_util_math.h"

//*****************************************************************************
//
// Globals
//
//*****************************************************************************
am_devices_amx8x5_time_t g_psTimeRegs;

//*****************************************************************************
//
//! @brief Clear one or more bits.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param ui8Address - RTC address.
//! @param ui8Mask - Bits to clear.
//!
//! This function clears one or more bits in the selected register, selected by
//! 1's in the mask.
//!
//! @return None.
//
//*****************************************************************************
void
am_devices_amx8x5_reg_clear(am_devices_amx8x5_t *psDevice, uint8_t ui8Address,
                            uint8_t ui8Mask)
{
    uint8_t ui8Temp;

    ui8Temp = am_devices_amx8x5_reg_read(psDevice, ui8Address);
    ui8Temp &= ~ui8Mask;
    am_devices_amx8x5_reg_write(psDevice, ui8Address, ui8Temp);
}

//*****************************************************************************
//
//! @brief Set one or more bits.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param ui8Address - RTC address.
//! @param ui8Mask - Bits to set.
//!
//! This function sets one or more bits in the selected register, selected by
//! 1's in the mask.
//!
//! @return None.
//
//*****************************************************************************
void
am_devices_amx8x5_reg_set(am_devices_amx8x5_t *psDevice, uint8_t ui8Address,
                          uint8_t ui8Mask)
{
    uint8_t ui8Temp;

    ui8Temp = am_devices_amx8x5_reg_read(psDevice, ui8Address);
    ui8Temp |= ui8Mask;
    am_devices_amx8x5_reg_write(psDevice, ui8Address, ui8Temp);
}

//*****************************************************************************
//
//! @brief Reads an internal register in the AMx8x5.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param ui32Register is the address of the register to read.
//!
//! This function performs a read to an AMx8x5 register over the serial bus.
//!
//! @return
//
//*****************************************************************************
uint8_t
am_devices_amx8x5_reg_read(am_devices_amx8x5_t *psDevice,
                           uint8_t ui8Register)
{
    uint8_t ui8Offset;
    am_hal_iom_buffer(1) sData;

    //
    // Build the SPI offset and the data buffer.
    //
    ui8Offset = ui8Register;

    //
    // If SPI mode else I2C.
    //
    if (psDevice->bMode == AM_DEVICES_AMX8X5_MODE_SPI)
    {
        //
        // Send the read to the bus using the polled API.
        //
        am_hal_iom_spi_read(psDevice->ui32IOMModule, psDevice->ui32ChipSelect,
                            sData.words, 1, AM_HAL_IOM_OFFSET(ui8Offset));
    }
    else
    {

        //
        // Send the write to the bus using the polled API.
        //
        am_hal_iom_i2c_read(psDevice->ui32IOMModule, psDevice->ui32Address,
                             sData.words, 1, AM_HAL_IOM_OFFSET(ui8Offset));
    }

    //
    // Return the retrieved data.
    //
    return sData.bytes[0];
}

//*****************************************************************************
//
//! @brief Writes an internal register in the AMx8x5.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param ui32Register is the address of the register to write.
//! @param ui32Value is the value to write to the register.
//!
//! This function performs a write to an AMx8x5 register over the serial bus.
//!
//! @return
//
//*****************************************************************************
void
am_devices_amx8x5_reg_write(am_devices_amx8x5_t *psDevice,
                            uint8_t ui8Register, uint8_t ui8Value)
{
    uint8_t ui8Offset;
    am_hal_iom_buffer(1) sData;

    //
    // Build the offset and the data buffer.
    //
    ui8Offset = ui8Register;
    sData.bytes[0] = ui8Value;

    //
    // If SPI mode else I2C.
    //
    if (psDevice->bMode == AM_DEVICES_AMX8X5_MODE_SPI)
    {

        //
        // Send the write to the bus using the polled API.
        //
        am_hal_iom_spi_write(psDevice->ui32IOMModule, psDevice->ui32ChipSelect,
                             sData.words, 1, AM_HAL_IOM_OFFSET(ui8Offset));
    }
    else
    {

        //
        // Send the write to the bus using the polled API.
        //
        am_hal_iom_i2c_write(psDevice->ui32IOMModule, psDevice->ui32Address,
                             sData.words, 1, AM_HAL_IOM_OFFSET(ui8Offset));
    }
}

//*****************************************************************************
//
//! @brief Reset the AMx8x5.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//!
//! This function performs a reset to AMx8x5.
//!
//! @return None
//
//*****************************************************************************
void
am_devices_amx8x5_reset(am_devices_amx8x5_t *psDevice)
{
    //
    // Reset.
    //
    am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_CONFIG_KEY, 0x3C);
}

//*****************************************************************************
//
//! @brief Get the time.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//!
//! This function loads the g_psTimeRegs structure with the time from the
//! AMX8XX.
//!
//! @return None.
//
//*****************************************************************************
void
am_devices_amx8x5_time_get(am_devices_amx8x5_t *psDevice)
{
    am_hal_iom_buffer(8) psTempBuff;

    //
    // Read the counters.
    //
    am_devices_amx8x5_reg_block_read(psDevice, AM_DEVICES_AMX8X5_HUNDREDTHS,
                                     psTempBuff.words, 8,
                                     NULL);

    g_psTimeRegs.ui8Hundredth = am_util_math_bcd_to_dec(psTempBuff.bytes[0]);
    g_psTimeRegs.ui8Second = am_util_math_bcd_to_dec(psTempBuff.bytes[1]);
    g_psTimeRegs.ui8Minute = am_util_math_bcd_to_dec(psTempBuff.bytes[2]);
    g_psTimeRegs.ui8Hour = psTempBuff.bytes[3];
    g_psTimeRegs.ui8Date = am_util_math_bcd_to_dec(psTempBuff.bytes[4]);
    g_psTimeRegs.ui8Month = am_util_math_bcd_to_dec(psTempBuff.bytes[5]);
    g_psTimeRegs.ui8Year = am_util_math_bcd_to_dec(psTempBuff.bytes[6]);
    g_psTimeRegs.ui8Weekday = am_util_math_bcd_to_dec(psTempBuff.bytes[7]);

    //
    // Get the current hours format mode 12:24.
    //
    psTempBuff.bytes[0] = am_devices_amx8x5_reg_read(psDevice,
                                                 AM_DEVICES_AMX8X5_CONTROL_1);
    if ((psTempBuff.bytes[0] & 0x40) == 0)
    {
        //
        // 24-hour mode.
        //
        g_psTimeRegs.ui8Mode = 2;
        g_psTimeRegs.ui8Hour = g_psTimeRegs.ui8Hour & 0x3F;
    }
    else
    {
        //
        // 12-hour mode.  Get PM:AM.
        //
        g_psTimeRegs.ui8Mode = (g_psTimeRegs.ui8Hour & 0x20) ? 1 : 0;
        g_psTimeRegs.ui8Hour &= 0x1F;
    }

    g_psTimeRegs.ui8Hour = am_util_math_bcd_to_dec(g_psTimeRegs.ui8Hour);

    //
    // Get the century bit.
    //
    psTempBuff.bytes[0] = am_devices_amx8x5_reg_read(psDevice,
                                                 AM_DEVICES_AMX8X5_STATUS);
    g_psTimeRegs.ui8Century = (psTempBuff.bytes[0] & 0x80) ? 1 : 0;
}

//*****************************************************************************
//
//! @brief Set the time in the counters.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param ui8Protect:  0 => leave counters writable
//!                     1 => leave counters unwritable
//!
//! This function loads the AMX8XX counter registers with the current
//! g_psTimeRegs structure values.
//!
//! @return None
//
//*****************************************************************************
void
am_devices_amx8x5_time_set(am_devices_amx8x5_t *psDevice, uint8_t ui8Protect)
{
    am_hal_iom_buffer(8) psTempBuff;

    //
    // Convert decimal to binary-coded decimal.
    //
    g_psTimeRegs.ui8Hundredth = am_util_math_dec_to_bcd(
                                             g_psTimeRegs.ui8Hundredth);
    g_psTimeRegs.ui8Second = am_util_math_dec_to_bcd(g_psTimeRegs.ui8Second);
    g_psTimeRegs.ui8Minute = am_util_math_dec_to_bcd(g_psTimeRegs.ui8Minute);
    g_psTimeRegs.ui8Hour = am_util_math_dec_to_bcd(g_psTimeRegs.ui8Hour);
    g_psTimeRegs.ui8Date = am_util_math_dec_to_bcd(g_psTimeRegs.ui8Date);
    g_psTimeRegs.ui8Weekday = am_util_math_dec_to_bcd(g_psTimeRegs.ui8Weekday);
    g_psTimeRegs.ui8Month = am_util_math_dec_to_bcd(g_psTimeRegs.ui8Month);
    g_psTimeRegs.ui8Year = am_util_math_dec_to_bcd(g_psTimeRegs.ui8Year);

    //
    // Determine whether 12 or 24-hour timekeeping mode is being used and set
    // the 1224 bit appropriately.
    // 24-hour day.
    //
    if (g_psTimeRegs.ui8Mode == AM_DEVICES_AMX8X5_24HR_MODE)
    {
        am_devices_amx8x5_reg_clear(psDevice, AM_DEVICES_AMX8X5_CONTROL_1,
                                    0x40);
    }

    //
    // 12-hour day PM.
    //
    else if (g_psTimeRegs.ui8Mode == AM_DEVICES_AMX8X5_12HR_MODE)
    {
        //
        // Set AM/PM.
        //
        g_psTimeRegs.ui8Hour |= 0x20;
        am_devices_amx8x5_reg_set(psDevice, AM_DEVICES_AMX8X5_CONTROL_1, 0x40);
    }

    //
    // 12-hour day AM.
    //
    else
    {
        am_devices_amx8x5_reg_set(psDevice, AM_DEVICES_AMX8X5_CONTROL_1, 0x40);
    }

    //
    // Set the WRTC bit to enable counter writes.
    //
    am_devices_amx8x5_reg_set(psDevice, AM_DEVICES_AMX8X5_CONTROL_1, 0x01);

    //
    // Set the correct century.
    //
    if (g_psTimeRegs.ui8Century == 0)
    {
        am_devices_amx8x5_reg_clear(psDevice, AM_DEVICES_AMX8X5_STATUS, 0x80);
    }
    else
    {
        am_devices_amx8x5_reg_set(psDevice, AM_DEVICES_AMX8X5_STATUS, 0x80);
    }

    //
    // Write all of the time counters.
    //
    psTempBuff.bytes[0] = g_psTimeRegs.ui8Hundredth;
    psTempBuff.bytes[1] = g_psTimeRegs.ui8Second;
    psTempBuff.bytes[2] = g_psTimeRegs.ui8Minute;
    psTempBuff.bytes[3] = g_psTimeRegs.ui8Hour;
    psTempBuff.bytes[4] = g_psTimeRegs.ui8Date;
    psTempBuff.bytes[5] = g_psTimeRegs.ui8Month;
    psTempBuff.bytes[6] = g_psTimeRegs.ui8Year;
    psTempBuff.bytes[7] = g_psTimeRegs.ui8Weekday;

    //
    // Write the values to the AMX8X5.
    //
    am_devices_amx8x5_reg_block_write(psDevice, AM_DEVICES_AMX8X5_HUNDREDTHS,
                                      psTempBuff.words,
                                      8, NULL);

    //
    // Load the final value of the WRTC bit based on the value of ui8Protect.
    // Clear the WRTC bit and the STOP bit.
    // Invert the protect bit and update WRTC.
    //
    psTempBuff.bytes[0] = am_devices_amx8x5_reg_read(psDevice,
                                                AM_DEVICES_AMX8X5_CONTROL_1);
    psTempBuff.bytes[0] &= 0x7E;
    psTempBuff.bytes[0] |= (0x01 & (~ui8Protect));
    am_devices_amx8x5_reg_write(psDevice,
                                AM_DEVICES_AMX8X5_CONTROL_1,
                                psTempBuff.bytes[0]);
}

//*****************************************************************************
//
//! @brief Set the calibration.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param  ui8Mode:
//!        0 => calibrate the XT oscillator
//!        1 => calibrate the RC oscillator
//! @param   iAdjust: Adjustment in ppm.
//!
//!  Adjustment limits are:
//!         ui8Mode = 0 => (-610 to +242)
//!         ui8Mode = 1 => (-65536 to +65520)
//!         An iAdjust value of zero resets the selected oscillator calibration
//!         value to 0.
//!
//! This function loads the AMX8XX counter registers with the current
//! g_psTimeRegs structure values.
//!
//! @return None
//
//*****************************************************************************
void
am_devices_amx8x5_cal_set(am_devices_amx8x5_t *psDevice, uint8_t ui8Mode,
                          int32_t iAdjust)
{
    int32_t iAdjint;
    uint8_t ui8Adjreg;
    uint8_t ui8Adjregu;
    uint8_t ui8XTcal;

    //
    // Calculate current calibration value:
    //    adjval = (double)iAdjust;
    //    iAdjint = (int16_t)round(adjval*1000/1907)
    //
    if (iAdjust < 0 )
    {
        iAdjint = ((iAdjust)*1000 - 953);
    }
    else
    {
        iAdjint = ((iAdjust)*1000 + 953);
    }
    iAdjint = iAdjint / 1907;

    if (ui8Mode == 0)
    {
        //
        // XT Adjust
        //
        if (iAdjint > 63 )
        {
            //
            // 64 to 127.
            // CMDX = 1.
            //
            ui8XTcal = 0;
            ui8Adjreg = ((iAdjint >> 1) & 0x3F) | 0x80;
        }
        else if (iAdjint > -65)
        {
            //
            // -64 to 63.
            // CMDX = 0.
            //
            ui8XTcal = 0;
            ui8Adjreg = (iAdjint & 0x7F);
        }
        else if (iAdjint > -129)
        {
            //
            // -128 to -65.
            // CMDX = 0.
            //
            ui8XTcal = 1;
            ui8Adjreg = ((iAdjint + 64) & 0x7F);
        }
        else if (iAdjint > -193)
        {
            //
            // -192 to -129.
            // CMDX = 0.
            //
            ui8XTcal = 2;
            ui8Adjreg = ((iAdjint + 128) & 0x7F);
        }
        else if (iAdjint > -257)
        {
            //
            // -256 to -193.
            // CMDX = 0.
            //
            ui8XTcal = 3;
            ui8Adjreg = ((iAdjint + 192) & 0x7F);
        }
        else
        {
            //
            // -320 to -257.
            // CMDX = 1.
            //
            ui8XTcal = 3;
            ui8Adjreg = ((iAdjint + 192) >> 1) & 0xFF;
        }
        //
        // Load the CALX register.
        //
        am_devices_amx8x5_reg_write(psDevice,
                                    AM_DEVICES_AMX8X5_CAL_XT, ui8Adjreg);

        //
        // Mask ui8XTcal.
        //
        ui8Adjreg = am_devices_amx8x5_reg_read(psDevice,
                                           AM_DEVICES_AMX8X5_OSC_STATUS) & 0x3F;

        //
        // Add ui8XTcal field.
        //
        ui8Adjreg = ui8Adjreg | (ui8XTcal << 6);

        //
        // Write it back.
        //
        am_devices_amx8x5_reg_write(psDevice,
                                    AM_DEVICES_AMX8X5_OSC_STATUS, ui8Adjreg);
    }
    else
    {
        //
        // RC Adjust.
        //
        if (iAdjint > 32767 )
        {
            //
            // 32768 to 65535.
            // Lower 8 bits.
            // CMDR = 3.
            //
            ui8Adjreg = ((iAdjint >> 3) & 0xFF);
            ui8Adjregu = ((iAdjint >> 11) | 0xC0);
        }
        else if (iAdjint > 16383 )
        {
            //
            // 16384 to 32767.
            // Lower 8 bits.
            // CMDR = 2.
            //
            ui8Adjreg = ((iAdjint >> 2) & 0xFF);
            ui8Adjregu = ((iAdjint >> 10) | 0x80);
        }
        else if (iAdjint > 8191 )
        {
            //
            // 8192 to 16383.
            // Lower 8 bits.
            // CMDR = 2.
            //
            ui8Adjreg = ((iAdjint >> 1) & 0xFF);
            ui8Adjregu = ((iAdjint >> 9) | 0x40);
        }
        else if (iAdjint >= 0 )
        {
            //
            // 0 to 1023.
            // Lower 8 bits.
            // CMDR = 0.
            //
            ui8Adjreg = ((iAdjint) & 0xFF);
            ui8Adjregu = (iAdjint >> 8);
        }
        else if (iAdjint > -8193 )
        {
            //
            // -8192 to -1.
            // Lower 8 bits.
            // CMDR = 0.
            //
            ui8Adjreg = ((iAdjint) & 0xFF);
            ui8Adjregu = (iAdjint >> 8) & 0x3F;
        }
        else if (iAdjint > -16385 )
        {
            //
            // -16384 to -8193.
            // Lower 8 bits.
            // CMDR = 1.
            //
            ui8Adjreg = ((iAdjint >> 1) & 0xFF);
            ui8Adjregu = (iAdjint >> 9) & 0x7F;
        }
        else if (iAdjint > -32769 )
        {
            //
            // -32768 to -16385.
            // Lower 8 bits.
            // CMDR = 2.
            //
            ui8Adjreg = ((iAdjint >> 2) & 0xFF);
            ui8Adjregu = (iAdjint >> 10) & 0xBF;
        }
        else
        {
            //
            // -65536 to -32769.
            // Lower 8 bits.
            // CMDR = 3.
            //
            ui8Adjreg = ((iAdjint >> 3) & 0xFF);
            ui8Adjregu = (iAdjint >> 11) & 0xFF;
        }

        //
        // Load the CALRU register.
        //
        am_devices_amx8x5_reg_write(psDevice,
                                    AM_DEVICES_AMX8X5_CAL_RC_HI, ui8Adjregu);

        //
        // Load the CALRL register.
        //
        am_devices_amx8x5_reg_write(psDevice,
                                    AM_DEVICES_AMX8X5_CAL_RC_LOW, ui8Adjreg);
    }
}

//*****************************************************************************
//
//! @brief Set the alarm value.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param ui8Repeat - the alarm repeat interval
//!        0 => disable alarm
//!        1 => once per year
//!        2 => once per month
//!        3 => once per week
//!        4 => once per day
//!        5 => once per hour
//!        6 => once per minute
//!        7 => once per second
//!        8 => once per 10th of a second
//!        9 => once per 100th of a second
//!        NOTE: year and century are not used
//!        NOTE: mode must match current 12/24 selection
//! @param ui8IntMode - define the interrupt mode
//!        0 => level interrupt
//!        1 => pulse of 1/8192s (XT) or 1/128 s (RC)
//!        2 => pulse of 1/64 s
//!        3 => pulse of 1/4 s
//! @param ui8Pin - pin on which to generate the interrupt
//!        0 => internal flag only
//!        1 => FOUT/nIRQ
//!        2 => PSW/nIRQ2
//!
//! This function sets the alarm value and configures the correct pin (if
//! necessary).
//!
//! @return None
//
//*****************************************************************************
void
am_devices_amx8x5_alarm_set(am_devices_amx8x5_t *psDevice, uint8_t ui8Repeat,
                            uint8_t ui8IntMode, uint8_t ui8Pin)
{
    uint8_t ui8Temp;
    am_hal_iom_buffer(8) psTempBuff;

    //
    // Convert decimal to binary-coded decimal.
    //
    g_psTimeRegs.ui8Hundredth = am_util_math_dec_to_bcd(
                                             g_psTimeRegs.ui8Hundredth);
    g_psTimeRegs.ui8Second = am_util_math_dec_to_bcd(g_psTimeRegs.ui8Second);
    g_psTimeRegs.ui8Minute = am_util_math_dec_to_bcd(g_psTimeRegs.ui8Minute);
    g_psTimeRegs.ui8Hour = am_util_math_dec_to_bcd(g_psTimeRegs.ui8Hour);
    g_psTimeRegs.ui8Date = am_util_math_dec_to_bcd(g_psTimeRegs.ui8Date);
    g_psTimeRegs.ui8Weekday = am_util_math_dec_to_bcd(g_psTimeRegs.ui8Weekday);
    g_psTimeRegs.ui8Month = am_util_math_dec_to_bcd(g_psTimeRegs.ui8Month);

    //
    // Determine whether a 12-hour or a 24-hour time keeping mode is being
    // used.
    //
    if (g_psTimeRegs.ui8Mode == 1)
    {
        //
        // A 12-hour day PM.
        // Set AM/PM.
        //
        g_psTimeRegs.ui8Hour = g_psTimeRegs.ui8Hour | 0x20;
    }

    //
    // Write all of the time counters.
    //
    psTempBuff.bytes[0] = g_psTimeRegs.ui8Hundredth;
    psTempBuff.bytes[1] = g_psTimeRegs.ui8Second;
    psTempBuff.bytes[2] = g_psTimeRegs.ui8Minute;
    psTempBuff.bytes[3] = g_psTimeRegs.ui8Hour;
    psTempBuff.bytes[4] = g_psTimeRegs.ui8Date;
    psTempBuff.bytes[5] = g_psTimeRegs.ui8Month;
    psTempBuff.bytes[6] = g_psTimeRegs.ui8Weekday;

    //
    // Clear the RPT field.
    // Clear the AIE bit IM field.
    // Clear the ALM flag.
    //
    am_devices_amx8x5_reg_clear(psDevice, AM_DEVICES_AMX8X5_TIMER_CTRL, 0x1C);
    am_devices_amx8x5_reg_clear(psDevice, AM_DEVICES_AMX8X5_INT_MASK, 0x64);
    am_devices_amx8x5_reg_clear(psDevice, AM_DEVICES_AMX8X5_STATUS, 0x04);

    if (ui8Pin == 1)
    {
        //
        // Interrupt on FOUT/nIRQ.
        // Get the Control2 Register.
        //
        ui8Temp = am_devices_amx8x5_reg_read(psDevice,
                                             AM_DEVICES_AMX8X5_CONTROL_2);

        //
        // Extract the OUT1S field.
        //
        ui8Temp = (ui8Temp & 0x03);

        //
        // Not already selecting nIRQ.
        //
        if (ui8Temp != 0)
        {
            //
            // Set OUT1S to 3.
            //
            am_devices_amx8x5_reg_set(psDevice,
                                      AM_DEVICES_AMX8X5_CONTROL_2, 0x03);
        }
    }
    if (ui8Pin == 2)
    {
        //
        // Interrupt on PSW/nIRQ2.
        // Get the Control2 Register.
        //
        ui8Temp = am_devices_amx8x5_reg_read(psDevice,
                                             AM_DEVICES_AMX8X5_CONTROL_2);

        //
        // Extract the OUT2S field.
        //
        ui8Temp &= 0x1C;

        //
        // Not already selecting nIRQ.
        //
        if (ui8Temp != 0)
        {
            //
            // Clear OUT2S & Set OUT2S to 3.
            //
            am_devices_amx8x5_reg_clear(psDevice,
                                        AM_DEVICES_AMX8X5_CONTROL_2, 0x1C);
            am_devices_amx8x5_reg_set(psDevice,
                                      AM_DEVICES_AMX8X5_CONTROL_2, 0x0C);
        }
    }

    if (ui8Repeat == 8)
    {
        //
        // 10ths interrupt.
        // Select correct RPT value.
        //
        psTempBuff.bytes[0] |= 0xF0;
        ui8Repeat = 7;
    }
    if (ui8Repeat == 9)
    {
        //
        // 100ths interrupt.
        // Select correct RPT value.
        //
        psTempBuff.bytes[0] = 0xFF;
        ui8Repeat = 7;
    }

    //
    // Don't initiate if ui8Repeat = 0.
    //
    if (ui8Repeat != 0)
    {
        //
        // Set the RPT field to the value of ui8Repeat.
        //
        ui8Temp = (ui8Repeat << 2);

        //
        // Was previously cleared.
        // Set the alarm interrupt mode.
        // Execute the burst write.
        // Set the AIE bit.
        //
        am_devices_amx8x5_reg_set(psDevice,
                                  AM_DEVICES_AMX8X5_TIMER_CTRL, ui8Temp);
        am_devices_amx8x5_reg_set(psDevice, AM_DEVICES_AMX8X5_INT_MASK,
                                  (ui8IntMode << 5));
        am_devices_amx8x5_reg_block_write(psDevice,
                                          AM_DEVICES_AMX8X5_ALARM_HUNDRS,
                                          psTempBuff.words, 7, NULL);
        am_devices_amx8x5_reg_set(psDevice, AM_DEVICES_AMX8X5_INT_MASK, 0x04);
    }
    else
    {
        //
        // Set IM field to 0x3 (reset value) to minimize current draw.
        //
        am_devices_amx8x5_reg_set(psDevice, AM_DEVICES_AMX8X5_INT_MASK, 0x60);
    }
}

//*****************************************************************************
//
//! @brief Configure and set the countdown.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param ui8Range:    0 => iPeriod in us
//!                     1 => iPeriod in seconds
//! @param iPeriod - the iPeriod of the countdown timer.
//! @param ui8Repeat - Configure the interrupt output type:
//!        0 => generate a single level interrupt
//!        1 => generate a repeated pulsed interrupt, 1/4096 s (XT mode), 1/128 s
//!        (RC mode)
//!                (ui8Range must be 0)
//!        2 => generate a single pulsed interrupt, 1/4096 s (XT mode), 1/128 s
//!        (RC mode)
//!                (ui8Range must be 0)
//!        3 => generate a repeated pulsed interrupt, 1/128 s (ui8Range must be 0)
//!        4 => generate a single pulsed interrupt, 1/128 s (ui8Range must be 0)
//!        5 => generate a repeated pulsed interrupt, 1/64 s (ui8Range must be 1)
//!        6 => generate a single pulsed interrupt, 1/64 s (ui8Range must be 1)
//! @param ui8Pin - Select the pin to generate a countdown interrupt:
//!        0 => disable the countdown timer
//!        1 => generate an interrupt on nTIRQ only, asserted low
//!        2 => generate an interrupt on FOUT/nIRQ and nTIRQ, both asserted low
//!        3 => generate an interrupt on PSW/nIRQ2 and nTIRQ, both asserted low
//!        4 => generate an interrupt on CLKOUT/nIRQ3 and nTIRQ, both asserted low
//!        5 => generate an interrupt on CLKOUT/nIRQ3 (asserted high) and nTIRQ
//!        (asserted low)
//!
//! This function configures and sets the countdown.
//!
//! @return None
//
//*****************************************************************************
void
am_devices_amx8x5_countdown_set(am_devices_amx8x5_t *psDevice, uint8_t ui8Range,
                                int32_t iPeriod, uint8_t ui8Repeat,
                                uint8_t ui8Pin)
{
    uint8_t ui8TM = 0;
    uint8_t ui8TRPT = 0;
    uint8_t ui8TFS = 0;
    uint8_t ui8TE;
    uint8_t ui8Temp;
    uint8_t ui8TCTRL;
    int32_t ui8Timer = 0;
    uint8_t ui8OMODE;

    //
    // 0 = XT, 1 = RC
    //
    ui8OMODE = (am_devices_amx8x5_reg_read(psDevice,
                AM_DEVICES_AMX8X5_OSC_STATUS) & 0x10) ? 1 : 0;

    if (ui8Pin == 0)
    {
        ui8TE = 0;
    }
    else
    {
        ui8TE = 1;
        if (ui8Repeat == 0)
        {
            //
            // Level interrupt
            //
            ui8TM = 1;
            ui8TRPT = 0;
            if (ui8Range == 0)
            {
                // Microseconds
                if (ui8OMODE == 0)
                {
                    //
                    // XT Mode.
                    // Use 4K Hz.
                    //
                    if (iPeriod <= 62500)
                    {
                        ui8TFS = 0;
                        ui8Timer = (iPeriod * 4096);
                        ui8Timer = ui8Timer / 1000000;
                        ui8Timer = ui8Timer - 1;
                    }

                    //
                    // Use 64 Hz
                    //
                    else if (iPeriod <= 16384000)
                    {
                        ui8TFS = 1;
                        ui8Timer = (iPeriod * 64);
                        ui8Timer /= 1000000;
                        ui8Timer = ui8Timer - 1;
                    }

                    //
                    // Else, use 1 Hz.
                    //
                    else
                    {
                        ui8TFS = 2;
                        ui8Timer = iPeriod / 1000000;
                        ui8Timer = ui8Timer - 1;
                    }
                }
                else
                {
                    //
                    // RC Mode.
                    // Use 128 Hz.
                    //
                    if (iPeriod <= 2000000)
                    {
                        ui8TFS = 0;
                        ui8Timer = (iPeriod * 128);
                        ui8Timer /= 1000000;
                        ui8Timer = ui8Timer - 1;
                    }

                    //
                    // Use 64 Hz.
                    //
                    else if (iPeriod <= 4000000)
                    {
                        ui8TFS = 1;
                        ui8Timer = (iPeriod * 64);
                        ui8Timer /= 1000000;
                        ui8Timer = ui8Timer - 1;
                    }

                    //
                    // Else, use 1 Hz.
                    //
                    else
                    {
                        ui8TFS = 2;
                        ui8Timer = iPeriod / 1000000;
                        ui8Timer = ui8Timer - 1;
                    }
                }
            }
            else
            {
                //
                // Seconds
                //
                if (iPeriod <= 256)
                {
                    //
                    // Use 1 Hz.
                    //
                    ui8TFS = 2;
                    ui8Timer = iPeriod - 1;
                }
                else
                {
                    //
                    // Use 1/60 Hz.
                    //
                    ui8TFS = 3;
                    ui8Timer = iPeriod / 60;
                    ui8Timer = ui8Timer - 1;
                }
            }
        }
        else
        {
            //
            // Pulse interrupts.
            // Set up ui8Repeat.
            //
            ui8TM = 0;
            ui8TRPT = ui8Repeat & 0x01;
            if (ui8Repeat < 3)
            {
                ui8TFS = 0;
                if (ui8OMODE == 0)
                {
                    ui8Timer = (iPeriod * 4096);
                    ui8Timer /= 1000000;
                    ui8Timer = ui8Timer - 1;
                }
                else
                {
                    ui8Timer = (iPeriod * 128);
                    ui8Timer /= 1000000;
                    ui8Timer = ui8Timer - 1;
                }
            }
            else if (ui8Repeat < 5)
            {
                ui8TFS = 1;
                ui8Timer = (iPeriod * 128);
                ui8Timer /= 1000000;
                ui8Timer = ui8Timer - 1;
            }
            else if (iPeriod <= 256)
            {
                //
                // Use 1 Hz.
                //
                ui8TFS = 2;
                ui8Timer = iPeriod - 1;
            }
            else
            {
                //
                // Use 1/60 Hz.
                //
                ui8TFS = 3;
                ui8Timer = iPeriod / 60;
                ui8Timer = ui8Timer - 1;
            }
        }
    }

    //
    // Get TCTRL, keep RPT, clear TE.
    //
    ui8TCTRL = am_devices_amx8x5_reg_read(psDevice,
                                          AM_DEVICES_AMX8X5_TIMER_CTRL) & 0x1C;
    am_devices_amx8x5_reg_write(psDevice,
                                AM_DEVICES_AMX8X5_TIMER_CTRL, ui8TCTRL);

    //
    // Merge the fields.
    //
    ui8TCTRL = ui8TCTRL | (ui8TE * 0x80) | (ui8TM * 0x40) |
        (ui8TRPT * 0x20) | ui8TFS;

    //
    // Generate nTIRQ interrupt on FOUT/nIRQ (asserted low).
    //
    if (ui8Pin == 2)
    {
        //
        // Clear OUT1S.
        //
        am_devices_amx8x5_reg_clear(psDevice, AM_DEVICES_AMX8X5_CONTROL_2, 0x3);
    }

    //
    // Generate nTIRQ interrupt on PSW/nIRQ2 (asserted low).
    //
    if (ui8Pin == 3)
    {
        //
        // Get OUT2S.
        //
        ui8Temp = am_devices_amx8x5_reg_read(psDevice,
                                             AM_DEVICES_AMX8X5_CONTROL_2);

        //
        // If OUT2S != 0, set OUT2S to 5.
        //
        if ((ui8Temp & 0x1C) != 0)
        {
            ui8Temp = (ui8Temp & 0xE3) | 0x14;
        }

        //
        // Write back.
        //
        am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_CONTROL_2,
                                    ui8Temp);
    }

    //
    // Generate TIRQ interrupt on CLKOUT/nIRQ3 (asserted low).
    //
    if (ui8Pin == 4)
    {
        //
        // Setup SQFS field and enable SQWE.
        //
        am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_SQW, 0x9B);
    }

    //
    // Generate TIRQ interrupt on CLKOUT/nIRQ3 (asserted high).
    //
    if (ui8Pin == 5)
    {
        //
        // Setup SQFS field and enable SQWE.
        //
        am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_SQW, 0x9A);
    }

    if (ui8Pin != 0)
    {
        //
        // Clear TIM.
        // Set TIE.
        // Initialize the timer.
        // Initialize the timer repeat.
        // Start the timer.
        //
        am_devices_amx8x5_reg_clear(psDevice, AM_DEVICES_AMX8X5_STATUS, 0x08);
        am_devices_amx8x5_reg_set(psDevice, AM_DEVICES_AMX8X5_INT_MASK, 0x08);
        am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_TIMER,
                                    ui8Timer);
        am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_TIMER_INITIAL,
                                    ui8Timer);
        am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_TIMER_CTRL,
                                    ui8TCTRL);
    }
}

//*****************************************************************************
//
//! @brief Select an oscillator mode.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param ui8OSC - the oscillator to select
//!        0 => 32 KHz XT oscillator, no automatic oscillator switching
//!        1 => 32 KHz XT oscillator, automatic oscillator switching to RC on
//!        switch to battery power
//!        2 => 128 Hz RC oscillator
//!
//! This function sets the desired oscillator.
//!
//! @return 1 for error
//
//*****************************************************************************
uint32_t
am_devices_amx8x5_osc_sel(am_devices_amx8x5_t *psDevice, uint8_t ui8OSC)
{
    uint8_t i;
    uint8_t ui8Temp;

    //
    // Read Oscillator Control register.
    //
    ui8Temp = am_devices_amx8x5_reg_read(psDevice,
                                         AM_DEVICES_AMX8X5_OSC_CONTROL);
    ui8Temp = ui8Temp & 0x67;

    //
    // Enable Oscillator Register writes.
    // Write the Key register.
    //
    am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_CONFIG_KEY,
                                AM_DEVICES_AMX8X5_CONFIG_KEY_VAL);

    switch (ui8OSC)
    {
        //
        // Do nothing, clear Key register.
        //
        case 0:
        am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_OSC_CONTROL,
                                    ui8Temp);
        break;

        //
        // Set AOS.
        //
        case 1:
        ui8Temp = ui8Temp | 0x10;
        am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_OSC_CONTROL,
                                    ui8Temp);
        break;

        //
        // Set OSEL
        //
        default:
        ui8Temp = ui8Temp | 0x80;
        am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_OSC_CONTROL,
                                    ui8Temp);
        break;
    }

    //
    // Wait to make sure switch occurred by testing OMODE.
    //
    for (i = 0; i < 100; i++)
    {
        //
        // Wait 100 ms.
        // Read OMODE.
        //
        am_util_delay_ms(100);
        ui8Temp = am_devices_amx8x5_reg_read(psDevice,
                                             AM_DEVICES_AMX8X5_OSC_STATUS);
        ui8Temp = (ui8Temp & 0x10) >> 4;

        if (ui8Temp == (ui8OSC >> 1))
        {
            //
            // Successful switch.
            //
            return 0;
        }
    }

    //
    // Return Error.
    //
    return 1;
}

//*****************************************************************************
//
//! @brief Configure and enable the square wave output.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param ui8SQFS - square wave output select (0 to 31)
//! @param ui8Pin - output pin for SQW (may be ORed) in addition to CLKOUT
//!        0 => disable SQW
//!        1 => FOUT
//!        2 => PSW/nIRQ2
//!
//! This function configures and enables the square wave output.
//!
//! @return None
//
//*****************************************************************************
void
am_devices_amx8x5_sqw_set(am_devices_amx8x5_t *psDevice, uint8_t ui8SQFS,
                          uint8_t ui8Pin)
{
    uint8_t ui8Temp;

    //
    // Set up SQW multiplexor:
    // Read the SQW register.
    // Load ui8SQFS, set SQWE.
    //
    ui8Temp = am_devices_amx8x5_reg_read(psDevice, AM_DEVICES_AMX8X5_SQW);
    ui8Temp = (ui8Temp & 0x70) | ui8SQFS | 0x80;

    if (ui8Pin == 0)
    {
        //
        // Clear SQWE.
        //
        ui8Temp &= 0x7F;
    }

    if (ui8Pin & 0x1)
    {
        //
        // Enable FOUT:
        // Clear OUT1S.
        // Load OUT1S with 1.
        //
        am_devices_amx8x5_reg_clear(psDevice, AM_DEVICES_AMX8X5_CONTROL_2,
                                    0x03);
        am_devices_amx8x5_reg_set(psDevice, AM_DEVICES_AMX8X5_CONTROL_2, 0x01);
    }
    if (ui8Pin & 0x2)
    {
        //
        // Enable PSW/nIRQ2:
        // Clear OUT2S.
        // Load OUT2S with 1.
        //
        am_devices_amx8x5_reg_clear(psDevice, AM_DEVICES_AMX8X5_CONTROL_2,
                                    0x1C);
        am_devices_amx8x5_reg_set(psDevice, AM_DEVICES_AMX8X5_CONTROL_2, 0x04);
    }

    //
    // Write the SQW register.
    //
    am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_SQW, ui8Temp);
}

//*****************************************************************************
//
//! @brief Set up sleep mode (AM18x5 only).
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param ui8Timeout - minimum timeout period in 7.8 ms periods (0 to 7)
//! @param ui8Mode - sleep mode (nRST modes not available in AM08xx)
//!        0 => nRST is pulled low in sleep mode
//!        1 => PSW/nIRQ2 is pulled high on a sleep
//!        2 => nRST pulled low and PSW/nIRQ2 pulled high on sleep
//!
//! This function sets up sleep mode. This is available on the AM18x5 only.
//!
//! @return returned value of the attempted sleep command:
//!        0 => sleep request accepted, sleep mode will be initiated in
//!        ui8Timeout seconds
//!        1 => illegal input values
//!        2 => sleep request declined, interrupt is currently pending
//!        3 => sleep request declined, no sleep trigger interrupt enabled
//
//*****************************************************************************
uint32_t
am_devices_amx8x5_sleep_set(am_devices_amx8x5_t *psDevice, uint8_t ui8Timeout,
                            uint8_t ui8Mode)
{
    uint8_t ui8SLRES;
    uint8_t ui8Temp0, ui8Temp1;

    if (ui8Mode > 0)
    {
        //
        // Sleep to PSW/nIRQ2.
        // Read OUT2S.
        // MUST NOT WRITE OUT2S WITH 000.
        // Write value to OUT2S.
        //
        ui8Temp0 = am_devices_amx8x5_reg_read(psDevice,
                                              AM_DEVICES_AMX8X5_CONTROL_2);
        ui8Temp0 = (ui8Temp0 & 0xE3) | 0x18;
        am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_CONTROL_2,
                                    ui8Temp0);
        ui8SLRES = 0;
    }

    if (ui8Mode != 1)
    {
        //
        // Sleep to nRST.
        //
        ui8SLRES = 1;
    }

    //
    // Assemble SLEEP register value.
    // Write to the register.
    //
    ui8Temp0 = ui8Timeout | (ui8SLRES << 6) | 0x80;
    am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_SLEEP_CTRL,
                                ui8Temp0);

    //
    // Determine if SLEEP was accepted:
    // Get SLP bit.
    //
    ui8Temp0 = am_devices_amx8x5_reg_read(psDevice,
                                          AM_DEVICES_AMX8X5_SLEEP_CTRL) & 0x80;

    if (ui8Temp0 == 0)
    {
        //
        // SLEEP did not happen. Determine why and return reason:
        // Get status register interrupt enables.
        // Get WDT register.
        //
        ui8Temp0 = am_devices_amx8x5_reg_read(psDevice,
                                             AM_DEVICES_AMX8X5_INT_MASK) & 0x0F;
        ui8Temp1 = am_devices_amx8x5_reg_read(psDevice, AM_DEVICES_AMX8X5_WDT);

        if ((ui8Temp0 == 0) & (((ui8Temp1 & 0x7C) == 0) ||
                               ((ui8Temp1 & 0x80) == 0x80)))
        {
            //
            // No trigger interrupts enabled.
            //
            return 3;
        }
        else
        {
            //
            // Interrupt pending.
            //
            return 2;
        }
    }
    else
    {
        //
        // SLEEP request successful.
        //
        return 0;
    }
}

//*****************************************************************************
//
//! @brief Set up the watchdog timer.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param ui8Period - timeout period in ms (65 to 124,000)
//! @param ui8Pin - pin to generate the watchdog signal
//!        0 => disable WDT
//!        1 => generate an interrupt on FOUT/nIRQ
//!        2 => generate an interrupt on PSW/nIRQ2
//!        3 => generate a reset on nRST (AM18xx only)
//!
//! This function sets up sleep mode. This is available on the AM18x5 only.
//!
//! @return None
//
//*****************************************************************************
void
am_devices_amx8x5_watchdog_set(am_devices_amx8x5_t *psDevice,
                               uint32_t ui8Period, uint8_t ui8Pin)
{
    uint8_t ui8WDTreg;
    uint8_t ui8WDS;
    uint8_t ui8BMB;
    uint8_t ui8WRB;

    //
    // Disable the WDT with BMB = 0.
    // Clear the WDT flag.
    //
    am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_WDT, 0x00);
    am_devices_amx8x5_reg_clear(psDevice, AM_DEVICES_AMX8X5_STATUS, 0x20);

    //
    // Use the shortest clock interval which will allow the selected period.
    //
    if (ui8Period < (31000 / 16))
    {
        //
        // Use 16 Hz.
        //
        ui8WRB = 0;
        ui8BMB = (ui8Period * 16) / 1000;
    }
    else if (ui8Period < (31000 / 4))
    {
        //
        // Use 4 Hz.
        //
        ui8WRB = 1;
        ui8BMB = (ui8Period * 4) / 1000;
    }
    else if (ui8Period < 31000)
    {
        //
        // Use 1 Hz.
        //
        ui8WRB = 2;
        ui8BMB = ui8Period / 1000;
    }
    else
    {
        //
        // Use 1/4 Hz.
        //
        ui8WRB = 3;
        ui8BMB = ui8Period / 4000;
    }

    switch (ui8Pin)
    {
        //
        // Disable WDT.
        //
        case 0:
        ui8WDS = 0;
        ui8BMB = 0;
        break;

        //
        // Interrupt on FOUT/nIRQ.
        //
        case 1:
        //
        // Select interrupt.
        // Clear the OUT1S field
        //
        ui8WDS = 0;
        am_devices_amx8x5_reg_clear(psDevice, AM_DEVICES_AMX8X5_CONTROL_2,
                                    0x03);
        break;

        //
        // Interrupt on PSW/nIRQ2.
        //
        case 2:
        //
        // Select interrupt.
        // Clear the OUT2S field.
        //
        ui8WDS = 0;
        am_devices_amx8x5_reg_clear(psDevice, AM_DEVICES_AMX8X5_CONTROL_2,
                                    0x1C);
        break;

        //
        // Interrupt on nRST.
        //
        case 3:
        default:
        //
        // Select reset out.
        //
        ui8WDS = 1;
        break;
    }

    //
    // Create the correct value.
    // Write the register.
    //
    ui8WDTreg = (ui8WDS * 0x80) + (ui8BMB * 0x4) + ui8WRB;
    am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_WDT, ui8WDTreg);
}

//*****************************************************************************
//
//! @brief Set up autocalibration.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param ui8Period - the repeat period for autocalibration.
//!        0 => disable autocalibration
//!        1 => execute a single autocalibration cycle
//!        2 => execute a cycle every 1024 seconds (~17 minutes)
//!        3 => execute a cycle every 512 seconds (~8.5 minutes)
//!
//! This function sets up autocalibration.
//!
//! @return None
//
//*****************************************************************************
void
am_devices_amx8x5_autocal_set(am_devices_amx8x5_t *psDevice, uint8_t ui8Period)
{
    uint8_t ui8Temp;

    //
    // Read Oscillator Control, mask ACAL.
    //
    ui8Temp = am_devices_amx8x5_reg_read(psDevice,
                                         AM_DEVICES_AMX8X5_OSC_CONTROL);
    ui8Temp &= 0x9F;

    //
    // Write the Key register.
    //
    am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_CONFIG_KEY,
                                AM_DEVICES_AMX8X5_CONFIG_KEY_VAL);

    switch (ui8Period)
    {
        case 0:
        //
        // Set ACAL to 0.
        //
        am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_OSC_CONTROL,
                                    ui8Temp);
        break;

        case 1:
        //
        // Set ACAL to 2
        //
        ui8Temp |= 0x40;
        am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_OSC_CONTROL,
                                    ui8Temp);

        //
        // Wait for initiation of autocal (10 ms).
        //
        am_util_delay_ms(10);

        //
        // Write the Key register.
        //
        am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_CONFIG_KEY,
                                    AM_DEVICES_AMX8X5_CONFIG_KEY_VAL);

        //
        // Mask ACAL.
        // Set ACAL to 0
        //
        ui8Temp = ui8Temp & 0x9F;
        am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_OSC_CONTROL,
                                    ui8Temp);
        break;

        case 2:
        //
        // Set ACAL to 2.
        //
        ui8Temp = ui8Temp | 0x40;
        am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_OSC_CONTROL,
                                    ui8Temp);
        break;

        case 3:
        //
        // Set ACAL to 3.
        //
        ui8Temp = ui8Temp | 0x60;
        am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_OSC_CONTROL,
                                    ui8Temp);
        break;
    }
}

//*****************************************************************************
//
//! @brief Gets the extension address for the AMx8x5..
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param ui8Address is the address.
//!
//! This function returns the extension address.
//!
//! @return the externsion address
//
//*****************************************************************************
uint8_t
am_devices_amx8x5_ext_address_get(am_devices_amx8x5_t *psDevice,
                                  uint8_t ui8Address)
{
    uint8_t ui8Xadd, ui8Temp;

    ui8Temp = am_devices_amx8x5_reg_read(psDevice,
                                        AM_DEVICES_AMX8X5_EXTENDED_ADDR) & 0xC0;

    if (ui8Address < 64)
    {
        ui8Xadd = 0x8;
    }
    else if (ui8Address < 128)
    {
        ui8Xadd = 0x9;
    }
    else if (ui8Address < 192)
    {
        ui8Xadd = 0xA;
    }
    else
    {
        ui8Xadd = 0xB;
    }

    //
    // Return the address.
    //
    return (ui8Xadd | ui8Temp);
}

//*****************************************************************************
//
//! @brief Reads a block of internal registers in the AMx8x5.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param ui32StartRegister is the address of the first register to read.
//! @param pui32Values is the byte-packed array where the read data will go.
//! @param ui32NumBytes is the total number of registers to read.
//! @param pfnCallback is an optional callback function pointer.
//!
//! This function performs a read to a block of AMx8x5 registers over the
//! serial bus. If the \e pfnCallback parameter is nonzero, this function will
//! use the am_hal_iom_spi_read_nb() function as the underlying interface, and
//! \e pfnCallback will be provided to the HAL as the IOM callback function.
//! Otherwise, the spi read will be polled.
//!
//! @return None
//
//*****************************************************************************
void
am_devices_amx8x5_reg_block_read(am_devices_amx8x5_t *psDevice,
                                 uint8_t ui8StartRegister,
                                 uint32_t *pui32Values,
                                 uint32_t ui32NumBytes,
                                 am_hal_iom_callback_t pfnCallback)
{
    uint8_t ui8Offset;

    //
    // Build the SPI offset for writing a block of registers from the
    // user-supplied start point.
    //
    ui8Offset = ui8StartRegister;

    //
    // If SPI mode else I2C.
    //
    if (psDevice->bMode == AM_DEVICES_AMX8X5_MODE_SPI)
    {
        //
        // Check to see if the callback pointer is valid.
        //
        if (pfnCallback)
        {
            //
            // If so, use a non-blocking call with a callback.
            //
            am_hal_iom_spi_read_nb(psDevice->ui32IOMModule,
                                   psDevice->ui32ChipSelect,
                                   pui32Values, ui32NumBytes,
                                   AM_HAL_IOM_OFFSET(ui8Offset),
                                   pfnCallback);
        }
        else
        {
            //
            // Otherwise, use a polled call.
            //
            am_hal_iom_spi_read(psDevice->ui32IOMModule,
                                psDevice->ui32ChipSelect,
                                pui32Values, ui32NumBytes,
                                AM_HAL_IOM_OFFSET(ui8Offset));
        }
    }
    else
    {
        //
        // Check to see if the callback pointer is valid.
        //
        if (pfnCallback)
        {
            //
            // If so, use a non-blocking call with a callback.
            //
            am_hal_iom_i2c_read_nb(psDevice->ui32IOMModule,
                                    psDevice->ui32Address,
                                    pui32Values, ui32NumBytes,
                                    AM_HAL_IOM_OFFSET(ui8Offset),
                                    pfnCallback);
        }
        else
        {
            //
            // Otherwise, use a polled call.
            //
            am_hal_iom_i2c_read(psDevice->ui32IOMModule,
                                 psDevice->ui32Address,
                                 pui32Values, ui32NumBytes,
                                 AM_HAL_IOM_OFFSET(ui8Offset));
        }
    }
}

//*****************************************************************************
//
//! @brief Writes a block of internal registers in the AMx8x5.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param ui32StartRegister is the address of the first register to write.
//! @param pui32Values is the byte-packed array of data to write.
//! @param ui32NumBytes is the total number of registers to write.
//! @param pfnCallback is an optional callback function pointer.
//!
//! This function performs a write to a block of AMx8x5 registers over the
//! serial bus. If the \e pfnCallback parameter is nonzero, this function will
//! use the am_hal_iom_spi_write_nb() function as the underlying interface, and
//! \e pfnCallback will be provided to the HAL as the IOM callback function.
//! Otherwise, the spi write will be polled.
//!
//! @return None
//
//*****************************************************************************
void
am_devices_amx8x5_reg_block_write(am_devices_amx8x5_t *psDevice,
                                  uint8_t ui8StartRegister,
                                  uint32_t *pui32Values,
                                  uint32_t ui32NumBytes,
                                  am_hal_iom_callback_t pfnCallback)
{
    uint8_t ui8Offset;

    //
    // Build the offset for writing a block of registers from the
    // user-supplied start point.
    //
    ui8Offset = ui8StartRegister;

    //
    // If SPI mode else I2C.
    //
    if (psDevice->bMode == AM_DEVICES_AMX8X5_MODE_SPI)
    {
        //
        // Check to see if the callback pointer is valid.
        //
        if (pfnCallback)
        {
            //
            // If so, use a non-blocking call with a callback.
            //
            am_hal_iom_spi_write_nb(psDevice->ui32IOMModule,
                                    psDevice->ui32ChipSelect,
                                    pui32Values, ui32NumBytes,
                                    AM_HAL_IOM_OFFSET(ui8Offset),
                                    pfnCallback);
        }
        else
        {
            //
            // Otherwise, use a polled call.
            //
            am_hal_iom_spi_write(psDevice->ui32IOMModule,
                                 psDevice->ui32ChipSelect,
                                 pui32Values, ui32NumBytes,
                                 AM_HAL_IOM_OFFSET(ui8Offset));
        }
    }
    else
    {
        //
        // Check to see if the callback pointer is valid.
        //
        if (pfnCallback)
        {
            //
            // If so, use a non-blocking call with a callback.
            //
            am_hal_iom_i2c_write_nb(psDevice->ui32IOMModule,
                                    psDevice->ui32Address,
                                    pui32Values, ui32NumBytes,
                                    AM_HAL_IOM_OFFSET(ui8Offset),
                                    pfnCallback);
        }
        else
        {
            //
            // Otherwise, use a polled call.
            //
            am_hal_iom_i2c_write(psDevice->ui32IOMModule,
                                 psDevice->ui32Address,
                                 pui32Values, ui32NumBytes,
                                 AM_HAL_IOM_OFFSET(ui8Offset));
        }
    }
}

//*****************************************************************************
//
//! @brief Read a byte from the local AMX8X5 RAM.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param ui8Address - RTC RAM address.
//!
//! This function reads a byte from the local AMX8X5 RAM.
//!
//! @return the Value at the desired address.
//
//*****************************************************************************
uint8_t
am_devices_amx8x5_ram_read(am_devices_amx8x5_t *psDevice, uint8_t ui8Address)
{
    uint8_t ui8Xadd;

    //
    // Calc XADDR value from address.
    //
    ui8Xadd = am_devices_amx8x5_ext_address_get(psDevice, ui8Address);

    //
    // Load the XADDR register.
    //
    am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_EXTENDED_ADDR,
                                ui8Xadd);

    //
    // Read and return the data.
    //
    return am_devices_amx8x5_reg_read(psDevice, (ui8Address & 0x3F) | 0x40);
}

//*****************************************************************************
//
//! @brief Wrtie a byte to the local AMX8X5 RAM.
//!
//! @param psDevice is a pointer to a device structure describing the AMx8x5.
//! @param ui8Address - RTC RAM address.
//! @param ui8Val - Value to be written.
//!
//! This function writes a byte to the local AMX8X5 RAM.
//!
//! @return None
//
//*****************************************************************************
void
am_devices_amx8x5_ram_write(am_devices_amx8x5_t *psDevice, uint8_t ui8Address,
                            uint8_t ui8Data)
{
    uint8_t ui8Xadd;

    //
    // Calc XADDR value from address.
    //
    ui8Xadd = am_devices_amx8x5_ext_address_get(psDevice, ui8Address);

    //
    // Load the XADDR register.
    //
    am_devices_amx8x5_reg_write(psDevice, AM_DEVICES_AMX8X5_EXTENDED_ADDR,
                                ui8Xadd);

    //
    // Write the value.
    //
    am_devices_amx8x5_reg_write(psDevice, (ui8Address & 0x3F) | 0x40, ui8Data);
}
