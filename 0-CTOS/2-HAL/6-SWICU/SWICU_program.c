/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 16/6/2024       *************************/
/*************************      SWC: SWICU          *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "TIMERS_interface.h"
#include "EXTI_interface.h"

/* HAL */
#include "SWICU_interface.h"
#include "SWICU_private.h"
#include "SWICU_config.h"

/* Global Definitions */
static u16 SWICU_u16OnPeriod,SWICU_u16OffPeriod;

void SWICU_voidEnable(void)
{
	/* Set EXTI CallBack */
	EXTI_u8EXTISetCallBack(EXTI_u8_EXTI0,&SWICU_voidEXTICallBack);
	/* Enable EXTI => Raising Edge */
	EXTI_u8EXTIEnable(EXTI_u8_EXTI0,EXTI_u8_RAISING_EDGE);
}

void SWICU_voidDisable(void)
{
	EXTI_u8EXTIDisable(EXTI_u8_EXTI0);
}

u8   SWICU_u8GetTotalPeriod(u32 * Copy_pu32TotalPeriod)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_pu32TotalPeriod != NULL)
	{
		*Copy_pu32TotalPeriod = SWICU_u16OnPeriod + SWICU_u16OffPeriod;
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}

u8   SWICU_u8GetDutyCycle(u8 * Copy_pu8DutyCycle)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_pu8DutyCycle != NULL)
	{
		*Copy_pu8DutyCycle = (u8)((SWICU_u16OnPeriod * 100UL) / (SWICU_u16OnPeriod + SWICU_u16OffPeriod));
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}

u8   SWICU_u8GetOnPeriod(u16 * Copy_pu16OnPeriod)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_pu16OnPeriod != NULL)
	{
		Copy_pu16OnPeriod = SWICU_u16OnPeriod;
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}

static void SWICU_voidEXTICallBack(void)
{
	u16 Local_u16TimerValue = 0;
	static u16 Local_u16OldValue = 0;
	static u8 Local_u8Flag = 0;
	/* Read Timer Value */
	TIMERS_u8GetTCNT1Value(&Local_u16TimerValue);
	if(Local_u8Flag == 0) /* Raising Edge */
	{
		/* Measure Off Period */
		SWICU_u16OffPeriod = Local_u16TimerValue - Local_u16OldValue;
		/* Change INT Trigger Source => Falling Edge */
		EXTI_u8EXTIEnable(EXTI_u8_EXTI0,EXTI_u8_FALLING_EDGE);
		/* Change Flag into Falling Edge */
		Local_u8Flag = 1;
	}
	else
	{
		/* Measure On Period */
		SWICU_u16OnPeriod = Local_u16TimerValue - Local_u16OldValue;
		/* Change INT Trigger Source => Raising Edge */
		EXTI_u8EXTIEnable(EXTI_u8_EXTI0,EXTI_u8_RAISING_EDGE);
		/* Change Flag into Raising Edge */
		Local_u8Flag = 0;
	}
	Local_u16OldValue = Local_u16TimerValue;
}
	