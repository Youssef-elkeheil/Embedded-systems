#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

/* data register */
#define SPDR    *((volatile uint_8*) 0x2F )

/* status register */
#define SPSR    *((volatile uint_8*) 0x2E )
#define SPIF    7
#define WCOL    6
#define SPI2X   0

/* control register */
/*
#define SPCR    *((volatile uint_8*) 0x2D )
#define SPIE    7
#define SPE     6
#define DORD    5
#define MSTR    4
#define CPOL    3
#define CPHA    2
#define SPR1    1
#define SPR0    0
*/

/* anther way to define register using struct */
typedef struct ST_SPCR
{
    uint_8 SPR  :2;  /* SPR0 and SPR1 */
    uint_8 CPHA :1;
    uint_8 CPOL :1;
    uint_8 MSTR :1;
    uint_8 DORD :1;
    uint_8 SPE  :1;
    uint_8 SPIE :1;
}ST_SPCR;

volatile ST_SPCR* const SPCR = ((volatile ST_SPCR*) 0x2D );




#endif /* SPI_REGISTER_H_ */