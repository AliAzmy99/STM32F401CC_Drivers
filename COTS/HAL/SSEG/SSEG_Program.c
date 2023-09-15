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
 * Func. Name	: SSEG_errInit
 * Description	: This function allows the user to initialize the seven segment display
 * I/p Argument	: Inprt_strctSsegConfig
 * Return		: Error status of function
 */
ErrorStatus SSEG_errInit(const SsegConfig_type* Inprt_strctSsegConfig)
{
	/*Variables Definitions*/
	ErrorStatus Loc_errReturn = NO_ERROR;
	u8 Loc_u8LastPin = Inprt_strctSsegConfig->Loc_u8SegFirstPin + 7;

	/*I/p Validation*/
	if (SSEG_NOT_A_PIN <= Loc_u8LastPin)
	{
		return INVALID_PARAMETERS;
	}

	/*Initialize the Common of the Display*/
	Loc_errReturn = PRIV_errInitCommon(Inprt_strctSsegConfig);
	RETURN_IF_ERROR(Loc_errReturn);
	
	/*Enable Peripheral for the Port that the Display is connected to*/
	Loc_errReturn = RCC_errEnablePeripheralClk(Glob_u8Peripheral[Inprt_strctSsegConfig->Loc_u8SegPort]);
	RETURN_IF_ERROR(Loc_errReturn);

	/*Configure the Pins that the Display is connected to*/
	for (u8 Loc_u8PinCounter = Inprt_strctSsegConfig->Loc_u8SegFirstPin; Loc_u8LastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
	{
		Loc_errReturn = GPIO_errSetPinMode(Inprt_strctSsegConfig->Loc_u8SegPort, Loc_u8PinCounter, GPIO_MODE_OUTPUT);
		RETURN_IF_ERROR(Loc_errReturn);
		Loc_errReturn = GPIO_errSetPinOutputType(Inprt_strctSsegConfig->Loc_u8SegPort, Loc_u8PinCounter, GPIO_OUTPUT_TYPE_PP);
		RETURN_IF_ERROR(Loc_errReturn);
		Loc_errReturn = GPIO_errSetPinOutputSpeed(Inprt_strctSsegConfig->Loc_u8SegPort, Loc_u8PinCounter, GPIO_OUTPUT_SPEED_L);
		RETURN_IF_ERROR(Loc_errReturn);
	}
	
	/*Cleating Display*/
	return SSEG_errClear(Inprt_strctSsegConfig);
}

/* 
 * Func. Name	: SSEG_errDisplayNumber
 * Description	: This function allows the user to display a number on the seven segment display
 * I/p Argument	: Inprt_strctSsegConfig
 * I/p Argument	: Copy_u8Number				Options: 0 -> 9
 * I/p Argument	: Copy_u8DotState			Options: DOT_OFF, DOT_ON
 * Return		: Error status of function
 */
ErrorStatus SSEG_errDisplayNumber(const SsegConfig_type* Inprt_strctSsegConfig, u8 Copy_u8Number, u8 Copy_u8DotState)
{
	switch (Inprt_strctSsegConfig->Loc_u8Type)
	{
	case SSEG_COMM_CATHODE:
		switch (Copy_u8DotState)
		{
		case SSEG_DOT_OFF:
			return PRIV_errWriteLeds(Inprt_strctSsegConfig, Glob_u8Num[Copy_u8Number]);
			break;
		case SSEG_DOT_ON:
			return PRIV_errWriteLeds(Inprt_strctSsegConfig, Glob_u8NumwDot[Copy_u8Number]);
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
			return PRIV_errWriteLeds(Inprt_strctSsegConfig, ~Glob_u8Num[Copy_u8Number]);
			break;
		case SSEG_DOT_ON:
			return PRIV_errWriteLeds(Inprt_strctSsegConfig, ~Glob_u8NumwDot[Copy_u8Number]);
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

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: SSEG_errClear
 * Description	: This function allows the user to clear the seven segment display
 * I/p Argument	: Inprt_strctSsegConfig
 * Return		: Error status of function
 */
ErrorStatus SSEG_errClear(const SsegConfig_type* Inprt_strctSsegConfig)
{
	switch (Inprt_strctSsegConfig->Loc_u8CommPort)
	{
	case SSEG_COMM_CATHODE:
		return PRIV_errWriteLeds(Inprt_strctSsegConfig, CLEAR);
		break;

	case SSEG_COMM_ANODE:
		return PRIV_errWriteLeds(Inprt_strctSsegConfig, ~CLEAR);
		break;
	default:
		return INVALID_PARAMETERS;
		break;
	}

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: SSEG_errEnable
 * Description	: This function allows the user to enable or disable the seven segment display
 * I/p Argument	: Inprt_strctSsegConfig
 * I/p Argument	: Copy_u8Enable				Options: SSEG_DISABLE, SSEG_ENABLE
 * Return		: Error status of function
 */
ErrorStatus SSEG_errEnable(const SsegConfig_type* Inprt_strctSsegConfig, u8 Copy_u8Enable)
{
	/*Enable the Seven Segment from the Common*/
	switch (Inprt_strctSsegConfig->Loc_u8Type)
	{
	case SSEG_COMM_CATHODE:
		switch (Copy_u8Enable)
		{
		case SSEG_DISABLE:
			return GPIO_errSetPinValueDirectAccess(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_SET);
			break;
		case SSEG_ENABLE:
			return GPIO_errSetPinValueDirectAccess(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_RST);
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
			return GPIO_errSetPinValueDirectAccess(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_RST);
			break;
		case SSEG_ENABLE:
			return GPIO_errSetPinValueDirectAccess(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_SET);
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

	/*Returning Error Status*/
	return NO_ERROR;
}
/*__________________________________________________________________________________________________________________________________________*/


/*Private Functions Definitions*/
/* 
 * Func. Name	: PRIV_errWriteLeds
 * Description	: This function is used by the driver to write set/rst LEDs in the display as needed
 * I/p Argument	: Inprt_strctSsegConfig
 * I/p Argument	: Copy_u8LedArray
 * Return		: Error status of function
 */
static ErrorStatus PRIV_errWriteLeds(const SsegConfig_type* Inprt_strctSsegConfig, u8 Copy_u8LedArray)
{
	/*Variables Definitions*/
	ErrorStatus Loc_errReturn = NO_ERROR;
	u8 Loc_u8LastPin = Inprt_strctSsegConfig->Loc_u8SegFirstPin + 7;

	/*I/p Validation*/
	if (SSEG_NOT_A_PIN <= Loc_u8LastPin)
	{
		return INVALID_PARAMETERS;
	}
	
	/*Writing LEDs*/
	for (u8 Loc_u8PinCounter = Inprt_strctSsegConfig->Loc_u8SegFirstPin; Loc_u8LastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
	{
		Loc_errReturn = GPIO_errSetPinValue(Inprt_strctSsegConfig->Loc_u8SegPort, Loc_u8PinCounter, GET_BIT(Copy_u8LedArray, Loc_u8PinCounter));
		RETURN_IF_ERROR(Loc_errReturn);
	}
	
	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: PRIV_errInitCommon
 * Description	: This function is used by the driver to initialize the common of the display
 * I/p Argument	: Inprt_strctSsegConfig
 * I/p Argument	: Copy_u8LedArray
 * Return		: Error status of function
 */
static ErrorStatus PRIV_errInitCommon(const SsegConfig_type* Inprt_strctSsegConfig)
{
	/*Variables Definitions*/
	ErrorStatus Loc_errReturn = NO_ERROR;

	/*Initialize the Common if it is Connected to the MCU*/
	if (SSEG_EXTERNAL_COMM > Inprt_strctSsegConfig->Loc_u8CommPort)
	{
		/*Enable Peripheral for the Port that the Common is Connected to*/
		Loc_errReturn = RCC_errEnablePeripheralClk(Glob_u8Peripheral[Inprt_strctSsegConfig->Loc_u8CommPort]);
		RETURN_IF_ERROR(Loc_errReturn);

		/*Configure the Pin that the Common is Connected to*/
		Loc_errReturn = GPIO_errSetPinMode(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_MODE_OUTPUT);
		RETURN_IF_ERROR(Loc_errReturn);
		Loc_errReturn = GPIO_errSetPinOutputType(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_OUTPUT_TYPE_PP);
		RETURN_IF_ERROR(Loc_errReturn);
		Loc_errReturn = GPIO_errSetPinOutputSpeed(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_OUTPUT_SPEED_L);
		RETURN_IF_ERROR(Loc_errReturn);

		/*Enable the Seven Segment from the Common*/
		switch (Inprt_strctSsegConfig->Loc_u8Type)
		{
		case SSEG_COMM_CATHODE:
			Loc_errReturn = GPIO_errSetPinValueDirectAccess(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_RST);
			break;
		case SSEG_COMM_ANODE:
			Loc_errReturn = GPIO_errSetPinValueDirectAccess(Inprt_strctSsegConfig->Loc_u8CommPort, Inprt_strctSsegConfig->Loc_u8CommPin, GPIO_SET);
			break;
		default:
			return INVALID_PARAMETERS;
			break;
		}
		RETURN_IF_ERROR(Loc_errReturn);
	}
	else if (SSEG_EXTERNAL_COMM == Inprt_strctSsegConfig->Loc_u8CommPort)
	{
		/*Do nothing*/
	}
	else
	{
		return INVALID_PARAMETERS;
	}

	/*Returning Error Status*/
	return NO_ERROR;
}
