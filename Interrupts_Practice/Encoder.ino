


//counts the rotations of output axel
//this should eventually reset the rpm and encoder
float rotation()
{
  nCdrA= abs(MotorPositionA.read());
  float Rotation;
  Rotation =float(nCdrA)/1975;
  return Rotation;
}

//RPM should use timer to set a flag based on reading the encoder 
//
float RPM()
{
  float rotDiff = rotation()-oldRotCnt;
  rpm = rotDiff*20;
  //Serial.println(rpm);
  return rpm;
}

float Compute_Speed()
{
   int current_pos;
   static int previous_pos = 0;
   int speed_value_counts;
   float rpm_new;
   
   
   current_pos = MotorPositionA.read();
   speed_value_counts = current_pos - previous_pos;
   previous_pos = current_pos;

   rpm_new = float(speed_value_counts)*6000/1975;
   
   return rpm_new;
}



