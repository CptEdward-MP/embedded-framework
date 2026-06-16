#ifndef MODULE_H
#define MODULE_H

typedef struct
{
    const char *name;

    void (*init)(void);
    void (*update)(void);

} module_t;

#endif /* MODULE_H */
