#include <iostream>

int printMonthCalendar(int numOfDays, int startingDay);
bool checkLeapYear(int year);
void printYearCalendar(int year, int startingDay);

int main() {
	int inputYear, inputStartDate;

	std::cout << "Please enter a year: ";
	std::cin >> inputYear;

	std::cout << "Enter the day that year starts on: ";
	std::cin >> inputStartDate;

	printYearCalendar(inputYear, inputStartDate);
	std::cout << checkLeapYear(2015);
	return 0;
}

int printMonthCalendar(int numOfDays, int startingDay) {
	//Print calendar header
	std::cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun\n";

	for (int i = 0; i < startingDay - 1; ++i) {
		std::cout << "\t";
	}

	for (int i = 1; i <= numOfDays; ++i) {
		std::cout << i;
		if ((i + startingDay - 1) % 7 == 0 && i != numOfDays)
			std::cout << "\n";
		else
			std::cout << "\t";
	}
	return (startingDay + numOfDays - 1) % 7;
}

bool checkLeapYear(int year) {
	return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

void printYearCalendar(int year, int startingDay) {
	int daysInMonth;
	for (int i = 1; i <= 12; ++i) {
		switch (i) {
			case 1:
				std::cout << "January " << year << "\n";
				daysInMonth = 31;
				break;
			case 2:
				std::cout << "February " << year << "\n";
				if (checkLeapYear(year))
					daysInMonth = 29;
				else
					daysInMonth = 28;
				break;
			case 3:
				std::cout << "March " << year << "\n";
				daysInMonth = 31;
				break;
			case 4:
				std::cout << "April " << year << "\n";
				daysInMonth = 30;
				break;
			case 5:
				std::cout << "May " << year << "\n";
				daysInMonth = 31;
				break;
			case 6:
				std::cout << "June " << year << "\n";
				daysInMonth = 30;
				break;
			case 7:
				std::cout << "July " << year << "\n";
				daysInMonth = 31;
				break;
			case 8:
				std::cout << "August " << year << "\n";
				daysInMonth = 31;
				break;
			case 9:
				std::cout << "September " << year << "\n";
				daysInMonth = 30;
				break;
			case 10:
				std::cout << "October " << year << "\n";
				daysInMonth = 31;
				break;
			case 11:
				std::cout << "November " << year << "\n";
				daysInMonth = 30;
				break;
			case 12:
				std::cout << "December " << year << "\n";
				daysInMonth = 31;
				break;
		}
		startingDay = printMonthCalendar(daysInMonth,startingDay) + 1;
		std::cout << "\n\n";
	}
}
