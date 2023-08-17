/************************************************************************/
/* SWC			: Seven Segment Driver									*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Seven Segment Display							*/
/************************************************************************/


#ifndef SSEG_INTERFACE_H
#define SSEG_INTERFACE_H


/*Public Macros*/
	/*Dot Options*/
#define DOT_OFF		(0u)
#define DOT_ON		(1u)

	/*Types of Seven Segment*/
#define SSEG_COMM_CATHODE		(0u)
#define SSEG_COMM_ANODE			(1u)

	/*Ports*/
#define GPIO_PORT_A						GPIO_PORT_A
#define GPIO_PORT_B						GPIO_PORT_B
#define GPIO_PORT_C						GPIO_PORT_C
#define COMM_CONNECTED_EXTERNALLY		GPIO_NOT_A_PORT

	/*Pins*/
#define SSEG_PIN_0			GPIO_PIN_0
#define SSEG_PIN_1			GPIO_PIN_1
#define SSEG_PIN_2			GPIO_PIN_2
#define SSEG_PIN_3			GPIO_PIN_3
#define SSEG_PIN_4			GPIO_PIN_4
#define SSEG_PIN_5			GPIO_PIN_5
#define SSEG_PIN_6			GPIO_PIN_6
#define SSEG_PIN_7			GPIO_PIN_7
#define SSEG_PIN_8			GPIO_PIN_8
#define SSEG_PIN_9			GPIO_PIN_9
#define SSEG_PIN_10			GPIO_PIN_10
#define SSEG_PIN_11			GPIO_PIN_11
#define SSEG_PIN_12			GPIO_PIN_12
#define SSEG_PIN_13			GPIO_PIN_13
#define SSEG_PIN_14			GPIO_PIN_14
#define SSEG_PIN_15			GPIO_PIN_15
/*__________________________________________________________________________________________________________________________________________*/


/*Seven Segment Configuration Structure*/
typedef struct{
	u8 Loc_u8SEGPort;	/*The port the seven segment is connected to.			Options: GPIO_PORT_A -> GPIO_PORT_C*/
	u8 Loc_u8Type;		/*Type of seven segment.								Options: SSEG_COMM_CATHODE, SSEG_COMM_ANODE, COMM_CONNECTED_EXTERNALLY*/
	u8 Loc_u8CommPort;	/*The port the seven segment common is connected to.	Options: GPIO_PORT_A -> GPIO_PORT_C*/
	u8 Loc_u8CommPin;	/*The pin the seven segment common is connected to.		Options: SSEG_PIN_0 -> SSEG_PIN_15*/
}SSEG_ConfigStruct;
/*__________________________________________________________________________________________________________________________________________*/


#endif /*SSEG_INTERFACE_H*/
