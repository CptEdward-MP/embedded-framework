#include "module_manager.h"
#include "logger.h"
#include <stddef.h>

/* Module A init */
static void ModuleA_Init(
    void *context)
{
    (void)context;

    Log_Info(
        "Module A Init");
}

/* Module A update */
static void ModuleA_Update(
    void *context)
{
    (void)context;

    Log_Info(
        "Module A Update");
}

/* Module B init */
static void ModuleB_Init(
    void *context)
{
    (void)context;

    Log_Info(
        "Module B Init");
}

/* Module B update */
static void ModuleB_Update(
    void *context)
{
    (void)context;

    Log_Info(
        "Module B Update");
}

/* Module instances */
static module_t module_a =
{
    .name = "Module A",

    .context = NULL,

    .init = ModuleA_Init,

    .update = ModuleA_Update
};

static module_t module_b =
{
    .name = "Module B",

    .context = NULL,

    .init = ModuleB_Init,

    .update = ModuleB_Update
};

int main(void)
{
    Module_Register(
        &module_a);

    Module_Register(
        &module_b);

    Module_InitAll();

    Module_UpdateAll();

    return 0;
}