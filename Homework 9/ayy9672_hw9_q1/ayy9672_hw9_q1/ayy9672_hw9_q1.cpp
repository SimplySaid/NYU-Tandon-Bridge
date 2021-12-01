#include <iostream>
#include <string>

void toLower(std::string& str);

const int SIZE_OF_LETTERS = 26;

int main() {
	std::string userInput;
	int lettersCount[SIZE_OF_LETTERS] = {0}; //Initialize array of 0's
	int numWords = 0;
	bool hitDelimiter = false;

	std::cout << "Please enter a line of text: \n";
	std::getline(std::cin, userInput);
	toLower(userInput);
	
	for (int i = 0; i < userInput.length(); ++i) {
		if (userInput[i] >= 'a' && userInput[i] <= 'z') {
			lettersCount[userInput[i] - 'a'] += 1;
			if (hitDelimiter) {
				numWords++;
				hitDelimiter = !hitDelimiter;
			}
		}
		else if (userInput[i] == '.' || userInput[i] == ',' || userInput[i] == ' ')
			hitDelimiter = true;
	}
	if (userInput.length() > 0)
		numWords++;

	std::cout << numWords << "\t" << "words\n";

	for (int i = 0; i < SIZE_OF_LETTERS; ++i) {
		if (lettersCount[i] >= 1)
			std::cout << lettersCount[i] << "\t" << (char)('a' + i) << "\n";
	}
	
	return 0;
}

void toLower(std::string &str) {
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - ('Z' - 'z');
	}
}