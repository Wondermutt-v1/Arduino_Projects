/*This program reads the encoder*/
//include files
//****************************
#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

//Channel defines
#define MotorA_Encoder_Channel_A 2
#define MotorA_Encoder_Channel_B 12
#define MotorB_Encoder_Channel_A 3
#define MotorB_Encoder_Channel_B 11

Encoder MotorPositionA(MotorA_Encoder_Channel_A,MotorA_Encoder_Channel_B);
Encoder MotorPositionB(MotorB_Encoder_Channel_A,MotorB_Encoder_Channel_B);

int powerOut(int serIn){
if (serIn < 255){
  return serIn;
  }else return 255;
} 

void motor1(int digADpin, int digADVal, int anaADpin, int anaADVal){
  digitalWrite(digADpin, digADVal);
  analogWrite(anaADpin,anaADVal);
}

void nCdr(){
  int nCdrA= MotorPositionA.read();
  int nCdrB= MotorPositionB.read();
 // Serial.println(nCdrA);
}
 
 void setup() {
   Serial.begin(9600);
   pinMode(A0, INPUT);
   pinMode(A1, INPUT);
   pinMode(4, INPUT);
   pinMode(5, INPUT);    //Potentiometer input
   pinMode(7, OUTPUT);   //motor 1 AD bridge
   pinMode(8, OUTPUT);   //motor 1 AC bridge
   pinMode(9, OUTPUT);   //motor 1 power
   }

void loop() {
  int serIn;
  int x;
  int y = digitalRead(4);   //Read in the blue button
  int jstk = analogRead(A0);
  int potVal = analogRead(5)/2;    // Read in the potentiometer value
  // put your main code here, to run repeatedly:
  x = powerOut(potVal);
  int nCdrA= MotorPositionA.read();
  int nCdrB= MotorPositionB.read();
  int z = x;
  motor1(8,1,9,x);
  nCdr();
  Serial.println(jstk);
  }

