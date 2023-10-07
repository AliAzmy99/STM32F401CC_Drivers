/************************************************************************/
/* SWC			: Seven Segment Driver									*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Seven Segment Display							*/
/************************************************************************/


#ifndef NECIR_INTERFACE_H
#define NECIR_INTERFACE_H


/*Public Functions Declarations*/
/* 
 * Func. Name	: NECIR_vdInit
 * Description	: This function allows the user to initialize the IR driver
 */
void NECIR_vdInit(LineId_type Copy_enmReceiverLine, PortId_type Copy_enmReceiverPort);

/* 
 * Func. Name	: NECIR_vdActivateReceiver
 * Description	: This function allows the user to activate the IR receiver
 * I/p Argument	: Inptr_vdCallbackFunction	: Pointer to the function to be called when a frame is received.
 * 				  It takes the received byte as an argument.
 */
void NECIR_vdActivateReceiver(void (* Inptr_vdCallbackFunction)(u8 Copy_u8Data));

/* 
 * Func. Name	: NECIR_vdDeactivateReceiver
 * Description	: This function allows the user to deactivate the IR receiver
 */
void NECIR_vdDeactivateReceiver(void);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*NECIR_INTERFACE_H*/
