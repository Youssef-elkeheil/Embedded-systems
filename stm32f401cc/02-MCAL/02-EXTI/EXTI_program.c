#include "EXTI_interface.h"
#include "EXTI_registers.h"
#include "EXTI_private.h"
#include "../01-GPIO/GPIO_interface.h"

void (*GLOBAL_ISR0_FunctionExcution)(void) = (void *)0x00;
void (*GLOBAL_ISR1_FunctionExcution)(void) = (void *)0x00;
void (*GLOBAL_ISR2_FunctionExcution)(void) = (void *)0x00;
void (*GLOBAL_ISR3_FunctionExcution)(void) = (void *)0x00;

/* for EXTI 0 -> 3*/
void MCAL_EXTI0_3_Init(int Port, char EXTx, char state, void (*Local_ISR_FunctionLogic)(void))
{
    switch (EXTx)
    {
    case 0:
        GLOBAL_ISR0_FunctionExcution = Local_ISR_FunctionLogic;
        break;
    case 1:
        GLOBAL_ISR1_FunctionExcution = Local_ISR_FunctionLogic;
        break;
    case 2:
        GLOBAL_ISR2_FunctionExcution = Local_ISR_FunctionLogic;
        break;
    case 3:
        GLOBAL_ISR3_FunctionExcution = Local_ISR_FunctionLogic;
        break;
    default:
        return;
        break;
    }
    RCC_APB2RSTR |=1<<14;
    SYSCFG_EXTICR(1) |= Port<<(4*EXTx);
    EXTI_IMR |=(1<<EXTx);
    EXTI_RTSR |= ((RISING(state))<< EXTx);
    EXTI_FTSR |= ((FALLING(state))<<EXTx);
    NVIC_ISER(EXTx)|=1<<(6+EXTx);
}

void EXTI0_IRQHandler(void)
{
    EXTI_PR=(1<<0);
    GLOBAL_ISR0_FunctionExcution();
}

void EXTI1_IRQHandler(void)
{
    EXTI_PR = (1 << 1);
    GLOBAL_ISR1_FunctionExcution();
}

void EXTI2_IRQHandler(void)
{
    EXTI_PR = (1 << 2);
    GLOBAL_ISR2_FunctionExcution();
}

void EXTI3_IRQHandler(void)
{
    EXTI_PR = (1 << 3);
    GLOBAL_ISR3_FunctionExcution();
}