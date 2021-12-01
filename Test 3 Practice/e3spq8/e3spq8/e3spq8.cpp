#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

std::fstream openFile() {
	std::fstream userFile;
	std::string userFileName;
	
	std::cout << "Please enter the name of your file";
	std::cin >> userFileName;
	userFile.open(userFileName);

	while (!userFile) {
		std::cout << "File name invalid: Please enter the name of your file";
		std::cin >> userFileName;
		userFile.open(userFileName);
	}
	return userFile;
}


int main() {
	std::fstream idFile = openFile();
	std::vector<int> rawData;
	std::vector<int> res;
	int temp;

	while (idFile >> temp) {
		rawData.push_back(temp);
	}

	for (int i = 0; i < rawData.size(); ++i) {
		if (std::find(res.begin(), res.end(), rawData[i]) == res.end())
			res.push_back(rawData[i]);
	}

	std::ofstream outputFile;
	outputFile.open("output.txt");
	for (int i = 0; i < res.size(); ++i) {
		outputFile << res[i] << "\n";
	}
	outputFile.close();

	return 0;
}


