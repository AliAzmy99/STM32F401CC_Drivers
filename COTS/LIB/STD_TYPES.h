/************************************************************************/
/* SWC  	    : Standard Types Library								*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for defining standard types						*/
/************************************************************************/


#ifndef STD_TYPES_H
#define STD_TYPES_H


/*Type Definitions*/
	/*Redefining Types for Portability and Conciseness*/
typedef unsigned char			u8;
typedef signed char				s8;

typedef unsigned short int		u16;
typedef signed short int		s16;

typedef unsigned long int		u32;
typedef signed long int			s32;

typedef unsigned long long int	u64;
typedef signed long long int	s64;

typedef float					f32;
typedef double					f64;
typedef long double				f128;
/*__________________________________________________________________________________________________________________________________________*/


/*Enumerators*/
	/*Value Type*/
typedef enum
{
	STD_LOW,
	STD_HIGH
}Value_type;

	/*Enable Type*/
typedef enum
{
	STD_DISABLE,
	STD_ENABLE
}Enable_type;

	/*True Type*/
typedef enum
{
	STD_FALSE,
	STD_TRUE
}True_type;
/*__________________________________________________________________________________________________________________________________________*/


#endif	/*STD_TYPES_H*/
