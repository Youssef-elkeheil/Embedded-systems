#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char 			    u8;
typedef signed char			    	s8;

typedef unsigned short int 			uint_16;
typedef unsigned long int 			uint_32;
typedef unsigned long long int 		uint_64;

typedef signed short int 			sint_16;
typedef signed long int 			sint_32;
typedef signed long long int 		sint_64;

typedef float 	  					float_32;
typedef double 						float_64;
typedef long double 				float_128;

#define NULL                        ((void *)0)
#define OK                           0
#define NOK                         (u8)-1 

#endif