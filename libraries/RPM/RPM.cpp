
#include <RPM.h>
#include <Encoder.h>
#include <EEPROM.h>

Encoder MotorPositionA(MotorA_Encoder_Channel_A,MotorA_Encoder_Channel_B);
Encoder MotorPositionB(MotorB_Encoder_Channel_A,MotorB_Encoder_Channel_B);

#define ENCODER_OPTIMIZE_INTERRUPTS
float rpm;	//This is a globalg variable inside this 
int RunTask_100ms;	//Global Variable to keep count. This should allow for a simple counter program.

RPM::RPM()
{
}

/*	
Initialize the pinout of the board
*/
void RPM:: init()
{
	//Set the output pins
	pinMode(MotorA_PWM_Channel, OUTPUT);
	pinMode(MotorA_DIR_ChannelA, OUTPUT);
	pinMode(MotorA_DIR_ChannelB, OUTPUT);

	pinMode(MotorB_PWM_Channel, OUTPUT);
	pinMode(MotorB_DIR_ChannelA, OUTPUT);
	pinMode(MotorB_DIR_ChannelB, OUTPUT);

	//Set the inputs pin
	pinMode(MotorA_Encoder_Channel_A, INPUT);
	pinMode(MotorA_Encoder_Channel_B, INPUT);
	pinMode(MotorB_Encoder_Channel_A, INPUT);
	pinMode(MotorB_Encoder_Channel_B, INPUT);
	pinMode(JOYSTICKX, INPUT);
	pinMode(Blue_Button,INPUT);
	pinMode(JOYSTICKY, INPUT);
	pinMode(Potentiometer, INPUT);
	pinMode(V_MOTOR_A3, INPUT);
	pinMode(A4, INPUT);
	pinMode(A5, INPUT);


	delay(500);

	//Turn off the bridges
	digitalWrite(MotorA_DIR_ChannelA, 0);
	digitalWrite(MotorA_DIR_ChannelB, 0);

	digitalWrite(MotorB_DIR_ChannelA, 0);
	digitalWrite(MotorB_DIR_ChannelB, 0);

	//Turn off the PWM driver
	analogWrite(MotorA_PWM_Channel, 0);
	analogWrite(MotorB_PWM_Channel, 0);



}

/* 
 Pass in the 10 bit ADC value from the joystick and the end points and this will return a value from -255 to 255, the joystick  can be inteverted with the last argument.

 -255 to 255 is equal to -100% to 100%. may be modified later to work with percentage later.
 */
signed int RPM:: GetJoystickValue(int volt)
{
		//int jmx  = V;
	int x=0;
	 int yin = analogRead(JOYSTICKY);
	// int zro = jmx/2;

	int centerZero = CentertoZero(volt, yin);
	//centerZero = centerZero-zro;
	if (centerZero <= -75)
	{
		x = abs(centerZero);
		x = constrain(x,75, 255);
		x=-x;
		return x;
	}
	else if(centerZero >= 75)
	{ 
      x = abs(centerZero);
      x = constrain(x,75, 255);
	  return x;
    }else
	x=0;
	return x;
}

/* 
Fills out the enumeration for the stick
*/
MOTOR_DIR_ENUM RPM:: GetDirection(int Val)
{

	MOTOR_DIR_ENUM drct;
	if (Val > 50)
	{
		drct = Forward;
		return drct;
	}
	else if (Val < -50)
    {
        drct = Backward;
		return drct;
    }
    else if (Val > -50 && Val < 50)
    {
		drct = Stop;
		return drct;
    }

}

/* 
Function gets the max and min values of the joystick and sets the middle value to 0 to give positive and negative values.

 not sure this is necessary.
*/
int RPM:: Calibrate_Joystick()
{
	int y;
	bool CalFlag;
	y = analogRead(JOYSTICKY);
	return y;

}

/* 
This will take the values of the encoder and convert it to RPM using the value of 240 pulses per revoputionfor the motor side and converting it to the output axle
*/
float RPM:: Compute_Speed()
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


/*
Simply reads in the potentiometer
*/
int RPM:: GetPot()
{
	int potVal = analogRead(Potentiometer);
	potVal = CentertoZero(510, potVal);
	return potVal;
}

/* 
Sets up the effect of the 10us timer going off. accounting for the the length a timer can be put up vor up to several seconds by using a counter.
*/
int RPM:: TM3(int RunTask_10ms)
{
	static int RunTask100ms;
 	float Desired_Speed = -50;
 	float Current_Speed = 0;
 	static float PrevDesiredSpeed = -50;
 	static float error_sum = 0;
 	static int time_count = 0;
 	static float output;
 	static float error;
 	static float integ;
 	int current_pos;

	 if(RunTask_10ms)
	 {
		rpm =  RPM();
		time_count++;
		RunTask_10ms = 0; 
		return RunTask_10ms;
		}
		return RunTask_10ms;
	}

//*********************************************
//Configure Timer 0
//*********************************************
void RPM:: SetupTimer0()
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

/*
Get function to retrieve the rpm for use externally
*/
float RPM:: GetRPM()
{
	return rpm;
}

/*
RPM should use timer to set a flag based on reading the encoder
*/
float RPM::RPM()
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


/*
Pushes center of the range to 0
*/
int RPM:: CentertoZero(int maxvolt, int pwrin)
{
	int centerZero  = maxvolt;
	int x=0;
	int zro = centerZero/2;
	centerZero = pwrin;
	centerZero = centerZero-zro;
		if (centerZero <= -75)
		{
			x = abs(centerZero);
			x = constrain(x,75, 255);
			x=-x;
			return x;
			}
		else if(centerZero >= 75)
		{ 
			x = abs(centerZero);
			x = constrain(x,75, 255);
			return x;
		}else
		x=0;
		return x;
		return 	centerZero;
}


/*

converts from rpm to %

*/
float RPM:: rpmToPrct()
{
	float val;	//this is simply used to break down the math parts for visibility
	val = float(rpm)/85;
	float prcnt = val*100;
	return prcnt;

}

//
float RPM:: prctToRPM(float prcnt)
{
	float val;
	val = prcnt / 100;
	//Serial.println(val);
	float r = val * 85;
	return r;
}

/*
this fxn is a general PID funcion. The PID may be the settings of P(proportional),I (integral),D(derivative). The current set up that is simple has a over simplified I term and no D term. 

This may be good for using the Potentiometer to 
*/
void RPM:: PID()
{
	float Desired_Speed = -50;
	float Current_Speed = 0;
	static float error_sum = 0;
	static int time_count = 0;
//  
//  if(RunTask_10ms)
//  {
//    //Set a function for desired speed
//    time_count++;
//    if(time_count > 900)
//    {
//      time_count = 0;
//      Desired_Speed = 50;
//    }
////    }
////    else if(time_count > 600)
////    {
////       Desired_Speed = 25;
////    }
////    else if(time_count > 300)
////    {
////       Desired_Speed = 10;
////    }
//    //Compute the speed
	Current_Speed = RPM();
   //Serial.println(String(Current_Speed) + "," + String(Desired_Speed));
   
   //computer the error
   float error = Desired_Speed - Current_Speed;

   if(Current_Speed != 0)
  {
      error_sum += error;
   }

   //Serial.println(error_sum);
   
   // Serial.println(error);
   //PID controls
   float output = (5 * error) + (0.2* error_sum);
   
//    if(abs(output) > 255)
//    {
//      output = 255;
//    }
   //Serial.println(output);
   //Set output
   //motor1(7,pressed,9,int(abs(output)));
   //RunTask_10ms = 0; 
 }