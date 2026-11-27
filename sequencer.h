#ifndef SEQUENCER_H
#define SEQUENCER_H

#include <Mozzi.h>

float midiToFrequency(int midiNote);
void setupSequencer();
void updateControl(); 
AudioOutput updateAudio(); 
void runSequencer(); 


#endif
