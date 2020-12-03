#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <queue>   
#include "Book.h"
#include "Utils.h"

using namespace std;

class Copy {
private:
	// Which book this copy belongs to
	Book* book;
	
	int id;

	string reader = "";
	long borrowDate = 0;
	long expirationDate = 0;
	
	queue<string> reserver;
	queue<long> reserveDate;

public: 
	Copy();
	Copy(int id, Book* book);

	void setId(int id);
	int getId();

	void setBorrowDate(long borrowDate);
	void setExpiration(long expirationDate);

	Book* getBook();
	void setBook(Book* book);

	void setReader(string reader);
	string getReader();

	bool isAvailable();
	bool isOverdue();

	void resetReaderFields();
	void borrowFor(string username, int maxBorrowDays);
	
	long getBorrowDate();
	long getExpirationDate();

	void addReservation(string reserver);

};


