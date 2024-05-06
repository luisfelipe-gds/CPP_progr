#include <iostream>
using namespace std;

/*
	>	greater than
	>=	greater than or equal to
	<	less than
	<=	less than or equal to
	==	equal-to (equality)
	!=	not-equal-to (equality)

*/


int main() {
	
	cout << boolalpha; //sticky operator - stays until you write noboolalpha

	int a = 15;
	int b = 20;
	bool areEqual = a == b;

	int myAge = 34;


	cout << (a < b) << endl;
	cout << areEqual << endl;
	cout << "myAge >= 21? " << (myAge >= 21) << endl;
	
	return 0;
}
