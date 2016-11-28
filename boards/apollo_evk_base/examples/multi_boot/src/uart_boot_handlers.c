//*****************************************************************************
//
//! @file uart_boot_handlers.c
//!
//! @brief Boot related functions for the UART interface.
//!
//! This file contains the main state machine for handling boot commands via
//! the I2C interface.
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
#include "am_bsp.h"
#include "am_util.h"
#include "am_bootloader.h"
#include "multi_boot.h"
#include "multi_boot_config.h"

//*****************************************************************************
//
// UART configuration settings.
//
//*****************************************************************************
am_hal_uart_config_t g_sUartConfig =
{
    .ui32BaudRate = 115200,
    .ui32DataBits = AM_HAL_UART_DATA_BITS_8,
    .bTwoStopBits = false,
    .ui32Parity   = AM_HAL_UART_PARITY_NONE,
    .ui32FlowCtrl = AM_HAL_UART_FLOW_CTRL_NONE,
};

//
//
#define MAX_BUFFER 128
volatile uint32_t ui32_serial_status;
volatile unsigned char cRecChar, RX_FIFO_FULL, RX_FIFO_EMPTY;
volatile unsigned char uart_RX_buffer[MAX_BUFFER];
volatile unsigned char uart_RX_cnt, uart_RX_head, uart_RX_tail;
// ************************************
unsigned char cTxChar, TX_FIFO_FULL, TX_FIFO_EMPTY;
unsigned char uart_TX_buffer[MAX_BUFFER];
unsigned char uart_TX_cnt, uart_TX_head, uart_TX_tail;
// ************************************

uint32_t command;
unsigned char packet_cnt, pkt_size;

void
setup_serial(int32_t i32Module, uint32_t ui32BaudRate)
{

    command = 0;
    uart_RX_head = uart_RX_tail = uart_RX_cnt = 0;
    RX_FIFO_FULL = 0;  // check serial FIFO operation
    RX_FIFO_EMPTY = 1;
    packet_cnt = 0xff;

    //
    // Make sure the UART RX and TX pins are enabled.
    //
#if defined (AM_PART_APOLLO2)
    am_hal_gpio_pin_config(1, AM_HAL_PIN_1_UART0TX);
    am_hal_gpio_pin_config(2, AM_HAL_PIN_2_UART0RX);
#elif defined (AM_PART_APOLLO)
    am_hal_gpio_pin_config(35, AM_HAL_PIN_35_UARTTX);
    am_hal_gpio_pin_config(36, AM_HAL_PIN_36_UARTRX);
#endif

    //
    // Power on the selected UART
    //
    am_hal_uart_pwrctrl_enable(i32Module);

    //
    // Start the UART interface, apply the desired configuration settings, and
    // enable the FIFOs.
    //
    am_hal_uart_clock_enable(i32Module);

    //
    // Disable the UART before configuring it.
    //
    am_hal_uart_disable(i32Module);

    //
    // Configure the UART.
    //
    g_sUartConfig.ui32BaudRate = ui32BaudRate;
    am_hal_uart_config(i32Module, &g_sUartConfig);

    //
    // Enable the UART FIFO.
    //
   am_hal_uart_fifo_config(i32Module, AM_HAL_UART_TX_FIFO_1_2 | AM_HAL_UART_RX_FIFO_1_2);

    //
    // Enable the UART.
    //
    am_hal_uart_enable(i32Module);

    am_hal_uart_int_clear(0, AM_HAL_UART_INT_RX | AM_HAL_UART_INT_RX_TMOUT);
    am_hal_uart_int_enable(0, AM_HAL_UART_INT_RX | AM_HAL_UART_INT_RX_TMOUT);

    am_hal_interrupt_enable(AM_HAL_INTERRUPT_UART);
}

