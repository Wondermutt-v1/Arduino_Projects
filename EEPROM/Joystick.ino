/*This function allows joystick controll of the motor. It does this by calling the motor1 function */
void joyStick()
{
  int x=0;
  int zro = jmx/2;
  int jstk = analogRead(A1);
  jstk = jstk-zro;
  if (jstk <= -75)
  {
    //x = jstk;
    x = abs(jstk);
    x = constrain(x,75, 255);
    Serial.println("Forward");
    //Serial.println(x);
    motor1(8,0,7,1,9,x);
  }
  else if(jstk >= 75)
  {
      x = abs(jstk);
      x = constrain(x,75, 255);
      Serial.println("Back");
      //Serial.println(x);
      motor1(7,0, 8, 1,9,x);
  }
  else
  {
    x=0;
    Serial.println("stop");
    //Serial.println(x);
    motor1(8,0,7,0,9,x);
    }
}