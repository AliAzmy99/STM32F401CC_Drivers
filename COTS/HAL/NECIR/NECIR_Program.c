/************************************************************************/
/* SWC			: NECIR Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for NEC Infrared Transmission Protocol			*/
/************************************************************************/


/*Include Needed Files*/
	/*Include Needed LIB Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed MCAL Files*/
#include "../../MCAL/STK/STK_Interface.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/EXTI/EXTI_Interface.h"

	/*Include Needed NECIR Files*/
#include "NECIR_Config.h"
#include "NECIR_Interface.h"
#include "NECIR_Private.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
/* 
 * Func. Name	: NECIR_vdInit
 * Description	: This function allows the user to initialize the IR driver
 */
void NECIR_vdInit(LineId_type Copy_enmReceiverLine, PortId_type Copy_enmReceiverPort)
{
	Glob_enmReceiverLine = Copy_enmReceiverLine;

	EXTI_vdInitLine(Copy_enmReceiverLine, Copy_enmReceiverPort, EXTI_FALLING_EDGE, &PRIV_vdReceiveFrame);
	
	GPIO_vdSetPinMode(Copy_enmReceiverPort, Copy_enmReceiverLine, GPIO_INPUT);
	GPIO_vdSetPinPullState(Copy_enmReceiverPort, Copy_enmReceiverLine, GPIO_PULL_UP);
}

/* 
 * Func. Name	: NECIR_vdActivateReceiver
 * Description	: This function allows the user to activate the IR receiver
 * I/p Argument	: Inptr_vdCallbackFunction	: Pointer to the function to be called when a frame is received.
 * 				  It takes the received byte as an argument.
 */
void NECIR_vdActivateReceiver(void (* Inptr_vdCallbackFunction)(u8 Copy_u8Data))
{
	EXTI_vdEnableInterrupt(Glob_enmReceiverLine);
	Globptr_vdCallbackFunction = Inptr_vdCallbackFunction;
}

/* 
 * Func. Name	: NECIR_vdDeactivateReceiver
 * Description	: This function allows the user to deactivate the IR receiver
 */
void NECIR_vdDeactivateReceiver(void)
{
	EXTI_vdDisableInterrupt(Glob_enmReceiverLine);
}
/*__________________________________________________________________________________________________________________________________________*/


/*Private Functions Definitions*/
/* 
 * Func. Name	: PRIV_vdReceiveFrame
 * Description	: This function is used by the driver to receive a frame
 */
static void PRIV_vdReceiveFrame(void)
{
	/*Variables Definitions*/
	static u32 Loc_u32Frame = 0;
	u32 Loc_u32ElapsedTicks = STK_vdGetElapsedTicks;

	/*Receiving Frame*/
	if (STD_FALSE == Glob_enmInTransmission)	/*Startting transmission*/
	{
		STK_vdSetIntervalSingle(75000, &PRIV_vdPrepareForNewFrame);
		Glob_enmInTransmission = STD_TRUE;
	}
	else if (13000 <= Loc_u32ElapsedTicks && 14000 >= Loc_u32ElapsedTicks && Glob_enmInTransmission && (!Glob_enmFrameStarted))		/*Starting frame*/
	{
		Glob_enmFrameStarted = STD_TRUE;
	}
	else if (875 <= Loc_u32ElapsedTicks && 1375 >= Loc_u32ElapsedTicks && Glob_enmFrameStarted)		/*Logical 0*/
	{
		CLR_BIT(Loc_u32Frame, Glob_u8EdgeCounter);
		++Glob_u8EdgeCounter;
	}
	else if (2000 <= Loc_u32ElapsedTicks && 2500 >= Loc_u32ElapsedTicks && Glob_enmFrameStarted)	/*Logical 1*/
	{
		SET_BIT(Loc_u32Frame, Glob_u8EdgeCounter);
		++Glob_u8EdgeCounter;
	}
	else	/*Data corruption*/
	{
		PRIV_vdPrepareForNewFrame();
	}

	/*Ending Transmission*/
	if (32 == Glob_u8EdgeCounter)	/*Frame received*/
	{
		Globptr_vdCallbackFunction(GET_BYTE(Loc_u32Frame, 2));	/*Sending Received byte to callback function*/
		PRIV_vdPrepareForNewFrame();
	}
	else if (32 < Glob_u8EdgeCounter)	/*Receiving failed*/
	{
		PRIV_vdPrepareForNewFrame();
	}
	else
	{
		/*Continue Receiving Frame*/
	}
}

/* 
 * Func. Name	: PRIV_vdPrepareForNewFrame
 * Description	: This function is used by the driver to reset the variables used by PRIV_vdReceiveFrame
 * 				  to prepare it for receiving another frame.
 * Use Case		: This function is called when the entire frame is received or when the transmission fails
 */
static void PRIV_vdPrepareForNewFrame(void)
{
	STK_vdStop();
	Glob_enmInTransmission = STD_FALSE;
	Glob_enmFrameStarted = STD_FALSE;
	Glob_u8EdgeCounter = 0;
}
