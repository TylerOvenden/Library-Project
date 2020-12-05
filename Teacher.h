#pragma once
#include "Reader.h"

using namespace std;

class Teacher : public Reader {
public:
	Teacher();
	Teacher(string username, string password);
};