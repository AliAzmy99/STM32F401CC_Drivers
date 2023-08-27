/************************************************************************/
/* SWC			: Seven Segment Driver									*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for LED Matrix									*/
/************************************************************************/


#ifndef LEDMAT_INTERFACE_H
#define LEDMAT_INTERFACE_H


/*Public Functions Declarations*/
/* 
 * Func. Name	: LEDMAT_errInit
 * Description	: This function allows the user to initialize the LED matrix
 * Return		: Error status of function
 */
ErrorStatus LEDMAT_errInit(void);

/* 
 * Func. Name	: LEDMAT_errDisplay
 * Description	: This function allows the user to display a frame
 * I/p Argument	: Inptr_u8Frame		Options: An array with each element representing a column of pixels
 * 											and each bit representing a pixel in the column
 * Return		: Error status of function
 */
ErrorStatus LEDMAT_errDisplay(const u8* Inptr_u8Frame);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*LEDMAT_INTERFACE_H*/
