#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;
class Book {
private:
	string titl;
	string author;
	int isbn;
	string category;
	int id;
	string reader;
	int start;
	int expiration;
	bool borrow;


public:
	Book();
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
};