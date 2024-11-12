# 🌐 GI Driver (Global Interrupt) 🌐

[![Category](https://img.shields.io/badge/Category-GI-blue)](#) [![Platform](https://img.shields.io/badge/Platform-ATmega32-orange)](#)

## 🚀 Overview 🚀
The **Global Interrupt (GI) Driver** allows for enabling and disabling global interrupts on an AVR microcontroller. This driver provides a simple interface to manage global interrupt settings, crucial for handling interrupt-driven applications efficiently. Developed in **C**, the GI Driver abstracts direct hardware access, making it easier to control global interrupt states in embedded projects.

## 🗂 Table of Contents 🗂
- [Features 🌟](#features)
- [Installation 🔧](#installation)
- [API Reference 📖](#api-reference)
- [Usage Example 💻](#usage-example)

---

## 🌟 Features 🌟

- **Global Interrupt Enable**: Activate global interrupts with a single function call.
- **Global Interrupt Disable**: Deactivate global interrupts easily when required by the application.
- **Minimalistic API**: Straightforward and easy-to-use API for controlling global interrupts.

---

## 🔧 Installation 🔧

1. Clone the repository:
   ```bash
   git clone https://github.com/Bahnasy2001/AVR_Drivers.git
   ```

2. Include the GI driver files in your project:
   - `GI_interface.h`
   - `GI_config.h`
   - `GI_private.h`
   - `GI_program.c`

3. Ensure `STD_TYPES.h` and `BIT_MATH.h` are also included, as they are dependencies for the driver.

---

## 📖 API Reference 📖

Here’s an overview of the key functions in `GI_interface.h`:

- `void GI_voidEnableGI(void);`  
  **Description**: Enables global interrupts by setting the appropriate bit in the status register.
  
- `void GI_voidDisableGI(void);`  
  **Description**: Disables global interrupts by clearing the relevant bit in the status register.

---

## 💻 Usage Example 💻

Here’s an example demonstrating how to use the GI driver in an embedded application:

1. **Enable Global Interrupts**  
   ```c
   #include "GI_interface.h"

   int main() {
       // Enable global interrupts
       GI_voidEnableGI();
       while (1) {
           // Application loop
       }
   }
   ```

2. **Disable Global Interrupts**  
   ```c
   #include "GI_interface.h"

   int main() {
       // Disable global interrupts
       GI_voidDisableGI();
       while (1) {
           // Application loop
       }
   }
   ```

---

## ✍️ Author ✍️

**Hassan Ahmed Fathy El Bahnasy**  
[LinkedIn](https://www.linkedin.com/in/hassanbahnasy/)