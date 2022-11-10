#include "../../01- LIB/std_types.h"
#include "../../01- LIB/common_macros.h"

#include "../../02- MCAL/01- DIO/DIO_interface.h"

#include "LED_interface.h"

void H_LED_voidLEDinit(ST_LED LED_object)
{
    MDIO_voidSetPinDirection(LED_object.port_ID,LED_object.pin_ID,OUTPUT);
}

void H_LED_voidChangeState (ST_LED LED_object, EN_LEDstate newState)
{
    MDIO_voidSetPinValue(LED_object.port_ID,LED_object.pin_ID,(uint_8)newState);
}

EN_LEDstate H_LED_EnGetState (ST_LED LED_object)
{
    return MDIO_u8GetPinValue(LED_object.port_ID,LED_object.pin_ID);
}
