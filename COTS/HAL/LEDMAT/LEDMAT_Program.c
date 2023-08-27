/************************************************************************/
/* SWC			: Seven Segment Driver									*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for LED Matrix									*/
/************************************************************************/

/*Include Needed Files*/
	/*Include Needed Library Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed MCAL Files*/
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"

	/*Include Needed LEDMAT Files*/
#include "LEDMAT_Interface.h"
#include "LEDMAT_Config.h"
#include "LEDMAT_Private.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
/* 
 * Func. Name	: LEDMAT_errInit
 * Description	: This function allows the user to initialize the LED matrix
 * Return		: Error status of function
 */
ErrorStatus LEDMAT_errInit(void)
{
	/*Variables Definitions*/
	ErrorStatus Loc_errReturn = NO_ERROR;
	u8 Loc_u8ColumnLastPin = COLUMN_FIRST_PIN + 7;
	u8 Loc_u8RowLastPin = ROW_FIRST_PIN + 7;

	/*Enable Peripheral for the Ports that the Matrix is connected to*/
	if (GPIO_PORT_A == COLUMN_PORT || GPIO_PORT_A == ROW_PORT)
	{
		Loc_errReturn = RCC_errEnablePeripheralClk(GPIOA);
		RETURN_IF_ERROR(Loc_errReturn);
	}
	if (GPIO_PORT_B == COLUMN_PORT || GPIO_PORT_B == ROW_PORT)
	{
		Loc_errReturn = RCC_errEnablePeripheralClk(GPIOB);
		RETURN_IF_ERROR(Loc_errReturn);
	}

	/*Initializing Column Pins*/
	for (u8 Loc_u8PinCounter = COLUMN_FIRST_PIN; Loc_u8ColumnLastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
	{
		Loc_errReturn = GPIO_errSetPinMode(COLUMN_PORT, Loc_u8PinCounter, GPIO_MODE_OUTPUT);
		RETURN_IF_ERROR(Loc_errReturn);
		Loc_errReturn = GPIO_errSetPinOutputType(COLUMN_PORT, Loc_u8PinCounter, GPIO_OUTPUT_TYPE_PP);
		RETURN_IF_ERROR(Loc_errReturn);
		Loc_errReturn = GPIO_errSetPinOutputSpeed(COLUMN_PORT, Loc_u8PinCounter, GPIO_OUTPUT_SPEED_M);
		RETURN_IF_ERROR(Loc_errReturn);
	}

	/*Initializing Row Pins*/
	for (u8 Loc_u8PinCounter = ROW_FIRST_PIN; Loc_u8RowLastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
	{
		Loc_errReturn = GPIO_errSetPinMode(ROW_PORT, Loc_u8PinCounter, GPIO_MODE_OUTPUT);
		RETURN_IF_ERROR(Loc_errReturn);
		Loc_errReturn = GPIO_errSetPinOutputType(ROW_PORT, Loc_u8PinCounter, GPIO_OUTPUT_TYPE_PP);
		RETURN_IF_ERROR(Loc_errReturn);
		Loc_errReturn = GPIO_errSetPinOutputSpeed(ROW_PORT, Loc_u8PinCounter, GPIO_OUTPUT_SPEED_M);
		RETURN_IF_ERROR(Loc_errReturn);
	}

	/*Clearing Matrix*/
	Loc_errReturn = LEDMAT_errDisableCols();
	RETURN_IF_ERROR(Loc_errReturn);

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: LEDMAT_errDisplay
 * Description	: This function allows the user to display a frame
 * I/p Argument	: Inptr_u8Frame		Options: An array with each element representing a column of pixels
 * 											and each bit representing a pixel in the column
 * Return		: Error status of function
 */
ErrorStatus LEDMAT_errDisplay(const u8* Inptr_u8Frame)
{
	/*Variables Definitions*/
	ErrorStatus Loc_errReturn = NO_ERROR;

	/*Displaying Columns*/
	for (u8 Loc_u8ColCounter = 0; 8 > Loc_u8ColCounter; ++Loc_u8ColCounter)
	{
		/*Disable All Columns*/
		Loc_errReturn = LEDMAT_errDisableCols();
		RETURN_IF_ERROR(Loc_errReturn);

		/*Set Row Value*/
		Loc_errReturn = LEDMAT_errSetColValues(Inptr_u8Frame[Loc_u8ColCounter]);
		RETURN_IF_ERROR(Loc_errReturn);

		/*Enable Column*/
		Loc_errReturn = GPIO_errSetPinValue(COLUMN_PORT, Loc_u8ColCounter, GPIO_VALUE_L);
		RETURN_IF_ERROR(Loc_errReturn);

		/*Delay 2.5ms*/
		Loc_errReturn = STK_errSetWait(2500);
		RETURN_IF_ERROR(Loc_errReturn);
	}

	/*Returning Error Status*/
	return NO_ERROR;
}
/*__________________________________________________________________________________________________________________________________________*/


/*Private Functions Definitions*/
/* 
 * Func. Name	: LEDMAT_errDisableCols
 * Description	: This function is used by the driver to disable all columns
 * Return		: Error status of function
 */
static ErrorStatus LEDMAT_errDisableCols(void)
{
	/*Variables Definitions*/
	ErrorStatus Loc_errReturn = NO_ERROR;
	u8 Loc_u8ColumnLastPin = COLUMN_FIRST_PIN + 7;
	u8 Loc_u8DisablingVal = 0;

	/*Choosing Disabling Value*/
	switch (MATRTIX_POLARITY)
	{
	case ANODE_AT_COLUMNS:
		Loc_u8DisablingVal = GPIO_VALUE_L;
		break;

	case CATHODE_AT_COLUMNS:
		Loc_u8DisablingVal = GPIO_VALUE_H;
		break;
	
	default:
		return INVALID_CONFIGS;
		break;
	}

	/*Disabling Columns*/
	for (u8 Loc_u8PinCounter = COLUMN_FIRST_PIN; Loc_u8ColumnLastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
	{
		Loc_errReturn = GPIO_errSetPinValue(COLUMN_PORT, Loc_u8PinCounter, Loc_u8DisablingVal);
		RETURN_IF_ERROR(Loc_errReturn);
	}

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: LEDMAT_errDisableCols
 * Description	: This function is used by the driver to disable all columns
 * I/p Argument	: Copy_u8Column		Options: An variable representing a column of pixels
 * 											with each bit representing a pixel in the column
 * Return		: Error status of function
 */
static ErrorStatus LEDMAT_errSetColValues(u8 Copy_u8Column)
{
	/*Variables Definitions*/
	ErrorStatus Loc_errReturn = NO_ERROR;
	u8 Loc_u8RowLastPin = ROW_FIRST_PIN + 7;

	/*Setting the Rows in the given Column*/
	switch (MATRTIX_POLARITY)
	{
	case ANODE_AT_COLUMNS:
		for (u8 Loc_u8PinCounter = ROW_FIRST_PIN; Loc_u8RowLastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
		{
			Loc_errReturn = GPIO_errSetPinValue(ROW_PORT, Loc_u8PinCounter, !GET_BIT(Copy_u8Column, 0));
			RETURN_IF_ERROR(Loc_errReturn);
		}
		break;

	case CATHODE_AT_COLUMNS:
		for (u8 Loc_u8PinCounter = ROW_FIRST_PIN; Loc_u8RowLastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
		{
			Loc_errReturn = GPIO_errSetPinValue(ROW_PORT, Loc_u8PinCounter, GET_BIT(Copy_u8Column, 0));
			RETURN_IF_ERROR(Loc_errReturn);
		}
		break;
	
	default:
		return INVALID_CONFIGS;
		break;
	}

	/*Returning Error Status*/
	return NO_ERROR;
}
