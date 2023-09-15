/************************************************************************/
/* SWC			: EXTI Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for External Interrupts/Events Controller			*/
/************************************************************************/


/*Include Needed Files*/
	/*Include Needed LIB Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed MCAL Files*/
#include "../GPIO/GPIO_Interface.h"
#include "../SYSCFG/SYSCFG_Interface.h"

	/*Include Needed EXTI Files*/
#include "EXTI_Config.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
/* 
 * Func. Name	: EXTI_errInit
 * Description	: This function allows the user to initialize the external interrupts/events controller
 * Return		: Error status of function
 */
ErrorStatus EXTI_errInit(void)
{
	/*Variables Definitions*/
	ErrorStatus Loc_errReturn = NO_ERROR;

	for (u8 Loc_u8LineCounter = 0; EXTI_NOT_A_LINE > Loc_u8LineCounter; ++Loc_u8LineCounter)
	{
		Loc_errReturn = SYSCFG_errSetExtiLinePort(Loc_u8LineCounter, Glob_u8LinePorts[Loc_u8LineCounter]);
		RETURN_IF_ERROR(Loc_errReturn);
	}
	
	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: EXTI_errEnableInterrupt
 * Description	: This function allows the user to enable a certain interrupt
 * I/p Argument	: Copy_u8InterruptLine				Options: EXTI_LINE_0 -> EXTI_LINE_15
 * Return		: Error status of function
 */
ErrorStatus EXTI_errEnableInterrupt(u8 Copy_u8InterruptLine)
{
	/*I/p validation*/
	if (EXTI_NOT_A_LINE <= Copy_u8InterruptLine)
	{
		return INVALID_PARAMETERS;
	}

	/*Unmask Interrupt*/
	SET_BIT(EXTI_IMR, Copy_u8InterruptLine);

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: EXTI_errDisableInterrupt
 * Description	: This function allows the user to disable a certain interrupt
 * I/p Argument	: Copy_u8InterruptLine				Options: EXTI_LINE_0 -> EXTI_LINE_15
 * Return		: Error status of function
 */
ErrorStatus EXTI_errDisableInterrupt(u8 Copy_u8InterruptLine)
{
	/*I/p validation*/
	if (EXTI_NOT_A_LINE <= Copy_u8InterruptLine)
	{
		return INVALID_PARAMETERS;
	}

	/*Mask Interrupt*/
	CLR_BIT(EXTI_IMR, Copy_u8InterruptLine);

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: EXTI_errSetCallbackFunction
 * Description	: This function allows the user set the callback function that will be called when a certain interrupt line triggers its ISR
 * I/p Argument	: Copy_u8InterruptLine				Options: EXTI_LINE_0 -> EXTI_LINE_15
 * I/p Argument	: Inptr_vdCallbackFunction			pointer to callback function
 * Return		: Error status of function
 */
ErrorStatus EXTI_errSetCallbackFunction(u8 Copy_u8InterruptLine, void (* Inptr_vdCallbackFunction)(void))
{
	/*I/p validation*/
	if (EXTI_NOT_A_LINE <= Copy_u8InterruptLine)
	{
		return INVALID_PARAMETERS;
	}
	if (!Inptr_vdCallbackFunction)
	{
		return NULL_POINTER_PASSED;
	}
	
	/*Set Callback Function*/
	Globptr_vdCallbackFunctions[Copy_u8InterruptLine] = Inptr_vdCallbackFunction;

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: EXTI_errEnableEvent
 * Description	: This function allows the user to enable a certain event
 * I/p Argument	: Copy_u8EventLine					Options: EXTI_LINE_0 -> EXTI_LINE_15
 * Return		: Error status of function
 */
ErrorStatus EXTI_errEnableEvent(u8 Copy_u8EventLine)
{
	/*I/p validation*/
	if (EXTI_NOT_A_LINE <= Copy_u8EventLine)
	{
		return INVALID_PARAMETERS;
	}

	/*Unmask Event*/
	SET_BIT(EXTI_EMR, Copy_u8EventLine);

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: EXTI_errDisableEvent
 * Description	: This function allows the user to disable a certain event
 * I/p Argument	: Copy_u8EventLine					Options: EXTI_LINE_0 -> EXTI_LINE_15
 * Return		: Error status of function
 */
ErrorStatus EXTI_errDisableEvent(u8 Copy_u8EventLine)
{
	/*I/p validation*/
	if (EXTI_NOT_A_LINE <= Copy_u8EventLine)
	{
		return INVALID_PARAMETERS;
	}

	/*Mask Event*/
	CLR_BIT(EXTI_EMR, Copy_u8EventLine);

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: EXTI_errSelectEdgeTriggers
 * Description	: This function allows the user to choose which edges trigger a certain interrupt/event line
 * I/p Argument	: Copy_u8Line						Options: EXTI_LINE_0 -> EXTI_LINE_15
 * I/p Argument	: Copy_u8EdgeTrigger				Options: EXTI_RISING_EDGE, EXTI_FALLING_EDGE, EXTI_DUAL_EDGE, EXTI_NO_EDGE
 * Return		: Error status of function
 */
ErrorStatus EXTI_errSelectEdgeTriggers(u8 Copy_u8Line, u8 Copy_u8EdgeTrigger)
{
	/*I/p validation*/
	if (EXTI_NOT_A_LINE <= Copy_u8Line)
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

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: EXTI_errTriggerSoftwareInterrupt
 * Description	: This function allows the user to trigger a certain interrupt using software
 * I/p Argument	: Copy_u8InterruptLine				Options: EXTI_LINE_0 -> EXTI_LINE_15
 * Return		: Error status of function
 */
ErrorStatus EXTI_errTriggerSoftwareInterrupt(u8 Copy_u8InterruptLine)
{
	/*I/p validation*/
	if (EXTI_NOT_A_LINE <= Copy_u8InterruptLine)
	{
		return INVALID_PARAMETERS;
	}

	/*Unmask Interrupt*/
	SET_BIT(EXTI_SWIER, Copy_u8InterruptLine);

	/*Returning Error Status*/
	return NO_ERROR;
}
/*__________________________________________________________________________________________________________________________________________*/


/*Interrupt Service Routines Definitions*/
/*
 * Func. Name	: EXTI0_IRQHandler
 * Description	: This function calls the callback function and clears the interrupt flag
 */
void EXTI0_IRQHandler(void)
{
	/*1- Call Callback Function*/
	if (Globptr_vdCallbackFunctions[0])
	{
		Globptr_vdCallbackFunctions[0]();
	}

	/*2- Clear Pending Flag*/
	SET_BIT(EXTI_PR, EXTI_PR_PR0);
}

/*
 * Func. Name	: EXTI1_IRQHandler
 * Description	: This function calls the callback function and clears the interrupt flag
 */
void EXTI1_IRQHandler(void)
{
	/*1- Call Callback Function*/
	if (Globptr_vdCallbackFunctions[1])
	{
		Globptr_vdCallbackFunctions[1]();
	}

	/*2- Clear Pending Flag*/
	SET_BIT(EXTI_PR, EXTI_PR_PR1);
}

/*
 * Func. Name	: EXTI2_IRQHandler
 * Description	: This function calls the callback function and clears the interrupt flag
 */
void EXTI2_IRQHandler(void)
{
	/*1- Call Callback Function*/
	if (Globptr_vdCallbackFunctions[2])
	{
		Globptr_vdCallbackFunctions[2]();
	}

	/*2- Clear Pending Flag*/
	SET_BIT(EXTI_PR, EXTI_PR_PR2);
}

/*
 * Func. Name	: EXTI3_IRQHandler
 * Description	: This function calls the callback function and clears the interrupt flag
 */
void EXTI3_IRQHandler(void)
{
	/*1- Call Callback Function*/
	if (Globptr_vdCallbackFunctions[3])
	{
		Globptr_vdCallbackFunctions[3]();
	}

	/*2- Clear Pending Flag*/
	SET_BIT(EXTI_PR, EXTI_PR_PR3);
}

/*
 * Func. Name	: EXTI4_IRQHandler
 * Description	: This function calls the callback function and clears the interrupt flag
 */
void EXTI4_IRQHandler(void)
{
	/*1- Call Callback Function*/
	if (Globptr_vdCallbackFunctions[4])
	{
		Globptr_vdCallbackFunctions[4]();
	}

	/*2- Clear Pending Flag*/
	SET_BIT(EXTI_PR, EXTI_PR_PR4);
}

/*
 * Func. Name	: EXTI9_5_IRQHandler
 * Description	: This function calls the callback function and clears the interrupt flag
 */
void EXTI9_5_IRQHandler(void)
{
	/*Loop on Interrupts 5 to 9*/
	for (u8 Loc_u8IrqCounter = 5; 9 >= Loc_u8IrqCounter; ++Loc_u8IrqCounter)
	{
		/*Check if Interrupt is Pending and Enabled*/
		if (!GET_BIT(EXTI_PR, Loc_u8IrqCounter) || !GET_BIT(EXTI_IMR, Loc_u8IrqCounter))
		{
			continue;
		}

		/*Clear Pending Flag*/
		SET_BIT(EXTI_PR, Loc_u8IrqCounter);

		/*Call Callback Function*/
		if (Globptr_vdCallbackFunctions[Loc_u8IrqCounter])
		{
			Globptr_vdCallbackFunctions[Loc_u8IrqCounter]();
		}
	}
}

/*
 * Func. Name	: EXTI15_10_IRQHandler
 * Description	: This function calls the callback function and clears the interrupt flag
 */
void EXTI15_10_IRQHandler(void)
{
	/*Loop on Interrupts 10 to 15*/
	for (u8 Loc_u8IrqCounter = 10; 15 >= Loc_u8IrqCounter; ++Loc_u8IrqCounter)
	{
		/*Check if Interrupt is Pending and Enabled*/
		if (!GET_BIT(EXTI_PR, Loc_u8IrqCounter) || !GET_BIT(EXTI_IMR, Loc_u8IrqCounter))
		{
			continue;
		}

		/*Clear Pending Flag*/
		SET_BIT(EXTI_PR, Loc_u8IrqCounter);

		/*Call Callback Function*/
		if (Globptr_vdCallbackFunctions[Loc_u8IrqCounter])
		{
			Globptr_vdCallbackFunctions[Loc_u8IrqCounter]();
		}
	}
}
