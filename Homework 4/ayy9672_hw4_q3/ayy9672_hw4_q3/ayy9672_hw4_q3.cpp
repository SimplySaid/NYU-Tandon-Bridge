#include <iostream>
#include <cmath>

int main() {
	double userInput;

	std::cout << "Enter decimal number:\n";
	std::cin >> userInput;

	std::cout << "The binary representation of " << userInput << " is ";

	//Find the most significant bit, represented by n
	int n = 0;
	while (userInput >= std::pow(2, n+1)) {
		n++;
	}

	for (int i = n; i >= 0; i--) {
		if (userInput - std::pow(2, i) >= 0) {
			std::cout << 1;
			userInput -= std::pow(2, i);
		}
		else {
			std::cout << 0;
		}
	}

	return 0;
}