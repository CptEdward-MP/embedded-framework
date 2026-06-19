#include <stdint.h>

#include "logger.h"
#include "time.h"

static void Test_TimeProgress(void)
{
    uint32_t start;
    uint32_t end;

    start =
        Time_GetMs();

    while ((Time_GetMs() - start) < 10U)
    {
    }

    end =
        Time_GetMs();

    if (end > start)
    {
        Log_Info(
            "PASS: Time Progress");
    }
    else
    {
        Log_Error(
            "FAIL: Time Progress");
    }
}

int main(void)
{
    Log_Info(
        "Starting Time Tests");

    Test_TimeProgress();

    Log_Info(
        "Time Tests Complete");

    return 0;
}