/*This program takes the power value from the potentiometer and ensures that the power is 
always between 0 and 100 percent

int powerOut(int serIn){
if (serIn < 255){
  return serIn;
  }else return 255;
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
  int y = digitalRead(4);   //Read in the blue button
  int potVal = analogRead(5)/2;    // Read in the potentiometer value
  // put your main code here, to run repeatedly:
  x = powerOut(potVal);
  int z = x;
  motor1(7,1,9,x);
  Serial.println(x);
  }

