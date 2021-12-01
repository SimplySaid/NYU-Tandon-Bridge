#include <iostream>

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void printArray(int arr[], int arrSize);

int main() {
	int size = 7;
	int arr[] = { 3,-1,-3,-4,10,9,4 };
	
	std::cout << "Array 1\n";

	int n1size;
	int* ptrNum1;
	ptrNum1 = getPosNums1(arr, size, n1size);
	std::cout << "Address: " << ptrNum1 << "\n";
	printArray(ptrNum1, n1size);

	std::cout << "\n";
	std::cout << "Array 2\n";

	int* ptrNum2;
	int* newSizePtr = new int;
	*newSizePtr = size;
	ptrNum2 = getPosNums2(arr, size, newSizePtr);
	std::cout << "Address: " << ptrNum2 << "\n";
	printArray(ptrNum2, *newSizePtr);

	std::cout << "\n";
	std::cout << "Array 3\n";

	int* ptrNum3;
	int n3size = size;
	getPosNums3(arr, size, ptrNum3, n3size);
	std::cout << "Address: " << ptrNum3 << "\n";
	printArray(ptrNum3, n3size);

	std::cout << "\n";
	std::cout << "Array 4\n";

	int* ptrNum4;
	int n4size = size;
	getPosNums3(arr, size, ptrNum4, n4size);
	std::cout << "Address: " << ptrNum4 << "\n";
	printArray(ptrNum4, n4size);
	
	delete[] ptrNum1;
	delete[] ptrNum2;
	delete[] ptrNum3;
	delete[] ptrNum4;
	delete newSizePtr;

	return 0;
}

void printArray(int arr[], int arrSize) {
	int i;
	for (i = 0; i < arrSize; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}


int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
	int* newPosArr = new int[arrSize];
	int j = 0;

	for (int i = 0; i < arrSize; ++i) {
		if (arr[i] >  0) {
			newPosArr[j] = arr[i];
			j++;
		}
	}
	outPosArrSize = j;
	return newPosArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
	int* newArr = new int[(*outPosArrSizePtr)];
	int j = 0;

	for (int i = 0; i < arrSize; ++i) {
		if (arr[i] > 0) {
			newArr[j] = arr[i];
			j++;
		}
	}
	*outPosArrSizePtr = j;
	return newArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
	outPosArr = getPosNums1(arr, arrSize, outPosArrSize);
	/*int j = 0;

	for (int i = 0; i < arrSize; ++i) {
		if (arr[i] % 2 == 0) {
			swap(&arr[i], &arr[j]);
			j++;
		}
	}
	outPosArrSize = j;
	outPosArr = arr;
	*/
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
	*outPosArrPtr = new int[*outPosArrSizePtr];
	int j = 0;

	for (int i = 0; i < arrSize; ++i) {
		if (arr[i] > 0) {
			(*outPosArrPtr)[j] = arr[i];
			j++;
		}
	}
	*outPosArrSizePtr = j;
}