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
	USBFS,
	DMA1,
	DMA2,
	CRC,
	GPIOA,
	GPIOB,
	GPIOC,
	TIM1,
	TIM2,
	TIM3,
	TIM4,
	TIM5,
	TIM9,
	TIM10,
	TIM11,
	SYSCFG,
	SPI1,
	SPI2,
	SPI3,
	SPI4,
	SDIO,
	ADC1,
	USART1,
	USART2,
	USART6,
	PWR,
	I2C1,
	I2C2,
	I2C3,
	WWDG,
	NOT_A_PERIPHERAL	/*Must remain the last element*/
}PeripheralId_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: RCC_errInitSysClk
 * Description	: This function allows the user to initialize the system clk
 * Return		: Error status of function
 */
ErrorStatus RCC_errInitSysClk(void);

/* 
 * Func. Name	: RCC_voidEnablePeripheralClk
 * Description	: This function allows the user to enable the clk of a certian peripheral
 * I/p Argument	: Copy_enmPeripheralId			Options: PERIPHERAL_USBFS -> PERIPHERAL_WWDG
 * Return		: Error status of function
 */
ErrorStatus RCC_errEnablePeripheralClk(PeripheralId_type Copy_enmPeripheralId);

/* 
 * Func. Name	: RCC_errDisablePeripheralClk
 * Description	: This function allows the user to disable the clk of a certian peripheral
 * I/p Argument	: Copy_enmPeripheralId			Options: PERIPHERAL_USBFS -> PERIPHERAL_WWDG
 * Return		: Error status of function
 */
ErrorStatus RCC_errDisablePeripheralClk(PeripheralId_type Copy_enmPeripheralId);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*RCC_INTERFACE_H*/
