#include <stdint.h>

#include "logger.h"
#include "scheduler.h"
#include "time.h"

static uint32_t task1_count;
static uint32_t task2_count;

static void TestTask1(
    void *context)
{
    (void)context;

    task1_count++;
}

static void TestTask2(
    void *context)
{
    (void)context;

    task2_count++;
}

static void Test_RegisterTask(void)
{
    uint8_t task_id;

    task_id =
        Scheduler_RegisterTask(
            TestTask1,
            0,
            100);

    if (task_id !=
        SCHEDULER_INVALID_TASK_ID)
    {
        Log_Info(
            "PASS: Register Task");
    }
    else
    {
        Log_Error(
            "FAIL: Register Task");
    }
}

static void Test_TaskExecution(void)
{
    uint32_t start;

    Scheduler_RegisterTask(
        TestTask1,
        0,
        100);

    start =
        Time_GetMs();

    while ((Time_GetMs() - start)
            < 150U)
    {
        Scheduler_Run();
    }

    if (task1_count > 0)
    {
        Log_Info(
            "PASS: Task Execution");
    }
    else
    {
        Log_Error(
            "FAIL: Task Execution");
    }
}

static void Test_MultipleTasks(void)
{
    uint32_t start;

    task1_count = 0;
    task2_count = 0;

    Scheduler_Init();

    Scheduler_RegisterTask(
        TestTask1,
        0,
        100);

    Scheduler_RegisterTask(
        TestTask2,
        0,
        200);

    start =
        Time_GetMs();

    while ((Time_GetMs() - start)
            < 300U)
    {
        Scheduler_Run();
    }

    if ((task1_count > 0) &&
        (task2_count > 0))
    {
        Log_Info(
            "PASS: Multiple Tasks");
    }
    else
    {
        Log_Error(
            "FAIL: Multiple Tasks");
    }
}

int main(void)
{
    Log_Info(
        "Starting Scheduler Tests");

    Scheduler_Init();

    Test_RegisterTask();

    Scheduler_Init();

    task1_count = 0;

    Test_TaskExecution();

    Test_MultipleTasks();

    Log_Info(
        "Scheduler Tests Complete");

    return 0;
}