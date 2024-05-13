/************************************************************************************/
/************** 	Author : Usef Elbedwehy              		*************************************/
/************** 	Layer : MCAL         				      		************************************/
/**************	 	SWC : TIMER 						           	***********************************/
/************** 	Version : V1         						   		**********************************/
/************** 	Date : Saturday, September 9, 2023	*********************************/
/******************************************************************************/
#include "STDTYPES.h"
#include "BITMATH.h"

#include "TIMER_Interface.h"
#include "TIMER_Register.h"
#include "TIMER_Private.h"
#include "TIMER_Config.h"
static void (*TIMER0_pvCallBackFunc)(void)=NULL;
void TIMER0_VoidInit(void)
{
	/*CHOOSE Fast PWM MODE*/
	SetBit(TIMER_TCCR0,TCCR0_WGM00);
	SetBit(TIMER_TCCR0,TCCR0_WGM01);
	/*Output Compare Match Interrupt Enable*/
	/*SetBit(TIMER0_TIMSK,TIMSK_OCIE0);*/
	/*Set Compare match value to 125*/
	/*TIMER0_OCR0=125;*/
	/* Clear OC0 on compare match, set OC0 at BOTTOM*/
	CLRBit(TIMER_TCCR0,TCCR0_COM00);
	SetBit(TIMER_TCCR0,TCCR0_COM01);
	/*PEESCALER: DIVISION BY 64*/
	SetBit(TIMER_TCCR0,TCCR0_CS00);
	SetBit(TIMER_TCCR0,TCCR0_CS01);
	CLRBit(TIMER_TCCR0,TCCR0_CS02);
}

void TIMER0_VoidSetCompareMatchValue(u8 Copy_u8Value)
{
	TIMER_OCR0=Copy_u8Value;			/*Duty*/
}

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(TIMER0_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}
/***********************TIMER(1)******************************/
void TIMER1_VoidInit(void)
{
	/*CHOOSE Fast PWM MODE NUMBER 14*/
	CLRBit(TIMER_TCCR1A,TCCR1A_WGM10);
	SetBit(TIMER_TCCR1A,TCCR1A_WGM11);
	SetBit(TIMER_TCCR1B,TCCR1B_WGM12);
	SetBit(TIMER_TCCR1B,TCCR1B_WGM13);
	/* FAST-PWM
	 * clear OC1A/OC1B on compare match, Set OC1A/OC1B at BOTTOM (inverting mode)*/
	CLRBit(TIMER_TCCR1A,TCCR1A_COM1A0);
	SetBit(TIMER_TCCR1A,TCCR1A_COM1A1);
	/*PRESCALER DIV BY 8*/
	TIMER_TCCR1B&=PRESCALER_INITIAL_MASK;
	TIMER_TCCR1B|=DIV_BY_8;
}
void TIMER1_VoidSetICR(u16 Copy_u16TopValue)
{
TIMER_ICR1L_u16=Copy_u16TopValue;
}
void TIMER1_VoidSetChannelACompareMatchValue(u16 Copy_u16CompareMatchValue)
{
	TIMER_OCR1AL_u16=Copy_u16CompareMatchValue;
}
void STEPPER_MaxAngle(void)
{
	TIMER1_VoidSetChannelACompareMatchValue(2600);
}
void STEPPER_MinAngle(void)
{
	TIMER1_VoidSetChannelACompareMatchValue(450);
}
void STEPPER_SetAngle(u8 Copy_u8Angle)
{
	Copy_u8Angle&=0xB4;
	TIMER1_VoidSetChannelACompareMatchValue(Copy_u8Angle);
}
