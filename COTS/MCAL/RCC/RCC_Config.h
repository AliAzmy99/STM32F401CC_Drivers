/************************************************************************/
/* SWC			: RCC Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.2													*/
/* Description	: SWC for Reset and Clock Control						*/
/************************************************************************/


#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


/*CLK Src Configuration*/
	/*CLK Src*/
#define RCC_CLK_SRC		HSI							/*Options: HSI, HSE, PLL*/

	/*Whether to Bypass HSE Oscillator*/
#define RCC_OSCILLATOR_BYPASS		DIS_OSC_BYPASS	/*Options: EN_OSC_BYPASS, DIS_OSC_BYPASS*/

	/*Whether to Enable Clk Security System*/
#define RCC_CSS_ENABLE				DIS_CSS			/*Options: EN_CSS, DIS_CSS*/	
/*__________________________________________________________________________________________________________________________________________*/


/*PLL Configuration*/
	/*Choosing PLL Multiplier Parameters*/
#define PLLM	(13u)		/*Options: 2 --> 63*/
#define PLLN	(200u)		/*Options: 192 --> 432*/
#define PLLP	(8u)		/*Options: 2, 4, 6, 8*/
#define PLLQ	(12u)		/*Options: 2 --> 15*/
/*
 * Calculating PLL Frequencies:
 * PLL input Freq = Frecuency of PLL input source					(chosen in RCC_PLL_SRC) 
 * VCO input freq = PLL input clk freq / PLLM						(freq must range from 1 to 2 MHz. 2 MHz is recommended to limit PLL jitter)
 * VCO output freq = VCO input freq * PLLN							(freq must range from 192 to 432 MHz)
 * PLL general clk output freq = VCO output freq / PLLP				(freq must not exceed 84 MHz)
 * USB,OTG,FS,SDIO,RNG clk output freq = VCO output freq / PLLQ		(freq must not not exceed 48 MHz)
 */

	/*Selecting PLL CLK Src*/
#define PLL_CLK_SRC		HSE		/*Options: HSI, HSE*/
/*__________________________________________________________________________________________________________________________________________*/


/*AMBA Buses Configuration*/
#define AHB_PRESCALER	AHB_PRE_2	/*AHB prescalar from system clk. Options: AHB_PRE1,2,4,8,16,64,128,256,512*/
#define APB1_PRESCALER	APB_PRE_2	/*APB1 prescalar from AHB clk. Options: APB_PRE1,2,4,8,16. APB1 CLK must not exceed 42MHz*/
#define APB2_PRESCALER	APB_PRE_2	/*APB2 prescalar from AHB clk. Options: APB_PRE1,2,4,8,16. APB2 CLK must not exceed 84MHz*/
/*__________________________________________________________________________________________________________________________________________*/


#endif /*RCC_CONFIG_H*/
