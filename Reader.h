#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <deque>

#include <vector>
#include "Copy.h"
#include "User.h"

using namespace std;

class Reader : public User {
private:
	int penalty = 0;
	int books = 0;
	int maxCopies;
	int maxBorrowDays;
	bool overdue;
	vector<Copy> borrowed;
	vector<Copy> reserved;

public:
	Reader();
	Reader(int type, string username, string password, int maxCopies, int maxBorrowDays);
	void increasePenalty();
	void setPenalty(int penalty);
	int getPenalty();
	void setMaxCopies(int maxCopies);
	int getMaxCopies();
	void setMaxBorrowDays(int maxBorrowDays);
	int getMaxBorrowDays();
	std::vector<Copy> getBorrow();
	std::vector<Copy> getReserve();
	void setBorrow(std::vector<Copy> borrow);
	void setReserve(std::vector<Copy> reserve);
	int getBook();
	void setBook(int num);
	void increaseBook();
	//methods for checking if books overdue
	bool getOverdue();
	void setOverdue(bool b);
	Copy* c;

	void addCopy( int enteri, vector<Copy>& copies);
	void reserveCopy( int enteri, vector<Copy>& copies);
	void deleteCopy( int enteri, vector<Copy>& copies);
	void findOverdue( vector<Copy>& borrow);
	void removeReserve(int enteri, vector<Copy>& copies);



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