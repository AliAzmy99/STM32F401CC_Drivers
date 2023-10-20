/************************************************************************/
/* SWC			: SPI Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Serial Peripheral Interface					*/
/************************************************************************/


#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H


/*Choosing SPI Pins*/
#define PIN_MOSI		GPIO_PIN_7
#define PORT_MOSI		GPIO_PORT_A

#define PIN_MISO		GPIO_PIN_6
#define PORT_MISO		GPIO_PORT_A

#define PIN_SCK			GPIO_PIN_5
#define PORT_SCK		GPIO_PORT_A

#define PIN_NSS			GPIO_PIN_4
#define PORT_NSS		GPIO_PORT_A
/*__________________________________________________________________________________________________________________________________________*/


/*Choosing Between Master and Slave*/
#define IS_MASTER		STD_TRUE		/*Options: STD_TRUE, STD_FALSE*/
/*__________________________________________________________________________________________________________________________________________*/


/*Choosing SPI Clk Prescaler*/
#define SPI_CLK_PRE		SPI_FP_2		/*Options: SPI_FP_2, SPI_FP_4, SPI_FP_8, SPI_FP_16, SPI_FP_32, SPI_FP_64, SPI_FP_128, SPI_FP_256*/
/*__________________________________________________________________________________________________________________________________________*/


#endif /*SPI_CONFIG_H*/
