#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Reader.h"

using namespace std;

class Book {
private:
	vector<Copy> copies;

	vector<string> reservers;
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
	void setISBN(int isbn);

	string getTitle();
	void setTitle(string title);

	string getAuthor();
	void setAuthor(string author);

	string getCategory();
	void setCategory(string category);

	void loadCopyIntoBook(Copy copy);

	Copy addCopy();
	void removeCopy(int id);

	int getCopyCount();

	std::vector<Copy> getCopies();

	int getFavor();
	void setFavor(int favor);
	
	void returnCopyToLibrary(Copy copy);

	void reserveFor(string username);

	void returnCopyToLibrary(int copyId);
	
	Copy* borrowCopy(Reader reader);

	string getFormattedCopyIds();

	void print();

	vector<string> getReservers();
	void setReservers(vector<string> reservers);

	bool isBorrowableFor(string username);

	void borrowCopyFor(Reader* reader, Copy* copy);

	void removeFromReservationsIfPresent(string username);

	vector<int> getReservationDates();
	void setReservationDates(vector<int> reservationDates);

	vector<Copy> getAvailableCopies();

	friend istream& operator>>(istream& is, Book& book) {
		string line;
		getline(is, line);
		stringstream bookStream(line);

		int isbn, copyCount, favor;
		string title, author, category;
		string reserversBracketString, reservationDatesBracketString;
		
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
		os << book.getFavor() << " ";
		// Reservers
		os << "[";
		for (int i = 0; i < book.reservers.size(); i++) {
			os << book.reservers.at(i);
			if (i != book.reservers.size() - 1) {
				os << ",";
			}
		}
		os << "] ";

		// Reservation Dates
		os << "[";
		for (int i = 0; i < book.reservationDates.size(); i++) {
			os << book.reservationDates.at(i);
			if (i != book.reservationDates.size() - 1) {
				os << ",";
			}
		}
		os << "] ";

		os << endl;
		return os;
	}
};