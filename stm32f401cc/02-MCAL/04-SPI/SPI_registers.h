#ifndef SPI_REGISTERS_H
#define SPI_REGISTERS_H

/* SPI1 BIT 12*/
#define RCC_APB2ENR         ((unsigned int *)0x40023844)
#define SPI1_BASE_ADDRESS   0x40013000

#define SPI1_CR1            *((unsigned int *)SPI1_BASE_ADDRESS + 0X00)
#define SPI1_SR             *((unsigned int *)SPI1_BASE_ADDRESS + 0X08)
#define SPI1_DR             *((unsigned int *)SPI1_BASE_ADDRESS + 0X0C)
#define SPI1_CRCPR          *((unsigned int *)SPI1_BASE_ADDRESS + 0X10)
#define SPI1_RXCRCR         *((unsigned int *)SPI1_BASE_ADDRESS + 0X14)
#define SPI1_TXCRCR         *((unsigned int *)SPI1_BASE_ADDRESS + 0X18)

#endif