//control_GPIO.cpp
//function will take gpio output number, hi/low, and gpio input number
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#define GPIO_PATH "/sys/class/gpio/" 

string ledpin;

void writeGPIO(string filename, string value)
{
  ostringstream sled;
  sled << "gpio" << filename;
  string ledpinname = string(sled.str());
  string ledPath = (GPIO_PATH + ledpinname + "/value");

  fstream fs;
  string path(ledPath);
  cout << path << endl;
  fs.open(path.c_str(), fstream::out);
  fs << value;
  fs.close();
}

string readGPIO(string pinread)
{
  ostringstream sbutton;
  sbutton << "gpio" << pinread;
  string buttonpinname = string(sbutton.str());
  string buttonpath = (GPIO_PATH + buttonpinname + "/value");


  ifstream fs;
  string path(buttonpath);
  fs.open((path).c_str(),fstream::in);
  string input;
  getline(fs,input);
  fs.close();
  return input;
}
int main(int argc, char* argv[])
{
    if(argc<=3)
    {
        cout << "usage of control_GPIO is LED pin, state, button read pin" << endl;
	cout << "e.g. 12 high 16" << endl;
    }

    string ledpin(argv[1]);
    string cmd(argv[2]);
    string button(argv[3]);
    
    if(cmd == "high")
    {
        writeGPIO(ledpin,"1");
	cout << "turing led on" << endl;
    }
    else if (cmd == "low")
    {
        writeGPIO(ledpin,"0");
	cout << "turning led off" << endl;
    }
    else
    {
        cout << "invalid command" << endl;
    }

    string gpioOutput =  readGPIO(button);
    cout << gpioOutput << endl;
}
