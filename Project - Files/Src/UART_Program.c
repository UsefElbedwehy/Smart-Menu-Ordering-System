/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	Layer : MACL 						             ***********************************/
/**************	 	SWC : UART 						           		***********************************/
/************** 	Version : V1         						   		**********************************/
/************** 	Wednesday, September 13, 2023		*********************************/
/******************************************************************************/
#include "STDTYPES.h"
#include "BITMATH.h"

#include "UART_Interface.h"
#include "UART_Private.h"
#include "UART_Register.h"
#include "UART_Config.h"

void UART_VoidInit(void)
{
	u8 Local_u8UCSRC_Value=0;
	u8 Local_u8UBRRH_Value=0;
	/*set select register bit to access UCSRC */
	SetBit(Local_u8UCSRC_Value,UCSRC_URSEL);
	/*Asynchronous*/
	CLRBit(Local_u8UCSRC_Value,UCSRC_UMSEL);
	/*set data 8 bits*/
	SetBit(Local_u8UCSRC_Value,UCSRC_UCSZ0);
	SetBit(Local_u8UCSRC_Value,UCSRC_UCSZ1);
	CLRBit(UART_UCSRB,UCSRB_UCSZ2);
	/*no parity*/
	CLRBit(Local_u8UCSRC_Value,UCSRC_UPM0);
	CLRBit(Local_u8UCSRC_Value,UCSRC_UPM1);
	/*one stop bit*/
	CLRBit(Local_u8UCSRC_Value,UCSRC_USBS);
	/*assign the value to UCSRC*/
	UART_UCSRC=Local_u8UCSRC_Value;
	/*Set Baud rate to 9600*/
	UART_UBRRL=51;
	/*enable receiver*/
	SetBit(UART_UCSRB,UCSRB_RXEN);
	/*enable transmitter*/
	SetBit(UART_UCSRB,UCSRB_TXEN);

}
void UART_VoidTransmit(u8 Copy_Data)
{

	/*wait for the empty transmition register flag*/
	while(GetBit(UART_UCSRA,UCSRA_UDRE)==0);
	/*Send data*/
	UART_UDR=Copy_Data;
}
u8 UART_u8Receive(void)
{

	/*waiting receive data flag*/
	while(GetBit(UART_UCSRA,UCSRA_RXC)==0);
	/*read data*/
	return UART_UDR;
}
void UART_VoidTransmitString(const char* Copy_pcString)
{
	u8 Local_u8Counter=0;
	while(Copy_pcString[Local_u8Counter]!='\0')
	{
		UART_VoidTransmit(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}
