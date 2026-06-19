#include <stddef.h>
#include <stdio.h>  // for converting int to string as logger currently cant do so

#include "module_manager.h"
#include "logger.h"

/* Module data */
typedef struct
{
    int count;

} counter_t;

/* Module init */
static void Counter_Init(
    void *context)
{
    counter_t *counter =
        (counter_t *)context;

    counter->count = 0;

    Log_Info(
        "Counter Initialized");
}

/* Module update */
static void Counter_Update(
    void *context)
{
    counter_t *counter =
        (counter_t *)context;

    counter->count++;

    char message[64];

    snprintf(
        message,
        sizeof(message),
        "Counter = %d",
        counter->count);

    Log_Info(
        message);
}

/* Module data instance */
static counter_t counter_data;

/* Module instance */
static module_t counter_module =
{
    .name = "Counter Module",

    .context = &counter_data,

    .init = Counter_Init,

    .update = Counter_Update
};

int main(void)
{
    Module_Register(
        &counter_module);

    Module_InitAll();

    for (int i = 0; i < 5; i++)
    {
        Module_UpdateAll();
    }

    return 0;
}