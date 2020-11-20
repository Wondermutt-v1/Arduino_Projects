#include <Signals.h>
#include <Encoder.h>
#include <EEPROM.h>


#define ENCODER_OPTIMIZE_INTERRUPTS
float rpm;	//This is a globalg variable inside this 


//*************begin Motor_Controller class******************
//***********************************************************
//***********************************************************


Motor_Controller::Motor_Controller()
{
}

///<summary>
///This function makes use of the MOTOR_DIR_ENUM enumeration
///</summary>
void Motor_Controller:: SetMotorDir(MOTOR_DIR_ENUM direction)
{
	if (direction == Forward)
	{
		digitalWrite(MotorA_DIR_ChannelA, 1);
		digitalWrite(MotorA_DIR_ChannelB, 0);

	}
	else if (direction == Backward)
	{
		digitalWrite(MotorA_DIR_ChannelA, 0);
		digitalWrite(MotorA_DIR_ChannelB, 1);
	}
	else if (direction == Stop)
	{
		digitalWrite(MotorA_DIR_ChannelA, 0);
		digitalWrite(MotorA_DIR_ChannelB, 0);
	}
}


///<summary>
/// sets the motor to running. The direction is set by the SetMotorDir fxn.
///</summary>
void Motor_Controller:: runMotorA(MOTOR_DIR_ENUM direction, int anaADVal)
{
	SetMotorDir(direction);
	analogWrite( MotorA_PWM_Channel, anaADVal);
}

/*
converts from rpm to %
*/
float Motor_Controller:: rpmToPrct()
{
	float val;	//this is simply used to break down the math parts for visibility
	val = rpm/85;
	float prcnt = val*100;
	return prcnt;
}

/*
Converts % to Motor_Controller
*/
float Motor_Controller:: prctToRPM(float prcnt)
{
	float val;
	val = prcnt / 100;
	//Serial.println(val);
	float r = val * 85;
	return r;
}
