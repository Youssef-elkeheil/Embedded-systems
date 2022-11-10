#include <stdio.h>

typedef struct 
{
    int* i;
    // unsigned char portID;
    // unsigned char pinID ;
    // void (*position)(void);
}Servo;


int main()  
{  
    printf("Size of int pointer = %d bytes.\n", sizeof(int*));  
    printf("Size of char pointer = %d bytes.\n", sizeof(char*));  
    printf("Size of float pointer = %d bytes.\n", sizeof(float*));  
    printf("Size of double pointer = %d bytes.\n", sizeof(double*));  
    printf("Size of long int pointer = %d bytes.\n", sizeof(long*));  
    printf("Size of short int pointer = %d bytes.\n", sizeof(short*));  
  
    return 0;  
}  