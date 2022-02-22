#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

#include"DMA_config.h"

inline void MCAL_DMA2_Clock_enable(char state);
void MCAL_DMA2_StreamConfig(char Stream_no, DMA_StreamConfig _Local_config);
void MCAL_DMA2_Transfer_Config(char Stream_no, int *Source, int *Destination, int items_no);
void MCAL_DMA2_Start_Transfer(char Stream_no);
char MCAL_DMA2_Transfer_State(char Stream_no);

struct DMA_StreamConfig
{   
    char channel_No;                    // select channel according to application 
    char M_BURST;                       // dest burst transfer configuration
    char P_BURST;                       // Peripheral burst transfer configuration
    char Current_target;                // for double buffer mode only
    char Double_buffer_mode;            
    char Priority;                      // priority level
    char PINCOS;                        // peripheral increament offset size
    char M_size;                        // Memory data size
    char P_size;                        // Peripheral data size
    char M_Inc;                         // Memory increment mode
    char P_Inc;                         // Peripheral increment mode
    char Circular_mode;                 // enable/disable circular mode
    char Data_direction;                // peripheral_memory or memory_peripheral or memory_memory
    char Flow_Controller;               // choose whether DMA or Peripheral controls flow of data
    char Transfer_complete_interrupt;   
    char Half_Transfer_interrupt;       
    char Transfer_error_interrupt;      
    char DirectMode_error_interrupt;    
    char FIFO_error_interrupt;          
    char FIFO_thershold;                // define FIFO Thershold (1/4,1/2,3/4,full)             

}typedef DMA_StreamConfig;


#endif