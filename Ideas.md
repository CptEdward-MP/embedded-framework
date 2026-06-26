
# Ideas and Problems to Solve

## Logging

- Logging should consume as little CPU time and RAM as possible.
- Logs should be usable not only for debugging but also by the application to make decisions.
- The logging backend should be replaceable (UART, USB CDC, file, memory, network, etc.) without changing application code.

---

## Drivers

- Drivers should be reusable across different applications.
- Driver APIs should remain stable even if the internal implementation changes.
- Drivers should isolate hardware-specific code from the application.
- Drivers should be easy to simulate without requiring physical hardware.

---

## Platform

- The same application should compile for Linux simulation and an MCU with minimal or no changes.
- Platform-specific code should remain isolated from business logic.

---

## Scheduling

- Periodic tasks should be easy to register and maintain.
- The application should not repeatedly implement timing logic.
- The scheduler should remain lightweight and deterministic.

---

## Modules

- Modules should own only their specific responsibility.
- Modules should not know about the application using them.
- Modules should communicate through well-defined interfaces.

---

## Simulation

- Most application logic should be testable without hardware.
- Fake drivers should behave similarly to real hardware.
- Simulation should help catch integration issues before deployment.

---

## Application Development

- Starting a new embedded project should require minimal boilerplate.
- The developer should focus on application logic rather than infrastructure.
- Common infrastructure should already exist.

---

## Long-Term Goal

Build a framework that removes repetitive embedded software infrastructure so developers can focus on solving application-specific problems.