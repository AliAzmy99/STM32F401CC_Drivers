/************************************************************************/
/* SWC  	    : RCC Driver                                            */
/* Author	    : Ali Azmy                                              */
/* Version	    : V0.0                                                  */
/* Date 	    : 21 Jul 2023                                           */
/* Description  : SWC for Reset and Clock Control                       */
/************************************************************************/


#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


/*Public Macros*/
    /*Bus ID Options:*/
#define AHB1    (0u)
#define AHB2    (1u)
#define APB1    (2u)
#define APB2    (3u)
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
void RCC_voidInitSysClk(void);
void RCC_voidEnablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);
void RCC_voidDisanablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*RCC_INTERFACE_H*/
