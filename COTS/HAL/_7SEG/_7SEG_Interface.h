/************************************************************************/
/* SWC			: Seven Segment Driver									*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Seven Segment Display							*/
/************************************************************************/


#ifndef _7SEG_INTERFACE_H_
#define _7SEG_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MACROS.h"

/*MACROS*/
#define DOT_OFF	(0u)
#define DOT_ON	(1u)

/*Types of Seven Segment*/
#define _7SEG_Comm_CATHODE 		0
#define _7SEG_Comm_ANODE      	1

/*Ports and Pins Imported from GPIO*/
#define _7SEG_PortA 			GPIO_PORTA
#define _7SEG_PortB 			GPIO_PORTB
#define _7SEG_PortC 			GPIO_PORTC
#define Comm_Not_Connected	GPIO_NOT_A_PORT

#define _7SEG_Pin0 			GPIO_PIN0
#define _7SEG_Pin1 			GPIO_PIN1
#define _7SEG_Pin2 			GPIO_PIN2
#define _7SEG_Pin3 			GPIO_PIN3
#define _7SEG_Pin4 			GPIO_PIN4
#define _7SEG_Pin5 			GPIO_PIN5
#define _7SEG_Pin6 			GPIO_PIN6
#define _7SEG_Pin7 			GPIO_PIN7
#define _7SEG_Pin8 			GPIO_PIN8
#define _7SEG_Pin9 			GPIO_PIN9
#define _7SEG_Pin10 		GPIO_PIN10
#define _7SEG_Pin11 		GPIO_PIN11
#define _7SEG_Pin12 		GPIO_PIN12
#define _7SEG_Pin13 		GPIO_PIN13
#define _7SEG_Pin14 		GPIO_PIN14
#define _7SEG_Pin15 		GPIO_PIN15

/*Seven Segment Configuration Structure*/
typedef struct{
	u8 Loc_u8SEGPort;	/*The port the Seven Segment is connected to       ----- options: _7SEG_PortA,..,_7SEG_PortC*/
	u8 Loc_u8CommType;	/*Type of Seven Segment                            ----- options: _7SEG_Comm_CATHODE, _7SEG_Comm_ANODE*/
	u8 Loc_u8CommPort;	/*The port the Seven Segment Common is connected to----- options: _7SEG_PortA,..,_7SEG_PortC,Comm_Not_Connected*/
	u8 Loc_u8CommPin;	/*The pin the Seven Segment Common is connected to ----- options: _7SEG_Pin0,..,_7SEG_Pin15*/
}_7SEG_Config;


/*Function Declerations*/
/* 
 * Function	: _7SEG_esInit_7SEG			: Initialize the Seven Segment Display
 * Input1 	: copy__7SEGConfig_Input   : Configuration Structure of the Seven Segment to control
 * Return 	: 					        : Error Status of function
 */
ErrorStatus _7SEG_esInit_7SEG(_7SEG_Config copy__7SEGConfig_Input);

/* 
 * Function	: _7SEG_esSetNumber			: Displays a number on a Seven Segment Display
 * Input1 	: copy__7SEGConfig_Input  	: Configuration Structure of the Seven Segment to control
 * Input2 	: copy_u8Number			   	: Number to display on Seven Segment
 * Input3 	: copy_u8DOT_stat		   	: Whether or not to print the dot
 * Return 	: 					        : Error Status of function
 */
ErrorStatus _7SEG_esSetNumber(_7SEG_Config copy__7SEGConfig_Input, u8 copy_u8Number, u8 copy_u8DOT_stat);

/* 
 * Function	: _7SEG_esClrNumber			: Clears all LEDs on the Seven Segment
 * Input1 	: copy__7SEGConfig_Input  	: Configuration Structure of the Seven Segment to control
 * Return 	: 					        : Error Status of function
 */
ErrorStatus _7SEG_esClrNumber(_7SEG_Config copy__7SEGConfig_Input);

#endif /*_7SEG_INTERFACE_H_*/
