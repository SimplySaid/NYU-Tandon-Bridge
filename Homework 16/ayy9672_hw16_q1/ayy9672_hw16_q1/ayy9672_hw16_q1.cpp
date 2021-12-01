#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <map>

bool isPair(std::string s1, std::string s2) {
	if (s1 == "{")
		return s2 == "}";
	else if (s1 == "(")
		return s2 == ")";
	else if (s1 == "[")
		return s2 == "]";
	else if (s1 == "begin" || s1 == "BEGIN")
		return s2 == "end" || s2 == "END";
	else return false;
}

bool validPascal(std::fstream& fs) {
	std::stack<std::string> s;
	std::string temp;

	while  (fs >> temp) {
		if (temp == "{" || temp == "(" || temp == "[" || temp == "begin" || temp == "BEGIN") {
			std::cout << temp << "\n";
			s.push(temp);
		}
		else if (temp == "}" || temp == ")" || temp == "]" || temp == "end" || temp == "END") {
			if (isPair(s.top(), temp)) {
				std::cout << temp << "\n";
				s.pop();
			}
			else {
				return false;
			}
		}
	}
	if (s.empty())
		return true;
	return false;
}

int main() {
	std::string filename;
	std::fstream fs;
	std::cout << "Please enter the file name: ";
	std::cin >> filename;
	fs.open(filename);
	if (fs.fail()) {
		std::cout << "File does not exist\n";
	}
	else {
		if (validPascal(fs)) {
			std::cout << "The symbols are balanced.\n";
		}
		else {
			std::cout << "The symbols are not balanced.\n";
		}
	}
	fs.close();

	return 0;
}
