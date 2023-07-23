/************************************************************************/
/* SWC  	    : RCC Driver                                            */
/* Author	    : Ali Azmy                                              */
/* Version	    : V0.0                                                  */
/* Date 	    : 21 Jul 2023                                           */
/* Description  : SWC for Reset and Clock Control                       */
/************************************************************************/


#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


/*Choose RCC Preferences*/
    /*RCC CLK SRC*/
#define RCC_CLK_SRC     HSI     /*Options: HSI, HSE, PLL*/

    /*PLL Configuration*/
#define PLLM    (u)
#define PLLN    (u)
#define PLLP    (u)
#define PLLQ    (u)
/*__________________________________________________________________________________________________________________________________________*/


#endif /*RCC_CONFIG_H*/
