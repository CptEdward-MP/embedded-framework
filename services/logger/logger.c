#include <stdarg.h>
#include <stdio.h>

#include "logger.h"
#include "log_types.h"
#include "platform_linux.h"


/*
 * TEMPORARY IMPLEMENTATION
 *
 * Logger currently dispatches records directly
 * to console output.
 *
 * Future versions will support multiple consumers:
 * - Console
 * - Memory
 * - File
 * - Network
 */
//-----------------------------------------------------------------//
static void Logger_Dispatch(const log_record_t *record)
{
    switch(record->level)
    {
        case LOG_INFO:
            Platform_Write("[INFO] ");
            break;

        case LOG_WARN:
            Platform_Write("[WARN] ");
            break;

        case LOG_ERROR:
            Platform_Write("[ERROR] ");
            break;

        default:
            Platform_Write("[UNKNOWN] ");
            break;
    }

    Platform_Write(record->message);
    Platform_Write("\n");
}
//--------------------------------------------------------------------//



static void Logger_Log(log_level_t level,
                       const char *message)
{
    log_record_t record =
    {
        .timestamp = 0,
        .level = level,
        .message = message
    };

    Logger_Dispatch(&record);
}


static void Logger_LogFormatted(
    log_level_t level,
    const char *format,
    va_list args)
{
    char buffer[128];

    vsnprintf(
        buffer,
        sizeof(buffer),
        format,
        args);

    Logger_Log(
        level,
        buffer);
}


void Log_Info(
    const char *format,
    ...)
{
    va_list args;

    va_start(
        args,
        format);

    Logger_LogFormatted(
        LOG_INFO,
        format,
        args);

    va_end(args);
}

void Log_Warn(
    const char *format,
    ...)
{
    va_list args;

    va_start(
        args,
        format);

    Logger_LogFormatted(
        LOG_WARN,
        format,
        args);

    va_end(args);
}

void Log_Error(
    const char *format,
    ...)
{
    va_list args;

    va_start(
        args,
        format);

    Logger_LogFormatted(
        LOG_ERROR,
        format,
        args);

    va_end(args);
}
