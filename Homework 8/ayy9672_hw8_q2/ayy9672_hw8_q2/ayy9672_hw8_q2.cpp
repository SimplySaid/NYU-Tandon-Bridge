#include <iostream>
#include <string>

bool isPalindrome(std::string str);

int main() {
	std::string userInput;

	std::cout << "Please enter a word: ";
	std::cin >> userInput;
	
	std::cout << userInput << " is ";
	if (isPalindrome(userInput))
		std::cout << "a palindrome";
	else
		std::cout << "not a palindrome";

	return 0;
}

bool isPalindrome(std::string str) {
	for (int i = 0; i < str.length() / 2; ++i) {
		if (str[i] != str[str.length() - 1 - i])
			return false;
	}
	return true;
}