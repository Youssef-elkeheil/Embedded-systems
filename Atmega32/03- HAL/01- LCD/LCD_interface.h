#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include "LCD_config.h"

void HLCD_voidInitialize (void);
void HLCD_voidSendCommand (u8 copy_u8Command);
void HLCD_voidSendData (u8 copy_u8Data);
void HLCD_voidSendString(u8 *ptr_u8Data);


#endif