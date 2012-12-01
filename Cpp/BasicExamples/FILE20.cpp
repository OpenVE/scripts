/*
When constructors are used in the base class and derived classes, the base class is initialised before the derived class, using either the default constructor or a constructor with arguments depending on the code of the constructor of the derived class.
The base class constructors are invoked first.
The order in which they are invoked is the same order in which the base classes are declared in the derived class declaration.
If there are any member objects in the class, they are initialised next, in the order they appear in the class declaration.
Finally the derived class constructor is called.
*/

#include <iostream>

using namespace std;

class Alpha
{
	public:
	Alpha()
	{	
		cout << "Constructor of class Alpha" << endl;
	}
};

class Beta:public Alpha
{
	public:
	Beta():Alpha()
	{	
		cout << "Constructor of class Beta, derived from Alpha" << endl;
	}
};

class Gamma:public Alpha
{
	public:
	Gamma():Alpha()
	{	
		cout << "Constructor of class Gamma, derived from Alpha" << endl;
	}
};

class Delta:public Gamma,public Beta
{
	Beta b; // Base class object
	public:
	Delta():Gamma(),Beta()
	{	
		cout << "Constructor of class Delta, derived from Beta and Gamma" << endl;
		cout << "having a Beta object inside";
	}
};

/*
In this program we will see how the constructors are called when multiple inheritance is used.
The classes have all got default constructors.
Let us see the order in which the constructors are called.
*/
int main()
{
	cout << "Defining an object of class Alpha" << endl;
	Alpha aa;
	cout << endl;
	cout << "Defining an object of class Beta" << endl;
	Beta bb;
	cout << endl;
	cout << "Defining an object of class Gamma" << endl;
	Gamma cc;
	cout << endl;
	cout << "Defining an object of class Delta" << endl;
	Delta dd;
	cout << endl;
	return 0;
}