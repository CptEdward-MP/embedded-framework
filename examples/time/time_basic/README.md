# Time Service

## Purpose

Provide a platform-independent time source to the framework.

The Time Service allows framework components to retrieve the current system time without depending on platform-specific APIs.

---

## Current Version

Time Service V1

---

## Supported Features

* Millisecond timestamp retrieval
* Platform-independent API
* Linux support
* Target MCU support
* Scheduler integration
* Timeout support
* Execution timing support

---

## Public API

```c
uint32_t Time_GetMs(void);
```

---

## Current Workflow

```text
Application
      ↓

Time_GetMs()

      ↓

Platform_Time_GetMs()

      ↓

Target Platform
```

---

## Example Usage

```c
uint32_t now =
    Time_GetMs();
```

---

## Measuring Elapsed Time

```c
uint32_t start =
    Time_GetMs();

/* Work */

uint32_t elapsed =
    Time_GetMs() - start;
```

---

## Periodic Execution

```c
static uint32_t last_run = 0;

if ((Time_GetMs() - last_run) >= 100)
{
    Update_Task();

    last_run =
        Time_GetMs();
}
```

This pattern is the foundation of the Scheduler Service.

---

## Platform Dependency

The Time Service depends only on:

```c
Platform_Time_GetMs();
```

---

## Linux Implementation

Current Linux implementation uses:

```c
gettimeofday()
```

to obtain the current time and convert it into milliseconds.

---

## Design Principles

* Platform-independent
* Lightweight
* No dynamic allocation
* No timer management
* No delays
* No scheduling logic
* Single responsibility

The Time Service answers only one question:

```text
What time is it?
```

---

## Relationship With Scheduler

```text
Scheduler
      ↓
Time_GetMs()
      ↓
Platform Time Source
```

The Scheduler uses timestamps from the Time Service to determine when tasks should execute.

---

## Current Limitations

* Millisecond resolution only
* No microsecond support
* No timeout helpers
* No timer objects
* No stopwatch utilities

---

## Future Direction

### Time Service V2

Possible additions:

```c
uint64_t Time_GetUs(void);
```

```c
bool Time_IsExpired(
    uint32_t start,
    uint32_t timeout_ms);
```

These features will only be added when required.

---

## Inputs

```text
Platform Time Source
```

---

## Outputs

```text
Current Time (Milliseconds)
```

---

## Related Components

```text
Platform Service
Scheduler Service
Event Service
Health Monitor
Telemetry
```

---

## Summary

The Time Service provides a simple platform-independent time source.

```text
Time_GetMs()
      ↓
Platform_Time_GetMs()
      ↓
Platform Implementation
```

It serves as the timing foundation for schedulers, timeouts, diagnostics, and future framework components.
