# 🖧 SPI Driver 🖧

[![Category](https://img.shields.io/badge/Category-SPI-blue)](#) [![Platform](https://img.shields.io/badge/Platform-ATmega32-orange)](#)

## 🚀 Overview 🚀
The **SPI Driver** enables communication between the microcontroller and peripheral devices using the SPI (Serial Peripheral Interface) protocol. This driver provides a flexible interface for sending and receiving data both synchronously and asynchronously. It supports byte and string transmission and reception, making it ideal for high-speed communication in embedded systems.

## 🗂 Table of Contents 🗂
- [Features 🌟](#-features-)
- [Installation 🔧](#-installation-)
- [Configuration ⚙️](#-configuration-)
- [API Reference 📖](#-api-reference-)
- [Usage Example 💻](#-usage-example-)

---

## 🌟 Features 🌟

- **Byte Transmission & Reception**: Supports sending and receiving data byte by byte via SPI.
- **String Transmission & Reception**: Send and receive strings synchronously or asynchronously.
- **Synchronous & Asynchronous Communication**: Flexibility in handling data transmission and reception.
- **Callback Functions**: Asynchronous operations support callback functions for efficient interrupt handling.

---

## 🔧 Installation 🔧

1. Clone the repository:
   ```bash
   git clone https://github.com/Bahnasy2001/AVR_Drivers.git
   ```

2. Include the SPI driver files in your project:
   - `SPI_interface.h`
   - `SPI_config.h`
   - `SPI_private.h`
   - `SPI_program.c`

3. Ensure `STD_TYPES.h` and `BIT_MATH.h` are included as dependencies for the driver.

---

## ⚙️ Configuration ⚙️

Adjust settings in **SPI_config.h** to configure the SPI interface for master or slave mode, and set any necessary parameters like baud rate or clock polarity.

---

## 📖 API Reference 📖

Here’s an overview of the key functions in `SPI_interface.h`:

- `void SPI_voidInit(void);`  
  **Description**: Initializes the SPI interface with default settings.
  - **Parameters**: None.
  - **Returns**: Nothing.

- `u8 SPI_u8TransReceive(u8 Copy_u8TransmittedByte, u8 * Copy_pu8ReceivedByte);`  
  **Description**: Transmits a byte and receives a byte via SPI.
  - **Parameters**:
    - `Copy_u8TransmittedByte`: The byte to transmit.
    - `Copy_pu8ReceivedByte`: Pointer to store the received byte.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if an error occurs.

- `void SPI_voidSlaveSendByte(u8 Copy_u8DataByte);`  
  **Description**: Sends a byte from the slave device via SPI.
  - **Parameters**:
    - `Copy_u8DataByte`: Data byte to send.
  - **Returns**: Nothing.

- `u8 SPI_u8ReceiveByte(u8 * Copy_pu8ReceivedByte);`  
  **Description**: Receives a byte via SPI.
  - **Parameters**:
    - `Copy_pu8ReceivedByte`: Pointer to store the received byte.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if an error occurs.

- `u8 SPI_u8SendStringSynch(u8 * Copy_pu8TransmittedString);`  
  **Description**: Sends a string synchronously via SPI.
  - **Parameters**:
    - `Copy_pu8TransmittedString`: Pointer to the string to transmit.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if an error occurs.

- `u8 SPI_u8ReceiveStringSynch(u8 * Copy_pu8ReceivedString);`  
  **Description**: Receives a string synchronously via SPI.
  - **Parameters**:
    - `Copy_pu8ReceivedString`: Pointer to store the received string.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if an error occurs.

- `u8 SPI_u8SendStringAsynch(u8 * Copy_pu8TransmittedString, void(*Copy_pf)(void));`  
  **Description**: Sends a string asynchronously via SPI with a callback function.
  - **Parameters**:
    - `Copy_pu8TransmittedString`: Pointer to the string to transmit.
    - `Copy_pf`: Callback function to call after transmission.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if an error occurs.

- `u8 SPI_u8ReceiveStringAsynch(u8 * Copy_pu8ReceivedString, void(*Copy_pf)(void));`  
  **Description**: Receives a string asynchronously via SPI with a callback function.
  - **Parameters**:
    - `Copy_pu8ReceivedString`: Pointer to store the received string.
    - `Copy_pf`: Callback function to call after reception.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if an error occurs.

- `u8 SPI_u8SendReceiveStringSynch(u8 * Copy_pu8TransmittedString, u8 * Copy_pu8ReceivedString);`  
  **Description**: Sends and receives a string synchronously via SPI.
  - **Parameters**:
    - `Copy_pu8TransmittedString`: Pointer to the string to transmit.
    - `Copy_pu8ReceivedString`: Pointer to store the received string.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if an error occurs.

- `u8 SPI_u8SendReceiveStringAsynch(u8 * Copy_pu8TransmittedString, u8 * Copy_pu8ReceivedString, void(*Copy_pf)(void));`  
  **Description**: Sends and receives a string asynchronously via SPI with a callback function.
  - **Parameters**:
    - `Copy_pu8TransmittedString`: Pointer to the string to transmit.
    - `Copy_pu8ReceivedString`: Pointer to store the received string.
    - `Copy_pf`: Callback function to call after operation completes.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if an error occurs.

---

## 💻 Usage Example 💻

Here’s an example showing how to use the SPI driver in an embedded application:

1. **Initialize SPI**  
   ```c
   #include "SPI_interface.h"

   int main() {
       // Initialize SPI
       SPI_voidInit();
       while (1) {
           // Application loop
       }
   }
   ```

2. **Send a Byte and Receive a Byte**  
   ```c
   u8 receivedByte;
   SPI_u8TransReceive(0x55, &receivedByte);
   ```

3. **Send a String Synchronously**  
   ```c
   u8 myString[] = "Hello, SPI!";
   SPI_u8SendStringSynch(myString);
   ```

4. **Receive a String Asynchronously**  
   ```c
   void SPI_ReceiveCallback(void) {
       // Code to execute after string reception is complete
   }

   u8 receivedString[100];
   SPI_u8ReceiveStringAsynch(receivedString, SPI_ReceiveCallback);
   ```

5. **Send and Receive a String Synchronously**  
   ```c
   u8 receivedString[100];
   SPI_u8SendReceiveStringSynch("Hello SPI", receivedString);
   ```

---

## ✍️ Author ✍️

**Hassan Ahmed Fathy El Bahnasy**  
[LinkedIn](https://www.linkedin.com/in/hassanbahnasy/)
