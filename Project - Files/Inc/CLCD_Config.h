
/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	Layer : HAL 						           		***********************************/
/**************	 	SWC : CLCD 						           		***********************************/
/************** 	Version : V1         						   		**********************************/
/************** 	Date : Thursday, August 22, 2023		*********************************/
/******************************************************************************/
#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_
/**********CONTROL***********/
/** * CONTROL PORT * **/
#define 	CLCD_CTRL_PORT		DIO_u8PORTB	
/** * CONTROL PINS * **/
#define 	CLCD_RS					DIO_u8PIN0	
#define 	CLCD_RW					DIO_u8PIN1	
#define 	CLCD_E  				DIO_u8PIN2

/**********DATA***********/
/** * DATA PORT * **/
#define 	CLCD_DATA_PORT		DIO_u8PORTA


#define CharacterSize 			CharcterDot5M10
#define NumberOfLines			TwoLines
/*********CharacterSizes*********/
#define    	CharcterDot5M10		0
#define    	CharcterDot5M7		1
/*********LinesNumber*********/
#define    	OneLine				0
#define    	TwoLines			1

#endif
