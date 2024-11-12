# 🖲️ DIO Driver (Digital Input/Output) 🖲️


[![Category](https://img.shields.io/badge/Category-DIO-green)](#) [![Platform](https://img.shields.io/badge/Platform-ATmega32-orange)](#)


## 🚀 Overview 🚀
This **Digital Input/Output (DIO) Driver** provides a configurable interface for controlling the input and output of pins on an AVR microcontroller. The driver abstracts direct hardware access, allowing for easier and more intuitive control of port and pin configurations. Developed in **C**, this DIO Driver can be integrated into embedded projects to manage pins across various ports and set pin values, directions, and states.

## 🗂 Table of Contents 🗂
- [Features 🌟](#-features-)
- [Installation 🔧](#-installation-)
- [Configuration ⚙️](#-configuration-)
- [API Reference 📖 ](#-api-reference-)
- [Usage Example 💻 ](#-usage-example-)

---

## 🌟 Features 🌟

- **Port and Pin Control**: Configure ports and individual pins as input or output.
- **Direction and Value Setting**: Define input/output directions and set high/low values.
- **Configurable Initial Settings**: Set up initial values and directions in a separate configuration file.
- **Port Handling**: Manage entire ports, not just individual pins.

---

## 🔧 Installation 🔧

1. Clone the repository:
   ```bash
   git clone https://github.com/Bahnasy2001/AVR_Drivers.git
   ```

2. Include the DIO driver files in your project:
   - `DIO_interface.h`
   - `DIO_config.h`
   - `DIO_private.h`
   - `DIO_program.c`

3. Ensure `STD_TYPES.h` and `BIT_MATH.h` are also available in your project, as they are required dependencies.

---

## ⚙️ Configuration ⚙️

Edit **DIO_config.h** to configure each pin's initial direction and value. The available options are:
- **Direction**: `DIO_u8_INTIAL_INPUT` or `DIO_u8_INTIAL_OUTPUT`
- **Value**: `DIO_u8_INPUT_FLOATING`, `DIO_u8_INPUT_PULLUP`, `DIO_u8_OUTPUT_LOW`, or `DIO_u8_OUTPUT_HIGH`

Example configuration:
```c
// PORTA Configuration
#define DIO_u8_PA0_INTIAL_DIRECTION DIO_u8_INTIAL_OUTPUT
#define DIO_u8_PA0_INTIAL_VALUE     DIO_u8_OUTPUT_LOW
```

---

## 📖 API Reference 📖

Here’s a list of key functions in `DIO_interface.h`:

- `void DIO_voidInit(void);`  
  **Description**: Initializes the DIO driver by setting up the direction and initial value for each pin as per `DIO_config.h`.

- `u8 DIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDirection);`  
  **Description**: Sets the direction of a specific pin on a specific port.

- `u8 DIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue);`  
  **Description**: Sets the value (HIGH/LOW) for a specified pin.

- `u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 *Copy_pu8ReturnedPinValue);`  
  **Description**: Reads the current value of a specified pin.

- `u8 DIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection);`  
  **Description**: Sets the direction (input/output) for all pins in a specified port.

- `u8 DIO_u8SetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue);`  
  **Description**: Sets the value for all pins in a specified port.

---

## 💻 Usage Example 💻

Here’s a quick example to demonstrate using the DIO driver in an embedded application:

1. **Initialize the Driver**  
   Ensure you call `DIO_voidInit();` once at the start of your application to apply initial configurations.

   ```c
   #include "DIO_interface.h"

   int main() {
       DIO_voidInit();
       // Set PORTA, PIN0 as output and set it high
       DIO_u8SetPinDirection(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_OUTPUT);
       DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_HIGH);
       while(1) {
           // Application loop
       }
   }
   ```

2. **Read a Pin Value**  
   You can read the value of a pin using `DIO_u8GetPinValue()`. Here’s an example:

   ```c
   u8 pinValue;
   DIO_u8GetPinValue(DIO_u8_PORTA, DIO_u8_PIN0, &pinValue);
   ```

---

## ✍️ Author ✍️

**Hassan Ahmed Fathy El Bahnasy**
[LinkedIn](https://www.linkedin.com/in/hassanbahnasy/)