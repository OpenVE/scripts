/*
Let us look at another program that makes use of virtual functions.
In the program shown below we will use one base class from which we have one publicly derived class.
The program is an example of how text can be generated in a desired format.
The derived class overrides only certain functions of the base class.
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
	virtual void body()
	{	
		cout << "  This is body text" << endl;
	}
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
	void header()
	{	
		cout << "This is the new header" << endl;
	}
	void footer()
	{	
		cout << "This is the new footer" << endl;
	}
};

int main()
{
	Format* first_form = new Format;
	first_form->display_form(); // A call to the base class
	delete first_form;
	first_form = new MyForm;
	first_form->display_form(); // A call to the derived class

	return 0;
}