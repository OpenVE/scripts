/*
This is a program that shows how functions with the same name can be overloaded with different data types and different number of arguments.
The function selected is based on the number and types of the formal parameters only.
The type of the return value is not significant in overload resolution.
The program given below uses member functions to display words and characters.
These member functions are overloaded to take arguments of type integer, char or string.
*/

#include <iostream>
#include <cstring>

using namespace std;

class Words 
{
	private:
	int num;
	char title[20];
	public:
	Words() // Constructor
	{
		num = 0;
		strcpy(title," ");
	}
	
	void display(int i) // Display with int argument
	{
		num = i;
		cout << "Parameter is " << num << endl;
		cout << "This is not a string" << endl;
	}

	void display(char c) // Display with char argument
	{
		title[0] = c;
		cout << "Parameter is " << title[0] << endl;
		cout << "This is a single letter" << endl;
	}

	void display(string s) // Display with string argument
	{
		strcpy(title, s.c_str());
		cout << "Parameter is " << title << endl;
		cout << "String length is: " << strlen(title) << endl;
	}

	void display(string s, int i) // Display with string and int
	{
		strcpy(title, s.c_str());
		cout << "Parameters are " << title << " and " << num << endl;
		cout << "String length is: " << strlen(title) << endl;
	}
};

int main()
{
	Words obj;
	obj.display(120);
	obj.display('B');
	obj.display("GNU");
	obj.display("Linux Tux", 5);

	return 0;
}