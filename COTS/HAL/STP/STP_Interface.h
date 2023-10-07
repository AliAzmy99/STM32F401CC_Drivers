/************************************************************************/
/* SWC			: STP Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Serial to Parallel using 74HC595				*/
/************************************************************************/


#ifndef STP_INTERFACE_H
#define STP_INTERFACE_H


/*Public Functions Declarations*/
/* 
 * Func. Name	: STP_vdInit
 * Description	: This function allows the user to initialize the STP driver
 */
void STP_vdInit(void);

/* 
 * Func. Name	: STP_vdSendSynch
 * Description	: This function allows the user to send data synchronously
 * I/p Argument	: Copy_u32Data
 */
void STP_vdSendSynch(u32 Copy_u32Data);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*STP_INTERFACE_H*/
