#ifndef MyFxns_h
#define MyFxns_h

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

#define  MotorA_Encoder_Channel_A  2
#define  MotorA_Encoder_Channel_B  12

#define  MotorB_Encoder_Channel_A  3
#define  MotorB_Encoder_Channel_B  11

#define V_MOTOR_A3   3
#define JOYSTICKX		0	//joystick left-right
#define JOYSTICKY	1	//joystick forward back
#define Blue_Button		4	//blue button on the board
#define Potentiometer	5	 //Potentiometer input


enum MOTOR_ID_ENUM
{
	MotorA,
	MotorB
};
enum MOTOR_DIR_ENUM
{
	Forward,
	Backward,
	Stop
};




class MyFxns
{
public:
	//Constructor, required, same name as class
	MyFxns();

	//Sets up all the pins properly for the I/O needed to control the L298
	void init();

	//Used by the application developer to control the motors
	void SetMotorPWM(MOTOR_ID_ENUM motor_id, int pwm_value, int direction);

	//Read Battery Voltage, returns an int in mV
	int ReadBatteryVoltage();

	//Send a sudo CAN messages
	void SendCANMessage(int data[]);


	
	//sets the motor to running. The direction is set by the SetMotorDir fxn.
	void runMotorA(MOTOR_DIR_ENUM direction, int AnaADVal);

	//Get the motor position
   // int GetMotorPosition(MOTOR_ID_ENUM motor_id);

	//make sure the joystic values are correct
	int Calibrate_Joystick();

   //Gets values from the Joystick
	signed int	GetJoystickValue(int volt);
	
	
	//Fills out the enumeration for the joystick
	MOTOR_DIR_ENUM GetDirection(int Val);
	
	//computes the RPM Values
	float Compute_Speed();

	//Recognizes Button push and latches
	int button_Push(int pressed);

	//
	int GetPot();

	int TM3(int RunTask_10ms);
	
	// Configure Timer 0
	void SetupTimer0();

	//
	float GetRPM();

	//RPM should use timer to set a flag based on reading the encoder
	float RPM();

	//
	void PID();

	//
	int CentertoZero(int maxvolt, int yin);

	//
	float pwrToPrct(int power);

	//
	int prctToPwr(float prcnt);

	//
	float rpmToPrct();

	//
	float prctToRPM(float prcnt);




private:
	//Used internally to load the values for the motor.
	void SetMotor(int ChannelA, int ChannelB, int PWM_Channel, int pwm_value, int direction);

	//set motor direction
	void SetMotorDir(MOTOR_DIR_ENUM direction);
	

	
};
#endif