/************************************************************************/
/* SWC			: Seven Segment Driver									*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Seven Segment Display							*/
/************************************************************************/


#ifndef SSEG_PRIVATE_H_
#define SSEG_PRIVATE_H_

#include "RCC_Interface.h"
#include "GPIO_Interface.h"

#include "SSEG_Config.h"
#include "SSEG_Interface.h"

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

#define ZERO_DOT		    0b10111111
#define ONE_DOT			    0b10000110
#define TWO_DOT		        0b11011011
#define THREE_DOT		    0b11001111
#define FOUR_DOT		    0b11100110
#define FIVE_DOT	        0b11101101
#define SIX_DOT		        0b11111101
#define SEVEN_DOT		    0b11000111
#define EIGHT_DOT		    0b11111111
#define NINE_DOT		    0b11101111

#define CLEAR               0x00

/*Arrays of Seven Segment Output Numbers*/
static u8 Loc_u8Num[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
static u8 Loc_u8NumwDOT[10] = {ZERO_DOT, ONE_DOT, TWO_DOT, THREE_DOT, FOUR_DOT, FIVE_DOT, SIX_DOT, SEVEN_DOT, EIGHT_DOT, NINE_DOT};
static u8 Loc_u8Prei[3]={PERIPHERAL_GPIOA, PERIPHERAL_GPIOB, PERIPHERAL_GPIOC};

/* 
 * Function	: SSEG_errWriteNum	: Turns on/off The appropriate LEDs in the SSEG based on the required number
 * Input1 	: Copy_u8Port		: Port where the Seven Segment is connected 
 * Input2 	: Copy_u8Number		: The number to display on the Seven Segment 
 * Return 	: 				    : Error Status of function
 */
ErrorStatus SSEG_errWriteNum(u8 Copy_u8Port, u8 Copy_u8Number);

#endif /*SSEG_PRIVATE_H_*/
