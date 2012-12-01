/*
In the program shown below we will modify the previous program so that the base class destructor is made virtual.
It is a good idea to supply a virtual destructor in all classes that act as a base class, specially when objects of the derived class are manipulated and deleted through a pointer to the base.
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
	virtual ~Sentence(); // Destructor made virtual
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

/*
This program is similar to the previous one except that the base class destructor has been made virtual.
You can see from the output that the derived class destructor is called before that of the base class.
*/
int main()
{
	Sentence* ptr = new Phrase;
	delete ptr;

	return 0;
}