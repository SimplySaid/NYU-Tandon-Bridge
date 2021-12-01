#include <iostream>
#include <cmath>

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main() {
	int n;

	std::cout << "Please enter a positive integer >= 2: ";
	std::cin >> n;

	std::cout << "Perfect Numbers: ";
	for (int i = 2; i <= n; ++i) {
		if (isPerfect(i))
			std::cout << i << " ";
	}
	std::cout << "\n";

	std::cout << "Amicable Numbers:\n";
	for (int i = 2; i <= n; ++i) {
		int c1, s1, c2, s2;
		analyzeDividors(i, c1, s1);
		if (i > s1) {
			analyzeDividors(s1, c2, s2);
			if (s1 <= n && s2 == i && i != s1)
				std::cout << i << " " << s1 << "\n";
		}
	}
	return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
	outCountDivs = 1, outSumDivs = 1;
	for (int i = 2; i <= std::sqrt(num); ++i) {
		if (num % i == 0) {
			outSumDivs += i;
			outSumDivs += num / i;
			outCountDivs += 2;
		}
	}
}

bool isPerfect(int num) {
	int tempOutCount, tempOutSum;
	analyzeDividors(num, tempOutCount, tempOutSum);
	return tempOutSum == num;
}