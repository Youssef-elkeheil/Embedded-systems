#include "SPI_registers.h"
#include "SPI_interface.h"
#include "01-GPIO/GPIO_interface.h"

void SPI1_Init(char port, char, char pin_no, char baudrate, char polarity, char phase)
{
    MCAL_GPIO_Init(port,pin_no,ALTERNATE,PUSH_PULL);
    MCAL_GPIO_Init(port, pin_no, ALTERNATE, AF5);

    SPI1_CR1|= (phase<<0)|(polarity<<1)|(1<<2);
}