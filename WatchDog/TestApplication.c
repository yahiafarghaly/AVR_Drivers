/*
 * GccApplication1.c
 *
 * Created: 10/2/2015 11:12:12 AM
 *  Author: Yahia
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include "util/delay.h"
#include "Extensions.h"
#include "watchdog.h"

void LightLed(void)
{
	DDRC|=(1<<PC0);
	SET_BIT(PORTC,PC0);
	_delay_ms(2000);
	CLEAR_BIT(PORTC,PC0);
}

int main(void)
{
	watch_dog_TimeOutAction(LightLed);
	DDRA|=(1<<PA0);	
	watch_dog_Enable(1,1,1);
	
    while(1)
    {
		TOGGLE_BIT(PORTA,PA0);
		_delay_ms(300);
        
    }
}