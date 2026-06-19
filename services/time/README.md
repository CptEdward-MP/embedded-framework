# Time Service

## Purpose

Provide a platform-independent time source to the framework.

The Time Service allows modules and services to retrieve the current system time without directly accessing platform-specific APIs.

---

## Current Version

Time Service V1

---

## Supported Features

* Millisecond timestamp retrieval
* Platform-independent API
* Linux support
* STM32 support (future)
* Scheduler integration
* Timeout handling support
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

Linux / STM32 / ESP32
```

---

## Example Usage

```c
uint32_t now =
    Time_GetMs();
```

---

## Measuring Elapsed Time

Example:

```c
uint32_t start =
    Time_GetMs();

/* Do work */

uint32_t end =
    Time_GetMs();

uint32_t elapsed =
    end - start;
```

---

## Periodic Execution

Example:

```c
static uint32_t last_run = 0;

if ((Time_GetMs() - last_run) >= 100)
{
    Update_Task();

    last_run =
        Time_GetMs();
}
```

This pattern is the foundation for the Scheduler Service.

---

## Platform Dependency

The Time Service depends only on:

```c
Platform_Time_GetMs()
```

---

## Linux Implementation

Current Linux implementation uses:

```c
clock_gettime(
    CLOCK_MONOTONIC,
    &ts);
```

The timestamp is converted into milliseconds.

Example:

```c
uint32_t Platform_Time_GetMs(void)
{
    struct timespec ts;

    clock_gettime(
        CLOCK_MONOTONIC,
        &ts);

    return
        (uint32_t)(
            ts.tv_sec * 1000U +
            ts.tv_nsec / 1000000U);
}
```

---

## Future STM32 Implementation

Example:

```c
uint32_t Platform_Time_GetMs(void)
{
    return HAL_GetTick();
}
```

No changes are required in the Time Service.

---

## Design Principles

* Platform-independent
* Lightweight
* No dynamic allocation
* No timer management
* No delays
* No scheduling logic
* Single responsibility

The Time Service only answers:

```text
"What time is it?"
```

---

## Relationship With Scheduler

The Time Service provides the foundation for the Scheduler Service.

Example:

```text
Scheduler
      ↓
Time_GetMs()
      ↓
Platform Time Source
```

The scheduler uses timestamps provided by the Time Service to determine when tasks should execute.

---

## Current Limitations

* Millisecond resolution only
* No microsecond support
* No timer objects
* No timeout helpers
* No stopwatch utilities

---

## Future Direction

### Time Service V2

Possible additions:

```c
uint64_t Time_GetUs(void);
```

```c
uint32_t Time_GetElapsedMs(
    uint32_t start);
```

```c
bool Time_IsExpired(
    uint32_t start,
    uint32_t timeout_ms);
```

These features will only be added when required by framework components.

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

The Time Service provides a simple platform-independent interface for retrieving system time.

```text
Time_GetMs()
        ↓
Platform_Time_GetMs()
        ↓
Hardware / OS Time Source
```

It serves as the timing foundation for future framework components such as schedulers, timeouts, diagnostics, and performance measurements.
