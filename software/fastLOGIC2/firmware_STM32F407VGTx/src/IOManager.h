#pragma once
#include <Arduino.h>
#include "Messenger.h"


class IOManager
{
private:
    byte eStopPin;
    byte endStopPin;
    byte diagPin;
    byte faultPin;
    byte voltDetectPin;
    bool jobDone;

    

    //DallasTemperature TempSensors;
    void init();

public:
    int boardlVoltage;
    int externalVoltage;
    int currentSenseA;
    int currentSenseB;
    int currentSenseC;

    IOManager();
    
    
    int getBoardVoltage();
    int getInputVoltage();

    int readCurrentSenseA();
    int readCurrentSenseB();
    int readCurrentSenseC();

    int readAnalogInA();
    int readAnalogInB();

    int readAnalogPressureSensor();

    float readDS18b20Temperature();

    bool readButtonStatePlus();
    bool readButtonStateMinus();
    bool readButtonStateSet();

    bool readDigitalInA();
    bool readDigitalInB();

    void setRelayStateA(bool state);
    void setRelayStateB(bool state);
    void setRelayStateC(bool state);

    void setLEDStateA(bool state);
    void setLEDStateB(bool state);
    void setLEDStateC(bool state);
    void setLEDStateD(bool state);

    //int getTime();


    //bool startUpCheck(Messenger messenger);    
};
