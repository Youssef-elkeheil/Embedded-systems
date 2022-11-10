#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#define MASTER
#define SLAVE

void SPI1_Init(char port, char, char pin_no, char master_slave, char polarity, char phase);

#endif