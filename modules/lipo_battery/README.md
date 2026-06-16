# LiPo Battery Module

## Purpose

Provide LiPo battery monitoring capabilities to the framework.

The module acquires battery voltage, calculates per-cell voltage, and detects low-battery conditions.

---

## Current Version

LiPo Battery V1

---

## Supported Features

* Configurable cell count
* Configurable ADC channel
* Voltage acquisition through Platform ADC
* Per-cell voltage calculation
* Low battery detection
* Logger integration

---

## Configuration

Current configuration:

```
cell_count
adc_channel
```

Example:

```
LipoBattery_Configure(3, 0);
```

Meaning:

```
3S LiPo Battery
ADC Channel 0
```

---

## Data Model

Current battery data:

```
voltage
cell_voltage
```

Example:

```
Voltage      = 10.5V
Cell Voltage = 3.5V
```

---

## Current Workflow

Platform_ADC_Read()

```
↓
```

Battery Voltage

```
↓
```

Cell Voltage Calculation

```
↓
```

Threshold Check

```
↓
```

Logger

---

## Low Battery Detection

Current threshold:

```
3.7V per cell
```

Example:

```
Total Voltage = 10.5V
Cell Count    = 3

Cell Voltage = 3.5V
```

Result:

```
Log_Error("LiPo Battery Low")
```

---

## Platform Dependency

The module depends only on:

```
Platform_ADC_Read()
```

The module does not depend on any platform-specific implementation.

Supported platforms provide their own ADC implementation.

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
* No module manager integration

---

## Design Principles

* Battery logic remains inside the battery module.
* The framework remains battery-agnostic.
* Platform provides hardware access.
* Logger provides reporting.
* Module configuration remains module-specific.

---

## Future Direction

LiPo Battery V2

* Module Manager integration
* Automatic cell count detection
* ADC calibration support
* State-of-charge estimation
* Temperature monitoring
* Battery health estimation
* Charge/discharge tracking
* Configurable warning thresholds

---

## Inputs

* Cell Count
* ADC Channel
* Platform ADC Reading

---

## Outputs

* Battery Voltage
* Cell Voltage
* Low Battery Events
* Log Messages

