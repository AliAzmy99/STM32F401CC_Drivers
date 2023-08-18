/************************************************************************/
/* SWC			: Seven Segment Driver									*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Seven Segment Display							*/
/************************************************************************/


#ifndef SSEG_INTERFACE_H
#define SSEG_INTERFACE_H


/*Public Macros*/
	/*Dot State Options*/
#define SSEG_DOT_OFF	(0u)	/*Do Not Display Dot*/
#define SSEG_DOT_ON		(1u)	/*Display Dot*/

	/*Enable Options*/
#define SSEG_DISABLE	(0u)	/*Disable the Display*/
#define SSEG_ENABLE		(1u)	/*Enable the Display*/

	/*Seven Segment Type Options*/
#define SSEG_COMM_CATHODE		(0u)
#define SSEG_COMM_ANODE			(1u)

	/*Port Options*/
#define SSEG_PORT_A						GPIO_PORT_A
#define SSEG_PORT_B						GPIO_PORT_B
#define SSEG_PORT_C						GPIO_PORT_C
#define COMM_CONNECTED_EXTERNALLY		GPIO_NOT_A_PORT

	/*Pin Options*/
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

	/*Port Half Options*/
#define SSEG_FIRST_HALF		(0u)
#define SSEG_SECOND_HALF	(1u)
/*__________________________________________________________________________________________________________________________________________*/


/*Seven Segment Configuration Structure*/
typedef struct{
	u8 Loc_u8SegPort;
		/*The port the seven segment is connected to.					Options: SSEG_PORT_A -> SSEG_PORT_B*/
	u8 Loc_u8SegHalf;
		/*The half of the port that the seven segment is connected to.	Options: SSEG_FIRST_HALF -> SSEG_SECOND_HALF*/
	u8 Loc_u8Type;
		/*Type of seven segment.										Options: SSEG_COMM_CATHODE, SSEG_COMM_ANODE, COMM_CONNECTED_EXTERNALLY*/
	u8 Loc_u8CommPort;
		/*The port the seven segment common is connected to.			Options: SSEG_PORT_A -> SSEG_PORT_C*/
	u8 Loc_u8CommPin;
		/*The pin the seven segment common is connected to.				Options: SSEG_PIN_0 -> SSEG_PIN_15*/
}SSEG_ConfigStruct;
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: SSEG_errInit
 * Description	: This function allows the user to initialize the seven segment display
 * Note			: Connect the display pins A -> G to the MCU oins 0 -> 7 (FIRST_HALF) or 8 -> 15 (SECOND_HALF) respectivly
 * I/p Argument	: Inptr_SSEG_ConfigStruct
 * Return		: Error status of function
 */
ErrorStatus SSEG_errInit(const SSEG_ConfigStruct* Inptr_SSEG_ConfigStruct);

/* 
 * Func. Name	: SSEG_errDisplayNumber
 * Description	: This function allows the user to display a number on the seven segment display
 * I/p Argument	: Inptr_SSEG_ConfigStruct
 * I/p Argument	: Copy_u8Number				Options: 0 -> 9
 * I/p Argument	: Copy_u8DotState			Options: DOT_OFF, DOT_ON
 * Return		: Error status of function
 */
ErrorStatus SSEG_errDisplayNumber(const SSEG_ConfigStruct* Inptr_SSEG_ConfigStruct, u8 Copy_u8Number, u8 Copy_u8DotState);

/* 
 * Func. Name	: SSEG_errClear
 * Description	: This function allows the user to clear the seven segment display
 * I/p Argument	: Inptr_SSEG_ConfigStruct
 * Return		: Error status of function
 */
ErrorStatus SSEG_errClear(const SSEG_ConfigStruct* Inptr_SSEG_ConfigStruct);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*SSEG_INTERFACE_H*/
