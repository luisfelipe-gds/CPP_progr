#include <iostream>
using namespace std;

/* 

    This program prompts the user for 3 real numbers and calculates their mean value.

*/

int main() {
  
  double num1;
  double num2;
  double num3;
  double average;

  cout << "Please enter a real number: " << endl;
  cin >> num1;
  
  cout << "Please enter another real number: " << endl;
  cin >> num2;
  
  cout << "Please enter the last real number: " << endl;
  cin >> num3;

  average = (num1 + num2 + num3) / 3;

  cout << "The average is: " << average << endl;
  
  return 0;
}
