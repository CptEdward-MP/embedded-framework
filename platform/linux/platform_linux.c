#include <stdio.h>
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
     * 10.5V total
     */
    return 10.5f;
}