//*****************************************************************************
//
//! @brief Read an image start packet from the IOS LRAM
//!
//! @param psImage is the image structure to read the packet into.
//!
//! This function reads the IOS LRAM as a "new image" packet, and uses that
//! packet to fill in a bootloader image structure. The caller is responsible
//! for verifying the packet type before calling this function.
//!
//! @return true if the image parameters are acceptable.
//
//*****************************************************************************
static bool
image_start_packet_read(am_bootloader_image_t *psImage)
{
    uint32_t *pui32Packet;

    pui32Packet = (uint32_t *) uart_RX_buffer;

    //
    // Set the image structure parameters based on the information in the
    // packet.
    //
    psImage->pui32LinkAddress = (uint32_t *)(pui32Packet[1]);
    psImage->ui32NumBytes = pui32Packet[2];
    psImage->ui32CRC = pui32Packet[3];
    psImage->ui32OverrideGPIO = DEFAULT_OVERRIDE_GPIO;
    psImage->ui32OverridePolarity = DEFAULT_OVERRIDE_POLARITY;
    psImage->pui32StackPointer = (uint32_t *)pui32Packet[4];
    psImage->pui32ResetVector = (uint32_t *)pui32Packet[5];

    //
    // Check to make sure we're not overwriting the bootloader.
    //
    if ((uint32_t) psImage->pui32LinkAddress < 0x4000)
    {
        return false;
    }

    //
    // Otherwise, the image is presumed to be reasonable. Set our global
    // variables based on the new image structure.
    //
    g_pui32WriteAddress = psImage->pui32LinkAddress;
    g_ui32BytesReceived = 0;
    return true;
}

//*****************************************************************************
//
//! @brief Read an image data packet from the IOS LRAM
//!
//! This function reads the IOS LRAM as a continuing data packet, and uses that
//! packet to write to the image area the flash. The caller is responsible for
//! verifying the packet type before calling this function.
//!
//! @return None.
//
//*****************************************************************************
static void
image_data_packet_read(void)
{
    uint32_t i;
    uint8_t *pui8Src;
    uint32_t ui32Size, ui32CurrentPage, ui32CurrentBlock;
    uint32_t ui32WordsInBuffer;

    ui32Size = *((uint32_t *)(uart_RX_buffer + 4));
    pui8Src = (uint8_t *)(uart_RX_buffer + 8);

    //
    // Run a quick CRC on the received bytes, holding on to the result in a
    // global variable, so we can pick up where we left off on the next pass.
    //
    am_bootloader_partial_crc32(pui8Src, ui32Size, &g_ui32CRC);

    //
    // Loop through the data, copying it into the global buffer.
    //
    for (i = 0; i < ui32Size; i++)
    {
        g_pui8RxBuffer[g_ui32BytesInBuffer] = *pui8Src++;

        //
        // Keep track of how much data we've copied into the SRAM buffer.
        //
        g_ui32BytesInBuffer++;
        g_ui32BytesReceived++;

        //
        // Whenever we hit a page boundary or the end of the image, we should
        // write to flash.
        //
        if (g_ui32BytesInBuffer == 2048 ||
            g_ui32BytesReceived == g_sImage.ui32NumBytes)
        {
            //
            // If this is the first block of our new image, we need to record
            // the reset vector and stack pointer information for inclusion in
            // the flag page.
            //
            if(g_ui32BytesReceived <= 2048)
            {
                g_sImage.pui32StackPointer = (uint32_t *)(g_pui32RxBuffer[0]);
                g_sImage.pui32ResetVector = (uint32_t *)(g_pui32RxBuffer[1]);
            }

            //
            // Erase the next page in flash.
            //
            ui32CurrentPage =  AM_HAL_FLASH_ADDR2PAGE((uint32_t)g_pui32WriteAddress);
            ui32CurrentBlock = AM_HAL_FLASH_ADDR2INST((uint32_t)g_pui32WriteAddress);

            //
            // Only erase pages with a write address on a PAGE boundry 0x2000
            //
            if (((uint32_t)g_pui32WriteAddress % AM_HAL_FLASH_PAGE_SIZE == 0))
            {
                am_hal_flash_page_erase(AM_HAL_FLASH_PROGRAM_KEY,
                                        ui32CurrentBlock, ui32CurrentPage);
            }

            ui32WordsInBuffer = g_ui32BytesInBuffer / 4;

            //
            // Program the flash page with the data we just received.
            //
            am_hal_flash_program_main(AM_HAL_FLASH_PROGRAM_KEY, g_pui32RxBuffer,
                                      g_pui32WriteAddress, ui32WordsInBuffer);

            //
            // Adjust the global variables.
            //
            g_pui32WriteAddress += (g_ui32BytesInBuffer / 4);
            g_ui32BytesInBuffer = 0;

            for (unsigned int a = 0; a < 2048; a++)
                g_pui8RxBuffer[a] = 0xaa;
        }
    }
}
//
void
ser_out(unsigned char data)
{
    AM_REGn(UART, 0, DR) = data;
    while (AM_BFRn(UART, 0, FR, TXFF));
}


