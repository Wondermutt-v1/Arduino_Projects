<<<<<<< HEAD
//LED Blink

int ledPin = 7;//the Arduino pin that is connected to the LED
int mtrPin = 12;
void setup()
{
  pinMode(ledPin, OUTPUT);// initialize the pin as an output
  pinMode(mtrPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);//turn LED on
  delay(1000);// wait for 1000 milliseconds (one second)
  digitalWrite(ledPin, LOW);//turn LED off
  delay(1000);//wait one second
  digitalWrite(mtrPin,HIGH);
}
=======
//Define pin names
//#define vMotor
//#define vMotorA3
#define bluSwch 4
#define redTog 3



//#include <IVT.h>

//IVT ivt;
//int vMotorA3 = 
//int vMotor = 
//const int R1 =
//const int R2 =
int analogPin = redTog;
int digiRead = bluSwch;
int HOut = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //ivt.init_IVT();
  //pinMode( 4,INPUT); //Blue button
  pinMode(3,OUTPUT);  //Outputs the Red toggle
  
  pinMode(9 , OUTPUT);
  pinMode(7 ,OUTPUT); //Bri AD
  pinMode(8 ,OUTPUT); // Bri AC
}

void loop() {
  // put your main code here, to run repeatedly:
  int Tog = analogRead(analogPin);
  Serial.println(Tog);
  digitalWrite(7, 1 );   //activate h-bridge
  digitalWrite(8, 0);
  analogWrite( 9 ,120);
  
}
>>>>>>> 712296353751e1f26a27aa0e5a65073e4594f7d9
