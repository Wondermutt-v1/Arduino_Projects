#include <EEPROM.h>
//#include <myfxns.h>
#define HANDLE_FF 192;

int jmx = 670;                  //max joystick value. 
int address = 50;                //Memory address to be used
//EEPROM.write(address, jmx);     //writes a value to memory address


//***********Channel defines*********
#define MotorA_Encoder_Channel_A 2
#define MotorA_Encoder_Channel_B 12
#define MotorB_Encoder_Channel_A 3
#define MotorB_Encoder_Channel_B 11
//***********************************


// Encoder MotorPositionA(MotorA_Encoder_Channel_A,MotorA_Encoder_Channel_B);
// Encoder MotorPositionB(MotorB_Encoder_Channel_A,MotorB_Encoder_Channel_B);

/* Global Variables */
int nCdrA=0;
int nCdrB= 0;
int nCdrVal = 0;
long previousMilsec = 0;
int pressed = 0;
int mtrPwr=0;



  
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);    //jstk left-right
  pinMode(A1, INPUT);    //jstk forward-back
  pinMode(4, INPUT);
  pinMode(5, INPUT);    //Potentiometer input
  pinMode(7, OUTPUT);   //motor 1 AC bridge or Forward
  pinMode(8, OUTPUT);   //motor 1 AD bridge or Reverse
  pinMode(9, OUTPUT);   //motor 1 power
}


void loop() 
{
  int serIn;
  int x;
  //int y = digitalRead(4);   //Read in the blue button
  //int jstk = analogRead(A1);
  //int sensVal = max(jstk, 0);

  EEPROM.write(address, jmx/4);
  int HandleFullForward = EEPROM.read(address);
  joyStick();
  int potVal = analogRead(5)/2;    // Read in the potentiometer value
  
  //int HandleFullForward = 42 ;
  int z = x;


  //*****converting stuff to strings and then to one long string*****
  String Adrs = String(address);
  String Jmx = String(jmx/4);
  String HFF = String(HandleFullForward);
  String stuff = String(Adrs+ " " +Jmx+" "+HFF);
  //*********************************

  //output to ensu
  Serial.println(stuff);
}




