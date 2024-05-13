/*
 * Service.c
 *
 *  Created on: May 13, 2024
 *      Author: Usef
 */

#include "PORT_Interface.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "CLCD_Interface.h"
#include "UART_Interface.h"
#include "TIMER_Interface.h"
#include <util/delay.h>


u8 Option_ONE=0;
u8 Option_TWO=0;
u8 MENU_CURSOUR=1;
u8 BTN_UP_STATE=1;
u8 BTN_DOWN_STATE=1;
u8 BTN_OK_STATE=1;


void PRG_Init(void)
{
	PORT_VoidInit();
	CLCD_VoidInit();
	TIMER1_VoidInit();
	TIMER1_VoidSetICR(20000);
	MENU_VoidWelcome();
	BZR_VoidNextOptionTone();
	UART_VoidInit();
}
//welcome to restaurant
void MENU_VoidWelcome(void)
{
	CLCD_VoidClearDisplay();
	CLCD_VoidGoToXY(0,0);
	CLCD_VoidSendString("WELCOME TO:");
	CLCD_VoidGoToXY(1,0);
	CLCD_VoidSendString("NEW RESTAURANT");
	BZR_VoidWelcomeTone();
	_delay_ms(3000);
	CLCD_VoidClearDisplay();
}

//welcome to menu
void MENU_VoidPreOrderMessage(void)
{
	CLCD_VoidClearDisplay();
	CLCD_VoidGoToXY(0,0);
	CLCD_VoidSendString("Door is opened...");
	STEPPER_MaxAngle();
	_delay_ms(2000);
	STEPPER_MinAngle();
	CLCD_VoidClearDisplay();
	CLCD_VoidGoToXY(0,0);
	CLCD_VoidSendString("Door is closed...");
	_delay_ms(2000);
	CLCD_VoidClearDisplay();
	CLCD_VoidGoToXY(0,0);
	CLCD_VoidSendString("Welcome! MS/r");
	CLCD_VoidGoToXY(1,0);
	CLCD_VoidSendString("Order now!");
	_delay_ms(2000);
}

//scrolling 1st layer of the menu
void MENU_VoidUpdateS1(void)
{
	switch(MENU_CURSOUR)
	{
	case 0:	MENU_CURSOUR=4;
	/*ADD TONE*/
	/*LCD Points to Option1*/
	CLCD_VoidClearDisplay();
	CLCD_VoidGoToXY(0,0);
	CLCD_VoidSendString(" TACOS");
	CLCD_VoidGoToXY(1,0);
	CLCD_VoidSendString(">DESSERTS");
	break;
	case 1:
		/*ADD TONE*/
		/*LCD Points to Option1*/
		CLCD_VoidClearDisplay();
		CLCD_VoidGoToXY(0,0);
		CLCD_VoidSendString(">PIZZAS");
		CLCD_VoidGoToXY(1,0);
		CLCD_VoidSendString(" BURGERS");
		break;
	case 2:
		/*ADD TONE*/
		/*LCD Points to Option1*/
		CLCD_VoidClearDisplay();
		CLCD_VoidGoToXY(0,0);
		CLCD_VoidSendString(" PIZZAS");
		CLCD_VoidGoToXY(1,0);
		CLCD_VoidSendString(">BURGERS");
		break;
	case 3:
		/*ADD TONE*/
		/*LCD Points to Option1*/
		CLCD_VoidClearDisplay();
		CLCD_VoidGoToXY(0,0);
		CLCD_VoidSendString(">TACOS");
		CLCD_VoidGoToXY(1,0);
		CLCD_VoidSendString(" DESSERTS");
		break;
	case 4:
		/*ADD TONE*/
		/*LCD Points to Option1*/
		CLCD_VoidClearDisplay();
		CLCD_VoidGoToXY(0,0);
		CLCD_VoidSendString(" TACOS");
		CLCD_VoidGoToXY(1,0);
		CLCD_VoidSendString(">DESSERTS");
		break;
	case 5:	MENU_CURSOUR=1;
	/*ADD TONE*/
	/*LCD Points to Option1*/
	CLCD_VoidClearDisplay();
	CLCD_VoidGoToXY(0,0);
	CLCD_VoidSendString(">PIZZAS");
	CLCD_VoidGoToXY(1,0);
	CLCD_VoidSendString(" BURGERS");
	break;
	}
}

