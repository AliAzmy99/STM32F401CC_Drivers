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
 * I/p Argument	: Copy_enmPortId
 * I/p Argument	: Copy_enmPinId
 * I/p Argument	: Copy_enmMode
 */
void GPIO_vdSetPinMode(PortId_type Copy_enmPortId, PinId_type Copy_enmPinId, PinMode_type Copy_enmMode)
{
	/*Variables Definitions*/
	volatile u32* Locptr_u32MODERxAddress = NULL;

	/*I/p Validation*/
	if (GPIO_PORT_C == Copy_enmPortId && GPIO_PIN_13 > Copy_enmPinId)
	{
		return;
	}

	/*Choosing Correct Register Address*/
	switch (Copy_enmPortId)
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
	switch (Copy_enmMode)
	{
	case GPIO_INPUT:
		CLR_BIT(*Locptr_u32MODERxAddress, Copy_enmPinId << 1);
		CLR_BIT(*Locptr_u32MODERxAddress, (Copy_enmPinId << 1) + 1);
		break;
	case GPIO_OUTPUT:
		SET_BIT(*Locptr_u32MODERxAddress, Copy_enmPinId << 1);
		CLR_BIT(*Locptr_u32MODERxAddress, (Copy_enmPinId << 1) + 1);
		break;
	case GPIO_ALTERNATE_FUNCTION:
		CLR_BIT(*Locptr_u32MODERxAddress, Copy_enmPinId << 1);
		SET_BIT(*Locptr_u32MODERxAddress, (Copy_enmPinId << 1) + 1);
		break;
	case GPIO_ANALOG:
		SET_BIT(*Locptr_u32MODERxAddress, Copy_enmPinId << 1);
		SET_BIT(*Locptr_u32MODERxAddress, (Copy_enmPinId << 1) + 1);
		break;
	default:
		return;
		break;
	}
}

/* 
 * Func. Name	: GPIO_vdSetPinOutputType
 * Description	: This function allows the user to select the output type of any pin
 * I/p Argument	: Copy_enmPortId
 * I/p Argument	: Copy_enmPinId
 * I/p Argument	: Copy_enmOutputMode
 */
void GPIO_vdSetPinOutputType(PortId_type Copy_enmPortId, PinId_type Copy_enmPinId, OutputMode_type Copy_enmOutputMode)
{
	/*Variables Definitions*/
	volatile u32* Locptr_u32OTYPERxAddress = NULL;

	/*I/p Validation*/
	if (GPIO_PORT_C == Copy_enmPortId && GPIO_PIN_13 > Copy_enmPinId)
	{
		return;
	}

	/*Choosing Correct Register Address*/
	switch (Copy_enmPortId)
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
	switch(Copy_enmOutputMode)
	{
		case GPIO_PUSH_PULL:
			CLR_BIT(*Locptr_u32OTYPERxAddress, Copy_enmPinId);
			break;
		case GPIO_OPEN_DRAIN:
			SET_BIT(*Locptr_u32OTYPERxAddress, Copy_enmPinId);
			break;
		default:
			return;
			break;
	}
}

/* 
 * Func. Name	: GPIO_vdSetPinOutputSpeed
 * Description	: This function allows the user to select the output speed of any pin
 * I/p Argument	: Copy_enmPortId
 * I/p Argument	: Copy_enmPinId
 * I/p Argument	: GPIO_vdSetPinOutputSpeed
 */
void GPIO_vdSetPinOutputSpeed(PortId_type Copy_enmPortId, PinId_type Copy_enmPinId, OutputSpeed_type Copy_enmOutputSpeed)
{
	/*Variables Definitions*/
	volatile u32* Locptr_u32OSPEEDRxAddress = NULL;

	/*I/p Validation*/
	if (GPIO_PORT_C == Copy_enmPortId && GPIO_PIN_13 > Copy_enmPinId)
	{
		return;
	}

	/*Choosing Correct Register Address*/
	switch (Copy_enmPortId)
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
	switch (Copy_enmOutputSpeed)
	{
	case GPIO_LOW_SPEED:
		CLR_BIT(*Locptr_u32OSPEEDRxAddress, Copy_enmPinId << 1);
		CLR_BIT(*Locptr_u32OSPEEDRxAddress, (Copy_enmPinId << 1) + 1);
		break;
	case GPIO_MEDIUM_SPEED:
		SET_BIT(*Locptr_u32OSPEEDRxAddress, Copy_enmPinId << 1);
		CLR_BIT(*Locptr_u32OSPEEDRxAddress, (Copy_enmPinId << 1) + 1);
		break;
	case GPIO_HIGH_SPEED:
		CLR_BIT(*Locptr_u32OSPEEDRxAddress, Copy_enmPinId << 1);
		SET_BIT(*Locptr_u32OSPEEDRxAddress, (Copy_enmPinId << 1) + 1);
		break;
	case GPIO_VERY_HIGH_SPEED:
		SET_BIT(*Locptr_u32OSPEEDRxAddress, Copy_enmPinId << 1);
		SET_BIT(*Locptr_u32OSPEEDRxAddress, (Copy_enmPinId << 1) + 1);
		break;
	default:
		return;
		break;
	}
}

/* 
 * Func. Name	: GPIO_vdSetPinPullState
 * Description	: This function allows the user to select the pull state of any pin
 * I/p Argument	: Copy_enmPortId
 * I/p Argument	: Copy_enmPinId
 * I/p Argument	: Copy_enmPullState
 */
