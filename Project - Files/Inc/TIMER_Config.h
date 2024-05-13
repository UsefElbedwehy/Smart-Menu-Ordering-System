/************************************************************************************/
/************** 	Author : Usef Elbedwehy              		*************************************/
/************** 	Layer : MCAL         				      		************************************/
/**************	 	SWC : TIMER 						           	***********************************/
/************** 	Version : V1         						   		**********************************/
/************** 	Date : Saturday, September 9, 2023	*********************************/
/******************************************************************************/
#ifndef	TIMER_CONFIG_H_
#define	TIMER_CONFIG_H_
/***********************TIMER(0)***************************/
/*Clock Select Bit Description
choose, options:
1-NO_CLK_SRC		                           
2-DIV_BY_1				
3-DIV_BY_8				
4-DIV_BY_64			
5-DIV_BY_256			
6-DIV_BY_1024		
7-EXT_CLK_FALLING	
8-EXT_CLK_RISING   	*/
#define PRESCALER	DIV_BY_8
/*Waveform Generation Mode Bit Description
choose, options:
1-NORMAL_MODE
2-CTC_MODE
3-FAST_PWM_MODE
4-PHASE_CORRECT_PWM_MODE	*/
#define WAVE_GENERATION_MODE	CTC_MODE
/*Compare Output Mode, non-PWM Mode
 choose, options:
 1-OC0_NPWM_NORMAL
 2-OC0_NPWM_TOGGLE
 3-OC0_NPWM_CLEAR
 4-OC0_NPWM_SET                    */
#define	COMPARE_MATCH_MODE_NPWM			OC0_NPWM_NORMAL
/*Compare Output Mode, Fast PWM Mode
 choose, options:
 1-OC0_FPWM_NORMAL
 2-OC0_FPWM_CLEAR
 3-OC0_FPWM_SET                   */
#define	COMPARE_MATCH_MODE_FPWM			OC0_FPWM_NORMAL
/*Compare Output Mode, Phase Correct PWM Mode
 choose, options:
 1-OC0_PCPWM_NORMAL
 2-OC0_PCPWM_CLEAR
 3-OC0_PCPWM_SET                */
#define	COMPARE_MATCH_MODE_PCPWM			OC0_PCPWM_NORMAL
/***********************TIMER(1)***************************/

/***********************TIMER(2)***************************/

#endif
