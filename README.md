# Embedded Framework

A lightweight embedded software framework focused on modular architecture, portability, and reusable components.

The project is designed as a learning platform for exploring embedded software architecture concepts commonly used in real-world firmware systems.

The framework emphasizes:

* Platform abstraction
* Modular design
* Service-oriented architecture
* Documentation-first development
* Testability
* Reusability

---

# Current Status

Version: Early Development

Implemented Components:

* Module Manager
* Logger Service
* Event Service
* LiPo Battery Module
* Linux Platform Layer
* POSIX OSAL

---

# Architecture

Application Layer

↓

Framework Core

* Module Manager

↓

Framework Services

* Logger
* Event Service

↓

Framework Modules

* LiPo Battery

↓

Platform Layer

* Linux Platform

↓

Operating System

* POSIX

---

# Project Structure

```text
apps/
    Example applications

core/
    Core framework infrastructure

modules/
    Reusable framework modules

services/
    Framework services

platform/
    Platform abstraction layer

osal/
    Operating system abstraction layer

examples/
    Usage examples

tests/
    Unit and integration tests

docs/
    Design and architecture documents
```

---

# Design Principles

## Platform Independence

Modules should not directly access platform-specific functionality.

Hardware access is performed through the Platform Layer.

---

## Separation of Responsibilities

Modules own functionality.

Services provide shared infrastructure.

Applications define system behavior.

---

## Static Allocation

Current implementations prefer static allocation over dynamic memory allocation.

---

## Documentation First

Every framework component should provide:

* Documentation
* Example
* Test

before being considered complete.

---

# Implemented Components

## Module Manager

Provides:

* Module registration
* Module initialization
* Module update execution

---

## Logger Service

Provides:

* Structured logging
* Log levels
* Platform-independent output

---

## Event Service

Provides:

* Event publication
* Event subscription
* Callback dispatching

---

## LiPo Battery Module

Provides:

* Battery voltage monitoring
* Cell voltage calculation
* Battery status monitoring

---

# Building

```bash
mkdir build

cd build

cmake ..

make
```

---

# Running Applications

Health Monitor Application:

```bash
./health_monitor
```

---

# Running Examples

Event Service Example:

```bash
./examples/event_basic/event_basic
```

---

# Current Goals

* Expand framework modules
* Improve service infrastructure
* Add automated testing
* Improve portability
* Explore RTOS integration
* Build realistic embedded applications

---

# Future Roadmap

## Framework V1

* Module Manager
* Logger Service
* Event Service
* Battery Module
* Documentation
* Examples
* Tests

## Framework V2

* Scheduler Service
* Health Monitoring Service
* Configuration Service
* Telemetry Service
* RTOS Integration

---

# Motivation

The goal of this project is to learn and demonstrate embedded software architecture by building reusable framework components that can be used across different applications and platforms.
