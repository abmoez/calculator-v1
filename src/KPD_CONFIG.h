/*
 * KPD_CONFIG.h
 *
 *  Created on: Aug 21, 2023
 *      Author: abmoez
 */

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_PORT 			PORT_D

#define KPD_NO_PRESSED_KEY 		0xff

#define KPD_COLUMN_0 		PIN_0
#define KPD_COLUMN_1 		PIN_1
#define KPD_COLUMN_2 		PIN_2
#define KPD_COLUMN_3 		PIN_3

#define KPD_ROW_0 			PIN_4
#define KPD_ROW_1 			PIN_5
#define KPD_ROW_2 			PIN_6
#define KPD_ROW_3	 		PIN_7

#define COLUMN_NUM 			4
#define ROW_NUM 			4

#define KPD_ARR_VAL			{{7,8,9,'/'},{4,5,6,'x'},{1,2,3,'-'},{'%','0','=','+'}}

#endif /* KPD_CONFIG_H_ */
