# 🚨 EXTI Driver (External Interrupt) 🚨

[![Category](https://img.shields.io/badge/Category-EXTI-blue)](#) [![Platform](https://img.shields.io/badge/Platform-ATmega32-orange)](#)

## 🚀 Overview 🚀
The **External Interrupt (EXTI) Driver** enables control and configuration of external interrupts on an AVR microcontroller. This driver allows you to set up interrupts with specific edge triggers and manage interrupt handlers. Developed in **C**, this EXTI Driver provides an easy interface for enabling, disabling, and configuring interrupts.

## 🗂 Table of Contents 🗂
- [Features 🌟](#features)
- [Installation 🔧](#installation)
- [Configuration ⚙️](#configuration)
- [API Reference 📖](#api-reference)
- [Usage Example 💻](#usage-example)

---

## 🌟 Features 🌟

- **Interrupt Enable/Disable**: Enable or disable interrupts based on application needs.
- **Edge Trigger Control**: Configure the interrupt trigger to respond on rising, falling, logical change, or low-level.
- **Callback Functionality**: Set callback functions for each interrupt to handle events as they occur.

---

## 🔧 Installation 🔧

1. Clone the repository:
   ```bash
   git clone https://github.com/Bahnasy2001/AVR_Drivers.git
   ```

2. Include the EXTI driver files in your project:
   - `EXTI_interface.h`
   - `EXTI_config.h`
   - `EXTI_private.h`
   - `EXTI_program.c`

3. Ensure `STD_TYPES.h` and `BIT_MATH.h` are also included as they are dependencies for the driver.

---

## ⚙️ Configuration ⚙️

Adjust settings in **EXTI_config.h** for any project-specific configurations. This driver provides flexibility for defining edge sources and specific interrupt configurations as needed.

---

## 📖 API Reference 📖

Here’s an overview of the key functions in `EXTI_interface.h`:

- `u8 EXTI_u8EXTIEnable(u8 Copy_u8EXTIIndex, u8 Copy_u8EdgeIndex);`  
  **Description**: Enables the specified external interrupt and configures its edge trigger.
  - **Parameters**:
    - `Copy_u8EXTIIndex`: Identifier for the interrupt (e.g., `EXTI_u8_INT0`, `EXTI_u8_INT1`, `EXTI_u8_INT2`).
    - `Copy_u8EdgeIndex`: Edge type for the interrupt trigger (e.g., `EXTI_u8_RAISING_EDGE`, `EXTI_u8_FALLING_EDGE`).
  - **Returns**: `STD_TYPES_OK` if successful, or `STD_TYPES_NOK` if an error occurs.

- `u8 EXTI_u8EXTIDisable(u8 Copy_u8EXTIIndex);`  
  **Description**: Disables the specified external interrupt.
  - **Parameters**:
    - `Copy_u8EXTIIndex`: Identifier for the interrupt (e.g., `EXTI_u8_INT0`, `EXTI_u8_INT1`, `EXTI_u8_INT2`).
  - **Returns**: `STD_TYPES_OK` if successful, or `STD_TYPES_NOK` if an error occurs.

- `u8 EXTI_u8EXTISetEdge(u8 Copy_u8EXTIIndex, u8 Copy_u8EdgeIndex);`  
  **Description**: Sets the edge trigger for an existing external interrupt.
  - **Parameters**:
    - `Copy_u8EXTIIndex`: Identifier for the interrupt.
    - `Copy_u8EdgeIndex`: Edge type (e.g., `EXTI_u8_RAISING_EDGE`, `EXTI_u8_FALLING_EDGE`).
  - **Returns**: `STD_TYPES_OK` if successful, or `STD_TYPES_NOK` if an error occurs.

- `u8 EXTI_u8EXTISetCallBack(u8 Copy_u8EXTIIndex, void (*Copy_pf)(void));`  
  **Description**: Sets a callback function to be executed when the specified interrupt occurs.
  - **Parameters**:
    - `Copy_u8EXTIIndex`: Identifier for the interrupt.
    - `Copy_pf`: Pointer to the callback function.
  - **Returns**: `STD_TYPES_OK` if successful, or `STD_TYPES_NOK` if an error occurs.

---

## 💻 Usage Example 💻

Here’s an example showing how to use the EXTI driver in an embedded application:

1. **Enable an Interrupt with a Rising Edge Trigger**  
   ```c
   #include "EXTI_interface.h"

   int main() {
       // Enable INT0 with a rising edge trigger
       EXTI_u8EXTIEnable(EXTI_u8_INT0, EXTI_u8_RAISING_EDGE);
       while (1) {
           // Application loop
       }
   }
   ```

2. **Set a Callback Function**  
   ```c
   void MyInterruptHandler(void) {
       // Code to execute when interrupt occurs
   }

   int main() {
       EXTI_u8EXTIEnable(EXTI_u8_INT0, EXTI_u8_FALLING_EDGE);
       EXTI_u8EXTISetCallBack(EXTI_u8_INT0, MyInterruptHandler);
       while (1) {
           // Application loop
       }
   }
   ```

3. **Disable an Interrupt**  
   ```c
   EXTI_u8EXTIDisable(EXTI_u8_INT1);
   ```

---

## ✍️ Author ✍️

**Hassan Ahmed Fathy El Bahnasy**  
[LinkedIn](https://www.linkedin.com/in/hassanbahnasy/)