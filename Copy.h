#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <queue>   
#include "Utils.h"

using namespace std;

class Copy {
private:
	int isbn;
	
	int id;

	string reader = "";
	long borrowDate = 0;
	long expirationDate = 0;
	
	queue<string> reserver;
	queue<long> reserveDate;

public: 
	Copy();
	Copy(int id, int isbn);

	void setId(int id);
	int getId();

	void setBorrowDate(long borrowDate);
	void setExpirationDate(long expirationDate);

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
		copyStream >> borrowDate;
		copy.setBorrowDate(borrowDate);
		copyStream >> expirationDate;
		copy.setExpirationDate(expirationDate);
		copyStream >> readerName;
		copy.setReaderName(readerName);

		return is;
	}

	friend ostream& operator<<(ostream& os, Copy& copy) {
		os << copy.getId() << " ";
		os << copy.getISBN() << " ";
		os << copy.getBorrowDate() << " ";
		os << copy.getExpirationDate() << " ";
		os << copy.getReaderName() << " ";
		
		return os;
	}
};

