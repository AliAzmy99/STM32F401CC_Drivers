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
	EXTI_LINE_15,
	EXTI_NOT_A_LINE		/*Must remain the last element*/
}LineId_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: EXTI_vdInitLine
 * Description	: This function allows the user to initialize a certain line
 * I/p Argument	: Copy_enmLineId			: Line to initialize
 * I/p Argument	: Copy_enmPortId			: Port to connect the line to
 * I/p Argument	: Copy_enmDetectedEdge		: Edges that trigger the line interrupt
 * I/p Argument	: Inptr_vdCallbackFunction	: Function that is called when the line interrupt triggered
 */
void EXTI_vdInitLine(LineId_type Copy_enmLineId, PortId_type Copy_enmPortId, DetectedEdge_type Copy_enmDetectedEdge, void (* Inptr_vdCallbackFunction)(void));

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
 * Func. Name	: EXTI_vdSetCallbackFunction
 * Description	: This function allows the user set the callback function that will be called when a certain interrupt line triggers its ISR
 * I/p Argument	: Copy_enmLineId
 * I/p Argument	: Inptr_vdCallbackFunction
 */
void EXTI_vdSetCallbackFunction(LineId_type Copy_enmLineId, void (* Inptr_vdCallbackFunction)(void));

/* 
 * Func. Name	: EXTI_vdSelectEdgeTriggers
 * Description	: This function allows the user to choose which edges trigger a certain interrupt line
 * I/p Argument	: Copy_enmLineId
 * I/p Argument	: Copy_enmDetectedEdge
 */
void EXTI_vdSelectEdgeTriggers(LineId_type Copy_enmLineId, DetectedEdge_type Copy_enmDetectedEdge);

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
