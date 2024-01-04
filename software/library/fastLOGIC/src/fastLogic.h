#ifndef FASTLOGIC_H
#define FASTLOGIC_H

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

class fastLogic {
  public:
    enum ButtonType {
      BUTTON_NONE,
      BUTTON_MINUS,
      BUTTON_PLUS,
      BUTTON_SET
    };

    fastLogic();

    void begin();

    void refreshInputData();

    float getTemperature();
    float getInputVoltage();
    float getAnalogInputA();
    float getAnalogInputB();
    boolean getDigitalInputA();
    boolean getDigitalInputB();
    int getButtonInput();

    // Relay control functions
    void setRelayAState(bool state);
    void setRelayBState(bool state);

    // Relay state query functions
    bool getRelayAState();
    bool getRelayBState();

    // LED control functions
    void setLedAState(bool state);
    void setLedBState(bool state);

    // LED state query functions
    bool getLedAState();
    bool getLedBState();

  private:
    void initializePins();
    int translateButtonInput(int analogValue);

    // Pin definitions
    static const int DIGITAL_IN_A = 2;
    static const int DIGITAL_IN_B = 3;
    static const int RELAY_A_OUT = 5;
    static const int RELAY_B_OUT = 4;
    static const int TM1637_SCK = 6;
    static const int TM1637_DIO = 7;
    static const int DS18B20_DATA = 9;
    static const int LED_B_OUT = 10;
    static const int LED_A_OUT = 13;
    static const int VOLTAGE_SENS_IN = A0;
    static const int BUTTONS_IN = A1;
    static const int ANALOG_IN_A = A2;
    static const int ANALOG_IN_B = A3;

    // DS18B20 sensor
    OneWire oneWire;
    DallasTemperature temperatureSensor;

    // Internal state variables
    float inputVoltage;
    float analogIntputA;
    float analogIntputB;
    boolean digitalInputA;
    boolean digitalInputB;
    int lastButtonState;
    bool relayAState;
    bool relayBState;
    bool ledAState;
    bool ledBState;

};

#endif // FASTLOGIC_H
