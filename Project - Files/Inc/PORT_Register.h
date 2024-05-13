/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	SWC : PORT 						           		***********************************/
/************** 	Version : V1         						   		**********************************/
/************** 	Date : Wednesday, August 23, 2023		*********************************/
/******************************************************************************/
#ifndef 			PORT_REGISTER_H_
#define 		PORT_REGISTER_H_

#define DIO_DDRA		*((volatile u8*)(0x3A))
#define DIO_DDRB		*((volatile u8*)(0x37))
#define DIO_DDRC		*((volatile u8*)(0x34))
#define DIO_DDRD		*((volatile u8*)(0x31))

#define DIO_PORTA		*((volatile u8*)(0x3B))
#define DIO_PORTB		*((volatile u8*)(0x38))
#define DIO_PORTC		*((volatile u8*)(0x35))
#define DIO_PORTD		*((volatile u8*)(0x32))

#endif
