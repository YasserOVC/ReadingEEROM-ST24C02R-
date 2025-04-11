# Arduino EEPROM Reader

## Description

This project provides an Arduino sketch to read data from a serial EEPROM (specifically the ST24C02R) using the I2C communication protocol. The code reads the entire contents of the EEPROM (256 bytes) and prints the address and data to the Arduino Serial Monitor.

## Hardware

* Arduino Mega
* ST24C02R EEPROM
* Breadboard
* Jumper wires
* Pull-up resistors (2.2kΩ to 10kΩ)

## Wiring

Connect the EEPROM to the Arduino Mega as follows:

| EEPROM Pin | Arduino Mega Pin |
| :---------- | :--------------- |
| VCC         | 3.3V or 5V       |
| GND         | GND              |
| SDA         | 20 (SDA)         |
| SCL         | 21 (SCL)         |
| WP (Write Protect) | GND              |

**Important:**

* Ensure you have pull-up resistors (2.2kΩ to 10kΩ) connected between:
    * Arduino Mega 3.3V/5V and SDA (Pin 20)
    * Arduino Mega 3.3V/5V and SCL (Pin 21)
* Connect the WP (Write Protect) pin of the EEPROM to GND to enable writing (if needed).  Connecting it to VCC will prevent writing.

## Software

The Arduino sketch (`.ino` file) is provided in this repository. It uses the Arduino `Wire` library for I2C communication.

### Code Overview

* **Includes:** The `Wire.h` library is included.
* **Defines:**
    * `EEPROM_ADDRESS`:  The I2C address of the EEPROM (0x50 for ST24C02R).
    * `EEPROM_SIZE`: The size of the EEPROM in bytes (256 for ST24C02R).
* **`setup()`:**
    * Initializes serial communication.
    * Initializes the I2C bus.
    * Prints a starting message.
* **`loop()`:**
    * Iterates through each address of the EEPROM (0 to 255).
    * Calls `readEEPROMByte()` to read the data at the current address.
    * Prints the address and data to the Serial Monitor in hexadecimal format.
    * Includes a small delay.
    * Stops reading after completing one pass.
* **`readEEPROMByte(int address)`:**
    * A function that reads a single byte from the EEPROM at the specified address.
    * Uses the `Wire` library to communicate with the EEPROM.

## How to Use

1.  Connect the EEPROM to the Arduino Mega as described in the "Wiring" section.
2.  Open the Arduino IDE.
3.  Create a new sketch and copy the code from the `.ino` file into the sketch.
4.  Select the correct Arduino Mega board and port in the Arduino IDE.
5.  Upload the sketch to the Arduino Mega.
6.  Open the Serial Monitor in the Arduino IDE to see the output.

## Output

The Serial Monitor will display the EEPROM data in the following format:

Address 0x00: 0xXXAddress 0x01: 0xXX...Address 0xFF: 0xXXFinished reading EEPROM.
Where `XX` is the hexadecimal value of the data byte at that address.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please feel free to submit a pull request or open an issue.
