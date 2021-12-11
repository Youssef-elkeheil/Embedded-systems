#include "SCH_interface.h"
#include "SCH_config.h"
#include "SCH_private.h"

void SCH_Start (void) {
    /* 1- init for timer */
    /* 2- measure time async takes schedulle as I/P */
}
void SCH_CreateTask(u8 copy_u8Priority,
                    u16 copy_u16Periodicity,
                    void (*ptr_TaskFunc)(void)
                    ){

    taskARR[copy_u8Priority].periodicity = copy_u16Periodicity;
    taskARR[copy_u8Priority].taskFunc = ptr_TaskFunc;
}
static void schedule(void){/* Called ar fixed intervals */
    static u16 local_u16TickCount =0;
    local_u16TickCount++;
    for (u8 local_TaskCount = 0; local_TaskCount < MAX_TASKS; local_TaskCount++){
        if ((local_u16TickCount % taskArr[local_u16TickCount].periodicity)== 0){
            taskArr[local_u16TickCount].TaskFunc();
        }
    }
}