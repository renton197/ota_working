//*****************************************************************************
//
//! @file am_devices_i2cioshc.h
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
#ifndef AM_DEVICES_I2CIOSHC_H
#define AM_DEVICES_I2CIOSHC_H

#ifdef __cplusplus
extern "C"
{
#endif
//*****************************************************************************
//
// Macro definitions
//
//*****************************************************************************
#define AM_DEVICES_I2CIOSHC_LAST_RCV_BYTE   0x4F
#define AM_DEVICES_I2CIOSHC_FIFO_BASE       0x80
#define AM_DEVICES_I2CIOSHC_FIFO_END        0x100
#define AM_DEVICES_I2CIOSHC_PAYLOAD_SIZE    (62)

//*****************************************************************************
//
// External variable definitions
//
//*****************************************************************************

//*****************************************************************************
//
// Message Header
//
//*****************************************************************************
typedef struct am_devices_i2cioshc_message_s
{
    //
    // Length of the message including header bytes.
    //
    uint32_t Length;

    //
    // Channel Number on which this message flows.
    //
    uint8_t ChannelNumber;

    //
    // Sequence Number for this message.
    //
    uint8_t SequenceNumber;

    //
    // Pointer to the actual message.
    //
    uint8_t Message[AM_DEVICES_I2CIOSHC_PAYLOAD_SIZE];

} am_devices_i2cioshc_message_t;

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern void am_devices_i2cioshc_init(am_hal_ios_config_t *psIOSConfig);

extern void am_devices_i2cioshc_message_format(
                   am_devices_i2cioshc_message_t *psMessage, uint8_t *pBuffer);
extern void am_devices_i2cioshc_message_extract(
                   am_devices_i2cioshc_message_t *psMessage, uint8_t *pBuffer);

extern void am_devices_i2cioshc_fifo_service(uint32_t ui32Status);
extern void am_devices_i2cioshc_acc_service(uint8_t *pui8Destination,
                                            uint32_t ui32Status);
void am_devices_i2cioshc_release_inbound_hw_buffer(void);
extern void am_devices_i2cioshc_ios_int_service(void (*XmitMsgHandler)(void),
                                                uint32_t ui32Status);
extern void am_devices_i2cioshc_write(uint8_t *pui8Data, uint8_t ui8Size);
extern uint32_t am_devices_i2cioshc_read(uint8_t *pui8Data, uint32_t ui32MaxSize);
extern bool am_devices_i2cioshc_check(void);

#ifdef __cplusplus
}
#endif

#endif // AM_DEVICES_I2CIOSHC_H
