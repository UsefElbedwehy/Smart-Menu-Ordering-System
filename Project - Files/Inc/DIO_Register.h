/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	SWC : DIO 						           		***********************************/
/************** 	Version : V1         						   		**********************************/
/************** 	Date : Thursday, August 21, 2023		*********************************/
/******************************************************************************/

#ifndef			DIO_REGISTER_H_
#define         DIO_REGISTER_H_

#define DIO_PORTA		*((volatile u8*)(0x3B))
#define DIO_PORTB		*((volatile u8*)(0x38))
#define DIO_PORTC		*((volatile u8*)(0x35))
#define DIO_PORTD		*((volatile u8*)(0x32))

#define DIO_PINA			*((volatile u8*)(0x39))
#define DIO_PINB			*((volatile u8*)(0x36))
#define DIO_PINC			*((volatile u8*)(0x33))
#define DIO_PIND			*((volatile u8*)(0x30))


#endif