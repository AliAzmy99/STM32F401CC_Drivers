/************************************************************************/
/* SWC  	    : SCB Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for System Control Block							*/
/************************************************************************/


/*Include Needed Files*/
	/*Include Needed LIB Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed SCB Files*/
#include "SCB_Config.h"
#include "SCB_Interface.h"
#include "SCB_Private.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
/* 
 * Func. Name	: SCB_vdSetNvicPriorityStructure
 * Description	: This function allows the user to control the priority grouping for the exception model
 * I/p Argument	: Copy_enmPriorityGrouping
 */
void SCB_vdConfigPriorityGrouping(PriorityGrouping_type Copy_enmPriorityGrouping)
{
	/*Setting Priority Structure*/
	SCB_AIRCR = (VECTKEY << SCB_AIRCR_VECTKEY) | ((Copy_enmPriorityGrouping + 3) << SCB_AIRCR_PRIGROUP);	/*Adding the register key to the choosen structure writing to register*/
}
