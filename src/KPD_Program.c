/*
 * KPD_Program.c
 *
 *  Created on: Aug 21, 2023
 *      Author: abmoez
 */

#include "STD_TYPES.h"
#include "Dio_Interface.h"
#include "KPD_CONFIG.h"
#include "KPD_INTERFACE.h"
#include "util/delay.h"

void KPD_voidInit()
{
	DIO_VidSetPinDirection(KPD_PORT, KPD_COLUMN_0 ,Output);
	DIO_VidSetPinDirection(KPD_PORT, KPD_COLUMN_1 ,Output);
	DIO_VidSetPinDirection(KPD_PORT, KPD_COLUMN_2 ,Output);
	DIO_VidSetPinDirection(KPD_PORT, KPD_COLUMN_3 ,Output);

	DIO_VidSetPinValue(KPD_PORT, KPD_COLUMN_0, PinHigh);
	DIO_VidSetPinValue(KPD_PORT, KPD_COLUMN_1, PinHigh);
	DIO_VidSetPinValue(KPD_PORT, KPD_COLUMN_2, PinHigh);
	DIO_VidSetPinValue(KPD_PORT, KPD_COLUMN_3, PinHigh);

	DIO_VidSetPinDirection(KPD_PORT, KPD_ROW_0 ,Input);
	DIO_VidSetPinDirection(KPD_PORT, KPD_ROW_1 ,Input);
	DIO_VidSetPinDirection(KPD_PORT, KPD_ROW_2 ,Input);
	DIO_VidSetPinDirection(KPD_PORT, KPD_ROW_3 ,Input);

	DIO_VidSetPinValue(KPD_PORT, KPD_ROW_0, PinHigh);
	DIO_VidSetPinValue(KPD_PORT, KPD_ROW_1, PinHigh);
	DIO_VidSetPinValue(KPD_PORT, KPD_ROW_2, PinHigh);
	DIO_VidSetPinValue(KPD_PORT, KPD_ROW_3, PinHigh);

}


u8 KPD_u8GetPressedKey(void)
{
	/**************value if button was not pressed*******************/
	u8 Local_u8_Pressed_Key=KPD_NO_PRESSED_KEY;

	/*********************counter for (forloop)*********************/
	u8  Local_u8_Column_Counter,Local_u8_Row_Counter;

	/***************************variable for pin state**************************/
	u8  Local_u8_Pint_State;

	/********************KEY_PAD_VALUES*******************************/
   static u8 Local_u8_Kpd_Arr[ROW_NUM][COLUMN_NUM]=KPD_ARR_VAL;

    /********************KEY_COLUMN_Array*******************************/
   static u8 Local_u8_Kpd_Column_Array[COLUMN_NUM]={KPD_COLUMN_0,KPD_COLUMN_1,KPD_COLUMN_2,KPD_COLUMN_3};

    /********************KEY_ROWS_Array*******************************/
   static  u8 Local_u8_Kpd_Rows_Array[ROW_NUM]={KPD_ROW_0,KPD_ROW_1,KPD_ROW_2,KPD_ROW_3};



    for(Local_u8_Column_Counter=0;Local_u8_Column_Counter<COLUMN_NUM;Local_u8_Column_Counter++)
    {
    	/***************ACTIVATE CURRENT COLUMN*************************/

    	DIO_VidSetPinValue(KPD_PORT,Local_u8_Kpd_Column_Array[Local_u8_Column_Counter], Pinlow);

    	/**************READ CURRENT ROW*****************/
    	for(Local_u8_Row_Counter=0;Local_u8_Row_Counter<ROW_NUM;Local_u8_Row_Counter++)
    	{
    		DIO_VidGetPinValue(KPD_PORT,Local_u8_Kpd_Rows_Array[Local_u8_Row_Counter],&Local_u8_Pint_State);

             /******CHECK IF KEY IS PREESED********/

    		if(Local_u8_Pint_State==Pinlow)
    		{
    			Local_u8_Pressed_Key=Local_u8_Kpd_Arr[Local_u8_Row_Counter][Local_u8_Column_Counter];

    			while(Local_u8_Pint_State==Pinlow)
    			{
    				DIO_VidGetPinValue(KPD_PORT,Local_u8_Kpd_Rows_Array[Local_u8_Row_Counter],&Local_u8_Pint_State);
    			}
    			return Local_u8_Pressed_Key;
    		}
    	}
    	/********DEACTIVATE CURRENT COLUMN************/
    	DIO_VidSetPinValue(KPD_PORT,Local_u8_Kpd_Column_Array[Local_u8_Column_Counter],PinHigh);

    }

    return Local_u8_Pressed_Key;

}

