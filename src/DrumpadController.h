#pragma once
#include <Arduino.h>
#include "IUpdatable.h"
#include "LEDView.h"
#include "ButtonModel.h"

// #define MIDI_NOTE_ON    0xA0
// #define MIDI_NOTE_ON    0xB0
// #define MIDI_NOTE_ON    0xC0
// #define MIDI_NOTE_ON    0xD0


class DrumpadController: public IUpdatable{
public:
    DrumpadController(int _r, int _c, unsigned long* _time);
    void update();
private:
    int btnPins[12] = { 0 };
    int ledPins[3][12] = { 0 };

    ButtonModel** buttons;
    // LEDView** leds;
    unsigned long* time;

    int r, c;



    void getMIDICommand();
    void sendMIDICommand(ButtonModel* btn, int state);

    void checkButtons();
};
/*

ButtonModel (low, high) 
-> ButtonStateClassifier (Push Hold None YET)
-> DrumpadController (On Off)



*/