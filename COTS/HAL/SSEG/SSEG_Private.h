/************************************************************************/
/* SWC			: Seven Segment Driver									*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Seven Segment Display							*/
/************************************************************************/


#ifndef SSEG_PRIVATE_H
#define SSEG_PRIVATE_H


/*Private Macros*/
	/*Mapped Outputs for the Seven Segment Display LEDs*/
		/*No Dots*/
#define CLEAR               0b00000000
#define ZERO		        0b00111111
#define ONE			        0b00000110
#define TWO			        0b01011011
#define THREE		        0b01001111
#define FOUR		        0b01100110
#define FIVE		        0b01101101
#define SIX			        0b01111101
#define SEVEN		        0b00000111
#define EIGHT		        0b01111111
#define NINE		        0b01101111

		/*Dots*/
#define DOT					0b10000000
#define ZERO_DOT		    0b10111111
#define ONE_DOT			    0b10000110
#define TWO_DOT		        0b11011011
#define THREE_DOT		    0b11001111
#define FOUR_DOT		    0b11100110
#define FIVE_DOT	        0b11101101
#define SIX_DOT		        0b11111101
#define SEVEN_DOT		    0b10000111
#define EIGHT_DOT		    0b11111111
#define NINE_DOT		    0b11101111
/*__________________________________________________________________________________________________________________________________________*/


/*Private Global Variables Definitions*/
	/*Arrays of Seven Segment Output Numbers*/
static u8 Glob_u8Num[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
static u8 Glob_u8NumwDot[10] = {ZERO_DOT, ONE_DOT, TWO_DOT, THREE_DOT, FOUR_DOT, FIVE_DOT, SIX_DOT, SEVEN_DOT, EIGHT_DOT, NINE_DOT};
static u8 Glob_u8Peripheral[3]={PERIPHERAL_GPIOA, PERIPHERAL_GPIOB, PERIPHERAL_GPIOC};
/*__________________________________________________________________________________________________________________________________________*/


/*Private Functions Declarations*/
/* 
 * Func. Name	: SSEG_errWriteLeds
 * Description	: This function is used by the module to write set/rst LEDs in the display as needed
 * I/p Argument	: Inptr_SSEG_ConfigStruct
 * I/p Argument	: Copy_u8LedArray
 * Return		: Error status of function
 */
static ErrorStatus SSEG_errWriteLeds(const SSEG_ConfigStruct* Inptr_SSEG_ConfigStruct, u8 Copy_u8LedArray);

/* 
 * Func. Name	: SSEG_errInitHelper
 * Description	: This function is used by the module to initialize the common of the display
 * I/p Argument	: Inptr_SSEG_ConfigStruct
 * I/p Argument	: Copy_u8LedArray
 * Return		: Error status of function
 */
static ErrorStatus SSEG_errInitCommon(const SSEG_ConfigStruct* Inptr_SSEG_ConfigStruct);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*SSEG_PRIVATE_H*/
