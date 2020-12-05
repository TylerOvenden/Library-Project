#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Copy.h"
#include "User.h"

using namespace std;

class Reader : public User {
private:
	int penalty = 0;
	int maxCopies;
	int maxBorrowDays;
	bool overdue;
	vector<Copy> borrowed;
	vector<int> reservedISBNs;

public:
	Reader();
	Reader(string username, string password);

	Reader(int type, string username, string password, int maxCopies, int maxBorrowDays);
	void increasePenalty();
	void setPenalty(int penalty);
	int getPenalty();
	void setMaxCopies(int maxCopies);
	int getMaxCopies();
	void setMaxBorrowDays(int maxBorrowDays);
	int getMaxBorrowDays();
	std::vector<Copy> getBorrowedCopies();
	std::vector<int> getReservedISBNs();
	void setBorrow(std::vector<Copy> borrow);
	void setReserve(std::vector<Copy> reserve);

	void addCopy(Copy copy);
	void deleteCopy(int copyId);
	vector<Copy> getOverdueCopies();

	friend istream& operator>>(istream& is, Reader& reader) {
		string line;
		getline(is, line);
		stringstream readerStream(line);

		int type, maxBorrowDays, maxCopies;
		string username, password, borrowingPeriod, bookIds;

		readerStream >> type;
		reader.setUserType((UserType)type);
		readerStream >> username;
		reader.setUsername(username);
		readerStream >> password;
		reader.setPassword(password);
		readerStream >> maxCopies;
		reader.setMaxCopies(maxCopies);
		readerStream >> maxBorrowDays;
		reader.setMaxBorrowDays(maxBorrowDays);
		// todo: Add book id parsing here ~ [1,2,3]
		return is;
	}

	friend ostream& operator<<(ostream& os, Reader& reader) {
		os << reader.getUserType() << " ";
		os << reader.getUsername() << " ";
		os << reader.getPassword() << " ";
		os << reader.getMaxCopies() << " ";
		os << reader.getMaxBorrowDays() << endl;
		// todo: Add book id parsing here ~ [1,2,3]
		return os;
	}
};