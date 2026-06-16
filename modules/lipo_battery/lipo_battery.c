#include "lipo_battery.h"
#include "logger.h"
#include "platform.h"

static lipo_battery_config_t lipo_cfg;
static lipo_battery_data_t lipo_data;

void LipoBattery_Configure(uint8_t cell_count,
                           uint8_t adc_channel)
{
    lipo_cfg.cell_count = cell_count;
    lipo_cfg.adc_channel = adc_channel;
}

void LipoBattery_Init(void)
{
    Log_Info("LiPo Battery Initialized");
}

lipo_battery_data_t LipoBattery_GetData(void)
{
    return lipo_data;
}

void LipoBattery_Update(void)
{
    if (lipo_cfg.cell_count == 0)
    {
        Log_Error("LiPo Battery Not Configured");
        return;
    }

    lipo_data.voltage =
        Platform_ADC_Read(lipo_cfg.adc_channel);

    lipo_data.cell_voltage =
        lipo_data.voltage /
        lipo_cfg.cell_count;

    if (lipo_data.cell_voltage < 3.7f)
    {
        Log_Error("LiPo Battery Low");
    }
}
