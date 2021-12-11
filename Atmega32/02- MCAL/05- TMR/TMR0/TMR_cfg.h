#ifndef _TMR0_CFG_H
#define _TMR0_CFG_H

/* Select the required option for Timer mode
 * TMR0_MODE_OVERFLOW - TMR0_MODE_CTC
 */
#define TMR0_MODE TMR0_MODE_OVERFLOW

/* Select the required option for timer clock source
 * TMR0_CLOCK_SOURCE_STOP            - TMR0_CLOCK_SOURCE_PRESCALER_1
 * TMR0_CLOCK_SOURCE_PRESCALER_8     - TMR0_CLOCK_SOURCE_PRESCALER_64
 * TMR0_CLOCK_SOURCE_PRESCALER_256   - TMR0_CLOCK_SOURCE_PRESCALER_1024
 * TMR0_CLOCK_SOURCE_EXTERNAL_RISING - TMR0_CLOCK_SOURCE_EXTERNAL_FALLING
 */
#define TMR0_CLOCK_SOURCE TMR0_CLOCK_SOURCE_PRESCALER_1024

#if TMR0_MODE == TMR0_MODE_CTC
/* Set the Top value for CTC mode */
#define TMR0_CTC_TOP_VALUE         255
#endif

/* Set the required initial value */
#define TMR0_PRELOAD_VALUE         0

/* Set the Number of overflows */
#define TMR0_NEEDED_OVERFLOW 	   122

#endif /* _TMR0_CFG_H */
