#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Book.h"
#include "Reader.h"
using namespace std;
class Student : public Reader {
private:
	
	//int books = 0;
	bool late;
public: 
	Student();
	Student(string p, string u);
	string getUser();
	string getPass();
	void setPass(string p);
	void setUser(string u);
	void increaseB();
	void print();
	int getBook();
	void setBook(int b);
	bool getLate();
	void setLate(bool l);
};