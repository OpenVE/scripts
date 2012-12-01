/*
The program below is used to display the date. 
The date is assigned a value in the main() program.
This program will demonstrate the accessibility of the data members of a class when they are declared as public.
*/

#include <iostream>

using namespace std;

class date
{
	public: // The data members are declared public, they can be accessed in the main() program.
	int day;
	int month;
	int year;
};

int main()
{
	date today;
	today.day = 26;
	today.month = 10;
	today.year = 2012;
	cout << "The date is " << today.day << "/" << today.month << "/" << today.year << endl;
	// The 'endl' is an output manipulator to generate a carriage return or line feed character. 

	return 0;
}