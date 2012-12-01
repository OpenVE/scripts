/*
This is a program that uses member functions to read the data variables of a class and display the contents of the class objects.
Here we will use a member function that accepts objects as parameters.
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
	void getinfo(void)
	{
		cin >> hours >> minutes >> seconds;
	}
	void display(void)
	{
		cout << hours << ":" << minutes << ":" << seconds << endl; 
	}
	/* 
	In this member function we will perform a check to see if the added minutes and seconds are greater than 59.
	If the seconds are greater than 59, the minutes will be incremented by one. 
	Similarly the hours will be incremented by one if the minutes are greater than 59.
	*/
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
};

int main()
{
	Time one, two, three;
	// While entering the time separate the values for the hours, minutes and seconds using the spacebar.
	cout << "Enter the first time (hours minutes seconds): ";
	one.getinfo();
	cout << "Enter the second time (hours minutes seconds): ";
	two.getinfo();
	// The function addit() is used to add the two Time objects passed to it as arguments.
	three.addit(one, two);
	cout << "The result is : ";
	three.display();	

	return 0;
} // End of function main