#include "Teacher.h"

Teacher::Teacher(string username, string password) {
	this->setUsername(username);
	this->setPassword(password);
	this->setUserType(UserType::TEACHER);
	this->setMaxBorrowDays(50);
	this->setMaxCopies(10);
}


Teacher::Teacher() {
	this->setUserType(UserType::TEACHER);
	this->setMaxBorrowDays(50);
	this->setMaxCopies(10);
}
