/*
 * watchdog.h
 *
 * Created: 10/2/2015 11:17:31 AM
 *  Author: Yahia
 */ 


#ifndef WATCHDOG_H_
#define WATCHDOG_H_

#include <avr/io.h>

/*Define Timeout reset action by a_WDP2,a_WDP1,a_WDP0 */
#define watch_dog_Enable(a_WDP2,a_WDP1,a_WDP0) WDTCR=((1<<WDE)|(a_WDP2<<WDP2)|(a_WDP1<<WDP1)|(a_WDP0<<WDP0))

/*Disable watch dog timer*/
#define watch_dog_Disable {WDTCR |= (1<<WDTOE) | (1<<WDE); WDTCR = 0x00;} /*from the datasheet*/
	
/*
  Execute a certain function in case of The TimeOut.
  In case another parameters needed in the function call ,just change the function pointer definition 
  here and in .c file.
  @this function is not called automatically when the reset happens ,you should placed it in the start
  @of the main program.
 
*/
extern void watch_dog_TimeOutAction(void (*FunctionPtr)(void));

#endif /* WATCHDOG_H_ */