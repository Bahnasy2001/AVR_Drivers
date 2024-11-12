# 🧩 MCAL Layer - Microcontroller Abstraction Layer 🧩

[![Category](https://img.shields.io/badge/Category-MCAL-blue)](#) [![Platform](https://img.shields.io/badge/Platform-ATmega32-orange)](#)

The **MCAL (Microcontroller Abstraction Layer)** includes drivers that directly interface with the ATmega32 microcontroller's hardware. It abstracts the hardware-specific code, enabling the **HAL and Application Layers** to operate independently of the microcontroller.

## 📑 Drivers 📑

| Driver         | Description                                 |
|----------------|---------------------------------------------|
| [DIO](./1-DIO/README.md)     | Digital Input/Output Control     |
| [EXTI](./2-EXTI/README.md)           | External Interrupts                         |
| [GI](./3-GI/README.md)             | General Interrupts                          |
| [ADC](./4-ADC/README.md)            | Analog-to-Digital Converter                 |
| [TIMERS](./5-TIMERS/README.md)         | Timer Management                            |
| [WDT](./6-WDT/README.md)            | Watchdog Timer Control                      |
| [UART](./7-UART/README.md)           | Serial Communication                        |
| [SPI](./8-SPI/README.md)            | Serial Peripheral Interface                |
| [TWI](./9-TWI/README.md)            | Two-Wire Interface Communication           |
| [EEPROM](./10-EEPROM/README.md)         | Electrically Erasable Programmable ROM     |

Each driver is documented with setup, usage, and configuration instructions.

## 🛠️ Getting Started with MCAL 🛠️

1. **Clone the repository** and navigate to the MCAL directory.
   ```bash
   git clone https://github.com/Bahnasy2001/AVR_Drivers.git
   cd AVR_Drivers/1-MCAL
   ```
2. **Select a driver** module (e.g., DIO) and review its specific README for setup instructions.

## 🔗 Additional Documentation 🔗

- [Primary README](../../README.md)
- [HAL Layer](../2-HAL/README.md)

---

## ✍️ Author ✍️

**Hassan Ahmed Fathy El Bahnasy**
[LinkedIn](https://www.linkedin.com/in/hassanbahnasy/)

