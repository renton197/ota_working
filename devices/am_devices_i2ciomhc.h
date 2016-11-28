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
#ifndef AM_DEVICES_I2CIOMHC_H
#define AM_DEVICES_I2CIOMHC_H

#ifdef __cplusplus
extern "C"
{
#endif
//*****************************************************************************
//
// Macro definitions
//
//*****************************************************************************
//#define AM_DEVICES_I2CIOSHC_LAST_RCV_BYTE   0x4F
//#define AM_DEVICES_I2CIOSHC_FIFO_BASE       0x78
//#define AM_DEVICES_I2CIOSHC_FIFO_END        0x100
#define AM_DEVICES_I2CIOMHC_PAYLOAD_SIZE    (62)

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
typedef struct
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
    // Pointer to the actual Message
    //
    uint8_t Message[AM_DEVICES_I2CIOMHC_PAYLOAD_SIZE];

} am_devices_i2ciomhc_message_t;

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern void am_devices_i2ciomhc_init(void);
extern uint8_t am_devices_i2ciomhc_read_int_status(void);
extern void am_devices_i2ciomhc_rcv_packet(am_devices_i2ciomhc_message_t *Msg);
extern void am_devices_i2ciomhc_xmit_packet(am_devices_i2ciomhc_message_t *Msg);


#ifdef __cplusplus
}
#endif

#endif // AM_DEVICES_I2CIOMHC_H

