
#include <ControlLogic.h>
#include <Encoder.h>
#include <EEPROM.h>




ControlLogic::ControlLogic()
{
}


/*	
  Send a serial message, not the CAN protocol but still teaches 
  the fundamentals.
*/
void ControlLogic::SendCANMessage(int data[])
{
	String datastring;
	String temp;

	datastring = "8 ";

	//Load the data and convert to hex.
	for (int i = 0; i < 8; i++)
	{
		datastring += " ";
		temp = String(data[i], HEX);
		//Pad the string
		if (temp.length() == 1)
		{
			temp = "0" + temp;
		}
		datastring += temp;

	}
	Serial.println(datastring);
}

// /*
// this fxn is a general PID funcion. The PID may be the settings of P(proportional),I (integral),D(derivative). The current set up that is simple has a over simplified I term and no D term. 

// This may be good for using the Potentiometer to 
// */
// void Motor_Controller:: PID()
// {
// 	float Desired_Speed = -50;
// 	float Current_Speed = 0;
// 	static float error_sum = 0;
// 	static int time_count = 0;
// //  
// //  if(RunTask_10ms)
// //  {
// //    //Set a function for desired speed
// //    time_count++;
// //    if(time_count > 900)
// //    {
// //      time_count = 0;
// //      Desired_Speed = 50;
// //    }
// ////    }
// ////    else if(time_count > 600)
// ////    {
// ////       Desired_Speed = 25;
// ////    }
// ////    else if(time_count > 300)
// ////    {
// ////       Desired_Speed = 10;
// ////    }
// //    //Compute the speed
// 	Current_Speed = Rpm();
//    //Serial.println(String(Current_Speed) + "," + String(Desired_Speed));
   
//    //computer the error
//    float error = Desired_Speed - Current_Speed;

//    if(Current_Speed != 0)
//   {
//       error_sum += error;
//    }

//    //Serial.println(error_sum);
   
//    // Serial.println(error);
//    //PID controls
//    float output = (5 * error) + (0.2* error_sum);
   
// //    if(abs(output) > 255)
// //    {
// //      output = 255;
// //    }
//    //Serial.println(output);
//    //Set output
//    //motor1(7,pressed,9,int(abs(output)));
//    //RunTask_10ms = 0; 
//  }