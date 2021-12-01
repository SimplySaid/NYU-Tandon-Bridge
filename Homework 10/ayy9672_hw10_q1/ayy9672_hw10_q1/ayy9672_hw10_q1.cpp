#include <iostream>
#include <string>

std::string* createWordsArray(std::string sentence, int& outWordsArrSize);
int countWordsInString(std::string sentence);

int main() {
	std::string str = "";
	int numWords = 0;
	
	std::cout << "Please enter your sentence: \n";
	std::getline(std::cin, str);

	std::string* words = createWordsArray(str, numWords);

	std::cout << "There are " << numWords << " in your sentence which are: \n";
	for (int i = 0; i < numWords; ++i) {
		std::cout << words[i] << "\n";
	}

	delete[] words;
	words = nullptr;
	
	return 0;
}

std::string* createWordsArray(std::string sentence, int& outWordsArrSize) {
	int lastIndex = 0, nextIndex = 0, arrayIndex = 0;
	std::string* words = new std::string[countWordsInString(sentence) + 1];

	do
	{
		nextIndex = sentence.find(' ', lastIndex);
		words[arrayIndex] =  sentence.substr(lastIndex, nextIndex - lastIndex);
		arrayIndex = arrayIndex+1;
		lastIndex = nextIndex + 1;
	} while (nextIndex != -1);
	outWordsArrSize = arrayIndex;
	return words;
}

int countWordsInString(std::string sentence) {
	int count = 0;
	
	for (int i = 0; i < sentence.length(); ++i) {
		if (sentence[i] == ' ')
			count++;
	}
	return count;
}