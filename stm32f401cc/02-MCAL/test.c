#include<stdio.h>

void main(void)
{
   for(int i=0;i<8;i++)
   {
      printf("%d ",4*((i>>1)&1)+6*(i&3)+5);
   }
}
