#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Student.h"

using namespace std;

class Book {
private:
	string title;
	string author;
	int isbn;
	string category;
	int id;
	string reader;
	int start;
	int expiration;
	bool borrow;
	string bookHolder;


public:
	Book();
	Book(string title, string author, int isbn, string category, int id/*, string bookHolder*//*, int startTime*/);
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
	void setStart(int s);
	int getStart();
	void setEnd(int end);
	int getEnd();
	void addCopy(Student s, int id, vector<Book>& books, vector<Book>& borrow);
	void removeCopy(Student s, int id, vector<Book>& books, vector<Book>& borrow);
};
