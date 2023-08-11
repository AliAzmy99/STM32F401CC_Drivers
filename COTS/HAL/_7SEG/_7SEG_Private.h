/************************************************************************/
/* SWC			: Seven Segment Driver									*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Seven Segment Display							*/
/************************************************************************/


#ifndef _7SEG_PRIVATE_H_
#define _7SEG_PRIVATE_H_

#include "RCC_Interface.h"
#include "GPIO_Interface.h"

#include "_7SEG_Config.h"
#include "_7SEG_Interface.h"

/*Macros*/
/*Numbers as output for the Seven segment Display*/
#define ZERO		        0b00111111
#define ONE			        0b00000110
#define TWO			        0b01011011
#define THREE		        0b01001111
#define FOUR		        0b01100110
#define FIVE		        0b01101101
#define SIX			        0b01111101
#define SEVEN		        0b01000111
#define EIGHT		        0b01111111
#define NINE		        0b01101111
#define DOT					0b10000000

#define ZEROwDOT		    0b10111111
#define ONEwDOT			    0b10000110
#define TWOwDOT		        0b11011011
#define THREEwDOT		    0b11001111
#define FOURwDOT		    0b11100110
#define FIVEwDOT	        0b11101101
#define SIXwDOT		        0b11111101
#define SEVENwDOT		    0b11000111
#define EIGHTwDOT		    0b11111111
#define NINEwDOT		    0b11101111

#define CLEAR               0x00

/*Arrays of Seven Segment Output Numbers*/
static u8 Loc_u8Num[10] = {ZERO , ONE , TWO , THREE , FOUR , FIVE , SIX , SEVEN , EIGHT , NINE };
static u8 Loc_u8NumwDOT[10] = {ZEROwDOT , ONEwDOT , TWOwDOT , THREEwDOT , FOURwDOT , FIVEwDOT , SIXwDOT , SEVENwDOT , EIGHTwDOT , NINEwDOT };
static u8 Loc_u8Prei[3]={PREI_GPIOA,PREI_GPIOB,PREI_GPIOC};

/* 
 * Function	: _7SEG_esWriteNum	: Turns on/off The appropriate LEDs in the _7SEG based on the required number
 * Input1 	: Copy_u8Port		: Port where the Seven Segment is connected 
 * Input2 	: Copy_u8Number		: The number to display on the Seven Segment 
 * Return 	: 				    : Error Status of function
 */
ErrorStatus _7SEG_esWriteNum(u8 Copy_u8Port, u8 Copy_u8Number);

#endif /*_7SEG_PRIVATE_H_*/
