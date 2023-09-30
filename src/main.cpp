#include "DrumpadController.h"

#define NOTE_ON_CMD 0x90
#define NOTE_OFF_CMD   0x80
#define MAX_MIDI_VELOCITY 127

DrumpadController* controller;
unsigned long* t_ptr;
unsigned long time;
void   setup() {
  Serial.begin(9600);

  t_ptr = &time;
  controller = new DrumpadController(4, 4, t_ptr);
}

void loop() {
  time = millis();
  controller->update();

}

// // Send MIDI note ON
// void midiNoteOn(byte note,   byte midiVelocity)
// {
//   Serial.write(NOTE_ON_CMD);
//   Serial.write(note);
//    Serial.write(midiVelocity);
// }

// //Send MIDI note OFF
// void midiNoteOff(byte   note, byte midiVelocity)
// {
//   Serial.write(NOTE_OFF_CMD);
//   Serial.write(note);
//   Serial.write(midiVelocity);
// }