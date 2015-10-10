/*
 * pc_Screen.h
 * It's built upon UART driver,so configure BAUD Rate,and other configuration in uart.h 
 * Created: 10/6/2015 9:48:41 PM
 *  Author: Yahia
 */ 


#ifndef PC_SCREEN_H_
#define PC_SCREEN_H_

#include "uart.h" /*must be included*/
#include "Extensions.h"

#define  DEL_Key 127
#define  EnterKey 13
#define  SpaceKey 32

#define pc_screenInit() UART_init()
#define pc_displayCharacter(data) UART_sendByte(data)
#define pc_displayString(str) UART_sendString(str)
#define pc_clearScreen() UART_sendByte(DEL_Key)
#define pc_newLine() UART_sendByte(EnterKey);

extern void pc_goToRowColumn(uint8 row,uint8 col);
extern void pc_sendInt(uint8 a_number);




#endif /* PC_SCREEN_H_ */