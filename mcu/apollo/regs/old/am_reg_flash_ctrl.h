//*****************************************************************************
//
//! @file am_reg_flashctrl.h
//!
//! @brief Register macros for the FLASHCTRL module
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_REG_FLASHCTRL_H
#define AM_REG_FLASHCTRL_H

//******************************************************************************
//
// Instance finder. (2 instance(s) available)
//
//******************************************************************************
#define AM_REG_FLASHCTRLn(n) \
    (REG_FLASHCTRL_BASEADDR + 0x00001000 * n)

//******************************************************************************
//
// Register offsets.
//
//******************************************************************************
#define AM_REG_FLASHCTRL_STATUS_O                    0x00000000
#define AM_REG_FLASHCTRL_WRDATA_O                    0x00000008
#define AM_REG_FLASHCTRL_WRADDR_O                    0x00000004
#define AM_REG_FLASHCTRL_DATACMD_O                   0x0000000C
#define AM_REG_FLASHCTRL_INFOCMD_O                   0x00000010
#define AM_REG_FLASHCTRL_ACCESS_O                    0x00000014
#define AM_REG_FLASHCTRL_EVENTREGEN_O                0x00000200
#define AM_REG_FLASHCTRL_EVENTREGSTAT_O              0x00000204
#define AM_REG_FLASHCTRL_EVENTREGCLR_O               0x00000208
#define AM_REG_FLASHCTRL_EVENTREGSET_O               0x0000020C

//******************************************************************************
//
// Key values.
//
//******************************************************************************
#define AM_REG_FLASHCTRL_ACCESS_KEYVAL               0x00000037

//******************************************************************************
//
// Interrupt Register: FLASHCTRL_EVENTREG
//
//******************************************************************************
// This bit is the operation timeout Event notification.
#define AM_REG_FLASHCTRL_EVENTREG_TIMEOUT_M          0x00000004

// This bit is the erase operation complete notification.
#define AM_REG_FLASHCTRL_EVENTREG_ERASECOMP_M        0x00000002

// This bit is the write operation complete notification.
#define AM_REG_FLASHCTRL_EVENTREG_WRITECOMP_M        0x00000001

//******************************************************************************
//
// FLASHCTRL_STATUS - Flash Controller Status Register
//
//******************************************************************************
// When set to 1, this bit indicates that write operations to the Flash INFO_CMD
// register are enabled. When set to 0, write and program operations are
// disabled to the Flash Information space.
#define AM_REG_FLASHCTRL_STATUS_INFOCMDEN_S          3
#define AM_REG_FLASHCTRL_STATUS_INFOCMDEN_M          0x00000008
#define AM_REG_FLASHCTRL_STATUS_INFOCMDEN(n)         (((n) << 3) & 0x00000008)

// When set to 1, this bit indicates that the Flash Controller is ready to
// accept a new write data via the WR_DATA register. When set to a 0, the Flash
// Controller is not ready for a new write data.
#define AM_REG_FLASHCTRL_STATUS_WRITERDY_S           2
#define AM_REG_FLASHCTRL_STATUS_WRITERDY_M           0x00000004
#define AM_REG_FLASHCTRL_STATUS_WRITERDY(n)          (((n) << 2) & 0x00000004)

// When set to 1, this bit indicates that an address has been written to the
// WRADDR register which is outside the range of valid addresses for the Flash
// Memory. This bit will be cleared on a write to the WRADDR register with a
// value that falls in the range of valid addresses.
#define AM_REG_FLASHCTRL_STATUS_ADDRERROR_S          1
#define AM_REG_FLASHCTRL_STATUS_ADDRERROR_M          0x00000002
#define AM_REG_FLASHCTRL_STATUS_ADDRERROR(n)         (((n) << 1) & 0x00000002)

// This bit reflects the status of the most recently requested Flash operation.
// When set to 1, the Flash Controller is still processing the last operation.
// When set to 0, the controller is idle and ready to accept a new command
// request.
#define AM_REG_FLASHCTRL_STATUS_BUSY_S               0
#define AM_REG_FLASHCTRL_STATUS_BUSY_M               0x00000001
#define AM_REG_FLASHCTRL_STATUS_BUSY(n)              (((n) << 0) & 0x00000001)

