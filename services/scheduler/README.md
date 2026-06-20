# Scheduler Service

## Purpose

Provide periodic task execution for the framework.

The Scheduler Service allows applications to register tasks that execute at fixed time intervals without using blocking delays.

---

## Current Version

Scheduler Service V1

---

## Supported Features

* Fixed-size task storage
* Static task registration
* Periodic task execution
* Callback + Context architecture
* Time Service integration
* Platform-independent design
* No dynamic memory allocation

---

## Dependencies

Required Services:

```text
Time Service
```

Required API:

```c
uint32_t Time_GetMs(void);
```

The Scheduler Service uses the Time Service as its timing source.

---

## Public API

```c
void Scheduler_Init(void);
```

```c
uint8_t Scheduler_RegisterTask(
    scheduler_callback_t callback,
    void *context,
    uint32_t period_ms);
```

```c
void Scheduler_Run(void);
```

---

## Task Model

Each task contains:

```c
Callback Function

Context Pointer

Period

Last Execution Time
```

Example:

```c
Scheduler_RegisterTask(
    IMU_Update,
    &imu,
    10);
```

Meaning:

```text
Run IMU_Update every 10 ms
```

---

## Current Workflow

```text
Register Task

        ↓

Wait For Period

        ↓

Execute Callback

        ↓

Update Execution Time

        ↓

Wait For Next Period
```

---

## Periodic Execution

Example:

```text
Period = 100 ms
```

Execution timeline:

```text
Register

t = 100 ms

t = 200 ms

t = 300 ms

t = 400 ms

...
```

Tasks do not execute immediately after registration.

Tasks become eligible only after their configured period has elapsed.

---

## Scheduler Loop

Applications typically run:

```c
while (1)
{
    Scheduler_Run();
}
```

The scheduler checks all registered tasks and executes those whose periods have expired.

---

## Design Principles

* Platform-independent
* Cooperative execution
* No dynamic allocation
* No task priorities
* No context switching
* No task suspension
* No task deletion

The Scheduler Service decides:

```text
When a task may run
```

The Scheduler Service does not decide:

```text
What a task does
```

---

## Relationship With Time Service

```text
Scheduler
      ↓
Time Service
      ↓
Platform Time Source
```

The Scheduler Service relies entirely on the Time Service for timing information.

---

## Current Limitations

* Fixed task count
* No priorities
* No enable/disable support
* No one-shot tasks
* No task statistics
* No overrun detection
* No task removal

---

## Future Direction

### Scheduler V2

Possible additions:

* Task enable/disable
* One-shot tasks
* Task statistics
* Execution counters
* Overrun detection
* Task diagnostics

---

## Inputs

```text
Registered Tasks

Task Periods

Current Time
```

---

## Outputs

```text
Periodic Task Execution
```

---

## Summary

The Scheduler Service provides periodic task execution using the Time Service.

```text
Application
      ↓

Scheduler

      ↓

Task Callbacks
```

It serves as the foundation for non-blocking embedded applications and helps eliminate timing-related delays from application code.
