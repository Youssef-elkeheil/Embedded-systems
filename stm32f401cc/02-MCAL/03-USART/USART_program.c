#include "GPIO_interface.h"
#include"USART_interface.h"
#include"USART_registers.h"

#define Rx_MASK 1
#define Tx_MASK 2

#define BAUD_RATE_9600 0x683

void MCAL_USART2_Init(char port,char pin_no,char mode)
{
    USART2_CLOCK|=(1<<17);
    MCAL_GPIO_Init(port, pin_no,ALTERNATE,AF7);
    USART2_CR1 |= ((mode & Rx_MASK) << 2) | ((mode & Tx_MASK) << 2) | (1 << 13);
    USART2_BRR |= BAUD_RATE_9600;
    USART2_CR2&=~(1<<12);
    
}
void MCAL_USART2_Send( char* String)
{
    while(*String != 0)
    {
        USART2_DR|= *String;
        while((USART2_SR>>6)&1 == 0);
    }
}