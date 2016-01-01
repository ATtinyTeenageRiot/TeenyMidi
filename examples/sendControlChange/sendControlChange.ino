/*---------------------------------------------------------------------------------------------

  TeenyMidi Library
  based on Gnusbuino MIDI Library 2012 by Michael Egger
 
  SEND CONTROL CHANGE EXAMPLE
  Read a potentiometer and send its value as a continuous controller message  
  
  This example code is in the public domain.

--------------------------------------------------------------------------------------------- */
/* The circuit:
 * Potentiometer attached to analog input 0, center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground,  the other side pin to +5V
 */

#include "TeenyMidi.h" // you have to include the TeenyMidi library

#define SENSOR_PIN 2

unsigned char sensorValue = 0;         // variable to store the value coming from the sensor
unsigned char sentValue = 255;         // we only want to send data when there's something changing
                             // so we have to keep track of the last value that was sent to the host

void setup() {               

}


void loop() {
  
  sensorValue = analogRead(SENSOR_PIN) / 8;  // analogRead returns 0-1023, we need 0-127
  if (sensorValue != sentValue) {  // compare actual readout to last sent value    
       
        TeenyMidi.send(MIDI_CONTROLCHANGE,1,sensorValue);     // put new control change message into MIDI sending queue
        sentValue = sensorValue;                          // store last sent value
  }
  
    TeenyMidi.delay(10); // give some time for sending, otherwhise the MIDI queue could fill up

    TeenyMidi.update();
}


/*---------------------------------------------------------------------------------------------
Some exercises:

  - how small can the delay be without stalling the transmission ? 
  - use two control channels to augment the resolution
  - add more potentiometers  (using an array for the values?)
  
*/
