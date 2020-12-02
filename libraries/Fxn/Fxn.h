#ifndef Fxn_h
#define Fxn_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#include "WConstants.h"
#endif


#define led  9         // the PWM pin the LED is attached to
//#define brightness 0;    // how bright the LED is
int fadeAmount = 1;    // how many points to fade the LED by

class Fxn
{
  public:
  Fxn();
  void init();
  void fade();

  private:
  
};
#endif
