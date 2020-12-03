#pragma once
#include <sstream>
#include "User.h"

using namespace std;

class Librarian: public User {
public:
	Librarian();

	friend istream& operator>>(istream& is, Librarian& librarian) {
		string line;
		getline(is, line);
		stringstream librarianStream(line);
		string username, password;

		librarianStream >> username;
		librarian.setUsername(username);
		librarianStream >> password;
		librarian.setPassword(password);
		librarian.setUserType(UserType::LIBRARIAN);

		return is;
	}

	friend ostream& operator<<(ostream& os, Librarian& librarian) {
		os << librarian.getUsername() << " ";
		os << librarian.getPassword() << " ";
		return os;
	}
};

