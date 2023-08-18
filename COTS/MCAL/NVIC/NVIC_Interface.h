/************************************************************************/
/* SWC  	    : NVIC Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for Nested Vectored Interrupt Controller			*/
/************************************************************************/


#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/*Types Definitions*/
	/*IRQ ID Type*/
typedef enum
{
	WWDG = 0,
	EXTI16_PVD,
	EXTI21_TAMP_STAMP,
	EXTI22_RTC_WKUP,
	FLASH,
	RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Stream0,
	DMA1_Stream1,
	DMA1_Stream2,
	DMA1_Stream3,
	DMA1_Stream4,
	DMA1_Stream5,
	DMA1_Stream6,
	ADC,
	EXTI9_5 = 23,
	TIM1_BRK_TIM9,
	TIM1_UP_TIM10,
	TIM1_TRG_COM_TIM11,
	TIM1_CC,
	TIM2,
	TIM3,
	TIM4,
	I2C1_EV,
	I2C1_ER,
	I2C2_EV,
	I2C2_ER,
	SPI1,
	SPI2,
	USART1,
	USART2,
	EXTI15_10 = 40,
	EXTI17_RTC_Alarm,
	EXTI18_OTG_FS_WKUP,
	DMA1_Stream7 = 47,
	SDIO = 49,
	TIM5,
	SPI3,
	DMA2_Stream0 = 56,
	DMA2_Stream1,
	DMA2_Stream2,
	DMA2_Stream3,
	DMA2_Stream4,
	OTG_FS = 67,
	DMA2_Stream5,
	DMA2_Stream6,
	DMA2_Stream7,
	USART6,
	I2C3_EV,
	I2C3_ER,
	FPU = 81,
	SPI4 = 84,
	NOT_A_PERIPHERAL = 240
}IrqId_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: NVIC_errInit
 * Description	: This function allows the user to initialize the nested vectored interrupt controller
 * Return		: Error status of function
 */
ErrorStatus NVIC_errInit(void);

/* 
 * Func. Name	: NVIC_errEnableInterrupt
 * Description	: This function allows the user to enable a specific interrupt
 * I/p Argument	: Copy_enmIrqId
 * Return		: Error status of function
 */
ErrorStatus NVIC_errEnableInterrupt(IrqId_type Copy_enmIrqId);

/* 
 * Func. Name	: NVIC_errDisableInterrupt
 * Description	: This function allows the user to disable a specific interrupt
 * I/p Argument	: Copy_enmIrqId
 * Return		: Error status of function
 */
ErrorStatus NVIC_errDisableInterrupt(IrqId_type Copy_enmIrqId);

/* 
 * Func. Name	: NVIC_errSetPending
 * Description	: This function allows the user to set a specific interrupt as pending
 * I/p Argument	: Copy_enmIrqId
 * Return		: Error status of function
 */
ErrorStatus NVIC_errSetPending(IrqId_type Copy_enmIrqId);

/* 
 * Func. Name	: NVIC_errClearPending
 * Description	: This function allows the user to set a specific interrupt as not pending
 * I/p Argument	: Copy_enmIrqId
 * Return		: Error status of function
 */
ErrorStatus NVIC_errClearPending(IrqId_type Copy_enmIrqId);

/* 
 * Func. Name	: NVIC_errSetPriority
 * Description	: This function allows the user to set the priority group and subgroup of a specific interrupt
 * I/p Argument	: Copy_enmIrqId
 * I/p Argument	: copy_u8Group
 * I/p Argument	: copy_u8SubGroup
 * Return		: Error status of function
 */
ErrorStatus NVIC_errSetPriority(IrqId_type Copy_enmIrqId, u8 copy_u8Group, u8 copy_u8SubGroup);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*NVIC_INTERFACE_H*/
