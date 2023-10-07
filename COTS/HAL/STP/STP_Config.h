/************************************************************************/
/* SWC			: STP Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Serial to Parallel using 74HC595				*/
/************************************************************************/


#ifndef STP_CONFIG_H
#define STP_CONFIG_H


/*Choosing where to Connect the 74HC595 Pin*/
#define DS_PIN			GPIO_PIN_0			/*Options: PinId_type*/
#define DS_PORT			GPIO_PORT_A			/*Options: PortId_type*/
#define SH_CLK_PIN		GPIO_PIN_1			/*Options: PinId_type*/
#define SH_CLK_PORT		GPIO_PORT_A			/*Options: PortId_type*/
#define ST_CLK_PIN		GPIO_PIN_2			/*Options: PinId_type*/
#define ST_CLK_PORT		GPIO_PORT_A			/*Options: PortId_type*/
/*__________________________________________________________________________________________________________________________________________*/


/*Choosing the Number of Chained 74HC595 ICs*/
#define NUM_CHAINED_ICS		(1u)						/*Options: 1 -> 4*/
/*__________________________________________________________________________________________________________________________________________*/


#endif /*STP_CONFIG_H*/
