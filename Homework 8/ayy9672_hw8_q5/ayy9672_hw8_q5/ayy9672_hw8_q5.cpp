#include <iostream>
#include <string>

void printName(std::string fName, std::string mName, std::string lName);

int main() {
	std::string fName, mName, lName;

	std::cout << "Please input your name: ";
	std::cin >> fName >> mName >> lName;
	printName(fName, mName, lName);

	return 0;
}

void printName(std::string fName, std::string mName, std::string lName) {
	/*
	if (mName[mName.length() - 1] == '.') {
		std::cout << lName << ", " << fName << " " << mName[]
	}
	*/
	std::cout << lName << ", " << fName << " " << mName[0] << ".";
}