void MENU_VoidGetChoiceS1(void)
{
	u8 Local_u8State=0;
	/*IT will get out from while loop when OK key is pressed*/
	/*Knowing the chosen option by knowing MENU_CURSOUR*/
	CLCD_VoidClearDisplay();
	CLCD_VoidSendString("   UP or DOWN");
	do
	{

		DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN1,&BTN_UP_STATE);
		DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN2,&BTN_DOWN_STATE);
		if(BTN_DOWN_STATE==0)
		{
			MENU_CURSOUR++;
			MENU_VoidUpdateS1();
			/*PULLING UNTIL KEY IS RELEASED*/
			while(BTN_DOWN_STATE==0)
			{
				DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN2,&BTN_DOWN_STATE);
			}
		}if(BTN_UP_STATE==0)
		{
			MENU_CURSOUR--;
			MENU_VoidUpdateS1();
			/*PULLING UNTIL KEY IS RELEASED*/
			while(BTN_UP_STATE==0)
			{
				DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN1,&BTN_UP_STATE);
			}
		}
		DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN0,&BTN_OK_STATE);
		while(BTN_OK_STATE==0)
		{
			DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN0,&BTN_OK_STATE);
			Local_u8State=1;
		}

		_delay_ms(100);
	}while(Local_u8State!=1);
	BTN_OK_STATE=1;
	Option_ONE=MENU_CURSOUR;
	BZR_VoidNextOptionTone();
}

