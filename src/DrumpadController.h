#pragma once
#include <Arduino.h>
#include "IUpdatable.h"
#include "LEDView.h"
#include "ButtonModel.h"

class DrumpadController: public IUpdatable{
public:
    DrumpadController(int _r, int _c, unsigned long* _time);
    void update();
private:

    int btnPins[12] = { 0 };
    int ledPins[3][12] = { 0 };

    ButtonModel** buttons;
    LEDView** leds;
    unsigned long* time;

    int r, c;

    void getCommand();
    void sendCommand(ButtonModel* btn, int state);

    void checkButtons();
};
/*

ButtonModel (low, high) 
-> ButtonStateClassifier (Push Hold None YET)
-> DrumpadController (On Off)



*/