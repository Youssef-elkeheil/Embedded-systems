#include "TIM_registers.h"
#include "TIM_interface.h"
#include "TIM_config.h"
#include "TIM_private.h"

void (*Global_TIM2_isr)(void);

void MCAL_TIM2_Init(unsigned char counter_mode, unsigned int prescaler, void (*TIM2_isr)(void))
{
    //enable timer 2 clock
    TIM2_CLOCK |= (1<<TIM2EN);

    TIM2_REG(TIM2_CR1) |= (counter_mode | CMS_MASK);
    TIM2_REG(TIM2_CR1) |= (counter_mode | DIR_MASK);

    TIM2_REG(TIM2_PSC) = prescaler;
    
    Global_TIM2_isr = TIM2_isr;
    TIM2_REG(TIM2_DIER) |= UIE;
    NVIC_ISER0 = NVIC_ISER_TIM2_BIT;
}

void MCAL_TIM2_Start(unsigned int counts)
{

    TIM2_REG(TIM2_CNT) = counts;
    TIM2_REG(TIM2_CR1) |= CEN;
}

void MCAL_TIM2_Stop()
{
    TIM2_REG(TIM2_DIER) &= ~UIE;
}

void TIM2_IRQHandler(void)
{
    TIM2_REG(TIM2_SR) &= ~UIF;
    Global_TIM2_isr();
    
}