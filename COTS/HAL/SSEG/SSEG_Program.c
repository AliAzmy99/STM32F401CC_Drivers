/************************************************************************/
/* SWC			: Seven Segment Driver									*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Seven Segment Display							*/
/************************************************************************/

/*Include Needed Files*/
	/*Include Needed Library Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed MCAL Files*/
#include "RCC_Interface.h"
#include "GPIO_Interface.h"

	/*Include Needed SSEG Files*/
#include "SSEG_Interface.h"
#include "SSEG_Private.h"
#include "SSEG_Config.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
/* 
 * Func. Name	: SSEG_errInit
 * Description	: This function allows the user to initialize the seven segment display
 * Note			: Connect the display pins A -> G,Dot to the MCU pins 0 -> 6,7 (FIRST_HALF) or 8 -> 14,15 (SECOND_HALF) respectivly
 * I/p Argument	: Inprt_strctDisplayConfig
 * Return		: Error status of function
 */
ErrorStatus SSEG_errInit(const SSEGConfig_type* Inprt_strctDisplayConfig)
{
	/*Variables Definitions*/
	ErrorStatus Loc_errReturn = NO_ERROR;
	u8 Loc_u8PinCounter = 0;
	u8 Loc_u8LastPin = 0;

	/*Initialize the Common of the Display*/
	Loc_errReturn = SSEG_errInitCommon(Inprt_strctDisplayConfig);
	RETURN_IF_ERROR(Loc_errReturn);
	
	/*Enable Peripheral for the Port that the Display is connected to*/
	Loc_errReturn = RCC_errEnablePeripheralClk(Glob_u8Peripheral[Inprt_strctDisplayConfig->Loc_u8SegPort]);
	RETURN_IF_ERROR(Loc_errReturn);

	/*Choosing Pin Range*/
	switch (Inprt_strctDisplayConfig->Loc_u8SegHalf)
	{
	case SSEG_FIRST_HALF:
		Loc_u8PinCounter = 0;
		Loc_u8LastPin = 7;
		break;
	case SSEG_SECOND_HALF:
		Loc_u8PinCounter = 8;
		Loc_u8LastPin = 15;
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}

	/*Configure the Pins that the Display is connected to*/
	for (; Loc_u8LastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
		{
			Loc_errReturn = GPIO_errSetPinMode(Inprt_strctDisplayConfig->Loc_u8SegPort, Loc_u8PinCounter, GPIO_MODE_OUTPUT);
			RETURN_IF_ERROR(Loc_errReturn);
			Loc_errReturn = GPIO_errSetPinOutputType(Inprt_strctDisplayConfig->Loc_u8SegPort, Loc_u8PinCounter, GPIO_OUTPUT_TYPE_PP);
			RETURN_IF_ERROR(Loc_errReturn);
			Loc_errReturn = GPIO_errSetPinOutputSpeed(Inprt_strctDisplayConfig->Loc_u8SegPort, Loc_u8PinCounter, GPIO_OUTPUT_SPEED_L);
			RETURN_IF_ERROR(Loc_errReturn);
		}
	
	return SSEG_errClear(Inprt_strctDisplayConfig);
}

/* 
 * Func. Name	: SSEG_errDisplayNumber
 * Description	: This function allows the user to display a number on the seven segment display
 * I/p Argument	: Inprt_strctDisplayConfig
 * I/p Argument	: Copy_u8Number				Options: 0 -> 9
 * I/p Argument	: Copy_u8DotState			Options: DOT_OFF, DOT_ON
 * Return		: Error status of function
 */
ErrorStatus SSEG_errDisplayNumber(const SSEGConfig_type* Inprt_strctDisplayConfig, u8 Copy_u8Number, u8 Copy_u8DotState)
{
	switch (Inprt_strctDisplayConfig->Loc_u8Type)
	{
	case SSEG_COMM_CATHODE:
		switch (Copy_u8DotState)
		{
		case SSEG_DOT_OFF:
			return SSEG_errWriteLeds(Inprt_strctDisplayConfig, Glob_u8Num[Copy_u8Number]);
			break;
		case SSEG_DOT_ON:
			return SSEG_errWriteLeds(Inprt_strctDisplayConfig, Glob_u8NumwDot[Copy_u8Number]);
			break;
		default:
			return INVALID_PARAMETERS;
			break;
		}
		break;

	case SSEG_COMM_ANODE:
		switch (Copy_u8DotState)
		{
		case SSEG_DOT_OFF:
			return SSEG_errWriteLeds(Inprt_strctDisplayConfig, ~Glob_u8Num[Copy_u8Number]);
			break;
		case SSEG_DOT_ON:
			return SSEG_errWriteLeds(Inprt_strctDisplayConfig, ~Glob_u8NumwDot[Copy_u8Number]);
			break;
		default:
			return INVALID_PARAMETERS;
			break;
		}
		break;

	default:
		return INVALID_PARAMETERS;
		break;
	}

	return NO_ERROR;
}

/* 
 * Func. Name	: SSEG_errClear
 * Description	: This function allows the user to clear the seven segment display
 * I/p Argument	: Inprt_strctDisplayConfig
 * Return		: Error status of function
 */
ErrorStatus SSEG_errClear(const SSEGConfig_type* Inprt_strctDisplayConfig)
{
	switch (Inprt_strctDisplayConfig->Loc_u8CommPort)
	{
	case SSEG_COMM_CATHODE:
		return SSEG_errWriteLeds(Inprt_strctDisplayConfig, CLEAR);
		break;

	case SSEG_COMM_ANODE:
		return SSEG_errWriteLeds(Inprt_strctDisplayConfig, ~CLEAR);
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}

	return NO_ERROR;
}

/* 
 * Func. Name	: SSEG_errEnable
 * Description	: This function allows the user to enable or disable the seven segment display
 * I/p Argument	: Inprt_strctDisplayConfig
 * I/p Argument	: Copy_u8Enable				Options: SSEG_DISABLE, SSEG_ENABLE
 * Return		: Error status of function
 */
ErrorStatus SSEG_errEnable(const SSEGConfig_type* Inprt_strctDisplayConfig, u8 Copy_u8Enable)
{
	/*Enable the Seven Segment from the Common*/
	switch (Inprt_strctDisplayConfig->Loc_u8Type)
	{
	case SSEG_COMM_CATHODE:
		switch (Copy_u8Enable)
		{
		case SSEG_DISABLE:
			return GPIO_errSetPinValueDirectAccess(Inprt_strctDisplayConfig->Loc_u8CommPort, Inprt_strctDisplayConfig->Loc_u8CommPin, GPIO_SET);
			break;
		case SSEG_ENABLE:
			return GPIO_errSetPinValueDirectAccess(Inprt_strctDisplayConfig->Loc_u8CommPort, Inprt_strctDisplayConfig->Loc_u8CommPin, GPIO_RST);
			break;
		default:
			return INVALID_PARAMETERS;
			break;
		}
		break;
	
	case SSEG_COMM_ANODE:
		switch (Copy_u8Enable)
		{
		case SSEG_DISABLE:
			return GPIO_errSetPinValueDirectAccess(Inprt_strctDisplayConfig->Loc_u8CommPort, Inprt_strctDisplayConfig->Loc_u8CommPin, GPIO_RST);
			break;
		case SSEG_ENABLE:
			return GPIO_errSetPinValueDirectAccess(Inprt_strctDisplayConfig->Loc_u8CommPort, Inprt_strctDisplayConfig->Loc_u8CommPin, GPIO_SET);
			break;
		default:
			return INVALID_PARAMETERS;
			break;
		}
		break;
	
	default:
		return INVALID_PARAMETERS;
		break;
	}

	return NO_ERROR;
}
/*__________________________________________________________________________________________________________________________________________*/


/*Private Functions Definitions*/
/* 
 * Func. Name	: SSEG_errWriteLeds
 * Description	: This function is used by the module to write set/rst LEDs in the display as needed
 * I/p Argument	: Inprt_strctDisplayConfig
 * I/p Argument	: Copy_u8LedArray
 * Return		: Error status of function
 */
static ErrorStatus SSEG_errWriteLeds(const SSEGConfig_type* Inprt_strctDisplayConfig, u8 Copy_u8LedArray)
{
	/*Variables Definitions*/
	ErrorStatus Loc_errReturn = NO_ERROR;
	u8 Loc_u8PinCounter = 0;
	u8 Loc_u8LastPin = 0;
	
	/*Choosing Pin Range*/
	switch (Inprt_strctDisplayConfig->Loc_u8SegHalf)
	{
	case SSEG_FIRST_HALF:
		Loc_u8PinCounter = 0;
		Loc_u8LastPin = 7;
		break;
	case SSEG_SECOND_HALF:
		Loc_u8PinCounter = 8;
		Loc_u8LastPin = 15;
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}

	/*Writing LEDs*/
	for (; Loc_u8LastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
	{
		Loc_errReturn = GPIO_errSetPinValue(Inprt_strctDisplayConfig->Loc_u8SegPort, Loc_u8PinCounter, GET_BIT(Copy_u8LedArray, Loc_u8PinCounter));
		RETURN_IF_ERROR(Loc_errReturn);
	}
	return NO_ERROR;
}

/* 
 * Func. Name	: SSEG_errInitHelper
 * Description	: This function is used by the module to initialize the common of the display
 * I/p Argument	: Inprt_strctDisplayConfig
 * I/p Argument	: Copy_u8LedArray
 * Return		: Error status of function
 */
static ErrorStatus SSEG_errInitCommon(const SSEGConfig_type* Inprt_strctDisplayConfig)
{
	/*Variables Definitions*/
	ErrorStatus Loc_errReturn = NO_ERROR;

	/*Initialize the Common if it is Connected to the MCU*/
	if (COMM_CONNECTED_EXTERNALLY > Inprt_strctDisplayConfig->Loc_u8CommPort)
	{
		/*Enable Peripheral for the Port that the Common is Connected to*/
		Loc_errReturn = RCC_errEnablePeripheralClk(Glob_u8Peripheral[Inprt_strctDisplayConfig->Loc_u8CommPort]);
		RETURN_IF_ERROR(Loc_errReturn);

		/*Configure the Pin that the Common is Connected to*/
		Loc_errReturn = GPIO_errSetPinMode(Inprt_strctDisplayConfig->Loc_u8CommPort, Inprt_strctDisplayConfig->Loc_u8CommPin, GPIO_MODE_OUTPUT);
		RETURN_IF_ERROR(Loc_errReturn);
		Loc_errReturn = GPIO_errSetPinOutputType(Inprt_strctDisplayConfig->Loc_u8CommPort, Inprt_strctDisplayConfig->Loc_u8CommPin, GPIO_OUTPUT_TYPE_PP);
		RETURN_IF_ERROR(Loc_errReturn);
		Loc_errReturn = GPIO_errSetPinOutputSpeed(Inprt_strctDisplayConfig->Loc_u8CommPort, Inprt_strctDisplayConfig->Loc_u8CommPin, GPIO_OUTPUT_SPEED_L);
		RETURN_IF_ERROR(Loc_errReturn);

		/*Enable the Seven Segment from the Common*/
		switch (Inprt_strctDisplayConfig->Loc_u8Type)
		{
		case SSEG_COMM_CATHODE:
			Loc_errReturn = GPIO_errSetPinValueDirectAccess(Inprt_strctDisplayConfig->Loc_u8CommPort, Inprt_strctDisplayConfig->Loc_u8CommPin, GPIO_RST);
			break;
		case SSEG_COMM_ANODE:
			Loc_errReturn = GPIO_errSetPinValueDirectAccess(Inprt_strctDisplayConfig->Loc_u8CommPort, Inprt_strctDisplayConfig->Loc_u8CommPin, GPIO_SET);
			break;
		default:
			return INVALID_PARAMETERS;
			break;
		}
		RETURN_IF_ERROR(Loc_errReturn);
	}
	else if (COMM_CONNECTED_EXTERNALLY == Inprt_strctDisplayConfig->Loc_u8CommPort)
	{
		/*Do nothing*/
	}
	else
	{
		return INVALID_PARAMETERS;
	}

	return NO_ERROR;
}
