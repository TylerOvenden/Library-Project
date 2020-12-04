#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <queue>   

#include "Book.h"


using namespace std;

class Copy
{
private:
	// Which book this copy belongs to
	Book book;

	int id;

	string reade;
	string reserver;

	bool available;
	int start;
	int expiration;

	int since;

	int reservedate;
	int borrowdate;
	int expiredate;

	queue<string> reserved;

public:
	Copy(); 
	Copy(Book b, int id);
	void setReader(string r);
	string getReader();
	void setReserver(string r);
	bool getAvail();
	void setAvail(bool b);
	string getReserver();
	int getReserveDate();
	int getBorrowDate();
	int getExpireDate();
	Book getBook();

	void setReserveDate(int r);
	void setBorrowDate(int r);
	void setExpireDate(int r);

	queue<string> getReserveQueue();
	void setReserveQueue(queue<string> r);

	void setStart();
	void setEnd(int end);
	int getEnd();
	int getStart();

	int getSince();
	void setSince(int s);



	void setID(int id);
	int getID();

	void search(vector<Copy>& borrow, istream& in);


};

