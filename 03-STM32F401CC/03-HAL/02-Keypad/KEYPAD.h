#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

#define KEYPAD_ROW_PORT                 PORTB
#define START_ROW                       0
#define END_ROW                         3

#define KEYPAD_COL_PORT                 PORTB
#define START_COL                       5
#define END_COL                         7


void HAL_KEYPAD_Init(void);	// called by the user to initialize the pins used by keypad
char HAL_KEYPAD_GetKey(void);// called by the user while writing the call out function
void HAL_KEYPAD_Manage(void);//called in the infinite loop
void HAL_KEYPAD_Callouts_KeyPressNotificaton(void);// definition is written by the user in the main.c file

#define KEYPAD_NOTPRESSED               0
#define KEYPAD_PRESSED           	    120

#endif
