//Define pin names
//#define vMotor
//#define vMotorA3
//#define bluSwch 4
//#define redTog 3



//#include <IVT.h>

//IVT ivt;
//int vMotorA3 = 
//int vMotor = 
//const int R1 =
//const int R2 =
//int analogPin = redTog;
//int digiRead = bluSwch;
//int HOut = 7;
int nCdrA;

void redTog( int pin){
    int Tog = analogRead(pin)/200;
    Serial.println(Tog);
}


/*ADpin is the pin to activate the pin number and Val is 0 or 1 (meaning on or off)
 * AC runs the same as AD
 * analog write is taking the analog pin while percentage is 0-255 (0-100%)
*/
void motor(int ADPin, int ADVal, int ACPin, int ACVal, int anaPin, int Prcnt){
  digitalWrite(ADPin, ADVal );   //activate h-bridge AD
  digitalWrite(ACPin, ACVal);     //activate AC H-bridge
  analogWrite(anaPin ,Prcnt);   //analog output and percentage
}

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
  //int Tog = analogRead(analogPin)/200;
  //Serial.println(Tog);
  redTog(3);
  motor(7,1,8,0,9,255);
//  digitalWrite(7, 1 );   //activate h-bridge
//  digitalWrite(8, 0);
//  analogWrite( 9 ,120);
  
}
