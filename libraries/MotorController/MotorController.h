#ifndef MotorController_h
#define MotorController_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#include "WConstants.h"

#endif
#include <Encoder.h>
#include <EEPROM.h>


//define motor pins
#define MotorA_PWM_Channel  9	//motor 1 power
#define MotorA_DIR_ChannelA 7	//motor 1 AC bridge or Forward
#define MotorA_DIR_ChannelB 8	//motor 1 AD bridge or Reverse

#define MotorB_PWM_Channel  10  
#define MotorB_DIR_ChannelA 5 
#define MotorB_DIR_ChannelB 6

// #define  MotorA_Encoder_Channel_A  2
// #define  MotorA_Encoder_Channel_B  12

// #define  MotorB_Encoder_Channel_A  3
// #define  MotorB_Encoder_Channel_B  11

#define V_MOTOR_A3   3



enum MOTOR_ID_ENUM
{
	MotorA,
	MotorB
};
enum MOTOR_DIR_ENUM
{
	Stop,
	Forward,
	Backward
};

class Motor_Controller
{
public:
	//Constructor, required, same name as class
	Motor_Controller();

	//Sets up all the pins properly for the I/O needed to control the L298
	void init();

	//
	void runMotorA(MOTOR_DIR_ENUM direction, int anaADVal)
	//
	float pwrToPrct(int power);

	//
	float rpmToPrct();

	//
	float prctToRPM(float prcnt);




private:
	//Used internally to load the values for the motor.
	void SetMotor(int ChannelA, int ChannelB, int PWM_Channel, int pwm_value, int direction);


	
};
#endif