/************************************************************************/
/* SWC  	    : RCC Driver                                            */
/* Author	    : Ali Azmy                                              */
/* Version	    : V0.0                                                  */
/* Date 	    : 21 Jul 2023                                           */
/* Description  : SWC for Reset and Clock Control                       */
/************************************************************************/


/*Include Needed Library Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*Include Needed Library Files*/
#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
void RCC_voidInitSysClk(void)
{
    #if HSI == RCC_CLK_SRC
        /*1- Turn On HSI*/
        SET_BIT(RCC_CR, HSION);
        /*2- Select the HSI as the System CLK Src*/
        CLR_BIT(RCC_CFGR, SW0);
        CLR_BIT(RCC_CFGR, SW1);
    #elif HSE == RCC_CLK_SRC
        /*1- Turn On HSE*/
        SET_BIT(RCC_CR, HSEON);
        /*2- Select the HSE as the System CLK Src*/
        SET_BIT(RCC_CFGR, SW0);
        CLR_BIT(RCC_CFGR, SW1);
    #elif PLL == RCC_CLK_SRC
        /*Assignment*/
    #else
        #error Error: Invalid RCC_CLK_SRC Configuration
    #endif
    #warning Do Assignment
}

/* 
 * Func. Name   : RCC_voidEnablePeripheralClk
 * Description  : This function allows the user to enable the clk of a certian peripheral
 * I/p Argument : Copy_u8BusId          Options: AHB1, AHB2, APB1, APB2
 * I/p Argument : Copy_u8PeripheralId   Options: 0 --> 31
 * Return 	    : Nothing
 */
void RCC_voidEnablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
    /*I/p Validation*/
    if ((APB2 < Copy_u8BusId) || (31 < Copy_u8PeripheralId))
    {
        return;
    }
    switch (Copy_u8BusId)
    {
    case AHB1:
        SET_BIT(RCC_AHB1ENR, Copy_u8PeripheralId);
        break;
    
    case AHB2:
        if ( 7 != Copy_u8PeripheralId)
        {
            return;
        }
        SET_BIT(RCC_AHB2ENR, Copy_u8PeripheralId);
        break;
    
    case APB1:
        SET_BIT(RCC_APB1ENR, Copy_u8PeripheralId);
        break;
    
    case APB2:
        SET_BIT(RCC_APB2ENR, Copy_u8PeripheralId);
        break;
    
    default:
        /*Do Nothing*/
        break;
    }
}

/* 
 * Func. Name   : RCC_voidDisanablePeripheralClk
 * Input1 	    : Copy_u8BusId          Options: AHB1, AHB2, APB1, APB2
 * Input2 	    : Copy_u8PeripheralId   Options: 0 --> 31
 * Return 	    : Nothing
 * Description  : This Api allows the user to disable the clk of a certian peripheral
 */
void RCC_voidDisanablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
    #warning use enums to specify inputs to avoid wrong imputs
    /*I/p Validation*/
    if ((APB2 < Copy_u8BusId) || (31 < Copy_u8PeripheralId))
    {
        return;
    }
    switch (Copy_u8BusId)
    {
    case AHB1:
        CLR_BIT(RCC_AHB1ENR, Copy_u8PeripheralId);
        break;
    
    case AHB2:
        if ( 7 != Copy_u8PeripheralId)
        {
            return;
        }
        CLR_BIT(RCC_AHB2ENR, Copy_u8PeripheralId);
        break;
    
    case APB1:
        CLR_BIT(RCC_APB1ENR, Copy_u8PeripheralId);
        break;
    
    case APB2:
        CLR_BIT(RCC_APB2ENR, Copy_u8PeripheralId);
        break;
    
    default:
        /*Do Nothing*/
        break;
    }
}

enum Peripheral
{
    TMR0,
    TMR1,
    ADC = 11,

};
