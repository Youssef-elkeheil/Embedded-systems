#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../01- DIO/DIO_interface.h"

void MADC_voidInit(void);

u8 MADC_u8GetChannelValue(u8 copy_Channel_ID);

#endif