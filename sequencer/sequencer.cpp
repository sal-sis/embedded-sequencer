#include <Mozzi.h>
#include <Oscil.h>
#include <tables/sin2048_int8.h>

Oscil<SIN2048_NUM_CELLS, MOZZI_AUDIO_RATE> sine(SIN2048_DATA);

int frequency = 100;
int tick = 0;

void setup() {
  sine.setFreq(frequency);  // Set the starting frequency
  startMozzi();              // Start the Mozzi sound engine
}

void updateControl() {
  tick++;                    // Count control updates

  if (tick >= 6) {           // Wait for 6 control updates
    tick = 0;                // Reset the counter
    frequency += 10;         // Increase frequency by 10 Hz

    if (frequency > 1500) {  // Check if frequency exceeds 1500 Hz
      frequency = 100;       // Reset frequency to 100 Hz
    }

    sine.setFreq(frequency); // Apply the new frequency
  }
}

AudioOutput updateAudio() {
  return MonoOutput::from16Bit((int)sine.next() * 128); // Generate the next audio sample
}

void loop() {
  audioHook();               // Keep the audio engine running
}
