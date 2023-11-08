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

	/*Include Needed EXTI Files*/
#include "EXTI_Config.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
/* 
 * Func. Name	: EXTI_vdInitLine
 * Description	: This function allows the user to initialize a certain line
 * 				  It also disables the initialized line
 * Note			: To choose which port this line is connected to, use SYSCFG_vdSetExtiLinePort()
 * I/p Argument	: Copy_enmLineId			: Line to initialize
 * I/p Argument	: Copy_enmDetectedEdge		: Edges that trigger the line interrupt
 * I/p Argument	: Inptr_vdCallbackFunction	: Pointer to the function that is called when the line interrupt triggered
 */
void EXTI_vdInitLine(LineId_type Copy_enmLineId, DetectedEdge_type Copy_enmDetectedEdge, void (* Inptr_vdCallbackFunction)(void))
{
	/*Disable Interrupts for the Line*/
	EXTI_vdDisableInterrupt(Copy_enmLineId);

	/*Enable / Disable Edge Triggers*/
	switch (Copy_enmDetectedEdge)
	{
	case EXTI_RISING_EDGE:
		SET_BIT(EXTI_RTSR, Copy_enmLineId);
		CLR_BIT(EXTI_FTSR, Copy_enmLineId);
		break;
	case EXTI_FALLING_EDGE:
		CLR_BIT(EXTI_RTSR, Copy_enmLineId);
		SET_BIT(EXTI_FTSR, Copy_enmLineId);
		break;
	case EXTI_DUAL_EDGE:
		SET_BIT(EXTI_RTSR, Copy_enmLineId);
		SET_BIT(EXTI_FTSR, Copy_enmLineId);
		break;
	case EXTI_NO_EDGE:
		CLR_BIT(EXTI_RTSR, Copy_enmLineId);
		CLR_BIT(EXTI_FTSR, Copy_enmLineId);
		break;
	default:
		return;
		break;
	}

	/*Set Callback Function*/
	Globptr_vdCallbackFunctions[Copy_enmLineId] = Inptr_vdCallbackFunction;
}

/* 
 * Func. Name	: EXTI_vdEnableInterrupt
 * Description	: This function allows the user to enable a certain interrupt
 * I/p Argument	: Copy_enmLineId
 */
void EXTI_vdEnableInterrupt(LineId_type Copy_enmLineId)
{
	/*Unmask Interrupt*/
	SET_BIT(EXTI_IMR, Copy_enmLineId);
}

/* 
 * Func. Name	: EXTI_vdDisableInterrupt
 * Description	: This function allows the user to disable a certain interrupt
 * I/p Argument	: Copy_enmLineId
 */
void EXTI_vdDisableInterrupt(LineId_type Copy_enmLineId)
{
	/*Mask Interrupt*/
	CLR_BIT(EXTI_IMR, Copy_enmLineId);
}

/* 
 * Func. Name	: EXTI_vdTriggerSoftwareInterrupt
 * Description	: This function allows the user to trigger a certain interrupt using software
 * I/p Argument	: Copy_enmLineId
 */
void EXTI_vdTriggerSoftwareInterrupt(LineId_type Copy_enmLineId)
{
	/*Unmask Interrupt*/
	SET_BIT(EXTI_SWIER, Copy_enmLineId);
}

/* 
 * Func. Name	: EXTI_vdGetPending
 * Description	: This function allows the user to know whether a specific interrupt is pending
 * I/p Argument	: Copy_enmLineId
 * O/p Argument : Outptr_enmPending
 */
void EXTI_vdGetPending(LineId_type Copy_enmLineId, True_type* Outptr_enmPending)
{
	/*Get Pending*/
	*Outptr_enmPending = GET_BIT(EXTI_PR, Copy_enmLineId);
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
