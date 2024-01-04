#include "fastLogic.h"

// Create an instance of the fastLogic class
fastLogic myFastLogic;

void setup() {
  // Initialize the fastLogic lib
  myFastLogic.begin();

  Serial.begin(9600);

  // Other setup code...

  myFastLogic.setLedAState(1);
  myFastLogic.setLedBState(0);
}



void loop() {
  static unsigned long lastButtonCheckTime = 0;
  unsigned long currentMillis = millis();
  const unsigned long buttonCheckInterval = 1000;  // Adjust the interval as needed (in milliseconds)

  // Check buttons at regular intervals
  if (currentMillis - lastButtonCheckTime >= buttonCheckInterval) {
    // Refresh input data
    myFastLogic.refreshInputData();

    // Read temperature from the sensor
    float temperature = myFastLogic.getTemperature();
    Serial.print("Temperature: ");
    Serial.println(temperature);

    // Read other data
    float inputVoltage = myFastLogic.getInputVoltage();
    float analogInputA = myFastLogic.getAnalogInputA();
    float analogInputB = myFastLogic.getAnalogInputB();
    boolean digitalInputA = myFastLogic.getDigitalInputA();
    boolean digitalInputB = myFastLogic.getDigitalInputB();
    int buttonInput = myFastLogic.getButtonInput();

    // Print other data
    Serial.print("Input Voltage: ");
    Serial.println(inputVoltage);

    Serial.print("Analog Input A: ");
    Serial.println(analogInputA);

    Serial.print("Analog Input B: ");
    Serial.println(analogInputB);

    Serial.print("Digital Input A: ");
    Serial.println(digitalInputA);

    Serial.print("Digital Input B: ");
    Serial.println(digitalInputB);

    Serial.print("Button Input: ");
    if (buttonInput == myFastLogic.ButtonType::BUTTON_NONE) {
      Serial.println("NONE");
    } else if (buttonInput == myFastLogic.ButtonType::BUTTON_MINUS) {
      Serial.println("MINUS");
    } else if (buttonInput == myFastLogic.ButtonType::BUTTON_PLUS) {
      Serial.println("PLUS");
    } else if (buttonInput == myFastLogic.ButtonType::BUTTON_SET) {
      Serial.println("SET");
    }

    Serial.println("------------");
    
    lastButtonCheckTime = currentMillis;
  }

  // Other continuous tasks can be added here...

  // No need for a delay, use millis() for timing

}
