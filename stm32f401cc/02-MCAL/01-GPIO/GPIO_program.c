#include "GPIO_interface.h"
#include"GPIO_registers.h"

#define PUPD_MASK   0x03
#define PUPD_SHIFT  0x01
#define OTYPE_MASK  0x01

#define AFR_MASK    0x0F
#define AFR_SHIFT   0x03

void MCAL_GPIO_Init(int Port, char pin_no, char Direction, char state)
{
    *LookUp[Port][CLOCK]|= 1<<Port; // Enable Clock
    
    *LookUp[Port][MODER] &= ~(0X03 << (2 * pin_no));    
    *LookUp[Port][MODER] |= (Direction << (2 * pin_no));

    /*  case input User enters: NO_PULL (0) or PULL_UP (2) or PULL_DOWN (4)  */
    /*  state is shifted by 1 to make the value 0 ,1 & 2  (First bit is for otype)  */
    *LookUp[Port][PUPDR] &= ~(PUPD_MASK << (2 * pin_no));
    *LookUp[Port][PUPDR] |= (( (state >> PUPD_SHIFT) & PUPD_MASK) << (2 * pin_no));
    
    /*  case output User enters: PUSH_PULL(0) or OPEN_DRAIN(1)  */
    /*  state is anded by 1 to clear the pupdr value  */
    *LookUp[Port][OTYPER] &= ~(OTYPE_MASK << pin_no);
    *LookUp[Port][OTYPER]|= ((state & OTYPE_MASK)<< pin_no);
    
    /*  case alternate function User enters: AFx (x = 0..15)  */
    if(pin_no <8)
    {
        *LookUp[Port][AFRL] &= ~(AFR_MASK << 4 * pin_no);
        *LookUp[Port][AFRL] |= (((state >> AFR_SHIFT) & AFR_MASK) << (4 * pin_no));
    }
    else
    {
        *LookUp[Port][AFRH] &= ~(AFR_MASK << 4 * pin_no);
        *LookUp[Port][AFRH] |= (((state >> AFR_SHIFT) & AFR_MASK) << (4 * pin_no));
    }
}

void MCAL_GPIO_WritePin(int Port, char pin_no, char Data)
{

    switch (Data)
    {
    case TOGGLE:
        *LookUp[Port][ODR] ^= (0x01 << pin_no);
        break;
    case HIGH:
        *LookUp[Port][ODR] |= (0x01 << pin_no);
        break;
    case LOW:
        *LookUp[Port][ODR] &= ~(0x01 << pin_no);
        break;

    default:
        break;
    }
}

unsigned char MCAL_GPIO_ReadPin(int Port, char pin_no)
{

    return (*LookUp[Port][IDR] >> (pin_no)) & 0X01;
}

void delay_ms(int ms)
{
	for(int i=0;i<ms*1000;i++);
}


