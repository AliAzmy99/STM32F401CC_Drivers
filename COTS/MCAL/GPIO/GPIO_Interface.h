/************************************************************************/
/* SWC			: GPIO Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for General-Purpose I/Os							*/
/************************************************************************/


#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


/*Public Macros*/
	/*Port ID Options*/
#define GPIO_PORT_A		(0u)
#define GPIO_PORT_B		(1u)
#define GPIO_PORT_C		(2u)
#define GPIO_NOT_A_PORT (3u)

	/*Pin ID Options*/
#define GPIO_PIN_0		(0u)
#define GPIO_PIN_1		(1u)
#define GPIO_PIN_2		(2u)
#define GPIO_PIN_3		(3u)
#define GPIO_PIN_4		(4u)
#define GPIO_PIN_5		(5u)
#define GPIO_PIN_6		(6u)
#define GPIO_PIN_7		(7u)
#define GPIO_PIN_8		(8u)
#define GPIO_PIN_9		(9u)
#define GPIO_PIN_10		(10u)
#define GPIO_PIN_11		(11u)
#define GPIO_PIN_12		(12u)
#define GPIO_PIN_13		(13u)
#define GPIO_PIN_14		(14u)
#define GPIO_PIN_15		(15u)

	/*Mode ID Options*/
#define GPIO_MODE_INPUT		(0u)	/*Input mode*/
#define GPIO_MODE_OUTPUT	(1u)	/*Output mode*/
#define GPIO_MODE_ALT_FUN	(2u)	/*Alternate function mode*/
#define GPIO_MODE_ANALOG	(3u)	/*Analog mode*/

	/*Output Type ID Options*/
#define GPIO_OUTPUT_TYPE_PP		(0u)	/*Output push-pull*/
#define GPIO_OUTPUT_TYPE_OD		(1u)	/*Output open-drain*/

	/*Output Speed ID Options*/
#define GPIO_OUTPUT_SPEED_L		(0u)	/*Low speed*/
#define GPIO_OUTPUT_SPEED_M		(1u)	/*Medium speed*/
#define GPIO_OUTPUT_SPEED_H		(2u)	/*High speed*/
#define GPIO_OUTPUT_SPEED_VH	(3u)	/*Very High speed*/

	/*Pull State ID Options*/
#define GPIO_NO_PULL		(0u)	/*No pull (floating)*/
#define GPIO_PULL_UP		(1u)	/*Pull-up*/
#define GPIO_PULL_DOWN		(2u)	/*Pull-down*/

	/*Value ID Options*/
#define GPIO_VALUE_L		(0u)	/*Low value*/
#define GPIO_VALUE_H		(1u)	/*High vale*/

	/*Action ID Options*/
#define GPIO_SET		(0u)	/*Set*/
#define GPIO_RST		(1u)	/*Reset*/
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: GPIO_errSetPinMode
 * Description	: This function allows the user to select the mode of the mode of any pin
 * I/p Argument	: Copy_u8Port		Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument	: Copy_u8Pin		Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument	: Copy_u8PinMode	Options: GPIO_MODE_INPUT, GPIO_MODE_OUTPUT, GPIO_MODE_ALT_FUN, GPIO_MODE_ANALOG
 * Return		: Error status of function
 */
ErrorStatus GPIO_errSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinMode);

/* 
 * Func. Name	: GPIO_errSetPinOutputType
 * Description	: This function allows the user to select the output type of any pin
 * I/p Argument	: Copy_u8Port			Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument	: Copy_u8Pin			Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument	: Copy_u8PinOutputType	Options: GPIO_OUTPUT_TYPE_PP, GPIO_OUTPUT_TYPE_OD
 * Return		: Error status of function
 */
ErrorStatus GPIO_errSetPinOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutputType);

/* 
 * Func. Name	: GPIO_errSetPinOutputSpeed
 * Description	: This function allows the user to select the output speed of any pin
 * I/p Argument	: Copy_u8Port					Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument	: Copy_u8Pin					Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument	: GPIO_errSetPinOutputSpeed		Options: GPIO_OUTPUT_SPEED_L -> GPIO_OUTPUT_SPEED_VH
 * Return		: Error status of function
 */
ErrorStatus GPIO_errSetPinOutputSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutputSpeed);

/* 
 * Func. Name	: GPIO_errSetPinPullState
 * Description	: This function allows the user to select the pull state of any pin
 * I/p Argument	: Copy_u8Port			Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument	: Copy_u8Pin			Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument	: Copy_u8PinPullState	Options: GPIO_NO_PULL, GPIO_PULL_UP, GPIO_PULL_DOWN
 * Return		: Error status of function
 */
ErrorStatus GPIO_errSetPinPullState(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinPullState);

/* 
 * Func. Name	: GPIO_errSetPinValue
 * Description	: This function allows the user to set the value of any pin
 * I/p Argument	: Copy_u8Port		Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument	: Copy_u8Pin		Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument	: Copy_u8PinValue	Options: GPIO_VALUE_L, GPIO_VALUE_H
 * Return		: Error status of function
 */
ErrorStatus GPIO_errSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue);

/* 
 * Func. Name	: GPIO_errSetPinValueDirectAccess
 * Description	: This function allows the user to set/reset any pin using direct access
 * I/p Argument	: Copy_u8Port		Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument	: Copy_u8Pin		Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument	: Copy_u8PinAction	Options: GPIO_SET, GPIO_RST
 * Return		: Error status of function
 */
ErrorStatus GPIO_errSetPinValueDirectAccess(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinAction);

/* 
 * Func. Name	: GPIO_errGetPinValue
 * Description	: This function allows the user to get the value of any pin
 * I/p Argument	: Copy_u8Port			Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument	: Copy_u8Pin			Options: GPIO_PIN_0 -> GPIO_PIN_15
 * O/p Argument : Outptr_u8PinValue		Options: GPIO_VALUE_L, GPIO_VALUE_H
 * Return		: Error status of function
 */
ErrorStatus GPIO_errGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Outptr_u8PinValue);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*GPIO_INTERFACE_H*/