void MENU_VoidUpdateS2(void)
{
	/*PIZZAS*/
	if(Option_ONE==1)
	{
		switch(MENU_CURSOUR)
		{
		case 0:	MENU_CURSOUR=4; break;
		case 1:
			/*ADD TONE*/
			/*LCD Points to Option1*/
			CLCD_VoidClearDisplay();
			CLCD_VoidGoToXY(0,0);
			CLCD_VoidSendString(">Beef");
			CLCD_VoidGoToXY(1,0);
			CLCD_VoidSendString(" Cheese");
			break;
		case 2:
			/*ADD TONE*/
			/*LCD Points to Option1*/
			CLCD_VoidClearDisplay();
			CLCD_VoidGoToXY(0,0);
			CLCD_VoidSendString(" Beef");
			CLCD_VoidGoToXY(1,0);
			CLCD_VoidSendString(">Cheese");
			break;
		case 3:
			/*ADD TONE*/
			/*LCD Points to Option1*/
			CLCD_VoidClearDisplay();
			CLCD_VoidGoToXY(0,0);
			CLCD_VoidSendString(">Chicken1");
			CLCD_VoidGoToXY(1,0);
			CLCD_VoidSendString(" Chicken2");
			break;
		case 4:
			/*ADD TONE*/
			/*LCD Points to Option1*/
			CLCD_VoidClearDisplay();
			CLCD_VoidGoToXY(0,0);
			CLCD_VoidSendString(" Chicken1");
			CLCD_VoidGoToXY(1,0);
			CLCD_VoidSendString(">Chicken2");
			break;
		case 5:	MENU_CURSOUR=1; break;
		}
	}
	/*BURGERS*/
	if(Option_ONE==2)
	{
		switch(MENU_CURSOUR)
		{
		case 0:	MENU_CURSOUR=4; break;
		case 1:
			/*ADD TONE*/
			/*LCD Points to Option1*/
			CLCD_VoidClearDisplay();
			CLCD_VoidGoToXY(0,0);
			CLCD_VoidSendString(">Classic");
			CLCD_VoidGoToXY(1,0);
			CLCD_VoidSendString(" Beef");
			break;
		case 2:
			/*ADD TONE*/
			/*LCD Points to Option1*/
			CLCD_VoidClearDisplay();
			CLCD_VoidGoToXY(0,0);
			CLCD_VoidSendString(" Classic");
			CLCD_VoidGoToXY(1,0);
			CLCD_VoidSendString(">Beef");
			break;
		case 3:
			/*ADD TONE*/
			/*LCD Points to Option1*/
			CLCD_VoidClearDisplay();
			CLCD_VoidGoToXY(0,0);
			CLCD_VoidSendString(">Chicken1");
			CLCD_VoidGoToXY(1,0);
			CLCD_VoidSendString(" Chicken2");
			break;
		case 4:
			/*ADD TONE*/
			/*LCD Points to Option1*/
			CLCD_VoidClearDisplay();
			CLCD_VoidGoToXY(0,0);
			CLCD_VoidSendString(" Chicken1");
			CLCD_VoidGoToXY(1,0);
			CLCD_VoidSendString(">Chicken2");
			break;
		case 5:	MENU_CURSOUR=1; break;
		}
	}
	/*TACOS*/
	if(Option_ONE==3)
	{
		switch(MENU_CURSOUR)
		{
		case 0:	MENU_CURSOUR=4; break;
		case 1:
			/*ADD TONE*/
			/*LCD Points to Option1*/
			CLCD_VoidClearDisplay();
			CLCD_VoidGoToXY(0,0);
			CLCD_VoidSendString(">Chicken");
			CLCD_VoidGoToXY(1,0);
			CLCD_VoidSendString(" beef");
			break;
		case 2:
			/*ADD TONE*/
			/*LCD Points to Option1*/
			CLCD_VoidClearDisplay();
			CLCD_VoidGoToXY(0,0);
			CLCD_VoidSendString(" Chicken");
			CLCD_VoidGoToXY(1,0);
			CLCD_VoidSendString(">beef");
			break;
		case 3:
			/*ADD TONE*/
			/*LCD Points to Option1*/
			CLCD_VoidClearDisplay();
			CLCD_VoidGoToXY(0,0);
			CLCD_VoidSendString(">shrimp");
			CLCD_VoidGoToXY(1,0);
			CLCD_VoidSendString(" Cheese");
			break;
		case 4:
			/*ADD TONE*/
			/*LCD Points to Option1*/
			CLCD_VoidClearDisplay();
			CLCD_VoidGoToXY(0,0);
			CLCD_VoidSendString(" shrimp");
			CLCD_VoidGoToXY(1,0);
			CLCD_VoidSendString(">Cheese");
			break;
		case 5:	MENU_CURSOUR=1; break;
		}
	}
	/*DESSERTS*/
	if(Option_ONE==4)
	{
		switch(MENU_CURSOUR)
		{
		case 0:	MENU_CURSOUR=4; break;
		case 1:
			/*ADD TONE*/
			/*LCD Points to Option1*/
			CLCD_VoidClearDisplay();
			CLCD_VoidGoToXY(0,0);
			CLCD_VoidSendString(">Orange");
			CLCD_VoidGoToXY(1,0);
			CLCD_VoidSendString(" Mango");
			break;
		case 2:
			/*ADD TONE*/
			/*LCD Points to Option1*/
			CLCD_VoidClearDisplay();
			CLCD_VoidGoToXY(0,0);
			CLCD_VoidSendString(" Orange");
			CLCD_VoidGoToXY(1,0);
			CLCD_VoidSendString(">Mango");
			break;
		case 3:
			/*ADD TONE*/
			/*LCD Points to Option1*/
			CLCD_VoidClearDisplay();
			CLCD_VoidGoToXY(0,0);
			CLCD_VoidSendString(">Fruits");
			CLCD_VoidGoToXY(1,0);
			CLCD_VoidSendString(" Cake");
			break;
		case 4:
			/*ADD TONE*/
			/*LCD Points to Option1*/
			CLCD_VoidClearDisplay();
			CLCD_VoidGoToXY(0,0);
			CLCD_VoidSendString(" Fruits");
			CLCD_VoidGoToXY(1,0);
			CLCD_VoidSendString(">Cake");
			break;
		case 5:	MENU_CURSOUR=1; break;
		}
	}

}
void MENU_VoidGetChoiceS2(void)
{
	u8 Local_u8state=0;
	/*IT will get out from while loop when OK key is pressed*/
	/*Knowing the chosen option by knowing MENU_CURSOUR*/
	CLCD_VoidClearDisplay();
	CLCD_VoidSendString("   UP or DOWN");
	do
	{

		DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN1,&BTN_UP_STATE);
		DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN2,&BTN_DOWN_STATE);
		if(BTN_DOWN_STATE==0)
		{
			MENU_CURSOUR++;
			MENU_VoidUpdateS2();
			/*PULLING UNTIL KEY IS RELEASED*/
			while(BTN_DOWN_STATE==0)
			{
				DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN2,&BTN_DOWN_STATE);
			}
		}if(BTN_UP_STATE==0)
		{
			MENU_CURSOUR--;
			MENU_VoidUpdateS2();
			/*PULLING UNTIL KEY IS RELEASED*/
			while(BTN_UP_STATE==0)
			{
				DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN1,&BTN_UP_STATE);
			}
		}
		DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN0,&BTN_OK_STATE);
		while(BTN_OK_STATE==0)
		{
			DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN0,&BTN_OK_STATE);
			Local_u8state=1;
		}
	}while(Local_u8state!=1);
	BTN_OK_STATE=1;
	Option_TWO=MENU_CURSOUR;
	BZR_VoidNextOptionTone();
}
void MENU_VoidOrderRecipt(void)
{
	static Local_NumerOfOrder=0;
	Local_NumerOfOrder++;
	if(Option_ONE==1)
	{
		/*PIZZAS*/
		CLCD_VoidClearDisplay();
		CLCD_VoidGoToXY(0,0);
		CLCD_VoidSendString("Wait 40 Min...");
		CLCD_VoidGoToXY(1,0);
		CLCD_VoidSendString("Order no ");
		CLCD_VoidSendString("#");
		CLCD_VoidSendNumber(Local_NumerOfOrder);
		UART_VoidTransmit(' ');
		UART_VoidTransmit('#');
		switch(Option_TWO)
		{
		case 1:
			/*sending order*/
			UART_VoidTransmitString("PIZZA->BEEF");
			break;
		case 2:
			UART_VoidTransmitString("PIZZA->CHEESE");
			break;
		case 3:
			UART_VoidTransmitString("PIZZA->CHICKEN1");
			break;
		case 4:
			UART_VoidTransmitString("PIZZA->CHICKEN2");
			break;
		}
	}else if(Option_ONE==2)
	{
		/*BURGERS*/
		CLCD_VoidClearDisplay();
		CLCD_VoidGoToXY(0,0);
		CLCD_VoidSendString("Wait 30 Min...");
		CLCD_VoidGoToXY(1,0);
		CLCD_VoidSendString("Order no ");
		CLCD_VoidSendString("#");
		CLCD_VoidSendNumber(Local_NumerOfOrder);
		UART_VoidTransmit(' ');
		UART_VoidTransmit('#');
		switch(Option_TWO)
		{
		case 1: /*Communication*/
			UART_VoidTransmitString("BURGER->CLASSIC");
			break;
		case 2: /*Communication*/
			UART_VoidTransmitString("BURGER->BEEF");
			break;
		case 3: /*Communication*/
			UART_VoidTransmitString("BURGER->CHICKEN1");
			break;
		case 4: /*Communication*/
			UART_VoidTransmitString("BURGER->CHICKEN2");
			break;
		}
	}else if(Option_ONE==3)
	{
		/*TACOS*/
		CLCD_VoidClearDisplay();
		CLCD_VoidGoToXY(0,0);
		CLCD_VoidSendString("Wait 20 Min...");
		CLCD_VoidGoToXY(1,0);
		CLCD_VoidSendString("Order no ");
		CLCD_VoidSendString("#");
		CLCD_VoidSendNumber(Local_NumerOfOrder);
		UART_VoidTransmit(' ');
		UART_VoidTransmit('#');
		switch(Option_TWO)
		{
		case 1: /*Communication*/
			UART_VoidTransmitString("TACOS->CHICKEN");
			break;
		case 2: /*Communication*/
			UART_VoidTransmitString("TACOS->BEEF");
			break;
		case 3: /*Communication*/
			UART_VoidTransmitString("TACOS->SHRIMP");
			break;
		case 4: /*Communication*/
			UART_VoidTransmitString("TACOS->CHEESE");
			break;
		}
	}else if(Option_ONE==4)
	{
		/*DESSERTS*/
		CLCD_VoidClearDisplay();
		CLCD_VoidGoToXY(0,0);
		CLCD_VoidSendString("Wait 10 Min...");
		CLCD_VoidGoToXY(1,0);
		CLCD_VoidSendString("Order no ");
		CLCD_VoidSendString("#");
		CLCD_VoidSendNumber(Local_NumerOfOrder);
		UART_VoidTransmit(' ');
		UART_VoidTransmit('#');
		switch(Option_TWO)
		{
		case 1:
			UART_VoidTransmitString("DESSERT->ORANGE");
			break;
		case 2:
			UART_VoidTransmitString("DESSERT->MANGO");
			break;
		case 3:
			UART_VoidTransmitString("DESSERT->FRUITS");
			break;
		case 4:
			UART_VoidTransmitString("DESSERT->CAKE");
			break;
		}
	}
	BZR_VoidNextOptionTone();
}
void MENU_SetUp(void)
{
	_delay_ms(5000);
	CLCD_VoidClearDisplay();
	CLCD_VoidSendString("Thanks...");
	BZR_VoidNextOptionTone();
	_delay_ms(3000);
}
void BZR_VoidNextOptionTone(void)
{
	u8 Local_u8Itterator=0;
	u8 Local_u8Itterator2=0;
	for(Local_u8Itterator2=0;Local_u8Itterator2<2;Local_u8Itterator2++)
	{
		for(Local_u8Itterator=0;Local_u8Itterator<150;Local_u8Itterator++)
		{
			DIO_VoidSetPinValue(DIO_u8PORTD,DIO_u8PIN7,1);
			_delay_us(6*Local_u8Itterator);
			DIO_VoidSetPinValue(DIO_u8PORTD,DIO_u8PIN7,0);
			_delay_us(6*Local_u8Itterator);
		}
	}

}

void BZR_VoidWelcomeTone(void)
{
	u8 Local_u8Itterator=0;
	u8 Local_u8Itterator2=0;
	for(Local_u8Itterator2=0;Local_u8Itterator2<15;Local_u8Itterator2++)
	{
		for(Local_u8Itterator=0;Local_u8Itterator<80;Local_u8Itterator++)
		{
			DIO_VoidSetPinValue(DIO_u8PORTD,DIO_u8PIN7,1);
			_delay_us(6*Local_u8Itterator);
			DIO_VoidSetPinValue(DIO_u8PORTD,DIO_u8PIN7,0);
			_delay_us(6*Local_u8Itterator);
		}
	}

}
