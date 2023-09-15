/************************************************************************/
/* SWC			: Seven Segment Driver									*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Seven Segment Display							*/
/************************************************************************/

/*Include Needed Files*/
	/*Include Needed LIB Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed MCAL Files*/
#include "../../MCAL/RCC/RCC_Interface.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"

	/*Include Needed SSEG Files*/
#include "SSEG_Config.h"
#include "SSEG_Interface.h"
#include "SSEG_Private.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
/* 
 * Func. Name	: SSEG_vdInit
 * Description	: This function allows the user to initialize the seven segment display
 * I/p Argument	: Inprt_strctSsegConfig
 */
void SSEG_vdInit(const SsegConfig_type* Inprt_strctSsegConfig)
{
	/*Variables Definitions*/
	u8 Loc_u8LastPin = Inprt_strctSsegConfig->Loc_u8SegFirstPin + 7;

	/*I/p Validation*/
	if (SSEG_NOT_A_PIN <= Loc_u8LastPin)
	{
		return;
	}

	/*Initialize the Common of the Display*/
	PRIV_vdInitCommon(Inprt_strctSsegConfig);
	
	
	/*Enable Peripheral for the Port that the Display is connected to*/
	RCC_vdEnablePeripheralClk(Glob_u8Peripheral[Inprt_strctSsegConfig->Loc_u8SegPort]);
	

	/*Configure the Pins that the Display is connected to*/
	for (u8 Loc_u8PinCounter = Inprt_strctSsegConfig->Loc_u8SegFirstPin; Loc_u8LastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
	{
		GPIO_vdSetPinMode(Inprt_strctSsegConfig->Loc_u8SegPort, Loc_u8PinCounter, GPIO_MODE_OUTPUT);
		
		GPIO_vdSetPinOutputType(Inprt_strctSsegConfig->Loc_u8SegPort, Loc_u8PinCounter, GPIO_OUTPUT_TYPE_PP);
		
		GPIO_vdSetPinOutputSpeed(Inprt_strctSsegConfig->Loc_u8SegPort, Loc_u8PinCounter, GPIO_OUTPUT_SPEED_L);
		
	}
	
	/*Cleating Display*/
	return SSEG_vdClear(Inprt_strctSsegConfig);
}

/* 
 * Func. Name	: SSEG_vdDisplayNumber
 * Description	: This function allows the user to display a number on the seven segment display
 * I/p Argument	: Inprt_strctSsegConfig
 * I/p Argument	: Copy_u8Number				Options: 0 -> 9
 * I/p Argument	: Copy_u8DotState			Options: DOT_OFF, DOT_ON
 */
void SSEG_vdDisplayNumber(const SsegConfig_type* Inprt_strctSsegConfig, u8 Copy_u8Number, u8 Copy_u8DotState)
{
	switch (Inprt_strctSsegConfig->Loc_u8Type)
	{
	case SSEG_COMM_CATHODE:
		switch (Copy_u8DotState)
		{
		case SSEG_DOT_OFF:
			return PRIV_vdWriteLeds(Inprt_strctSsegConfig, Glob_u8Num[Copy_u8Number]);
			break;
		case SSEG_DOT_ON:
			return PRIV_vdWriteLeds(Inprt_strctSsegConfig, Glob_u8NumwDot[Copy_u8Number]);
			break;
		default:
			return;
			break;
		}
		break;

	case SSEG_COMM_ANODE:
		switch (Copy_u8DotState)
		{
		case SSEG_DOT_OFF:
			return PRIV_vdWriteLeds(Inprt_strctSsegConfig, ~Glob_u8Num[Copy_u8Number]);
			break;
		case SSEG_DOT_ON:
			return PRIV_vdWriteLeds(Inprt_strctSsegConfig, ~Glob_u8NumwDot[Copy_u8Number]);
			break;
		default:
			return;
			break;
		}
		break;

	default:
		return;
		break;
	}
}

/* 
 * Func. Name	: SSEG_vdClear
 * Description	: This function allows the user to clear the seven segment display
 * I/p Argument	: Inprt_strctSsegConfig
 */
void SSEG_vdClear(const SsegConfig_type* Inprt_strctSsegConfig)
{
	switch (Inprt_strctSsegConfig->Loc_u8CommPort)
	{
	case SSEG_COMM_CATHODE:
		return PRIV_vdWriteLeds(Inprt_strctSsegConfig, CLEAR);
		break;

	case SSEG_COMM_ANODE:
		return PRIV_vdWriteLeds(Inprt_strctSsegConfig, ~CLEAR);
		break;
	default:
		return;
		break;
	}
}

/* 
 * Func. Name	: SSEG_vdEnable
 * Description	: This function allows the user to enable or disable the seven segment display
 * I/p Argument	: Inprt_strctSsegConfig
 * I/p Argument	: Copy_u8Enable				Options: SSEG_DISABLE, SSEG_ENABLE
 */
void SSEG_vdEnable(const SsegConfig_type* Inprt_strctSsegConfig, u8 Copy_u8Enable)
{
	/*Enable the Seven Segment from the Common*/
	switch (Inprt_strctSsegConfig->Loc_u8Type)
	{
	case SSEG_COMM_CATHODE:
		switch (Copy_u8Enable)
		{
		case SSEG_DISABLE:
			return GPIO_vdSetPinValueDirectAccess(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_SET);
			break;
		case SSEG_ENABLE:
			return GPIO_vdSetPinValueDirectAccess(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_RST);
			break;
		default:
			return;
			break;
		}
		break;
	
	case SSEG_COMM_ANODE:
		switch (Copy_u8Enable)
		{
		case SSEG_DISABLE:
			return GPIO_vdSetPinValueDirectAccess(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_RST);
			break;
		case SSEG_ENABLE:
			return GPIO_vdSetPinValueDirectAccess(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_SET);
			break;
		default:
			return;
			break;
		}
		break;
	
	default:
		return;
		break;
	}
}
/*__________________________________________________________________________________________________________________________________________*/


/*Private Functions Definitions*/
/* 
 * Func. Name	: PRIV_vdWriteLeds
 * Description	: This function is used by the driver to write set/rst LEDs in the display as needed
 * I/p Argument	: Inprt_strctSsegConfig
 * I/p Argument	: Copy_u8LedArray
 */
static void PRIV_vdWriteLeds(const SsegConfig_type* Inprt_strctSsegConfig, u8 Copy_u8LedArray)
{
	/*Variables Definitions*/
	u8 Loc_u8LastPin = Inprt_strctSsegConfig->Loc_u8SegFirstPin + 7;

	/*I/p Validation*/
	if (SSEG_NOT_A_PIN <= Loc_u8LastPin)
	{
		return;
	}
	
	/*Writing LEDs*/
	for (u8 Loc_u8PinCounter = Inprt_strctSsegConfig->Loc_u8SegFirstPin; Loc_u8LastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
	{
		GPIO_vdSetPinValue(Inprt_strctSsegConfig->Loc_u8SegPort, Loc_u8PinCounter, GET_BIT(Copy_u8LedArray, Loc_u8PinCounter));
		
	}
}

/* 
 * Func. Name	: PRIV_vdInitCommon
 * Description	: This function is used by the driver to initialize the common of the display
 * I/p Argument	: Inprt_strctSsegConfig
 * I/p Argument	: Copy_u8LedArray
 */
static void PRIV_vdInitCommon(const SsegConfig_type* Inprt_strctSsegConfig)
{
	/*Initialize the Common if it is Connected to the MCU*/
	if (SSEG_EXTERNAL_COMM > Inprt_strctSsegConfig->Loc_u8CommPort)
	{
		/*Enable Peripheral for the Port that the Common is Connected to*/
		RCC_vdEnablePeripheralClk(Glob_u8Peripheral[Inprt_strctSsegConfig->Loc_u8CommPort]);
		

		/*Configure the Pin that the Common is Connected to*/
		GPIO_vdSetPinMode(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_MODE_OUTPUT);
		
		GPIO_vdSetPinOutputType(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_OUTPUT_TYPE_PP);
		
		GPIO_vdSetPinOutputSpeed(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_OUTPUT_SPEED_L);
		

		/*Enable the Seven Segment from the Common*/
		switch (Inprt_strctSsegConfig->Loc_u8Type)
		{
		case SSEG_COMM_CATHODE:
			GPIO_vdSetPinValueDirectAccess(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_RST);
			break;
		case SSEG_COMM_ANODE:
			GPIO_vdSetPinValueDirectAccess(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_SET);
			break;
		default:
			return;
			break;
		}
		
	}
	else if (SSEG_EXTERNAL_COMM == Inprt_strctSsegConfig->Loc_u8CommPort)
	{
		/*Do nothing*/
	}
	else
	{
		return;
	}
}
