/*Function controls the motor and the H-Bridge. If the AC bridge is activated (1) then the AD bridge can not be activated until
the AC bridge is set to low. This means that each of the calls must have an AC-bridge pin and an AC value for each call as well as an ADbridge 
pin and value. Finally the analogWrite function is the power pin and speed of the motor that will go through the bridge*/
void motor1(int digADpin, int digADVal, int digACpin, int digACVal, int anaADpin, int anaADVal){
  digitalWrite(digACpin, digACVal);
  digitalWrite(digADpin, digADVal);
  analogWrite(anaADpin,anaADVal);}