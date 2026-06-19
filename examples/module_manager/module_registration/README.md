# Module Registration Example

## Purpose

Demonstrate basic Module Manager usage.

The example shows how modules can be registered, initialized, and updated through a common framework interface.

---

## Concepts Demonstrated

* Module creation
* Module registration
* Module initialization
* Module update execution

---

## Files

```text
examples/
└── module_manager/
    └── module_registration/
        ├── main.c
        ├── CMakeLists.txt
        └── README.md
```

---

## Module Definition

A framework module is represented by:

```c
module_t
{
    name,
    context,
    init,
    update
}
```

Each module provides lifecycle functions that can be managed by the Module Manager.

---

## Example Workflow

Create Module

↓

Register Module

↓

Initialize All Modules

↓

Update All Modules

---

## Example Modules

The example creates two independent modules:

```text
Module A
Module B
```

Each module implements:

```text
Init Function
Update Function
```

---

## Registration

Modules are registered using:

```c
Module_Register(
    &module_a);

Module_Register(
    &module_b);
```

The Module Manager stores the modules in its internal registry.

---

## Initialization

All registered modules are initialized using:

```c
Module_InitAll();
```

The Module Manager executes:

```text
module_a.init()

module_b.init()
```

---

## Update

All registered modules are updated using:

```c
Module_UpdateAll();
```

The Module Manager executes:

```text
module_a.update()

module_b.update()
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
./examples/module_manager/module_registration/module_registration
```

---

## Expected Output

```text
[INFO] Module A Init
[INFO] Module B Init

[INFO] Module A Update
[INFO] Module B Update
```

---

## Learning Objective

This example demonstrates how the Module Manager interacts with modules through a common lifecycle interface.

The Module Manager does not need to know the implementation details of a module.

It only requires:

```text
init()

update()
```

This allows different modules to be managed through a common framework API.

---

## Related Components

* Module Manager
* Logger Service

---

## Summary

The Module Registration Example demonstrates the complete lifecycle of framework modules:

```text
Create
    ↓
Register
    ↓
Initialize
    ↓
Update
```

using the Module Manager's common interface.
