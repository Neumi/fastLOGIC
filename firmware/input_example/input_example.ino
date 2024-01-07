// pin connections and base setup for fastLOGIC! controller v0.01

// pin definitions
#define DIGITAL_IN_A 2
#define DIGITAL_IN_B 3
#define RELAY_A_OUT 5
#define RELAY_B_OUT 4
#define TM1637_SCK 6
#define TM1637_DIO 7

#define DS18B20_DATA 9
#define LED_B_OUT 10
#define LED_A_OUT 13

#define VOLTAGE_SENS_IN A0
#define BUTTONS_IN A1
#define ANALOG_IN_A A2  //shared with XGZP6847A pressure sensor
#define ANALOG_IN_B A3

#define BUTTON_NONE 0
#define BUTTON_MINUS 1
#define BUTTON_PLUS 2
#define BUTTON_SET 3


float inputVoltage;
float analogIntputA;
float analogIntputB;
float inputButton;

boolean digitalInputA = 0;
boolean digitalInputB = 0;

int lastButtonState = 0;

void setup(void)
{
  Serial.begin(9600);

  pinMode(RELAY_A_OUT, OUTPUT);
  pinMode(RELAY_B_OUT, OUTPUT);
  pinMode(LED_A_OUT, OUTPUT);
  pinMode(LED_B_OUT, OUTPUT);

  pinMode(DIGITAL_IN_A, INPUT);
  pinMode(DIGITAL_IN_B, INPUT);

}

int translateButtonInput(int analogValue) {
  if (analogValue < 45 && analogValue > 25) {
    return BUTTON_MINUS;
  }
  else if (analogValue < 470 && analogValue > 320) {
    return BUTTON_PLUS;
  }
  else if (analogValue < 20) {
    return BUTTON_SET;
  }
  else {
    return BUTTON_NONE;
  }
}

void refreshInputData() {
  inputVoltage = (analogRead(VOLTAGE_SENS_IN) * 5.0) / 1024.0 / (2.0 / 10.0) * 1000;
  analogIntputA = analogRead(ANALOG_IN_A);
  analogIntputB = analogRead(ANALOG_IN_B);
  inputButton = translateButtonInput(analogRead(BUTTONS_IN));
  
  digitalInputA = digitalRead(DIGITAL_IN_A);
  digitalInputB = digitalRead(DIGITAL_IN_B);
}


void loop(void)
{
  refreshInputData();
  if ( lastButtonState != inputButton) {
    if (inputButton == BUTTON_MINUS) Serial.println("MINUS");
    if (inputButton == BUTTON_PLUS) Serial.println("PLUS");
    if (inputButton == BUTTON_SET) Serial.println("SET");
    lastButtonState = inputButton;
  }
  Serial.print("Input Voltage: ");
  Serial.println(inputVoltage);

  Serial.print("Input Analog A: ");
  Serial.println(analogIntputA);

  Serial.print("Input Analog B: ");
  Serial.println(analogIntputB);
  
  Serial.print("Input A: ");
  Serial.println(digitalInputA);
  Serial.print("Input B: ");
  Serial.println(digitalInputB);


  Serial.println("------------");
  delay(10);
}
