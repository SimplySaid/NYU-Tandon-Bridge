#include <iostream>
#include <string>

int main() {
	std::string studentName, studentStatus;
	int graduationYear, currentYear;

	std::cout << "Please enter your name: ";
	std::cin >> studentName;

	std::cout << "Please enter your graduation year: ";
	std::cin >> graduationYear;

	std::cout << "Please enter current year: ";
	std::cin >> currentYear;

	//Calculate the student status based on graduation year and current year
	if (graduationYear - currentYear <= 0) {
		studentStatus = "Graduated"; //If I wanted gramatical correctness, this would be graduate, but prompt asks for Graduated
	}
	else if (graduationYear - currentYear == 1) {
		studentStatus = "Senior";
	}
	else if (graduationYear - currentYear == 2) {
		studentStatus = "Junior";
	}
	else if (graduationYear - currentYear == 3) {
		studentStatus = "Sophomore";
	}
	else if (graduationYear - currentYear == 4) {
		studentStatus = "Freshman";
	}
	else {
		studentStatus = "not in college yet";
	}

	std::cout << studentName << ", you are a" << studentStatus;

	return 0;
}