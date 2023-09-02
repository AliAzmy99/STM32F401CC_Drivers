/************************************************************************/
/* SWC			: Seven Segment Driver									*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for LED Matrix									*/
/************************************************************************/


#ifndef LEDMAT_PRIVATE_H
#define LEDMAT_PRIVATE_H


/*Private Macros*/
/*Matrix Polarity Options*/
#define ANODE_AT_COLUMNS		(0u)
#define CATHODE_AT_COLUMNS		(1u)
/*__________________________________________________________________________________________________________________________________________*/


/*Private Functions Declarations*/
/* 
 * Func. Name	: PRIV_errDisableCols
 * Description	: This function is used by the driver to disable all columns
 * Return		: Error status of function
 */
static ErrorStatus PRIV_errDisableCols(void);

/* 
 * Func. Name	: PRIV_errSetColValues
 * Description	: This function is used by the driver to disable all columns
 * I/p Argument	: Copy_u8Column		Options: An variable representing a column of pixels
 * 											with each bit representing a pixel in the column
 * Return		: Error status of function
 */
static ErrorStatus PRIV_errSetColValues(u8 Copy_u8Column);
/*__________________________________________________________________________________________________________________________________________*/


/*Configurations Validation*/
#if (GPIO_PORT_A != COLUMN_PORT && GPIO_PORT_B != COLUMN_PORT)
	#error Error: Invalid COLUMN_PORT Configuration
#endif
#if (GPIO_PORT_A != ROW_PORT && GPIO_PORT_B != ROW_PORT)
	#error Error: Invalid ROW_PORT Configuration
#endif
#if (GPIO_PIN_8 < COLUMN_FIRST_PIN)
	#error Error: Invalid COLUMN_FIRST_PIN Configuration
#endif
#if (GPIO_PIN_8 < ROW_FIRST_PIN)
	#error Error: Invalid ROW_FIRST_PIN Configuration
#endif
#if (COLUMN_PORT == ROW_PORT)
	#if (!((0 == COLUMN_FIRST_PIN && 8 == ROW_FIRST_PIN) || (8 == COLUMN_FIRST_PIN && 0 == ROW_FIRST_PIN)))
		#error Error: Columns and Rows Cannot Share Pins
	#endif
#endif
/*__________________________________________________________________________________________________________________________________________*/


#endif /*LEDMAT_PRIVATE_H*/
