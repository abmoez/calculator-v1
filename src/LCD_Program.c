/*
 * LCD_Program.c
 *
 *  Created on: 20 Aug 2023
 *      Author: abmoez
 */

#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"Dio_Interface.h"
#include"LCD.CONFIG.h"
#include"LCD_INTERFACE.h"
#include<util/delay.h>

void CLCD_voidSendCommand(u8 copy_u8command){

	/*SET RS Pin to low for command*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,Pinlow);

	/*SET RW to low for Write*/
    DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,Pinlow);

    /*Set command to data pins*/
    DIO_VidSetPortValue(CLCD_DATA_PORT,copy_u8command);

    /*Set Enable Pulse*/
    DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,PinHigh);

    _delay_ms(2);

    DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,Pinlow);
}

void CLCD_voidSendData(u8 copy_u8Data){

	/*SET RS Pin to high for command*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,PinHigh);

	/*SET Rw Pin to low for command*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,Pinlow);

	/*Set command to data pins*/
	DIO_VidSetPortValue(CLCD_DATA_PORT,copy_u8Data);

	/*Set Enable Pulse*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,PinHigh);

	_delay_ms(2);

	/*Set Enable Pulse*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,Pinlow);
}

void CLCD_voidInit(void){

	DIO_VidSetPortDirection(CLCD_DATA_PORT,Output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,Output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,Output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_E_PIN,Output);

	/*wait for more than 30ms*/
	_delay_ms(40);

	/*Function set command:2 lines,5*8 Font size*/
	CLCD_voidSendCommand(0b00111000);


	/*Display on off control:display enable,disaple cursor,no blink cursor*/
	CLCD_voidSendCommand(0b00001100);

	/*Clear display*/
	CLCD_voidSendCommand(1);
}
void LCD_voidSendString(unsigned char*ptr)
{
	while(*ptr!='\0')
	{
		CLCD_voidSendData(*ptr);
		ptr++;
	}
}

void LCD_voidClear(void){
	CLCD_voidSendCommand(1);
}
void LCD_voidSendNumber(int num){
	char st[16];
	itoa(num,st,10);
	LCD_voidSendString(st);
}

void LCD_voidSendChar(char a)
{
	CLCD_voidSendData(a);
}
