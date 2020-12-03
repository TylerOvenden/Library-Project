#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include "Reader.h"
#include "Copy.h"

using namespace std;

class Book {
private:
	vector<Copy> copies;

	queue<Reader> reservations;
	queue<long> reservationTimes;

	string title;
	string author;
	string category;

	int isbn;
	int favor;

public:
	Book();
	Book(int isbn, string title, string author, string category, int favor);

	int getISBN();
	void setISBN(int ISBN);

	string getTitle();
	void setTitle(string title);

	string getAuthor();
	void setAuthor(string author);

	string getCategory();
	void setCategory(string category);

	void addCopy();
	void removeCopy(int id);

	int getCopyCount();

	std::vector<Copy> getCopies();

	int getFavor();
	void setFavor(int favor);
	
	void reserveFor(Reader reader);
	void returnCopyToLibrary(Copy copy);
	void addReservations(Reader reader);
	queue<Reader> getReservations();
	
	Copy* borrowCopy(Reader reader);

	string getFormattedCopyIds();

	void print();

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
		bookStream >> favor;
		book.setFavor(favor);
		return is;
	}

	friend ostream& operator<<(ostream& os, Book& book) {
		os << book.getISBN() << " ";
		os << book.getTitle() << " ";
		os << book.getAuthor() << " ";
		os << book.getCategory() << " ";
		os << book.getFavor() << endl;
		return os;
	}
};