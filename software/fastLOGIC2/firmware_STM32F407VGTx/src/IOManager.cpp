#include "IOManager.h"
#include "Messenger.h"
#include "Configuration.h"
#include <OneWire.h>
#include <DallasTemperature.h>

IOManager::IOManager()
{

}

void IOManager::init()
{
    OneWire oneWire(DS18B20_PIN);
    DallasTemperature sensors(&oneWire);
    //this->TempSensors = sensors;
}

// return board 5V lane voltage in millivolts
int IOManager::getBoardVoltage()
{
    int vin = (analogRead(VOLT_DETECT_PIN_5V) * 3.3) / 1024.0 / (1.0 / 2.0) * 1000;
    vin = analogRead(VOLT_DETECT_PIN_5V);
    return vin;
}

// return board INPUT lane voltage in millivolts
int IOManager::getInputVoltage()
{
    int vin = (analogRead(VOLT_DETECT_PIN_VIN) * 3.3) / 1024.0 / (1.0 / 11.0) * 1000;
    return vin;
}


int IOManager::readAnalogInA(){
    return analogRead(ANALOG_IN_A);
};
int IOManager::readAnalogInB(){
    return analogRead(ANALOG_IN_B);
};
int IOManager::readAnalogPressureSensor(){
    return analogRead(PRESSURE_SENSOR_PIN);
};

float IOManager::readDS18b20Temperature(){
    //this->tempSensors.requestTemperatures();

    /*float temperatureC = tempSensors.getTempCByIndex(0);
    if (temperatureC != DEVICE_DISCONNECTED_C) {
        return temperatureC;
    } else {
        return -255.0;
    }
    */
    return 0.0;
};

bool IOManager::readButtonStatePlus(){
    return 1;
};
bool IOManager::readButtonStateMinus(){
    return 1;
};
bool IOManager::readButtonStateSet(){
    return 1;
};

bool IOManager::readDigitalInA(){
    return digitalRead(DIGITAL_IN_A);
};
bool IOManager::readDigitalInB(){
    return digitalRead(DIGITAL_IN_B);
};

void IOManager::setRelayStateA(bool state){
    digitalWrite(RELAY_OUT_A, state);
};
void IOManager::setRelayStateB(bool state){
    digitalWrite(RELAY_OUT_B, state);
};
void IOManager::setRelayStateC(bool state){
    digitalWrite(RELAY_OUT_C, state);
};

void IOManager::setLEDStateA(bool state){
    digitalWrite(LEDA, state);
};
void IOManager::setLEDStateB(bool state){
    digitalWrite(LEDB, state);
};
void IOManager::setLEDStateC(bool state){
    digitalWrite(LEDC, state);
};
void IOManager::setLEDStateD(bool state){
    digitalWrite(LEDD, state);
};
