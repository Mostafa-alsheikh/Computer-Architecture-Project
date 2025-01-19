# 4-Bit ALU Implementation

## Description
This project involves building a 4-bit Arithmetic Logic Unit (ALU) capable of performing basic operations like addition, subtraction, AND, OR, and XOR. The ALU will be controlled through user inputs on an Arduino Uno, with the results displayed on LEDs and an I2C LCD screen.

## Required Components
- **Arduino Uno**
- **2x 4-bit DIP switch** (for input data)
- **LEDs** (for output bits)
- **Push buttons** (for operation selection: add, subtract, AND, OR, XOR, etc.)
- **Resistors** (100Ω for LEDs)
- **Breadboard and connecting wires**
- **I2C LCD** (to display the whole operation)
- **Serial Terminal** (for executing operations)

## Functionality
- **Inputs**: Two 4-bit numbers represented by the DIP switches.
- **Operation Selection**: Push buttons are used to select the operation (e.g., addition, subtraction, AND, OR, XOR).
- **Output**: The result of the operation is displayed in binary on the LEDs.
- **LCD**: The I2C LCD displays the complete operation (input data, selected operation, and result).
- **Serial Terminal**: The operation can also be executed through the serial terminal for remote control.

## Operation
1. The user sets two 4-bit binary inputs using the DIP switches.
2. The user selects an operation (Add/Sub/AND/OR/XOR) using the push buttons.
3. The result of the operation is displayed on the LEDs in binary format.
4. The operation is also shown on the I2C LCD.
5. The serial terminal can be used to execute the operation by sending the appropriate commands.

## Notes
- The LEDs will light up based on the binary output of the operation.
- Ensure proper connections of the LEDs, switches, and buttons with the Arduino Uno.
- The project can be extended with more complex operations or an improved user interface.
