#include <iostream>
#include <cmath>


int main() {
	//Section A
	std::cout << "section a" << std::endl;

	int sequenceLength;
	double inputTotal = 1;
	std::cout << "Please enter the length of the sequence:";
	std::cin >> sequenceLength;

	for (int i = 0; i < sequenceLength; i++) {
		int temp;
		std::cin >> temp;

		inputTotal *= temp;
	}

	std::cout << std::pow(inputTotal, 1.0 / sequenceLength) << std::endl;

	//Section B
	std::cout << "section b" << std::endl;
	double whileInputTotal = 1;

	std::cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:\n";

	int temp = 1, m = 0;
	while (true) {
		std::cin >> temp;
		if (temp == -1) {
			break;
		}
		whileInputTotal *= temp;
		m += 1;
	}

	std::cout << std::pow(whileInputTotal, 1.0 / m);

	return 0;
}
