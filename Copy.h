#pragma once
#include <string>
#include <vector>
#include "Book.h"
//#include "Student.h"
using namespace std;
class Copy 
{
private:
	int id;
	Book cop;
	string reader;
	string reserver;
	bool available;
	int reservedate;
	int borrowdate;
	int expiredate;

public: 
	Copy();
	void setReader(string r);
	string getReader();
	void setReserver(string r);
	bool getAvail();
	void setAvail(bool b);
	string getReserver();
	int getReserveDate();
	int getBorrowDate();
	int getExpireDate();
	void setReserveDate(int r);
	void setBorrowDate(int r);
	void setExpireDate(int r);



};

