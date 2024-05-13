#ifndef		CLCD_INTERFACE_H_
#define		CLCD_INTERFACE_H_

void CLCD_VoidInit(void);
void CLCD_VoidSendCommand(u8 Copy_u8Command);
void CLCD_VoidSendData(u8 Copy_u8Data);
void CLCD_VoidSendString(const char* string);
void CLCD_VoidGoToXY(u8 Copy_u8Xposition,u8 Copy_u8Yposition);
void CLCD_VoidSendStringSinWave(const char* Copy_pcString);
void CLCD_VoidWriteSpecialCharacter(u8* Copy_pu8pattern,u8 Copy_u8PatternNum,u8 Copy_u8Xpos,u8 Copy_u8Ypos);
void CLCD_VoidSendNumber(s32 Copy_s32Number);
void CLCD_VoidClearDisplay(void);

#endif
