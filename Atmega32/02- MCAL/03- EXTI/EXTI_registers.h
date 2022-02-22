#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

/* Macros For GICR Register */
#define GICR_REG		*((volatile u8*)0x5B)
#define GICR_INT0		6
#define GICR_INT1		7
#define GICR_INT2		5

/* Macros For GIFR Register */
#define GIFR_REG 		*((volatile u8*)0x5A)
#define GIFR_INTF0		6
#define GIFR_INTF1		7
#define GIFR_INTF2		5

/* Macros For MCUCR Register */
#define MCUCR_REG		*((volatile u8*)0x55)
#define MCUCR_ISC00		0
#define MCUCR_ISC01		1
#define MCUCR_ISC10		2
#define MCUCR_ISC11		3

/* Macros For MCUCSR Register */
#define MCUCSR_REG		*((volatile u8*)0x54)
#define MCUCSR_ISC2		6

#endif