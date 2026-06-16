#ifndef LOG_TYPES_H
#define LOG_TYPES_H

#include <stdint.h>

typedef enum
{
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR
} log_level_t;

typedef struct
{
    uint32_t timestamp;
    log_level_t level;
    const char *message;
} log_record_t;

#endif
