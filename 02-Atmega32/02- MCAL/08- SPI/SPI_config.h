#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_


/* SPI interrupt 
 * 0 : disable
 * 1 : enable
 */
#define SPI_ENABLE_INTERRUPT    0

/* define the order of data while trasnmitting:
 * LSB_FIRST
 * MSB_FIRST
 */
#define SPI_DATA_ORDER      MSB_FIRST

/*  define SCK idle state
 * IDLE_LOW
 * IDLE_HIGH
*/
#define SPI_POLARITY        IDLE_LOW

/* define data sampling edge
 * SAMPLE_ON_LEADING
 * SAMPLE_ON_TRAILING

 */
#define SPI_DATA_SAMPLE     SAMPLE_ON_LEADING

/* define SCK frequency  **** NOTE: only affective in master mode  ****
 *  F_OSC_2
 *  F_OSC_4
 *  F_OSC_8
 *  F_OSC_16
 *  F_OSC_32
 *  F_OSC_64
 *  F_OSC_128
 */
#define SPI_CLOCK_RATE  F_OSC_8

#endif /* SPI_CONFIG_H_ */