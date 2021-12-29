#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/* function to initialize EXTI0 ->EXTI3 
*/
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
void MCAL_EXTI0_3_Init(char Port, int EXTx, char state, void (*Local_ISR_Logic)(void));
/* Enable EXTI0 -> EXTI3 */
void MCAL_EXTI_Enable(char EXTx);
/* Disable EXTI0 -> EXTI3 */
void MCAL_EXTI_Disable(char EXTx);

/* EXTI options: */
#define EXTI0 0
#define EXTI1 1
#define EXTI2 2
#define EXTI3 3

/* state options: */
#define FALLING 1
#define RISSING 2
#define ANY_CHANGE 3

#endif