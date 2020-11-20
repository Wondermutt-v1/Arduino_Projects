
#include <Signals.h>
#include <Encoder.h>
#include <EEPROM.h>

void Controller_Logic:: SendCANMessage(int data[])
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

float Controller_Logic:: batteryToHex()
{
	int BatteryVoltage_ADC;
	int BatteryVoltage_mV;

	//Read in the voltage of the following PIN, this is 10 bit
	BatteryVoltage_ADC = analogRead(V_MOTOR_A3);

	//Convert from ADC to mV, assume a 5v reference
	//Use 512 instead of 1024 since there is a voltage divider that 
	//divides by 2. 
	float stepsPerVolt =5/1024.00;
  	BatteryVoltage_mV = stepsPerVolt*BatteryVoltage_ADC*2000;
	
	int BatteryVoltage_hex= int(BatteryVoltage_mV*0.0425);

	return BatteryVoltage_hex;
}
////
int Controller_Logic:: prctToPwr(float prcnt)
{
	float val;
	val = prcnt / 100;
	//Serial.println(pwr);
	int pwr = val * 255;
	return pwr;

}

