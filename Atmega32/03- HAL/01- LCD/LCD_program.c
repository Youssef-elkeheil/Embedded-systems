#include "../../01- LIB/STD_TYPES.h"
#include "../../01- LIB/BIT_MATH.h"

#include "../../02- MCAL/01- DIO/DIO_interface.h"
#include "util/delay.h"

#include "LCD_interface.h"

void HLCD_voidInitialize(void)
{
	// set used pins to output
	MDIO_voidSetPinDirection(LCD_RS, OUTPUT);
	MDIO_voidSetPinDirection(LCD_RW, OUTPUT);
	MDIO_voidSetPinDirection(LCD_EN, OUTPUT);
	MDIO_voidSetPinDirection(LCD_DB4, OUTPUT);
	MDIO_voidSetPinDirection(LCD_DB5, OUTPUT);
	MDIO_voidSetPinDirection(LCD_DB6, OUTPUT);
	MDIO_voidSetPinDirection(LCD_DB7, OUTPUT);

	_delay_ms(40); /* LCD Power ON delay always >30ms */

	HLCD_voidSendCommand(FUN_SET_4BITS_MODE); /* Send for 4 bit initialization of LCD  */
	HLCD_voidSendCommand(FUN_SET);			 /* 2 line, 5*7 matrix in 4-bit mode */

	_delay_ms(1);
	HLCD_voidSendCommand(LCD_DISPLAY_MODE);
	HLCD_voidSendCommand(LCD_DISPLAY_ON);   /* Display on cursor off */
	_delay_ms(1);
	
	HLCD_voidSendCommand(LCD_DISPLAY_MODE);
	HLCD_voidSendCommand(LCD_CLEAR); /* Clear display screen */

	_delay_ms(1);
	HLCD_voidSendCommand(LCD_DISPLAY_MODE);
	HLCD_voidSendCommand(LCD_ENTRY_MODE); /* Increment cursor (shift cursor to right) */
}

void HLCD_voidSendCommand(u8 copy_u8Command)
{

	/* RS = 0 */
	MDIO_voidSetPinValue(LCD_RS, LOW);
	/* RW = 0 */
	MDIO_voidSetPinValue(LCD_RW, LOW);
	/* EN = 1 */
	MDIO_voidSetPinValue(LCD_EN, HIGH);

	MDIO_voidSetPinValue(LCD_DB4, GET_BIT(copy_u8Command, 0));
	MDIO_voidSetPinValue(LCD_DB5, GET_BIT(copy_u8Command, 1));
	MDIO_voidSetPinValue(LCD_DB6, GET_BIT(copy_u8Command, 2));
	MDIO_voidSetPinValue(LCD_DB7, GET_BIT(copy_u8Command, 3));

	/* EN = 0 */
	MDIO_voidSetPinValue(LCD_EN, LOW);
	_delay_ms(1);
	MDIO_voidSetPinValue(LCD_EN, HIGH);
	_delay_ms(2);
}

void HLCD_voidSendChar(u8 copy_u8_Data)
{
	/* Set RS to HIGH */
	MDIO_voidSetPinValue(LCD_RS, HIGH);

	/* Set R/W to LOW */
	MDIO_voidSetPinValue(LCD_RW, LOW);

	/* Set E to HIGH */
	MDIO_voidSetPinValue(LCD_EN, HIGH);

	/* Load Command on Data bus */
	MDIO_voidSetPinValue(LCD_DB4, GET_BIT(copy_u8Command, 0));
	MDIO_voidSetPinValue(LCD_DB5, GET_BIT(copy_u8Command, 1));
	MDIO_voidSetPinValue(LCD_DB6, GET_BIT(copy_u8Command, 2));
	MDIO_voidSetPinValue(LCD_DB7, GET_BIT(copy_u8Command, 3));

	/* Set E to LOW */
	MDIO_voidSetPinValue(LCD_EN, LOW);

	/* Wait for E to settle */
	_delay_ms(1);

	/* Set E to HIGH */
	MDIO_voidSetPinValue(LCD_EN, HIGH);

	/* Delay to let the LCD Display the character */
	_delay_ms(2);
}

void HLCD_voidSendString(u8 *ptr_u8_String)
{
	/* Local loop index */
	u8 u8Index = 0;
	while (ptr_u8_String[u8Index] != '\0')
	{
		/* Write Character on LCD */
		HLCD_voidSendChar(ptr_u8_String[u8Index]);

		/* Increment local loop index */
		u8Index++;

		/* Delay to let the LCD show the character */
		_delay_ms(2);
	}
}

void HLCD_voidClearScreen()
{
	HLCD_voidSendCommand(LCD_CLEAR);
}

void HLCD_voidGotoRawCol(u8 copy_u8_RawID, u8 copy_u8_ColID)
{
	u8 local_u8_Address;
	switch (copy_u8_RawID)
	{
	case 0:
		local_u8_Address = copy_u8_ColID;
		break;
	case 1:
		local_u8_Address = copy_u8_ColID + 0x40;
		break;
	case 2:
		local_u8_Address = copy_u8_ColID + 0x10;
		break;
	case 3:
		local_u8_Address = copy_u8_ColID + 0x50;
		break;
	}
	HLCD_voidSendCommand(local_u8_Address | LCD_CURSOR_OFFSET);
}

void HLCD_voidDisplayNumber(u8 copy_u8_Number)
{
	s8 *localPtr_str[16] = {0};
	itoa(copy_u8_Number, (s8 *)localPtr_str, 10);
	HLCD_voidSendString((u8 *)localPtr_str);
}