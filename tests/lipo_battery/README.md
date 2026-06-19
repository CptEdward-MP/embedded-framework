# LiPo Battery Tests

## Purpose

Verify the functionality of the LiPo Battery Module.

The tests validate:

* Battery configuration
* Battery initialization
* Battery update operation
* Battery data retrieval
* Battery status classification

---

## Files

```text
tests/
└── lipo_battery/
    ├── main.c
    ├── CMakeLists.txt
    └── README.md
```

---

## Test Coverage

### Configure Test

Verifies that battery configuration parameters are stored correctly.

Checks:

```text
Cell Count
ADC Channel
```

Example:

```c
LipoBattery_Configure(
    &battery,
    3,
    0);
```

Expected:

```text
cell_count = 3
adc_channel = 0
```

---

### Init Test

Verifies that the battery module initializes successfully.

Checks:

```text
Initialization path executes successfully
```

---

### Update Test

Verifies that the battery module acquires battery measurements.

Checks:

```text
Voltage acquisition
Cell voltage calculation
Status update
```

Example:

```c
LipoBattery_Update(
    &battery);
```

---

### GetData Test

Verifies that battery data can be retrieved through the public API.

Checks:

```text
Voltage retrieval
Status retrieval
```

Example:

```c
lipo_battery_data_t data =
    LipoBattery_GetData(
        &battery);
```

---

### Status Test

Verifies that battery status classification is performed correctly.

Current Linux mock platform returns:

```text
13.5V
```

For a:

```text
3 Cell LiPo
```

The resulting cell voltage is:

```text
4.5V
```

Expected status:

```text
LIPO_STATUS_OK
```

---

## Running Tests

Build:

```bash
cd build

cmake ..

make
```

Run:

```bash
./tests/lipo_battery/lipo_battery_test
```

---

## Expected Output

```text
[INFO] Starting LiPo Battery Tests

[INFO] PASS: Configure

[INFO] LiPo Battery Initialized
[INFO] PASS: Init

[INFO] PASS: Update

[INFO] PASS: GetData

[INFO] PASS: Status

[INFO] LiPo Battery Tests Complete
```

---

## Current Limitations

The Linux platform currently returns a fixed ADC value.

Current tests verify:

```text
Configuration
Initialization
Data Flow
Status = OK
```

The following status paths are not currently exercised:

```text
WARNING
LOW
CRITICAL
```

---

## Future Improvements

Future platform enhancements may allow configurable ADC values.

Example:

```c
Platform_ADC_SetMockValue(
    11.1f);
```

This would enable testing of:

```text
Status Warning

Status Low

Status Critical

Status Transition Detection
```

---

## Summary

The LiPo Battery Test Suite verifies the core functionality of the battery module:

```text
Configure
    ↓
Initialize
    ↓
Update
    ↓
Get Data
    ↓
Verify Status
```

and serves as the regression test suite for LiPo Battery V1.
