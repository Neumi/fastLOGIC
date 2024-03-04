#include <TM1637Display.h>
#include "settingsMenu.h"

// 7-segment displays
TM1637Display display1(DIO_1, CLK_1);
TM1637Display display2(DIO_2, CLK_2);
TM1637Display display3(DIO_3, CLK_3);
TM1637Display display4(DIO_4, CLK_4);

// buttons
const int button1 = 2;
const int button2 = 3;
const int button3 = 4;

void setup() {
  // buttons as inputs
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);

  // 7-segment displays init
  display1.init();
  display2.init();
  display3.init();
  display4.init();

  // start menu
  showMainMenu();
}

void showMainMenu() {

}


void loop() {
  // read buttons 
  int button1State = digitalRead(button1);
  int button2State = digitalRead(button2);
  int button3State = digitalRead(button3);

  // menu navigation
  handleMenuNavigation(button1State, button2State, button3State);

  // update display
  updateDisplay();

  // Implementation will follow
  // ...
  
}