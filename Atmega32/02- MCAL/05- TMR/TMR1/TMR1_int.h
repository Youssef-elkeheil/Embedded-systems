#ifndef _TMR1_INT_H
#define _TMR1_INT_H

#define M_TMR1_TRIGGERING_MODE_FALLING    0
#define M_TMR1_TRIGGERING_MODE_RISING     1

void M_TMR1_void_Init(void);

void M_TMR1_void_SetDuty(u8 copy_u8_DutyCycle);

/* ICU */
void M_TMR1_void_SetIcuCallBack(void (* ptr_FunSetCallBack)(void));

void M_TMR1_void_SetTriggeringEdge(u8 copy_EdgeID);

void M_TMR1_void_ClearTimerValue(void);

void M_TMR1_void_GetIcuValue(u16 * ptr_u16_IcuValue);

#endif /* _TMR1_INT_H */
