#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Copy.h"
#include "User.h"
using namespace std;
class Reader : public User
{
private:
	int pentality = 0;
	int maxCop;
	int borrow;
	vector<Copy>& borrowed;
	vector<Copy>& reserved;
public:
	Reader();
	void increasePentality();
	int getPentality();

};

