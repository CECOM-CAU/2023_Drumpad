#pragma once
#include <Arduino.h>
#include "IUpdatable.h"
#include "LEDView.h"
#include "ButtonModel.h"

class DrumpadController: public IUpdatable{
public:
    DrumpadController(int r, int c);
    
    void update();
private: 
    ButtonModel* buttons;
    LEDView* leds;

    void getCommand();

};
