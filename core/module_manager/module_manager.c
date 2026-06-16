#include "module_manager.h"

#define MAX_MODULES 10

static module_t *registered_modules[MAX_MODULES];

static int module_count = 0;

void Module_Register(module_t *module)
{
    if (module_count < MAX_MODULES)
    {
        registered_modules[module_count] = module;
        module_count++;
    }
}

void Module_InitAll(void)
{
    for (int i = 0; i < module_count; i++)
    {
        if (registered_modules[i]->init)
        {
            registered_modules[i]->init();
        }
    }
}

void Module_UpdateAll(void)
{
    for (int i = 0; i < module_count; i++)
    {
        if (registered_modules[i]->update)
        {
            registered_modules[i]->update();
        }
    }
}
