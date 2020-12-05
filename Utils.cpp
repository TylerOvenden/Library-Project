#include "Utils.h"

// todo change time to be int starting at 0
long Utils::getCurrentTimeMs() {
	return 0;
}

string Utils::promptForInput(string prompt) {
	cout << prompt;
	string input;
	cin >> input;
	return input;
}

vector<string> Utils::extractStringsFromBracketString(string bracketString) {
	vector<string> result;

	string currentStr;
	for (int i = 0; i < bracketString.size(); i++) {
		char current = bracketString[i];
		if (current == '[') {
			continue;
		} else if (current == ',' || current == ']') {
			result.push_back(currentStr);
			currentStr = "";
		} else {
			currentStr += current;
		}
	}
	return result;
}

vector<int> Utils::extractIntegersFromBracketString(string bracketString) {
	vector<string> strings = extractStringsFromBracketString(bracketString);
	vector<int> result;
	for (int i = 0; i < strings.size(); i++) {
		result.push_back(atoi(strings.at(i).c_str()));;
	}
	return result;
}