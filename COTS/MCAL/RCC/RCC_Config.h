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
/*ADC_REF_VOLTAGE Reference voltage Options*/
    /*
     * ADC_VREF_EXTERNAL		:	External Voltage Reference (reference voltage put through  AREF pin)
     * ADC_VREF_VCC				:	AVCC with external capacitor at AREF pin
     * ADC_VREF_INTERNAL1_1V	:	Internal 1.1V Voltage Reference with external capacitor at AREF pin
     * ADC_VREF_INTERNAL2_56V	:	Internal 2.56V Voltage Reference with external capacitor at AREF pin
     */

        /*Selecting PLL CLK Src*/
#define PLL_CLK_SRC     HSI     /*Options: HSI, HSE*/
    

/*__________________________________________________________________________________________________________________________________________*/


#endif /*RCC_CONFIG_H*/
