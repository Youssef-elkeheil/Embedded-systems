#ifndef EXTI_REGISTERS_H_
#define EXTI_REGISTERS_H_

#define RCC_APB2RSTR       *((volatile unsigned int *)(0x40023800 + 0x44))
#define SYSCFG_EXTICR(X)   *((volatile unsigned int *)(0x40013804 + 0X04 * (X)))

#define NVIC_ISER(X)       *((volatile unsigned int *)(0xE000E100 + 0x04 * (X)))
#define NVIC_ICER(X)       *((volatile unsigned int *)(0xE000E180 + 0x04 * (X)))
#define NVIC_ISPR(X)       *((volatile unsigned int *)(0xE000E200 + 0x04 * (X)))
#define NVIC_ICPR(X)       *((volatile unsigned int *)(0xE000E200 + 0x04 * (X)))
#define NVIC_IABR(X)       *((volatile unsigned int *)(0xE000E300 + 0x04 * (X)))
#define NVIC_IPR(X)        *((volatile unsigned int *)(0xE000E400 + 0x04 * (X)))

#define EXTI_IMR           *((volatile unsigned int *)(0x40013C00 + 0x00))
#define EXTI_EMR           *((volatile unsigned int *)(0x40013C00 + 0x04))
#define EXTI_RTSR          *((volatile unsigned int *)(0x40013C00 + 0x08))
#define EXTI_FTSR          *((volatile unsigned int *)(0x40013C00 + 0x0C))
#define EXTI_SWIER         *((volatile unsigned int *)(0x40013C00 + 0x10))
#define EXTI_PR            *((volatile unsigned int *)(0x40013C00 + 0x14))


#endif