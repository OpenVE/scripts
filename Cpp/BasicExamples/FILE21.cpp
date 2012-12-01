/*
In the context of programming, polymorphism allows you to refer to objects of different classes by means of the same program item and to perform the same operation in different ways, depending on which object is being referred to.
In C++, one way polymorphism is implemented is through the use of virtual functions.
When virtual functions are used, the system makes the decision of which method to actually call based on which object the pointer is pointing to.
The decision of which function to call is not made during the time when the code is compiled but when the code is executed.
This is dynamic binding and can be very useful in some programming situations.
In the program below we will see how virtual functions are used.
We will use a protected data member in the base class and publicly derive two classes from the base class.
The base class will have a virtual member function that is redefined in the derived classes.
*/

#include <iostream>

using namespace std;

class Person
{
	protected:
	const char* name;
	public:
	Person(string n)
	{	
		name=n.c_str();
	}
	virtual void print()
	{
		cout << "My name is " << name << endl;
	}
};

class Foreigner:public Person
{
	public:
	Foreigner(string f):Person(f){}
	void print()
	{	
		cout << "IL mio nome e " << name << endl;
	}
};

class Alien:public Person
{
	public:
	Alien(string s):Person(s){}
	void print()
	{	
		cout << "##$&(<@$%@!#@$%~~***@## " << name << endl;
		cout << "Sorry, there is a communication problem" << endl;
	}
};

int main()
{
	Person* person1;
	person1 = new Person("Jack");
	cout << "Introducing a Person: " << endl;
	person1->print();
	Person* person2;
	person2 = new Foreigner("Maria");
	cout << "Introducing a Foreigner: " << endl;
	person2->print();
	person1 = new Foreigner("Al Pacino");
	cout << "Reintroducing the Person: " << endl;
	person1->print();
	Person* person3;
	person3 = new Alien("Martian");
	cout << "Introducing the Alien: " << endl;
	person3->print();

	return 0;
}