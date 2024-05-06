#include <iostream>;
using namespace std;

int main() {

	bool isSunny = true;
	bool isWarm = false;
	
	//boolalpha manipulates boolean values to use words instead of numbers

	cout << boolalpha;
	cout << "Is it Sunny? " << isSunny << endl;
	cout << "Is it Warm? " << isWarm << endl;
	
	return 0;

}
