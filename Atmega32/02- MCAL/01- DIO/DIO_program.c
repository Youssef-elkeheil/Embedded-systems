#include "../../01- LIB/STD_TYPES.h"
#include "../../01- LIB/BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_registers.h"

void MDIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection)
{
    if (copy_u8PortId<=PORTD)
    {
        DDRx_REG(copy_u8PortId) = copy_u8PortDirection;
    }    
}

void MDIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue)
{
    if (copy_u8PortId <= PORTD)
    {
        PORTx_REG(copy_u8PortId) = copy_u8PortValue;
    }
}

void MDIO_voidSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection)
{
    if (copy_u8PortId <= PORTD && copy_u8PinId <= 7)
    {
        switch (copy_u8PinDirection&1)
        {
        case (OUTPUT&1):
            SET_BIT(DDRx_REG(copy_u8PortId), copy_u8PinId);
            break;

        case (INPUT&1):
            CLR_BIT(DDRx_REG(copy_u8PortId), copy_u8PinId);
            break;
        }
    }
}

void MDIO_voidSetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue)
{
    if (copy_u8PortId <= PORTD && copy_u8PinId <= 7)
    {
        switch (copy_u8PinValue&3)
        {
        case (HIGH&3):
            SET_BIT(PORTx_REG(copy_u8PortId), copy_u8PinId);
            break;

        case (LOW&3):
            CLR_BIT(PORTx_REG(copy_u8PortId), copy_u8PinId);
            break;

        case (TOGGLE&3):
            TOG_BIT(PORTx_REG(copy_u8PortId), copy_u8PinId);
            break;
        }
    }
}

u8 MDIO_u8GetPinValue(u8 copy_u8PortId, u8 copy_u8PinId)
{
    if (copy_u8PortId <= PORTD && copy_u8PinId <= 7)
    {
        return GET_BIT(PINx_REG(copy_u8PortId), copy_u8PinId);
    }
    else
        return NOK;
}