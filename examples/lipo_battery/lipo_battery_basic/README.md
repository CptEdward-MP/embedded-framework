# LiPo Battery Basic Example

## Purpose

Demonstrate basic usage of the LiPo Battery Module.

The example shows how to:

* Configure a battery instance
* Initialize the battery module
* Update battery measurements
* Retrieve battery data
* Access battery status information

---

## Files

```text
examples/
└── lipo_battery/
    └── lipo_battery_basic/
        ├── main.c
        ├── CMakeLists.txt
        └── README.md
```

---

## Concepts Demonstrated

The example demonstrates the complete battery workflow:

```text
Configure Battery
        ↓
Initialize Battery
        ↓
Update Measurements
        ↓
Retrieve Battery Data
        ↓
Display Results
```

---

## Battery Configuration

A battery instance is first configured:

```c
lipo_battery_t battery;

LipoBattery_Configure(
    &battery,
    3,
    0);
```

Configuration parameters:

```text
Cell Count  = 3
ADC Channel = 0
```

Meaning:

```text
3S LiPo Battery
ADC Channel 0
```

---

## Battery Initialization

The battery module is initialized:

```c
LipoBattery_Init(
    &battery);
```

Initialization prepares the battery instance for operation.

---

## Battery Update

Battery measurements are acquired:

```c
LipoBattery_Update(
    &battery);
```

The module performs:

```text
ADC Read
    ↓
Voltage Calculation
    ↓
Cell Voltage Calculation
    ↓
Status Classification
```

---

## Retrieving Battery Data

Latest battery information can be retrieved using:

```c
lipo_battery_data_t data =
    LipoBattery_GetData(
        &battery);
```

Available data:

```text
Voltage
Cell Voltage
Status
```

---

## Battery Status

The battery module classifies battery condition into one of the following states:

```c
LIPO_STATUS_OK

LIPO_STATUS_WARNING

LIPO_STATUS_LOW

LIPO_STATUS_CRITICAL
```

Applications can use the status field to make decisions without needing to interpret raw voltage values.

---

## Example Output

Example output from the Linux platform:

```text
[INFO] Battery Example Started
[INFO] LiPo Battery Initialized
[INFO] Voltage = 13.50V, Cell Voltage = 4.50V, Status = OK
```

Actual values depend on the platform ADC implementation.

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
./examples/lipo_battery/lipo_battery_basic/lipo_battery_basic
```

---

## Platform Dependency

The example relies on:

```c
Platform_ADC_Read()
```

The platform implementation provides the ADC reading source.

Examples:

```text
Linux
    -> Mock ADC

STM32
    -> HAL ADC

ESP32
    -> ESP-IDF ADC
```

---

## Learning Objective

This example demonstrates how applications can interact with the LiPo Battery Module through a simple API.

Applications do not need to:

```text
Read ADC hardware directly

Calculate cell voltage manually

Determine battery status manually
```

The battery module handles these responsibilities internally and provides a simplified interface to the application.

---

## Related Components

```text
LiPo Battery Module
Logger Service
Platform Service
```

---

## Summary

The LiPo Battery Basic Example demonstrates the complete battery monitoring workflow:

```text
Configure
    ↓
Initialize
    ↓
Update
    ↓
Get Data
    ↓
Use Status Information
```

using the LiPo Battery Module API.
