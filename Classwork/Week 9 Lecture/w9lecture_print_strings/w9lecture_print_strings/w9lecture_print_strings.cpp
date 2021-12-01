/*
#include <iostream>
#include <string>

int main() {
	int n;

	std::cout << "Please enter number of lines:\n";
	std::cin >> n;
	std::cin.ignore();

	std::string* userInput = new std::string[n];

	std::cout << "Please enter " << n << " lines" << std::endl;

	for (int i = 0; i < n; ++i) {
		std::getline(std::cin, userInput[i]);
	}

	std::cout << userInput[0] << "\n";

	for (int i = 0; i < n; ++i) {
		std::cout << i + 1 << ". " << userInput[i] << "\n";
	}

	delete[] userInput;

	return 0;
}
*/

