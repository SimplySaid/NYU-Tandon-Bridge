#include <iostream>
#include <cmath>

int main() {
	double a, b, c, root1, root2;

	std::cout << "Please enter value of a: ";
	std::cin >> a;

	std::cout << "Please enter value of b: ";
	std::cin >> b;

	std::cout << "Please enter value of c: ";
	std::cin >> c;

	//Calculating exceptions to b^2 - 4 * a * c rule first
	if (a == 0 && b == 0 && c == 0) {
		std::cout << "This equation has an infinite number of solutions";
	}
	else if (a == 0) {
		std::cout << "This equation has no solution";
	}
	//If none of the exceptions apply, then calculate the number of roots and print using b^2 - 4 * a * c
	else {
		if (((b * b) - (4 * a * c)) < 0) {
			std::cout << "This equation has no real solution";
		}
		else if (((b * b) - (4 * a * c)) == 0) {
			root1 = (-(b)+std::sqrt((b * b) - (4 * a * c))) / (2 * a);
			std::cout << "This equation has a single real solution x =" << root1;
		}
		else if (((b * b) - (4 * a * c)) > 0) {
			root1 = (-(b)+std::sqrt((b * b) - (4 * a * c))) / (2 * a);
			root2 = (b + std::sqrt((b * b) - (4 * a * c))) / (2 * a);
			std::cout << "This equation has two real soltuions, x =" << root1 << " and x =" << root2;
		}
	}

	return 0;
}

