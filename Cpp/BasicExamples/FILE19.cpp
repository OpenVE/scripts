/*
Multiple inheritance occurs when a class derives from more then one base class. 
It inherits the properties of its base classes.
A derived class inherits data members and function from all its base classes regardless of whether the inheritance is public, private or protected.
In the program shown below we will use two base classes from which we have one publicly derived class.
The program will take information from the user regarding a student's personal information and academic record and display it.
*/

#include <iostream>

using namespace std;

class Person_data // One base class
{
	private:
	char name[25];
	int roll_no;
	char sex;
	public:
	void getinfo();
	void display();
};

class Academics // Second base class
{
	private:
	char course_name[25];
	int semester;
	char grade[3];
	public:
	void getinfo();
	void display();
};

/*
The derived class has been declared as publicly inherited. 
To be able to access the private data members of its base classes, the derived class calls the member functions of the base classes.
*/
class Stud_scholarship : public Person_data, public Academics // Public derived class
{
	private:
	float amount;
	public:
	void getinfo();
	void display();
};

void Person_data::getinfo()
{
	cout << "Name? ";
	cin >> name;
	cout << "Roll number? ";
	cin >> roll_no;
	cout << "Sex (F/M)? ";
	cin >> sex;
}

void Person_data::display()
{
	cout << name << "\t";
	cout << roll_no << "\t";
	cout << sex << "\t";
}

void Academics::getinfo()
{
	cout << "Course name (BA/MBA/MCA etc)? ";
	cin >> course_name;
	cout << "Semester (1/2/3/...)? ";
	cin >> semester;
	cout << "Grade (A,B,B+,B-...)? ";
	cin >> grade;
}

void Academics::display()
{
	cout << course_name << "\t";
	cout << semester << "\t\t";
	cout << grade << "\t";
}

//When the base classes have member functions with identical names we need to use the scope resolution operator to refer to the correct class.
void Stud_scholarship::getinfo()
{
	Person_data::getinfo();
	Academics::getinfo();
	cout << "Assistance received (in $)? ";
	cin >> amount;
}

void Stud_scholarship::display()
{
	Person_data::display();
	Academics::display();
	cout << amount  << endl;
}

int main()
{
	Stud_scholarship obj;
	cout << "Please enter the following information:" << endl;
	obj.getinfo();
	cout << endl;
	cout << "Name\tRollno\tSex\tCourse\tSemester\tGrade\tAmount" << endl;
	obj.display();

	return 0;
}