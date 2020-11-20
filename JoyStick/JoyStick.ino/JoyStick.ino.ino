#include <Signals.h>
int FULL_FORWARD= 671;
int FULL_REVERSE = 0;
int HANDLE_NUETRAL = 326;
int DEADBAND = 14;

 void setup() {
   Serial.begin(9600);
   pinMode(A0, INPUT);    //jstk left-right
   pinMode(A1, INPUT);    //jstk forward-back
   pinMode(A3, INPUT);
   pinMode(4, INPUT);
   pinMode(5, INPUT);    //Potentiometer input
   pinMode(7, OUTPUT);   //motor 1 AD bridge
   pinMode(8, OUTPUT);   //motor 1 AC bridge
   pinMode(9, OUTPUT);   //motor 1 power
   }

void loop() {
 int serIn;
  int CurrentPosition = analogRead(A1);
 int ForwardRange;
  int ReverseRange;
 int DB_High;
 int DB_Low; 
 float PositionPercent;
 DB_High = (HANDLE_NUETRAL + DEADBAND);
 DB_Low = (HANDLE_NUETRAL - DEADBAND);
 ForwardRange = FULL_FORWARD - DB_High;
 ReverseRange = FULL_REVERSE -DB_Low;

 if (CurrentPosition>DB_High)
 {
  PositionPercent = (float(CurrentPosition - DB_High)/ForwardRange)*100;
 }
else if (CurrentPosition<DB_Low)
 {
  PositionPercent = (float(CurrentPosition - DB_Low)/ReverseRange)*100;
 }
  else if (CurrentPosition<= DB_High && CurrentPosition >= DB_Low)
 {
  PositionPercent = 0.00;
 }
//float w =5.00/1024;
//float z = w*x*2000;
  Serial.println(String(PositionPercent)/*+","+String(w)+","+String(z)*/);
  }


