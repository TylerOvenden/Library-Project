#include "User.h"

using namespace std;

User::User() { }

User::User(string p, string u) {
	username = p;
	password = u;
}

void User::setUserType(UserType type) {
	this->type = type;
}

string User::getUserTypeDisplay() {
	switch (this->getUserType()) {
	case UserType::STUDENT:
		return "Student";
	case UserType::TEACHER:
		return "Teacher";
	case UserType::LIBRARIAN:
		return "Librarian";
	}
}

bool User::isReader() {
	return this->type == STUDENT || this->type == TEACHER;
}

UserType User::getUserType() {
    return this->type;
}

string User::getUsername() {
	return username;
}

string User::getPassword() {
	return password;
}

void User::setUsername(string username) {
	this->username = username;
}

void User::setPassword(string password) {
	this->password = password;
}