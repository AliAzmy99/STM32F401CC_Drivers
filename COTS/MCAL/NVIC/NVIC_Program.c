/************************************************************************/
/* SWC  	    : NVIC Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for Nested Vectored Interrupt Controller			*/
/************************************************************************/


/*Include Needed Files*/
	/*Include Needed Library Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed MCAL Files*/
#include "../SCB/SCB_Interface.h"

	/*Include Needed NVIC Files*/
#include "NVIC_Interface.h"
#include "NVIC_Private.h"
#include "NVIC_Config.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
/* 
 * Func. Name	: NVIC_errInit
 * Description	: This function allows the user to initialize the nested vectored interrupt controller
 * Return		: Error status of function
 */
ErrorStatus NVIC_errInit(void)
{
	return SCB_errSetNvicPriorityStructure(SCB_G16_SG01);
}

/* 
 * Func. Name	: NVIC_errEnableInterrupt
 * Description	: This function allows the user to enable a specific interrupt
 * I/p Argument	: Copy_enmIrqId
 * Return		: Error status of function
 */
ErrorStatus NVIC_errEnableInterrupt(IrqId_type Copy_enmIrqId)
{
	/*I/p Validation*/
	if(NVIC_NOT_AN_IRQ <= Copy_enmIrqId)
	{
		return INVALID_PARAMETERS;
	}

	/*Enabling Interrupt*/
	NVIC_ISER_FIRST_ADDRESS[Copy_enmIrqId >> 5] = 1 << (Copy_enmIrqId % 32);

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: NVIC_errDisableInterrupt
 * Description	: This function allows the user to disable a specific interrupt
 * I/p Argument	: Copy_enmIrqId
 * Return		: Error status of function
 */
ErrorStatus NVIC_errDisableInterrupt(IrqId_type Copy_enmIrqId)
{
	/*I/p Validation*/
	if(NVIC_NOT_AN_IRQ <= Copy_enmIrqId)
	{
		return INVALID_PARAMETERS;
	}

	/*Disabling Interrupt*/
	NVIC_ICER_FIRST_ADDRESS[Copy_enmIrqId >> 5] = 1 << (Copy_enmIrqId % 32);

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: NVIC_errSetPending
 * Description	: This function allows the user to set a specific interrupt as pending
 * I/p Argument	: Copy_enmIrqId
 * Return		: Error status of function
 */
ErrorStatus NVIC_errSetPending(IrqId_type Copy_enmIrqId)
{
	/*I/p Validation*/
	if(NVIC_NOT_AN_IRQ <= Copy_enmIrqId)
	{
		return INVALID_PARAMETERS;
	}

	/*Setting Pending*/
	NVIC_ISPR_FIRST_ADDRESS[Copy_enmIrqId >> 5] = 1 << (Copy_enmIrqId % 32);

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: NVIC_errClearPending
 * Description	: This function allows the user to set a specific interrupt as not pending
 * I/p Argument	: Copy_enmIrqId
 * Return		: Error status of function
 */
ErrorStatus NVIC_errClearPending(IrqId_type Copy_enmIrqId)
{
	/*I/p Validation*/
	if(NVIC_NOT_AN_IRQ <= Copy_enmIrqId)
	{
		return INVALID_PARAMETERS;
	}

	/*Clearing Pending*/
	NVIC_ICPR_FIRST_ADDRESS[Copy_enmIrqId >> 5] = 1 << (Copy_enmIrqId % 32);

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: NVIC_errSetPriority
 * Description	: This function allows the user to set the priority group and subgroup of a specific interrupt
 * I/p Argument	: Copy_enmIrqId
 * I/p Argument	: copy_u8Group
 * I/p Argument	: copy_u8SubGroup
 * Return		: Error status of function
 */
ErrorStatus NVIC_errSetPriority(IrqId_type Copy_enmIrqId, u8 copy_u8Group, u8 copy_u8SubGroup)
{
	/*Variables Definitions*/
	u8 Loc_u8Priority = 0;
	u8 Loc_u8PriorityFirstBit = 0;

	/*I/p Validation*/
	if(NVIC_NOT_AN_IRQ >= Copy_enmIrqId)
	{
		return INVALID_PARAMETERS;
	}
	#if G16_SG01 == PRIORITY_STRUCTURE
	if((16 <= copy_u8Group) || (0 < copy_u8SubGroup))
	{
		return INVALID_PARAMETERS;
	}
	#elif G08_SG02 == PRIORITY_STRUCTURE
	if((8 <= copy_u8Group) || (2 <= copy_u8SubGroup))
	{
		return INVALID_PARAMETERS;
	}
	#elif G04_SG04 == PRIORITY_STRUCTURE
	if((4 <= copy_u8Group) || (4 <= copy_u8SubGroup))
	{
		return INVALID_PARAMETERS;
	}
	#elif G02_SG08 == PRIORITY_STRUCTURE
	if((2 <= copy_u8Group) || (8 <= copy_u8SubGroup))
	{
		return INVALID_PARAMETERS;
	}
	#elif G01_SG16 == PRIORITY_STRUCTURE
	if((0 < copy_u8Group) || (16 <= copy_u8SubGroup))
	{
		return INVALID_PARAMETERS;
	}
	#else
		#error Error: Invalid PRIORITY_STRUCTURE Configuration
	#endif

	/*Setting the Group and Subgroup of the IRQ*/
	Loc_u8Priority = copy_u8SubGroup | (copy_u8Group << (PRIORITY_STRUCTURE));
	Loc_u8PriorityFirstBit = (((Copy_enmIrqId % 4) << 3) + 4);

	CLR_NIBBLE(NVIC_IPR_FIRST_ADDRESS[Copy_enmIrqId >> 2], Loc_u8PriorityFirstBit);
	NVIC_IPR_FIRST_ADDRESS[Copy_enmIrqId >> 2] |= Loc_u8Priority << Loc_u8PriorityFirstBit;

	/*Returning Error Status*/
	return NO_ERROR;
}
