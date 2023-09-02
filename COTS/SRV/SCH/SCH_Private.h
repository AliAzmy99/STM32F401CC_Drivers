/************************************************************************/
/* SWC			: SCH Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.2													*/
/* Description	: SWC for Reset and Clock Control						*/
/************************************************************************/


#ifndef SCH_PRIVATE_H
#define SCH_PRIVATE_H


/*Private Macros*/
	/*SCH_CLK_SRC Options*/
#define HSI		(1u)
#define HSE		(2u)
#define PLL		(3u)
	/*SCH_OSCILLATOR_BYPASS Options*/
#define EN_OSC_BYPASS	(1u)
#define DIS_OSC_BYPASS	(2u)
	/*SCH_CSS_ENABLE Options*/
#define EN_CSS	(1u)
#define DIS_CSS	(2u)

/*Prescalar options*/
	/*AHB*/
#define AHB_PRE_1		(7u)
#define AHB_PRE_2		(8u)
#define AHB_PRE_4		(9u)
#define AHB_PRE_8		(10u)
#define AHB_PRE_16		(11u)
#define AHB_PRE_64		(12u)
#define AHB_PRE_128		(13u)
#define AHB_PRE_256		(14u)
#define AHB_PRE_512		(15u)
	/*APB*/
#define APB_PRE_1		(3u)
#define APB_PRE_2		(4u)
#define APB_PRE_4		(5u)
#define APB_PRE_8		(6u)
#define APB_PRE_16		(7u)

	/*Registers, SCH First Address: 0x40023800*/
#define SCH_CR			(*((volatile u32*)0x40023800))
#define SCH_PLLCFGR		(*((volatile u32*)0x40023804))
#define SCH_CFGR		(*((volatile u32*)0x40023808))
#define SCH_CIR			(*((volatile u32*)0x4002380C))
#define SCH_AHB1RSTR	(*((volatile u32*)0x40023810))
#define SCH_AHB2RSTR	(*((volatile u32*)0x40023814))
#define SCH_APB1RSTR	(*((volatile u32*)0x40023820))
#define SCH_APB2RSTR	(*((volatile u32*)0x40023824))
#define SCH_AHB1ENR		(*((volatile u32*)0x40023830))
#define SCH_AHB2ENR		(*((volatile u32*)0x40023834))
#define SCH_APB1ENR		(*((volatile u32*)0x40023840))
#define SCH_APB2ENR		(*((volatile u32*)0x40023844))
#define SCH_AHB1LPENR	(*((volatile u32*)0x40023850))
#define SCH_AHB2LPENR	(*((volatile u32*)0x40023854))
#define SCH_APB1LPENR	(*((volatile u32*)0x40023860))
#define SCH_APB2LPENR	(*((volatile u32*)0x40023864))
#define SCH_BDCR		(*((volatile u32*)0x40023870))
#define SCH_CSR			(*((volatile u32*)0x40023874))
#define SCH_SSCGR		(*((volatile u32*)0x40023880))
#define SCH_PLLI2SCFGR	(*((volatile u32*)0x40023884))
#define SCH_DCKCFGR		(*((volatile u32*)0x4002388C))

	/*Bits*/
		/*SCH_CR*/
#define SCH_CR_HSION			(0u)
#define SCH_CR_HSEON			(16u)
#define SCH_CR_PLLON			(24u)
#define SCH_CR_HSIRDY			(1u)
#define SCH_CR_HSERDY			(17u)
#define SCH_CR_PLLRDY			(25u)
#define SCH_CR_HSEBYP			(18u)
#define SCH_CR_CSSON			(19u)
		/*SCH_PLLCFGR*/
#define SCH_PLLCFGR_PLLM0		(0u)
#define SCH_PLLCFGR_PLLN0		(6u)
#define SCH_PLLCFGR_PLLP0		(16u)
#define SCH_PLLCFGR_PLLQ0		(24u)
#define SCH_PLLCFGR_PLLSRC		(22u)
		/*SCH_CFGR*/
#define SCH_CFGR_SW0			(0u)
#define SCH_CFGR_SW1			(1u)
#define SCH_CFGR_HPRE0			(4u)
#define SCH_CFGR_PPRE10			(10u)
#define SCH_CFGR_PPRE20			(13u)
		/*SCH_AHB1ENR*/
#define SCH_AHB1ENR_GPIOAEN		(0u)
#define SCH_AHB1ENR_GPIOBEN		(1u)
#define SCH_AHB1ENR_GPIOCEN		(2u)
#define SCH_AHB1ENR_CRCEN		(12u)
#define SCH_AHB1ENR_DMA1EN		(21u)
#define SCH_AHB1ENR_DMA2EN		(22u)
		/*SCH_AHB2ENR*/
#define SCH_AHB2ENR_OTGFSEN		(7u)
		/*SCH_APB1ENR*/
#define SCH_APB1ENR_TIM2EN		(0u)
#define SCH_APB1ENR_TIM3EN		(1u)
#define SCH_APB1ENR_TIM4EN		(2u)
#define SCH_APB1ENR_TIM5EN		(3u)
#define SCH_APB1ENR_WWDGEN		(11u)
#define SCH_APB1ENR_SPI2EN		(14u)
#define SCH_APB1ENR_SPI3EN		(15u)
#define SCH_APB1ENR_USART2EN	(17u)
#define SCH_APB1ENR_I2C1EN		(21u)
#define SCH_APB1ENR_I2C2EN		(22u)
#define SCH_APB1ENR_I2C3EN		(23u)
#define SCH_APB1ENR_PWREN		(28u)
		/*SCH_APB2ENR*/
#define SCH_APB2ENR_TIM1EN		(0u)
#define SCH_APB2ENR_USART1EN	(4u)
#define SCH_APB2ENR_USART6EN	(5u)
#define SCH_APB2ENR_ADC1EN		(8u)
#define SCH_APB2ENR_SDIOEN		(11u)
#define SCH_APB2ENR_SPI1EN		(12u)
#define SCH_APB2ENR_SPI4EN		(13u)
#define SCH_APB2ENR_SYSCFGEN	(14u)
#define SCH_APB2ENR_TIM9EN		(16u)
#define SCH_APB2ENR_TIM10EN		(17u)
#define SCH_APB2ENR_TIM11EN		(18u)

	/*Reset Values*/
#define SCH_PLLCFGR_RESET	(0x24003010)
#define SCH_CFGR_RESET		(0x00000000)

	/*Empty Values*/
		/*Values of registers when a certain part is cleared while the rest is at the reset value*/
#define SCH_PLLCFGR_MUL_PAR_RESET	(0xF0FC8000)
#define SCH_CFGR_AMBA_PRE_RESET		(0xFFFF030F)
/*__________________________________________________________________________________________________________________________________________*/


#endif /*SCH_PRIVATE_H*/
