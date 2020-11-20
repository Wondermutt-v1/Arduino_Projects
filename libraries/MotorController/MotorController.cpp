#include <MotorController.h>
#include <Encoder.h>
#include <EEPROM.h>

 Encoder MotorPositionA(MotorA_Encoder_Channel_A,MotorA_Encoder_Channel_B);
 Encoder MotorPositionB(MotorB_Encoder_Channel_A,MotorB_Encoder_Channel_B);

#define ENCODER_OPTIMIZE_INTERRUPTS
float rpm;	//This is a globalg variable inside this 
//int RunTask_100ms;	//Global Variable to keep count. This should allow for a simple counter program.

Motor_Controller::Motor_Controller()
{
}

/*	
Initialize the pinout of the board for the Motor
*/
void Motor_Controller:: init()
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

///<summary>
///This function makes use of the MOTOR_DIR_ENUM enumeration
///</summary>
void Signals:: SetMotorDir(MOTOR_DIR_ENUM direction)
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
void Signals:: runMotorA(MOTOR_DIR_ENUM direction, int anaADVal)
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
