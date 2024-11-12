# ⏱️ Watchdog Timer (WDT) Driver ⏱️

[![Category](https://img.shields.io/badge/Category-WDT-blue)](#) [![Platform](https://img.shields.io/badge/Platform-ATmega32-orange)](#)

## 🚀 Overview 🚀
The **Watchdog Timer (WDT) Driver** allows for controlling the Watchdog Timer on an AVR microcontroller. This timer is a critical safety mechanism that resets the microcontroller if the system encounters a fault or enters an unresponsive state. Developed in **C**, this WDT driver provides functions to enable, disable, and configure the Watchdog Timer with various timeout periods.

## 🗂 Table of Contents 🗂
- [Features 🌟](#-features-)
- [Installation 🔧](#-installation-)
- [Configuration ⚙️](#-configuration-)
- [API Reference 📖](#-api-reference-)
- [Usage Example 💻](#-usage-example-)

---

## 🌟 Features 🌟

- **Enable/Disable WDT**: Easily enable or disable the Watchdog Timer.
- **Configurable Timeout Periods**: Set different timeout intervals using prescaler settings.
- **Fault Protection**: The WDT can reset the microcontroller in case of software faults or hangs.

---

## 🔧 Installation 🔧

1. Clone the repository:
   ```bash
   git clone https://github.com/Bahnasy2001/AVR_Drivers.git
   ```

2. Include the WDT driver files in your project:
   - `WDT_interface.h`
   - `WDT_config.h`
   - `WDT_private.h`
   - `WDT_program.c`

3. Ensure `STD_TYPES.h` and `BIT_MATH.h` are also included as they are dependencies for the driver.

---

## ⚙️ Configuration ⚙️

In **WDT_config.h**, configure the prescaler to set the timeout period. Each prescaler value corresponds to a specific time interval before the Watchdog Timer resets the system:

```c
#define WDT_u8_PRESCALER             WDT_u8_PRESCALER_2048
```

### Available Timeout Periods:
- `WDT_u8_PRESCALER_16` - 16.3 ms
- `WDT_u8_PRESCALER_32` - 32.5 ms
- `WDT_u8_PRESCALER_64` - 65 ms
- `WDT_u8_PRESCALER_128` - 0.13 s
- `WDT_u8_PRESCALER_256` - 0.26 s
- `WDT_u8_PRESCALER_512` - 0.52 s
- `WDT_u8_PRESCALER_1024` - 1.0 s
- `WDT_u8_PRESCALER_2048` - 2.1 s

---

## 📖 API Reference 📖

The following functions are defined in `WDT_interface.h`:

- `void WDT_voidEnable(void);`  
  **Description**: Enables the Watchdog Timer with the configured timeout period.
  
- `void WDT_voidDisable(void);`  
  **Description**: Disables the Watchdog Timer, preventing it from resetting the system.

---

## 💻 Usage Example 💻

Here’s an example demonstrating the basic usage of the WDT driver in an embedded application:

1. **Enable the WDT with a 2.1-second Timeout**  
   ```c
   #include "WDT_interface.h"

   int main() {
       // Enable the WDT with the prescaler defined in WDT_config.h
       WDT_voidEnable();
       while (1) {
           // Main application loop
       }
   }
   ```

2. **Disable the WDT**  
   ```c
   #include "WDT_interface.h"

   int main() {
       WDT_voidDisable();
       while (1) {
           // Main application loop
       }
   }
   ```

---

## ✍️ Author ✍️

**Hassan Ahmed Fathy El Bahnasy**  
[LinkedIn](https://www.linkedin.com/in/hassanbahnasy/)
