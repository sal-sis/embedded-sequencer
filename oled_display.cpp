#include "oled_display.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

// Initialize the OLED display
void initOLED() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
}

// Update the information shown on the OLED display
void updateOLED(int octave, const char* waveform, int track, int totalTracks, const char* status) {
    display.clearDisplay();

    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print("Octave: ");
    display.println(octave);

    display.setTextSize(1);
    display.setCursor(0, 48);
    display.print("Track: ");
    display.print(track);
    display.print("/");
    display.println(totalTracks);

    display.print("Status: ");
    display.println(status);

    display.display();
}
