#ifndef	EXTI_INTERFACE_H
#define	EXTI_INTERFACE_H

/* Initialization Functions  */
void EXTI_voidInt0Init(void (* ptr_Isr0FunLogic)(void));
void EXTI_voidInt1Init(void (* ptr_Isr1FunLogic)(void));
void EXTI_voidInt2Init(void (* ptr_Isr2FunLogic)(void));

#endif 