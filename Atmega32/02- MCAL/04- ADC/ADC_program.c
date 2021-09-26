#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_register.h"
#include "ADC_config.h"

void MADC_voidInit(void)
{
    ADMUX_REG  |= REFERENCE_SELECTION ;     //select reference voltage
    ADMUX_REG  |= DATA_ADJUSTMENT_MODE;     //choose left adjusted or right adjusted
    ADCSRA_REG |= ADC_PRESCALER_VALUE ;     //Select prescaler value
    SET_BIT(ADCSRA_REG, ADEN);              //ENABLE ADC
}

u8 MADC_u8GetChannelValue(u8 copy_Channel_ID)
{
    /* Select the specified Channel */
    ADMUX_REG &= CHANNEL_MASK | copy_Channel_ID ;
    /* Start the Conversion */
    SET_BIT(ADCSRA_REG, ADSC);
    /* Busy-Wait Polling till conversion complete */
    while ((GET_BIT(ADCSRA_REG, ADIF)) != 1);
    /* Clear the ADC complete conversion flag */
    SET_BIT(ADCSRA_REG, ADIF);
    
    return ADC_DATA_REG;
}
