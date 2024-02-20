#include <Wire.h>
#include <SoftwareSerial.h>
#include <i2c_to_rs485.h>

SoftwareSerial RS485(RS485_RX_PIN, RS485_TX_PIN); 

// Function for scanning the i2c bus for devices
void scanI2CBus() {
  Serial.println("Looking for I2C devices...");
  for (uint8_t address = 0; address < 128; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("I2C-Device found with the adress: 0x");
      Serial.println(address, HEX);
    }
  }
  Serial.println("End of the scan.");
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
    Serial.println("Error while reading from i2c device");
    return 0; // change to some error message
  }
}

// function to send from the i2c bus
void sendDataViaRS485(uint8_t data) {

  //set high for data transmit
  digitalWrite(RS485_DE_PIN, HIGH);
  digitalWrite(RS485_RE_PIN, HIGH);

  RS485.write(data);

  //and low for data receive
  digitalWrite(RS485_DE_PIN, LOW);
  digitalWrite(RS485_RE_PIN, LOW);

  // we can add here an error message aswell

}

void setup() {
  Serial.begin(9600);
  RS485.begin(9600);

  //set pins for rs485
  pinMode(RS485_DE_PIN, OUTPUT);
  pinMode(RS485_RE_PIN, OUTPUT);

  scanI2CBus(); 
}

void loop() {

  //read and send
  uint8_t data = readDataFromI2C();
  sendDataViaRS485(data);
}
