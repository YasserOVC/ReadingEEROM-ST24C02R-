#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin();

  Serial.println("I2C Scanner");
}

void loop() {
  byte error, address;
  int nDevices;

  nDevices = 0;
  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
      nDevices++;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\\n");
  else
    Serial.println("done\\n");

  delay(5000); // Wait 5 seconds for next scan
}
