#include "platform.h"
#include "osal.h"
#include "logger.h"
#include "lipo_battery.h"
#include "module_manager.h"

/* Battery instance */
lipo_battery_t main_battery;

/* Module registration */
module_t main_battery_module =
{
    .name = "Main Battery",

    .context = &main_battery,

    .init = LipoBattery_ModuleInit,

    .update = LipoBattery_ModuleUpdate
};

int main(void)
{
    Log_Info("Framework Started");

    LipoBattery_Configure(
        &main_battery,
        3,
        0);

    Module_Register(
        &main_battery_module);

    Module_InitAll();

    while (1)
    {
        Module_UpdateAll();

        OS_SleepMs(1000);
    }

    return 0;
}