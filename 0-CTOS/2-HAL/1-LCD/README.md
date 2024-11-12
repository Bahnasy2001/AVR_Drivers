# 🖥️ LCD Driver 🖥️

[![Category](https://img.shields.io/badge/Category-LCD-blue)](#) [![Platform](https://img.shields.io/badge/Platform-ATmega32-orange)](#)

## 🚀 Overview 🚀
The **LCD Driver** provides an interface for controlling and interacting with LCD displays using a microcontroller. This driver supports common operations like sending commands, displaying characters, writing strings, displaying numbers, and more. It's ideal for applications requiring visual output on an LCD screen, such as user interfaces for embedded systems.

## 🗂 Table of Contents 🗂
- [Features 🌟](#-features-)
- [Installation 🔧](#-installation-)
- [Configuration ⚙️](#-configuration-)
- [API Reference 📖](#-api-reference-)
- [Usage Example 💻](#-usage-example-)

---

## 🌟 Features 🌟

- **LCD Initialization**: Initialize the LCD for use with default settings.
- **Command Sending**: Send commands to control LCD behavior (e.g., clear screen, cursor position).
- **Character Display**: Display a single character on the screen.
- **String Display**: Display a full string of text on the LCD.
- **Number Display**: Display numbers on the LCD, including handling large numbers.
- **Cursor Control**: Set the cursor position for text output.
- **Special Characters**: Display custom special characters on the screen.
- **Half Command Sending**: Send half commands to control the LCD in 4-bit mode.

---

## 🔧 Installation 🔧

1. Clone the repository:
   ```bash
   git clone https://github.com/Bahnasy2001/AVR_Drivers.git
   ```

2. Include the LCD driver files in your project:
   - `LCD_interface.h`
   - `LCD_config.h`
   - `LCD_private.h`
   - `LCD_program.c`

3. Ensure `STD_TYPES.h` and `BIT_MATH.h` are included as dependencies for the driver.

---

## ⚙️ Configuration ⚙️

Adjust settings in **LCD_config.h** to configure the LCD interface (e.g., number of lines, 4-bit or 8-bit mode). You can also configure pin mappings for the data and control pins of the LCD.

---

## 📖 API Reference 📖

Here’s an overview of the key functions in `LCD_interface.h`:

- `void LCD_voidInit(void);`  
  **Description**: Initializes the LCD to be ready for operation.
  - **Parameters**: None.
  - **Returns**: Nothing.

- `void LCD_voidSendCmnd(u8 Copy_u8Cmnd);`  
  **Description**: Sends a command to the LCD to control its behavior.
  - **Parameters**:
    - `Copy_u8Cmnd`: The command byte to send to the LCD.
  - **Returns**: Nothing.

- `void LCD_voidSendChar(u8 Copy_u8Char);`  
  **Description**: Displays a single character on the LCD.
  - **Parameters**:
    - `Copy_u8Char`: The character to display.
  - **Returns**: Nothing.

- `void LCD_voidWriteString(u8* Copy_pu8String);`  
  **Description**: Displays a string of characters on the LCD.
  - **Parameters**:
    - `Copy_pu8String`: A pointer to the string to display.
  - **Returns**: Nothing.

- `void LCD_voidWriteNumber(u32 Copy_u32Number);`  
  **Description**: Displays a number on the LCD.
  - **Parameters**:
    - `Copy_u32Number`: The number to display.
  - **Returns**: Nothing.

- `u8 LCD_u8GoToXY(u8 Copy_u8LineNum, u8 Copy_u8Location);`  
  **Description**: Moves the cursor to a specific location on the LCD.
  - **Parameters**:
    - `Copy_u8LineNum`: The line number (1 or 2).
    - `Copy_u8Location`: The location on the line (0-15).
  - **Returns**: `0` if successful, error code otherwise.

- `void LCD_voidClearScreen(void);`  
  **Description**: Clears the LCD screen and resets the cursor to the home position.
  - **Parameters**: None.
  - **Returns**: Nothing.

- `u8 LCD_voidWriteSpecialChar(u8 Copy_u8CharNum, u8* Copy_pu8Char, u8 Copy_u8LineNum, u8 Copy_u8Location);`  
  **Description**: Displays a special character on the LCD.
  - **Parameters**:
    - `Copy_u8CharNum`: The character number.
    - `Copy_pu8Char`: Pointer to the custom character data.
    - `Copy_u8LineNum`: The line number (1 or 2).
    - `Copy_u8Location`: The location on the line (0-15).
  - **Returns**: `0` if successful, error code otherwise.

- `void LCD_voidSendHalfCmnd(u8 Copy_u8HalfCmnd);`  
  **Description**: Sends half a command to the LCD in 4-bit mode.
  - **Parameters**:
    - `Copy_u8HalfCmnd`: The half command to send.
  - **Returns**: Nothing.

---

## 💻 Usage Example 💻

Here’s an example showing how to use the LCD driver in an embedded application:

1. **Initialize the LCD**  
   ```c
   #include "LCD_interface.h"

   int main() {
       // Initialize the LCD
       LCD_voidInit();
       while (1) {
           // Application loop
       }
   }
   ```

2. **Display a Character**  
   ```c
   LCD_voidSendChar('A');
   ```

3. **Display a String**  
   ```c
   LCD_voidWriteString("Hello World");
   ```

4. **Display a Number**  
   ```c
   LCD_voidWriteNumber(12345);
   ```

5. **Clear the Screen**  
   ```c
   LCD_voidClearScreen();
   ```

6. **Move Cursor to Specific Location**  
   ```c
   LCD_u8GoToXY(1, 5);  // Line 1, Location 5
   ```

---

## ✍️ Author ✍️

**Hassan Ahmed Fathy El Bahnasy**  
[LinkedIn](https://www.linkedin.com/in/hassanbahnasy/)
