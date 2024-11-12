# 🖧 TWI Driver 🖧

[![Category](https://img.shields.io/badge/Category-TWI-blue)](#) [![Platform](https://img.shields.io/badge/Platform-ATmega32-orange)](#)

## 🚀 Overview 🚀
The **TWI Driver** enables communication between the microcontroller and peripheral devices using the TWI (Two-Wire Interface) protocol, also known as I2C (Inter-Integrated Circuit). This driver provides a flexible interface for sending and receiving data with both master and slave devices. It supports various TWI operations such as sending start/stop conditions, reading and writing data, and managing slave addresses. It is ideal for applications requiring efficient serial communication with low pin usage.

## 🗂 Table of Contents 🗂
- [Features 🌟](#-features-)
- [Installation 🔧](#-installation-)
- [Configuration ⚙️](#-configuration-)
- [API Reference 📖](#-api-reference-)
- [Usage Example 💻](#-usage-example-)

---

## 🌟 Features 🌟

- **Master and Slave Communication**: Supports both master and slave initialization and communication.
- **Start, Restart, and Stop Conditions**: Functions for controlling TWI's start, restart, and stop conditions.
- **Addressing**: Functions to send slave addresses for read/write operations.
- **Data Transmission & Reception**: Supports sending and receiving bytes of data.
- **Error Handling**: Provides error handling for common TWI communication issues.

---

## 🔧 Installation 🔧

1. Clone the repository:
   ```bash
   git clone https://github.com/Bahnasy2001/AVR_Drivers.git
   ```

2. Include the TWI driver files in your project:
   - `TWI_interface.h`
   - `TWI_config.h`
   - `TWI_private.h`
   - `TWI_program.c`

3. Ensure `STD_TYPES.h` and `BIT_MATH.h` are included as dependencies for the driver.

---

## ⚙️ Configuration ⚙️

Adjust settings in **TWI_config.h** to configure the TWI interface for master or slave mode, and set the desired I2C clock speed and other relevant parameters.

---

## 📖 API Reference 📖

Here’s an overview of the key functions in `TWI_interface.h`:

- `void TWI_voidMasterInit(void);`  
  **Description**: Initializes the TWI interface in master mode with default settings.
  - **Parameters**: None.
  - **Returns**: Nothing.

- `TWI_ErrorState TWI_u8SlaveInit(u8 Copy_u8Address);`  
  **Description**: Initializes the TWI interface in slave mode and sets the slave address.
  - **Parameters**:
    - `Copy_u8Address`: The address of the slave device.
  - **Returns**: `TWI_OK` if successful, `TWI_SLA_Error` if the address is invalid.

- `TWI_ErrorState TWI_u8SendStartCondition(void);`  
  **Description**: Sends a start condition to initiate communication.
  - **Parameters**: None.
  - **Returns**: `TWI_OK` if successful, `TWI_SC_Error` if the start condition fails.

- `TWI_ErrorState TWI_u8SendReStartCondition(void);`  
  **Description**: Sends a repeated start condition to continue communication.
  - **Parameters**: None.
  - **Returns**: `TWI_OK` if successful, `TWI_RSC_Error` if the restart condition fails.

- `TWI_ErrorState TWI_u8SendStopCondition(void);`  
  **Description**: Sends a stop condition to end communication.
  - **Parameters**: None.
  - **Returns**: `TWI_OK` if successful.

- `TWI_ErrorState TWI_u8SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);`  
  **Description**: Sends the slave address with the write flag.
  - **Parameters**:
    - `Copy_u8SlaveAddress`: The address of the slave device.
  - **Returns**: `TWI_OK` if successful, `TWI_SLA_W_Error` if an error occurs.

- `TWI_ErrorState TWI_u8SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);`  
  **Description**: Sends the slave address with the read flag.
  - **Parameters**:
    - `Copy_u8SlaveAddress`: The address of the slave device.
  - **Returns**: `TWI_OK` if successful, `TWI_SLA_R_Error` if an error occurs.

- `TWI_ErrorState TWI_u8SendDataByte(u8 Copy_u8DataByte);`  
  **Description**: Sends a byte of data to the slave device.
  - **Parameters**:
    - `Copy_u8DataByte`: The data byte to send.
  - **Returns**: `TWI_OK` if successful, `TWI_MT_DATA_Error` if an error occurs.

- `TWI_ErrorState TWI_u8ReadDataByte(u8 * Copy_puReturnedDataByte);`  
  **Description**: Reads a byte of data from the slave device.
  - **Parameters**:
    - `Copy_puReturnedDataByte`: Pointer to store the received data byte.
  - **Returns**: `TWI_OK` if successful, `TWI_MR_DATA_Error` if an error occurs, `TWI_NULL_Pointer` if the pointer is null.

---

## 💻 Usage Example 💻

Here’s an example showing how to use the TWI driver in an embedded application:

1. **Initialize the Master**  
   ```c
   #include "TWI_interface.h"

   int main() {
       // Initialize TWI in master mode
       TWI_voidMasterInit();
       while (1) {
           // Application loop
       }
   }
   ```

2. **Send a Start Condition**  
   ```c
   TWI_u8SendStartCondition();
   ```

3. **Send Slave Address and Write Data**  
   ```c
   TWI_u8SendSlaveAddressWithWrite(0x50);  // Send address of the slave
   TWI_u8SendDataByte(0x10);  // Send data byte
   ```

4. **Read Data from Slave**  
   ```c
   u8 receivedData;
   TWI_u8SendSlaveAddressWithRead(0x50);  // Send address of the slave
   TWI_u8ReadDataByte(&receivedData);  // Receive data byte
   ```

5. **Send a Stop Condition**  
   ```c
   TWI_u8SendStopCondition();
   ```

---

## ✍️ Author ✍️

**Hassan Ahmed Fathy El Bahnasy**  
[LinkedIn](https://www.linkedin.com/in/hassanbahnasy/)
