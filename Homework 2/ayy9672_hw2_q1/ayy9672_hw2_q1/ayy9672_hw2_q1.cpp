#include <iostream>

const double QUARTER_VALUE = .25, DIME_VALUE = .1, NICKEL_VALUE = .05, PENNY_VALUE = .01;

int main() {
	double totalValue;
	int numQuarters, numDimes, numNickels, numPennies;

	std::cout << "Please enter number of coins:" << std::endl;
	
	std::cout << "# of quarters: ";
	std::cin >> numQuarters;

	std::cout << "# of dimes: ";
	std::cin >> numDimes;

	std::cout << "# of nickels: ";
	std::cin >> numNickels;

	std::cout << "# of pennies: ";
	std::cin >> numPennies;

	totalValue = (numQuarters * QUARTER_VALUE) + (numDimes * DIME_VALUE) + (numNickels * NICKEL_VALUE) + (numPennies * PENNY_VALUE);

	std::cout << "The total is " << (int)totalValue << " dollars and " << (int)((totalValue - (int)totalValue)*100) << " cents";

	return 0;
}



