#include "time.h"

#include "platform.h"

uint32_t Time_GetMs(void)
{
    return Platform_Time_GetMs();
}