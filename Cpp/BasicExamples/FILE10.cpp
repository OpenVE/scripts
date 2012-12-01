/*
In the program below we will use the file FILE7.cpp.
In this program we will use constructos to initialise the values of the data members hours, minutes and seconds of the class Time.
You will see how constructors can be used with different arguments or no arguments to create objects.
The program will take two Time objects, add them and display the result.
A destructor will also be used to destroy the objects.
*/

#include <iostream>

using namespace std;

class Time
{
	private:
	int hours;
	int minutes;
	int seconds;
	public:
	Time() // Constructors
	{
		hours=minutes=seconds=0;
		cout << "In default constructor" << endl; 
	}

	Time(int h, int m, int s)
	{
		hours=h;
		minutes=m;
		seconds=s;
		cout << "Constructor with three arguments" << endl; 
	}

	void display(void)
	{
		cout << hours << ":" << minutes << ":" << seconds << endl; 
	}

	void addit(Time aa, Time bb)
	{
		hours = aa.hours + bb.hours;
		minutes = aa.minutes + bb.minutes;
		seconds = aa.seconds + bb.seconds;
		// Checking that seconds is < 60
		if (seconds >= 60)
		{
			seconds -= 60;
			minutes++;
		}
		// Checking that minutes < 60
		if (minutes >= 60)
		{
			minutes -= 60;
			hours++;
		}
	}

	~Time() // Destructor
	{
		cout << "In destructor" << endl; 
	}
};

int main()
{
	Time result;
	Time one(1, 49, 45);
	Time two(3, 40, 30);
	result.addit(one, two);
	cout << "The result is : ";
	result.display();	

	return 0;
}