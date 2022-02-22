#ifndef DMA_REGISTERS_H_
#define DMA_REGISTERS_H_

// DMA1EN bit 21
// DMA2EN bit 22
#define RCC_AHB1ENR *((unsigned int *)(0x40023830))
#define RCC_AHB1ENR_DMA1 (1 << 21)
#define RCC_AHB1ENR_DMA2 (1 << 22)

#define DMA1_ADDRESS 0x40026000
#define DMA2_ADDRESS 0x40026400

#define DMA1_LISR    *((unsigned int *)(DMA1_ADDRESS + 0x0000))
#define DMA1_HISR    *((unsigned int *)(DMA1_ADDRESS + 0x0004))
#define DMA1_LIFCR   *((unsigned int *)(DMA1_ADDRESS + 0x0008))
#define DMA1_HIFCR   *((unsigned int *)(DMA1_ADDRESS + 0x000C))

#define DMA1_SxCR(x)    *((unsigned int *)(DMA1_ADDRESS + 0x0010 +(x)*0x18))
#define DMA1_SxNDTR(x)  *((unsigned int *)(DMA1_ADDRESS + 0x0014 +(x)*0x18))
#define DMA1_SxPAR(x)   *((unsigned int**)(DMA1_ADDRESS + 0x0018 +(x)*0x18))
#define DMA1_SxM0AR(x)  *((unsigned int**)(DMA1_ADDRESS + 0x001C +(x)*0x18))
#define DMA1_SxM1AR(x)  *((unsigned int**)(DMA1_ADDRESS + 0x0020 +(x)*0x18))
#define DMA1_SxFCR(x)   *((unsigned int *)(DMA1_ADDRESS + 0x0024 +(x)*0x18))

#define DMA2_LISR       *((unsigned int *)(DMA2_ADDRESS + 0x0000))
#define DMA2_HISR       *((unsigned int *)(DMA2_ADDRESS + 0x0004))
#define DMA2_LIFCR      *((unsigned int *)(DMA2_ADDRESS + 0x0008))
#define DMA2_HIFCR      *((unsigned int *)(DMA2_ADDRESS + 0x000C))

#define DMA2_SxCR(x)    *((unsigned int *)(DMA2_ADDRESS + 0x0010 +(x)*0x18))
#define DMA2_SxNDTR(x)  *((unsigned int *)(DMA2_ADDRESS + 0x0014 +(x)*0x18))
#define DMA2_SxPAR(x)   *((unsigned int**)(DMA2_ADDRESS + 0x0018 +(x)*0x18))
#define DMA2_SxM0AR(x)  *((unsigned int**)(DMA2_ADDRESS + 0x001C +(x)*0x18))
#define DMA2_SxM1AR(x)  *((unsigned int**)(DMA2_ADDRESS + 0x0020 +(x)*0x18))
#define DMA2_SxFCR(x)   *((unsigned int *)(DMA2_ADDRESS + 0x0024 +(x)*0x18))

#endif