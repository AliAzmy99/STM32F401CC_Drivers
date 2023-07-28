/************************************************************************/
/* SWC  	    : RCC Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.1													*/
/* Description  : SWC for Reset and Clock Control						*/
/************************************************************************/


#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/*Private Macros*/
    /*RCC_CLK_SRC Options*/
#define HSI (1u)
#define HSE (2u)
#define PLL (3u)
	/*HSE Bypass HSE Options*/
#define EN_OSC_BYPASS	(1u)
#define DIS_OSC_BYPASS	(2u)
    /*CSS Enable Options*/
#define EN_CSS	(1u)
#define DIS_CSS	(2u)

	/*Registers, RCC First Address: 0x40023800*/
#define RCC_CR 			(*((volatile u32*)0x40023800))
#define RCC_PLLCFGR		(*((volatile u32*)0x40023804))
#define RCC_CFGR		(*((volatile u32*)0x40023808))
#define RCC_CIR			(*((volatile u32*)0x4002380C))
#define RCC_AHB1RSTR	(*((volatile u32*)0x40023810))
#define RCC_AHB2RSTR	(*((volatile u32*)0x40023814))
#define RCC_APB1RSTR	(*((volatile u32*)0x40023820))
#define RCC_APB2RSTR	(*((volatile u32*)0x40023824))
#define RCC_AHB1ENR		(*((volatile u32*)0x40023830))
#define RCC_AHB2ENR		(*((volatile u32*)0x40023834))
#define RCC_APB1ENR		(*((volatile u32*)0x40023840))
#define RCC_APB2ENR		(*((volatile u32*)0x40023844))
#define RCC_AHB1LPENR	(*((volatile u32*)0x40023850))
#define RCC_AHB2LPENR	(*((volatile u32*)0x40023854))
#define RCC_APB1LPENR	(*((volatile u32*)0x40023860))
#define RCC_APB2LPENR	(*((volatile u32*)0x40023864))
#define RCC_BDCR		(*((volatile u32*)0x40023870))
#define RCC_CSR			(*((volatile u32*)0x40023874))
#define RCC_SSCGR		(*((volatile u32*)0x40023880))
#define RCC_PLLI2SCFGR	(*((volatile u32*)0x40023884))
#define RCC_DCKCFGR		(*((volatile u32*)0x4002388C))

    /*Bits*/
        /*RCC_CR*/
#define RCC_CR_HSION			(0u)
#define RCC_CR_HSEON			(16u)
#define RCC_CR_PLLON			(24u)
#define RCC_CR_HSIRDY			(1u)
#define RCC_CR_HSERDY			(17u)
#define RCC_CR_PLLRDY			(25u)
#define RCC_CR_HSEBYP			(18u)
#define RCC_CR_CSSON			(19u)
        /*RCC_PLLCFGR*/
#define RCC_PLLCFGR_PLLM0		(0u)
#define RCC_PLLCFGR_PLLN0		(6u)
#define RCC_PLLCFGR_PLLP0		(16u)
#define RCC_PLLCFGR_PLLQ0		(24u)
#define RCC_PLLCFGR_PLLSRC		(22u)
        /*RCC_CFGR*/
#define RCC_CFGR_SW0			(0u)
#define RCC_CFGR_SW1			(1u)
        /*RCC_AHB1ENR*/
#define RCC_AHB1ENR_GPIOAEN     (0u)
#define RCC_AHB1ENR_GPIOBEN     (1u)
#define RCC_AHB1ENR_GPIOCEN     (2u)
#define RCC_AHB1ENR_CRCEN       (12u)
#define RCC_AHB1ENR_DMA1EN      (21u)
#define RCC_AHB1ENR_DMA2EN      (22u)
        /*RCC_AHB2ENR*/
#define RCC_AHB2ENR_OTGFSEN     (7u)
        /*RCC_APB1ENR*/
#define RCC_APB1ENR_TIM2EN      (0u)
#define RCC_APB1ENR_TIM3EN      (1u)
#define RCC_APB1ENR_TIM4EN      (2u)
#define RCC_APB1ENR_TIM5EN      (3u)
#define RCC_APB1ENR_WWDGEN      (11u)
#define RCC_APB1ENR_SPI2EN      (14u)
#define RCC_APB1ENR_SPI3EN      (15u)
#define RCC_APB1ENR_USART2EN    (17u)
#define RCC_APB1ENR_I2C1EN      (21u)
#define RCC_APB1ENR_I2C2EN      (22u)
#define RCC_APB1ENR_I2C3EN      (23u)
#define RCC_APB1ENR_PWREN       (28u)
        /*RCC_APB2ENR*/
#define RCC_APB2ENR_TIM1EN      (0u)
#define RCC_APB2ENR_USART1EN    (4u)
#define RCC_APB2ENR_USART6EN    (5u)
#define RCC_APB2ENR_ADC1EN      (8u)
#define RCC_APB2ENR_SDIOEN      (11u)
#define RCC_APB2ENR_SPI1EN      (12u)
#define RCC_APB2ENR_SPI4EN      (13u)
#define RCC_APB2ENR_SYSCFGEN    (14u)
#define RCC_APB2ENR_TIM9EN      (16u)
#define RCC_APB2ENR_TIM10EN     (17u)
#define RCC_APB2ENR_TIM11EN     (18u)

    /*Reset Values*/
#define RCC_PLLCFGR_RESET	(0x24003010)
#define RCC_PLLCFGR_EMPTY	(0x24000000)
/*__________________________________________________________________________________________________________________________________________*/


#endif /*RCC_PRIVATE_H*/
