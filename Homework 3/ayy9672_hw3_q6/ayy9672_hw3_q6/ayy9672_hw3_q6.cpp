#include <iostream>
#include <iomanip>
#include <string>

int main() {
	int timeHour, timeMinute, callDuration;
	double rate;
	char temp;
	std::string weekday;

	std::cout << "Enter the abbreviation for the day of the week (Mo, Tu, We, Th, Fr, Sa, Su): ";
	std::cin >> weekday;

	std::cout << "Enter the call start time in a 24-hour notation (e.g., 1:30 P.M. should be input as 13:30) ";
	std::cin >> timeHour >> temp >> timeMinute;

	std::cout << "Enter the duration of the call in minutes: ";
	std::cin >> callDuration;

	timeMinute += timeHour * 60;

	if (weekday == "Sa" || weekday == "Su") {
		rate = .15;
	}
	else {
		if (timeMinute >= 480 && timeMinute <= 1080) {
			rate = .40;
		}
		else {
			rate = .25;
		}	
	}

	//Print out the cost with two decimal points since the output should be a currency amount
	std::cout << "The cost of the call is: $" << std::fixed << std::setprecision(2) << (double)callDuration * rate;

	return 0;
}