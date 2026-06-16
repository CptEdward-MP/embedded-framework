#include "lipo_battery.h"

#include "logger.h"
#include "platform.h"



/* Configure battery instance */
void LipoBattery_Configure(
    lipo_battery_t *battery,
    uint8_t cell_count,
    uint8_t adc_channel)
{
    battery->config.cell_count = cell_count;

    battery->config.adc_channel = adc_channel;
}

/* Initialize battery instance */
void LipoBattery_Init(
    lipo_battery_t *battery)
{
    (void)battery;

    Log_Info("LiPo Battery Initialized");
}

/* Get latest battery data */
lipo_battery_data_t LipoBattery_GetData(
    const lipo_battery_t *battery)
{
    return battery->data;
}

/* Update battery measurements */
void LipoBattery_Update(
    lipo_battery_t *battery)
{
    if (battery->config.cell_count == 0)
    {
        Log_Error("LiPo Battery Not Configured");

        return;
    }

    battery->data.voltage =
        Platform_ADC_Read(
            battery->config.adc_channel);

    battery->data.cell_voltage =
        battery->data.voltage /
        battery->config.cell_count;

    if (battery->data.cell_voltage < 3.7f)
    {
        Log_Error("LiPo Battery Low");
    }
}

/* Module init adapter */
void LipoBattery_ModuleInit(
    void *context)
{
    LipoBattery_Init(
        (lipo_battery_t *)context);
}

/* Module update adapter */
void LipoBattery_ModuleUpdate(
    void *context)
{
    LipoBattery_Update(
        (lipo_battery_t *)context);
}