#include "../../01- LIB/std_types.h"
#include "../../01- LIB/common_macros.h"

#include "../01- DIO/DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_registers.h"

static void (*G_ptr_ISR12FunctionExcution) (void);

void H_SPI_voidMasterInit(void)
{

	/* Set MOSI and SCK output, all others input */
	MDIO_voidSetPinDirection(PORTB,DD_MOSI,OUTPUT);
	MDIO_voidSetPinDirection(PORTB,DD_SCK,OUTPUT);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR->SPR  = SPI_CLOCK_RATE & 3;
	/* get the value of SPI2X bit in SPI_CLOCK_RATE macro which is 3rd bit   */
	SPSR|= (( (SPI_CLOCK_RATE>>2)&1) <<SPI2X);

	SPCR->MSTR = 1;
	SPCR->SPIE = SPI_ENABLE_INTERRUPT &1;
	SPCR->DORD = SPI_DATA_ORDER &1;
	SPCR->CPOL = SPI_POLARITY &1;
	SPCR->CPHA = SPI_DATA_SAMPLE &1;
	/* enable SPI */
	SPCR->SPE = 1; 


} /* SPI_MasterInit */

void H_SPI_voidSlaveInit(void)
{
	/* Set MISO output, all others input */
	MDIO_voidSetPinDirection(PORTB,DD_MISO,OUTPUT);
	/* Enable SPI */
	SPCR->SPE = 1;

} /* SPI_SlaveInit */


void H_SPI_voidTransmit(uint_8 copy_Data)
{

	/* Start transmission */
	SPDR = copy_Data;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
	;

}/* SPI_Transmit */

uint_8 H_SPI_u8Receive(void)
{

	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)))
	;
	/* Return data register */
	return SPDR;

} /* SPI_Receive */

void H_SPI_voidInterruptISR( void (*ptr_ISR)(void) )
{
	G_ptr_ISR12FunctionExcution = ptr_ISR;
}

void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	G_ptr_ISR12FunctionExcution();
}