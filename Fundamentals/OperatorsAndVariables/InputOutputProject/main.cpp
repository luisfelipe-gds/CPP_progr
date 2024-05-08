#include <iostream>
#include <string>
using namespace std; //resolution operator

/*

	Input Output Project

	-> Create a fullName string variable
	-> Create a location string variable
	-> Create an integer named initialScore

	-> Prompt the user for their fullName, which should be store in the proper variable
	-> Prompt the user for their city, state/province, and country, and store that in the location variable
	-> Ask the user for an integer between 0 and 100, to be stored in initialScore
	-> At the end, print out the following:
		- "Hello, " followed by fullName
		- "We heard you are from location " followed by location
		- "Your original score is initialScore, but with five points added, you score is 
			<< print out the initial score plus five points >>
*/

int main() {
	
	string fullName;
	string location;
	int initialScore;
	
	cout << "Please enter your project score (0-100): " << endl;  //insertion operator
	cin >> initialScore;		//just get the input, not the entire line, since we're dealing with an integer
	
	cin.get();		//to make sure the program consumes the <">new line character>

	cout << "Please enter you full name: " << endl;
	getline(cin, fullName);		//get the entire string line

	cout << "Please enter your city, state/province, and country of residence: " << endl;
	getline(cin, location);
	
	cout << "Hello, " << fullName << endl;
	cout << "We heard you are from " << location << endl;
	cout << "Your original score is " << initialScore << endl;
	cout << "But with five points added, you score is " << (initialScore + 5) << endl;
	
	return 0;
}
