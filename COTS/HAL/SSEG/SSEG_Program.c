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
 * I/p Argument	: Copy_SSEG_ConfigStruct
 * Return		: Error status of function
 */
ErrorStatus SSEG_errInit(SSEG_ConfigStruct Copy_SSEG_ConfigStruct)
{
	ErrorStatus Loc_errReturn = NO_ERROR;

	if (COMM_CONNECTED_EXTERNALLY > Copy_SSEG_ConfigStruct.Loc_u8CommPort)
	{
		/*Enable Peripheral for the Port that the Common is Connected to*/
		Loc_errReturn = RCC_voidEnablePeripheralClk(Glob_u8Prei[Copy_SSEG_ConfigStruct.Loc_u8CommPort]);
		RETURN_IF_ERROR(Loc_errReturn);

		/*Configure the Pin that the Common is Connected to*/
		Loc_errReturn = GPIO_errSetPinMode (Copy_SSEG_ConfigStruct.Loc_u8CommPort, Copy_SSEG_ConfigStruct.Loc_u8CommPin, GPIO_MODE_OUTPUT);
		RETURN_IF_ERROR(Loc_errReturn);
		Loc_errReturn = GPIO_errSetPinOutputType(Copy_SSEG_ConfigStruct.Loc_u8CommPort, Copy_SSEG_ConfigStruct.Loc_u8CommPin, GPIO_OUTPUT_TYPE_PP);
		RETURN_IF_ERROR(Loc_errReturn);
		Loc_errReturn = GPIO_errSetPinSpeed(Copy_SSEG_ConfigStruct.Loc_u8CommPort, Copy_SSEG_ConfigStruct.Loc_u8CommPin, GPIO_OUTPUT_SPEED_L);
		RETURN_IF_ERROR(Loc_errReturn);

		/*Enable the Seven Segment from the Common*/
		switch (Copy_SSEG_ConfigStruct.Loc_u8Type)
		{
		case SSEG_COMM_CATHODE:
			Loc_errReturn = GPIO_errSetPinValue (Copy_SSEG_ConfigStruct.Loc_u8CommPort, Copy_SSEG_ConfigStruct.Loc_u8CommPin, GPIO_VALUE_L);
			break;
		case SSEG_COMM_ANODE:
			Loc_errReturn = GPIO_errSetPinValue (Copy_SSEG_ConfigStruct.Loc_u8CommPort, Copy_SSEG_ConfigStruct.Loc_u8CommPin, GPIO_VALUE_H);
			break;
		default:
			return INVALID_PARAMETERS;
			break;
		}
		RETURN_IF_ERROR(Loc_errReturn);
	}
	else if (COMM_CONNECTED_EXTERNALLY == Copy_SSEG_ConfigStruct.Loc_u8CommPort)
	{
		/*Do nothing*/
	}
	else
	{
		return INVALID_PARAMETERS;
	}
	
	/*Enable Peripheral for the Port the Seven Segment is connected to*/
	Loc_errReturn = RCC_voidEnablePeripheralClk(Glob_u8Prei[Copy_SSEG_ConfigStruct.Loc_u8SEGPort]);
	RETURN_IF_ERROR(Loc_errReturn);

	/*Set the pins the Seven Segment is connected to as output*/
	for (u8 i=0; 1<7; i++)
	{
		Loc_errReturn = GPIO_errSetPinMode (Copy_SSEG_ConfigStruct.Loc_u8SEGPort, i, GPIO_MODE_OUTPUT);
		RETURN_IF_ERROR(Loc_errReturn);
		Loc_errReturn = GPIO_errSetPinOutputType(Copy_SSEG_ConfigStruct.Loc_u8SEGPort, i, GPIO_OUTPUT_TYPE_PP);
		RETURN_IF_ERROR(Loc_errReturn);
		Loc_errReturn = GPIO_errSetPinSpeed(Copy_SSEG_ConfigStruct.Loc_u8SEGPort, i, GPIO_OUTPUT_SPEED_L);
		RETURN_IF_ERROR(Loc_errReturn);
	}

	return NO_ERROR;
}

