#include "_7Segment.h"
#include "GPIO_interface.h"

void HAL_7_Segment_Init(char port, char start)
{
    for (int i = 0; i < 7; i++)
        MCAL_GPIO_Init(port, i+start, OUTPUT, PUSH_PULL);
}
void HAL_7_Segment_Display(char port , char start,int num)
{

    char LOCAL_display[10] = {0x3F,0x30,0x6D,0x79,0x72,0x5B,0x5F,0x31,0x7F,0x7B};
    for (int i = 0; i < 7; i++)
    {
    	MCAL_GPIO_WritePin(port, i, (LOCAL_display[num] >> (i - start)) & 1);
    }
}
void HAL_7_Segment_TurnOff(char port, char start)
{
	for (int i = 0; i < 7; i++)
	    {
	    	MCAL_GPIO_WritePin(port, i, 0);
	    }
}
