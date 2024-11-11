/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 5/8/2024        *************************/
/*************************      SWC: EEPROM         *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef EEPROM_INT_INTERFACE_H
#define EEPROM_INT_INTERFACE_H


u8 EEPROM_u8WriteByte(u16 Copy_u16addr, u8 Copy_u8Byte);

u8 EEPROM_u8ReadByte(u16 Copy_u16addr, u8 * Copy_pu8ReturnedByte);

u8 EEPROM_u8WriteBlock(u16 Copy_u16startAddr, const u8 *Copy_u8Data, u16 Copy_u16length);

u8 EEPROM_u8ReadBlock(u16 Copy_u16startAddr, u8 * Copy_pu8ReturnedData, u16 Copy_u16length);

#endif