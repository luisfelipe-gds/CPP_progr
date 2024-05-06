#include <iostream>
using namespace std;

int main() {

	bool isRaining = true;
	bool isWarm = true;

	cout << boolalpha;

	cout << "And: " << (isRaining && isWarm) << endl;
	cout << "Or: " << (isRaining || isWarm) << endl;
	cout << "Not: " << !isRaining << endl;

	isRaining = true;
	isWarm = false;

	cout << "And: " << (isRaining && isWarm) << endl;
	cout << "Or: " << (isRaining || isWarm) << endl;
	cout << "Not: " << !isRaining << endl;

	isRaining = false;
	isWarm = true;

	cout << "And: " << (isRaining && isWarm) << endl;
	cout << "Or: " << (isRaining || isWarm) << endl;
	cout << "Not: " << !isRaining << endl;

	isRaining = false;
	isWarm = false;

	cout << "And: " << (isRaining && isWarm) << endl;
	cout << "Or: " << (isRaining || isWarm) << endl;
	cout << "Not: " << !isRaining << endl;

	return 0;

}
