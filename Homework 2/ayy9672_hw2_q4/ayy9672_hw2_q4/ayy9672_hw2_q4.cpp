#include <iostream>

int main() {
	int num1, num2;

	//Assign values to num1 and num2 based on user input
	std::cout << "Please enter two positive integers, separated by a space:" << std::endl;
	std::cin >> num1 >> num2;

	//Print out sum, difference, product, quotient, div and mod
	std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
	std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
	std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
	std::cout << num1 << " / " << num2 << " = " << (double)num1 / (double)num2 << std::endl;
	std::cout << num1 << " div " << num2 << " = " << num1 / num2 << std::endl;
	std::cout << num1 << " mod " << num2 << " = " << num1 % num2 << std::endl;

	return 0;
}