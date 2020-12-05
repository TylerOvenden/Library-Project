#pragma once
#include <sstream>
#include <iostream>
#include "User.h"
#include "Reader.h"
#include <vector>
using namespace std;

class Librarian: public User {
public:
	Librarian();
	Librarian(string username, string password);

	void searchUser(vector<User> users, string username);
    vector<Reader> addUser(vector<Reader> users);
    vector<Reader> deleteUser(vector<Reader> users);

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
		os << librarian.getPassword() << endl;
		return os;
	}
};

