#include "logger.h"

int main(void)
{
    float battery_voltage = 12.45f;

    float yaw = 35.7f;

    int encoder_count = 1250;

    Log_Info(
        "System Started");

    Log_Info(
        "Battery = %.2f V",
        battery_voltage);

    Log_Info(
        "Yaw = %.2f deg",
        yaw);

    Log_Info(
        "Encoder = %d",
        encoder_count);

    Log_Warn(
        "Battery Low: %.2f V",
        10.90f);

    Log_Error(
        "Encoder Fault: %d",
        -1);

    return 0;
}