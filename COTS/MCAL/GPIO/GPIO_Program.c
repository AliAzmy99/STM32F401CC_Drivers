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
	case GPIO_Mode_INPUT:
		CLR_BIT(*Locptr_u32MODERxAddress, Copy_u8PinId << 1);
		CLR_BIT(*Locptr_u32MODERxAddress, Copy_u8PinId << 1 + 1);
		break;
	case GPIO_Mode_OUTPUT:
		SET_BIT(*Locptr_u32MODERxAddress, Copy_u8PinId << 1);
		CLR_BIT(*Locptr_u32MODERxAddress, Copy_u8PinId << 1 + 1);
		break;
	case GPIO_Mode_ALT_FUN:
		CLR_BIT(*Locptr_u32MODERxAddress, Copy_u8PinId << 1);
		SET_BIT(*Locptr_u32MODERxAddress, Copy_u8PinId << 1 + 1);
		break;
	case GPIO_MODE_ANALOG:
		SET_BIT(*Locptr_u32MODERxAddress, Copy_u8PinId << 1);
		SET_BIT(*Locptr_u32MODERxAddress, Copy_u8PinId << 1 + 1);
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}

	return NO_ERROR;	
}

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
		CLR_BIT(*Locptr_u32OSPEEDRxAddress, Copy_u8PinId << 1 + 1);
		break;
	case GPIO_OUTPUT_SPEED_M:
		SET_BIT(*Locptr_u32OSPEEDRxAddress, Copy_u8PinId << 1);
		CLR_BIT(*Locptr_u32OSPEEDRxAddress, Copy_u8PinId << 1 + 1);
		break;
	case GPIO_OUTPUT_SPEED_H:
		CLR_BIT(*Locptr_u32OSPEEDRxAddress, Copy_u8PinId << 1);
		SET_BIT(*Locptr_u32OSPEEDRxAddress, Copy_u8PinId << 1 + 1);
		break;
	case GPIO_OUTPUT_SPEED_VH:
		SET_BIT(*Locptr_u32OSPEEDRxAddress, Copy_u8PinId << 1);
		SET_BIT(*Locptr_u32OSPEEDRxAddress, Copy_u8PinId << 1 + 1);
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}
	
	return NO_ERROR;	
}

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
		case GPIO_PIN_VALUE_L:
			CLR_BIT(*Locptr_u32ODRxAddress, Copy_u8PinId);
			break;
		case GPIO_PIN_VALUE_H:
			SET_BIT(*Locptr_u32ODRxAddress, Copy_u8PinId);
			break;
		default:
			return INVALID_PARAMETERS;
			break;
	}

	return NO_ERROR;
}

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
		case GPIO_PIN_SET:
			SET_BIT(*Locptr_u32BSRRxAddress, Copy_u8PinId);
			break;
		case GPIO_PIN_RST:
			SET_BIT(*Locptr_u32BSRRxAddress, Copy_u8PinId + 16);
			break;
		default:
			return INVALID_PARAMETERS;
			break;
	}

	return NO_ERROR;
}