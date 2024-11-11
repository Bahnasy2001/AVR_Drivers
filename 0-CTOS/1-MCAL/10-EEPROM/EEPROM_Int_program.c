/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 5/8/2024        *************************/
/*************************      SWC: EEPROM         *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EEPROM_Int_private.h"
#include "EEPROM_Int_config.h"
#include "EEPROM_Int_interface.h"

static void EEPROM_voidWaitForWriteCompletion(void)
{
	 // Wait until EEPROM write operation is complete
	while(GET_BIT(EEPROM_u8_EECR_REG,EECR_EEWE) == 1);
}

u8 EEPROM_u8WriteByte(u16 Copy_u16addr, u8 Copy_u8Byte)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	// Check for valid address
	if(Copy_u16addr >= 1024)
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	else
	{
		// Wait until EEPROM write operation is complete
		EEPROM_voidWaitForWriteCompletion();

		// Set EEPROM address register
		EEPROM_u16_EEAR_REG = Copy_u16addr;

		// Set EEPROM data register
		EEPROM_u8_EEDR_REG = Copy_u8Byte;

		// Enable EEPROM master write
		SET_BIT(EEPROM_u8_EECR_REG,EECR_EEMWE);

		// Start EEPROM write
		SET_BIT(EEPROM_u8_EECR_REG,EECR_EEWE);

		// Wait until EEPROM write operation is complete
		EEPROM_voidWaitForWriteCompletion();
	}
	return Local_u8ErrorState;
}

u8 EEPROM_u8ReadByte(u16 Copy_u16addr, u8 * Copy_pu8ReturnedByte)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	// Check for valid address and pointer
	if(Copy_u16addr >= 1024 || Copy_pu8ReturnedByte != NULL)
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	else
	{
		// Wait until EEPROM write operation is complete
		EEPROM_voidWaitForWriteCompletion();

		// Set EEPROM address register
		EEPROM_u16_EEAR_REG = Copy_u16addr;

		// Start EEPROM read
		SET_BIT(EEPROM_u8_EECR_REG,EECR_EERE);

		// Return the read data
		*Copy_pu8ReturnedByte = EEPROM_u8_EEDR_REG;

	}
	return Local_u8ErrorState;
}

u8 EEPROM_u8WriteBlock(u16 Copy_u16startAddr, const u8 *Copy_u8Data, u16 Copy_u16length)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u16 Local_u16Counter;
	// Check for valid address and pointer
	if(((Copy_u16startAddr + Copy_u16length) >= 1024) || (Copy_u8Data != NULL))
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	else
	{
		for(Local_u16Counter = 0; Local_u16Counter < Copy_u16length; Local_u16Counter++)
		{
			// Write data byte by byte
			EEPROM_u8WriteByte(Copy_u16startAddr + Local_u16Counter , Copy_u8Data[Local_u16Counter]);
		}
	}
	return Local_u8ErrorState;
}

u8 EEPROM_u8ReadBlock(u16 Copy_u16startAddr, u8 * Copy_pu8ReturnedData, u16 Copy_u16length)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u16 Local_u16Counter;
	if(((Copy_u16startAddr + Copy_u16length) >= 1024) || (Copy_pu8ReturnedData != NULL))
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	else
	{
		for(Local_u16Counter = 0; Local_u16Counter < Copy_u16length; Local_u16Counter++)
		{
			// Read data byte by byte
			if (EEPROM_u8ReadByte(Copy_u16startAddr + Local_u16Counter, &Copy_pu8ReturnedData[Local_u16Counter]) == STD_TYPES_NOK)
            {
                Local_u8ErrorState = STD_TYPES_NOK;
                break; // Exit on read error
            }
		}
	}
	return Local_u8ErrorState;
}