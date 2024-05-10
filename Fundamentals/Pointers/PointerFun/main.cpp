#include <iostream>
using namespace std;

int main()
{
	int myInt{ 150 };
	int* somePtr{ &myInt }; // The star notation means I'm declaring a pointer to an int variable. The ampersand & operator retrieves the memory address of that variable.
	double myDouble{ 3.14 };
	double* dblPtr{ &myDouble };

	cout << "myInt is originally: " << myInt << endl;
	cout << "pointer holds value: " << somePtr << endl;
	cout << "pointer dereferenced: " << *somePtr << endl; //putting the star in front of a pointer variable dereferences it, bringing the actual value.

	*somePtr = 200;  //changing the dereferenced variable is simpluy changing the original value.

	cout << "myInt is now: " << myInt << endl;
	cout << "myDouble is: " << *dblPtr << endl;
	cout << "pointer holds value: " << dblPtr << endl;

	return 0;
}
