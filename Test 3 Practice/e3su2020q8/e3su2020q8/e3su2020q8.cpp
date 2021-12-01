#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

std::fstream readFile() {
	std::fstream userFile;
	
	std::string userFileName;
	std::cout << "Please enter the name of your file: ";
	std::cin >> userFileName;
	userFile.open(userFileName);

	while (!userFile) {
		std::cout << "File not found. Please enter the name of your file: ";
		std::cin >> userFileName;
		userFile.open(userFileName);
	}
	return userFile;
}


int main() {
	std::fstream wordsFile = readFile();
	std::map<std::string, int> res;
	std::string temp;

	while (wordsFile >> temp) {
		//if (res.find(temp) == res.end())
		res[temp] += 1;
	}

	std::ofstream outputFile;
	outputFile.open("output.txt");
	for (auto val : res) {
		outputFile << val.first << " " << val.second << "\n";
	}
	outputFile.close();

	return 0;
}