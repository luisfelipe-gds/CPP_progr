#include <iostream>
#include <string>
using namespace std;

/*
	This is a program that simulates a MadLibs game.
	The user is prompted for several strings and the program places these strings in a preset story.

*/

int main() {

	string adjective1;
	string girlsName;
	string adjective2;
	string occupation1;
	string placeName;
	string clothing;
	string hobby;
	string adjective3;
	string occupation2;
	string boysName;
	string mansName;

	cout << "Please, enter an adjective." << endl;
	getline(cin, adjective1);
	cout << "Please, enter a girl's name." << endl;
	getline(cin, girlsName);
	cout << "Please, enter another adjective." << endl;
	getline(cin, adjective2);
	cout << "Please, enter an occupation." << endl;
	getline(cin, occupation1);
	cout << "Please, enter the name of a place." << endl;
	getline(cin, placeName);
	cout << "Please, enter the name of a clothing in plural." << endl;
	getline(cin, clothing);
	cout << "Please, enter a hobby." << endl;
	getline(cin, hobby);
	cout << "Please, enter yet another adjective." << endl;
	getline(cin, adjective3);
	cout << "Please, enter another occupation." << endl;
	getline(cin, occupation2);
	cout << "Please, enter a boy's name." << endl;
	getline(cin, boysName);
	cout << "Please, enter a man's name." << endl;
	getline(cin, mansName);

	cout << "There once was a " << adjective1 << " girl named " << endl;
	cout << girlsName << " who was a " << adjective2 << endl;
	cout << occupation1 << " in the Kingdom of " << endl;
	cout << placeName << ". She loved to wear " << clothing << endl;
	cout << " and " << hobby << ". She wanted to marry the " << endl;
	cout << adjective3 << " " << occupation2 << " named " << endl;
	cout << boysName << " but her father, King " << mansName << endl;
	cout << " forbid her from seeing him." << endl;

	return 0;

}
