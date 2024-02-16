#include <Wire.h>
#include <SoftwareSerial.h>

// Definitionen für bessere Lesbarkeit
#define RS485_RX_PIN 2
#define RS485_TX_PIN 3
#define I2C_DEVICE_ADDRESS 0x42
#define I2C_REGISTER_ADDRESS 0x00

// SoftwareSerial-Verbindung für RS485
SoftwareSerial RS485(RS485_RX_PIN, RS485_TX_PIN);

// Funktionsprototypen
void scanI2CBus();
uint8_t readDataFromI2C();
void sendDataViaRS485(uint8_t data);

// Funktionen
void setup() {
  Serial.begin(9600);
  RS485.begin(9600);

  scanI2CBus();
}

void loop() {
  uint8_t data = readDataFromI2C();
  sendDataViaRS485(data);
}

// I2C-Funktionen
void scanI2CBus();
uint8_t readDataFromI2C();

// RS485-Funktionen
void sendDataViaRS485(uint8_t data);
