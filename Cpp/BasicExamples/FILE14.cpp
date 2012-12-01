/*
Operators  ++, --, <=, >, += can be overloaded to give additional operations for user-defined types, such as classes.
Operator overloading can be done for unary and binary operators.
In the program below we will see how the unary operators, such as the increment (++) and decrement operators (--), can be overloaded.
The program will be used to convert a string with alphabets in the lower case to upper case with an overloaded operator ++.
The decrement operator will be used to convert a string, which contains lower case alphabets, to upper case.
*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class Converter
{
	private:
	string str;
	public:
	Converter()
	{
		str = "";
	}

	Converter(string s)
	{
		str = s;
	}

	void display()
	{
		cout << str << endl;
	}

	/*
	When ++ and -- are overloaded, the compiler does not distinguish between the prefix and postfix notation.
	You will notice that both the operators have two functions each. 
	The function that uses the syntax, operator++(); does the prefix operation and the function that uses, operator++(int); performs the postfix operation. 
	The int argument is just a dummy and is only included for the compiler to distinguish the two forms.
	We have used both notations in the program to illustrate how the operator functions work.
	*/

	Converter operator++() // Prefix
	{
		transform(str.begin(), str.end(), str.begin(),(int (*)(int))toupper);
		return str;
	}

	Converter operator++(int) // Postfix
	{
		Converter ss(str);
		transform(ss.str.begin(), ss.str.end(), ss.str.begin(),(int (*)(int))toupper);
		return ss;
	}

	Converter operator--() // Prefix
	{
		transform(str.begin(), str.end(), str.begin(),(int (*)(int))tolower);
		return str;		
	}

	Converter operator--(int) // Postfix
	{
		Converter ss(str);
		transform(ss.str.begin(), ss.str.end(), ss.str.begin(),(int (*)(int))tolower);
		return ss;
	}
};

int main()
{
	Converter s1("changed to UPPERCASE");
	Converter s2("BACK TO LOWER CASE");
	Converter s3("ending on a low note");
	Converter s4;
	int i,j;
	++s1;
	cout << "++s1 = ";
	s1.display();
	--s2;
	cout << "--s2 = ";
	s2.display();
	s4 = s3++;
	cout << "Result of s4 = s3++" << endl << "s3 = ";
	s3.display();
	cout << "s4 = ";
	s4.display();

	return 0;
}