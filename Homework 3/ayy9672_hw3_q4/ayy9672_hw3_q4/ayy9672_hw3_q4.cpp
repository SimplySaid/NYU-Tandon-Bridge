#include <iostream>

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {
	double userNumInput;
	int userRoundingInput;

	std::cout << "Please enter a Real number:" << std::endl;
	std::cin >> userNumInput;

	std::cout << "Choose your rounding method: \n1. Floor round \n2. Ceiling round \n3. Round to the nearest whole number" << std::endl;
	std::cin >> userRoundingInput;

	if (userNumInput == (int)userNumInput) {
		std::cout << userNumInput;
	}
	else {
		switch (userRoundingInput) {
			case FLOOR_ROUND:
				if (userNumInput >= 0) {
					std::cout << (int)userNumInput;
				}
				else {
					std::cout << (int)(userNumInput - 1);
				}
				break;
			case CEILING_ROUND:
				if (userNumInput >= 0) {
					std::cout << (int)(userNumInput + 1);
				}
				else {
					std::cout << (int)userNumInput;
				}
				break;
			case ROUND:
				if (userNumInput >= 0) {
					std::cout << (int)(userNumInput + .5);
				}
				else {
					std::cout << (int)(userNumInput - .5);
				}
				break;
			default:
				std::cout << "Rounding Input Invalid";
				break;
			}
	}
	return 0;
}