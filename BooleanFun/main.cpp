#include <iostream>;
using namespace std;

int main() {

	bool isSunny = true;
	bool isWarm = false;
	
	//boolalpha manipulates boolean values to use words instead of numbers

	cout << "Is it Sunny? " << boolalpha << isSunny << endl;
	cout << "Is it Warm? " << boolalpha << isWarm << endl;
	
	return 0;

}
