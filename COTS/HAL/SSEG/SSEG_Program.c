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
 * Func. Name   : SSEG_errInit
 * Description  : This function allows the user to select the mode of the mode of any pin
 * I/p Argument : Copy_u8PortId		Options: GPIO_PORT_A -> GPIO_PORT_C
 * I/p Argument : Copy_u8PinId		Options: GPIO_PIN_0 -> GPIO_PIN_15
 * I/p Argument : Copy_u8PinMode	Options: GPIO_MODE_INPUT, GPIO_MODE_OUTPUT, GPIO_MODE_ALT_FUN, GPIO_MODE_ANALOG
 * Return 	    : Error status of function
 */
/* 
 * Function	: _7SEG_esInit_7SEG			: Initialize the Seven Segment Display
 * Input1 	: copy__7SEGConfig_Input   : Configuration Structure of the Seven Segment to control
 * Return 	: 					        : Error Status of function
 */
ErrorStatus SSEG_errInit(SSEG_ConfigStruct Copy_SSEG_ConfigStruct)
{
	ErrorStatus Loc_esReturn = NO_ERROR;

	if (Comm_Not_Connected > copy__7SEGConfig_Input.Loc_u8CommPort)
	{
		/*Enable Peripheral for the Port the Common is connected to*/
		Loc_esReturn = RCC_voidEnablePeripheralClk(Loc_u8Prei[copy__7SEGConfig_Input.Loc_u8CommPort]);
		RETURN_IF_ERROR(Loc_esReturn);

		/*Set the pin the Common is connected to as output*/
		Loc_esReturn = GPIO_esSetPinMode (copy__7SEGConfig_Input.Loc_u8CommPort, copy__7SEGConfig_Input.Loc_u8CommPin, GPIO_PIN_OUTPUT);
		RETURN_IF_ERROR(Loc_esReturn);
		Loc_esReturn = GPIO_esSetPinOutputType(copy__7SEGConfig_Input.Loc_u8CommPort, copy__7SEGConfig_Input.Loc_u8CommPin, GPIO_PIN_OUTPUT_PUSHPULL);
		RETURN_IF_ERROR(Loc_esReturn);
		Loc_esReturn = GPIO_esSetPinSpeed(copy__7SEGConfig_Input.Loc_u8CommPort, copy__7SEGConfig_Input.Loc_u8CommPin, GPIO_PIN_LOWSPEED);
		RETURN_IF_ERROR(Loc_esReturn);

		/*Set Value as LOW(if common cathod)/HIGH(if common anode) to Enable the Seven Segment*/
		switch (copy__7SEGConfig_Input.Loc_u8CommType)
		{
		case _7SEG_Comm_CATHODE:		Loc_esReturn = GPIO_esSetPinValue (copy__7SEGConfig_Input.Loc_u8CommPort, copy__7SEGConfig_Input.Loc_u8CommPin, GPIO_PIN_LOW);	break;
		case _7SEG_Comm_ANODE:		Loc_esReturn = GPIO_esSetPinValue (copy__7SEGConfig_Input.Loc_u8CommPort, copy__7SEGConfig_Input.Loc_u8CommPin, GPIO_PIN_HIGH);	break;
		default:					return INVALID_PARAMETERS;		break;
		}
		RETURN_IF_ERROR(Loc_esReturn);
	}
	else if (Comm_Not_Connected == copy__7SEGConfig_Input.Loc_u8CommPort)
	{
		/*Do nothing*/
	}
	else
	{
		return INVALID_PARAMETERS;
	}
	
	/*Enable Peripheral for the Port the Seven Segment is connected to*/
	Loc_esReturn = RCC_voidEnablePeripheralClk(Loc_u8Prei[copy__7SEGConfig_Input.Loc_u8SEGPort]);
	RETURN_IF_ERROR(Loc_esReturn);
	/*Set the pins the Seven Segment is connected to as output*/
	for (u8 i=0; 1<7; i++)
	{
		Loc_esReturn = GPIO_esSetPinMode (copy__7SEGConfig_Input.Loc_u8SEGPort,i,GPIO_PIN_OUTPUT);
		RETURN_IF_ERROR(Loc_esReturn);
		Loc_esReturn = GPIO_esSetPinOutputType(copy__7SEGConfig_Input.Loc_u8SEGPort, i, GPIO_PIN_OUTPUT_PUSHPULL);
		RETURN_IF_ERROR(Loc_esReturn);
		Loc_esReturn = GPIO_esSetPinSpeed(copy__7SEGConfig_Input.Loc_u8SEGPort, i, GPIO_PIN_LOWSPEED);
		RETURN_IF_ERROR(Loc_esReturn);
	}
	return NO_ERROR;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/* 
 * Function	: _7SEG_esSetNumber			: Displays a number on a Seven Segment Display
 * Input1 	: copy__7SEGConfig_Input  	: Configuration Structure of the Seven Segment to control
 * Input2 	: copy_u8Number			   	: Number to display on Seven Segment
 * Input3 	: copy_u8DOT_stat		   	: Whether or not to print the dot
 * Return 	: 					        : Error Status of function
 */
ErrorStatus _7SEG_esSetNumber(_7SEG_Config copy__7SEGConfig_Input, u8 copy_u8Number, u8 copy_u8DOT_stat)
{
	switch (copy__7SEGConfig_Input.Loc_u8CommType)
	{
	case _7SEG_Comm_CATHODE:
		switch (copy_u8DOT_stat)
		{
		case DOT_OFF:	return _7SEG_esWriteNum(copy__7SEGConfig_Input.Loc_u8SEGPort, Loc_u8Num[copy_u8Number]);			break;
		case DOT_ON:	return _7SEG_esWriteNum(copy__7SEGConfig_Input.Loc_u8SEGPort, Loc_u8NumwDOT[copy_u8Number]);		break;
		default:		return INVALID_PARAMETERS;
		}
		break;
	case _7SEG_Comm_ANODE:
		switch (copy_u8DOT_stat)
		{
		case DOT_OFF:	return _7SEG_esWriteNum(copy__7SEGConfig_Input.Loc_u8SEGPort, ~Loc_u8Num[copy_u8Number]);			break;
		case DOT_ON:	return _7SEG_esWriteNum(copy__7SEGConfig_Input.Loc_u8SEGPort, ~Loc_u8NumwDOT[copy_u8Number]);		break;
		default:		return INVALID_PARAMETERS;
		}
		break;
	default:			return INVALID_PARAMETERS;
	}
	return NO_ERROR;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/* 
 * Function	: _7SEG_esClrNumber			: Clears all LEDs on the Seven Segment
 * Input1 	: copy__7SEGConfig_Input  	: Configuration Structure of the Seven Segment to control
 * Return 	: 					        : Error Status of function
 */
ErrorStatus _7SEG_esClrNumber(_7SEG_Config copy__7SEGConfig_Input)
{
	switch (copy__7SEGConfig_Input.Loc_u8CommPort)
	{
	case _7SEG_Comm_CATHODE:		return _7SEG_esWriteNum(copy__7SEGConfig_Input.Loc_u8SEGPort, CLEAR);			break;
	case _7SEG_Comm_ANODE:		return _7SEG_esWriteNum(copy__7SEGConfig_Input.Loc_u8SEGPort, ~CLEAR);		break;
	default:					return INVALID_PARAMETERS;
	}
	return NO_ERROR;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/* 
 * Function	: _7SEG_esWriteNum	: Turns on/off The appropriate LEDs in the _7SEG based on the required number
 * Input1 	: Copy_u8Port		: Port where the Seven Segment is connected 
 * Input2 	: Copy_u8Number		: The number to display on the Seven Segment 
 * Return 	: 				    : Error Status of function
 */
ErrorStatus _7SEG_esWriteNum(u8 Copy_u8Port, u8 Copy_u8Number)
{
	ErrorStatus Loc_esReturn = NO_ERROR;
	for (u8 i = 0; i < 8; i++)
	{
		Loc_esReturn = GPIO_esSetPinValue(Copy_u8Port, i, GET_BIT(Copy_u8Number,i));
		RETURN_IF_ERROR(Loc_esReturn);
	}
	return NO_ERROR;
}
