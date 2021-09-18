#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "../../01- LIB/STD_TYPES.h"
#include "../../01- LIB/BIT_MATH.h"

/* PORT functions  */
void MDIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection);
void MDIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue);


/* PIN functions */
void MDIO_voidSetPinDirection(u8 copy_u8PinId, u8 copy_u8PinDirection);
void MDIO_voidSetPinValue(u8 copy_u8PinId, u8 copy_u8PinValue);
void MDIO_voidTogglePinValue(u8 copy_u8PinId);
u8   MDIO_u8GetPinValue(u8 copy_u8PinId);

/* user interface PORTs  */
#define PORTA       0
#define PORTB       1
#define PORTC       2
#define PORTD       3

/* user interface  directions */
#define OUTPUT      1
#define INPUT       0

/* user interface states  */
#define HIGH        1
#define LOW         0

/* user interface Pins of Port A */
#define PINA0       0
#define PINA1       1
#define PINA2       2
#define PINA3       3
#define PINA4       4
#define PINA5       5
#define PINA6       6
#define PINA7       7

/* user interface Pins of Port B */
#define PINB0       8
#define PINB1       9
#define PINB2       10
#define PINB3       11
#define PINB4       12
#define PINB5       13
#define PINB6       14
#define PINB7       15

/* user interface Pins of Port C */
#define PINC0       16
#define PINC1       17
#define PINC2       18
#define PINC3       19
#define PINC4       20
#define PINC5       21
#define PINC6       22
#define PINC7       23

/* user interface Pins of Port D */
#define PIND0       24
#define PIND1       25
#define PIND2       26
#define PIND3       27
#define PIND4       28
#define PIND5       29
#define PIND6       30
#define PIND7       31

#endif