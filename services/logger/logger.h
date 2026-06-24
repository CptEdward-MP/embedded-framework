#ifndef LOGGER_H
#define LOGGER_H


void Log_Info(
    const char *format,
    ...);

void Log_Warn(
    const char *format,
    ...);

void Log_Error(
    const char *format,
    ...);

#endif
