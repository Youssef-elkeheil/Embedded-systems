#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#define USART_Rx 1
#define USART_Tx 2

MCAL_USART2_Init(char port, char pin_no, char mode);
void MCAL_USART2_Send(char *String);
void MCAL_USART2_Recieve(void);


#endif