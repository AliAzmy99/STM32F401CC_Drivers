/************************************************************************/
/* SWC			: RCC Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.2													*/
/* Description	: SWC for Reset and Clock Control						*/
/************************************************************************/


#warning Fix PLL
/*Include Needed Files*/
	/*Include Needed Library Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed RCC Files*/
#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
/* 
 * Func. Name	: RCC_errInitSysClk
 * Description	: This function allows the user to initialize the system clk
 * Return		: Error status of function
 */
ErrorStatus RCC_errInitSysClk(void)
{
	/*1- AMBA Buses Prescaler Selection*/
	#if ((AHB_PRE_1 <= AHB_PRESCALER && AHB_PRE_512 >= AHB_PRESCALER) && (APB_PRE_1 <= APB1_PRESCALER && APB_PRE_16 >= APB1_PRESCALER) && (APB_PRE_1 <= APB2_PRESCALER && APB_PRE_16 >= APB2_PRESCALER))
		RCC_CFGR = (RCC_CFGR & RCC_CFGR_AMBA_PRE_RESET) | (AHB_PRESCALER << RCC_CFGR_HPRE0) | (APB1_PRESCALER << RCC_CFGR_PPRE10) | (APB2_PRESCALER << RCC_CFGR_PPRE20);
	#else
		#error Error: Invalid AMBA Buses Configuration
	#endif

	/*2- HSE Options*/
		/*HSE Oscillator Bypass*/
	#if (EN_OSC_BYPASS == RCC_OSCILLATOR_BYPASS)
		SET_BIT(RCC_CR, RCC_CR_HSEBYP);
	#elif (DIS_OSC_BYPASS == RCC_OSCILLATOR_BYPASS)
		CLR_BIT(RCC_CR, RCC_CR_HSEBYP);
	#else
		#error Error: Invalid RCC_CSS_ENABLE Configuration
	#endif
		/*Clock Security System*/
	#if (EN_CSS	== RCC_CSS_ENABLE)
		SET_BIT(RCC_CR, RCC_CR_CSSON);
		#error ISR not implemented yet and NMI not reset
	#elif (DIS_CSS == RCC_CSS_ENABLE)
		CLR_BIT(RCC_CR, RCC_CR_CSSON);
	#else
		#error Error: Invalid RCC_CSS_ENABLE Configuration
	#endif

	/*3- Clk Src Configuration*/
		/*Choosing HSI*/
	#if (HSI == RCC_CLK_SRC)
		/*1- Turn On HSI*/
		SET_BIT(RCC_CR, RCC_CR_HSION);
		/*2- Select the HSI as the System CLK Src When Ready*/
		while (!GET_BIT(RCC_CR, RCC_CR_HSIRDY))
			{
				/*Wait for HSI to Turn On*/
			}
		CLR_BIT(RCC_CFGR, RCC_CFGR_SW0);
		CLR_BIT(RCC_CFGR, RCC_CFGR_SW1);

		/*Choosing HSE*/
	#elif (HSE == RCC_CLK_SRC)
		/*1- Turn On HSE*/
		SET_BIT(RCC_CR, RCC_CR_HSEON);
		/*2- Select the HSE as the System CLK Src When Ready*/
		while (!GET_BIT(RCC_CR, RCC_CR_HSERDY))
			{
				/*Wait for HSE to Turn On*/
			}
		SET_BIT(RCC_CFGR, RCC_CFGR_SW0);
		CLR_BIT(RCC_CFGR, RCC_CFGR_SW1);

		/*Choosing PLL*/
	#elif (PLL == RCC_CLK_SRC)
		/*1- Turn Off PLL*/
		CLR_BIT(RCC_CR, RCC_CR_PLLON);
		/*2- Choosing PLL Multiplier Parameters*/
		#if ((2 <= PLLM && 63 >= PLLM) && (192 <= PLLN && 432 >= PLLN) && (2 == PLLP || 4 == PLLP || 6 == PLLP || 8 == PLLP) && (2 <= PLLQ && 15 >= PLLQ))
			RCC_PLLCFGR = (RCC_PLLCFGR & RCC_PLLCFGR_MUL_PAR_RESET) | (PLLM<<RCC_PLLCFGR_PLLM0) | (PLLN<<RCC_PLLCFGR_PLLN0) | (((PLLP>>1)-1)<<RCC_PLLCFGR_PLLP0) | (PLLQ<<RCC_PLLCFGR_PLLQ0);
		#else
			#error Error: Invalid PLL Multiplier Parameters Configuration
		#endif
		/*3- Selecting PLL CLK Src*/
		#if (HSI == PLL_CLK_SRC)
			SET_BIT(RCC_CR, RCC_CR_HSION);	/*Turn On HSI*/
			while (!GET_BIT(RCC_CR, RCC_CR_HSIRDY))
			{
				/*Wait for HSI to Turn On*/
			}
			CLR_BIT(RCC_PLLCFGR, RCC_PLLCFGR_PLLSRC);	/*Select HSI as PLL Src When Ready*/
		#elif (HSE == PLL_CLK_SRC)
			SET_BIT(RCC_CR, RCC_CR_HSEON);		/*Turn On HSE*/
			while (!GET_BIT(RCC_CR, RCC_CR_HSERDY))
			{
				/*Wait for HSE to Turn On*/
			}
			SET_BIT(RCC_PLLCFGR, RCC_PLLCFGR_PLLSRC);	/*Select HSE as PLL Src When Ready*/
		#else
			#error Error: Invalid PLL_CLK_SRC Configuration
		#endif
		/*4- Turn On PLL*/
		SET_BIT(RCC_CR, RCC_CR_PLLON);
		/*5- Select the PLL as the System CLK Src When Ready*/
		while (!GET_BIT(RCC_CR, RCC_CR_PLLRDY))
			{
				/*Wait for PLL to Turn On*/
			}
		CLR_BIT(RCC_CFGR, RCC_CFGR_SW0);
		SET_BIT(RCC_CFGR, RCC_CFGR_SW1);

		/*Defaulting to Error*/
	#else
		#error Error: Invalid RCC_CLK_SRC Configuration
	#endif

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: RCC_voidEnablePeripheralClk
 * Description	: This function allows the user to enable the clk of a certian peripheral
 * I/p Argument	: Copy_enmPeripheralId			Options: PERIPHERAL_USBFS -> PERIPHERAL_WWDG
 * Return		: Error status of function
 */
ErrorStatus RCC_errEnablePeripheralClk(PeripheralId_type Copy_enmPeripheralId)
{
	switch (Copy_enmPeripheralId)
	{
	case USBFS:		SET_BIT(RCC_AHB2ENR, RCC_AHB2ENR_OTGFSEN);	break;
	case DMA1:		SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_DMA1EN);	break;
	case DMA2:		SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_DMA2EN);	break;
	case CRC:		SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_CRCEN);	break;
	case GPIOA:		SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOAEN);	break;
	case GPIOB:		SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOBEN);	break;
	case GPIOC:		SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOCEN);	break;
	case TIM1:		SET_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM1EN);	break;
	case TIM2:		SET_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM2EN);	break;
	case TIM3:		SET_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM3EN);	break;
	case TIM4:		SET_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM4EN);	break;
	case TIM5:		SET_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM5EN);	break;
	case TIM9:		SET_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM9EN);	break;
	case TIM10:		SET_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM10EN);	break;
	case TIM11:		SET_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM11EN);	break;
	case SYSCFG:	SET_BIT(RCC_APB2ENR, RCC_APB2ENR_SYSCFGEN);	break;
	case SPI1:		SET_BIT(RCC_APB2ENR, RCC_APB2ENR_SPI1EN);	break;
	case SPI2:		SET_BIT(RCC_APB1ENR, RCC_APB1ENR_SPI2EN);	break;
	case SPI3:		SET_BIT(RCC_APB1ENR, RCC_APB1ENR_SPI3EN);	break;
	case SPI4:		SET_BIT(RCC_APB2ENR, RCC_APB2ENR_SPI4EN);	break;
	case SDIO:		SET_BIT(RCC_APB2ENR, RCC_APB2ENR_SDIOEN);	break;
	case ADC1:		SET_BIT(RCC_APB2ENR, RCC_APB2ENR_ADC1EN);	break;
	case USART1:	SET_BIT(RCC_APB2ENR, RCC_APB2ENR_USART1EN);	break;
	case USART2:	SET_BIT(RCC_APB1ENR, RCC_APB1ENR_USART2EN);	break;
	case USART6:	SET_BIT(RCC_APB2ENR, RCC_APB2ENR_USART6EN);	break;
	case PWR:		SET_BIT(RCC_APB1ENR, RCC_APB1ENR_PWREN);	break;
	case I2C1:		SET_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C1EN);	break;
	case I2C2:		SET_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C2EN);	break;
	case I2C3:		SET_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C3EN);	break;
	case WWDG:		SET_BIT(RCC_APB1ENR, RCC_APB1ENR_WWDGEN);	break;
	default:		return INVALID_PARAMETERS;					break;
	}
	
	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: RCC_errDisablePeripheralClk
 * Description	: This function allows the user to disable the clk of a certian peripheral
 * I/p Argument	: Copy_enmPeripheralId			Options: PERIPHERAL_USBFS -> PERIPHERAL_WWDG
 * Return		: Error status of function
 */
