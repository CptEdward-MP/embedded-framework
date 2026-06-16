# Module Manager

## Purpose

Provide a common framework interface for registering, initializing, and updating modules.

The Module Manager allows the framework to interact with different modules through a common lifecycle interface.

---

## Current Version

Module Manager V1

---

## Module Interface

Current module structure:

```
module_t
{
    name
    init()
    update()
}
```

---

## Supported Features

* Module registration
* Module initialization
* Module update execution
* Common lifecycle interface
* Framework-independent module implementation

---

## Registration Flow

Application

```
↓
```

Module_Register()

```
↓
```

Module Registry

```
↓
```

Module_InitAll()

```
↓
```

Module_UpdateAll()

---

## Current Behavior

Modules register themselves with the Module Manager.

All registered modules are stored in a common registry.

Module_InitAll() initializes every registered module.

Module_UpdateAll() updates every registered module.

The framework only interacts with modules through their lifecycle functions.

---

## Design Principles

* The framework sees modules, not implementations.
* Modules own their internal logic.
* Module initialization logic remains inside the module.
* The framework should not contain device-specific behavior.
* Prefer extension over modification.

---

## Current Limitations

* Fixed maximum module count.
* No module priorities.
* No dependency management.
* No dynamic registration.
* No module removal.
* No module state tracking.
* No health monitoring integration.
* No scheduler integration.
* No update periods.
* No thread safety.
* All modules are initialized through Module_InitAll().
* All modules are updated through Module_UpdateAll().
* No independent initialization sequencing.
* No independent update scheduling.

---

## Future Direction

Module Manager V2:

* Module priorities
* Dependency management
* Module states
* Health integration
* Scheduler integration
* Update periods
* Independent initialization sequencing
* Independent update scheduling
* Dynamic registration support

---

## Example

Battery Module

```
Battery_Init()
Battery_Update()
```

IMU Module

```
IMU_Init()
IMU_Update()
```

Framework View

```
module->init()
module->update()
```
