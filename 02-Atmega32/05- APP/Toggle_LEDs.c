#include<stdio.h>
#include "../01- LIB/common_macros.h"

void main(void)
{
  float i = MAP(88,0,100,0,10);

  printf("%0.1f",i);
}
