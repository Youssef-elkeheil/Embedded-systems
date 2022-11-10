#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"
//void display(char num);
int Lab4_main(void) {
	int i = 0,j = 0;

	for( i =0;i<7;i++)
		GPIO_Init('A', i , OUTPUT, PUSH_PULL);

	int display[10][7] = {
							{1,1,1,1,1,1,0},{0,0,0,0,1,1,0},{1,0,1,1,0,1,1},{1,0,0,1,1,1,1},
							{0,1,0,0,1,1,1},{1,1,0,1,1,0,1},{1,1,1,1,1,0,1},
							{1,0,0,0,1,1,0},{1,1,1,1,1,1,1},{1,1,0,1,1,1,1}
						  };
	while (1)
	{
	  //led on
	  for(i =0;i<10;i++)
	  {
		  for(j =0;j<7;j++)
	  {
			  GPIO_WritePin('A', j, display[i][j]);
	  }
	// for(i =0;i<10;i++)
	// {
	//	   	display(i);
	//		for (int i = 0; i < 1000000; i++);
	// }
		for (int i = 0; i < 1000000; i++);
	  }
	}
	return 0;
}
/* other method */
//void display(char num)
//{
//	switch(num)
//	{
//	case 0:
//		  GPIO_WritePin('A', 0, 1);
//		  GPIO_WritePin('A', 1, 1);
//		  GPIO_WritePin('A', 2, 1);
//		  GPIO_WritePin('A', 3, 1);
//		  GPIO_WritePin('A', 4, 1);
//		  GPIO_WritePin('A', 5, 1);
//		  GPIO_WritePin('A', 6, 0);
//		  break;
//
//	case 1:
//		  GPIO_WritePin('A', 0, 0);
//		  GPIO_WritePin('A', 1, 0);
//		  GPIO_WritePin('A', 2, 0);
//		  GPIO_WritePin('A', 3, 0);
//		  GPIO_WritePin('A', 4, 1);
//		  GPIO_WritePin('A', 5, 1);
//		  GPIO_WritePin('A', 6, 0);
//		  break;
//	case 2:
//		  GPIO_WritePin('A', 0, 1);
//		  GPIO_WritePin('A', 1, 0);
//		  GPIO_WritePin('A', 2, 1);
//		  GPIO_WritePin('A', 3, 1);
//		  GPIO_WritePin('A', 4, 0);
//		  GPIO_WritePin('A', 5, 1);
//		  GPIO_WritePin('A', 6, 1);
//		  break;
//	case 3:
//		  GPIO_WritePin('A', 0, 1);
//		  GPIO_WritePin('A', 1, 0);
//		  GPIO_WritePin('A', 2, 0);
//		  GPIO_WritePin('A', 3, 1);
//		  GPIO_WritePin('A', 4, 1);
//		  GPIO_WritePin('A', 5, 1);
//		  GPIO_WritePin('A', 6, 1);
//		  break;
//	case 4:
//		  GPIO_WritePin('A', 0, 0);
//		  GPIO_WritePin('A', 1, 1);
//		  GPIO_WritePin('A', 2, 0);
//		  GPIO_WritePin('A', 3, 0);
//		  GPIO_WritePin('A', 4, 1);
//		  GPIO_WritePin('A', 5, 1);
//		  GPIO_WritePin('A', 6, 1);
//		  break;
//	case 5:
//		  GPIO_WritePin('A', 0, 1);
//		  GPIO_WritePin('A', 1, 1);
//		  GPIO_WritePin('A', 2, 0);
//		  GPIO_WritePin('A', 3, 1);
//		  GPIO_WritePin('A', 4, 1);
//		  GPIO_WritePin('A', 5, 0);
//		  GPIO_WritePin('A', 6, 1);
//		  break;
//	case 6:
//		  GPIO_WritePin('A', 0, 1);
//		  GPIO_WritePin('A', 1, 1);
//		  GPIO_WritePin('A', 2, 1);
//		  GPIO_WritePin('A', 3, 1);
//		  GPIO_WritePin('A', 4, 1);
//		  GPIO_WritePin('A', 5, 0);
//		  GPIO_WritePin('A', 6, 1);
//		  break;
//	case 7:
//		  GPIO_WritePin('A', 0, 1);
//		  GPIO_WritePin('A', 1, 0);
//		  GPIO_WritePin('A', 2, 0);
//		  GPIO_WritePin('A', 3, 0);
//		  GPIO_WritePin('A', 4, 1);
//		  GPIO_WritePin('A', 5, 1);
//		  GPIO_WritePin('A', 6, 0);
//		  break;
//	case 8:
//		  GPIO_WritePin('A', 0, 1);
//		  GPIO_WritePin('A', 1, 1);
//		  GPIO_WritePin('A', 2, 1);
//		  GPIO_WritePin('A', 3, 1);
//		  GPIO_WritePin('A', 4, 1);
//		  GPIO_WritePin('A', 5, 1);
//		  GPIO_WritePin('A', 6, 1);
//		  break;
//	case 9:
//		  GPIO_WritePin('A', 0, 1);
//		  GPIO_WritePin('A', 1, 1);
//		  GPIO_WritePin('A', 2, 0);
//		  GPIO_WritePin('A', 3, 1);
//		  GPIO_WritePin('A', 4, 1);
//		  GPIO_WritePin('A', 5, 1);
//		  GPIO_WritePin('A', 6, 1);
//		  break;
//	}
//}
