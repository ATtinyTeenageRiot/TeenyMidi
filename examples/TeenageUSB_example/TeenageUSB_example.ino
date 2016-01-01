#include "TeenyMidi.h"

unsigned long lastTime;            // variable to store the last time we sent a chord

void setup() {

}


void loop() {

  if (millis()-lastTime >= 500)  {             // every 500 miliseconds = 2 times per second        
         TeenyMidi.send(MIDI_NOTEON,60,127);            // put three notes into the MIDI send queue
         TeenyMidi.send(MIDI_NOTEON,64,127);
         TeenyMidi.send(MIDI_NOTEON,67,127);
         lastTime = millis();      
  }   

  TeenyMidi.update();

}
