//*****************************************************************************
//
//! @file am_devices_display_qg9696tswhg04.c
//!
//! @brief Driver for handling low-level graphics and display operations for
//!        the Forfuture Electron Technology qg9696tswhg04 OLED display module.
//!
//!        This Forfuture display is a 96x96, 4bpp monochrome (white) OLED
//!        incorporating a 4-wire SPI-only interface and is completely software
//!        compatible with the common SSD1327 display.
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

#include "am_mcu_apollo.h"
#include "am_util.h"
#include "am_devices.h"
#include "am_bsp.h"

//*****************************************************************************
//
// Local definitions.
//
//*****************************************************************************
#define ADDR_MODE_NONE  0
#define ADDR_MODE_HORZ  1
#define ADDR_MODE_VERT  2

#define ROTATE_90       0       // 1 = rotate image 90 (counter-clockwise)

//*****************************************************************************
//
// Global variables.
//
//*****************************************************************************
static uint32_t g_ui32AddressMode = ADDR_MODE_NONE;
static uint32_t g_bDCn = false;

static volatile bool bComplete = false;
am_hal_iom_callback_t display_qg9696tswhg04_yield;
am_hal_iom_callback_t display_qg9696tswhg04_callback;

static uint32_t g_ui32IOMBuf[64 / 4];
static uint32_t g_FB4bitLine[96*4 / 8 / 4];

#if ROTATE_90
static uint8_t g_ui8MaskTbl[8] =
{
    0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01
};
#else // !ROTATE_90
static uint32_t g_XlateNibble[] =
{
    0x00000000, //0
    0x00000F00, //1
    0x0000F000, //2
    0x0000FF00, //3
    0x0000000F, //4
    0x00000F0F, //5
    0x0000F00F, //6
    0x0000FF0F, //7
    0x000000F0, //8

    0x00000FF0, //9
    0x0000F0F0, //A
    0x0000FFF0, //B
    0x000000FF, //C
    0x00000FFF, //D
    0x0000F0FF, //E
    0x0000FFFF, //F
};
#endif // ROTATE_90

//*****************************************************************************
//
// Static helper functions.
//
//*****************************************************************************
static void
IOMCallBack(void)
{
    bComplete = true;
}

static void
IOMYield(void)
{
    while(!bComplete);
    bComplete = false;
}

//*****************************************************************************
//
// start_iom() - Static helper function.
//
//  This function starts a SPI transaction using the IOM parameters specified
//  in u32SPIparms and ui32CSpin.
//
//  @param
//  psDisplayContext    Pointer to the displey device context structure.
//                      The structure contains the IOM parameters ui32Module,
//                      ui32ChipSelect, and ui32ChipSelectPin.
//  pui32Data           Pointer to the data buffer.
//  ui32NumBytes        Number of bytes to send.
//  ui32Options         IOM command options, e.g. AM_HAL_IOM_RAW.
//
//*****************************************************************************
static void
start_iom(am_devices_display_qg9696tswhg04_t *psDisplayContext,
          uint32_t *pui32Data,
          uint32_t ui32NumBytes,
          uint32_t ui32Options)
{
    //
    // Write data to the display.
    //
    am_hal_iom_queue_spi_write(psDisplayContext->ui32Module,
                         psDisplayContext->ui32ChipSelect,
                         pui32Data,
                         ui32NumBytes,
                         ui32Options,
                         display_qg9696tswhg04_callback);

    display_qg9696tswhg04_yield();

} // start_iom()

