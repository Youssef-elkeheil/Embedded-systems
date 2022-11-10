#ifndef	EXTI_INTERFACE_H
#define	EXTI_INTERFACE_H

/* Initialization Functions  */
/* pins are intialized as input pull up*/

/*PortD Pin2*/
void EXTI_voidInt0Init(void (* ptr_Isr0FunLogic)(void));
/*PortD Pin3*/
void EXTI_voidInt1Init(void (* ptr_Isr1FunLogic)(void));
/*PortB Pin2*/
void EXTI_voidInt2Init(void (* ptr_Isr2FunLogic)(void));

#endif 