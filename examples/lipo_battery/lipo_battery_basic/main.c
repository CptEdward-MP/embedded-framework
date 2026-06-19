#include <stdio.h>



#include "lipo_battery.h"
#include "logger.h"

static const char *BatteryStatusToString(
    lipo_battery_status_t status)
{
    switch (status)
    {
        case LIPO_STATUS_OK:
            return "OK";

        case LIPO_STATUS_WARNING:
            return "WARNING";

        case LIPO_STATUS_LOW:
            return "LOW";

        case LIPO_STATUS_CRITICAL:
            return "CRITICAL";

        default:
            return "UNKNOWN";
    }
}

int main(void)
{
    lipo_battery_t battery;

    Log_Info(
        "Battery Example Started");

    LipoBattery_Configure(
        &battery,
        3,
        0);

    LipoBattery_Init(
        &battery);

    LipoBattery_Update(
        &battery);

    lipo_battery_data_t data =
        LipoBattery_GetData(
            &battery);

    char message[128];

    snprintf(
        message,
        sizeof(message),
        "Voltage = %.2fV, Cell Voltage = %.2fV, Status = %s",
        data.voltage,
        data.cell_voltage,
        BatteryStatusToString(
            data.status));

    Log_Info(
        message);

    return 0;
}