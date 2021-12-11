#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
/* Ports */
#define PORTA       'A'
#define PORTB       'B'

/* Pin Direction */
#define INPUT       0
#define OUTPUT      1
#define ALTERNATE   2
#define ANALOG      3

/* Input */
#define NO_PULL     0
#define PULL_UP     1
#define PULL_DOWN   2
/* Output */
#define PUSH_PULL   0
#define OPEN_DRAIN  1

/* Pin value */
#define LOW 0
#define HIGH 1

/* function state */
#define OK 0
#define NOK 1

void MCAL_GPIO_Init(char port,char pin_no,char pin_dir, char state);
unsigned char MCAL_GPIO_WritePin(char port, unsigned int pin_no, unsigned int Data);
unsigned char MCAL_GPIO_ReadPin(char port, unsigned int pin_no);
void delay_ms(int ms);

#endif
