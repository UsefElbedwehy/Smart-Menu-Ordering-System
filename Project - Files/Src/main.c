/*
 * main.c
 *
 *  Created on: Sep 11, 2023
 *      Author: Usef
 */

#include "STDTYPES.h"
#include "BITMATH.h"

#include "service.h"

void main(void)
{

	PRG_Init();

	while(1)
	{
		/*get value of ir sensor , when somebody id detected the servo will go 180 degree*/
		/*servo control the door*/
		/*Pulling until the IR sensor detect somebody*/
		/*IR sensor detects somebody so the the door opens*/
		MENU_VoidPreOrderMessage();
		/*For First Choice:
		 * OPTIONS:
		 * 1-PIZZAS
		 * 2-BURGERS
		 * 3-TACOS
		 * 4-DESSERTS
		 * */
		MENU_VoidGetChoiceS1();
		/*For Second Choice:
		 * OPTIONS depend on the first choice */
		MENU_VoidGetChoiceS2();
		MENU_VoidOrderRecipt();
		MENU_SetUp();

	}
}
