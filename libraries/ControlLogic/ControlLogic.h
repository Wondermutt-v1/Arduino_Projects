#ifndef ControlLogic_h
#define ControlLogic_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#include "WConstants.h"

#endif
#include <Encoder.h>
#include <EEPROM.h>





class ControlLogic
{
private:
    /* data */
public:

    //
    ControlLogic();

    //
    void SendCANMessage(int data[]);

    //void
    void PID();
};

#endif