//*****************************************************************************
//
// send_cmd() - Send a command to the display.
//
//  This function sends a display COMMAND by first setting D/C low.  The
//  command can be up to 3 bytes (3 bytes is the largest command the display
//  can handle).
//
//  @param
//  u8Cmd0 - Always contains a valid command byte.
//  u8Cmd1 - Used for 2 byte and 3 byte commands.  Ignored for 1 byte commands.
//  u8Cmd2 - Used for 3 byte commands.  Ignored for 1 or 2 byte commands.
//  ui32nBytes - The number of command bytes to be sent.
//  psDisplayContext    Pointer to the displey device context structure.
//
//*****************************************************************************
static void
send_cmd(uint8_t u8Cmd0, uint8_t u8Cmd1, uint8_t u8Cmd2, uint32_t ui32nBytes,
         am_devices_display_qg9696tswhg04_t *psDisplayContext)
{
    uint32_t ui32Buf[4 / 4];
    uint8_t *pui8Buf = (uint8_t*)ui32Buf;
    uint32_t ui32DCpin = psDisplayContext->ui32DCselect;

    if ( ui32nBytes > 3 )
    {
        //
        // Invalid command.
        //
        return;
    }

    //
    // Now send the device commands bytes.
    // The command will use up to 3 bytes, but must be terminated with a null.
    //
    pui8Buf[0] = u8Cmd0;
    pui8Buf[1] = u8Cmd1;
    pui8Buf[2] = u8Cmd2;
    pui8Buf[ui32nBytes] = 0x00;

    //
    // Take D/C low for commands
    // And set DC state
    //
    AM_HAL_GPIO_ENS(ui32DCpin) = AM_HAL_GPIO_ENS_M(ui32DCpin);
    AM_HAL_GPIO_WTC(ui32DCpin) = AM_HAL_GPIO_WTC_M(ui32DCpin);
    g_bDCn = false;

    //
    // We have a buffer to send.  Go send the bytes to the IOM.
    //
    start_iom(psDisplayContext, ui32Buf, ui32nBytes, AM_HAL_IOM_RAW);
}

//*****************************************************************************
//
// send_data() - Send multiple data bytes to the display.
//
//  This function sends multiple bytes of data to the display by first
//  setting D/C high.
//
//  @param
//  pui8Data            Pointer to the data bytes to be sent to the display.
//  ui32nBytes          The number of bytes to send to the display.
//  psDisplayContext    Pointer to the displey device context structure.
//
//*****************************************************************************
static void
send_data(uint8_t *pui8Data, uint32_t ui32nBytes,
          am_devices_display_qg9696tswhg04_t *psDisplayContext)
{
    uint8_t *pui8Buf = (uint8_t*)g_ui32IOMBuf;
    uint32_t ix, ui32SendBytes, ui32DCpin;
    uint32_t ui32ByteCnt = ui32nBytes;

    if ( !g_bDCn )
    {
        ui32DCpin = psDisplayContext->ui32DCselect;

        //
        // Take D/C high for data
        //
        AM_HAL_GPIO_ENS(ui32DCpin) = AM_HAL_GPIO_ENS_M(ui32DCpin);
        AM_HAL_GPIO_WTS(ui32DCpin) = AM_HAL_GPIO_WTS_M(ui32DCpin);

        g_bDCn = true;
    }

    //
    // Now send the device data bytes.
    // The data has to be word-aligned, so we'll need to stuff the bytes into
    // a stack array, which is 64 bytes to correspond to the IOM FIFO size.
    //
    while ( ui32ByteCnt )
    {
        ui32SendBytes = 0;
        for ( ix = 0; ui32ByteCnt > 0 && ix < 64; ix++ )
        {
            pui8Buf[ix] = *pui8Data++;
            ui32ByteCnt--;
            ui32SendBytes++;
        }

        //
        // We have a buffer to send.  Go send the bytes to the IOM.
        //
        start_iom(psDisplayContext, g_ui32IOMBuf, ui32SendBytes, AM_HAL_IOM_RAW);
    }
}

//*****************************************************************************
//
// set_horz_mode() - Set display for horizontal access mode.
//
//  This function sets the display for horizontal mode with autoincrement.
//  This is the typical mode in which pixels are read or written by rows, left
//  to right then to the next row.  No setting of address is required between
//  accesses.
//
//  Calling this function sets the address to 0,0.
//
//  @param
//  psDisplayContext    Pointer to the displey device context structure.
//
//*****************************************************************************
static void
set_horz_mode(am_devices_display_qg9696tswhg04_t *psDisplayContext)
{
    //
    // Remap to horizontal mode
    //
    send_cmd(QG9696TSWHG04_CMD2B_SET_REMAP, 0x53, 0, 2, psDisplayContext);

    //
    // Set row address.
    // Start 0, end 95.
    //
    send_cmd(QG9696TSWHG04_CMD3B_SET_ROW_ADDR, 0,
             AM_DISPLAY_QG9696TSWHG04_HEIGHT - 1, 3, psDisplayContext);


    //
    // Set column address.
    // Start from 8th column of driver IC, which is the 0th column for OLED.
    // End at (8+(96/8)).  Each column has 8 pixels.
    //
    send_cmd(QG9696TSWHG04_CMD3B_SET_COL_ADDR, 8,
             8 + (AM_DISPLAY_QG9696TSWHG04_WIDTH / 2) - 1, 3, psDisplayContext);

    //
    // Set the addressing mode state.
    //
    g_ui32AddressMode = ADDR_MODE_HORZ;

    //
    // Make sure we're done
    //
    am_hal_iom_poll_complete(psDisplayContext->ui32Module);
}


