#include "GPIO_interface.h"
#include"GPIO_registers.h"
#define PUPD_MASK   0x03
#define OTYPE_MASK  0x01

void MCAL_GPIO_Init(int Port, char pin_no, char Direction, char state)
{
    Port -= 'A'; //   User enters 'A' or 'B' --> *LookUp[0][reg] or * LookUp[1][reg]

    *LookUp[Port][CLOCK]|= 1<<Port; // Enable Clock
    
    *LookUp[Port][MODER] &= ~(0X03 << (2 * pin_no));    
    *LookUp[Port][MODER] |= (Direction << (2 * pin_no));

    switch (Direction)
    {
    case INPUT:// if Pin is Input state will 
        *LookUp[Port][PUPDR] &= ~(0X03 << (2 * pin_no));
        *LookUp[Port][PUPDR] |= ((state & PUPD_MASK) << (2 * pin_no));
    break;
    case OUTPUT:
        *LookUp[Port][OTYPER]&=~(0x01 << pin_no);
        *LookUp[Port][OTYPER]|= ((state & OTYPE_MASK)<< pin_no);
    break;
    default:
        break;
    }
}

void MCAL_GPIO_WritePin(int Port, char pin_no, char Data)
{
    Port -= 'A';
    if (Data)
    {
        *LookUp[Port][ODR] |= (0x01<<pin_no);
    }
    else
    {
        *LookUp[Port][ODR] &= ~(0x01 << pin_no);
    }
}


unsigned char MCAL_GPIO_ReadPin(int Port, char pin_no)
{
    Port-='A';
    return (*LookUp[Port][IDR] >> (pin_no)) & 0X01;
}


void delay_ms(int ms)
{
	for(int i=0;i<ms*1000;i++);
}
