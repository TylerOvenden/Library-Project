#include "Student.h"

using namespace std;

Student::Student() {
	this->setUserType(UserType::STUDENT);
	this->setMaxBorrowDays(30);
	this->setMaxCopies(5);
}
