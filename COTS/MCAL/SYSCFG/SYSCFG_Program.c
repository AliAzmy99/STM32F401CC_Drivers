/************************************************************************/
/* SWC  	    : SYSCFG Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for System Configuration Controller				*/
/************************************************************************/


/*Include Needed Files*/
	/*Include Needed LIB Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed MCAL Files*/
#include "../GPIO/GPIO_Interface.h"
#include "../EXTI/EXTI_Interface.h"

	/*Include Needed SYSCFG Files*/
#include "SYSCFG_Config.h"
#include "SYSCFG_Interface.h"
#include "SYSCFG_Private.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
/* 
 * Func. Name	: SYSCFG_vdSetExtiLinePort
 * Description	: This function allows the user to choose the Port that a particular EXTI line is connected to
 * I/p Argument	: Copy_u8Line			Options: SYSCFG_LINE_0 -> SYSCFG_LINE_15
 * I/p Argument : Copy_u8Port			Options: SYSCFG_PORT_A -> SYSCFG_PORT_C
 */
void SYSCFG_vdSetExtiLinePort(u8 Copy_u8Line, u8 Copy_u8Port)
{
	/*Variables Definitions*/
	u8 Loc_u8RegisterNum = 0;
	u8 Loc_u8BitNum = 0;

	/*I/p Validation*/
	if ((SYSCFG_PORT_C == Copy_u8Port && SYSCFG_LINE_13 > Copy_u8Line) || SYSCFG_NOT_A_LINE <= Copy_u8Line || SYSCFG_NOT_A_PORT <= Copy_u8Port)
	{
		return;
	}

	/*Choosing Register and Bit*/
	Loc_u8RegisterNum = Copy_u8Line >> 2;
	Loc_u8BitNum = (Copy_u8Line - (Loc_u8RegisterNum << 2)) << 2;

	/*Setting Port*/
	CLR_NIBBLE(SYSCFG_EXTICR_FIRST_ADDRESS[Loc_u8RegisterNum], Loc_u8BitNum);
	SYSCFG_EXTICR_FIRST_ADDRESS[Loc_u8RegisterNum] |= Copy_u8Port << Loc_u8BitNum;
}