//*****************************************************************************
//
// set_row() - Set the row number for writing data.
//
//  This function sets the row number.  All subsequently written data will
//  start on the specified row.
//
//  @param
//  psDisplayContext    Pointer to the displey device context structure.
//  ui32BegLineNum      Beginning line number (0-based).
//  ui32EndLineNum      Ending line number (0-based).
//
//*****************************************************************************
static void
set_row(am_devices_display_qg9696tswhg04_t *psDisplayContext,
        uint32_t ui32BegLineNum, uint32_t ui32EndLineNum)
{
    //
    // Set row address.
    // By offseting by 1, a blank line on the display is avoided.
    //
    send_cmd(QG9696TSWHG04_CMD3B_SET_ROW_ADDR, ui32BegLineNum + 1,
             ui32EndLineNum + 1, 3, psDisplayContext);

    //
    // While we're at it, reset the column address.
    //
    send_cmd(QG9696TSWHG04_CMD3B_SET_COL_ADDR, 8,
             8 + (AM_DISPLAY_QG9696TSWHG04_WIDTH / 2) - 1, 3, psDisplayContext);

    //
    // Make sure we're done
    //
    am_hal_iom_poll_complete(psDisplayContext->ui32Module);
}

//*****************************************************************************
//
//! @brief Initialize the display device and driver.
//!
//! @param psDisplayContext     Pointer to the displey device context structure.
//!        psDisplayIOMConfig   NULL if interface is already configured, or
//!                             pointer to am_hal_iom_config_t structure.
//!
//! This function should be called before any other am_devices_display
//! functions. It optionally initializes the IO SPI interface and then the
//! display device.
//!
//! @return Non-zero if successful, 0 if fail.
//!         Non-zero indicates that the am_util_draw_context_t structure
//!         was successfully updated with device information as follows:
//!         bit0 if ui32HwFreshMs was successfully updated.
//!         bit1 if ui32DrawWidth and/or ui32DrawHeight were updated.
//
//*****************************************************************************
uint32_t
am_devices_display_qg9696tswhg04_init(
                        am_devices_display_qg9696tswhg04_t *psDisplayContext)
{
    uint32_t ui32Ret = 0x01;

    //
    // Initialize the IOM callbacks.
    //
    display_qg9696tswhg04_yield = (am_hal_iom_callback_t) IOMYield;
    display_qg9696tswhg04_callback = (am_hal_iom_callback_t) IOMCallBack;

    if ( (psDisplayContext->ui32DisplayWidth  != AM_DISPLAY_QG9696TSWHG04_WIDTH )  ||
         (psDisplayContext->ui32DisplayHeight != AM_DISPLAY_QG9696TSWHG04_HEIGHT) )
    {
        psDisplayContext->ui32DisplayWidth  = AM_DISPLAY_QG9696TSWHG04_WIDTH;
        psDisplayContext->ui32DisplayHeight = AM_DISPLAY_QG9696TSWHG04_HEIGHT;
        ui32Ret |= 0x02;
    }

    //
    // Return the hardware refresh period for this device (ms).
    // For this particular display, a periodic refresh is not required,
    //  so return the period as 0.
    //
    psDisplayContext->ui32HwRefreshMs = 0;

    //
    // Display background polarity.  The frame buffer handler will use this
    //  attribute to determine the polarity used in the frame buffer.
    //  Set to 1 if the background clears with 1s (0xffs).
    //  Set to 0 if the background clears with 0s (0x00s).
    //
    // The qg9696tswhg04 is cleared with 0x00s, so set to 0.
    //
    psDisplayContext->ui32DisplayBkgndPolarity = QG9696TSWHG04_FB_CLEAR_VALUE & 1;

    //
    // Now send the device initialization commands.
    // Unlock the display to accept commands.
    //
    send_cmd(QG9696TSWHG04_CMD2B_SET_CMD_LOCK, 0x12, 0, 2, psDisplayContext);

    //
    // Set the display off.
    //
    send_cmd(QG9696TSWHG04_CMD1B_DISPLAY_OFF, 0, 0, 1, psDisplayContext);

    //
    // Set re-map.
    //
    send_cmd(QG9696TSWHG04_CMD2B_SET_REMAP, 0x53, 0, 2, psDisplayContext);

    //
    // Set display start line.
    //
    send_cmd(QG9696TSWHG04_CMD2B_SET_START_LINE, 0x00, 0, 2, psDisplayContext);

    //
    // Set display offset.
    //
    send_cmd(QG9696TSWHG04_CMD2B_SET_OFFSET, 0x20, 0, 2, psDisplayContext);

    //
    // Set Normal display.
    //
    send_cmd(QG9696TSWHG04_CMD1B_SETMODE_INVERT, 0, 0, 1, psDisplayContext);

    //
    // Set Multiplex (Mux) ratio.
    //
    send_cmd(QG9696TSWHG04_CMD2B_SET_MULTIPLEX,
             AM_DISPLAY_QG9696TSWHG04_HEIGHT, 0, 2, psDisplayContext);

    //
    // Function select A.
    // Enable internal VDD regulator.
    //
    send_cmd(QG9696TSWHG04_CMD2B_SELECT_FUNC, 0x01, 0, 2, psDisplayContext);

    //
    // Set Contrast.
    //
    send_cmd(QG9696TSWHG04_CMD2B_SET_CONTRAST_CURRENT, 0x49, 0, 2, psDisplayContext);

    //
    // Set Phase Length.
    //
    send_cmd(QG9696TSWHG04_CMD2B_SET_PHASE_LEN, 0x32, 0, 2, psDisplayContext);

    //
    // Set front clock divider/oscillator frequency.
    //
    send_cmd(QG9696TSWHG04_CMD2B_SET_CLK_DIVIDER, 0x51, 0, 2, psDisplayContext);

    //
    // For Brightness enhancement.
    //
    send_cmd(0xB4, 0xB5, 0, 2, psDisplayContext);

    //
    // Set second pre-charge period.
    //
    send_cmd(QG9696TSWHG04_CMD2B_SET_2ND_PRECHARGE, 0x0D, 0, 2, psDisplayContext);

    //
    // Set pre-charge voltage.
    //
    send_cmd(QG9696TSWHG04_CMD2B_SET_PRECHARGE_VOLT, 0x07, 0, 2, psDisplayContext);

    //
    // Set vcomh.
    //
    send_cmd(QG9696TSWHG04_CMD2B_SET_VCOMH_VOLT, 0x07, 0, 2, psDisplayContext);

    //
    // Function selection B.
    //
    send_cmd(QG9696TSWHG04_CMD2B_SELECT_FUNC_B, 0x02, 0, 2, psDisplayContext);

    //
    // Display ON.
    //
    send_cmd(QG9696TSWHG04_CMD1B_DISPLAY_ON, 0, 0, 1, psDisplayContext);

    //
    // Initialize to horizontal mode, which also sets the row and col addresses.
    //
    set_horz_mode(psDisplayContext);

    if ( g_ui32AddressMode == ADDR_MODE_NONE )
    {
        return ui32Ret;
    }

    return ui32Ret;
} // am_devices_display_qg9696tswhg04_init()

