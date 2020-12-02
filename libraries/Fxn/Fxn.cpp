#include <Arduino.h>
#include <Fxn.h>

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;  
Fxn :: Fxn()
{
}
void Fxn :: init()
{
  //set input pins here


  //set output pin modes here
  pinMode(led, OUTPUT);

}
int Fxn :: fade()
{


  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255)
  {
    fadeAmount = -fadeAmount;
  }
}