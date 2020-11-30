#include <string>
#include "User.h"

using namespace std;

User::User() { }

User::User(string p, string u) {
	username = p;
	password = u;
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