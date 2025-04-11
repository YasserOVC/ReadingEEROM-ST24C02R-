#include <Wire.h>

// Define the EEPROM address.  The ST24C02R typically has an address of 0x50.
#define EEPROM_ADDRESS 0x50

// Define the size of the EEPROM.  The ST24C02R is 256 bytes (2Kbit).
#define EEPROM_SIZE 256

void setup() {
  Serial.begin(9600);
  Wire.begin();

  Serial.println("Reading ST24C02R EEPROM...");
  delay(500); // Increased delay
}

void loop() {
  // Read and print the entire EEPROM contents.
  for (int address = 0; address < EEPROM_SIZE; address++) {
    byte data = readEEPROMByte(address);
    Serial.print("Address 0x");
    if (address < 16) {
      Serial.print("0");
    }
    Serial.print(address, HEX);
    Serial.print(": 0x");
    if (data < 16) {
      Serial.print("0");
    }
    Serial.println(data, HEX);
    delay(10); // Increased delay
  }
  Serial.println("Finished reading EEPROM.\n");
  while (1); // Stop after reading once
}

// Function to read a single byte from the EEPROM at a given address.
byte readEEPROMByte(int address) {
  byte data = 0;
  int error;

  Wire.beginTransmission(EEPROM_ADDRESS);
  Wire.write(address);         // Set the address to read from.
  error = Wire.endTransmission();
  if (error != 0) {
    Serial.print("Error setting address: ");
    Serial.println(error);
    return 0xFF; // Return a default error value
  }

  Wire.requestFrom(EEPROM_ADDRESS, 1); // Request one byte.
  if (Wire.available()) {
    data = Wire.read();
  } else {
    Serial.println("No data available");
    return 0xFF;
  }
  return data;
}
