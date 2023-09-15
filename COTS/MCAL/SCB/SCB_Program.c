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
 * Func. Name	: SCB_errSetNvicPriorityStructure
 * Description	: This function allows the user to choose the number of priority groups and subgroups the for the NVIC
 * I/p Argument	: Copy_u8PriorityStructure		Options: SCB_G16_SG01, SCB_G08_SG02, SCB_G04_SG04, SCB_G02_SG08, SCB_G01_SG16
 * Return		: Error status of function
 */
ErrorStatus SCB_errSetNvicPriorityStructure(u8 Copy_u8PriorityStructure)
{
	/*I/p Validation*/
	if (SCB_G01_SG16 < Copy_u8PriorityStructure)
	{
		return INVALID_PARAMETERS;
	}

	/*Setting Priority Structure*/
	SCB_AIRCR = VECTKEY | ((Copy_u8PriorityStructure + 3) << SCB_AIRCR_PRIGROUP);	/*Adding the register key to the choosen structure writing to register*/

	/*Returning Error Status*/
	return NO_ERROR;
}
