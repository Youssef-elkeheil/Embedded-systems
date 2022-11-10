#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#define USART_Rx 1
#define USART_Tx 2

#define BAUDRATE_9600 0x683
#define BAUDRATE_11500 0x045

void MCAL_USART2_Init(char port, char pin_no, char mode, int baud_rate);
void MCAL_USART2_SendString(const char *String);
void MCAL_USART2_SendNum(float num);
#endif