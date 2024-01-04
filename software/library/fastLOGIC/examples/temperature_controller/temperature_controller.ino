/*
 * Example to use DS18b20 temperature sensor and relay output for fridge
 * temperature control.
 * The display shows the current temperature. Change hysteresis and setTemp
 * as you like.
 */


#include <fastLogic.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 6
#define DIO 7

#define UPDATE_INTERVAL 500

TM1637Display display(CLK, DIO);

// Create an instance of the fastLogic class
fastLogic myFastLogic;
float temperature;

float hysteresis = 1.5;

float setTemp = 7.0;

void setup() {
  // Initialize the fastLogic lib
  myFastLogic.begin();
  
  Serial.begin(9600);

  display.setBrightness(0x0a);
}

void loop() {
  static float lastTemperature = -1.0;

  unsigned long currentMillis = millis();

  // Check temperature at regular intervals
  if (currentMillis - lastTemperature >= UPDATE_INTERVAL) {
    temperature = myFastLogic.getTemperature();

    // Update the display only when the temperature changes
    if (temperature != lastTemperature) {
      // Multiply by 10 to shift the decimal point, then use modulo to get one digit after the decimal point
      int tempInt = int(temperature * 10);
      int digitAfterDecimal = tempInt % 10;

      // Set the display with one digit after the decimal point, centered
      display.showNumberDecEx(tempInt / 1, 0b00100000, false);
      lastTemperature = temperature;
    }
  }

   if (temperature >= setTemp + hysteresis) {
    myFastLogic.setRelayAState(1);  // Turn on relay when temperature is above the set temperature + hysteresis
  }
  else if (temperature <= setTemp - hysteresis) {
    myFastLogic.setRelayAState(0);  // Turn off relay when temperature is below the set temperature - hysteresis
  }
}
