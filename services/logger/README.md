# Logger Service Documentation

## Purpose

The Logger Service provides a framework-wide mechanism for generating structured log records.

The logger is responsible for creating log records and distributing them to consumers.

The logger is not responsible for deciding how logs are displayed, stored, or transmitted.

---

## Current Version

Version: Logger V1.1

Status: Functional

---

## Architecture

Application

↓

Logger API

```c
Log_Info()
Log_Warn()
Log_Error()
```

↓

Formatted Message Generation

```c
vsnprintf()
```

↓

log_record_t

↓

Logger Dispatch

↓

Platform Output (Temporary)

---

## Log Record Structure

Current log record:

```c
timestamp
level
message
```

Example:

```c
{
    .timestamp = 0,
    .level = LOG_WARN,
    .message = "Battery Low"
}
```

---

## Log Levels

Supported levels:

```c
LOG_INFO
LOG_WARN
LOG_ERROR
```

---

## Formatted Logging

The logger supports printf-style formatting.

Examples:

```c
Log_Info("System Started");

Log_Info(
    "Battery = %.2f V",
    voltage);

Log_Info(
    "Encoder = %d",
    encoder_count);

Log_Warn(
    "Low Battery %.2f V",
    voltage);
```

Formatting is performed inside the Logger Service before records are dispatched.

Applications do not need to manually convert numbers into strings.

---

## Current Behavior

A log record is created.

The log message is formatted into a string.

The record is immediately dispatched.

The record is displayed through Platform_Write().

The record is then destroyed.

No persistent storage exists.

---

## Current Limitations

* No log storage
* No log history
* No ring buffer
* No real timestamps
* No filtering
* No multiple consumers
* No thread safety
* No dynamic consumer registration

---

## Sink Interface

Current sink interface:

```c
typedef struct
{
    void (*consume)(
        const log_record_t *record);
} log_sink_t;
```

Purpose:

```text
Allow future consumers to receive log records
without modifying the logger.
```

---

## Planned Consumers

* Console Consumer
* Memory Consumer
* File Consumer
* Network Consumer
* Dashboard Consumer

---

## Logger V1 Goal

Provide:

* Structured log records
* Log levels
* Formatted logging
* Platform-independent output path
* Consumer extension point

Avoid:

* Storage systems
* Complex infrastructure
* Dynamic registration
* Premature optimization

---

## Logger V2 Goals

* Memory Consumer
* Ring Buffer
* Log History
* Multiple Consumers
* Timestamp Support
* Log Filtering

---

## Design Principles

* Logger creates records.
* Consumers own behavior.
* Data and representation are separate.
* Formatting and transport are separate.
* Public APIs remain stable.
* Prefer extension over modification.
* Keep abstractions minimal.

---

## Dependencies

Current dependencies:

```text
Platform Service
```

Required platform functions:

```c
Platform_Write()
```

---

## Platform Independence

The Logger Service does not depend on a specific output mechanism.

Current Linux implementation:

```text
Logger
    ↓
Platform_Write()
    ↓
printf()
```

Future MCU implementation:

```text
Logger
    ↓
Platform_Write()
    ↓
UART
```

or

```text
Logger
    ↓
Platform_Write()
    ↓
USB CDC
```

Only the Platform layer changes.

The Logger API remains unchanged.

---

## Public API

Current API:

```c
void Log_Info(
    const char *format,
    ...);

void Log_Warn(
    const char *format,
    ...);

void Log_Error(
    const char *format,
    ...);
```

---

## Summary

The Logger Service provides a lightweight and portable logging mechanism for framework applications.

The service currently supports:

* Log Levels
* Structured Records
* Formatted Messages
* Platform-Independent Output

while remaining simple enough to run on Linux and embedded targets with minimal changes.
