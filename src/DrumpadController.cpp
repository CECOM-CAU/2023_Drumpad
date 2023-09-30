#include "DrumpadController.h"
#include "MIDI_Helper.h"

DrumpadController::DrumpadController(int _r, int _c, unsigned long* _time){
    r = _r;
    c = _c;
    time = _time;
    buttons = new ButtonModel*[r*c];
    // leds = new LEDView*[r*c];

    for(int i = 0; i < r; i++){
        for (int j = 0; j < c; j++) {
            buttons[i*r + j] = new ButtonModel(btnPins[i*r + j], i*r + j);
            // leds[i*r + j] = new LEDView(ledPins[i*r + j], i*r + j);
        }
    }

    Serial.begin(9600);
}

void DrumpadController::getMIDICommand(){
    byte cmd = MIDI_Helper::getCommand();
    while(cmd == MIDI_Helper::GET_FAILED){
        cmd = MIDI_Helper::getCommand();
    }

    byte param[2];
    if(MIDI_Helper::validateCommand(cmd, MIDI_Helper::CMD_MIDI_NOTE_ON)){
        param[0] = MIDI_Helper::getNextParam();
        param[1] = MIDI_Helper::getNextParam();
    }
    else if(MIDI_Helper::validateCommand(cmd, MIDI_Helper::CMD_MIDI_NOTE_OFF)){
        param[0] = MIDI_Helper::getNextParam();
        param[1] = MIDI_Helper::getNextParam();
    }
}

void DrumpadController::sendMIDICommand(ButtonModel* btn, int state){
    
}

void DrumpadController::update(){
    if(Serial.available()){
        getMIDICommand();
    }

}