# 🚀 AVR Drivers (ATmega32 Drivers) Repository 🚀

 [![Platform](https://img.shields.io/badge/Platform-ATmega32-orange)](#) [![Embedded Systems](https://img.shields.io/badge/Category-Embedded%20Systems-blue)](#)

Welcome to the **AVR Drivers** repository! This project includes drivers for the **ATmega32** microcontroller, organized by layers and modules to simplify development for embedded systems. This repository provides reusable, modularized drivers for multiple peripheral controls across various layers.

## 📂 Repository Structure 📂

```
0-CTOS/
├── 1-MCAL/       # Microcontroller Abstraction Layer
│   ├── 1-DIO/    # Digital I/O
│   ├── 2-EXTI/   # External Interrupts
│   ├── 3-GI/     # General Interrupts
│   ├── 4-ADC/    # Analog-to-Digital Converter
│   ├── 5-TIMERS/
│   ├── 6-WDT/    # Watchdog Timer
│   ├── 7-UART/
│   ├── 8-SPI/
│   ├── 9-TWI/    # Two-Wire Interface
│   └── 10-EEPROM/
├── 2-HAL/        # Hardware Abstraction Layer
│   ├── 1-LCD/          # LCD Display
│   ├── 2-KPD/          # Keypad
│   ├── 3-STEPPER/      # Stepper Motor
│   │   └── stepper/    # Stepper Motor Library
│   │       └── Electronics Tree Stepper Motor Library/
│   │           └── LIB/
│   ├── 4-H_BRIDGE/     # H-Bridge Motor Control
│   ├── 5-SERVO/        # Servo Motor
│   ├── 6-SWICU/        # Software Input Capture Unit
│   └── 7-EEPROM/
├── 3-Service/    # Service Layer
│   ├── 1-RTO/          # Real-Time Operating System
│   ├── 2-MQTT/         # Message Queuing Telemetry Transport
│   └── FreeRTOS/       # FreeRTOS Kernel
├── 4-App/        # Application Layer
└── 5-LIB/        # Libraries
    ├── 1-STD_TYPES/    # Standard Types
    └── 2-BIT_MATH/     # Bit Manipulation Macros

```

Each layer serves a different purpose in the development hierarchy:
- **MCAL**: Provides drivers that interact directly with the hardware.
- **HAL**: Offers device-specific functionalities with abstraction.
- **Service Layer**: Contains services like OS support (e.g., FreeRTOS).
- **App Layer**: Application-specific code integrating the drivers and libraries.
- **LIB**: Utility libraries used across the application.

## 🔗 Layer Documentation 🔗

- [MCAL Layer](./1-MCAL/README.md)
- [HAL Layer](./2-HAL/README.md)
- [Service Layer](./3-Service/README.md)
- [App Layer](./4-App/README.md)
- [Libraries](./5-LIB/README.md)

---

## ✍️ Author ✍️

**Hassan Ahmed Fathy El Bahnasy**
[LinkedIn](https://www.linkedin.com/in/hassanbahnasy/)