/**********************************************************************
 * Title		: Universal MACROS File for Commonly Needed Macros
 * Layer		: Libraries
 * Author		: Ashraf Ehab
 * Last Update	: Oct 23, 2022
 **********************************************************************/


#ifndef MACROS_H
#define MACROS_H


/*Defining Macros*/
#define TRUE			(1u)
#define FALSE			(0u)

#ifndef NULL
#define NULL			((void*)0u)
#endif

#define IDLE			(0u)
#define BUSY			(1u)

#define DISABLE			(1u)
#define ENABLE			(2u)

#define BIT_HIGH		(1u)
#define BIT_LOW			(0u)
#define BYTE_HIGH		(0xFF)
#define BYTE_LOW		(0x00)
/*__________________________________________________________________________________________________________________________________________*/


/*Efficient Multiplication and Division*/
	/*Multiplication*/
#define MUL2(Var)			((Var) << 1)
#define MUL4(Var)			((Var) << 2)
#define MUL8(Var)			((Var) << 3)
#define MUL16(Var)			((Var) << 4)
#define MUL32(Var)			((Var) << 5)
#define MUL64(Var)			((Var) << 6)
#define MUL128(Var)			((Var) << 7)
#define MUL256(Var)			((Var) << 8)
#define MUL512(Var)			((Var) << 9)
#define MUL1024(Var)		((Var) << 10)

	/*Division*/
#define DIV2(Var)			((Var) >> 1)
#define DIV4(Var)			((Var) >> 2)
#define DIV8(Var)			((Var) >> 3)
#define DIV16(Var)			((Var) >> 4)
#define DIV32(Var)			((Var) >> 5)
#define DIV64(Var)			((Var) >> 6)
#define DIV128(Var)			((Var) >> 7)
#define DIV256(Var)			((Var) >> 8)
#define DIV512(Var)			((Var) >> 9)
#define DIV1024(Var)		((Var) >> 10)
/*__________________________________________________________________________________________________________________________________________*/


#endif /*MACROS_H*/
