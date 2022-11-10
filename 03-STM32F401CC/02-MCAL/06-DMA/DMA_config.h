#ifndef DMA_CONFIG_H_
#define DMA_CONFIG_H_

#define DMA_DISABLE 0
#define DMA_ENABLE  1

#define DMA_IS_CONTROLLING         0
#define DMA_IS_NOT_CONTROLLING     1

#define DMA_PERIPHERAL_TO_MEMORY    0
#define DMA_MEMORY_TO_PERIPHERAL    1
#define DMA_MEMORY_TO_MEMORY        2

#define DMA_INC_POINTER_IS_FIXED 0
#define DMA_INC_POINTER_IS_INCREMENTED 1

#define DMA_SIZE_8_BITS 0
#define DMA_SIZE_16_BITS 1
#define DMA_SIZE_32_BITS 2

#define DMA_BURST_Single    0
#define DMA_BURST_INC4      1
#define DMA_BURST_INC8      2
#define DMA_BURST_INC16     3

#define DMA_PINCOS_PSIZE  0 // linked to Psize
#define DMA_PINCOS_FIXED  1 //fixed by 4 bytes

#define DMA_FIFO_TH_1_4     0
#define DMA_FIFO_TH_1_2     1
#define DMA_FIFO_TH_3_4     2
#define DMA_FIFO_TH_FULL    3

#define DMA_HALF_TRANSFER     1
#define DMA_TRANSFER_COMPLETE 2

#endif