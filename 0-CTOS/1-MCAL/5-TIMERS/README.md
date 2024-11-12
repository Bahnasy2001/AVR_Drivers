# ⏱️ TIMERS Driver ⏱️

[![Category](https://img.shields.io/badge/Category-TIMERS-blue)](#) [![Platform](https://img.shields.io/badge/Platform-ATmega32-orange)](#)

## 🚀 Overview 🚀
The **TIMERS Driver** enables control and configuration of timers in an AVR microcontroller. This driver provides an easy-to-use interface to set up and manage timers for various timing-related tasks such as delays, PWM generation, and time counting. Developed in **C**, the TIMERS Driver includes functions for configuring timer modes, prescalers, and overflow interrupts.

## 🗂 Table of Contents 🗂
- [Features 🌟](#-features-)
- [Installation 🔧](#-installation-)
- [Configuration ⚙️](#-configuration-)
- [API Reference 📖](#-api-reference-)
- [Usage Example 💻](#-usage-example-)

---

## 🌟 Features 🌟

- **Timer Configuration**: Set up timers in different modes such as Normal, CTC, and PWM.
- **Interrupt Handling**: Enable or disable interrupts for timer overflows and compare matches.
- **Prescaler Configuration**: Set the prescaler for timers to control the timer's frequency.
- **PWM Generation**: Use timers to generate PWM signals for motor control or signal modulation.

---

## 🔧 Installation 🔧

1. Clone the repository:
   ```bash
   git clone https://github.com/Bahnasy2001/AVR_Drivers.git
   ```

2. Include the TIMERS driver files in your project:
   - `TIMERS_interface.h`
   - `TIMERS_config.h`
   - `TIMERS_private.h`
   - `TIMERS_program.c`

3. Ensure `STD_TYPES.h` and `BIT_MATH.h` are also included as they are dependencies for the driver.

---

## ⚙️ Configuration ⚙️

Adjust settings in **TIMERS_config.h** to configure the timer modes, prescalers, and other project-specific options. This driver allows flexibility in selecting different timer configurations based on your application requirements.

---

## 📖 API Reference 📖

Here’s an overview of the key functions in `TIMERS_interface.h`:

- `void TIMERS_voidTimer0Init(void);`  
  **Description**: Initializes Timer0 with default settings.

- `void TIMERS_voidTimer1Init(void);`  
  **Description**: Initializes Timer1 with default settings.

- `u8 TIMERS_u8GetTCNT0Value(u8 * Copy_pu8Value);`  
  **Description**: Gets the current value of Timer0's counter.
  - **Parameters**:
    - `Copy_pu8Value`: Pointer to a variable to store the counter value.
  - **Returns**: `STD_TYPES_OK` if successful, or `STD_TYPES_NOK` if an error occurs.

- `u8 TIMERS_u8Timer0SetCallBack(void(*Copy_pf)(void));`  
  **Description**: Sets a callback function for Timer0 overflow interrupt.
  - **Parameters**:
    - `Copy_pf`: Pointer to the callback function.
  - **Returns**: `STD_TYPES_OK` if successful, or `STD_TYPES_NOK` if an error occurs.

- `u8 TIMERS_u8Timer0CTCSetCallBack(void(*Copy_pf)(void));`  
  **Description**: Sets a callback function for Timer0 CTC interrupt.
  - **Parameters**:
    - `Copy_pf`: Pointer to the callback function.
  - **Returns**: `STD_TYPES_OK` if successful, or `STD_TYPES_NOK` if an error occurs.

- `u8 TIMERS_u8Timer1SetCallBack(void(*Copy_pf)(void));`  
  **Description**: Sets a callback function for Timer1 overflow interrupt.
  - **Parameters**:
    - `Copy_pf`: Pointer to the callback function.
  - **Returns**: `STD_TYPES_OK` if successful, or `STD_TYPES_NOK` if an error occurs.

- `u8 TIMERS_u8Timer1COMPASetCallBack(void(*Copy_pf)(void));`  
  **Description**: Sets a callback function for Timer1 Compare Match A interrupt.
  - **Parameters**:
    - `Copy_pf`: Pointer to the callback function.
  - **Returns**: `STD_TYPES_OK` if successful, or `STD_TYPES_NOK` if an error occurs.

- `u8 TIMERS_u8Timer1COMPBSetCallBack(void(*Copy_pf)(void));`  
  **Description**: Sets a callback function for Timer1 Compare Match B interrupt.
  - **Parameters**:
    - `Copy_pf`: Pointer to the callback function.
  - **Returns**: `STD_TYPES_OK` if successful, or `STD_TYPES_NOK` if an error occurs.

- `u8 TIMERS_u8Timer1CAPTSetCallBack(void(*Copy_pf)(void));`  
  **Description**: Sets a callback function for Timer1 Capture Event interrupt.
  - **Parameters**:
    - `Copy_pf`: Pointer to the callback function.
  - **Returns**: `STD_TYPES_OK` if successful, or `STD_TYPES_NOK` if an error occurs.

- `void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value);`  
  **Description**: Sets the compare match value for Timer0 in CTC mode.

- `void TIMERS_voidTimer1SetCompareMatchValueUnitA(u16 Copy_u16OCR1AValue);`  
  **Description**: Sets the compare match value for Timer1, Unit A in CTC mode.

- `void TIMERS_voidTimer1SetCompareMatchValueUnitB(u16 Copy_u16OCR1BValue);`  
  **Description**: Sets the compare match value for Timer1, Unit B in CTC mode.

- `void TIMERS_voidTimer1SetICR1Value(u16 Copy_u16ICR1Value);`  
  **Description**: Sets the Input Capture Register (ICR1) value for Timer1.

- `u8 TIMERS_u8GetTCNT1Value(u16 * Copy_pu16Value);`  
  **Description**: Gets the current value of Timer1's counter.
  - **Parameters**:
    - `Copy_pu16Value`: Pointer to a variable to store the counter value.
  - **Returns**: `STD_TYPES_OK` if successful, or `STD_TYPES_NOK` if an error occurs.

- `u8 TIMERS_u8SetTCNT1Value(u16 * Copy_u16TCNT1Value);`  
  **Description**: Sets the value of Timer1's counter.
  - **Parameters**:
    - `Copy_u16TCNT1Value`: Pointer to a variable with the value to set for Timer1's counter.
  - **Returns**: `STD_TYPES_OK` if successful, or `STD_TYPES_NOK` if an error occurs.

---

## 💻 Usage Example 💻

Here’s an example showing how to use the TIMERS driver in an embedded application:

1. **Initialize Timer0**  
   ```c
   #include "TIMERS_interface.h"

   int main() {
       // Initialize Timer0
       TIMERS_voidTimer0Init();
       while (1) {
           // Application loop
       }
   }
   ```

2. **Set Compare Match Value for Timer0**  
   ```c
   TIMERS_voidTimer0SetCompareMatchValue(100);
   ```

3. **Set Callback Function for Timer1 Overflow**  
   ```c
   void Timer1OverflowHandler(void) {
       // Code to execute when Timer1 overflows
   }

   int main() {
       TIMERS_u8Timer1SetCallBack(Timer1OverflowHandler);
       TIMERS_voidTimer1Init();
       while (1) {
           // Application loop
       }
   }
   ```

4. **Get Timer1 Counter Value**  
   ```c
   u16 timer1Value;
   TIMERS_u8GetTCNT1Value(&timer1Value);
   ```

5. **Disable Timer1**  
   ```c
   TIMERS_u8SetTCNT1Value(0); // Reset Timer1 counter to zero
   ```

---

## ✍️ Author ✍️

**Hassan Ahmed Fathy El Bahnasy**  
[LinkedIn](https://www.linkedin.com/in/hassanbahnasy/)

