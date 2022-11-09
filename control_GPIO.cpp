//control_GPIO.cpp
//function will take gpio output number, hi/low, and gpio input number
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdio>
#include <unistd>
#include <string>

#define LED_PATH "/sys/bus/iio/devices/iio:device0"


void writeLED(string name, string value)
{
	ofstream ledstream;
	ledstream.open(LED_PATH.c_str());
	ledstream << value;
	ledstream.close();
}

string readButton(string name)
{
	ifstream buttonstream;
	buttonstream.open(BUTTON_PATH.c_str());
	string buttonVAL;
	getline(buttonstream,buttonVAL);
	buttonstream.close();
	return buttonVAL;
}

writeLED(i )
{

string GPIOout = argv[0];
string ledVAL = argv[1];
string GPIOin = argv[2];

ostringstream LED_PIN;
LED_PIN << "gpio" << GPIOout;
string LED_name = string(LED_PIN.str());
LED_PATH = GPIO_PATH + LED_name + "/";

ostringstream BUTTON_PIN;
BUTTON_PIN << "gpio" << GPIOin;
string BUTTON_name = string(LED_BUTTON.str());
BUTTON_PATH = GPIO_PATH + BUTTON_name + "/";

writeLED(LED_name,ledVAL);
string buttonVALUE = readButton(BUTTON_name);


}
