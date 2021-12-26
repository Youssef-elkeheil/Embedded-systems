#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*PORT options:
 *POATA
 *POATB
 */
/*EXTI options:
 *EXTI0
 *EXTI1
 *EXTI2
 *EXTI3
 */
/*state options:
 *FALLING
 *RISSING
 *ANY_CHANGE
 */
void MCAL_EXTI0_3_Init(int Port, char EXTx, char state, void (*isr)(void));

#endif