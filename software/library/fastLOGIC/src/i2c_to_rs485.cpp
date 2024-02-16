#include <Wire.h>
#include <SoftwareSerial.h>


#define RS485_RX_PIN 2
#define RS485_TX_PIN 3
#define I2C_DEVICE_ADDRESS 0x42
#define I2C_REGISTER_ADDRESS 0x00

SoftwareSerial RS485(RS485_RX_PIN, RS485_TX_PIN); 

// Function for scanning the i2c bus for devices
void scanI2CBus() {
  Serial.println("Suche nach I2C-Geräten...");
  for (uint8_t address = 0; address < 128; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("I2C-Gerät gefunden mit der Adresse: 0x");
      Serial.println(address, HEX);
    }
  }
  Serial.println("Ende Scan.");
}

// function to read from the i2c bus
uint8_t readDataFromI2C() {

}

// function to send from the i2c bus
void sendDataViaRS485(uint8_t data) {
  // Möglicherweise RS485 DE/RE Treiberkontrolle hinzufügen

  RS485.write(data);

  // Möglicherweise Fehlercode oder Quittung behandeln 
}

void setup() {
  Serial.begin(9600);
  RS485.begin(9600);

  scanI2CBus(); 
}

void loop() {
  uint8_t data = readDataFromI2C();
  sendDataViaRS485(data);
}
