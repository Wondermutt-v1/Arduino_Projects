//volatile bool RunTask_10ms = 0;

//**************************************
//  10 ms Task Rate
//  Creates a periodic Task
//  Vector Address 15
//**************************************
ISR(TIMER0_COMPA_vect)
{
  //Check to see if the flag was not cleared, this will track
  //overruns in the 10ms task
  if(RunTask_10ms)
  {
    //digitalWrite(LED_BUILTIN,1);
    pressed = !pressed;

  }
  RunTask_10ms = 1;
}

//*********************************************
//  Configure Timer 0
//*********************************************
void SetupTimer0()
{
  TCCR0A = 0; // set entire TCCR0A register to 0
  TCCR0B = 0; // same for TCCR0B
  TCNT0  = 0; //initialize counter value to 0
  // set compare match register for 2khz increments
  OCR0A = 155;// = (16*10^6) / (100*1024) - 1 = 155(must be <256)
  // turn on CTC mode
  TCCR0A |= (1 << WGM01);
  // 1024 prescaler - page 142 of datasheet
  TCCR0B |= (1 << CS00);
  TCCR0B |= (1 << CS02);
  // enable timer compare interrupt
  TIMSK0 |= (1 << OCIE0A);
}

void Tm3()
{
  float Desired_Speed = -50;
  float Current_Speed = 0;
  static float error_sum = 0;
  static int time_count = 0;
  
  if(RunTask_10ms)
  {
    //Set a function for desired speed
    time_count++;
    if(time_count > 900)
    {
      time_count = 0;
      Desired_Speed = 50;
    }

    //Compute the speed
    Current_Speed = Compute_Speed();
    //Serial.println(String(Current_Speed) + "," + String(Desired_Speed));
    
    //computer the error
    float error = Desired_Speed - Current_Speed;

    if(Current_Speed != 0)
   {
       error_sum += error;
    }
 
    Serial.println(error_sum);
    
    // Serial.println(error);
    //PID controls
    float output = (5 * error) + (0.2* error_sum);
    
    if(abs(output) > 255)
    {
      output = 255;
    }
    //Serial.println(output);
    //Set output
    motor1(7,pressed,9,int(abs(output)));
    RunTask_10ms = 0; 
  }
  counter ++;
}
