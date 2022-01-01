#include "../01-GPIO/GPIO_interface.h"

#include "EXTI_interface.h"
#include "EXTI_registers.h"
#include "EXTI_private.h"

void (*GLOBAL_ISR_Excution[4])(void) = {(void *)0x00};

void MCAL_EXTI0_3_Init(char Port, int EXTx, char state, void (*Local_ISR_Logic)(void))
{
    GLOBAL_ISR_Excution[EXTx] = Local_ISR_Logic;
    RCC_APB2RSTR |=1<<14;
    SYSCFG_EXTICR(1) |= Port<<(4*EXTx);
    EXTI_IMR |=(1<<EXTx);
    EXTI_RTSR |= ((RISING_MASK(state)) << EXTx);
    EXTI_FTSR |= ((FALLING_MASK(state)) << EXTx);
    NVIC_ISER(0)|=1<<(6+EXTx);
    
}

void MCAL_EXTI_Enable(char EXTx)
{
    EXTI_IMR |= (1 << EXTx);
}

void MCAL_EXTI_Disable(char EXTx)
{
    EXTI_IMR &= ~(1 << EXTx);
}

void EXTI0_IRQHandler(void)
{
    EXTI_PR=(1<<0);
    GLOBAL_ISR_Excution[0]();
}

void EXTI1_IRQHandler(void)
{
    EXTI_PR = (1 << 1);
    GLOBAL_ISR_Excution[1]();
}

void EXTI2_IRQHandler(void)
{
    EXTI_PR = (1 << 2);
    GLOBAL_ISR_Excution[2]();
}

void EXTI3_IRQHandler(void)
{
    EXTI_PR = (1 << 3);
    GLOBAL_ISR_Excution[3]();
}