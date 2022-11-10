#ifndef TIM_INTERFACE_H
#define TIM_INTERFACE_H

// counter modes:
#define UPCOUNTING              0x00
#define DPWNCOUNTING            0x10
#define CENTER_UP               0x20
#define CENTER_DOWN             0x40
#define CENTER_UP_DOWN          0x60

void MCAL_TIM2_Init(unsigned char counter_mode, unsigned int prescaler, void (*TIM2_ISR)(void) );
void MCAL_TIM2_Start();
void MCAL_TIM2_Stop();

#endif