#include <iostream>

//One pass O(n) using Dynamic Programming 
//Store net of positive and negatives in array, looks at result for n with one less digit and adds on pos/neg value for new digit
int main() {
	int n = 0;

	std::cout << "Input a positive number: ";
	std::cin >> n;

	int* dp = new int[n + 1];
	dp[0] = 0;

	for (int i = 1; i < n + 1; ++i) {
		if (i % 2 == 1) {
			dp[i] = dp[i / 10] - 1;
		}
		else {
			dp[i] = dp[i / 10] + 1;
		}
		if (dp[i] > 0)
			std::cout << i << "\n";
	}
	delete[] dp;
	return 0;
}

/*
//O(n len(n)) solution using brute force.
int main() {
	int n = 0;

	std::cout << "Input a positive number: ";
	std::cin >> n;

	for (int i = 1; i < n + 1; ++i) {
		int temp = i, netDigitsValue = 0;

		while (temp > 0) {
			if (temp % 2 == 1) {
				netDigitsValue -= 1;
			}
			else {
				netDigitsValue += 1;
			}
			temp /= 10;
		}

		if (netDigitsValue > 0) {
			std::cout << i << "\n";
		}
	}
	return 0;
}
*/



