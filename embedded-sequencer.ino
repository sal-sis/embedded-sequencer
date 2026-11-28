#include "sequencer.h"
#include "oled_display.h"
#include "rgb_lcd.h"


void setup() {
  initLCD();
  initOLED();
  setupSequencer();
}


void loop() {
  runSequencer();
}
