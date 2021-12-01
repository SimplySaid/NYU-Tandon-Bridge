#include <iostream>

int* findMaxValuePtr(int* arr, int arrLength);

int main() {
	int n = 0;

	std::cout << "Enter the number of elements in your set: ";
	std::cin >> n;

	int* userInput = new int[n];

	std::cout << "Enter the elements separated by a space";
	for (int i = 0; i < n; ++i) {
		std::cin >> userInput[i];
	}

	std::cout << findMaxValuePtr(userInput, n) << "\n";

	delete[] userInput;
}

int* findMaxValuePtr(int* arr, int arrLength) {
	int* currMax = &arr[0];
	std::cout << arrLength << "\n";
	
	for (int i = 1; i < arrLength; ++i) {
		if (arr[i] > *currMax)
			currMax = &arr[i];
	}
	return currMax;
}


/*
#include <iostream>

int main() {
	int a, b;

	std::cout << "Enter two integers a, b as an input: ";
	std::cin >> a >> b;

	int* ptrA = &a;
	int* ptrB = &b;

	std::cout << *ptrA << " " << *ptrB;

	return 0;
}
*/
