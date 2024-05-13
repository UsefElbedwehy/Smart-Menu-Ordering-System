/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	SWC : DIO 						           		***********************************/
/************** 	Version : V1         						   		**********************************/
/************** 	Date : Thursday, August 21, 2023		*********************************/
/******************************************************************************/

#ifndef			DIO_INTERFACE_H_
#define			DIO_INTERFACE_H_


u8 DIO_VoidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Output);     			/*PIN*/
u8 DIO_VoidSetPortValue(u8 Copy_u8Port , u8 Copy_u8Value);									   /*PORT*/

u8   DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_Pu8Value);	    										 /*PIN*/
u8   DIO_u8GetPortValue(u8 Copy_u8Port , u8* Copy_Pu8Value);                          											 /*PORT*/

u8 DIO_VoidTogglePin(u8 Copy_u8Port , u8 Copy_u8Pin);

#endif
