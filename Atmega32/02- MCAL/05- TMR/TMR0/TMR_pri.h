#ifndef _TMR0_PRI_H
#define _TMR0_PRI_H

/* Max number of counts */
#define TMR0_MAX_COUNT_VALUE               256

/* Masking for the Select Clock Bits */
#define TMR0_SELECT_CLOCK_MASKING		   0xF8
/* Options for Timer modes */
#define TMR0_MODE_OVERFLOW 				   0
#define TMR0_MODE_CTC	  				   2

/* Option for Clock Source */
#define TMR0_CLOCK_SOURCE_STOP             0
#define TMR0_CLOCK_SOURCE_PRESCALER_1      1
#define TMR0_CLOCK_SOURCE_PRESCALER_8      2
#define TMR0_CLOCK_SOURCE_PRESCALER_64     3
#define TMR0_CLOCK_SOURCE_PRESCALER_256    4
#define TMR0_CLOCK_SOURCE_PRESCALER_1024   5
#define TMR0_CLOCK_SOURCE_EXTERNAL_RISING  6
#define TMR0_CLOCK_SOURCE_EXTERNAL_FALLING 7


/*
 * ISR Compiler Attribute 
 */
void __vector_10 (void) __attribute__((signal));
void __vector_11 (void) __attribute__((signal));

#endif /* _TMR0_PRI_H */
