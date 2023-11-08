/************************************************************************/
/* SWC			: EXTI Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for External Interrupts/Events Controller			*/
/************************************************************************/


#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


/*Public Macros*/
	/*Detected Edge Type*/
typedef enum
{
	EXTI_RISING_EDGE,
	EXTI_FALLING_EDGE,
	EXTI_DUAL_EDGE,
	EXTI_NO_EDGE
}DetectedEdge_type;

	/*Line ID Type*/
typedef enum
{
	EXTI_LINE_0,
	EXTI_LINE_1,
	EXTI_LINE_2,
	EXTI_LINE_3,
	EXTI_LINE_4,
	EXTI_LINE_5,
	EXTI_LINE_6,
	EXTI_LINE_7,
	EXTI_LINE_8,
	EXTI_LINE_9,
	EXTI_LINE_10,
	EXTI_LINE_11,
	EXTI_LINE_12,
	EXTI_LINE_13,
	EXTI_LINE_14,
	EXTI_LINE_15
}LineId_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: EXTI_vdInitLine
 * Description	: This function allows the user to initialize a certain line
 * 				  It also disables the initialized line
 * Note			: To choose which port this line is connected to, use SYSCFG_vdSetExtiLinePort()
 * I/p Argument	: Copy_enmLineId			: Line to initialize
 * I/p Argument	: Copy_enmDetectedEdge		: Edges that trigger the line interrupt
 * I/p Argument	: Inptr_vdCallbackFunction	: Pointer to the function that is called when the line interrupt triggered
 */
void EXTI_vdInitLine(LineId_type Copy_enmLineId, DetectedEdge_type Copy_enmDetectedEdge, void (* Inptr_vdCallbackFunction)(void));

/* 
 * Func. Name	: EXTI_vdEnableInterrupt
 * Description	: This function allows the user to enable a certain interrupt
 * I/p Argument	: Copy_enmLineId
 */
void EXTI_vdEnableInterrupt(LineId_type Copy_enmLineId);

/* 
 * Func. Name	: EXTI_vdDisableInterrupt
 * Description	: This function allows the user to disable a certain interrupt
 * I/p Argument	: Copy_enmLineId
 */
void EXTI_vdDisableInterrupt(LineId_type Copy_enmLineId);

/* 
 * Func. Name	: EXTI_vdTriggerSoftwareInterrupt
 * Description	: This function allows the user to trigger a certain interrupt using software
 * I/p Argument	: Copy_enmLineId
 */
void EXTI_vdTriggerSoftwareInterrupt(LineId_type Copy_enmLineId);

/* 
 * Func. Name	: EXTI_vdGetPending
 * Description	: This function allows the user to know whether a specific interrupt is pending
 * I/p Argument	: Copy_enmLineId
 * O/p Argument : Outptr_enmPending
 */
void EXTI_vdGetPending(LineId_type Copy_enmLineId, True_type* Outptr_enmPending);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*EXTI_INTERFACE_H*/
