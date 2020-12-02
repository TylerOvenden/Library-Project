#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Book.h"
#include "Student.h"
using namespace std;
Student::Student()
{


}
Student::Student(string p, string u)
{
	this->setUsername(u);
	this->setPassword(p);
	
}
