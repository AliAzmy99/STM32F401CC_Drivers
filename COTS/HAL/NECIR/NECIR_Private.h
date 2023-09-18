/************************************************************************/
/* SWC			: Seven Segment Driver									*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Seven Segment Display							*/
/************************************************************************/


#ifndef NECIR_PRIVATE_H
#define NECIR_PRIVATE_H


/*Private Macros*/

/*__________________________________________________________________________________________________________________________________________*/


/*Private Global Variables Definitions*/
static void (* Globptr_vdCallbackFunction)(u8 Copy_u8Data) = NULL;	/*The callback function called when a frame is received*/
static True_type Glob_enmInTransmission = STD_FALSE;
static True_type Glob_enmFrameStarted = STD_FALSE;
static u8 Glob_u8EdgeCounter = 0;
/*__________________________________________________________________________________________________________________________________________*/


/*Private Functions Declarations*/

/*__________________________________________________________________________________________________________________________________________*/


#endif /*NECIR_PRIVATE_H*/
