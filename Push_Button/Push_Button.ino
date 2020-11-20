//Encoder file
#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

//Channel defines
#define MotorA_Encoder_Channel_A 2
#define MotorA_Encoder_Channel_B 12
#define MotorB_Encoder_Channel_A 3
#define MotorB_Encoder_Channel_B 11

Encoder MotorPositionA(MotorA_Encoder_Channel_A,MotorA_Encoder_Channel_B);
Encoder MotorPositionB(MotorB_Encoder_Channel_A,MotorB_Encoder_Channel_B);

int nCdrA=0;
int nCdrB= 0;
int nCdrVal = 0;
long previousMilsec = 0;
int pressed = 0;

 
 void setup() 
 {
   Serial.begin(115200);
   pinMode(A0, INPUT);
   pinMode(A1, INPUT);
   pinMode(4, INPUT);     //Blue Button
   pinMode(5, INPUT);     //Potentiometer input
   pinMode(7, OUTPUT);    //motor 1 AD bridge
   pinMode(8, OUTPUT);    //motor 1 AC bridge
   pinMode(9, OUTPUT);    //motor 1 power

   previousMilsec = millis();

   //attachInterrupt()
//****** Interrupts *******

  //Disable interrupts
//  cli();
//
//  //Setup Timers
//  SetupTimer0();
//
//  //Start the serial port
//  Serial.begin(115200);
//
//  delay(1000);
//
//  //enable interrupts
//  sei();
  // ******** END OF SETUP ********
  }

void loop() {
  int serIn;
  float x;
  int y = digitalRead(4);         //Read in the blue button
  nCdrA= abs(MotorPositionA.read());
  //float RPM = abs(nCdrA)/44;
  //int nCdrB= MotorPositionB.read();
   button_Push();
  // if(nCdrA >19747)
  // {
  //   pressed =0; 
  // }
  motor1(7,pressed,9,120);
  String mSec = String(pressed);
  String X = String(rotation());
  String stuff = String (X + " " +nCdrA);
  Serial.println(stuff);
  //Serial.println(RPM);
  }

