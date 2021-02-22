#include <iostream>

const int MINUTES_IN_DAY = 1440, MINUTES_IN_HOUR = 60;

int main() {
	int johnDaysWorked, johnHoursWorked, johnMinutesWorked;
	int billDaysWorked, billHoursWorked, billMinutesWorked;
	int runningTotalMinutesWorked;

	std::cout << "Please enter the number of days John has worked: ";
	std::cin >> johnDaysWorked;

	std::cout << "Please enter the number of hours John has worked: ";
	std::cin >> johnHoursWorked;

	std::cout << "Please enter the number of minutes John has worked: ";
	std::cin >> johnMinutesWorked;

	std::cout << "\nPlease enter the number of days Bill has worked: ";
	std::cin >> billDaysWorked;

	std::cout << "Please enter the number of hours Bill has worked: ";
	std::cin >> billHoursWorked;

	std::cout << "Please enter the number of minutes Bill has worked: ";
	std::cin >> billMinutesWorked;

	//Add up the total amount of time worked by John and Bill in minutes
	runningTotalMinutesWorked = johnDaysWorked * MINUTES_IN_DAY + johnHoursWorked * MINUTES_IN_HOUR + johnMinutesWorked
		+ billDaysWorked * MINUTES_IN_DAY + billHoursWorked * MINUTES_IN_HOUR + billMinutesWorked;

	//Calculates and Prints Days, Hours, Minutes based on Total Time worked by John and Bill
	std::cout << "\nThe total time both of them worked together is: " << runningTotalMinutesWorked / MINUTES_IN_DAY;
	runningTotalMinutesWorked = runningTotalMinutesWorked % MINUTES_IN_DAY;

	std::cout << " days, " << runningTotalMinutesWorked / MINUTES_IN_HOUR;
	runningTotalMinutesWorked = runningTotalMinutesWorked % MINUTES_IN_HOUR;

	std::cout << " hours and " << runningTotalMinutesWorked << " minutes.";

	return 0;
}