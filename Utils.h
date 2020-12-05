#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

class Utils {
public:
	static int getCurrentTimeSecs();
	static string promptForInput(string prompt);
	static vector<string> extractStringsFromBracketString(std::string bracketString);
	static vector<int> extractIntegersFromBracketString(std::string bracketString);
};

