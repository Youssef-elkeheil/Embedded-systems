#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/* state masking */
#define FALLING_MASK(state) (state & 1)
#define RISING_MASK(state) ((state >> 1) & 1)

#endif