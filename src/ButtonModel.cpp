#include "ButtonModel.h"


ButtonModel::ButtonModel(int pin, short note)
{
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);
  _state = 1;
  _lastState  = 1;
  _note = note;
}


int ButtonModel::getState()
{
   int  returnValue = -1;
   int state = digitalRead(_pin);
    
    if(state ==  _lastState)
      return 5;
   if(state!= _lastState)
   {
        if(state  == 0)
         {
            returnValue = 0;       
         }
         else
         {
            returnValue = 1;
         }
   }

   _lastState  = state;

   return returnValue;
}

byte ButtonModel::getNote(){
   return _note;
}