#include <iostream>

/*
void printNEvenWhileLoop(int n) {
	int i = 1;

	while (i <= n) {
		std::cout << i * 2 << "\n";
		i++;
	}
}

void printNEvenForLoop(int n) {
	for (int i = 1; i <= n; i++) {
		std::cout << i * 2 << "\n";
	}
}
*/

int main() {
	int n, m;

	//Using while loop
	std::cout << "section a" << std::endl;

	std::cout << "Please enter a positive integer: ";
	std::cin >> n;

	int i = 1;
	while (i <= n) {
		std::cout << i * 2 << "\n";
		i++;
	}

	//Using for Loop
	std::cout << "section b" << std::endl;

	std::cout << "Please enter a positive integer: ";
	std::cin >> m;

	for (int j = 1; j <= m; ++j) {
		std::cout << j * 2 << "\n";
	}

	return 0;
}


