#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <queue>   
#include <deque>
#include "Book.h"


using namespace std;

class Copy : public Book
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

	deque<string> reserved;

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
	void setBook(Book b);

	void setReserveDate(int r);
	void setBorrowDate(int r);
	void setExpireDate(int r);

	deque<string> getReserveQueue();
	void setReserveQueue(deque<string> &r);

	void setStart();
	void setEnd(int end);
	int getEnd();
	int getStart();

	int getSince();
	void setSince(int s);

	void resetStart();

	void setID(int id);
	int getID();

	void search(vector<Copy>& borrow, istream& in);

	friend istream& operator>>(istream& is, Copy& copy) {
		Book b = Book();
		
		string line;
		getline(is, line);
		stringstream bookStream(line);

		int isbn, copyCount, favor, id;
		string title, author, category;

		bookStream >> isbn;
		b.setISBN(isbn);
		bookStream >> title;
		b.setTitle(title);
		bookStream >> author;
		b.setAuthor(author);
		bookStream >> category;
		b.setCategory(category);
		bookStream >> copyCount;
		b.setCopyCount(copyCount);
		bookStream >> favor;
		b.setFavor(favor);
		bookStream >> id;
		copy.setID(id);
		copy.setBook(b);
		return is;
	}

	friend ostream& operator<<(ostream& os, Copy& copy) {
		os << copy.getISBN() << " ";
		os << copy.getTitle() << " ";
		os << copy.getAuthor() << " ";
		os << copy.getCategory() << " ";
		os << copy.getCopyCount() << " ";
		os << copy.getFavor() << " ";
		os << copy.getID() << endl;
		return os;
	}

};

