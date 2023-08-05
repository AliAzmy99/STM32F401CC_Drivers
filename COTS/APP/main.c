/*Include Needed Files*/
	/*Include Needed Library Files*/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/MACROS.h"

	/*Include Needed MCAL Files*/
#include "../MCAL/RCC/RCC_Interface.h"
#include "../MCAL/GPIO/GPIO_Interface.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Functions Declarations*/
void MAIN_vdDelay(u32 Copy_u32MilliSeconds);

void MAIN_vdDisplay(u8 Copy_u8LedArray);

u8 MAIN_u8ShiftLeft(u8 Copy_u8LedArray, u8 Copy_u8Size);

u8 MAIN_u8ShiftRight(u8 Copy_u8LedArray, u8 Copy_u8Size);

u8 MAIN_u8Converge(u8 Copy_u8LedArray);

u8 MAIN_u8Diverge(u8 Copy_u8LedArray);

u8 MAIN_u8Pong(u8 Copy_u8LedArray);

u8 MAIN_u8Loading(u8 Copy_u8LedArray);
/*__________________________________________________________________________________________________________________________________________*/


/*Main Function Definition*/
int main()
{
	u8 Loc_u8LedArray = 0b00000000;

	/*RCC Setup*/
	RCC_errInitSysClk();
	RCC_errEnablePeripheralClk(PERIPHERAL_GPIOA);

	/*GPIO Setup*/
	for (u8 Loc_u8PinCounter = GPIO_PIN_0; GPIO_PIN_8 > Loc_u8PinCounter; ++Loc_u8PinCounter)
	{
		GPIO_errSetPinMode(GPIO_PORT_A, Loc_u8PinCounter, GPIO_MODE_OUTPUT);
		GPIO_errSetPinOutputType(GPIO_PORT_A, Loc_u8PinCounter, GPIO_OUTPUT_TYPE_PP);
		GPIO_errSetPinOutputSpeed(GPIO_PORT_A, Loc_u8PinCounter, GPIO_OUTPUT_SPEED_L);
	}

	/*Main Loop*/
	while(1)
	{
		MAIN_vdDisplay(Loc_u8LedArray);
		MAIN_vdDelay(1000);
		Loc_u8LedArray = MAIN_u8Loading(Loc_u8LedArray);
	}

	return 0;
}
/*__________________________________________________________________________________________________________________________________________*/


/*Functions Definitions*/
void MAIN_vdDelay(u32 Copy_u32MilliSeconds)
{
	Copy_u32MilliSeconds *= 3200;
	for (u32 Loc_u32Counter = 0; Copy_u32MilliSeconds > Loc_u32Counter; ++Loc_u32Counter)
	{
		__asm("nop");
	}
}

void MAIN_vdDisplay(u8 Copy_u8LedArray)
{
	for (u8 Loc_u8PinCounter = GPIO_PIN_0; GPIO_PIN_8 > Loc_u8PinCounter; ++Loc_u8PinCounter)
	{
		if ((Copy_u8LedArray >> Loc_u8PinCounter) & 0b00000001)
		{
			GPIO_errSetPinValue(GPIO_PORT_A, Loc_u8PinCounter, GPIO_VALUE_H);
		}
		else
		{
			GPIO_errSetPinValue(GPIO_PORT_A, Loc_u8PinCounter, GPIO_VALUE_L);
		}
	}
}

u8 MAIN_u8ShiftLeft(u8 Copy_u8LedArray, u8 Copy_u8Size)
{
	Copy_u8LedArray = (Copy_u8LedArray)? Copy_u8LedArray << 1 : 1;
	return ((1 << Copy_u8Size) <= Copy_u8LedArray)? 0 : Copy_u8LedArray;
}

u8 MAIN_u8ShiftRight(u8 Copy_u8LedArray, u8 Copy_u8Size)
{
	return (Copy_u8LedArray)? (Copy_u8LedArray >> 1) : (1 << (Copy_u8Size - 1));
}

u8 MAIN_u8Converge(u8 Copy_u8LedArray)
{
	u8 Loc_u8LeftLedArray = (Copy_u8LedArray & 0b11110000) >> 4;
	u8 Loc_u8RightLedArray = Copy_u8LedArray & 0b00001111;
	Loc_u8LeftLedArray = MAIN_u8ShiftRight(Loc_u8LeftLedArray, 4);
	Loc_u8RightLedArray = MAIN_u8ShiftLeft(Loc_u8RightLedArray, 4);
	return (Loc_u8LeftLedArray << 4) | Loc_u8RightLedArray;
}

u8 MAIN_u8Diverge(u8 Copy_u8LedArray)
{
	u8 Loc_u8LeftLedArray = (Copy_u8LedArray & 0b11110000) >> 4;
	u8 Loc_u8RightLedArray = Copy_u8LedArray & 0b00001111;
	Loc_u8LeftLedArray = MAIN_u8ShiftLeft(Loc_u8LeftLedArray, 4);
	Loc_u8RightLedArray = MAIN_u8ShiftRight(Loc_u8RightLedArray, 4);
	return (Loc_u8LeftLedArray << 4) | Loc_u8RightLedArray;
}

u8 MAIN_u8Pong(u8 Copy_u8LedArray)
{
	static u8 Loc_u8Direction = 1;
	if (!Copy_u8LedArray)
	{
		return 1;
	}
	if (Loc_u8Direction)
	{
		Copy_u8LedArray = MAIN_u8ShiftLeft(Copy_u8LedArray, 8);
	}
	else
	{
		Copy_u8LedArray = MAIN_u8ShiftRight(Copy_u8LedArray, 8);
	}
	if (Loc_u8Direction && 0b10000000 == Copy_u8LedArray)
	{
		Loc_u8Direction = 0;
	}
	else if (!Loc_u8Direction && 0b00000001 == Copy_u8LedArray)
	{
		Loc_u8Direction = 1;
	}
	return Copy_u8LedArray;
}

u8 MAIN_u8Loading(u8 Copy_u8LedArray)
{
	return (0b11111111 == Copy_u8LedArray)? 0 : ((Copy_u8LedArray >> 1) + 0b10000000);
}
