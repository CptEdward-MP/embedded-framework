#include "logger.h"

/* Test info logging */
static void Test_InfoLog(void)
{
    Log_Info(
        "PASS: Info Log");
}

/* Test warning logging */
static void Test_WarnLog(void)
{
    Log_Warn(
        "PASS: Warning Log");
}

/* Test error logging */
static void Test_ErrorLog(void)
{
    Log_Error(
        "PASS: Error Log");
}

/* Test multiple log records */
static void Test_MultipleLogs(void)
{
    Log_Info(
        "PASS: Multiple Logs 1");

    Log_Warn(
        "PASS: Multiple Logs 2");

    Log_Error(
        "PASS: Multiple Logs 3");
}

int main(void)
{
    Log_Info(
        "Starting Logger Tests");

    Test_InfoLog();

    Test_WarnLog();

    Test_ErrorLog();

    Test_MultipleLogs();

    Log_Info(
        "Logger Tests Complete");

    return 0;
}