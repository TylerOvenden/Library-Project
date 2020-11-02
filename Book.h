#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Student.h"
#include <ctime>
using namespace std;
class Book {
private:
	string title;
	string author;
	int isbn;
	string category;
	int id;
	string reader;
	double start;
	double expiration;
	bool borrow;
	bool overdue;

public:
	Book();
	Book(string title, string author, int isbn, string category, int id);
	void setTitle(string t);
	string getTitle();
	void setAuthor(string aut);
	string getAuthor();
	void setISBN(int is);
	int getISBN();
	void setCat(string cat);
	string getCat();
	void setID(int ide);
	int getID();
	void setRead(string read);
	string getRead();
	void setStart();
	double getStart();
	void setEnd(double end);
	double getEnd();
	double getDiff();
	void findOverdue(Student s, vector<Book>& borrow);
	void addCopy(Student s, int id, vector<Book>& books, vector<Book>& borrow);
	void removeCopy(Student s, int id, vector<Book>& books, vector<Book>& borrow);
	void findOverdue(Student s, vector<Book>& borrow);
};
