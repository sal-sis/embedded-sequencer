#include <Oscil.h>
#include <tables/square_no_alias_2048_int8.h>

#include "sequencer.h"

Oscil<SQUARE_NO_ALIAS_2048_NUM_CELLS, MOZZI_AUDIO_RATE> squareOsc(SQUARE_NO_ALIAS_2048_DATA);

// Fixe octave
const int OCTAVE = 4;
const int MIDI_BASE = 12 * (OCTAVE + 1);

// assign keys: left to right
const byte keyPins[12] = {
  33, 32, 31, 30, 29, 28, 
  27, 26, 25, 24, 23, 22
};


int previousMidiNote = -1;
bool noteActive = false;


// Convert MIDI note to frequency
float midiToFrequency(int midiNote) {
  return 440.0f * powf(
      2.0f,
      (midiNote -69) / 12.0f
      );
}

void setupSequencer() {
  for(int i = 0; i < 12; i++) {
    pinMode(keyPins[i], INPUT_PULLUP);
  }

  squareOsc.setFreq(440.0f);

  startMozzi();
}

void updateControl() {
  int pressedKey = -1;
  
  // Find first pressed key 
  for(int i = 0; i < 12; i++) {
    if(digitalRead(keyPins[i]) == LOW) {
      pressedKey = i;
      break;
    }
  }

  // No key pressed
  if(pressedKey == -1) {
    noteActive = false;
    previousMidiNote = -1;
    return;
  }

  // Convert key index to MIDI number
  int midiNote = MIDI_BASE + pressedKey;

  // Update frequency only when note changes
  if(midiNote != previousMidiNote) {
    float frequency = midiToFrequency(midiNote);
    
    squareOsc.setFreq(frequency);

    previousMidiNote = midiNote;
  }

  noteActive = true;
}

AudioOutput updateAudio() {
  if(!noteActive) {
    return MonoOutput::from16Bit(0);
  }

  return MonoOutput::from16Bit((int)squareOsc.next() * 128);
}

void runSequencer() {
  audioHook();               // Keep the audio engine running
}
