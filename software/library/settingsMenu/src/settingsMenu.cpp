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
  // Need to check setup
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

void handleMenuNavigation(int button1State, int button2State, int button3State) {
  static int currentMenu = 0; 
  static int currentSubmenu = 0;
  static int currentOption = 0;

  if (button1State == LOW) { // Cycle main menus
    currentMenu = (currentMenu + 1) % 3; // Assuming 3 main menus
  } else if (button2State == LOW) { // Enter submenu / cycle options
    if (currentSubmenu == 0) {
        currentSubmenu = 1; // Enter options mode
    } else {
        currentOption = (currentOption + 1) % 4; // Assuming 4 options 
    }  
  } else if (button3State == LOW) {
    // Handle value modification (more complex, depends on your settings data)
  }
}

void updateDisplay() {
  display1.showNumberDec(currentMenu);

  if (currentSubmenu == 0) { 
    display2.showNumberDec(0); // Indicate main menu mode
  } else {
    display2.showNumberDec(currentOption);
  }

  // Get the value to display. Assuming you have something like:
  int currentValue = getOptionValue(currentMenu, currentSubmenu, currentOption); 

  // Logic to split currentValue and send it to display3 and display4
  // ...
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