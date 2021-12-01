#include <iostream>
#include <string>

bool checkAnagram(std::string s1, std::string s2);
void toLower(std::string& str);

int main() {
	std::string s1, s2;
	std::cout << "Enter the first sentence: ";
	std::getline(std::cin, s1);


	std::cout << "Enter the second sentence: ";
	std::getline(std::cin, s2);

	toLower(s1);
	toLower(s2);

	if (checkAnagram(s1, s2))
		std::cout << "The two strings are anagrams.";
	else
		std::cout << "The two strings are not anagrams.";

	return 0;
}

bool checkAnagram(std::string s1, std::string s2) {
	int s1chars[26] = { 0 }, s2chars[26] = { 0 };
	
	for (int i = 0; i < s1.length(); ++i) {
		if (s1[i] >= 'a' && s1[i] <= 'z')
			s1chars[s1[i] - 'a']++;
	}

	for (int i = 0; i < s2.length(); ++i) {
		if (s2[i] >= 'a' && s2[i] <= 'z')
			s2chars[s2[i] - 'a']++;
	}

	for (int i = 0; i < sizeof(s1chars) / sizeof(s1chars[0]); ++i) {
		if (s1chars[i] != s2chars[i])
			return false;
	}
	return true;
}

void toLower(std::string& str) {
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - ('Z' - 'z');
	}
}

/*
bool checkAnagram(std::string s1, std::string s2) {
	for (int i = 0; i < s1.length(); ++i) {
		int charLocation = s2.find(s1[i]);
		std::cout << s1[i];
		std::cout << s2 << "\n";
		if (charLocation == -1 && (s1[i] >= 'a' && s1[i] <= 'z'))
			return false;
		else
			s2.erase(charLocation);
	}
	std::cout << s2 << "\n";
	if (s2 == "")
		return true;
	return false;
}
*/