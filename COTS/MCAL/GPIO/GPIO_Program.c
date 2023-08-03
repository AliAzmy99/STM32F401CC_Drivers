/************************************************************************/
/* SWC  	    : GPIO Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.1													*/
/* Description  : SWC for General-Purpose I/Os 							*/
/************************************************************************/


/*Include Needed Library Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

/*Include Needed Library Files*/
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
/* 
 * Func. Name   : GPIO_errSetPinMode
 * Description  : This function allows the user to select the mode of the mode of any pin
 * I/p Argument : Copy_u8PortId		Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument : Copy_u8PinId		Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument : Copy_u8PinMode	Options: GPIO_MODE_INPUT, GPIO_MODE_OUTPUT, GPIO_MODE_ALT_FUN, GPIO_MODE_ANALOG
 * Return 	    : Error status of function
 */
ErrorStatus GPIO_errSetPinMode(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinMode)
{
	volatile u32* Locptr_u32MODERxAddress = NULL;

	if ((GPIO_PORT_C == Copy_u8PortId && GPIO_PIN_13 > Copy_u8PinId) || GPIO_PIN_15 < Copy_u8PinId)
	{
		return INVALID_PARAMETERS;
	}

	switch (Copy_u8PortId)
	{
	case GPIO_PORT_A:
		Locptr_u32MODERxAddress = ((u32*) GPIOA_FIRST_ADDRESS) + GPIO_MODER_NO;
		break;
	case GPIO_PORT_B:
		Locptr_u32MODERxAddress = ((u32*) GPIOB_FIRST_ADDRESS) + GPIO_MODER_NO;
		break;
	case GPIO_PORT_C:
		Locptr_u32MODERxAddress = ((u32*) GPIOC_FIRST_ADDRESS) + GPIO_MODER_NO;
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}

	switch (Copy_u8PinMode)
	{
	case GPIO_MODE_INPUT:
		CLR_BIT(*Locptr_u32MODERxAddress, Copy_u8PinId << 1);
		CLR_BIT(*Locptr_u32MODERxAddress, (Copy_u8PinId << 1) + 1);
		break;
	case GPIO_MODE_OUTPUT:
		SET_BIT(*Locptr_u32MODERxAddress, Copy_u8PinId << 1);
		CLR_BIT(*Locptr_u32MODERxAddress, (Copy_u8PinId << 1) + 1);
		break;
	case GPIO_MODE_ALT_FUN:
		CLR_BIT(*Locptr_u32MODERxAddress, Copy_u8PinId << 1);
		SET_BIT(*Locptr_u32MODERxAddress, (Copy_u8PinId << 1) + 1);
		break;
	case GPIO_MODE_ANALOG:
		SET_BIT(*Locptr_u32MODERxAddress, Copy_u8PinId << 1);
		SET_BIT(*Locptr_u32MODERxAddress, (Copy_u8PinId << 1) + 1);
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}

	return NO_ERROR;	
}

/* 
 * Func. Name   : GPIO_errSetPinOutputType
 * Description  : This function allows the user to select the output type of any pin
 * I/p Argument : Copy_u8PortId			Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument : Copy_u8PinId			Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument : Copy_u8PinOutputType	Options: GPIO_OUTPUT_TYPE_PP, GPIO_OUTPUT_TYPE_OD
 * Return 	    : Error status of function
 */
ErrorStatus GPIO_errSetPinOutputType(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinOutputType)
{
	volatile u32* Locptr_u32OTYPERxAddress = NULL;

	if ((GPIO_PORT_C == Copy_u8PortId && GPIO_PIN_13 > Copy_u8PinId) || GPIO_PIN_15 < Copy_u8PinId)
	{
		return INVALID_PARAMETERS;
	}

	switch (Copy_u8PortId)
	{
	case GPIO_PORT_A:
		Locptr_u32OTYPERxAddress = ((u32*) GPIOA_FIRST_ADDRESS) + GPIO_OTYPER_NO;
		break;
	case GPIO_PORT_B:
		Locptr_u32OTYPERxAddress = ((u32*) GPIOB_FIRST_ADDRESS) + GPIO_OTYPER_NO;
		break;
	case GPIO_PORT_C:
		Locptr_u32OTYPERxAddress = ((u32*) GPIOC_FIRST_ADDRESS) + GPIO_OTYPER_NO;
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}

	switch(Copy_u8PinOutputType)
	{
		case GPIO_OUTPUT_TYPE_PP:
			CLR_BIT(*Locptr_u32OTYPERxAddress, Copy_u8PinId);
			break;
		case GPIO_OUTPUT_TYPE_OD:
			SET_BIT(*Locptr_u32OTYPERxAddress, Copy_u8PinId);
			break;
		default:
			return INVALID_PARAMETERS;
			break;
	}

	return NO_ERROR;
}

