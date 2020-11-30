#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Book {
private:

	string title;
	string author;
	string category;

	int isbn;
	int copyCount;
	int favor;

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

	int getFavor();
	void setFavor(int favor);

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
