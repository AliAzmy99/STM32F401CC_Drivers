/************************************************************************/
/* SWC			: Seven Segment Driver									*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Seven Segment Display							*/
/************************************************************************/


#ifndef NECIR_PRIVATE_H
#define NECIR_PRIVATE_H


/*Private Global Variables Definitions*/
static void (* Globptr_vdCallbackFunction)(u8 Copy_u8Data) = NULL;	/*The callback function called when a frame is received*/
static LineId_type Glob_enmReceiverLine = EXTI_LINE_0;
static True_type Glob_enmInTransmission = STD_FALSE;
static True_type Glob_enmFrameStarted = STD_FALSE;
static u8 Glob_u8EdgeCounter = 0;
/*__________________________________________________________________________________________________________________________________________*/


/*Private Functions Declarations*/
/* 
 * Func. Name	: PRIV_vdReceiveFrame
 * Description	: This function is used by the driver to receive a frame
 */
static void PRIV_vdReceiveFrame(void);

/* 
 * Func. Name	: PRIV_vdReceiveFrame
 * Description	: This function is used by the driver to reset the variables used by PRIV_vdReceiveFrame
 * 				  to prepare it for receiving another frame.
 * Use Case		: This function is called when the entire frame is received or when the transmission fails
 */
static void PRIV_vdPrepareForNewFrame(void);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*NECIR_PRIVATE_H*/
