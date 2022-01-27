/*
 * LCD_CFG.h
 *
 * Created: 1/5/2022 1:24:22 PM
 *  Author: master
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/*******************************Modes Options***********************************/
#define LCD_MODE  _4_BIT_MODE
/*******************************************************************************/
/******************************Macros*******************************************/
//#define LCD_DATA_PIN_0  PB0
//#define LCD_DATA_PIN_1  PB1
//#define LCD_DATA_PIN_2  PB2
//#define LCD_DATA_PIN_3  PB3

#define LCD_DATA_PIN_4	PA3
#define LCD_DATA_PIN_5	PA4
#define LCD_DATA_PIN_6	PA5
#define LCD_DATA_PIN_7	PA6
#define LCD_RS_PIN      PA1
#define LCD_EN_PIN      PA2


//another kit
/*
#define LCD_DATA_PIN_4	PA4
#define LCD_DATA_PIN_5	PA5
#define LCD_DATA_PIN_6	PA6
#define LCD_DATA_PIN_7	PA7
#define LCD_RS_PIN      PB1
#define LCD_RW_PIN      PB2
#define LCD_EN_PIN      PB3
*/

#define LCD_DATA_PORT   A
/*******************************************************************************/


#endif /* LCD_CFG_H_ */