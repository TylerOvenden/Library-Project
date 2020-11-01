#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Book.h"
//#include "Student.h"

using namespace std;

class Student {
private:
	string username;
	string password;
	const int maxCop = 5;
	const int borrow = 30;
	//B;
//	std::vector <Book> vec;
	int books = 0;
	int penalaties = 0;
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
};
