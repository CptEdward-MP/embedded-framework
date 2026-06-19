#include <stddef.h>

#include "module_manager.h"
#include "logger.h"

/* Test counters */
static int init_called = 0;

static int update_called = 0;

/* Test init */
static void Test_Init(
    void *context)
{
    (void)context;

    init_called++;
}

/* Test update */
static void Test_Update(
    void *context)
{
    (void)context;

    update_called++;
}

/* Test module */
static module_t test_module =
{
    .name = "Test Module",

    .context = NULL,

    .init = Test_Init,

    .update = Test_Update
};

/* Test successful registration */
static void Test_RegisterSuccess(void)
{
    int result =
        Module_Register(
            &test_module);

    if (result == MODULE_OK)
    {
        Log_Info(
            "PASS: Register Success");
    }
    else
    {
        Log_Error(
            "FAIL: Register Success");
    }
}

/* Test NULL module */
static void Test_NullModule(void)
{
    int result =
        Module_Register(
            NULL);

    if (result == MODULE_NULL)
    {
        Log_Info(
            "PASS: NULL Module");
    }
    else
    {
        Log_Error(
            "FAIL: NULL Module");
    }
}

/* Test init execution */
static void Test_InitExecution(void)
{
    Module_InitAll();

    if (init_called == 1)
    {
        Log_Info(
            "PASS: Init Execution");
    }
    else
    {
        Log_Error(
            "FAIL: Init Execution");
    }
}

/* Test update execution */
static void Test_UpdateExecution(void)
{
    Module_UpdateAll();

    if (update_called == 1)
    {
        Log_Info(
            "PASS: Update Execution");
    }
    else
    {
        Log_Error(
            "FAIL: Update Execution");
    }
}

int main(void)
{
    Log_Info(
        "Starting Module Manager Tests");

    Test_RegisterSuccess();

    Test_NullModule();

    Test_InitExecution();

    Test_UpdateExecution();

    Log_Info(
        "Module Manager Tests Complete");

    return 0;
}