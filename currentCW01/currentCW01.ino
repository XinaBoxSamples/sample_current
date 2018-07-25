/*************************************************************
	This is an examples for the PB04
	Smart Battery Module
	
	You can buy one on our store!
	-----> https://xinabox.cc/PB04/
	
	This example requests the Battery module to measure
	the instantaneous current being used.
	
	Currently Supported on the following ☒CHIPs:
	- CW01
	- CC01
	- CR01
	
	The sensor communicates over the I2C Bus.
	
	------------------------TIPS--------------------------
	Change this line ----->Wire.begin(2,14);
	to this			 ----->Wire.begin();
	to allow this sensor to communicate with CC01 and CR01
	
*************************************************************/

#include <xCore.h> //add core library @ https://github.com/xinabox/xCore
#include <xPB04.h> //add sensor library @ https://github.com/xinabox/xPB04
#include <xOD01.h> //add sensor library @ https://github.com/xinabox/xOD01

const int DELAY_TIME = 1000;

xPB04 PB04;
  
void setup(){
  OLED.begin();
  
	// Start the Serial Monitor
	Serial.begin(115200);
	
	// Set the I2C Pins for CW01
	#ifdef ESP8266
	  Wire.pins(2, 14);
	  Wire.setClockStretchLimit(15000);
	#endif
	
	// Start the I2C Comunication
	Wire.begin();
	
	// Start the Battery Sensor
	PB04.begin();
	
	// Small delay for sensor to normalise
	delay(5000);
	
	OD01.println("====================================");
 	OD01.println("PB04 Current Measurement  ");
	OD01.println("====================================");
}

void loop(){
	// Create a variable to store the data read from PB04
	float current;
	current = 0;
	
	// Poll the sensor to read all available data
	PB04.poll();
	
	// Request PB04 to get the current measurement and store in
	// the current variable
	current = PB04.getCurrent();
	
	// Display the recorded data over the serial monitor
	OD01.print("Current on battery is :");
	OD01.print(current);
	OD01.println(" mA");
	
	delay(DELAY_TIME);
}
