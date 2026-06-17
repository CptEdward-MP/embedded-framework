# LiPo Battery Module

## Purpose

Provide LiPo battery monitoring capabilities to the framework.

The module acquires battery voltage, calculates per-cell voltage, classifies battery condition, and provides battery status information to the application layer.

---

## Current Version

LiPo Battery V1

---

## Supported Features

* Configurable cell count
* Configurable ADC channel
* Multiple battery instance support
* Voltage acquisition through Platform ADC
* Per-cell voltage calculation
* Battery status classification
* Low battery detection
* Logger integration
* Module Manager integration

---

## Configuration

Current configuration:

```c
cell_count
adc_channel
```

Example:

```c
LipoBattery_Configure(
    &main_battery,
    3,
    0);
```

Meaning:

```text
3S LiPo Battery
ADC Channel 0
```

---

## Data Model

Current battery data:

```c
voltage
cell_voltage
status
```

Example:

```text
Voltage      = 10.5V
Cell Voltage = 3.5V
Status       = LIPO_STATUS_LOW
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

Current thresholds:

```text
>= 3.80V  -> OK

>= 3.75V  -> WARNING

>= 3.60V  -> LOW

<  3.60V  -> CRITICAL
```

Example:

```text
Cell Voltage = 3.85V

Status = LIPO_STATUS_OK
```

Example:

```text
Cell Voltage = 3.72V

Status = LIPO_STATUS_LOW
```

---

## Current Workflow

```text
Platform_ADC_Read()

        ↓

Battery Voltage

        ↓

Cell Voltage Calculation

        ↓

Battery Status Classification

        ↓

Logger / Application Layer
```

---

## Using Battery Data

Applications can retrieve the latest battery information:

```c
lipo_battery_data_t data =
    LipoBattery_GetData(
        &main_battery);
```

Access voltage:

```c
float voltage =
    data.voltage;

float cell_voltage =
    data.cell_voltage;
```

---

## Using Battery Status

Applications can react to battery condition:

```c
lipo_battery_data_t data =
    LipoBattery_GetData(
        &main_battery);

switch (data.status)
{
    case LIPO_STATUS_OK:
        break;

    case LIPO_STATUS_WARNING:
        break;

    case LIPO_STATUS_LOW:
        break;

    case LIPO_STATUS_CRITICAL:
        break;
}
```

Example actions:

```text
WARNING
    Notify operator

LOW
    Reduce system load

CRITICAL
    Enter safe shutdown state
```

The battery module reports battery condition.

The application decides how to react.

---

## Example Usage

```c
lipo_battery_t main_battery;

LipoBattery_Configure(
    &main_battery,
    3,
    0);

LipoBattery_Init(
    &main_battery);

LipoBattery_Update(
    &main_battery);

lipo_battery_data_t data =
    LipoBattery_GetData(
        &main_battery);
```

---

## Platform Dependency

The module depends only on:

```c
Platform_ADC_Read()
```

The module does not depend on any platform-specific implementation.

Supported platforms provide their own ADC implementation.

Example:

```text
Linux
    -> Mock ADC

STM32
    -> HAL ADC

ESP32
    -> ESP-IDF ADC
```

---

## Module Dependencies

Current dependencies:

```text
Platform Service
Logger Service
```

Required platform functions:

```c
Platform_ADC_Read()
```

Used logger functions:

```c
Log_Info()

Log_Warn()

Log_Error()
```

---

## Outputs

The module provides:

```text
Battery Voltage

Cell Voltage

Battery Status

Diagnostic Messages
```

Applications can consume these outputs for:

```text
System Protection

Telemetry

Logging

Displays

Data Storage
```

---

## Current Limitations

* Mock ADC source on Linux
* No automatic cell count detection
* No battery chemistry selection
* No current measurement
* No temperature monitoring
* No state-of-charge estimation
* No battery health estimation
* No charge/discharge tracking
* No balancing information
* No event notification system
* No status transition tracking

---

## Design Principles

* Battery logic remains inside the battery module.
* Applications consume battery information.
* Platform provides hardware access.
* Logger provides reporting.
* Battery status is application-independent.
* Multiple battery instances are supported.
* Platform-specific code remains outside the module.

---

## Future Direction

### LiPo Battery V2

* Automatic cell count detection
* ADC calibration support
* State-of-charge estimation
* Temperature monitoring
* Battery health estimation
* Charge/discharge tracking
* Configurable warning thresholds
* Battery event notifications
* Status transition tracking

Example:

```text
OK
    ↓
WARNING
    ↓
LOW
    ↓
CRITICAL
```

Applications will be able to react to battery state transitions rather than continuously polling battery status.

---

## Inputs

```text
Cell Count

ADC Channel

Platform ADC Reading
```

---

## Outputs

```text
Battery Voltage

Cell Voltage

Battery Status

Battery Events

Diagnostic Messages
```
