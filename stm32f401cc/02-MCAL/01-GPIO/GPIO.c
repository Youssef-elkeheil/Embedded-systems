#include "GPIO.h"
#include "stm32f401cc_interface.h"

void MCAL_GPIO_Init(char port, char pin_no, char pin_dir, char state)
{
    switch (port)
    {
        case PORTA:
        	RCC_AHB1ENR|=1;
            switch (pin_dir)
            {
                case INPUT:
                GPIOA_MODER &= ~(0X03 << (2 * pin_no));
                    switch (state)
                    {
                    case NO_PULL:
                    GPIOA_PUPDR &= ~(0x03 << (2 * pin_no));
                        break;
                    case PULL_UP:
                        GPIOA_PUPDR |= (0X01 << (2 * pin_no));
                        break;
                    case PULL_DOWN:
                        GPIOA_PUPDR |= (0X02 << (2 * pin_no));
                        break;
                    default:
                        break;
                    }
                    break;
                case OUTPUT:
                    GPIOA_MODER |= (0X01 << (2 * pin_no));
                    switch (state)
                    {
                    case PUSH_PULL:
                        GPIOA_OTYPER &= ~(0x01 << (pin_no));
                        break;
                    case OPEN_DRAIN:
                        GPIOA_OTYPER |= (0X01 << (pin_no));
                        break;
                    default:
                        break;
                    }
                    break;
                case ALTERNATE:
                    GPIOA_MODER |= (0X02 << (2 * pin_no));
                    break;
                case ANALOG:
                    GPIOA_MODER |= (0X03 << (2 * pin_no));
                    break;
                default:
                break;
            }

        break;
        case PORTB:
        	RCC_AHB1ENR|=(1<<1);
            switch (pin_dir)
            {
            case INPUT:
                GPIOB_MODER &= ~(0X03 << (2 * pin_no));
                switch (state)
                {
                case NO_PULL:
                    GPIOB_PUPDR &= ~(0x03 << (2 * pin_no));
                    break;
                case PULL_UP:
                    GPIOB_PUPDR |= (0X01 << (2 * pin_no));
                    break;
                case PULL_DOWN:
                    GPIOB_PUPDR |= (0X02 << (2 * pin_no));
                    break;
                default:
                    break;
                }
                break;
            case OUTPUT:
                GPIOB_MODER |= (0X01 << (2 * pin_no));
                switch (state)
                {
                case PUSH_PULL:
                    GPIOB_OTYPER &= ~(0x01 << (pin_no));
                    break;
                case OPEN_DRAIN:
                    GPIOB_OTYPER |= (0X01 << (pin_no));
                    break;
                default:
                    break;
                }
                break;
            case ALTERNATE:
                GPIOB_MODER |= (0X02 << (2 * pin_no));
                break;
            case ANALOG:
                GPIOB_MODER |= (0X03 << (2 * pin_no));
                break;
            default:
                break;
            }
        break;
        default:
        break;
    }
}
unsigned char MCAL_GPIO_WritePin(char port, unsigned int pin_no, unsigned int Data)
{
    switch (port)
    {
    case PORTA:
        if((GPIOA_MODER>>(2*pin_no)&0x03) == OUTPUT)
        {
            if(Data)
            {
                GPIOA_ODR|=(1<<pin_no);
            }
            else
            {
                GPIOA_ODR &= ~(1 << pin_no);
            }
            return OK;
        }
        else
        {
            return NOK;
        }

        break;
    case PORTB:
        if ((GPIOB_MODER >> (2 * pin_no) & 0x03) == OUTPUT)
        {
            if (Data)
            {
                GPIOB_ODR |= (1 << pin_no);
            }
            else
            {
                GPIOB_ODR &= ~(1 << pin_no);
            }
            return OK;
        }
        else
        {
            return NOK;
        }
        break;

    default: return NOK;
        break;
    }
}
unsigned char MCAL_GPIO_ReadPin(char port, unsigned int pin_no)
{
    switch (port)
    {
    case PORTA: return (GPIOA_IDR >> (pin_no)) & 0X01; break;
    case PORTB: return (GPIOB_IDR >> (pin_no)) & 0X01; break;
    }
    return NOK;
}


void delay_ms(int ms)
{
	for(int i=0;i<ms*1000;i++);
}
