#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdint.h>

void Platform_Write(const char *data);

float Platform_ADC_Read(uint8_t channel);

#endif

