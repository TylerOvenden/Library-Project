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
Student::Student(string user, string pass)
{
	username = user;
	password = pass;
}
int Student::getBook() {

	return books;
}
void Student::setBook(int b) {
	books = b;
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
