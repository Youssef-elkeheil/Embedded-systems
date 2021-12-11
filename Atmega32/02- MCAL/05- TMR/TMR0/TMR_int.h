#ifndef _TMR0_INT_H
#define _TMR0_INT_H

void M_TMR0_void_Init(void);

void M_TMR0_void_MeasureTimeAsync(void (* ptr_TMR0SetCallBack)(void));

#endif /* _TMR0_INT_H */