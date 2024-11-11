/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 5/8/2024        *************************/
/*************************      SWC: EEPROM         *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef EEPROM_INT_PRIVATE_H
#define EEPROM_INT_PRIVATE_H

/* Registers & Bits Define */
/****************************************************************************/
#define EEPROM_u16_EEAR_REG                     *((volatile u16 *)0x3E)    //EEPROM Address Register
#define EEPROM_u8_EEDR_REG                      *((volatile u8 *)0x3D)    //EEPROM Data Register
/****************************************************************************/
/*********************************EECR REG*******************************************/
#define EEPROM_u8_EECR_REG                      *((volatile u8 *)0x3C)    //EEPROM Control Register
#define EECR_EERIE                                        3               //EEPROM Ready Interrupt Enable
#define EECR_EEMWE                                        2               //EEPROM Master Write Enable
#define EECR_EEWE                                         1               //EEPROM Write Enable
#define EECR_EERE                                         0               //EEPROM Read Enable

static void EEPROM_voidWaitForWriteCompletion(void);

#endif