#include <iostream>
#include <string>

const double QUARTER_VALUE = .25, DIME_VALUE = .10, NICKEL_VALUE = .05, PENNY_VALUE = .01;

int main() {
	double inputDollars, inputCents, runningTotalAmount;
	int quarters, dimes, nickels, pennies;
	
	std::cout << "Please enter your amount in the format of dollars and cents separated by a space: " << std::endl;
	std::cin >> inputDollars >> inputCents;

	runningTotalAmount = inputDollars + (inputCents / 100);

	quarters = runningTotalAmount / QUARTER_VALUE;
	runningTotalAmount = runningTotalAmount - (QUARTER_VALUE * quarters);

	dimes = runningTotalAmount / DIME_VALUE;
	runningTotalAmount = runningTotalAmount - (DIME_VALUE * dimes);

	nickels = runningTotalAmount / NICKEL_VALUE;
	runningTotalAmount = runningTotalAmount - (NICKEL_VALUE * nickels);

	pennies = runningTotalAmount / PENNY_VALUE;
	runningTotalAmount = runningTotalAmount - (PENNY_VALUE * pennies);

	std::cout << inputDollars << " dollars and " << inputCents << " cents are:" << std::endl;
	std::cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " << pennies << " pennies";

	return 0;
}
