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
	NVIC_IRQ_WWDG = 0,
	NVIC_IRQ_EXTI16_PVD,
	NVIC_IRQ_EXTI21_TAMP_STAMP,
	NVIC_IRQ_EXTI22_RTC_WKUP,
	NVIC_IRQ_FLASH,
	NVIC_IRQ_RCC,
	NVIC_IRQ_EXTI0,
	NVIC_IRQ_EXTI1,
	NVIC_IRQ_EXTI2,
	NVIC_IRQ_EXTI3,
	NVIC_IRQ_EXTI4,
	NVIC_IRQ_DMA1_Stream0,
	NVIC_IRQ_DMA1_Stream1,
	NVIC_IRQ_DMA1_Stream2,
	NVIC_IRQ_DMA1_Stream3,
	NVIC_IRQ_DMA1_Stream4,
	NVIC_IRQ_DMA1_Stream5,
	NVIC_IRQ_DMA1_Stream6,
	NVIC_IRQ_ADC,
	NVIC_IRQ_EXTI9_5 = 23,
	NVIC_IRQ_TIM1_BRK_TIM9,
	NVIC_IRQ_TIM1_UP_TIM10,
	NVIC_IRQ_TIM1_TRG_COM_TIM11,
	NVIC_IRQ_TIM1_CC,
	NVIC_IRQ_TIM2,
	NVIC_IRQ_TIM3,
	NVIC_IRQ_TIM4,
	NVIC_IRQ_I2C1_EV,
	NVIC_IRQ_I2C1_ER,
	NVIC_IRQ_I2C2_EV,
	NVIC_IRQ_I2C2_ER,
	NVIC_IRQ_SPI1,
	NVIC_IRQ_SPI2,
	NVIC_IRQ_USART1,
	NVIC_IRQ_USART2,
	NVIC_IRQ_EXTI15_10 = 40,
	NVIC_IRQ_EXTI17_RTC_Alarm,
	NVIC_IRQ_EXTI18_OTG_FS_WKUP,
	NVIC_IRQ_DMA1_Stream7 = 47,
	NVIC_IRQ_SDIO = 49,
	NVIC_IRQ_TIM5,
	NVIC_IRQ_SPI3,
	NVIC_IRQ_DMA2_Stream0 = 56,
	NVIC_IRQ_DMA2_Stream1,
	NVIC_IRQ_DMA2_Stream2,
	NVIC_IRQ_DMA2_Stream3,
	NVIC_IRQ_DMA2_Stream4,
	NVIC_IRQ_OTG_FS = 67,
	NVIC_IRQ_DMA2_Stream5,
	NVIC_IRQ_DMA2_Stream6,
	NVIC_IRQ_DMA2_Stream7,
	NVIC_IRQ_USART6,
	NVIC_IRQ_I2C3_EV,
	NVIC_IRQ_I2C3_ER,
	NVIC_IRQ_FPU = 81,
	NVIC_IRQ_SPI4 = 84,
	NVIC_NOT_AN_IRQ = 240
}IrqId_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: NVIC_vdInit
 * Description	: This function allows the user to initialize the nested vectored interrupt controller
 */
void NVIC_vdInit(void);

/* 
 * Func. Name	: NVIC_vdEnableInterrupt
 * Description	: This function allows the user to enable a specific interrupt
 * I/p Argument	: Copy_enmIrqId
 */
void NVIC_vdEnableInterrupt(IrqId_type Copy_enmIrqId);

/* 
 * Func. Name	: NVIC_vdDisableInterrupt
 * Description	: This function allows the user to disable a specific interrupt
 * I/p Argument	: Copy_enmIrqId
 */
void NVIC_vdDisableInterrupt(IrqId_type Copy_enmIrqId);

/* 
 * Func. Name	: NVIC_vdSetPending
 * Description	: This function allows the user to set a specific interrupt as pending
 * I/p Argument	: Copy_enmIrqId
 */
void NVIC_vdSetPending(IrqId_type Copy_enmIrqId);

/* 
 * Func. Name	: NVIC_vdGetPending
 * Description	: This function allows the user to know whether a specific interrupt is pending
 * I/p Argument	: Copy_enmIrqId
 * O/p Argument : Outptr_u8Pending		Options: TRUE, FALSE
 */
void NVIC_vdGetPending(IrqId_type Copy_enmIrqId, u8* Outptr_u8Pending);

/* 
 * Func. Name	: NVIC_vdClearPending
 * Description	: This function allows the user to set a specific interrupt as not pending
 * I/p Argument	: Copy_enmIrqId
 */
void NVIC_vdClearPending(IrqId_type Copy_enmIrqId);

/* 
 * Func. Name	: NVIC_vdSetPriority
 * Description	: This function allows the user to set the priority group and subgroup of a specific interrupt
 * I/p Argument	: Copy_enmIrqId
 * I/p Argument	: copy_u8Group
 * I/p Argument	: copy_u8SubGroup
 */
void NVIC_vdSetPriority(IrqId_type Copy_enmIrqId, u8 copy_u8Group, u8 copy_u8SubGroup);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*NVIC_INTERFACE_H*/
