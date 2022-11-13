#include "../../01- LIB/std_types.h"
#include "../../01- LIB/common_macros.h"

#include "SCH_interface.h"
#include "SCH_config.h"
#include "SCH_private.h"

void SCH_Start (void) {
    /* 1- init for timer */
    /* 2- measure time async takes schedulle as I/P */
}
void SCH_CreateTask(uint_8 copy_u8Priority,
                    uint_16 copy_u16Periodicity,
                    void (*ptr_TaskFunc)(void)
                    ){

    taskArr[copy_u8Priority].periodicity = copy_u16Periodicity;
    taskArr[copy_u8Priority].taskFunc = ptr_TaskFunc;
}
static void schedule(void){/* Called at fixed intervals */
    static uint_16 local_u16TickCount =0;
    local_u16TickCount++;
    for (uint_8 local_TaskCount = 0; local_TaskCount < MaX_TASKS; local_TaskCount++){
        if ((local_u16TickCount % taskArr[local_u16TickCount].periodicity)== 0){
            taskArr[local_u16TickCount].taskFunc();
        }
    }
}