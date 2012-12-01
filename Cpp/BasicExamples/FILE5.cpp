/*
If the keyword public is not used to define the members of a class, the C++ compiler assumes, by default, that all its members are private.
*/

#include <iostream>

using namespace std;

class date
{
	// By default, members are private.
	int day;
	int month;
	int year;
};

int main()
{
	date today;
	// Such private members are not accessible outside the class.
	// You can see from the error message that the accessibility of the data variables changes when they are treated as private members of the class.	
	today.day = 26;
	today.month = 10;
	today.year = 2012;
	cout << "The date is " << today.day << "/" << today.month << "/" << today.year << endl; 
	// To access the private data members you will need to use member functions.

	return 0;
}