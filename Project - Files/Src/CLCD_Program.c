#include "STDTYPES.h"
#include <util/delay.h>
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "CLCD_Config.h"
#include "CLCD_Private.h"
#include "CLCD_Interface.h"


void CLCD_VoidInit(void)
{
	/*wait for mare than 30ms*/
	_delay_ms(40);
	/*Function Set 2 lines & 5*8 font size*/
	CLCD_VoidSendCommand(FunctionSet);
	/*display on/off control:display enable ,disable cursor,no blink cursor*/
	CLCD_VoidSendCommand(DisplayON);
	/*clear display*/
	CLCD_VoidSendCommand(DisplayCLEAR);

}
void CLCD_VoidSendCommand(u8 Copy_u8Command)
{
	DIO_VoidSetPinValue(CLCD_CTRL_PORT,CLCD_RS,DIO_u8PIN_LOW);
	DIO_VoidSetPinValue(CLCD_CTRL_PORT,CLCD_RW,DIO_u8PIN_LOW);
	DIO_VoidSetPortValue(CLCD_DATA_PORT,Copy_u8Command);
	DIO_VoidSetPinValue(CLCD_CTRL_PORT,CLCD_E,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_VoidSetPinValue(CLCD_CTRL_PORT,CLCD_E,DIO_u8PIN_LOW);
}
void CLCD_VoidSendData(u8 Copy_u8Data)
{
	DIO_VoidSetPinValue(CLCD_CTRL_PORT,CLCD_RS,DIO_u8PIN_HIGH);
	DIO_VoidSetPinValue(CLCD_CTRL_PORT,CLCD_RW,DIO_u8PIN_LOW);
	DIO_VoidSetPortValue(CLCD_DATA_PORT,Copy_u8Data);
	DIO_VoidSetPinValue(CLCD_CTRL_PORT,CLCD_E,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_VoidSetPinValue(CLCD_CTRL_PORT,CLCD_E,DIO_u8PIN_LOW);
}
void CLCD_VoidSendString(const char* Copy_pcString)
{
	u8 Local_u8Counter=0;
	while(Copy_pcString[Local_u8Counter]!='\0')
	{
		CLCD_VoidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}
void CLCD_VoidSendStringSinWave(const char* Copy_pcString)
{
	u8 Local_u8Counter=0;
	u8 Local_u8Xpos=0;
	u8 Local_u8Ypos=0;
	while(Copy_pcString[Local_u8Counter]!='\0')
	{
		CLCD_VoidGoToXY(Local_u8Xpos,Local_u8Ypos);
		CLCD_VoidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
		Local_u8Ypos++;
		Local_u8Xpos=!Local_u8Xpos;
	}
}
void CLCD_VoidGoToXY(u8 Copy_u8Xposition,u8 Copy_u8Yposition)
{
	u8 Local_u8Address;
	if(Copy_u8Xposition==0)
	{
		Local_u8Address=Copy_u8Yposition;
	}else if(Copy_u8Xposition==1)
	{
		Local_u8Address=Copy_u8Yposition+0x40;
	}
	CLCD_VoidSendCommand(Local_u8Address+128);
}

void CLCD_VoidWriteSpecialCharacter(u8* Copy_pu8pattern,u8 Copy_u8PatternNum,u8 Copy_u8Xpos,u8 Copy_u8Ypos)
{
	/*calculate the CGRAM address whose each block is 8 bytes*/
	u8 Local_u8CGRAMAddress=Copy_u8PatternNum*8,Local_u8Iterator;
	/*send CGRAM address command to lcd, sitting bit 6 and clearing bit 7*/
	CLCD_VoidSendCommand(Local_u8CGRAMAddress+64);
	/*writing the pattern into CG RAM*/
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		CLCD_VoidSendData(Copy_pu8pattern[Local_u8Iterator]);
	}
	/*go back to DDRAM to display pattern*/
	CLCD_VoidGoToXY(Copy_u8Xpos, Copy_u8Ypos);
	/*display pattern written in the CG RAM*/
	CLCD_VoidSendData(Copy_u8PatternNum);
}


void CLCD_VoidSendNumber(s32 Copy_s32Number)
{
	u32 Local_u32Counter=1;
	u8  Local_u8Digit=0;
	if(Copy_s32Number<0)
	{
		CLCD_VoidSendData('-');
		Copy_s32Number=-Copy_s32Number;
	}
	if(Copy_s32Number==0)
	{
		CLCD_VoidSendData('0');
	}
	else
	{
		while(Copy_s32Number/Local_u32Counter!=0)
		{
			Local_u32Counter*=10;
		}
		Local_u32Counter/=10;
		while(Local_u32Counter!=0)
		{
			Local_u8Digit=Copy_s32Number/Local_u32Counter;
			CLCD_VoidSendData(Local_u8Digit+'0');
			Copy_s32Number=Copy_s32Number%Local_u32Counter;
			Local_u32Counter/=10;
		}
	}
}

void CLCD_VoidClearDisplay(void)
{
	CLCD_VoidSendCommand(DisplayCLEAR);
}
