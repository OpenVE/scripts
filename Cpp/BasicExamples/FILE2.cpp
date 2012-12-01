/*
The following program explains the concepts of class and object. 
It accepts your name and age as input from standard input and displays it on the standard output.
It also checks the person's age and displays a message.
*/

#include <iostream>

using namespace std;

class person
{
	public:
	char name[16];
	int age;
}; // end of class person

int main()
{
	person myself;
	cout << "Enter your name: " << endl;
	cin >> myself.name; // 'cin' accepts input from the user. It is defined in the header file 'iostream'.
	cout << "Your name is " << myself.name << endl;
	cout << "Enter your age: " << endl;	
	cin >> myself.age;
	cout << "Your age is " << myself.age << endl;
	
	if(myself.age < 100) {cout << "You are pretty young!" << endl;}
	if(myself.age == 100){cout << "You are old" << endl;}
	if(myself.age > 100) {cout << "You are really old" << endl;}

	return 0;
}