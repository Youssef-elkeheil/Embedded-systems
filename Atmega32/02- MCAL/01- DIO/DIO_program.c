#include "../../01- LIB/STD_TYPES.h"
#include "../../01- LIB/BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_registers.h"

void MDIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection)
{
	switch(copy_u8PortId)
	{
		case PORTA: if(copy_u8PortDirection == OUTPUT)
		            {
		                DDRA_REG = 0xFF;	
		            }
					else if(copy_u8PortDirection == INPUT)
					{
						DDRA_REG = 0x00;
					}
					else
					{
						DDRA_REG = copy_u8PortDirection;
					}
					break;
		case PORTB: if(copy_u8PortDirection == OUTPUT)
		            {
		                DDRB_REG = 0xFF;	
		            }
					else if(copy_u8PortDirection == INPUT)
					{
						DDRB_REG = 0x00;
					}
					else
					{
						DDRB_REG = copy_u8PortDirection;
					}
					break;
		case PORTC: if(copy_u8PortDirection == OUTPUT)
		            {
		                DDRC_REG = 0xFF;	
		            }
					else if(copy_u8PortDirection == INPUT)
					{
						DDRC_REG = 0x00;
					}
					else
					{
						DDRC_REG = copy_u8PortDirection;
					}
					break;
		case PORTD: if(copy_u8PortDirection == OUTPUT)
		            {
		                DDRD_REG = 0xFF;	
		            }
					else if(copy_u8PortDirection == INPUT)
					{
						DDRD_REG = 0x00;
					}
					else
					{
						DDRD_REG = copy_u8PortDirection;
					}
					break;
	}
}

void MDIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue)
{
		switch(copy_u8PortId)
	{
		case PORTA: if(copy_u8PortValue == HIGH)
		            {
		                PORTA_REG = 0xFF;	
		            }
					else if(copy_u8PortValue == LOW)
					{
						PORTA_REG = 0x00;
					}
					else
					{
						PORTA_REG = copy_u8PortValue;
					}
					break;
		case PORTB: if(copy_u8PortValue == HIGH)
		            {
		                PORTB_REG = 0xFF;	
		            }
					else if(copy_u8PortValue == LOW)
					{
						PORTB_REG = 0x00;
					}
					else
					{
						PORTB_REG = copy_u8PortValue;
					}
					break;
		case PORTC: if(copy_u8PortValue == HIGH)
		            {
		                PORTC_REG = 0xFF;	
		            }
					else if(copy_u8PortValue == LOW)
					{
						PORTC_REG = 0x00;
					}
					else
					{
						PORTC_REG = copy_u8PortValue;
					}
					break;
		case PORTD: if(copy_u8PortValue == HIGH)
		            {
		                PORTD_REG = 0xFF;	
		            }
					else if(copy_u8PortValue == LOW)
					{
						PORTD_REG = 0x00;
					}
					else
					{
						PORTD_REG = copy_u8PortValue;
					}
					break;
	}
}


void MDIO_voidSetPinDirection(u8 copy_u8PinId, u8 copy_u8PinDirection)
{
	if (copy_u8PinId >= PINA0 && copy_u8PinId <= PINA7) /* from PINA0 to PINA7  */
	{
		if (copy_u8PinDirection == OUTPUT)
		{
			SET_BIT(DDRA_REG, copy_u8PinId);
		}
		else if (copy_u8PinDirection == INPUT)
		{
			CLR_BIT(DDRA_REG, copy_u8PinId);
		}

	}
	else if (copy_u8PinId <= PINB7) /* from PINB0 to PINB7  */
	{
		copy_u8PinId -= PINB0; /* To set pins range from 0 to 7 */
		if (copy_u8PinDirection == OUTPUT)
		{
			SET_BIT(DDRB_REG, copy_u8PinId);
		}
		else if (copy_u8PinDirection == INPUT)
		{
			CLR_BIT(DDRB_REG, copy_u8PinId);
		}

	}
	else if (copy_u8PinId <= PINC7) /* from PINC0 to PINC7  */
	{
		copy_u8PinId -= PINC0; /* To set pins range from 0 to 7 */
		if (copy_u8PinDirection == OUTPUT)
		{
			SET_BIT(DDRC_REG, copy_u8PinId);
		}
		else if (copy_u8PinDirection == INPUT)
		{
			CLR_BIT(DDRC_REG, copy_u8PinId);
		}

	}
	else if (copy_u8PinId <= PIND7) /* from PIND0 to PIND7  */
	{
		copy_u8PinId -= PIND0; /* To set pins range from 0 to 7 */
		if (copy_u8PinDirection == OUTPUT)
		{
			SET_BIT(DDRD_REG, copy_u8PinId);
		}
		else if (copy_u8PinDirection == INPUT)
		{
			CLR_BIT(DDRD_REG, copy_u8PinId);
		}

	}
}

