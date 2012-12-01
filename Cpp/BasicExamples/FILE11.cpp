/*
In C++ the 'new' operator often appears in constructors to allocate memory while initialising an object.
This memory has to be deallocated. This is usually done using the 'delete' operator in a destructor. 
In the program below we will use a class that contains a data member which is a string.
We will use a constructor to allocate memory for the string using the 'new' operator.
The destructor of the class will 'delete' the memory space that is allocated to the string data member.
*/

#include <iostream>
#include <cstring>

using namespace std;

class Command 
{
	private:
	char* name;
	public:
	Command(string s) // Constructor
	{
		int size = strlen(s.c_str()); // Length of string argument
		name = new char[size+1]; // Allocate memory
		strcpy(name, s.c_str()); // Copy argument to name
	}
	
	void display();

	~Command() // Destructor
	{
		delete[] name;
	} 
};

void Command::display() 
{
	cout << name << endl;
	cout << "Lenght of the command string: " << strlen(name) << endl;
}


int main()
{
	Command first("Start of program");
	Command second("Stopping");
	first.display();
	second.display();

	return 0;
}