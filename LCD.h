/*
 * LCD.h
 *
 * Created: 1/5/2022 1:24:03 PM
 *  Author: master
 */ 


#ifndef LCD_H_
#define LCD_H_


/*******************************Inclutions**************************************/
#include "STD_TYPES.h"
/*******************************************************************************/
/******************************Macros*******************************************/
#define _4_BIT_MODE         4
#define _8_BIT_MODE         8
/*******************************************************************************/
/**********************************Prototypes***********************************/
void LCD_INIT(void);
void LCD_WRITE_CHR(u8);
void LCD_WRITE_CMD(u8);
void LCD_WRITE_STR(u8 *p);
void LCD_CLR  (void);
void LCD_WRITE_INT(u32);
void LCD_GO_TO(u8 ,u8);
void LCD_String_xy (u8, u8,u8 *str);
/*******************************************************************************/

#endif /* LCD_H_ */