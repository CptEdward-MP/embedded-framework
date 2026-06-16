#include <unistd.h>
#include "osal.h"

void OS_SleepMs(uint32_t ms)
{
    usleep(ms * 1000);
}
