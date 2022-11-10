#ifndef _7_SEGMENT_H
#define _7_SEGMENT_H

void HAL_7_Segment_Init(char port,char start_pin);
void HAL_7_Segment_Display(char port, char start, int num);
void HAL_7_Segment_TurnOff(char port, char start);
#endif
