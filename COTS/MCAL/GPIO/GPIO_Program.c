/************************************************************************/
/* SWC			: GPIO Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for General-Purpose I/Os							*/
/************************************************************************/


/*Include Needed Files*/
	/*Include Needed LIB Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed GPIO Files*/
#include "GPIO_Config.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
/* 
 * Func. Name	: GPIO_vdSetPinMode
 * Description	: This function allows the user to select the mode of the mode of any pin
 * I/p Argument	: Copy_u8Port		Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument	: Copy_u8Pin		Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument	: Copy_u8PinMode	Options: GPIO_MODE_INPUT, GPIO_MODE_OUTPUT, GPIO_MODE_ALT_FUN, GPIO_MODE_ANALOG
 */
void GPIO_vdSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinMode)
{
	/*Variables Definitions*/
	volatile u32* Locptr_u32MODERxAddress = NULL;

	/*I/p Validation*/
	if ((GPIO_PORT_C == Copy_u8Port && GPIO_PIN_13 > Copy_u8Pin) || GPIO_NOT_A_PIN <= Copy_u8Pin)
	{
		return;
	}

	/*Choosing Correct Register Address*/
	switch (Copy_u8Port)
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
		return;
		break;
	}

	/*Setting Mode*/
	switch (Copy_u8PinMode)
	{
	case GPIO_MODE_INPUT:
		CLR_BIT(*Locptr_u32MODERxAddress, Copy_u8Pin << 1);
		CLR_BIT(*Locptr_u32MODERxAddress, (Copy_u8Pin << 1) + 1);
		break;
	case GPIO_MODE_OUTPUT:
		SET_BIT(*Locptr_u32MODERxAddress, Copy_u8Pin << 1);
		CLR_BIT(*Locptr_u32MODERxAddress, (Copy_u8Pin << 1) + 1);
		break;
	case GPIO_MODE_ALT_FUN:
		CLR_BIT(*Locptr_u32MODERxAddress, Copy_u8Pin << 1);
		SET_BIT(*Locptr_u32MODERxAddress, (Copy_u8Pin << 1) + 1);
		break;
	case GPIO_MODE_ANALOG:
		SET_BIT(*Locptr_u32MODERxAddress, Copy_u8Pin << 1);
		SET_BIT(*Locptr_u32MODERxAddress, (Copy_u8Pin << 1) + 1);
		break;
	default:
		return;
		break;
	}
}

/* 
 * Func. Name	: GPIO_vdSetPinOutputType
 * Description	: This function allows the user to select the output type of any pin
 * I/p Argument	: Copy_u8Port			Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument	: Copy_u8Pin			Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument	: Copy_u8PinOutputType	Options: GPIO_OUTPUT_TYPE_PP, GPIO_OUTPUT_TYPE_OD
 */
void GPIO_vdSetPinOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutputType)
{
	/*Variables Definitions*/
	volatile u32* Locptr_u32OTYPERxAddress = NULL;

	/*I/p Validation*/
	if ((GPIO_PORT_C == Copy_u8Port && GPIO_PIN_13 > Copy_u8Pin) || GPIO_NOT_A_PIN <= Copy_u8Pin)
	{
		return;
	}

	/*Choosing Correct Register Address*/
	switch (Copy_u8Port)
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
		return;
		break;
	}

	/*Setting Output Type*/
	switch(Copy_u8PinOutputType)
	{
		case GPIO_OUTPUT_TYPE_PP:
			CLR_BIT(*Locptr_u32OTYPERxAddress, Copy_u8Pin);
			break;
		case GPIO_OUTPUT_TYPE_OD:
			SET_BIT(*Locptr_u32OTYPERxAddress, Copy_u8Pin);
			break;
		default:
			return;
			break;
	}
}

/* 
 * Func. Name	: GPIO_vdSetPinOutputSpeed
 * Description	: This function allows the user to select the output speed of any pin
 * I/p Argument	: Copy_u8Port					Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument	: Copy_u8Pin					Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument	: GPIO_vdSetPinOutputSpeed		Options: GPIO_OUTPUT_SPEED_L -> GPIO_OUTPUT_SPEED_VH
 */
void GPIO_vdSetPinOutputSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutputSpeed)
{
	/*Variables Definitions*/
	volatile u32* Locptr_u32OSPEEDRxAddress = NULL;

	/*I/p Validation*/
	if ((GPIO_PORT_C == Copy_u8Port && GPIO_PIN_13 > Copy_u8Pin) || GPIO_NOT_A_PIN <= Copy_u8Pin)
	{
		return;
	}

	/*Choosing Correct Register Address*/
	switch (Copy_u8Port)
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
		return;
		break;
	}

	/*Setting Output Speed*/
	switch (Copy_u8PinOutputSpeed)
	{
	case GPIO_OUTPUT_SPEED_L:
		CLR_BIT(*Locptr_u32OSPEEDRxAddress, Copy_u8Pin << 1);
		CLR_BIT(*Locptr_u32OSPEEDRxAddress, (Copy_u8Pin << 1) + 1);
		break;
	case GPIO_OUTPUT_SPEED_M:
		SET_BIT(*Locptr_u32OSPEEDRxAddress, Copy_u8Pin << 1);
		CLR_BIT(*Locptr_u32OSPEEDRxAddress, (Copy_u8Pin << 1) + 1);
		break;
	case GPIO_OUTPUT_SPEED_H:
		CLR_BIT(*Locptr_u32OSPEEDRxAddress, Copy_u8Pin << 1);
		SET_BIT(*Locptr_u32OSPEEDRxAddress, (Copy_u8Pin << 1) + 1);
		break;
	case GPIO_OUTPUT_SPEED_VH:
		SET_BIT(*Locptr_u32OSPEEDRxAddress, Copy_u8Pin << 1);
		SET_BIT(*Locptr_u32OSPEEDRxAddress, (Copy_u8Pin << 1) + 1);
		break;
	default:
		return;
		break;
	}
}