/* 
 * Function	: SSEG_errSetNumber			: Displays a number on a Seven Segment Display
 * Input1 	: Copy_SSEG_ConfigStruct  	: Configuration Structure of the Seven Segment to control
 * Input2 	: Copy_u8Number			   	: Number to display on Seven Segment
 * Input3 	: Copy_u8DOT_stat		   	: Whether or not to print the dot
 * Return 	: 					        : Error Status of function
 */
ErrorStatus SSEG_errSetNumber(SSEG_ConfigStruct Copy_SSEG_ConfigStruct, u8 Copy_u8Number, u8 Copy_u8DOT_stat)
{
	switch (Copy_SSEG_ConfigStruct.Loc_u8Type)
	{
	case SSEG_COMM_CATHODE:
		switch (Copy_u8DOT_stat)
		{
		case DOT_OFF:	return SSEG_errWriteNum(Copy_SSEG_ConfigStruct.Loc_u8SEGPort, Glob_u8Num[Copy_u8Number]);			break;
		case DOT_ON:	return SSEG_errWriteNum(Copy_SSEG_ConfigStruct.Loc_u8SEGPort, Glob_u8NumwDOT[Copy_u8Number]);		break;
		default:		return INVALID_PARAMETERS;
		}
		break;

	case SSEG_COMM_ANODE:
		switch (Copy_u8DOT_stat)
		{
		case DOT_OFF:	return SSEG_errWriteNum(Copy_SSEG_ConfigStruct.Loc_u8SEGPort, ~Glob_u8Num[Copy_u8Number]);			break;
		case DOT_ON:	return SSEG_errWriteNum(Copy_SSEG_ConfigStruct.Loc_u8SEGPort, ~Glob_u8NumwDOT[Copy_u8Number]);		break;
		default:		return INVALID_PARAMETERS;
		}
		break;

	default:			return INVALID_PARAMETERS;
	}

	return NO_ERROR;
}

/* 
 * Function	: SSEG_errClrNumber			: Clears all LEDs on the Seven Segment
 * Input1 	: Copy_SSEG_ConfigStruct  	: Configuration Structure of the Seven Segment to control
 * Return 	: 					        : Error Status of function
 */
ErrorStatus SSEG_errClrNumber(SSEG_ConfigStruct Copy_SSEG_ConfigStruct)
{
	switch (Copy_SSEG_ConfigStruct.Loc_u8CommPort)
	{
	case SSEG_COMM_CATHODE:		return SSEG_errWriteNum(Copy_SSEG_ConfigStruct.Loc_u8SEGPort, CLEAR);		break;
	case SSEG_COMM_ANODE:		return SSEG_errWriteNum(Copy_SSEG_ConfigStruct.Loc_u8SEGPort, ~CLEAR);		break;
	default:					return INVALID_PARAMETERS;
	}

	return NO_ERROR;
}

/* 
 * Function	: SSEG_errWriteNum	: Turns on/off The appropriate LEDs in the SSEG based on the required number
 * Input1 	: Copy_u8Port		: Port where the Seven Segment is connected 
 * Input2 	: Copy_u8Number		: The number to display on the Seven Segment 
 * Return 	: 				    : Error Status of function
 */
ErrorStatus SSEG_errWriteNum(u8 Copy_u8Port, u8 Copy_u8Number)
{
	ErrorStatus Loc_errReturn = NO_ERROR;
	for (u8 i = 0; i < 8; i++)
	{
		Loc_errReturn = GPIO_errSetPinValue(Copy_u8Port, i, GET_BIT(Copy_u8Number, i));
		RETURN_IF_ERROR(Loc_errReturn);
	}
	return NO_ERROR;
}
