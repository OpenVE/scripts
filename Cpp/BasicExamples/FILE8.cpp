/*
Arrays are user defined data types whose members are of the same type. For practical applications such as designing a larga database, arrays are very useful.
Arrays of class objects are used in a manner similar to other basic data types.
This is a program that will define a class Student with the roll number and marks as the data members.
The average marks obtained by the students are calculated and displayed along with the student details.
*/

#include <iostream>

using namespace std;

class Student
{
	private:
	int rollno;
	int marks;
	public:
	void getinfo(void)
	{
		cout << "Enter the Roll number: ";
		cin >> rollno;
		cout << "Enter the marks: ";
		cin >> marks;
	}
	void display(void)
	{
		cout << rollno << " " << marks << endl; 
	}
	int getmarks(void)
	{	
		return marks;
	}
}; // End of class Student

int main()
{
	Student stulist[100];
	float total, average;
	int no, i;
	total = 0.0;
	/*
	It will prompt you to enter the number of students for whom details will be supplied.
	You will also be prompted to enter the roll number and marks of the students.
	*/
	cout << "Enter the number of students: ";
	cin >> no;
	for (i=0; i<no; i++)
	{
		stulist[i].getinfo();
		total = total + stulist[i].getmarks(); // Adding the marks
	}
	cout << "Rollno Marks " << endl;
	for (i=0; i<no; i++)
	{
		stulist[i].display();
	}	
	average = total / no; // Find the average
	cout << "Average marks: " << average << endl;

	return 0;
} // End of function main