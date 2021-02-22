#include <iostream>
#include <string>

int main() {
	double decimalInput, temporaryValue;
	std::string romanNumeral;

	std::cout << "Enter decimal number:\n";
	std::cin >> decimalInput;

	temporaryValue = decimalInput;

	while (temporaryValue > 0) {
		if (temporaryValue >= 1000) {
			temporaryValue -= 1000;
			romanNumeral += 'M';
		}
		else if (temporaryValue >= 500) {
			temporaryValue -= 500;
			romanNumeral += "D";
		}
		else if (temporaryValue >= 100) {
			temporaryValue -= 100;
			romanNumeral += "C";
		}
		else if (temporaryValue >= 50) {
			temporaryValue -= 50;
			romanNumeral += "L";
		}
		else if (temporaryValue >= 10) {
			temporaryValue -= 10;
			romanNumeral += "X";
		}
		else if (temporaryValue >= 5) {
			temporaryValue -= 5;
			romanNumeral += "V";
		}
		else if (temporaryValue >= 1) {
			temporaryValue -= 1;
			romanNumeral += "I";
		}
	}

	std::cout << decimalInput << " is " << romanNumeral;
}