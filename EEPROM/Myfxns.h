#include <Encoder.h>
//***********Channel defines*********
#define MotorA_Encoder_Channel_A 2
#define MotorA_Encoder_Channel_B 12
#define MotorB_Encoder_Channel_A 3
#define MotorB_Encoder_Channel_B 11
//***********************************



Encoder MotorPositionA(MotorA_Encoder_Channel_A,MotorA_Encoder_Channel_B);
Encoder MotorPositionB(MotorB_Encoder_Channel_A,MotorB_Encoder_Channel_B);