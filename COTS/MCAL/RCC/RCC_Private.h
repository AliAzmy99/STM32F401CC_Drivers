/************************************************************************/
/* SWC  	    : RCC Driver                                            */
/* Author	    : Ali Azmy                                              */
/* Version	    : V0.0                                                  */
/* Date 	    : 21 Jul 2023                                           */
/* Description  : SWC for Reset and Clock Control                       */
/************************************************************************/


#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/*Private Macros*/
	/*RCC_CLK_SRC Options*/
#define HSI (1u)
#define HSE (2u)
#define PLL (3u)

	/*Registers, RCC First Address: 0x40023800*/
#define RCC_CR 					(*((volatile u32*)0x40023800))
		/*Bits*/
	#define HSION				(0u)
	#define HSEON				(16u)
	#define PLLON				(24u)
	#define HSIRDY				(1u)
	#define HSERDY				(17u)
	#define PLLRDY				(25u)

#define RCC_PLLCFGR				(*((volatile u32*)0x40023804))
		/*Reset Value*/
	#define RCC_PLLCFGR_EMPTY	(0x24000000)
		/*Bits*/
	#define PLLM0					(0u)
	#define PLLN0					(6u)
	#define PLLP0					(16u)
	#define PLLQ0					(24u)
	#define PLLSRC					(22u)

#define RCC_CFGR				(*((volatile u32*)0x40023808))
		/*Bits*/
	#define SW0						(0u)
	#define SW1						(1u)

#define RCC_CIR						(*((volatile u32*)0x4002380C))
#define RCC_AHB1RSTR				(*((volatile u32*)0x40023810))
#define RCC_AHB2RSTR				(*((volatile u32*)0x40023814))
#define RCC_APB1RSTR				(*((volatile u32*)0x40023820))
#define RCC_APB2RSTR				(*((volatile u32*)0x40023824))
#define RCC_AHB1ENR					(*((volatile u32*)0x40023830))
#define RCC_AHB2ENR					(*((volatile u32*)0x40023834))
#define RCC_APB1ENR					(*((volatile u32*)0x40023840))
#define RCC_APB2ENR					(*((volatile u32*)0x40023844))
#define RCC_AHB1LPENR				(*((volatile u32*)0x40023850))
#define RCC_AHB2LPENR				(*((volatile u32*)0x40023854))
#define RCC_APB1LPENR				(*((volatile u32*)0x40023860))
#define RCC_APB2LPENR				(*((volatile u32*)0x40023864))
#define RCC_BDCR					(*((volatile u32*)0x40023870))
#define RCC_CSR						(*((volatile u32*)0x40023874))
#define RCC_SSCGR					(*((volatile u32*)0x40023880))
#define RCC_PLLI2SCFGR				(*((volatile u32*)0x40023884))
#define RCC_DCKCFGR					(*((volatile u32*)0x4002388C))
/*__________________________________________________________________________________________________________________________________________*/


#endif /*RCC_PRIVATE_H*/
