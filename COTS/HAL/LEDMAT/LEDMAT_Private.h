/************************************************************************/
/* SWC			: LEDMAT Driver											*/
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
 * Func. Name	: PRIV_vdDisableCols
 * Description	: This function is used by the driver to disable all columns
 */
static void PRIV_vdDisableCols(void);

/* 
 * Func. Name	: PRIV_vdSetColValues
 * Description	: This function is used by the driver to disable all columns
 * I/p Argument	: Copy_u8Column		Options: An variable representing a column of pixels
 * 											with each bit representing a pixel in the column
 */
static void PRIV_vdSetColValues(u8 Copy_u8Column);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*LEDMAT_PRIVATE_H*/
