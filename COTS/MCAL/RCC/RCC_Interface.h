/************************************************************************/
/* SWC  	    : RCC Driver                                            */
/* Author	    : Ali Azmy                                              */
/* Description  : SWC for Reset and Clock Control                       */
/************************************************************************/


#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


/*Public Macros*/
    /*Bus ID Options:*/
#define AHB1    (0u)
#define AHB2    (1u)
#define APB1    (2u)
#define APB2    (3u)

    /*Peripheral IDs*/
#define PREI_USBFS          (0u)
#define PREI_DMA1           (1u)
#define PREI_DMA2           (2u)
#define PREI_CRC            (3u)
#define PREI_GPIOA          (4u)
#define PREI_GPIOB          (5u)
#define PREI_GPIOC          (6u)
#define PREI_TIM1           (7u)
#define PREI_TIM2           (8u)
#define PREI_TIM3           (9u)
#define PREI_TIM4           (10u)
#define PREI_TIM5           (11u)
#define PREI_TIM9           (12u)
#define PREI_TIM10          (13u)
#define PREI_TIM11          (14u)
#define PREI_SYSCFG         (15u)
#define PREI_SPI1           (16u)
#define PREI_SPI2           (17u)
#define PREI_SPI3           (18u)
#define PREI_SPI4           (19u)
#define PREI_SDIO           (20u)
#define PREI_ADC1           (21u)
#define PREI_USART1         (22u)
#define PREI_USART2         (23u)
#define PREI_USART6         (24u)
#define PREI_PWR            (25u)
#define PREI_I2C1           (26u)
#define PREI_I2C2           (27u)
#define PREI_I2C3           (28u)
#define PREI_WWDG           (29u)
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name   : RCC_errInitSysClk
 * Description  : This function allows the user to initiate the system clk
 * I/p Argument : No Inputs
 * Return 	    : Error status of function
 */
ErrorStatus RCC_errInitSysClk(void);

/* 
 * Func. Name   : RCC_voidEnablePeripheralClk
 * Description  : This function allows the user to enable the clk of a certian peripheral
 * I/p Argument : Copy_u8PeripheralId   Options: PREI_USBFS -> PREI_WWDG
 * Return 	    : Error status of function
 */
ErrorStatus RCC_errEnablePeripheralClk(u8 Copy_u8PeripheralId);

/* 
 * Func. Name   : RCC_voidDisanablePeripheralClk
 * Input2 	    : Copy_u8PeripheralId   Options: PREI_USBFS -> PREI_WWDG
 * Return 	    : Error status of function
 */
ErrorStatus RCC_errDisanablePeripheralClk(u8 Copy_u8PeripheralId);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*RCC_INTERFACE_H*/
