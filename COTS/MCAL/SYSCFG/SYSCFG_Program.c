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
 * I/p Argument	: Copy_enmLineId
 * I/p Argument : Copy_enmPortId
 */
void SYSCFG_vdSetExtiLinePort(LineId_type Copy_enmLineId, PortId_type Copy_enmPortId)
{
	/*Variables Definitions*/
	u8 Loc_u8RegisterNum = 0;
	u8 Loc_u8NibbleNum = 0;

	/*I/p Validation*/
	if (GPIO_PORT_C == Copy_enmPortId && EXTI_LINE_13 > Copy_enmLineId)
	{
		return;
	}

	/*Choosing Register and Bit*/
	Loc_u8RegisterNum = Copy_enmLineId >> 2;
	Loc_u8NibbleNum = Copy_enmLineId - (Loc_u8RegisterNum << 2);

	/*Setting Port*/
	MAKE_NIBBLE(SYSCFG_EXTICR_FIRST_ADDRESS[Loc_u8RegisterNum], Loc_u8NibbleNum, Copy_enmPortId);
}