//*****************************************************************************
//
//! @brief Clear the display.
//!
//! @param  psDisplayContext    Pointer to the displey device context structure.
//!
//! Clears the LCD panel and sets the framebuffer to 0xFF.
//!
//! @return None.
//
//*****************************************************************************
void
am_devices_display_qg9696tswhg04_screen_clear(
                            am_devices_display_qg9696tswhg04_t *psDisplayContext)
{
    int32_t i32x;

    //
    // Begin by clearing the framebuffer
    //
    for (i32x = 0; i32x < (AM_DISPLAY_QG9696TSWHG04_WIDTH / 8) * AM_DISPLAY_QG9696TSWHG04_HEIGHT; i32x++)
    {
        psDisplayContext->pui8Framebuffer[i32x] = QG9696TSWHG04_FB_CLEAR_VALUE;
    }

    //
    // Set to horizontal mode, which also resets the coordinates to 0,0.
    //
    set_horz_mode(psDisplayContext);

    //
    // Now, send the framebuffer to the display.
    // Since this display is 4bpp, but our framebuffer is 1bpp, we need to
    // send the cleared framebuffer 4 times.
    //
    for (i32x = 0; i32x < 4; i32x++)
    {
        send_data(psDisplayContext->pui8Framebuffer,
            AM_DISPLAY_QG9696TSWHG04_WIDTH / 8 * AM_DISPLAY_QG9696TSWHG04_HEIGHT,
            psDisplayContext);
    }

} // am_devices_display_qg9696tswhg04_screen_clear()

