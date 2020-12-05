#include "Student.h"

using namespace std;

Student::Student(string username, string password) {
	this->setUsername(username);
	this->setPassword(password);
	this->setUserType(UserType::STUDENT);
	this->setMaxBorrowDays(30);
	this->setMaxCopies(5);
}

Student::Student() {
	this->setUserType(UserType::STUDENT);
	this->setMaxBorrowDays(30);
	this->setMaxCopies(5);
}
