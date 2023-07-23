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
#define RCC_CLK_SRC     PLL     /*Options: HSI, HSE, PLL*/

    /*PLL Configuration*/
        /*Choosing PLL Multiplier Parametes*/
#define PLLM    (2u)        /*Options: 2 --> 63*/
#define PLLN    (192u)      /*Options: 192 --> 432*/
#define PLLP    (2u)        /*Options: 2,4,6,8*/
#define PLLQ    (2u)        /*Options: 2 --> 15*/
/*
 * Calculating PLL Frequencies:
 * PLL input Freq = Frecuency of PLL input source                   (chosen in RCC_PLL_SRC) 
 * VCO input freq = PLL input clk freq / PLLM                       (ensure that this freq ranges from 1 to 2 MHz. It is recommended to select a freq of 2 MHz to limit PLL jitter)
 * VCO output freq = VCO input freq × PLLN                          (ensure that thist freq ranges from 192 to 432 MHz)
 * PLL general clk output freq = VCO output freq / PLLP             (ensure that this freq does not exceed 84 MHz)
 * USB,OTG,FS,SDIO,RNG clk output freq = VCO output freq / PLLQ     (ensure that this freq does not exceed 48 MHz)
 */

        /*Selecting PLL CLK Src*/
#define PLL_CLK_SRC     HSI     /*Options: HSI, HSE*/
    

/*__________________________________________________________________________________________________________________________________________*/


#endif /*RCC_CONFIG_H*/
