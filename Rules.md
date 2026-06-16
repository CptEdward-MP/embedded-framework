# Embedded Framework Rules

## Rule 1: Single Responsibility

* Each component should have one primary responsibility.
* Example: Logger creates logs; consumers handle logs.

## Rule 2: Use Framework APIs

* Applications should use framework interfaces, not implementation details.
* Example: Use `Log_Info()` instead of `printf()`.

## Rule 3: OS Abstraction

* OS-specific APIs must remain inside OSAL.
* Example: Use `OS_SleepMs()` instead of `sleep()`.

## Rule 4: Platform Abstraction

* Platform-specific APIs must remain inside Platform.
* Example: Use `Platform_Write()` instead of `printf()`.

## Rule 5: Separate Data from Representation

* Data structures are the source of truth; displays are representations.
* Example: `log_record_t` is data, terminal output is a representation.

## Rule 6: Logger Creates Records

* The logger creates and distributes log records.
* Example: `Log_Info()` produces a `log_record_t`.

## Rule 7: Consumers Own Behavior

* Consumers decide how data is used.
* Example: Print, store, transmit, or ignore a log record.

## Rule 8: Stable Public APIs

* Public interfaces should remain stable as implementations evolve.
* Example: `Log_Info()` should work regardless of logging backend.

## Rule 9: Extend Before Modifying

* Prefer adding new components over changing existing ones.
* Example: Add a new consumer instead of changing the logger.

## Rule 10: Minimize Contributor Impact

* New features should require changes to as few files as possible.
* Example: A new module should not require core modifications.

## Rule 11: Prevent Platform Leakage

* Applications must not know platform details.
* Example: Applications should not know about Linux or STM32 APIs.

## Rule 12: Prevent OS Leakage

* Applications must not know OS details.
* Example: Applications should not use POSIX or FreeRTOS APIs directly.

## Rule 13: Framework Code Stays in Framework

* Reusable functionality belongs in framework layers.
* Example: Shared logic should not live in `apps/`.

## Rule 14: Design for Extension

* Create extension points instead of predicting future requirements.
* Example: Add interfaces, not speculative features.

## Rule 15: Depend on Interfaces

* Components should depend on abstractions, not implementations.
* Example: Depend on `module_t`, not a specific module source file.

## Rule 16: Keep Abstractions Minimal

* Introduce abstractions only when they solve a real problem.
* Example: Avoid wrapping functionality with a single implementation.

## Rule 17: Respect Layer Responsibilities

* Every layer must have a clear purpose.
* Example: Apps solve problems; services provide capabilities.

## Rule 18: Core Owns Infrastructure

* Core contains framework infrastructure only.
* Example: Module Manager belongs in `core/`.

## Rule 19: Services Provide Capabilities

* Services offer reusable functionality across applications.
* Example: Logger, Diagnostics, Telemetry.

## Rule 20: Modules Represent Features

* Modules encapsulate devices or functional units.
* Example: Battery, IMU, OLED, Motor.

## Rule 21: Abstract Multiple Implementations

* Create an abstraction when multiple implementations are expected.
* Example: `OS_SleepMs()` supports POSIX, FreeRTOS, and future OSes.


