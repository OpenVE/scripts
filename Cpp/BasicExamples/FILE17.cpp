/*
Type conversion from basic types to user-defined types, such as objects, and vice versa, or between user-defined types have to be defined explicitly since the compiler knows only about converting basic types.
In the program below we will see how conversion of an object of a class to character string is done.
The conversion function overloads the typecast operator.
*/

#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 80;

class String
{
	private:
	char str[SIZE];
	public:
	String()
	{	
		strcpy(str,"");
	}

	String(string s) 
	{
		strcpy(str,s.c_str());
	}

	void getstr()
	{
		cout << "Enter a string" << endl;
		cin >> str;
	}

	void display() 
	{
		cout << "String in object = " << str << endl;
	}

	operator char*()
	{
		return (str);
	}

	String& operator=(char* s)
	{
		strcpy(str, s);
		return *this;		
	}
};

int main()
{
	String s1;
	char* p;
	s1.getstr();
	s1.display();
	p = s1;
	cout << "String p = " << p << endl;
	char n[15] = "New String";
	s1 = n;
	s1.display();

	return 0;
}