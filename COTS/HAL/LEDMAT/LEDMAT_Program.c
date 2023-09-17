/************************************************************************/
/* SWC			: Seven Segment Driver									*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for LED Matrix									*/
/************************************************************************/

/*Include Needed Files*/
	/*Include Needed LIB Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed MCAL Files*/
#include "../../MCAL/RCC/RCC_Interface.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/STK/STK_Interface.h"

	/*Include Needed LEDMAT Files*/
#include "LEDMAT_Config.h"
#include "LEDMAT_Interface.h"
#include "LEDMAT_Private.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
/* 
 * Func. Name	: LEDMAT_vdInit
 * Description	: This function allows the user to initialize the LED matrix
 */
void LEDMAT_vdInit(void)
{
	/*Variables Definitions*/
	u8 Loc_u8ColumnLastPin = COLUMN_FIRST_PIN + 7;
	u8 Loc_u8RowLastPin = ROW_FIRST_PIN + 7;

	/*Enable Peripheral for the Ports that the Matrix is connected to*/
	if (GPIO_PORT_A == COLUMN_PORT || GPIO_PORT_A == ROW_PORT)
	{
		RCC_vdEnablePeripheralClk(RCC_PERIPHERAL_GPIOA);
		
	}
	if (GPIO_PORT_B == COLUMN_PORT || GPIO_PORT_B == ROW_PORT)
	{
		RCC_vdEnablePeripheralClk(RCC_PERIPHERAL_GPIOB);
		
	}

	/*Initializing the System Timer*/
	STK_vdInit();
	
	
	/*Initializing Column Pins*/
	for (u8 Loc_u8PinCounter = COLUMN_FIRST_PIN; Loc_u8ColumnLastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
	{
		GPIO_vdSetPinMode(COLUMN_PORT, Loc_u8PinCounter, GPIO_OUTPUT);
		
		GPIO_vdSetPinOutputType(COLUMN_PORT, Loc_u8PinCounter, GPIO_PUSH_PULL);
		
		GPIO_vdSetPinOutputSpeed(COLUMN_PORT, Loc_u8PinCounter, GPIO_LOW_SPEED);
		
	}

	/*Initializing Row Pins*/
	for (u8 Loc_u8PinCounter = ROW_FIRST_PIN; Loc_u8RowLastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
	{
		GPIO_vdSetPinMode(ROW_PORT, Loc_u8PinCounter, GPIO_OUTPUT);
		
		GPIO_vdSetPinOutputType(ROW_PORT, Loc_u8PinCounter, GPIO_PUSH_PULL);
		
		GPIO_vdSetPinOutputSpeed(ROW_PORT, Loc_u8PinCounter, GPIO_LOW_SPEED);
		
	}

	/*Clearing Matrix*/
	PRIV_vdDisableCols();
}

/* 
 * Func. Name	: LEDMAT_vdDisplay
 * Description	: This function allows the user to display a frame
 * I/p Argument	: Inptr_u8Frame		Options: An array with each element representing a column of pixels
 * 											and each bit representing a pixel in the column
 */
void LEDMAT_vdDisplay(const u8* Inptr_u8Frame)
{
	/*Displaying Columns*/
	for (u8 Loc_u8ColCounter = 0; 8 > Loc_u8ColCounter; ++Loc_u8ColCounter)
	{
		/*Disable All Columns*/
		PRIV_vdDisableCols();
		

		/*Set Row Value*/
		PRIV_vdSetColValues(Inptr_u8Frame[Loc_u8ColCounter]);
		

		/*Enable Column*/
		GPIO_vdSetPinValue(COLUMN_PORT, Loc_u8ColCounter, STD_LOW);
		

		/*Delay 2.5ms*/
		STK_vdSetWait(2500);
		
	}
}
/*__________________________________________________________________________________________________________________________________________*/


/*Private Functions Definitions*/
/* 
 * Func. Name	: PRIV_vdDisableCols
 * Description	: This function is used by the driver to disable all columns
 */
static void PRIV_vdDisableCols(void)
{
	/*Variables Definitions*/
	u8 Loc_u8ColumnLastPin = COLUMN_FIRST_PIN + 7;
	u8 Loc_u8DisablingVal = 0;

	/*Choosing Disabling Value*/
	#if (ANODE_AT_COLUMNS == MATRTIX_POLARITY)
		Loc_u8DisablingVal = GPIO_VALUE_L;
	#elif (CATHODE_AT_COLUMNS == MATRTIX_POLARITY)
		Loc_u8DisablingVal = STD_HIGH;
	#else
		#error Error: Invalid MATRTIX_POLARITY Configuration
	#endif

	/*Disabling Columns*/
	for (u8 Loc_u8PinCounter = COLUMN_FIRST_PIN; Loc_u8ColumnLastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
	{
		GPIO_vdSetPinValue(COLUMN_PORT, Loc_u8PinCounter, Loc_u8DisablingVal);
		
	}
}

/* 
 * Func. Name	: PRIV_vdSetColValues
 * Description	: This function is used by the driver to disable all columns
 * I/p Argument	: Copy_u8Column		Options: An variable representing a column of pixels
 * 											with each bit representing a pixel in the column
 */
static void PRIV_vdSetColValues(u8 Copy_u8Column)
{
	/*Variables Definitions*/
	u8 Loc_u8RowLastPin = ROW_FIRST_PIN + 7;

	/*Setting the Rows in the given Column*/
	#if (ANODE_AT_COLUMNS == MATRTIX_POLARITY)
		for (u8 Loc_u8PinCounter = ROW_FIRST_PIN; Loc_u8RowLastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
		{
			GPIO_vdSetPinValue(ROW_PORT, Loc_u8PinCounter, !GET_BIT(Copy_u8Column, Loc_u8PinCounter));
			
		}
	#elif (CATHODE_AT_COLUMNS == MATRTIX_POLARITY)
		for (u8 Loc_u8PinCounter = ROW_FIRST_PIN; Loc_u8RowLastPin >= Loc_u8PinCounter; ++Loc_u8PinCounter)
		{
			GPIO_vdSetPinValue(ROW_PORT, Loc_u8PinCounter, GET_BIT(Copy_u8Column, Loc_u8PinCounter));
			
		}
	#else
		#error Error: Invalid MATRTIX_POLARITY Configuration
	#endif
}
