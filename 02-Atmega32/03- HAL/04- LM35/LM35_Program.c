#include "../../01- LIB/STD_TYPES.h"
#include "../../01- LIB/BIT_MATH.h"

#include "../../02- MCAL/04- ADC/ADC_interface.h"

void HLM35_Init(void)
{
    MADC_voidInit();

}
double HLM35_Reading(u8 copy_Analog_PinID)
{
    return (MADC_uint_16GetChannelValue(copy_Analog_PinID) * 500.0) / 1024;
}