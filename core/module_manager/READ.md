# Module Manager

## Purpose

Provide a common framework interface for registering, initializing, and updating module instances.

The Module Manager allows the framework to interact with different modules through a common lifecycle interface without knowing module-specific implementation details.

The Module Manager is responsible only for lifecycle management.

Module functionality remains inside individual modules.

---

## Current Version

Module Manager V1

Status: Functional

---

## Architecture

Application

↓

Module Instance

↓

Module Manager

↓

Lifecycle Callbacks

↓

Module Implementation

---

## Module Interface

Current module structure:

```c
typedef struct
{
    const char *name;

    void *context;

    void (*init)(
        void *context);

    void (*update)(
        void *context);

} module_t;
```

Purpose:

```text
name
    Human-readable module name

context
    Module instance data

init()
    Initialization callback

update()
    Periodic update callback
```

---

## Context-Based Architecture

The Module Manager does not interact directly with module implementations.

Instead, it interacts with module instances through callback functions and a context pointer.

The context pointer allows multiple independent instances of the same module type.

Example:

```text
Module Instance A
    -> Context A

Module Instance B
    -> Context B
```

Both instances may use the same implementation while maintaining independent state.

This allows the framework to support multiple instances without modifying the Module Manager.

---

## Supported Features

* Module registration
* Module initialization
* Module update execution
* Context-based module instances
* Multiple instance support
* Common lifecycle interface
* Callback-based architecture
* Framework-independent module implementation

---

## Public API

Current API:

```c
Module_Register()

Module_InitAll()

Module_UpdateAll()
```

---

## Return Codes

Module registration returns:

```c
MODULE_OK

MODULE_FULL

MODULE_NULL

MODULE_DUPLICATE

MODULE_INVALID
```

Purpose:

```text
MODULE_OK
    Registration successful

MODULE_FULL
    Registry capacity reached

MODULE_NULL
    Invalid module pointer

MODULE_DUPLICATE
    Duplicate registration

MODULE_INVALID
    Invalid module configuration
```

---

## Registration Flow

Application

↓

Module_Register()

↓

Module Registry

↓

Module_InitAll()

↓

Module_UpdateAll()

---

## Current Workflow

Application creates a module instance:

```c
module_t module_a =
{
    .name = "Module A",

    .context = &context_a,

    .init = ModuleA_Init,

    .update = ModuleA_Update
};
```

Application registers the module:

```c
Module_Register(
    &module_a);
```

Framework initializes modules:

```c
Module_InitAll();
```

Framework updates modules:

```c
Module_UpdateAll();
```

---

## Current Behavior

Applications register module instances.

All registered modules are stored in a common registry.

Module_InitAll() initializes every registered module.

Module_UpdateAll() updates every registered module.

The Module Manager interacts only with lifecycle callbacks.

The Module Manager does not contain module-specific logic.

---

## Generic Example

Module A:

```c
void ModuleA_Init(
    void *context);

void ModuleA_Update(
    void *context);
```

Module B:

```c
void ModuleB_Init(
    void *context);

void ModuleB_Update(
    void *context);
```

Framework View:

```c
module->init(
    module->context);

module->update(
    module->context);
```

The Module Manager does not know what a module does.

It only knows how to execute lifecycle callbacks.

---

## Multiple Instance Example

Contexts:

```c
context_t context_a;

context_t context_b;
```

Module Instances:

```c
module_t module_a;

module_t module_b;
```

Registration:

```c
Module_Register(
    &module_a);

Module_Register(
    &module_b);
```

The Module Manager treats both as independent modules.

---

## Dependencies

The Module Manager has no dependency on framework services.

The Module Manager depends only on:

```text
module_t

Lifecycle Callbacks
```

The Module Manager does not depend on:

```text
Logger

Platform

Storage

Communication

Any Specific Module
```

This keeps the framework core independent from module implementations.

---

## Design Principles

* The framework sees modules, not implementations.
* Modules own their internal logic.
* Modules own their internal state.
* The Module Manager owns lifecycle execution.
* The framework should not contain domain-specific behavior.
* Prefer callbacks over direct dependencies.
* Prefer extension over modification.
* Keep framework code independent from module code.
* The Module Manager is domain agnostic.

---

## Current Limitations

* Fixed maximum module count
* Static module registry
* No module priorities
* No dependency management
* No module state tracking
* No scheduler integration
* No update periods
* No module removal
* No runtime allocation support
* No thread safety
* All modules initialized through Module_InitAll()
* All modules updated through Module_UpdateAll()
* No independent initialization sequencing
* No independent update scheduling

---

## Future Direction

### Module Manager V2

* Module priorities
* Dependency management
* Module state tracking
* Scheduler integration
* Update periods
* Independent initialization sequencing
* Independent update scheduling
* Runtime allocation support

Potential future state model:

```c
MODULE_STATE_UNINITIALIZED

MODULE_STATE_INITIALIZED

MODULE_STATE_RUNNING

MODULE_STATE_ERROR
```

This would allow the framework to monitor module lifecycle and execution status.

---

## Summary

The Module Manager provides a generic lifecycle interface for framework modules.

Modules are represented as context-based instances.

The framework interacts with modules only through callbacks.

The Module Manager does not know what a module does.

This architecture allows new module types and multiple module instances to be added without modifying the Module Manager.
