void motor1(int digADpin, int digADVal, int anaADpin, int anaADVal)
{
  digitalWrite(digADpin, digADVal);
  analogWrite(anaADpin,anaADVal);
}
