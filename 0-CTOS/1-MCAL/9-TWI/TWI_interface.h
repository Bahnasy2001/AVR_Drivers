/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 3/7/2024        *************************/
/*************************      SWC: TWI            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

typedef enum 
{
	TWI_OK = 1,
	TWI_SC_Error,
	TWI_SLA_Error,
	TWI_RSC_Error,
	TWI_SLA_W_Error,
	TWI_SLA_R_Error,
	TWI_MT_DATA_Error,
	TWI_NULL_Pointer,
	TWI_MR_DATA_Error
}TWI_ErrorState;

void TWI_voidMasterInit(void);

TWI_ErrorState TWI_u8SlaveInit(u8 Copy_u8Address);

TWI_ErrorState TWI_u8SendStartCondition(void);

TWI_ErrorState TWI_u8SendReStartCondition(void);

TWI_ErrorState TWI_u8SendStopCondition(void);

TWI_ErrorState TWI_u8SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

TWI_ErrorState TWI_u8SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_ErrorState TWI_u8SendDataByte(u8 Copy_u8DataByte);

TWI_ErrorState TWI_u8ReadDataByte(u8 * Copy_puReturnedDataByte);

#endif