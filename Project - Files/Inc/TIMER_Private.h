/************************************************************************************/
/************** 	Author : Usef Elbedwehy              		*************************************/
/************** 	Layer : MCAL         				      		************************************/
/**************	 	SWC : TIMER 						           	***********************************/
/************** 	Version : V1         						   		**********************************/
/************** 	Date : Saturday, September 9, 2023	*********************************/
/******************************************************************************/
#ifndef	TIMER_PRIVATE_H_
#define	TIMER_PRIVATE_H_

/*Clock Select Bit Description*/
#define		NO_CLK_SRC				0
#define		DIV_BY_1				1
#define		DIV_BY_8				2
#define		DIV_BY_64				3
#define		DIV_BY_256				4
#define		DIV_BY_1024				5
#define		EXT_CLK_FALLING			6
#define		EXT_CLK_RISING			7
/*Waveform Generation Mode Bit Description */
#define		NORMAL_MODE					0
#define		CTC_MODE                    1
#define		FAST_PWM_MODE               2
#define		PHASE_CORRECT_PWM_MODE      3
/*Compare Output Mode, non-PWM Mode			*/
#define		OC0_NPWM_NORMAL					0
#define		OC0_NPWM_TOGGLE					1
#define		OC0_NPWM_CLEAR					2
#define		OC0_NPWM_SET					3

/*Compare Output Mode, Fast PWM Mode*/
#define		OC0_FPWM_NORMAL					0
#define		OC0_FPWM_CLEAR					2
#define		OC0_FPWM_SET					3
/*Compare Output Mode, Phase Correct PWM Mode*/
#define		OC0_PCPWM_NORMAL				0
#define		OC0_PCPWM_CLEAR					2
#define		OC0_PCPWM_SET					3
/*PRESCALER MASK*/
#define	PRESCALER_INITIAL_MASK				0b11111000
#endif
