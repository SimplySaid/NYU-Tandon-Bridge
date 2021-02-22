/* This program takes two inputs and outputs their sum */

//#include <iostream>
//using namespace std;
/*
int main()
{
	int n1;
	int n2;

	cout << "Please enter two numbers separated by a space:" << endl;
	cin >> n1 >> n2;

	cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;

	return n1 + n2;

}

*/

/*
cout = console output
cin = console input

<< = continue outputting
>> = continue inputting
*/

/*
//This program translates the amount of days into weeks and days
#include <iostream>
using namespace std;

const int DAYS_IN_WEEK = 7;

int main() {
	int traveled;

	cout << "Input the amount of days traveled" << endl;
	cin >> traveled;

	cout << "You have traveled " << traveled / DAYS_IN_WEEK << " weeks and " << traveled % DAYS_IN_WEEK << " days";

	return traveled / DAYS_IN_WEEK;
}
*/

/*
//This program calculates the area of a circle based on entered radius
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

//const double PI = 3.14159;

int main(){

	float radius;
	cout << "Enter desired radius" << endl;
	cin >> radius;

	cout << "The circle area is: " << (radius * radius) * M_PI << endl;

	return 0;
}
*/

/*
//This program takes a char input and converts it to its integer representation
#include <iostream>
using namespace std;

int main() {

	char inputCharacter;

	cout << "Input your character" << endl;
	cin >> inputCharacter;

	cout << "The character you inputted can be converted to: " << (int)inputCharacter << endl;

	return 0;
}
*/

//This program converts a lower-case char into a upper-case char
#include <iostream>
#include <string>
using namespace std;

int main() {
	char lowerChar = 0;

	while (lowerChar < 97 or lowerChar > 116) {
		cout << "Enter a lowercase Char" << endl;
		cin >> lowerChar;
	}

	cout << "Your char in uppercase is " << (char)(lowerChar - 32) << endl;

	return 0;
}