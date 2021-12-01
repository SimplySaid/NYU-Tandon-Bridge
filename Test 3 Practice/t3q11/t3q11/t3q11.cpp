#include <iostream>
#include <fstream>
#include <string>
#include <queue>

std::string addTwoFiles(std::fstream& f1, std::fstream& f2);
std::fstream readFile();

std::fstream readFile() {
	std::string fileName;
	std::fstream userFile;
	std::cout << "Please enter the name of your file: ";
	std::cin >> fileName;
	userFile.open(fileName);

	while (!userFile) {
		std::cout << "File not found. Please enter the name of your file: ";
		std::cin >> fileName;
		userFile.open(fileName);
	}
	return userFile;
}

std::string addTwoFiles(std::fstream& f1, std::fstream& f2) {
	std::queue<char> f1output;
	std::queue<char> f2output;
	std::string output;
	char temp;

	while (f1 >> temp)
		f1output.push(temp);

	while (f2 >> temp)
		f2output.push(temp);

	int carry = 0;
	while (!f1output.empty() || !f2output.empty()) {
		output += std::to_string(((int)(f1output.front() - '0') + ((int)f2output.front() - '0') + carry) % 10);
		carry = ((int)(f1output.front() - '0') + (int)(f2output.front() - '0')) / 10;
		std::cout << carry << "\n";
		f1output.pop();
		f2output.pop();
	}

	return output;
}

int main() {
	std::fstream f1;
	std::fstream f2;
	f1 = readFile();
	f2 = readFile();
	
	std::cout << addTwoFiles(f1, f2);

	return 0;
}