#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

#include "platform_linux.h"

void Platform_Write(const char *data)
{
    printf("%s", data);
}


static float adc_channels[8] =
{
    13.5f
};


float Platform_ADC_Read(
    unsigned char channel)
{
    if (channel >= 8)
    {
        return 0.0f;
    }

    return adc_channels[channel];
}


void Platform_ADC_SetValue(
    unsigned char channel,
    float value)
{
    if (channel >= 8)
    {
        return;
    }

    adc_channels[channel] =
        value;
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