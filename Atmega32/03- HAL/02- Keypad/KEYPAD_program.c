#include "../../01- LIB/STD_TYPES.h"
#include "../../01- LIB/BIT_MATH.h"

#include "../../02- MCAL/01- DIO/DIO_interface.h"
#include "util/delay.h"

#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"

s8 KeypadState = KEYPAD_NOTPRESSED;
s8 Global_u8PressedKey = 0;

void HKEYPAD_voidInitialize(void)
{
	/* for pull up */
	for(s8 row = START_ROW; row !=(END_ROW + UPDATE_ROW) ;row+=UPDATE_ROW )
	{
		MDIO_voidSetPinDirection(KEYPAD_ROW_PORT, row, INPUT);
		MDIO_voidSetPinValue(KEYPAD_ROW_PORT, row, HIGH);
	}
	/* to be disabled */
	for (s8 col = START_COL; col != (END_COL + UPDATE_COL); col += UPDATE_COL)
	{
		MDIO_voidSetPinDirection(KEYPAD_COL_PORT, col, OUTPUT);
		MDIO_voidSetPinValue(KEYPAD_COL_PORT, col, HIGH);
		
	}
}
void HKEYPAD_voidManage(void (*local_CallOutHandler)(void))
{
	s8 row, column, row_flag, column_flag;
	if (KeypadState == KEYPAD_NOTPRESSED)
	{
		for (column = START_COL; column != (END_COL + UPDATE_COL); column += UPDATE_COL)
		{
			MDIO_voidSetPinValue(KEYPAD_COL_PORT, column, LOW);
			for (row = START_ROW; row != (END_ROW + UPDATE_ROW); row += UPDATE_ROW)
			{
				if (MDIO_u8GetPinValue(KEYPAD_ROW_PORT, row) == LOW)
				{
					_delay_ms(30);
					if (MDIO_u8GetPinValue(KEYPAD_ROW_PORT, row) == LOW)
					{
						KeypadState = KEYPAD_PRESSED;
						Global_u8PressedKey = Global_u8KeypadKeys[SELECTED_ROW][SELECTED_COL];
						local_CallOutHandler();
						row_flag = row;
						column_flag = column;
						return;
					}
				}
			}
			MDIO_voidSetPinValue(KEYPAD_COL_PORT, column, HIGH);
		}
	}
	else
	{
		if (MDIO_u8GetPinValue(KEYPAD_ROW_PORT, row_flag) == HIGH)
		{
			_delay_ms(30);

			if (MDIO_u8GetPinValue(KEYPAD_ROW_PORT, row_flag) == HIGH)
			{
				KeypadState = KEYPAD_NOTPRESSED;
				MDIO_voidSetPinValue(KEYPAD_COL_PORT, column_flag, HIGH);
			}
		}
	}
}

u8   HKEYPAD_u8GetPressedKey (void)
{
	return Global_u8PressedKey;
}
