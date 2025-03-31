#pragma once

const String version = "0.21"; // software version

#define STATIC_IP 0 // when set 1, DHCP is enabled, when 0, statis IP is used

#define DEBUG_MODE 1 // when set 1, debugging output is enabled

#define BAUD_SPEED 9600 // debug and message baud speed

#define SYS_VOL 3.3 // system voltage in volts

#define BUFFER_SIZE 256 // communication buffer size

#define LOCAL_PORT 8888 // local UDP port

#define STANDARD_REMOTE_SENSOR_PORT 5000 // remote machines receiving UDP port

#define DEFAULT_DISPLAY_REFRESH_TIME 100 // milliseconds until new data is shown
#define DEFAULT_FEEDBACK_TIME 100 // milliseconds until hearbeat


// scheduler modes
#define standby 0 // waiting for instructions
#define running 1 // running drive loop

// connection modes
#define CONNECTION_STAT "STAT"
#define CONNECTION_DHCP "DHCP"
#define CONNECTION_USB "USB "
 

// I/O
#define LED_PIN PC13

#define LCD_BG_LED_PIN PE9
#define LCD_SI PE10
#define LCD_SCL PE11    
#define LCD_RS PE12
#define LCD_RSE PE13
#define LCD_CS PE14

#define SD_DET PE15
#define SD_CMD PD2
#define SD_D0 PC8
#define SD_D1 PC9
#define SD_D2 PC10
#define SD_D3 PC11
#define SD_CLK PC12

#define MAX485_DI PC6
#define MAX485_RO PC7
#define MAX485_RE PD14
#define MAX485_DE PD15

#define ETHERNET_INT PA3
#define ETHERNET_RST PA2
#define ETHERNET_CS PA1
#define ETHERNET_MISO PA6
#define ETHERNET_MOSI PA7
#define ETHERNET_SCK PA5

#define DS18B20_PIN PD12

#define TX1 PA9
#define RX1 PA10
#define TX2 PD5
#define RX2 PD6

#define SCL1 PB6
#define SDA1 PB7
#define SCL2 PB10
#define SDA2 PB11

#define LEDA PB15
#define LEDB PB14
#define LEDC PB13
#define LEDD PB12

#define DIGITAL_IN_A PE7
#define DIGITAL_IN_B PE8

#define RELAY_OUT_A PD0
#define RELAY_OUT_B PD1
#define RELAY_OUT_C PD3

#define BUTTON_SET_IN PD4
#define BUTTON_PLUS_IN PD7
#define BUTTON_MINUS_IN PB3

#define VOLT_DETECT_PIN_5V PE0 // false pinmap NOT SUITABLE FOR ADC VOLTAGE MEASUREMENT
#define VOLT_DETECT_PIN_VIN PB0

#define ANALOG_IN_A PC5
#define ANALOG_IN_B PC4

#define PRESSURE_SENSOR_PIN PE1 // false pinmap NOT SUITABLE FOR ADC PRESSURE MEASUREMENT

#define CURRENT_SENSE_PIN_A PC2
#define CURRENT_SENSE_PIN_B PC1
#define CURRENT_SENSE_PIN_C PC0

#define UC_TX PA9
#define UC_RX PA10
