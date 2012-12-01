/*
Using inheritance in object-oriented programming we are able to reuse functions from one class to another.
The accessibility of the base class members varies depending on whether they are private, public or protected.
Members of the derived class can access only the public and protected members of the base class.
In the program below we will see how  single inheritance is implemented in a program.
We will use protected data members in the base class and publicly derive two classes from a base class.
We will see how the protected data members of the base class are accessed from the derived class.
*/

#include <iostream>

using namespace std;

/*
The class 'Vehicle' is the base class for two derived classes, 'Car' and 'Truck'.
It contains two protected data members, and several functions in the public section.
*/
class Vehicle
{
	protected:
	int wheels;
	double weight;
	public:
	void initialise(int whls, double wght);
	
	int get_wheels()
	{
		return wheels;
	}

	double get_weight()
	{
		return weight;
	}
	
	double wheel_loading()
	{
		return weight/wheels;
	}
};

class Car : public Vehicle
{
	private:
	int passenger_load;
	public:
	void initialise(int whls, double wght, int people = 4);
	
	int passengers()
	{
		return passenger_load;
	}
};

class Truck : public Vehicle
{
	private:
	int passenger_load;
	double payload;
	public:
	void init_truck(int number = 2, double max_load = 24000.0);
	
	double efficiency();

	int passengers()
	{
		return passenger_load;
	}
};

//Initialise to any data desired

void Vehicle::initialise(int whls, double wght)
{
	wheels = whls;
	weight = wght;	
}

void Car::initialise(int whls, double wght, int people)
{
	passenger_load = people;
	wheels = whls;
	weight = wght;	
}

void Truck::init_truck(int number, double max_load)
{
	passenger_load = number;
	payload = max_load;
}

double Truck::efficiency()
{
	return payload / (payload + weight);
}

int main()
{
	Vehicle bicycle;
	bicycle.initialise(2, 25);
	cout << "The bicycle has " << bicycle.get_wheels() << " wheels." << endl;
	cout << "The bicycle's wheel loading is " << bicycle.wheel_loading() << " pounds on a single tire." << endl;
	cout << "The bicycle weighs " << bicycle.get_weight() << " pounds." << endl << endl;
	Car coupe;
	coupe.initialise(4, 3500.0, 5);
	cout << "The coupe carries " << coupe.passengers() << " passengers." << endl;
	cout << "The coupe weighs " << coupe.get_weight() << " pounds." << endl;
	cout << "The coupe's wheel loading is " << coupe.wheel_loading() << " pounds per tire." << endl << endl;	
	Truck van;
	van.initialise(18, 12500.0);
	van.init_truck(1, 33675.0);
	cout << "The van weighs " << van.get_weight() << " pounds." << endl;
	cout << "The van's efficiency is " << 100.0 * van.efficiency() << " percent." << endl;

	return 0;
}