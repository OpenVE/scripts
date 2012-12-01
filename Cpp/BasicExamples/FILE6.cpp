/*
The program below is also used to display the date. The value for the date that is input by the user is displayed.
We will see how this is done using member functions to receive input and display the results.
*/

#include <iostream>

using namespace std;

class date
{
	private:
	int day;
	int month;
	int year;
	public:
	void getdata(void)
	{
		cout << "Enter the day (dd): ";
		cin >> day;
		cout << "Enter the day (mm): ";
		cin >> month;
		cout << "Enter the year (yy): ";
		cin >> year;
	} // End of function getdate
	void display(void)
	{
		cout << "The date is " << day << "/" << month << "/" << year << endl; 
	} // End of function display
};

int main()
{
	date today;
	today.getdata();
	today.display();

	return 0;
} // End of function main