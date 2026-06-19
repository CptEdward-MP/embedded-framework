#include "logger.h"
#include "time.h"

int main(void)
{
    uint32_t start;

    Log_Info(
        "Time Example Started");

    start =
        Time_GetMs();

    while ((Time_GetMs() - start) < 1000U)
    {
    }

    Log_Info(
        "1 Second Elapsed");

    return 0;
}