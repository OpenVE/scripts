/*
In the program below we will see how constructors and destructors are implemented.
The program will be used to generate the area of a rectangle, give the length and width.
The program will also make use of scope resolution operator to define member functions outside the class specifier.
*/

#include <iostream>

using namespace std;

class rectangle // A simple class
{
	private:
	int height;
	int width;
	public:
	rectangle(); // A constructor
	int area();
	void initialise(int, int);
	~rectangle(); // And a destructor
};

// Constructors are used to automatically initialise an object when it is created, without the need to make a separate call to a member function.
rectangle::rectangle() // Constructor
{
	cout << "Rectangle constructor in action" << endl;
	height = 6;
	width = 6;
}

int rectangle::area() // Area of a rectangle
{
	return height * width;
}

void rectangle::initialise(int init_height, int init_width)
{
	cout << "Initialising rectangle with given values" << endl;
	height = init_height;
	width = init_width;
}

// Following the same principle, a destructor is a function that is automatically called when an object is destroyed.
rectangle::~rectangle() // Destructor
{
	cout << "Rectangle destructor in action" << endl;
}

int main()
{
	rectangle box, square;
	int can_ht, can_width, can_area;
	cout << "The area of the box is " << box.area() << endl;
	cout << "The area of the square is " << square.area() << endl;
	box.initialise(12, 10);
	square.initialise(8, 8);
	cout << "The area of the box is " << box.area() << endl;
	cout << "The area of the square is " << square.area() << endl;
	can_ht = 50;
	can_width = 6;
	can_area = can_ht * can_width;
	cout << "The area of the can is " << can_area << endl;

	return 0;
}