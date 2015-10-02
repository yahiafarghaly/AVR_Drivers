/*
 * watchdog.c
 *
 * Created: 10/2/2015 11:17:02 AM
 *  Author: Yahia
 */ 
#include "watchdog.h"

void inline watch_dog_TimeOutAction(void (*FunctionPtr)(void))
{

	if( MCUCSR & (1<<WDRF)) /*Check the Watchdog flag in case of timeout*/
		(*FunctionPtr)(); /*Calling the TimeOut Action*/
		
	MCUCSR&=~(1<<WDRF);	 /*Clean the WDRF flag*/
	
}