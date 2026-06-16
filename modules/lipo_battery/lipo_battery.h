#ifndef LIPO_BATTERY_H
#define LIPO_BATTERY_H

#include <stdint.h>

typedef struct
{
    uint8_t cell_count;

    uint8_t adc_channel;

} lipo_battery_config_t;

typedef struct
{
    float voltage;
    float cell_voltage;

} lipo_battery_data_t;

void LipoBattery_Configure(uint8_t cell_count,
                           uint8_t adc_channel);

void LipoBattery_Init(void);

void LipoBattery_Update(void);

lipo_battery_data_t LipoBattery_GetData(void);

#endif /* LIPO_BATTERY_H */
