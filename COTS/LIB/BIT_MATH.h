/************************************************************************/
/* SWC  	    : Bit Math Library										*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.1													*/
/* Description  : SWC for bit manipulation								*/
/************************************************************************/


#ifndef BIT_MATH_H
#define BIT_MATH_H


/*Function-like Macros for Logical Operations on Variables or Registers*/
	/*Bits*/
#define SET_BIT(Var, BitNo)						(Var) |= 0x1 << (BitNo)
#define CLR_BIT(Var, BitNo)						(Var) &= ~(0x1 << (BitNo))
#define TOGGLE_BIT(Var, BitNo)					(Var) ^= 0x1 << (BitNo)
#define GET_BIT(Var, BitNo)						(((Var) >> (BitNo)) & 0x1)
#define MAKE_BIT(Var, BitNo, Val)				(Var) &= ((~(0x1 << (BitNo)))) | ((Val) << (BitNo))

#define SET_4BITS(Var, BitNo)					(Var) |= 0xF << (BitNo)
#define CLR_4BITS(Var, BitNo)					(Var) &= ~(0xF << (BitNo))
#define TOGGLE_4BITS(Var, BitNo)				(Var) ^= 0xF << (BitNo)
#define GET_4BITS(Var, BitNo)					(((Var) >> (BitNo)) & 0xF)
#define MAKE_4BITS(Var, BitNo, Val)				(Var) &= ((~(0xF << (BitNo)))) | ((Val) << (BitNo))

#define SET_8BITS(Var, BitNo)					(Var) |= 0xFF << (BitNo)
#define CLR_8BITS(Var, BitNo)					(Var) &= ~(0xFF << (BitNo))
#define TOGGLE_8BITS(Var, BitNo)				(Var) ^= 0xFF << (BitNo)
#define GET_8BITS(Var, BitNo)					(((Var) >> (BitNo)) & 0xFF)
#define MAKE_8BITS(Var, BitNo, Val)				(Var) &= ((~(0xFF << (BitNo)))) | ((Val) << (BitNo))

	/*Nibbles*/
#define SET_NIBBLE(Var, NibbleNo)				(Var) |= 0xF << (NIBBLE_TO_BIT_NUM(NibbleNo))
#define CLR_NIBBLE(Var, NibbleNo)				(Var) &= ~(0xF << (NIBBLE_TO_BIT_NUM(NibbleNo)))
#define TOGGLE_NIBBLE(Var, NibbleNo)			(Var) ^= 0xF << (NIBBLE_TO_BIT_NUM(NibbleNo))
#define GET_NIBBLE(Var, NibbleNo)				(((Var) >> (NIBBLE_TO_BIT_NUM(NibbleNo))) & 0xF)
#define MAKE_NIBBLE(Var, NibbleNo, Val)			(Var) &= ((~(0xF << (NIBBLE_TO_BIT_NUM(NibbleNo))))) | ((Val) << (NIBBLE_TO_BIT_NUM(NibbleNo)))

	/*Bytes*/
#define SET_BYTE(Var, ByteNo)					(Var) |= 0xFF << (BYTE_TO_BIT_NUM(ByteNo))
#define CLR_BYTE(Var, ByteNo)					(Var) &= ~(0xFF << (BYTE_TO_BIT_NUM(ByteNo)))
#define TOGGLE_BYTE(Var, ByteNo)					(Var) ^= 0xFF << (BYTE_TO_BIT_NUM(ByteNo))
#define GET_BYTE(Var, ByteNo)					(((Var) >> (BYTE_TO_BIT_NUM(ByteNo))) & 0xFF)
#define MAKE_BYTE(Var, ByteNo, Val)				(Var) &= ((~(0xFF << (BYTE_TO_BIT_NUM(ByteNo))))) | ((Val) << (BYTE_TO_BIT_NUM(ByteNo)))

	/*Conversions*/
#define BYTE_TO_NIBBLE_NUM(Var)					((Var) << 1)
#define NIBBLE_TO_BIT_NUM(Var)					((Var) << 2)
#define BYTE_TO_BIT_NUM(Var)					((Var) << 3)

#define NIBBLE_TO_BYTE_NUM(Var)					((Var) >> 1)
#define BIT_TO_NIBBLE_NUM(Var)					((Var) >> 2)
#define BIT_TO_BYTE_NUM(Var)					((Var) >> 3)

	/*Concatenating*/
#define CONC_BYTE(A7,A6,A5,A4,A3,A2,A1,A0)		(0b##A7##A6##A5##A4##A3##A2##A1##A0)
/*__________________________________________________________________________________________________________________________________________*/


#endif /*BIT_MATH_H*/
