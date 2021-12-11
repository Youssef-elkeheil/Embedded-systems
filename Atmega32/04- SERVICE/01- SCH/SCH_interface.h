#ifndef _SCH_INTERFACE_H
#define _SCH_INTERFACE_H

void SCH_Start (void);
void SCH_CreateTask(u8 copy_u8Priority,
                    u16 copy_u16Periodicity,
                    void (* ptr_TaskFunc)(void)
                    );
                    
#endif