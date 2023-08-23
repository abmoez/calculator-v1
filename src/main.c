/*
 * main.c
 *
 *  Created on: 19 Aug 2023
 *      Author: abmoez
 */
#include<avr/io.h>
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"Dio_Interface.h"
#include"LCD.CONFIG.h"
#include"LCD_INTERFACE.h"
#include"KPD_INTERFACE.h"
#include<util/delay.h>

int main(){

	CLCD_voidInit();
	KPD_voidInit();
	LCD_voidClear();
	char op;
	u8 tot1, val1, tot2, val2, nxt;
	f32 res ;
	while(1)
	{
		tot1=0;
		tot2=0;
		val1 = KPD_u8GetPressedKey();
		while(val1==0xff || (val1!='+' && val1!='-' && val1!='x' && val1!='/'))
		{
			if (val1==0xff)
			{
				val1 = KPD_u8GetPressedKey();
				_delay_ms(50);
			}
			else
			{
				tot1*=10 ;
				tot1+=val1;
				LCD_voidSendNumber(val1);
				val1=0xff;
			}

		}


		op = (char)val1;
		LCD_voidSendChar(op);

		val2 = KPD_u8GetPressedKey();
		while(val2==0xff || val2!='=')
		{
			if (val2==0xff)
			{
				val2 = KPD_u8GetPressedKey();
				_delay_ms(50);
			}
			else
			{
				tot2*=10 ;
				tot2+=val2;
				LCD_voidSendNumber(val2);
				val2=0xff;
			}
		}


		switch(op)
		{
			case '+':
				res = tot1 + tot2 ;
				break ;
			case '-':
				res = tot1 - tot2;
				break;
			case 'x':
				res = tot1 * tot2;
				break;
			case '/':
				res = tot1 / tot2;
				break;
		}

		LCD_voidSendChar('=');


		LCD_voidSendNumber(res);

		nxt = KPD_u8GetPressedKey();
		while(nxt==0xff || nxt!='%')
		{
			nxt = KPD_u8GetPressedKey();
		}
		LCD_voidClear();

	}

	return 0;
}

