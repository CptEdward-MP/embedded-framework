# Scheduler Service Tests

## Purpose

Verify the functionality of the Scheduler Service.

The tests validate task registration, periodic execution, and support for multiple scheduled tasks.

---

## Files

```text
tests/
└── scheduler/
    ├── main.c
    ├── CMakeLists.txt
    └── README.md
```

---

## Test Coverage

### Register Task Test

Verifies that tasks can be successfully registered.

Checks:

```text
Scheduler_RegisterTask()

Valid Task ID Returned
```

Expected Result:

```text
Task registration succeeds.
```

---

### Task Execution Test

Verifies that a registered task executes after its configured period expires.

Checks:

```text
Task Registration

Scheduler_Run()

Task Callback Execution
```

Expected Result:

```text
Task callback executes at least once.
```

---

### Multiple Tasks Test

Verifies that multiple tasks can coexist within the scheduler.

Checks:

```text
Task 1 Registration

Task 2 Registration

Independent Period Tracking

Independent Callback Execution
```

Expected Result:

```text
Both tasks execute successfully.
```

---

## Current Test Workflow

```text
Initialize Scheduler

        ↓

Register Tasks

        ↓

Run Scheduler

        ↓

Verify Callback Execution

        ↓

Report Results
```

---

## Running Tests

Build:

```bash
cd build

cmake ..

make
```

Run:

```bash
./tests/scheduler/scheduler_test
```

---

## Expected Output

```text
[INFO] Starting Scheduler Tests

[INFO] PASS: Register Task

[INFO] PASS: Task Execution

[INFO] PASS: Multiple Tasks

[INFO] Scheduler Tests Complete
```

---

## What Is Being Verified

The test suite confirms:

```text
Scheduler Initialization

Task Registration

Periodic Execution

Multiple Task Support

Scheduler and Time Service Integration
```

---

## Dependencies

Required Services:

```text
Time Service

Logger Service
```

The Scheduler Service depends on the Time Service to determine when tasks become eligible for execution.

---

## Current Limitations

The current test suite does not verify:

```text
Task Overrun Handling

Maximum Task Count

Invalid Task Registration

Future Enable/Disable Support

Future One-Shot Task Support

Future Task Statistics
```

These features are outside the scope of Scheduler Service V1.

---

## Future Improvements

Future tests may include:

```text
Task Limit Verification

Invalid Callback Handling

Task Enable/Disable

One-Shot Tasks

Execution Statistics

Overrun Detection
```

---

## Summary

The Scheduler Service Test Suite verifies the core functionality of Scheduler V1:

```text
Register Task
        ↓
Wait For Period
        ↓
Execute Callback
        ↓
Repeat
```

and serves as the regression test suite for periodic task scheduling within the framework.