void MDIO_voidSetPinValue(u8 copy_u8PinId, u8 copy_u8PinValue)
{
	if (copy_u8PinId >= PINA0 && copy_u8PinId <= PINA7) /* from PINA0 to PINA7  */
	{
		if (copy_u8PinValue == HIGH)
		{
			SET_BIT(PORTA_REG, copy_u8PinId);
		}
		else if (copy_u8PinValue == LOW)
		{
			CLR_BIT(PORTA_REG, copy_u8PinId);
		}

	}
	else if (copy_u8PinId <= PINB7) /* from PINB0 to PINB7  */
	{
		copy_u8PinId -= PINB0; /* To set pins range from 0 to 7 */
		if (copy_u8PinValue == HIGH)
		{
			SET_BIT(PORTB_REG, copy_u8PinId);
		}
		else if (copy_u8PinValue == LOW)
		{
			CLR_BIT(PORTB_REG, copy_u8PinId);
		}

	}
	else if (copy_u8PinId <= PINC7) /* from PINC0 to PINC7  */
	{
		copy_u8PinId -= PINC0; /* To set pins range from 0 to 7 */
		if (copy_u8PinValue == HIGH)
		{
			SET_BIT(PORTC_REG, copy_u8PinId);
		}
		else if (copy_u8PinValue == LOW)
		{
			CLR_BIT(PORTC_REG, copy_u8PinId);
		}

	}
	else if (copy_u8PinId <= PIND7) /* from PIND0 to PIND7  */
	{
		copy_u8PinId -= PIND0; /* To set pins range from 0 to 7 */
		if (copy_u8PinValue == HIGH)
		{
			SET_BIT(PORTD_REG, copy_u8PinId);
		}
		else if (copy_u8PinValue == LOW)
		{
			CLR_BIT(PORTD_REG, copy_u8PinId);
		}

	}
}

void MDIO_voidTogglePinValue(u8 copy_u8PinId)
{
	if (copy_u8PinId >= PINA0 && copy_u8PinId <= PINA7) /* from PINA0 to PINA7  */
	{
		TOG_BIT(PORTA_REG, copy_u8PinId);
	}
	else if (copy_u8PinId <= PINB7) /* from PINB0 to PINB7  */
	{
		copy_u8PinId -= PINB0;
		TOG_BIT(PORTB_REG, copy_u8PinId);
	}
	else if (copy_u8PinId <= PINC7) /* from PINC0 to PINC7  */
	{
		copy_u8PinId -= PINC0;
		TOG_BIT(PORTC_REG, copy_u8PinId);
	}	
	else if (copy_u8PinId <= PIND7) /* from PIND0 to PIND7  */
	{
		copy_u8PinId -= PIND0;
		TOG_BIT(PORTD_REG, copy_u8PinId);
	}
}

u8   MDIO_u8GetPinValue(u8 copy_u8PinId)
{
	u8 Local_u8PinState;

	if (copy_u8PinId >= PINA0 && copy_u8PinId <= PINA7) /* from PINA0 to PINA7  */
	{
		Local_u8PinState = GET_BIT(PINA_REG, copy_u8PinId);
	}
	else if (copy_u8PinId <= PINB7) /* from PINB0 to PINB7  */
	{
		copy_u8PinId -= PINB0;
		Local_u8PinState = GET_BIT(PINB_REG, copy_u8PinId);
	}
	else if (copy_u8PinId <= PINC7) /* from PINC0 to PINC7  */
	{
		copy_u8PinId -= PINC0;
		Local_u8PinState = GET_BIT(PINC_REG, copy_u8PinId);
	}
	else if (copy_u8PinId <= PIND7) /* from PIND0 to PIND7  */
	{
		copy_u8PinId -= PIND0;
		Local_u8PinState = GET_BIT(PIND_REG, copy_u8PinId);
	}	
	return Local_u8PinState;
}