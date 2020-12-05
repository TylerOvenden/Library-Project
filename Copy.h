#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include "Utils.h"

using namespace std;

class Copy {
private:
	int isbn;
	int id;

	string reader = "";
	long borrowDate = 0;
	long expirationDate = 0;

public: 
	Copy();
	Copy(int id, int isbn);

	void setId(int id);
	int getId();

	void setBorrowDate(int borrowDate);
	void setExpirationDate(int expirationDate);

	int getISBN();
	void setISBN(int isbn);

	void print();

	void setReaderName(string reader);
	string getReaderName();

	bool isAvailable();
	bool isOverdue();

	void resetReaderFields();
	void borrowFor(string username, int maxBorrowDays);
	
	long getBorrowDate();
	long getExpirationDate();

	friend istream& operator>>(istream& is, Copy& copy) {
		string line;
		getline(is, line);
		stringstream copyStream(line);

		long borrowDate, expirationDate;
		int isbn, id;
		string readerName;

		copyStream >> id;
		copy.setId(id);
		copyStream >> isbn;
		copy.setISBN(isbn);
		
		/* The remaining fields may or may not exist depending on if the copy
			is currently borrowed. If borrowDate does not exist, we populate the
			remaining fields with default values. */
		
		// The copy has no borrower - we hit the end of the line (literally)
		if (!(copyStream >> borrowDate)) {
			copy.setBorrowDate(0);
			copy.setExpirationDate(0);
			copy.setReaderName("");
		} else {
			copy.setBorrowDate(borrowDate);
			copyStream >> expirationDate;
			copy.setExpirationDate(expirationDate);
			copyStream >> readerName;
			copy.setReaderName(readerName);
		}
		
		return is;
	}

	friend ostream& operator<<(ostream& os, Copy& copy) {
		os << copy.getId() << " ";
		os << copy.getISBN() << " ";
		os << copy.getBorrowDate() << " ";
		os << copy.getExpirationDate() << " ";
		os << copy.getReaderName() << endl;
		
		return os;
	}
};

