/*
 * UART.c
 * Author: Yahia Farghaly
 */

#include "uart.h"

#if(Parity==0)
	#define PA_MODE ((0<<UPM1)|(0<<UPM0))
#elif(parity==1)
	#define PA_MODE ((1<<UPM1)|(0<<UPM0))
#elif(parity==11)
	#define PA_MODE ((1<<UPM1)|(1<<UPM0))
#endif

#if(DataWidth_in_bits==8)
	#define SET_Communication_Bits ((1<<UCSZ0) | (1<<UCSZ1))
#elif(DataWidth_in_bits==9)
	#define SET_Communication_Bits ((1<<UCSZ0) | (1<<UCSZ1)|(1<<UCSZ2))
#endif

 #if(NumberOf_Stop_Bits==1)
	 #define stopBits (0<<USBS)
 #else
	 #define stopBits (1<<USBS)
 #endif
 
void UART_init(void)
{
	UCSRA = (UART_TRANSIMMISION_SPEED<<U2X)|(Multi_processor_communication_mode<<MPCM);
	
	UCSRB = (Transmitter_Enable<<RXEN) | (Receiver_Enable<<TXEN);
#ifdef UART_INTERRUPT
	UCSRB = (RX_COMPLETE_INT<<RXCIE)|(TX_COMPLETE_INT<<TXCIE)|(UDR_EMPTY_INT<<UDRIE);
#endif
UCSRC = (1<<URSEL) | (SET_Communication_Bits)|(Asynchronous_Operation<<UMSEL)|(PA_MODE)|(stopBits);
	
	/* baud rate=9600 & Fosc=1MHz -->  UBBR=( Fosc / (8 * baud rate) ) - 1 = 12 */  
	UBRRH = 0; /*To set URSEL to 0 also to be able to write on that register*/
	UBRRL = UBBR_Value;
}
	
void UART_sendByte(const uint8 data)
{
	/* UDRE flag is set when the Tx buffer (UDR) is empty and ready for 
	 * transmitting a new byte so wait until this flag is set to one */
	while(BIT_IS_CLEAR(UCSRA,UDRE)){}
	/* Put the required data in the UDR register and it also clear the UDRE flag as 
	 * the UDR register is not empty now */	 
	UDR = data;
	/************************* Another Method *************************
	UDR = data;
	while(BIT_IS_CLEAR(UCSRA,TXC)){} // Wait until the transimission is complete TXC = 1
	SET_BIT(UCSRA,TXC); // Clear the TXC flag as not ISR is not defined
	*******************************************************************/	
}

uint8 UART_recieveByte(void)
{
	/* RXC flag is set when the UART receive data so wait until this 
	 * flag is set to one */
	while(BIT_IS_CLEAR(UCSRA,RXC)){}
	/* Read the received data from the Rx buffer (UDR) and the RXC flag 
	   will be cleared after read this data */	 
    return UDR;		
}

void UART_sendString(const uint8 *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}
	/************************* Another Method *************************
	while(*Str != '\0')
	{
		UART_sendByte(*Str);
		Str++;
	}		
	*******************************************************************/
}

void UART_receiveString(uint8 *Str)
{
	uint8 i = 0;
	Str[i] = UART_recieveByte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_recieveByte();
	}
	Str[i] = '\0';
}
