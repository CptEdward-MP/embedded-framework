#include "logger.h"
#include "scheduler.h"

static void Task_100ms(void *context)
{
    (void)context;

    Log_Info(
        "100 ms Task");
}

static void Task_500ms(void *context)
{
    (void)context;

    Log_Info(
        "500 ms Task");
}

int main(void)
{
    Scheduler_Init();

    Scheduler_RegisterTask(
        Task_100ms,
        0,
        100);

    Scheduler_RegisterTask(
        Task_500ms,
        0,
        500);

    Log_Info(
        "Scheduler Example Started");

    while (1)
    {
        Scheduler_Run();
    }

    return 0;
}