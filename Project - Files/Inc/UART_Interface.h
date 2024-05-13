/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	Layer : MACL 						             ***********************************/
/**************	 	SWC : UART 						           		***********************************/
/************** 	Version : V1         						   		**********************************/
/************** 	Wednesday, September 13, 2023		*********************************/
/******************************************************************************/
#ifndef	UART_INTERFACE_H_
#define	UART_INTERFACE_H_
/*fast*/
void UART_VoidInit(void);
void UART_VoidTransmit(u8 Copy_Data);
u8 UART_u8Receive(void);
void UART_VoidTransmitString(const char* Copy_pcString);
/*post*/
/*pre*/
#endif
