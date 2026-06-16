#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

#include "module.h"

void Module_Register(module_t *module);

void Module_InitAll(void);

void Module_UpdateAll(void);

#endif /* MODULE_MANAGER_H */
