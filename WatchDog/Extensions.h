/*This file Contains helpful defined codes to get your job done quickly
  Author: Yahia Farghaly*/

#ifndef EXTENSIONS_H_
#define EXTENSIONS_H_

/*Data types*/
typedef unsigned char uint8;
typedef  signed char sint8;
typedef  unsigned short uint16;
typedef  signed short sint16;
typedef  unsigned long uint32;
typedef  signed long sint32;
typedef  unsigned long long uint64;
typedef  signed long long sint64;
typedef  unsigned char bool;
#define True 1
#define False 0

/*Quick Macros*/

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(sizeof(SREG)-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(sizeof(SREG)-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

/*Configure a pin to input and in pull up configuration,as AVR feature*/
#define PULL_UP_BIT(DDR_REG,PORT_REG,BIT) {CLEAR_BIT(DDR_REG,BIT);SET_BIT(PORT_REG,BIT);}

/*High state and low*/
#define HIGH 1
#define LOW  0			


#endif