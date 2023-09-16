/************************************************************************/
/* SWC  	    : NVIC Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for Nested Vectored Interrupt Controller			*/
/************************************************************************/


/*Include Needed Files*/
	/*Include Needed LIB Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed MCAL Files*/
#include "../SCB/SCB_Interface.h"

	/*Include Needed NVIC Files*/
#include "NVIC_Config.h"
#include "NVIC_Interface.h"
#include "NVIC_Private.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
/* 
 * Func. Name	: NVIC_vdInit
 * Description	: This function allows the user to initialize the nested vectored interrupt controller
 */
void NVIC_vdInit(void)
{
	return SCB_vdSetNvicPriorityStructure(PRIORITY_STRUCTURE);
}

/* 
 * Func. Name	: NVIC_vdEnableInterrupt
 * Description	: This function allows the user to enable a specific interrupt
 * I/p Argument	: Copy_enmIrqId
 */
void NVIC_vdEnableInterrupt(IrqId_type Copy_enmIrqId)
{
	/*I/p Validation*/
	if(NVIC_NOT_AN_IRQ <= Copy_enmIrqId)
	{
		return;
	}

	/*Enabling Interrupt*/
	NVIC_ISER_FIRST_ADDRESS[Copy_enmIrqId >> 5] = 1 << (Copy_enmIrqId % 32);
}

/* 
 * Func. Name	: NVIC_vdDisableInterrupt
 * Description	: This function allows the user to disable a specific interrupt
 * I/p Argument	: Copy_enmIrqId
 */
void NVIC_vdDisableInterrupt(IrqId_type Copy_enmIrqId)
{
	/*I/p Validation*/
	if(NVIC_NOT_AN_IRQ <= Copy_enmIrqId)
	{
		return;
	}

	/*Disabling Interrupt*/
	NVIC_ICER_FIRST_ADDRESS[Copy_enmIrqId >> 5] = 1 << (Copy_enmIrqId % 32);
}

/* 
 * Func. Name	: NVIC_vdSetPending
 * Description	: This function allows the user to set a specific interrupt as pending
 * I/p Argument	: Copy_enmIrqId
 */
void NVIC_vdSetPending(IrqId_type Copy_enmIrqId)
{
	/*I/p Validation*/
	if(NVIC_NOT_AN_IRQ <= Copy_enmIrqId)
	{
		return;
	}

	/*Setting Pending*/
	NVIC_ISPR_FIRST_ADDRESS[Copy_enmIrqId >> 5] = 1 << (Copy_enmIrqId % 32);
}

/* 
 * Func. Name	: NVIC_vdClearPending
 * Description	: This function allows the user to set a specific interrupt as not pending
 * I/p Argument	: Copy_enmIrqId
 */
void NVIC_vdClearPending(IrqId_type Copy_enmIrqId)
{
	/*I/p Validation*/
	if(NVIC_NOT_AN_IRQ <= Copy_enmIrqId)
	{
		return;
	}

	/*Clearing Pending*/
	NVIC_ICPR_FIRST_ADDRESS[Copy_enmIrqId >> 5] = 1 << (Copy_enmIrqId % 32);
}

/* 
 * Func. Name	: NVIC_vdGetPending
 * Description	: This function allows the user to know whether a specific interrupt is pending
 * I/p Argument	: Copy_enmIrqId
 * O/p Argument : Outptr_u8Pending		Options: TRUE, FALSE
 */
void NVIC_vdGetPending(IrqId_type Copy_enmIrqId, u8* Outptr_u8Pending)
{
	/*I/p Validation*/
	if(NVIC_NOT_AN_IRQ <= Copy_enmIrqId)
	{
		return;
	}

	/*Getting Pending*/
	*Outptr_u8Pending = GET_BIT(NVIC_ISPR_FIRST_ADDRESS[Copy_enmIrqId >> 5], (Copy_enmIrqId % 32));
}

/* 
 * Func. Name	: NVIC_vdSetPriority
 * Description	: This function allows the user to set the priority group and subgroup of a specific interrupt
 * I/p Argument	: Copy_enmIrqId
 * I/p Argument	: copy_u8Group
 * I/p Argument	: copy_u8SubGroup
 */
void NVIC_vdSetPriority(IrqId_type Copy_enmIrqId, u8 copy_u8Group, u8 copy_u8SubGroup)
{
	/*Variables Definitions*/
	u8 Loc_u8Priority = 0;
	u8 Loc_u8PriorityFirstBit = 0;

	/*I/p Validation*/
	if(NVIC_NOT_AN_IRQ >= Copy_enmIrqId)
	{
		return;
	}
	#if G16_SG01 == PRIORITY_STRUCTURE
	if((16 <= copy_u8Group) || (0 < copy_u8SubGroup))
	{
		return;
	}
	#elif G08_SG02 == PRIORITY_STRUCTURE
	if((8 <= copy_u8Group) || (2 <= copy_u8SubGroup))
	{
		return;
	}
	#elif G04_SG04 == PRIORITY_STRUCTURE
	if((4 <= copy_u8Group) || (4 <= copy_u8SubGroup))
	{
		return;
	}
	#elif G02_SG08 == PRIORITY_STRUCTURE
	if((2 <= copy_u8Group) || (8 <= copy_u8SubGroup))
	{
		return;
	}
	#elif G01_SG16 == PRIORITY_STRUCTURE
	if((0 < copy_u8Group) || (16 <= copy_u8SubGroup))
	{
		return;
	}
	#else
		#error Error: Invalid PRIORITY_STRUCTURE Configuration
	#endif

	/*Setting the Group and Subgroup of the IRQ*/
	Loc_u8Priority = copy_u8SubGroup | (copy_u8Group << (PRIORITY_STRUCTURE));
	Loc_u8PriorityFirstBit = (((Copy_enmIrqId % 4) << 3) + 4);

	CLR_NIBBLE(NVIC_IPR_FIRST_ADDRESS[Copy_enmIrqId >> 2], Loc_u8PriorityFirstBit);
	NVIC_IPR_FIRST_ADDRESS[Copy_enmIrqId >> 2] |= Loc_u8Priority << Loc_u8PriorityFirstBit;
}
