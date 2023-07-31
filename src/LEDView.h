#pragma once

#include <Arduino.h>
#include "IUpdatable.h"

class LEDView: public IUpdatable {
private:
    int _pin[3];
    int _state;
    byte _note;
    byte _velocity;

    byte* convertVelocityToRGB();
    void turnOn();
    void turnOff();

public:
    LEDView(int pins[], byte note);

    byte getNote();
    void setState(int state); // on off state
    void setVelocity(byte velocity); // set velocity
    void update();
};