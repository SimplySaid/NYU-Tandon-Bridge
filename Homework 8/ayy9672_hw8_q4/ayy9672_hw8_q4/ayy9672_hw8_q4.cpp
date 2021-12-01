#include <iostream>
#include <cmath>
#include <string>
#include <ctime>

void generateNums(int arr[]);
bool checkCorrectPIN(std::string str, int arr[]);

const std::string PIN = "12345";

int main() {
	int numMapping[10];
	std::string userInput;

	std::cout << "Please enter your PIN according to the following mapping: \n";
	std::cout << "PIN: 0 1 2 3 4 5 6 7 8 9 \n";

	std::cout << "NUM: ";

	generateNums(numMapping);
	for (int i = 0; i < 10; ++i) {
		std::cout << numMapping[i] << " ";
	}
	std::cout << "\n";

	std::cin >> userInput;

	if (checkCorrectPIN(userInput, numMapping)) {
		std::cout << "Your PIN is correct";
	}
	else {
		std::cout << "Your PIN is not correct";
	}

	return 0;
}

void generateNums(int arr[]) {
	srand(time(0));
	for (int i = 0; i < 10; ++i) {
		arr[i] = rand() % 3 + 1;
	}
}

bool checkCorrectPIN(std::string str, int arr[]) {
	for (int i = 0; i < str.length(); ++i) {
		if (arr[PIN[i] - '0'] != str[i] - '0') {
			return false;
		}
	} 
	return true;
}
