#pragma once
#include <Arduino.h>

class ButtonModel
{
public:
  ButtonModel(int pin, short note);
  int getState();
  byte getNote();
private:
  int _pin;
  byte _note;
  int _state;
  int _lastState;
};