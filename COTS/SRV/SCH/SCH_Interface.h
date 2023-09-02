/************************************************************************/
/* SWC			: SCH Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.2													*/
/* Description	: SWC for Reset and Clock Control						*/
/************************************************************************/


#ifndef SCH_INTERFACE_H
#define SCH_INTERFACE_H


/*Types Definitions*/
	/*Peripheral ID Type*/
typedef enum
{
	SCH_PERIPHERAL_USBFS,
	SCH_PERIPHERAL_DMA1,
	SCH_PERIPHERAL_DMA2,
	SCH_PERIPHERAL_CRC,
	SCH_PERIPHERAL_GPIOA,
	SCH_PERIPHERAL_GPIOB,
	SCH_PERIPHERAL_GPIOC,
	SCH_PERIPHERAL_TIM1,
	SCH_PERIPHERAL_TIM2,
	SCH_PERIPHERAL_TIM3,
	SCH_PERIPHERAL_TIM4,
	SCH_PERIPHERAL_TIM5,
	SCH_PERIPHERAL_TIM9,
	SCH_PERIPHERAL_TIM10,
	SCH_PERIPHERAL_TIM11,
	SCH_PERIPHERAL_SYSCFG,
	SCH_PERIPHERAL_SPI1,
	SCH_PERIPHERAL_SPI2,
	SCH_PERIPHERAL_SPI3,
	SCH_PERIPHERAL_SPI4,
	SCH_PERIPHERAL_SDIO,
	SCH_PERIPHERAL_ADC1,
	SCH_PERIPHERAL_USART1,
	SCH_PERIPHERAL_USART2,
	SCH_PERIPHERAL_USART6,
	SCH_PERIPHERAL_PWR,
	SCH_PERIPHERAL_I2C1,
	SCH_PERIPHERAL_I2C2,
	SCH_PERIPHERAL_I2C3,
	SCH_PERIPHERAL_WWDG,
	SCH_NOT_A_PERIPHERAL	/*Must remain the last element*/
}PeripheralId_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: SCH_errInitSysClk
 * Description	: This function allows the user to initialize the system clk
 * Return		: Error status of function
 */
ErrorStatus SCH_errInitSysClk(void);

/* 
 * Func. Name	: SCH_voidEnablePeripheralClk
 * Description	: This function allows the user to enable the clk of a certian peripheral
 * I/p Argument	: Copy_enmPeripheralId			Options: PERIPHERAL_USBFS -> PERIPHERAL_WWDG
 * Return		: Error status of function
 */
ErrorStatus SCH_errEnablePeripheralClk(PeripheralId_type Copy_enmPeripheralId);

/* 
 * Func. Name	: SCH_errDisablePeripheralClk
 * Description	: This function allows the user to disable the clk of a certian peripheral
 * I/p Argument	: Copy_enmPeripheralId			Options: PERIPHERAL_USBFS -> PERIPHERAL_WWDG
 * Return		: Error status of function
 */
ErrorStatus SCH_errDisablePeripheralClk(PeripheralId_type Copy_enmPeripheralId);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*SCH_INTERFACE_H*/
