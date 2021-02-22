#include <iostream>

const double POUND_TO_KILO = .453592, INCH_TO_METER = .0254;

int main() {
	int inputWeight, inputHeight;
	double weightMetric, heightMetric, bmi;

	std::cout << "Please enter weight (in pounds): ";
	std::cin >> inputWeight;

	std::cout << "Please enter height (in inches): ";
	std::cin >> inputHeight;

	weightMetric = inputWeight * POUND_TO_KILO;
	heightMetric = inputHeight * INCH_TO_METER;

	bmi = weightMetric / (heightMetric * heightMetric);
	
	if (bmi < 18.5)
		std::cout << "The weight status is: Underweight";
	else if (bmi >= 18.5 && bmi < 25)
		std::cout << "The weight status is: Normal";
	else if (bmi >= 25 && bmi < 30)
		std::cout << "The weight status is: Overweight";
	else if (bmi >= 30) //Using else if instead of else for more readable code
		std::cout << "The weight status is: Obese";

	return 0;

}