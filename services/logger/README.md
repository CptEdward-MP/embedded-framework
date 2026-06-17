# Logger Service Documentation

## Purpose

The Logger Service provides a framework-wide mechanism for generating structured log records.

The logger is responsible for creating log records and distributing them to consumers.

The logger is not responsible for deciding how logs are displayed, stored, or transmitted.

---

## Current Version

Version: Logger V1

Status: Functional

---

## Architecture

Application

```
↓
```

Logger API

```
Log_Info()
Log_Warn()
Log_Error()

↓
```

log_record_t

```
↓
```

Logger Dispatch

```
↓
```

Platform Output (Temporary)

---

## Log Record Structure

Current log record:

```
timestamp
level
message
```

Example:

```
{
    .timestamp = 0,
    .level = LOG_WARN,
    .message = "Battery Low"
}
```

---

## Log Levels

Supported levels:

```
LOG_INFO
LOG_WARN
LOG_ERROR
```

---

## Current Behavior

A log record is created.

The record is immediately dispatched.

The record is displayed through Platform_Write().

The record is then destroyed.

No persistent storage exists.

---

## Current Limitations

* No log storage.
* No log history.
* No ring buffer.
* No real timestamps.
* No filtering.
* No multiple consumers.
* No thread safety.
* No dynamic consumer registration.

---

## Sink Interface

Current sink interface:

```
typedef struct
{
    void (*consume)(const log_record_t *record);
} log_sink_t;
```

Purpose:

```
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
* Platform-independent output path
* Consumer extension point

Avoid:

* Storage systems
* Complex formatting
* Dynamic infrastructure
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
* Public APIs remain stable.
* Prefer extension over modification.
* Keep abstractions minimal.

---

## Dependencies

Current dependencies:

Platform Service

Required platform functions:

Platform_Write()


---

## Public API

Current API:

Log_Info()

Log_Warn()

Log_Error()


---