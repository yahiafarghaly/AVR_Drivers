/*
 * pc_Screen.c
 *
 * Created: 10/6/2015 9:48:15 PM
 *  Author: Yahia
 */ 
#include "pc_Screen.h"

void pc_goToRowColumn(uint8 row,uint8 col)
{
	uint8 index=0;
	
	for(index=0;index<row;index++)
			UART_sendByte(EnterKey);
	for (index=0;index<col;index++)
			UART_sendByte(SpaceKey);
			
}

void pc_sendInt(uint8 a_number)
{
	char buff[16];
	itoa(a_number,buff,10);
	UART_sendString(buff);
}