/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	SWC : DIO 						           		***********************************/
/************** 	Version : V1         						   		**********************************/
/************** 	Date : Thursday, August 21, 2023		*********************************/
/******************************************************************************/

#include "STDTYPES.H"
#include "BITMATH.H"

#include "DIO_Interface.h"
#include "DIO_Register.h"
#include "DIO_Private.h"
#include "DIO_Config.h"

/***************************************************************/
u8 DIO_VoidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Output)       /*PIN VALUE*/
{
	u8 Local_u8ErroState=0;
	if(Copy_u8Pin<=DIO_u8PIN7)
	{
		if(Copy_u8Output==DIO_u8PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA		:  SetBit( DIO_PORTA , Copy_u8Pin); 	 		break;
			case DIO_u8PORTB		:  SetBit( DIO_PORTB , Copy_u8Pin); 	 		break;
			case DIO_u8PORTC		:  SetBit( DIO_PORTC , Copy_u8Pin); 	 		break;
			case DIO_u8PORTD		:  SetBit( DIO_PORTD , Copy_u8Pin);   	 		break;
			default: 				   Local_u8ErroState=1; 						break;
			}
		}
		else if(Copy_u8Output==DIO_u8PIN_LOW)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA		:  CLRBit( DIO_PORTA , Copy_u8Pin); 	 		break;
			case DIO_u8PORTB		:  CLRBit( DIO_PORTB , Copy_u8Pin); 	 		break;
			case DIO_u8PORTC		:  CLRBit( DIO_PORTC , Copy_u8Pin); 	 		break;
			case DIO_u8PORTD		:  CLRBit( DIO_PORTD , Copy_u8Pin); 		 	break;
			default: 				   Local_u8ErroState=1; 						break;
			}
		}else
		{
			Local_u8ErroState=1;
		}
	}else
	{
		Local_u8ErroState=1;
	}

	return Local_u8ErroState;
}
/***************************************************************/
u8   DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_Pu8Value)		 							 /*GET PIN VALUE */
{
	u8 Local_u8ErroState=0;
	if( (Copy_u8Pin<=DIO_u8PIN7))
	{
		switch(Copy_u8Port)
			{
			case DIO_u8PORTA		: *Copy_Pu8Value = GetBit( DIO_PINA , Copy_u8Pin);       break;
			case DIO_u8PORTB		: *Copy_Pu8Value = GetBit( DIO_PINB , Copy_u8Pin);       break;
			case DIO_u8PORTC		: *Copy_Pu8Value = GetBit( DIO_PINC , Copy_u8Pin);       break;
			case DIO_u8PORTD		: *Copy_Pu8Value = GetBit( DIO_PIND , Copy_u8Pin);       break;
			default: 				   Local_u8ErroState=1; 						         break;
			}
	}
	else
	{
		Local_u8ErroState=1;
	}

	return Local_u8ErroState;
}
/***************************************************************/
u8 DIO_VoidTogglePin(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 Local_u8ErroState=0;
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA		:  ToggleBit( DIO_PORTA , Copy_u8Pin); 	 		break;
	case DIO_u8PORTB		:  ToggleBit( DIO_PORTB , Copy_u8Pin); 	 		break;
	case DIO_u8PORTC		:  ToggleBit( DIO_PORTC , Copy_u8Pin); 	 		break;
	case DIO_u8PORTD		:  ToggleBit( DIO_PORTD , Copy_u8Pin);   	 	break;
	default: 				   Local_u8ErroState=1; 						break;
	}
	return Local_u8ErroState;
}

/***************************************************************/
u8 DIO_VoidSetPortValue(u8 Copy_u8Port , u8 Copy_u8Value)
{
	u8 Local_u8ErroState=0;
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA		:  DIO_PORTA = Copy_u8Value;	 		 break;
	case DIO_u8PORTB		:  DIO_PORTB = Copy_u8Value;	 		 break;
	case DIO_u8PORTC		:  DIO_PORTC = Copy_u8Value;	 		 break;
	case DIO_u8PORTD		:  DIO_PORTD = Copy_u8Value;  	 	 	 break;
	default: 				   Local_u8ErroState=1; 						break;
	}
	return Local_u8ErroState;
}
/***************************************************************/
u8   DIO_u8GetPortValue(u8 Copy_u8Port , u8* Copy_Pu8Value)
{
	u8 Local_u8ErroState=0;
	if(*Copy_Pu8Value!=NULL)
	{
		switch(Copy_u8Port)
			{
			case DIO_u8PORTA		:  *Copy_Pu8Value = DIO_PINA ;			break;
			case DIO_u8PORTB		:  *Copy_Pu8Value = DIO_PINB ;          break;
			case DIO_u8PORTC		:  *Copy_Pu8Value = DIO_PINC ;          break;
			case DIO_u8PORTD		:  *Copy_Pu8Value = DIO_PIND ;          break;
			default: 				   Local_u8ErroState=1; 						break;
			}
	}
	else
	{
		Local_u8ErroState=1;
	}

	return Local_u8ErroState;
}
