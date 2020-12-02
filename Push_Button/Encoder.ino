


//counts the rotations of output axel
float rotation()
{
  float Rotation;
  //11 pulses per motor rotation and 44 per Output rotation
  Rotation = nCdrA/1975;
  return Rotation;
}


float RPM()
{
   int interval= 1000; //defines the inverval as 1 second
   long cMil =0;
   int rpm = 0;
   if(cMil - previousMilsec > interval)
   {
      previousMilsec = cMil;
   }
   return previousMilsec;
}

// int rotA(int y)
// {
//  int a;
//  float Pos = MotorPositionA.read();
//  float Rot = nCdrA/44;
//  float oldPos;
//   //int val =nCdrA;
//   if (abs(Pos) >= oldPos +11)
//   {
//    oldPos = abs(Pos);
//    motor1(7,0,9,0);
//    return Pos;
//    }
//    else
//    a = Pos;
//    motor1(7,1,9,120);
//    return Pos;
// }

