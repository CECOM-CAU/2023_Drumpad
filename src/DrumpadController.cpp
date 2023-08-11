#include "DrumpadController.h"

DrumpadController::DrumpadController(int _r, int _c, unsigned long* _time){
    r = _r;
    c = _c;
    time = _time;
    buttons = new ButtonModel*[r*c];
    leds = new LEDView*[r*c];

    for(int i = 0; i < r; i++){
        for (int j = 0; j < c; j++) {
            buttons[i*r + j] = new ButtonModel(btnPins[i*r + j], i*r + j);
            leds[i*r + j] = new LEDView(ledPins[i*r + j], i*r + j);
        }
    }

    Serial.begin(9600);
}

static byte cmd[2] = {0};
void DrumpadController::getCommand(){
    Serial.readBytes(cmd, 2);
}

void DrumpadController::sendCommand(ButtonModel* btn, int state){
    
}

void DrumpadController::update(){
    if(Serial.available()){
        this->getCommand();
    }

    cmd[0] = cmd[1] = 0;
}