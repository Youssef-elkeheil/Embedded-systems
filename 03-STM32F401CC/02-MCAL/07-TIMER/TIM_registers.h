#ifndef TIM_REGISTERS_H
#define TIM_REGISTERS_H

// clock register
#define TIM2_CLOCK *((volatile unsigned int *)0x40023840)
// timer enable bit
#define TIM2EN 0

// timer 2 register
#define TIM2_REG(OFFSET) *((volatile unsigned int *)(0x40000000 + (OFFSET)))

#define TIM2_CR1    0x00

#define TIM2_DIER   0x0C
#define TIM2_SR     0x10

#define TIM2_CNT    0x24
#define TIM2_PSC    0x28
#define TIM2_ARR    0x2C

#define NVIC_ISER0 *((volatile unsigned int *)0xE000E100)

#endif
