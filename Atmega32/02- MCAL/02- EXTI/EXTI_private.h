#ifndef	EXTI_PRIVATE_H
#define	EXTI_PRIVATE_H

/* EXTI0 Modes */
#define EXTI0_MODE_LOW_LEVEL			0
#define EXTI0_MODE_ANY_LOGICAL_CHANGE	1
#define EXTI0_MODE_FALLING				2
#define EXTI0_MODE_RISING				3

/* EXTI1 Modes */
#define EXTI1_MODE_LOW_LEVEL			0<<2
#define EXTI1_MODE_ANY_LOGICAL_CHANGE	1<<2
#define EXTI1_MODE_FALLING				2<<2
#define EXTI1_MODE_RISING				3<<2

/* EXTI2 Modes */
#define EXTI2_MODE_FALLING				0<<6
#define EXTI2_MODE_RISING				1<<6

/* EXTI pins */
#define INT0_PIN						2
#define INT1_PIN						3
#define INT2_PIN						2

/* EXTI ports */
#define INT0_PORT						3
#define INT1_PORT						3
#define INT2_PORT						1

#endif