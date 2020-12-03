#include "Teacher.h"

Teacher::Teacher() {
	this->setUserType(UserType::TEACHER);
	this->setMaxBorrowDays(50);
	this->setMaxCopies(10);
}
