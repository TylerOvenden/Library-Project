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
	username = "";
	password = "";
}
Student::Student(string p, string u)
{
	username = p;
	password = u;
}
string Student:: getUser() {
	return username;
}
string Student::getPass() {
	return password;
}
void Student::setUser(string u) {
	username = u;
}
void Student::setPass(string p) {
	password = p;
}