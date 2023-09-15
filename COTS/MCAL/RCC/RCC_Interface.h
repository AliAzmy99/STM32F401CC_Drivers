/************************************************************************/
/* SWC			: RCC Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.2													*/
/* Description	: SWC for Reset and Clock Control						*/
/************************************************************************/


#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


/*Types Definitions*/
	/*Peripheral ID Type*/
typedef enum
{
	RCC_PERIPHERAL_USBFS,
	RCC_PERIPHERAL_DMA1,
	RCC_PERIPHERAL_DMA2,
	RCC_PERIPHERAL_CRC,
	RCC_PERIPHERAL_GPIOA,
	RCC_PERIPHERAL_GPIOB,
	RCC_PERIPHERAL_GPIOC,
	RCC_PERIPHERAL_TIM1,
	RCC_PERIPHERAL_TIM2,
	RCC_PERIPHERAL_TIM3,
	RCC_PERIPHERAL_TIM4,
	RCC_PERIPHERAL_TIM5,
	RCC_PERIPHERAL_TIM9,
	RCC_PERIPHERAL_TIM10,
	RCC_PERIPHERAL_TIM11,
	RCC_PERIPHERAL_SYSCFG,
	RCC_PERIPHERAL_SPI1,
	RCC_PERIPHERAL_SPI2,
	RCC_PERIPHERAL_SPI3,
	RCC_PERIPHERAL_SPI4,
	RCC_PERIPHERAL_SDIO,
	RCC_PERIPHERAL_ADC1,
	RCC_PERIPHERAL_USART1,
	RCC_PERIPHERAL_USART2,
	RCC_PERIPHERAL_USART6,
	RCC_PERIPHERAL_PWR,
	RCC_PERIPHERAL_I2C1,
	RCC_PERIPHERAL_I2C2,
	RCC_PERIPHERAL_I2C3,
	RCC_PERIPHERAL_WWDG,
	RCC_NOT_A_PERIPHERAL	/*Must remain the last element*/
}PeripheralId_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: RCC_vdInitSysClk
 * Description	: This function allows the user to initialize the system clk
 */
void RCC_vdInitSysClk(void);

/* 
 * Func. Name	: RCC_voidEnablePeripheralClk
 * Description	: This function allows the user to enable the clk of a certian peripheral
 * I/p Argument	: Copy_enmPeripheralId			Options: PERIPHERAL_USBFS -> PERIPHERAL_WWDG
 */
void RCC_vdEnablePeripheralClk(PeripheralId_type Copy_enmPeripheralId);

/* 
 * Func. Name	: RCC_vdDisablePeripheralClk
 * Description	: This function allows the user to disable the clk of a certian peripheral
 * I/p Argument	: Copy_enmPeripheralId			Options: PERIPHERAL_USBFS -> PERIPHERAL_WWDG
 */
void RCC_vdDisablePeripheralClk(PeripheralId_type Copy_enmPeripheralId);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*RCC_INTERFACE_H*/
