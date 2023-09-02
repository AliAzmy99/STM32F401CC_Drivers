/************************************************************************/
/* SWC			: SCH Driver											*/
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

	/*Include Needed SCH Files*/
#include "SCH_Interface.h"
#include "SCH_Private.h"
#include "SCH_Config.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
/* 
 * Func. Name	: SCH_errInitSysClk
 * Description	: This function allows the user to initialize the system clk
 * Return		: Error status of function
 */
ErrorStatus SCH_errInitSysClk(void)
{
	/*1- AMBA Buses Prescaler Selection*/
	#if ((AHB_PRE_1 <= AHB_PRESCALER && AHB_PRE_512 >= AHB_PRESCALER) && (APB_PRE_1 <= APB1_PRESCALER && APB_PRE_16 >= APB1_PRESCALER) && (APB_PRE_1 <= APB2_PRESCALER && APB_PRE_16 >= APB2_PRESCALER))
		SCH_CFGR = (SCH_CFGR & SCH_CFGR_AMBA_PRE_RESET) | (AHB_PRESCALER << SCH_CFGR_HPRE0) | (APB1_PRESCALER << SCH_CFGR_PPRE10) | (APB2_PRESCALER << SCH_CFGR_PPRE20);
	#else
		#error Error: Invalid AMBA Buses Configuration
	#endif

	/*2- HSE Options*/
		/*HSE Oscillator Bypass*/
	#if (EN_OSC_BYPASS == SCH_OSCILLATOR_BYPASS)
		SET_BIT(SCH_CR, SCH_CR_HSEBYP);
	#elif (DIS_OSC_BYPASS == SCH_OSCILLATOR_BYPASS)
		CLR_BIT(SCH_CR, SCH_CR_HSEBYP);
	#else
		#error Error: Invalid SCH_CSS_ENABLE Configuration
	#endif
		/*Clock Security System*/
	#if (EN_CSS	== SCH_CSS_ENABLE)
		SET_BIT(SCH_CR, SCH_CR_CSSON);
		#error ISR not implemented yet and NMI not reset
	#elif (DIS_CSS == SCH_CSS_ENABLE)
		CLR_BIT(SCH_CR, SCH_CR_CSSON);
	#else
		#error Error: Invalid SCH_CSS_ENABLE Configuration
	#endif

	/*3- Clk Src Configuration*/
		/*Choosing HSI*/
	#if (HSI == SCH_CLK_SRC)
		/*1- Turn On HSI*/
		SET_BIT(SCH_CR, SCH_CR_HSION);
		/*2- Select the HSI as the System CLK Src When Ready*/
		while (!GET_BIT(SCH_CR, SCH_CR_HSIRDY))
			{
				/*Wait for HSI to Turn On*/
			}
		CLR_BIT(SCH_CFGR, SCH_CFGR_SW0);
		CLR_BIT(SCH_CFGR, SCH_CFGR_SW1);

		/*Choosing HSE*/
	#elif (HSE == SCH_CLK_SRC)
		/*1- Turn On HSE*/
		SET_BIT(SCH_CR, SCH_CR_HSEON);
		/*2- Select the HSE as the System CLK Src When Ready*/
		while (!GET_BIT(SCH_CR, SCH_CR_HSERDY))
			{
				/*Wait for HSE to Turn On*/
			}
		SET_BIT(SCH_CFGR, SCH_CFGR_SW0);
		CLR_BIT(SCH_CFGR, SCH_CFGR_SW1);

		/*Choosing PLL*/
	#elif (PLL == SCH_CLK_SRC)
		/*1- Turn Off PLL*/
		CLR_BIT(SCH_CR, SCH_CR_PLLON);
		/*2- Choosing PLL Multiplier Parameters*/
		#if ((2 <= PLLM && 63 >= PLLM) && (192 <= PLLN && 432 >= PLLN) && (2 == PLLP || 4 == PLLP || 6 == PLLP || 8 == PLLP) && (2 <= PLLQ && 15 >= PLLQ))
			SCH_PLLCFGR = (SCH_PLLCFGR & SCH_PLLCFGR_MUL_PAR_RESET) | (PLLM<<SCH_PLLCFGR_PLLM0) | (PLLN<<SCH_PLLCFGR_PLLN0) | (((PLLP>>1)-1)<<SCH_PLLCFGR_PLLP0) | (PLLQ<<SCH_PLLCFGR_PLLQ0);
		#else
			#error Error: Invalid PLL Multiplier Parameters Configuration
		#endif
		/*3- Selecting PLL CLK Src*/
		#if (HSI == PLL_CLK_SRC)
			SET_BIT(SCH_CR, SCH_CR_HSION);	/*Turn On HSI*/
			while (!GET_BIT(SCH_CR, SCH_CR_HSIRDY))
			{
				/*Wait for HSI to Turn On*/
			}
			CLR_BIT(SCH_PLLCFGR, SCH_PLLCFGR_PLLSRC);	/*Select HSI as PLL Src When Ready*/
		#elif (HSE == PLL_CLK_SRC)
			SET_BIT(SCH_CR, SCH_CR_HSEON);		/*Turn On HSE*/
			while (!GET_BIT(SCH_CR, SCH_CR_HSERDY))
			{
				/*Wait for HSE to Turn On*/
			}
			SET_BIT(SCH_PLLCFGR, SCH_PLLCFGR_PLLSRC);	/*Select HSE as PLL Src When Ready*/
		#else
			#error Error: Invalid PLL_CLK_SRC Configuration
		#endif
		/*4- Turn On PLL*/
		SET_BIT(SCH_CR, SCH_CR_PLLON);
		/*5- Select the PLL as the System CLK Src When Ready*/
		while (!GET_BIT(SCH_CR, SCH_CR_PLLRDY))
			{
				/*Wait for PLL to Turn On*/
			}
		CLR_BIT(SCH_CFGR, SCH_CFGR_SW0);
		SET_BIT(SCH_CFGR, SCH_CFGR_SW1);

		/*Defaulting to Error*/
	#else
		#error Error: Invalid SCH_CLK_SRC Configuration
	#endif

	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: SCH_voidEnablePeripheralClk
 * Description	: This function allows the user to enable the clk of a certian peripheral
 * I/p Argument	: Copy_enmPeripheralId			Options: PERIPHERAL_USBFS -> PERIPHERAL_WWDG
 * Return		: Error status of function
 */
ErrorStatus SCH_errEnablePeripheralClk(PeripheralId_type Copy_enmPeripheralId)
{
	switch (Copy_enmPeripheralId)
	{
	case SCH_PERIPHERAL_USBFS:		SET_BIT(SCH_AHB2ENR, SCH_AHB2ENR_OTGFSEN);	break;
	case SCH_PERIPHERAL_DMA1:		SET_BIT(SCH_AHB1ENR, SCH_AHB1ENR_DMA1EN);	break;
	case SCH_PERIPHERAL_DMA2:		SET_BIT(SCH_AHB1ENR, SCH_AHB1ENR_DMA2EN);	break;
	case SCH_PERIPHERAL_CRC:		SET_BIT(SCH_AHB1ENR, SCH_AHB1ENR_CRCEN);	break;
	case SCH_PERIPHERAL_GPIOA:		SET_BIT(SCH_AHB1ENR, SCH_AHB1ENR_GPIOAEN);	break;
	case SCH_PERIPHERAL_GPIOB:		SET_BIT(SCH_AHB1ENR, SCH_AHB1ENR_GPIOBEN);	break;
	case SCH_PERIPHERAL_GPIOC:		SET_BIT(SCH_AHB1ENR, SCH_AHB1ENR_GPIOCEN);	break;
	case SCH_PERIPHERAL_TIM1:		SET_BIT(SCH_APB2ENR, SCH_APB2ENR_TIM1EN);	break;
	case SCH_PERIPHERAL_TIM2:		SET_BIT(SCH_APB1ENR, SCH_APB1ENR_TIM2EN);	break;
	case SCH_PERIPHERAL_TIM3:		SET_BIT(SCH_APB1ENR, SCH_APB1ENR_TIM3EN);	break;
	case SCH_PERIPHERAL_TIM4:		SET_BIT(SCH_APB1ENR, SCH_APB1ENR_TIM4EN);	break;
	case SCH_PERIPHERAL_TIM5:		SET_BIT(SCH_APB1ENR, SCH_APB1ENR_TIM5EN);	break;
	case SCH_PERIPHERAL_TIM9:		SET_BIT(SCH_APB2ENR, SCH_APB2ENR_TIM9EN);	break;
	case SCH_PERIPHERAL_TIM10:		SET_BIT(SCH_APB2ENR, SCH_APB2ENR_TIM10EN);	break;
	case SCH_PERIPHERAL_TIM11:		SET_BIT(SCH_APB2ENR, SCH_APB2ENR_TIM11EN);	break;
	case SCH_PERIPHERAL_SYSCFG:		SET_BIT(SCH_APB2ENR, SCH_APB2ENR_SYSCFGEN);	break;
	case SCH_PERIPHERAL_SPI1:		SET_BIT(SCH_APB2ENR, SCH_APB2ENR_SPI1EN);	break;
	case SCH_PERIPHERAL_SPI2:		SET_BIT(SCH_APB1ENR, SCH_APB1ENR_SPI2EN);	break;
	case SCH_PERIPHERAL_SPI3:		SET_BIT(SCH_APB1ENR, SCH_APB1ENR_SPI3EN);	break;
	case SCH_PERIPHERAL_SPI4:		SET_BIT(SCH_APB2ENR, SCH_APB2ENR_SPI4EN);	break;
	case SCH_PERIPHERAL_SDIO:		SET_BIT(SCH_APB2ENR, SCH_APB2ENR_SDIOEN);	break;
	case SCH_PERIPHERAL_ADC1:		SET_BIT(SCH_APB2ENR, SCH_APB2ENR_ADC1EN);	break;
	case SCH_PERIPHERAL_USART1:		SET_BIT(SCH_APB2ENR, SCH_APB2ENR_USART1EN);	break;
	case SCH_PERIPHERAL_USART2:		SET_BIT(SCH_APB1ENR, SCH_APB1ENR_USART2EN);	break;
	case SCH_PERIPHERAL_USART6:		SET_BIT(SCH_APB2ENR, SCH_APB2ENR_USART6EN);	break;
	case SCH_PERIPHERAL_PWR:		SET_BIT(SCH_APB1ENR, SCH_APB1ENR_PWREN);	break;
	case SCH_PERIPHERAL_I2C1:		SET_BIT(SCH_APB1ENR, SCH_APB1ENR_I2C1EN);	break;
	case SCH_PERIPHERAL_I2C2:		SET_BIT(SCH_APB1ENR, SCH_APB1ENR_I2C2EN);	break;
	case SCH_PERIPHERAL_I2C3:		SET_BIT(SCH_APB1ENR, SCH_APB1ENR_I2C3EN);	break;
	case SCH_PERIPHERAL_WWDG:		SET_BIT(SCH_APB1ENR, SCH_APB1ENR_WWDGEN);	break;
	default:						return INVALID_PARAMETERS;					break;
	}
	
	/*Returning Error Status*/
	return NO_ERROR;
}

/* 
 * Func. Name	: SCH_errDisablePeripheralClk
 * Description	: This function allows the user to disable the clk of a certian peripheral
 * I/p Argument	: Copy_enmPeripheralId			Options: PERIPHERAL_USBFS -> PERIPHERAL_WWDG
 * Return		: Error status of function
 */
ErrorStatus SCH_errDisablePeripheralClk(PeripheralId_type Copy_enmPeripheralId)
{
	switch (Copy_enmPeripheralId)
	{
	case SCH_PERIPHERAL_USBFS:		CLR_BIT(SCH_AHB2ENR, SCH_AHB2ENR_OTGFSEN);	break;
	case SCH_PERIPHERAL_DMA1:		CLR_BIT(SCH_AHB1ENR, SCH_AHB1ENR_DMA1EN);	break;
	case SCH_PERIPHERAL_DMA2:		CLR_BIT(SCH_AHB1ENR, SCH_AHB1ENR_DMA2EN);	break;
	case SCH_PERIPHERAL_CRC:		CLR_BIT(SCH_AHB1ENR, SCH_AHB1ENR_CRCEN);	break;
	case SCH_PERIPHERAL_GPIOA:		CLR_BIT(SCH_AHB1ENR, SCH_AHB1ENR_GPIOAEN);	break;
	case SCH_PERIPHERAL_GPIOB:		CLR_BIT(SCH_AHB1ENR, SCH_AHB1ENR_GPIOBEN);	break;
	case SCH_PERIPHERAL_GPIOC:		CLR_BIT(SCH_AHB1ENR, SCH_AHB1ENR_GPIOCEN);	break;
	case SCH_PERIPHERAL_TIM1:		CLR_BIT(SCH_APB2ENR, SCH_APB2ENR_TIM1EN);	break;
	case SCH_PERIPHERAL_TIM2:		CLR_BIT(SCH_APB1ENR, SCH_APB1ENR_TIM2EN);	break;
	case SCH_PERIPHERAL_TIM3:		CLR_BIT(SCH_APB1ENR, SCH_APB1ENR_TIM3EN);	break;
	case SCH_PERIPHERAL_TIM4:		CLR_BIT(SCH_APB1ENR, SCH_APB1ENR_TIM4EN);	break;
	case SCH_PERIPHERAL_TIM5:		CLR_BIT(SCH_APB1ENR, SCH_APB1ENR_TIM5EN);	break;
	case SCH_PERIPHERAL_TIM9:		CLR_BIT(SCH_APB2ENR, SCH_APB2ENR_TIM9EN);	break;
	case SCH_PERIPHERAL_TIM10:		CLR_BIT(SCH_APB2ENR, SCH_APB2ENR_TIM10EN);	break;
	case SCH_PERIPHERAL_TIM11:		CLR_BIT(SCH_APB2ENR, SCH_APB2ENR_TIM11EN);	break;
	case SCH_PERIPHERAL_SYSCFG:		CLR_BIT(SCH_APB2ENR, SCH_APB2ENR_SYSCFGEN);	break;
	case SCH_PERIPHERAL_SPI1:		CLR_BIT(SCH_APB2ENR, SCH_APB2ENR_SPI1EN);	break;
	case SCH_PERIPHERAL_SPI2:		CLR_BIT(SCH_APB1ENR, SCH_APB1ENR_SPI2EN);	break;
	case SCH_PERIPHERAL_SPI3:		CLR_BIT(SCH_APB1ENR, SCH_APB1ENR_SPI3EN);	break;
	case SCH_PERIPHERAL_SPI4:		CLR_BIT(SCH_APB2ENR, SCH_APB2ENR_SPI4EN);	break;
	case SCH_PERIPHERAL_SDIO:		CLR_BIT(SCH_APB2ENR, SCH_APB2ENR_SDIOEN);	break;
	case SCH_PERIPHERAL_ADC1:		CLR_BIT(SCH_APB2ENR, SCH_APB2ENR_ADC1EN);	break;
	case SCH_PERIPHERAL_USART1:		CLR_BIT(SCH_APB2ENR, SCH_APB2ENR_USART1EN);	break;
	case SCH_PERIPHERAL_USART2:		CLR_BIT(SCH_APB1ENR, SCH_APB1ENR_USART2EN);	break;
	case SCH_PERIPHERAL_USART6:		CLR_BIT(SCH_APB2ENR, SCH_APB2ENR_USART6EN);	break;
	case SCH_PERIPHERAL_PWR:		CLR_BIT(SCH_APB1ENR, SCH_APB1ENR_PWREN);	break;
	case SCH_PERIPHERAL_I2C1:		CLR_BIT(SCH_APB1ENR, SCH_APB1ENR_I2C1EN);	break;
	case SCH_PERIPHERAL_I2C2:		CLR_BIT(SCH_APB1ENR, SCH_APB1ENR_I2C2EN);	break;
	case SCH_PERIPHERAL_I2C3:		CLR_BIT(SCH_APB1ENR, SCH_APB1ENR_I2C3EN);	break;
	case SCH_PERIPHERAL_WWDG:		CLR_BIT(SCH_APB1ENR, SCH_APB1ENR_WWDGEN);	break;
	default:						return INVALID_PARAMETERS;					break;
	}

	/*Returning Error Status*/
	return NO_ERROR;
}
