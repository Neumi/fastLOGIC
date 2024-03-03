#include <Wire.h>
#include <SoftwareSerial.h>


//pins
#define RS485_RX_PIN 2
#define RS485_TX_PIN 3
#define RS485_DE_PIN 4 
#define RS485_RE_PIN 5 

#define I2C_DEVICE_ADDRESS 0x42
#define I2C_REGISTER_ADDRESS 0x00
// SoftwareSerial-Connection for RS485
SoftwareSerial RS485(RS485_RX_PIN, RS485_TX_PIN);

// function prototypes
void scanI2CBus();
uint8_t readDataFromI2C();
void sendDataViaRS485(uint8_t data);

// functions
void setup() {
  Serial.begin(9600);
  RS485.begin(9600);

  scanI2CBus();
}

void loop() {
  uint8_t data = readDataFromI2C();
  sendDataViaRS485(data);
}

// I2C-function
void scanI2CBus();
uint8_t readDataFromI2C();

// RS485-function
void sendDataViaRS485(uint8_t data);
