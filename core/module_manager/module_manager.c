#include "module_manager.h"
#include <stddef.h>

#define MAX_MODULES 10

static module_t *registered_modules[MAX_MODULES];

static int module_count = 0;

/* Register framework module */
int Module_Register(
    module_t *module)
{
    if (module == NULL)
    {
        return MODULE_NULL;
    }

    if (module_count >= MAX_MODULES)
    {
        return MODULE_FULL;
    }

    registered_modules[module_count] = module;

    module_count++;

    return MODULE_OK;
}

/* Initialize all registered modules */
void Module_InitAll(void)
{
    for (int i = 0; i < module_count; i++)
    {
        if (registered_modules[i]->init)
        {
            registered_modules[i]->init(
                registered_modules[i]->context);
        }
    }
}

/* Update all registered modules */
void Module_UpdateAll(void)
{
    for (int i = 0; i < module_count; i++)
    {
        if (registered_modules[i]->update)
        {
            registered_modules[i]->update(
                registered_modules[i]->context);
        }
    }
}