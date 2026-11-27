#include "rgb_lcd.h"

#include <Wire.h>
#include <DFRobot_RGBLCD1602.h>

DFRobot_RGBLCD1602 lcd(0x60, 16, 2);

// Initialize the RGB LCD
void initLCD() {
    lcd.init();
    lcd.setRGB(255, 255, 255);
}

// Update the text shown on the LCD
void updateLCD(const char* line1, const char* line2) {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print(line1);

    lcd.setCursor(0, 1);
    lcd.print(line2);
}
