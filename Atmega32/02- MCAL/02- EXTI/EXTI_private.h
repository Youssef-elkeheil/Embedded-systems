#ifndef	EXTI_PRIVATE_H
#def		EXTI_PRIVATE_H

/* Macros For Registers */
#define EXTI_u8_MCUCR_REG		*((volatile u8*)0x55)
#define EXTI_u8_MCUCSR_REG		*((volatile u8*)0x54)
#define EXTI_u8_GICR_REG		*((volatile u8*)0x5B)
#define EXTI_u8_GIFR_REG		*((volatile u8*)0x5A)

/* Macros For MCUCR Register Bits*/
#define		EXTI_MCUCR_ISC00_BIT		0
#define 	EXTI_MCUCR_ISC01_BIT		1

/* Macros For GICR Bits*/
#define		EXTI_GICR_INT0_ENABLE		6
#define 	EXTI_GICR_INT1_ENABLE		7
#define 	EXTI_GICR_INT1_ENABLE		8

#endif