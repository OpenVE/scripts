/*
Using the assignment operator and copy constructor we can create a String class.
When we use the overloaded assignment operator to assign one String object to another we copy the string from the source into the destination object.
Now the same string exists in two places in memory.
In the program shown below we will use the String class and provide the full complement of operations such as constructors, copy constructor, overloaded assignment operator, and destructor.
*/

#include <iostream>
#include <cstring>

using namespace std;

class String
{
	private:
	char* str;
	public:
	String()
	{
	}

	String(string s) // One-arg constructor
	{
		cout << "In constructor" << endl;
		int size = strlen(s.c_str());
		str = new char[size+1];
		strcpy(str,s.c_str());
	}

	String(String& ss) // Copy constructor
	{
		cout << "In copy constructor" << endl;
		str = new char[strlen(ss.str) + 1];
		strcpy(str,ss.str);
	}

	~String() // Destructor
	{
		delete str;
	}
	
	String& operator=(String& ss) // Assignment operator
	{
		cout << "Assignment invoked" << endl;
		str = new char[strlen(ss.str) + 1];
		strcpy(str, ss.str);
		return *this;
	}

	void showstring()
	{
		cout << str << endl;
	}


};

int main()
{
	String s1("String in memory");
	cout << "s1 = ";
	s1.showstring();
	String s2(s1);
	cout << "s2 = ";
	s2.showstring();	
	String s3;
	s3=s1;
	cout << "s3 = ";
	s3.showstring();
	String s4 = s1;
	cout << "s4 = ";
	s4.showstring();

	return 0;
}