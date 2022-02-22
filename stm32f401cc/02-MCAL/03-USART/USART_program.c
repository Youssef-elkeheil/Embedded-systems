#include "GPIO_interface.h"
#include"USART_interface.h"
#include"USART_registers.h"

#include<stdio.h>

#define Rx_MASK 0b01
#define Tx_MASK 0b10

void MCAL_USART2_Init(char port,char pin_no,char mode,int baud_rate)
{
    // Initialize the pin as alternate function 
    MCAL_GPIO_Init(port, pin_no, ALTERNATE, AF7);

    // enable clk on UART2
    USART2_CLOCK |= 1 << 17;

    // oversampling by 16
    USART2_CR1 &= ~(1 << 15);

    // baudrate define
    USART2_BRR = baud_rate;

    // enable USART2
    USART2_CR1 |= 1 << 13;

    // define word size (8-bytes)
    USART2_CR1 &= ~(1 << 12);

    // enable transmit direction
    USART2_CR1 |= mode << 2;
}

void MCAL_USART2_SendString(char* String)
{
    while(*String != 0)
    {
        USART2_DR = *String;
        while((USART2_SR>>6)&1 == 0);
        String++;
    }
}

void MCAL_USART2_SendNum(float num)
{
    char *String;
    if(num == (int)num)
        sprintf(String, "%d", (int)num);
    else
        sprintf(String, "%0.4f", num);

    while (*String != 0)
    {
        USART2_DR = *String;
        while (((USART2_SR >> 6) & 1) == 0) ;
        String++;
    }
}