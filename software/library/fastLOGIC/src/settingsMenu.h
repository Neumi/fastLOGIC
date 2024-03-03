#ifndef MENUE_H
#define MENUE_H

// constants
#define ANZAHL_MENUEOPTIONEN 3

// variables
extern int hauptmenuOption;
extern int submenuOption;

// functions
void showMainMenu();
void showSubmenu1();
void handleMenuNavigation(int button1State, int button2State, int button3State);
void updateDisplay();
// adding new functions

#endif