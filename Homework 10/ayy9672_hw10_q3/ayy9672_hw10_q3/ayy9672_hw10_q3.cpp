#include <iostream>
#include <vector>

void printArray(int arr[], int arrSize);
int* doubleArrSize(int* arr, int& arrSize);
bool searchArr(int* arr, int arrSize, int*& foundIndicies, int& foundIndiciesSize, int n);
int main1();
int main2();

int main() {
	std::cout << "Program 1 without Vectors: \n";
	main1();
	std::cout << "\n";

	std::cout << "Program 2 with Vectors: \n";
	main2();

	return 0;
}

int main1() {
	int userInput = 0; int logicalSize = 1, arrElements = 0, search = 0;
	int* userInputArr = new int[1]();

	std::cout << "Please enter a sequence of positive integers, each in a separate line.\n";
	std::cout << "End your input by typing -1.\n";

	while (true) {
		std::cin >> userInput;

		if (userInput == -1)
			break;

		if (arrElements == logicalSize - 1) {
			userInputArr = doubleArrSize(userInputArr, logicalSize);
		}

		userInputArr[arrElements] = userInput;
		arrElements++;
	}

	std::cout << "Please enter the number you want to search.\n";
	std::cin >> search;

	int* results = new int[1](); 
	int resultsSize = 0;
	
	if (searchArr(userInputArr, arrElements, results, resultsSize, search)) {
		std::cout << search << " shows in lines ";
		printArray(results, resultsSize);
	}
	else
		std::cout << search << " was not found.";
	
	return 0;
}

void printArray(int arr[], int arrSize) {
	int i;
	for (i = 0; i < arrSize; i++) {
		if (i == arrSize - 1)
			std::cout << arr[i] + 1 << '.';
		else
			std::cout << arr[i] + 1 << ", ";
	}
	std::cout << std::endl;
}

bool searchArr(int* arr, int arrSize, int*& foundIndicies, int& foundIndiciesSize, int n) {
	bool found = false;
	int* resultsArr = new int[1];
	int resultsArrLogicalSize = 1, resultsArrSize = 0;

	for (int i = 0; i < arrSize; ++i) {
		if (arr[i] == n) {
			found = true;
			if (resultsArrSize == resultsArrLogicalSize)
				resultsArr = doubleArrSize(resultsArr, resultsArrLogicalSize);
			resultsArr[resultsArrSize] = i;
			resultsArrSize++;
		}
	}
	foundIndiciesSize = resultsArrSize;
	delete[] foundIndicies;
	foundIndicies = resultsArr;
	return found;
}

int* doubleArrSize(int* arr, int& arrSize) {
	int* tempArr = new int[arrSize * 2];
	for (int i = 0; i < arrSize; ++i) {
		tempArr[i] = arr[i];
	}
	arrSize *= 2;
	delete[] arr;
	return tempArr;
}

int main2() {
	int userInput = 0, search = 0; 
	std::vector<int> userInputVector;
	bool found = false;

	std::cout << "Please enter a sequence of positive integers, each in a separate line.\n";
	std::cout << "End your input by typing -1.\n";

	while (true) {
		if (userInput == -1)
			break;

		std::cin >> userInput;
		userInputVector.push_back(userInput);
	}

	std::cout << "Please enter the number you want to search.\n";
	std::cin >> search;

	std::vector<int> results;

	for (int i = 0; i < userInputVector.size(); ++i) {
		if (userInputVector[i] == search) {
			found = true;
			results.push_back(i);
		}
	}

	if (found == true) {
		std::cout << search << " shows in lines ";
		for (int i = 0; i < results.size(); ++i) {
			if (i == results.size() - 1)
				std::cout << results[i] + 1 << '.';
			else
				std::cout << results[i] + 1 << ", ";
		}
	}
	else
		std::cout << search << " was not found.";

	return 0;
}