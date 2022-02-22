#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

void MADC_voidInit(void);

uint_16 MADC_uint_16GetChannelValue(u8 copy_Channel_ID);

/* It enables ADC ISR and it is the registeration function at the same time */
void MADC_voidReadDigital_Async(u8 copy_u8_ChannelID,
                                uint_16 *ptr_u16ReturnedResult,
                                void (*ptr_AdcIsrFuncLogic)(void));
#endif