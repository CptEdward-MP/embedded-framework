#ifndef LIPO_BATTERY_H
#define LIPO_BATTERY_H

#include <stdint.h>
#include "module.h"

typedef enum
{
    LIPO_STATUS_OK,

    LIPO_STATUS_WARNING,

    LIPO_STATUS_LOW,

    LIPO_STATUS_CRITICAL

} lipo_battery_status_t;


/* Battery configuration */
typedef struct
{
    uint8_t cell_count;

    uint8_t adc_channel;

} lipo_battery_config_t;

/* Battery measurements */
typedef struct
{
    float voltage;

    float cell_voltage;

    lipo_battery_status_t status;

} lipo_battery_data_t;

/* Battery instance */
typedef struct
{
    lipo_battery_config_t config;

    lipo_battery_data_t data;

} lipo_battery_t;

/* Configure battery instance */
void LipoBattery_Configure(
    lipo_battery_t *battery,
    uint8_t cell_count,
    uint8_t adc_channel);

/* Initialize battery instance */
void LipoBattery_Init(
    lipo_battery_t *battery);

/* Update battery measurements */
void LipoBattery_Update(
    lipo_battery_t *battery);

/* Get latest battery data */
lipo_battery_data_t LipoBattery_GetData(
    const lipo_battery_t *battery);

/* Module init adapter */
void LipoBattery_ModuleInit(
    void *context);

/* Module update adapter */
void LipoBattery_ModuleUpdate(
    void *context);

#endif /* LIPO_BATTERY_H */