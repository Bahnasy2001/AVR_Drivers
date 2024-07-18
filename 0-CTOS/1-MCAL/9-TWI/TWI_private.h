/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 3/7/2024        *************************/
/*************************      SWC: TWI            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H

/* Registers & Bits Define */
/****************************************************************************/
#define TWI_u8_TWBR_REG                    *((volatile u8 *)0x20)
/****************************************************************************/

/***************************TWCR Reg******************************************/
#define TWI_u8_TWCR_REG                    *((volatile u8 *)0x56)
#define TWCR_TWINT                                    7 //TWI Interrupt Flag
#define TWCR_TWEA                                     6 //TWI Enable Acknowledge Bit
#define TWCR_TWSTA                                    5 //TWI START Condition Bit
#define TWCR_TWSTO                                    4 //TWI STOP Condition Bit
#define TWCR_TWWC                                     3 //TWI Write Collision Flag
#define TWCR_TWEN                                     2 //TWI Enable Bit
#define TWCR_TWIE                                     0 //TWI Interrupt Enable
/****************************************************************************/

/***************************TWSR Reg******************************************/
#define TWI_u8_TWSR_REG                    *((volatile u8 *)0x21)
#define TWSR_TWPS1                                    1 //TWI Prescaler Bit 1
#define TWSR_TWPS0                                    0 //TWI Prescaler Bit 0
/****************************************************************************/

/***************************TWAR Reg******************************************/
#define TWI_u8_TWAR_REG                    *((volatile u8 *)0x22)
#define TWAR_TWGCE                                    0 //TWI General Call Recognition Enable Bit
/****************************************************************************/
#define TWI_u8_TWDR_REG                    *((volatile u8 *)0x23)
#define TWI_u8_TWBR_REG                    *((volatile u8 *)0x20)

/***************************Master Transmitter Status Macros******************************************/
#define TWI_START                0x08  // Start condition transmitted
#define TWI_REP_START            0x10  // Repeated start condition transmitted
#define TWI_MT_SLA_ACK           0x18  // SLA+W transmitted, ACK received
#define TWI_MT_SLA_NACK          0x20  // SLA+W transmitted, NACK received
#define TWI_MT_DATA_ACK          0x28  // Data transmitted, ACK received
#define TWI_MT_DATA_NACK         0x30  // Data transmitted, NACK received
#define TWI_MT_ARB_LOST          0x38  // Arbitration lost in SLA+W or data
/****************************************************************************************************/

/***************************Master Receiver  Status Macros******************************************/
#define TWI_MR_SLA_ACK           0x40  // SLA+R transmitted, ACK received
#define TWI_MR_SLA_NACK          0x48  // SLA+R transmitted, NACK received
#define TWI_MR_DATA_ACK          0x50  // Data received, ACK returned
#define TWI_MR_DATA_NACK         0x58  // Data received, NACK returned
/**************************************************************************************************/

/***************************Slave Receiver Status Macros******************************************/
#define TWI_SR_SLA_ACK           0x60  // Own SLA+W received, ACK returned
#define TWI_SR_ARB_LOST_SLA_ACK  0x68  // Arbitration lost in SLA+W, own SLA+W received, ACK returned
#define TWI_SR_GCALL_ACK         0x70  // General call address received, ACK returned
#define TWI_SR_ARB_LOST_GCALL_ACK 0x78  // Arbitration lost in SLA+W, general call address received, ACK returned
#define TWI_SR_DATA_ACK          0x80  // Data received, ACK returned
#define TWI_SR_DATA_NACK         0x88  // Data received, NACK returned
#define TWI_SR_GCALL_DATA_ACK    0x90  // General call data received, ACK returned
#define TWI_SR_GCALL_DATA_NACK   0x98  // General call data received, NACK returned
#define TWI_SR_STOP              0xA0  // Stop or repeated start condition received while selected
/**************************************************************************************************/

/***************************Slave Transmitter Status Macros******************************************/
#define TWI_ST_SLA_ACK           0xA8  // Own SLA+R received, ACK returned
#define TWI_ST_ARB_LOST_SLA_ACK  0xB0  // Arbitration lost in SLA+R, own SLA+R received, ACK returned
#define TWI_ST_DATA_ACK          0xB8  // Data transmitted, ACK received
#define TWI_ST_DATA_NACK         0xC0  // Data transmitted, NACK received
#define TWI_ST_LAST_DATA         0xC8  // Last data byte transmitted, ACK received
/**************************************************************************************************/

/***************************Miscellaneous Status Macros******************************************/
#define TWI_NO_INFO              0xF8  // No relevant state information available, TWINT = 0
#define TWI_BUS_ERROR            0x00  // Bus error due to an illegal START or STOP condition
/**************************************************************************************************/

#endif