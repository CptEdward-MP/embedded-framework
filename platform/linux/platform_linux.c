#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

#include "platform_linux.h"

void Platform_Write(const char *data)
{
    printf("%s", data);
}


float Platform_ADC_Read(unsigned char channel)
{
    (void)channel;

    /*
     * Mock ADC implementation.
     *
     * Linux development environment
     * does not provide a real ADC source.
     *
     * Simulated 3S LiPo:
     * 13.5V total
     */
    return 13.5f;
}


uint32_t Platform_Time_GetMs(void)
{
    struct timeval tv;

    gettimeofday(
        &tv,
        NULL);

    return
        (uint32_t)(
            tv.tv_sec * 1000U +
            tv.tv_usec / 1000U);
}