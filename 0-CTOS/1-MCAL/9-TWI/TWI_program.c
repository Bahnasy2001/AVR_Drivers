/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 3/7/2024        *************************/
/*************************      SWC: TWI            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_interface.h"
#include "TWI_config.h"
#include "TWI_private.h"

void TWI_voidMasterInit(void)
{
	/* Set Prescaler Value */
	CLR_BIT(TWI_u8_TWSR_REG,TWSR_TWPS1);
	CLR_BIT(TWI_u8_TWSR_REG,TWSR_TWPS0);
	/* Set TWBR With The Value --> 200KHZ */
	TWI_u8_TWBR_REG = 12; //TWBR = ((CPU Clock/200KHZ)-16)/2
	/* Enable ACK */
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWEA);
	/* Enable I2C */
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWEN);
}

TWI_ErrorState TWI_u8SlaveInit(u8 Copy_u8Address)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	if(Copy_u8Address < 127)
	{
		/* Set Slave Address in TWAR */
		TWI_u8_TWAR_REG = Copy_u8Address << 1;
		/* Enable ACK */
		SET_BIT(TWI_u8_TWCR_REG,TWCR_TWEA);
		/* Enable I2C */
		SET_BIT(TWI_u8_TWCR_REG,TWCR_TWEN);
	}
	else
	{
		Local_enuErrorState = TWI_SLA_Error;
	}
	return Local_enuErrorState;
}

TWI_ErrorState TWI_u8SendStartCondition(void)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Clear Flag + Start Condition */
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWSTA);
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT);
	/* wait for the flag to be 1 */
	while(!GET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT)); //For Enhance add Time out
	/* Check The Status Code */
	if((TWI_u8_TWSR_REG & 0xF8) != TWI_START)
	{
		Local_enuErrorState = TWI_SC_Error;
	}
	/* Clear Start Condition bit */
	//CLR_BIT(TWI_u8_TWCR_REG,TWCR_TWSTA);
	return Local_enuErrorState;
}

TWI_ErrorState TWI_u8SendReStartCondition(void)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Clear Flag + Start Condition */
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWSTA);
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT);
	/* wait for the flag to be 1 */
	while(!GET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT)); //For Enhance add Time out
	/* Check The Status Code == Repeated Start Condition */
	if((TWI_u8_TWSR_REG & 0xF8) != TWI_REP_START)
	{
		Local_enuErrorState = TWI_RSC_Error;
	}
	/* Clear Start Condition bit */
	//CLR_BIT(TWI_u8_TWCR_REG,TWCR_TWSTA);
	return Local_enuErrorState;
}

TWI_ErrorState TWI_u8SendStopCondition(void)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Clear Flag + Stop Condition */
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWSTO);
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT);
	return Local_enuErrorState;
}

TWI_ErrorState TWI_u8SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Write Slave Address + 0 in TWDR */
	TWI_u8_TWDR_REG = Copy_u8SlaveAddress << 1;
	CLR_BIT(TWI_u8_TWDR_REG,0);

	/* Clear Start Condition bit */
	CLR_BIT(TWI_u8_TWCR_REG,TWCR_TWSTA);

	/* Clear Flag */
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT);
	/* wait for the flag to be 1 */
	while(!GET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT)); //For Enhance add Time out
	/* Check The Status Code == SLA + W */
	if((TWI_u8_TWSR_REG & 0xF8) != TWI_MT_SLA_ACK)
	{
		Local_enuErrorState = TWI_SLA_W_Error;
	}
	return Local_enuErrorState;
}

TWI_ErrorState TWI_u8SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Write Slave Address + 1 in TWDR */
	TWI_u8_TWDR_REG = Copy_u8SlaveAddress << 1;
	SET_BIT(TWI_u8_TWDR_REG,0);

	/* Clear Start Condition bit */
	CLR_BIT(TWI_u8_TWCR_REG,TWCR_TWSTA);
	
	/* Clear Flag */
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT);
	/* wait for the flag to be 1 */
	while(!GET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT)); //For Enhance add Time out
	/* Check The Status Code == SLA + R */
	if((TWI_u8_TWSR_REG & 0xF8) != TWI_MR_SLA_ACK)
	{
		Local_enuErrorState = TWI_SLA_R_Error;
	}
	return Local_enuErrorState;
}

TWI_ErrorState TWI_u8SendDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Write Data in TWDR */
	TWI_u8_TWDR_REG = Copy_u8DataByte;
	/* Clear Flag */
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT);
	/* wait for the flag to be 1 */
	while(!GET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT)); //For Enhance add Time out
	/* Check The Status Code == MASTERSendData */
	if((TWI_u8_TWSR_REG & 0xF8) != TWI_MT_DATA_ACK)
	{
		Local_enuErrorState = TWI_MT_DATA_Error;
	}
	return Local_enuErrorState;
}

TWI_ErrorState TWI_u8ReadDataByte(u8 * Copy_puReturnedDataByte)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Check Pointer */
	if(Copy_puReturnedDataByte != NULL)
	{
		/* Clear Flag */
		SET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT);
		/* wait for the flag to be 1 */
		while(!GET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT)); //For Enhance add Time out
		/* Check The Status Code == MASTERReceivedData */
		if((TWI_u8_TWSR_REG & 0xF8) != TWI_MR_DATA_ACK)
		{
			Local_enuErrorState = TWI_MR_DATA_Error;
		}
		else
		{
			/* Read Data in The Pointer */
			*Copy_puReturnedDataByte = TWI_u8_TWDR_REG;
		}
	}
	else
	{
		Local_enuErrorState = TWI_NULL_Pointer;
	}
	return Local_enuErrorState;
}