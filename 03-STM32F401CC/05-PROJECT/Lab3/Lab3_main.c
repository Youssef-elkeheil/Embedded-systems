#include "stm32f401cc_interface.h"

#define SET_BIT(var,bit) 					var|=1<<bit
#define CLR_BIT(var,bit) 					var&=~(1<<bit)
#define ASSIGN_2_BIT(var,bit1,value) 		var&=~(3<<bit1*2); var|=(value<<bit1*2)

int lab3_main(void)
{
	SET_BIT(RCC_AHB1ENR,0);			// RCC_AHB1ENR |= 1
	ASSIGN_2_BIT(GPIOA_MODER,0,1);
	CLR_BIT(GPIOA_OTYPER,0);

	int delay = 0;
	while(1)
	{
		SET_BIT(GPIOA_ODR,0);
		for(delay = 0;delay < 1000000;delay++);
		CLR_BIT(GPIOA_ODR,0);
		for(delay = 0;delay < 1000000;delay++);
	}
}
