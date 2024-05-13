/************************************************************************************/
/************** 	Author : Usef Elbedwehy              		*************************************/
/************** 	Layer : MCAL         				      		************************************/
/**************	 	SWC : TIMER 						           	***********************************/
/************** 	Version : V1         						   		**********************************/
/************** 	Date : Saturday, September 9, 2023	*********************************/
/******************************************************************************/
#ifndef	TIMER_INTERFACE_H_
#define	TIMER_INTERFACE_H_
/********************/
void TIMER0_VoidInit(void);
u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));
void TIMER0_VoidSetCompareMatchValue(u8 Copy_u8Value);
/*********************/
void TIMER1_VoidInit(void);
void TIMER1_VoidSetICR(u16 Copy_u16TopValue);
void TIMER1_VoidSetChannelACompareMatchValue(u16 Copy_u16CompareMatchValue);
u8 TIMER1_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));
void STEPPER_MaxAngle(void);
void STEPPER_MinAngle(void);
void STEPPER_SetAngle(u8 Copy_u8Angle);
#endif
