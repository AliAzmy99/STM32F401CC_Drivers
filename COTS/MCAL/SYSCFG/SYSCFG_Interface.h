/************************************************************************/
/* SWC  	    : SYSCFG Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for System Configuration Controller				*/
/************************************************************************/


#ifndef SYSCFG_INTERFACE_H
#define SYSCFG_INTERFACE_H


/*Include Needed MCAL Files*/
#include "../EXTI/EXTI_Interface.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: SYSCFG_vdSetExtiLinePort
 * Description	: This function allows the user to choose the Port that a particular EXTI line is connected to
 * I/p Argument	: Copy_enmLineId
 * I/p Argument : Copy_enmPortId
 */
void SYSCFG_vdSetExtiLinePort(LineId_type Copy_enmLineId, PortId_type Copy_enmPortId);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*SYSCFG_INTERFACE_H*/
