/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	SWC : PORT 						           		***********************************/
/************** 	Version : V1         						   		**********************************/
/************** 	Date : Wednesday, August 23, 2023		*********************************/
/******************************************************************************/
#ifndef 			PORT_CONFIG_H_
#define 		PORT_CONFIG_H_

/* *** ** * DIRECTION * ** *** */
/*	choose:
				0 -> INPUT
				1 -> OUTPUT				*/
/* * * * * PORTA -> DIR* * * * */
#define    PORTA_PIN0_DIR			 					1
#define    PORTA_PIN1_DIR          						1
#define    PORTA_PIN2_DIR          						1
#define    PORTA_PIN3_DIR          						1
#define    PORTA_PIN4_DIR          						1
#define    PORTA_PIN5_DIR          						1
#define    PORTA_PIN6_DIR          						1
#define    PORTA_PIN7_DIR          						1
/* * * * * PORTB -> DIR* * * * */			
#define    PORTB_PIN0_DIR			  					1
#define    PORTB_PIN1_DIR           					1
#define    PORTB_PIN2_DIR           					1
#define    PORTB_PIN3_DIR           					0
#define    PORTB_PIN4_DIR           					0
#define    PORTB_PIN5_DIR           					0
#define    PORTB_PIN6_DIR           					0
#define    PORTB_PIN7_DIR           					0
/* * * * * PORTC -> DIR* * * * */					
#define    PORTC_PIN0_DIR			  					0
#define    PORTC_PIN1_DIR           					0
#define    PORTC_PIN2_DIR           					0
#define    PORTC_PIN3_DIR           					0
#define    PORTC_PIN4_DIR           					0
#define    PORTC_PIN5_DIR           					0
#define    PORTC_PIN6_DIR           					0
#define    PORTC_PIN7_DIR           					0
/* * * * * PORTD -> DIR* * * * */			
#define    PORTD_PIN0_DIR			  					0
#define    PORTD_PIN1_DIR          						1
#define    PORTD_PIN2_DIR          						0
#define    PORTD_PIN3_DIR          						0
#define    PORTD_PIN4_DIR          						0
#define    PORTD_PIN5_DIR          						1
#define    PORTD_PIN6_DIR          						0
#define    PORTD_PIN7_DIR          						1
/* *** ** * VALUE * ** *** */	
/*	if OUTPUT choose:	
							0 -> LOW	
							1 -> HIGH			
	if INPUT choose:	
							0 -> FLOATING	
							1 -> PULLUP	*/								
/* * * * * PORTA -> VAL* * * * */	
#define    PORTA_PIN0_INITIAL_VALUE		   		0
#define    PORTA_PIN1_INITIAL_VALUE          	0
#define    PORTA_PIN2_INITIAL_VALUE          	0
#define    PORTA_PIN3_INITIAL_VALUE          	0
#define    PORTA_PIN4_INITIAL_VALUE          	0
#define    PORTA_PIN5_INITIAL_VALUE          	0
#define    PORTA_PIN6_INITIAL_VALUE          	0
#define    PORTA_PIN7_INITIAL_VALUE          	0
/* * * * * PORTB -> VAL* * * * */	
#define    PORTB_PIN0_INITIAL_VALUE		  		0
#define    PORTB_PIN1_INITIAL_VALUE          	0
#define    PORTB_PIN2_INITIAL_VALUE          	0
#define    PORTB_PIN3_INITIAL_VALUE          	0
#define    PORTB_PIN4_INITIAL_VALUE          	0
#define    PORTB_PIN5_INITIAL_VALUE          	0
#define    PORTB_PIN6_INITIAL_VALUE          	0
#define    PORTB_PIN7_INITIAL_VALUE          	0
/* * * * * PORTC -> VAL* * * * */	
#define    PORTC_PIN0_INITIAL_VALUE		    	1
#define    PORTC_PIN1_INITIAL_VALUE          	1
#define    PORTC_PIN2_INITIAL_VALUE          	1
#define    PORTC_PIN3_INITIAL_VALUE          	0
#define    PORTC_PIN4_INITIAL_VALUE          	0
#define    PORTC_PIN5_INITIAL_VALUE          	0
#define    PORTC_PIN6_INITIAL_VALUE          	0
#define    PORTC_PIN7_INITIAL_VALUE          	0
/* * * * * PORTD -> VAL* * * * */	
#define    PORTD_PIN0_INITIAL_VALUE		  		0
#define    PORTD_PIN1_INITIAL_VALUE          	0
#define    PORTD_PIN2_INITIAL_VALUE          	0
#define    PORTD_PIN3_INITIAL_VALUE          	0
#define    PORTD_PIN4_INITIAL_VALUE          	0
#define    PORTD_PIN5_INITIAL_VALUE          	0
#define    PORTD_PIN6_INITIAL_VALUE          	0
#define    PORTD_PIN7_INITIAL_VALUE          	0


#endif
