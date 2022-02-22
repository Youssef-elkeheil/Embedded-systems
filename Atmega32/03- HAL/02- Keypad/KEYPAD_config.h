#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

#define KEYPAD_ROW_PORT     PORTD
#define START_ROW           PIN4
#define END_ROW             PIN7

#define KEYPAD_COL_PORT     PORTD
#define START_COL           PIN3
#define END_COL             PIN0

u8 Global_u8KeypadKeys[4][4] = {
    {'1', '2', '3', '+'},
    {'4', '5', '6', '-'},
    {'7', '8', '9', '/'},
    {'*', '0', '#', '='}};

#endif