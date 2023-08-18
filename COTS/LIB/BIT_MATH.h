#ifndef BIT_MATH_H
#define BIT_MATH_H


/*Function-like Macros for Logical Operations on Variables or Registers*/
	/*Bits*/
#define SET_BIT(Var,BitNo)						(Var) |= (1<<(BitNo))
#define CLR_BIT(Var,BitNo)						(Var) &= ~(1<<(BitNo))
#define TOGGLE_BIT(Var,BitNo)					(Var) ^= (1<<(BitNo))
#define GET_BIT(Var,BitNo)						(((Var) >> (BitNo)) & 1)
#define MAKE_BIT(Var,BitNo,Val)					(Var) = (((Var) & (~(1<<(BitNo)))) | ((Val)<<(BitNo)))

	/*Bytes*/
#define SET_BYTE(Var, BitNo)					(Var) |= (0xFF << (BitNo))
#define CLR_BYTE(Var, BitNo)					(Var) &= ~(0xFF << (BitNo))

	/*Nibbles*/
#define SET_NIBBLE(Var, BitNo)					(Var) |= (0xF << (BitNo))
#define CLR_NIBBLE(Var, BitNo)					(Var) &= ~(0xF << (BitNo))

	/*Concatenating*/
#define CONC_BYTE(A7,A6,A5,A4,A3,A2,A1,A0)		(0b##A7##A6##A5##A4##A3##A2##A1##A0)
/*__________________________________________________________________________________________________________________________________________*/


#endif /*BIT_MATH_H*/