//*****************************************************************************
//
//! @brief Perform a hardware refresh of the display.
//!
//! @param  psDisplayContext    Pointer to the displey device context structure.
//!         bFullScreenDataRefresh  Refresh all pixels in the display.
//!
//! Many memory LCD panels require a periodic refresh cycle.  This refresh is
//! not to necessarily refresh the pixels, but to provide a command to the
//! display to avoid a DC bias buildup within the LCD panel.
//!
//! Also, the entire screen needs to be refreshed about every 2 hours in order
//! to guarantee proper pixel retaining.  To do so, the application simply
//! need set the bFullScreenFresh parameter to true.
//!
//! This function is called in order to send a periodic refresh command to the
//! display.  The function am_devices_display_refresh_ms() will tell the caller
//! how often this function should be called.
//!
//! @return true if successful, false otherwise.
//
//*****************************************************************************
bool
am_devices_display_qg9696tswhg04_hw_refresh(
                            am_devices_display_qg9696tswhg04_t *psDisplayContext,
                            bool bFullScreenDataRefresh)
{
    if ( bFullScreenDataRefresh )
    {
        //
        // We'll do a complete refresh of the display this time.
        //
        am_devices_display_qg9696tswhg04_lines_copy(psDisplayContext, 0,
                            AM_DISPLAY_QG9696TSWHG04_HEIGHT - 1);
    }

    return true;
} // am_devices_display_qg9696tswhg04_hw_refresh()

