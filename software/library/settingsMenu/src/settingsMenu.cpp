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
  static int currentTopMenu = 0;
  static int currentSubMenu = -1; // -1 indicates main menu level
  static int currentOption = 0;

  if (button1State == LOW) { // Cycle top-level menu
    currentTopMenu = (currentTopMenu + 1) % NUM_TOP_MENUS; // Adjust NUM_TOP_MENUS
    currentSubMenu = -1; // Reset to main menu level
  } else if (button2State == LOW) { // Enter Submenu / Cycle Options
    if (currentSubMenu == -1) {
      currentSubMenu = 0; // Enter submenu
    } else {
      currentOption = (currentOption + 1) % NUM_OPTIONS_PER_SUBMENU; // Adjust ...
    }
  } else if (button3State == LOW) {
    // Handle value modification (more complex)
  }
}


void updateDisplay() {
  if (currentSubMenu == -1) { // Main Menu Level
    if (currentTopMenu == 0) {
      showText(display1, "baud");
    } else if (currentTopMenu == 1) {
      showText(display1, "rs48");
    } // ... add more cases

    showText(display3, "Entr"); // Indicate submenu entry
  } else { // Submenu Level
    // Example based on 'baud' submenu
    if (currentTopMenu == 0) { 
      showText(display1, "basud");
      showNumber(display3, currentOption + 2400); // Assuming your options are 2400, 4800, ...
    } // ... add more cases
  } 
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