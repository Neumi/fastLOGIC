#include "fastLogic.h"

fastLogic::fastLogic() : oneWire(DS18B20_DATA), temperatureSensor(&oneWire) {
}

void fastLogic::initializePins() {
  pinMode(RELAY_A_OUT, OUTPUT);
  pinMode(RELAY_B_OUT, OUTPUT);
  pinMode(LED_A_OUT, OUTPUT);
  pinMode(LED_B_OUT, OUTPUT);

  pinMode(DIGITAL_IN_A, INPUT);
  pinMode(DIGITAL_IN_B, INPUT);
}

void fastLogic::begin() {
  initializePins();
  temperatureSensor.begin();
  lastButtonState = fastLogic::ButtonType::BUTTON_NONE;  // Use the enum here

  // Initialize relays to the OFF state
  setRelayAState(false);
  setRelayBState(false);

  // Initialize LEDs to the OFF state
  setLedAState(false);
  setLedBState(false);
}

float fastLogic::getTemperature() {
  temperatureSensor.requestTemperatures();
  return temperatureSensor.getTempCByIndex(0);
}

float fastLogic::getInputVoltage() {
  return inputVoltage;
}

float fastLogic::getAnalogInputA() {
  return analogIntputA;
}

float fastLogic::getAnalogInputB() {
  return analogIntputB;
}

boolean fastLogic::getDigitalInputA() {
  return digitalInputA;
}

boolean fastLogic::getDigitalInputB() {
  return digitalInputB;
}

int fastLogic::getButtonInput() {
  return lastButtonState;
}

int fastLogic::translateButtonInput(int analogValue) {
  if (analogValue < 45 && analogValue > 25) {
    return ButtonType::BUTTON_MINUS;
  }
  else if (analogValue < 470 && analogValue > 320) {
    return ButtonType::BUTTON_PLUS;
  }
  else if (analogValue < 20) {
    return ButtonType::BUTTON_SET;
  }
  else {
    return ButtonType::BUTTON_NONE;
  }
}

void fastLogic::refreshInputData() {
  inputVoltage = (analogRead(VOLTAGE_SENS_IN) * 5.0) / 1024.0 / (2.0 / 10.0) * 1000;
  analogIntputA = analogRead(ANALOG_IN_A);
  analogIntputB = analogRead(ANALOG_IN_B);

  digitalInputA = digitalRead(DIGITAL_IN_A);
  digitalInputB = digitalRead(DIGITAL_IN_B);

  int currentButtonState = translateButtonInput(analogRead(BUTTONS_IN));

  if (lastButtonState != currentButtonState) {
    if (currentButtonState == ButtonType::BUTTON_MINUS) Serial.println("MINUS");
    if (currentButtonState == ButtonType::BUTTON_PLUS) Serial.println("PLUS");
    if (currentButtonState == ButtonType::BUTTON_SET) Serial.println("SET");
    lastButtonState = currentButtonState;
  }
}

void fastLogic::setRelayAState(bool state) {
  digitalWrite(RELAY_A_OUT, state ? HIGH : LOW);
  relayAState = state;
}

void fastLogic::setRelayBState(bool state) {
  digitalWrite(RELAY_B_OUT, state ? HIGH : LOW);
  relayBState = state;
}

bool fastLogic::getRelayAState() {
  return relayAState;
}

bool fastLogic::getRelayBState() {
  return relayBState;
}

void fastLogic::setLedAState(bool state) {
  digitalWrite(LED_A_OUT, state ? HIGH : LOW);
  ledAState = state;
}

void fastLogic::setLedBState(bool state) {
  digitalWrite(LED_B_OUT, state ? HIGH : LOW);
  ledBState = state;
}

bool fastLogic::getLedAState() {
  return ledAState;
}

bool fastLogic::getLedBState() {
  return ledBState;
}