ErrorStatus RCC_errDisablePeripheralClk(PeripheralId_type Copy_enmPeripheralId)
{
	switch (Copy_enmPeripheralId)
	{
	case USBFS:		CLR_BIT(RCC_AHB2ENR, RCC_AHB2ENR_OTGFSEN);	break;
	case DMA1:		CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_DMA1EN);	break;
	case DMA2:		CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_DMA2EN);	break;
	case CRC:		CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_CRCEN);	break;
	case GPIOA:		CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOAEN);	break;
	case GPIOB:		CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOBEN);	break;
	case GPIOC:		CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOCEN);	break;
	case TIM1:		CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM1EN);	break;
	case TIM2:		CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM2EN);	break;
	case TIM3:		CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM3EN);	break;
	case TIM4:		CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM4EN);	break;
	case TIM5:		CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM5EN);	break;
	case TIM9:		CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM9EN);	break;
	case TIM10:		CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM10EN);	break;
	case TIM11:		CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM11EN);	break;
	case SYSCFG:	CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_SYSCFGEN);	break;
	case SPI1:		CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_SPI1EN);	break;
	case SPI2:		CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_SPI2EN);	break;
	case SPI3:		CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_SPI3EN);	break;
	case SPI4:		CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_SPI4EN);	break;
	case SDIO:		CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_SDIOEN);	break;
	case ADC1:		CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_ADC1EN);	break;
	case USART1:	CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_USART1EN);	break;
	case USART2:	CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_USART2EN);	break;
	case USART6:	CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_USART6EN);	break;
	case PWR:		CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_PWREN);	break;
	case I2C1:		CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C1EN);	break;
	case I2C2:		CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C2EN);	break;
	case I2C3:		CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C3EN);	break;
	case WWDG:		CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_WWDGEN);	break;
	default:		return INVALID_PARAMETERS;					break;
	}

	/*Returning Error Status*/
	return NO_ERROR;
}