//
//*****************************************************************************
//
void
hex_out(unsigned char hex_data)
{
    unsigned char temp;
    temp = hex_data >> 4;
    if (temp > 10)
        ser_out(temp + 0x37);
    else
        ser_out(temp + 0x30);

    temp = hex_data & 0x0f;
    if ((hex_data & 0x0f) > 10)
        ser_out(temp + 0x37);
    else
        ser_out(temp + 0x30);
}

void
hex_out_int(int ihex_data)
{
    hex_out(ihex_data >> 8);
    hex_out(ihex_data & 0x00ff);
}

//*****************************************************************************
//
// am_uart_isr
//
//*****************************************************************************
void
am_uart_isr(void)
{
    uint32_t *rx_pui32Packet;
    unsigned char send_byte_cnt, cnt, flush = 0;
    uint32_t *tx_pui32Packet;

    uint32_t ui32Status;

    //
    // Check to see what caused this interrupt, then clear the bit from the
    // interrupt register.
    //
    ui32Status = am_hal_uart_int_status_get(0, false);
    am_hal_uart_int_clear(0, ui32Status);
    // ui32_serial_status = ui32Status;
    //
    // Service the uart FIFO.
    //

    uart_RX_buffer[uart_RX_head++] = AM_REGn(UART, 0, DR);
    uart_RX_head = uart_RX_head & (MAX_BUFFER - 1);

    RX_FIFO_EMPTY = 0;
    uart_RX_cnt++;
    if (uart_RX_head == uart_RX_tail)
        RX_FIFO_FULL = 1;

    if (uart_RX_cnt == 4)    // cmd received, wait for parameters
    {
        command = uart_RX_buffer[0];        //*(uint32_t *) uart_RX_buffer[0];    //
        switch (command)
        {
            case AM_BOOTLOADER_NEW_IMAGE:
                packet_cnt = 16;
                break;
            case AM_BOOTLOADER_SET_OVERRIDE_CMD:
                packet_cnt = 12;
                break;
            case AM_BOOTLOADER_NEW_PACKET:
                //    packet_cnt = pkt_size+8;
                break;
            case AM_BOOTLOADER_RESET:
                packet_cnt = 4;
                break;
            case AM_BOOTLOADER_BL_VERSION_CMD:
                packet_cnt = 4;
                break;
            default:
                //packet_cnt = 8;
                break;
        }
    }

    if ((command == AM_BOOTLOADER_NEW_PACKET) && (uart_RX_cnt == 8))
    {
        pkt_size = uart_RX_buffer[4];        //*(uint32_t *) uart_RX_buffer[1];    //
        packet_cnt = pkt_size + 8;
    }

    if (uart_RX_cnt == packet_cnt)
    {
        rx_pui32Packet = (uint32_t *) uart_RX_buffer;
        tx_pui32Packet = (uint32_t *) uart_TX_buffer;

        switch (rx_pui32Packet[0])
        {
            case AM_BOOTLOADER_NEW_IMAGE:
                //
                // Parse the image packet, and store the result to the global
                // image structure.
                //
                g_bImageValid = image_start_packet_read(&g_sImage);

                //
                // Make sure the image packet had reasonable contents. If it
                // didn't, we need to let the host know.
                //
                if (g_bImageValid)
                {
                    //
                    // Good image; Send back a "READY" packet.
                    //
                    tx_pui32Packet[0] = AM_BOOTLOADER_READY;
                    //am_hal_gpio_out_bit_clear(INTERRUPT_PIN);
                }
                else
                {
                    //
                    // Bad image; Send back an error.
                    //
                    tx_pui32Packet[0] = AM_BOOTLOADER_ERROR;
                    //am_hal_gpio_out_bit_clear(INTERRUPT_PIN);
                }

                flush = 1;
                send_byte_cnt = 4;
                break;

            case AM_BOOTLOADER_SET_OVERRIDE_CMD:
                //
                // Set the override GPIO settings based on the packet
                // information.
                //
                g_sImage.ui32OverrideGPIO = rx_pui32Packet[1];
                g_sImage.ui32OverridePolarity = rx_pui32Packet[2];

                //
                // Send back a "READY" packet.
                //
                tx_pui32Packet[0] = AM_BOOTLOADER_READY;
                //am_hal_gpio_out_bit_clear(INTERRUPT_PIN);
                flush = 1;
                send_byte_cnt = 4;
                break;

            case AM_BOOTLOADER_NEW_PACKET:
                //
                // Only take new packets if our image structure is valid.
                //
                if (!g_bImageValid)
                {
                    tx_pui32Packet[0] = AM_BOOTLOADER_ERROR;
                    //am_hal_gpio_out_bit_clear(INTERRUPT_PIN);
                    break;
                }

                //
                // Parse the rest of the packet sitting in the IOS LRAM.
                //
                image_data_packet_read();

                //
                // If this packet completed the image...
                //
                if (g_ui32BytesReceived == g_sImage.ui32NumBytes)
                {
                    //
                    // Check this against the CRC we received from the host
                    // earlier. Report the status (either good or bad) back to
                    // the host.
                    //
                    tx_pui32Packet[0] = ((g_ui32CRC == g_sImage.ui32CRC) ?
                                         AM_BOOTLOADER_IMAGE_COMPLETE :
                                         AM_BOOTLOADER_BAD_CRC);

                    //
                    // Assert the interrupt line so the host knows we have a
                    // message.
                    //
                    am_hal_gpio_out_bit_clear(INTERRUPT_PIN);
                }
                else
                {
                    //
                    // If this wasn't the end of the image, just send back a
                    // "READY" packet.
                    //
                    tx_pui32Packet[0] = AM_BOOTLOADER_READY;
                    //am_hal_gpio_out_bit_clear(INTERRUPT_PIN);
                }

                flush = 1;
                send_byte_cnt = 4;

                break;

            case AM_BOOTLOADER_RESET:
                //
                // Write the flag page.
                //
                am_bootloader_flag_page_update(&g_sImage, (uint32_t *)g_psBootImage);

                //
                // Perform a software reset.
                //
                am_hal_reset_poi();

                //
                // Wait for the reset to take effect.
                //
                while (1);

            case AM_BOOTLOADER_BL_VERSION_CMD:
                //
                // Respond with the version number.
                //
                tx_pui32Packet[0] = AM_BOOTLOADER_BL_VERSION;
                tx_pui32Packet[1] = AM_BOOTLOADER_VERSION_NUM;

                flush = 1;
                send_byte_cnt = 8;
                break;

            case AM_BOOTLOADER_ACK_CMD:
            case AM_BOOTLOADER_NAK_CMD:
                break;

            default:
                break;
        }
    }


    if (flush)
    {
        uart_TX_tail = 0;

        for (cnt = 0; cnt < send_byte_cnt; cnt++)
        {
            ser_out(uart_TX_buffer[uart_TX_tail++]);
        }
        command = 0;
        uart_RX_head = uart_RX_tail = uart_RX_cnt = 0;
        RX_FIFO_FULL = 0;  // check serial FIFO operation
        RX_FIFO_EMPTY = 1;
        flush = 0;
        send_byte_cnt = 0;
        packet_cnt = 0xff;
    }

}
