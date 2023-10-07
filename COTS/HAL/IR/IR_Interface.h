/************************************************************************/
/* SWC			: IR Driver												*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for NEC Infrared Transmission Protocol			*/
/************************************************************************/


#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H


/*Public Functions Declarations*/
/* 
 * Func. Name	: IR_vdInit
 * Description	: This function allows the user to initialize the IR driver
 */
void IR_vdInit(LineId_type Copy_enmReceiverLine, PortId_type Copy_enmReceiverPort);

/* 
 * Func. Name	: IR_vdActivateReceiver
 * Description	: This function allows the user to activate the IR receiver
 * I/p Argument	: Inptr_vdCallbackFunction	: Pointer to the function to be called when a frame is received.
 * 				  It takes the received byte as an argument.
 */
void IR_vdActivateReceiver(void (* Inptr_vdCallbackFunction)(u8 Copy_u8Data));

/* 
 * Func. Name	: IR_vdDeactivateReceiver
 * Description	: This function allows the user to deactivate the IR receiver
 */
void IR_vdDeactivateReceiver(void);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*IR_INTERFACE_H*/
