#pragma once
#include "Reader.h"

using namespace std;

class Student : public Reader {
public: 
	Student();
	Student(string username, string password);
};