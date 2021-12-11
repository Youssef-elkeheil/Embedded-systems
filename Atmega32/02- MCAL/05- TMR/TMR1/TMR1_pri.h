#ifndef _TMR1_PRI_H
#define _TMR1_PRI_H



/* Masking for the Select Clock Bits */
#define TMR1_SELECT_CLOCK_MASKING		   0xF8

/* Options for Timer modes */
#define TMR1_MODE_FAST_PWM_TOP_ICR1		   0
#define TMR1_MODE_ICU	  				   1

/* Options for selecting a channel */
#define TMR1_CHANNEL_A 					   0
#define TMR1_CHANNEL_B				       1

/* Options for selecting leading edge */
#define TMR1_CHANNEL_MODE_INVERTING	       0
#define TMR1_CHANNEL_MODE_NON_INVERTING	   1

/* Option for Clock Source */
#define TMR1_CLOCK_SOURCE_STOP             0
#define TMR1_CLOCK_SOURCE_PRESCALER_1      1
#define TMR1_CLOCK_SOURCE_PRESCALER_8      2
#define TMR1_CLOCK_SOURCE_PRESCALER_64     3
#define TMR1_CLOCK_SOURCE_PRESCALER_256    4
#define TMR1_CLOCK_SOURCE_PRESCALER_1024   5
#define TMR1_CLOCK_SOURCE_EXTERNAL_RISING  6
#define TMR1_CLOCK_SOURCE_EXTERNAL_FALLING 7

/*
 * ISR Compiler Attribute 
 */
/* ICU Interrupt */
void __vector_6 (void) __attribute__((signal));


#endif /* _TMR0_PRI_H */
