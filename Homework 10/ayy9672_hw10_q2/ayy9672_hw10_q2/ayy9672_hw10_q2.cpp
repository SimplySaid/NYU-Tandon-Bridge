#include <iostream>

int* findMissing(int arr[], int n, int& resArrSize);

int main() {
	int arr[6] = { 3, 1, 3, 0, 6, 4};
	int resArrSize = 6;

	int* missingInts = findMissing(arr, 6, resArrSize);

	std::cout << "Missing array size is: " << resArrSize << " and the array contains: ";
	for (int i = 0; i < resArrSize; ++i) {
		std::cout << missingInts[i] << " ";
	}

	std::cout << "\n";

	delete[] missingInts;
	missingInts = nullptr;

	return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
	int* tempArr = new int[n+1]();
	int notMissing = 0;
	
	for (int i = 0; i < n; ++i) {
		if (tempArr[arr[i]] == 0) {
			tempArr[arr[i]] = 1;
			notMissing++;
		}
	}
	int* missingNums = new int[n - notMissing + 1];
	int j = 0;

	for (int i = 0; i < n + 1; ++i) {
		if (tempArr[i] == 0) {
			missingNums[j] = i;
			j++;
		}
	}
	resArrSize = j;
	delete[] tempArr;
	return missingNums;
}