/* 
 * Func. Name   : GPIO_errSetPinOutputSpeed
 * Description  : This function allows the user to select the output speed of any pin
 * I/p Argument : Copy_u8PortId					Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument : Copy_u8PinId					Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument : GPIO_errSetPinOutputSpeed		Options: GPIO_OUTPUT_SPEED_L -> GPIO_OUTPUT_SPEED_VH
 * Return 	    : Error status of function
 */
ErrorStatus GPIO_errSetPinOutputSpeed(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinOutputSpeed)
{
	volatile u32* Locptr_u32OSPEEDRxAddress = NULL;

	if ((GPIO_PORT_C == Copy_u8PortId && GPIO_PIN_13 > Copy_u8PinId) || GPIO_PIN_15 < Copy_u8PinId)
	{
		return INVALID_PARAMETERS;
	}

	switch (Copy_u8PortId)
	{
	case GPIO_PORT_A:
		Locptr_u32OSPEEDRxAddress = ((u32*) GPIOA_FIRST_ADDRESS) + GPIO_OSPEEDR_NO;
		break;
	case GPIO_PORT_B:
		Locptr_u32OSPEEDRxAddress = ((u32*) GPIOB_FIRST_ADDRESS) + GPIO_OSPEEDR_NO;
		break;
	case GPIO_PORT_C:
		Locptr_u32OSPEEDRxAddress = ((u32*) GPIOC_FIRST_ADDRESS) + GPIO_OSPEEDR_NO;
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}

	switch (Copy_u8PinOutputSpeed)
	{
	case GPIO_OUTPUT_SPEED_L:
		CLR_BIT(*Locptr_u32OSPEEDRxAddress, Copy_u8PinId << 1);
		CLR_BIT(*Locptr_u32OSPEEDRxAddress, (Copy_u8PinId << 1) + 1);
		break;
	case GPIO_OUTPUT_SPEED_M:
		SET_BIT(*Locptr_u32OSPEEDRxAddress, Copy_u8PinId << 1);
		CLR_BIT(*Locptr_u32OSPEEDRxAddress, (Copy_u8PinId << 1) + 1);
		break;
	case GPIO_OUTPUT_SPEED_H:
		CLR_BIT(*Locptr_u32OSPEEDRxAddress, Copy_u8PinId << 1);
		SET_BIT(*Locptr_u32OSPEEDRxAddress, (Copy_u8PinId << 1) + 1);
		break;
	case GPIO_OUTPUT_SPEED_VH:
		SET_BIT(*Locptr_u32OSPEEDRxAddress, Copy_u8PinId << 1);
		SET_BIT(*Locptr_u32OSPEEDRxAddress, (Copy_u8PinId << 1) + 1);
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}
	
	return NO_ERROR;	
}

/* 
 * Func. Name   : GPIO_errSetPinPull
 * Description  : This function allows the user to select the pull state of any pin
 * I/p Argument : Copy_u8PortId			Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument : Copy_u8PinId			Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument : Copy_u8PinPullState	Options: GPIO_NO_PULL, GPIO_PULL_UP, GPIO_PULL_DOWN
 * Return 	    : Error status of function
 */
ErrorStatus GPIO_errSetPinPull(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinPullState)
{
	volatile u32* Locptr_u32PUPDRxAddress = NULL;

	if ((GPIO_PORT_C == Copy_u8PortId && GPIO_PIN_13 > Copy_u8PinId) || GPIO_PIN_15 < Copy_u8PinId)
	{
		return INVALID_PARAMETERS;
	}

	switch (Copy_u8PortId)
	{
	case GPIO_PORT_A:
		Locptr_u32PUPDRxAddress = ((u32*) GPIOA_FIRST_ADDRESS) + GPIO_PUPDR_NO;
		break;
	case GPIO_PORT_B:
		Locptr_u32PUPDRxAddress = ((u32*) GPIOB_FIRST_ADDRESS) + GPIO_PUPDR_NO;
		break;
	case GPIO_PORT_C:
		Locptr_u32PUPDRxAddress = ((u32*) GPIOC_FIRST_ADDRESS) + GPIO_PUPDR_NO;
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}

	switch (Copy_u8PinPullState)
	{
	case GPIO_NO_PULL:
		CLR_BIT(*Locptr_u32PUPDRxAddress, Copy_u8PinId << 1);
		CLR_BIT(*Locptr_u32PUPDRxAddress, (Copy_u8PinId << 1) + 1);
		break;
	case GPIO_PULL_UP:
		SET_BIT(*Locptr_u32PUPDRxAddress, Copy_u8PinId << 1);
		CLR_BIT(*Locptr_u32PUPDRxAddress, (Copy_u8PinId << 1) + 1);
		break;
	case GPIO_PULL_DOWN:
		CLR_BIT(*Locptr_u32PUPDRxAddress, Copy_u8PinId << 1);
		SET_BIT(*Locptr_u32PUPDRxAddress, (Copy_u8PinId << 1) + 1);
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}
	
	return NO_ERROR;	
}

