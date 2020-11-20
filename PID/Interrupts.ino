////volatile bool RunTask_10ms = 0;
//static int RunTask50ms = 0;
////**************************************
////  10 ms Task Rate
////  Creates a periodic Task
////  Vector Address 15
////**************************************
//ISR(TIMER0_COMPA_vect)
//{
//  //Check to see if the flag was not cleared, this will track
//  //overruns in the 10ms task
//  if(RunTask_10ms)
//  {
// 
//    //digitalWrite(LED_BUILTIN,1);
//
//  }
//
//  RunTask50ms ++;
//  if(RunTask50ms >= 5)
//  {     
//     RunTask50ms = 0;
//     RunTask_10ms = 1;
//  }
//  
//}
//
////*********************************************
////  Configure Timer 0
////*********************************************
//void SetupTimer0()
//{
//  TCCR0A = 0; // set entire TCCR0A register to 0
//  TCCR0B = 0; // same for TCCR0B
//  TCNT0  = 0; //initialize counter value to 0
//  // set compare match register for 2khz increments
//  OCR0A = 155;// = (16*10^6) / (100*1024) - 1 = 155(must be <256)
//  // turn on CTC mode
//  TCCR0A |= (1 << WGM01);
//  // 1024 prescaler - page 142 of datasheet
//  TCCR0B |= (1 << CS00);
//  TCCR0B |= (1 << CS02);
//  // enable timer compare interrupt
//  TIMSK0 |= (1 << OCIE0A);
//}
//
//void Tm3()
//{
//  // unsigned int Cdr = MotorPositionA.read();
//  float Desired_Speed = -50;
//  float Current_Speed = 0;
//  static float PrevDesiredSpeed = -50;
//  static float error_sum = 0;
//  static int time_count = 0;
//  static float output;
//  static float error;
//  static float integ;
//  int current_pos;
//  
//  if(RunTask_10ms)
//  {
//    //Set a function for desired speed
//   time_count++;
//   //Serial.println(time_count);
//   if(time_count <= 900/* && time_count > 600*/)
//   {
//      Desired_Speed = -50;
//   }
//   else if(time_count <= 600/* && time_count > 300*/)
//   {
//      Desired_Speed = -35;
//         
//   }
//   else if(time_count <=300 /*&& time_count > 0*/)
//   {
//      Desired_Speed = -20;
//
//   }
////  else if (time_count >1200)
////   {
////    //error=0;
////    integ= 0;
////    time_count = 0;
////   }
//    //Compute the speed
//   //Current_Speed = abs(Compute_Speed());
//    current_pos = MotorPositionA.read();
//    Serial.println(current_pos);
//    
//    //computer the error
//    error = Current_Speed -Desired_Speed;
//    
////    if (integ <-800)
////    {
////      integ= -1;
////    }
//    
//   
//
//    //PID controls
//    output = 255;//(5 * error)+ (0.1*error_sum);
//    
//    if(abs(output) > 50)
//    {
//      output = 255;
//    }
//
//     
//      motor1(7,1,9,output);
//    
//    //Serial.println(String(Current_Speed)/* + "," + String(error) + "," + String(Cdr) + "," + String(output)*/);
//    RunTask_10ms = 0; 
//  }
//}

