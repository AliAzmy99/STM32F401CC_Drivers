/************************************************************************/
/* SWC			: EXTI Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for External Interrupts/Events Controller			*/
/************************************************************************/


/*Include Needed Files*/
	/*Include Needed Library Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed MCAL Files*/
#include "../GPIO/GPIO_Interface.h"

	/*Include Needed EXTI Files*/
#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
ErrorStatus EXTI_errEnableInterrupt(u8 Copy_u8InterruptLine)
{
	/*I/p validation*/
	if (15 < Copy_u8InterruptLine)
	{
		return INVALID_PARAMETERS;
	}

	/*Unmask Interrupt*/
	SET_BIT(EXTI_IMR, Copy_u8InterruptLine);

	return NO_ERROR;
}

ErrorStatus EXTI_errDisableInterrupt(u8 Copy_u8InterruptLine)
{
	/*I/p validation*/
	if (15 < Copy_u8InterruptLine)
	{
		return INVALID_PARAMETERS;
	}

	/*Mask Interrupt*/
	CLR_BIT(EXTI_IMR, Copy_u8InterruptLine);

	return NO_ERROR;
}

ErrorStatus EXTI_errSetCallbackFunction(u8 Copy_u8Line, void (* Inptr_vdCallbackFunction)(void))
{
	/*I/p validation*/
	if (15 < Copy_u8Line)
	{
		return INVALID_PARAMETERS;
	}

	/*Set Callback Function*/
	switch (Copy_u8Line)
	{
	case EXTI_LINE_0:
		Globptr_vdCallbackFunction_EXTI0 = Inptr_vdCallbackFunction;
		break;
	case EXTI_LINE_1:
		Globptr_vdCallbackFunction_EXTI1 = Inptr_vdCallbackFunction;
		break;
	case EXTI_LINE_2:
		Globptr_vdCallbackFunction_EXTI2 = Inptr_vdCallbackFunction;
		break;
	case EXTI_LINE_3:
		Globptr_vdCallbackFunction_EXTI3 = Inptr_vdCallbackFunction;
		break;
	case EXTI_LINE_4:
		Globptr_vdCallbackFunction_EXTI4 = Inptr_vdCallbackFunction;
		break;
	case EXTI_LINE_5:
	case EXTI_LINE_6:
	case EXTI_LINE_7:
	case EXTI_LINE_8:
	case EXTI_LINE_9:
		Globptr_vdCallbackFunction_EXTI9_5 = Inptr_vdCallbackFunction;
		break;
	case EXTI_LINE_10:
	case EXTI_LINE_11:
	case EXTI_LINE_12:
	case EXTI_LINE_13:
	case EXTI_LINE_14:
	case EXTI_LINE_15:
		Globptr_vdCallbackFunction_EXTI15_10 = Inptr_vdCallbackFunction;
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}

	return NO_ERROR;
}

ErrorStatus EXTI_errEnableEvent(u8 Copy_u8EventLine)
{
	/*I/p validation*/
	if (15 < Copy_u8EventLine)
	{
		return INVALID_PARAMETERS;
	}

	/*Unmask Event*/
	SET_BIT(EXTI_EMR, Copy_u8EventLine);

	return NO_ERROR;
}

ErrorStatus EXTI_errDisableEvent(u8 Copy_u8EventLine)
{
	/*I/p validation*/
	if (15 < Copy_u8EventLine)
	{
		return INVALID_PARAMETERS;
	}

	/*Mask Event*/
	CLR_BIT(EXTI_EMR, Copy_u8EventLine);

	return NO_ERROR;
}

ErrorStatus EXTI_errSelectEdgeTriggers(u8 Copy_u8Line, u8 Copy_u8EdgeTrigger)
{
	/*I/p validation*/
	if (15 < Copy_u8Line)
	{
		return INVALID_PARAMETERS;
	}

	/*Enable / Disable Edge Triggers*/
	switch (Copy_u8EdgeTrigger)
	{
	case EXTI_RISING_EDGE:
		SET_BIT(EXTI_RTSR, Copy_u8Line);
		CLR_BIT(EXTI_FTSR, Copy_u8Line);
		break;
	case EXTI_FALLING_EDGE:
		CLR_BIT(EXTI_RTSR, Copy_u8Line);
		SET_BIT(EXTI_FTSR, Copy_u8Line);
		break;
	case EXTI_DUAL_EDGE:
		SET_BIT(EXTI_RTSR, Copy_u8Line);
		SET_BIT(EXTI_FTSR, Copy_u8Line);
		break;
	case EXTI_NO_EDGE:
		CLR_BIT(EXTI_RTSR, Copy_u8Line);
		CLR_BIT(EXTI_FTSR, Copy_u8Line);
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}

	return NO_ERROR;
}