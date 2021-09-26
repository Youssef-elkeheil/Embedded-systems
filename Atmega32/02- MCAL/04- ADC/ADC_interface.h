#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../01- DIO/DIO_interface.h"

void MADC_voidInit(void);

u8 MADC_u8GetChannelValue(u8 copy_Channel_ID);

/* It enables ADC ISR and it is the registeration function at the same time */
void MADC_voidReadDigital_Async(u8 copy_u8_ChannelID,
                                u16 *ptr_u16ReturnedResult,
                                void (*ptr_AdcIsrFuncLogic)(void));
#endif