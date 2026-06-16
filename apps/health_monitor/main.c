#include "platform_linux.h"
#include "osal.h"
#include "logger.h"
#include "lipo_battery.h"

int main(void)
{
    Log_Info("Framework Started");


    LipoBattery_Configure(3, 0);
    LipoBattery_Init();



    while (1)
    {
        LipoBattery_Update();

        OS_SleepMs(1000);
    }

    return 0;
}