/* 
 * Func. Name   : GPIO_errSetPinValue
 * Description  : This function allows the user to set the value of any pin
 * I/p Argument : Copy_u8PortId		Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument : Copy_u8PinId		Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument : Copy_u8PinValue	Options: GPIO_VALUE_L, GPIO_VALUE_H
 * Return 	    : Error status of function
 */
ErrorStatus GPIO_errSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue)
{
	volatile u32* Locptr_u32ODRxAddress = NULL;

	if ((GPIO_PORT_C == Copy_u8PortId && GPIO_PIN_13 > Copy_u8PinId) || GPIO_PIN_15 < Copy_u8PinId)
	{
		return INVALID_PARAMETERS;
	}

	switch (Copy_u8PortId)
	{
	case GPIO_PORT_A:
		Locptr_u32ODRxAddress = ((u32*) GPIOA_FIRST_ADDRESS) + GPIO_ODR_NO;
		break;
	case GPIO_PORT_B:
		Locptr_u32ODRxAddress = ((u32*) GPIOB_FIRST_ADDRESS) + GPIO_ODR_NO;
		break;
	case GPIO_PORT_C:
		Locptr_u32ODRxAddress = ((u32*) GPIOC_FIRST_ADDRESS) + GPIO_ODR_NO;
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}

	switch(Copy_u8PinValue)
	{
		case GPIO_VALUE_L:
			CLR_BIT(*Locptr_u32ODRxAddress, Copy_u8PinId);
			break;
		case GPIO_VALUE_H:
			SET_BIT(*Locptr_u32ODRxAddress, Copy_u8PinId);
			break;
		default:
			return INVALID_PARAMETERS;
			break;
	}

	return NO_ERROR;
}

/* 
 * Func. Name   : GPIO_errSetPinValueDirectAccess
 * Description  : This function allows the user to set/reset any pin using direct access
 * I/p Argument : Copy_u8PortId		Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument : Copy_u8PinId		Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument : Copy_u8PinAction	Options: GPIO_SET, GPIO_RST
 * Return 	    : Error status of function
 */
ErrorStatus GPIO_errSetPinValueDirectAccess(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinAction)
{
	volatile u32* Locptr_u32BSRRxAddress = NULL;

	if ((GPIO_PORT_C == Copy_u8PortId && GPIO_PIN_13 > Copy_u8PinId) || GPIO_PIN_15 < Copy_u8PinId)
	{
		return INVALID_PARAMETERS;
	}

	switch (Copy_u8PortId)
	{
	case GPIO_PORT_A:
		Locptr_u32BSRRxAddress = ((u32*) GPIOA_FIRST_ADDRESS) + GPIO_BSRR_NO;
		break;
	case GPIO_PORT_B:
		Locptr_u32BSRRxAddress = ((u32*) GPIOB_FIRST_ADDRESS) + GPIO_BSRR_NO;
		break;
	case GPIO_PORT_C:
		Locptr_u32BSRRxAddress = ((u32*) GPIOC_FIRST_ADDRESS) + GPIO_BSRR_NO;
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}

	switch(Copy_u8PinAction)
	{
		case GPIO_SET:
			SET_BIT(*Locptr_u32BSRRxAddress, Copy_u8PinId);
			break;
		case GPIO_RST:
			SET_BIT(*Locptr_u32BSRRxAddress, Copy_u8PinId + 16);
			break;
		default:
			return INVALID_PARAMETERS;
			break;
	}

	return NO_ERROR;
}

/* 
 * Func. Name   : GPIO_errGetPinValue
 * Description  : This function allows the user to get the value of any pin
 * I/p Argument : Copy_u8PortId			Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument : Copy_u8PinId			Options: GPIO_PIN_0 -> GPIO_PIN_15
 * O/p Argument : Outptr_u8PinValue		Options: GPIO_VALUE_L, GPIO_VALUE_H
 * Return 	    : Error status of function
 */
ErrorStatus GPIO_errGetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8* Outptr_u8PinValue)
{
	volatile u32* Locptr_u32IDRxAddress = NULL;

	if ((GPIO_PORT_C == Copy_u8PortId && GPIO_PIN_13 > Copy_u8PinId) || GPIO_PIN_15 < Copy_u8PinId)
	{
		return INVALID_PARAMETERS;
	}

	switch (Copy_u8PortId)
	{
	case GPIO_PORT_A:
		Locptr_u32IDRxAddress = ((u32*) GPIOA_FIRST_ADDRESS) + GPIO_IDR_NO;
		break;
	case GPIO_PORT_B:
		Locptr_u32IDRxAddress = ((u32*) GPIOB_FIRST_ADDRESS) + GPIO_IDR_NO;
		break;
	case GPIO_PORT_C:
		Locptr_u32IDRxAddress = ((u32*) GPIOC_FIRST_ADDRESS) + GPIO_IDR_NO;
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}

	*Outptr_u8PinValue = GET_BIT(*Locptr_u32IDRxAddress, Copy_u8PinId);

	return NO_ERROR;
}
