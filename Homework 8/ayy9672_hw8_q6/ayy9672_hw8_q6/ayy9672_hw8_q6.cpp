#include <iostream>
#include <string>

std::string parseString(std::string str, char splitter);
bool isNumber(std::string str);

int main() {
	std::string userInput = "";

	std::cout << "Please enter a line of text: \n";
	std::getline(std::cin, userInput);
	
	std::cout << parseString(userInput, ' ');

	return 0;
}

std::string parseString(std::string str, char splitter) {
	std::string stack = "", output = ""; //Using stack for algorithm practice
	
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] != splitter) {
			stack += str[i];
		}
		else {
			if (isNumber(stack)) {
				stack = std::string(stack.length(), 'x');
			}
			output += stack;
			stack = ""; //Clear stack
			output += splitter;
		}
	}
	if (isNumber(stack)) { //Spaghetti code. I know.
		stack = std::string(stack.length(), 'x');
	}
	output += stack;

	return output;
}

bool isNumber(std::string str) {
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}
