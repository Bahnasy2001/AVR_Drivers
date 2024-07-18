/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 15/7/2024       *************************/
/*************************      SWC: EEPROM         *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

u8 EEPROM_u8WriteDataByte(u16 Copy_u16ByteAddress,u8 Copy_u8Data);

u8 EEPROM_u8ReadDataByte(u16 Copy_u16ByteAddress,u8 * Copy_pu8ReturnedData);

#endif