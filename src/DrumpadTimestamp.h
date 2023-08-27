#pragma once
#include <Arduino.h>
class DrumpadTimestamp{
    unsigned long startTime;
    unsigned long timestamp;
    bool buttons[4][4];
    DrumpadTimestamp(unsigned long timestamp);
    
};