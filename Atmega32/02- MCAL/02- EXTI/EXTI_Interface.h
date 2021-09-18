#ifndef	EXTI_INTERFACE_H
#define	EXTI_INTERFACE_H

/* Inilization Functions  */
void EXTI_voidInt0Init(void (* ptr_Isr0FunLogic)(void));
void EXTI_voidInt1Init(void (* ptr_Isr1FunLogic)(void));
void EXTI_voidInt2Init(void (* ptr_Isr2FunLogic)(void));

/* Registration Functions */
/*
void M_EXTI_void_Int0SetCallBack(void (* ptr_Isr0FunLogic)(void));
void M_EXTI_void_Int1SetCallBack(void (* ptr_Isr1FunLogic)(void));
void M_EXTI_void_Int2SetCallBack(void (* ptr_Isr2FunLogic)(void));
*/

void __vector_1 (void) __attribute__((signal));		//for interrupt 0 logic 
void __vector_2 (void) __attribute__((signal));		//for interrupt 1 logic 
void __vector_3 (void) __attribute__((signal));		//for interrupt 2 logic 
#endif