/*
A function can be defined as a friend function of the class to freely access the private members of the class.
Neither a constructor nor a destructor can be a friend function.
In the program below we will use a friend function that adds the value assigned to two float variables belonging to two different classes called Alpha and Beta.
The friend function forms a kind of bridge between the two classes and has access to the private data of both the classes.
*/

#include <iostream>

using namespace std;

class Beta; // Needed for forward declaration
/*
The declaration is essential because the class 'Beta' is referred to in the declaration of the friend function 'init()' in the class 'Alpha'
If we do not make this declaration the compiler will give an error since the 'Beta' class specifier comes after that of 'Alpha'
*/

class Alpha 
{
	private:
	float energy_level;
	public:
	Alpha() // Constructor
	{
		energy_level = 5.0;
	}
	
	friend float init(Alpha, Beta); // Friend function
};

class Beta
{
	private:
	float energy_level;
	public:
	Beta() // Constructor
	{
		energy_level = 10.0;
	}

	friend float init(Alpha, Beta); // Friend function 
};

/*
Note that the friend function is defined outside of any class.
It does not need a scope resolution operator as it does not belong to either class.
*/
float init(Alpha aa, Beta bb) // Definition of friend function
{
	return (aa.energy_level + bb.energy_level);
}

int main()
{
	Alpha obj1;
	Beta obj2;
	cout << init(obj1, obj2) << " is the combined energy level" << endl;

	return 0;
}