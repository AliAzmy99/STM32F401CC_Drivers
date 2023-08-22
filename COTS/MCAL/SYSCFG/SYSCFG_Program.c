/************************************************************************/
/* SWC  	    : SYSCFG Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for System Configuration Controller				*/
/************************************************************************/


/*Include Needed Files*/
	/*Include Needed Library Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed MCAL Files*/
#include "../GPIO/GPIO_Interface.h"
#include "../EXTI/EXTI_Interface.h"

	/*Include Needed SYSCFG Files*/
#include "SYSCFG_Interface.h"
#include "SYSCFG_Private.h"
#include "SYSCFG_Config.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
/* 
 * Func. Name	: SYSCFG_errSetExtiLinePort
 * Description	: This function allows the user to choose the Port that a particular EXTI line is connected to.
 * I/p Argument	: Copy_u8Line			Options: SYSCFG_LINE_0 -> SYSCFG_LINE_15
 * I/p Argument : Copy_u8Port			Options: SYSCFG_PORT_A -> SYSCFG_PORT_C
 * Return		: Error status of function
 */
ErrorStatus SYSCFG_errSetExtiLinePort(u8 Copy_u8Line, u8 Copy_u8Port)
{
	/*I/p Validation*/
	if ((SYSCFG_PORT_C == Copy_u8Port && SYSCFG_LINE_13 > Copy_u8Line) || SYSCFG_NOT_A_PORT <= Copy_u8Line)
	{
		return INVALID_PARAMETERS;
	}

	/*Choosing Port*/
	if (SYSCFG_LINE_3 >= Copy_u8Line)
	{
		CLR_NIBBLE(SYSCFG_EXTICR1, Copy_u8Line << 2);
		SYSCFG_EXTICR1 |= Copy_u8Port << (Copy_u8Line << 2);
	}
	else if (SYSCFG_LINE_7 >= Copy_u8Line)
	{
		CLR_NIBBLE(SYSCFG_EXTICR2, (Copy_u8Line - 4) << 2);
		SYSCFG_EXTICR2 |= Copy_u8Port << ((Copy_u8Line - 4) << 2);
	}
	else if (SYSCFG_LINE_11 >= Copy_u8Line)
	{
		CLR_NIBBLE(SYSCFG_EXTICR3, (Copy_u8Line - 8) << 2);
		SYSCFG_EXTICR3 |= Copy_u8Port << ((Copy_u8Line - 8) << 2);
	}
	else if (SYSCFG_LINE_15 >= Copy_u8Line)
	{
		CLR_NIBBLE(SYSCFG_EXTICR4, (Copy_u8Line - 12) << 2);
		SYSCFG_EXTICR4 |= Copy_u8Port << ((Copy_u8Line - 12) << 2);
	}
	else
	{
		return INVALID_PARAMETERS;
	}

	/*Returning Error Status*/
	return NO_ERROR;
}
