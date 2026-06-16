#ifndef LOG_SINK_H
#define LOG_SINK_H

#include "log_types.h"

typedef struct
{
    void (*consume)(const log_record_t *record);
} log_sink_t;

#endif