//******************************************************************************
//
// FLASHCTRL_WRDATA - Flash Controller Write Address Register
//
//******************************************************************************
// The value written to this field contains the next data to use for a Program
// operation to the Flash IP. A write to this register will initiate the Program
// Word operation, and once complete, will auto-increment the WRADDR to allow
// continuous writes without the need to writing the next Address (for Data
// Segment writes ONLY! This auto-increment functionality is not supported for
// writes to the Information space of the Flash).
#define AM_REG_FLASHCTRL_WRDATA_DATA_S               0
#define AM_REG_FLASHCTRL_WRDATA_DATA_M               0xFFFFFFFF
#define AM_REG_FLASHCTRL_WRDATA_DATA(n)              (((n) << 0) & 0xFFFFFFFF)

//******************************************************************************
//
// FLASHCTRL_WRADDR - Flash Controller Write Address Register
//
//******************************************************************************
// The value written to this field contains the next address to use for either
// an Erase or a Program operation to the Flash IP. If an invalid address is
// written, the Address Error bit of the Status register will be set.
#define AM_REG_FLASHCTRL_WRADDR_ADDR_S               0
#define AM_REG_FLASHCTRL_WRADDR_ADDR_M               0x0003FFFF
#define AM_REG_FLASHCTRL_WRADDR_ADDR(n)              (((n) << 0) & 0x0003FFFF)

//******************************************************************************
//
// FLASHCTRL_DATACMD - Flash Controller Data Space Command Register
//
//******************************************************************************
// Writing a 1 to this bitfield initiates a programming operation to the Flash
// Data space. Writing a 0 to this bitfield terminates the programming
// operation.
#define AM_REG_FLASHCTRL_DATACMD_DATAPROGRAM_S       2
#define AM_REG_FLASHCTRL_DATACMD_DATAPROGRAM_M       0x00000004
#define AM_REG_FLASHCTRL_DATACMD_DATAPROGRAM(n)      (((n) << 2) & 0x00000004)

// Writing a 1 to this bitfield initiates an erase operation of the entire Flash
// Data space.
#define AM_REG_FLASHCTRL_DATACMD_DATAMASSERASE_S     1
#define AM_REG_FLASHCTRL_DATACMD_DATAMASSERASE_M     0x00000002
#define AM_REG_FLASHCTRL_DATACMD_DATAMASSERASE(n)    (((n) << 1) & 0x00000002)

// Writing a 1 to this bitfield initiates a erase operation to the Flash Data
// word line specified by the WRADDR register.
#define AM_REG_FLASHCTRL_DATACMD_DATAPAGEERASE_S     0
#define AM_REG_FLASHCTRL_DATACMD_DATAPAGEERASE_M     0x00000001
#define AM_REG_FLASHCTRL_DATACMD_DATAPAGEERASE(n)    (((n) << 0) & 0x00000001)

//******************************************************************************
//
// FLASHCTRL_INFOCMD - Flash Controller Information Space Command Register
//
//******************************************************************************
// Writing a 1 to this bitfield initiates a programming operation to the Flash
// Information space. Writing a 0 to this bitfield terminates the programming
// operation.
#define AM_REG_FLASHCTRL_INFOCMD_INFOPROGRAM_S       2
#define AM_REG_FLASHCTRL_INFOCMD_INFOPROGRAM_M       0x00000004
#define AM_REG_FLASHCTRL_INFOCMD_INFOPROGRAM(n)      (((n) << 2) & 0x00000004)

// Writing a 1 to this bitfield initiates an erase operation of both the Flash
// Information and Flash Data spaces.
#define AM_REG_FLASHCTRL_INFOCMD_INFOMASSERASE_S     1
#define AM_REG_FLASHCTRL_INFOCMD_INFOMASSERASE_M     0x00000002
#define AM_REG_FLASHCTRL_INFOCMD_INFOMASSERASE(n)    (((n) << 1) & 0x00000002)

// Writing a 1 to this bitfield initiates a erase operation to the Flash
// Information spac. The WRADDR register is not relevant for an Information
// Space page erase operation.
#define AM_REG_FLASHCTRL_INFOCMD_INFOPAGEERASE_S     0
#define AM_REG_FLASHCTRL_INFOCMD_INFOPAGEERASE_M     0x00000001
#define AM_REG_FLASHCTRL_INFOCMD_INFOPAGEERASE(n)    (((n) << 0) & 0x00000001)


#endif // AM_REG_FLASHCTRL_H
