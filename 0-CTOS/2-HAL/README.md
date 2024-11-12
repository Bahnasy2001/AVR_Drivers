# 🧩 HAL Layer - Hardware Abstraction Layer 🧩

[![Category](https://img.shields.io/badge/Category-HAL-blue)](#) [![Platform](https://img.shields.io/badge/Platform-ATmega32-orange)](#)

The **HAL (Hardware Abstraction Layer)** provides drivers for higher-level hardware components and peripherals, allowing the **Application Layer** to interface with hardware features like displays, motors, and sensors without interacting directly with microcontroller-specific registers.

## 📑 Modules 📑

| Module           | Description                           |
|------------------|---------------------------------------|
| [LCD](./1-LCD/README.md)         | Liquid Crystal Display Control  |
| [KPD](./2-KPD/README.md)         | Keypad Interface                 |
| [STEPPER](./3-STEPPER/README.md) | Stepper Motor Control            |
| [H_BRIDGE](./4-H_BRIDGE/README.md)| H-Bridge Motor Driver            |
| [SERVO](./5-SERVO/README.md)     | Servo Motor Control              |
| [SWICU](./6-SWICU/README.md)     | Software Input Capture Unit      |
| [EEPROM](./7-EEPROM/README.md)   | External EEPROM Interface        |

Each module is equipped with documentation on configuration, usage, and API functions, ensuring a straightforward integration process for hardware components.

## 🛠️ Getting Started with HAL 🛠️

1. **Clone the repository** and navigate to the HAL directory.
   ```bash
   git clone https://github.com/Bahnasy2001/AVR_Drivers.git
   cd AVR_Drivers/2-HAL
   ```
2. **Select a module** (e.g., LCD) and refer to its specific README for detailed usage instructions and examples.

## 🔗 Additional Documentation 🔗

- [Primary README](../../README.md)
- [MCAL Layer](../1-MCAL/README.md)

---

## ✍️ Author ✍️

**Hassan Ahmed Fathy El Bahnasy**  
[LinkedIn](https://www.linkedin.com/in/hassanbahnasy/)