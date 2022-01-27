/*
 * LCD.c
 *
 * Created: 1/5/2022 1:23:47 PM
 *  Author: master
 */ 
/*******************************Inclutions**************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "REG.h"
#include "LCD_CFG.h"
#include "LCD.h"

 #define  F_CPU 16000000UL
 #include "util/delay.h"
/*******************************************************************************/
/*******************************Functions***************************************/
void LCD_INIT(void)
{
	#if    LCD_MODE   ==    _8_BIT_MODE
	PORT_MODE(LCD_DATA_PORT,OUTPUT);
	//PIN_MODE(LCD_DATA_PIN_0,OUTPUT);
	//PIN_MODE(LCD_DATA_PIN_1,OUTPUT);
	//PIN_MODE(LCD_DATA_PIN_2,OUTPUT);
	//PIN_MODE(LCD_DATA_PIN_3,OUTPUT);
	//PIN_MODE(LCD_DATA_PIN_4,OUTPUT);
	//PIN_MODE(LCD_DATA_PIN_5,OUTPUT);
	//PIN_MODE(LCD_DATA_PIN_6,OUTPUT);
	//PIN_MODE(LCD_DATA_PIN_7,OUTPUT);
	PIN_MODE(LCD_RS_PIN,OUTPUT);
	PIN_MODE(LCD_EN_PIN,OUTPUT);
	
	LCD_WRITE_CMD(0X38);
	LCD_WRITE_CMD(0X0c);
	LCD_WRITE_CMD(0X01);
	LCD_WRITE_CMD(0X06);
	LCD_WRITE_CMD(0X02);
	
	#elif  LCD_MODE   ==    _4_BIT_MODE
	
	PIN_MODE(LCD_DATA_PIN_4,OUTPUT);
	PIN_MODE(LCD_DATA_PIN_5,OUTPUT);
	PIN_MODE(LCD_DATA_PIN_6,OUTPUT);
	PIN_MODE(LCD_DATA_PIN_7,OUTPUT);
	PIN_MODE(LCD_RS_PIN,OUTPUT);
	PIN_MODE(LCD_EN_PIN,OUTPUT);
	
	//PIN_MODE(LCD_RW_PIN,OUTPUT);
	//PIN_WRITE(LCD_RW_PIN,LOW);
	
	LCD_WRITE_CMD(0X33);
	LCD_WRITE_CMD(0X32);
	LCD_WRITE_CMD(0X28);
	LCD_WRITE_CMD(0X0c);
	LCD_WRITE_CMD(0X01);
	LCD_WRITE_CMD(0X06);
	LCD_WRITE_CMD(0X02);
	#endif	
}
/*******************************************************************************/
void LCD_WRITE_CHR(u8 character)
{
	PIN_WRITE(LCD_RS_PIN,HIGH);
	#if      LCD_MODE   ==    _8_BIT_MODE
	PORT_WRITE(LCD_DATA_PORT,character);
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(5);

	#elif    LCD_MODE   ==    _4_BIT_MODE
	//***SEND_FIRST_PART***/
	PORT_WRITE(LCD_DATA_PORT,(((character >> 1) & 0b01111000) | (PORT_READ(LCD_DATA_PORT) & 0b10000111)));
	PIN_WRITE(LCD_EN_PIN,HIGH);            
	_delay_ms(1);                          
	PIN_WRITE(LCD_EN_PIN,LOW);             
	_delay_ms(5); 
	
	/***SEND_LAST_PART***/
	PORT_WRITE(LCD_DATA_PORT,(((character << 3) & 0b01111000) | (PORT_READ(LCD_DATA_PORT) & 0b10000111)));
	PIN_WRITE(LCD_EN_PIN,HIGH);            
	_delay_ms(1);                          
	PIN_WRITE(LCD_EN_PIN,LOW);  
	_delay_ms(5);     
	      
	#endif
	
	//another kit
	/*
	#elif    LCD_MODE   ==    _4_BIT_MODE
	***SEND_FIRST_PART***
	PORT_WRITE(LCD_DATA_PORT,(((character) & 0b11110000) | (PORT_READ(LCD_DATA_PORT) & 0b00001111)));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(5);
	
	***SEND_LAST_PART***
	PORT_WRITE(LCD_DATA_PORT,(((character << 4) & 0b11110000) | (PORT_READ(LCD_DATA_PORT) & 0b00001111)));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#endif
	*/
}
/*******************************************************************************/
void LCD_WRITE_CMD(u8 command)
{
	PIN_WRITE(LCD_RS_PIN,LOW);            
	PIN_WRITE(LCD_EN_PIN,LOW);
	#if      LCD_MODE   ==    _8_BIT_MODE
	PORT_WRITE(LCD_DATA_PORT,command);
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(5);
	
	#elif    LCD_MODE   ==    _4_BIT_MODE
	/***SEND_FIRST_PART***/
	PORT_WRITE(LCD_DATA_PORT,(((command >> 1) & 0b01111000) | ( PORT_READ(LCD_DATA_PORT) & 0b10000111)));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(5);
	
	/***SEND_LAST_PART***/
	PORT_WRITE(LCD_DATA_PORT,(((command << 3) & 0b01111000) | ( PORT_READ(LCD_DATA_PORT) & 0b10000111)));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(5);
	
	#endif

	//another kit
	/*
	#elif    LCD_MODE   ==    _4_BIT_MODE
	***SEND_FIRST_PART***
	PORT_WRITE(LCD_DATA_PORT,(((command ) & 0b11110000) | ( PORT_READ(LCD_DATA_PORT) & 0b00001111)));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(5);
	
	***SEND_LAST_PART***
	PORT_WRITE(LCD_DATA_PORT,(((command << 4) & 0b11110000) | ( PORT_READ(LCD_DATA_PORT) & 0b00001111)));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	#endif
	*/
}
/*******************************************************************************/
void LCD_WRITE_STR (u8 *p)
{
	u8 i = 0;
	while (p[i] != '\0')
	{
		LCD_WRITE_CHR(p[i]);
		i++;
	}
}
/*******************************************************************************/
void LCD_CLR(void)
{
	LCD_WRITE_CMD(0X01);
}
/*******************************************************************************/
void LCD_WRITE_INT (u32 num)
{
	u32 rem = 0;
	u8 arr [16];//16 MAX NUMBER IN THIS LCD
	s8 i = 0;
	while(num != 0)//in with 125
	{
		rem = num % 10;
		arr[i] = rem + 48;//TO CONVERT NUMBER AS A ASCI
		i++;
		num = num / 10;
	}//out with {'5','2','1'} and i =3
	i--;// i = 2 to be last index ->1
	while(i > -1)
	{
		LCD_WRITE_CHR(arr[i]);
		i--;
	}
}
/*******************************************************************************/
void LCD_GO_TO(u8 row,u8 col)
{
	u8 Loc[2] = {0x80 , 0xC0};
	LCD_WRITE_CMD(Loc[row]+col);
}
/*******************************************************************************/
void LCD_String_xy (u8 row, u8 pos, u8 *str)	/* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
	LCD_WRITE_CMD((pos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LCD_WRITE_CMD((pos & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	LCD_WRITE_STR(str);		/* Call LCD string function */
}
