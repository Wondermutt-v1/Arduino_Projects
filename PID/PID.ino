#include <EEPROM.h>

#include <MyFxns.h>

MyFxns myfxns;
enum  MOTOR_DIR_ENUM direction;
int data[8] = {0,0,0,0,0,0,0,0};

volatile bool RunTask_10ms = 0;

//**************************************
//  10 ms Task Rate
//  Creates a periodic Task
//  Vector Address 15
//**************************************
ISR(TIMER0_COMPA_vect)
{
  //Check to see if the flag was not cleared, this will track
  //overruns in the 10ms task
  if(RunTask_10ms)
  {
    //digitalWrite(LED_BUILTIN,1);
  }
  RunTask_10ms = 1;
}

//************Initialize Global Variables***********************************
int BlBtn = 4;
int pressed = 0;
int MtrPwr;
int MtrChan = 9;
int maxvolt = analogRead(3);
static int time_count = 0;
static int RunTask100ms = 0;
static int RunTask10ms = 0;




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
  myfxns.SetupTimer0();

  //Start the serial port
  Serial.begin(115200);

  delay(1000);

  //enable interrupts
  sei();
}
 

 void loop()
  {
    static int drct;
    int x;     
    
     myfxns.SendCANMessage(data);
     x = myfxns.button_Push(pressed);
     pressed = x;
     int jsk = myfxns.GetJoystickValue(672);
     int pot = myfxns.GetPot();
     int jdrct = myfxns.GetDirection(jsk);
     int pdrct = myfxns.GetDirection(pot);
     int jMtrPwr= abs(jsk);
     int pMtrPwr= abs(pot);
     data[0]= jdrct;
     data[1]= myfxns.pwrToPrct(jMtrPwr);
     data[2] = pdrct;
     data[3]= myfxns.pwrToPrct(pMtrPwr);
//     data[0,1,2,3] = (jdrct, myfxns.pwrToPrct(jMtrPwr), pdrct, myfxns.GetDirection(pot));
    
       if (x ==0)
       {
       myfxns.runMotorA(jdrct ,jMtrPwr);
       }
       else if (pressed ==1)
       {
        myfxns.runMotorA(pdrct ,pMtrPwr);
       }
      
     // = myfxns.TM3(RunTask_10ms);
     //myfxns.runMotorA(drct ,jMtrPwr);
     RunTask_10ms= myfxns.TM3(RunTask_10ms);
     //myfxns.runMotorA(jdrct ,jMtrPwr);
     //float pct = myfxns.pwrToPrct(jsk);
     //float prt = myfxns.prctToRPM(jpct);
     //Serial.println(String(x)+ ", "+ String(prt));
 }

 
