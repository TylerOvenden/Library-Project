#include "Book.h"

using namespace std;

Book::Book() {
}

Book::Book(int isbn, string title, string author, string category, int copyCount, int favor) {
	this->isbn = isbn;
	this->title = title;
	this->author = author;
	this->category = category;
	this->copyCount = copyCount;
	this->favor = favor;
}

int Book::getISBN() {
	return this->isbn;
}

void Book::setISBN(int isbn) {
	this->isbn = isbn;
}

string Book::getTitle() {
	return this->title;
}

void Book::setTitle(string title) {
	this->title = title;
}

string Book::getAuthor() {
	return this->author;
}

void Book::setAuthor(string author) {
	this->author = author;
}

string Book::getCategory() {
	return this->category;
}

void Book::setCategory(string category) {
	this->category = category;
}

int Book::getCopyCount() {
	return this->copyCount;
}

void Book::setCopyCount(int copyCount) {
	this->copyCount = copyCount;
}

int Book::getFavor() {
	return this->favor;
}

void Book::setFavor(int favor) {
	this->favor = favor;
}
/*
queue<Reader> Book::getReservations() {
	return this->reservations;
}

void Book::addReservations(Reader reader) {
	this->reservations.push(reader);
}
*/

void Book::inresCount() {
	this->resCount++;
}

void Book::deresCount() {
	this->resCount--;
}

int Book::getresCount() {
	return resCount;
}


void Book::print() {
	cout << "Title: " << this->getTitle() << ", ";
	cout << "Category: " << this->getCategory() << ", ";
	cout << "Author: " << this->getAuthor() << ", ";
	cout << "Favor: " << this->getFavor() << ", ";
	cout << "Copies: " << this->getCopyCount() << ", ";
	cout << "ISBN: " << this->getISBN() << endl;
}

// can we change this to add a Copy object instead? and a Copy object can have an on ID it
//adds id of copy when another copy of book is added
void Book::addCopy(int id) {
	copyIDs.push_back(id);
}

void Book::setIDs(vector<int> t) {
	this->copyIDs = t;

}

std::vector<int> Book::getIDs() {
	return copyIDs;

}
