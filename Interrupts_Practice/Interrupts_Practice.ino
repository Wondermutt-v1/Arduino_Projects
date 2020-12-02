//Encoder file
#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

//***********Channel defines*********
#define MotorA_Encoder_Channel_A 2
#define MotorA_Encoder_Channel_B 12
#define MotorB_Encoder_Channel_A 3
#define MotorB_Encoder_Channel_B 11
//***********************************



Encoder MotorPositionA(MotorA_Encoder_Channel_A,MotorA_Encoder_Channel_B);
Encoder MotorPositionB(MotorB_Encoder_Channel_A,MotorB_Encoder_Channel_B);

//************Initialize Global Variables***********************************
int BlBtn = 4;
static int nCdrA=0;
int nCdrB= 0;
int nCdrVal = 0;
long previousMilsec = 0;
int pressed = 0;
int mtrPwr;
static int counter = 0;
static float oldRotCnt = 0;
static float rpm;
volatile bool RunTask_10ms = 0;
//***************************************************************************



void setup()
{
  
  Serial.begin(115200);
  pinMode(BlBtn, INPUT);
  pinMode(5, INPUT);    //Potentiometer input
  pinMode(7, OUTPUT);   //motor 1 AD bridge
  pinMode(8, OUTPUT);   //motor 1 AC bridge
  pinMode(9, OUTPUT);   //motor 1 power //
  //Disable interrupts
  cli();
  //Setup Timers
  SetupTimer0();
  //Start the serial port
  //enable interrupts
  sei();
}
 

//************loop**************
//*****************************
 void loop()
  {
//************Initialize Variables*************************
  float x;
  int z = analogRead(3);
  int y = digitalRead(BlBtn);         //Read in the blue button
  //nCdrA= abs(MotorPositionA.read());

//*********************************************************

//**********call functions***********
  Tm3();
  button_Push();
  

//***********************************
   Serial.println(RunTask_10ms);
 }
