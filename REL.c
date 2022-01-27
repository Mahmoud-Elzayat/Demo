/*
 * REL.c
 *
 * Created: 1/4/2022 12:05:05 PM
 *  Author: master
 */ 
/*******************************Inclutions**************************************/
#include "REL.h"
#include "REL_CFG.h"
#include "DIO.h"
#include "STD_TYPES.h"
/*******************************************************************************/
/*******************************Functions***************************************/
void REL_INIT(u8 rel)
{
	switch (rel)
	{
		case REL_1:
		PIN_MODE(REL_1_PIN,OUTPUT);
		break;
		case REL_2:
		PIN_MODE(REL_2_PIN,OUTPUT);
		break;
		default:
		break;
	}
}
/*******************************************************************************/
void REL_ON(u8 rel)
{
	switch (rel)
	{
		case REL_1:
		PIN_WRITE(REL_1_PIN,HIGH);
		break;
		case REL_2:
		PIN_WRITE(REL_2_PIN,HIGH);
		break;
		default:
		break;
	}
}
/*******************************************************************************/
void REL_OFF(u8 rel)
{
	switch (rel)
	{
		case REL_1:
		PIN_WRITE(REL_1_PIN,LOW);
		break;
		case REL_2:
		PIN_WRITE(REL_2_PIN,LOW);
		break;
		default:
		break;
	}
}
/*******************************************************************************/
void REL_TOG(u8 REL)
{
	switch (REL)
	{
		case REL_1:
		PIN_TOG(REL_1_PIN);
		break;
		case REL_2:
		PIN_TOG(REL_2_PIN);
		break;
		default:
		break;
	}
}