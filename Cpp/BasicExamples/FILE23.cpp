/*
A pure function is declared by assigning the value of zero to the function.
A class containing one or more pure virtual functions cannot be used to define an object.
The class is therefore only useful as a base class to be inherited into a useable derived class.
It is called an abstract class.
Every derived class must include a function for each pure virtual function that is inherited from the base class if it will be used to create an object.
*/

#include <iostream>

using namespace std;

class Format
{
	public:
	void display_form();
	virtual void header()
	{	
		cout << "This is a header" << endl;
	}
	virtual void body() = 0; // Pure virtual function
	virtual void footer()
	{	
		cout << "This is a footer" << endl << endl;
	}
};

void Format::display_form()
{
	header();
	for(int index = 0; index < 3; index++)
	{
		body();
	}
	footer();
}

//This class overrides two of the virtual methods of the base class
class MyForm:public Format
{
	void body()
	{	
		cout << "  This is the new body text" << endl;
	}
	void footer()
	{	
		cout << "This is the new footer" << endl;
	}
};

int main()
{
	// The next three lines of code are invalid since Format is
	// now an abstract class and an object cannot be created
	// Format* first_form = new Format;
	// first_form->display_form(); // A call to the base class
	// delete first_form;
	// An object of the derived class
	Format* first_form = new MyForm;
	first_form->display_form(); // A call to the derived class

	return 0;
}