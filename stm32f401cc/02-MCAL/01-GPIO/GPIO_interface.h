#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/* Ports */
#define PORTA       0
#define PORTB       1
#define PORTC       2
#define PORTD       3
#define PORTE       4
#define PORTH       7

/* Pin Direction */
#define INPUT       0
#define OUTPUT      1
#define ALTERNATE   2
#define ANALOG      3

/* Input */
#define NO_PULL     0
#define PULL_UP     2
#define PULL_DOWN   4

/* Output */
#define PUSH_PULL   0
#define OPEN_DRAIN  1

/* Pin value */
#define LOW 0
#define HIGH 1
#define TOGGLE 2
/* function state */
#define OK 0
#define NOK 1

void MCAL_GPIO_Init(int port,char pin_no,char pin_dir, char state);
void MCAL_GPIO_WritePin(int port, char pin_no, char Data);
unsigned char MCAL_GPIO_ReadPin(int port, char pin_no);
void delay_ms(int ms);

#endif
