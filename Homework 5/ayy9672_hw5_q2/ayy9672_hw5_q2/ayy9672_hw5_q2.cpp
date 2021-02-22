#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	int tries = 0, guess = -1, randNumTarget;
	int low = 1, high = 100;
	bool numberGuessed = false;
	
	std::srand(time(0));
	randNumTarget = (rand() % 100) + 1;

	std::cout << randNumTarget << "\n";

	std::cout << "I thought of a number between 1 and 100! Try to guess it.\n";

	while (tries < 5 && !numberGuessed) {
		std::cout << "Range: [" << low << ", " << high << "], Number of guesses left: " << 5 - tries << std::endl;
		std::cout << "Your guess: ";
		std::cin >> guess;

		if (guess == randNumTarget) {
			numberGuessed = true;
		}
		else if (guess > randNumTarget && tries != 4) {
			high = guess - 1;
			std::cout << "Wrong! My number is smaller.\n\n";
		}
		else if (guess < randNumTarget && tries != 4) {
			low = guess + 1;
			std::cout << "Wrong! My number is bigger.\n\n";
		}
		tries++;
	}

	if (numberGuessed) {
		std::cout << "Congrats! You guessed my number in " << tries << " guesses.";
	}
	else {
		std::cout << "Out of guesses! My number is " << randNumTarget;
	}

	return 0;
}