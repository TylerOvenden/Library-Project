#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
//#include "Reader.h"

using namespace std;

class Book {
private:
	//queue<Reader> reservations;
	// vector<Copy> copies;

	string title;
	string author;
	string category;
	vector<int> copyIDs;
	int isbn;
	int copyCount;
	int favor;

	int resCount;
public:
	Book();
	Book(int isbn, string title, string author, string category, int copyCount, int favor);

	int getISBN();
	void setISBN(int ISBN);

	string getTitle();
	void setTitle(string title);

	string getAuthor();
	void setAuthor(string author);

	string getCategory();
	void setCategory(string category);

	int getCopyCount();
	void setCopyCount(int copyCount);


	void addCopy(int id);

	std::vector<int> getIDs();
	void setIDs(vector<int> t);


	int getFavor();
	void setFavor(int favor);
	//gets number of reserved copies
	int getresCount();
	//increases number of reserved copies
	void inresCount();
	//decreases number of reserved copies
	void deresCount();

	//queue<Reader> getReservations();
	//void addReservations(Reader reader);
	//
	void print();

	// void addCopy(Student s, int id, vector<Book>& books, vector<Book>& borrow);
	// void removeCopy(Student s, int id, vector<Book>& books, vector<Book>& borrow);

	friend istream& operator>>(istream& is, Book& book) {
		string line;
		getline(is, line);
		stringstream bookStream(line);

		int isbn, copyCount, favor;
		string title, author, category;

		bookStream >> isbn;
		book.setISBN(isbn);
		bookStream >> title;
		book.setTitle(title);
		bookStream >> author;
		book.setAuthor(author);
		bookStream >> category;
		book.setCategory(category);
		bookStream >> copyCount;
		book.setCopyCount(copyCount);
		bookStream >> favor;
		book.setFavor(favor);
		return is;
	}

	friend ostream& operator<<(ostream& os, Book& book) {
		os << book.getISBN() << " ";
		os << book.getTitle() << " ";
		os << book.getAuthor() << " ";
		os << book.getCategory() << " ";
		os << book.getCopyCount() << " ";
		os << book.getFavor() << endl;
		return os;
	}
};