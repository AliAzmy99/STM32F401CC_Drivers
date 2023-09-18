/************************************************************************/
/* SWC			: Seven Segment Driver									*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Seven Segment Display							*/
/************************************************************************/


#ifndef NECIR_INTERFACE_H
#define NECIR_INTERFACE_H


/*Types Definitions*/

/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: NECIR_vdInit
 * Description	: This function allows the user to initialize the IR driver
 */
void NECIR_vdInit(void);

/* 
 * Func. Name	: NECIR_vdInit
 * Description	: This function allows the user to initialize the IR driver
 * I/p Argument	: Inptr_vdCallbackFunction	: Pointer to the function to be called when a frame is received.
 * 				  It takes the received byte as an argument.
 */
void NECIR_vdActivateReceiver(void (* Inptr_vdCallbackFunction)(u8 Copy_u8Data));
/*__________________________________________________________________________________________________________________________________________*/


#endif /*NECIR_INTERFACE_H*/
