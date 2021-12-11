#ifndef _SCH_PRIVATE_H
#define _SCH_PRIVATE_H

typedef struct 
{
    u16 periodicity;
    void (* taskFunc) (void);
}task_t;
 
static task_t taskArr[MaX_TASKS] = {{0}};
static void schedule (void);
#endif