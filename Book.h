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

	vector<string> reservers;
	// todo: change every fking instance of date to time for consistency's sake
	vector<int> reservationDates;

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

	void deleteReservationFor(string username);

	void setReservers(vector<string> reservers);

	void setReservationDates(vector<int> reservationDates);

	friend istream& operator>>(istream& is, Book& book) {
		string line;
		getline(is, line);
		stringstream bookStream(line);

		int isbn, copyCount, favor;
		string title, author, category;
		string reserversBracketString, reservationDatesBracketString;
		
		// 123 My_Favorite_Title Jeff_Dezos Horror 420 [] []
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
		bookStream >> reserversBracketString;
		vector<string> reservers = Utils::extractStringsFromBracketString(reserversBracketString);
		book.setReservers(reservers);
		bookStream >> reservationDatesBracketString;
		vector<int> reservationDates = Utils::extractIntegersFromBracketString(reservationDatesBracketString);
		book.setReservationDates(reservationDates);

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