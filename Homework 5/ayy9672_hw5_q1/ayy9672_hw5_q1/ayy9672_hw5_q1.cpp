#include <iostream>

int main() {
	int n;

	std::cout << "Please enter a positive integer:\n";
	std::cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			std::cout << i * j << "\t";
		}
		std::cout << "\n";
	}
	return 0;
}