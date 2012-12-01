/*
The following program will write a class which has a private data member and public member functions.
We will see how the member functions are to access the private data member of the objects created and assign values.
*/

#include <iostream>

using namespace std;

class Hotel1_rooms
{
	private:
	int room_no;
	public:
	void set(int invalue)
	{
		room_no = invalue;
	}
	int getvalue()
	{
		return room_no;
	}
};

int main()
{
	Hotel1_rooms room1, room2, room3;
	int suite_no;
	room1.set(12);
	room2.set(17);
	room3.set(13);
	suite_no = 123;
	cout << "The number of room1 is " << room1.getvalue() << endl;
	cout << "The number of room2 is " << room2.getvalue() << endl;
	cout << "The number of room3 is " << room3.getvalue() << endl;
	cout << "The number of suite_no is " << suite_no << endl;
	/*
	Observe the way the values are assigned to the data member of the objects created and to the variable 'suite_no'. 
	The function getvalue is used to display the value of the data member.
	*/

	return 0;
}