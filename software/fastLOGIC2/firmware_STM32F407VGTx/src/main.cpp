#include <Arduino.h>
#include <U8x8lib.h>
#include <STM32RTC.h>
#include "Configuration.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "IOManager.h"


// Define your hardware pins for the display
#define LCD_BG_LED_PIN PE9
#define LCD_SI PE10
#define LCD_SCL PE11    
#define LCD_RS PE12
#define LCD_RSE PE13
#define LCD_CS PE14

// Initialize display
U8X8_ST7565_LX12864_4W_SW_SPI u8x8(
  /* clock=*/ LCD_SCL, 
  /* data=*/ LCD_SI, 
  /* cs=*/ LCD_CS, 
  /* dc=*/ LCD_RS, 
  /* reset=*/ LCD_RSE
);

// Initialize RTC
STM32RTC& rtc = STM32RTC::getInstance();
#define ONE_WIRE_BUS  // Adjust this to your pin

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(DS18B20_PIN);

// Pass the oneWire reference to DallasTemperature library
DallasTemperature DS18b20Sensors(&oneWire);

// Define the CP2102 serial port
HardwareSerial Serial1(UC_RX, UC_TX);

IOManager ioManager;  // Correct: Declare an instance of IOManager


void setup() {
  // Setup LCD backlight
  pinMode(LCD_BG_LED_PIN, OUTPUT);
  digitalWrite(LCD_BG_LED_PIN, HIGH);
  Serial1.begin(115200);

  // Initialize the display
  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
  u8x8.setContrast(63);

  // Display startup message
  u8x8.clear();
  u8x8.println("DS18b20 Example");
  delay(200);

  
  DS18b20Sensors.begin();

}

void loop() {

  DS18b20Sensors.requestTemperatures();

  // Fetch the temperature in Celsius
  float temperatureC = DS18b20Sensors.getTempCByIndex(0);

  // Print the temperature to Serial
  if (temperatureC != DEVICE_DISCONNECTED_C) {
    Serial1.print("Temperature: ");
    Serial1.print(temperatureC);
    Serial1.println(" °C");

    u8x8.clear();
    u8x8.print(temperatureC);
    u8x8.println(" °C");

    u8x8.print("VCC: ");
    u8x8.println(ioManager.getBoardVoltage());
    u8x8.print("VIN: ");
    u8x8.println(ioManager.getInputVoltage());

    u8x8.print("V anlg. A: ");
    u8x8.print(ioManager.readAnalogInA());

    // refresh only the temperature display area
    
  } else {
    Serial1.println("Error: Could not read temperature");
  }


  delay(500); // Update every second

  
}
