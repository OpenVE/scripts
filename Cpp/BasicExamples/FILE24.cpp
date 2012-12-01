/*
Destructors are invoked to automatically free memory that has been assigned to objects.
However the destructor member function of the derived class is not invoked to free the memory storage which was allocated by the constructor of the derived class.
This is because destructor functions are non-trivial and the message does not reach the destructor member function under dynamec binding.
In such a situation it is better to have a virtual destructor function.
In the program shown below we will use a base class which does not have a virtual destructor.
You can see from the output displayed that the destructor of the derived class is not invoked.
*/

#include <iostream>
#include <cstring>

using namespace std;

class Sentence
{
	private:
	char* str;
	public:
	Sentence(); 
	~Sentence();
};

class Phrase:public Sentence
{
	private:
	char* phr;
	public:
	Phrase();
	~Phrase();
};

Sentence::Sentence() // Base constructor
{
	str = new char[50];
	strcpy(str, "This sentence is worth considering\n");
	cout << str;	
}

Sentence::~Sentence() // Base's destructor
{
	delete[] str;
	cout << "Releasing the worthy sentence" << endl;
}

Phrase::Phrase() // Derived class constructor
{
	phr = new char[25];
	strcpy(phr, "This is only a humble phrase\n");
	cout << phr;	
}

Phrase::~Phrase() // Derived class destructor
{
	delete[] phr;
	cout << "Releasing the humble phrase" << endl;	
}

int main()
{
	Sentence* ptr = new Phrase;
	delete ptr;

	return 0;
}