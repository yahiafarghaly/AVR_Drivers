/*
 * UART.h
 * 
 * This is UART Configuration File
 * The file is set to work with asynchronous communication of 8 bits char size with no interrupts,
 * and double transmission speed with Baud rate of 9600 @F_CPU =1MHz
 * Methods for 9 bits send/receive should be added in .c file,but the registers set for 9 bits 
 * can be already configured within this file.
 * The Synchronous configuration is not set here. 
 * 8 Bits is the standard and safer width for communications
 *
 * Author: Yahia Farghaly
 */  

#ifndef UART_H_
#define UART_H_

#include "micro_config.h"
#include "Extensions.h"

/*Main Setting and GoTo each configuration individually*/
/*1 for enable,0 for not*/

/**************UCSRA Configuration**********************/

#define UART_TRANSIMMISION_SPEED 1
/*1 for Double the transferring rate for asynchronous communication
 * 0 for normal mode 
 */
#define Multi_processor_communication_mode 0
 /*End UCSRA Configuration */
 
/**************UCSRB Configuration**********************/

#define Transmitter_Enable 1
#define Receiver_Enable 1 

/*UART Interrupts configurations*/
#undef UART_INTERRUPT
#ifdef UART_INTERRUPT
	#define RX_COMPLETE_INT 0
	#define TX_COMPLETE_INT 0
	#define UDR_EMPTY_INT 0 
/*IF UDR IS EMPTY, IT WILL GENERATE AN INTERRUPT*/
#endif
 /*End UCSRB Configuration */
/**************UCSRC Configuration**********************/

/*8 and 9 is allowed*/
#define DataWidth_in_bits 8 
/*1 for Synchronous*/
#define Asynchronous_Operation  0
/*Set in case of Parity(0=>Disable parity bit,1=>Even,11=>Odd)*/
#define Parity 0
/*1 or 2 stop bits are allowed*/
#define NumberOf_Stop_Bits 1
/*End UCSRC Configuration */

#define UBBR_Value 12
/*Remember that UBBR value is depend on
 *F_CPU and Baud rate
 *so review the table in the "examples of baud rates" section in UART section
 *of AVR DataSheet
baud rate=9600 & Fosc=1MHz -->  UBBR=( Fosc / (8 * baud rate) ) - 1 = 12 */


void UART_init(void);

void UART_sendByte(const uint8 data);

uint8 UART_recieveByte(void);

void UART_sendString(const uint8 *Str);

void UART_receiveString(uint8 *Str); // Receive until #

#endif /* UART_H_ */
