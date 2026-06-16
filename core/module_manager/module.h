#ifndef MODULE_H
#define MODULE_H

/* Framework module instance */
typedef struct
{
    const char *name;

    void *context;

    void (*init)(
        void *context);

    void (*update)(
        void *context);

} module_t;

#endif /* MODULE_H */