/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 15/7/2024       *************************/
/*************************      SWC: EEPROM         *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU    8000000UL
#include <util/delay.h>

#include "TWI_interface.h"

#include "EEPROM_interface.h"
#include "EEPROM_config.h"
#include "EEPROM_private.h"

u8 EEPROM_u8WriteDataByte(u16 Copy_u16ByteAddress,u8 Copy_u8Data)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	TWI_ErrorState Local_enuTWIErrorState = TWI_OK;
	/* Send Start Condition */
	Local_enuTWIErrorState = TWI_u8SendStartCondition();
	Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);
	/* Send Slave Address with Write Operation */
	Local_enuTWIErrorState =  TWI_u8SendSlaveAddressWithWrite((EEPROM_u8FIXED_ADDRESS | (EEPROM_u8_A2_ADDRESS << 2) | (Copy_u16ByteAddress >> 8)));
	Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);
	/* Send  Byte Address */
	Local_u8ErrorState =  TWI_u8SendDataByte((u8)Copy_u16ByteAddress);
	Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);

	/* Send  Data */
	Local_u8ErrorState =  TWI_u8SendDataByte(Copy_u8Data);
	Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);

	/* Send Stop Condition */
	TWI_u8SendStopCondition();
	/* Delay */
	_delay_ms(5);
	return Local_u8ErrorState;
}

u8 EEPROM_u8ReadDataByte(u16 Copy_u16ByteAddress,u8 * Copy_pu8ReturnedData)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	TWI_ErrorState Local_enuTWIErrorState = TWI_OK;
	/* Check the Pointer */
	if(Copy_pu8ReturnedData != NULL)
	{
		/* Send Start Condition */
		Local_enuTWIErrorState = TWI_u8SendStartCondition();
		Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);

		/* Send Slave Address with Write Operation */
		Local_enuTWIErrorState =  TWI_u8SendSlaveAddressWithWrite((EEPROM_u8FIXED_ADDRESS | (EEPROM_u8_A2_ADDRESS << 2) | (Copy_u16ByteAddress >> 8)));
		Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);

		/* Send  Byte Address */
		Local_u8ErrorState =  TWI_u8SendDataByte((u8)Copy_u16ByteAddress);
		Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);

		/* Send Repeated Start Condition */
		Local_enuTWIErrorState = TWI_u8SendReStartCondition();
		Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);

		/* Send Slave Address with Read Operation */
		Local_enuTWIErrorState =  TWI_u8SendSlaveAddressWithRead((EEPROM_u8FIXED_ADDRESS | (EEPROM_u8_A2_ADDRESS << 2) | (Copy_u16ByteAddress >> 8)));
		Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);

		/* Read Data */
		Local_enuTWIErrorState = TWI_u8ReadDataByte(Copy_pu8ReturnedData);
		Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);

		/* Send Stop Condition */
		TWI_u8SendStopCondition();
		/* Delay */
		_delay_ms(5);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

static u8 Private_u8CheckErrorState(TWI_ErrorState Copy_enuErrorState)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_enuErrorState !=  TWI_OK)
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}