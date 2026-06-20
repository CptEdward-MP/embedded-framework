# Scheduler Basic Example

## Purpose

Demonstrate periodic task execution using the Scheduler Service.

This example registers two tasks with different execution periods and allows the scheduler to execute them automatically.

---

## Demonstrated Features

* Scheduler initialization
* Task registration
* Multiple task periods
* Callback execution
* Time Service integration

---

## Example Tasks

Task 1:

```text
100 ms Task
```

Period:

```text
100 ms
```

Task 2:

```text
500 ms Task
```

Period:

```text
500 ms
```

---

## Example Workflow

```text
Scheduler_Init()

        ↓

Register 100 ms Task

        ↓

Register 500 ms Task

        ↓

Run Scheduler Forever
```

---

## Example Code

```c
Scheduler_RegisterTask(
    Task_100ms,
    NULL,
    100);

Scheduler_RegisterTask(
    Task_500ms,
    NULL,
    500);
```

---

## Execution Timeline

```text
100 ms
    Task_100ms

200 ms
    Task_100ms

300 ms
    Task_100ms

400 ms
    Task_100ms

500 ms
    Task_100ms
    Task_500ms
```

---

## Running The Example

Build:

```bash
cd build

cmake ..

make
```

Run:

```bash
./examples/scheduler/scheduler_basic/scheduler_basic
```

---

## Expected Output

```text
[INFO] Scheduler Example Started

[INFO] 100 ms Task

[INFO] 100 ms Task

[INFO] 100 ms Task

[INFO] 100 ms Task

[INFO] 100 ms Task

[INFO] 500 ms Task
```

The 100 ms task executes five times for every execution of the 500 ms task.

---

## What This Example Demonstrates

The example demonstrates that:

```text
Tasks execute periodically

Tasks execute independently

No blocking delays are required

Time Service drives scheduling
```

---

## Related Components

```text
Scheduler Service

Time Service

Logger Service
```

---

## Summary

This example demonstrates how the Scheduler Service can be used to execute multiple tasks at different periodic rates without using blocking delays.
