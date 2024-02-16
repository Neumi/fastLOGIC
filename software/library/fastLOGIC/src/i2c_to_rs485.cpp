#include <Wire.h>
#include <SoftwareSerial.h>

#define RS485_RX_PIN 2
#define RS485_TX_PIN 3
#define RS485_DE_PIN 4 
#define RS485_RE_PIN 5 

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
  Wire.beginTransmission(I2C_DEVICE_ADDRESS);
  Wire.write(I2C_REGISTER_ADDRESS); 
  Wire.endTransmission();

  Wire.requestFrom(I2C_DEVICE_ADDRESS, 1);
  if (Wire.available()) {
    return Wire.read();
  } else {
    Serial.println("Fehler beim Lesen des I2C-Geräts");
    return 0; // change to some error message
  }
}

// function to send from the i2c bus
void sendDataViaRS485(uint8_t data) {

  digitalWrite(RS485_DE_PIN, HIGH);
  digitalWrite(RS485_RE_PIN, HIGH);

  RS485.write(data);

  digitalWrite(RS485_DE_PIN, LOW);
  digitalWrite(RS485_RE_PIN, LOW);

  // we can add here an error message aswell

}

void setup() {
  Serial.begin(9600);
  RS485.begin(9600);

  pinMode(RS485_DE_PIN, OUTPUT);
  pinMode(RS485_RE_PIN, OUTPUT);

  scanI2CBus(); 
}

void loop() {
  uint8_t data = readDataFromI2C();
  sendDataViaRS485(data);
}
