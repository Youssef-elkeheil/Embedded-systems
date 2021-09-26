#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define PRESCALER_MASK          0x11111000        
#define ADC_PRESCALER_2         1
#define ADC_PRESCALER_4         2
#define ADC_PRESCALER_8         3
#define ADC_PRESCALER_16        4
#define ADC_PRESCALER_32        5
#define ADC_PRESCALER_64        6
#define ADC_PRESCALER_128       7

#define REFERENCE_MASK          0x00111111
#define TURN_OFF                0
#define AVCC                    1<<6
#define INTERNAL_2_56V          3<<6

#define _8_BITS                 0
#define _10_BITS                1

#define ADJUSTMENT_MASK         0b11011111
#define RIGHT_ADJUSTED          0
#define LEFT_ADJUSTED           1<<5

#define CHANNEL_MASK            0x11100000
#define ADC0                    0
#define ADC1                    1
#define ADC2                    2
#define ADC3                    3
#define ADC4                    4
#define ADC5                    5
#define ADC6                    6
#define ADC7                    7
#define ADC0_ADC0_10x           8
#define ADC1_ADC0_10x           9
#define ADC0_ADC0_200x          10
#define ADC1_ADC0_200x          11
#define ADC2_ADC2_10x           12
#define ADC3_ADC2_10x           13
#define ADC2_ADC2_200x          14
#define ADC3_ADC2_200x          15
#define ADC0_ADC1_1x            16
#define ADC1_ADC1_1x            17
#define ADC2_ADC1_1x            18
#define ADC3_ADC1_1x            19
#define ADC4_ADC1_1x            20
#define ADC5_ADC1_1x            21
#define ADC6_ADC1_1x            22
#define ADC7_ADC1_1x            23
#define ADC0_ADC2_1x            24
#define ADC1_ADC2_1x            25
#define ADC2_ADC2_1x            26
#define ADC3_ADC2_1x            27
#define ADC4_ADC2_1x            28
#define ADC5_ADC2_1x            29
#define VBG                     30
#define ZERO_VOLT               31

void __vector_16(void) __attribute__((signal));

#endif