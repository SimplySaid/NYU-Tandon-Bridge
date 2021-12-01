#include <iostream>

int minInArray(int arr[], int arrSize);

int main() {
	int userInput[20], minValue;

	std::cout << "Please enter 20 integers separated by a space:\n";

	for (int i = 0; i < 20; ++i) {
		std::cin >> userInput[i];
	}
	minValue = minInArray(userInput, 20);
	std::cout << "The minimum value is " << minValue << ", and it is located in the following indicies: ";

	for (int i = 0; i < 20; ++i) {
		if (userInput[i] == minValue)
			std::cout << i << " ";
	}
	return 0;
}

int minInArray(int arr[], int arrSize) {
	int minVal = arr[0];

	for (int i = 1; i < arrSize; ++i) {
		if (arr[i] < minVal)
			minVal = arr[i];
	}
	return minVal;
}