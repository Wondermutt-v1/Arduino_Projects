#include <TimerOne.h>
#include <Fxn.h>
static int brt;
 
void setup() 
{
  // Initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards
  //pinMode(13, OUTPUT);  
    // declare pin 9 to be an output:
  pinMode(led, OUTPUT);  
  
  Timer1.initialize(3000000); // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
  Timer1.attachInterrupt( timerIsr ); // attach the service routine here
}
 
void loop()
{ 
  
  Fxn.fade();
  delay(60);
}
 
/// --------------------------
/// Custom ISR Timer Routine
/// --------------------------
//void timerIsr()
//{
//    // Toggle LED
//    digitalWrite( 13, digitalRead( 13 ) ^ 1 );
//}

//void fade()
//{
//      // set the brightness of pin 9:
//  analogWrite(led, brightness);
//
//  // change the brightness for next time through the loop:
//  brightness = brightness + fadeAmount;
//
//  // reverse the direction of the fading at the ends of the fade:
//  if (brightness <= 0 || brightness >= 255)
//  {
//    fadeAmount = -fadeAmount;
//  }
//}
