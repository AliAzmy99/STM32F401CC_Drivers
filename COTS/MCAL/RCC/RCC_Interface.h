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
	/*AHB1*/
	RCC_PERIPHERAL_GPIOA, /*Bit 0*/
	RCC_PERIPHERAL_GPIOB,
	RCC_PERIPHERAL_GPIOC,
	RCC_PERIPHERAL_CRC, /*Bit 12*/
	RCC_PERIPHERAL_DMA1, /*Bit 21*/
	RCC_PERIPHERAL_DMA2,

	/*AHB2*/
	RCC_PERIPHERAL_USBOTGFS, /*Bit 7*/

	/*APB1*/
	RCC_PERIPHERAL_TIM2, /*Bit 0*/
	RCC_PERIPHERAL_TIM3,
	RCC_PERIPHERAL_TIM4,
	RCC_PERIPHERAL_TIM5,
	RCC_PERIPHERAL_WWDG, /*Bit 11*/
	RCC_PERIPHERAL_SPI2, /*Bit 14*/
	RCC_PERIPHERAL_SPI3,
	RCC_PERIPHERAL_USART2, /*Bit 17*/
	RCC_PERIPHERAL_I2C1, /*Bit 21*/
	RCC_PERIPHERAL_I2C2,
	RCC_PERIPHERAL_I2C3,
	RCC_PERIPHERAL_PWR, /*Bit 28*/

	/*APB2*/
	RCC_PERIPHERAL_TIM1, /*Bit 0*/
	RCC_PERIPHERAL_USART1, /*Bit 4*/
	RCC_PERIPHERAL_USART6,
	RCC_PERIPHERAL_ADC1, /*Bit 8*/
	RCC_PERIPHERAL_SDIO, /*Bit 11*/
	RCC_PERIPHERAL_SPI1,
	RCC_PERIPHERAL_SPI4,
	RCC_PERIPHERAL_SYSCFG,
	RCC_PERIPHERAL_TIM9, /*Bit 16*/
	RCC_PERIPHERAL_TIM10,
	RCC_PERIPHERAL_TIM11
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
