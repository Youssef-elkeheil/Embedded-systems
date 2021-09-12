#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "util/delay.h"

#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"

typedef unsigned short int u32;

void HKEYPAD_voidInitialize (void)
{
	/* for pull up */
	MDIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_R1, INPUT);
	MDIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_R2, INPUT);
	MDIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_R3, INPUT);
	MDIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_R4, INPUT);

	/* to be disabled */
	MDIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_C1, OUTPUT);
	MDIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_C2, OUTPUT);
	MDIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_C3, OUTPUT);
	MDIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_C4, OUTPUT);

	MDIO_voidSetPortValue(KEYPAD_PORT, HIGH);
}

u8   HKEYPAD_u8GetPressedKey (void)
{
	u8 flag = 0;
	u8 Local_u8PressedKey=0;
	u8 row, column;
	u8 Local_u8KeypadKeys[4][4] = {
			{'1', '2', '3' , '+'},
			{'4', '5', '6', '-'},
			{'7', '8', '9', '/'},
			{'*', '0', '#', '='}
	};
	while(1)
	{
		for(column=4; column<8; column++)
		{
			MDIO_voidSetPinValue(KEYPAD_PORT, column, LOW);
			for(row=0; row<4; row++)
			{
				if(MDIO_u8GetPinValue(KEYPAD_PORT, row) == 0)
				{
					Local_u8PressedKey = Local_u8KeypadKeys[row][column-4];
					while(MDIO_u8GetPinValue(KEYPAD_PORT, row) == 0);
					_delay_ms(30);
					flag = 1;
					break;
				}
			}
			if(flag == 1)
			{
				break;
			}
			MDIO_voidSetPinValue(KEYPAD_PORT, column, HIGH);
		}
		if(flag == 1)
		{
			break;
		}
	}
	return Local_u8PressedKey;
}
