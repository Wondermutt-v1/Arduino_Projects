// //Encoder file
// #define ENCODER_OPTIMIZE_INTERRUPTS
// #include <Encoder.h>



// //************Initialize Global Variables***********************************
// int BlBtn = 4;
// int nCdrA=0;
// int nCdrB= 0;
// int nCdrVal = 0;
// long previousMilsec = 0;
// int pressed = 0;
// int mtrPwr;
// static int counter = 0;
// volatile bool RunTask_10ms = 0;
// //***************************************************************************



// void setup() {
//   Serial.begin(115200);
//   pinMode(BlBtn, INPUT);
//   pinMode(5, INPUT);    //Potentiometer input
//   pinMode(7, OUTPUT);   //motor 1 AD bridge
//   pinMode(8, OUTPUT);   //motor 1 AC bridge
//   pinMode(9, OUTPUT);   //motor 1 power // 


//   //Disable interrupts
//   cli();
//   //Setup Timers
//   SetupTimer0();
//   //Start the serial port
//   //enable interrupts
//   sei();
//    }
 
//  void loop()
//  {
// //************Initialize Variables*************************
//   float x;
//   int y = digitalRead(BlBtn);         //Read in the blue button
//   nCdrA= abs(MotorPositionA.read());

// //*********************************************************

// //**********call functions***********
//   Tm3();
//   motor1(7,pressed,9,mtrPwr);

// //***********************************


// //*******Output*********************
//   String mSec = String(pressed);
//   String X = String(rotation());
//   String Cntr = String(counter);
//   String stuff = String (X + " " +mSec+ " " + Cntr);
//   Serial.println(stuff);
// //********************************** 
//  }
