#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Utils {
public:
	static long getCurrentTimeMs();
	static string promptForInput(string prompt);
	static vector<string> extractStringsFromBracketString(std::string bracketString);
	static vector<int> extractIntegersFromBracketString(std::string bracketString);
};

