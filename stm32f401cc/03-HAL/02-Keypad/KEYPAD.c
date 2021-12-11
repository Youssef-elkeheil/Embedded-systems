#include "GPIO.h"
#include "_7Segment.h"
#include"KEYPAD.h"


char PressedKey = KEYPAD_NOTPRESSED ;
char KeypadState = KEYPAD_NOTPRESSED ;
char buttons[END_ROW - START_ROW+1][END_COL-START_COL+1] = {{1,2,3},
                                                            {4,5,6},
                                                            {7,8,9},
                                                            {'*',0,'#'}
                                                            };
void HAL_KEYPAD_Init(void)
{
    char row ,col;
    for(row=START_ROW;row<=END_ROW;row++)
    {
    	MCAL_GPIO_Init(KEYPAD_ROW_PORT,row,INPUT,PULL_UP);
    }
    for (col = START_COL; col <= END_COL; col++)
    {
    	MCAL_GPIO_Init(KEYPAD_COL_PORT, col, OUTPUT, PUSH_PULL);
    	MCAL_GPIO_WritePin(KEYPAD_COL_PORT,col,HIGH);
    }

}
void HAL_KEYPAD_Manage(void)
{
	int row, col;
	if(KeypadState == KEYPAD_NOTPRESSED)
	{
		for (col = START_COL; col <= END_COL; col++)
		{
			MCAL_GPIO_WritePin(KEYPAD_COL_PORT, col, LOW);
			for (row = START_ROW; row <= END_ROW; row++)
			{
			  if(MCAL_GPIO_ReadPin(KEYPAD_ROW_PORT, row)==0)
			  {
				  delay_ms(30);
				  if(MCAL_GPIO_ReadPin(KEYPAD_ROW_PORT, row)==0)
				  {
					  KeypadState = KEYPAD_PRESSED;
					  PressedKey = buttons[END_ROW-row][col-START_COL];
					  HAL_KEYPAD_Callouts_KeyPressNotificaton();
				  }
			  }
			}
			MCAL_GPIO_WritePin(KEYPAD_COL_PORT, col, HIGH);
		}
	}

}

char HAL_KEYPAD_GetKey(void)
{
	KeypadState = KEYPAD_NOTPRESSED;
	return PressedKey;
}