//*****************************************************************************
//
//! @brief Copy lines from the framebuffer to the display.
//!
//! @param  psDisplayContext    Pointer to the displey device context structure.
//!         u32BegLineNum       First line number (0-based) to be updated.
//!         u32EndLineNum       Last line number (0-based) to be updated.
//!
//! Copy the given lines from the given framebuffer to the display.
//!
//! @return None.
//
//*****************************************************************************
void
am_devices_display_qg9696tswhg04_lines_copy(
                            am_devices_display_qg9696tswhg04_t *psDisplayContext,
                            uint32_t ui32BegLineNum, uint32_t ui32EndLineNum)
{
    uint8_t *pui8FrBuf, *pu8Line4bit;
    int32_t i32row, i32col;
#if ROTATE_90
    uint8_t *pui8FB;
    uint8_t ui8Mask, ui8FBbyte0, ui8FBbyte1, ui8Pix;
#endif // ROTATE_90

    if ( (ui32BegLineNum > ui32EndLineNum)  ||
         (ui32EndLineNum > (AM_DISPLAY_QG9696TSWHG04_WIDTH-1)) )
    {
        return;
    }

    //
    // Set the row that we'll be writing the data to.
    //
    set_row(psDisplayContext, ui32BegLineNum, ui32EndLineNum);

#if ROTATE_90
    //
    // Rotate the image 90 (counter-clockwise). It should be noted that the
    //  following method only works if width=height and if each dimension is
    //  a multiple of 8.
    // To accomplish the rotatation, we'll read the pixels from the binary
    //  bitmap starting at the rightmost edge (column 95), translate the binary
    //  bit to a 4bpp pixel, and send them to the incrementally to the display
    //  device (which is in horizontal mode).  After getting all of the pixels
    //  from the rightmost edge of the binary bitmap, we'll move in 1 pixel
    //  (column 94) and read those, continuing until the entire bitmap has been
    //  read, translated, and sent to the display.
    //

    //
    // Get a byte pointer to the line buffer.
    //
    pu8Line4bit = (uint8_t*)g_FB4bitLine;

    //
    // Get ptr to the beginning of the framebuffer.
    //
    pui8FrBuf = psDisplayContext->pui8Framebuffer;

    //
    // Begin the binary bitmap to 4bpp translation loop.
    // This loop rotates the image by 90 from its normal orientation.
    //
    for ( i32row = ui32BegLineNum; i32row <= ui32EndLineNum; i32row++ )
    {
        //
        // Get a ptr to the byte in the first row of the binary bitmap
        // containing the pixel that we're interested in.
        //
        pui8FB = pui8FrBuf + ((AM_DISPLAY_QG9696TSWHG04_WIDTH / 8) - 1) -
                 (i32row / 8);

        //
        // Compute the bitmask needed for the pixels in this row.
        // The LSB of the binary bitmap is bit7 in MCU memory.
        //
        ui8Mask = g_ui8MaskTbl[i32row & 0x7];

        for ( i32col = 0; i32col < AM_DISPLAY_QG9696TSWHG04_WIDTH / 2; i32col++ )
        {
            //
            // Translate 2 pixels at a time.
            // Get the byte containing the pixel from the current row, and then
            // the byte with the 2nd pixel from the next row.
            //
            ui8FBbyte0 = *pui8FB;
            ui8FBbyte1 = *(pui8FB + (AM_DISPLAY_QG9696TSWHG04_WIDTH / 8));

            //
            // Translate the two binary-bitmask pixels to 4bpp pixels.
            //
            ui8Pix  = (ui8FBbyte0 & ui8Mask) ? 0x0F : 0x00;
            ui8Pix |= (ui8FBbyte1 & ui8Mask) ? 0xF0 : 0x00;

            //
            // Copy these two 4bpp pixels to the line buffer.
            //
            pu8Line4bit[i32col] = ui8Pix;

            //
            // Increment the framebuffer ptr to the next rows to be translated.
            //
            pui8FB += (AM_DISPLAY_QG9696TSWHG04_WIDTH / 8) * 2;
        }

        //
        // Now that we have a line of 4bpp data, write it to the display.
        //
        send_data((uint8_t*)g_FB4bitLine,
                  AM_DISPLAY_QG9696TSWHG04_WIDTH / 8 * 4, psDisplayContext);
    }
#else // Normal orientation (no rotation)
    //
    // Begin the binary bitmap to 4bpp translation loop.
    // This loop displays the image in its normal orientation.
    //
    pui8FrBuf = &psDisplayContext->pui8Framebuffer[ui32BegLineNum *
                (AM_DISPLAY_QG9696TSWHG04_WIDTH / 8)];

    for ( i32row = ui32BegLineNum; i32row <= ui32EndLineNum; i32row++ )
    {
        //
        // Translate one line worth of monochrome data to 4bpp data.
        // Translate 4 pixels at a time via the lookup table.
        //
        pu8Line4bit = (uint8_t*)g_FB4bitLine;
        for ( i32col = 0; i32col < AM_DISPLAY_QG9696TSWHG04_WIDTH; i32col += 8)
        {
            uint8_t u8FBbyte = *pui8FrBuf++;
            uint32_t u32FB4bit;
            u32FB4bit  = g_XlateNibble[u8FBbyte & 0xF];
            *pu8Line4bit++ = (u32FB4bit >> 8) & 0xFF;
            *pu8Line4bit++ = (u32FB4bit >> 0) & 0xFF;
            u8FBbyte >>= 4;
            u32FB4bit  = g_XlateNibble[u8FBbyte & 0xF];
            *pu8Line4bit++ = (u32FB4bit >> 8) & 0xFF;
            *pu8Line4bit++ = (u32FB4bit >> 0) & 0xFF;
        }

        //
        // Now that we have a line of 4bpp data, write it to the display.
        //
        send_data((uint8_t*)g_FB4bitLine,
                  AM_DISPLAY_QG9696TSWHG04_WIDTH / 8 * 4, psDisplayContext);
    }
#endif // ROTATE_90

    //
    // Set rows to default to the entire screen.
    //
    set_row(psDisplayContext, 0, AM_DISPLAY_QG9696TSWHG04_WIDTH - 1);

} // am_devices_display_qg9696tswhg04_lines_copy()


//*****************************************************************************
//
//! @brief Configure the callbacks for the IOM to enable nonblocking functionality.
//!
//! @param pfnYield - pointer to function used while waiting for the IOM to complete.
//! @param pfnCallback - pointer to function used when transaction are complete.
//!
//! This function configures the function pointers used during IOM transactions
//! to allow for nonblocking transfers. If not configured the transfers will be
//! blocking.
//!
//! @return None.
//
//*****************************************************************************
void
am_devices_display_qg9696tswhg04_callbacks_config(am_hal_iom_callback_t pfnYield,
                                                  am_hal_iom_callback_t pfnCallback)
{
    display_qg9696tswhg04_yield = pfnYield;
    display_qg9696tswhg04_callback = pfnCallback;
}

// #### INTERNAL END ####

