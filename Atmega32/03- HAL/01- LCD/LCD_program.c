#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "util/delay.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

void HLCD_voidSendCommand (u8 copy_u8Command)
{
	/* write the command on DDRAM */
	MDIO_voidSetPortValue(LCD_DATA_PORT, copy_u8Command);
	
	/* RS and RW = 0 */
	MDIO_voidSetPinValue(LCD_COMMAND_PORT, LCD_RS, LOW);
	MDIO_voidSetPinValue(LCD_COMMAND_PORT, LCD_RW, LOW);
	
	/* Enable pulse */
	MDIO_voidSetPinValue(LCD_COMMAND_PORT, LCD_EN, HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(LCD_COMMAND_PORT, LCD_EN, LOW);
}


void HLCD_voidSendData (u8 copy_u8Data)
{
	/* write the command on DDRAM */
	MDIO_voidSetPortValue(LCD_DATA_PORT, copy_u8Data);
	
	/* RS and RW = 0 */
	MDIO_voidSetPinValue(LCD_COMMAND_PORT, LCD_RS, HIGH);
	MDIO_voidSetPinValue(LCD_COMMAND_PORT, LCD_RW, LOW);
	
	/* Enable pulse */
	MDIO_voidSetPinValue(LCD_COMMAND_PORT, LCD_EN, HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(LCD_COMMAND_PORT, LCD_EN, LOW);
}


void HLCD_voidInitialize (void)
{
	MDIO_voidSetPortDirection(LCD_DATA_PORT, OUTPUT);
	MDIO_voidSetPortDirection(LCD_COMMAND_PORT, OUTPUT);
	
	/*  optional  */
	MDIO_voidSetPinValue(LCD_COMMAND_PORT, LCD_EN, LOW);
	
	_delay_ms(100);
	HLCD_voidSendCommand(0x38);
	HLCD_voidSendCommand(0x0F);
	HLCD_voidSendCommand(0x01);
	_delay_ms(2);
	HLCD_voidSendCommand(0x06);
}


void HLCD_voidSendString(u8 *ptr_u8Data)
{
	u8 i=0;
	while(ptr_u8Data[i] != '\0')
	{
		HLCD_voidSendData(ptr_u8Data[i]);
		i++;
	}
}