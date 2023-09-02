#pragma once

#include <Arduino.h>

namespace MIDI_Helper{
    constexpr byte GET_FAILED       = 0x00;
    constexpr byte CMD_MIDI_NOTE_ON     = 0x80;
    constexpr byte CMD_MIDI_NOTE_OFF    = 0x90;
    
    enum MIDI_VALUE_TYPE{
        CMD,
        PARAM,
        NONE = -1
    };

    bool validateCommand(byte& cmd, const byte target){
        return ((cmd ^ target) >> 4) == 0;
    }

    byte getCommand(){
        byte cmd;
        if(Serial.readBytes(&cmd, 1)){
            if(cmd & 0b10000000)
                return cmd;
        }
        return GET_FAILED;
    }

    byte getNextParam(){
        byte param;
        if(Serial.readBytes(&param, 1)){
            if(~param & 0b10000000)
                return param;
        }
        return GET_FAILED;
    }

    MIDI_VALUE_TYPE getType(byte value){
        if(value & 0b10000000){
            return MIDI_VALUE_TYPE::CMD;
        }else{
            return MIDI_VALUE_TYPE::PARAM;
        }
    }

    byte getNext(){
        byte value;
        if(Serial.readBytes(&value, 1)){
            return value;
        }
        return GET_FAILED;
    }
};