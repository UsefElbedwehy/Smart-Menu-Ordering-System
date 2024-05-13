/************************************************************************************/
/************** 	Author : Usef Elbedwehy              		*************************************/
/************** 	Layer : MCAL         				      		************************************/
/**************	 	SWC : TIMER 						           	***********************************/
/************** 	Version : V1         						   		**********************************/
/************** 	Date : Saturday, September 9, 2023	*********************************/
/******************************************************************************/
#ifndef	TIMER_REGISTER_H_
#define	TIMER_REGISTER_H_

#define TIMER_TCCR0			*((volatile u8*)(0x53))		/*Timer/Counter0 Output Compare Register*/
#define TCCR0_CS00      		0										/*Clock Select BIT0*/
#define TCCR0_CS01     	  		1                                      /*Clock Select BIT1*/
#define TCCR0_CS02      		2                                      /*Clock Select BIT2*/
#define TCCR0_WGM01      		3                                      /*Waveform Generation Mode BIT1*/
#define TCCR0_COM00     	  	4                                      /*Compare Match Output Mode BIT0*/
#define TCCR0_COM01      		5                                      /*Compare Match Output Mode BIT1*/
#define TCCR0_WGM00     		6                                      /*Waveform Generation Mode BIT0*/
#define TCCR0_FOC0     	  		7                                      /*Force Output Compare*/

#define TIMER_TCNT0         	*((volatile u8*)(0x52))		/*Timer/Counter Register*/

#define TIMER_OCR0          	*((volatile u8*)(0x5C))		/*Output Compare Register*/

#define TIMER_TIMSK        	*((volatile u8*)(0x59))		/*Timer/Counter Interrupt Mask Register*/
#define TIMSK_TOIE0      		0						/*TIMER(0)*/
#define TIMSK_OCIE0       		1						/*TIMER(0)*/
#define TIMSK_TOIE1      		2                        /*TIMER(1)*/
#define TIMSK_OCIE1B       		3                        /*TIMER(1)*/
#define TIMSK_OCIE1A      		4                        /*TIMER(1)*/
#define TIMSK_TICIE1       		5                        /*TIMER(1)*/

#define TIMER_TIFR            *((volatile u8*)(0x58))		/*Timer/Counter Interrupt Flag Register*/
#define TIFR_TOV0      			0                        /*TIMER(0)*/
#define TIFR_OCF0     	  		1                        /*TIMER(0)*/
#define TIFR_TOV1      			2                         /*TIMER(1)*/
#define TIFR_OCF1B     	  		3                         /*TIMER(1)*/
#define TIFR_OCF1A      		4                         /*TIMER(1)*/
#define TIFR_ICF1     	  		5                         /*TIMER(1)*/

/**************  TIMER(1)  ***************/
#define	TIMER_TCCR1A			*((volatile u8*)0x4F)		/*Timer/Counter1 Control Register A*/
#define	TCCR1A_WGM10             0
#define	TCCR1A_WGM11             1
#define	TCCR1A_FOC1B             2
#define	TCCR1A_FOC1A             3
#define	TCCR1A_COM1B0            4
#define	TCCR1A_COM1B1            5
#define	TCCR1A_COM1A0            6
#define	TCCR1A_COM1A1            7

#define	TIMER_TCCR1B			*((volatile u8*)0x4E)		/*Timer/Counter1 Control Register B*/
#define	TCCR1B_CS10              0
#define	TCCR1B_CS11              1
#define	TCCR1B_CS12              2
#define	TCCR1B_WGM12             3
#define	TCCR1B_WGM13             4
#define	TCCR1B_ICES1             6
#define	TCCR1B_ICNC1             7


#define	TIMER_OCR1AH			*((volatile u8*)0x4B)		/*Timer/Counter1 Location HIGH*/
#define	TIMER_OCR1AL			*((volatile u8*)0x4A)		/*Timer/Counter1 Location LOW*/
#define	TIMER_OCR1BH			*((volatile u8*)0x49)		/*Output Compare Register 1 A HIGH*/
#define	TIMER_OCR1BL			*((volatile u8*)0x48)		/*Output Compare Register 1 A LOW*/
#define	TIMER_ICR1H				*((volatile u8*)0x47)		/*Input Capture Register 1 HIGH*/
#define	TIMER_ICR1L				*((volatile u8*)0x46)		/*Input Capture Register 1 LOW*/

#define	TIMER_OCR1AL_u16		*((volatile u16*)0x4A)
#define	TIMER_ICR1L_u16			*((volatile u16*)0x46)
#define	TIMER_OCR1BL_u16		*((volatile u16*)0x48)
#endif
