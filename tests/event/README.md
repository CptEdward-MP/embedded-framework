# Event Service Tests

## Purpose

Verify the correctness of the Event Service implementation.

The tests validate event subscription, event publication, and error handling behavior.

The goal is to ensure the Event Service behaves as expected before integration into applications and framework modules.

---

## Current Version

Event Service Test Suite V1

---

## Test Structure

```text
tests/
└── event/
    ├── main.c
    ├── CMakeLists.txt
    └── README.md
```

---

## Build

From the project root:

```bash
mkdir build

cd build

cmake ..

make
```

---

## Run

From the build directory:

```bash
./tests/event/event_test
```

Expected output:

```text
[INFO] Starting Event Tests
[INFO] PASS: Subscribe Success
[INFO] PASS: Duplicate Detection
[INFO] PASS: NULL Callback
[INFO] PASS: Publish Event
[INFO] Event Tests Complete
```

---

## Implemented Test Cases

### Subscribe Success

Purpose:

Verify that a valid subscription can be registered successfully.

Checks:

* Valid event identifier
* Valid callback
* Successful registration

Expected Result:

```text
EVENT_OK
```

---

### Duplicate Detection

Purpose:

Verify that duplicate subscriptions are rejected.

Checks:

* Same event identifier
* Same callback

Expected Result:

```text
EVENT_DUPLICATE
```

---

### NULL Callback

Purpose:

Verify that invalid callback registration is rejected.

Checks:

* NULL callback pointer

Expected Result:

```text
EVENT_NULL
```

---

### Publish Event

Purpose:

Verify that event publication dispatches registered callbacks.

Checks:

* Callback execution
* Notification count

Expected Result:

```text
Callback executed once
Notified count = 1
```

---

## Current Coverage

The current test suite verifies:

* Event subscription
* Duplicate detection
* Invalid callback handling
* Event dispatch
* Subscriber notification count

---

## Current Limitations

The test suite currently does not verify:

* Maximum subscription count
* Multiple subscribers
* Multiple event identifiers
* NULL event publication
* Registry reset behavior
* Stress testing

---

## Future Test Cases

Planned additions:

### Registry Full

Verify behavior when the subscription registry reaches maximum capacity.

---

### Multiple Subscribers

Verify that multiple subscribers receive the same event.

---

### Multiple Event Types

Verify that only matching subscribers receive an event.

---

### Invalid Event Publication

Verify behavior when publishing invalid events.

---

### Stress Testing

Verify behavior under large numbers of publications and subscriptions.

---

## Design Principles

* Tests should remain independent.
* Tests should be deterministic.
* Tests should be easy to execute.
* Tests should not require application code.
* Tests should validate framework behavior only.

---

## Summary

The Event Service Test Suite validates the core functionality of the Event Service and provides a foundation for future regression testing as the framework evolves.
