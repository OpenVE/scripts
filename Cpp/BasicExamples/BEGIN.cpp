#include <iostream>
/*
The line '#include <iostream>' instructs the compiler to include the declarations of the standard stream input and output.
The declarations are found in the header file iostream.
*/

using namespace std;

int main()
{
	cout << "My first program in C++" << endl;
	/*
	'cout' is defined in the header file 'iostream'. It is used to display text and values on th screen.
	The operator << ("put to") writes value on its right-hand side to the left-hand side.
	In this case, the string "My first program in C++" is written onto the standard output stream 'cout'.
	*/

	return 0;
}