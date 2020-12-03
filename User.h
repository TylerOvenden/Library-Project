#pragma once
#include <string>

using namespace std;

enum UserType {
	STUDENT,
	TEACHER,
	LIBRARIAN
};

class User {
private:
	UserType type;

	string username;
	string password;

public:
	User();
	User(string password, string username);

	string getUsername();
	string getPassword();

	void setPassword(string password);
	void setUsername(string username);

	UserType getUserType();
	string getUserTypeString();
	void setUserType(UserType type);
};
