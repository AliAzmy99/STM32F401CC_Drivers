/************************************************************************/
/* SWC  	    : RCC Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.1													*/
/* Description  : SWC for Reset and Clock Control						*/
/************************************************************************/


#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


/*Public Macros*/
    /*Peripheral ID Options*/
#define PERIPHERAL_USBFS	(0u)
#define PERIPHERAL_DMA1		(1u)
#define PERIPHERAL_DMA2		(2u)
#define PERIPHERAL_CRC		(3u)
#define PERIPHERAL_GPIOA	(4u)
#define PERIPHERAL_GPIOB	(5u)
#define PERIPHERAL_GPIOC	(6u)
#define PERIPHERAL_TIM1		(7u)
#define PERIPHERAL_TIM2		(8u)
#define PERIPHERAL_TIM3		(9u)
#define PERIPHERAL_TIM4		(10u)
#define PERIPHERAL_TIM5		(11u)
#define PERIPHERAL_TIM9		(12u)
#define PERIPHERAL_TIM10	(13u)
#define PERIPHERAL_TIM11	(14u)
#define PERIPHERAL_SYSCFG	(15u)
#define PERIPHERAL_SPI1		(16u)
#define PERIPHERAL_SPI2		(17u)
#define PERIPHERAL_SPI3		(18u)
#define PERIPHERAL_SPI4		(19u)
#define PERIPHERAL_SDIO		(20u)
#define PERIPHERAL_ADC1		(21u)
#define PERIPHERAL_USART1	(22u)
#define PERIPHERAL_USART2	(23u)
#define PERIPHERAL_USART6	(24u)
#define PERIPHERAL_PWR		(25u)
#define PERIPHERAL_I2C1		(26u)
#define PERIPHERAL_I2C2		(27u)
#define PERIPHERAL_I2C3		(28u)
#define PERIPHERAL_WWDG		(29u)
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
 * I/p Argument	: Copy_u8PeripheralId	Options: PERIPHERAL_USBFS -> PERIPHERAL_WWDG
 * Return		: Error status of function
 */
ErrorStatus RCC_errEnablePeripheralClk(u8 Copy_u8PeripheralId);

/* 
 * Func. Name	: RCC_errDisanablePeripheralClk
 * Description	: This function allows the user to disable the clk of a certian peripheral
 * I/p Argument	: Copy_u8PeripheralId	Options: PERIPHERAL_USBFS -> PERIPHERAL_WWDG
 * Return		: Error status of function
 */
ErrorStatus RCC_errDisanablePeripheralClk(u8 Copy_u8PeripheralId);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*RCC_INTERFACE_H*/
