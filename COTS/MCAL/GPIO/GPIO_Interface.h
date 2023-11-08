/************************************************************************/
/* SWC			: GPIO Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for General-Purpose I/Os							*/
/************************************************************************/


#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*Types Definitions*/
	/*Port ID Type*/
typedef enum
{
	GPIO_PORT_A,
	GPIO_PORT_B,
	GPIO_PORT_C
}PortId_type;

	/*Pin ID Type*/
typedef enum
{
	GPIO_PIN_0,
	GPIO_PIN_1,
	GPIO_PIN_2,
	GPIO_PIN_3,
	GPIO_PIN_4,
	GPIO_PIN_5,
	GPIO_PIN_6,
	GPIO_PIN_7,
	GPIO_PIN_8,
	GPIO_PIN_9,
	GPIO_PIN_10,
	GPIO_PIN_11,
	GPIO_PIN_12,
	GPIO_PIN_13,
	GPIO_PIN_14,
	GPIO_PIN_15
}PinId_type;

	/*Pin Mode Type*/
typedef enum
{
	GPIO_INPUT,
	GPIO_OUTPUT,
	GPIO_ALTERNATE_FUNCTION,
	GPIO_ANALOG
}PinMode_type;

	/*Output Mode Type*/
typedef enum
{
	GPIO_PUSH_PULL,
	GPIO_OPEN_DRAIN
}OutputMode_type;

	/*Output Speed Type*/
typedef enum
{
	GPIO_LOW_SPEED,
	GPIO_MEDIUM_SPEED,
	GPIO_HIGH_SPEED,
	GPIO_VERY_HIGH_SPEED
}OutputSpeed_type;

	/*Pull State Type*/
typedef enum
{
	GPIO_FLOATING,
	GPIO_PULL_UP,
	GPIO_PULL_DOWN
}PullState_type;

	/*Alternative Function Type*/
typedef enum
{
	GPIO_AF_0,
	GPIO_AF_1,
	GPIO_AF_2,
	GPIO_AF_3,
	GPIO_AF_4,
	GPIO_AF_5,
	GPIO_AF_6,
	GPIO_AF_7,
	GPIO_AF_8,
	GPIO_AF_9,
	GPIO_AF_10,
	GPIO_AF_11,
	GPIO_AF_12,
	GPIO_AF_13,
	GPIO_AF_14,
	GPIO_AF_15
}AlternativeFunction_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: GPIO_vdSetPinMode
 * Description	: This function allows the user to select the mode of the mode of any pin
 * I/p Argument	: Copy_enmPortId
 * I/p Argument	: Copy_enmPinId
 * I/p Argument	: Copy_enmMode
 */
void GPIO_vdSetPinMode(PortId_type Copy_enmPortId, PinId_type Copy_enmPinId, PinMode_type Copy_enmMode);

/* 
 * Func. Name	: GPIO_vdSetPinOutputType
 * Description	: This function allows the user to select the output type of any pin
 * I/p Argument	: Copy_enmPortId
 * I/p Argument	: Copy_enmPinId
 * I/p Argument	: Copy_enmOutputMode
 */
void GPIO_vdSetPinOutputType(PortId_type Copy_enmPortId, PinId_type Copy_enmPinId, OutputMode_type Copy_enmOutputMode);

/* 
 * Func. Name	: GPIO_vdSetPinOutputSpeed
 * Description	: This function allows the user to select the output speed of any pin
 * I/p Argument	: Copy_enmPortId
 * I/p Argument	: Copy_enmPinId
 * I/p Argument	: GPIO_vdSetPinOutputSpeed
 */
void GPIO_vdSetPinOutputSpeed(PortId_type Copy_enmPortId, PinId_type Copy_enmPinId, OutputSpeed_type Copy_enmOutputSpeed);

/* 
 * Func. Name	: GPIO_vdSetPinPullState
 * Description	: This function allows the user to select the pull state of any pin
 * I/p Argument	: Copy_enmPortId
 * I/p Argument	: Copy_enmPinId
 * I/p Argument	: Copy_enmPullState
 */
void GPIO_vdSetPinPullState(PortId_type Copy_enmPortId, PinId_type Copy_enmPinId, PullState_type Copy_enmPullState);

/* 
 * Func. Name	: GPIO_vdSetPinValue
 * Description	: This function allows the user to set the value of any pin using direct access
 * I/p Argument	: Copy_enmPortId
 * I/p Argument	: Copy_enmPinId
 * I/p Argument	: Copy_enmValue
 */
void GPIO_vdSetPinValue(PortId_type Copy_enmPortId, PinId_type Copy_enmPinId, Value_type Copy_enmValue);

/* 
 * Func. Name	: GPIO_vdGetPinValue
 * Description	: This function allows the user to get the value of any pin
 * I/p Argument	: Copy_enmPortId
 * I/p Argument	: Copy_enmPinId
 * O/p Argument : Outptr_enmValue
 */
void GPIO_vdGetPinValue(PortId_type Copy_enmPortId, PinId_type Copy_enmPinId, Value_type* Outptr_enmPinValue);

/* 
 * Func. Name	: GPIO_vdSetAlternativeFunction
 * Description	: This function allows the user to set the alternative function of any pin
 * I/p Argument	: Copy_enmPortId
 * I/p Argument	: Copy_enmPinId
 * I/p Argument	: Copy_enmAltFunNum
 */
void GPIO_vdSetAlternativeFunction(PortId_type Copy_enmPortId, PinId_type Copy_enmPinId, AlternativeFunction_type Copy_enmAltFunNum);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*GPIO_INTERFACE_H*/
