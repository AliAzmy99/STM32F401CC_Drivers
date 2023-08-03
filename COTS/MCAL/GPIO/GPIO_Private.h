/************************************************************************/
/* SWC  	    : GPIO Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.1													*/
/* Description  : SWC for General-Purpose I/Os 							*/
/************************************************************************/


#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


/*Private Macros*/
	/*Registers*/
		/*First Addresses*/
#define GPIOA_FIRST_ADDRESS		(0x40020000)
#define GPIOB_FIRST_ADDRESS		(0x40020400)
#define GPIOC_FIRST_ADDRESS		(0x40020800)

		/*Register Numbers*/
#define GPIO_MODER_NO		(0u)
#define GPIO_OTYPER_NO		(1u)
#define GPIO_OSPEEDR_NO		(2u)
#define GPIO_PUPDR_NO		(3u)
#define GPIO_IDR_NO			(4u)
#define GPIO_ODR_NO			(5u)
#define GPIO_BSRR_NO		(6u)
#define GPIO_LCKR_NO		(7u)
#define GPIO_AFRL_NO		(8u)
#define GPIO_AFRH_NO		(9u)
/*__________________________________________________________________________________________________________________________________________*/


#endif /*GPIO_PRIVATE_H*/
