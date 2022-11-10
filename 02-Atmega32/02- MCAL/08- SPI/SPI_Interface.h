#ifndef	SPI_INTERFACE_H
#define	SPI_INTERFACE_H



/* Initialize pins  */
/* PB4: Slave Select        MASTER-> User defined  ,  Slave-> Input
 * PB5: MOSI                MASTER-> User defined  ,  Slave-> User defined
 * PB6: MISO                MASTER-> Input         ,  Slave-> Input
 * PB7: SCK                 MASTER-> User defined  ,  Slave-> Input
*/
void H_SPI_voidMasterInit(void);
void H_SPI_voidSlaveInit(void);

void H_SPI_voidTransmit(uint_8 copy_Data);
uint_8 H_SPI_u8Receive(void);

void H_SPI_voidInterruptISR( void (*ptr_ISR)(void) );
#endif /* SPI_INTERFACE_H */