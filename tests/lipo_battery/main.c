#include <stdio.h>

#include "lipo_battery.h"
#include "logger.h"

/* Test battery instance */
static lipo_battery_t battery;

/* Test Configure */
static void Test_Configure(void)
{
    LipoBattery_Configure(
        &battery,
        3,
        0);

    if ((battery.config.cell_count == 3) &&
        (battery.config.adc_channel == 0))
    {
        Log_Info(
            "PASS: Configure");
    }
    else
    {
        Log_Error(
            "FAIL: Configure");
    }
}

/* Test Init */
static void Test_Init(void)
{
    LipoBattery_Init(
        &battery);

    Log_Info(
        "PASS: Init");
}

/* Test Update */
static void Test_Update(void)
{
    LipoBattery_Update(
        &battery);

    if (battery.data.voltage > 0.0f)
    {
        Log_Info(
            "PASS: Update");
    }
    else
    {
        Log_Error(
            "FAIL: Update");
    }
}

/* Test GetData */
static void Test_GetData(void)
{
    lipo_battery_data_t data =
        LipoBattery_GetData(
            &battery);

    if (data.voltage > 0.0f)
    {
        Log_Info(
            "PASS: GetData");
    }
    else
    {
        Log_Error(
            "FAIL: GetData");
    }
}

/* Test Status */
static void Test_Status(void)
{
    lipo_battery_data_t data =
        LipoBattery_GetData(
            &battery);

    if (data.status ==
        LIPO_STATUS_OK)
    {
        Log_Info(
            "PASS: Status");
    }
    else
    {
        Log_Error(
            "FAIL: Status");
    }
}

int main(void)
{
    Log_Info(
        "Starting LiPo Battery Tests");

    Test_Configure();

    Test_Init();

    Test_Update();

    Test_GetData();

    Test_Status();

    Log_Info(
        "LiPo Battery Tests Complete");

    return 0;
}