/* 
 * Func. Name	: GPIO_vdSetPinPullState
 * Description	: This function allows the user to select the pull state of any pin
 * I/p Argument	: Copy_u8Port			Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument	: Copy_u8Pin			Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument	: Copy_u8PinPullState	Options: GPIO_NO_PULL, GPIO_PULL_UP, GPIO_PULL_DOWN
 */
void GPIO_vdSetPinPullState(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinPullState)
{
	/*Variables Definitions*/
	volatile u32* Locptr_u32PUPDRxAddress = NULL;

	/*I/p Validation*/
	if ((GPIO_PORT_C == Copy_u8Port && GPIO_PIN_13 > Copy_u8Pin) || GPIO_NOT_A_PIN <= Copy_u8Pin)
	{
		return;
	}

	/*Choosing Correct Register Address*/
	switch (Copy_u8Port)
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
		return;
		break;
	}

	/*Setting Pull State*/
	switch (Copy_u8PinPullState)
	{
	case GPIO_NO_PULL:
		CLR_BIT(*Locptr_u32PUPDRxAddress, Copy_u8Pin << 1);
		CLR_BIT(*Locptr_u32PUPDRxAddress, (Copy_u8Pin << 1) + 1);
		break;
	case GPIO_PULL_UP:
		SET_BIT(*Locptr_u32PUPDRxAddress, Copy_u8Pin << 1);
		CLR_BIT(*Locptr_u32PUPDRxAddress, (Copy_u8Pin << 1) + 1);
		break;
	case GPIO_PULL_DOWN:
		CLR_BIT(*Locptr_u32PUPDRxAddress, Copy_u8Pin << 1);
		SET_BIT(*Locptr_u32PUPDRxAddress, (Copy_u8Pin << 1) + 1);
		break;
	default:
		return;
		break;
	}
}

/* 
 * Func. Name	: GPIO_vdSetPinValue
 * Description	: This function allows the user to set the value of any pin
 * I/p Argument	: Copy_u8Port		Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument	: Copy_u8Pin		Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument	: Copy_u8PinValue	Options: GPIO_VALUE_L, GPIO_VALUE_H
 */
void GPIO_vdSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue)
{
	/*Variables Definitions*/
	volatile u32* Locptr_u32ODRxAddress = NULL;

	/*I/p Validation*/
	if ((GPIO_PORT_C == Copy_u8Port && GPIO_PIN_13 > Copy_u8Pin) || GPIO_NOT_A_PIN <= Copy_u8Pin)
	{
		return;
	}

	/*Choosing Correct Register Address*/
	switch (Copy_u8Port)
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
		return;
		break;
	}

	/*Setting Value*/
	switch(Copy_u8PinValue)
	{
		case GPIO_VALUE_L:
			CLR_BIT(*Locptr_u32ODRxAddress, Copy_u8Pin);
			break;
		case GPIO_VALUE_H:
			SET_BIT(*Locptr_u32ODRxAddress, Copy_u8Pin);
			break;
		default:
			return;
			break;
	}
}

/* 
 * Func. Name	: GPIO_vdSetPinValueDirectAccess
 * Description	: This function allows the user to set/reset any pin using direct access
 * I/p Argument	: Copy_u8Port		Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument	: Copy_u8Pin		Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument	: Copy_u8PinAction	Options: GPIO_SET, GPIO_RST
 */
void GPIO_vdSetPinValueDirectAccess(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinAction)
{
	/*Variables Definitions*/
	volatile u32* Locptr_u32BSRRxAddress = NULL;

	/*I/p Validation*/
	if ((GPIO_PORT_C == Copy_u8Port && GPIO_PIN_13 > Copy_u8Pin) || GPIO_NOT_A_PIN <= Copy_u8Pin)
	{
		return;
	}

	/*Choosing Correct Register Address*/
	switch (Copy_u8Port)
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
		return;
		break;
	}

	/*Taking Action*/
	switch(Copy_u8PinAction)
	{
		case GPIO_SET:
			*Locptr_u32BSRRxAddress = 1 << Copy_u8Pin;
			break;
		case GPIO_RST:
			*Locptr_u32BSRRxAddress = 1 << (Copy_u8Pin + 16);
			break;
		default:
			return;
			break;
	}
}

/* 
 * Func. Name	: GPIO_vdGetPinValue
 * Description	: This function allows the user to get the value of any pin
 * I/p Argument	: Copy_u8Port			Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument	: Copy_u8Pin			Options: GPIO_PIN_0 -> GPIO_PIN_15
 * O/p Argument : Outptr_u8PinValue		Options: GPIO_VALUE_L, GPIO_VALUE_H
 */
void GPIO_vdGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Outptr_u8PinValue)
{
	/*Variables Definitions*/
	volatile u32* Locptr_u32IDRxAddress = NULL;

	/*I/p Validation*/
	if ((GPIO_PORT_C == Copy_u8Port && GPIO_PIN_13 > Copy_u8Pin) || GPIO_NOT_A_PIN <= Copy_u8Pin)
	{
		return;
	}
	if (!Outptr_u8PinValue)
	{
		return;
	}
	
	/*Choosing Correct Register Address*/
	switch (Copy_u8Port)
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
		return;
		break;
	}

	/*Outputting Value*/
	*Outptr_u8PinValue = GET_BIT(*Locptr_u32IDRxAddress, Copy_u8Pin);
}
