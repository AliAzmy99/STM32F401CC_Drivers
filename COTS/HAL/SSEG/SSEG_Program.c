/************************************************************************/
/* SWC			: SSEG Driver											*/
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
	u8 Loc_u8LastPin = Inprt_strctSsegConfig->enmSegFirstPinId + 7;

	/*I/p Validation*/
	if (GPIO_NOT_A_PIN <= Loc_u8LastPin)
	{
		return;
	}

	/*Initialize the Common of the Display*/
	PRIV_vdInitCommon(Inprt_strctSsegConfig);
	
	
	/*Enable Peripheral for the Port that the Display is connected to*/
	RCC_vdEnablePeripheralClk(Glob_u8Peripheral[Inprt_strctSsegConfig->enmSegPortId]);
	

	/*Configure the Pins that the Display is connected to*/
	for (u8 Loc_u8PinCounter = Inprt_strctSsegConfig->enmSegFirstPinId; Loc_u8LastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
	{
		GPIO_vdSetPinMode(Inprt_strctSsegConfig->enmSegPortId, Loc_u8PinCounter, GPIO_OUTPUT);
		
		GPIO_vdSetPinOutputType(Inprt_strctSsegConfig->enmSegPortId, Loc_u8PinCounter, GPIO_PUSH_PULL);
		
		GPIO_vdSetPinOutputSpeed(Inprt_strctSsegConfig->enmSegPortId, Loc_u8PinCounter, GPIO_LOW_SPEED);
		
	}
	
	/*Clearing Display*/
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
	switch (Inprt_strctSsegConfig->enmPolarity)
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
	switch (Inprt_strctSsegConfig->enmCommPortId)
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
 * I/p Argument	: Copy_enmEnable
 */
void SSEG_vdEnable(const SsegConfig_type* Inprt_strctSsegConfig, Enable_type Copy_enmEnable)
{
	/*Enable the Seven Segment from the Common*/
	switch (Inprt_strctSsegConfig->enmPolarity)
	{
	case SSEG_COMM_CATHODE:
		switch (Copy_enmEnable)
		{
		case STD_DISABLE:
			return GPIO_vdSetPinValueDirectAccess(Inprt_strctSsegConfig->enmCommPortId, Inprt_strctSsegConfig->enmCommPinId, STD_HIGH);
			break;
		case STD_ENABLE:
			return GPIO_vdSetPinValueDirectAccess(Inprt_strctSsegConfig->enmCommPortId, Inprt_strctSsegConfig->enmCommPinId, STD_LOW);
			break;
		default:
			return;
			break;
		}
		break;
	
	case SSEG_COMM_ANODE:
		switch (Copy_enmEnable)
		{
		case STD_DISABLE:
			return GPIO_vdSetPinValueDirectAccess(Inprt_strctSsegConfig->enmCommPortId, Inprt_strctSsegConfig->enmCommPinId, STD_LOW);
			break;
		case STD_ENABLE:
			return GPIO_vdSetPinValueDirectAccess(Inprt_strctSsegConfig->enmCommPortId, Inprt_strctSsegConfig->enmCommPinId, STD_HIGH);
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
	u8 Loc_u8LastPin = Inprt_strctSsegConfig->enmSegFirstPinId + 7;

	/*I/p Validation*/
	if (GPIO_NOT_A_PIN <= Loc_u8LastPin)
	{
		return;
	}
	
	/*Writing LEDs*/
	for (u8 Loc_u8PinCounter = Inprt_strctSsegConfig->enmSegFirstPinId; Loc_u8LastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
	{
		GPIO_vdSetPinValue(Inprt_strctSsegConfig->enmSegPortId, Loc_u8PinCounter, GET_BIT(Copy_u8LedArray, Loc_u8PinCounter));
		
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
	if (GPIO_NOT_A_PORT > Inprt_strctSsegConfig->enmCommPortId && GPIO_NOT_A_PIN > Inprt_strctSsegConfig->enmCommPinId)
	{
		if (GPIO_PORT_C == Inprt_strctSsegConfig->enmCommPortId && GPIO_PIN_13 > Inprt_strctSsegConfig->enmCommPinId)
		{
			return;
		}
		
		/*Enable Peripheral for the Port that the Common is Connected to*/
		RCC_vdEnablePeripheralClk(Glob_u8Peripheral[Inprt_strctSsegConfig->enmCommPortId]);
		

		/*Configure the Pin that the Common is Connected to*/
		GPIO_vdSetPinMode(Inprt_strctSsegConfig->enmCommPortId, Inprt_strctSsegConfig->enmCommPinId, GPIO_OUTPUT);
		
		GPIO_vdSetPinOutputType(Inprt_strctSsegConfig->enmCommPortId, Inprt_strctSsegConfig->enmCommPinId, GPIO_PUSH_PULL);
		
		GPIO_vdSetPinOutputSpeed(Inprt_strctSsegConfig->enmCommPortId, Inprt_strctSsegConfig->enmCommPinId, GPIO_LOW_SPEED);
		

		/*Enable the Seven Segment from the Common*/
		switch (Inprt_strctSsegConfig->enmPolarity)
		{
		case SSEG_COMM_CATHODE:
			GPIO_vdSetPinValueDirectAccess(Inprt_strctSsegConfig->enmCommPortId, Inprt_strctSsegConfig->enmCommPinId, STD_LOW);
			break;
		case SSEG_COMM_ANODE:
			GPIO_vdSetPinValueDirectAccess(Inprt_strctSsegConfig->enmCommPortId, Inprt_strctSsegConfig->enmCommPinId, STD_HIGH);
			break;
		default:
			return;
			break;
		}
		
	}
	else if (GPIO_NOT_A_PORT == Inprt_strctSsegConfig->enmCommPortId && GPIO_NOT_A_PIN == Inprt_strctSsegConfig->enmCommPinId)
	{
		/*Do nothing*/
	}
	else
	{
		return;
	}
}
