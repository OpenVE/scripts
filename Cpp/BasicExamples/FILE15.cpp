/*
Binary operators can also be overloaded as easily as unary operators.
Binary operators work with two operands.
In an overloaded binary operator function the operand on the operator is passed to function as the argument.
The left-hand side operand is accessed directly since this is the object that invokes the function.
In the program below we will overload a compound assignment operator +=.
This operator combines assignment and addition in one step.
The operator function that we will use will add one phrase, s2, to another, s1, and assign the result to s1.
The function can also be used to add phrases in the form s3 = s1 += s2.
*/

#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 80;

class Phrase
{
	public:
	char str[SIZE];

	Phrase() // Constructors
	{
		strcpy(str,"");
	}

	Phrase(string s)
	{
		strcpy(str,s.c_str());
	}

	void display()
	{
		cout << str << endl;
	}

	/*
	The function need not return a value. 
	In such a case, the result of the operation is assigned to the operand on the left-hand side, which is the object that actually invokes the function.
	To return a value from the overloaded operator function we have used a this pointer.
	This is a more elegant use than creating a temporary object and passing its value.	
	*/
	Phrase operator +=(Phrase aa) // Overloaded +=
	{
		if(strlen(str)+strlen(aa.str)<SIZE)
			strcat(str,aa.str);
		else
			cout << "String is too long" << endl;
		
		return (*this);
	}
};

int main()
{
	Phrase s1;
	Phrase s2("Check the program ");
	s1 += s2;
	s1.display();

	strcpy(s1.str,"Next ");
	
	Phrase s3;
	s3 = s1 += s2;
	s3.display();

	Phrase s4;
	Phrase s5("and again ");
	s4 = s2 += s5 += s5;
	s4.display();

	return 0;
}