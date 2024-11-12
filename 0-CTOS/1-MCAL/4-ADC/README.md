# 🚨 ADC Driver (Analog-to-Digital Converter) 🚨

[![Category](https://img.shields.io/badge/Category-ADC-blue)](#) [![Platform](https://img.shields.io/badge/Platform-ATmega32-orange)](#)

## 🚀 Overview 🚀
The **ADC (Analog-to-Digital Converter) Driver** allows easy integration of ADC functionality into an AVR-based microcontroller project. This driver enables analog signal conversion into a digital value, providing control over voltage reference, adjustment, prescaler, and auto-trigger modes. Developed in **C**, the driver supports both synchronous and asynchronous ADC readings with the ability to set callback functions for notifications.

## 🗂 Table of Contents 🗂
- [Features 🌟](#-features-)
- [Installation 🔧](#-installation-)
- [Configuration ⚙️](#-configuration-)
- [API Reference 📖](#-api-reference-)
- [Usage Example 💻](#-usage-example-)

---

## 🌟 Features 🌟

- **Analog Signal Conversion**: Convert analog signals to digital values with adjustable resolution and reference voltage.
- **Callback Functionality**: Asynchronously handle ADC conversions with a user-defined callback function.
- **Flexible Configuration**: Configure reference voltage, adjustment, prescaler, and auto-trigger modes to suit project needs.

---

## 🔧 Installation 🔧

1. Clone the repository:

```bash
git clone https://github.com/Bahnasy2001/AVR_Drivers.git
```

2. Include the ADC driver files in your project:
   - **ADC_interface.h**
   - **ADC_config.h**
   - **ADC_private.h**
   - **ADC_program.c**

3. Ensure **STD_TYPES.h** and **BIT_MATH.h** are also included as they are dependencies for the driver.

---

## ⚙️ Configuration ⚙️

Adjust settings in **ADC_config.h** for project-specific configurations. This includes selecting the voltage reference (AVCC, AREF, or internal), adjusting the ADC result (left or right), configuring the prescaler, and enabling/disabling auto-trigger.

---

## 📖 API Reference 📖

Here’s an overview of the key functions in **ADC_interface.h**:

- `void ADC_voidInit(void)` 
  **Description**: Initializes the ADC with the configuration defined in the `ADC_config.h` file. It configures the reference voltage, adjustment, prescaler, and auto-trigger settings.
  
- `u8 ADC_u8GetDigitalValueSynchNonBlocking(u8 Copy_u8ChannelNb, u16 *Copy_pu16DigitalValue)`  
  **Description**: Synchronously gets the digital value of an ADC channel. It waits for the conversion to complete before returning the result.
  - **Parameters**:
    - Copy_u8ChannelNb: The ADC channel number (0 to 31).
    - Copy_pu16DigitalValue: Pointer to store the resulting digital value.
  - **Returns**: `STD_TYPES_OK` if successful, or `STD_TYPES_NOK` if an error occurs.

- `u8 ADC_u8GetDigitalValueAsynch(u8 Copy_u8ChannelNb, void (*Copy_pfNotification) (u16))`  
  **Description**: Asynchronously gets the digital value of an ADC channel. A callback function is called once the conversion is complete.
  - **Parameters**:
    - Copy_u8ChannelNb: The ADC channel number (0 to 31).
    - Copy_pfNotification: Pointer to the callback function to be called when conversion is complete.
  - **Returns**: `STD_TYPES_OK` if successful, or `STD_TYPES_NOK` if an error occurs.

- `u8 ADC_u8GetADCRegValue (u16 * Copy_pu16ADCValue)`  
  **Description**: Retrieves the current ADC register value directly.
  - **Parameters**:
    - Copy_pu16ADCValue: Pointer to store the ADC register value.
  - **Returns**: `STD_TYPES_OK` if successful, or `STD_TYPES_NOK` if an error occurs.

---

## 💻 Usage Example 💻

Here’s an example showing how to use the ADC driver in an embedded application:

1. **Get a Synchronous ADC Value**  

```c
#include "ADC_interface.h"

int main() {
    u16 digitalValue;
    // Initialize ADC
    ADC_voidInit();
    // Get ADC value for channel 0 synchronously
    ADC_u8GetDigitalValueSynchNonBlocking(0, &digitalValue);
    while (1) {
        // Application loop
    }
}
```

2. **Get an Asynchronous ADC Value with a Callback**  

```c
void MyADCHandler(u16 adcValue) {
    // Handle the ADC value here
}

int main() {
    // Initialize ADC
    ADC_voidInit();
    // Get ADC value for channel 0 asynchronously and use the callback
    ADC_u8GetDigitalValueAsynch(0, MyADCHandler);
    while (1) {
        // Application loop
    }
}
```

3. **Retrieve the ADC Register Value**  

```c
u16 adcRegValue;
ADC_u8GetADCRegValue(&adcRegValue);
```

---

## ✍️ Author ✍️

**Hassan Ahmed Fathy El Bahnasy**  
[LinkedIn](https://www.linkedin.com/in/hassanbahnasy/)
