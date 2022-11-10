#ifndef	SPI_PRIVATE_H
#define	SPI_PRIVATE_H

/* SPI pins in PORTB */
#define DD_SS           PIN4
#define DD_MOSI         PIN5
#define DD_MISO         PIN6
#define DD_SCK          PIN7

/* SPI_DATA_ORDER */
#define  LSB_FIRST      0
#define  MSB_FIRST      1

/* SPI_POLARITY */
#define IDLE_LOW        0
#define IDLE_HIGH       1

/* SPI_DATA_SAMPLE */
#define SAMPLE_ON_LEADING   0
#define SAMPLE_ON_TRAILING  1

/* SPI_CLOCK_RATE */
#define F_OSC_4             0
#define F_OSC_16            1
#define F_OSC_64            2
#define F_OSC_128           3
#define F_OSC_2             4
#define F_OSC_8             5
#define F_OSC_32            6


#endif /* SPI_PRIVATE_H */