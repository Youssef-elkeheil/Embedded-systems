#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

void HKEYPAD_voidInitialize (void);
void HKEYPAD_voidManage(void (*ptr_CallBackHandler)(void));
u8 HKEYPAD_u8GetPressedKey(void);

#endif