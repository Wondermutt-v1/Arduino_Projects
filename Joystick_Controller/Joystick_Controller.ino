int jmx = 670;


/*Function controls the motor and the H-Bridge. If the AC bridge is activated (1) then the AD bridge can not be activated until
the AC bridge is set to low. This means that each of the calls must have an AC-bridge pin and an AC value for each call as well as an ADbridge 
pin and value. Finally the analogWrite function is the power pin and speed of the motor that will go through the bridge*/
void motor1(int digADpin, int digADVal, int digACpin, int digACVal, int anaADpin, int anaADVal){
  digitalWrite(digACpin, digACVal);
  digitalWrite(digADpin, digADVal);
  analogWrite(anaADpin,anaADVal);}

/*This function allows joystick controll of the motor. It does this by calling the motor1 function */
 void joyStick(){
  int x=0;
  int zro = jmx/2;
  int jstk = analogRead(A1);
  jstk = jstk-zro;
  if (jstk <= -75){
    //x = jstk;
    x = abs(jstk);
    x = constrain(x,75, 255);
    Serial.println("Forward");
    Serial.println(x);
    motor1(8,0,7,1,9,x);
    }else if(jstk >= 75){
      x = abs(jstk);
      x = constrain(x,75, 255);
      Serial.println("Back");
      Serial.println(x);
      motor1(7,0, 8, 1,9,x);
      }else{
        x=0;
        Serial.println("stop");
        Serial.println(x);
        motor1(8,0,7,0,9,x);
      }
   }
  
 void setup() {
   Serial.begin(9600);
   pinMode(A0, INPUT);    //jstk left-right
   pinMode(A1, INPUT);    //jstk forward-back
   pinMode(4, INPUT);
   pinMode(5, INPUT);    //Potentiometer input
   pinMode(7, OUTPUT);   //motor 1 AC bridge or Forward
   pinMode(8, OUTPUT);   //motor 1 AD bridge or Reverse
   pinMode(9, OUTPUT);   //motor 1 power
   }

void loop() {
  int serIn;
  int x;
  //int y = digitalRead(4);   //Read in the blue button
  //int jstk = analogRead(A1);
  //int sensVal = max(jstk, 0);
  joyStick();
  int potVal = analogRead(5)/2;    // Read in the potentiometer value
  
  //x = powerOut(potVal);
  int z = x;
  //motor1(8,1,9,255);
  //Serial.println(stk);
  }



