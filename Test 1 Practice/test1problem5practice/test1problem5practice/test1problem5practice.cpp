#include <iostream>
#include <cmath>

/*
int main() {
	int userInput, digitSum = 0;

	std::cout << "Please enter an integer: ";
	std::cin >> userInput;

	while (userInput > 0) {
		digitSum += userInput % 10;
		userInput /= 10;
	}

	std::cout << digitSum;

	return 0;
}
*/

int main() {
	int n;

	std::cout << "Please enter a number n which will serve as the maximum possible number of stars in a row: ";
	std::cin >> n;

	for (int i = 0; i < 2*n-1; ++i) {
		int padding = std::abs(n - i - 1);
		for (int j = 0; j < padding; ++j) {
			std::cout << " ";
		}
		for (int k = 0; k < 2*n-1 - (2 * padding); ++k) {
			std::cout << "*";
		}
		std::cout << "\n";
	}

	return 0;
}