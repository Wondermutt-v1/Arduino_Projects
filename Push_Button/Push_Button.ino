int powerOut(int serIn){
if (serIn < 255){
  return serIn;
  }else return 255;
} 

int button_Push(int digVal){
  int x;
  if (digVal = 0){
    
    return digVal;
  } else return digVal;
}

void motor1(int digADpin, int digADVal, int anaADpin, int anaADVal){
  digitalWrite(digADpin, digADVal);
  analogWrite(anaADpin,anaADVal);
}
 
 void setup() {
   Serial.begin(9600);
   pinMode(4, INPUT);
   pinMode(5, INPUT);    //Potentiometer input
   pinMode(7, OUTPUT);   //motor 1 AD bridge
   pinMode(8, OUTPUT);   //motor 1 AC bridge
   pinMode(9, OUTPUT);   //motor 1 power
   }

void loop() {
  int serIn;
  int x;
  int y = !digitalRead(4);         //Read in the blue button
  int potVal = analogRead(5)/2;    // Read in the potentiometer value
  x = powerOut(potVal);
  motor1(7,y,9,x);
  Serial.println(y);
  }
