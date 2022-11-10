#ifndef USART_REGISTERS_H_
#define USART_REGISTERS_H_

// RCC_APB1ENR -> USART2 Clock Pin 17
#define USART2_CLOCK    (*(unsigned int *)(0x40023800 + 0x40))
// RCC_APB2ENR -> USART(1/6) Clock Pin (4/5)
#define USART_1_6_CLOCK (*(unsigned int *)(0x40023800 + 0x44))

#define USART1_REG 0x40011000
#define USART2_REG 0x40004400
#define USART6_REG 0x40011400

#define USART1_SR   (*(unsigned int *)(USART1_REG + 0x00))
#define USART1_DR   (*(unsigned int *)(USART1_REG + 0x04))
#define USART1_BRR  (*(unsigned int *)(USART1_REG + 0x08))
#define USART1_CR1  (*(unsigned int *)(USART1_REG + 0x0C))
#define USART1_CR2  (*(unsigned int *)(USART1_REG + 0x10))
#define USART1_CR3  (*(unsigned int *)(USART1_REG + 0x14))
#define USART1_GTPR (*(unsigned int *)(USART1_REG + 0x18))

#define USART2_SR   (*(unsigned int *)(USART2_REG + 0x00))
#define USART2_DR   (*(unsigned int *)(USART2_REG + 0x04))
#define USART2_BRR  (*(unsigned int *)(USART2_REG + 0x08))
#define USART2_CR1  (*(unsigned int *)(USART2_REG + 0x0C))
#define USART2_CR2  (*(unsigned int *)(USART2_REG + 0x10))
#define USART2_CR3  (*(unsigned int *)(USART2_REG + 0x14))
#define USART2_GTPR (*(unsigned int *)(USART2_REG + 0x18))

#define USART6_SR   (*(unsigned int *)(USART6_REG + 0x00))
#define USART6_DR   (*(unsigned int *)(USART6_REG + 0x04))
#define USART6_BRR  (*(unsigned int *)(USART6_REG + 0x08))
#define USART6_CR1  (*(unsigned int *)(USART6_REG + 0x0C))
#define USART6_CR2  (*(unsigned int *)(USART6_REG + 0x10))
#define USART6_CR3  (*(unsigned int *)(USART6_REG + 0x14))
#define USART6_GTPR (*(unsigned int *)(USART6_REG + 0x18))

#endif