/*
The following program will help you understand how classes and objects are defined. 
This program we will first write a class containing an integer variable and the define an object of the class in the main() program.
The data variable will be assigned a value, which will be displayed on to the standard output.
*/

#include <iostream>

using namespace std;

class myclass
{
	public:
	int data1;
};

int main()
{
	myclass object1;
	object1.data1 = 25;
	cout << "The value of data1 is " << object1.data1 << endl;

	return 0;
}