# 🖧 UART Driver 🖧

[![Category](https://img.shields.io/badge/Category-UART-blue)](#) [![Platform](https://img.shields.io/badge/Platform-ATmega32-orange)](#)

## 🚀 Overview 🚀
The **UART Driver** enables communication between the microcontroller and external devices through the UART (Universal Asynchronous Receiver-Transmitter) interface. This driver provides an easy-to-use interface for sending and receiving data synchronously and asynchronously. It supports byte and string transmission, both with and without length specifications, making it versatile for embedded communication tasks.

## 🗂 Table of Contents 🗂
- [Features 🌟](#-features-)
- [Installation 🔧](#-installation-)
- [Configuration ⚙️](#-configuration-)
- [API Reference 📖](#-api-reference-)
- [Usage Example 💻](#-usage-example-)

---

## 🌟 Features 🌟

- **Byte Transmission**: Send and receive data byte by byte using UART.
- **String Transmission**: Send and receive strings synchronously or asynchronously.
- **Synchronous and Asynchronous Modes**: Both transmission modes are supported for flexibility.
- **Support for Length-Based String Transmission**: Control string length during transmission.
- **Interrupt-driven Asynchronous Reception**: UART reception can be handled using interrupts for non-blocking operations.

---

## 🔧 Installation 🔧

1. Clone the repository:
   ```bash
   git clone https://github.com/Bahnasy2001/AVR_Drivers.git
   ```

2. Include the UART driver files in your project:
   - `UART_interface.h`
   - `UART_config.h`
   - `UART_private.h`
   - `UART_program.c`

3. Ensure `STD_TYPES.h` and `BIT_MATH.h` are included as dependencies for the driver.

---

## ⚙️ Configuration ⚙️

Adjust settings in **UART_config.h** to configure the UART baud rate, parity, stop bits, and other options based on your project requirements.

---

## 📖 API Reference 📖

Here’s an overview of the key functions in `UART_interface.h`:

- `void UART_voidInit(void);`  
  **Description**: Initializes the UART with default configuration settings (baud rate, data bits, stop bits, etc.).

- `void UART_voidSendByte(u8 Copy_u8DataByte);`  
  **Description**: Sends a single byte of data via UART.
  - **Parameters**:
    - `Copy_u8DataByte`: The byte of data to send.
  - **Returns**: None.

- `u8 UART_u8ReceiveByte(u8 * Copy_u8RecByte);`  
  **Description**: Receives a single byte of data via UART.
  - **Parameters**:
    - `Copy_u8RecByte`: Pointer to store the received byte.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if an error occurs.

- `u8 UART_u8SendStringSynch(u8 * Copy_u8String);`  
  **Description**: Sends a string synchronously via UART.
  - **Parameters**:
    - `Copy_u8String`: Pointer to the null-terminated string to send.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if an error occurs.

- `u8 UART_u8SendStringSynchWithLength(u8 *Copy_u8Data, u16 Copy_u16Length);`  
  **Description**: Sends a string of a specific length synchronously via UART.
  - **Parameters**:
    - `Copy_u8Data`: Pointer to the string data.
    - `Copy_u16Length`: The length of the string to send.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if an error occurs.

- `u8 UART_u8ReceiveStringSynch(u8 * Copy_u8ReceivedString, u8 Copy_u8MessageSize);`  
  **Description**: Receives a string synchronously via UART.
  - **Parameters**:
    - `Copy_u8ReceivedString`: Pointer to store the received string.
    - `Copy_u8MessageSize`: The expected size of the message to receive.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if an error occurs.

- `u8 UART_u8SendStringAsynch(u8* Copy_pu8String, void(*Copy_pf)(void));`  
  **Description**: Sends a string asynchronously via UART with an interrupt-based callback function.
  - **Parameters**:
    - `Copy_pu8String`: Pointer to the string data.
    - `Copy_pf`: Callback function to execute after the transmission completes.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if an error occurs.

- `u8 UART_u8ReceiveStringAsynch(u8* Copy_pu8ReceivedString, void(*Copy_pf)(void), u8 Copy_u8MessageSize);`  
  **Description**: Receives a string asynchronously via UART with an interrupt-based callback function.
  - **Parameters**:
    - `Copy_pu8ReceivedString`: Pointer to store the received string.
    - `Copy_pf`: Callback function to execute after the reception completes.
    - `Copy_u8MessageSize`: The size of the message to receive.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if an error occurs.

---

## 💻 Usage Example 💻

Here’s an example showing how to use the UART driver in an embedded application:

1. **Initialize UART**  
   ```c
   #include "UART_interface.h"

   int main() {
       // Initialize UART
       UART_voidInit();
       while (1) {
           // Application loop
       }
   }
   ```

2. **Send a Single Byte**  
   ```c
   UART_voidSendByte('A');
   ```

3. **Send a String Synchronously**  
   ```c
   u8 myString[] = "Hello, UART!";
   UART_u8SendStringSynch(myString);
   ```

4. **Receive a Byte**  
   ```c
   u8 receivedByte;
   UART_u8ReceiveByte(&receivedByte);
   ```

5. **Receive a String Asynchronously**  
   ```c
   void UART_ReceiveCallback(void) {
       // Code to execute after string reception is complete
   }

   u8 receivedString[100];
   UART_u8ReceiveStringAsynch(receivedString, UART_ReceiveCallback, 100);
   ```

---

## ✍️ Author ✍️

**Hassan Ahmed Fathy El Bahnasy**  
[LinkedIn](https://www.linkedin.com/in/hassanbahnasy/)
