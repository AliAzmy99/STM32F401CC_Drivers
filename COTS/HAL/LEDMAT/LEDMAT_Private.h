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
 * Func. Name	: LEDMAT_errDisableCols
 * Description	: This function is used by the module to disable all columns
 * Return		: Error status of function
 */
static ErrorStatus LEDMAT_errDisableCols(void);

/* 
 * Func. Name	: LEDMAT_errDisableCols
 * Description	: This function is used by the module to disable all columns
 * I/p Argument	: Copy_u8Column		Options: An variable representing a column of pixels
 * 											with each bit representing a pixel in the column
 * Return		: Error status of function
 */
static ErrorStatus LEDMAT_errSetColValues(u8 Copy_u8Column);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*LEDMAT_PRIVATE_H*/
