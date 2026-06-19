#include "lipo_battery.h"

#include "logger.h"
#include "platform.h"

/* Configure battery instance */
void LipoBattery_Configure(
    lipo_battery_t *battery,
    uint8_t cell_count,
    uint8_t adc_channel)
{
    battery->config.cell_count =
        cell_count;

    battery->config.adc_channel =
        adc_channel;

    battery->data.status =
        LIPO_STATUS_OK;

    battery->last_status =
        LIPO_STATUS_OK;
}

/* Initialize battery instance */
void LipoBattery_Init(
    lipo_battery_t *battery)
{
    (void)battery;

    Log_Info(
        "LiPo Battery Initialized");
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
        Log_Error(
            "LiPo Battery Not Configured");

        return;
    }

    battery->data.voltage =
        Platform_ADC_Read(
            battery->config.adc_channel);

    battery->data.cell_voltage =
        battery->data.voltage /
        battery->config.cell_count;

    lipo_battery_status_t new_status;

    if (battery->data.cell_voltage >= 3.8f)
    {
        new_status =
            LIPO_STATUS_OK;
    }
    else if (battery->data.cell_voltage >= 3.75f)
    {
        new_status =
            LIPO_STATUS_WARNING;
    }
    else if (battery->data.cell_voltage >= 3.6f)
    {
        new_status =
            LIPO_STATUS_LOW;
    }
    else
    {
        new_status =
            LIPO_STATUS_CRITICAL;
    }

    battery->data.status =
        new_status;

    if (new_status != battery->last_status)
    {
        battery->last_status =
            new_status;

        switch (new_status)
        {
            case LIPO_STATUS_OK:

                Log_Info(
                    "LiPo Battery OK");

                break;

            case LIPO_STATUS_WARNING:

                Log_Warn(
                    "LiPo Battery Warning");

                break;

            case LIPO_STATUS_LOW:

                Log_Error(
                    "LiPo Battery Low");

                break;

            case LIPO_STATUS_CRITICAL:

                Log_Error(
                    "LiPo Battery Critical");

                break;

            default:

                break;
        }
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