#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

#include "module.h"

/* Registration status */
#define MODULE_OK          0
#define MODULE_FULL       -1
#define MODULE_NULL       -2


/* Register framework module */
int Module_Register(
    module_t *module);

/* Initialize all modules */
void Module_InitAll(void);

/* Update all modules */
void Module_UpdateAll(void);

#endif /* MODULE_MANAGER_H */