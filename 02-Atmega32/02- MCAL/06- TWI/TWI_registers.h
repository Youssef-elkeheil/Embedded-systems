#ifndef TWI_REGISTERS_H
#define TWI_REGISTERS_H

#define TWCR  *((volatile uint_8 *)0x56)
#define TWINT   7
#define TWEA    6 
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
#define TWIE    0

#define TWDR  *((volatile uint_8 *)0x23)

#define TWAR  *((volatile uint_8 *)0x23)
#define TWA6    7
#define TWA5    6  
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE   0

#define TWSR  *((volatile uint_8 *)0x23)

#define TWBR  *((volatile uint_8 *)0x23)

#endif