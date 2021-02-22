#include <iostream>
#include <cmath>
#include <string>

/*
void printAsterisks(int n, int k) {
	std::string line;

	int padding = (k - n) / 2;
	for (int i = 0; i < k; i++) {
		if (i < padding || (k - padding) <= i) {
			line += " ";
		}
		else {
			line += "*";
		}
	}
	std::cout << line << "\n";
}
*/

int main() {
	int n, lineLength, numAsterisks, padding;

	std::cout << "Enter a positive integer: ";
	std::cin >> n;

	lineLength = 2 * n - 1;

	for (int i = 0; i < 2 * n; i++) {
		//printAsterisks(std::abs((2 * n - 1) - (i * 2)), 2*n-1);
		std::string line;

		numAsterisks = std::abs((2 * n - 1) - (i * 2));
		int padding = (lineLength - numAsterisks) / 2;

		for (int i = 0; i < lineLength; i++) {
			if (i < padding || (lineLength - padding) <= i) {
				line += " ";
			}
			else {
				line += "*";
			}
		}
		std::cout << line << "\n";
	}

	return 0;
}