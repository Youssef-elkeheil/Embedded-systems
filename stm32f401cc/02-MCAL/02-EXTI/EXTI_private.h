#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/* EXTI */
#define EXTI0 0
#define EXTI1 1
#define EXTI2 2
#define EXTI3 3

/* state */
#define FALLING 1
#define RISSING 2
#define ANY_CHANGE 3

/* state masking */
#define FALLING(state)  (state&1)
#define RISING(state) ((state>>1) & 1)

#endif