void GPIO_vdSetPinPullState(PortId_type Copy_enmPortId, PinId_type Copy_enmPinId, PullState_type Copy_enmPullState)
{
	/*Variables Definitions*/
	volatile u32* Locptr_u32PUPDRxAddress = NULL;

	/*I/p Validation*/
	if (GPIO_PORT_C == Copy_enmPortId && GPIO_PIN_13 > Copy_enmPinId)
	{
		return;
	}

	/*Choosing Correct Register Address*/
	switch (Copy_enmPortId)
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
	switch (Copy_enmPullState)
	{
	case GPIO_FLOATING:
		CLR_BIT(*Locptr_u32PUPDRxAddress, Copy_enmPinId << 1);
		CLR_BIT(*Locptr_u32PUPDRxAddress, (Copy_enmPinId << 1) + 1);
		break;
	case GPIO_PULL_UP:
		SET_BIT(*Locptr_u32PUPDRxAddress, Copy_enmPinId << 1);
		CLR_BIT(*Locptr_u32PUPDRxAddress, (Copy_enmPinId << 1) + 1);
		break;
	case GPIO_PULL_DOWN:
		CLR_BIT(*Locptr_u32PUPDRxAddress, Copy_enmPinId << 1);
		SET_BIT(*Locptr_u32PUPDRxAddress, (Copy_enmPinId << 1) + 1);
		break;
	default:
		return;
		break;
	}
}

/* 
 * Func. Name	: GPIO_vdSetPinValue
 * Description	: This function allows the user to set the value of any pin using direct access
 * I/p Argument	: Copy_enmPortId
 * I/p Argument	: Copy_enmPinId
 * I/p Argument	: Copy_enmValue
 */
void GPIO_vdSetPinValue(PortId_type Copy_enmPortId, PinId_type Copy_enmPinId, Value_type Copy_enmValue)
{
	/*Variables Definitions*/
	volatile u32* Locptr_u32BSRRxAddress = NULL;

	/*I/p Validation*/
	if (GPIO_PORT_C == Copy_enmPortId && GPIO_PIN_13 > Copy_enmPinId)
	{
		return;
	}

	/*Choosing Correct Register Address*/
	switch (Copy_enmPortId)
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

	/*Setting Value*/
	switch(Copy_enmValue)
	{
		case STD_HIGH:
			*Locptr_u32BSRRxAddress = 1 << Copy_enmPinId;
			break;
		case STD_LOW:
			*Locptr_u32BSRRxAddress = 1 << (Copy_enmPinId + 16);
			break;
		default:
			return;
			break;
	}
}

/* 
 * Func. Name	: GPIO_vdGetPinValue
 * Description	: This function allows the user to get the value of any pin
 * I/p Argument	: Copy_enmPortId
 * I/p Argument	: Copy_enmPinId
 * O/p Argument : Outptr_enmValue
 */
void GPIO_vdGetPinValue(PortId_type Copy_enmPortId, PinId_type Copy_enmPinId, Value_type* Outptr_enmPinValue)
{
	/*Variables Definitions*/
	volatile u32* Locptr_u32IDRxAddress = NULL;

	/*I/p Validation*/
	if (GPIO_PORT_C == Copy_enmPortId && GPIO_PIN_13 > Copy_enmPinId)
	{
		return;
	}
	if (!Outptr_enmPinValue)
	{
		return;
	}
	
	/*Choosing Correct Register Address*/
	switch (Copy_enmPortId)
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
	*Outptr_enmPinValue = GET_BIT(*Locptr_u32IDRxAddress, Copy_enmPinId);
}

/* 
 * Func. Name	: GPIO_vdSetAlternativeFunction
 * Description	: This function allows the user to set the alternative function of any pin
 * I/p Argument	: Copy_enmPortId
 * I/p Argument	: Copy_enmPinId
 * I/p Argument	: Copy_enmAltFunNum
 */
void GPIO_vdSetAlternativeFunction(PortId_type Copy_enmPortId, PinId_type Copy_enmPinId, AlternativeFunction_type Copy_enmAltFunNum)
{
	/*Variables Definitions*/
	volatile u32* Locptr_u32AFRxAddress = NULL;
	u8 Loc_u8RegNumber = 0;

	/*I/p Validation*/
	if (GPIO_PORT_C == Copy_enmPortId && GPIO_PIN_13 > Copy_enmPinId)
	{
		return;
	}

	/*Choosing the Correct Register Number*/
	if (7 >= Copy_enmPinId)
	{
		Loc_u8RegNumber = GPIO_AFRL_NO;
	}
	else
	{
		Loc_u8RegNumber = GPIO_AFRH_NO;
		Copy_enmPinId -= 8;
	}

	/*Choosing Correct Register Address*/
	switch (Copy_enmPortId)
	{
	case GPIO_PORT_A:
		Locptr_u32AFRxAddress = ((u32*) GPIOA_FIRST_ADDRESS) + Loc_u8RegNumber;
		break;
	case GPIO_PORT_B:
		Locptr_u32AFRxAddress = ((u32*) GPIOB_FIRST_ADDRESS) + Loc_u8RegNumber;
		break;
	case GPIO_PORT_C:
		Locptr_u32AFRxAddress = ((u32*) GPIOC_FIRST_ADDRESS) + Loc_u8RegNumber;
		break;
	default:
		return;
		break;
	}

	/*Setting Alternative Function*/
	MAKE_4BITS(*Locptr_u32AFRxAddress, Copy_enmPinId << 2, Copy_enmAltFunNum);
}