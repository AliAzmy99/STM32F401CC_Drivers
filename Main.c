#include "COTS/LIB/STD_TYPES.h"
#include "COTS/LIB/MACROS.h"
#include "COTS/LIB/BIT_MATH.h"

#include "COTS/MCAL/RCC/RCC_Interface.h"
#include "COTS/MCAL/GPIO/GPIO_Interface.h"
#include "COTS/MCAL/STK/STK_Interface.h"

#include "COTS/SRV/SCH/SCH_Interface.h"

int main(void)
{
    /*Init System Clock*/
    RCC_vdInitSysClk();
    
    /*Enable Clock for GPIOA*/
    RCC_vdEnablePeripheralClk(RCC_PERIPHERAL_GPIOA);
    
    /*Configure the Mode of the LEDS Pins as O/P*/


    /*Create Tasks*/
    SCH_vdCreateTask(0, 200, APP_LED1,  0);  //200  micro sec
    SCH_vdCreateTask(1, 500, APP_LED2,  1);  //500  micro sec
    SCH_vdCreateTask(2, 100, APP_LED3, 2);  //100   micro sec

    /*Start Scheduling*/
    SCH_StartOs();

    while(1);

	/*Return*/
	return 0;
}
