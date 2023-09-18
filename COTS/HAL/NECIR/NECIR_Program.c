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
void NECIR_vdInit()
{
	EXTI_vdInitLine(NECIR_LINE, NECIR_PORT, EXTI_FALLING_EDGE, &PRIV_vdReceiveFrame);
}

void NECIR_vdActivateReceiver(void (* Inptr_vdCallbackFunction)(u8 Copy_u8Data))
{
	EXTI_vdEnableInterrupt(NECIR_LINE);
	Globptr_vdCallbackFunction = Inptr_vdCallbackFunction;
}
/*__________________________________________________________________________________________________________________________________________*/


#warning decide whether to add checking using the data inverse and to check for your address
/*Private Functions Definitions*/
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
	else if (13000 <= Loc_u32ElapsedTicks && 14000 >= Loc_u32ElapsedTicks && Glob_enmInTransmission)	/*Starting frame*/
	{
		Glob_enmFrameStarted = STD_TRUE;
	}
	else if (875 <= Loc_u32ElapsedTicks && 1375 >= Loc_u32ElapsedTicks && Glob_enmFrameStarted)		/*Logical 1*/
	{
		CLR_BIT(Loc_u32Frame, Glob_u8EdgeCounter);
		++Glob_u8EdgeCounter;
	}
	else if (2000 <= Loc_u32ElapsedTicks && 2500 >= Loc_u32ElapsedTicks && Glob_enmFrameStarted)	/*Logical 0*/
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

/*Called when the entire frame is received or when the transmission fails*/
static void PRIV_vdPrepareForNewFrame(void)
{
	STK_vdStop();
	Glob_enmInTransmission = STD_FALSE;
	Glob_enmFrameStarted = STD_FALSE;
	Glob_u8EdgeCounter = 0;
}
