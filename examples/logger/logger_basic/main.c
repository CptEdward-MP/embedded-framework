#include "logger.h"

int main(void)
{
    Log_Info(
        "System Started");

    Log_Warn(
        "Battery Warning");

    Log_Error(
        "Battery Critical");

    return 0;
}