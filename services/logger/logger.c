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

void Log_Info(const char *message)
{
    Logger_Log(LOG_INFO, message);
}

void Log_Warn(const char *message)
{
    Logger_Log(LOG_WARN, message);
}

void Log_Error(const char *message)
{
    Logger_Log(LOG_ERROR, message);
}
