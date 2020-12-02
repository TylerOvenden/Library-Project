#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Copy.h"
#include "User.h"

using namespace std;

enum ReaderType {
	STUDENT,
	TEACHER
};

class Reader : public User {
private:
	ReaderType type;

	int penalty = 0;
	int books = 0;
	int maxCopies;
	int maxBorrowDays;

	vector<Copy> borrowed;
	vector<Copy> reserved;

public:
	Reader();

	void setReaderType(ReaderType type);
	ReaderType getReaderType();
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


	friend istream& operator>>(istream& is, Reader& reader) {
		string line;
		getline(is, line);
		stringstream readerStream(line);

		int type;
		string username, password, borrowingPeriod, bookIds;

		readerStream >> type;
		if (type == ReaderType::STUDENT) {
			reader.setMaxBorrowDays(30);
			reader.setMaxCopies(5);
		}
		else if (type == ReaderType::TEACHER) {
			reader.setMaxBorrowDays(50);
			reader.setMaxCopies(10);
		}

		readerStream >> username;
		reader.setUsername(username);
		readerStream >> password;
		reader.setPassword(password);
		//studentStream >> borrowingPeriod;
		// serialize borrowing period into duration-type
		// stud.setBorrowingPeriod(borrowingPeriod);
		//studentStream >> bookIds;
		// serialize book ids into vector<string>
		// stud.setBookIds(bookIds)
		return is;
	}

	friend ostream& operator<<(ostream& os, Reader& reader) {
		os << reader.getReaderType() << " ";
		os << reader.getUsername() << " ";
		os << reader.getPassword() << " ";
		os << reader.getMaxCopies() << " " << endl;
		return os;
	}
};
