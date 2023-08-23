/*
 * LCD_INTERFACE.h
 *
 *  Created on: 20 Aug 2023
 *      Author: abmoez
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void CLCD_voidSendCommand(u8 copy_u8command);

void CLCD_voidSendData(u8 copy_u8Data);

void CLCD_voidInit(void);

void LCD_voidSendString(unsigned char*ptr);

void LCD_voidClear(void);

void LCD_voidSendNumber(int num);

void LCD_voidSendChar(char a);

#endif /* LCD_INTERFACE_H_ */
