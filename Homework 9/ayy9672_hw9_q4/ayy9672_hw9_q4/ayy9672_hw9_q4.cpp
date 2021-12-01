#include <iostream>

void oddsKeepEvensFlip(int arr[], int arrSize);

int main() {

	int arraySizeEntered;

	std::cout << "Enter the size of the array:\n";
	std::cin >> arraySizeEntered;

	int* numArray = new int[arraySizeEntered];

	std::cout << "Enter the numbers into the array: " << std::endl;

	for (int i = 0; i < arraySizeEntered; i++) {
		std::cin >> numArray[i];
	}

	oddsKeepEvensFlip(numArray, arraySizeEntered);

	for (int i = 0; i < arraySizeEntered; ++i) {
		std::cout << numArray[i] << " ";
	} 

	delete[] numArray;
}


void oddsKeepEvensFlip(int arr[], int arrSize) {
	int* tempArr = new int [arrSize];
	int l = 0, r = arrSize - 1;
	
	for (int i = 0; i < arrSize; ++i)
		if (arr[i] % 2 == 1) {
			tempArr[l] = arr[i];
			l++;
		}
		else {
			tempArr[r] = arr[i];
			r--;
		}
	
	for (int i = 0; i < arrSize; ++i) {
		arr[i] = tempArr[i];
	}

	delete[] tempArr;
}
