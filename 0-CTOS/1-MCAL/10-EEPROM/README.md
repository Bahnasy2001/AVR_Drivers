# 📝 EEPROM Internal Driver 📝

[![Category](https://img.shields.io/badge/Category-EEPROM-blue)](#) [![Platform](https://img.shields.io/badge/Platform-ATmega32-orange)](#)

## 🚀 Overview 🚀
The **EEPROM Internal Driver** enables reading from and writing to the EEPROM (Electrically Erasable Programmable Read-Only Memory) of the ATmega32 microcontroller. This driver provides a set of APIs for byte and block read/write operations, allowing persistent data storage across power cycles. Ideal for applications requiring non-volatile data storage such as configurations, calibration data, or small data logs.

## 🗂 Table of Contents 🗂
- [Features 🌟](#-features-)
- [Installation 🔧](#-installation-)
- [Configuration ⚙️](#-configuration-)
- [API Reference 📖](#-api-reference-)
- [Usage Example 💻](#-usage-example-)

---

## 🌟 Features 🌟

- **Byte-Level Operations**: Allows writing and reading individual bytes.
- **Block-Level Operations**: Supports writing and reading multiple bytes (blocks) at once.
- **Write Completion Check**: Ensures operations are completed before proceeding.
- **Error Handling**: Detects invalid address and data errors for reliable operation.

---

## 🔧 Installation 🔧

1. Clone the repository:
   ```bash
   git clone https://github.com/Bahnasy2001/AVR_Drivers.git
   ```

2. Include the EEPROM driver files in your project:
   - `EEPROM_Int_interface.h`
   - `EEPROM_Int_config.h`
   - `EEPROM_Int_private.h`
   - `EEPROM_Int_program.c`

3. Ensure `STD_TYPES.h` and `BIT_MATH.h` are included as dependencies for the driver.

---

## ⚙️ Configuration ⚙️

Configure **EEPROM_Int_config.h** as needed, based on the EEPROM settings or project-specific configurations.

---

## 📖 API Reference 📖

Here’s an overview of the key functions in `EEPROM_Int_interface.h`:

- `u8 EEPROM_u8WriteByte(u16 Copy_u16addr, u8 Copy_u8Byte);`  
  **Description**: Writes a single byte to a specified EEPROM address.
  - **Parameters**:
    - `Copy_u16addr`: Address in EEPROM to write to.
    - `Copy_u8Byte`: Data byte to write.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if the address is invalid.

- `u8 EEPROM_u8ReadByte(u16 Copy_u16addr, u8 * Copy_pu8ReturnedByte);`  
  **Description**: Reads a single byte from a specified EEPROM address.
  - **Parameters**:
    - `Copy_u16addr`: Address in EEPROM to read from.
    - `Copy_pu8ReturnedByte`: Pointer to store the read data.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if the address is invalid or the pointer is NULL.

- `u8 EEPROM_u8WriteBlock(u16 Copy_u16startAddr, const u8 *Copy_u8Data, u16 Copy_u16length);`  
  **Description**: Writes a block of data starting from a specified EEPROM address.
  - **Parameters**:
    - `Copy_u16startAddr`: Starting address in EEPROM for the block write.
    - `Copy_u8Data`: Pointer to the data array to write.
    - `Copy_u16length`: Number of bytes to write.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if any address or pointer issues occur.

- `u8 EEPROM_u8ReadBlock(u16 Copy_u16startAddr, u8 * Copy_pu8ReturnedData, u16 Copy_u16length);`  
  **Description**: Reads a block of data starting from a specified EEPROM address.
  - **Parameters**:
    - `Copy_u16startAddr`: Starting address in EEPROM for the block read.
    - `Copy_pu8ReturnedData`: Pointer to store the read data array.
    - `Copy_u16length`: Number of bytes to read.
  - **Returns**: `STD_TYPES_OK` if successful, `STD_TYPES_NOK` if any address or pointer issues occur.

---

## 💻 Usage Example 💻

Here’s an example showing how to use the EEPROM driver in an embedded application:

1. **Write a Byte to EEPROM**  
   ```c
   #include "EEPROM_Int_interface.h"

   int main() {
       // Write a single byte
       EEPROM_u8WriteByte(0x10, 0x5A);
       while (1) {
           // Application loop
       }
   }
   ```

2. **Read a Byte from EEPROM**  
   ```c
   u8 receivedByte;
   EEPROM_u8ReadByte(0x10, &receivedByte);
   ```

3. **Write a Block to EEPROM**  
   ```c
   u8 dataBlock[] = {0x01, 0x02, 0x03, 0x04};
   EEPROM_u8WriteBlock(0x20, dataBlock, 4);
   ```

4. **Read a Block from EEPROM**  
   ```c
   u8 readBlock[4];
   EEPROM_u8ReadBlock(0x20, readBlock, 4);
   ```

---

## ✍️ Author ✍️

**Hassan Ahmed Fathy El Bahnasy**  
[LinkedIn](https://www.linkedin.com/in/hassanbahnasy/)
