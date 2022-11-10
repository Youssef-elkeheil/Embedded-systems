#include"DMA_interface.h"
#include "DMA_registers.h"
#include"DMA_config.h"

void (*Global_DMA_ISRExcution[2][8])(void) = {(void *)0};

inline void MCAL_DMA2_Clock_enable(char state)
{
    RCC_AHB1ENR &= ~RCC_AHB1ENR_DMA2;
    RCC_AHB1ENR |= state;
}

void MCAL_DMA2_StreamConfig(char Stream_no, DMA_StreamConfig* _Local_config)
{

    /* clear previous configurations */
    DMA2_SxCR(Stream_no) = 0;
    /*wait until register reset is complete*/
    while ((DMA2_SxCR(Stream_no)));
    /* channel selection*/
    DMA2_SxCR(Stream_no) |= ((_Local_config->channel_No) << 25);
    /* Memory BURST*/
    DMA2_SxCR(Stream_no) |= ((_Local_config->M_BURST) << 23);
    /* Peripheral BURST*/
    DMA2_SxCR(Stream_no) |= ((_Local_config->P_BURST) << 21);
    /* Current target */
    DMA2_SxCR(Stream_no) |= ((_Local_config->Current_target) << 19);
    /* Double buffer mode*/
    DMA2_SxCR(Stream_no) |= ((_Local_config->Double_buffer_mode) << 18);
    /* Priority Level */
    DMA2_SxCR(Stream_no) |= ((_Local_config->Priority) << 16);
    /* peripheral increment offset size */
    DMA2_SxCR(Stream_no) |= ((_Local_config->Priority) << 15);
    /* Memory data size*/
    DMA2_SxCR(Stream_no) |= ((_Local_config->M_size) << 13);
    /* Peripheral data size*/
    DMA2_SxCR(Stream_no) |= ((_Local_config->P_size) << 11);
    /* Memory increment mode */
    DMA2_SxCR(Stream_no) |= ((_Local_config->M_Inc )<< 10);
    /* Peripheral increment mode*/
    DMA2_SxCR(Stream_no) |= ((_Local_config->P_Inc )<< 9);
    /* Circular mode*/
    DMA2_SxCR(Stream_no) |= ((_Local_config->Circular_mode )<< 8);
    /* Data direction */
    DMA2_SxCR(Stream_no) |= ((_Local_config->Data_direction )<< 6);
    /* Flow Controller */
    DMA2_SxCR(Stream_no) |= ((_Local_config->Flow_Controller )<< 5);
    /* Transfer Complete interrupt */
    DMA2_SxCR(Stream_no) |= ((_Local_config->Transfer_complete_interrupt) << 4);
    /* Half Transfer interrupt */
    DMA2_SxCR(Stream_no) |= ((_Local_config->Half_Transfer_interrupt) << 3);
    /* Transfer Error interrupt */
    DMA2_SxCR(Stream_no) |= ((_Local_config->Transfer_error_interrupt) << 2);
    /* Direct mode Error interrupt */
    DMA2_SxCR(Stream_no) |= ((_Local_config->DirectMode_error_interrupt) << 1);
    /* FIFO Threshold */
    DMA2_SxFCR(Stream_no) |= ((_Local_config->FIFO_thershold) << 0);
    /* FIFO interrupt */
    DMA2_SxFCR(Stream_no) |= ((_Local_config->FIFO_error_interrupt) << 7);
}

void MCAL_DMA2_Transfer_Config(char Stream_no, int *Source, int *Destination, int items_no)
{
    char transfer_direction = (DMA2_SxCR(Stream_no)>>6)&0x03;
    switch (transfer_direction)
    {
        case DMA_MEMORY_TO_PERIPHERAL:
            DMA2_SxM0AR(Stream_no) = Source;
            DMA2_SxPAR(Stream_no) = Destination;
        break;

        default:
            DMA2_SxM0AR(Stream_no) = Destination;
            DMA2_SxPAR(Stream_no) = Source;
        break;
    }
    /* define number of items to transfer */
    DMA2_SxNDTR(Stream_no) = items_no;
}

void MCAL_DMA2_Start_Transfer(char Stream_no) 
{
    DMA2_SxCR(Stream_no) |= 1;
}
char MCAL_DMA2_Transfer_State(char Stream_no)
{
    switch (Stream_no)
    {
    case 0:
        return (DMA2_LISR>>4)&0x03;
        break;
    case 1:
        return (DMA2_LISR>>10)&0x03;
        break;
    case 2:
        return (DMA2_LISR>>20)&0x03;
        break;
    case 3:
        return (DMA2_LISR>>26)&0x03;
    break;
    case 4:
        return (DMA2_HISR>>4)&0x03;
        break;
    case 5:
        return (DMA2_HISR>>10)&0x03;
    break;
    case 6:
        return (DMA2_HISR>>20)&0x03;
    break;
    case 7:
        return (DMA2_HISR>>26)&0x03;
    break;
    }
}

void DMA1_Stream0_IRQHandler(void)
{
    Global_DMA_ISRExcution[0][0]();
}
void DMA1_Stream1_IRQHandler(void)
{
    Global_DMA_ISRExcution[0][1]();
}
void DMA1_Stream2_IRQHandler(void)
{
    Global_DMA_ISRExcution[0][2]();
}
void DMA1_Stream3_IRQHandler(void)
{
    Global_DMA_ISRExcution[0][3]();
}
void DMA1_Stream4_IRQHandler(void)
{
    Global_DMA_ISRExcution[0][4]();
}
void DMA1_Stream5_IRQHandler(void)
{
    Global_DMA_ISRExcution[0][5]();
}
void DMA1_Stream6_IRQHandler(void)
{
    Global_DMA_ISRExcution[0][6]();
}
void DMA1_Stream7_IRQHandler(void)
{
    Global_DMA_ISRExcution[0][7]();
}

// DMA 2
void DMA2_Stream0_IRQHandler(void)
{
    Global_DMA_ISRExcution[1][0]();
}
void DMA2_Stream1_IRQHandler(void)
{
    Global_DMA_ISRExcution[1][1]();
}
void DMA2_Stream2_IRQHandler(void)
{
    Global_DMA_ISRExcution[1][2]();
}
void DMA2_Stream3_IRQHandler(void)
{
    Global_DMA_ISRExcution[1][3]();
}
void DMA2_Stream4_IRQHandler(void)
{
    Global_DMA_ISRExcution[1][4]();
}
void DMA2_Stream5_IRQHandler(void)
{
    Global_DMA_ISRExcution[1][5]();
}
void DMA2_Stream6_IRQHandler(void)
{
    Global_DMA_ISRExcution[1][6]();
}
void DMA2_Stream7_IRQHandler(void)
{
    Global_DMA_ISRExcution[1][7]();
}