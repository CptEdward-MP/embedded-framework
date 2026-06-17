# Event Service

## Purpose

Provide a lightweight framework-wide mechanism for publishing and subscribing to events.

The Event Service allows independent components to communicate without direct knowledge of each other.

The service provides event dispatching infrastructure only.

The framework does not define event meanings or callback behavior.

---

## Current Version

Event Service V1

---

## Architecture

Publisher

↓

Event_Publish()

↓

Event Service

↓

Subscriber Registry

↓

Registered Callbacks

---

## Design Principles

* Application owns event definitions.
* Framework owns event infrastructure.
* Publishers do not know subscribers.
* Subscribers do not know publishers.
* Events are optional.
* Components remain loosely coupled.
* Prefer static allocation over dynamic allocation.

---

## Event Ownership

The framework does not define event identifiers.

Applications define their own events.

Example:

```c
typedef enum
{
    EVENT_BUTTON_PRESSED = 1,

    EVENT_BATTERY_LOW,

    EVENT_IMU_FAULT

} app_event_t;
```

---

## Event Model

Current event object:

```c
typedef struct
{
    event_id_t id;

} event_t;
```

Current Version:

* Event ID only
* No payload support
* No dynamic memory

---

## Callback Interface

Current callback interface:

```c
typedef void (*event_callback_t)(
    const event_t *event,
    void *context);
```

Purpose:

* Receive event notification
* Access event information
* Access subscriber context

---

## Subscription Flow

Application

↓

Event_Subscribe()

↓

Subscriber Registry

↓

Callback Stored

---

## Publish Flow

Publisher

↓

Event_Publish()

↓

Event Service

↓

Subscriber Lookup

↓

Callback Execution

---

## Supported Features

* Event subscription
* Event publication
* Multiple subscribers per event
* Context-based callbacks
* Duplicate subscription detection
* Static allocation
* Synchronous dispatch

---

## Current Behavior

When an event is published:

1. Event Service searches all registered subscriptions.
2. Matching subscribers are identified.
3. Registered callbacks are executed immediately.
4. Publish returns the number of subscribers notified.

Example:

```c
event_t event =
{
    .id = EVENT_BUTTON_PRESSED
};

int notified =
    Event_Publish(
        &event);
```

---

## Return Codes

Subscription return codes:

```c
EVENT_OK
EVENT_FULL
EVENT_NULL
EVENT_DUPLICATE
```

Publish return value:

```c
0
```

No subscribers notified.

```c
N
```

N subscribers notified.

---

## Current Limitations

* Fixed maximum subscription count.
* No unsubscribe support.
* No event payload support.
* No event priorities.
* No event filtering.
* No event queues.
* No asynchronous dispatch.
* No thread safety.
* No event history.
* No persistence.

---

## Example

Subscribe:

```c
Event_Subscribe(
    EVENT_BUTTON_PRESSED,
    ButtonHandler,
    NULL);
```

Publish:

```c
event_t event =
{
    .id = EVENT_BUTTON_PRESSED
};

Event_Publish(
    &event);
```

Result:

```text
Button Event Received
```

---

## Current Use Cases

* Module notifications
* System status changes
* Diagnostics integration
* User interface notifications
* Fault reporting
* State change notification

---

## Future Direction

Event Service V2

* Event payload support
* Event unsubscription
* Event priorities
* Event queues
* Asynchronous dispatch
* Event filtering
* Thread safety
* Dynamic subscription management

---

## Framework Responsibilities

The Event Service is responsible for:

* Storing subscriptions
* Matching event identifiers
* Dispatching callbacks

The Event Service is not responsible for:

* Defining events
* Event semantics
* Application behavior
* Event handling policies

---

## Summary

The Event Service provides a lightweight callback-based communication mechanism that allows independent framework components to exchange notifications while remaining loosely coupled.
