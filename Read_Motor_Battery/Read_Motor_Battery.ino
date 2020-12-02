//int jmx = 670;
//
//int powerOut(int serIn){
//if (serIn > 50){
//  int x = joyStick()
//  x = constrain(x,50, 255);
//  return x;
//  }else return 255;
//} 
//
//void motor1(int digADpin, int digADVal, int anaADpin, int anaADVal){
//  digitalWrite(digADpin, digADVal);
//  analogWrite(anaADpin,anaADVal);
//}
//
//int joyStick(){
//  int zro = jmx/2;
//  int jstk = analogRead(A1);
//  jstk = jstk-zro;
//  if (jstk > 50){
//    int x = joyStick();
//    x = constrain(x,50, 255);
//    return x;
//    }else if(jstk < -50){
//      x = constrain(x,-255, -50);
//    return x;
//    }else if(){
//      return 255;}
//  
//}
int FULL_FORWARD= 671;
int FULL_REVERSE = 0;
int HANDLE_NUETRAL = 326;
int DEADBAND = 13;

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

 if (CurrentPosition>HANDLE_NUETRAL)
 {
  PositionPercent = (float(CurrentPosition - DB_High)/ForwardRange)*100;
 }
else if (CurrentPosition<HANDLE_NUETRAL)
 {
  PositionPercent = (float(CurrentPosition - DB_Low)/ReverseRange)*100;
 }
  else if (CurrentPosition<= HANDLE_NUETRAL && CurrentPosition >= HANDLE_NUETRAL)
 {
  PositionPercent = 0;
 }
//float w =5.00/1024;
//float z = w*x*2000;
  Serial.println(String(PositionPercent)/*+","+String(w)+","+String(z)*/);
  }


